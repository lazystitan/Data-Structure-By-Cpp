//
// Created by Riton on 2019/9/2.
//

#ifndef DATA_STRUCTURE_BY_CPP_GRAPH_H
#define DATA_STRUCTURE_BY_CPP_GRAPH_H

#include <climits>
#include "../Stack/stack.h"
#include "../Queue/queue.h"

typedef enum {UNDISCOVERED, DISCOVERED, VISITED} VStatus;
//三种节点状态：未发现，已发现，已访问
typedef enum {UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD} EType;
//三种边状态：未决定，树，交叉，前向，后向
//未决定：初始状态

template <typename Tv, typename Te>
class Graph {
private:
    void reset() {
        /*
         * 遍历所有节点
         * 节点设为未发现，d时间和f时间设为-1，消除父节点，优先级最大
         * 所有边设置为未决定
         * */
        for (int i = 0; i < n; ++i) {
            status(i) = UNDISCOVERED;
            d_time(i) = f_time(i) = -1;
            parent(i) = -1;
            priority(i) = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if  (exists(i, j))
                    type(i, j) = UNDETERMINED;
            }
        }
    }
    void BFS(int, int&); //广度优先
    void DFS(int, int&); //深度优先
    void BCC(int, int&, Stack<int>&);
    bool TSort(int, int &, Stack<Tv> *);
    template <typename PU>
    void PFS(int, PU);

public:
    int n;
    virtual int insert(Tv const&) = 0;
    virtual Tv remove(int) = 0;
    virtual Tv& vertex(int) = 0;
    virtual int in_degree(int) = 0;
    virtual int out_degree(int) = 0;
    virtual int first_nbr(int) = 0;
    virtual int next_nbr(int, int) = 0;
    virtual VStatus& status(int) = 0;
    virtual int& d_time(int) = 0;
    virtual int& f_time(int) = 0;
    virtual int& parent(int) = 0;
    virtual int& priority(int) = 0;

    int e;
    virtual bool exists(int, int) = 0;
    virtual void insert(Te const&, int, int, int) = 0;
    virtual Te remove(int, int) = 0;
    virtual EType& type(int, int) =0;
    virtual Te& edge(int, int) = 0;
    virtual int& weight(int, int) = 0;

    void bfs(int);
    void dfs(int);
    void bcc(int);
    Stack<Tv> * t_sort(int);
    void prim(int);
    void dijkstra(int);
    template <typename PU>
    void pfs(int, PU);

};

template<typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s) {
    //start with s
    reset();
    int clock = 0;
    int v = s;
    do
        if (status(v) == UNDISCOVERED)
            BFS(v, clock);
    while (s != (v = (++v % n)));
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int &clock) {
    Queue<int> queue;
    status(v) = DISCOVERED;
    queue.enqueue(v);
    while (!queue.empty()) {
//        int v = queue.dequeue();
//        strange!
        v = queue.dequeue();
        d_time(v) = ++clock;
        for (int u = first_nbr(v); u > -1; u = next_nbr(v, u)) {
            if (status(u) == UNDISCOVERED) {
                status(u) = DISCOVERED;
                queue.enqueue(u);
                type(v, u) = TREE;
                parent(u) = v;
            } else {
                type(v, u) = CROSS;
            }
        }
        status(v) = VISITED;
    }

}

template<typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s) {
    //外部入口，从编号为s的节点开始深度优先遍历
    reset();//先初始化
    int clock = 0;//计“时”
    int v = s;//初始化v，即是传入的节点编号
    /*
     * 当节点v未发现且的时候，进行遍历
     * 这时传入的v就是s，即是从s开始遍历
     * while的条件是防止是不连通的图
     * */
    do
        if (status(v) == UNDISCOVERED)
            DFS(v, clock);
    while (s != (v = ++v % n));
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int &clock) {
    d_time(v) = ++clock;//设置此节点活动开始时间
    status(v) = DISCOVERED;//将当前节点v设置为已发现
    /*
     * 从v开始的边中不断寻找下一个节点。
     * 当下一个节点没有被发现的时候，将这条边设置为树的一部分，
     * 并且将它的父节点设置为当前节点，然后从此节点开始新一轮深度优先搜索；
     * 如果下一个节点是已发现节点，就将这条边设置为后向边；
     * 如果下一个节点是已访问节点，确定当前节点是先被访问还是后被访问，
     * 先被访问说明此边是前向边，否则是交叉边。
     * */
    for (int u = first_nbr(v); u > -1 ; u = next_nbr(v, u)) {
        switch (status(u)) {
            case UNDISCOVERED: type(v, u) = TREE;
                parent(u) = v;
                DFS(u, clock);
                break;
            case DISCOVERED: type(v, u) = BACKWARD;
                break;
            default:type(v, u) = (d_time(v) < d_time(u) ? FORWARD : CROSS);
                break;
        }
    }
    status(v) = VISITED;//此节点已访问
    f_time(v) = ++clock;//设置此节点活动截止时间
}

template<typename Tv, typename Te>
Stack<Tv> *Graph<Tv, Te>::t_sort(int s) {
    reset();
    int clock = 0;
    int v = s;
    auto* stack = new Stack<Tv>;
    do {
        if (status(v) == UNDISCOVERED)
            /*
             * 不同之处在这里，传入了一个栈，如果TSort报错错误，
             * 会把栈内所有的节点弹出并返回，即就是失败；
             * */
            if (!TSort(v, clock, stack)) {
                while (!stack->empty())
                    stack->pop();
                break;
            }
    } while (s != (v = (++v % n)));
    return stack;
}

template<typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(int v, int &clock, Stack<Tv> *stack) {
    d_time(v) = ++clock;
    status(v) = DISCOVERED;
    for (int u = first_nbr(v); u > -1; u = next_nbr(v, u))
        switch (status(u)) {
            case UNDISCOVERED:
                parent(u) = v;
                type(v, u) = TREE;
                //对下一个节点进行深度优先
                if (!TSort(u, clock, stack))
                    return false;
                break;
            case DISCOVERED:
                //有后向边说明有环存在（未确定）所以报错。
                type(v, u) = BACKWARD;
                return false;
            default:
                type(v, u) = (d_time(v) < d_time(u)) ? FORWARD : CROSS;
                break;
    }
    status(v) = VISITED;
    //将此节点入栈
    stack->push(vertex(v));
    return true;
}

template<typename Tv, typename Te>
template<typename PU>
void Graph<Tv, Te>::pfs(int s, PU priority_updater) {
    reset();
    int v = s;
    do
        if (status(v) == UNDISCOVERED)
            PFS(v, priority_updater);
    while (s != (v = (++v % n)));
}

template<typename Tv, typename Te>
template<typename PU>
void Graph<Tv, Te>::PFS(int s, PU priority_updater) {
    priority(s) = 0;
    status(s) = VISITED;
    parent(s) = -1;
    while (true) {
        for (int w = first_nbr(s); w > -1 ; w = next_nbr(s, w)) {
            priority_updater(this, s, w);
        }

        for (int shortest = INT_MAX, w = 0; w < n; ++w) {
            if (status(w) == UNDISCOVERED)
                if (shortest > priority(w)) {
                    shortest = priority(w);
                    s = w;
                }
        }

        if (status(s) == VISITED)
            break;
        status(s) = VISITED;
        type(parent(s), s) = TREE;
    }
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::BCC(int, int &, Stack<int> &) {

}


template<typename Tv, typename Te>
void Graph<Tv, Te>::bcc(int) {
//    TODO
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::prim(int) {
//    TODO
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::dijkstra(int) {
//    TODO
}

//针对Prim算法的顶点优先级更新器
template <typename Tv, typename Te>
struct PrimPU {
    virtual void operator() (Graph<Tv, Te> *g, int uk, int v) {
        if (g->status(v) == UNDISCOVERED)
            if (g->priority(v) > g->weight(uk, v)) {
                g->priority(v) = g->weight(uk, v);
                g->parent(v) = uk;
            }
    }
};

//针对Dijkstra算法的顶点优先级更新器
template <typename Tv, typename Te>
struct DijkstraPU {
    virtual void operator() (Graph<Tv, Te> *g, int uk, int v) {
        if (g->priority(v) > g->priority(uk) + g->weight(uk, v)) {
            g->priority(v) = g->priority(uk) + g->weight(uk, v);
            g->parent(v) = uk;
        }
    }
};



#endif //DATA_STRUCTURE_BY_CPP_GRAPH_H

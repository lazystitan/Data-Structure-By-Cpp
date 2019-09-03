//
// Created by Riton on 2019/9/2.
//

#ifndef DATA_STRUCTURE_BY_CPP_GRAPH_H
#define DATA_STRUCTURE_BY_CPP_GRAPH_H

#include "../Stack/stack.h"
#include "../Queue/queue.h"

typedef enum {UNDISCOVERED, DISCOVERED, VISITED} VStatus;
typedef enum {UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD} EType;

template <typename Tv, typename Te>
class Graph {
private:
    void reset() {
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
    reset();
    int clock = 0;
    int v = s;
    do
        if (status(v) == UNDISCOVERED)
            DFS(v, clock);
    while (s != (v = ++v % n));
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int &clock) {
    d_time(v) = ++clock;
    status(v) = DISCOVERED;
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
    status(v) = VISITED;
    f_time(v) = ++clock;
}

template<typename Tv, typename Te>
void Graph<Tv, Te>::BCC(int, int &, Stack<int> &) {

}

template<typename Tv, typename Te>
Stack<Tv> *Graph<Tv, Te>::t_sort(int s) {
    reset();
    int clock = 0;
    int v = s;
    auto* stack = new Stack<Tv>;
    do {
        if (status(v) == UNDISCOVERED)
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
                if (!TSort(u, clock, stack))
                    return false;
                break;
            case DISCOVERED:
                type(v, u) = BACKWARD;
                return false;
            default:
                type(v, u) = (d_time(v) < d_time(u)) ? FORWARD : CROSS;
                break;
    }
    status(v) = VISITED;
    stack->push(vertex(v));
    return true;
}

template<typename Tv, typename Te>
template<typename PU>
void Graph<Tv, Te>::PFS(int, PU) {

}


template<typename Tv, typename Te>
void Graph<Tv, Te>::bcc(int) {

}

template<typename Tv, typename Te>
void Graph<Tv, Te>::prim(int) {

}

template<typename Tv, typename Te>
void Graph<Tv, Te>::dijkstra(int) {

}

template<typename Tv, typename Te>
template<typename PU>
void Graph<Tv, Te>::pfs(int, PU) {

}


#endif //DATA_STRUCTURE_BY_CPP_GRAPH_H

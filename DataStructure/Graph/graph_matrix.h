//
// Created by Riton on 2019/9/2.
//

#ifndef DATA_STRUCTURE_BY_CPP_GRAPH_MATRIX_H
#define DATA_STRUCTURE_BY_CPP_GRAPH_MATRIX_H

#include <climits>
#include "../Vector/vector.h"
#include "graph.h"

template <typename Tv>
struct Vertex {
    Tv data;
    int in_degree;
    int out_degree;
    int parent;
    int priority;
    VStatus status;
    int d_time, f_time;
    explicit Vertex(Tv const& d = (Tv) 0) :
        data(d), in_degree(0), out_degree(0), status(UNDISCOVERED),
        d_time(-1), f_time(-1), parent(-1), priority(INT_MAX) {}
};

template <typename Te>
struct Edge {
    Te data;
    int weight;
    EType type;
    Edge(Te const& d, int w) : data(d), weight(w), type(UNDETERMINED) {}
};

template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te> {
private:
    Vector<Vertex<Tv>> vertexs;
    Vector<Vector<Edge<Te>*>> edges;
public:
    using Graph<Tv, Te>::n;
    using Graph<Tv, Te>::e;
    GraphMatrix() {
        n = e = 0;
    }
    ~GraphMatrix() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                delete edges[i][j];
    }
    Tv& vertex(int i) override {
        return vertexs[i].data;
    }

    int insert(Tv const &tv) override {
        for (int i = 0; i < n; ++i)
            edges[i].insert(nullptr);
        n++;
        edges.insert(Vector<Edge<Te>*> (n, n, (Edge<Te>*) nullptr));
        return 0;
    }

    Tv remove(int i) override {
        for (int j = 0; j < n; ++j) {
            if (exists(i, j)) {
                delete edges[i][j];
                vertexs[j].in_degree--;
            }
        }
        edges.remove(i);
        n--;
        Tv v_back = vertex(i);
        vertexs.remove(i);
        for (int k = 0; k < n; ++k) {
            if (Edge<Te> * e = edges[k].remove(i)) {
                delete e;
                vertexs[k].out_degree--;
            }
        }
        return v_back;
    }

    int in_degree(int i) override {
        return vertexs[i].in_degree;
    }

    int out_degree(int i) override {
        return vertexs[i].out_degree;
    }

    int first_nbr(int i) override {
        return next_nbr(i, n);
    }

    int next_nbr(int i, int j) override {
        while ((j > -1) && (!exists(i, --j)));
        return j;
    }

    VStatus &status(int i) override {
        return vertexs[i].status;
    }

    int &d_time(int i) override {
        return vertexs[i].d_time;
    }

    int &f_time(int i) override {
        return vertexs[i].f_time;
    }

    int &parent(int i) override {
        return vertexs[i].parent;
    }

    int &priority(int i) override {
        return vertexs[i].priority;
    }

    bool exists(int i, int j) override {
        return (i >= 0) && (i < n) && (j >= 0) && (j < n) && edges[i][j] != nullptr;
    }

    EType& type(int i, int j) override {
        return edges[i][j]->type;
    }

    Te& edge(int i, int j) override {
        return edges[i][j]->data;
    }

    int &weight(int i, int j) override {
        return edges[i][j]->weight;
    }

    void insert(Te const& edge, int w, int i, int j) override {
        if (exists(i, j)) return;
        edges[i][j] = new Edge<Te>(edge, w);
        e++;
        vertexs[i].out_degree++;
        vertexs[j].in_degree++;
    }

    Te remove(int i, int j) override {
        Te e_back = edges[i][j];
        delete edges[i][j];
        edges[i][j] = nullptr;
        e--;
        vertexs[i].out_degree--;
        vertexs[j].in_degree--;
        return e_back;
    }

};

#endif //DATA_STRUCTURE_BY_CPP_GRAPH_MATRIX_H

#ifndef LAB3_FUNCTION_HPP
#define LAB3_FUNCTION_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    class Node {
    public:
        int nodeName;
        int weight;

        Node(int name, int w) {
            this->nodeName = name;
            this->weight = w;
        }
    };

    std::vector<std::vector<Node>> gragh;
public:

    Graph(int index) {
        this->gragh.resize(index);
    }

    void insert(int from, int to, int weight, bool orient) {
        Node node = Node(to, weight);
        if (orient == false) {
            Node node_1 = Node(from, weight);
            this->gragh[to].push_back(node_1);
        }
        this->gragh[from].push_back(node);
    }

    int getName(int index, int index_1) {
        return this->gragh[index][index_1].nodeName;
    }

    int getWeight(int index, int index_1) {
        return this->gragh[index][index_1].weight;
    }
};

void fillGraph(Graph *g, bool orient) {
    g->insert(0, 1, 1, orient);
    g->insert(0, 2, 1, orient);
    g->insert(1, 3, 1, orient);
    g->insert(2, 1, 1, orient);
    g->insert(3, 5, 1, orient);
    g->insert(3, 4, 1, orient);
    g->insert(6, 3, 1, orient);
    g->insert(6, 4, 1, orient);

}

void printGraph(Graph g) {
    for (int i = 0; i < g.gragh.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < g.gragh[i].size(); j++) {
            cout << " (" << g.getName(i, j) << ", " << g.getWeight(i, j) << ") ";
        }
        cout << endl;
    }
}

vector<int> dijkstraAlgo(Graph g, int index) {
    vector<int> d(g.gragh.size(), 1000000);
    vector<int> used(g.gragh.size(), 0);
    d[index] = 0;


    for (int i = 0; i < g.gragh.size(); i++) {
        int next = -1;
        for (int j = 0; j < g.gragh.size(); j++) {
            if (used[j] == 0) {
                if (next == -1) {
                    next = j;
                } else {
                    if (d[j] < d[next]) {
                        next = j;
                    }
                }
            }
        }
        used[next] = 1;
        for (int j = 0; j < g.gragh[next].size(); j++) {
            int tempNode = g.gragh[next][j].nodeName;
            d[tempNode] = min(d[tempNode], d[next] + g.getWeight(next, j));
        }
    }
    return d;
}

void dfs(Graph g, int index, vector<int> &used, vector<int> &tout, int &T) {
    used[index] = 1;

    for (int i = 0; i < g.gragh[index].size(); i++) {
        if (used[g.getName(index, i)] == 0) {
            dfs(g, g.getName(index, i), used, tout, T);
        }
    }
    T = T + 1;
    tout[index] = T;

}

bool comparedecrease(const pair<int, int> &left, const pair<int, int> &right) {
    return (left.first > right.first);
}

vector<pair<int, int>>
topologicSort(Graph g, int index, bool compare(const pair<int, int> &left, const pair<int, int> &right)) {
    int T = 0;
    vector<int> used(g.gragh.size(), 0);
    vector<int> tout(g.gragh.size(), 0);
    for (int i = 0; i < g.gragh.size(); i++) {
        if (used[i] != 1) {
            dfs(g, i, used, tout, T);
        }
    }
    vector<pair<int, int>> graphTout;
    graphTout.resize(tout.size());
    for (int i = 0; i < tout.size(); i++) {
        graphTout[i].first = tout[i];
        graphTout[i].second = i;
    }
    sort(graphTout.begin(), graphTout.end(), compare);
    return graphTout;
}

vector<vector<int>> floid(Graph g) {
    vector<vector<int>> d;
    d.resize(g.gragh.size());
    for (int i = 0; i < g.gragh.size(); i++) {
        d[i].resize(g.gragh.size());
    }
    for (int i = 0; i < g.gragh.size(); i++) {
        for (int j = 0; j < g.gragh.size(); j++) {
            if (i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = 1000000;
            }
        }
    }
    for (int i = 0; i < g.gragh.size(); i++) {
        for (int j = 0; j < g.gragh[i].size(); j++) {
            d[i][g.getName(i, j)] = g.getWeight(i, j);
        }
    }

    for (int k = 0; k < g.gragh.size(); k++) {
        for (int u = 0; u < g.gragh.size(); u++) {
            for (int v = 0; v < g.gragh.size(); v++) {
                if (d[u][v] > d[u][k] + d[k][v]) {
                    d[u][v] = d[u][k] + d[k][v];
                }
            }
        }
    }
    return d;
}

vector<pair<int, bool>> fordBelman(Graph g, int index) {
    vector<int> d(g.gragh.size(), 1000000);
    d[index] = 0;
    for (int k = 0; k < g.gragh.size(); k++) {
        for (int i = 0; i < g.gragh.size(); i++) {
            for (int j = 0; j < g.gragh[i].size(); j++) {
                d[i] = min(d[i], d[g.getName(i, j)] + g.getWeight(i, j));
            }
        }
    }
    vector<pair<int, bool>> answer;
    answer.resize(g.gragh.size());
    for (int i = 0; i < g.gragh.size(); i++) {
        answer[i].first = d[i];
        answer[i].second = false;
    }
    for (int k = 0; k < g.gragh.size(); k++) {
        for (int i = 0; i < g.gragh.size(); i++) {
            for (int j = 0; j < g.gragh[i].size(); j++) {
                if (d[i] > d[g.getName(i, j)] + g.getWeight(i, j)) {
                    answer[i].second = true;
                }
            }
        }
    }
    return answer;
}

#endif //LAB3_FUNCTION_HPP

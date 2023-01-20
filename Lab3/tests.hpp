#ifndef LAB3_TESTS_HPP
#define LAB3_TESTS_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "function.hpp"
#include <assert.h>

void testDijkstra() {
    int size = 7;
    Graph g = Graph(size);
    fillGraph(&g, true);
    cout << "Dijkstra orient: " << endl;
    printGraph(g);
    vector<int> distance;
    distance = dijkstraAlgo(g, 0);
    cout << endl;
    for (int i = 0; i < size; ++i) {
        cout << distance[i] << '\t';
    }
    cout << endl;

    vector<int> test;
    test.resize(size);
    test[0] = 0;
    test[1] = 1;
    test[2] = 1;
    test[3] = 2;
    test[4] = 3;
    test[5] = 3;
    test[6] = 1000000;
    for (int i = 0; i < size; i++) {
        assert(test[i] == distance[i]);
    }

    Graph g_1 = Graph(size);
    fillGraph(&g_1, false);
    cout << "Dijkstra not orient: " << endl;
    printGraph(g_1);
    vector<int> distance_1;
    distance_1 = dijkstraAlgo(g_1, 0);
    cout << endl;
    for (int i = 0; i < size; ++i) {
        cout << distance_1[i] << '\t';
    }

    test[0] = 0;
    test[1] = 1;
    test[2] = 1;
    test[3] = 2;
    test[4] = 3;
    test[5] = 3;
    test[6] = 3;
    for (int i = 0; i < size; i++) {
        assert(test[i] == distance_1[i]);
    }
    cout << endl;
}

void testTopologic() {
    int size = 7;
    Graph g = Graph(size);
    fillGraph(&g, true);
    cout << "Topologic: " << endl;
    printGraph(g);
    vector<pair<int, int>> sortGraph;
    sortGraph = topologicSort(g, 0, comparedecrease);
    cout << endl;
    for (int i = 0; i < size; ++i) {
        cout << sortGraph[i].second << '\t';
    }

    cout << endl;
    vector<int> test;
    test.resize(size);
    test[0] = 6;
    test[1] = 0;
    test[2] = 2;
    test[3] = 1;
    test[4] = 3;
    test[5] = 4;
    test[6] = 5;
    for (int i = 0; i < size; i++) {
        assert(test[i] == sortGraph[i].second);
    }
}

void testFloid() {
    int size = 7;
    Graph g = Graph(size);
    fillGraph(&g, true);
    cout << "Floid: " << endl;
    printGraph(g);
    vector<vector<int>> distance;
    distance = floid(g);
    cout << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << distance[i][j] << '\t';
        }
        cout << endl;
    }

    vector<vector<int>> d;
    d.resize(g.gragh.size());
    for (int i = 0; i < g.gragh.size(); i++) {
        d[i].resize(g.gragh.size());
    }

    d[1][0] = d[2][0] = d[3][0] = d[4][0] = d[5][0] = d[6][0] = d[3][1] = d[4][1] = d[5][1] = d[6][1] = d[1][2] = d[3][2] = d[4][2] = d[5][2] = d[6][2] = d[4][3] = d[5][3] = d[5][4] = d[4][5] = d[0][6] = d[1][6] = d[2][6] = d[3][6] = d[4][6] = d[5][6] = 1000000;
    d[0][0] = d[1][1] = d[2][2] = d[3][3] = d[4][4] = d[5][5] = d[6][6] = 0;
    d[0][1] = d[0][2] = d[1][3] = d[2][1] = d[3][4] = d[3][5] = d[6][3] = d[6][4] = 1;
    d[0][3] = d[1][4] = d[1][5] = d[2][3] = d[6][5] = 2;
    d[0][4] = d[0][5] = d[2][4] = d[2][5] = 3;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            assert(distance[i][j] == d[i][j]);
        }
    }
}

void testFordBelman() {
    int size = 7;
    Graph g = Graph(size);
    fillGraph(&g, false);
    cout << "FordBelman orient: " << endl;
    printGraph(g);
    vector<pair<int, bool>> distance;
    distance = fordBelman(g, 0);
    cout << endl;
    for (int i = 0; i < size; ++i) {
        cout << distance[i].first << " ";
        if (distance[i].second == true) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

    }
    cout << endl;

    vector<int> test;
    test.resize(size);
    test[0] = 0;
    test[1] = 1;
    test[2] = 1;
    test[3] = 2;
    test[4] = 3;
    test[5] = 3;
    test[6] = 3;
    for (int i = 0; i < size; i++) {
        assert(test[i] == distance[i].first);
        assert(false == distance[i].second);
    }
}

#endif //LAB3_TESTS_HPP

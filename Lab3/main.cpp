#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "function.hpp"
#include "tests.hpp"

using namespace std;

int main() {
    testDijkstra();
    testTopologic();
    testFloid();
    testFordBelman();
    return 0;
}

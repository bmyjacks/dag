#ifndef HEAD_H
#define HEAD_H

#include <vector>

using namespace std;

class Edge {
public:
    int from, to, weight;


    Edge(int from, int to, int weight);
};

class Node {
public:
    int index = 0;
    int inDegree = 0;
    int inMemory = 0, outMemory = 0;
    int deltaMemory = 0;

    vector<Edge> connectTo;

    Node();

    bool operator<(const Node &b) const;
};

#endif //HEAD_H

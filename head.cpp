#include "head.h"

Edge::Edge(const int from, const int to, const int weight) {
    this->from = from;
    this->to = to;
    this->weight = weight;
}

Node::Node() {
    this->index = 0;
    this->inDegree = 0;
    this->inMemory = 0;
    this->outMemory = 0;
    this->deltaMemory = 0;
    this->connectTo.clear();
}

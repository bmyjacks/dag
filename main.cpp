#include <iostream>
#include <vector>
#include <queue>

#include "head.h"

using namespace std;

constexpr int MAX_N = 1e5;

int nodeNum = 0, edgeNum = 0;

Node node[MAX_N];

int nowMemory = 0;
int peakMemory = 0;

void addEdge(int from, int to, int weight) {
    node[from].connectTo.emplace_back(from, to, weight);
    ++node[to].inDegree;
    node[from].outMemory += weight;
    node[to].inMemory += weight;
}

bool Node::operator<(const Node &b) const {
    int afterA = nowMemory + this->deltaMemory, afterB = nowMemory + b.deltaMemory;
    if (afterA <= peakMemory && afterB <= peakMemory) {
        return afterA < afterB;
    }
    return this->deltaMemory > b.deltaMemory;
}


int main() {
    freopen("dag.in", "r", stdin);

    cin >> nodeNum >> edgeNum;

    for (int i = 0; i < nodeNum; ++i) {
        node[i].index = i;
    }

    for (int i = 0, from, to, weight; i < edgeNum; ++i) {
        cin >> from >> to >> weight;
        addEdge(from, to, weight);
    }

    for (int i = 0; i < nodeNum; ++i) {
        node[i].deltaMemory = node[i].outMemory - node[i].inMemory;
    }

    priority_queue<Node> nodeHeap;
    for (int i = 0; i < nodeNum; ++i) {
        if (node[i].inDegree == 0) {
//            cout << "inDegree = 0 " << i << endl;
            nodeHeap.emplace(node[i]);
        }
    }
    peakMemory = nowMemory;

//    cout << "initial size " << nodeHeap.size() << endl;

    while (!nodeHeap.empty()) {
        const Node nextNode = nodeHeap.top();
//        cout << "top" << nextNode.index;
        nodeHeap.pop();
        nowMemory += nextNode.deltaMemory;
//        cout << " delta " << nextNode.deltaMemory;
        peakMemory = max(peakMemory, nowMemory);

//        cout << " nowMem " << nowMemory << endl;

        for (const Edge i: nextNode.connectTo) {
            --node[i.to].inDegree;
            if (node[i.to].inDegree == 0) {
//                cout << "push " << i.to << endl;
                nodeHeap.push(node[i.to]);
            }
        }
    }

    cout << peakMemory << endl;

    return 0;
}

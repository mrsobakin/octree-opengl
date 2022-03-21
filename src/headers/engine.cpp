#include "engine.hpp"
#include <vector>

#include <iostream>

namespace {
    int worldSize = 500;
}

// класс для дерева.
class Node {
    private:
        int depth;
        int x, y, z;
    public:
        bool stop; // ну типо что на этой вершине нужно обход по поддереву закончить
        Node (int depth, int x, int y, bool stop = true) : depth(depth), stop(stop) {};
        int getDepth() { return depth; }
        int getX() { return x; }
        int getY() { return y; }
        int getZ() { return z; }
        int getScale() { return worldSize / (1 << depth); }
};

namespace {
    std::vector<Node> tree;
    int treeDepth;

    void _recursiveTreeWalk(std::size_t cur, void (*execOnStop) (std::size_t)) {
        if (tree[cur].stop) {
            execOnStop(cur);
        }
        for (int i = 1; i <= 8; ++i) {
            _recursiveTreeWalk((cur << 3) + i, execOnStop);
        }
    }
}

void initTree(int depth = 8) {
    treeDepth = depth;
    tree.reserve(19173961);
    tree.push_back(Node(0, 0, 0));
    setTreeNodesCoords(0, 0);
}

void setTreeNodesCoords(std::size_t cur, int depth) {
    if (depth == treeDepth) {
        return;
    }
    int scale = worldSize / (1 << tree[cur].getDepth());
    scale >>= 1;
    for (int i = 0; i < 8; ++i) {
        tree.push_back(Node(depth, tree[cur].getX() + (i & 1) * scale, tree[cur].getY() + ((i >> 1) & 1) * scale, tree[cur].getZ() + ((i >> 2) & 1) * scale));
    }
    for (int i = 1; i <= 8; ++i) {
        setTreeNodesCoords((cur << 3) + i, depth + 1);
    }
}

void drawNode(Node& node) {
    
}

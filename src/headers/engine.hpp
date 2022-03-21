#ifndef _OCTREE_ENGINE
#define _OCTREE_ENGINE

#include <vector>

void _recursiveTreeWalk(std::size_t cur, void (*execOnStop) (std::size_t));
void initTree(int depth);
void setTreeNodesCoords(std::size_t cur, int depth);
void passToRender(int depthLimit);

#endif

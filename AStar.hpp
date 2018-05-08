#ifndef AStar_hpp
#define AStar_hpp

#include "PathingAlgorithm.hpp"
#include <queue>

class AStar : public PathingAlgorithm {

protected:

    virtual int heuristic(Node startNode, Node endNode);

public:
    AStar(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g);
    void next();
};

AStar::AStar(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g)
    : PathingAlgorithm(adjList, vecList, s, g)
{ }

int AStar::heuristic(Node startNode, Node endNode)
{
    return abs(endNode.i - startNode.i) + abs(endNode.j - startNode.j);   
}

void AStar::next()
{
     
}

#endif // AStar_hpp

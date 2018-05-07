#ifndef AStar_hpp
#define AStar_hpp

#include "PathingAlgorithm.hpp"
#include <queue>

class AStar : public PathingAlgorithm {

protected:

    int heuristic(Node startNode, Node endNode);
    bool finished;

public:

    AStar();

};

AStar::AStar()
{



}

int AStar::heuristic(Node startNode, Node endNode)
{
    return abs(endNode.i - startNode.i) + abs(endNode.j - startNode.j);   
}

void AStar::run()
{
     
}

bool AStar::isRUnning()
{
    return finished;
}

#endif // AStar_hpp

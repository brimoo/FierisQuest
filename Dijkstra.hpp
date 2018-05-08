#ifndef Dijkstra_hpp
#define Dijkstra_hpp

#include "AStar.hpp"

class Dijkstra : public AStar {
    int heuristic(Node startNode, Node endNode);

public:
    Dijkstra(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g);
};

Dijkstra::Dijkstra(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g)
    : AStar(adjList, vecList, s, g)
{ }

int Dijkstra::heuristic(Node startNode, Node endNode)
{
    return 0;
}

#endif // Dijkstra_hpp

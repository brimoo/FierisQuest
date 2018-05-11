#ifndef Dijkstra_hpp
#define Dijkstra_hpp

#include "AStar.hpp"

class Dijkstra : public AStar {
    int heuristic(int startNode, int endNode);

public:
    Dijkstra(std::vector< std::vector<int> > adjList, std::vector<Node> nodeList, int s, int g);
};

Dijkstra::Dijkstra(std::vector< std::vector<int> > adjList, std::vector<Node> nodeList, int s, int g)
    : AStar(adjList, nodeList, s, g)
{ }

int Dijkstra::heuristic(int startNode, int endNode)
{
    return 0;
}

#endif // Dijkstra_hpp

#ifndef PathingAlgorithm_hpp
#define PathingAlgorithm_hpp

#include <vector>
#include "Node.hpp"

class PathingAlgorithm {
   
protected:

    std::vector< std::vector<Node> > adjList;
    Node startNode, endNode;
        
public:

    PathingAlgorithm(std::vector< std::vector<Node> > adjList, Node s, Node g)
        : adjList(adjList)
        , startNode(s)
        , endNode(g)
    { }
    virtual ~PathingAlgorithm(){}
    virtual void run() = 0;
    virtual bool isRunning() = 0;
    std::vector<std::vector<Node>> getList(); 

};

std::vector<std::vector<Node>> PathingAlgorithm:: getList()
{
    return adjList;
}

#endif // PathingAlgorithm_hpp

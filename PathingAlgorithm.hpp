#ifndef PathingAlgorithm_hpp
#define PathingAlgorithm_hpp

#include <vector>
#include "Node.hpp"

class PathingAlgorithm {
   
protected:

    std::vector< std::vector<Node> > adjList;
    std::vector<Node> vecList;
    Node startNode, endNode;
        
public:

    PathingAlgorithm(std::vector< std::vector<Node> > adjList, std::vector<Node> vecList, Node s, Node g)
        : adjList(adjList)
        , startNode(s)
        , endNode(g)
        , vecList(vecList)
    { }
    virtual ~PathingAlgorithm(){}
    virtual void run() = 0;
    virtual bool isRunning() = 0;
    std::vector<std::vector<Node>> getList(); 

};

std::vector<Node> PathingAlgorithm:: getList()
{
    return vecList;
}

#endif // PathingAlgorithm_hpp

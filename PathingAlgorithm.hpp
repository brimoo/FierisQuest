#ifndef PathingAlgorithm_hpp
#define PathingAlgorithm_hpp

#include <vector>
#include "Node.hpp"

class PathingAlgorithm {
   
protected:

    std::vector< std::vector<int> > adjList;
    std::vector<Node> vecList;
    int startID;
    int endID;
    bool running;
        
public:

    PathingAlgorithm(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g)
        : adjList(adjList)
        , vecList(vecList)
        , startID(s)
        , endID(g)
        , running(false)
    { }
    virtual ~PathingAlgorithm(){}
    virtual void next() = 0;
    virtual bool isRunning() { return running; }
    std::vector<Node> getList() { return vecList; }

};

#endif // PathingAlgorithm_hpp

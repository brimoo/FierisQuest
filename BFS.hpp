#ifndef BFS_hpp
#define BFS_hpp

#include "PathingAlgorithm.hpp"

#include <iostream>
#include <queue>
#include <map>
#include <climits>

class BFS : public PathingAlgorithm {
    std::map<int, int> came_from;
    std::queue<int> open;
    void extractPath();

public:
    BFS(std::vector< std::vector<int> > adjList, std::vector<Node> nodeList, int s, int g);
    
    void next();
};

BFS::BFS(std::vector< std::vector<int> > adjList, std::vector<Node> nodeList, int s, int g)
    : PathingAlgorithm(adjList, nodeList, s, g)
{
    came_from[s] = s;
    open.push(s);
}

void BFS::next()
{
    if(!open.empty()){

        int curr = open.front();
        open.pop();

        nodeList[curr].traverse();

        if(curr == endID){
            std::cout << "-----GOAL FOUND-----" << std::endl;
            running = false;
            pathFound = true;
            extractPath();
            return;
        }

        for(int neighbor : adjList[curr]){
            if(came_from.find(neighbor) == came_from.end() && nodeList[neighbor].cost != INT_MAX){
                open.push(neighbor);
                came_from[neighbor] = curr;
                nodeList[neighbor].expand();
            }
        }
    }
    else{
        running = false;
        std::cout << "-----NO PATH FOUND-----" << std::endl;
    }
}

void BFS::extractPath()
{
    int i = endID;

    while(i != startID && pathFound){
        nodeList[i].inPath = true;
        i = came_from[i];
    }
}

#endif // BFS_hpp

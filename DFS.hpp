#ifndef DFS_hpp
#define DFS_hpp

#include "PathingAlgorithm.hpp"

#include <stack>
#include <vector>
#include <map>
#include <iostream>
#include <climits>

class DFS : public PathingAlgorithm {
    std::map<int, int> came_from;
    std::stack<int> stack;
    std::vector<bool> visited;
    void extractPath();

public:
    DFS(std::vector< std::vector<int> > adjList, std::vector<Node> nodeList, int s, int g);
    void next();
};

DFS::DFS(std::vector< std::vector<int> > adjList, std::vector<Node> nodeList, int s, int g)
    : PathingAlgorithm(adjList, nodeList, s, g)
    , visited(std::vector<bool>(nodeList.size(), false))
{ 
    stack.push(s);
    came_from[s] = s;
}

void DFS::next()
{
    if(!stack.empty()) {

        int curr = stack.top();
        stack.pop();

        if(!visited[curr]){
            visited[curr] = true;
            nodeList[curr].traverse();
        }

        if(curr == endID){
            std::cout << "-----GOAL FOUND-----" << std::endl;
            running = false;
            pathFound = true;
            extractPath();
            return;
        }

        for(int neighbor : adjList[curr]){
            if(!visited[neighbor] && nodeList[neighbor].cost != INT_MAX){
                stack.push(neighbor);
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

void DFS::extractPath()
{
    int i = endID;

    while(i != startID && pathFound){
        nodeList[i].inPath = true;
        i = came_from[i];
    }
}

#endif // DFS_hpp

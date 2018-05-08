#ifndef DFS_hpp
#define DFS_hpp

#include <stack>
#include <vector>
#include <map>
#include "PathingAlgorithm.hpp"
#include <iostream>
#include <climits>

class DFS : public PathingAlgorithm {

    std::map<int, int> came_from;
    std::stack<int> stack;
    std::vector<bool> visited;
    void extractPath();

public:
    DFS(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g);
    void next();
};

DFS::DFS(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g)
    : PathingAlgorithm(adjList, vecList, s, g)
    , visited(std::vector<bool>(vecList.size(), false))
{ 
    stack.push(s);
    came_from[s] = s;
}

void DFS::next()
{
    if(!stack.empty()){

        int curr = stack.top();
        stack.pop();

        if(!visited[curr]){
            visited[curr] = true;
            vecList[curr].traverse();
        }

        if(curr == endID){
            std::cout << "-----GOAL FOUND-----" << std::endl;
            running = false;
            pathFound = true;
            extractPath();
            return;
        }

        for(int neighbor : adjList[curr]){
            if(!visited[neighbor] && vecList[neighbor].cost != INT_MAX){
                stack.push(neighbor);
                came_from[neighbor] = curr;
                vecList[neighbor].expand();
            }
        }

    }
    else{
        running = false;
        std::cout << "-----NO PATH FOUND-----" << std::endl;
    }

    return;
}

void DFS::extractPath()
{
    int i = endID;

    while(i != startID && pathFound){
        vecList[i].inPath = true;
        i = came_from[i];
    }

    return;
}

#endif // DFS_hpp

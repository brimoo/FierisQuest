#ifndef AStar_hpp
#define AStar_hpp

#include "PathingAlgorithm.hpp"
#include <queue>
#include <map>
#include <functional>
#include <climits>
#include <iostream>

struct PriorityQueue {
    typedef std::pair<int, int> element;
    std::priority_queue<element, std::vector<element>, std::greater<element>> elements;

    inline bool empty() const {
        return elements.empty();
    }

    inline void push(int item, int priority) {
        elements.emplace(priority, item);
    }

    int pop() {
        int best_item = elements.top().second;
        elements.pop();
        return best_item;
    }
};

class AStar : public PathingAlgorithm {

protected:

    virtual int heuristic(int startNode, int endNode);
    void extractPath();
    PriorityQueue open;
    std::map<int, int> cost_so_far;
    std::map<int, int> came_from;
    std::queue<int> path_to_goal;

public:
    AStar(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g);
    void next();
};

AStar::AStar(std::vector< std::vector<int> > adjList, std::vector<Node> vecList, int s, int g)
    : PathingAlgorithm(adjList, vecList, s, g)
{
    open.push(s, 0);
    came_from[s] = s;
    cost_so_far[s] = 0;
}

int AStar::heuristic(int startNode, int endNode)
{
    return abs(vecList[startNode].i - vecList[endNode].i) + abs(vecList[startNode].j - vecList[endNode].j);   
}

void AStar::next()
{

    if(!open.empty()){

        int curr = open.pop();
        vecList[curr].traverse();

        if(curr == endID){
            std::cout << "-----FOUND GOAL-----" << std::endl;
            running = false;
            pathFound = true;
            extractPath();
            return;
        }

        for(auto neighbor : adjList[curr]){
            int new_cost = cost_so_far[curr] + vecList[neighbor].cost;
            if((cost_so_far.find(neighbor) == cost_so_far.end() || new_cost < cost_so_far[neighbor]) && vecList[neighbor].cost != INT_MAX){
                cost_so_far[neighbor] = new_cost;
                int priority = new_cost + heuristic(neighbor, endID);
                open.push(neighbor, priority);
                vecList[neighbor].expand();
                came_from[neighbor] = curr;
            }

        }

    }
    else{
        running = false;
        std::cout << "-----NO PATH AVAILABLE-----" << std::endl;
    }
}

void AStar::extractPath()
{
    int i = endID;

    while(i != startID && pathFound){
        vecList[i].inPath = true;
        i = came_from[i];
    }
}

#endif // AStar_hpp

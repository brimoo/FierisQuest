#include <vector>
#include <functional>
#include <set>
#include <algorithm>
#include <iostream>

#include "Rect.h"

using namespace std;
//Flavortown = goal
//Fieri = start

class AStar{
	//heuristic which separates A* from dijkstra
	double heuristic(Rect Flavortown, Rect Fieri) {
		return abs(Flavortown.x - Fieri.x) + abs(Flavortown.y - Fieri.y);
	}
	
	//actual algorithm implementation with some inconsistencies which need to be fixed
	void a_star_search(Graph graph, Rect Fieri, Rect Flavortown, map<Rect, Rect>& came_from, map<Rect, double>& cost_so_far){
		//makes pushing in new nodes/rects to a path sooo much easier
		PriorityQueue<Rect, double> Path;
		Path.put(Fieri, 0);

		came_from[Fieri] = Fieri;
		cost_so_far[Fieri] = 0;
		  
		while (!Path.empty()) {
			Rect current = Path.get();

			if (current == Flavortown) {
				break;
			}

			for (Rect next : graph.neighbors(current)) {
				double new_cost = cost_so_far[current] + graph.cost(current, next);
				if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next]) {
					cost_so_far[next] = new_cost;
					
					double priority = new_cost + heuristic(next, Flavortown);
					
					Path.put(next, priority);
					came_from[next] = current;
				}
			}
		}
	}
};
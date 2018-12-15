#include "pch.h"
#include "aStar.h"


aStar::aStar()
{
}


aStar::~aStar()
{
}

void aStar::algorithm()
{
	//PriorityQueue<Location, double> frontier;
	//frontier.put(start, 0);
	previousNode[start] = start;
	cost_so_far[start] = 0;

	while (!frontier.empty()) {
		Location current = frontier.get();

		if (current == end) {
			break;
		}

		for (Location next : graph.neighbors(current)) {
			double new_cost = cost_so_far[current] + graph.cost(current, next);
			if (cost_so_far.find(next) == cost_so_far.end()
				|| new_cost < cost_so_far[next]) {
				cost_so_far[next] = new_cost;
				double priority = new_cost + heuristic(next, goal);
				frontier.put(next, priority);
				came_from[next] = current;
			}
		}
	}
}

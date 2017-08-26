#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <cmath>
#include <functional>
#include "graph.h"

struct VertexCost {
    int vertex;
    // Heuristic + cost from the start
    double totalCost;
    // Cost from the start
    int cost;

    VertexCost(int vertex, int totalCost, int cost)
        : vertex(vertex), totalCost(totalCost), cost(cost)
    {
    }

    bool operator<(const VertexCost & a) const
    {
        return totalCost < a.totalCost;
    }

    bool operator>(const VertexCost & a) const
    {
        return totalCost > a.totalCost;
    }
};

double heuristic(const Coordinates & node, const Coordinates & goal);

std::vector<int> aStar(const Graph & graph, int start, int goal);

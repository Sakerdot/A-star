#include <vector>
#include <utility>
#include <queue>
#include <set>

typedef std::vector<int> path;

struct vertexCost {
    int node;
    // Heuristic + cost from the start
    int totalCost;
    // Cost from the start
    int cost;

    vertexCost(int node, int totalCost, int cost):
        node(node),
        totalCost(totalCost),
        cost(cost)
    {}
};

int heuristic(const int node, const int goal);

path aStar(const std::vector<std::vector<int>> & graph, int start, int goal);

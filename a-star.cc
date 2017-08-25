#include "a-star.h"

struct lessCost {
    bool operator() (const vertexCost & lhs, const vertexCost &rhs) const
    {
        return lhs.cost > rhs.cost;
    }
};

int heuristic(const int node, const int goal) 
{
    // Test purposes
    return 1000;
}

std::vector<int> aStar(const std::vector<std::vector<int>> & graph, int start, int goal)
{
    std::vector<int> path;

    std::set<int> finishedVertices;
    std::priority_queue<vertexCost, std::vector<vertexCost>, lessCost> notFinished;
    
    notFinished.push(vertexCost(start, heuristic(start, goal), 0));

    while (!notFinished.empty()) {
        auto currentVertex = notFinished.top();
        notFinished.pop();

        if (currentVertex.node == goal)
        {
            path.push_back(currentVertex.node);
            return path;
        }

        if (finishedVertices.find(currentVertex.node) != finishedVertices.end())
        {
            continue;
        }

        path.push_back(currentVertex.node);
        finishedVertices.insert(currentVertex.node);

        for (int neighbour = 0; neighbour < graph[currentVertex.node].size(); ++neighbour)
        {
            if (graph[currentVertex.node][neighbour] != 0)
            {
                notFinished.push(vertexCost(
                    neighbour,
                    currentVertex.cost + heuristic(neighbour, goal),
                    currentVertex.cost + graph[currentVertex.node][neighbour])
                );
            }
        }
    }
    
    return path;
}

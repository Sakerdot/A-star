#include "a-star.h"

struct lessCost {
    bool operator() (const vertexCost & lhs, const vertexCost &rhs) const
    {
        return lhs.cost < rhs.cost;
    }
};

int heuristic(const int node, const int goal) 
{

}

path aStar(const std::vector<std::vector<int>> & graph, int start, int goal)
{
    path result;

    std::set<int> finishedVertices;
    std::priority_queue<vertexCost, std::vector<vertexCost>, lessCost> notFinished;
    
    notFinished.push(vertexCost(start, heuristic(start, goal), 0));

    while (!notFinished.empty()) {
        auto current = notFinished.pop();

        if (current.vertex == goal)
        {
            return result;
        }

        if (finishedVertices.find(current.vertex) != finishedVertices.end())
        {
            continue;
        }

        result.push_back(current.vertex);
        finishedVertices.insert(current.vertex);

        for (int neighbour = 0; neighbour < graph[current.vertex].size(); ++neighbour)
        {
            if (graph[current.vertex][neighbour] != 0)
            {
                notFinished.push(vertexCost(neighbour, heuristic(neighbour, goal), graph[current.vertex][neighbour]));
            }
        }
    }
    
    return result;
}

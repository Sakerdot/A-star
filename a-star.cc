#include "a-star.h"

Graph::Graph(int vertices):
    vertices(vertices)
{
    for (int i = 0; i < vertices; ++i)
    {
        std::vector<int> row;
        for (int j = 0; j < vertices; ++j)
        {
            row.push_back(0);
        }

        this->adjancencyMatrix.push_back(row);
        this->verticesCoordinates.push_back(Coordinates(-1, -1));
    }
}

void Graph::setCoordinates(int node, Coordinates vertexCoordinates)
{
    this->verticesCoordinates[node] = vertexCoordinates;
}

void Graph::connectNodes(int nodeA, int nodeB, int length)
{
    this->adjancencyMatrix[nodeA][nodeB] = length;
    this->adjancencyMatrix[nodeB][nodeA] = length;
}

struct LessCost {
    bool operator() (const VertexCost & lhs, const VertexCost &rhs) const
    {
        return lhs.cost > rhs.cost;
    }
};

double heuristic(const Coordinates & node, const Coordinates & goal)
{
    // Using Euclidean distance since we don't know how the graph is layed out
    int dx = abs(node.x - goal.y);
    int dy = abs(node.y - goal.y);
    return sqrt(dx * dx + dy * dy);
}

std::vector<int> aStar(const Graph & graph, int start, int goal)
{
    std::vector<int> path;

    std::set<int> finishedVertices;
    std::priority_queue<VertexCost, std::vector<VertexCost>, LessCost> notFinished;

    notFinished.push(VertexCost(
        start, 
        heuristic(graph.getCoordinatesOf(start), graph.getCoordinatesOf(goal)),
        0)
    );

    while (!notFinished.empty()) {
        auto currentVertex = notFinished.top();
        notFinished.pop();

        if (currentVertex.vertex == goal)
        {
            path.push_back(currentVertex.vertex);
            return path;
        }

        if (finishedVertices.find(currentVertex.vertex) != finishedVertices.end())
        {
            continue;
        }

        path.push_back(currentVertex.vertex);
        finishedVertices.insert(currentVertex.vertex);

        auto neighbours = graph.getNeighboursOf(currentVertex.vertex);
        for (int neighbour = 0; neighbour < neighbours.size(); ++neighbour)
        {
            if (neighbours[neighbour] != 0)
            {
                notFinished.push(VertexCost(
                    neighbour,
                    currentVertex.cost + heuristic(
                        graph.getCoordinatesOf(neighbour), 
                        graph.getCoordinatesOf(goal)),
                    currentVertex.cost + neighbours[neighbour])
                );
            }
        }
    }

    return path;
}

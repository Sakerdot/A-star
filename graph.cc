#include "graph.h"

Graph::Graph(int vertices)
    : vertices(vertices)
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

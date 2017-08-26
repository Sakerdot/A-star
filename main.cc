#include <iostream>
#include "a-star.h"

void createGraph(Graph & graph)
{
    int vertices = graph.getVertices();
    
    for (int i = 0; i < vertices; ++i)
    {
        std::cout << "Coordinates for node " << i << " (x y)";

        Coordinates coordinates;
        std::cin >> coordinates.x;
        std::cin >> coordinates.y;
        std::cout << std::endl;

        graph.setCoordinates(i, coordinates);

        for (int j = i + 1; j < vertices; ++j)
        {
            std::cout << "Node " << i << " length to node " << j << " (0 for no connection): ";

            int length;
            std::cin >> length;
            std::cout << std::endl;

            graph.connectNodes(i, j, length);
        }
    }
}

int main()
{
    std::cout << "Number of vertices: ";
    
    int vertices;
    std::cin >> vertices;
    std::cout << std::endl;
    
    auto newGraph = Graph(vertices);
    createGraph(newGraph);

    std::vector<int> path = aStar(newGraph, 0, vertices - 1);

    for (auto node : path)
    {
        std::cout << node << ", ";
    }

    std::cout << std::endl;

    return 1;
}
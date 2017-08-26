#include <iostream>
#include "a-star.h"

void createGraph(Graph & graph)
{
    int vertices = graph.getVertices();
    
    for (int i = 0; i < vertices; ++i)
    {
        std::cout << "Coordinates for node " << i << " (x y): ";

        Coordinates coordinates;
        std::cin >> coordinates.x;
        std::cin >> coordinates.y;

        graph.setCoordinates(i, coordinates);

        for (int j = i + 1; j < vertices; ++j)
        {
            std::cout << "Node " << i << " length to node " << j << " (0 for no connection): ";

            int length;
            std::cin >> length;

            graph.connectNodes(i, j, length);
        }

        std::cout << std::endl;
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

    auto path = aStar(newGraph, 0, vertices - 1);

    int pathLength = path.size();
    for (int i = 0; i < pathLength - 1; ++i)
    {
        std::cout << path[i] << ", ";
    }

    std::cout << path[pathLength - 1] << std::endl;

    return 1;
}
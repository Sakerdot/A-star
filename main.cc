#include <iostream>
#include "a-star.h"

std::vector<std::vector<int>> createGraph(int vertices)
{
    std::vector<std::vector<int>> graph;

    for (int i = 0; i < vertices; ++i)
    {
        std::vector<int> row;
        for (int j = 0; j < vertices; ++j)
        {
            row.push_back(0);
        }

        graph.push_back(row);
    }

    for (int i = 0; i < vertices; ++i)
    {
        for (int j = i + 1; j < vertices; ++j)
        {
            std::cout << i << " length to " << j << " (0 for no connection): ";

            int length;
            std::cin >> length;
            std::cout << std::endl;

            graph[i][j] = length;
            graph[j][i] = length;
        }
    }

    return graph;
}

int main()
{
    std::cout << "Number of vertices: ";
    
    int vertices;
    std::cin >> vertices;
    std::cout << std::endl;

    std::vector<int> path = aStar(createGraph(vertices), 0, vertices - 1);

    for (auto node : path)
    {
        std::cout << node << ", ";
    }

    std::cout << std::endl;

    return 1;
}
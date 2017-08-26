#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <cmath>

struct Coordinates {
    int x;
    int y;

    Coordinates() {}

    Coordinates(int x, int y):
        x(x),
        y(y)
    {}
};

class Graph {
public:
    Graph(int vertices);

    void setCoordinates(int node, Coordinates vertexCoordinates);

    void connectNodes(int nodeA, int nodeB, int length);

    const std::vector<int>& getNeighboursOf(int node) const {
        return this->adjancencyMatrix[node];
    }

    const Coordinates& getCoordinatesOf(int node) const {
        return this->verticesCoordinates[node];
    }

    int getVertices() const { 
        return this->vertices; 
    }
private:
    int vertices;
    std::vector<std::vector<int>> adjancencyMatrix;
    std::vector<Coordinates> verticesCoordinates;
};

struct VertexCost {
    int vertex;
    // Heuristic + cost from the start
    double totalCost;
    // Cost from the start
    int cost;

    VertexCost(int vertex, int totalCost, int cost):
        vertex(vertex),
        totalCost(totalCost),
        cost(cost)
    {}
};

double heuristic(const Coordinates & node, const Coordinates & goal);

std::vector<int> aStar(const Graph & graph, int start, int goal);

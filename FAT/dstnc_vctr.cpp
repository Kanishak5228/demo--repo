#include <iostream>
#include <limits>

#define INFINITY 9999
#define MAX_NODES 10

void distanceVectorRouting(int costMatrix[][MAX_NODES], int numNodes, int sourceNode) {
    int distances[MAX_NODES];
    int nextHops[MAX_NODES];
    int i, j, k;

    // Initialize distance and next hop arrays
    for (i = 0; i < numNodes; i++) {
        distances[i] = INFINITY;
        nextHops[i] = -1;
    }

    // Set distance to source node as 0
    distances[sourceNode] = 0;

    // Update distances and next hops
    for (k = 0; k < numNodes - 1; k++) {
        for (i = 0; i < numNodes; i++) {
            for (j = 0; j < numNodes; j++) {
                if (distances[j] > distances[i] + costMatrix[i][j]) {
                    distances[j] = distances[i] + costMatrix[i][j];
                    nextHops[j] = i;
                }
            }
        }
    }

    // Print routing table
    std::cout << "Routing Table\n";
    std::cout << "Destination\tNext Hop\tDistance\n";
    for (i = 0; i < numNodes; i++) {
        std::cout << i << "\t\t" << nextHops[i] << "\t\t" << distances[i] << std::endl;
    }
}

int main() {
    using namespace std;

    int numNodes, sourceNode;
    cout << "Number of nodes: ";
    cin >> numNodes;

    if (numNodes <= 0 || numNodes > MAX_NODES) {
        cout << "Invalid number of nodes\n";
        return 1;
    }

    int costMatrix[MAX_NODES][MAX_NODES];
    cout << "Cost matrix:\n";
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cin >> costMatrix[i][j];
            if (costMatrix[i][j] < 0 && costMatrix[i][j] != INFINITY) {
                cout << "Invalid value\n";
                return 1;
            }
        }
    }

    cout << "Source node: ";
    cin >> sourceNode;

    if (sourceNode < 0 || sourceNode >= numNodes) {
        cout << "Invalid source node\n";
        return 1;
    }

    distanceVectorRouting(costMatrix, numNodes, sourceNode);

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_NODES = 100; // Maximum number of nodes
const int INF = numeric_limits<int>::max(); // Represents infinity

struct Edge {
    int to;
    int weight;
};

class Graph {
    vector<Edge> adj[MAX_NODES]; // Adjacency list representation

public:
    void addEdge(int from, int to, int weight) {
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight}); // For undirected graph
    }

    void dijkstra(int source, int destination) {
        vector<int> dist(MAX_NODES, INF);
        vector<bool> visited(MAX_NODES, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[source] = 0;
        pq.push({0, source}); // {distance, node}

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            for (const auto& edge : adj[u]) {
                int v = edge.to;
                int weight = edge.weight;

                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[destination] == INF) {
            cout << "No path exists from " << source << " to " << destination << "." << endl;
        } else {
            cout << "The shortest path from " << source << " to " << destination << " is: " << dist[destination] << endl;
        }
    }
};

int main() {
    Graph graph;

    // Example: Add edges (from, to, weight)
    graph.addEdge(0, 1, 7);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 6);
    graph.addEdge(3, 4, 7);
    graph.addEdge(4, 0, 1);
    graph.addEdge(4, 2, 2);

    int source = 0;
    int destination = 2;

    graph.dijkstra(source, destination);

    return 0;
}
// Name: Nitu
// UID: 22BCS10707
// Section: 631-B


// BFS and DFS implementation:


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;

public:
    Graph(int nodes) : n(nodes) {
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void bfs(int start) {
        vector<bool> visited(n, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void dfs(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    void dfsWrapper(int start) {
        vector<bool> visited(n, false);
        dfs(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "BFS starting from node 0: ";
    g.bfs(0);

    cout << "DFS starting from node 0: ";
    g.dfsWrapper(0);

    return 0;
}


// Prim's Algorithm implementation:

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;

public:
    Graph(int nodes) : n(nodes) {
        adj.resize(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v, int weight) {
        adj[u][v] = weight;
        adj[v][u] = weight;
    }

    void prims(int start) {
        vector<int> key(n, INT_MAX);
        vector<bool> inMST(n, false);
        vector<int> parent(n, -1);

        key[start] = 0;
        parent[start] = -1;

        for (int count = 0; count < n - 1; count++) {
            int u = -1;

            for (int i = 0; i < n; i++) {
                if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                    u = i;
                }
            }

            inMST[u] = true;

            for (int v = 0; v < n; v++) {
                if (adj[u][v] != 0 && !inMST[v] && adj[u][v] < key[v]) {
                    key[v] = adj[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "Edges in the MST:" << endl;
        for (int i = 1; i < n; i++) {
            cout << parent[i] << " - " << i << " with weight " << adj[i][parent[i]] << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    cout << "Minimum Spanning Tree using Prim's Algorithm:" << endl;
    g.prims(0);

    return 0;
}

// Kruskal's Algorithm implementation:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int n;
    vector<pair<int, pair<int, int>>> edges;

public:
    Graph(int nodes) : n(nodes) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back({weight, {u, v}});
    }

    int findParent(int u, vector<int>& parent) {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u], parent);
    }

    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    void kruskal() {
        sort(edges.begin(), edges.end());

        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<pair<int, pair<int, int>>> mstEdges;

        for (auto& edge : edges) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            int rootU = findParent(u, parent);
            int rootV = findParent(v, parent);

            if (rootU != rootV) {
                mstEdges.push_back({weight, {u, v}});
                unionSets(u, v, parent, rank);
            }
        }

        cout << "Edges in the MST:" << endl;
        for (auto& edge : mstEdges) {
            cout << edge.second.first << " - " << edge.second.second << " with weight " << edge.first << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    cout << "Minimum Spanning Tree using Kruskal's Algorithm:" << endl;
    g.kruskal();

    return 0;
}

// dijkstra's Algorithm implementation:

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Graph {
    int n;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int nodes) : n(nodes) {
        adj.resize(n);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});  // For undirected graph
    }

    void dijkstra(int start) {
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from node " << start << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    cout << "Shortest paths using Dijkstra's Algorithm:" << endl;
    g.dijkstra(0);

    return 0;
}


//Bellman-Ford Algorithm implemantation:

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adjMatrix;

public:
    Graph(int nodes) : n(nodes) {
        adjMatrix.resize(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            adjMatrix[i][i] = 0;  // Distance to itself is always 0
        }
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
    }

    void bellmanFord(int start) {
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    if (adjMatrix[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + adjMatrix[u][v];
                    }
                }
            }
        }

        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (adjMatrix[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                    cout << "Graph contains negative weight cycle!" << endl;
                    return;
                }
            }
        }

        cout << "Shortest distances from node " << start << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << ": " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    cout << "Shortest paths using Bellman-Ford Algorithm:" << endl;
    g.bellmanFord(0);

    return 0;
}

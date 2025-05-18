#include <iostream>
using namespace std;

const int INF = 9999;
const int MAX = 100;

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX];
    bool visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDist = INF, u;


        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To node " << i << ": ";
        if (dist[i] == INF)
            cout << "Unreachable\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges in format (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    dijkstra(graph, n, start);

    return 0;
}

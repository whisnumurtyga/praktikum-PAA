#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

// Fungsi untuk mencari jalur terpendek dari simpul awal ke semua simpul lainnya
void bellmanFordShortestPath(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();
    std::vector<int> dist(n, INF);      // Jarak terpendek dari simpul awal
    std::vector<int> parent(n, -1);     // Menyimpan simpul sebelumnya dalam jalur terpendek

    dist[start] = 0;

    // Lakukan relaksasi pada semua tepi (n-1) kali
    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Cek apakah terdapat siklus berbobot negatif
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                std::cout << "Graph contains negative-weight cycle!" << std::endl;
                return;
            }
        }
    }

    // Cetak hasil jalur terpendek dari simpul awal ke semua simpul lainnya
    for (int i = 0; i < n; ++i) {
        std::cout << "Shortest path from A to " << char('A' + i) << ": ";
        std::vector<int> path;
        int node = i;
        while (node != -1) {
            path.push_back(node);
            node = parent[node];
        }
        for (int j = path.size() - 1; j >= 0; --j) {
            std::cout << char('A' + path[j]) << " ";
        }
        std::cout << "Distance: " << dist[i] << std::endl;
    }
}

int main() {
    // Matriks ketetanggaan yang diberikan dalam bentuk array 2D
    std::vector<std::vector<int>> graph = {
        {0, 17, 19, 18, 20, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 22, 23, 21, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 28, 27, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 25, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 26, 24, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 13, 17, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 12, 16, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 15, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Cari jalur terpendek dari simpul A (indeks 0) ke semua simpul lainnya
    bellmanFordShortestPath(graph, 0);

    return 0;
}

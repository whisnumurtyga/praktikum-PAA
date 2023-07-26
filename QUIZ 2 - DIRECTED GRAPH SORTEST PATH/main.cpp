#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

// Fungsi untuk mencari indeks simpul dengan jarak terpendek yang belum diproses
int minDistance(const std::vector<int>& dist, const std::vector<bool>& visited) {
    int minDist = INF;
    int minIndex = -1;

    for (size_t i = 0; i < dist.size(); ++i) {
        if (!visited[i] && dist[i] <= minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Fungsi untuk mencetak jalur dari simpul awal ke simpul tujuan
void printPath(const std::vector<int>& parent, int destination) {
    if (parent[destination] != -1) {
        printPath(parent, parent[destination]);
    }
    std::cout << char('A' + destination) << " ";
}

// Algoritma Dijkstra untuk mencari jalur terpendek dalam directed graph
void dijkstraShortestPath(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();
    std::vector<int> dist(n, INF);      // Jarak terpendek dari simpul awal
    std::vector<bool> visited(n, false); // Menandai apakah simpul sudah diproses
    std::vector<int> parent(n, -1);     // Menyimpan simpul sebelumnya dalam jalur terpendek

    dist[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Cetak hasil jalur terpendek dari simpul awal ke semua simpul lainnya
    for (int i = 0; i < n; ++i) {
        std::cout << "Shortest path from A to " << char('A' + i) << ": ";
        printPath(parent, i);
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
    dijkstraShortestPath(graph, 0);

    return 0;
}

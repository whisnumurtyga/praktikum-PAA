#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

struct Edge {
    int destination;
    int cost;
};

void dijkstra(int source, const vector<vector<Edge>>& graph, vector<int>& distances) {
    int n = graph.size();
    distances.resize(n, INT_MAX);
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int currNode = pq.top().second;
        int currDistance = pq.top().first;
        pq.pop();

        if (currDistance > distances[currNode]) {
            continue;
        }

        for (const Edge& edge : graph[currNode]) {
            int newDistance = currDistance + edge.cost;
            if (newDistance < distances[edge.destination]) {
                distances[edge.destination] = newDistance;
                pq.push({newDistance, edge.destination});
            }
        }
    }
}

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;

        unordered_map<string, int> cityIndices;
        vector<vector<Edge>> graph(n);

        // Build the graph
        for (int i = 0; i < n; ++i) {
            string cityName;
            cin >> cityName;

            cityIndices[cityName] = i;

            int neighbors;
            cin >> neighbors;

            for (int j = 0; j < neighbors; ++j) {
                int destination, cost;
                cin >> destination >> cost;
                graph[i].push_back({destination - 1, cost});
            }
        }

        int paths;
        cin >> paths;

        while (paths--) {
            string sourceCity, destCity;
            cin >> sourceCity >> destCity;

            int source = cityIndices[sourceCity];
            int dest = cityIndices[destCity];

            vector<int> distances;
            dijkstra(source, graph, distances);
            int minCost = distances[dest];

            cout << minCost << endl;
        }
    }

    return 0;
}

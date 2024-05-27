/*
 * Created by: Abhishek Dubey
 * Created on: 2024-05-27
 */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 1e9;

void dijkstra(int src, vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {

    /*code*/
    int n = 5;
    vector<vector<pair<int, int>>> graph(n);
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 3});
    graph[1].push_back({2, 2});
    graph[1].push_back({4, 4});
    graph[2].push_back({3, 9});
    graph[3].push_back({2, 7});
    graph[4].push_back({1, 1});
    graph[4].push_back({2, 8});
    graph[4].push_back({3, 2});

    vector<int> dist;
    dijkstra(0, graph, dist);

    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < n; ++i)
        cout << i << "\t\t" << dist[i] << endl;

    return 0;
}

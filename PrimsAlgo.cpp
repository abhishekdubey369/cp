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

void primMST(vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Edge   Weight\n";
    for (int i = 1; i < n; ++i)
        cout << parent[i] << " - " << i << "    " << key[i] << endl;
}

int main() {
    /*code*/
    int n = 5;
    vector<vector<pair<int, int>>> graph(n);

    graph[0].push_back({1, 2});
    graph[0].push_back({3, 6});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 8});
    graph[1].push_back({4, 5});
    graph[2].push_back({1, 3});
    graph[2].push_back({4, 7});
    graph[3].push_back({0, 6});
    graph[3].push_back({1, 8});
    graph[4].push_back({1, 5});
    graph[4].push_back({2, 7});

    primMST(graph);

    return 0;
}

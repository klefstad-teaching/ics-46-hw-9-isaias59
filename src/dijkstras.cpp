#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include "dijkstras.h"

using namespace std;


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distances(n, INF);
    previous.assign(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    distances[source] = 0;
    pq.emplace(0, source);

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_distance > distances[current_vertex]) continue;

        for (const Edge& edge : G[current_vertex]) {
            int new_distance = distances[current_vertex] + edge.weight;
            if (new_distance < distances[edge.dst]) {
                distances[edge.dst] = new_distance;
                previous[edge.dst] = current_vertex;
                pq.emplace(new_distance, edge.dst);
            }
        }
    }

    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int at = destination; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    if (path.size() == 1 && path[0] != destination) {
        path.clear(); 
    }

    return path;
}

void print_path(const vector<int>& path, int total) {
    if (path.empty()) {
        cout << "No path found.\n";
        return;
    }

    cout << "Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i != path.size() - 1) cout << " ";
    }

    if (total != -1) {
        cout << "\nTotal cost is" << total << '\n'; 
    }
    else {
        cout << "\nTotal cost: No path found."; 
    }
}

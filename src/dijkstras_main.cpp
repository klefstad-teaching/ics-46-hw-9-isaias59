#include <iostream>
#include <vector>
#include <string>
#include "dijkstras.h" 

using namespace std;

int main() {
    string filename;
    cout << "Enter the graph file name: ";
    cin >> filename;

    Graph graph;
    try {
        file_to_graph(filename, graph);
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }

    int source, destination;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(graph, source, previous);

    if (source < 0 || source >= graph.numVertices || destination < 0 || destination >= graph.numVertices) {
        cerr << "Invalid source or destination vertex." << endl;
        return 1;
    }

    vector<int> path = extract_shortest_path(distances, previous, destination);
    int total_cost = (distances[destination] == INF) ? -1 : distances[destination];

    print_path(path, total_cost);

    return 0;
}

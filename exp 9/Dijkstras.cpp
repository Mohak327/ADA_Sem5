#include <iostream>
#include <climits>
using namespace std;

// this method returns a minimum distance for the
// vertex which is not included in Tset.
int minimumDist(int dist[], bool Tset[])
{
    int min = INT_MAX, index;

    for (int i = 0; i < 6; i++)
    {
        if (Tset[i] == false && dist[i] <= min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra(int **graph, int n, int src) // adjacency matrix used is 6x6
{
    // integer array to calculate minimum distance for each node.
    int* dist = new int[n];
    // boolean array to mark visted/unvisted for each node.
    bool* Tset = new bool[n];

    // set the nodes with infinity distance except for the initial node and mark them unvisited.
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        Tset[i] = false;
    }

    dist[src] = 0; // Source vertex distance is set to zero.

    for (int i = 0; i < n; i++)
    {
        int m = minimumDist(dist, Tset); // vertex not yet included.
        Tset[m] = true;                  // m with minimum distance included in Tset.
        for (int i = 0; i < n; i++)
        {
            // Updating the minimum distance for the particular node.
            if (!Tset[i] && graph[m][i] && dist[m] != INT_MAX && dist[m] + graph[m][i] < dist[i])
                dist[i] = dist[m] + graph[m][i];
        }
    }
    
    cout << "Vertex\t\tDistance from source" << endl;
    for (int i = 0; i < 6; i++)
    {                      //Printing
        char str = 65 + i; // Ascii values for pritning A,B,C..
        cout << str << "\t\t\t" << dist[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    int** graph = new int*[n];
	for(int i=0; i<n; i++){
		graph[i] = new int[n];
		for(int j=0; j<n; j++){
			cin >> graph[i][j];
		}
	}

    Dijkstra(graph, n, 0);

    delete[] graph;
    return 0;
}
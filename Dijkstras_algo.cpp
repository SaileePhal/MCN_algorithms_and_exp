#include<iostream>
#include<conio.h>
#include<vector>
#include<limits>
using namespace std;
const int INF = numeric_limits<int>::max();

int minDistance(vector<int>& dist, vector<bool>& visited) //return index
{
	int minDist = INF; //initial set
	int minIndex;
	for (int v = 0; v < dist.size(); v++) //dist vector traversal
	{
		if (!visited[v] && dist[v] <= minDist)
		{
			minDist = dist[v];
			minIndex = v; //vertex with smallest dist
		}
	}
	return minIndex;
}

void dijkstra(vector<vector<int>>& graph, int src)
{
	int V = graph.size();     //will get vertices
	vector<int> dist(V, INF); //dist vector set to inf
	vector<bool>visited(V, false); //visited vector to false
	dist[src] = 0; //initial dist
	for (int i = 0; i < V - 1; i++) //bcoz first element visited
	{
		int u = minDistance(dist, visited); //min dist
		visited[u] = true;                 //elem visited
		for (int v = 0; v < V; v++)
		{
			if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) //4 condn
			{
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}

	cout << "Vertex\t\t Distance from Source\n";
	for (int i = 0; i < V; i++)
	{
		cout << i << "\t\t" << dist[i] << endl;
	}

}
int main()
{
	int V;
	cout << "Enter number of vertices: ";
	cin >> V;
	vector<vector<int>>graph(V, vector<int>(V)); // graph using vector
		cout << "Enter adjacency matrix (use " << INF << " for infinity)" << endl;
	for (int i = 0; i < V; i++)   //enter into graph just like 2D array
	{
		for (int j = 0; j < V; j++)
		{
			cin >> graph[i][j];
		}
	}
	int src;
	cout << "Enter source vertex" << endl;
	cin >> src;
	dijkstra(graph, src); //call fn

	_getch();
}
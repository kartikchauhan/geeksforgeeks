// creation of cyclic graph using adjacency list and its DFS.

#include <bits/stdc++.h>

using namespace std;

class Graph
{
	private:
		int V;

		list<int> *adj;

		void DFSUtility(int root, vector<bool> &visited)
		{
			visited[root] = true;

			cout << root << " ";

			list<int>::iterator it;

			for(it = adj[root].begin(); it != adj[root].end(); ++it)
			{
				if(!visited[*it])
				{
					DFSUtility(*it, visited);
				}
			}
		}

	public:
		Graph(int V)
		{
			this->V = V;
			adj = new list<int>[V];
		}

		void addEdge(int source, int destination)
		{
			adj[source].push_back(destination);
		}

		void DFS(int root)
		{
			vector<bool> visited(this->V, false);

			DFSUtility(root, visited);
		}
};

int main()
{
	Graph g(4);	// 4 is the number of nodes. Can be modified according to the design of the program.

	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(2);

    return 0;
}
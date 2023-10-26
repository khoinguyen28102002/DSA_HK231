#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colors(n, 0);
    for(int i = 0; i < n; i++){
        if(colors[i] == 0){
            queue<int> q;
            q.push(i);
            colors[i] = 1;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (colors[neighbor] == 0) {
                        // Color the neighbor with the opposite color of the current node
                        colors[neighbor] = -colors[node];
                        q.push(neighbor);
                    } else if (colors[neighbor] == colors[node]) {
                        // If the neighbor has the same color as the current node, it's not bipartite
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
void bfs(vector<vector<int>> graph, int start) {
	int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> printList, q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        printList.push(node);
        q.pop();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            } 
        }
    }
    while(printList.size() > 1){
        cout << printList.front() << " ";
        printList.pop();
    }
    cout << printList.front();
}

int main(){
    // Ex: isBipartite
    // int G[6][6] = { {0, 1, 0, 0, 0, 1},
    //             {1, 0, 1, 0, 0, 0},
    //             {0, 1, 0, 1, 0, 0},
    //             {0, 0, 1, 0, 1, 0},
    //             {0, 0, 0, 1, 0, 1},
    //             {1, 0, 0, 0, 1, 0} };
    // int n = 6;

    // vector<vector<int>> graph(n, vector<int>());
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < n; ++j) {
    //             if (G[i][j]) graph[i].push_back(j);
    //         }
    //     }

    // isBipartite(graph) ? cout << "Yes" : cout << "No";
    // Ex: BFS
    int init_graph[10][10] = {  {0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
				    {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
				    {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
				    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
				    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
				    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
				    {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
				    {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
				    {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
				    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0} };
	int n = 10;
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (init_graph[i][j]) graph[i].push_back(j);
		}
	}

	bfs(graph, 0);
}
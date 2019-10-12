#include <iostream>
#include <vector>

using namespace std;
 
int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> q(N);
	for (int i = 0; i < N; i++) {
	    q[i].resize(M);
	    for (int j = 0; j < M; j++) {
	        cin >> q[i][j];
	    }
	}
	vector<pair<int, int>> graph[100000];
	bool used[100000];      //вклю чили ли мы соответствующую вершину в остов

    int mst_weight = 0;     //Текущий вес остова.

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, 0});     //Начнём с вершины 0.

    while (!q.empty()) {
        pair<int, int> c = q.top();
        q.pop();

        int dst = c.first, v = c.second;

        if (used[v]) {      //вершина уже добавлена в остов
            continue;
        }

        used[v] = true;
        mst_weight += dst;

        for (pair<int, int> e: graph[v]) {
            int u = e.first, len_vu = e.second;

            if (!used[u]) {
                q.push({len_vu, u});    //Заметьте: мы учитываем только длину ребра.
            }
        }
    }

    cout << "Minimum spanning tree weight: " << mst_weight << endl;
    return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, K;
    const int64_t inf = 100000000000000;
    cin >> N >> K;
    vector<vector<pair<int, int>>> Matrix(N);
    for (int i = 0; i < K; i++) {
        int a, b;
        int l;
        cin >> a >> b >> l;
        Matrix[a - 1].push_back(make_pair(b - 1, l));
        Matrix[b - 1].push_back(make_pair(a - 1, l));
    }
    int s, f;
    cin >> s >> f;
    s--;
    f--;
    vector<int64_t> d(N, inf);
    d[s] = 0;
    set<pair<int,int>> q;
    q.insert(make_pair(d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (size_t i = 0; i < Matrix[v].size(); ++i) {
            int to = Matrix[v][i].first;
            int len = Matrix[v][i].second;
            if (d[v] + len < d[to]) {
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                q.insert(make_pair(d[to], to));
            }
        }
    }
    if (d[f] == inf) {
        cout << -1;
    } else {
        cout << d[f];
    }
    return 0;
}
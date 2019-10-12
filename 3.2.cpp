#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double find_distance (int from, int to, const vector<vector<int>> &coordinates, const vector<vector<pair<int,double>>> &v) {
    for (auto p : v[from]) {
        if (p.first == to) {
            return p.second;
        }
    }
    return sqrt(pow(coordinates[from][0] - coordinates[to][0], 2)
                + pow(coordinates[from][1] - coordinates[to][1], 2));
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> coordinates(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        coordinates[i].push_back(x);
        coordinates[i].push_back(y);
    }
    int M;
    cin >> M;
    vector<vector<pair<int, double>>> v(N);
    for (int i = 0; i < M; i++) {
        pair<int, double> p;
        int x, y;
        cin >> x >> y;
        cin >> p.second;
        p.first = y - 1;
        v[x - 1].push_back(p);
        p.first = x - 1;
        v[y - 1].push_back(p); 
    }
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    const double inf = 10000000;
    vector<double> d(N, inf);
    vector<bool> u(N, false);
    d[a] = 0;
    for (int i = 0; i < N; i++) {
        int from = -1;
        for (int j = 0; j < N; j++) {
            if ((!u[j]) && ((from == -1) || (d[j] < d[from]))) {
                from = j;
            }
        }
        u[from] = true;
        for (size_t j = 0; j < coordinates.size(); j++) {
            d[j] = min(d[j], d[from] + find_distance(from, j, coordinates, v));
        }
    }
    cout << d[b];
    return 0;
}
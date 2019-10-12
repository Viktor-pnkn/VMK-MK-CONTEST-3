#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

int Find(int x, vector<int> & p) {
    if (p[x] == x) {
        return x;
    }
    return p[x] = Find(p[x], p);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    vector<vector<int>> Most(M);
    for (int i = 0; i < M; i++) {
        Most[i].resize(2);
        cin >> Most[i][0] >> Most[i][1];
    }
    int count = 0;
    int s = N - 1;
    for (int i = 0; i < M; ++i) {
        int x = Find(Most[i][0], p);
        int y = Find(Most[i][1], p);
        if (x == y) {
            count++;
        } else {
            p[x] = y;
            s--;
        }
        if (s == 0) {
            break;
        }
    }
    cout << N - 1 + count;
    return 0;
}
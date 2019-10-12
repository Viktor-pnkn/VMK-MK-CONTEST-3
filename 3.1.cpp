#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    const size_t row = N;
    vector<vector<int>> W(row);
    for (size_t i = 0; i < row; ++i) {
        W[i].resize(row);
        for (size_t j = 0; j < row; j++) {
            cin >> W[i][j];
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << W[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
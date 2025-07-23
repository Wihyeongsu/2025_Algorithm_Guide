#include <iostream>
#include <vector>

using namespace std;

int count_m1 = 0;
int count_0 = 0;
int count_1 = 0;

void paper(vector<vector<int>>& mat, int sr, int er, int sc, int ec) {
    int x = mat[sr][sc];
    bool isSame = true;
    for (int i = sr; i <= er; i++) {
        for (int j = sc; j <= ec; j++) {
            if (x != mat[i][j]) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }
    if (isSame) {
        if (x == -1) count_m1++;
        else if (x == 0) count_0++;
        else if (x == 1) count_1++;
    } else {
        int x = (er - sr + 1) / 3;
        int y = (ec - sc + 1) / 3;
        paper(mat, sr, sr + x - 1, sc, sc + y - 1);
        paper(mat, sr, sr + x - 1, sc + y, sc + y * 2 - 1);
        paper(mat, sr, sr + x - 1, sc + y * 2, ec);
        paper(mat, sr + x, sr + x * 2 - 1, sc, sc + y - 1);
        paper(mat, sr + x, sr + x * 2 - 1, sc + y, sc + y * 2 - 1);
        paper(mat, sr + x, sr + x * 2 - 1, sc + y * 2, ec);
        paper(mat, sr + x * 2, er, sc, sc + y - 1);
        paper(mat, sr + x * 2, er, sc + y, sc + y * 2 - 1);
        paper(mat, sr + x * 2, er, sc + y * 2, ec);
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> mat(N, vector<int>(N));

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++)
            cin >> mat[i][j];
    paper(mat, 0, N - 1, 0, N - 1);

    cout << count_m1 << "\n";
    cout << count_0 << "\n";
    cout << count_1 << "\n";

    return 0;
}
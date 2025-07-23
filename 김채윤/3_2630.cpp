#include <iostream>
#include <vector>

using namespace std;

int white = 0;
int black = 0;

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
        if (x == 0) white++;
        else if (x == 1) black++;
    } else {
        if ((er - sr + 1) >= 2) {
            int n = (er - sr + 1) / 2;
            paper(mat, sr, sr + n - 1, sc, sc + n - 1);
            paper(mat, sr, sr + n -1, sc + n, ec);
            paper(mat, sr + n, er, sc, sc + n - 1);
            paper(mat, sr + n, er, sc + n, ec);
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>>  mat(N, vector<int>(N));

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++)
            cin >> mat[i][j];
    
    paper(mat, 0, N - 1, 0, N - 1);

    cout << white << "\n";
    cout << black << "\n";

    return 0;
}

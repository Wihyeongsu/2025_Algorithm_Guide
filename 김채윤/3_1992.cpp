#include <iostream>
#include <vector>

using namespace std;

string ans = "";

void divide(vector<vector<string>>& mat, int sr, int er, int sc, int ec) {
    string x = mat[sr][ec];
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
    if (isSame) ans += x;
    else {
        int d = (er - sr + 1) / 2;
        if (d >= 1) {
            ans += "(";
            divide(mat, sr, sr + d - 1, sc, sc + d - 1);
            divide(mat, sr, sr + d - 1, sc + d, ec);
            divide(mat, sr + d, er, sc, sc + d - 1);
            divide(mat, sr + d, er, sc + d, ec);
            ans += ")";
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<string>> mat(N, vector<string>(N));

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) 
            mat[i][j] = s[j];
    }
    divide(mat, 0, N - 1, 0, N - 1);

    cout << ans;

    return 0;
}
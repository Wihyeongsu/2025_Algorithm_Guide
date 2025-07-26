#include <iostream>

using namespace std;
const int INF = 1000;

int main() {
    int N;
    cin >> N;
    
    int arr[50][50];
    int friend_2[50] = {0};

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == 'N') arr[i][j] = INF;
            else if (s[j] == 'Y') arr[i][j] = 1;
        }
        for (int k = 0; k < N; k++) {
            if (i == k) arr[i][k] = 0;
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }
    int max = 0;
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (arr[j][k] <= 2 && j != k) friend_2[j]++;
        }
        if (max < friend_2[j]) max = friend_2[j];
    }
    
    cout << max;

    return 0;
}
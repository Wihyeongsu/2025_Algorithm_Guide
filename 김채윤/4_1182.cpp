#include <iostream>
using namespace std;

int N, S, sum, total;
int arr[20];

void DFS(int n, int sum) {
    if (N == n) return;
    if (sum + arr[n] == S) total++;
    DFS(n + 1, sum);
    DFS(n + 1, sum + arr[n]);
}

int main() {
    cin >> N >> S;
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    total = 0;
    DFS(0, 0);
    cout << total;

    return 0;
}
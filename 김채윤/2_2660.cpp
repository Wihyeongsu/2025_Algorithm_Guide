#include <iostream>
#include <queue>

using namespace std;
const int INF = 1e9;

int main() {
    int arr[51][51];
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }

    int a = 0, b = 0;
    while (1) {
        cin >> a >> b;

        if (a == -1 && b == -1) break;

        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int j = 1; j <= N; j++) {
        for (int k = 2; k <= N; k++) {
            if (arr[j][1] < arr[j][k]) {
                arr[j][1] = arr[j][k];
            }
        }
        pq.push({arr[j][1], j});
    }

    int count = 1;
    int n = pq.top().first;
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(pq.top().second);
    pq.pop();

    while (!pq.empty() && n == pq.top().first) {
        count++;
        q.push(pq.top().second);
        pq.pop();
    }

    cout << n << " " << count << "\n";
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}
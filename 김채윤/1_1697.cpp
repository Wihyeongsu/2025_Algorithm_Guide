#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
const int MAX = 100000;
int main() {
    int N, K;
    cin >> N >> K;

    queue<int> q;
    int visited[100001] = {0};

    q.push(N);
    visited[N] = 1;

    while (q.empty() == 0) {
        int now = q.front();
        q.pop();

        if (now == K) {
            cout << visited[now] - 1;
            return 0;
        }
        if (now - 1 >= 0 && visited[now - 1] == 0) {
            q.push(now - 1);
            visited[now - 1] = visited[now] + 1;
        }
        if (now + 1 <= MAX && visited[now + 1] == 0) {
            q.push(now + 1);
            visited[now + 1] = visited[now] + 1;
        }
        if (now * 2 <= MAX && visited[now * 2] == 0) {
            q.push(now * 2);
            visited[now * 2] = visited[now] + 1;
        }
    }

    return 0;
}
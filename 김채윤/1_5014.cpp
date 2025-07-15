#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int visited[1000001] = {0};
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> F >> S >> G >> U >> D;

    q.push(S); // 시작점 큐에 넣기
    visited[S] = 1; // 방문 표시 + 버튼 누른 횟수 1로 설정(출력 시 -1)

    while (q.empty() == 0) { // q가 빌 때까지
        int now = q.front(); // 위아래로 갈 수 있는 모든 경우 탐색(BFS)
        q.pop();
        if (now == G) {
            cout << visited[now] - 1;
            return 0;
        }
        if (now + U <= F && visited[now + U] == 0) {
            q.push(now + U);
            visited[now + U] = visited[now] + 1;
        }
        if (now - D >= 1 && visited[now - D] == 0) {
            q.push(now - D);
            visited[now - D] = visited[now] + 1;
        }
    }
    
    cout << "use the stairs";

    return 0;
}

/*
F : 총 층 개수
S : 지금 있는 층 (시작점)
G : 스타트링크가 있는 곳의 층
U : 엘베 위로 이동 층
D : 엘베 아래로 이동 층 층
*/
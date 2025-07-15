#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    deque<int> dq;

    for (int i = 1; i <= N; i++) dq.push_back(i);

    int count = 0;
    for (int j = 0; j < M; j++) {
        int n;
        cin >> n;
        int i = 0;
        for (int x : dq) {
            if (x == n) break;
            i++;
        }

        if (dq.size() - i >= i) {
            count += i;
            while (i--) {
                int m = dq.front();
                dq.push_back(m);
                dq.pop_front();
            }
        } 
        else {
            int k = dq.size() - i;
            count += k;
            while (k--) {
                int m = dq.back();
                dq.push_front(m);
                dq.pop_back();
            }
        }
        dq.pop_front();
    }
    cout << count;

    return 0;
}
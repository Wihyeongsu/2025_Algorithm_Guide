#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[100][100];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][k] && arr[k][j])
                    arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
아래는 잘못된 코드: 
arr[i][i] = INF라고 초기화하면 안 됨
그럼에도 맞은 이유는 우연히 자기 자신 경유가 필요 없는 입력이었기 때문

#include <iostream>

using namespace std;
const int INF = 10000;

int main() {
    int N;
    cin >> N;

    int arr[100][100];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            if (x == 0) arr[i][j] = INF;
            else if (x == 1) arr[i][j] = 1;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }

    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (arr[j][k] == INF) arr[j][k] = 0;
            if (arr[j][k] > 0) arr[j][k] = 1;
        }
        for (int i = 0; i < N; i++) {
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
*/
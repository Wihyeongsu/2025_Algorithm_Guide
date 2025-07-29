#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> card(N);

    for (int i = 0; i < N; i++)
        cin >> card[i];
    
    int max = 0;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (k != i && k != j && i != j) {
                    int sum = card[k] + card[i] + card[j];
                    if (sum <= M && sum > max) max = sum;
                }
            }
        }
    }
    cout << max;

    return 0;
}
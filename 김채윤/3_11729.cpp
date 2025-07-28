#include <iostream>

using namespace std;

void hanoi(int n, int from, int mid, int to) {
    if (n == 1) {
        cout << from << " " << to << "\n";
        return;
    }
    else {
        hanoi(n - 1, from, to, mid);
        cout << from << " " << to << "\n";
        hanoi(n - 1, mid, from, to);
    }
}

int main() {
    int N;
    cin >> N;

    long long move = 1;
    for(int i=0; i<N; ++i) move *= 2;
    move -= 1;

    cout << move << "\n";
    hanoi(N, 1, 2, 3);

    return 0;
}
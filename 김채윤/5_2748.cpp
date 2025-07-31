#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long num1 = 0;
    long long num2 = 1;

    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        long long temp = num2;
        num2 = num1 + num2;
        num1 = temp;
    }

    cout << num2;

    return 0;
}
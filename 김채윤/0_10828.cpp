#include <iostream>

using namespace std;

const int MAX = 10000;
int top2 = -1;
int arr[MAX] = {0};

void push(int x) {
    if (top2 < MAX - 1) arr[++top2] = x;
}
void pop() {
    if (top2 == -1) cout << -1 << "\n";
    else cout << arr[top2--] << "\n";
}
void size() {
    cout << (top2 + 1) << "\n";
}
void empty() {
    if (top2 == -1) cout << 1 << "\n";
    else cout << 0 << "\n";
}
void top() {
    if (top2 == -1) cout << -1 << "\n";
    else cout << arr[top2] << "\n";
}

int main() {
    int n;
    cin >> n;
    string s;
    int m;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "push") {
            cin >> m;
            push(m);
        }
        else if (s == "pop") pop();
        else if (s == "size") size();
        else if (s == "empty") empty();
        else if (s == "top") top();
    }

    return 0;
}


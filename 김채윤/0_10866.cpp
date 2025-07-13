#include <iostream>

using namespace std;

const int MAX = 10000;
int top = -1;
int arr[MAX] = {0};

void push_front(int x) {
    if (top < MAX - 1) {
        top++;
        if (top != -1) {
            for (int i = top; i > 0; i--) {
            arr[i] = arr[i - 1];
            }
        }
        arr[0] = x;
    }
}
void push_back(int x) {
    if (top < MAX - 1)
        arr[++top] = x;
}
void pop_front() {
    if (top == -1) cout << -1 << "\n";
    else {
        cout << arr[0] << "\n";
        for (int i = 0; i < top; i++) {
            arr[i] = arr[i + 1];
        }
        top--;
    }
}
void pop_back() {
    if (top == -1) cout << -1 << "\n";
    else {
        cout << arr[top--] << "\n";
    }
} 
void size() {
    cout << top + 1 << "\n";
}
void empty() {
    if (top == -1) cout << 1 << "\n";
    else cout << 0 << "\n";
}
void front() {
    if (top == -1) cout << -1 << "\n";
    else cout << arr[0] << "\n";
}
void back() {
    if (top == -1) cout << -1 << "\n";
    else cout << arr[top] << "\n";
}


int main() {
    int n;
    cin >> n;
    string s;
    int m;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "push_back") {
            cin >> m;
            push_back(m);
        }
        else if (s == "push_front") {
            cin >> m;
            push_front(m);
        }
        else if (s == "pop_front") pop_front();
        else if (s == "pop_back") pop_back();
        else if (s == "size") size();
        else if (s == "empty") empty();
        else if (s == "front") front();
        else if (s == "back") back();
    }

    return 0;
}


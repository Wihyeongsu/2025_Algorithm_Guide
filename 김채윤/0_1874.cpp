#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> s;
    vector<char> v;
    int n;
    cin >> n;

    int now = 0;
    int arr[100000] = {0};

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x;
    }
    for (int j = 0; j < n; j++) {
        if (arr[j] > now) {
                for (int k = now + 1; k <= arr[j]; k++) {
                    s.push(k);
                    v.push_back('+');
                }
                now = arr[j];
        }

        if (!s.empty() && s.top() == arr[j]) {
            s.pop();
            v.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }
    for (int k = 0; k <= v.size() - 1; k++) {
        cout << v[k] << "\n";
    }
    
    return 0;
}


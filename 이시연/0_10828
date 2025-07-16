#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	stack<int> s;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int X;
			cin >> X;
			s.push(X);
		}
		else if (str == "pop") {
			if (s.size() == 0) cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (str == "size") {
			cout << s.size() << '\n';
		}
		else if (str == "empty") {
			if (s.size() == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (str == "top") {
			if (s.size() == 0) cout << -1 << '\n';
			else cout << s.top() << '\n';
		}
		
	}
	return 0;
}

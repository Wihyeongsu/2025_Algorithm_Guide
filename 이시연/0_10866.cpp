#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	deque<int> d;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push_front") {
			int X;
			cin >> X;
			d.push_front(X);
		}
		else if (str == "push_back") {
			int X;
			cin >> X;
			d.push_back(X);
		}
		else if (str == "pop_front") {
			if (d.size() == 0) cout << -1 << '\n';
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (d.size() == 0) cout << -1 << '\n';
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (str == "size") {
			cout << d.size() << '\n';
		}
		else if (str == "empty") {
			if (d.size() == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (str == "front") {
			if (d.size() == 0) cout << -1 << '\n';
			else cout << d.front() << '\n';
		}
		else if (str == "back") {
			if (d.size() == 0) cout << -1 << '\n';
			else cout << d.back() << '\n';
		}
	}

	return 0;
}

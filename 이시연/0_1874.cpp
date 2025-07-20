#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	stack<int> s;
	vector<char> result;
	int current = 1;
	bool isPossible = true;

	for (int i = 0; i < n; i++) {
		int tar = v[i];

		while (current <= tar) {
			s.push(current++);
			result.push_back('+');
		}

		if (!s.empty() && s.top() == tar) {
			s.pop();
			result.push_back('-');
		}
		else {
			isPossible = false;
			break;
		}
	}

	for (char c : result) {
		if (!isPossible) {
			cout << "NO" << '\n';
			break;
		}
		else {
			cout << c << '\n';
		}

	}

	return 0;
}

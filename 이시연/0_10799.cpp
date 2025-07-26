#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	stack<char> s;
	int result = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else if (str[i] == ')') {
			s.pop();
			if (str[i - 1] == '(') result += s.size();
			else result++;
		}
	}

	cout << result << '\n';

	return 0;
}

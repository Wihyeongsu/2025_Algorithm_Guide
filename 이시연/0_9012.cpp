#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	int* vps = new int[T];
	
	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;

		int count = 0;

		for (char ch : str) {
			if (ch == '(') {
				count++;
			}
			else if (ch == ')') {
				count--;
			}
			if (count < 0) {
				break;
			}
		}
		
		if (count == 0) vps[i] = 1;
		else vps[i] = 0;
	}

	for (int i = 0; i < T; i++) {
		if (vps[i]) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}

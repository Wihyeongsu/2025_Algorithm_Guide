#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, p = 1;
	cin >> N;

	while (p <= N / 2) {
		p *= 2;
	}

	if (N == p) cout << N;
	else cout << (N - p) * 2;

	return 0;
}

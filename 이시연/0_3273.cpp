#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, count = 0;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cin >> x;

	sort(v.begin(), v.end());

	int leftIndex = 0;
	int rightIndex = n - 1;

	while (leftIndex < rightIndex) {
		int sum = v[leftIndex] + v[rightIndex];

		if (sum == x) {
			count++;
			leftIndex++;
			rightIndex--;
		}
		else if (sum > x) rightIndex--;
		else leftIndex++;
	}

	cout << count;
	
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* arr = new int[n * n];
	for (int i = 0; i < n * n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n * n);

	cout << arr[n * n - n];

	return 0;
}

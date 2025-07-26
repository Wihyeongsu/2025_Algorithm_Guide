#include <iostream>
#include <deque>
#include <cstdlib>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int count = 0;

	cin >> N >> M;

	int* arr = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}

	deque<int> d;
	for (int i = 0; i < N; i++) {
		d.push_back(i + 1);
	}

	for (int i = 0; i < M; i++) {
		int tar = arr[i];
		int index = 0;

		for (int j = 0; j < d.size(); j++) {
			if (tar == d[j]) {
				index = j;
				break;
			}
		}

		if (index == 0) {
			d.pop_front();
			continue;
		}
		
		if (index < (d.size() - index)) {
			for (int j = 0; j < index; j++) {
				int front = d.front();
				d.pop_front();
				d.push_back(front);
			}
			count += index;
			d.pop_front();
		}
		else {
			for (int j = 0; j < d.size() - index; j++) {
				int back = d.back();
				d.pop_back();
				d.push_front(back);
			}
			count += d.size() - index;
			d.pop_front();
		}
	}

	cout << count;

	return 0;
}

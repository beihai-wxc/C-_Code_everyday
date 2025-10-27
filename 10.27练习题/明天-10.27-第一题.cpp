#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N;
	int count = 0;
	cin >> N;
	vector <int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				count++;
			}
		}
	}

	cout << count << endl;
	return 0;
}
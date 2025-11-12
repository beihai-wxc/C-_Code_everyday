#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector <int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int count = 0;
	int temp = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				count++;
			}
		}
	}
	cout << count << endl;

	return 0;
}
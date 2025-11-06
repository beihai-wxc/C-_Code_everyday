#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    int avg = sum / n;
    int moves = 0;
    int current = 0;

    for (int i = 0; i < n - 1; ++i) {
        current += a[i] - avg;
        if (current != 0) {
            ++moves;
        }
    }

    cout << moves << endl;
    return 0;
}
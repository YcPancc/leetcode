#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> intervalSum(n + 1, 0);
	int num;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		intervalSum[i] = num + intervalSum[i - 1];
	}
	int l, r;
	while (cin >> l >> r) {
		cout << intervalSum[r + 1] - intervalSum[l] << '\n';
	}
}
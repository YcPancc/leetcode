#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> prefixSum(n + 1, 0);
	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &prefixSum[i]);
		prefixSum[i] += prefixSum[i - 1];
	}
	int l, r;
	while (scanf("%d%d", &l, &r)) {
		printf("%d", prefixSum[r + 1] - prefixSum[l]);
	}
}
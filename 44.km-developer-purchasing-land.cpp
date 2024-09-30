#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<int>> vec(n, vector<int>(m));
	int min;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &vec[i][j]);
			min += vec[i][j];
		}
	}

	if (m > 1) {
		vector<vector<int>> row_vec(n, vector<int>(m + 1, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m + 1; j++) {
				row_vec[i][j] = row_vec[i][j - 1] + vec[i][j - 1];
			}
		}
		int sum;
		for (int i = 1; i < m; i++) {
			sum = 0;
			for (int j = 0; j < n; j++) {
				sum += row_vec[j][m] - 2 * row_vec[j][i];
			}
			if (min > abs(sum)) {
				min = abs(sum);
			}
		}
	}
	if (n > 1) {
		vector<vector<int>> col_vec(n + 1, vector<int>(m, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 1; j < n + 1; j++) {
				col_vec[j][i] = col_vec[j - 1][i] + vec[j - 1][i];
			}
		}
		int sum;
		for (int i = 1; i < n; i++) {
			sum = 0;
			for (int j = 0; j < m; j++) {
				sum += col_vec[n][j] - 2 * col_vec[i][j];
			}
			if (min > abs(sum)) {
				min = abs(sum);
			}
		}
	}
	printf("%d", min);
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
	vector<vector<int>> result;

	void backtracking(vector<int> &vec, const int &start, const int &k, const int &end) {
		for (int i = start; i <= end - k + 1; i++) {
			if (k == 1) {
				result.push_back(vec);
				return;
			}
			vec.push_back(i);
			backtracking(vec, i + 1, k - 1, end);
			vec.pop_back();
		}
	}

  public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> vec;
		backtracking(vec, 1, k, n);
		return result;
	}
};

int main() {
	Solution s;
	s.combine(6, 3);
}
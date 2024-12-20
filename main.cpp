#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
	vector<int> partitionLabels(string s) {
		int dis[26] = {0};
		for (int i = 0; i < s.size(); i++) {
			dis[s[i] - 'a'] = i;
		}
		int cur = 0;
		int start = 0;
		vector<int> result;
		while (cur < s.size()) {
			int max_dis = dis[s[cur] - 'a'];
			for (; cur <= max_dis; cur++) {
				max_dis = max_dis >= dis[s[cur] - 'a'] ? max_dis : dis[s[cur] - 'a'];
			}
			result.push_back(cur - start);
			start = cur;
		}
		return result;
	}
};

int main() {
	Solution s;
	string str = "ababcbacadefegdehijhklij";
	vector<int> result = s.partitionLabels(str);
	for (const int &num : result) {
		cout << num << ' ';
	}
}
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
  public:
	vector<int> partitionLabels(string s) {
		vector<int> arr(26, 0);
		for (int i = 0; i < s.size(); i++) {
			arr[s[i] - 'a'] = i;
		}
		int site;
		vector<int> result;
		int start;
		int i;
		for (i = 0; i < s.size();) {
			start = i;
			site = arr[s[i] - 'a'];
			while (i <= site) {
				if (arr[s[i] - 'a'] > site) {
					site = arr[s[i] - 'a'];
				}
				i++;
			}
			result.push_back(i - start);
		}
		return result;
	}
};

int main() {
	Solution s;
	auto arr = s.partitionLabels("ababcbacadefegdehijhklij");
	for (auto a : arr) {
		cout << a << ' ';
	}
}
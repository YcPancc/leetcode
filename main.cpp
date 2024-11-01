#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
	string reverseStr(string s, int k) {
		int lens = s.size();
		for (int i = 0; i < lens; i += 2 * k) {
			if (i + k > lens) {
				reverse(s, i, lens - 1);
			} else {
				reverse(s, i, i + k - 1);
			}
		}
		return s;
	}

  private:
	void reverse(string &s, int l, int r) {
		char ch;
		while (l < r) {
			ch = s[l];
			s[l] = s[r];
			s[r] = ch;
			l++;
			r--;
		}
	}
};
int main() {
	Solution s;
	cout << s.reverseStr("abcdefg", 2);
}
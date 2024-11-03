#include <bits/stdc++.h>
using namespace std;

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

int main() {
	int n;
	string str;
	cin >> n;
	cin >> str;
	int lens = str.size();
	n = n % lens;
	reverse(str, 0, lens - 1);
	reverse(str, 0, n - 1);
	reverse(str, n, lens - 1);
	cout << str << '\n';
}
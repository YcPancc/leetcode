#include <bits/stdc++.h>
using namespace std;

void reverse(string &str, int l, int r);

int main() {
	int n;
	scanf("%d", &n);
	string str;
	cin >> str;
	n = n % str.length();
	reverse(str, 0, str.length() - 1);
	reverse(str, 0, n - 1);
	reverse(str, n, str.length() - 1);
	cout << str;
}

void reverse(string &str, int l, int r) {
	char tmp;
	while (l < r) {
		tmp = str[l];
		str[l] = str[r];
		str[r] = tmp;
		l++;
		r--;
	}
}
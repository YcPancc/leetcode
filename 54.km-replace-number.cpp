#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin >> str;
	string result;
	for (const char &ch : str) {
		if (ch >= '0' && ch <= '9') {
			result += "number";
		} else {
			result += ch;
		}
	}
	cout << result << '\n';
	return 0;
}
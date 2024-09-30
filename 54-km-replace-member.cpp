#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	char s;
	while (cin >> s) {
		if (s >= '0' && s <= '9')
			printf("%s", "number");
		else
			printf("%c", s);
	}
}
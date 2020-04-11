#include <iostream>
#include <map>
#include <set>
using namespace std;
bool ok[256];
int main() {
	int k, cnt = 1;
	scanf("%d", &k);
	string s;
	cin >> s;
	map<char, bool> m;
	set<char> printed;
	char pre = '#';
	s += '#';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == pre) cnt++;
		else {
			if (cnt % k != 0) ok[pre] = true;
			cnt = 1;
		}
		if (cnt % k == 0) m[s[i]] = true;
		pre = s[i];
	}
	for (int i = 0; i < s.length()-1; i++)
		if (ok[s[i]]) m[s[i]] = false;
	for (int i = 0; i < s.length()-1; i++)
		if (m[s[i]] == true && printed.find(s[i]) == printed.end()) {
			printf("%c", s[i]);
			printed.insert(s[i]);
		}
	printf("\n");
	for (int i = 0; i < s.length()-1; i++) {
		printf("%c", s[i]);
		if (m[s[i]]) i += k - 1;
	}
	return 0;
}

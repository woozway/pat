#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int m, n, s;
	cin >> m >> n >> s;
	string str;
	unordered_map<string, int> mp;
	bool flag = false;
	for (int i = 1; i <= m; i++) {
		cin >> str;
		if (mp[str] == 1) s += 1;
		if (i == s && mp[str] == 0) {
			mp[str] = 1;
			cout << str << endl;
			flag = true;
			s += n;
		}
	}
	if (flag == false) cout << "Keep going...";
	return 0;
}

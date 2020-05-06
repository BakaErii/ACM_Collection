/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-16 14:24:24
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

map<string, set<string>> mp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string strA, strB;
	while (cin >> n) {
		mp.clear();
		while (n > 0) {
			cin >> strA >> strB;
			if (mp[strA].count(strB) != 0) {
				cout << strA << ' ' << strB << endl;
				int t = n - 1;
				while (t--)
					cin >> strA >> strB;
				break;
			}
			mp[strB].insert(strA);
			for (auto it : mp[strA])
				mp[strB].insert(it);
			n--;
		}
		if (n == 0)
			cout << 0 << endl;
	}
	return 0;
}
/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-09-03 16:01:59
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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, num, cnt, ans;
	char ch;
	while (cin >> t) {
		//INIT
		ans = 0;
		cnt = 0;
		for (int i = 0; i < t; i++) {
			cin >> ch;
			switch (ch) {
			case 'C':
				cin >> num;
				if (num != cnt + 1) {
					ans++;
					cnt = 1;
				} else
					cnt++;
				break;
			case 'B':
				cin >> num;
				if (num != cnt + 1) {
					ans++;
					cnt = 1;
				} else
					cnt++;
				break;
			case 'S':
				if (cnt == 0)
					ans++;
				else {
					ans += 2;
					cnt = 0;
				}
				break;
			}
		}
		if (cnt != 0)
			ans++;
		cout << ans << endl;
	}
	return 0;
}
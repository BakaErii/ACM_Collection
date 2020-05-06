/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-20 16:58:11
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

string str;

int main(void) {
	int ans, i, n, status;
	pair<int, int> pos;
	//init
	cin >> n;
	cin >> str;
	pos.first = 0;
	pos.second = 0;
	ans = 0;
	if (str[0] == 'U') {
		pos.first++;
		status = 1;
	} else {
		pos.second++;
		status = 0;
	}
	for (i = 1; i < n; i++) {
		if (str[i] == 'U')
			pos.first++;
		else
			pos.second++;
		if (pos.first == pos.second && i != n - 1) {
			if (str[++i] == 'U') {
				pos.first++;
				if (status == 0) {
					status = 1;
					ans++;
				}
			} else {
				pos.second++;
				if (status == 1) {
					status = 0;
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-02 23:28:18
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
	int t, n, l, r, i, time;
	cin >> t;
	while (t--) {
		cin >> n;
		time = 0;
		for (i = 0; i < n; i++) {
			if (i != 0)
				cout << " ";
			cin >> l >> r;
			if (r > time && l <= time)
				cout << ++time;
			else if (r > time && l > time) {
				time = l;
				cout << time;
			}
			else
				cout << 0;
		}
		cout << endl;
	}
	return 0;
}
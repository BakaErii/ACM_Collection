/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-21 00:00:04
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
	int k;
	long long int ans = 0L;
	cin >> k;
	if (k > 36)
		cout << -1 << endl;
	else {
		while (k >= 2) {
			ans = ans * 10 + 8;
			k -= 2;
		}
		while (k > 0) {
			ans = ans * 10 + 6;
			k--;
		}
		cout << ans << endl;
	}
	return 0;
}
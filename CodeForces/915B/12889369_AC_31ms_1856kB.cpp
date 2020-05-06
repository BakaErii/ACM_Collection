/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-13 21:13:54
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
	int n, pos, l, r, ans = 0;
	cin >> n >> pos >> l >> r;
	if (l == 1 && r == n)
		ans = 0;
	else if (r == n)
		ans = abs(pos - l) + 1;
	else if (l == 1)
		ans = abs(pos - r) + 1;
	else {
		ans += min(abs(pos - l), abs(pos - r));
		ans += r - l;
		ans += 2;
	}
	cout << ans << endl;
	return 0;
}
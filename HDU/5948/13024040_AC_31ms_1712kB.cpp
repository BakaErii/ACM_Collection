/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-14 13:37:02
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
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a >= b)
			cout << a * 2 + b << endl;
		else
			cout << b * 2 + a << endl;
	}
	return 0;
}
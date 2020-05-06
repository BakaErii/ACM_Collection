/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-17 14:39:19
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
	int i, tmp, n, ans = 0;
	int num1 = 0, num2 = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 1)
			num1++;
		else
			num2++;
	}
	ans = min(num1, num2);
	num1 -= ans;
	num2 -= ans;
	if (num1 >= 3)
		ans += num1 / 3;
	cout << ans << endl;
	return 0;
}
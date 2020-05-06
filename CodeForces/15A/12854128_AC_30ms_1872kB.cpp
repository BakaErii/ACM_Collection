/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-01 22:43:37
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

double arr[2005];

int main(void) {
	int i, n, t, ans, x, a;
	//init
	ans = 2;
	cin >> n >> t;
	for (i = 0; i < n; i++) {
		cin >> x >> a;
		arr[i * 2] = x + a / 2.0;
		arr[i * 2 + 1] = x - a / 2.0;
	}
	sort(arr, arr + n * 2);
	for (i = 0; i < n; i++) {
		if (i != 0 && arr[2 * i] - arr[2 * i - 1] > t)
			ans += 2;
		else if (i != 0 && arr[2 * i] - arr[2 * i - 1] == t)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
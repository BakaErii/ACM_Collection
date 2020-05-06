/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-31 23:46:28
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

int arr[1001];

int main(void) {
	int i, j, ans, n, x, a, b;
	//init
	memset(arr, 0, sizeof(arr));
	ans = 233333;
	cin >> n >> x;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		for (j = a; j <= b; j++)
			arr[j]++;
	}
	for (i = 0; i < 1001; i++)
		if (arr[i] == n)
			ans = min(ans, abs(i - x));
	if (ans != 233333)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}
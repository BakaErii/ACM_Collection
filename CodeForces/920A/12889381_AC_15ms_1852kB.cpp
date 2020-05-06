/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-02 22:40:07
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

int arr[200];

int main(void) {
	int  t, n, k, d, ans;
	int i;
	cin >> t;
	while (t--) {
		d = 0;
		cin >> n >> k;
		for (i = 0; i < k; i++)
			cin >> arr[i];
		sort(arr, arr + k);
		for (i = 1; i < k; i++)
			d = max(arr[i] - arr[i - 1] + 1, d);
		if (d % 2 == 0)
			ans = d / 2;
		else
			ans = d / 2 + 1;
		ans = max(arr[0], ans);
		ans = max(n - arr[k - 1] + 1, ans);
		cout << ans << endl;
	}
	return 0;
}
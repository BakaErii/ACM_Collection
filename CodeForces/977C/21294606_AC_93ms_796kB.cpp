/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-14 14:23:39
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

const int maxN = 200005;

int n, k;
int arr[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int ans;
	if (k == 0) {
		ans = arr[0] - 1;
	} else if (k == n) {
		ans = arr[n - 1];
	} else {
		if (arr[k - 1] == arr[k])
			ans = -1;
		else
			ans = arr[k - 1];
	}
	if (ans < 1 || ans > 1e9)
		ans = -1;
	cout << ans << endl;
	return 0;
}
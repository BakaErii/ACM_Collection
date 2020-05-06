/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-08 21:40:12
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

int arr[200005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	unsigned long long int ans;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + 2 * n);
	ans = (unsigned long long int)(arr[n - 1] - arr[0]) * (unsigned long long int)(arr[2 * n - 1] - arr[n]);
	int border = arr[2 * n - 1] - arr[0];
	for (int i = 1; i <= n; i++)
		ans = min(ans, (unsigned long long int)border * (arr[i + n - 1] - arr[i]));
	printf("%llu\n", ans );
	return 0;
}
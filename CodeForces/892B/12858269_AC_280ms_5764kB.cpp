/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-05 12:59:37
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

int arr[1000005];

int main(void) {
	int n, ans, cnt, i;
	//init
	scanf("%d", &n);
	ans = 0;
	cnt = n;
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (i = n - 1; i >= 0; i--) {
		if (i < cnt)
			ans++;
		cnt = min(i - arr[i], cnt);
	}
	printf("%d\n", ans );
	return 0;
}
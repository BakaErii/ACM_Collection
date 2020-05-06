/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-22 12:55:29
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

int arr[5001];

int main(void) {
	int i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (i = 1; i <= n; i++)
		if (i == arr[arr[arr[i]]])
			break;
	if (i == n + 1)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
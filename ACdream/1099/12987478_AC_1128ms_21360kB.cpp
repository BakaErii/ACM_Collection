/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-11 17:11:16
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

int arr[5000000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, n, k;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	nth_element(arr, arr + (n - k), arr + n);
	printf("%d\n", arr[n - k]);
	return 0;
}
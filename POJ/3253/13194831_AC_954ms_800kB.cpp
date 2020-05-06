/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-26 15:08:44
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

int arr[20001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i;
	int aptr, bptr;
	long long int ans;
	scanf("%d", &n);
	//init
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	ans = 0;
	while (n > 1) {
		//arr[aptr]<=arr[bptr]
		aptr = 0;
		bptr = 1;
		if (arr[aptr] > arr[bptr])
			swap(aptr, bptr);
		for (i = 2; i < n; i++)
			if (arr[i] < arr[aptr]) {
				bptr = aptr;
				aptr = i;
			} else if (arr[i] < arr[bptr])
				bptr = i;
		ans += arr[aptr] + arr[bptr];
		if (aptr == n - 1)
			swap(aptr, bptr);
		arr[aptr] = arr[aptr] + arr[bptr];
		arr[bptr] = arr[n - 1];
		n--;
	}
	printf("%lld\n", ans );
	return 0;
}
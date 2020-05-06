/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-09-09 12:40:07
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

int n;
int a, b;
int arr[20];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int times;
	int ans = 0;
	if(n % 2 == 0) {
		times = n / 2;
	} else {
		times = n / 2 + 1;
	}
	for(int i = 0; i < times; i++) {
		if(arr[i] == arr[n - i - 1] && arr[i] == 2) {
			if(i == n - i - 1)
				ans += min(a, b);
			else
				ans += 2 * min(a, b);
		} else if(arr[i] == 2 || arr[n - i - 1] == 2) {
			if(arr[i] == 0 || arr[n - i - 1] == 0)
				ans += a;
			else
				ans += b;
		} else if(arr[i] != arr[n - i - 1]) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", ans );
	return 0;
}
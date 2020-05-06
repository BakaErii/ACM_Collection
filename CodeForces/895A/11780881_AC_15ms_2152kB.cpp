/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-30 16:57:15
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

int arr[360];

int main(void) {
	int x, i, j, ans, n;
	//ans=|x - (360 - x)| = |2 * x - 360| = 2 * |x - 180|
	ans = 360;
	i = 0;
	j = 0;
	x = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	i = 0;
	while (i < n) {
		x += arr[i++];
		while (x > 180){
			ans = min(ans, 2 * abs(x - 180));
			x -= arr[j++];
		}
		ans = min(ans, 2 * abs(x - 180));
	}
	printf("%d\n",ans );
	return 0;
}
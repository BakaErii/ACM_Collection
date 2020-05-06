/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-20 16:48:58
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

int main(void) {
	int i, n, ans = 0;
	scanf("%d", &n);
	for (i = 1; i < n; i++)
		if ((n - i) % i == 0)
			ans++;
	printf("%d\n", ans );
	return 0;
}
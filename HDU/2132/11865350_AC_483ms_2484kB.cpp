/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-06 16:18:08
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

__int64 ans[100001];

int main(void) {
	__int64 i;
	//计算数组
	ans[1] = 1;
	for (i = 2; i <= 100000; i++) {
		if (i % 3 == 0)
			ans[i] = ans[i - 1] + i * i * i;
		else
			ans[i] = ans[i - 1] + i;
	}
	while (cin >> i && i >= 0)
		printf("%I64d\n", ans[i] );
	return 0;
}
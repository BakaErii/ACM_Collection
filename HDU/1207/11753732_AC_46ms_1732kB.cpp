/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-28 16:36:21
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

#define MAX 99999999

using namespace std;

int ans[65];

int main(void) {
	int i, x, n, flag;
	ans[1] = 1;
	ans[2] = 3;
	for (i = 3; i <= 65; i++) {
		flag = MAX;
		for (x = 1; x < i; x++) {
			if ((2 * ans[x] + pow(2, i - x) - 1) < flag)
				flag = 2 * ans[x] + (int) pow(2, i - x) - 1;
		}
		ans[i] = flag;
	}
	while (cin >> n)
		cout << ans[n] << endl;
	return 0;
}
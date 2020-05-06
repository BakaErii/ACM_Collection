/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-02 16:39:45
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

const int maxN = 35;

struct Wood
{
	int length, width, height;
	bool operator < (const Wood & a) const {
		if (length == a.length)
			return width > a.width;
		return length > a.length;
	}
} W[maxN * 3];

int woodCnt;
int arrDp[maxN * 3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, kase = 0;
	int a, b, c, ans, tmp;
	while (~scanf("%d", &n) && n != 0) {
		// INIT
		woodCnt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &a, &b, &c);
			W[woodCnt++] = {max(a, b), min(a, b), c};
			W[woodCnt++] = {max(a, c), min(a, c), b};
			W[woodCnt++] = {max(b, c), min(b, c), a};
		}
		sort(W, W + woodCnt);
		arrDp[0] = W[0].height;
		ans = arrDp[0];
		for (int i = 1; i < woodCnt; i++) {
			arrDp[i] = W[i].height;
			tmp = 0;
			for (int j = 0; j < i; j++)
				if (W[i].length < W[j].length && W[i].width < W[j].width)
					tmp = max(tmp, arrDp[j]);
			arrDp[i] += tmp;
			ans = max(ans, arrDp[i]);
		}
		printf("Case %d: maximum height = %d\n", ++kase, ans);
	}
	return 0;
}
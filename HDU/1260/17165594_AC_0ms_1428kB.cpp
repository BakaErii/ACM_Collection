/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-24 17:08:16
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

const int maxN = 2005;

int arr[maxN];
int arrAdj[maxN];
int arrDp[maxN];
int n;

int DP(void) {
	for (int i = 2; i <= n; i++)
		arrDp[i] = min(arrDp[i - 1] + arr[i], arrDp[i - 2] + arrAdj[i - 1]);
	return arrDp[n];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		for (int i = 1; i <= n - 1; i++)
			scanf("%d", &arrAdj[i]);
		arrDp[0] = 0;
		arrDp[1] = arr[1];
		int time = DP();
		int h, m, s;
		h = time / 3600;
		h += 8;
		h %= 24;
		time %= 3600;
		m = time / 60;
		time %= 60;
		s = time;
		if (h < 13)
			printf("%02d:%02d:%02d am\n", h, m, s);
		else
			printf("%02d:%02d:%02d pm\n", h - 12, m, s);
	}
	return 0;
}
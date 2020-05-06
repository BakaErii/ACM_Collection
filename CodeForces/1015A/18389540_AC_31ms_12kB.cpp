/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-07-31 22:09:20
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

int n, m;
bool vis[105];
int cnt;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l, r;
	memset(vis, 0, sizeof(vis));
	scanf("%d %d", &n, &m);
	cnt = m;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l, &r);
		for (int j = l; j <= r; j++) {
			if (vis[j] == false)
				cnt--;
			vis[j] = true;
		}
	}
	printf("%d\n", cnt );
	bool isFirst = true;
	for (int i = 1; i <= m; i++)
		if (vis[i] == false) {
			if (isFirst == false)
				putchar(' ');
			isFirst = false;
			printf("%d", i);
		}
	putchar('\n');
	return 0;
}
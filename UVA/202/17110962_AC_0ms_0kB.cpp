/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-21 12:21:21
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

const int maxN = 10005;

int arr[maxN];
int vis[maxN];
int a, b, cnt, res;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d %d", &a, &b)) {
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		memset(arr, 0, sizeof(arr));
		printf("%d/%d = %d.", a, b, a / b );
		a = a % b;
		while (vis[a] == 0) {
			arr[++cnt] = (a * 10) / b;
			vis[a] = cnt;
			a = a * 10 % b;
		}
		for (int i = 1; i <= cnt && i <= 50; i++) {
			if (i == vis[a])
				putchar('(');
			printf("%d", arr[i] );
			if (i == 50)
				printf("...");
		}
		printf(")\n   %d = number of digits in repeating cycle\n\n", cnt - vis[a] + 1);
	}
	return 0;
}

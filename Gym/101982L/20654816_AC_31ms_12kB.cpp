/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-22 15:45:50
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

struct Section
{
	int l, r;
} S[1005];

int n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &S[i].l, &S[i].r);
	for (int i = 1000; i >= 0; i--) {
		int ans = 0;
		for (int j = 0; j < n; j++)
			if (S[j].l <= i && i <= S[j].r)
				ans++;
		if (ans == i) {
			printf("%d\n", i );
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-24 15:11:09
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

const int maxN = 100005;

int n;
int arrSum[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l, r;
	while (~scanf("%d", &n) && n != 0) {
		memset(arrSum, 0, sizeof(arrSum));
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &l, &r);
			arrSum[l]++;
			arrSum[r + 1]--;
		}
		printf("%d", arrSum[1]);
		for (int i = 2; i <= n; i++) {
			arrSum[i] = arrSum[i] + arrSum[i - 1];
			printf(" %d", arrSum[i]);
		}
		putchar('\n');
	}
	return 0;
}
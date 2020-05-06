/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-09 08:29:03
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

const int maxN = 200005 << 1;

int arr[maxN];

int find(int x) {
	if (arr[x] == x)
		return x;
	arr[x] = find(arr[x]);
	return arr[x];
}

void merge(int a, int b) {
	int tmpa = find(a);
	int tmpb = find(b);
	arr[tmpa] = tmpb;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q, x, y, ans = 0;
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n + m; i++)
		arr[i] = i;
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &x, &y);
		merge(x, n + y);
	}
	for (int i = 1; i <= n + m; i++)
		if (find(i) == i)
			ans++;
	printf("%d\n", ans - 1 );
	return 0;
}
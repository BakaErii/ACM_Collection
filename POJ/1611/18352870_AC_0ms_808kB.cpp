/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-21 16:39:25
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

const int maxN = 30005;

int n, m;
int arrSet[maxN];

void Init() {
	for (int i = 0; i < n; i++)
		arrSet[i] = i;
	return;
}

int FindSet(int x) {
	return x == arrSet[x] ? x : arrSet[x] = FindSet(arrSet[x]);
}

void MergeSet(int a, int b) {
	int tmpA = FindSet(a);
	int tmpB = FindSet(b);
	if (tmpA > tmpB)
		swap(tmpA, tmpB);
	if (tmpA != tmpB)
		arrSet[tmpB] = tmpA;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num, u, v, ans;
	while (~scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0)
			break;
		ans = 0;
		Init();
		for (int i = 0; i < m; i++) {
			scanf("%d", &num);
			if (num == 0)
				continue;
			scanf("%d", &u);
			for (int j = 1; j < num; j++) {
				scanf("%d", &v);
				MergeSet(u, v);
				u = v;
			}
		}
		for (int i = 0; i < n; i++)
			if (FindSet(i) == 0)
				ans++;
		printf("%d\n", ans );
	}
	return 0;
}
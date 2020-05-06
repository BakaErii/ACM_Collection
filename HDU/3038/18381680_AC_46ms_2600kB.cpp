/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-23 15:13:11
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

const int maxN = 200005;

int arrSet[maxN];
int arrVal[maxN];

int n, m;

void Init() {
	for (int i = 0; i <= n; i++) {
		arrSet[i] = i;
		arrVal[i] = 0;
	}
	return;
}

int FindSet(int x) {
	if (arrSet[x] == x)
		return x;
	int root = FindSet(arrSet[x]);
	arrVal[x] += arrVal[arrSet[x]];
	arrSet[x] = root;
	return arrSet[x];
}

bool MergeSet(int a, int b, int val) {
	int tmpA = FindSet(a);
	int tmpB = FindSet(b);
	if (tmpA != tmpB) {
		arrSet[tmpB] = tmpA;
		arrVal[tmpB] = -arrVal[b] + arrVal[a] + val;
	} else if (arrVal[a] + val != arrVal[b])
		return true;
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, s, ans;
	while (~scanf("%d %d", &n, &m)) {
		ans = 0;
		Init();
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &s);
			a--;
			if (MergeSet(a, b, s) == true)
				ans++;
		}
		printf("%d\n", ans );
	}
	return 0;
}
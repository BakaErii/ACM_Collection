/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-02 17:23:10
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

const int maxN = 30;

struct Edge
{
	int u, v, val;
} E[maxN * maxN];

int edgeCnt, ans;

bool cmp(Edge a, Edge b) {
	return a.val < b.val;
}

int arrSet[maxN];

void Init() {
	edgeCnt = 0;
	ans = 0;
	for (int i = 0; i < maxN; i++)
		arrSet[i] = i;
	return;
}

int FindSet(int x) {
	if (arrSet[x] == x)
		return x;
	arrSet[x] = FindSet(arrSet[x]);
	return arrSet[x];
}

void MergeSet(int a, int b) {
	int tmpA = FindSet(a);
	int tmpB = FindSet(b);
	if (tmpA != tmpB)
		arrSet[tmpB] = tmpA;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, u, v, val, num;
	char ch[10];
	while (~scanf("%d", &n) && n != 0) {
		// INIT
		Init();
		n--;
		while (n--) {
			scanf("%s %d", ch, &num);
			u = ch[0] - 'A' + 1;
			for (int i = 0; i < num; i++) {
				scanf("%s %d", ch, &val);
				v = ch[0] - 'A' + 1;
				E[edgeCnt++] = {u, v, val};
			}
		}
		// Solve
		sort(E, E + edgeCnt, cmp);
		for (int i = 0; i < edgeCnt; i++)
			if (FindSet(E[i].u) != FindSet(E[i].v)) {
				MergeSet(E[i].u, E[i].v);
				ans += E[i].val;
			}
		printf("%d\n", ans );
	}
	return 0;
}
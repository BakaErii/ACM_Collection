/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-19 00:25:24
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

char str[maxN][9];
int arrSet[maxN];

int findSet(int x) {
	if (arrSet[x] == x)
		return x;
	arrSet[x] = findSet(arrSet[x]);
	return arrSet[x];
}

void merge(int a, int b) {
	int tmpA = findSet(a);
	int tmpB = findSet(b);
	if (tmpA != tmpB)
		arrSet[tmpB] = tmpA;
	return;
}

struct Edge
{
	int u, v;
	int val;
} E[maxN * maxN];

bool cmp(Edge a, Edge b) {
	return a.val < b.val;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, edgeCnt, cost;
	while (~scanf("%d", &t) && t != 0) {
		getchar();
		// INIT
		edgeCnt = 0;
		cost = 0;
		for (int i = 0; i < t; i++) {
			gets(str[i]);
			arrSet[i] = i;
		}
		for (int i = 0; i < t; i++)
			for (int j = i + 1; j < t; j++) {
				int dis = 0;
				for (int k = 0; k < 7; k++)
					if (str[i][k] != str[j][k])
						dis++;
				E[edgeCnt++] = {i, j, dis};
			}
		sort(E, E + edgeCnt, cmp);
		for (int i = 0; i < edgeCnt; i++)
			if (findSet(E[i].u) != findSet(E[i].v)) {
				merge(E[i].u, E[i].v);
				cost += E[i].val;
			}
		printf("The highest possible quality is 1/%d.\n", cost );
	}
	return 0;
}
/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-21 23:13:40
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

int n, m;
int arrSet[maxN];
int arrPer[maxN];

void Init() {
	for (int i = 0; i <= n; i++) {
		arrSet[i] = i;
		arrPer[i] = 0;
	}
	return;
}

int FindSet(int x) {
	if (arrSet[x] == x)
		return x;
	int per = arrSet[x];
	arrSet[x] = FindSet(arrSet[x]);
	arrPer[x] = (arrPer[x] + arrPer[per]) % 2;
	return arrSet[x];
}

void MergeSet(int a, int b) {
	int tmpA = FindSet(a);
	int tmpB = FindSet(b);
	if (tmpA != tmpB) {
		arrSet[tmpB] = tmpA;
		arrPer[tmpB] = (arrPer[a] + arrPer[b] + 1) % 2;
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, x, y, kase = 0;
	bool isHomo;
	scanf("%d", &t);
	while (t--) {
		isHomo = false;
		scanf("%d %d", &n, &m);
		Init();
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			if (FindSet(x) != FindSet(y))
				MergeSet(x, y);
			else {
				if (arrPer[x] == arrPer[y])
					isHomo = true;
			}
		}
		printf("Scenario #%d:\n", ++kase );
		if (isHomo)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");
		putchar('\n');
	}
	return 0;
}
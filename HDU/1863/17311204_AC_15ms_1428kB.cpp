/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-12-04 19:18:17
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

int n, m, cost;
int arrSet[105];

struct Edge {
	int u, v, val;
} E[100005];

bool cmp(Edge a, Edge b) {
	return a.val < b.val;
}

void Init(void) {
	cost = 0;
	for(int i = 1; i <= m; i++)
		arrSet[i] = i;
	return;
}

int find(int x) {
	if(arrSet[x] == x)
		return x;
	else
		arrSet[x] = find(arrSet[x]);
	return arrSet[x];
}

void unionSet(int a, int b) {
	int ap = find(a);
	int bp = find(b);
	if(ap != bp)
		arrSet[bp] = ap;
	return;
}

bool Kruskal(void) {
	int linkedEdge = 0;
	for(int i = 0; i < n; i++)
		if(find(E[i].u) != find(E[i].v)) {
			unionSet(E[i].u, E[i].v);
			cost += E[i].val;
			linkedEdge++;
		}
	if(linkedEdge < m - 1)
		return false;
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(~scanf("%d %d", &n, &m)) {
		if(n == 0)
			break;
		Init();
		for(int i = 0; i < n; i++)
			scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].val);
		sort(E, E + n, cmp);
		if(Kruskal() == false)
			printf("?\n");
		else
			printf("%d\n", cost );
	}
	return 0;
}
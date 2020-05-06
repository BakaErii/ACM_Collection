/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-12-06 19:19:53
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

const int maxN = 10000005;

int arrSet[maxN];
bool vis[maxN];
long int arrSum[maxN];
set<int> boySt;

int findSet(int x) {
	if(arrSet[x] == x)
		return x;
	else
		arrSet[x] = findSet(arrSet[x]);
	return arrSet[x];
}

void unionSet(int a, int b) {
	int ap = findSet(a);
	int bp = findSet(b);
	if(ap != bp) {
		arrSet[bp] = ap;
		arrSum[ap] += arrSum[bp];
	}
	return;
}

void init(void) {
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < maxN; i++) {
		arrSet[i] = i;
		arrSum[i] = 1;
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	while(~scanf("%d", &n)) {
		init();
		while(n--) {
			scanf("%d %d", &a, &b);
			unionSet(a, b);
			vis[a] = true;
			vis[b] = true;
		}
		long int maxAns = 1;
		for(int i = 0; i < maxN; i++)
			if(vis[i] == true)
				maxAns = max(maxAns, arrSum[i]);
		printf("%ld\n", maxAns);
	}
	return 0;
}
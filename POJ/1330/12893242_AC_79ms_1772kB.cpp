/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-04 15:00:38
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

vector<int> node[10001];
vector<int> fptr, deep;

void dfs(int curNode, int curDeep) {
	deep[curNode] = curDeep;
	for (int i = 1; i <= node[curNode][0]; i++) {
		dfs(node[curNode][i],  curDeep + 1);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, t, n, curFptr, curNode, curPtrA, curPtrB;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		fptr.clear();
		deep.clear();
		for (i = 0; i <= n; i++) {
			node[i].clear();
			node[i].push_back(0);
			fptr.push_back(0);
			deep.push_back(0);
		}
		for (i = 0; i < n - 1; i++) {
			scanf("%d %d", &curFptr, &curNode);
			node[curFptr][0]++;
			node[curFptr].push_back(curNode);
			fptr[curNode] = curFptr;
		}
		for (i = 1; i <= n; i++)
			if (fptr[i] == 0)
				dfs(i, 0);
		scanf("%d %d", &curPtrA, &curPtrB);
		while (curPtrA != curPtrB)
			if (deep[curPtrA] >= deep[curPtrB])
				curPtrA = fptr[curPtrA];
			else
				curPtrB = fptr[curPtrB];
		printf("%d\n", curPtrA );
	}
	return 0;
}
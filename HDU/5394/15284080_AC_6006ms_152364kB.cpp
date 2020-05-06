/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-08 13:30:56
 *
 */

#pragma comment(linker, "/STACK:1024000000,1024000000")

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

const int maxN = 2e6 + 5;
const int size = 4;

struct PalindromicTree {
	int nextPtr[maxN][size];
	int failPtr[maxN];
	unsigned long long int cnt[maxN];
	int strLen[maxN];
	int ch[maxN];
	int lastPtr[maxN];
	int strPtr, nodePtr;
	int addNode(int len) {
		for (int i = 0; i < size; i++)
			nextPtr[nodePtr][i] = 0;
		cnt[nodePtr] = 0;
		strLen[nodePtr] = len;
		return nodePtr++;
	}
	void init(void) {
		strPtr = 0;
		nodePtr = 0;
		addNode(0);
		addNode(-1);
		lastPtr[0] = 0;
		ch[0] = -1;
		failPtr[0] = 1;
		return;
	}
	int getFail(int x) {
		while (ch[strPtr - strLen[x] - 1] != ch[strPtr])
			x = failPtr[x];
		return x;
	}
	unsigned long long int add(int dep, int c) {
		strPtr = dep;
		ch[strPtr] = c;
		int curr = getFail(lastPtr[strPtr - 1]);
		if (!nextPtr[curr][c]) {
			int nowPtr = addNode(strLen[curr] + 2);
			failPtr[nowPtr] = nextPtr[getFail(failPtr[curr])][c];
			nextPtr[curr][c] = nowPtr;
			cnt[nowPtr] = cnt[failPtr[nowPtr]] + strLen[nowPtr];
		}
		lastPtr[strPtr] = nextPtr[curr][c];
		return cnt[lastPtr[strPtr]];
	}
	void count(void) {
		for (int i = nodePtr - 1; i >= 0; i--)
			cnt[failPtr[i]] += cnt[i];
	}
} PTree;

char str[maxN];
int head[maxN];
int v[maxN];
int nextArr[maxN];
int tot;
unsigned long long int ans;

void DFS(int dep, int u) {
	for (int i = head[u]; i != -1; i = nextArr[i]) {
		ans += PTree.add(dep, str[v[i]] - 'a');
		DFS(dep + 1, v[i]);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		PTree.init();
		memset(head, -1, sizeof(head));
		tot = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%s%d",str + i, &x);
			v[tot] = i;
			nextArr[tot] = head[x];
			head[x] = tot++;
		}
		ans = 0;
		DFS(1, 0);
		printf("%llu\n", ans );
	}
	return 0;
}
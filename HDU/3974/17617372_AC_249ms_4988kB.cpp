/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-02 12:42:05
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

#define leftSon left,mid,curr<<1
#define rightSon mid+1,right,curr<<1|1

using namespace std;

const int maxN = 50005;
struct DisNode
{
	int l, r;
} disArr[maxN];
vector<int> vet[maxN];
int segTree[maxN << 2];
int lazyTag[maxN << 2];
int fatherArr[maxN];
int discnt;

inline void DFS(int id) {
	disArr[id].l = discnt++;
	for (int i = 0; i < (int)vet[id].size(); i++)
		DFS(vet[id][i]);
	disArr[id].r = discnt - 1;
	return;
}

void pushDown(int curr) {
	if (lazyTag[curr] != -1) {
		lazyTag[curr << 1] = lazyTag[curr];
		lazyTag[curr << 1 | 1] = lazyTag[curr];
		segTree[curr << 1] = lazyTag[curr];
		segTree[curr << 1 | 1] = lazyTag[curr];
		lazyTag[curr] = -1;
	}
	return;
}

void buildTree(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == right) {
		segTree[curr] = -1;
		return;
	}
	buildTree(leftSon);
	buildTree(rightSon);
	return;
}

void updateSection(int leftSection, int rightSection, int val, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection) {
		lazyTag[curr] = val;
		return;
	}
	pushDown(curr);
	if (leftSection <= mid)
		updateSection(leftSection, rightSection, val, leftSon);
	if (rightSection > mid)
		updateSection(leftSection, rightSection, val, rightSon);
	return;
}

int queryNode(int node, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == right) {
		if (lazyTag[curr] != -1)
			segTree[curr] = lazyTag[curr];
		return segTree[curr];
	}
	pushDown(curr);
	if (node <= mid)
		return queryNode(node, leftSon);
	else
		return queryNode(node, rightSon);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, arg0, arg1, u, v;
	char ch[10];
	scanf("%d", &t);
	for (int kase = 1; kase <= t; kase++) {
		// INIT
		discnt = 1;
		memset(fatherArr, 0, sizeof(fatherArr));
		memset(vet, 0, sizeof(vet));
		memset(lazyTag, -1, sizeof(lazyTag));
		// DataIn
		printf("Case #%d:\n", kase);
		scanf("%d", &n);
		for (int i = 0; i < n - 1; i++) {
			scanf("%d %d", &u, &v);
			fatherArr[u] = v;
			vet[v].push_back(u);
		}
		// Deal data & Build tree
		for (int i = 1; i <= n; i++)
			if (fatherArr[i] == 0)
				DFS(i);
		buildTree(1, n, 1);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			// Query
			scanf("%s", ch);
			switch (ch[0]) {
			case 'C':
				scanf("%d", &arg0);
				printf("%d\n", queryNode(disArr[arg0].l, 1, n, 1));
				break;
			case 'T':
				scanf("%d %d", &arg0, &arg1);
				updateSection(disArr[arg0].l, disArr[arg0].r, arg1, 1, n, 1);
				break;
			}
		}
	}
	return 0;
}

// 1 
// 5 
// 4 3 
// 3 2 
// 1 3 
// 5 2 
// 5 
// C 3 
// T 2 1
// C 3 
// T 3 2 
// C 3

// Case #1:
// -1 
// 1 
// 2
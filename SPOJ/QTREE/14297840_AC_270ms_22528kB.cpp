/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-06-14 19:53:28
 * 树链剖分
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
const int maxM = 100005;

int father[maxN];
int son[maxN];
int deep[maxN];
int top[maxN];
int size[maxN];
int pos[maxN];
int edge[maxN][8];

int ed[maxM], pre[maxM], now[maxN], v[maxM];
int n, cnt, tot;

void build(int a, int b, int c) {
	pre[++tot] = now[a];
	now[a] = tot;
	ed[tot] = b;
	v[tot] = c;
	return;
}

//第一遍DFS求Deep Size Son
void DFS(int x) {
	size[x] = 1;
	son[x] = 0;
	for (int i = now[x]; i; i = pre[i])
		if (ed[i] != father[x]) {
			int tmp = ed[i];
			father[tmp] = x;
			deep[tmp] = deep[x] + 1;
			DFS(tmp);
			if (size[tmp] > size[son[x]])
				son[x] = tmp;
			size[x] += size[tmp];
		}
	return;
}

void reDFS(int x, int currTop) {
	pos[x] = ++cnt;
	top[x] = currTop;
	if (son[x])
		reDFS(son[x], currTop);
	for (int i = now[x]; i; i = pre[i])
		if (ed[i] != father[x] && ed[i] != son[x])
			reDFS(ed[i], ed[i]);
	return;
}

//线段树部分

int tree[maxN * 7];

void pushUp(int curr) {
	tree[curr] = max(tree[curr << 1], tree[curr << 1 | 1]);
	return;
}

void updateNode(int traget, int value, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == traget && right == traget) {
		tree[curr] = value;
		return;
	}
	if (traget <= mid)
		updateNode(traget, value, leftSon);
	else
		updateNode(traget, value, rightSon);
	pushUp(curr);
	return;
}

int querySection(int leftSection, int rightSection, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection == left && rightSection == right)
		return tree[curr];
	if (rightSection <= mid)
		return querySection(leftSection, rightSection, leftSon);
	else if (leftSection > mid)
		return querySection(leftSection, rightSection, rightSon);
	else
		return max(querySection(leftSection, mid, leftSon), querySection(mid + 1, rightSection, rightSon));
}

int getAns(int aPos, int bPos) {
	int aTop = top[aPos];
	int bTop = top[bPos];
	int ans = 0;
	while (aTop != bTop) {
		if (deep[aTop] < deep[bTop]) {
			swap(aTop, bTop);
			swap(aPos, bPos);
		}
		ans = max(ans, querySection(pos[aTop], pos[aPos], 1, cnt, 1));
		aPos = father[aTop];
		aTop = top[aPos];
	}
	if (aPos == bPos)
		return ans;
	if (deep[aPos] > deep[bPos])
		swap(aPos, bPos);
	return max(ans, querySection(pos[son[aPos]], pos[bPos], 1, cnt, 1));
}

void init(void) {
	int root = 1;
	int a, b, c, n;
	scanf("%d", &n);
	memset(now, 0, sizeof(int) * (n + 1));
	memset(tree, 0, sizeof(int) * (n + 1) * 7);
	tot = 0;
	cnt = 0;
	deep[root] = 0;
	father[root] = 0;
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[i][0] = a;
		edge[i][1] = b;
		edge[i][2] = c;
		build(a, b, c);
		build(b, a, c);
	}
	DFS(root);
	reDFS(root, root);
	for (int i = 1; i < n; i++) {
		if (deep[edge[i][0]] > deep[edge[i][1]])
			swap(edge[i][0], edge[i][1]);
		updateNode(pos[edge[i][1]], edge[i][2], 1, cnt, 1);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char str[10];
	int a, b, t;
	scanf("%d", &t);
	while (t--) {
		init();
		while (~scanf("%s", str) && str[0] != 'D') {
			scanf("%d %d", &a, &b);
			if (str[0] == 'Q')
				printf("%d\n", getAns(a, b));
			else
				updateNode(pos[edge[a][1]], b, 1, cnt, 1);
		}
	}
	return 0;
}
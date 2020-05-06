/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-28 13:37:53
 * 线段树 大区间问题 + 离散化 + 区间更新
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

const int maxN = 40005;

int arrRaw[maxN];	// 原数组
int disIdx[maxN];	// 离散化下标

// 海报
struct Post
{
	int left, right;
} post[maxN << 1];

// 线段树节点
struct Node
{
	int left, right;
	int value, lazyTag;
	// 更新LazyTag节点
	void update(int x) {
		value = (right - left + 1) * x;
		lazyTag = x;
		return;
	}
} node[maxN << 2];

// 向下更新LazyTag
void pushDown(int curr) {
	if (node[curr].lazyTag != 0) {
		node[curr << 1].update(node[curr].lazyTag);
		node[curr << 1 | 1].update(node[curr].lazyTag);
		node[curr].lazyTag = 0;
	}
	return;
}

// 向上更新
void pushUp(int curr) {
	node[curr].value = max(node[curr << 1].value, node[curr << 1 | 1].value);
	return;
}

// 建树
void buildTree(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	node[curr].left = left;
	node[curr].right = right;
	node[curr].value = 0;
	node[curr].lazyTag = 0;
	if (left == right) {
		node[curr].value = arrRaw[left];
		return;
	}
	buildTree(leftSon);
	buildTree(rightSon);
	pushUp(curr);
	return;
}

// 区间更新
void updateSection(int leftSection, int rightSection, int value, int curr) {
	if(leftSection>node[curr].right||rightSection<node[curr].left) return;
	if (leftSection <= node[curr].left && node[curr].right <= rightSection) {
		node[curr].update(value);
		return;
	}
	pushDown(curr);
	updateSection(leftSection, rightSection, value, curr << 1);
	updateSection(leftSection, rightSection, value, curr << 1 | 1);
	pushUp(curr);
	return;
}

// 区间查询
int querySection(int leftSection, int rightSection, int curr) {
	if (rightSection < node[curr].left || node[curr].right < leftSection) return 0;
	if (leftSection <= node[curr].left && node[curr].right <= rightSection)
		return node[curr].value;
	pushDown(curr);
	int leftValue = querySection(leftSection, rightSection, curr << 1);
	int rightValue = querySection(leftSection, rightSection, curr << 1 | 1);
	pushUp(curr);
	return max(leftValue, rightValue);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, t, cnt, ansCnt;
	scanf("%d", &t);
	while (t--) {
		//INIT
		cnt = 0;
		ansCnt = 0;
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d %d", &post[i].left, &post[i].right);
			disIdx[cnt++] = post[i].left;
			disIdx[cnt++] = post[i].left - 1;
			disIdx[cnt++] = post[i].right;
			disIdx[cnt++] = post[i].right + 1;
		}
		sort(disIdx, disIdx + cnt);
		cnt = unique(disIdx, disIdx + cnt) - disIdx;	// 去重
		buildTree(1, cnt, 1);	// 建树
		for (int i = 1; i <= m; i++) {
			// 取到post[i]对应离散化后的值
			int leftSection = lower_bound(disIdx, disIdx + cnt, post[i].left) - disIdx + 1;
			int rightSection = lower_bound(disIdx, disIdx + cnt, post[i].right) - disIdx + 1;
			// 区间更新
			updateSection(leftSection, rightSection, i, 1);
		}
		// 遍历区间内的所有值
		for (int i = 1; i <= cnt; i++) {
			int tmpQuery = querySection(i, i, 1);
			if (tmpQuery > 0)
				disIdx[ansCnt++] = tmpQuery;
		}
		sort(disIdx, disIdx + ansCnt);
		printf("%d\n",unique(disIdx,disIdx+ansCnt)-disIdx);
	}
	return 0;
}
/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-23 13:19:44
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

#define leftSon left,mid,cur<<1
#define rightSon mid+1,right,cur<<1|1

const int maxN = 50005;

struct Node
{
	int sum;			// 当前节点的区间和
	int per;			// 当前节点的最大前缀和(前子段和)
	int suf;			// 当前节点的最大后缀和(后子段和)
	int con;			// 当前节点的最大子段和
} T[maxN << 2];

int n, q, l, r;

// 向上更新
void PushUp(int cur) {
	// 更新区间和
	T[cur].sum = T[cur << 1].sum + T[cur << 1 | 1].sum;
	// 更新前缀和(左区间前缀 或者 右区间前缀+左区间和)
	T[cur].per = max(T[cur << 1].per, T[cur << 1].sum + T[cur << 1 | 1].per);
	// 更新后缀和(同理)
	T[cur].suf = max(T[cur << 1 | 1].suf, T[cur << 1].suf + T[cur << 1 | 1].sum);
	// 更新最大子段和 两种情况
	// 1.单独在左右区间内
	T[cur].con = max(T[cur << 1].con, T[cur << 1 | 1].con);
	// 2.在合并的区间中(左区间后缀+右区间前缀)
	T[cur].con = max(T[cur].con, T[cur << 1].suf + T[cur << 1 | 1].per);
	return;
}

// 建树
void BuildTree(int left, int right, int cur) {
	int mid = (left + right) >> 1;
	if (left == right) {
		scanf("%d", &T[cur].sum);
		T[cur].suf = T[cur].per = T[cur].con = T[cur].sum;
		return;
	}
	BuildTree(leftSon);
	BuildTree(rightSon);
	PushUp(cur);
	return;
}

// 查询
Node QuerySection(int leftSection, int rightSection, int left, int right, int cur) {
	int mid = (left + right) >> 1;
	// 当前节点完全在查询区间内
	if (leftSection <= left && right <= rightSection)
		return T[cur];
	// 当前节点不在查询区间内 向下递归
	if (mid < leftSection)
		return QuerySection(leftSection, rightSection, rightSon);
	else if (rightSection <= mid)
		return QuerySection(leftSection, rightSection, leftSon);
	// 当前节点部分在查询区域内 取左右子树合并求解(类似PushUp操作)
	Node retNode, leftNode, rightNode;
	leftNode = QuerySection(leftSection, rightSection, leftSon);
	rightNode = QuerySection(leftSection, rightSection, rightSon);
	// 合并区间结果
	retNode.sum = leftNode.sum + rightNode.sum;
	retNode.per = max(leftNode.per, leftNode.sum + rightNode.per);
	retNode.suf = max(rightNode.suf, leftNode.suf + rightNode.sum);
	retNode.con = max(leftNode.con, rightNode.con);
	retNode.con = max(retNode.con, leftNode.suf + rightNode.per);
	return retNode;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	BuildTree(1, n, 1);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &l, &r);
		printf("%d\n", QuerySection(l, r, 1, n, 1).con);
	}
	return 0;
}
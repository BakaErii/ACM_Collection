/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-04-07 19:01:55
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

#define leftSon left , mid , curr << 1
#define rightSon mid + 1 , right, curr << 1 | 1

const int maxN = 100005;

int arrSum[maxN << 2];
int lazyTag[maxN << 2];

//自底向上更新
void pushUp(int curr) {
	arrSum[curr] = arrSum[curr << 1] + arrSum[curr << 1 | 1];
	return;
}

//从上向下更新懒标签
void pushDown(int curr, int mid)
{
	if (lazyTag[curr])
	{
		lazyTag[curr << 1] = lazyTag[curr];
		lazyTag[curr << 1 | 1] = lazyTag[curr];
		arrSum[curr << 1] = lazyTag[curr] * (mid - (mid >> 1));
		arrSum[curr << 1 | 1] = lazyTag[curr] * (mid >> 1);
		lazyTag[curr] = 0;
	}
	return;
}

//建树
void buildTree(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	lazyTag[curr] = 0;
	arrSum[curr] = right - left + 1;
	if (left == right)
		return;
	buildTree(leftSon);
	buildTree(rightSon);
	//递归之后更新
	pushUp(curr);
	return;
}

//区间更新
void updateSection(int leftSection, int rightSection, int value, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection) {
		lazyTag[curr] = value;
		arrSum[curr] = value * (right - left + 1);
		return;
	}
	pushDown(curr, right - left + 1);
	if (leftSection <= mid)
		updateSection(leftSection, rightSection, value, leftSon);
	if (rightSection > mid)
		updateSection(leftSection, rightSection, value, rightSon);
	pushUp(curr);
	return;
}

//区间求和
int querySum(int leftSection, int rightSection, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection)
		return arrSum[curr];
	pushDown(curr, right - left + 1);
	int ret = 0;
	if (leftSection <= mid)
		ret = querySum(leftSection, rightSection, leftSon);
	else
		ret = querySum(leftSection, rightSection, rightSon);
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, i, j, left, right, value;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d %d", &n, &m);
		buildTree(1, n, 1);
		for (j = 0; j < m; j++) {
			scanf("%d %d %d", &left, &right, &value);
			updateSection(left, right, value, 1, n, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n", i, querySum(1, n, 1, n, 1));
	}
	return 0;
}
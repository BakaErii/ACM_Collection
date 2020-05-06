/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-04-07 17:14:49
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

const int maxN = 200005;
int arrMax[maxN << 2];

//自底向上更新
void pushUp(int curr) {
	arrMax[curr] = max(arrMax[curr << 1], arrMax[curr << 1 | 1]);
	return;
}

//读入数据建树
void buildTree(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == right) {
		scanf("%d", &arrMax[curr]);
		return;
	}
	buildTree(leftSon);
	buildTree(rightSon);
	pushUp(curr);
	return;
}

//单点更新
void updateNode(int node, int value, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == right) {
		arrMax[curr] = value;
		return;
	}
	if (node <= mid)
		updateNode(node, value, leftSon);
	else
		updateNode(node, value, rightSon);
	pushUp(curr);
	return;
}

//区间求最大值
int queryMax(int leftSection, int rightSection, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection)
		return arrMax[curr];
	int ret = -1;
	if (leftSection <= mid)
		ret = max(ret, queryMax(leftSection, rightSection, leftSon));
	if (rightSection > mid)
		ret = max(ret, queryMax(leftSection, rightSection, rightSon));
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, n, m, arg1, arg2;
	char cmd[5];
	while (~scanf("%d %d", &n, &m)) {
		//init
		memset(arrMax, 0, sizeof(arrMax));
		//建树
		buildTree(1, n, 1);
		//执行指令
		for (i = 0; i < m; i++) {
			scanf("%s %d %d", cmd, &arg1, &arg2);
			switch (cmd[0]) {
			case 'Q':
				//查询区间最大值
				printf("%d\n", queryMax(arg1, arg2, 1, n, 1));
				break;
			case 'U':
				//单点更新
				updateNode(arg1, arg2, 1, n, 1);
				break;
			}
		}
	}
	return 0;
}
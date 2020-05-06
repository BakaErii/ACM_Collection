/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-26 16:46:15
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
int arrSum[maxN << 4];

void pushUp(int curr) {
	arrSum[curr] = arrSum[curr << 1] + arrSum[curr << 1 | 1];
	return;
}

void buildTree(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == right) {
		scanf("%d", &arrSum[curr]);
		return;
	}
	buildTree(leftSon);
	buildTree(rightSon);
	pushUp(curr);
	return;
}

int querySection(int leftSection, int rightSection, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection)
		return arrSum[curr];
	int ret = 0;
	if (leftSection <= mid)
		ret += querySection(leftSection, rightSection, leftSon);
	if (rightSection > mid)
		ret += querySection(leftSection, rightSection, rightSon);
	return ret;
}

void updateNode(int node, int val, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == right) {
		arrSum[curr] += val;
		return;
	}
	if (node <= mid)
		updateNode(node, val, leftSon);
	else
		updateNode(node, val, rightSon);
	pushUp(curr);
	return;
}

int main(void) {
	int t, n, arg0, arg1;
	char op[10];
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		printf("Case %d:\n", i + 1 );
		scanf("%d", &n);
		buildTree(1, n, 1);
		while (~scanf("%s", op)) {
			if (op[0] == 'Q') {
				scanf("%d %d", &arg0, &arg1);
				printf("%d\n", querySection(arg0, arg1, 1, n, 1));
			} else if (op[0] == 'A') {
				scanf("%d %d", &arg0, &arg1);
				updateNode(arg0, arg1, 1, n, 1);
			} else if (op[0] == 'S') {
				scanf("%d %d", &arg0, &arg1);
				updateNode(arg0, -arg1, 1, n, 1);
			} else
				break;
		}
	}
	return 0;
}
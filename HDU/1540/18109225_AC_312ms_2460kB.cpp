/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-02 16:57:41
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

#define leftSon left,mid,curr<<1
#define rightSon mid+1,right,curr<<1|1

const int maxN = 50005;

int arrLeftLen[maxN << 2];
int arrRightLen[maxN << 2];

void pushUp(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	arrLeftLen[curr] = arrLeftLen[curr << 1];
	arrRightLen[curr] = arrRightLen[curr << 1 | 1];
	if (arrLeftLen[curr] == mid - left + 1)
		arrLeftLen[curr] += arrLeftLen[curr << 1 | 1];
	if (arrRightLen[curr] == right - mid)
		arrRightLen[curr] += arrRightLen[curr << 1];
	return;
}

void buildTree(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	arrLeftLen[curr] = arrRightLen[curr] = right - left + 1;
	if (left == right)
		return;
	buildTree(leftSon);
	buildTree(rightSon);
	pushUp(left, right, curr);
	return;
}

void updateNode(int node, int status, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == right) {
		arrLeftLen[curr] = arrRightLen[curr] = status;
		return;
	}
	if (mid >= node)
		updateNode(node, status, leftSon);
	else
		updateNode(node, status, rightSon);
	pushUp(left, right, curr);
	return;
}

int queryNode(int node, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == right)
		return arrLeftLen[curr];
	if (mid >= node) {
		if (mid - node + 1 <= arrRightLen[curr << 1])
			return arrRightLen[curr << 1] + arrLeftLen[curr << 1 | 1];
		else
			return queryNode(node, leftSon);
	} else {
		if (node - mid <= arrLeftLen[curr << 1 | 1])
			return arrLeftLen[curr << 1 | 1] + arrRightLen[curr << 1];
		else
			return queryNode(node, rightSon);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, arg;
	char cmd[5];
	while (~scanf("%d %d", &n, &m)) {
		// INIT
		stack<int> st;
		buildTree(1, n, 1);
		while (m--) {
			scanf("%s", cmd);
			switch (cmd[0]) {
			case 'D':
				scanf("%d", &arg);
				st.push(arg);
				updateNode(arg, 0, 1, n, 1);
				break;
			case 'R':
				if (st.empty())
					break;
				updateNode(st.top(), 1, 1, n, 1);
				st.pop();
				break;
			case 'Q':
				scanf("%d", &arg);
				printf("%d\n", queryNode(arg, 1, n, 1) );
				break;
			}
		}
	}
	return 0;
}
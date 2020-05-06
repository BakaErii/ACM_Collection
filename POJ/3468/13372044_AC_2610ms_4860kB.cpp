/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-04-07 19:49:00
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

const int maxN = 100005;

long long int arrSum[maxN << 2];
long long int lazyTag[maxN << 2];

void pushUp(int curr) {
	arrSum[curr] = arrSum[curr << 1] + arrSum[curr << 1 | 1];
	return;
}

void pushDown(int curr, int mid) {
	if (lazyTag[curr]) {
		lazyTag[curr << 1] += lazyTag[curr];
		lazyTag[curr << 1 | 1] += lazyTag[curr];
		arrSum[curr << 1] += lazyTag[curr] * (mid - (mid >> 1));
		arrSum[curr << 1 | 1] += lazyTag[curr] * (mid >> 1);
		lazyTag[curr] = 0;
	}
	return;
}

void buildTree(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	lazyTag[curr] = 0;
	if (left == right) {
		scanf("%lld", &arrSum[curr]);
		return;
	}
	buildTree(leftSon);
	buildTree(rightSon);
	pushUp(curr);
	return;
}

void addSection(int leftSection, int rightSection, int value, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection) {
		lazyTag[curr] += value;
		arrSum[curr] += value * (right - left + 1);
		return;
	}
	pushDown(curr, right - left + 1);
	if (leftSection <= mid)
		addSection(leftSection, rightSection, value, leftSon);
	if (rightSection > mid)
		addSection(leftSection, rightSection, value, rightSon);
	pushUp(curr);
	return;
}

long long int querySum(int leftSection, int rightSection, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection)
		return arrSum[curr];
	pushDown(curr, (right - left) + 1);
	long long int ret = 0;
	if (leftSection <= mid)
		ret += querySum(leftSection, rightSection, leftSon);
	if (rightSection > mid)
		ret += querySum(leftSection, rightSection, rightSon);
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, n, m, left, right, value;
	char ch[2];
	scanf("%d %d", &n, &m);
	buildTree(1, n, 1);
	for (i = 0; i < m; i++) {
		scanf("%s", ch);
		if (ch[0] == 'Q') {
			scanf("%d %d", &left, &right);
			printf("%lld\n", querySum(left, right, 1, n, 1) );
		} else {
			scanf("%d %d %d", &left, &right, &value);
			addSection(left, right, value, 1, n, 1);
		}
	}
	return 0;
}
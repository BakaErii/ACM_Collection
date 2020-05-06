/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-13 07:55:43
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

const int maxN = 100005;

long long int arrSum[maxN << 2];

void pushUp(int curr) {
	arrSum[curr] = arrSum[curr << 1] + arrSum[curr << 1 | 1];
	return;
}

void buildTree(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == right) {
		scanf("%lld", &arrSum[curr]);
		return;
	}
	buildTree(leftSon);
	buildTree(rightSon);
	pushUp(curr);
	return;
}

long long int querySection(int leftSection, int rightSection, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection)
		return arrSum[curr];
	long long int ret = 0;
	if (leftSection <= mid)
		ret += querySection(leftSection, rightSection, leftSon);
	if (rightSection > mid)
		ret += querySection(leftSection, rightSection, rightSon);
	return ret;
}

void updateSection(int leftSection, int rightSection, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (right - left + 1 == arrSum[curr])
		return;
	if (left == right) {
		arrSum[curr] = sqrt(arrSum[curr]);
		return;
	}
	if (leftSection <= mid)
		updateSection(leftSection, rightSection, leftSon);
	if (rightSection > mid)
		updateSection(leftSection, rightSection, rightSon);
	pushUp(curr);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int kase = 1;
	int n, m, l, r, op;
	while (~scanf("%d", &n)) {
		//INIT
		memset(arrSum,0,sizeof(arrSum));
		printf("Case #%d:\n",kase++ );
		buildTree(1, n, 1);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &op, &l, &r);
			if (l > r)
				swap(l, r);
			switch (op) {
			case 0:
				updateSection(l, r, 1, n, 1);
				break;
			case 1:
				printf("%lld\n", querySection(l, r, 1, n, 1));
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
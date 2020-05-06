/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-19 18:51:11
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

#define leftSon left, mid, curr<<1
#define rightSon mid+1, right, curr<<1|1

using namespace std;

const int maxN = 50005;

long long int lazyTag[maxN << 2];
long long int SegTree[maxN << 2];

void pushUp(int curr) {
	SegTree[curr] = SegTree[curr << 1] + SegTree[curr << 1 | 1];
	return;
}

void pushDown(int left, int right , int curr) {
	int mid = (left + right) >> 1;
	if (~lazyTag[curr]) {
		SegTree[curr << 1] = lazyTag[curr] ? mid - left + 1 : 0;
		SegTree[curr << 1 | 1] = lazyTag[curr] ? right - mid : 0;
		lazyTag[curr << 1] = lazyTag[curr];
		lazyTag[curr << 1 | 1] = lazyTag[curr];
		lazyTag[curr] = -1;
	}
	return;
}

void InitTree(void) {
	memset(lazyTag, -1, sizeof(lazyTag));
	memset(SegTree, 0, sizeof(SegTree));
	return;
}

void updateSection(int leftSection, int rightSection, int value, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection) {
		lazyTag[curr] = value;
		SegTree[curr] = lazyTag[curr] ? right - left + 1 : 0;
		return;
	}
	pushDown(left, right, curr);
	if (leftSection <= mid)
		updateSection(leftSection, rightSection, value, leftSon);
	if (mid < rightSection)
		updateSection(leftSection, rightSection, value, rightSon);
	pushUp(curr);
	return;
}

int querySection(int leftSection, int rightSection, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection) {
		return SegTree[curr];
	}
	pushDown(left, right, curr);
	long long int ret = 0;
	if (leftSection <= mid)
		ret += querySection(leftSection, rightSection, leftSon);
	if (mid < rightSection)
		ret += querySection(leftSection, rightSection, rightSon);
	return ret;
}

int searchInSection(int value, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == right)
		return left;
	pushDown(left, right, curr);
	int zeroNum = mid - left + 1 - SegTree[curr << 1];
	if (zeroNum >= value)
		return searchInSection(value, leftSon);
	else
		return searchInSection(value - zeroNum, rightSon);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, arg0, arg1, arg2;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		InitTree();
		while (m--) {
			scanf("%d %d %d", &arg0, &arg1, &arg2);
			switch (arg0) {
			case 1:
				int leftZeroNum, rightZeroNum, left, right;
				rightZeroNum = n - arg1 - querySection(arg1 + 1, n, 1, n, 1);
				leftZeroNum = n - SegTree[1] - rightZeroNum;
				if (rightZeroNum == 0) {
					printf("Can not put any one.\n");
					break;
				}
				left = searchInSection(1 + leftZeroNum, 1, n, 1);
				if (arg2 > rightZeroNum)
					right = searchInSection(leftZeroNum + rightZeroNum, 1, n, 1);
				else
					right = searchInSection(arg2 + leftZeroNum, 1, n, 1);
				printf("%d %d\n", left - 1, right - 1 );
				updateSection(left, right, 1, 1, n, 1);
				break;
			case 2:
				printf("%d\n", querySection(arg1 + 1, arg2 + 1, 1, n, 1));
				updateSection(arg1 + 1, arg2 + 1, 0, 1, n, 1);
				break;
			}
		}
		putchar('\n');
	}
	return 0;
}
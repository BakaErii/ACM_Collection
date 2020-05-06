/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-26 19:12:43
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
const int INF = 0x3f3f3f3f;

int arrMin[maxN << 4];
int arrMax[maxN << 4];

void pushUp(int curr) {
	arrMin[curr] = min(arrMin[curr << 1], arrMin[curr << 1 | 1]);
	arrMax[curr] = max(arrMax[curr << 1], arrMax[curr << 1 | 1]);
	return;
}

void buildTree(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (left == right) {
		scanf("%d", &arrMin[curr]);
		arrMax[curr] = arrMin[curr];
		return;
	}
	buildTree(leftSon);
	buildTree(rightSon);
	pushUp(curr);
	return;
}

int querySectionMax(int leftSection, int rightSection, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection)
		return arrMax[curr];
	int ret = -INF;
	if (leftSection <= mid)
		ret = max(ret, querySectionMax(leftSection, rightSection, leftSon));
	if (rightSection > mid)
		ret = max(ret, querySectionMax(leftSection, rightSection, rightSon));
	return ret;
}

int querySectionMin(int leftSection, int rightSection, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection)
		return arrMin[curr];
	int ret = INF;
	if (leftSection <= mid)
		ret = min(ret, querySectionMin(leftSection, rightSection, leftSon));
	if (rightSection > mid)
		ret = min(ret, querySectionMin(leftSection, rightSection, rightSon));
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, l, r;
	while (~scanf("%d %d", &n, &q)) {
		buildTree(1, n, 1);
		for (int i = 0; i < q; i++) {
			scanf("%d %d", &l, &r);
			printf("%d\n", querySectionMax(l, r, 1, n, 1) - querySectionMin(l, r, 1, n, 1));
		}
	}
	return 0;
}
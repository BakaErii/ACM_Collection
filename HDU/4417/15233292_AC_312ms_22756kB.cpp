/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-06 17:14:20
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

#define leftSon left, mid, curr << 1
#define rightSon mid+1, right, curr << 1 | 1

using namespace std;

const int maxN = 100005;
int arr[maxN];
vector<int> v[maxN << 2];

void buildTree(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	v[curr].clear();
	for (int i = left; i <= right; i++)
		v[curr].push_back(arr[i]);
	sort(v[curr].begin(), v[curr].end());
	if (left == right)
		return;
	buildTree(leftSon);
	buildTree(rightSon);
	return;
}

int query(int leftSection, int rightSection, int value, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection) {
		vector<int>::iterator it;
		it = upper_bound(v[curr].begin(), v[curr].end(), value);
		return it - v[curr].begin();
	}
	int ret = 0;
	if (leftSection <= mid)
		ret += query(leftSection, rightSection, value, leftSon);
	if (mid < rightSection)
		ret += query(leftSection, rightSection, value, rightSon);
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, l, r, value, kase = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		buildTree(1, n, 1);
		printf("Case %d:\n", ++kase);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &l, &r, &value);
			printf("%d\n", query(l + 1, r + 1, value, 1, n, 1));
		}
	}
	return 0;
}
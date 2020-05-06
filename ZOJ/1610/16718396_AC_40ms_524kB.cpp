/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-29 14:53:32
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

const int maxN = 10005;

int arrCol[maxN << 2];
int num[maxN];
int getCol[maxN];

void pushDown(int curr) {
	if (arrCol[curr] != -1) {
		arrCol[curr << 1] = arrCol[curr];
		arrCol[curr << 1 | 1] = arrCol[curr];
		arrCol[curr] = -1;
	}
	return;
}

void updateSection(int leftSection, int rightSection, int value, int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (leftSection <= left && right <= rightSection) {
		arrCol[curr] = value;
		return;
	}
	pushDown(curr);
	if (leftSection <= mid)
		updateSection(leftSection, rightSection, value, leftSon);
	if (mid < rightSection)
		updateSection(leftSection, rightSection, value, rightSon);
	return;
}

void querySection(int left, int right, int curr) {
	int mid = (left + right) >> 1;
	if (arrCol[curr] != -1) {
		for (int i = left; i <= right; i++)
			getCol[i] = arrCol[curr];
		return;
	}
	if (left < right && arrCol[curr] == -1) {
		querySection(leftSon);
		querySection(rightSon);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l, r, v;
	while (~scanf("%d", &n)) {
		//INIT
		memset(num, 0, sizeof(num));
		memset(arrCol, -1, sizeof(arrCol));
		memset(getCol, -1, sizeof(getCol));
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &l, &r, &v);
			updateSection(l + 1, r, v, 1, 8000, 1);
		}
		querySection(1, 8000, 1);
		if (getCol[0] != -1)
			num[getCol[0]]++;
		for(int i=1;i<=8000;i++)
			if(getCol[i]!=-1&&getCol[i]!=getCol[i-1])
				num[getCol[i]]++;
		for(int i=0;i<=8000;i++)
			if(num[i]!=0)
				printf("%d %d\n",i,num[i]);
		printf("\n");
	}
	return 0;
}
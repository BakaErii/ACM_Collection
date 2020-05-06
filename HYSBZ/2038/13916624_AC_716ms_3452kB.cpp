/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-14 19:10:05
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

const int maxN = 50005;
int n, m, blockSize, L, R, now;
int arr[maxN], C[maxN][3], ansUpdate[maxN], ansDo[maxN], s[maxN];

struct Query {
	int pos;
	int left;
	int right;
	int id;
} que[maxN];

bool cmp(Query a, Query b) {
	if(a.pos == b.pos)
		return a.right < b.right;
	return a.pos < b.pos;
}

int GCD(int a, int b) {
	if(!a || !b)  return a ? a : b;
	int t = a % b;
	while(t) {
		a = b, b = t;
		t = a % b;
	}
	return b;
}

void update(int x, int op) {
	now -= C[s[arr[x]]][2];
	s[arr[x]] += op;
	now += C[s[arr[x]]][2];
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	scanf("%d %d", &n, &m);
	//init
	blockSize = sqrt(n);
	for(i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for(i = 0; i <= n; i++) {
		C[i][0] = 1;
		for(j = 1; j <= 2; j++)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	for(i = 1; i <= m; i++) {
		scanf("%d %d", &que[i].left, &que[i].right);
		que[i].id = i;
		que[i].pos = que[i].left / blockSize;
	}
	sort(que + 1, que + m + 1, cmp);
	L = 0;
	R = 0;
	now = 0;
	s[50001] = 1;
	arr[0] = 50001;
	for(i = 1; i <= m; i++) {
		while(L < que[i].left) update(L++, -1);
		while(L > que[i].left) update(--L, 1);
		while(R < que[i].right) update(++R, 1);
		while(R > que[i].right) update(R--, -1);
		ansUpdate[que[i].id] = now;
		ansDo[que[i].id] = C[R - L + 1][2];
	}
	for(i = 1; i <= m; i++) {
		int tmp = GCD(ansUpdate[i], ansDo[i]);
		printf("%d/%d\n", ansUpdate[i] / tmp, ansDo[i] / tmp);
	}
	return 0;
}
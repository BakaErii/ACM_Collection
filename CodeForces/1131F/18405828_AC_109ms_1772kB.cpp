/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-25 15:23:41
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

const int maxN = 150005;

int n;
int arrSet[maxN];
int arrNext[maxN];
int arrAns[maxN];

void Init() {
	for (int i = 0; i <= n; i++) {
		arrSet[i] = i;
		arrNext[i] = i;
	}
	return;
}

int FindSet(int x) {
	if (arrSet[x] == x)
		return x;
	arrSet[x] = FindSet(arrSet[x]);
	return arrSet[x];
}

void MergeSet(int a, int b) {
	int tmpA = FindSet(a);
	int tmpB = FindSet(b);
	// Union & Update
	arrAns[arrNext[tmpA]] = tmpB;
	arrSet[tmpB] = tmpA;
	arrNext[tmpA] = arrNext[tmpB];
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v, curr;
	scanf("%d", &n);
	Init();
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		MergeSet(u, v);
	}
	curr = FindSet(1);
	while (curr != 0) {
		printf("%d ", curr );
		curr = arrAns[curr];
	}
	putchar('\n');
	return 0;
}
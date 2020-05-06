/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-23 15:27:46
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

const int maxN = 10005;

int n, m;

int arrSet[maxN];
int arrVal[maxN];
map<int, int> mp;

void Init() {
	mp.clear();
	for (int i = 0; i < maxN; i++) {
		arrSet[i] = i;
		arrVal[i] = 0;
	}
	return;
}

int FindSet(int x) {
	if (arrSet[x] == x)
		return x;
	int root = FindSet(arrSet[x]);
	arrVal[x] = arrVal[x] ^ arrVal[arrSet[x]];
	arrSet[x] = root;
	return arrSet[x];
}

bool MergeSet(int a, int b, int val) {
	int tmpA = FindSet(a);
	int tmpB = FindSet(b);
	if (tmpA != tmpB) {
		arrSet[tmpB] = tmpA;
		arrVal[tmpB] = arrVal[a] ^ arrVal[b] ^ val;
	} else if ((arrVal[a] ^ arrVal[b]) != val)
		return true;
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v, val, ans, cnt = 1;
	char str[10];
	scanf("%d %d", &n, &m);
	ans = 0;
	Init();
	for (int i = 0; i < m; i++) {
		scanf("%d %d %s", &u, &v, str);
		if (u > v)
			swap(u, v);
		if (mp[u - 1] == 0)
			mp[u - 1] = cnt++;
		u = mp[u - 1];
		if (mp[v] == 0)
			mp[v] = cnt++;
		v = mp[v];
		val = str[0] == 'e' ? 0 : 1;
		if (MergeSet(u, v, val) == true)
			break;
		ans++;
	}
	printf("%d\n", ans );
	return 0;
}
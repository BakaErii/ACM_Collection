/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-14 13:42:11
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

int arr[1001];
int t, n, m, ans;

int get(int x) {
	if (arr[x] == x)
		return x;
	else {
		arr[x] = get(arr[x]);
		return arr[x];
	}
}

void merge(int x, int y) {
	int t1, t2;
	t1 = get(x);
	t2 = get(y);
	if (t1 != t2)
		arr[t2] = t1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int arg1, arg2;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		//init
		ans = 0;
		for (int i = 1; i <= n; i++)
			arr[i] = i;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &arg1, &arg2);
			merge(arg1, arg2);
		}
		for (int i = 1; i <= n; i++)
			if (arr[i] == i)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}
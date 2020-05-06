/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-16 11:41:36
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

const int maxN = 300005;

int n, m;
int arrQue[maxN];
bool arrVis[maxN];
vector<int> E[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, v;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arrQue[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		E[u].push_back(v);
	}
	reverse(arrQue + 1, arrQue + n + 1);
	int ans = 0;
	arrVis[arrQue[1]] = true;
	int cnt = 1;
	for (int i = 2; i <= n; i++) {
		int cnt2 = 0;
		for (int v : E[arrQue[i]])
			if (arrVis[v])
				cnt2++;
		if (cnt == cnt2)
			ans++;
		else {
			arrVis[arrQue[i]] = true;
			cnt++;
		}
	}
	printf("%d\n", ans );
	return 0;
}
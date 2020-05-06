/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-06-01 12:31:13
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

const int maxN = 100005;

vector<int> T[maxN];
int arrSum[maxN];

void DFS(int x, int dep) {
	arrSum[dep]++;
	for (int i = 0; i < (int)T[x].size(); i++)
		DFS(T[x][i], dep + 1);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, tmp;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &tmp);
		T[tmp].push_back(i);
	}
	DFS(1, 1);
	int ans = 0;
	for (int i = 1; i < maxN; i++)
		if (arrSum[i] % 2 == 1)
			ans++;
	cout << ans << endl;
	return 0;
}
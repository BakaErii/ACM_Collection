/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-16 09:56:43
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

vector<int> Va[1005];
vector<int> Vb[1005];
int n, m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			Va[i + j].push_back(tmp);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			Vb[i + j].push_back(tmp);
		}
	for (int i = 0; i < n + m; i++) {
		sort(Va[i].begin(), Va[i].end());
		sort(Vb[i].begin(), Vb[i].end());
		for (int j = 0; j < (int)Va[i].size(); j++)
			if (Va[i][j] != Vb[i][j]) {
				printf("NO\n");
				return 0;
			}
	}
	printf("YES\n");
	return 0;
}
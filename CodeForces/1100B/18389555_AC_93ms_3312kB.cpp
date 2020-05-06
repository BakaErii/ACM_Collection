/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-13 22:49:11
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

map<int, int> mp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, cnt = 0;
	int tmp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		mp[tmp]++;
		if (mp[tmp] == 1)
			cnt++;
		if (cnt >= n) {
			for (auto it : mp) {
				mp[it.first]--;
				if (mp[it.first] == 0)
					cnt--;
			}
			printf("1");
			continue;
		}
		printf("0");
	}
	putchar('\n');
	return 0;
}
/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-24 13:03:16
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

int n;
char ch[10];
int ans, num;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d", &n)) {
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", ch);
			if (ch[0] == 'S')
				ans++;
			else {
				scanf("%d", &num);
				if (num == 1)
					ans++;
			}
		}
		printf("%d\n", ans );
	}
	return 0;
}
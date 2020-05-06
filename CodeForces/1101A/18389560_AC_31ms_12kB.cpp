/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-11 23:15:42
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

int t, l, r, d;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &l, &r, &d);
		if (d < l) {
			printf("%d\n", d );
			continue;
		}
		tmp = r % d;
		printf("%d\n", r + (d - tmp));
	}
	return 0;
}
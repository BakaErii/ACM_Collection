/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-08 20:23:00
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

set<int> raw, nxt;
multiset<int> mraw, mnxt;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, tmp;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		raw.insert(tmp);
		mraw.insert(tmp);
		if (tmp != (tmp & k)) {
			nxt.insert(tmp & k);
			mnxt.insert(tmp & k);
		}
	}
	if (raw.size() != mraw.size()) {
		printf("0\n");
		return 0;
	}
	for (auto it : raw)
		if (mnxt.count(it) != 0) {
			printf("1\n");
			return 0;
		}
	if (nxt.size() != mnxt.size()) {
		printf("2\n");
		return 0;
	}
	printf("-1\n");
	return 0;
}
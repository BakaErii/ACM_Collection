/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-29 19:16:12
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
int arr[200005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, tmp, last = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		mp[tmp] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (i != 0)
			putchar(' ');
		if (last < mp[tmp]) {
			printf("%d", mp[tmp] - last);
			last = mp[tmp];
		} else {
			printf("0");
		}
	}
	return 0;
}
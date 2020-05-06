/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-24 18:03:04
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
bool flag = false;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, tmp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		mp[tmp]++;
	}
	if(mp.size() == 2) {
		for(auto it : mp)
			if(it.second != n / 2)
				flag = true;
		if(flag == false) {
			printf("YES\n");
			for(auto it : mp)
				printf("%d ", it.first);
			putchar('\n');
		} else
			printf("NO\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
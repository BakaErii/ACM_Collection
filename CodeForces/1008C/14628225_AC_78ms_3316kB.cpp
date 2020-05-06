/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-07-17 20:48:04
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
	int n, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		mp[tmp]++;
	}
	int maxNum = 0;
	for (auto it : mp)
		maxNum = max(maxNum, it.second);
	cout << n - maxNum << endl;
	return 0;
}
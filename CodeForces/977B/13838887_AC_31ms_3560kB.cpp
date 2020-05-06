/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-08 07:38:10
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

map<string, int> mp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, len, ans = 0;
	string str, tmp, ansStr;
	cin >> len >> str;
	for(i = 1; i < len; i++) {
		tmp.clear();
		tmp.push_back(str[i - 1]);
		tmp.push_back(str[i]);
		mp[tmp]++;
	}
	for(auto it : mp)
		if(ans < it.second) {
			ans = it.second;
			ansStr = it.first;
		}
	printf("%s\n", ansStr.c_str());
	return 0;
}
/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-04-17 18:59:24
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

int strLen, dparr[2][5005];
string str, strRev;

int calMaxDpAns(void) {
	int i, j, ans;
	//init
	ans = 0;
	strRev = str;
	reverse(strRev.begin(), strRev.end());
	memset(dparr, 0, sizeof(dparr));
	for(i = 1; i <= strLen; i++)
		for(j = 1; j <= strLen; j++) {
			if(str[i - 1] == strRev[j - 1])
				dparr[i % 2][j] = dparr[(i - 1) % 2][j - 1] + 1;
			else
				dparr[i % 2][j] = max(dparr[(i - 1) % 2][j], dparr[i % 2][j - 1]);
			ans = max(ans, dparr[i % 2][j]);
		}
	ans = strLen - ans;
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> strLen) {
		cin >> str;
		printf("%d\n", calMaxDpAns());
	}
	return 0;
}
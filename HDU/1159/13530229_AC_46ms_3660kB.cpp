/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-04-17 18:33:06
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

int dparr[1000][1000];
string aStr, bStr;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, aLen, bLen, ans;
	while(cin >> aStr >> bStr) {
		//init
		ans = 0;
		aLen = aStr.length();
		bLen = bStr.length();
		for(i = 0; i <= aLen; i++)
			for(j = 0; j <= bLen; j++)
				dparr[i][j] = 0;
		//dp
		for (i = 1; i <= aLen; i++)
			for (j = 1; j <= bLen; j++) {
				if (aStr[i - 1] == bStr[j - 1]) {
					dparr[i][j] = dparr[i - 1][j - 1] + 1;
				} else if (dparr[i - 1][j] >= dparr[i][j - 1])
					dparr[i][j] = dparr[i - 1][j];
				else
					dparr[i][j] = dparr[i][j - 1];
				ans = max(ans, dparr[i][j]);
			}
		printf("%d\n",ans );
	}
	return 0;
}
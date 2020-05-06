/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-14 14:38:14
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
string str1, str2;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, ans;
	while (cin >> str1 >> str2) {
		//init
		ans = 0;
		for (i = 0; i <= (int)str1.length(); i++)
			for (j = 0; j <= (int)str2.length(); j++)
				dparr[i][j] = 0;
		for (i = 1; i <= (int)str1.length(); i++)
			for (j = 1; j <= (int)str2.length(); j++) {
				if (str1[i - 1] == str2[j - 1]) {
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
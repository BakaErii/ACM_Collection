/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-19 19:27:06
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

int main(void) {
	int i, len, ans = 0, usernum = 0;
	string str;
	while (getline(cin, str)) {
		if (str[0] == '+')
			usernum++;
		else if (str[0] == '-')
			usernum--;
		else{
			len = 0;
			for (i = 0; i != (int)str.length(); i++)
				if (str[i] == ':') {
					len = (int)str.length() - i - 1;
					break;
				}
			ans += len*usernum;
		}
	}
	cout << ans << endl;
	return 0;
}
/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-14 13:25:04
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	while (getline(cin, str)) {
		for (int i = 0; i < (int)str.length(); i++) {
			if (i == 0)
				str[i] -= 32;
			if (i > 0 && str[i - 1] == ' ')
				str[i] -= 32;
		}
		cout << str << endl;
	}
	return 0;
}
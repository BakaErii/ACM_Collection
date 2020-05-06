/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-07-18 13:06:14
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

string str;
int n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			str.push_back('0');
		else
			str.push_back('1');
	}
	cout << str << endl;
	return 0;
}
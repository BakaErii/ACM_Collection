/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-03 14:41:46
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
	string str;
	int i, t, n, a, b;
	char ar, br;
	cin >> n >> t;
	cin >> str;
	while (t--) {
		cin >> a >> b >> ar >> br;
		for (i = a - 1; i <= b - 1; i++)
			if (str[i] == ar)
				str[i] = br;
	}
	cout << str << endl;
	return 0;
}
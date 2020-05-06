/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-14 13:59:07
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
	int numH, numC, numO, t, i;
	string str;
	cin >> t;
	while (t--) {
		//init
		cin >> str;
		numH = numC = numO = 0;
		for (i = 0; i < (int)str.length(); i++)
			switch (str[i]) {
			case 'C': numC++; break;
			case 'O': numO++; break;
			case 'H': numH++; break;
			}
		cout << numH + numC * 12 + numO * 16 << endl;
	}
	return 0;
}
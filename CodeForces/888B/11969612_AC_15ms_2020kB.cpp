/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-14 19:43:55
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
	int i, n, unum, dnum, lnum, rnum, ans;
	unum = dnum = lnum = rnum = 0;
	string str;
	cin >> n >> str;
	for (i = 0; i < (int)str.length(); i++)
		switch (str[i]) {
		case 'U': unum++; break;
		case 'D': dnum++; break;
		case 'L': lnum++; break;
		case 'R': rnum++; break;
		}
	//UD一对 LR一对
	ans = min(unum, dnum) * 2 + min(lnum, rnum) * 2;
	cout << ans << endl;
	return 0;
}

/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-19 21:17:17
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
	int x, tmp, pos;
	cin >> x;
	x = abs(x);
	pos = 0;
	tmp = 0;
	while (true) {
		if (tmp >= x && tmp % 2 == x % 2)
			break;
		pos++;
		tmp += pos;
	}
	cout << pos << endl;
	return 0;
}
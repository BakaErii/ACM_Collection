/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-16 19:35:05
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
	int n, tmp;
	cin >> n;
	tmp = n;
	tmp %= 10;
	if (tmp >= 5)
		n += (10 - tmp);
	else
		n -= tmp;
	cout << n << endl;
	return 0;
}
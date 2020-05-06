/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-18 17:52:05
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
	int w;
	cin >> w;
	if (w % 2 == 0 && w != 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}

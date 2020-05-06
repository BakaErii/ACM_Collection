/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-03 17:00:51
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
	bool isFirst = true;
	int a, sum;
	while (cin >> a) {
		sum = 0;
		while (a > 0) {
			if ((a % 10) % 2 == 0)
				sum += (a % 10);
			a/=10;
		}
		if (isFirst != true)
			cout << endl;
		isFirst = false;
		cout << sum << endl;
	}
	return 0;
}
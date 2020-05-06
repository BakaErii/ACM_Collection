/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-24 18:55:48
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
	long long int m, k, tmp;
	while (cin >> m >> k) {
		tmp = (m - k + 1) * k;
		cout << tmp << endl;
	}
	return 0;
}
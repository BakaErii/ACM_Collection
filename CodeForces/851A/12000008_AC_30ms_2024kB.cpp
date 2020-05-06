/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-17 18:14:57
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
	int n, k, t;
	cin >> n >> k >> t;
	if (t <= k)
		cout << t << endl;
	else if (t > k && t < n)
		cout << k << endl;
	else
		cout << n + k - t << endl;
	return 0;
}
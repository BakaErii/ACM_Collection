/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-14 18:37:17
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

int arr[9] = {1, 6,28, 120, 496, 2016, 8128, 32640, 130816};

int main(void) {
	int i, n;
	cin >> n;
	for (i = 8; i >= 0; i--)
		if (n % arr[i] == 0) {
			cout << arr[i] << endl;
			break;
		}
	return 0;
}
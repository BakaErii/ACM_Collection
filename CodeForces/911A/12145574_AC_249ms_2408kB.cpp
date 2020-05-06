/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-05 21:17:18
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

int arr[100000];

int main(void) {
	int i, n, minnum, mind = 999999, d = 999999;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0)
			minnum = arr[i];
		else
			minnum = min(minnum, arr[i]);
	}
	for (i = 0; i < n; i++) {
		if (arr[i] == minnum) {
			mind = min(mind, d);
			d = 0;
		}
		d++;
	}
	cout << mind << endl;
	return 0;
}
/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-12 23:17:57
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

int arr[1000000];

int main(void) {
	int h1, a1, c1, h2, a2;
	int i, n = 0;
	cin >> h1 >> a1 >> c1;
	cin >> h2 >> a2;
	while (h2 > 0) {
		if (a1 >= h2) {
			arr[n++] = 0;
			h2 -= a1;
		} else if (a2 >= h1) {
			arr[n++] = 1;
			h1 += c1;
		} else {
			arr[n++] = 0;
			h2 -= a1;
		}
		if (h2 > 0)
			h1 -= a2;
	}
	cout << n << endl;
	for (i = 0; i < n; i++)
		if (arr[i] == 0)
			cout << "STRIKE" << endl;
		else
			cout << "HEAL" << endl;
	return 0;
}
/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-15 18:16:29
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

int arr[100];

int main(void) {
	int n, t, i;
	cin >> n >> t;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		t = t - (86400 - arr[i]);
		if (t <= 0)
			break;
	}
	cout << i + 1 << endl;
	return 0;
}
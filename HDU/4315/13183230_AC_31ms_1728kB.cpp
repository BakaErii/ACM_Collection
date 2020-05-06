/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-25 14:21:06
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

int arr[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, n, k;
	int xorSum;
	while (~scanf("%d %d", &n, &k)) {
		//init
		xorSum = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		//special
		if (k == 1) {
			cout << "Alice" << endl;
			continue;
		} else {
			if (n % 2 != 0) {
				if (k == 2)
					arr[0]--;
				xorSum ^= arr[0];
				for (i = 2; i < n; i += 2)
					xorSum ^= (arr[i] - arr[i - 1] - 1);
			} else {
				for (i = 1; i < n; i += 2)
					xorSum ^= (arr[i] - arr[i - 1] - 1);
			}
		}
		if (xorSum == 0)
			cout << "Bob" << endl;
		else
			cout << "Alice" << endl;
	}
	return 0;
}
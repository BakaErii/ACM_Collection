/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-24 20:19:11
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

int t, n;
int arr[1001];

int main(void) {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int xorSum, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		xorSum = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		if (n % 2 != 0) {
			xorSum ^= arr[0] - 1;
			for (i = 2; i < n; i += 2)
				xorSum ^= (arr[i] - arr[i - 1] - 1);
		} else {
			for (i = 1; i < n; i += 2)
				xorSum ^= (arr[i] - arr[i - 1] - 1);
		}
		if (xorSum == 0)
			cout << "Bob will win" << endl;
		else
			cout << "Georgia will win" << endl;
	}
	return 0;
}
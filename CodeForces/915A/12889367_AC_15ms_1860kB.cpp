/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-13 21:03:49
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
	int n, k, i;
	cin >> n >> k;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (i = n - 1; i >= 0; i--)
		if (k % arr[i] == 0 && arr[i] <= k) {
			cout << k / arr[i] << endl;
			break;
		}
	return 0;
}
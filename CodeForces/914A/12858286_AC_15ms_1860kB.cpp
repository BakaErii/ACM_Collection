/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-20 23:35:18
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

int arr[1000];

int main(void) {
	int i, n;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (i = n - 1; i >= 0; i--) {
		if (sqrt(arr[i]) != (int)sqrt(arr[i])) {
			cout << arr[i] << endl;
			return 0;
		}
	}
	return 0;
}
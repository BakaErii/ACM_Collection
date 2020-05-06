/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-14 18:47:56
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
	int i, n, ans = 0;
	cin >> n;
	if (n < 3) {
		cout << "0" << endl;
		return 0;
	}
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 1; i < n - 1; i++)
		if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]))
			ans++;
	cout << ans << endl;
	return 0;
}
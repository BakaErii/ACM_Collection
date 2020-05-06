/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-02 12:19:44
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, n, d, ans;
	cin >> n >> d;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	ans = -1;
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			if (arr[j] - arr[i] <= d)
				ans = max(ans, j - i);
	cout << n - ans - 1 << endl;
	return 0;
}
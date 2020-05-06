/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-07-18 12:58:10
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

int n, d, ans;
long long int arr[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	cin >> n >> d;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 0; i < n - 1; i++) {
		if (arr[i + 1] - arr[i] > 2 * d)
			ans += 2;
		else if (arr[i + 1] - arr[i] == 2 * d)
			ans++;
	}
	cout << ans + 2 << endl;
	return 0;
}
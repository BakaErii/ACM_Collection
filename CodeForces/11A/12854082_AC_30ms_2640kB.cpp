/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-19 20:47:23
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

unsigned long long int arr[100000];

int main(void) {
	int i, n, d, cnt, tmp;
	cnt = 0;
	cin >> n >> d;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 1; i < n; i++) {
		if (arr[i - 1] >= arr[i]) {
			tmp = (arr[i - 1] - arr[i]) / d + 1;
			cnt += tmp;
			arr[i] += tmp * d;
		}
	}
	cout << cnt << endl;
	return 0;
}
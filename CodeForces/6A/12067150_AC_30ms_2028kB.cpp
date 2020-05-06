/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-25 15:28:32
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

int arr[4];

bool cmp(int a, int b) {
	return a > b;
}

int main(void) {
	int i;
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
	sort(arr, arr + 4, cmp);
	for (i = 0; i < 2; i++)
		if (arr[i + 2] + arr[i + 1] > arr[i]) {
			cout << "TRIANGLE" << endl;
			return 0;
		}
	if (arr[0] == arr[1] + arr[2] || arr[0] == arr[1] + arr[3] || arr[0] == arr[2] + arr[3]) {
		cout << "SEGMENT" << endl;
		return 0;
	} else if (arr[1] == arr[2] + arr[3]) {
		cout << "SEGMENT" << endl;
		return 0;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
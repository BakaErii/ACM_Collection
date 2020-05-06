/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-15 17:59:41
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

int arr[100000];

int main(void) {
	int n, x, tmp;
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	vector<int> v(arr, arr + n);
	vector<int>::iterator up;
	cin >> x;
	while (x--) {
		cin >> i;
		up = upper_bound(v.begin(), v.end(), i);
		cout << (up-v.begin()) << endl;
	}
	return 0;
}

/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-20 21:58:00
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

set<string> strs;
map<string, int> strm;
int arr[101];
int stringarr[101];

int main(void) {
	int n, m, i, ans_min, ans_max, ptr;
	string str;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (i = 0; i < m; i++) {
		cin >> str;
		strs.insert(str);
		strm[str]++;
	}
	ptr = 0;
	for (string str : strs)
		stringarr[ptr++] = strm[str];
	sort(stringarr, stringarr + ptr);
	ans_min = 0;
	ans_max = 0;
	for (i = 0; i < ptr; i++) {
		ans_min += arr[i] * stringarr[ptr - 1 - i];
		ans_max += arr[n - 1 - i] * stringarr[ptr - 1 - i];
	}
	printf("%d %d\n", ans_min, ans_max );
	return 0;
}
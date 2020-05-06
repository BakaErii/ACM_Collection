/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-08 18:04:10
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

vector<pair<int, long long int> > arr;

int cal3(long long int tmp) {
	int ret = 0;
	while(tmp % 3 == 0) {
		tmp /= 3;
		ret++;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	arr.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i].second;
		arr[i].first = -cal3(arr[i].second);
	}
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n; i++) {
		if(i != 0)
			putchar(' ');
		printf("%lld", arr[i].second);
	}
	putchar('\n');
	return 0;
}
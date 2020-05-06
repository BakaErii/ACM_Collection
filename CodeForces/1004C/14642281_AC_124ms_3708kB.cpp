/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-07-18 13:13:45
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

int n;
int arr[100005];
map<int, int> mp;
set<int> st;
unsigned long long int ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		mp[arr[i]] = i;
	}
	for (i = 0; i < n - 1; i++) {
		//erase
		if (i == mp[arr[i]])
			mp.erase(arr[i]);
		//count & insert
		if (st.count(arr[i]) == 0) {
			ans += mp.size();
			st.insert(arr[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
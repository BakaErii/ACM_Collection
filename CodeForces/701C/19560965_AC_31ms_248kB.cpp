/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-03 10:10:00
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

const int maxN = 100005;
const int INF = 0x3f3f3f3f;

int n, ansLen, ans;
char arr[maxN];
set<char> st;
map<char, int> mp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	scanf("%s", arr);
	for (int i = 0; i < n; i++)
		st.insert(arr[i]);
	ansLen = (int)st.size();
	int fptr = 0;
	int bptr = 0;
	ans = INF;
	while (fptr <= bptr) {
		while (bptr < n && (int)mp.size() < ansLen)
			mp[arr[bptr++]]++;
		while (fptr <= bptr && fptr < n)
			if (mp[arr[fptr]] > 1) {
				mp[arr[fptr]]--;
				fptr++;
			} else
				break;
		if ((int)mp.size() == ansLen)
			ans = min(ans, bptr - fptr);
		mp[arr[fptr]]--;
		if (mp[arr[fptr]] == 0)
			mp.erase(arr[fptr]);
		fptr++;
	}
	printf("%d\n", ans );
	return 0;
}
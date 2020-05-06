/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-06 21:11:26
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

struct Tv
{
	int ti_s;
	int ti_e;
} t[100];

bool cmp(Tv a, Tv b) {
	return a.ti_e < b.ti_e;
}

int main(void) {
	int i, n, time, ans;
	while (cin >> n && n != 0) {
		ans = 0;
		time = 0;
		for (i = 0; i < n; i++)
			cin >> t[i].ti_s >> t[i].ti_e;
		sort(t, t + n, cmp);
		for (i = 0; i < n; i++)
			if (time <= t[i].ti_s) {
				time = t[i].ti_e;
				ans++;
			}
		cout << ans << endl;
	}
	return 0;
}


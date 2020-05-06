/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-13 17:20:54
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

int arr[1000];

int main(void) {
	int i, n, r, ans, sptr, mptr, eptr;
	while (cin >> r >> n && n != -1 && r != -1) {
		ans = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		sptr = 0;
		mptr = 0;
		while (sptr != n) {
			while (arr[sptr] + r >= arr[mptr] && mptr < n)
				mptr++;
			if (sptr == mptr)
				mptr++;
			mptr--;
			eptr = mptr;
			while (arr[mptr] + r >= arr[eptr] && eptr < n)
				eptr++;
			if (mptr == eptr)
				eptr++;
			ans++;
			sptr = eptr;
			mptr = sptr;
		}
		cout << ans << endl;
	}
	return 0;
}
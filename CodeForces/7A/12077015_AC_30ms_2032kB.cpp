/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-26 19:39:46
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

char cs[9];

int main(void) {
	int i, j, ans, cnt, tmp;
	ans = 0;
	for (i = 0; i < 8; i++) {
		gets(cs);
		cnt = 0;
		for (j = 0; j < 8; j++)
			if (cs[j] == 'B')
				cnt++;
		if (cnt == 8)
			ans++;
		else
			tmp = cnt;
	}
	ans += tmp;
	cout << ans << endl;
	return 0;
}
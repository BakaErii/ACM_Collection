/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-03 21:13:34
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

string str;
char ch;

int main(void) {
	int i, len, cnt;
	double ans;
	while (~scanf("%c", &ch)) {
		cin >> str;
		getchar();
		cnt = 0;
		len = (int)str.length();
		for (i = 0; i < len; i++)
			if (ch == str[i])
				cnt++;
			else if (ch == str[i] - 32 || ch == str[i] + 32)
				cnt++;
		ans = (double)cnt / (double)len;
		printf("%.5lf\n", ans );
	}
	return 0;
}
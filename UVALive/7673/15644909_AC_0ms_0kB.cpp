/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-23 16:38:03
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

string arr[20];
int n, m, cnt;
map<char, int> mp;

struct st
{
	char ch;
	int value;
} s[5];

bool cmp(st a, st b) {
	if (a.value == b.value)
		return a.ch < b.ch;
	return a.value > b.value;
}

int main(void) {
	while (~scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0)
			return 0;
		getchar();
		mp.clear();
		for (int i = 0; i < n; i++) {
			getline(cin, arr[i]);
			for (int j = 0; j < m; j++)
				mp[arr[i][j]]++;
		}
		cnt = 0;
		for (auto it : mp) {
			s[cnt].ch = it.first;
			s[cnt].value = it.second;
			cnt++;
		}
		sort(s, s + cnt, cmp);
		for (int i = 0; i < cnt; i++) {
			if (i != 0)
				putchar(' ');
			printf("%c %d", s[i].ch, s[i].value );
		}
		putchar('\n');
	}
	return 0;
}
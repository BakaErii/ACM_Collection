/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-15 13:41:07
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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int nowX = 0, nowY = 0;
	int t, x, y;
	char ch;
	scanf("%d", &t);
	while (t--) {
		getchar();
		scanf("%c", &ch);
		scanf("%d %d", &x, &y);
			if (x < y)
				swap(x, y);
		switch (ch) {
		case '+':
			nowX = max(nowX, x);
			nowY = max(nowY, y);
			break;
		case '?':
			if (x >= nowX && y >= nowY)
				printf("YES\n");
			else
				printf("NO\n");
			break;
		}
	}
	return 0;
}
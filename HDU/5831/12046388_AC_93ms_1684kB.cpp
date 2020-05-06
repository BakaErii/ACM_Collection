/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-22 19:09:34
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

char st[100000];

int main(void) {
	int t, n, i, ptr;
	int equalnum;
	scanf("%d", &t);
	while (t--) {
		equalnum = 0;
		ptr = 0;
		scanf("%d", &n);
		getchar();
		while (n--) {
			st[ptr] = getchar();
			if (st[ptr] == ')' && ptr != 0 && st[ptr - 1] == '(') {
				//括号匹配 出栈
				ptr -= 1;
				equalnum++;
				continue;
			}
			ptr++;
		}
		if (ptr == 4) {
			if (st[0] == ')' && st[1] == ')' && st[2] == '(' && st[3] == '(')
				cout << "Yes" << endl;
		} else if (ptr == 2) {
			if (st[0] == ')' && st[1] == '(')
				cout << "Yes" << endl;
		} else if (ptr == 0 && equalnum > 1) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
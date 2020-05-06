/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-06 12:34:21
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

int t, n;
int cnt;
int tot;
double ans;

char str[11][11];

int PraseName(char * str) {
	int len = strlen(str);
	int ptr = 0;
	while (ptr < len && str[ptr] != '[')
		ptr++;
	int cnt = 1;
	int num = 0;
	if (ptr < len && str[ptr] == '[') {
		ptr++;
		while (ptr < len && str[ptr] != ']') {
			num = num * 10 + (str[ptr] - '0');
			// cout << str[ptr] << endl;
			ptr++;
		}
	}
	return max(cnt, num);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int kase = 0;
	scanf("%d", &t);
	while (t--) {
		tot = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", str[0]);
			cnt = 1;
			while ((scanf("%s", str[cnt]), 1) && str[cnt][strlen(str[cnt]) - 1] != ';' && cnt++);
			switch (cnt + 1) {
			case 2:
				if (strcmp(str[0], "char") == 0) {
					tot += PraseName(str[cnt]);
				} else if (strcmp(str[0], "bool") == 0) {
					tot += PraseName(str[cnt]);
				} else if (strcmp(str[0], "int") == 0) {
					tot += PraseName(str[cnt]) * 4;
				} else if (strcmp(str[0], "__int128") == 0) {
					tot += PraseName(str[cnt]) * 16;
				} else if (strcmp(str[0], "float") == 0) {
					tot += PraseName(str[cnt]) * 4;
				} else if (strcmp(str[0], "double") == 0) {
					tot += PraseName(str[cnt]) * 8;
				}
				break;
			case 3:
				if (strcmp(str[1], "double") == 0) {
					tot += PraseName(str[cnt]) * 16;
				} else if (strcmp(str[1], "long") == 0) {
					tot += PraseName(str[cnt]) * 8;
				}
				break;
			}
		}
		// printf("%d\n", tot );
		printf("Case #%d: %.0f\n", ++kase, ceil((double)tot / 1024));
	}
	return 0;
}
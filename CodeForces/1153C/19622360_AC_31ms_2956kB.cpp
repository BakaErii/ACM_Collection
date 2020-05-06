/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-05-06 20:01:20
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

const int maxN = 3000005;

char str[maxN];

int n, lefLCnt, lCnt, rCnt, dep;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	scanf("%s", str);
	if(n % 2 == 1 || str[0] == ')' || str[n - 1] == '(') {
		printf(":(\n");
		return 0;
	}
	for(int i = 0; i < n; i++) {
		if(str[i] == '(')
			lCnt++;
		if(str[i] == ')')
			rCnt++;
	}
	lefLCnt = n / 2 - lCnt;
	for(int i = 0; i < n; i++) {
		switch(str[i]) {
		case '(':
			dep++;
			break;
		case ')':
			dep--;
			break;
		case '?':
			if(lefLCnt > 0) {
				dep++;
				lCnt++;
				lefLCnt--;
				str[i] = '(';
			} else {
				dep--;
				rCnt++;
				str[i] = ')';
			}
			break;
		}
		if(dep == 0 && i != n - 1) {
			printf(":(\n");
			return 0;
		}
	}
	if(lCnt==rCnt)
		printf("%s\n", str );
	else
		printf(":(\n");
	return 0;
}
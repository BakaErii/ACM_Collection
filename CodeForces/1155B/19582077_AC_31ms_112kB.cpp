/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-04 10:11:15
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

int n;
char str[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	scanf("%s", str);
	int cnt = (n - 11) / 2;
	int aptr = 0;
	int bptr = 0;
	while (aptr < n && str[aptr] == '8')
		aptr++;
	while (bptr < n && str[bptr] != '8')
		bptr++;
	for (int i = 0; i < cnt; i++) {
		// A
		aptr++;
		while (aptr < n && str[aptr] == '8')
			aptr++;
		if (aptr >= n) {
			printf("YES\n");
			return 0;
		}
		// B
		bptr++;
		while (bptr < n && str[bptr] != '8')
			bptr++;
		if (bptr >= n) {
			printf("NO\n");
			return 0;
		}
	}
	if (str[min(aptr, bptr)] == '8')
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
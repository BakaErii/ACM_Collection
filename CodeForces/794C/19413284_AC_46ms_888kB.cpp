/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-23 19:18:49
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

const int maxN = 300005;

char a[maxN];
char b[maxN];
char ans[maxN];
int aPtr, bPtr, aEnd, bEnd, ansFPtr, ansLPtr;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	gets(a);
	gets(b);
	int len = strlen(a);
	sort(a, a + len);
	sort(b, b + len, greater<char>());
	if(len % 2 == 0) {
		aEnd = len / 2 - 1;
		bEnd = len / 2 - 1;
	} else {
		aEnd = len / 2;
		bEnd = len / 2 - 1;
	}
	int cnt = 0;
	ansLPtr = len - 1;
	while(ansFPtr <= ansLPtr) {
		if(cnt % 2 == 0) {
			if(a[aPtr] < b[bPtr])
				ans[ansFPtr++] = a[aPtr++];
			else
				ans[ansLPtr--] = a[aEnd--];
		} else {
			if(a[aPtr] < b[bPtr])
				ans[ansFPtr++] = b[bPtr++];
			else
				ans[ansLPtr--] = b[bEnd--];
		}
		cnt++;
	}
	ans[len] = '\0';
	printf("%s\n", ans );
	return 0;
}
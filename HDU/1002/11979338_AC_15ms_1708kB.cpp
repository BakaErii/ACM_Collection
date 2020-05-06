/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-15 18:02:36
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

char a[1005], b[1005];
int c[1005];

int main(void) {
	int i, n, alen, blen, ptr, kase = 0;
	cin >> n;
	getchar();
	while (n--) {
		kase++;
		for (i = 0; i < 1005; i++)
			c[i] = 0;
		ptr = 1004;
		cin >> a >> b;
		alen = strlen(a);
		blen = strlen(b);
		for (i = alen - 1; i >= 0; i--)
			c[ptr--] = a[i] - '0';
		ptr = 1004;
		for (i = blen - 1; i >= 0; i--) {
			c[ptr] += b[i] - '0';
			if (c[ptr] >= 10) {
				c[ptr - 1] += 1;
				c[ptr] -= 10;
			}
			ptr--;
		}
		if(kase!=1)
			putchar('\n');
		printf("Case %d:\n", kase );
		cout << a << " + " << b << " = ";
		for (i = 0; i < 1005; i++)
			if (c[i] != 0)
				for (; i < 1005; i++)
					printf("%d", c[i] );
		putchar('\n');
	}
	return 0;
}
/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-27 15:22:49
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
	int q, w, b;
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &b, &w);
		if (w > 3 * b + 1 || b > 3 * w + 1)
			printf("NO\n");
		else {
			printf("YES\n");
			int tmp = min(w, b);
			for (int i = 0; i < 2 * tmp; i++)
				printf("2 %d\n", i + 2 );
			b -= tmp;
			w -= tmp;
			// White
			for (int i = 0; i < w; i++)
				if (i < tmp)
					printf("1 %d\n", 2 * i + 3 );
				else if (i < tmp * 2)
					printf("3 %d\n", 2 * i + 3 - 2 * tmp );
				else
					printf("2 %d\n", 2 * tmp + 2 );
			// Black
			for (int i = 0; i < b; i++)
				if (i < tmp)
					printf("1 %d\n", 2 * i + 2 );
				else if (i < tmp * 2)
					printf("3 %d\n", 2 * i + 2 - 2 * tmp );
				else
					printf("2 1\n");
		}
	}
	return 0;
}
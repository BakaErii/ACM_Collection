/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-23 15:43:31
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	double ans;
	int a, b, n, i;
	char c;
	while (cin >> n) {
		for (i = 0; i < n; i++) {
			getchar();
			c = getchar();
			cin >> a >> b;
			switch (c) {
			case '+':
				ans = a + b;
				break;
			case '-':
				ans = a - b;
				break;
			case '*':
				ans = a * b;
				break;
			case '/':
				ans = (double)a / (double)b;
				break;
			}
			if (ans == (int)ans)
				printf("%d\n", (int)ans );
			else
				printf("%.2lf\n", ans );
		}
	}
	return 0;
}
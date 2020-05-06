/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-02 19:48:14
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

int ans[100];

int main(void) {
	int i, a, b, num;
	while (cin >> a >> b) {
		if (a == 0 && b == 0)
			return 0;
		num = 0;
		for (i = 0; i < 100; i++)
			if ((a * 100 + i) % b == 0)
				ans[num++] = i;
		for (i = 0; i < num; i++) {
			if (i != 0)
				printf(" ");
			if(ans[i]>=10)
				printf("%d", ans[i] );
			else
				printf("0%d",ans[i] );
		}
		printf("\n");
	}
	return 0;
}
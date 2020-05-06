/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-18 23:00:44
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

int arr[20];

int main(void) {
	int i, j, n, ans;
	while (1) {
		ans = 0;
		n = 0;
		while (scanf("%d", &arr[n])) {
			if (arr[n] == 0 || arr[n] == -1)
				break;
			n++;
		}
		//输入结束
		if (arr[0] == -1)
			return 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if ((double)arr[i] / (double)arr[j] == 2 && i != j)
					ans++;
		printf("%d\n", ans );
	}
	return 0;
}
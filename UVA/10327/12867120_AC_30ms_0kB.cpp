/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-08 02:01:04
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

int arr[1000];

int main(void) {
	int i, n, ans, op;
	while (~scanf("%d", &n)) {
		//init
		ans = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		while (1) {
			op = 0;
			for (i = 1; i < n; i++)
				if (arr[i - 1] > arr[i]) {
					swap(arr[i - 1], arr[i]);
					op++;
				}
			if (op == 0)
				break;
			else
				ans += op;
		}
		printf("Minimum exchange operations : %d\n", ans);
	}
	return 0;
}
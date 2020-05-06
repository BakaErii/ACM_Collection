/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-08 18:10:35
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

int arr1[100], arr2[100];

int main(void) {
	int i, n, cv, jv;
	while (cin >> n && n != 0) {
		cv = 0;
		jv = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &arr1[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &arr2[i]);
		sort(arr1, arr1 + n);
		sort(arr2, arr2 + n);
		for (i = 0; i < n; i++)
			if (arr1[i] == arr2[i]) {
				cv++;
				jv++;
			} else if (arr1[i] > arr2[i])
				cv += 2;
			else
				jv += 2;
		printf("%d vs %d\n", cv, jv );
	}
	return 0;
}
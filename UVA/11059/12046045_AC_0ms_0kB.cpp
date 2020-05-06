/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-22 18:57:48
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

int arr[18];

int main(void) {
	int kase, i, j, n;
	kase = 0;
	long long int thissum, maxsum;
	while (~scanf("%d", &n)) {
		maxsum = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		for (i = 0; i < n; i++) {
			thissum = 1;
			for (j = i; j < n; j++) {
				thissum *= arr[j];
				maxsum = max(thissum, maxsum);
			}
		}
		cout << "Case #" << ++kase << ": The maximum product is " << maxsum << "." << endl;
		putchar('\n');
	}
	return 0;
}
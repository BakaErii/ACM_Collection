/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-24 14:44:46
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

int arr[41] = {1, 1, 2, 6, 24, 120, 720, 1022, 140, 1260, 546, 1988, 1757, 742, 343, 1127, 1960, 1176, 1078, 392, 1813, 1911, 1862, 637, 1225, 490, 686, 441, 294, 490, 637, 1666, 1078, 1421, 98, 1421, 931, 294, 1127, 1764, 245};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (~scanf("%d", &n)) {
		if (n <= 40)
			printf("%d\n", arr[n] );
		else
			printf("0\n");
	}
	return 0;
}
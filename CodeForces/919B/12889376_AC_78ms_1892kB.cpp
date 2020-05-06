/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-31 21:22:19
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

int arr[10000];

int main(void) {
	int i, n, k, tmp, tmpa;
	k = 0;
	for (i = 0; k < 10000; i++) {
		tmp = i;
		tmpa = 0;
		while (tmp > 0) {
			tmpa += tmp % 10;
			tmp /= 10;
			if (tmpa > 10)
				break;
		}
		if (tmpa == 10)
			arr[k++] = i;
	}
	cin >> n;
	cout << arr[n - 1] << endl;
	return 0;
}
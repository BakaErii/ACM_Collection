/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-24 19:15:02
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
	int i, n, tmp, sum;
	while (~scanf("%d", &n) && n != 0) {
		sum = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &tmp);
			sum ^= tmp;
		}
		if (sum == 0)
			cout << "Grass Win!" << endl;
		else
			cout << "Rabbit Win!" << endl;
	}
	return 0;
}
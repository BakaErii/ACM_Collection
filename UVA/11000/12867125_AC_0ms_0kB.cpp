/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-19 03:08:58
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
	unsigned long long int a, b, na, nb;
	int i, n;
	while (~scanf("%d", &n) && n != -1) {
		a = 1;
		b = 0;
		for (i = 0; i < n; i++) {
			na = b + 1;
			nb = a + b;
			a = na;
			b = nb;
		}
		cout << b << " " << a + b << endl;
	}
	return 0;
}
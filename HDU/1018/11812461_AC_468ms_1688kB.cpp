/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-02 16:33:09
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
	int n, m, i;
	double tmp = 0;
	//位数=log10(n!)==log10(1*2*3*4*5*6*...)==log10(1)+log10(2)+.....
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		tmp = 0;
		for (i = 1; i <= m; i++)
			tmp += log10(i);
		printf("%d\n", (int)tmp + 1 );
	}
	return 0;
}
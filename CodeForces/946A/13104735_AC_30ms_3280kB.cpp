/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-19 19:06:08
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

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int perB, perC, i, n, tmp;
	scanf("%d", &n);
	perB = perC = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp > 0)
			perB += tmp;
		else
			perC += tmp;
	}
	printf("%d\n", perB - perC );
	return 0;
}
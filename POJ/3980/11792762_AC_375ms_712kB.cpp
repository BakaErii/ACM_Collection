/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-01 16:21:03
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

int mod(int a, int b) {
	return a % b;
}

int main(void) {
	int a, b;
	while (~scanf("%d %d", &a, &b))
		printf("%d\n", mod(a, b) );
	return 0;
}
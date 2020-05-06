/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-05-08 07:32:42
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
	int num, k;
	scanf("%d %d", &num, &k);
	for(int i = 0; i < k; i++)
		if(num % 10 == 0)
			num /= 10;
		else
			num--;
	printf("%d\n", num);
	return 0;
}
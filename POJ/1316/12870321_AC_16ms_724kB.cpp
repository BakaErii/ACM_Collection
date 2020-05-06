/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-19 02:48:02
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

int arr[10001];

void cal(int in) {
	int tmp = in;
	while (in > 0) {
		tmp += in % 10;
		in /= 10;
	}
	if (tmp > 10000 || arr[tmp] == 0)
		return;
	else {
		arr[tmp] = 0;
		cal(tmp);
	}
}

int main(void) {
	int i = 1;
	for (i = 1; i < 10001; i++)
		arr[i] = 1;
	for (i = 1; i < 10001; i++)
		cal(i);
	for (i = 1; i < 10001; i++)
		if (arr[i] == 1)
			printf("%d\n", i );
	return 0;
}
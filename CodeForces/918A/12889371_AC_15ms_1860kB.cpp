/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-29 23:25:39
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

int arr[1000];
char carr[1005];

int main(void) {
	arr[0] = 1;
	arr[1] = 1;
	int i, n;
	for (i = 2; i < 20; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	for (i = 0; i < 1005; i++)
		carr[i] = 'o';
	for (i = 0; i < 20; i++)
		if (arr[i] <= 1000)
			carr[arr[i] - 1] = 'O';
	cin >> n;
	for (i = 0; i < n; i++)
		putchar(carr[i]);
	putchar('\n');
	return 0;
}
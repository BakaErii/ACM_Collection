/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-05 12:21:18
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

string perStr, inStr;

void findTree(int root, int left, int right) {
	int i;
	if (left > right)
		return;
	for (i = left; i <= right && perStr[root] != inStr[i]; i++);
	findTree(root + 1, left, i - 1);
	findTree(root + i - left + 1, i + 1, right);
	putchar(inStr[i]);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> perStr >> inStr) {
		findTree(0, 0, perStr.length() - 1);
		putchar('\n');
	}
	return 0;
}
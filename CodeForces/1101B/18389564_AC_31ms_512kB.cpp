/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-11 22:34:53
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

char str[500005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int leftPtr, rightPtr;
	int len, ptr, ans = 4;
	gets(str);
	// INIT
	len = strlen(str);
	// Fetch left
	ptr = 0;
	while (str[ptr] != '[' && str[ptr] != '\0')
		ptr++;
	while (str[ptr] != ':' && str[ptr] != '\0')
		ptr++;
	if (ptr == len) {
		printf("-1\n");
		return 0;
	}
	leftPtr = ptr;
	// Fetch right
	ptr = len - 1;
	while (str[ptr] != ']' && ptr > leftPtr)
		ptr--;
	while (str[ptr] != ':' && ptr > leftPtr)
		ptr--;
	if (ptr == leftPtr) {
		printf("-1\n");
		return 0;
	}
	rightPtr = ptr;
	rightPtr--;
	// Solve
	for (int i = rightPtr; i > leftPtr; i--)
		if (str[i] == '|')
			ans++;
	printf("%d\n", ans );
	return 0;
}
/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-20 16:00:20
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

char arr[101];
const char vowels[7] = "aeiouy";
int ptr = 0;

void checkStack(void) {
	int i, j;
	if (ptr > 1) {
		for (i = 0; i < 6; i++)
			if (arr[ptr - 1] == vowels[i])
				break;
		for (j = 0; j < 6; j++)
			if (arr[ptr - 2] == vowels[j])
				break;
		if (i != 6 && j != 6)
			ptr--;
	}
	return;
}

int main(void) {
	int i, n;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		scanf("%c", &arr[ptr++]);
		checkStack();
	}
	for (i = 0; i < ptr; i++)
		putchar(arr[i]);
	putchar('\n');
	return 0;
}
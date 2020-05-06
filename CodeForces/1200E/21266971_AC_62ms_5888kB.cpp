/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-13 11:48:37
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

const int maxN = 1000005;

char arrStr[maxN];
char tmpStr[maxN];
int arrNext[maxN];

int n, tmpLen, strLen;

void GetNext() {
	int ptr = 0;
	int matchPtr = -1;
	arrNext[0] = -1;
	while (ptr < tmpLen) {
		if (matchPtr == -1 || tmpStr[matchPtr] == tmpStr[ptr]) {
			matchPtr++;
			ptr++;
			arrNext[ptr] = matchPtr;
		} else
			matchPtr = arrNext[matchPtr];
	}
	return;
}

int Match() {
	int ptr = max(strLen - tmpLen, 0);
	int matchPtr = 0;
	while (ptr < strLen) {
		if (matchPtr == -1 || arrStr[ptr] == tmpStr[matchPtr]) {
			ptr++;
			matchPtr++;
		} else
			matchPtr = arrNext[matchPtr];
	}
	return matchPtr;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	scanf("%s", arrStr);
	strLen = strlen(arrStr);
	for (int i = 1; i < n; i++) {
		scanf("%s", tmpStr);
		tmpLen = strlen(tmpStr);
		GetNext();
		for (int i = Match(); i < tmpLen; i++)
			arrStr[strLen++] = tmpStr[i];
	}
	arrStr[strLen] = '\0';
	printf("%s\n", arrStr);
	return 0;
}
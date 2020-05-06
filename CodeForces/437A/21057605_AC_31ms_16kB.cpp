/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-04 14:46:50
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

const int maxN = 105;

char str[4][maxN];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ansCnt = 0, ansIdx = 0;
	int len[4];
	for (int i = 0; i < 4; i++) {
		scanf("%s", str[i]);
		len[i] = strlen(str[i]) - 2;
	}
	for (int i = 0; i < 4; i++) {
		int t = 0;
		for (int j = 0; j < 4; j++) {
			if (i == j)
				continue;
			if (len[i] >= len[j] * 2)
				t++;
		}
		if (t == 3) {
			ansCnt++;
			ansIdx = i;
		}
		t = 0;
		for (int j = 0; j < 4; j++) {
			if (i == j)
				continue;
			if (len[i] * 2 <= len[j] )
				t++;
		}
		if (t == 3) {
			ansCnt++;
			ansIdx = i;
		}
	}
	if (ansCnt == 1)
		printf("%c\n", 'A' + ansIdx);
	else
		printf("C\n");
	return 0;
}
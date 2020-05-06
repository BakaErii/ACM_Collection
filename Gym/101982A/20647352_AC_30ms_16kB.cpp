/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-22 12:07:14
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

char strA[1005];
char strB[1005];
bool use[1005];
int lenA, lenB, k, ans, lft;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &k);
	scanf("%s", strA);
	scanf("%s", strB);	
	lenA = strlen(strA);
	lenB = strlen(strB);
	lft = lenA;
	// True
	for (int i = 0; i < lenA; i++)
		if (strA[i] == strB[i] && k > 0) {
			k--;
			lft--;
			ans++;
			use[i] = true;
		}
	// Switch
	if (k == 0) {
		for (int i = 0; i < lenA; i++)
			if (use[i] == false && strA[i] != strB[i])
				ans++;	
	} else {
		ans += lft - k;
	}
	printf("%d\n", ans );
	return 0;
}
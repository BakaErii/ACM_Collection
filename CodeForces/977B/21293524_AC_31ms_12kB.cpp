/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-14 14:18:28
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

int arr[26][26];
char str[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int ans = 0;
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 1; i < n; i++)
		arr[str[i - 1] - 'A'][str[i] - 'A']++;
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			ans = max(ans, arr[i][j]);
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			if (arr[i][j] == ans){
				printf("%c%c\n", i + 'A', j + 'A' );
				return 0;
			}
	return 0;
}
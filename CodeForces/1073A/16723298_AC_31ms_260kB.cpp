/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-29 18:43:30
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

int n;
string str;
int arr[26];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> str;
	for (int i = 0; i < n - 1; i++)
		if (str[i] != str[i + 1]) {
			printf("YES\n");
			printf("%c%c\n", str[i], str[i + 1]);
			return 0;
		}
	printf("NO\n");
	return 0;
}
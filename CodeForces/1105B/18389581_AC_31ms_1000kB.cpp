/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-20 20:33:49
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

char str[200005];
int arr[200005];
int ans[26];
int n, k;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &k);
	getchar();
	gets(str);
	arr[0] = 1;
	int lastans = 0;
	for (int i = 1; i < n; i++)
		if (str[i] == str[i - 1])
			arr[i] = arr[i - 1] + 1;
		else
			arr[i] = 1;
	for (int i = 0; i < n; i++)
		if (arr[i] % k == 0)
			ans[str[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		lastans = max(lastans, ans[i]);
	printf("%d\n", lastans );
	return 0;
}
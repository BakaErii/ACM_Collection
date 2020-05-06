/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-04 10:01:26
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

const int maxN = 300005;

int n;
char str[maxN];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 1; i < n; i++)
		if (str[i] < str[i - 1]) {
			printf("YES\n");
			printf("%d %d\n", i, i + 1 );
			return 0;
		}
	printf("NO\n");
	return 0;
}
/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-04 10:55:58
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

typedef long long int LL;

int n, m;
LL arrN[maxN];
LL arrM[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arrN[i]);
	for (int i = 0; i < m; i++)
		scanf("%lld", &arrM[i]);
	LL minGcd = arrN[1] - arrN[0];
	for (int i = 2; i < n; i++)
		minGcd = __gcd(minGcd, arrN[i] - arrN[i - 1]);
	for (int i = 0; i < m; i++)
		if (minGcd % arrM[i] == 0) {
			printf("YES\n");
			printf("%lld %d\n", arrN[0], i + 1 );
			return 0;
		}
	printf("NO\n");
	return 0;
}
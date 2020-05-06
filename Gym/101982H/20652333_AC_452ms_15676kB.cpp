/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-22 12:30:37
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
#include <fstream>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

ofstream file;

int prime[1000005];
int check[1000005];
struct Xx
{
	int p, q;
} X[1000005];

int tot = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	check[1] = true;
	check[0] = true;
	for (int i = 2; i < 1000005; ++i)
	{
		if (!check[i])
		{
			prime[tot++] = i;
		}
		for (int j = 0; j < tot; ++j)
		{
			if (i * prime[j] > 1000005)
			{
				break;
			}
			check[i * prime[j]] = 1;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
	int x;
	scanf("%d", &x);
	int times = 0;
	while (x >= 4) {
		for (int i = tot - 1; i >= 0; i--)
			if (x - prime[i] >= 0 && !check[x - prime[i]]) {
				x = prime[i] - (x - prime[i]);
				times++;
				break;
			}
	}
	printf("%d\n", times);
	return 0;
}
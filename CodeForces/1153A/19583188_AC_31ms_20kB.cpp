/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-04 11:09:15
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

int n, t;

typedef long long int LL;

struct Node
{
	LL u, v;
} N[105];

struct Ans
{
	LL val;
	int id;
	bool operator < (const Ans & a) const {
		return val < a.val;
	}
} A[105];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &N[i].u, &N[i].v);
	for (int i = 0; i < n; i++) {
		LL mod = abs(t - N[i].u) % N[i].v;
		LL k = abs(t - N[i].u) / N[i].v;
		if (mod != 0)
			k++;
		A[i].val = N[i].u + k * N[i].v;
		A[i].id = i + 1;
		if (t <= N[i].u)
			A[i].val = min(A[i].val, N[i].u);
	}
	sort(A, A + n);
	printf("%d\n", A[0].id );
	return 0;
}
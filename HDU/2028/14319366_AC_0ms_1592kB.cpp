#include<cstdio>
#include<algorithm>

using namespace std;

int main(void)
{
	long long int a[1000], i, n, m, max, mid, j, k;
	while (scanf("%lld", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
		}
		max = a[0];
		for (i = 1; i < n; i++)
		{
			mid = max * a[i];
			max = mid / __gcd(max, a[i]);
			// for (;;)
			// {
			// 	m = j % k;
			// 	if (m == 0)
			// 	{
			// 		max = mid / k;
			// 		break;
			// 	}
			// 	j = k;
			// 	k = m;
			// }
		}
		printf("%lld\n", max);
	}
	return 0;
}

/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-11-28 19:04:48
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int maxN = 21;

long long int LCM(long long int a, long long int b) {
	long long int ret = __gcd(a, b);
	ret = a / ret * b;
	return ret;
}

long long int arr[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n, m, ans, sum, cnt;
	while(~scanf("%lld %lld", &n, &m)) {
		// INIT
		ans = 0;
		for(int i = 0; i < m; i++)
			scanf("%lld", &arr[i]);
		// for each subset
		for(int i = 1; i < (1 << m); i++) {
			sum = 1;
			cnt = 0;
			for(int j = 0; j < m; j++)
				if((1 << j)&i) {
					sum = LCM(sum, arr[j]);
					if(sum > n)
						break;
					cnt++;
				}
			if(cnt % 2 == 1)
				ans += n / sum;
			else
				ans -= n / sum;
		}
		printf("%lld\n", n - ans );
	}
	return 0;
}
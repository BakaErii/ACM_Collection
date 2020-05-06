/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-26 18:59:49
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

const int maxN = 50005;

long long int arrPrime[maxN];
bool isPrime[maxN];
int cnt;

void calPrimes() {
	memset(isPrime, 1, sizeof(isPrime));
	cnt = 0;
	isPrime[1] = false;
	for (long long int i = 2; i < maxN; i++) {
		if (isPrime[i] == true)
			arrPrime[cnt++] = i;
		for (int j = 0; j < cnt && i * arrPrime[j] < maxN; j++) {
			isPrime[i * arrPrime[j]] = false;
			if (i % arrPrime[j] == false)
				break;
		}
	}
	return;
}

long long int calNum(int n) {
	long long int ret = 1;
	int num;
	for (int i = 0; i < cnt; i++) {
		if (n % arrPrime[i] == 0) {
			num = 1;
			while (n % arrPrime[i] == 0 && n > 0) {
				num++;
				n /= arrPrime[i];
			}
			ret *= num;
		}
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int maxNum, maxCount;
	int t, l, r;
	calPrimes();
	scanf("%d", &t);
	while (t--) {
		maxNum = 0;
		maxCount = 0;
		scanf("%d %d", &l, &r);
		for (int i = l; i <= r; i++) {
			long long int tmp = calNum(i);
			if (tmp > maxCount) {
				maxCount = tmp;
				maxNum = i;
			}
		}
		printf("Between %d and %d, %lld has a maximum of %lld divisors.\n", l, r, maxNum, maxCount);
	}
	return 0;
}
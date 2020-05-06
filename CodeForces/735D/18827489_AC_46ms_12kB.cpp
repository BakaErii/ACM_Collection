/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-03-20 19:16:23
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

bool isPrime(long long int x) {
	long long int tmp = (int)sqrt(x);
	for(int i = 2; i <= tmp; i++)
		if(x % i == 0)
			return false;
	return true;
}

long long int t;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%lld", &t);
	if(t == 2) {
		printf("1\n");
		return 0;
	}
	if(isPrime(t)) {
		printf("1\n");
		return 0;
	}
	if(t % 2 == 0)
		printf("2\n");
	else {
		if(isPrime(t - 2))
			printf("2\n");
		else
			printf("3\n");
	}
	return 0;
}
/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-03-20 19:35:56
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

typedef unsigned long long int ULL;

ULL tab[1000005];
int ptr;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ULL t;
	tab[0] = 1;
	tab[1] = 2;
	ptr = 1;
	while(tab[ptr] <= 1e18) {
		tab[ptr + 1] = tab[ptr] + tab[ptr - 1];
		ptr++;
	}
	scanf("%llu", &t);
	for(int i = 1; i < ptr; i++)
		if(tab[i] <= t && t < tab[i + 1]) {
			printf("%d\n", i );
			return 0;
		}
	printf("%d\n", ptr - 1 );
	return 0;
}
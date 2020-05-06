/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-24 18:18:24
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

long long int fib[450];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, n, ptr;
	fib[0] = 1;
	fib[1] = 2;
	ptr = 1;
	while (fib[ptr] < 2147483648) {
		ptr++;
		fib[ptr] = fib[ptr - 1] + fib[ptr - 2];
	}
	while (~scanf("%d", &n) && n != 0) {
		for (i = 0; i < ptr; i++)
			if (fib[i] == n)
				break;
		if (i == ptr)
			cout << "First win" << endl;
		else
			cout << "Second win" << endl;
	}
	return 0;
}
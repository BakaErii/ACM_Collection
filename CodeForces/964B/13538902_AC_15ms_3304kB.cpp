/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-04-17 22:33:09
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

int n, A, B, C, T;
int arr[1001];
int value[1001];
bool isRead[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	unsigned long long int ans = 0;
	scanf("%d %d %d %d %d", &n, &A, &B, &C, &T);
	for(i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		value[i] = A;
	}
	for(i = 1; i < T; i++) {
		for(j = 0; j < n; j++) {
			if(isRead[j] != true && arr[j] <= i) {
				if(value[j] + C - B > value[j]) {
					value[j] -= B;
					ans += C;
				} else {
					ans += value[j];
					isRead[j] = true;
				}
			}
		}
	}
	for(j = 0; j < n; j++)
		if(isRead[j] == false)
			ans += value[j];
	printf("%llu\n", ans);
	return 0;
}
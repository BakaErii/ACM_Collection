/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-25 16:31:37
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

int arr[100000];

int main(void) {
	int n, i , ansa, ansb, tima, timb, ptra, ptrb;
	ansa = 0;
	ansb = 0;
	tima = 0;
	timb = 0;
	cin >> n;
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	ptra = 0;
	ptrb = n - 1;
	while (n--) {
		if (tima <= timb) {
			tima += arr[ptra++];
			ansa++;
		} else {
			timb += arr[ptrb--];
			ansb++;
		}
	}
	cout << ansa << " " << ansb << endl;
	return 0;
}
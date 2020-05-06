/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-23 15:22:47
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int array[10000];

int main(void) {
	int n, i;
	while (cin >> n) {
		for (i = 0; i < n; i++)
			cin >> array[i];
		sort(array, array + n);
		cout << array[n / 2] << endl;
	}
	return 0;
}
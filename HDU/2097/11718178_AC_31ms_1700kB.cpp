/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-25 21:12:44
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

int arr[68] = {2992, 2993, 2994, 2995, 2996, 2997, 2998, 2999, 4470, 4471, 4472, 4473, 4474, 4475, 4970, 4971, 4972, 4973, 4974, 4975, 5460, 5461, 5462, 5463, 5464, 5465, 5466, 5467, 5468, 5469, 5960, 5961, 5962, 5963, 6456, 6457, 6458, 6459, 7440, 7441, 7442, 7443, 7444, 7445, 7446, 7447, 7448, 7449, 7940, 7941, 7942, 7943, 8436, 8437, 8438, 8439, 9424, 9425, 9426, 9427, 9428, 9429, 9924, 9925, 9926, 9927, 9928, 9929};

int main(void) {
	int n, i;
	while (cin >> n && n != 0) {
		for (i = 0; i < 68; i++)
			if (arr[i] == n) {
				cout << n << " is a Sky Number." << endl;
				break;
			}
		if (i == 68)
			cout << n << " is not a Sky Number." << endl;
	}
	return 0;
}
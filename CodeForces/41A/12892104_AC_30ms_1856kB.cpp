/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-04 14:03:36
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

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	if (a == b)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
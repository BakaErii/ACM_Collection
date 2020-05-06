/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-14 20:35:35
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

int main(void) {
	string str;
	int i, num0 = 0;
	bool is1exist = false;
	cin >> str;
	for (i = 0; i < (int)str.length(); i++)
		if (str[i] == '1')
			is1exist = true;
		else if (str[i] == '0' && is1exist == true)
			num0++;
	if(num0>=6)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}
/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-15 15:47:21
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
	bool isBack = false, isForward = false;
	string a, b, c;
	cin >> a >> b >> c;
	if (a.find(b)+b.length() <= a.rfind(c) && a.find(b) != string::npos && a.rfind(c) != string::npos)
		isForward = true;
	reverse(a.begin(), a.end());
	if (a.find(b)+b.length() <= a.rfind(c) && a.find(b) != string::npos && a.rfind(c) !=string::npos)
		isBack = true;
	if (isForward && isBack)
		cout << "both" << endl;
	else if (isForward)
		cout << "forward" << endl;
	else if (isBack)
		cout << "backward" << endl;
	else
		cout << "fantasy" << endl;
	return 0;
}
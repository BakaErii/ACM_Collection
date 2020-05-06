/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-02 21:11:23
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
	int y, w, d;
	cin >> y >> w;
	d = max(y, w);
	switch(d){
		case 1:cout<<"1/1"<<endl;break;
		case 2:cout<<"5/6"<<endl;break;
		case 3:cout<<"2/3"<<endl;break;
		case 4:cout<<"1/2"<<endl;break;
		case 5:cout<<"1/3"<<endl;break;
		case 6:cout<<"1/6"<<endl;break;
	}
	return 0;
}
/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-19 03:23:43
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

string str[20];
int n;

void deal(int i) {
	if (i + 2 <= n) {
		cout << str[i] << endl;
		deal(i + 2);
		cout << str[i + 1] << endl;
	}else if(i+1==n){
		cout<<str[i]<<endl;
	}
	return;
}

int main(void) {
	int kase = 0;
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; i++)
			cin >> str[i];
		printf("SET %d\n", ++kase);
		deal(0);
	}
	return 0;
}
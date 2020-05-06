/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-04-16 18:54:04
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
	int n,ans=0;
	string str;
	cin>>n;
	cin>>str;
	for(int i=0;i<(int)str.length();i++){
		if(i<(int)str.length()-1&&((str[i]=='U'&&str[i+1]=='R')||(str[i]=='R'&&str[i+1]=='U')))
			i++;
		ans++;
	}
	printf("%d\n",ans );
	return 0;
}
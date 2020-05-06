/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-04-16 19:13:37
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

int maxLen,nowLen,n;
string str;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i,j;
	cin>>n;
	cin>>str;
	for(i=0;i<(int)str.length();i++){
		if(str[0]==str[i]){
			nowLen=i;
			for(j=0;j<nowLen&&i+j<(int)str.length();j++)
				if(str[j]!=str[i+j])
					break;
			if(j==nowLen)
				maxLen=nowLen;
		}
	}
	printf("%d\n",min(n-maxLen+1,n));
	return 0;
}
/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-04 03:09:00
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
    string a,b,tmp;
    int i,j,abit,bbit;
    cin>>a>>b;
    abit=(int)a.length();
    bbit=(int)b.length();
    if(abit<bbit){
        sort(a.rbegin(),a.rend());
        cout<<a<<endl;
        return 0;
    }else{
        sort(a.begin(),a.end());
        for(i=0;i<a.length();i++)
            for(j=a.length()-1;j>i;j--){
                tmp=a;
                swap(a[i],a[j]);
                sort(a.begin()+i+1,a.end());
                if(a.compare(b)>0)
                    a=tmp;
                else
                    break;
            }
         cout<<a<<endl;
    }
	return 0;
}
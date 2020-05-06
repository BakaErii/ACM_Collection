#include <iostream>

using namespace std;

int main(void){
    int a,b,tmp;
    while(cin>>a>>b){
        tmp=a+b;
        if(tmp%86==0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}

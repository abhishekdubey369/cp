#include<iostream>
#include<string.h>

using namespace std;

void uclcnc(char *s){
    int l=0,u=0,n=0,c=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>=48 && s[i]<=57){
            n++;
        }else if(s[i]>=65 && s[i]<=90){
            u++;
        }else if(s[i]>=97 && s[i]<=122){
            l++;
        }else{
            c++;
        }
    }

    cout<<"total no."<<n<<endl;
    cout<<"total no. uc"<<u<<endl;
    cout<<"total no. lc"<<l<<endl;
    cout<<"total no. sc"<<c<<endl;

}

int main(void){
    char *s="HellOO1234WoRlD'";
    uclcnc(s);
    return 0;
}
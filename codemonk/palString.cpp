// To check if the given string is palindrome
#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    bool isPal = true;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != s[s.length() - i - 1])
                isPal = false;
    }
    if(isPal)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

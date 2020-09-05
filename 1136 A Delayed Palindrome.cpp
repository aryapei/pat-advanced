#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// 判断是否是回文字
bool isPalindrome(string s){
    int len = s.length();
    for(int i=0; i<len/2; i++){
       if(s[i] != s[len-1-i]) return false;
    } 
    return true;
}
// 字符串相加，这里是个难点
string add(string s1, string s2){
    string s=s1;
    int carry = 0;
    // 从字符串高位向低位加，其实就是数字的低位到高位
    for(int i=(int)s1.length()-1;i>=0;i--){
        s[i]=(s1[i] - '0' + s2[i] - '0' + carry)%10 + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry)/10;
    }
    if(carry>0){
        s = "1"+ s;
    }
    return s;
}
int main(){
    string s;
    cin >> s;
    
    if(isPalindrome(s)){
        cout<<s<<" is a palindromic number.\n";
        return 0;
    }
    // 总共10趟
    int n=10;
    while(n--){
        string r=s;
        reverse(r.begin(), r.end());
        string t = add(s, r);
        cout<< s << " + " << r << " = " << t <<endl;
        if(isPalindrome(t)){
            cout<<t<<" is a palindromic number.\n";
            return 0; 
        }else{
            s = t;
        }
    }
    cout<<"Not found in 10 iterations.\n";
    return 0;
    
}
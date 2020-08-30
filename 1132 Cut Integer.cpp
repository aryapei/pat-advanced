#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    for(int i=0; i<n; i++){
        int len = v[i].size();
        // substr的用法，第一个参数为下标，第二个参数为长度
        // 如果省略第二个参数表示直接取到结尾
        int a = stoi(v[i].substr(0, len/2));
        int b = stoi(v[i].substr(len/2));
        int num = stoi(v[i]);
        // 注意这里要判断a*b是否为0，否则会报【浮点错误】
        if(a*b!=0 && num % (a*b) == 0) 
            cout<< "Yes\n";
        else 
            cout<<"No\n";
    }
    return 0;
}
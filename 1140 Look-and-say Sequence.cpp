#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int n;
    cin >> s >> n;
    int k;
    // 第一轮就是输入的内容，所以从第二轮开始到第n轮遍历
    for(int i=2; i<=n; i++){
        string t;
        // j=k真的很妙，k为下个不重复的内容的下标
        for(unsigned int j=0; j<s.length(); j=k){
            // 从k=j开始遍历，直到出现不同于s[j]的内容
            for(k=j; s[k]==s[j];k++);
            t += s[j] + to_string(k-j);
        }
        s = t;
    }
    cout<<s;
    return 0;
}
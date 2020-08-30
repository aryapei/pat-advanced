//第一种解决方案：使用vector
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    // n个数字中，最多有n个正整数，所以缺失的最小正整数必定在（1，n+1）区间
    // 即n个数字中如果存在0或负数或重复的正整数，那么最小正整数必定在（1，n）区间
    // 否则最小正整数必定为n+1，综上必定为（1，n+1），所以声明动态数组a大小为n+1（下标0不用）
    // a[i] = -1,表示数组v中不存在整数i，初始化为全-1
    vector<int> a(n+2, -1);
    for(int i=0; i<n; i++){
        // 如果v[i]为正整数并且在(1,n+1)区间，标记它为1
        if(v[i] > 0 && v[i]<n+2){
            a[v[i]] = 1;
        }
    }
    // 遍历数组a，打印发现的第一个没标记的i
    for(int i=1; i<n+2; i++){
        if(a[i] < 0){
            cout<< i;
            return 0;
        }
    }
    return 0;
}


//第二种解决方案：使用map(更简洁了)
/*
#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, t, num=0;
    cin >> n;
    map<int, int> m;
    
    for(int i=0; i<n; i++){
        // 用一个int类型变量t临时存储每个数字，而不是存储所有的输入，更简洁了
        // 因为没必要把整个输入数组都存储起来，只要统计它们的个数等信息就可以了
        cin >> t;
        m[t]++;
    }
    while(++num){
        if(m[num] == 0){
            cout<<num;
            break;
        }
    }
    return 0;
}
*/
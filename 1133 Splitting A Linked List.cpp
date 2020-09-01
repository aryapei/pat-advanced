// 给⼀个链表和K，遍历链表后将<0的结点先输出，再将0～k区间的结点输出，最后输出>k的结点
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct node{
    string addr;
    int data;
    string next;
};
int main(){
    // 解决最后一个测试用例【超时】，关闭同步stdio
    // C++为了兼容C，保证程序在使用了std::printf和std::cout的时候不发生混乱，将输出流绑到了一起。
    // cin，cout之所以效率低，是因为先把要输出的东西存入缓冲区，再输出，导致效率降低，而这段语句可以来打消iostream的输入 输出缓存，可以节省许多时间，使效率与scanf与printf相差无几
    ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    string begin;   //把地址改为string类型，输出的时候就不用格式化了；如果是int类型00110会被读为110，后面输出的时候要重新格式化
    int n, k;
    cin >> begin >> n >> k;
    
    vector<node> v, v1, v2, v3;
    string addr, next;
    int data;
    
    // 使用map，以地址为索引存储这些结点
    map<string, node> m;
    for(int i=0; i<n; i++){
        cin >> addr >> data >> next;
        m[addr] = {addr, data, next};
    }
    // 从begin开始遍历,边遍历边按照data分类
    for(; begin != "-1"; begin = m[begin].next){
        if(m[begin].data < 0)  v1.push_back(m[begin]);
        else if(m[begin].data >=0 && m[begin].data <= k)   v2.push_back(m[begin]);
        else    v3.push_back(m[begin]);
    }
    // 按照顺序合并三个数组
    v.insert(v.end(), v1.begin(), v1.end());
    v.insert(v.end(), v2.begin(), v2.end());
    v.insert(v.end(), v3.begin(), v3.end());
    
    // 打印输出
    for(int i=0 ; i < (int)v.size(); i++){
        string next="-1";
        if(i < (int)v.size()-1 ) next = v[i+1].addr;
        // 注意这里换行的时候，不能是endl要是\n，不然最后一个测试用例会报【超时】的错误
        cout << v[i].addr << " " << v[i].data << " " << next <<"\n";
    }
    return 0;
}
#include<iostream>
#include<vector>
// map自动排序，中序遍历从小到大；unordered_map无序
#include<unordered_map>
// sort函数的头文件
#include<algorithm>
// 这题不难，但是有丢丢繁琐，一点点出错整个输出结果就全错了
using namespace std;
struct node{
    string s;
    int score;
};
// 排序函数，分数从大到小，学号从小到大
bool cmp(const node &a, const node &b){
    return a.score != b.score ? a.score > b.score : a.s < b.s;
}
int main(){
    int n, m, type;
    string term;
    cin >> n >> m;
    vector<node> v(n);
    // 原始数据读入v数组
    for(int i=0; i<n; i++)
        cin >> v[i].s >> v[i].score;
    // 根据情况开始处理
    for(int i=1; i<=m; i++){
        cin >> type >> term;
        // 注意这里要输出的是Case 【i】
        cout << "Case " << i << ": " << type << " " << term << "\n";
        // 每次循环一个新的ans数组，用来存放要打印出来的结果
        vector<node> ans;
        if(type == 1){
            for(int j=0; j<n; j++){
                if(v[j].s[0] == term[0]) ans.push_back(v[j]);
            }
        }
        if(type == 2){
            int cnt=0, sum=0;
            for(int j=0; j<n; j++){
                if(v[j].s.substr(1,3) == term){
                    cnt++;
                    sum += v[j].score;
                }
            }
            if(cnt != 0)   ans.push_back({to_string(cnt), sum});
        }
        if(type == 3){
            unordered_map<string, int> mymap;
            for(int j=0; j<n; j++){
                // 下标，长度
                if(v[j].s.substr(4,6) == term)
                    mymap[v[j].s.substr(1,3)]++;
            }
            // 遍历map，逐个添加
            for(auto it: mymap) ans.push_back({it.first, it.second});
        }
        // 如果ans数组为空，表示case1和case3没有查找到，以及case2的cnt为0
        if((int)ans.size() == 0){
            cout << "NA\n";
            continue;
        }
        // 排序并打印输出
        sort(ans.begin(), ans.end(), cmp);
        for(int j=0; j < (int)ans.size(); j++){
            cout << ans[j].s << " " << ans[j].score << "\n";
        }
    }
    return 0;
}
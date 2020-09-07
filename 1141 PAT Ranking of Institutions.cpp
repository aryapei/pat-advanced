#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
struct node{
    string school;
    int sum, num;
};
bool cmp(node a, node b){
    if(a.sum != b.sum)  return a.sum > b.sum;
    if(a.num != b.num)  return a.num < b.num;
    return a.school < b.school;
}
int main(){
    int n;
    cin >> n;
    unordered_map<string, int> cnt;
    unordered_map<string, double> sum;
    for(int i=0; i<n; i++){
        string id, school;
        double score;
        cin >> id >> score >> school;
        // 小写
        transform(school.begin(),school.end(),school.begin(),::tolower);
        if(id[0] == 'B')    score /= 1.5;
        if(id[0] == 'T')    score *= 1.5;
        sum[school] += score;
        cnt[school]++;
    }
    vector<node> ans;
    for(auto it=cnt.begin(); it!=cnt.end(); it++)   ans.push_back(node{it->first, (int)sum[it->first], cnt[it->first]});
    // 排序
    sort(ans.begin(), ans.end(), cmp);
    
    cout << (int)ans.size() << "\n";
    // 调整排名，如果总分和上一个一样，rank不变
    int rank = 0, pres = -1;
    for(int i=0; i<(int)ans.size(); i++){
        if(pres != ans[i].sum)  rank = i+1;
        pres = ans[i].sum;
        cout << rank << " "<< ans[i].school << " "<< ans[i].sum << " "<< ans[i].num << "\n";
    }
    return 0;
}
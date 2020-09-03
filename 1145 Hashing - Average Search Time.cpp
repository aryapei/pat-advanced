// 相关知识点：https://blog.csdn.net/allisonshing/article/details/104303850
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

bool isPrime(int n){
    // 注意这里从2开始，因为0和1都是素数
    for(int i=2; i*i<=n; i++){
        if(n % i == 0)  return false;
    }
    return true;
}
int main(){
    int mSize, N, M, t;
    cin >> mSize >> N >> M;
    // 重新计算mSize为一个质数
    while(!isPrime(mSize))   mSize++;
    vector<int> v(mSize);
    // 插入n个数字
    for(int i=0; i<N; i++){
        cin >> t;
        bool flag = false;
        for(int j=0; j<mSize; j++){
            int pos = (t + j*j) % mSize;
            if(v[pos] == 0){
                v[pos] = t;
                flag = true;
                break;
            }
        }
        // 遍历完仍没有加进去，就是加不进去了
        if(!flag) cout << t << " cannot be inserted.\n";
    }
    // ans记录查找总次数
    int ans=0;
    for(int i=0; i<M; i++){
        cin >> t;
        // 这里是小于等于，等于号多了一次计数的机会，当查找到结尾还没有找到的时候，再查找一次回到出发地
        // 但是个人觉得这最后一次不太有必要，因为到mSize-1的时候查找完已经遍历完所有的了，所以没必要再多这一次？
        for(int j=0; j<=mSize; j++){
            ans++;
            int pos = (t + j*j) % mSize;
            // 0表示查找失败 t表示查找成功
            if(v[pos] == 0 || v[pos]==t) break;
        }
    }
    cout << fixed << setprecision(1) << ans * 1.0 / M;
    return 0;
}
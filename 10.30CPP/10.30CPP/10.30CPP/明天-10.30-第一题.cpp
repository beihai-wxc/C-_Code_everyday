#include <iostream>

using namespace std;

int main()
{
    long long a[101], b[101];//a[i]:第i个月有多少对虫  b[i]:第i个月出生的卵的数量 

    int x, y, z;
    cin >> x >> y >> z;

    b[0] = 0;  
    /*
    初始化b[0]，防止出错
    当 x = 1 时，主循环从 i = 2 开始：
    a[2] = a[1] + b[0];  这里会用到 b[0]
    */
    for (int i = 1; i <= x; i++)//前x个月只有第一对幼年虫 
    {
        a[i] = 1;   //成虫数量全为1
        b[i] = 0;   //产卵全为0
    }

    //递推求解
    for (int i = x + 1; i <= z + 1; i++)//求第z个月后，即第z+1个月 
    {
        b[i] = a[i - x] * y;          //第 i 个月新产生的卵数 = 第 (i - x) 个月的成虫数 × y
        a[i] = a[i - 1] + b[i - 2];   //第 i 个月末的成虫总数 = 上个月的成虫数 + 两个月前出生的卵现在变成的成虫数
    }

    cout << a[z + 1] << endl;

    return 0;
}
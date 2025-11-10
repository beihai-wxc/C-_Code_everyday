#include<iostream>
#include<limits>
#include<cstring>
#include<cmath>
using namespace std;
long long ob, p;
int b, k, res;
int dfs(long long n) {
    if (n == 0) return 1;
    int res = dfs(n / 2) % k;
    res = (res * res) % k;
    if (n % 2 == 1) res = ((res % k) * (b % k)) % k;
    return res;
}
int main()
{
    cin >> ob >> p >> k;
    b = ob % k;
    res = dfs(p);
    printf("%lld^%lld mod %d=%d", ob, p, k, res);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

const int MOD = 12345;

int main() {
    string n_str;
    cin >> n_str;

    // ��������ַ���ת��Ϊ���� N
    int N = stoi(n_str);

    // dp_even: ��ǰλ���£�����ż���� '3' �����ָ���
    // dp_odd:  ��ǰλ���£����������� '3' �����ָ���
    long long dp_even = 0; // ��ʼ��Ϊ 0
    long long dp_odd = 0;  // ��ʼ��Ϊ 0

    //���ƽ��
    if (N == 1) {
        // һλ����1~9
        // ż���� '3'������ 3 ����� 8 ������ (1,2,4,5,6,7,8,9)
        dp_even = 8;
        dp_odd = 1; // ֻ������ 3
    }
    else {
        // �����һλ
        dp_even = 8; // ��һλ���� 3 (8��ѡ��)
        dp_odd = 1;  // ��һλ�� 3 (1��ѡ��)

        // ����� 2 λ���� N λ
        for (int i = 2; i <= N; ++i) {
            long long new_even = (dp_even * 9 + dp_odd * 1) % MOD;
            long long new_odd = (dp_even * 1 + dp_odd * 9) % MOD;
            dp_even = new_even;
            dp_odd = new_odd;
        }
    }

    cout << dp_even % MOD << endl;

    return 0;
}
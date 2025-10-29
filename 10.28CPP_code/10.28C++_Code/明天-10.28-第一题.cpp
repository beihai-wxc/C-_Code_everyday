#include <iostream>
#include <vector>

using namespace std;

// �ϲ������������������ [left, mid] �� [mid+1, right]��
// ͬʱͳ�ƿ�Խ���������ֵ����������
long long mergeCount(vector<int>& arr, int left, int mid, int right) {
    // ������ʱ���飬���ڴ�źϲ���Ľ��
    vector<int> temp(right - left + 1);

    int i = left;      // �����������ʼ����
    int j = mid + 1;   // �����������ʼ����
    int k = 0;         // ��ʱ���������
    long long count = 0; // ���κϲ����������������������

    // ˫ָ��ϲ�������������
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            // ���Ԫ�ز������ұߣ�����������ԣ�ֱ�ӷ�����ʱ����
            temp[k++] = arr[i++];
        }
        else {
            // arr[i] > arr[j]��˵�� arr[i], arr[i+1], ..., arr[mid] �� > arr[j]
            // ��Ϊ��벿��������ģ����Դ� i �� mid ������Ԫ�ض����� arr[j]
            count += (mid - i + 1);  // ��ЩԪ���� arr[j] ���������
            temp[k++] = arr[j++];
        }
    }

    // ����������ʣ��Ԫ�ؿ����� temp������У�
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // ����������ʣ��Ԫ�ؿ����� temp������У�
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // ���ϲ���Ľ���� temp ���ƻ�ԭ���� arr �Ķ�Ӧλ��
    for (int idx = 0; idx < k; ++idx) {
        arr[left + idx] = temp[idx];
    }

    return count; // ���ر��κϲ����������������
}

// �ݹ���й鲢���򣬲�ͳ�����������е����������
long long mergeSortCount(vector<int>& arr, int left, int right) {
    // �ݹ���ֹ����������Ԫ�ػ�����䣬�����Ϊ 0
    if (left >= right) {
        return 0;
    }

    // �����е㣬��������������ȼ��� (left + right) / 2��
    int mid = left + (right - left) / 2;

    long long count = 0;

    // �ݹ鴦����벿�֣��õ���벿���ڲ������������
    count += mergeSortCount(arr, left, mid);

    // �ݹ鴦���Ұ벿�֣��õ��Ұ벿���ڲ������������
    count += mergeSortCount(arr, mid + 1, right);

    // �ϲ����������֣���ͳ�ƿ�Խ���ҵ����������
    count += mergeCount(arr, left, mid, right);

    return count;
}

int main() {
    // ��������������ر�ͬ������� cin �� cout �İ󶨣�
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ���ù鲢����ͳ�����������
    long long result = mergeSortCount(arr, 0, n - 1);

    // ��������ע�⣺����Կ��ܷǳ��࣬������ long long��
    cout << result << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

// 合并两个已排序的子数组 [left, mid] 和 [mid+1, right]，
// 同时统计跨越左右两部分的逆序对数量
long long mergeCount(vector<int>& arr, int left, int mid, int right) {
    // 创建临时数组，用于存放合并后的结果
    vector<int> temp(right - left + 1);

    int i = left;      // 左子数组的起始索引
    int j = mid + 1;   // 右子数组的起始索引
    int k = 0;         // 临时数组的索引
    long long count = 0; // 本次合并过程中新增的逆序对数量

    // 双指针合并两个有序数组
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            // 左边元素不大于右边，不构成逆序对，直接放入临时数组
            temp[k++] = arr[i++];
        }
        else {
            // arr[i] > arr[j]：说明 arr[i], arr[i+1], ..., arr[mid] 都 > arr[j]
            // 因为左半部分是有序的，所以从 i 到 mid 的所有元素都大于 arr[j]
            count += (mid - i + 1);  // 这些元素与 arr[j] 构成逆序对
            temp[k++] = arr[j++];
        }
    }

    // 将左子数组剩余元素拷贝到 temp（如果有）
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // 将右子数组剩余元素拷贝到 temp（如果有）
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 将合并后的结果从 temp 复制回原数组 arr 的对应位置
    for (int idx = 0; idx < k; ++idx) {
        arr[left + idx] = temp[idx];
    }

    return count; // 返回本次合并产生的逆序对数量
}

// 递归进行归并排序，并统计整个数组中的逆序对总数
long long mergeSortCount(vector<int>& arr, int left, int right) {
    // 递归终止条件：单个元素或空区间，逆序对为 0
    if (left >= right) {
        return 0;
    }

    // 计算中点，避免整数溢出（等价于 (left + right) / 2）
    int mid = left + (right - left) / 2;

    long long count = 0;

    // 递归处理左半部分，得到左半部分内部的逆序对数量
    count += mergeSortCount(arr, left, mid);

    // 递归处理右半部分，得到右半部分内部的逆序对数量
    count += mergeSortCount(arr, mid + 1, right);

    // 合并左右两部分，并统计跨越左右的逆序对数量
    count += mergeCount(arr, left, mid, right);

    return count;
}

int main() {
    // 加速输入输出（关闭同步，解除 cin 与 cout 的绑定）
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 调用归并排序并统计逆序对总数
    long long result = mergeSortCount(arr, 0, n - 1);

    // 输出结果（注意：逆序对可能非常多，必须用 long long）
    cout << result << endl;

    return 0;
}
//
// Created by gongshuang on 2026/6/30.
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== 旧方式：手写函数对象类 =====
struct Greater : public binary_function<int, int, bool> {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main() {
    vector<int> v = {5, 2, 8, 1, 9, 3};

    // 旧方式：传函数对象
    sort(v.begin(), v.end(), Greater());

    for (int x : v) cout << x << " ";  // 9 8 5 3 2 1
    cout << endl;

    // ===== Lambda 替代：直接写 =====
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });

    for (int x : v) cout << x << " ";  // 9 8 5 3 2 1
    cout << endl;

    // Lambda 还能捕获外部变量（旧方式做不到）
    int threshold = 5;
    auto aboveThreshold = [threshold](int x) {
        return x > threshold;
    };

    // 找出大于 threshold 的元素个数
    int count = count_if(v.begin(), v.end(), aboveThreshold);
    cout << "大于 " << threshold << " 的有 " << count << " 个" << endl;

    return 0;
}

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void customSort(vector<int>& arr, int k) {
    auto compare = [](const auto& a, const auto& b) {
        return a.first > b.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);

    for (int i = 0; i < arr.size(); ++i) {
        minHeap.push({arr[i] % k, arr[i]});
    }

    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = minHeap.top().second;
        minHeap.pop();
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    customSort(arr, k);
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

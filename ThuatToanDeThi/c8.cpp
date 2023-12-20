#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm sắp xếp đếm phân phối
void countingSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());

    // Tạo mảng đếm và khởi tạo giá trị bằng 0
    vector<int> count(maxElement + 1, 0);

    // Đếm tần suất xuất hiện của từng phần tử
    for (int num : arr) {
        count[num]++;
    }

    // Cập nhật mảng ban đầu
    int index = 0;
    for (int i = 0; i <= maxElement; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

// Hàm tìm mốt và trung vị của mảng
void findModeAndMedian(const vector<int>& arr) {
    int n = arr.size();

    // Bước 1: Sắp xếp mảng
    vector<int> sortedArr = arr;
    countingSort(sortedArr);

    // Bước 2: Tìm tần suất xuất hiện của từng phần tử
    vector<int> frequencies(n, 0);
    for (int i = 0; i < n; ++i) {
        frequencies[sortedArr[i]]++;
    }

    // Bước 3: Tìm mốt
    int mode = -1;
    int maxFrequency = 0;
    for (int i = 0; i < n; ++i) {
        if (frequencies[sortedArr[i]] > maxFrequency) {
            maxFrequency = frequencies[sortedArr[i]];
            mode = sortedArr[i];
        }
    }

    // Bước 4: Tìm trung vị
    int median;
    if (n % 2 == 1) {
        median = sortedArr[n / 2];
    } else {
        median = (sortedArr[n / 2 - 1] + sortedArr[n / 2]) / 2;
    }

    // In kết quả
    cout << "Mode: " << mode << endl;
    cout << "Median: " << median << endl;
}

int main() {
    vector<int> arr = {1, 4, 1, 2, 7, 1, 2, 5, 3, 6};

    // Tìm mốt và trung vị của mảng
    findModeAndMedian(arr);

    return 0;
}

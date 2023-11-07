#include <iostream>
#include <vector>

std::vector<int> maxCrossingSubarray(const std::vector<int>& arr, int low, int mid, int high) {
    int leftSum = INT_MIN;
    int maxLeft = mid;
    int sum = 0;

    for (int i = mid; i >= low; --i) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = INT_MIN;
    int maxRight = mid + 1;
    sum = 0;

    for (int i = mid + 1; i <= high; ++i) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    std::vector<int> result;
    for (int i = maxLeft; i <= maxRight; ++i) {
        result.push_back(arr[i]);
    }

    return result;
}

std::vector<int> findMaxSubarraySum(const std::vector<int>& arr, int low, int high) {
    if (low == high) {
        std::vector<int> result;
        result.push_back(arr[low]);
        return result;
    }

    int mid = (low + high) / 2;
    std::vector<int> leftSubarray = findMaxSubarraySum(arr, low, mid);
    std::vector<int> rightSubarray = findMaxSubarraySum(arr, mid + 1, high);
    std::vector<int> crossSubarray = maxCrossingSubarray(arr, low, mid, high);

    // Trova quale sottoarray ha la somma massima
    int leftSum = 0;
    for (int num : leftSubarray) {
        leftSum += num;
    }

    int rightSum = 0;
    for (int num : rightSubarray) {
        rightSum += num;
    }

    int crossSum = 0;
    for (int num : crossSubarray) {
        crossSum += num;
    }

    if (leftSum >= rightSum && leftSum >= crossSum) {
        return leftSubarray;
    } else if (rightSum >= leftSum && rightSum >= crossSum) {
        return rightSubarray;
    } else {
        return crossSubarray;
    }
}

int main() {
    std::vector<int> arr = {1, 2, -3, 4, 5, -1};
    std::vector<int> maxSubarray = findMaxSubarraySum(arr, 0, arr.size() - 1);

    std::cout << "Sottoarray con la somma massima: ";
    for (int num : maxSubarray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

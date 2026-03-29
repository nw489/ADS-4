// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int *sorted = new int[len];
    for (int i = 0; i < len; i++) {
        sorted[i] = arr[i];
    }
    
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    
    int count = 0;
    int left = 0;
    int right = len - 1;
    
    while (left < right) {
        int sum = sorted[left] + sorted[right];
        if (sum == value) {
            if (sorted[left] == sorted[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int leftCount = 1, rightCount = 1;
                while (left + 1 < right && sorted[left] == sorted[left + 1]) {
                    leftCount++;
                    left++;
                }
                while (right - 1 > left && sorted[right] == sorted[right - 1]) {
                    rightCount++;
                    right--;
                }
                count += leftCount * rightCount;
                left++;
                right--;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    
    delete[] sorted;
    return count;
}

int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int countPairs3(int *arr, int len, int value) {
    int *sorted = new int[len];
    for (int i = 0; i < len; i++) {
        sorted[i] = arr[i];
    }
    
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    
    int count = 0;
    for (int i = 0; i < len; i++) {
        int target = value - sorted[i];
        int index = binarySearch(sorted, i + 1, len - 1, target);
        if (index != -1) {
            int j = index;
            while (j < len && sorted[j] == target) {
                count++;
                j++;
            }
            j = index - 1;
            while (j > i && sorted[j] == target) {
                count++;
                j--;
            }
        }
    }
    
    delete[] sorted;
    return count;
}

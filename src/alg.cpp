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
    int count = 0;
    int left = 0;
    int right = len - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
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
      int count = 0;
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        if (target < arr[i]) {
            continue;
        }
        int index = binarySearch(arr, i + 1, len - 1, target);
        if (index != -1) {
            int j = index;
            while (j < len && arr[j] == target) {
                count++;
                j++;
            }
            if (target == arr[i]) {
                int sameCount = 0;
                int k = i;
                while (k < len && arr[k] == target) {
                    sameCount++;
                    k++;
                }
                count = sameCount * (sameCount - 1) / 2;
                break;
            }
            i = index;
        }
    }
    return count;
}

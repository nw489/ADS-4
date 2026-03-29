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
            int leftVal = arr[left];
            int rightVal = arr[right];
            int leftCount = 0;
            int rightCount = 0;
            while (left <= right && arr[left] == leftVal) {
                leftCount++;
                left++;
            }
            while (left <= right && arr[right] == rightVal) {
                rightCount++;
                right--;
            }
            if (leftVal == rightVal) {
                count += leftCount * (leftCount - 1) / 2;
            } else {
                count += leftCount * rightCount;
            }
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
        int pos = binarySearch(arr, i + 1, len - 1, target);
        if (pos != -1) {
            int leftPos = pos;
            int rightPos = pos;
            while (leftPos > i && arr[leftPos - 1] == target) {
                leftPos--;
            }
            while (rightPos < len - 1 && arr[rightPos + 1] == target) {
                rightPos++;
            }
            count += (rightPos - leftPos + 1);
            i = rightPos;
        }
    }
    return count;
}

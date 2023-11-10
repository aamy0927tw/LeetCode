#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int* arr, int start, int end) {
    if (start >= end) return;
    int i = start + 1, j = end;
    while (1) {
        while (i < j) {
            if (arr[i] >= arr[start]) break;
            i++;
        }
        while (j > i) {
            if (arr[j] < arr[start]) break;
            j--;
        }
        if (i >= j) break;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[i], &arr[start]);
    sort(arr, start, i - 1);
    sort(arr, i + 1, end);
}

int singleNumber(int* nums, int numsSize) {
    sort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");
    if (nums[0] != nums[1]) return nums[0];
    if (nums[numsSize - 1] != nums[numsSize - 2]) return nums[numsSize - 1];
    int i;
    for (i = 1; i < numsSize - 1; i++) {
        if ((nums[i - 1] != nums[i]) && (nums[i + 1] != nums[i])) break;
    }
    return nums[i];
}

int main (void)
{
    int testCase[] = {1};
    int n = singleNumber(testCase, sizeof(testCase) / sizeof(testCase[0]));
    printf("%d\n", n);

    return 0;
}
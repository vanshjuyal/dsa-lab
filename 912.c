#include <stdio.h>
#include <stdlib.h>

// Helper function to merge two sorted sub-arrays
void merge(int* nums, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = nums[left + i];
    for (j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    // Merge the temporary arrays back into nums[left..right]
    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }

    // Free allocated temporary memory
    free(L);
    free(R);
}

// Main Merge Sort logic
void mergeSort(int* nums, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        // Merge the sorted halves
        merge(nums, left, mid, right);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    // 1. Set the return size to match the input size
    *returnSize = numsSize;
    
    // 2. Allocate dynamic memory for the result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    if (result == NULL) {
        return NULL;
    }
    
    // 3. Copy the original elements into the newly allocated array
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
    }
    
    // 4. Sort the new array
    mergeSort(result, 0, numsSize - 1);
    
    // 5. Return the pointer to the sorted array
    return result;
}

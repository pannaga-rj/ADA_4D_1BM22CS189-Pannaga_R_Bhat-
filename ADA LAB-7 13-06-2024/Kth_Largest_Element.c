#include<string.h>
char res[50];

int compare(const void* a, const void* b) {
    const char* num1 = *(const char**)a;
    const char* num2 = *(const char**)b;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == len2) {
        return strcmp(num2, num1);  // Sort in descending order
    }
    return len2 - len1;  // Longer string is considered larger
} 
char* kthLargestNumber(char** nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(char*), compare);

    // Allocate memory for the result
    char* res = (char*)malloc((strlen(nums[k - 1]) + 1) * sizeof(char));
    if (res == NULL) {
        return NULL; // Memory allocation failed
    }

    // Copy the k-th largest number to the result
    strcpy(res, nums[k - 1]);

    return res;
}

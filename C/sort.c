/**
 * @file sort.c
 * @author fuck your mother
 * @brief 
 * @version 0.1
 * @date 2023-09-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<stdlib.h>

int compare(const void *prt1, const void *ptr2) {
    return *(int*)prt1 - *(int*)ptr2;
}





int main(void) {
    int num1;
    int num2;
    int num3;
    int num4;
    int arr[4];
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    arr[0] = num1;
    arr[1] = num2;
    arr[2] = num3;
    arr[3] = num4;
    qsort(arr, 4, sizeof(int), compare);
    for(int i = 3; i >= 0; i--) {
        printf("%d, ", arr[i]);
    }
}
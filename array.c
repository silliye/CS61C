/**
 * @file array.c
 * @author fuck your mother
 * @brief 
 * @version 0.1
 * @date 2023-10-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<stdlib.h>

void printTriangle(int* array, int length) {
    for(int i = 0; i < length-1; ++i) {
        for(int j = 0; j < i+1; ++j) {
            printf("%d\t", array[i+1] - array[i-j]);
        }
        printf("\n");
    }
}


int main() {
    int num;
    printf("input the length of Array\n");
    scanf("%d", &num);

    int *array;
    array = malloc(sizeof(int) * num);

    int inputNum;
    for(int i = 0; i < num; i ++) {
        scanf("%d", &inputNum);
        array[i] = inputNum;
    }

    printTriangle(array, num);
}


/**
 * @file sum.c
 * @author Liu Guofeng
 * @brief 
 * @version 0.1
 * @date 2023-09-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include<stdio.h>

int sum(int first, int second, int third) {
    return first + second + third;
}

int main() {
    int first = 10;
    int second = 20;
    int third = 30;
    printf("the first = %d\n", first);
    printf("the second = %d\n", second);
    printf("the third = %d\n", third);
    printf("the sum = %d\n", sum(first, second, third));

    return 0;
}
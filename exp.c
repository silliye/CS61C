/**
 * @file exp.c
 * @author GFY
 * @brief 
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>

char *encode_morse(char* s) {
    

    return NULL;
}

int main() {
    double fact = 1.0;
    double exp = 1.0;
    int times; 
    scanf("%d", &times);
    int i = 1;
    for (;i < times; i++) {
        fact *= i;
        exp += (1.0 / fact);
        printf("exp = %lf\n", exp);
        printf("i = %d\n", i);
        printf("fact = %lf\n", fact);


    }
    printf("%.10lf\n", exp);
}
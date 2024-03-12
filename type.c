/**
 * @file type.c
 * @author fuck your mother
 * @brief 
 * @version 0.1
 * @date 2023-09-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <time.h>
#include <stdio.h>
#include<stdlib.h>

const char ESC_KEY = 0x1b ; // ESC key value
int MAX_HIT = 100;
int SIZE = 80;


// char getRandomCh() {
//     srand((unsigned)time(NULL));
//     int value = rand() % SIZE; 
//     return (char) ((SIZE % 26) + 65);
// }


int main() {
    char ch;
    int touchTime = 0;
    int rightTime = 0;
    char random_ch;
    srand((unsigned)time(NULL));
    // random_ch = (char) ((rand() % 26) + 65);
    // printf("You should type : %c\n", random_ch);

    for(int i = 1; i <= 80; ++i) {
        random_ch = (char) ((rand() % 26) + 65);
        printf("%c\t", random_ch);

        if(i % 14 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    while(1) {
        random_ch = (char) ((rand() % 26) + 65);
        printf("You should type : %c\n", random_ch);
        // scanf("%c", &ch);
        ch = getchar();

        while (getchar() != '\n')
            continue;//跳过剩余输入行
        
        if(ch == ESC_KEY || touchTime >= MAX_HIT) {
            break;
        }
        touchTime ++;
        if(ch == random_ch) {
            rightTime ++;
        }
        
    }
    printf("TouchTime = %d\n", touchTime);
    printf("%lf\n", (float) rightTime / (float) touchTime * 100);

 

}
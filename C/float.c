/**
 * @file float.c
 * @author Liu Guofeng
 * @brief 
 * @version 0.1
 * @date 2023-09-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>

int max(float *floats) {
    int max_index = 0;
    for(int i = 1; i < 4; ++i) {
        if(floats[i] > floats[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}
int min(float *floats) {
    int min_index = 0;
    for(int i = 1; i < 4; ++i) {
        if(floats[i] < floats[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

float Average(float floats[]) {
    float sum = 0.0;
    for(int i = 0; i < 4; ++i) {
        sum += floats[i];
    }
    return sum / 4.0;
}

int main() {
    float f1 = 3.5;
    float f2 = 4.5;
    float f3 = 2.5;
    float f4 = -3.5;
    float floats[4];
    floats[0] = f1;
    floats[1] = f2;
    floats[2] = f3;
    floats[3] = f4;
    int max_index = max(floats); 
    int min_index = min(floats);
    float average = Average(floats);
    printf("the max is %lf\n", floats[max_index]);
    printf("the min is %lf\n", floats[min_index]);
    printf("the average is %lf\n", average);

}   
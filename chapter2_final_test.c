/**
 * @file chapter2_final_test.c
 * @author Michael George()
 * @brief 
 * @version 0.1
 * @date 2023-07-16 - 2023-07
 * 
 * @copyright Copyright (c) CS:APP
 * 
 */

#include<stdio.h>
#include"chapter2.h"

/*test2.58*/
int is_little_endian() {
    int x = 0x00000001;
    show_int(x);
    if( *((char*)&x) != 0 ) {
        return 1;
    }
    else 
        return 0;
}

void test_is_little_endian() {
    printf("our endian is little so the result is %d", is_little_endian());
}
/*test2.58*/

/*shift operation*/ 

void shift() {
    int x = 0x01010101;
    printf("--right--\n");
    show_int(x >> 4);
    show_int(x >> 8);
    show_int(x >> 12);
    show_int(x >> 16);

    unsigned int u = 0x11111111;
    printf("--right for unsigned int\n");
    show_int(u >> 4);
    show_int(u >> 8);
    show_int(u >> 12);
    show_int(u >> 16);

    printf("--left--\n");
    show_int(x << 4);
    show_int(x << 8);
    show_int(x << 12);
    show_int(x << 16);




}

/*shift operation*/


/*2.59*/
int mergeX_Y(int x, int y) {
    show_int(x);
    show_int(y);
    int res = y;
    *((char*)(&res)) = *((char*)(&x));
    show_int(res);
}

/*2.59*/

/*test for 2.59*/
void test_merge() {
    int x = 0x12345678;
    int y = 0x76543210;
    mergeX_Y(x, y);

}
/*test for 2.59*/

/*2.60*/
unsigned replace_byte(unsigned x, int i, unsigned char b) {
    unsigned res = x;
    show_unsigned_int(x);
    show_unsigned_char(b);
    *((unsigned char*)&res+i) = b;
    show_unsigned_int(res);
}
/*2.60*/

/*test for 2.60*/
void test_replace_byte() {
    replace_byte(0x12345678, 2, 0xAB);
    replace_byte(0x12345678, 0, 0xAB);
}
/*test for 2.60*/

/*bug code for show_byte*/
void show_byte_with_bug(char* base, size_t len) {
    size_t i;
    for(i = 0; i < len; ++i) {
        printf("%.2x\t", *(base + i));
    }
    printf("\n");
}

void show_int_with_bug(int x) {
    show_byte_with_bug((char*)&x, sizeof(int));
}
// reason : char* should be unsigned char* 
// char* may cause negative such as 0xABCDEFAB, so the first bit is 1, while .2x with negative number may cause ffffffAB ffffffEF ffffffCD ffffffAB

/*bug code for show_byte*/

/*2.61*/
int expression_(int x) {
    int exp = !(~x) || !(x) || !(~(x | 0xFFFFFF00)) || !(~(x | 0x00FFFFFF));
    return exp;
}
/*2.61*/

/*test for 2.61*/
void test_expression1() {
    int x = 0x11223344;
    int y = 0x11111111;
    int res1 = x && y;
    int res2 = x & y;
    printf("%d\n", res1);
    show_byte_with_big_endian((unsigned char*)&res1, sizeof(int));
}

void test_expression2() {
    int r1 = 0xFFFFFFFF;
    int r2 = 0x00000000;
    int r3 = 0xFFAFDF10;
    int r4 = 0xABCDEFFF;

    int r5 = 0xF1642584;

    int e1 = expression_(r1);
    int e2 = expression_(r2);
    int e3 = expression_(r3);
    int e4 = expression_(r4);
    int e5 = expression_(r5);
    
    show_int_with_big_endian(e1);
    show_int_with_big_endian(e2);
    show_int_with_big_endian(e3);
    show_int_with_big_endian(e4);
    show_int_with_big_endian(e5);


}
/*test for 2.61*/

/*2.64*/
int any_odd_one(unsigned x) {
    return !(~(x | 0x55555555));
}
/*2.64*/

/*test for 2.64*/
void test_any_odd_one() {
    unsigned x = 0xAAAAACAA;
    show_int_with_big_endian(x);
    int res = any_odd_one(x);
    show_int_with_big_endian(res);
}
/*test for 2.64*/

/* 2.68
* you should not use == != if for, even recursion
* */
int lower_one_mask(int n) {
    unsigned all_one = 0xFFFFFFFF;
    int res = all_one >> (32 - n);
    show_int_with_big_endian(res);
}
/*2.68*/

/*test for 2.68*/
void test_lower_one_mask() {
    int w = 32;
    for(size_t i = 1; i <= w; ++i) {
        lower_one_mask(i);
    }
}
/*test for 2.68*/

/*2.69*/
//注意 移位符号的优先级, 加法的优先级是比移位符号的优先级大的
unsigned rotate_left(unsigned x, int n) {
    // show_int_with_big_endian(x>>(32-n));
    // show_int_with_big_endian(x<<n);
    unsigned res = (x>>(32-n)) + (x<<n);
    show_int_with_big_endian(res);
    return res;
}
/*2.69*/

/*test for 2.69*/
void test_rotate_left() {
    int w = 32;
    unsigned temp;
    unsigned x = 0x12345678;
    for(size_t i = 0; i < w; i+=4) {
        temp = rotate_left(x, i);
    }
}
/*test for 2.69*/

/*2.*/


int main() {
    printf("%d\n", is_little_endian());
    return 0;

}
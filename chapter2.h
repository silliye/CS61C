#ifndef CHAPTER__H__
#define CHAPTER__H__

#include<stdio.h>
#include<string.h>
#include<limits.h>

typedef struct rec {
    int i;
    int j;
    int a[2];
    int *p;
} rec;


/*test1 : 大端小端测试*/
void show_byte(unsigned char* base, size_t len) {
    size_t i;
    for(i = 0; i < len; ++i) {
        printf("%.2x\t", *(base + i));
    }
    printf("\n");
}

void show_byte_with_big_endian(unsigned char* base, size_t len) {
    int i;
    for(i = len-1; i >= 0; --i) {
        printf("%.2x\t", *(base + i));
    }
    printf("\n");
}

void show_short(short s) {
    show_byte((unsigned char*)&s, sizeof(short));
}

void show_int(int x) {
    show_byte((unsigned char *)&x, sizeof(int));
}

void show_int_with_big_endian(int x) {
    show_byte_with_big_endian((unsigned char*)&x, sizeof(int));
}

void show_struct_with_big_endian(rec r, size_t size) {
    show_byte_with_big_endian((unsigned char*)&r, size);
}

void show_struct(rec r, size_t size) {
    show_byte((unsigned char*)&r, size);
}

void show_unsigned_int(unsigned u) {
    show_byte((unsigned char *)&u, sizeof(unsigned));
}

void show_unsigned_char(unsigned char c) {
    show_byte(&c, sizeof(char));
}

void show_float(float f) {
    show_byte((unsigned char *)&f, sizeof(float));
}

void show_void(void* v) {
    show_byte((unsigned char *)v, sizeof(void*));
}

void show_pointer(void* c) {
    show_byte((unsigned char*)c, sizeof(void*));
}

void show_string(char* s) {
    show_byte((unsigned char*)s, strlen(s));
}



/*test1*/


/*test2*/
void print_max() {
    unsigned int u = 4294967295u;
    printf("%u\n", u);
    printf("%d\n", (int)u);
    int x = -1;
    printf("%u\n", x);
}


void sign_extend() {
    short sx = 0x1234;
    int ix = sx;
    int ixxx = (int)sx;
    printf("ix = %d\tixxx = %d\n", ix, ixxx);
    unsigned short usx = 0x3156;
    unsigned int uix = usx;
    printf("usx = %u\tuix = %u\t\n", usx, uix);

    int x = 0x56781234; 
    short s = x;
    show_short(s);
    
    size_t a = 2;
    size_t b = 4;
    printf("%u\n", a-b);

}

/*test2*/

/*bug*/
float sum_float(float *a, unsigned len) {
    int i;
    float result = 0;
    for (i = 0; i <= len -1; ++i) {
        result += a[i];
    }
    return result;
}



#endif

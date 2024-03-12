/**
 * @file chapter3_final_test.c
 * @author Michael George
 * @brief 
 * @version 0.1
 * @date 2023-07-31
 * 
 * @copyright Copyright (c) CS:APP
 * 
 */

#define N 3

#include<stdio.h>
#include"chapter2.h"
typedef int fix_matrix[N][N];
void print_square_matrix(fix_matrix A, int size);


/*3.40 imul of matrix*/
int fix_pred_ele_matrix(fix_matrix A, fix_matrix B, long i, long k) {
    i--;
    k--;
    int *Aptr = &A[i][0];
    int *Bptr = &B[0][k];
    int *Bend = &B[N][k];

    long result = 0;
    while(Bptr != Bend) {
        result += (*Aptr) * (*Bptr);
        Aptr ++;
        Bptr += N; 
    }
    return result;
}

void fix_set_diag_opt(fix_matrix A, int val) {
    int *start = &A[0][0];
    int *end = &A[N][N];
    while(start != end) {
        *start = val;
        printf("hello\n");
        start += sizeof(int)*(N+1);
    }
    return;
}
/*3.40*/

/*test for 3.40*/
void test_340() {
    fix_matrix A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    fix_matrix B = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    print_square_matrix(A, N);
    print_square_matrix(B, N);
    fix_set_diag_opt(A, 100);
    fix_set_diag_opt(B, 100);
    print_square_matrix(A, N);
    print_square_matrix(B, N);

}

void print_square_matrix(fix_matrix A, int size) {
    for(size_t i = 0; i < size; ++i) {
        for(size_t j = 0; j < size; ++j) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}
/*test for 3.40*/


/*test for struct*/
void test_struct() {
    rec r;
    int number = 111;
    r.a[0] = 10;
    r.a[1] = 10;
    r.i = r.j = 0x01010101;
    r.p = &number;
    rec* sr = &r;
    sr->a[10] = 100000;
    sr->p = &(sr->a[10]);
    show_struct_with_big_endian(r, sizeof(rec));
    printf("\n%d\n", *(sr->p));

}
/*test for struct*/


int main(){

    test_struct();
    return 0;

}
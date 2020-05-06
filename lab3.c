#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
        short N=10, rez=0;//n<655
        unsigned char i, j;
        short mas[N][N];
        long long *ptr_st = &mas[0][0];
        long long *ptr_end = &mas[0][N-1];

        srand(time(NULL));
        for(i=0;i<N;i++)
                for(j=0;j<N;j++)
                                mas[i][j]=rand()%101-50;

        for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                        printf("%3d ", mas[i][j]);
                }
                printf("\n");
        }
        asm volatile (
                        "xorq %%rcx, %%rcx\n\t"
                        "movw %[n], %%cx\n\t"
                        "decb %%cl\n\t"
                        "movq %%rcx, %%rbx\n\t"
                        "shlw $1, %%bx\n\t"
                        "movq %%rbx, %%rax\n\t"
                        "addb $4, %%al\n\t"
                        "movq %[ptr1], %%r8\n\t"
                        "movw (%%r8), %[Rez]\n\t"
                        "movq %[ptr2], %%r9\n\t"
                        "addw (%%r9), %[Rez]\n\t"
                        "1:\n\t"
                        "addq %%rax, %%r8\n\t"
                        "addq %%rbx, %%r9\n\t"
                        "addw (%%r8), %[Rez]\n\t"
                        "addw (%%r9), %[Rez]\n\t"
                        "loop 1b\n\t"
                        :[Rez]"=r"(rez)
                        :[n]"m"(N), [ptr1]"m"(ptr_st), [ptr2]"m"(ptr_end)
                        :"rcx", "rbx", "rax", "r8", "r9", "cc", "memory"
                        );
        printf("%d\n", rez);
        return 0;
}

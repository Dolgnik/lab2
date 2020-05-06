#include <stdio.h>
#include <stdlib.h>

int main()
{
	int8_t a = 107;
        u_int8_t count = 0;
        int arr[10] = {132, -20, -3, 10, 210, 56, 73, 107, 115, 128};

        for(int i=0; i<10; i++){
                arr[i] |= a;
                if (arr[i] > 128){
                        count++;
                }
	}
        printf("%hhu\n", count);
	return 0;
}

#include <stdlib.h>
#include <stdio.h>

int main(){
    int r=5, c=7;
    int *ptr, **arr;
    
    arr = (int **)malloc(sizeof(int *) * r + sizeof(int) * c * r);
 
    // ptr is now pointing to the first element in of 2D array
    ptr = (int *)(arr + r);
 
    // for loop to point rows pointer to appropriate location in 2D array
    for(int i = 0; i < r; i++){
        arr[i] = (ptr + c * i);
    }
 
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            arr[i][j] = i+j;
        }
    }//for
    //we can now print all the addresses and see that they are in order together    
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("%d %p ", arr[i][j], &arr[i][j]);
        }
        printf("\n");
    }
    free(arr);
    return 0;
}//main

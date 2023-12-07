#include "minFunc.h"

const int * min(const int arr[], int arrSize) {
    if(arrSize == 0){
        return nullptr;
    }
    if(arrSize <= 1){
        return &arr[0];
    }
    else{
        const int *min2 = min(arr, arrSize - 1); //goes from the end of the list
        if(*min2 > arr[arrSize - 1]){
            return &arr[arrSize - 1];
        }
        else{
            return min2;
        }
    }
}
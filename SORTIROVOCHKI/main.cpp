//
//  main.cpp
//  SORTIROVOCHKI
//
//  Created by Константин on 23.09.16.
//  Copyright © 2016 Константин. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "LinearSort.h"

int max_element(int* arr, int n){
    int max = arr[0];
    
    for(int i = 0 ; i < n; i++){
        if (arr[i]>max) {
            max = arr[i];
        }
    }
    
    return max;
}

int min_element(int* arr, int n){
    
    int min = arr[0];
    
    for(int i = 0 ; i < n; i++){
        if (arr[i]<min) {
            min = arr[i];
        }
    }
    
    return min;
}

void copy_array(int *from, int *to, int size){
    for (int i = 0; i < size; i++) {
        to[i] = from[i];
    }
}

void counting_sort(int* arr, int n){
    int max = max_element(arr, n);
    int min = min_element(arr, n);
    
    int sizeOfCountAr = max - min +1;
    
    int* count = new int[sizeOfCountAr];
    
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    
    for (int i = 0; i < n; i++) {
        count[i] += count[i-1];
    }
    
    int* amazingNewArray = new int[n];
    
    for (int i = n - 1; i >= 0; i--) {
        count[arr[i] - min]--;
        amazingNewArray[count[arr[i] - min]] = arr[i];
    }
    
    copy_array(amazingNewArray, arr, n);
    delete [] amazingNewArray;
    delete [] count;
}

void radix_sort(int *arr, int n, int base){
    
    int maxIndex = get_max_digit_index(arr, n, base);
    for (int i = 0; i < maxIndex; ++i)
        sort_at_digit(arr, n, base, i);
    
}

void sort_at_digit(int *arr, int n, int base, int digit_index){
    
    int* buferArray = new int[base];
    int* newArr = new int[n];
    
    for (int i = 0; i < base; i++) {
        buferArray[i] = 0;
    }
    
    for(int i = 0; i < n; i ++){
        buferArray[get_digit(arr[i], base, digit_index)] += 1;
    }
    
    for (int i = n - 1; i >= 0; --i)
    {
        int digit = get_digit(arr[i], base, digit_index);
        buferArray[digit]--;
        newArr[buferArray[digit]] = arr[i];
    }
    
    copy_array(newArr, arr, n);
    
    delete[] buferArray;
    delete[] newArr;
    
}

int get_digit(int number, int base, int digit_index){
    int digit = (number / (int) pow(base, digit_index)) % base;
    return digit;
}



int main(int argc, const char * argv[]) {

    
    int foo [5] = { 4, 2, 3, 4, 1 };
    
    int* to = new int[5];
    
    int a =  max_element(foo, 5);
    
    int b = min_element(foo, 5);
    
    counting_sort(foo, 5);
    
    std::cout<<a<<" "<<b<<"\n";
    
    
    return 0;
}

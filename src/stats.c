/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Hongjian Zhu>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)



void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  char *charPtr = test;
  int Size = SIZE;
  print_array(charPtr,Size);
  print_statistics(charPtr,Size);
}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char* charPtr, int size){
  
  //float median = 10;
  unsigned char* sortedArray = sort_array(charPtr, 40);
  float median = find_median(sortedArray,size);
  unsigned char max = find_maximum(sortedArray,size);
  unsigned char min = find_minimum(sortedArray);
  float mean = find_mean(charPtr, size);

  printf("\nStatistics of the given array\n");
  printf("The median is %.2f\n", median);
  printf("The mean is %.2f\n", mean);
  printf("The Max is %d\n",max);
  printf("The Min is %d\n",min);
  

}
unsigned char find_maximum(unsigned char *sortedArray, int size){
  if(size == 0){
    printf("No input");
    return 0;
  }
  return sortedArray[size-1];
}
unsigned char find_minimum(unsigned char *sortedArray){
  return sortedArray[0];
}

float find_median(unsigned char* charPtr, int size){
  if(size == 0){
    printf("No Inputs");
    return 0;
  }
  if(size%2 == 0){
    //even length
    float median = (charPtr[(size/2)-1] + charPtr[(size/2)]) / 2.0;
    return median;
  }
  else{
    return charPtr[size/2];
  }
}

float find_mean(unsigned char* charPtr, int size){
  float sum = 0;

  for(int ix = 0; ix<size; ix++){
    sum += charPtr[ix];
  }
  return sum/size;
}

unsigned char* sort_array(unsigned char*charPtr, int size){
  for(int ix = 0; ix<size-1; ix++){
    for (int j = 0; j<size-ix-1; j++){
      if(charPtr[j]>charPtr[j+1]){
        unsigned char temp = charPtr[j];
        charPtr[j] = charPtr[j+1];
        charPtr[j+1] = temp;
      }
    }
  }
  return charPtr;
}

void print_array(unsigned char* charPtr, int size){
  printf("\nHere is the given array: \n");
  for(int ix = 0; ix<size; ix++){
    printf("%d ",charPtr[ix]);
  }
  printf("\n");
}

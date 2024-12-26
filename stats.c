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
//File Name : Lodha_Coursera
 * @brief <Add Brief Description Here >
//Analytics on Array
 *
 * <Add Extended Description Here>
//This code can analyse an array of unsigned char data items and report(print) analytics on the maximum, minimum, mean, and median of the data set. Additionally, it can sort the data set in descending order. 
 *
 * @author <Add FirstName LastName>
//Author name : Gunjan Lodha
 * @date <Add date >
//Date : 26/12/2024
 *
 */



#include <stdio.h>
#include "stats.h"
#include <limits.h>
#include <math.h>

/* Size of the Data Set */
#define SIZE (40)

void sort_array(unsigned char*arr, int n)
{
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(arr[j]<arr[j+1])
{
unsigned char temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}//end of sort_array



void print_array(unsigned char *arr, int n)
{
printf("Sorted Array:\n");
for(int i=0;i<n;i++)
{
printf("%hhu ",arr[i]);
}
printf("\n");
}//end of print_array



double find_mean(unsigned char *arr, int n)
{
double sum=0;
for(int i=0;i<n;i++)
{
sum+=(double)arr[i];
}
sum/=(double)n;//93.975
return sum;
}//end of find_mean


char find_maximum(unsigned char *arr, int n)
{
unsigned char max=0;
for(int i=0;i<n;i++)
{
if(arr[i]>=max)
max=arr[i];
}
return max;
}//end of find_maximum



char find_minimum(unsigned char *arr, int n)
{
unsigned char min=CHAR_MAX;
for(int i=0;i<n;i++)
{
if(arr[i]<=min)
min=arr[i];
}
return min;
}//end of find_minimum


double find_median(unsigned char *arr, int n)
{
double median;
if(n%2==0)
median=((double)arr[(n/2)-1]+(double)arr[n/2])/2;
else
median=(double)arr[(n/2)+1];
return median;
}//end of find_median

void print_statistics(unsigned char*arr, int n)
{
unsigned char mini,maxi;
double mean,med;
mini=find_minimum(arr,n);
maxi=find_maximum(arr,n);
med=find_median(arr,n);
mean=find_mean(arr,n);
printf("Minimum : %hhu\n",mini);
printf("Maximum : %hhu\n",maxi);
printf("Mean : %0.4f\n",mean);
printf("Median : %0.2f",med);
}//end of print_statistics


void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
unsigned char* ptr=&test[0];
  /* Statistics and Printing Functions Go Here */
sort_array(ptr,SIZE);
print_array(ptr,SIZE);
print_statistics(ptr,SIZE);
}

/* Add other Implementation File Code Here */

/*Name: Shreeju Magaju 
Class: CSCE 1040.002
Instructor: Rubenia Borge Flores 
HOMEWORK 1
Description: Working with data structures to process garde data */


// DOCUMENTATION GOES HERE
#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"
#include <iomanip>
#include <cmath>
#include <string.h>


struct classStats{
    float mean;
    float min;
    float max;
    float median;
    char* name;
};


int main()
{
  // ENTER YOUR CODE HERE
  
  classStats classData;

  FILE *readFile;

  readFile = fopen ("grades", "r");

  if(readFile == NULL){
    printf("Error File");
  return 1;
  }
    
  struct student_info *studentList[19];
    
  classData.name= (char *)malloc(sizeof(char) * 20);
  
  fscanf(readFile, "%s", classData.name); //take out the first line from Grades
  
  for(int i=0; i<19; i++){
  
    studentList[i]= (struct student_info*)malloc(sizeof(struct student_info));
   studentList[i]->first= (char*)malloc(sizeof(char)*20);
    studentList[i]->last= (char*)malloc(sizeof(char)*20);
    
    fscanf(readFile, "%s%s%d%d%d", studentList[i]-> first, studentList[i]->last, &studentList[i]->exam1, &studentList[i]->exam2, &studentList[i]->exam3);
    studentList[i]->mean = (studentList[i]->exam1 + studentList[i]->exam2 + studentList[i]->exam3)/3.0;
}

bubble(studentList,19);

for(int i=1; i < 10; i++){
    printf("%d",i);
}

for (int j= 0; j < 5; j++){
    for (int i = 0; i < 10; i++){
        printf("%d",i);
    }
}

printf("%d", 0);

printf("\n");

float sum = 0;

 for (int i = 0; i < 19; i++){
 sum += studentList[i]->mean;
 }
 
 classData.mean = sum / 19;
 
 classData.min = studentList[0]->mean;
 classData.max = studentList[18]->mean;
 classData.median = studentList[19/2]->mean;

printf("CSCE1040 MEAN: %.2f MIN:  %.2f  MAX: %.2f  MEDIAN: %.2f\n", classData.mean, classData.min, classData.max, classData.median); 
 
 for (int i =0; i < 19; i++){
     printf("%12s %12s                    %.2f\n", studentList[i]->first, studentList[i]->last, studentList[i]->mean);
 }

  fclose(readFile);
  return 0;
}

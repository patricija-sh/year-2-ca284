// Includes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: outstanding-students.c
Functions: main,  addStudent, printAboveAverage, findAverage
Parameters: multiple str name, str programme, float grade.
Returns: int
Description: Reads in multiple student parameters and outputs the average grade along with the student with above average grades.
Author: Patricija Shalkauskaite
*/

//Defining Student as a type name.
typedef struct Student Student;

//Structure type definition.
struct Student 
{
    char name[20];
    char programme[20];
    float grade;
};

// Initialising functins.
void addStudent(Student *student, char *name, char *programme, float grade);
float findAverage(Student *student, int student_count);
void printAboveAverage(Student *student, float average);

int main(int argc, char *argv[])
{   // Start main function.

    // Defining variables
    Student *p_students;
    int start_capacity = 2;
    p_students = (Student*)malloc(start_capacity * sizeof(Student)); // Inital memory allocation for p_students.
    int student_count = (argc - 1) / 3; // Count of students.
    int array_count = 0; // Tracking the count of students in the array

    if(!p_students)
    {
        printf("Not enough memory.\n");
        free(p_students);
        p_students = NULL;
        exit(0);
    }

    if(student_count > 2) // Checking to see if there are more than 2 students inputted.
    {
        p_students = (Student*)realloc(p_students, student_count*sizeof(Student)); // Reallocating memory for the student number.
    }

    for(int i = 1; i < student_count * 3; i += 3) // Adding the students in array to struct. 
    {
        addStudent(&p_students[array_count], argv[i], argv[i + 1], atof(argv[i + 2]));
        array_count++;
    }
    
    float average = findAverage(p_students, array_count);

    for(int j = 0; j < array_count; j++) // Prints the student(s) who scored above average.
    {
        printAboveAverage(&p_students[j], average);
    }

    printf("Average grade: %.2f\n", average);

    free(p_students); // p_students is freed up as we're done with it.

    return(0);
}
void addStudent(Student *student, char *name, char *programme, float grade) // Add each student to struct.
{
    strcpy(student->name, name);
    strcpy(student->programme, programme);
    student->grade = grade;
}

float findAverage(Student *student, int student_count) // Finding average of grades inputted.
{
    float sum = 0;
    float average = 0;

    for(int j = 0; j < student_count; j++) // Getting grades' sum.
    {
        sum += student[j].grade;
    }

    average = sum / student_count;
    return average;
}

void printAboveAverage(Student *student, float average)
{
    if(student->grade > average && strcmp(student->programme, "CSCE") == 0) // If their grade is higher than the average and the student is in CSCE.
    {
        printf("%s, %.2f\n", student->name, student->grade);
    }
}

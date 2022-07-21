// Import libraries.
#include <stdio.h>
#include <stdlib.h>

/*
Name: load-binary.c
Functions: main, read_binary_files
Parameters: None.
Returns: Student
Description: Reads from a binary file and puts input into Student struct and prints the student out.
Author: Patricija Shalkauskaite
Date: 20-11-2021
*/

typedef struct Student Student;

struct Student{
    char name[50];
    char college[40];
    int age;
    float grade;
};

void read_binary_file(Student *student, FILE *pfile);
void show_student(Student *student);

int main(int argc, char *argv[])
{
    Student student;
    Student *pstudent = &student;  // Pointer points to the type Student student initialised.
    FILE *pfile;  // File pointer.
    char *filename = "studentBinary.bin";


    pfile = fopen(filename, "rb");  // Open a file with binary mode.
    if(!pfile)  // Check if open operation worked correctly.
    {
        printf("Error opening file. Program terminated.");
        exit(1);
    }

    read_binary_file(pstudent, pfile);
    fclose(pfile); // Close the file.

    show_student(pstudent);

    return(0);
}

void read_binary_file(Student *student, FILE *pfile)
{
    // Defining variables.
    int name_size = 0;
    int *pname_size = &name_size;
    int college_size = 0;
    int *pcollege_size = &college_size;

    //Read the data from binary file.
    fread(pname_size, sizeof(int), 1, pfile);  // unsigned int fread(void * pdata, unsigned int size, unsigned int nitems, FILE * pfile);
    fread(student->name, sizeof(char), name_size, pfile);
    
    fread(pcollege_size, sizeof(int), 1, pfile);
    fread(student->college, sizeof(char), college_size, pfile);
    
    fread(&student->age, sizeof(int), 1, pfile); // We only put & in front of ints/ floats in this case, e.g. student->name is already an array/pointer.
    fread(&student->grade, sizeof(float), 1, pfile);
}

void show_student(Student *student)
{
    printf("Name: %s\n", student->name);
    printf("College: %s\n", student->college);
    printf("Age: %d\n", student->age);
    printf("Grade: %.2f\n", student->grade);
}
// Import libraries.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: ex4-attendance.c
Functions: main, check_absence, check_lateness, check_attendance_status.
Parameters: char array of strings representing students' records (char *argv[]).
Returns: int
Description: The code takes in an array of strings representing students' attendance records and outputs 0 or 1 depending on 
             whether they're absent 3 or more times, or late three times in a row.
Author: Patricija Shalkauskaite
Date: 09-12-2021
*/

// Function prototypes.
int check_absence(char *student, int record_length);  // Count the number of 'A's (absent) in student's record.
int check_lateness(char *student, int record_length);  // Count the record of 'L's (late) in student's record.
int check_attendance_status(int absence_count, int is_late);  // Modify or keep current attendance status of student.

int main(int argc, char *argv[])
{   // Start of main function.
    
    // Defining variables.
    int student_length = argc - 1;  // It's - 1 so program name isn't counted.
    char *students[student_length];  // Pointer to characters (records of student's presence).
    int absence_count;
    int is_late;

    for(int i = 0; i < student_length; ++i)  // Creating array of students' presences.
    {
        students[i] = argv[i + 1];
    }

    for(int i = 0; i < student_length; ++i)  // Iterate through each student and call absence and lateness functions.
    {
        absence_count = check_absence(students[i], strlen(students[i]));
        is_late = check_lateness(students[i], strlen(students[i]));
        printf("%d\n", check_attendance_status(absence_count, is_late));
    }

    return 0;
}   // End of main function.


/*
    Function Name: check_absence
    Parameters: one student's attendance records (char *student) and their record length (int record_length).
    Description: For each student, count the amount of absences in their record and return it.
*/

int check_absence(char *student, int record_length)
{
    // Defining variables.
    int absence_count = 0;

    for(int i = 0; i < record_length; ++i)  // Iterate through the student's presence record.
    {
        if(student[i] == 'A')  // Check if student has been absent and increment count if so.
        {
            absence_count += 1;
        }
    }

    return absence_count;
}

/*
    Function Name: check_lateness
    Parameters: One student (char *student) and their record length (int record_length).
    Description: Function checks for 3 late records in a row in their attendance records and returns 1 if such is the case, else it returns 0.
*/

int check_lateness(char *student, int record_length)
{
    // Defining variables.
    int is_late = 0;

    for(int i = 0; i < record_length; ++i)  // Iterate through the student's presence record.
    {
        if((student[i] == 'L') && (student[i + 1] == 'L') && (student[i + 2] == 'L'))  // If student is late three times in a row.
        {
            is_late = 1;
        }
    }

    return is_late;
}

/*
    Function Name: check_attendance_status
    Parameters: Student's absence count (int absence_count) and whether they're late three times in a row (int is_late).
    Description: Function checks if the student's absence count 
*/

int check_attendance_status(int absence_count, int is_late)
{
    if(absence_count >= 3)  // If student is late three or more times.
    {
        return 1;
    }

    else if(is_late == 1)  // Or if student is late three times in a row.
    {
        return 1;
    }
    else  // Student has good attendance.
    {
        return 0;
    }
}
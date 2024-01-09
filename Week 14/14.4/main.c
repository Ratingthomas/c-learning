#include <stdio.h>
#include "functions.h"
#include "string.h"

typedef enum { INSUFFICIENT, SUFFICIENT, GOOD, OUTSTANDING } result_t;

typedef struct {
    char name[100];
    result_t grade;
} student_t;

/// Uses the console to read a student from the user.
/// @param prompt The prompt to display to the user.
/// @return The student entered by the user.
student_t read_student(const char *prompt){
    student_t student;

    char * input[100];
    strncpy(student.name, read_string(prompt), 100);

    return student;
}

/// Returns the text representation of a grade.
/// @param grade The grade to convert to text.
/// @return The text representation of the grade.
const char *grade_to_text(result_t grade){
    if(grade == INSUFFICIENT){
        return "INSUFFICIENT";
    }
    else if(grade == SUFFICIENT){
        return "SUFFICIENT";
    }
    else if(grade == GOOD){
        return "GOOD";
    }
    else if(grade == OUTSTANDING){
        return "OUTSTANDING";
    }
}

/// Prints a student (name and grade) to the console.
/// The grade is printed in text form as "insufficient", "sufficient", "good", or "outstanding".
/// @param student The student to print.
void print_student(const student_t *student){

    printf("%s: %s \n", student->name, grade_to_text(student->grade));
}

/// Counts the number of students that have a certain grade.
/// @param students The array of students.
/// @param count The number of students in the array.
/// @param grade The grade students must have to be included in the count.
/// @return The number of students that have the specified grade.
int count_students_with_grade(const student_t students[static 1], int count, result_t grade);

int main() {
    student_t students[20];

    bool loop = true;

    for (int i = 0; i < 20; ++i) {
        students[i] = read_student("Enter student name: ");

        if(strcmp(students[i].name, "") == 0){
            i = 20;
        } else{
            char grade = read_char("Please enter grade");
            if(grade == 'i'){
                result_t grade_result = INSUFFICIENT;
                students[i].grade = grade_result;
            }
            else if(grade == 's'){
                result_t grade_result = SUFFICIENT;
                students[i].grade = grade_result;
            }
            else if(grade == 'g'){
                result_t grade_result = GOOD;
                students[i].grade = grade_result;
            }
            else if(grade == 'o'){
                result_t grade_result = OUTSTANDING;
                students[i].grade = grade_result;
            }
        }
    }

    printf("Grades:\n");
    for (int i = 0; i < 20; ++i) {
        if(strcmp(students[i].name, "") != 0){
            print_student(&students[i]);
        }
    }


    return 0;
}

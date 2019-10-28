/*
 * This program contains seven parts:
 * (a) Define a structure name, which contains two members: first name and last name.
 * (b) Define a structure student, which contains struct name, an array of three grades
 *     and an average of three grades.
 * (c) Declare CSIZE = 4 and a student array[CSIZE].
 * (d) Let the user input the informations of four students.
 * (e) Calculate the average grade of each student, and assign the result to main().
 * (f) Print the informations of each student.
 * (g) Print the average grade of a specific student.
 */
#include <stdio.h>
#include <string.h>
#define NAMESIZE 10
#define GRADES 3
/* (a) */
struct name {
    char first_name[NAMESIZE];
    char last_name[NAMESIZE];
};

/* (b) */
struct student {
    struct name name;
    double grade[GRADES];
    double average;
};

/* (d) */
struct student getStudentInfo();

/* (e) */
double calcAverage(const struct student s);

/* (f) */
void printInfo(const struct student s);

/* (g) */
void printAverage(const struct student s);

char * s_gets(char * str, int n);

int main(void)
{
    /* (c) */
    int CSIZE = 4;
    struct student students[CSIZE];

    /* (d) */
    printf("Please enter the informations of four students.\n");
    for (int i = 0; i < CSIZE; i++)
    {
        printf("Number %d:\n", i + 1);
        students[i] = getStudentInfo();
    }

    /* (e) */
    printf("\nCalculate the average grade of each student.\n");
    for (int i = 0; i < CSIZE; i++)
        students[i].average = calcAverage(students[i]);
    printf("Calculate done!!!\n");

    /* (f) */
    printf("\nPrint the informations of each student:\n");
    for (int i = 0; i < CSIZE; i++)
        printInfo(students[i]);

    /* (g) */
    printf("Print the average grade of each student:\n");
    for (int i = 0; i < CSIZE; i++)
        printAverage(students[i]);

    return 0;
}

struct student getStudentInfo()
{
    struct student temp;

    printf("Enter the first name: ");
    s_gets(temp.name.first_name, NAMESIZE);
    printf("Enter the last name: ");
    s_gets(temp.name.last_name, NAMESIZE);
    printf("Enter three grades: ");
    for (int i = 0; i < GRADES; i++)
        scanf("%lf", &(temp.grade[i]));

    while (getchar() != '\n')
        continue;

    return temp;
}

double calcAverage(const struct student s)
{
    double total = 0;

    for (int i = 0; i < GRADES; i++)
        total += s.grade[i];

    return (total / GRADES);
}

void printInfo(const struct student s)
{
    printf("Name: %s %s\n", s.name.first_name, s.name.last_name);
    printf("Grades:");
    for (int i = 0; i < GRADES; i++)
        printf(" %.2lf", s.grade[i]);
    printf("\nAverage: %.2lf\n\n", s.average);
}

/* (g) */
void printAverage(struct student s)
{
    printf("The average grade of %s %s: %.2lf\n", s.name.first_name, s.name.last_name, s.average);
}

char * s_gets(char * str, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

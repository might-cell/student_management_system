#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// CONSTANT DEFINITION
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// define the maximum number of student is 1000
#define MAX 1000

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// STRUCTION DEFINITION
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// encapsulate the structure of student
// students' information include name, gender, age, C score, linear Algebra score and calculus score
typedef struct student
{
    char m_Name[10];              /* student name */
    int m_Gender;                 /* student gender */
    int m_Age;                    /* student age */
    float m_C_Score;              /* C score */
    float m_Linear_Algebra_Score; /* linear Algebra score */
    float m_Calculus_Score;       /* calculus score */
} stu;

// encapsulate the structure of system
typedef struct management_System
{
    // student array
    struct student student_Array[MAX];
    // student number at present
    int m_Student_Number;
} manager;

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// FUNCTION DEFINITION
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// encapsulate the function to display the operation interface
void showMenu(void)
{
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=   1.Add Student       -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   2.Display Student   -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   3.Delete Student    -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   4.Search Student    -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   5.Modify Student    -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   6.Wipe Student      -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   7.Clear Screen      -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   0.Exit System       -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

// 1.Add Student
void add_Student(manager *core)
{
    // check whether the system is full
    if (core->m_Student_Number == MAX)
    {
        printf("This mangement system is full, you cannot add any student!\n");
    }
    else
    {
        // add student name
        char name[30];
        printf("Please input student's name: ");
        scanf("%s", name);
        strcpy(core->student_Array[core->m_Student_Number].m_Name, name);

        // add student gender: 1 -> man, 0 -> woman
        printf("Please input stdeunt's gender: ");
        int gender = 0;
        while (1)
        {
            // if enter 1 or 0, you can break the loop
            // else the gender is worry, you will try again
            scanf("%d", &gender);
            if (gender == 1 || gender == 0)
            {
                core->student_Array[core->m_Student_Number].m_Gender = gender;
                break;
            }
            printf("The gender you input is worry, please input again: ");
        }

        // add student age
        printf("Please input student's age: ");
        int age = 0;
        while (1)
        {
            // if the age is in (0, 100), you can break the loop
            // else the age is worry, you will try again
            scanf("%d", &gender);
            if (gender > 0 && gender < 100)
            {
                core->student_Array[core->m_Student_Number].m_Age = age;
                break;
            }
            printf("The age you input is worry, please input again: ");
        }

        // add student C score
        printf("Please input student's C program lecture score: ");
        float c_Score = 0;
        while (1)
        {
            // if the score is in [0, 100], you can break the loop
            // else the score is worry, you will try again
            scanf("%f", &c_Score);
            if (c_Score >= 0 && c_Score <= 100)
            {
                core->student_Array[core->m_Student_Number].m_C_Score = c_Score;
                break;
            }
            printf("The C program lecture score you input is worry, please input again: ");
        }

        // add student Linear Algebra score
        printf("Please input student's Linear Algebra lecture score: ");
        float linear_Algebra_Score = 0;
        while (1)
        {
            // if the score is in [0, 100], you can break the loop
            // else the score is worry, you will try again
            scanf("%f", &linear_Algebra_Score);
            if (linear_Algebra_Score >= 0 && linear_Algebra_Score <= 100)
            {
                core->student_Array[core->m_Student_Number].m_Linear_Algebra_Score = linear_Algebra_Score;
                break;
            }
            printf("The Linear Algebra lecture score you input is worry, please input again: ");
        }

        // add student calculus score
        printf("Please input student's Calculus lecture score: ");
        float calculus_Score = 0;
        while (1)
        {
            // if the score is in [0, 100], you can break the loop
            // else the score is worry, you will try again
            scanf("%f", &calculus_Score);
            if (calculus_Score >= 0 && calculus_Score <= 100)
            {
                core->student_Array[core->m_Student_Number].m_Linear_Algebra_Score = calculus_Score;
                break;
            }
            printf("The Calculus lecture score you input is worry, please input again: ");
        }
    }
}

int main(void)
{
    int select = 0;

    // create a management system structure
    manager core;

    // initialize the current number of student in this core
    core.m_Student_Number = 0;

    // encapsulate the loop to finish the selection
    while (1)
    {
        // invoke the function to show the operation interface
        showMenu();

        printf("Please enter your selection: ");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            // use address transfer
            add_Student(&core);
            break;
        case 2:
            // 2.Display Student
            break;
        case 3:
            // 3.Delete Student
            break;
        case 4:
            // 4.Search Student
            break;
        case 5:
            // 5.Modify Student
            break;
        case 6:
            // 6.Wipe Student
            break;
        case 7:
            // 7.Clear Screen
            system("cls");
            break;
        case 0:
            // 0.Exit System
            printf("Welcom to use the system next time!\n");
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }
}
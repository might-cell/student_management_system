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
    printf("-=-=-=-=-=-=-=   1.Add     Student   -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   2.Display Student   -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   3.Delete  Student   -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   4.Search  Student   -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   5.Modify  Student   -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   6.Wipe    Student   -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   7.Clear   Screen    -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=   0.Exit    System    -=-=-=-=-=-=-=\n");
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
        printf("1 - Man\t0 - Woman\n");
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
            scanf("%d", &age);
            if (age > 0 && age < 100)
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
                core->student_Array[core->m_Student_Number].m_Calculus_Score = calculus_Score;
                break;
            }
            printf("The Calculus lecture score you input is worry, please input again: ");
        }

        // update the number of student in the mangement system
        core->m_Student_Number++;

        system("pause");
    }
}

// 2.Dispplay Student
void show_Student(manager *core)
{
    // if check whether the number of the management system is 0, disp 0
    // else disp the information of the student
    if (core->m_Student_Number == 0)
    {
        printf("The current record is empty!\n");
    }
    else
    {
        for (int i = 0; i < core->m_Student_Number; i++)
        {
            printf("Name:%s\t\t", core->student_Array[i].m_Name);
            printf("Gender:%s\t\t", core->student_Array[i].m_Gender == 1 ? "Man" : "Woman");
            printf("Age:%d\t\t", core->student_Array[i].m_Age);
            printf("C Program:%.1f\t\t", core->student_Array[i].m_C_Score);
            printf("Linear Algebra:%.1f\t\t", core->student_Array[i].m_Linear_Algebra_Score);
            printf("Calculus:%.1f\n", core->student_Array[i].m_Calculus_Score);
        }
    }

    system("pause");
}

// encapsulate a function to check whether a student is in the mangement system
// if exsit, return the index of the student in the management system
// else, return -1
int check_Student_Exist(manager *core, char name[])
{
    for (int i = 0; i < core->m_Student_Number; i++)
    {
        if (!strcmp(core->student_Array[i].m_Name, name))
        {
            // finde the student in the mangement system
            // return the index of the student
            return i;
        }
    }
    // if the management system cannot find the student at the end of the loop
    return -1;
}

// 3.Delete Student
void delete_Student(manager *core)
{
    printf("Please input the name you want to delete: ");
    char name[10];
    scanf("%s", &name);

    // check whether the student is in the management system
    int result = check_Student_Exist(core, name);

    // if reslut = -1, the student is not exsit
    // else the student is exist
    if (result != -1)
    {
        // find out the student and perform the delete operation

        // delete the student's information, we need to move the data after the student forward
        for (int i = result; i < core->m_Student_Number; i++)
        {
            // move all the data after this student forward one by one
            core->student_Array[i] = core->student_Array[i + 1];
        }
        // update the number of student in the management system
        core->m_Student_Number--;
        printf("Successfully delete!\n");
        system("pause");
    }
    else
    {
        printf("The student is not exsit in this management system!");
        system("pause");
    }
}

// 4.Search Student
void search_Student(manager *core)
{
    printf("Please input the name you want to search: ");
    char name[10];
    scanf("%s", &name);

    // check whether the student is in the management system
    int result = check_Student_Exist(core, name);

    // if reslut = -1, the student is not exsit
    // else the student is exist

    if (result != -1)
    {
        // find out the student and perform the search operation
        printf("Successfully find out the student!\n");
        

        printf("Name:%s\t\t", core->student_Array[result].m_Name);
        printf("Gender:%s\t\t", core->student_Array[result].m_Gender == 1 ? "Man" : "Woman");
        printf("Age:%d\t\t", core->student_Array[result].m_Age);
        printf("C Program:%.1f\t\t", core->student_Array[result].m_C_Score);
        printf("Linear Algebra:%.1f\t\t", core->student_Array[result].m_Linear_Algebra_Score);
        printf("Calculus:%.1f\n", core->student_Array[result].m_Calculus_Score);

        system("pause");
    }
    else
    {
        printf("The student is not exsit in this management system!");
        system("pause");
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
            show_Student(&core);
            break;
        case 3:
            // 3.Delete Student

            // The following is the test funtion

            // printf("Please input the student name: ");
            // char name[10];
            // scanf("%s", &name);
            // if (check_Student_Exist(&core, name) == -1)
            // {
            //     printf("The student is not in the management system!");
            // }
            // else
            // {
            //     printf("Find out the student!\nThe index of the student is %d.\n", check_Student_Exist(&core, name));
            // }

            delete_Student(&core);
            break;
        case 4:
            // 4.Search Student
            search_Student(&core);
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
#include <stdio.h>
#include <stdlib.h>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// CONSTANT DEFINITION
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// define the maximum number of student is 1000
#define MAX 1000

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

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// STRUCTION DEFINITION
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// encapsulate the structure of student
// students' information include name, gender, age, C score, linear Algebra score and calculus score
struct student
{
    char m_Name[10];              /* student name */
    int m_Gender;                 /* student gender */
    int m_Age;                    /* student age */
    float m_C_Score;              /* C score */
    float m_Linear_Algebra_Score; /* linear Algebra score */
    float m_Calculus_Score;       /* calculus score */
};

// encapsulate the structure of system
struct management_System
{
    // student array 
    struct student student_Array[MAX];
    // student number at present
    int m_Student_Number;
};

int main(void)
{
    int select = 0;

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
            // 1.Add Student
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
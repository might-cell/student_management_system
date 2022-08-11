#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// CONSTANT DEFINITION
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// define the maximum number of student is 1000
#define MAX 100
// define the maximum number of student's exam
#define EXAM_NUM 3
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
    int m_Id;                     /* student id */
    float m_C_Score;              /* C score */
    float m_Linear_Algebra_Score; /* linear Algebra score */
    float m_Calculus_Score;       /* calculus score */
    float m_Total_Score;          /* student total score */
    float m_Average_Score;        /* student average score */
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
    printf("                                       \n");
    printf("          [1].Add     Student          \n");
    printf("          [2].Display Student          \n");
    printf("          [3].Delete  Student          \n");
    printf("          [4].Search  Student          \n");
    printf("          [5].Modify  Student          \n");
    printf("          [6].Wipe    Student          \n");
    printf("          [7].Clear   Screen           \n");
    printf("          [8].Sort    Student          \n");
    printf("          [9].Insert  Student          \n");
    printf("          [0].Exit    System           \n");
    printf("                                       \n");
}
void screen_Disp()
{
    system("pause");
    system("cls");
}
void calculate_Score(float c_Score, float linear_Agebra, float calculus)
{
    float total_Score = 0;
    float average_Score = 0;
    total_Score = c_Score + linear_Algebra_Score + calculus_Score;
    return total_Score;
}
// 1.Add Student
void add_Student(manager *core)
{
    // check whether the system is full
    if (core->m_Student_Number == MAX)
        printf("This mangement system is full, you cannot add any student!\n");
    else
    {
        // addd student id
        int id = 0;
        printf("Please input student's id: ");
        scanf("%d", &id);
        core->student_Array[core->m_Student_Number].m_Id = id;
        // add student name
        char name[30];
        printf("Please input student's name: ");
        scanf("%s", name);
        strcpy(core->student_Array[core->m_Student_Number].m_Name, name);
        // add student gender: 1 -> man, 0 -> woman
        printf("Use following number to describe the gender.\n");
        printf("                              \n");
        printf("          [1].  Man           \n");
        printf("          [0].  Woman         \n");
        printf("                              \n");
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
        // calculate the total and average score of the student
        int total_Score = calculate_Score(c_Score, linear_Algebra_Score, calculate_Score);
        core->student_Array[core->m_Student_Number].m_Total_Score = total_Score;
        core->student_Array[core->m_Student_Number].m_Average_Score = total_Score / EXAM_NUM;
        // update the number of student in the mangement system
        core->m_Student_Number++;
        screen_Disp();
    }
}


void disp_Interface(manager *core, int index)
{
    printf("Id:%d\t", core->student_Array[index].m_Id);
    printf("Name:%s\t", core->student_Array[index].m_Name);
    printf("Gender:%s\t", core->student_Array[index].m_Gender == 1 ? "Man" : "Woman");
    printf("Age:%d\t", core->student_Array[index].m_Age);
    printf("C Program:%.1f\t", core->student_Array[index].m_C_Score);
    printf("Linear Algebra:%.1f\t", core->student_Array[index].m_Linear_Algebra_Score);
    printf("Calculus:%.1f\t", core->student_Array[index].m_Calculus_Score);
    printf("Total Socre:%.1f\t", core->student_Array[index].m_Total_Score);
    printf("Average Score:%.1f\n", core->student_Array[index].m_Average_Score);
}
// 2.Dispplay Student
void show_Student(manager *core)
{
    // if check whether the number of the management system is 0, disp 0
    // else disp the information of the student
    if (core->m_Student_Number == 0)
        printf("The current record is empty!\n");
    else
    {
        for (int i = 0; i < core->m_Student_Number; i++)
            disp_Interface(core, index);
    }
    screen_Disp();
}
// encapsulate a function to check whether a student is in the mangement system
// if exsit, return the index of the student in the management system
// else, return -1
int check_Student_Id(manager *core, int id)
{
    for (int i = 0; i < core->m_Student_Number; i++)
    {
        if (core->student_Array[i].m_Id == id)
            // finde the student in the mangement system
            // return the index of the student
            return i;
    }
    // if the management system cannot find the student at the end of the loop
    return -1;
}
int check_Student_Exist(manager *core, char name[])
{
    for (int i = 0; i < core->m_Student_Number; i++)
    {
        if (!strcmp(core->student_Array[i].m_Name, name))
            // finde the student in the mangement system
            // return the index of the student
            return i;
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
            // move all the data after this student forward one by one
            core->student_Array[i] = core->student_Array[i + 1];
        // update the number of student in the management system
        core->m_Student_Number--;
        printf("Successfully delete!\n");
        screen_Disp();
    }
    else
    {
        printf("The student is not exsit in this management system!\n");
        screen_Disp();
    }
}
void search_Name(manager *core)
{
    printf("Please input the name you want to search: ");
    char name[10];
    scanf("%s", name);
    // check whether the student is in the management system
    int result = check_Student_Exist(core, name);
    // if reslut = -1, the student is not exsit
    // else the student is exist
    if (result != -1)
    {
        // find out the student and perform the search operation
        printf("Successfully find out the student!\n");
        disp_Interface(core, result);
        screen_Disp();
    }
    else
    {
        printf("The student is not exsit in this management system!\n");
        screen_Disp();
    }
}
// search by id
void search_Id(manager *core)
{
    printf("Please input the id you want to search: ");
    int num = 0;
    scanf("%d", &num);
    // check whether the student is in the management system
    int result = check_Student_Id(core, num);
    // if reslut = -1, the student is not exsit
    // else the student is exist
    if (result != -1)
    {
        // find out the student and perform the search operation
        printf("Successfully find out the student!\n");
        disp_Interface(core, result);
        screen_Disp();
    }
    else
    {
        printf("The student is not exsit in this management system!\n");
        screen_Disp();
    }
}
// 4.Search Student
void search_Student(manager *core)
{
    printf("                   [1].Search by name.\n");
    printf("                   [2].Search by id.\n");
    int option = 0;
    printf("Please select a search metric: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        search_Name(core);
        break;
    case 2:
        search_Id(core);
        break;
    default:
        break;
    }
}
// 5.Modify Student
void modify_Student(manager *core)
{
    printf("Please input the name you want to modify: ");
    char name[10];
    scanf("%s", &name);
    // check whether the student is in the management system
    int result = check_Student_Exist(core, name);
    // if reslut = -1, the student is not exsit
    // else the student is exist
    if (result != -1)
    {
        // find out the student and perform the modify operation
        // modify student id
        int id = 0;
        printf("Please input student's id");
        scanf("%d", &id);
        core->student_Array[result].m_Id = id;
        // modify student name
        char name[30];
        printf("Please input student's name: ");
        scanf("%s", name);
        strcpy(core->student_Array[result].m_Name, name);
        // modify student gender: 1 -> man, 0 -> woman
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
                core->student_Array[result].m_Gender = gender;
                break;
            }
            printf("The gender you input is worry, please input again: ");
        }
        // modify student age
        printf("Please input student's age: ");
        int age = 0;
        while (1)
        {
            // if the age is in (0, 100), you can break the loop
            // else the age is worry, you will try again
            scanf("%d", &age);
            if (age > 0 && age < 100)
            {
                core->student_Array[result].m_Age = age;
                break;
            }
            printf("The age you input is worry, please input again: ");
        }
        // modify student C score
        printf("Please input student's C program lecture score: ");
        float c_Score = 0;
        while (1)
        {
            // if the score is in [0, 100], you can break the loop
            // else the score is worry, you will try again
            scanf("%f", &c_Score);
            if (c_Score >= 0 && c_Score <= 100)
            {
                core->student_Array[result].m_C_Score = c_Score;
                break;
            }
            printf("The C program lecture score you input is worry, please input again: ");
        }
        // modify student Linear Algebra score
        printf("Please input student's Linear Algebra lecture score: ");
        float linear_Algebra_Score = 0;
        while (1)
        {
            // if the score is in [0, 100], you can break the loop
            // else the score is worry, you will try again
            scanf("%f", &linear_Algebra_Score);
            if (linear_Algebra_Score >= 0 && linear_Algebra_Score <= 100)
            {
                core->student_Array[result].m_Linear_Algebra_Score = linear_Algebra_Score;
                break;
            }
            printf("The Linear Algebra lecture score you input is worry, please input again: ");
        }
        // modify student calculus score
        printf("Please input student's Calculus lecture score: ");
        float calculus_Score = 0;
        while (1)
        {
            // if the score is in [0, 100], you can break the loop
            // else the score is worry, you will try again
            scanf("%f", &calculus_Score);
            if (calculus_Score >= 0 && calculus_Score <= 100)
            {
                core->student_Array[result].m_Calculus_Score = calculus_Score;
                break;
            }
            printf("The Calculus lecture score you input is worry, please input again: ");
        }
        // calculate the total and average score of the student
        float total_Score = calculate_Score(c_Score, linear_Algebra_Score, calculus_Score);
        core->student_Array[result].m_Total_Score = total_Score;
        core->student_Array[result].m_Average_Score = total_Score/EXAM_NUM;
        screen_Disp();
    }
    else
    {
        printf("The student is not exsit in this management system!\n");
        screen_Disp();
    }
}
// 6.Wipe Student
void wipe_Student(manager *core)
{
    // implemet logical clearing
    // let current number of student in this management system is 0
    core->m_Student_Number = 0;
    printf("Information in the management has already been cleared!");
    screen_Disp();
}
// Sort by total score
void sort_Total_Score(manager *core)
{
    printf("                                                                                               \n");
    printf("                   [1].Sort in ascending order according to the total score.                   \n");
    printf("                   [2].Sort in descending order according to the total score                   \n");
    printf("                                                                                               \n");
    printf("Please select a collation rule: ");
    int select = 0;
    scanf("%d", &select);
    for (int i = 0; i < core->m_Student_Number; i++)
    {
        // defien the maximum or minximum index of the students
        int max_Score = i;
        for (int j = i + 1; j < core->m_Student_Number; j++)
        {
            if (select == 1)
            {
                // ascending order
                if (core->student_Array[max_Score].m_Total_Score >= core->student_Array[j].m_Total_Score)
                {
                    max_Score = j;
                }
            }
            else
            {
                // descending order
                if (core->student_Array[max_Score].m_Total_Score <= core->student_Array[j].m_Total_Score)
                {
                    max_Score = j;
                }
            }
        }
        // check opearation
        if (i != max_Score)
        {
            stu temp = core->student_Array[i];
            core->student_Array[i] = core->student_Array[max_Score];
            core->student_Array[max_Score] = temp;
        }
    }
    printf("Successfully sorted!\n");
}
// sort by id
void sort_Id(manager *core)
{
    printf("                                                                                      \n");
    printf("                   [1].Sort in ascending order according to the id.                   \n");
    printf("                   [2].Sort in descending order according to the id.                  \n");
    printf("                                                                                       \n");
    printf("Please select a collation rule: ");
    int select = 0;
    scanf("%d", &select);
    for (int i = 0; i < core->m_Student_Number; i++)
    {
        // defien the maximum or minximum index of the students
        int max_Score = i;
        for (int j = i + 1; j < core->m_Student_Number; j++)
        {
            if (select == 1)
            {
                // ascending order
                if (core->student_Array[max_Score].m_Id >= core->student_Array[j].m_Id)
                {
                    max_Score = j;
                }
            }
            else
            {
                // descending order
                if (core->student_Array[max_Score].m_Id <= core->student_Array[j].m_Id)
                {
                    max_Score = j;
                }
            }
        }
        // check opearation
        if (i != max_Score)
        {
            stu temp = core->student_Array[i];
            core->student_Array[i] = core->student_Array[max_Score];
            core->student_Array[max_Score] = temp;
        }
    }
    printf("Successfully sorted!\n");
}
// sort by name
void sort_Name(manager *core)
{
    printf("                                                                                        \n");
    printf("                   [1].Sort in ascending order according to the name.                   \n");
    printf("                   [2].Sort in descending order according to the name                   \n");
    printf("                                                                                        \n");
    printf("Please select a collation rule: ");
    int select = 0;
    scanf("%d", &select);
    for (int i = 0; i < core->m_Student_Number; i++)
    {
        // defien the maximum or minximum index of the students
        int max_Score = i;
        for (int j = i + 1; j < core->m_Student_Number; j++)
        {
            if (select == 1)
            {
                // ascending order
                if (strcmp(core->student_Array[max_Score].m_Name, core->student_Array[j].m_Name) >= 0)
                {
                    max_Score = j;
                }
            }
            else
            {
                // descending order
                if (strcmp(core->student_Array[max_Score].m_Name, core->student_Array[j].m_Name) <= 0)
                {
                    max_Score = j;
                }
            }
        }
        // check opearation
        if (i != max_Score)
        {
            stu temp = core->student_Array[i];
            core->student_Array[i] = core->student_Array[max_Score];
            core->student_Array[max_Score] = temp;
        }
    }
    printf("Successfully sorted!\n");
}
// sort by average score
void sort_Average_Score(manager *core)
{
    printf("                   [1].Sort in ascending order according to the average score.\n");
    printf("                   [2].Sort in descending order according to the average score\n");
    printf("Please select a collation rule: ");
    int select = 0;
    scanf("%d", &select);
    for (int i = 0; i < core->m_Student_Number; i++)
    {
        // defien the maximum or minximum index of the students
        int max_Score = i;
        for (int j = i + 1; j < core->m_Student_Number; j++)
        {
            if (select == 1)
            {
                // ascending order
                if (core->student_Array[max_Score].m_Average_Score >= core->student_Array[j].m_Average_Score)
                {
                    max_Score = j;
                }
            }
            else
            {
                // descending order
                if (core->student_Array[max_Score].m_Average_Score <= core->student_Array[j].m_Average_Score)
                {
                    max_Score = j;
                }
            }
        }
        // check opearation
        if (i != max_Score)
        {
            stu temp = core->student_Array[i];
            core->student_Array[i] = core->student_Array[max_Score];
            core->student_Array[max_Score] = temp;
        }
    }
    printf("Successfully sorted!\n");
}
// 7.Sort Student
void sort_Student(manager *core)
{
    // check whether the number of student in the mangement is 0
    if (core->m_Student_Number == 0)
    {
        printf("The current record is empty!\n");
    }
    else
    {
        printf("                   [1].Sort by total score.\n");
        printf("                   [2].Sort by average score.\n");
        printf("                   [3].Sort by name.\n");
        printf("                   [4].Sort by id.\n");
        printf("Please select a sort metric: ");
        int option = 0;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            // 1.Sort by total score.
            sort_Total_Score(core);
            break;
        case 2:
            // 2.Sort by average score.
            sort_Average_Score(core);
            break;
        case 3:
            // 3.Sort by name.
            sort_Name(core);
            break;
        case 4:
            // 4.Sort by id.
            sort_Id(core);
            break;
        default:
            break;
        }
    }
    screen_Disp();
}
// Insert  Student
void insert_Student(manager *core)
{
    core->m_Student_Number++;
    printf("Please input the index you want to insert: ");
    int index = 0;
    scanf("%d", &index);
    // init
    printf("Let's init the new student!\n");
    stu new_Student;
    // check whether the system is full
    if (core->m_Student_Number == MAX)
    {
        printf("This mangement system is full, you cannot add any student!\n");
    }
    else
    {
        // add student id
        int id = 0;
        printf("Please input student's id: ");
        scanf("%d", &id);
        new_Student.m_Id = id;
        // add student name
        char name[30];
        printf("Please input student's name: ");
        scanf("%s", name);
        strcpy(new_Student.m_Name, name);
        // add student gender: 1 -> man, 0 -> woman
        printf("Use following number to describe the gender.\n");
        printf("                              \n");
        printf("          [1].  Man           \n");
        printf("          [0].  Woman         \n");
        printf("                              \n");
        printf("Please input stdeunt's gender: ");
        int gender = 0;
        while (1)
        {
            // if enter 1 or 0, you can break the loop
            // else the gender is worry, you will try again
            scanf("%d", &gender);
            if (gender == 1 || gender == 0)
            {
                new_Student.m_Gender = gender;
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
                new_Student.m_Age = age;
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
                new_Student.m_C_Score = c_Score;
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
                new_Student.m_Linear_Algebra_Score = linear_Algebra_Score;
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
                new_Student.m_Calculus_Score = calculus_Score;
                break;
            }
            printf("The Calculus lecture score you input is worry, please input again: ");
        }
        // calculate the total and average score of the student
        calculate_Score();
        new_Student.m_Total_Score = total_Score;
        new_Student.m_Average_Score = average_Score;
        for (int i = core->m_Student_Number - 1; i >= index; i--)
        {
            core->student_Array[i + 1] = core->student_Array[i];
        }
        core->student_Array[index] = new_Student;
        screen_Disp();
    }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// MAIN FUNCTION DEFINITION
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
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
            delete_Student(&core);
            break;
        case 4:
            // 4.Search Student
            search_Student(&core);
            break;
        case 5:
            // 5.Modify Student
            modify_Student(&core);
            break;
        case 6:
            // 6.Wipe Student
            wipe_Student(&core);
            break;
        case 7:
            // 7.Clear Screen
            system("cls");
            break;
        case 8:
            // 8.Sort Student
            sort_Student(&core);
            break;
        case 9:
            // 9.Insert  Student
            insert_Student(&core);
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
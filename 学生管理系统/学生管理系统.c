#include <stdio.h>
#include <stdlib.h>

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
    printf("-=-=-=-=-=-=-=   0.Exit System       -=-=-=-=-=-=-=\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

// 


int main(void)
{
    int select = 0;

    // invoke the function to show the operation interface
    showMenu();

    // encapsulate the loop to finish the selection
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
    case 0:
        // 0.Exit System 
        printf("Welcom to use the system next time!\n");
        system("pause");
        return 0;
        break;
    default:
        break;
    }

    return 0;
}
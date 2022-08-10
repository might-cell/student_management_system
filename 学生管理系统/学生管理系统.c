#include <stdio.h>
#include <stdlib.h>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// FUNCTION DECLARATION
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


int main(void)
{
    // invoke the function to show the operation interface
    showMenu();
    return 0;
}
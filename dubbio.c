/* non mi ricordo se posso dichiarare e assegnare contemporaneamente
non resta che provare
gcc dubbio.c -o dubbio.exe
*/

#include <stdio.h>

int main() {

    int i = 5;

    int * px = &i;

    printf ("%i %i", i, *px);

}

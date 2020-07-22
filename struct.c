
/*
gcc struct.c -o struct.exe
*/

// cosa farei io al tuo posto:
// per prima cosa mi definirei una struct che mi raccolga l'input dell'utente (tutto quanto, magari sbaglio, non so, poi vedremo)

#include <stdio.h>


struct Riga {
    char* testo;   // attenzione che non punta a niente
    int tipo;      // qui ci scriverò se la riga è un comando oppure un testo, vedremo.
    struct Riga* next; // ho in mente di fare una lista di questi elementi Riga
};

int prova1(){
    // giusto per prendere dimestichezza con la sintassi che non mi ricordo piu niente
    struct Riga r;  // dichiaro una variabile di tipo Riga
    r.tipo = 1;     // assegno qualcosa di semplice

    printf("%d\n", r.tipo);

    char ciao[] = "ciao Ale";

    r.testo = ciao;     // se non ricordo male ciao è un puntatore a un array di caratteri quindi r.testo = ciao è l'assegnamento di una variabile di tipo puntatore
    printf("%s\n", r.testo);

}

// giusto per vedere se compila
int main() {
    prova1();

}




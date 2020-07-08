/*
gcc ed0.c -o ed0.exe
*/

#include <stdio.h>
#include <string.h>

int isComando(char* buf, int* r1, int* r2, char* cmd) {
    int ret;

    // cerca di riconoscere un comando a 3 parametri:   1,2p
    ret = sscanf(buf,"%d,%d%c",r1, r2, cmd );
    if (ret !=3) {
        // comando a 2 parametri: 3u
        ret = sscanf(buf,"%d%c",r1, cmd );
        *r2 = 0;

        // per essere un comando buf deve essere lungo 2: il carattere di comando e il carattere CR (invio)
        if (ret != 2 && strlen(buf)==2 ) {
            ret = sscanf(buf,"%c", cmd );
            *r1=0;
            *r2=0;
        }
        else {
            *r1 = 0;
            *r2 = 0;
            *cmd = 'z';   // z = nessun comando
            ret = 0;
        }
    }

    // prima di uscire andrebbe controllato che il carattere di comando trovato sia effettivamente tra i comandi ammessi
    return ret;
}

int main() {
    char buffer[100];
    int quit;
    int r1;
    int r2;
    char cmd;
    int ok;

    for (quit=0; quit==0;) {
        printf(">>");
        fgets(buffer,100,stdin);
        // esame del buffer, riconoscimento comandi
        ok = isComando(buffer, &r1, &r2, &cmd);

        printf("risultato sscanf %d\n", ok);
        printf("r1 %d\n", r1);
        printf("r2 %d\n", r2);
        printf("cmd %c\n", cmd);
        printf("%s\n", buffer);

        if (cmd == 'q'){
            quit=1;
        }
    }
return(0);
}

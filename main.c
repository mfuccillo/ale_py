#include <stdio.h>
#include <string.h>




int isComando(char* buf, int* r1, int* r2, char* cmd) {
    int ret;

    // cerca di riconoscere un comando a 3 parametri:   1,2p
    ret = sscanf(buf, "%d,%d%c", r1, r2, cmd);

    if (ret != 3) {
        // comando a 2 parametri: 3u o 3r
        ret = sscanf(buf, "%d%c", r1, cmd);
        *r2 = 0;

        if(ret == 2) {

            if (( *cmd != 'u') && ( *cmd != 'r')) {

                *cmd = 'z'; //comando non valido
            }
        }
        // per essere un comando buf deve essere lungo 2: il carattere di comando e il carattere invio
        else if (ret != 2 && strlen(buf)==2 ) {
            ret = sscanf(buf,"%c", cmd );
            *r1=0;
            *r2=0;

        }else {
            *r1 = 0;
            *r2 = 0;
            *cmd = 'z';   // z = nessun comando
            ret = 0;
        }
    }else if (ret == 3){

        if( ( *cmd != 'c') && ( *cmd != 'd') && ( *cmd != 'p')){

            *cmd = 'z';
        }
    }

    return ret;
}

//change modifica porzione di testo agli indirizzi passati come argomento
void c(int val1,int val2, FILE *pointer){
    int n_lines;
    int curr_pos, pos;
    char string[1024];
    char end[] = ".";

    n_lines = val2 - val1 + 1;
    //uso val1 per spostarmi all'indirizzo/riga dove metter stringa
    // calcolando (indirizzo - 1) * num. byte per riga +1 (mi sposto a inizio riga succesiva)
    fseek(pointer, (val1-1)*1024 +1 , SEEK_CUR);

    while ((n_lines > 0) && (strcmp(string, end)!=0) ){
        fgets(string,1024,stdin);
        fputs(string,pointer);
        n_lines--;
    }

    curr_pos=ftell(pointer);
    pos = curr_pos - 1024 ;
    fseek(pointer, curr_pos + pos + 1 , SEEK_CUR);
    fprintf(pointer, "%c", end);




}

int main() {
    char buffer[100];
    char cmd;
    int quit;
    int ind1, ind2, ok;

    FILE *fp;


    for (quit=0; quit==0;) {

        printf(">>");

        fgets(buffer,100,stdin);

        ok = isComando(buffer, &ind1, &ind2, &cmd);

        //esame comando

        printf("risultato sscanf %d\n", ok);
        printf("ind1 %d\n", ind1);
        printf("ind2 %d\n", ind2);
        printf("cmd %c\n", cmd);

        fp = fopen("file.txt","w+");

        switch (cmd) {

            case 'c':
                c(ind1,ind2, &fp);
                break;
            case 'd':
                break;
            case 'p':
                break;
            case 'u':
                break;
            case 'r':
                break;
            case 'z':
                printf("Comando non valido (._.)\n");
                break;

        }

        fclose(fp);




        if (buffer[0] == 'q'){

            quit=1;

        }

    }

    return(0);

}

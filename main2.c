#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    printf("Hey there! To control your dalek, press the keywords w-> forward, d-> right, s->backward, a->left, p->stop, n->quit the program, then enter!\n");
    char input;
    int status;
    int count = 0;
    while(1){
        if ( _kbhit() ){
            input = _getch();
            switch(input){
                case 'w':
                    if(count > 0){
                        fprintf(stdout, "Ho premuto avanti mentre facevo altro\n");
                        fflush(stdout);
                        status=system("python3 movements/pause.py");
                        status=system("sudo killall python3");
                    }
                    count++;
                    //forward.py
                    status = system("python3 movements/forward.py&");
                    break;
                case 's':
                    if(count > 0){
                        fprintf(stdout, "Ho premuto indietro mentre facevo altro\n");
                        fflush(stdout);
                        status=system("python3 movements/pause.py");
                        status=system("sudo killall python3");
                    }
                    count++;
                    //backward.py
                    status = system("python3 movements/backward.py&");
                break;
                case 'd':
                    if(count > 0){
                        fprintf(stdout, "Ho premuto destra mentre facevo altro\n");
                        fflush(stdout);
                        status=system("python3 movements/pause.py");
                        status=system("sudo killall python3");
                    }
                    count++;
                    //right.py
                    status = system("python3 movements/right.py&");
                break;
                case 'a':
                    if(count > 0){
                        fprintf(stdout, "Ho premuto sinistra mentre facevo altro\n");
                        fflush(stdout);
                        status=system("python3 movements/pause.py");
                        status=system("sudo killall python3");
                    }
                    count++;
                    //left.py
                    status = system("python3 movements/left.py&");
                break;
                case 'p':
                    if(count > 0){
                        fprintf(stdout, "Ho premuto pausa mentre facevo altro\n");
                        fflush(stdout);
                        status=system("python3 movements/pause.py");
                        status=system("sudo killall python3");
                    }
                break;
                case 'n':
                    return 0;
                fprintf(stdout, "CI ARRIVO SÌ\n");
                fflush(stdout);
            }
        }else{
            status=system("python3 movements/pause.py");
            status=system("sudo killall python3");
        }

        scanf("%c", &input);
        switch(input){
            case 'w':
                if(count > 0){
                    fprintf(stdout, "Ho premuto avanti mentre facevo altro\n");
                    fflush(stdout);
                    status=system("python3 movements/pause.py");
                    status=system("sudo killall python3");
                }
                count++;
                //forward.py
                status = system("python3 movements/forward.py&");
                break;
            case 's':
                if(count > 0){
                    fprintf(stdout, "Ho premuto indietro mentre facevo altro\n");
                    fflush(stdout);
                    status=system("python3 movements/pause.py");
                    status=system("sudo killall python3");
                }
                count++;
                //backward.py
                status = system("python3 movements/backward.py&");
            break;
            case 'd':
                if(count > 0){
                    fprintf(stdout, "Ho premuto destra mentre facevo altro\n");
                    fflush(stdout);
                    status=system("python3 movements/pause.py");
                    status=system("sudo killall python3");
                }
                count++;
                //right.py
                status = system("python3 movements/right.py&");
            break;
            case 'a':
                if(count > 0){
                    fprintf(stdout, "Ho premuto sinistra mentre facevo altro\n");
                    fflush(stdout);
                    status=system("python3 movements/pause.py");
                    status=system("sudo killall python3");
                }
                count++;
                //left.py
                status = system("python3 movements/left.py&");
            break;
            case 'p':
                if(count > 0){
                    fprintf(stdout, "Ho premuto pausa mentre facevo altro\n");
                    fflush(stdout);
                    status=system("python3 movements/pause.py");
                    status=system("sudo killall python3");
                }
            break;
            case 'n':
                return 0;
            fprintf(stdout, "CI ARRIVO SÌ\n");
            fflush(stdout);
        }
    }
    return 0;
}

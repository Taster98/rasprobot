#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

int main(){
    printf("Hey there! To control your dalek, press the keywords w-> forward, d-> right, s->backward, a->left, p->stop, n->quit the program, then enter!\n");
    char input;
    int status;
    int count = 0;
    while(1){
        input = getch();
        switch(input){
            case 'w':
                if(count > 0){
                    fprintf(stdout, "Ho premuto avanti\n");
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
                    fprintf(stdout, "Ho premuto indietro\n");
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
                    fprintf(stdout, "Ho premuto destra\n");
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
                    fprintf(stdout, "Ho premuto sinistra\n");
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
                    fprintf(stdout, "Ho premuto pausa\n");
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

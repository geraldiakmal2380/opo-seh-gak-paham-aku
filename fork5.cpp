#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    pid_t child_pid;
    int status;
    pid_t wait_result;

    child_pid = fork();
    
    if(child_pid == 0){
        cout << "I'm a child and my pid is " << getpid() << endl;
        execl("/bin/ls","ls","-l","/home", NULL);
        cout << "Could not execl /bin/ls " << endl;
        exit(1);
    }
    else if(child_pid>0){
            cout << "I'm the parent and my pid " << getpid() << endl;
            cout << "My child  has a pid " << child_pid << endl;


    }
}
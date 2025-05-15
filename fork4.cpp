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
    if(child_pid==0){
        /*Kode ini hanya akan dieksekusi proses child*/
        cout << "Child Proces PID : " << getpid() << endl;
        cout << "My Parent is : " << getppid() << endl; 
    }
    else if(child_pid>0){   
        /*kode ini akan dieksekusi proses parent*/
        cout << "I am the parent and my pid = " << getpid() << endl;
        cout << "My child has a pid " << child_pid << endl;
        
    }
    else{
        cout << "The fork System has failed to create a new process " << endl;
        exit(1);
    }

    /* kode ini dieksekusi baik oleh proses parent ataupun child*/

    cout << "I'm happy, Healthy process and my PID = " << getpid() << endl;

    do{
        wait_result = wait(&status);
    }while (wait_result != child_pid);
    
    return 0;
}
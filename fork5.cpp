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
    else
    {
        cout << "The fork system call failed to create a new process" << endl; 
        exit(1);
    }

    /*Kode ini hanya dieksekusi oleh proses parent karena child mengeksekusi dari "/bin/ls" atau keluar
    */

    cout << "I am happy, Healthy process and my pid =" << getpid() << endl;

    if(child_pid == 0){
        cout << "Kode ini tidak pernah dieksekusi" << endl;
    }
    else{
        /*Kode ini hanya dieksekusi oleh proses parent*/
        cout << "I am parent and i'm waiting my child die" << endl;
    }

    do{
        wait_result = wait(&status);
    }while(wait_result != child_pid);
    
    
}
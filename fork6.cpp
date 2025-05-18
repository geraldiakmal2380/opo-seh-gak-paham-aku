#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/* pid_t fork() dideklarasikan pada unistd.h
    pid_t adalah type khusus untuk process id yang ekuivalen dg int

*/

int main(void){
    pid_t child_pid;
    int status;
    pid_t wait_result;

    child_pid = fork();
    if (child_pid ==0)
    {
        /*kode ini hanya dieksekusi oleh process child*/
        cout <<  "I am a child and my pid is " << getpid() << endl;
        execl("fork3","goose",NULL);
        //jika execl berhasil maka kode ini tidak akan digunakan.
        cout << "Could not execl fork3 " << endl;
        exit(1);
        //exit hanya menghentikan process child
    }
    else if (child_pid > 0)
    {
        //kode ini hanya dieksekudi proses parent
        cout << "I am a parent and waiting my child to die" << endl;
    }
    do
    {
        /*Parent menunggu sinyal SIGCHILD mengirim tanda bila proses child diterminasi*/
        wait_result = wait(&status);
    } while (wait_result != child_pid);

    cout << "I'm parent and quitting" << endl;
    
    
    
}
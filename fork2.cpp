#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>

int main(void){
    pid_t pidku;
    uid_t uidku;

    pid_t childpid;
    int x =5;

    while (1)
    {
        cout << "This is process " << getpid() << endl;
        cout << "X is " << x << endl;
        sleep(1);   
        x++;
    }
    
    return 0;
}

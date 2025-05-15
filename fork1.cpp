#include <iostream>

using namespace std;

#include <sys/types.h>
#include <unistd.h>

/* */

int main(void){
    pid_t mypid;
    uid_t myuid;

    for(int i=0;i<3;i++){
        mypid = getpid();
        cout << "I am process " << mypid << endl;
        cout << "My parent process" << getpid()<< endl;
        cout << "The owner of this process has uid " << getuid() << endl;

        /*
        */
        sleep(1);
    }
    return 0;
}
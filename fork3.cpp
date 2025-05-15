#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t childpid;

    childpid = fork();
    for (int i = 0; i < 5; i++)
    {
        cout << "This is process " << getpid() <<endl;
        sleep(2);
    }
    
    return 0;
}

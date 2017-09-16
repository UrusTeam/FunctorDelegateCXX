#include <string.h>
#include "functor.h"
#include <stdio.h>

class BoxProcess {
public:
    BoxProcess(){}

    typedef void(*Proc)(void);
    FUNCTOR_TYPEDEF(MemberProc, void);

    MemberProc _proc[2];
    uint8_t counter = 0;

    void _process_one()
    {
        printf("    Process one: %u\n", counter);
    }

    void _process_two()
    {
        printf("    Process two: %u\n", counter);
    }

    void register_process(MemberProc proc)
    {
        static uint8_t pos = 0;

        if (pos > 1) return;
        _proc[pos] = proc;
        pos++;
    }

    void run()
    {
        register_process(FUNCTOR_BIND_MEMBER(&BoxProcess::_process_one, void));
        register_process(FUNCTOR_BIND_MEMBER(&BoxProcess::_process_two, void));

        uint8_t sentinel = 0;
        for (uint8_t i = 0; i < 10; i++) {
            counter = i;
            sentinel %= 2;
            _proc[sentinel]();
            sentinel++;
            if (sentinel == 2) {
                printf("\n");
            }
        }
    }
};

BoxProcess boxprocess;

int main(int argc, char* argv[])
{
    printf("\nStart!\n\n");

    //boxprocess = new BoxProcess;
    boxprocess.run();

    printf("Finish!\n");

    return 0;
}

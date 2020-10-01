#include "q.h"

struct queue* RunQ;

void start_thread(void(*function),int x,int y)
{
    TCB_t *temp = newItem();
    void *stack = (void *)malloc(8192);
    init_TCB(temp, function, stack, 8192, x, y);
    AddQueue(RunQ,temp);

    return;
}

void run()
{
    
    ucontext_t parent;
    getcontext(&parent);
    swapcontext(&parent, &(RunQ->head->context));
    return;
}

void yield()
{
    ucontext_t originalpos,newpos;
    getcontext(&originalpos);
    RunQ->head->context = originalpos;
    RotateQ(RunQ);
    newpos = RunQ->head->context;
    swapcontext(&originalpos, &newpos);
    return;
    
}

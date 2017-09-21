#ifndef SUBTHREAD_H
#define SUBTHREAD_H
#include "Thread.h"

class SubThread : public Thread
{
    public:
        SubThread();
        SubThread(int i);
        virtual ~SubThread();
        virtual void run();

    protected:

    private:
};

#endif // SUBTHREAD_H

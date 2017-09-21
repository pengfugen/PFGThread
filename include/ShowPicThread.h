#ifndef SHOWPICTHREAD_H
#define SHOWPICTHREAD_H
#include "Thread.h"

class ShowPicThread : public Thread
{
    public:
        ShowPicThread();
        virtual ~ShowPicThread();
        ShowPicThread(const ShowPicThread& other);
        ShowPicThread& operator=(const ShowPicThread& other);


    protected:


    private:
        void run();

};

#endif // SHOWPICTHREAD_H

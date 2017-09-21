#ifndef DOWNLOADFILETHREAD_H
#define DOWNLOADFILETHREAD_H

#include "Thread.h"

class DownloadFileThread : public Thread
{
    public:
        DownloadFileThread();
        virtual ~DownloadFileThread();
        void run();

    protected:

    private:
};

#endif // DOWNLOADFILETHREAD_H

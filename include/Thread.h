#ifndef THREAD_H
#define THREAD_H

#include "pthread.h"

class Thread
{
    public:
        Thread();
        virtual ~Thread();
        void start();
        pthread_t getTid();

    protected:
        virtual void run() = 0;

    private:
        static void* startThread(void* arg);
        pthread_t m_tid;
};

#endif // THREAD_H

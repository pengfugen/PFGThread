#ifndef SYNCOBJ_H
#define SYNCOBJ_H

#include "pthread.h"

class SyncObj
{
    public:
        void syncStart();
        void syncEnd();
        void wait();
        static SyncObj* instance();

    protected:

    private:
        static SyncObj mInstance;
        SyncObj();
        virtual ~SyncObj();
        pthread_mutex_t m_mutex=PTHREAD_MUTEX_INITIALIZER;
};

#endif // SYNCOBJ_H

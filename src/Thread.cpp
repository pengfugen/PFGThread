#include "Thread.h"
#include <iostream>

Thread::Thread()
{
    //ctor
}

Thread::~Thread()
{
    //dtor
}

void*
Thread::startThread(void* arg)
{
    Thread *thPtr = (Thread*)arg;
    thPtr->run();
    return NULL;
}

void
Thread::start()
{
    if(pthread_create(&m_tid, NULL, startThread, (void *)this) != 0)
    {
        std::cout<<"Create thread failed!\n"<<std::endl;
        return;
    }
    //std::cout<<"Create thread success.\n"<<std::endl;
}

pthread_t
Thread::getTid()
{
    return m_tid;
}

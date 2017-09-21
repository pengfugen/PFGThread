#include "SubThread.h"
#include <iostream>

SubThread::SubThread()
{
    //ctor
}

SubThread::SubThread(int i)
{
    std::cout<<"SubThread-------------i:"<<i<<std::endl;
}

SubThread::~SubThread()
{
    //dtor
}

void
SubThread::run()
{
    for(int i = 0; i < 10; i++)
    {
        std::cout<<"SubThread-------------i:"<<i<<std::endl;
    }
}

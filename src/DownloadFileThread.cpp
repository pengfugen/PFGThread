#include "DownloadFileThread.h"
#include <iostream>
#include <unistd.h>
#include "SyncObj.h"

static int count = 0;

DownloadFileThread::DownloadFileThread()
{
    //ctor
}

DownloadFileThread::~DownloadFileThread()
{
    //dtor
}

void
DownloadFileThread::run()
{
    //SyncObj::instance()->syncStart();
    std::cout<<"Download file running begin tid:"<<getTid()<<std::endl;

    while(count <= 10000)
    {
        count++;
        std::cout<<"===count:"<<count<<std::endl;
    }
    std::cout<<"Download file running end"<<std::endl;
    //SyncObj::instance()->syncEnd();
}

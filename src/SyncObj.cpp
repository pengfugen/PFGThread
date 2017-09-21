#include "SyncObj.h"

SyncObj SyncObj::mInstance;

SyncObj::SyncObj()
{
    //ctor
    pthread_mutex_init(&m_mutex, NULL);
}

SyncObj::~SyncObj()
{
    //dtor
    pthread_mutex_destroy(&m_mutex);
}

SyncObj*
SyncObj::instance()
{
    return &mInstance;
}

void
SyncObj::syncStart()
{
    pthread_mutex_lock(&m_mutex);
}

void
SyncObj::syncEnd()
{
    pthread_mutex_unlock(&m_mutex);
}

void
SyncObj::wait()
{

}

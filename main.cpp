#include "SyncObj.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>



pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


int count = 10;
int thd_id = 1;

typedef struct
{
   void (*callback)(int);
}CallBack;

void * download(void * arg)
{
    CallBack *back = (CallBack*)arg;
    back->callback(10);
    return (void*)0;
}

void downloadCallBack(int value) {
   printf("downloadCallBack get value:%d\n", value);
}

void startDownload() {
    CallBack back;
    back.callback = downloadCallBack;
    pthread_t tid;
    if(pthread_create(&tid, NULL, download, (void*)(&back)) != 0) {
       printf("Thread created failed!\n");
    }
}


int add(int a, int b) {
   return a + b;
}

int sub(int a, int b) {
   return a - b;
}

enum FUNC_TYPE
{
    ADD,
    SUB
};

int getValue(int (*funcptr)(int, int), int a, int b)
{
    return funcptr(a,b);
}

typedef struct {
   char name[20];
   void * funcptr;
} Methods;

int main()
{
    pthread_t thd[4];
    for(int i = 1; i <= 4; i++) {
     //  if(pthread_create(&thd[i], NULL, thread_func, (void*)(i)) != 0) {
    //      printf("Thread:%d created failed!\n", i);
      // }
    }

    char *str[] = {"abc1","def23","ghi456"};
    char **ptr = str;

    for(int i = 0; i < (sizeof(str)/sizeof(char *)); i++)
    {
        //printf("str(%d)=%s\n", i, (ptr+i));
        printf("str(%d)=%s\n", i, *(ptr+i));
        printf("str(%d)=%s\n", i, ptr[i]);
        printf("str(%d)=%s\n", i, str[i]);
    }


    Methods methods[] = {{"add", (void*)add},
                         {"sub", (void*)sub}
                        };



    printf("add:%d\n",getValue(add, 10, 6));
    printf("sub:%d\n",getValue(sub, 10, 6));


    startDownload();
    return 0;
}

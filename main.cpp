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

int* getArr(int &length) {
   length = 6;
   int *arr = new int[6];
   arr[0] = 1;
   arr[1] = 2;
   return arr;
}
/*
int add(int a,int b,int c){
return 0;
}
*/
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

int (*func1)(int a, int b);

typedef struct {
   char name[20];
   void * funcptr;
} Methods;

int main()
{
    int length;
    int *arr = getArr(length);
    for(int i = 0; i < length; i++) {
        printf("arr:%d\n",arr[i]);
    }
    delete[]arr;

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
    func1 = &add; // Ҳ������func1 = add;
    int a = func1(2,3);

    printf("add:%d\n",getValue(add, 10, 6));
    printf("sub:%d\n",getValue(sub, 10, 6));


    startDownload();
    return 0;
}

#ifndef PFGTHREAD_H
#define PFGTHREAD_H


class PFGThread
{
    public:
        PFGThread();
        virtual ~PFGThread();
        void func1();
        void func2();

    protected:

    private:
        double member1;
        int member2;
};

#endif // PFGTHREAD_H

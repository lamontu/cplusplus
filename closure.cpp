#include <stdio.h>

class Closure
{
public:
    virtual ~Closure() {}
    virtual void Run() {}
protected:
    Closure() {} //构造函数是protected，只能被子类调用
};

// 运行函数不含参数
template<class T>
class Callback0 : public Closure
{
public:
    typedef void (T::*Done)();
public:
    Callback0(T *obj, Done run) : object_(obj), run_(run) {}

    virtual void Run()
    {
        (object_->*run_)();
    }
private:
    T *object_;
    Done run_;
};

// 运行函数带有一个参数
template<class T, class T1>
class Callback1 : public Closure
{
public:
    typedef void (T::*Done)(T1);

public:
    Callback1(T *obj, Done run, T1 arg)
        : object_(obj)
        , run_(run)
        , arg0_(arg)
    {
    }

    virtual void Run()
    {
        (object_->*run_)(arg0_);
    }
private:
    T *object_;
    Done run_;
    T1 arg0_;
};

class Test
{
public:
    void Run0()
    {
        printf("in Test::Run0\n");
    }

    void Run1(int i)
    {
        printf("in Test::Run1, i=%d\n", i);
    }
};

template<class T>
Closure* NewCallback(T *obj, void (T::*member)())
{
    return new Callback0<T>(obj, member);
}

template<class T, class T1>
Closure* NewCallback(T *obj, void (T::*member)(T1), T1 arg)
{
    return new Callback1<T, T1>(obj, member, arg);
}

int main()
{
    Test test;
    Closure *callback0 = NewCallback(&test, &Test::Run0);
    callback0->Run();
    delete callback0;

    Closure *callback1 = NewCallback(&test, &Test::Run1, 1);
    callback1->Run();
    delete callback1;

    return 0;
}

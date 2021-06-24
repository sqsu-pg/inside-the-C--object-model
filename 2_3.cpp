#include <iostream>


class X
{
    public:
        X () {
            std::cout << "调用默认构造函数" << std::endl;
            val_ = 0;
        }
        X(int val)
        {
            val_ = val;
            std::cout << "调用构造函数" << std::endl;
        }
        X(const X& x)
        {
            std::cout << "调用拷贝构造函数" << std::endl;
            val_ = x.val_;
        }
        X& operator=(const X& a)
        {
            val_ = a.val_;
            std::cout << "调用赋值函数" << std::endl;
        }
        ~X()
        {
            std::cout << "调用析构函数" << std::endl;
        } 
    private:
        int val_;
};

//doing 当用类的一个对象去初始化该类的另一个对象（或引用）时系统自动调用拷贝构造函数实现拷贝赋值。
//doing 若函数的形参为类对象，调用函数时，实参赋值给形参，系统自动调用拷贝构造函数。（这里可有可能被编译器优化）
//doing 当函数的返回值是类对象时，系统自动调用拷贝构造函数。（注意会有编译器可能会进行优化，而观察不到拷贝的发生）//!这个与编译器有关


X foo()
{
    X xx;
    return xx;
}

X foo2(const X& x2)//doing 
{
    X xx = x2;//doing 调用拷贝构造函数
    return xx;//?返回的时候调用赋值函数
}

X foo3(const X x3)//doing 生成临时对象的时候调用了拷贝构造函数
{
    return x3;//doing 返回的时候调用了拷贝构造函数
}

int main()
{
    X x1;
    x1 = foo();

    X x2 = x1;

    X x3;
    x3 = foo2(x2);
    // X x3 = foo2(x2);

    X x4;
    x4 = foo3(x1);
    return 0;
}
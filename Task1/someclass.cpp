#include "someclass.h"
#include <new>
#include <iostream>
#include <cstring>

SomeClass::SomeClass()
{
    init();
}

SomeClass::~SomeClass()
{
    destroy();
}

SomeClass::SomeClass(const SomeClass &other)
    :SomeClass()
{
    copy(other);
}

SomeClass &SomeClass::operator=(const SomeClass &other)
{
    destroy();
    init();
    copy(other);
    return *this;
}

SomeClass::SomeClass(SomeClass &&other)
    :x1(other.x1), x2(other.x2)
{
    other.x1 = nullptr;
    other.x2 = nullptr;
}

SomeClass &SomeClass::operator=(SomeClass &&other)
{
    destroy();

    x1 = other.x1;
    x2 = other.x2;

    other.x1 = nullptr;
    other.x2 = nullptr;

    return *this;
}


const char *SomeClass::getX1() const
{
    return x1;
}

const char *SomeClass::getX2() const
{
    return x2;
}

SomeClass SomeClass::create()
{
    SomeClass someClass;
    return someClass;
}

void SomeClass::init()
{
    try {
        x1 = new char[ size1 ];
        x2 = new char[ size2 ];
    } catch (std::bad_alloc) {
        std::cerr << "Need to do something according busines requirements" << std::endl;
    }
}

void SomeClass::destroy()
{
    if (x1)
        delete x1;

    if (x2)
        delete x2;
}

void SomeClass::copy(const SomeClass &other)
{
    if (x1)
        std::memcpy(x1, other.getX1(), size1);

    if (x2)
        std::memcpy(x2, other.getX2(), size2);
}

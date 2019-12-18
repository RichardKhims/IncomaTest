#include "someclass.h"

int main(int argc, char *argv[])
{
    SomeClass *class1 = new SomeClass();
    SomeClass *class2 = new SomeClass(*class1);

    SomeClass class3 = SomeClass::create();
    SomeClass class4 = class3;

    delete class1;
    delete class2;

    return 0;
}

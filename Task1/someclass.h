#ifndef SOMECLASS_H
#define SOMECLASS_H


class SomeClass
{
    const int size1 = 1024;
    const int size2 = 1024 * 1024;
private:
    char *x1 = nullptr;
    char *x2 = nullptr;
public:
    SomeClass();
    ~SomeClass();

    SomeClass(const SomeClass &other);
    SomeClass& operator=(const SomeClass &other);

    SomeClass(SomeClass &&other);
    SomeClass& operator=(SomeClass &&other);

    const char *getX1() const;
    const char *getX2() const;

    static SomeClass create();
private:
    void init();
    void destroy();
    void copy(const SomeClass &other);
};

#endif // SOMECLASS_H

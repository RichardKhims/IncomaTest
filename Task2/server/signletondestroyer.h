#ifndef SIGNLETONDESTROYER_H
#define SIGNLETONDESTROYER_H

template <class T>
class SingletonDestroyer
{
public:
    ~SingletonDestroyer() {
        if (p_instance) delete p_instance;
    }

    void setInstance(T *instance) {
        p_instance = instance;
    }

private:
   T* p_instance = nullptr;
};

#endif // SIGNLETONDESTROYER_H

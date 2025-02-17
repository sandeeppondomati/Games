#ifndef __GENERIC_SINGLETON__GENERATOR__HPP__
#define __GENERIC_SINGLETON__GENERATOR__HPP__ 
#include<mutex>
namespace spgames {
/*
// Generic Singleton generator make sure to keep this as friend of the to be Singleton class
//
*/

template<typename T>
class SingletonGenerator : public T
{
    public:
    template<typename... Args>
    static std::shared_ptr<T> getInstance(Args&&... args)
    {
        if(instance == nullptr)
        {
             std::call_once(flag, create, std::forward<Args>(args)...);
        }
        
        return instance;
    } 
    template<>
    static std::shared_ptr<T> getInstance()
    {
        if(instance == nullptr)
        {
            std::call_once(flag, create<>);
        }
        
        return instance;
    } 

    ~SingletonGenerator()
    {
    }
    
    private:

    template<typename... Args>
    static void create(Args&&... args)
    {
        instance.reset(new T(std::forward<Args>(args)...));
    }

    template<>
    static void create()
    {
        instance.reset(new T());
    }
    
    static std::shared_ptr<T> instance;
    static std::once_flag flag;
};

template<typename T> 
std::shared_ptr<T> SingletonGenerator<T>::instance = nullptr;
template<typename T> 
std::once_flag SingletonGenerator<T>::flag;

}
#endif

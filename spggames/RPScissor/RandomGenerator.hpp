#ifndef __RANDOM_GENERATOR__HPP__
#define __RANDOM_GENERATOR__HPP__ 
#include<memory>
#include<mutex>
#include<random>

namespace spgames {

template<int min,int max>
class RandomGenerator
{
    public:
    int generate()
    {
        return distribution(generator);
    }

    ~RandomGenerator()
    {
    }
    
    private:

    template<typename T>
    friend class SingletonGenerator;

    RandomGenerator()
    {
        generator=std::mt19937(device());
        distribution=std::uniform_int_distribution<int>(min,max);
    }
    
    static std::shared_ptr<RandomGenerator> instance;
    static std::once_flag flag;

    std::random_device device;
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;
    
};
template<int min, int max> 
std::shared_ptr<RandomGenerator<min,max>> RandomGenerator<min,max>::instance = nullptr;
template<int min, int max> 
std::once_flag RandomGenerator<min,max>::flag;
}
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/*
    This method will provaide delete some elements from vector which 
    will has O(1) complexity for everyone elements.
*/

template<typename T>
void quick_remove(std::vector<T>& vec, const std::size_t index)
{
    if(index >= 0 and index < vec.size())
    {
        vec[index] = std::move(vec.back());
        vec.pop_back();
    }
    else
    {
        std::cout << "Bad index \n";
    }
}

template<typename T>
void quick_remove(std::vector<T>& vec, const typename std::vector<T>::iterator itr)
{
    if(itr != vec.end())
    {
        *itr = std::move(vec.back());
        vec.pop_back();
    }
    else
    {
        std::cout << "Bad iterator \n";
    }
}

int main()
{
    std::vector<int> vec{1, 2, 333, 123};
    quick_remove(vec, 3);
    for(const auto& i : vec)
    {
        std::cout << i << "\n";
    }

    std::cout << "\n";

    const auto vecPosition = vec.begin() + 1;
    quick_remove(vec, vecPosition);
    for(const auto& i : vec)
    {
        std::cout << i << "\n";
    }
}
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <set>

struct Person
{
public:
    Person() : age(25), name("JAN"), iq(144.6) {} 

    int age;
    std::string name;
    double iq;
};

template<typename T>
class Addable
{
public:
    Addable(T val) : value{val} {}
    template<typename U>
    T add(U arg) const
    {
        if constexpr(std::is_same_v<T, std::vector<U>>)
        {
            auto copy(value);
            for(auto &i : copy)
            {
                i+= arg;
            }
            return copy;
        }
        else
        {
            return value + arg;
        }
    }
private:
    T value;
};

// fold expressions
template<typename R, typename ... Ts>
auto matches(const R& range, Ts ... ts)
{
    return (std::count(std::begin(range), std::end(range), ts) + ...);
}

template<typename Set, typename ... Ts>
auto insertToSet(Set& set, Ts ... ts)
{
    return (set.insert(ts).second && ...);
}

template<typename T, typename ... Ts>
auto insert_all(std::vector<T>& vec, Ts ... ts)
{
    return (vec.push_back(ts), ...);
}

int main()
{
    // argument pack
    auto [age, name, iq] = Person();
    std::cout << "Age = " << age << " Name = " << name << " iq = " << iq << "\n";

    // If statement with initializer
    if(auto condition(2 == 2); condition)
    {
        std::cout << condition << "\n";
    }
    else
    {
        std::cout << condition << "\n";
    }
    
    // aggregate initialization
    auto x{1}; // x is int
    auto y = {1}; // y is std::initializer_list 

    // default template parameter
    auto tuple = std::tuple(2.0, 3, "C++17");
    std::cout << "Tuple has : " << std::get<0>(tuple) << ", "
                                << std::get<1>(tuple) << ", "
                                << std::get<2>(tuple) << "\n";
    
    // constexpr-if
    std::cout << "Addable<int>{1}.add(2) = " << Addable<int>{1}.add(2) << "\n";
    std::vector<int> vec{1, 2, 3};
    
    std::cout << "std::vector<int> vec{1, 2, 3} ,Addable<std::vector<int>>{vec}.add(2) = ";
    for(const auto i : Addable<std::vector<int>>{vec}.add(2))
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";

    // fold expressions example
    std::cout << "matches(std::vector<int>{1, 2, 3, 4, 5}, 1, 2) = " << matches(std::vector<int>{1, 2, 3, 4, 5}, 1, 2) << std::endl;
    std::cout << "matches(std::string{\"C++\"}, '+') = " << matches(std::string{"C++"}, '+') << std::endl;

    std::set<int> mySet{1, 2, 3};
    std::cout << "Result of insertToSet(mySet, 4, 5, 1) is = " << insertToSet(mySet, 4, 5, 1) << "\n";
    std::cout << "mySet has now: ";
    for(const auto i : mySet)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::vector<int> myVector{1, 2, 3};
    std::cout << "myVector{1, 2, 3}\n";
    insert_all(myVector, 4, 5, 6);
    std::cout << "Vector after insert: ";
    for(const auto i : myVector)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
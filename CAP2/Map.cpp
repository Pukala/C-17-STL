#include <iostream>
#include <functional>
#include <list>
#include <map>

struct Billionaire
{
    std::string name;
    double dollars;
    std::string country;
};

int main()
{
    std::list<Billionaire> billionaires
    {
        {"Bill Gates", 86.0, "USA"},
        {"Warren Buffet", 75.6, "USA"},
        {"Jeff Bezos", 72.8, "USA"},
        {"Amamcio Ortega", 71.3, "Spain"},
        {"Mark Zuckerberg", 56.0, "USA"},
        {"Carlos Slim", 54.5, "Mexic"},
        {"Bermard Arnault", 41.5, "French"},
        {"Liliane Bettencourt", 39.5, "French"},
        {"Wang Jianlin", 31.3, "Chaina"},
        {"Li Ka-shing", 31.2, "Honkong"},
    };

    std::map<std::string, std::pair<const Billionaire, size_t>> mapOfbillionaires;

    for(const auto& b : billionaires)
    {
        auto[iterator, success] = mapOfbillionaires.try_emplace(b.country, b, 1);

        if(!success)
        {
            iterator->second.second += 1;
        }
    }

    for(const auto& [key, value] : mapOfbillionaires)
    {
        const auto& [b, count] = value;

        std::cout << b.country << " has billionaires: " << count
        << ", the richest person is " << b.name << " his wealth is "
        << b.dollars << " billionas USD.\n";
    }
}
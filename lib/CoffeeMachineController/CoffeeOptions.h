#ifndef COFFEEOPTIONS_H
#define COFFEEOPTIONS_H

enum class CoffeeType
{
    NONE,
    ESPRESSO,
    COFFEE
};

enum class StrengthLevel
{
    MILD = 1,
    MEDIUM = 2,
    STRONG = 3
};

enum class SizeLevel
{
    SMALL = 1,
    MEDIUM = 2,
    LARGE = 3
};

struct CoffeeOptions
{
    CoffeeType type = CoffeeType::NONE;
    int quantity = 0;
    StrengthLevel strength = StrengthLevel::STRONG;
    SizeLevel size = SizeLevel::MEDIUM;
};

#endif // COFFEEOPTIONS_H
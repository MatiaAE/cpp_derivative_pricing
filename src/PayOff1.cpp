#include "PayOff1.hpp"
#include <algorithm>

//#include <MinMax.h>
// using namespace std;

PayOff::PayOff(double Strike_, OptionType TheOptionsType_)
:
    Strike(Strike_),TheOptionsType(TheOptionsType_)
{
    
}

double PayOff::operator()(double Spot) const
{
    switch (TheOptionsType)
    {
        case call:
            return std::max(Spot - Strike, 0.0);
        case put:
            return std::max(Strike - Spot,0.0);
        case digitalcall:
            return std::max(std::min(Spot - Strike, 1.0), 0.0);
        default:
            throw("unknow option type found.");
    }
}
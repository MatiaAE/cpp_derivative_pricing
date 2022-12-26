#include "SimpleMC.hpp"
#include<iostream>


int main(){
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    std::cout<< "\nEnter expiry\n";
    std::cin >> Expiry;

    std::cout<< "\nEnter strike\n";
    std::cin >> Strike;

    std::cout<< "\nEnter spot\n";
    std::cin >> Spot;

    std::cout<< "\nEnter vol\n";
    std::cin >> Vol;

    std::cout<< "\nEnter r\n";
    std::cin >> r;

    std::cout<< "\nNumber of paths\n";
    std::cin >> NumberOfPaths;

    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);

    double resultCall = SimpleMonteCarlo2(callPayOff
                            , Expiry
                            , Spot
                            , Vol
                            , r
                            , NumberOfPaths);
                        
    double resultPut = SimpleMonteCarlo2(putPayOff
                            , Expiry
                            , Spot
                            , Vol
                            , r
                            , NumberOfPaths);
    
    std::cout<<"the prices are " << resultCall <<" for the call and " << resultPut <<" for the put\n";

    double tmp;
    std::cin >> tmp;

    return 0;
     
}
#include "Random1.hpp"
#include <iostream>
#include <cmath>

double SimpleMonteCarlo1(double Expiry
                        , double Strike
                        , double Spot
                        , double Vol
                        , double r
                        , unsigned long NumberOfPaths){

    double variance         = Vol*Vol*Expiry;
    double rootVariance     = sqrt(variance);
    double itoCorrection    = -0.5 * variance;

    double movedSpot = Spot * (std::exp(r*Expiry + itoCorrection));
    double thisSpot;
    double runningSum{0.0};
    double thisPayoff{0.0};

    for(unsigned long i=0; i < NumberOfPaths; i++){
        double thisGaussian = getOneGaussianByBoxMuller();
        thisSpot = movedSpot * std::exp(rootVariance* thisGaussian);
        thisPayoff = thisSpot - Strike;
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}

int main(){
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    std::cout<<"\nEnter expiry\n";
    std::cin >> Expiry;

    std::cout<<"\nEnter strike\n";
    std::cin >> Strike;
    
    std::cout<<"\nEnter spot\n";
    std::cin >> Spot;

    std::cout<<"\nEnter vol\n";
    std::cin >> Vol;

    std::cout<<"\nEnter r\n";
    std::cin >> r;

    std::cout<<"\nEnter Number of Paths\n";
    std::cin >> NumberOfPaths;

    double result = SimpleMonteCarlo1(Expiry
                                    , Strike
                                    , Spot
                                    , Vol
                                    , r
                                    , NumberOfPaths);
    
    std::cout<<"The price is " << result << std::endl;
    int blank{0};
    std::cin >>blank;

    return 0;


}
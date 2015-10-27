#include "evaluator.hpp"
#include "utils.hpp"

using namespace TPL;
using CYTL::UTIL::StaticCheckEQ;

int main()
{
    // Add Testing
    StaticCheckEQ< Add< Int<1>, Int<3> >::value, Int<4> >();
    StaticCheckEQ< Add< Int<-9>, Int<45> >::value, Int<36> >();


    // Comparing Testing
    StaticCheckEQ< IsGreater< Int<5>, Int<8> >::value, Bool<false> >();
    StaticCheckEQ< IsLess< Int<5>, Int<8> >::value, Bool<true> >();
    StaticCheckEQ< IsEqual< Int<8>, Int<8> >::value, Bool<true> >();


    // Pair Testing
    typedef Pair< Pair< Int<4>, Bool<true> >,
                  Pair< Pair<Int<2>, Unit>, 
                        Bool<false> > > 
            P;
    StaticCheckEQ< Fst< Fst<P>::value >::value, Int<4> >();
    StaticCheckEQ< Snd< Fst< Snd<P>::value >::value >::value, Unit >();
    StaticCheckEQ< Snd< Snd<P>::value >::value, Bool<false> >();


    // List Testing
    StaticCheckEQ< ListRef< List< Int<0>, Int<1>, Int<2>, Int<3> >, Int<2> >::value,
                   Int<2> >();
    StaticCheckEQ< ListRef< List< Int<3> >, Int<0> >::value, Int<3> >();

    typedef List< List< Int<2>, Bool<false> >, 
                  List< Int<2>, Bool<true> >, 
                  List< Int<4> > >  
            L1;
    StaticCheckEQ< ListRef< ListRef< L1, Int<1> >::value, Int<1> >::value, Bool<true> >();
    StaticCheckEQ< ListRef< ListRef< L1, Int<2> >::value, Int<0> >::value, Int<4> >();


    // if-then-else Testing
    StaticCheckEQ< If_Then_Else< IsGreater< Int<5>, Int<8> >::value,
                                 L1,
                                 P>::value,
                    P >();
    StaticCheckEQ< If_Then_Else< IsLess< Int<5>, Int<8> >::value,
                                 L1,
                                 P>::value,
                   L1 >();

    return 0;
}
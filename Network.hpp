#include "Neurone.hpp"
#include <array>

#ifndef NETWORK_H
#define NETWORK_H

class Network{
   private: 
      std::vector<Neurone*> neurones_;
   public:
      Network();
      BuildNetwork(unsigned int number_of_neurones, double connection_probability);
      int run(clock,...);
      getNeurones();
 };

#endif

#include "Network.hpp"
using namespace std;

      Network::Network(){}
      
      Network::~Network(){
        //supprimer les neurones
      }
      
      void Network::BuildNetwork(unsigned int number_of_neurones, double connection_probability){
        for(unsigned int i(0);i<number_of_neurones;++i){
          new Neurone n(clock);
	}
	      
      
      vector<Neurone> Network::getNeurones(){
      
      int Network::run(...){
        while (clock<TotalNumberOfTimeIncrement){
			for(auto& n:network.getNeurones()){
				bool spike=n.update(1,clock); //arguments pour neurone::update ??
				if(spike){
					for(auto& connection:n.getConnections()){
						(connection.getPost()).receive(clock+D),connection.getJ());
					}
				}
			}
			clock+=1;
		}
    return 0;
    }

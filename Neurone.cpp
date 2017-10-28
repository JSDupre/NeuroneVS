#include <iostream>
#include "Neurone.hpp"
#include <cmath>
using namespace std;

	Neurone::Neurone (int clock,double Iext)
	:spikeRingBuffer_((int)(D/TimeIncrement)+1),membranePotential_(STANDART_POTENTIAL),localClock_(clock),Iext_(Iext){}
	
	bool Neurone::update(unsigned int const& NumberOfTimeIncrement){
		bool spike(false);
		for(unsigned int i(1);i<=NumberOfTimeIncrement;++i){
				if(membranePotential_>=SpikeThreshold)
				{
					//1 we store the spike time
					SpikesTimeInNumberOfTimeIncrement_.push_back(localClock_);
					//2 the neurone goes refractory: the potential fall down to 0
					membranePotential_=RefractoryPotential;
					spike=true;
				} 
				
				else if(not SpikesTimeInNumberOfTimeIncrement_.empty() and (localClock_-SpikesTimeInNumberOfTimeIncrement_.back())<=RefractoryTimeInTimeIncrement) //on regarde le temps ecoulé depuis le dernier spike
				{
					membranePotential_=RefractoryPotential;
				} 
				else
				{
					double NewPotential;
					NewPotential=membranePotential_*exp(-TimeIncrement/Tau)+Iext_*NeuroneResistance*(1-exp(-TimeIncrement/Tau));
					size_t currentIndex(localClock_%(D+1));
					NewPotential+=spikeRingBuffer_[currentIndex]; //on a network
					membranePotential_=NewPotential;
					//reinitialsitation of the ring buffer case
					spikeRingBuffer_[currentIndex]=0.0;
				}
				localClock_+=1;
				}
			
			return spike;
		}
	
	double Neurone::getMembranePotential() const{
		return membranePotential_;
	}

	std::vector<int> Neurone::getSpikesTimeInNumberOfTimeIncrement() const{
		return SpikesTimeInNumberOfTimeIncrement_;
	}
	vector<Connection> Neurone::getConnections() const{
		return connections_;
	}
	void Neurone::setConnections (vector<Connection>& connections){
		connections_=connections;
	}
	void Neurone::receive(int clockPlusDelay,double J){
		size_t storageIndex(clockPlusDelay % (D+1));
		spikeRingBuffer_[storageIndex]+=J;
	}


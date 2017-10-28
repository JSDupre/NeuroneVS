#include <iostream>
#include <vector>
#include "Connection.hpp"
#include "Constants.hpp"

#ifndef NEURONE_H
#define NEURONE_H

class Neurone {
	private:
	double membranePotential_; 
	std::vector<int> SpikesTimeInNumberOfTimeIncrement_; //store the spikes time (a certain number of time incrment)
	int localClock_;                                     //local clock for the neurone (can be incremented before the global simulation clock)
	std::vector<Connection> connections_;                //all the connection the neurone have (s
	std::vector<double> spikeRingBuffer_;		     //used to sum the different J of every presynaptic neurones who has fired after a certain delay D
	double Iext_;					     //Intensity comming from the outside
	
	public:
	Neurone (int clock,double Iext);
	bool update(unsigned int const& NumberOfTimeIncrement);
	double getMembranePotential() const;
	std::vector<int> getSpikesTimeInNumberOfTimeIncrement() const;
	std::vector<Connection> getConnections() const;
	void setConnections (std::vector<Connection> & connections);//const& ?
	void receive(int clockPlusDelay,double J);
};

#endif

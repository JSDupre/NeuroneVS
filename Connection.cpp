#include "Connection.hpp"


    Connection::Connection(Neurone* post,double J)
    :postsynapticNeurone_(post),J_(J){}
    
    Neurone* Connection::getPost(){
      return postsynapticNeurone_;
    }
    double Connection::getJ() const{
      return J_;
    }
	
	Connection::~Connection(){
		//postsynapticNeurone_=nullptr;
	}

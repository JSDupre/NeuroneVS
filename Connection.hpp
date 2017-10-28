
#ifndef CONNECTION_H
#define CONNECTION_H

class Neurone;//predeclaration pour eviter dependance circulaire

class Connection {
  private: 
    Neurone* postsynapticNeurone_;
    double J_; //connection strenght
    
   public:
    Connection(Neurone* post,double J);
    //Connection(Connection const& c)=delete;
    ~Connection();
    Neurone* getPost(); //const?
    double getJ() const;
};
    
#endif

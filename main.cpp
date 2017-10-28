#include <iostream>
#include "Neurone.hpp"
#include <fstream>
#include <iomanip>
#include <vector>
#include "Connection.hpp"
using namespace std;

bool isInIntervalle(double ToTest,double Inf,double Sup){
	bool x(ToTest>=Inf and ToTest<Sup);
	return x;
}
void recordValue(Neurone const& n,double time,ofstream& out)
{
	out<<setprecision(3)<<time<<" "<<n.getMembranePotential()<<endl;
}

double AskUserADouble() {
	//on pourrait checker que l'entrée soit correcte
	double result;
		cin>>result;
	return result;
	}

int main() {
		cout<<"temps de simulation? (ms)"<<endl;
		double Tstop(AskUserADouble());
		int TotalNumberOfTimeIncrement = Tstop/TimeIncrement;//calcul du nombre de pas de simulation (pourrait prendre une valeur max)
		
		/*
		cout<<"entrez borne inf (entre 0 et Tstop)"<<endl;
		double BorneInfIntervalle(AskUserADouble());
		
		cout<<"entrez borne sup (entre borne sup et Tstop)"<<endl;
		double BorneSupIntervalle(AskUserADouble());
		
		cout<<"Input value?"<<endl;
		double Iext(AskUserADouble());
		*/
		ofstream f("values.txt",ios::trunc);//declaration du stream d'ecriture
		/*
		//simulation loop for a single neurone
		for(unsigned int i(0);i<TotalNumberOfIncrement;++i){
			recordValue(n,i*TimeIncrement,f);
			if(isInIntervalle(i*TimeIncrement,BorneInfIntervalle,BorneSupIntervalle)){
				n.update(1,Iext,0.0);
			}
			else {
				n.update(1,0.0,0.0);
			}
		}
		*/
		int clock(0);
		//loop for two or more neurone
	//test for 2 neurons
		Neurone n1(clock,5);
		Neurone n2(clock,0.0);
		vector<Neurone> network;
		network.push_back(n1);
		network.push_back(n2);
		Neurone* ptr(&n2);
		//cerr<<(*ptr).getMembranePotential()<<endl;//ca a l'air de marcher
		Connection c(ptr,0.01);
		vector<Connection> co;
		co.push_back(c);
		if(not co.empty()){cerr<<"pas vide"<<endl;}
		n1.setConnections(co);
		if(not (n1.getConnections()).empty()){cerr<<"pas vide"<<endl;}
		//cerr<<(((n1.getConnections())[0]).getPost())->getMembranePotential()<<endl;
	//fin initialisations
		while (clock<TotalNumberOfTimeIncrement){
			for(auto& n:network){ //for(auto& n:network.getNeurones())
				bool spike(n.update(1)); //arguments pour neurone::update ?? Iext?
				if(spike){
					cerr<<"SPIKE"<<endl;
					for(auto& connection:n.getConnections()){
						cerr<<"boucle"<<endl;
						(connection.getPost())->receive((clock+D),connection.getJ());
					}
				}
			}
			recordValue(n1,clock*TimeIncrement,f);//record
			clock+=1;
		}
			
		
		return 0;
	}

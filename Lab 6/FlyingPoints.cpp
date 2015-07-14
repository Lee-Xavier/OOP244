//FlyingPoints.cpp

#include <iostream>
#include "FlyingPoints.h"
using namespace std;

FlyingPoints::FlyingPoints(){
 in=0;
 out=0;
}

FlyingPoints::FlyingPoints(int i, int o){
 in=i;
 out=o;
}

void FlyingPoints::updateBalance(){

	if(in > out)
	{
	in-=out;
	out=0;
	}
	else 
	{
	out-=in;
	in=0;
	}
}

void FlyingPoints::display() const {
 cout << in << " points available to fly." << endl << out << " points available to spent." << endl;
}

FlyingPoints& FlyingPoints::operator +=(const FlyingPoints& f) {
 in= in + f.in;
 out= out + f.out;
 updateBalance();
 return *this;
}

FlyingPoints operator +(const FlyingPoints& lhs, const FlyingPoints& rhs) {
 FlyingPoints result= lhs; 
 result += rhs;
 return result;
}

bool operator == (const FlyingPoints& lhs, const FlyingPoints& rhs) {
 	
	FlyingPoints leftHS=lhs;
	FlyingPoints rightHS=rhs;

	leftHS.updateBalance();
	rightHS.updateBalance();

   if (leftHS.in==rightHS.in && leftHS.out==rightHS.out)

	return true;
	else 
	return false;
}	



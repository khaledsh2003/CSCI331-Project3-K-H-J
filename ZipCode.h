// deltext.h
// Copyright 1997, Gregory A. Riccardi

#include <iostream>
#include "Buffer.h"
using namespace std;
#ifndef ZIPCODE_H
#define ZIPCODE_H
    
class ZipCode 
{
  public:
	char Zipcode [1100];
	char PlaceName [1100];
	char State [1100];
	char County [1100];
	char Latitude [1100];
	char Longtitude [1100];
    
	ZipCode ();
    void Print (ostream &);
	void Clear ();
	int Unpack (DelimBuffer &);
};
#endif

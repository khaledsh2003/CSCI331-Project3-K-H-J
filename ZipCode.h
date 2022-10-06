/**
   
/*@file name: ZipCode.h */

#include <iostream>
#include "Buffer.h"
using namespace std;
#ifndef ZIPCODE_H
#define ZIPCODE_H
    
class ZipCode 
{
  public:
  	/** zip code */                                      
	char Zipcode [1100];
	/** place name */                                      
	char PlaceName [1100];
	/** state */                                      
	char State [1100];
	/** county */                                      
	char County [1100];
	/** latitude */                                      
	char Latitude [1100];
	/** longtitude */                                      
	char Longtitude [1100];
    
	/** Initializes the ZipCode
        /* @pre None
        /* @post clears ZipCode*/
	ZipCode ();

	/** Clears zipcode, sets data members to 0
        /* @pre None
        /* @post sets data members to 0*/
	void Clear ();

	/** unpacks buffer to zipcode data members
        /* @pre DelimBuffer
        /* @post unpacks buffer to zipcode data members*/
	int Unpack (DelimBuffer &);
};
#endif

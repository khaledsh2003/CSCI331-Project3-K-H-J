/**
   
/*@file name: ZipCode.cpp */


#include "ZipCode.h"

/// @brief clears zipCode data members
ZipCode::ZipCode ()
{
	Clear ();
}

/// @brief clears zipCode data members
void ZipCode::Clear ()
{
	Zipcode [0]=0;
	PlaceName [0]=0;
	State [0]=0;
	County [0]=0;
	Latitude [0]=0;
	Longtitude [0]=0;
}

/// @brief unpacks buffer to zipcode data members
/// @param Buffer 
/// @return failing or passing of unpacking
int ZipCode::Unpack (DelimBuffer & Buffer)
{
	int result;
	result = Buffer . Unpack (Zipcode);
	result = result && Buffer . Unpack (PlaceName);
	result = result && Buffer . Unpack (State);
	result = result && Buffer . Unpack (County);
	result = result && Buffer . Unpack (Latitude);
	result = result && Buffer . Unpack (Longtitude);
	return result;
}






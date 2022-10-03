#include "ZipCode.h"


ZipCode::ZipCode ()
{
	Clear ();
}

void ZipCode::Clear ()
{
	Zipcode [0]=0;
	PlaceName [0]=0;
	State [0]=0;
	County [0]=0;
	Latitude [0]=0;
	Longtitude [0]=0;
}

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
void ZipCode::Print (ostream & stream)
{
	stream << "Person:"
		<< "\t Last Name '"<<Zipcode<<"'\n"
		<< "\tFirst Name '"<<PlaceName<<"'\n"
		<< "\t   Address '"<<State<<"'\n"
		<< "\t      City '"<<County<<"'\n"
		<< "\t     State '"<<Latitude<<"'\n"
		<< "\t  Zip Code '"<<Longtitude<<"'\n" <<flush;
}





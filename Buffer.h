#include <iostream>
using namespace std;
#ifndef BUFFER_H
#define BUFFER_H
    

class DelimBuffer 
{ 
    public:
	    DelimBuffer (char delim = ',', int maxBytes = 10000);    
	    void Clear ();
	    int Read (istream &);
	    int Unpack (char *); 
	    void Print (ostream &) const;
 	    int Init (char delim, int maxBytes = 1000);
    private:
	    char Delim;
	    char DelimStr[2];
	    char * Buffer;
	    int BufferSize;
	    int MaxBytes; 
	    int NextByte; 
};
#endif

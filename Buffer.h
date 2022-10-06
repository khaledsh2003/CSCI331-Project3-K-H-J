/**
   
/*@file name: Buffer.h */

#include <iostream>
using namespace std;
#ifndef BUFFER_H
#define BUFFER_H
    
class DelimBuffer 
{ 
    public:
		/** Constructor 
        /* @param takes in the delimiter character and the max bytes
        /* @pre None
        /* @post initializes buffer with the delimiter character and the max bytes */
	    DelimBuffer (char delim = ',', int maxBytes = 10000);
		
		/** Sets the next byte and the buffer size to 0
        /* @pre None
        /* @post Sets the next byte and the buffer size to 0 */  
	    void Clear ();

		/** Reads one record from input stream
        /* @param takes in an input stream
        /* @pre None
        /* @post record read from input stream */
	    int Read (istream &);
		 
		/** extract the value of the next field of the buffer
        /* @param Takes in a character pointer to array
        /* @pre None
        /* @post  value of the next field of the buffer is extracted */
	    int Unpack (char *);
		
		/** Prints the maximun number of bytes and the buffer size
        /* @param Takes in an output stream
        /* @pre None
        /* @post Prints the maximun number of bytes and the buffer size */
	    void Print (ostream &) const;

		/** Initializes the buffer
        /* @param Takes in a delimiter and max bytes
        /* @pre None
        /* @post initializes buffer with the delimiter character and the max bytes */
 	    int Init (char delim, int maxBytes = 1000);
    private:
	    /** delimiter */                                      
	    char Delim;
		/** delimiter array */                                      
	    char DelimStr[2];
		/** buffer array */                                      
	    char * Buffer;
		/** buffer size */                                      
	    int BufferSize;
		/** max bytes */                                      
	    int MaxBytes; 
		/** next byte in buffer */                                      
	    int NextByte; 
};
#endif

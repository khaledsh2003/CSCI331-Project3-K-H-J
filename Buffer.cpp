/**
   
/*@file name: Buffer.cpp */

#include "Buffer.h"
#include <string.h>
#include <string> 
#include <cstring>
#include <limits>
#ifndef FALSE
#define FALSE (0)
#define TRUE (1)
#endif

/// @brief takes in the delimiter character and the max bytes
/// @param delim 
/// @param maxBytes 
DelimBuffer :: DelimBuffer (char delim, int maxBytes)
{	Init (delim, maxBytes);}


/// @brief Initializes the buffer
/// @param delim 
/// @param maxBytes 
/// @return intilizing failing or passing
int DelimBuffer :: Init (char delim, int maxBytes)
{
	Delim = delim;
	DelimStr[0] = Delim;
	DelimStr[1] = 0;
	if (maxBytes < 0) maxBytes = 0;
	MaxBytes = maxBytes;
	Buffer = new char[MaxBytes];
	BufferSize = 0;
	return 1;
}

/// @brief Sets the next byte and the buffer size to 0
void DelimBuffer :: Clear ()
{	NextByte = 0; BufferSize = 0;}


/// @brief Reads one record from input stream
/// @param stream 
/// @return failing or passing of reading
int DelimBuffer :: Read (istream & stream) 
{
    char ch;
    string record;
	Clear ();
	if (BufferSize > MaxBytes) return FALSE; // buffer overflow
    getline(stream,record);
    strcpy(Buffer, record.c_str());
    int length=strlen(Buffer);
    BufferSize=length;
	return stream.good ();
}

/// @brief extract the value of the next field of the buffer
/// @param str 
/// @return failing or passing of unpacking
int DelimBuffer :: Unpack (char * str)
{
	int len = -1; // length of packed string
	int start = NextByte; // first character to be unpacked
	for (int i = start; i < BufferSize; i++)
	{
			if (Buffer[i] == Delim) 
			{
                len = i - start;
                break;
            }
			else if(i==BufferSize-1)
			{ 
            	len = i - start;
				len++;
                break;  
			}
	}
	if (len == -1) return FALSE; // delimeter not found
	NextByte += len + 1;
	strncpy (str, &Buffer[start], len);
	str [len] = 0; // zero termination for string 
	return TRUE;
}

/// @brief Prints the maximun number of bytes and the buffer size
/// @param stream 
void DelimBuffer :: Print (ostream & stream) const
{
	stream << "Buffer has max characters "<<MaxBytes<<" and Buffer Size "<<BufferSize<<endl;
}



 

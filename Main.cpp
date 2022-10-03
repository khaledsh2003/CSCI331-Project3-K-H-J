
#include <iostream>
#include <fstream>
#include "Buffer.h"
#include "ZipCode.h"
#include <limits>
#define MAX 40933
int OpenFile(fstream & stream)
{
    stream.open("us_postal_codes.csv", ios::in|ios::binary);
    if (stream.fail())
    {
		cout << "File open failed!" <<endl;
		return 0;
	}
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}
void ReadFile(fstream &file,DelimBuffer &Buff,ZipCode zipCodes[])
{
    int counter=0;
    while(!file.eof())
    {
	    Buff.Read(file);
        zipCodes[counter].Unpack(Buff);
        counter++;
    }
}
int main()
{
    DelimBuffer Buff(',',10000000);
    static ZipCode zipCodes[MAX];
    fstream file;
    int counter=0;
  
    OpenFile(file);
    //reads one records per loop, saves records into buffer, and then loads zipcode array with record from buffer
    ReadFile(file,Buff,zipCodes); 

    //sort records aplhabetically
    ...

    //compute Easternmost (least longitude), Westernmost,Northernmost (greatest latitude), and Southernmost Zip Code for a given state
    ...


    //print info(Table)
    //format:
    //State Easternmost Westernmost Northernmost Southernmost
    ...



    //testing printing
    for(int x=0;x<MAX;x++)
    {
        cout<<"1:"<<zipCodes[x].Longtitude<<endl;
    }
   
    
     
    
 


}
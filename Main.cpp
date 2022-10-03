
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
    const int NUMSTATES = 57;
    DelimBuffer Buff(',',10000000);
    static ZipCode zipCodes[MAX];
    fstream file;
    const string STATE_LIST[NUMSTATES] = {"AA","AK","AL","AP","AR","AZ","CA"
                        ,"CO","CT","DC","DE","FL","FM"
                        ,"GA","HI","IA","ID","IL"
                        ,"IN","KS","KY","LA","MA"
                        ,"MD","ME","MH","MI","MN","MO"
                        ,"MP","MS","MT","NC","ND","NE"
                        ,"NH","NJ","NM","NV","NY"
                        ,"OH","OK","OR","PA","PW","RI"
                        ,"SC","SD","TN","TX","UT"
                        ,"VA","VT","WA","WI","WV","WY"};
  
    OpenFile(file);
    //reads one records per loop, saves records into buffer, and then loads zipcode array with record from buffer
    ReadFile(file,Buff,zipCodes); 

    //sort records aplhabetically

    /*maybe use a 2D array?*/

    //compute Easternmost (least longitude), Westernmost,Northernmost (greatest latitude), and Southernmost Zip Code for a given state
    


    //print info(Table)
    //format:
    //State Easternmost Westernmost Northernmost Southernmost



    //testing printing
    for(int x=0;x<MAX;x++)
    {
        cout<<zipCodes[x].Zipcode<<zipCodes[x].State <<zipCodes[x].County <<zipCodes[x].PlaceName <<zipCodes[x].Latitude <<zipCodes[x].Longtitude <<endl;
    }
   
    


}

#include <iostream>
#include <fstream>
#include "Buffer.h"
#include "ZipCode.h"
#include <iomanip> 
#include <limits>
#define MAX 40933
#define NUMSTATES 57

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
    static ZipCode sortedZipCodes[MAX];
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
   
    int i=0;
    for(int x=0;x<NUMSTATES;x++)
    {
        for(int y=0;y<MAX;y++)
        {
            if(STATE_LIST[x]==zipCodes[y].State)
            {
               sortedZipCodes[i]=zipCodes[y];
               i++;
            }
        }
    }

      

    //computes table
    // Westernmost and Southernmost zipcodes are left not computed guys
    int y=0;
    int counter=0;
    double Easternmost = stof(sortedZipCodes[0].Longtitude);
    double Northernmost = stof(sortedZipCodes[0].Latitude);
    double Westernmost=0;
    double Southernmost=0;
    string EasternmostZipcode="";
    string NorthernmostZipcode="";
    string WesternmostZipcode="";
    string SouthernmostZipcode="";
    for(int x=0;x<NUMSTATES;x++)
    {
        for(y;y<i;y++)
        {
            if(STATE_LIST[x]==sortedZipCodes[y].State)
            {

                counter++;
                if(Easternmost >= stof(sortedZipCodes[y].Longtitude))
                {
                    Easternmost= stof(sortedZipCodes[y].Longtitude);
                    EasternmostZipcode=sortedZipCodes[y].Zipcode;
                }
                if(Northernmost <= stof(sortedZipCodes[y].Latitude))
                {
                    Northernmost = stof(sortedZipCodes[y].Latitude);
                    NorthernmostZipcode=sortedZipCodes[y].Zipcode;
                }
            }
            else
            {
                //print zip codes information
                // guys find a better way to space things out
                cout<<STATE_LIST[x]<<"  "<<EasternmostZipcode<<"  "<<"  "<<NorthernmostZipcode<<"  "<<endl;
                y=counter;
                Easternmost = stof(sortedZipCodes[y].Longtitude);
                Northernmost = stof(sortedZipCodes[y].Latitude);
                break;
            }
        }
    }
}
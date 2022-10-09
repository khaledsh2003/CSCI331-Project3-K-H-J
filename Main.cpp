/**
   
/*@file name: Main.cpp */


#include <iostream>
#include <fstream>
#include "Buffer.h"
#include "ZipCode.h"
#include <iomanip> 
#include <limits>
#define MAX 40933       // number of records
#define NUMSTATES 57    // number of states in the records


/// @brief Opens a file stream for reading and ignore first 3 lines of the csv(header)
/// @param stream 
/// @return passing or failing of reading
int OpenFile(fstream & stream)
{
    stream.open("us_postal_codes.csv", ios::in|ios::binary);
    if (stream.fail())
    {
		cout << "File open failed!" <<endl;
		return 0;
	}
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');       // skip line
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');       
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 1;
}

/// @brief reads a record into a buffer then unpacks buffer to a ZipCode object array
/// @param file 
/// @param Buff 
/// @param zipCodes 
void ReadFile(fstream &file,DelimBuffer &Buff,ZipCode zipCodes[])
{
    int counter=0;
    while(!file.eof())
    {
	    Buff.Read(file);                    //read into buffer
        zipCodes[counter].Unpack(Buff);     //unpack to zipcode
        counter++;
    }
}

/// @brief sorts ZipCode array of records alphabetically
/// @param STATE_LIST 
/// @param zipCodes 
/// @param sortedZipCodes 
void SortRecords(const string STATE_LIST[NUMSTATES],ZipCode zipCodes[MAX],ZipCode sortedZipCodes[MAX])
{
    int i=0;
    for(int x=0;x<NUMSTATES;x++)
    {
        for(int y=0;y<MAX;y++)
        {
            if(STATE_LIST[x]==zipCodes[y].State) // find a state the matches the ordered states array
            {
               sortedZipCodes[i]=zipCodes[y]; // move the state to array in a sorted way
               i++;
            }
        }
    }
}

/// @brief generate a table comprising (using the alphabetical sorted zipCode records array)  IDs, one state
///per row, where for each row the Easternmost (least longitude), Westernmost(greatest longitude),
///Northernmost (greatest latitude), and Southernmost(least latitude) Zip Code in that state 
/// @param STATE_LIST 
/// @param sortedZipCodes 
void print(const string STATE_LIST[NUMSTATES],ZipCode sortedZipCodes[MAX])
{
    int y=0;
    int counter=0;
    // Intialize to find min and max for each zipcode
    double Easternmost = stof(sortedZipCodes[0].Longtitude);
    double Northernmost = stof(sortedZipCodes[0].Latitude);
    double Westernmost= stof(sortedZipCodes[0].Longtitude);
    double Southernmost= stof(sortedZipCodes[0].Latitude);
    string EasternmostZipcode="";
    string NorthernmostZipcode="";
    string WesternmostZipcode="";
    string SouthernmostZipcode="";

    //print formatted table header
    cout
        << left
        << setw(10)
        << "State"
        << left
        << setw(15)
        << "Easternmost"
        << left
        << setw(15)
        << "Westernmost"
        << left
        << setw(15)
        << "Northernmost"
        << left
        << setw(15)
        << "Southernmost"
        << endl;
   
    //loop throught the states array
    for(int x=0;x<NUMSTATES;x++)
    {
        //loop through the records array
        for(y;y<MAX;y++)
        {
            //if matching state is found in the sorted states compute Easternmost, Northernmost,Westernmost,Southernmost
            if(STATE_LIST[x]==sortedZipCodes[y].State)
            {
                
                counter++;
                if(Easternmost >= stof(sortedZipCodes[y].Longtitude))  //least longitude
                {
                    Easternmost = stof(sortedZipCodes[y].Longtitude);
                    EasternmostZipcode=sortedZipCodes[y].Zipcode;
                }
                if(Northernmost <= stof(sortedZipCodes[y].Latitude)) //greatest latitude)
                {
                    Northernmost = stof(sortedZipCodes[y].Latitude);
                    NorthernmostZipcode=sortedZipCodes[y].Zipcode;
                }
                 if(Westernmost <= stof(sortedZipCodes[y].Longtitude))//greatest longitude
                {
                    Westernmost = stof(sortedZipCodes[y].Longtitude);
                    WesternmostZipcode=sortedZipCodes[y].Zipcode;
                }
                if(Southernmost >= stof(sortedZipCodes[y].Latitude))//least latitude
                {
                    Southernmost = stof(sortedZipCodes[y].Latitude);
                    SouthernmostZipcode=sortedZipCodes[y].Zipcode;
                }

                if(counter==MAX) // if reached last state and finished it's computation then print info for state and break
                {
                     cout
                    << left
                    << setw(10)
                    << STATE_LIST[x]
                    << left
                    << setw(15)
                    << EasternmostZipcode
                    << left
                    << setw(15)
                    << WesternmostZipcode
                    << left
                    << setw(15)
                    << NorthernmostZipcode
                    << left
                    << setw(15)
                    << SouthernmostZipcode
                    << endl;
                }

                
            }
            else 
            {
                //if a different state is found in the record then print the previous state information and computations
                 cout
                << left
                << setw(10)
                << STATE_LIST[x]
                << left
                << setw(15)
                << EasternmostZipcode
                << left
                << setw(15)
                << WesternmostZipcode
                << left
                << setw(15)
                << NorthernmostZipcode
                << left
                << setw(15)
                << SouthernmostZipcode
                << endl;
   
                //get the index to reintilize the zipcodes
                y=counter;
                //reintilize the zipcodes
                Easternmost = stof(sortedZipCodes[y].Longtitude);
                Northernmost = stof(sortedZipCodes[y].Latitude);
                Westernmost= stof(sortedZipCodes[y].Longtitude);
                Southernmost= stof(sortedZipCodes[y].Latitude);
                break;
            }
        }
    }
}



int main()
{
    DelimBuffer Buff(',',10000000);
    static ZipCode zipCodes[MAX];          
    static ZipCode sortedZipCodes[MAX];     //sorted zipCode array
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
  
    //open file
    OpenFile(file);
    //reads one records per loop, saves records into buffer, and then loads zipcode array with record from buffer
    ReadFile(file,Buff,zipCodes); 
    //sorts records alpha by state
    SortRecords(STATE_LIST,zipCodes,sortedZipCodes);
    //compute and print Easternmost, Northernmost,Westernmost,Southernmost 
    print(STATE_LIST,sortedZipCodes);

}
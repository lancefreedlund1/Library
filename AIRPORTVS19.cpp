/**************************************************************
CSC100-Lab 6
AIRPORT
FLorin Postelnicu
***************************************************************/
#include<fstream>
#include<iostream>


#include<cstring>
#include<stdio.h>
#include<stdexcept>
#include<cstdlib>
#include<iomanip>

const int SIZE = 100;

struct AIRlines
{
	char Carrier[20];
	int Flight;
	char Arrival;
	char Arrival_Dest_City[20];
	int Published_Time;
	int Actual_Time;

};



void readFlights(AIRlines Flights[], int& flightsCount);//Read the flight information into an array
                                                        //of record structures Flights[]

void writeFlight(AIRlines Flights[], int flightsCount );//This function writes the updated infos back to outflights.txt
                                                        //It should be used prior to exiting the program, or any time
                                                        //the user feals it is necesary

int search(const AIRlines Flights[],int flightsCount, int target);//It locates a flight using the  Flight number
                                                                  // and returns the index of where the flight is
                                                                  //located in the array Flights[].

void deleteFlight(AIRlines Flights[], int& flightsCount, int target);//Prompt the user for the flight number.
                                                                     //Using search() function verify that the flight number
                                                                     //exists, and delete it from the list.
                                                                     //Shift left the array of Flights[], and update the
                                                                     //flightsCount number.

void displayAllFlights(const AIRlines Flights[], int  flightsCount);//Display all flights

void displayADFlights(const AIRlines Flights[], int flightsCount,char Arr_Dep);

void updateFlight(AIRlines Flights[], int flightsCount, int target, int new_time);//Prompt the user for the flight number.
                                                                                  //Prompt the user for the new actual time
                                                                                  //to be stored in the array Flights[].

void addFlight( AIRlines Flights[], int& j);//Prompt the user for the flight number.
                                            //Prompt the user for the remaining flight data
                                            //that is inserted into the first open slot
                                            //at the end of the array Flights[].


void sortFlights (AIRlines Flights[], int flightsCount);// This function sorts ascendengly
                                                          // the array Flights[]
                                                          // by the published time.
void Frame();//Display the Header



int main()
{
	using namespace std;


	// declare variables
	AIRlines Flights[SIZE];           // array of structures

	               // how many flights in the array
    int target, result, newtime;
    char ans, ardep;

    //start the switch

    int choice;
    do
    {
		int flightsCount = 0;
		cout<<endl
		    <<"Choose 1 to display all the flights \n"
		    <<"Choose 2 to add a new flight    \n"
		    <<"Choose 3 to locate a specific flight \n"
		    <<"Choose 4 to delete a specific flight  \n"
		    <<"Choose 5 to update the Actual_Time for a specific flight \n"
		    <<"Choose 6 to display Arrival or Departure (A/D) flights    \n"
		    <<"Choose 7 to write flights to the flight.txt - Done at the end ayway \n"
		    <<"Choose 8 to order ascendengly the array Flights be published time. \n"
		    <<"Choose 9 to terminate. \n";
		    try
		    {
				readFlights(Flights, flightsCount);//read the data from a file "flights.txt"
			}

           catch (runtime_error e)                    // catch handler
	        {

		cerr << "ERROR -- " << e.what() << endl;
	       }


	try
	{

		cin>>choice;
		switch(choice)
		{
			case 1://It sorts Flights[] ascendengly by published time
			       // and, it diplays all flights.
		      {
				  sortFlights(Flights,flightsCount);
				  displayAllFlights(Flights, flightsCount);//display all flights
		        break;
			}
		    case 2 ://Add a new flight if it doesn't exist, and
		            // sortFlights ascendengly by the published time.
		      {
				  addFlight(Flights, flightsCount);//add a new flight to the list
				  sortFlights(Flights, flightsCount);
		        break;
			}
		    case 3:
		    {


		         //The search routine


		do
		{
			cout<<"Enter the Filght number to search for  : ";
			cin>>target;
			result = search(Flights,flightsCount,target);
			if(result == -1)
			   { cout<<target<<"is not on the list.\n";
			   //update the AIRlines Flights
			   }
			else
			   { cout<<target<<"  is stored in array position :"
			        <<result<<endl
			        <<"(Remember : The first position is 0 . )\n";
				}
			cout<<"Search again?(y/n followed by Return):  \n";
			cin>>ans;
		}while((ans !='n')&&(ans!='N'));
		break;
	        }//end case 3


	        case 4:
	        {



		//CASE delete Flight:

		cout<<"Enter the Flight number to be deleted :";
		cin>>target;
		deleteFlight(Flights,flightsCount, target);

		break;
	       }//end case 4


	       case 5:
	       {


	     //CASE update the New Actual Time
		cout<<"Enter the Flight number for Actual Time update  :";
		cin>>target;
		cout<<endl<<" Enter the New Actual Time : ";
		cin>>newtime;
		updateFlight( Flights, flightsCount, target, newtime);
		break;
	      }//end case 5

	       case 6:
	       {



		//CASE of DisplayADFlights

		cout<<"Enter (A/D for Arrival _Departure List of flights  :";
		cin>>ardep;
		Frame();
		displayADFlights(Flights, flightsCount,ardep);
		break;
	     }//end case 6

	       case 7:
	       {

			   writeFlight(Flights, flightsCount);
			   break;
		   }//end case 7

		   case 8:
		   {
			   sortFlights(Flights, flightsCount);
			   break;
		   }

		   case 9:
		   {
			   break;
		   }

		    default:
		   { cout<<"Not a valid choice. \n"
		        <<"Choose again.\n";
			}
	    }//end switch



      }//end try




	catch (runtime_error e)                    // catch handler
	{

		cerr << "ERROR -- " << e.what() << endl;
	}

  } while(choice!=9);//end of do loop
  cout<<"The End!";

	cin.get(); cin.get();

	return 0;
}



//Definitions for functions

void Frame()
{
	using namespace std;

		cout << "***********************************************************************\n"
			<< "*                                                                     *\n"
			<< "*   CARRIER         Flight  Arrival        City    Published   Actual *\n"
			<< "*                           Departure               Time        Time  *\n"
			<< "*                                                                     *\n"
			<< "***********************************************************************\n";
}

void readFlights(AIRlines Flights[], int& i)
{
	using namespace std;
	//create a file pointer
	ifstream inFile;

	//connect to a file
	inFile.open("C:\\Users\\fkastelka\\Desktop\\Borland C++\\Airport\\flights.txt");
	if (inFile.fail())
		throw runtime_error("File not found");  // throw exception --> catch in main()
	else

		//for( int i=0; i < SIZE; i++ )
		while (!inFile.eof())      // keep data in the bounds of the array
		{
			if (i == SIZE)
			throw runtime_error("Too many flights in file");
			else
			{
			// prompt and read each member


			inFile >> Flights[i].Carrier;
			inFile >> Flights[i].Flight;
			inFile >> Flights[i].Arrival;
			inFile >> Flights[i].Arrival_Dest_City;
			inFile >> Flights[i].Published_Time;
			inFile >> Flights[i].Actual_Time;
			inFile.ignore();        // advances 1 character past the last return key
									// to prepare for the next read (cstring)
			i++;        // increment index
		}
	}

	inFile.close();
}
void displayAllFlights(const  AIRlines Flights[], int flightsCount)
{
	using namespace std;
	Frame();


	for (int i = 0; i < flightsCount ; i++)
		printf("%-20s%6d%  4c%  20s%8d%8d\n", Flights[i].Carrier,
			Flights[i].Flight,
			Flights[i].Arrival,
			Flights[i].Arrival_Dest_City,
			Flights[i].Published_Time,
			Flights[i].Actual_Time);

	cout << endl;
}
void addFlight( AIRlines Flights[], int& j)
{
	using namespace std;

	//create a file pointer


	ofstream outFile;
	outFile.open("C:\\Users\\fkastelka\\Desktop\\Borland C++\\Airport\\flights.txt",ios::out | ios::app);
	if (outFile.fail())
		throw runtime_error("File not found");  // throw exception --> catch in main()
	else
	{
		if (j == SIZE)
			throw runtime_error("Too many flights in file");
		// prompt and read each member
		else
		{



			cout << "\n Carrier  :";
			cin>>Flights[j].Carrier;
			outFile<<endl;
			outFile <<left<<setw(20)<<Flights[j].Carrier;

			cout<<"\n Flight Number  :";
			cin>> Flights[j].Flight;
			outFile<<left<<setw(6)<<Flights[j].Flight;

			cout<<"\n Arrival\Departure  :";
			cin>> Flights[j].Arrival;
			outFile<<right<<setw(4)<< Flights[j].Arrival;

			cout<<"\n Arrival Destination City  :";
			cin>>Flights[j].Arrival_Dest_City ;
			outFile<<right<< setw(20)<<Flights[j].Arrival_Dest_City;

			cout<<"\n Published Times  :";
			cin>> Flights[j].Published_Time;
			outFile<< right<<setw(8 )<< Flights[j].Published_Time;

			cout<<"\n Actual Time  :";
			cin>> Flights[j].Actual_Time;
			outFile<<right<<setw(8)<< Flights[j].Actual_Time;
			j++;

		}
	}
	outFile.close();
}//end addFlight

int search(const AIRlines Flights[],int flightsCount, int target)//return the Flight number

{
	int index = 0;
	bool found = false;
	while((!found)&&(index<flightsCount))
	   {
		   if(target== Flights[index].Flight )
	        found = true;
	    else
	        index++;
		}
    if(found)
        return index;
    else
    return -1;
}

void deleteFlight(AIRlines Flights[], int& flightsCount, int target)//use search()
{
	using namespace std;
	int  result, index, i;

		//create a file pointer
		ifstream inFile;

		//connect to a file
		inFile.open("C:\\Users\\fkastelka\\Desktop\\Borland C++\\Airport\\flights.txt");
		if (inFile.fail())
			throw runtime_error("File not found");  // throw exception --> catch in main()
		//else


		ofstream outFile;
		outFile.open("C:\\Users\\fkastelka\\Desktop\\Borland C++\\Airport\\outflights.txt");

		if (outFile.fail())
			throw runtime_error("File not found");  // throw exception --> catch in main()
		else

		{
			if (flightsCount == SIZE)
			throw runtime_error("Too many flights in file");
		}
		//call search() for the number of the flight to be deleted
	result = search(Flights, flightsCount,target);
	if(result ==-1)
	    {throw runtime_error("Flight Number Doesn't exist.");// throw exception --> catch in main()
        }
    else //Shufle the array LEFT
    {
		if(result == flightsCount -1)
		    {flightsCount = flightsCount-1;
	    }

	    else
	    {

	    {for(index = result;index<flightsCount-1;index++)
	        Flights[index]=Flights[index+1];
		}

		flightsCount = flightsCount-1;
	    }
	}//end shufle array


	// Upadate the outflights.txt file
	for(index = 0; index<flightsCount; index++)
{
		    outFile<<endl;
		    outFile <<left<<setw(20)<<Flights[index].Carrier;
		    outFile<<left<<setw(6)<<Flights[index].Flight;
		    outFile<<right<<setw(4)<< Flights[index].Arrival;
		    outFile<<right<< setw(20)<<Flights[index].Arrival_Dest_City;
		    outFile<< right<<setw(8 )<< Flights[index].Published_Time;
		    outFile<<right<<setw(8)<< Flights[index].Actual_Time;


}//end for loop
  //displayAllFlights(Flights, flightsCount);
  writeFlight(Flights, flightsCount);
  outFile.close();
}//end deleteFlight


void updateFlight(AIRlines Flights[], int flightsCount, int target, int new_time) //use search
{
	using namespace std;
	int result;

	result = search(Flights, flightsCount,target);
		if(result ==-1)
		    {throw runtime_error("Flight Number Doesn't exist.");// throw exception --> catch in main()
	        }
    else
      { Flights[result].Actual_Time = new_time;
       Frame();

       printf("%-20s%6d%  4c%  20s%8d%8d\n", Flights[result].Carrier,
	   			Flights[result].Flight,
	   			Flights[result].Arrival,
	   			Flights[result].Arrival_Dest_City,
	   			Flights[result].Published_Time,
			Flights[result].Actual_Time);

       }//end else

	writeFlight(Flights, flightsCount);
}
//writeFlight CASE 7

void writeFlight(AIRlines Flights[], int flightsCount )//Write in, anew all the flights

{
	using namespace std;
	int i;
	ofstream outFile;
   	outFile.open("C:\\Users\\fkastelka\\Desktop\\Borland C++\\Airport\\flights.txt");
   	if (outFile.fail())
   		throw runtime_error("File not found");  // throw exception --> catch in main()
   	else
   	{
   		if (flightsCount == SIZE)
   			throw runtime_error("Too many flights in file");
   		// prompt and read each member
		else
		for(int i=0; i<flightsCount;i++)
		{


						outFile<<endl;
						outFile <<left<<setw(20)<<Flights[i].Carrier;
						outFile<<left<<setw(6)<<Flights[i].Flight;
						outFile<<right<<setw(4)<< Flights[i].Arrival;
						outFile<<right<< setw(20)<<Flights[i].Arrival_Dest_City;
						outFile<< right<<setw(8 )<< Flights[i].Published_Time;
			            outFile<<right<<setw(8)<< Flights[i].Actual_Time;
		}//end for loop
	}//end else
	outFile.close();


}

//DisplayADFlights CASE 6

void displayADFlights(const AIRlines Flights[],int flightsCount, char Arr_Dep)
{
	using namespace std;
	if((Arr_Dep =='a')||(Arr_Dep == 'A'))
	   {
		   for(int i= 0; i<flightsCount;i++)
	      {
			  if(Flights[i].Arrival == 'A')
	            printf("%-20s%6d%  4c%  20s%8d%8d\n",
	                            Flights[i].Carrier,
					   			Flights[i].Flight,
					   			Flights[i].Arrival,
					   			Flights[i].Arrival_Dest_City,
					   			Flights[i].Published_Time,
			                    Flights[i].Actual_Time);

						}//end for loop


		}//end case A
        else
       {

	              for(int i= 0; i<flightsCount;i++)
			      {  if(Flights[i].Arrival == 'D')
			            printf("%-20s%6d%  4c%  20s%8d%8d\n",
			                            Flights[i].Carrier,
							   			Flights[i].Flight,
							   			Flights[i].Arrival,
							   			Flights[i].Arrival_Dest_City,
							   			Flights[i].Published_Time,
					                    Flights[i].Actual_Time);

								}//end for loop

		}//end case D
}


void sortFlights (AIRlines Flights[], int flightsCount)
{
	using namespace std;
	bool mark;
	int i, temp;
	do
	{
		mark = false;
		for(i = 0;i<flightsCount-1;i++)
		{
			if(Flights[i].Published_Time > Flights[i+1].Published_Time)
			{
				mark = true;
				temp = Flights[i].Published_Time;
				Flights[i].Published_Time = Flights[i+1].Published_Time;
				Flights[i+1].Published_Time = temp;

		}//end if


	}//end for loop

	}while(mark);//end do loop
	writeFlight(Flights, flightsCount);


}//end of sortFlights














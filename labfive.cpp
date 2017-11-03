






#include<time.h>
#include <windows.h>
#include <stdio.h>
#include<fstream>
#include<cstdlib>
#include<iostream>

//#include<specstrings.h>



void fill_ups(int a[], int size);


void display_array(int a[], int size);


void square_array(int a[], int  b[], int size);


void replace_last(int a[], int b[], int size);


void shift_right(int a[], int b[], int size);


int count_multiples(int a[], int size,int div); 

// global constatns

const int size = 10;




int main()
{
	srand((unsigned)time(NULL));
	using namespace std;
    int choice;
	int array[10];
	int barray[10];
	fill_ups(array, 10);

	

    cout << "Welcome and description" << endl;

	cout << " Enter chices  - See the list" << endl;
	do
	{
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			//call display array

			
			display_array(array, 10);

			cout << "Enter a new choice";



			break;
		}//end case 1
		case 2:
		{
			//call square_array

			square_array(array, barray, 10);
			//display_array(array, 10);
			//cout << endl;


			break;
		}//end case 2

		case 3:
		{
			//call replace

			break;
		}//end case 3

		case 4:
		{
			//call shift_right
			shift_right(array, barray, 10);

			break;
		}//end case 4

		case 5:
		{
			int div;
			//call count_multiples
			cout << "Please Enter an integer\n "
				<< "Will check how many terms of the array are multiples \n"
				<< "of that number \n" << endl;
			cout << "Integer :";
			cin >> div;
			cout << endl;
			cout<<"The numbers of multiples of "<< div<<" is "<<count_multiples(array, 10, div);
			cout << endl<< endl;


			break;
		}//end case 5


		default:
		{
			break;
		}//end default


		cin >> choice;
		}//end switch
	} while (choice != 5);
	cout << "Thank you";

	
	

	cin.get(); cin.get();
	return 0;
}//end main


void fill_ups(int a[], int size)//Generate the array 
{
	for (int i = 0; i <= 9; i++)
	{
		a[i] = rand() % 100;
	}

}

void display_array(int a[], int size)// display an array
{
	using namespace std;
	

	cout << " [ ";
	int i;
	for (i = 0; i < 9; i++)
	{
		cout << a[i] << ",";
	}
	cout << a[i] << " ] \n"<<endl;
	
}


void square_array(int a[], int  b[], int size)
{
	using namespace std;
	
	

	for (int i = 0; i <= 9; i++)
	{
		b[i] = pow(static_cast<int>(a[i]), 2);
	}
	display_array(a, 10);
	cout << endl;
	display_array(b, 10);
	cout << endl;

}

void replace_last(int a[], int b[], int size)
{
	//No code yet
}


void shift_right(int a[], int b[], int size)
{
	using namespace std;
	int i;

	for (i = 0; i < 9; i++)
	{
		b[i] = a[i + 1];
	}
	b[i] = a[0];
	display_array(a, 10);
	cout << endl;
	display_array(b, 10);
	cout << endl;


}


int count_multiples(int a[], int size,int div)
{ 
	
	int counts = 0;
	for (int i = 0; i < 10; i++)
	{
		if( a[i]% div ==0)
		{
			counts = counts + 1;
		}
	}
	return counts;

}

/*******************************
CSC100AB 39013
Assignments
Lab 5 - Arrays

Florin Postelnicu

11/03/2017
********************************/




#include<time.h>
#include <windows.h>
#include <stdio.h>
#include<fstream>
#include<cstdlib>
#include<iostream>



const int array_size = 10;

void presentation();

void fill_ups(int a[], int size);


void display_array(int a[], int size);


void square_array(int a[], int  b[], int size);


void replace_last(int a[], int b[], int size, int ldg);


void shift_right(int a[], int b[], int size);


int count_multiples(int a[], int size, int div);








int main()
{
	srand((unsigned)time(NULL));
	using namespace std;
	int choice, last_dg;
	int array[array_size];
	int barray[array_size];
	fill_ups(array, array_size);




	do
	{
		cout << "List of options \n" << endl;

		cout << " Enter a choice  \n" << endl;
		presentation();
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			//call display array


			display_array(array, array_size);




			break;
		}//end case 1
		case 2:
		{
			//call square_array

			square_array(array, barray, array_size);
			//display_array(array, 10);
			//cout << endl;


			break;
		}//end case 2

		case 3:
		{
			//call replace
			cout << "Enter the last digit ldg = ";
			cin >> last_dg;
			if((last_dg>=0)&&(last_dg<=9))
			{
				replace_last(array, barray, array_size, last_dg);
			}
			else
			{
			cout<<"You are supposed to enter a DIGIT between 0-9"<<endl;
		    }




			break;
		}//end case 3

		case 4:
		{
			//call shift_right
			shift_right(array, barray, array_size);

			break;
		}//end case 4

		case 5:
		{
			int div;
			//call count_multiples
			cout << "\n "
				<< "Will check how many terms of the array are multiples \n"
				<< " of tha number  div \n" << endl;
			cout <<"div = ";
			cin >> div;
			cout << endl;
			cout << "The numbers of multiples of number " << div << " is :" << count_multiples(array, array_size, div);
			cout << endl << endl;


			break;
		}//end case 5

		case 6:
		{
			break;
		}


		default:
		{
			cout << "You need to enter a positive integer, 1 though 5" << endl;
			break;
		}//end default

        cout<<"Enter another choice :";

		cin >> choice;
		cout<<endl;
		}//end switch

	} while (choice != 6);


	cout << "Thank you";




	cin.get(); cin.get();
	return 0;
}//end main




//Presentation

void presentation()
{
	using namespace std;
	cout << "In this Program you can choose between 6 options: \n\n "
		<<"1 : Display the content of an array \n"
		<<" 2 : Square each element of the  array \n"
		<<" 3 : Replace last digit with a given ldg between 0-9 \n"
		<<" 4 : Shift all contents of the aray one element to the right \n"
		<<" 5 : Choose a  number div ,and count all its multiples among the elements of the array \n"
		<<" 6 : Quit \n";
}

void fill_ups(int a[], int size)//Generate the array
{
	for (int i = 0; i <= size - 1; i++)
	{
		a[i] = rand() % 100;
	}

}

void display_array(int a[], int size)// display an array
{
	using namespace std;


	cout << " [ ";
	int i;
	for (i = 0; i < size - 1; i++)
	{
		cout << a[i] << ",";
	}
	cout << a[i] << " ] \n" << endl;

}


void square_array(int a[], int  b[], int size)
{
	using namespace std;



	for (int i = 0; i <= size - 1; i++)
	{
		b[i] = a[i] * a[i];
	}
	display_array(a, size);
	cout << endl;
	display_array(b, size);
	cout << endl;

}

void replace_last(int a[], int b[], int size, int  ldg)
{
	using namespace std;

	for (int i = 0; i <= size; i++)
	{
		if (a[i] % 10 == ldg)
		{
			b[i] = a[i];
		}
		else
		{
			b[i] = (a[i] / 10) * 10 + ldg;
		}
	}
	display_array(a, size);
	cout << endl << endl;
	display_array(b, size);
	cout << "last digit is :" << ldg << endl;





}


void shift_right(int a[], int b[], int size)
{
	using namespace std;
	int i;

	for (i = 0; i < size - 1; i++)
	{
		b[i] = a[i + 1];
	}
	b[i] = a[0];
	display_array(a, size);
	cout << endl;
	display_array(b, size);
	cout << endl;


}


int count_multiples(int a[], int size, int div)
{

	int counts = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] % div == 0)
		{
			counts = counts + 1;
		}
	}
	return counts;

}
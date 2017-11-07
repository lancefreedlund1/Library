/******************************************************
                       Dice Game

                   FLORIN POSTELNICU

*******************************************************/

//player1_score and Player2_score are the total scores for each player
//turn is a variable used to switch between the two players
//die1, die2 are obvious. All these variables have as scope the function main()


//For each case there is a pair of variables
//Player_turn : keeps the score for the turn for each player, and
// pass : holds the value returned by the function calcPoints
//throughout each case.

//The decision for who rolls first is random!

//You have the option to play EDDIE, the machine by chosing option 'e'
//EDDIE will play as Player1.
//Or you can play one of your friends.
//In this case you need to determine who is Player1, and
//who is Player2.


#include<iostream>
#include<time.h>
#include <windows.h>
#include <stdio.h>
#include<fstream>


void rollDice(int& die1, int& die2);

int calcPoints(int& die1, int& die2);

void Menu_Eddie_Style();

void Eddie_Style(dim[4][8]);

void get_style_explorer(int dim[4][8]);

bool eddie_answers(int dim[4][8], int Player1_score, int Player2_score, int Player1_turn,int  counts, int sty);

void display_results(int a[2], Player1_score, Player2_score);

void read_data(int a[2]);

void save_data(int a[2]);


using namespace std;

int main()
{

	srand((unsigned)time(NULL));


	int a[2] = { 0 };

	Eddie_Style(dim);
	read_dat(a);

	int sty;
	char start;
	
	do {

		get_style_explorer(dim);
		char answer, decision;
		cout << "If you want to play one of your friends, press 'F' \n" << endl;


		cout << "Do you want EDDIE, the machine, to be Player1 ? Press  'E' \n" << endl << endl;

		cin >> decision;
		if (decision == 'e')
		{
			Menu_Eddie_Style();
			cin >> sty;
		}

		int Player1_score = 0, Player2_score = 0, turn, die1, die2, pass1, pass2, counts = 1;

		turn = rand() % 2;

		do
		{

			cout << "Player1 score" << Player1_score << endl;
			cout << "Player2 score" << Player2_score << endl;

			switch (turn)
			{

			case 0://Player 1
			{

				int Player1_turn = 0;
				do
				{
					pass1 = calcPoints(die1, die2);

					if (pass1 == 0)
					{
						Player1_turn = 0;
						cout << "Player1";
						cout << " rolls " << die1 << " and " << die2 << " ."
							<< "Your total for this turn is  " << Player1_turn << endl << endl;
						Sleep(1000 * 2);
						counts = 1;
						break;
					}
					else
					{
						Player1_turn = Player1_turn + pass1;

						cout << "Player1";
						cout << " rolls " << die1 << " and " << die2 << " ."
							<< "Your total for this turn is  " << Player1_turn << endl;
						counts++;
						
						if (decision == 'e')
						{
							if (eddie_answers( dim , Player1_score, Player2_score, Player1_turn, counts,sty))

							{
								answer = 'y';
								Sleep(1000 * 2);

							}
							else
							{
								answer = 'n';
								Sleep(1000 * 2);

							}

						}//end if decision e
						else
						{
							cout << "        Do you want to roll again (Y/N) ? ";
							cin >> answer;
						}

					}//end else

				} while ((answer == 'Y') || (answer == 'y'));//end do lop
				Player1_score = Player1_score + Player1_turn;
				if (Player1_score >= 100)
				{
					break;
				}
				else
				{
					turn = 1;
				}

			}//End case 0

			case 1://Player 2
			{

				int Player2_turn = 0;
				do
				{
					pass2 = calcPoints(die1, die2);

					if (pass2 == 0)
					{
						Player2_turn = 0;

						cout << "Player2";
						cout << " rolls " << die1 << " and " << die2 << " ."
							<< "Your total for this turn is  " << Player2_turn << endl << endl;

						Sleep(1000 * 2);// sleep 2 sec;
						counts = 1;
						break;
					}

					else
					{
						Player2_turn = Player2_turn + pass2;
						cout << "Player2";
						cout << " rolls " << die1 << " and " << die2 << " ."
							<< "Your total for this turn is  " << Player2_turn << endl;
						counts++;
						cout << "        Do you want to roll again (Y/N) ? ";
						cin >> answer;
					}

				} while ((answer == 'Y') || (answer == 'y'));//end do lop
				Player2_score = Player2_score + Player2_turn;
				if (Player2_score >= 100)
				{
					break;
				}
				else
				{
					turn = 0;
				}

			}//End case 1
			}//End switch

		} while ((Player1_score < 100) & (Player2_score < 100));// end do loop

		display_results( a, Player1_score, Player2_score);


		cout << "Do you want to play again (Start/Terminate)  ?";
		cin >> start;

		if (start != 's')
		{
			cout << "Thank you for playing the game" << endl;
			break;
		}


	} while ((start == 's') || (start == 'S'));

	save_data(a);

	cin.get(); cin.get();
	return 0;
}




void rollDice(int& die1, int& die2)
{
	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;
}

int calcPoints(int& die1, int& die2)
{

	int  roll_score;
	rollDice(die1, die2);

	if ((die1 == 1)&(die2 == 1))
		roll_score = 25;
	else if (((die1 == 1)&(die2 != 1)) || ((die1 != 1)&(die2 == 1)))
	{
		roll_score = 0;
	}
	else if (die1 == die2)
	{
		roll_score = 2 * (die1 + die2);
	}
	else
	{
		roll_score = die1 + die2;
	}
	return roll_score;
}


void get_style_explorer(int dim[4][8])

{
	//generate the field for Eddie the EXPLORER
	int c1, c2, c3, c4, c6, c7, c8;




	c1 = rand() % 4 + 13;
	c2 = rand() % 9 + 13;
	c3 = rand() % 24 - 10;
	c4 = rand() % 3 + 3;
	c6 = rand() % 8 + 13;
	c7 = rand() % 3 + 85;
	c8 = rand() % 2 + 2;

	dim[3][0] = c1;
	dim[3][1] = c2;
	dim[3][2] = c3;
	dim[3][3] = c4;
	dim[3][4] = 100;
	dim[3][5] = c6;
	dim[3][6] = c8;
	dim[3][7] = c7;



}

bool eddie_answers(int dim[4][8], int Player1_score, int Player2_score, int Player1_turn, int counts,int sty)
{

	bool cond_1= true, cond_2= true, cond_3 =true, cond_4= true, cond_5= true, cond_6= true, cond_7= true, cond_8= true, condition= true;
	int treshold1, treshold2;

	treshold1 = dim[sty][3];

	treshold2 = dim[sty][6];


	cond_1 = (Player1_turn <= dim[sty][0]);
	cond_2 = ((100 - Player2_score <= dim[sty][1]));
	cond_3 = ((Player2_score - (Player1_turn + Player1_score) >= dim[sty][2]) && cond_4);
	cond_4 = (counts < treshold1);
	cond_5 = (Player1_score + Player1_turn < 100);
	cond_6 = ((Player1_turn < dim[sty][5]) && (cond_4));
	cond_7 = ((Player1_score + Player1_turn > dim[sty][7]) && cond_8);
	cond_8 = (counts < treshold2);

	condition = ((cond_1 || cond_2 || cond_3 || cond_6 || cond_7) && cond_5);




	return condition;
}

void Menu_Eddie_Style()
{

	cout << "Decide what style Eddie should play \n"
	<< "For  CAUTIOUS enter  0 \n"
	<< "For MODERATE  enter  1  \n"
	<< "For AGRESSIVE enter  2  \n"
	<< "For EXPLORER  enter  3 \n";

}

void Eddie_Style(dim[4][8])
{

	int dim[4][8] = {
		{ 13, 13, 13, 3,  100, 18, 3,  87 },
		{ 14, 14, 0,  3,  100, 20, 3,  87 },
		{ 16, 21, -10, 4, 100, 25, 4,  85 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 } };
}

void display_results(int a[2], Player1_score, Player2_score)
{
	if (Player1_score >= 100)
	{

		a[0] ++;
		cout << "Player1 is the winner" << endl;
	}
	else
	{

		a[1]++;
		cout << "Player2 is the winner   " << endl;
	}

	cout << "Wins Player1:   " << a[0] << endl
		<< "Wins Player2:    " << a[1] << endl;

}
void save_data(int a[2])
{
	ofstream out_eddie("file2.txt");
	if (out_eddie.is_open())
	{
		out_eddie << a[0] << endl;
		out_eddie << a[1] << endl;
		//cout << "Writing data into Eddie is a successful " << endl;
	}
	out_eddie.close();
	//cout << a[0] << "   and   " << a[1] << endl;
}
void read_data(int a[2])
{
	ifstream in_eddie("file2.txt");
	in_eddie >> a[0];
	in_eddie >> a[1];
	in_eddie.close();
}
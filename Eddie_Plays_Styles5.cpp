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

//chance_for_one is a variable giving the geometric probability
//of rolling exactly one die of 1 at each new turn.
//If an event E has the probability p(E)= p to occur, then
//the probability that event E occurs n times in a row is p^n.
//Therefore, the probability of having p(Not E) at the turn n, is 1-p^n.

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
//#include<specstrings.h>

void rollDice(int& die1, int& die2);

int calcPoints(int& die1, int& die2);


const int size = 4;


//void get_style(int dim[][7],  int styel);






using namespace std;

int main()
{

	srand((unsigned)time(NULL));
	int c1, c2, c3, c4, c6, c7;

							c1 = rand() % 4 + 13;
							c2 = rand() % 9 + 13;
							c3 = rand() % 24 - 10;
							c4 = rand() % 3 + 2;
							c6 = rand() % 8 + 13;
							c7 = rand() % 3 + 85;


	int a[2] = { 0 };
	int dim[4][8] = {
	   { 13, 13, 13, 3,  100, 18, 3,  87 },
	   { 14, 14, 0,  3,  100, 20, 3,  87 },
	   { 16, 21, -10, 4, 100, 25, 4,  85 },
	   { c1, c2, c3, c4, 100, c6, c4, c7 } };






	/*for (int r = 0; r < 4; r++)
	{


		for (int i = 0; i < 8; i++)
		{
			cout << dim[r][i] << " , ";
		}
		cout << endl;
	}*/



	ifstream in_eddie("file2.txt");
	in_eddie >> a[0];
	in_eddie >> a[1];
	in_eddie.close();






	//int wins_Player1 = 0, wins_Player2=0;
	int sty ;
	char start;
	bool cond_1, cond_2, cond_3, cond_4, cond_5, cond_6, cond_7, cond_8;




	do {

		char answer, decision;
		cout << "If you want to play one of your friends, press 'F' \n" << endl;


		cout << "Do you want EDDIE, the machine, to be Player1 ? Press  'E' \n" << endl << endl;

		cin >> decision;
		if (decision == 'e')
		{
			cout << "Decide what style Eddie should play \n"
				<< "For  CAUTIOUS enter 0 \n"
				<< "For MODERATE  enter 1  \n"
				<< "For AGRESSIVE enter 2  \n"
				<< "For EXPLORING Random EDDIE  enter  3 \n";
			cin >> sty;
		}



		int Player1_score = 0, Player2_score = 0, turn, die1, die2, pass1, pass2, counts = 1;

		double chance_for_one, kar1, kar2;


		turn = rand() % 2;










		chance_for_one = 1 - pow(static_cast<double>(13) / 18, counts);
		cout << "Your chance to roll a single 1 this time is :" << chance_for_one << endl;


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
						chance_for_one = 1 - pow(static_cast<double>(13) / 18, counts);
						cout << "Your chance to roll a single 1 this time is :" << chance_for_one << endl;
						if (decision == 'e')
						{




							//get_style(dim ,  sty);
							//kar1, kar2 are the number of times Eddie should roll

							kar1 = 1 - pow(static_cast<double>(13) / 18.0, dim[sty][3]);

							kar2 = 1 - pow(static_cast<double>(13) / 18.0, dim[sty][6]);



							cond_1 = (Player1_turn <= dim[sty][0]);
							cond_2 = (100 - Player2_score <= dim[sty][1]);
							cond_3 = (Player2_score - (Player1_turn + Player1_score) >= dim[sty][2]);
							cond_4 = (chance_for_one < kar1);
							cond_5 = (Player1_score + Player1_turn < 100);
							cond_6 = (Player1_turn < dim[sty][5]) && cond_4;
							cond_7 = (Player1_score + Player1_turn > dim[sty][7]) && cond_8;
							cond_4 = (chance_for_one < kar2);


							if ((cond_1 || cond_2 || (cond_3 && cond_4) || cond_6 || cond_7) && cond_5)

							{
								answer = 'y';
								Sleep(1000 * 2);
							}
							else
							{
								answer = 'n';
								Sleep(1000 * 2);
							}
						}
						else
						{

							cout << "        Do you want to roll again (Y/N) ? ";
							cin >> answer;
						}

					}


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
						chance_for_one = 1 - pow(static_cast<double>(13) / 18, counts);
						cout << "Your chance to roll a single 1 this time is :" << chance_for_one << endl;

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

		cout << "Do you want to play again (Start/Terminate)  ?";
		cin >> start;

		if (start != 's')
		{
			cout << "Thank you for playing the game" << endl;
			break;
		}






	} while ((start == 's') || (start == 'S'));

	ofstream out_eddie("file2.txt");
	if (out_eddie.is_open())
	{
		out_eddie << a[0] << endl;
		out_eddie << a[1] << endl;
		cout << "Writing data into Eddie is a successful op" << endl;
	}
	out_eddie.close();
	cout << a[0] << "   and   " << a[1] << endl;
	cin.get(); cin.get();
	return 0;
}




void rollDice(int& die1, int& die2)
{
	//srand((unsigned)time(NULL));
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




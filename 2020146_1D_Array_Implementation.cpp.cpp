
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;
char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
void show_board();
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player();
void delay();

void show_board()
{
	cout <<"\t\t\t\t\t\t\t\t" << board[0] <<" | "<<board[1] <<" | "<< board[2]<<endl;
	cout <<  "\t\t\t\t\t\t\t\t---------"<<endl;
	cout <<"\t\t\t\t\t\t\t\t" << board[3] <<" | "<<board[4] <<" | "<< board[5]<<endl;
	cout <<  "\t\t\t\t\t\t\t\t---------"<<endl;
	cout <<"\t\t\t\t\t\t\t\t" << board[6] <<" | "<<board[7] <<" | "<< board[8]<<endl;
	cout <<endl;
}

int main()

{

	cout << "\t\t\t***********************************************************************************\n";
	cout << "\t\t\t*                                                                                 *\n";
	cout << "\t\t\t*                              TIC***TAC***TOE                                    *\n"; 
	cout << "\t\t\t*                                                                                 *\n";
	cout << "\t\t\t***********************************************************************************\n";
	show_board();
	computer_vs_player();
	return 0;
}

void computer_vs_player()
{
	
	string player_name;
	cout << "Enter Your Name : ";
	cin >> player_name;
	while (true)
	{
		system("cls");
		show_board();
		if(count_board('X') == count_board('O'))
		{
			cout << player_name <<"'s Turn. " <<endl;
			get_x_player_choice();
		}
		else
		{
	    	get_computer_choice();
		}
		
		char winner = check_winner();
		if (winner == 'X')
		{
			system("cls");
			show_board();
			cout <<player_name << "  Won The Game." <<endl;
			break;
		}
		else if(winner=='O')
		{
			system("cls");
			show_board();
			cout << "Computer Won the Game. " <<endl;
			break;
		}
		else if (winner == 'D')
		{
			cout << " GAME IS DRAW . " <<endl;
			break;
		}
	}
}

void delay(int a)
{
	int add;
	int time;
	time = a*1000000;
	for(int i=0;i<time;i++)
	{
		add*-i;
		add++;
		add++;
	}
}

void get_computer_choice()
{
	srand(time(0));
	int choice;
	int timer;
	
	cout << "The computer is making its choice." ;
	
	for (int i=0; i<5; i++)
	{
		timer = i + 1;
		cout << timer << " " ;
		delay(14);
	}
	do
	{
		choice = rand()%10;
	}while(board[choice] != ' ');
	board[choice] = 'O';
	system ("CLS");
	
}

void get_x_player_choice()
{
    
	while(true)
	{
		cout << "Select Your Position from (1-9) : ";
		int choice;
		cin >> choice;
		choice--;
		if(choice<0 || choice >8)
		{
			cout << "Please select your choice from (1 - 9) : " << endl;	
		}
		else if(board[choice] != ' ')
		{
		cout << "Please select an Empty Position ."	<<endl;
		}
		else
		{
			board[choice] = 'X';
			break;
		}
		system ("CLS");
	}
}


void get_o_player_choice()
{
	while(true)
	{
		cout << "Select Your Position from (1-9) : ";
		int choice;
		cin >> choice;
		choice--;
		if(choice<0 || choice >8)
		{
			cout << "Please select your choice from (1 - 9) : " << endl;	
		}
		else if(board[choice] != ' ')
		{
		cout << "Please select an Empty Position ."	<<endl;
		}
		else
		{
			board[choice] = 'O';
			break;
		}
	}
}

int count_board(char symbol)
{
	int total = 0;
	for(int i = 0;i<9;i++)
	{
		if (board[i] == symbol)
		total = total + 1;
	}
	return total;
}

char check_winner()
{
	//checking winner in horizontal/rows
	
	if(board[0] == board[1] && board[1] == board[2]&& board[0] !=' ')
		return board[0];
	if(board[3] == board[4] && board[4] == board[5]&& board[3] !=' ')
		return board[3];
	if(board[6] == board[7] && board[7] == board[8]&& board[6] !=' ')
		return board[6];
		
		//columns
	if(board[0] == board[3] && board[3] == board[6]&& board[0] !=' ')
		return board[0];
	if(board[1] == board[4] && board[4] == board[7]&& board[1] !=' ')
		return board[5];
	if(board[2] == board[5] && board[5] == board[8]&& board[2] !=' ')
		return board[2];
		
		//checking winner diagonally
	if(board[0] == board[4] && board[4] == board[8]&& board[0] !=' ')
		return board[0];
	if(board[2] == board[4] && board[4] == board[6]&& board[2] !=' ')
		return board[2];
		
	if(count_board('X') + count_board('O') < 9)	
		return 'C';//continue
	else
		return 'D'; //draw
}



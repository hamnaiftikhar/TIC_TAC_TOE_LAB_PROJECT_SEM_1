#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;
char square[3][3] = {{' ', ' ',' '},{' ', ' ',' '},{' ', ' ',' '}};
void show_board();
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();
int count_square(char symbol);
char check_winner();
void computer_vs_player();
//void delay();

void show_board()
{
	cout <<"\t\t\t\t\t\t\t\t" << square[0][0] <<" | "<<square[0][1] <<" | "<< square[0][2]<<endl;
	cout <<  "\t\t\t\t\t\t\t\t---------"<<endl;
	cout <<"\t\t\t\t\t\t\t\t" << square[1][0] <<" | "<<square[1][1] <<" | "<< square[1][2]<<endl;
	cout <<  "\t\t\t\t\t\t\t\t---------"<<endl;
	cout <<"\t\t\t\t\t\t\t\t" << square[2][0] <<" | "<<square[2][1] <<" | "<< square[2][2]<<endl;
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
		if(count_square('X') == count_square('O'))
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
			cout <<player_name << "Won The Game." <<endl;
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
//
//void delay()
//{
//	int a;
//	int add;
//	int time;
//	time = a*1000000;
//	for(int i=0;i<time;i++)
//	{
//		add*-i;
//		add++;
//		add++;
//	}
//}

void get_computer_choice()
{
		{
			int x=0, y=0;
			do
			{
				srand(time(0));
    		    for (int i = 0; i < 3; i++)
    			{ 				
    				x = rand()%3;	
        			for (int j = 0; j < 3; j++)
        			{
        				y = rand()%3;
        			}
    			}		
			}
			while(square[x][y]!=' ');
			square[x][y] = 'O';
		}
}

void get_x_player_choice()
{
    
	while(true)
		{
			cout << "Select Your Position in from [][] : ";
			int i,j;
			cout<<"enter row number : ";
			cin >> i;
			cout<<"enter column number : ";
			cin >> j;
			if(square[i][j] != ' ')
			{
				cout << "Please select an Empty Position ."	<<endl;
			}
			else
			{
				square[i][j] = 'X';
				break;
			}
		}
	}
		
int count_square(char symbol)
	{
		int total = 0;
		for(int i = 0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if (square[i][j] == symbol)
				total = total +1;
			}
		}
		return total;
	}

char check_winner()
	{
		//checking winner in horizontal/rows	
		if(square[0][0] == square[0][1] && square[0][1] == square[0][2] && square[0][0] !=' ')
			return square[0][0];
		if(square[1][0] == square[1][1] && square[1][1] == square[1][2] && square[1][0] !=' ')
			return square[1][0];
		if(square[1][2] == square[2][0] && square[2][0] == square[2][1] && square[1][2] !=' ')
			return square[1][2];
			
		//checking winner incolumns
		if(square[0][0] == square[1][0] && square[1][0] == square[2][0] && square[0][0] !=' ')
			return square[0][0];
		if(square[0][1] == square[1][1] && square[1][1] == square[2][1] && square[0][1] !=' ')
			return square[0][1];
		if(square[0][2] == square[1][2] && square[1][2] == square[2][2] && square[0][2] !=' ')
			return square[0][1];
			
		//checking winner diagonally
		if(square[0][0] == square[1][1] && square[1][1] == square[2][2] && square[0][0] !=' ')
			return square[0][0];
		if(square[0][2] == square[1][1] && square[1][1] == square[2][0] && square[0][2] !=' ')
			return square[0][1];
			
		if(count_square('X') + count_square('O') < 9)	
		return 'C';//continue
		
		else if (count_square('X') + count_square('O') > 9)
		cout << "ITS A DRAW ." <<endl;
		return 'D'; //draw
	}

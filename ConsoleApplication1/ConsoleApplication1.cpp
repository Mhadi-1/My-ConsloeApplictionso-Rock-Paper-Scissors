
#include <iostream>
#include <string>
#include <cstdlib>
using namespace ::std;

// Stone Game  ;

enum enGameChoice{ Stone = 1 , Paper =2 ,Scissor =3};

struct stGameInfo
{
	enGameChoice enCopmputrChoice;
	enGameChoice enPlayerChoice;
	int RoundTime = 0;
	int ComputerWin = 0 ;
	int PlayerWin = 0 ;
	int Draw = 0 ;
};

string GameChoice(int Choice)
{
	enGameChoice TypeChoice; 
	TypeChoice = enGameChoice(Choice);

	switch (TypeChoice)
	{
	case Stone:
		return "Stone";
		break;
	case Paper:
		return "Paper";
		break;
	case Scissor:
		return "Scissor";
		break;
	default:
		return " Your Choice Is Wrong !!";
		break;
	}
}

int AskForRound(string Massge)
{
	int NumbRound;
	do
	{
	cout << " " << Massge;
	cin >> NumbRound;

	} while (NumbRound < 1 || NumbRound > 10);
	return NumbRound;

}

int CamputerChoice(int From, int To)
{
	int Number = rand() % (To - From + 1) + From;
	return Number;
}

void RecedScreen()
{
	system("cls");
	system("color 0f");
}

string ChickWinner(stGameInfo &Game)
{

	if ( (Game.enPlayerChoice == Stone && Game.enCopmputrChoice == Stone) || ( Game.enPlayerChoice == Paper && Game.enCopmputrChoice == Paper ) || (Game.enPlayerChoice == Scissor && Game.enCopmputrChoice == Scissor))
	{
		Game.Draw++;
		system("color 3f");
		return" No Winner ";
	}
	else if (Game.enPlayerChoice == enGameChoice::Stone && Game.enCopmputrChoice == enGameChoice::Scissor)
	{
		Game.PlayerWin++;
		system("color 2f");
		return" Player Win ";
	}
	else if (Game.enPlayerChoice == enGameChoice::Paper && Game.enCopmputrChoice == enGameChoice::Stone)
	{
		Game.PlayerWin++;
		system("color 2f");
		return" Player Win ";
	}
	else if (Game.enPlayerChoice == enGameChoice::Scissor && Game.enCopmputrChoice == enGameChoice::Paper)
	{
		Game.PlayerWin++;
		system("color 2f");
		return" Player Win ";
	}
	else
	{
		Game.ComputerWin++;
		system("color 4f");
		cout << "\a";
		return" Coputer Win ";
	}
}

void FinalResult(stGameInfo &GameInfo)
{

	cout << "\n" << "-------------------------+++GAME OVER+++---------------------" <<endl;
	cout << "\n" << "-------------------------[ RESULT ]------------------------" << endl;
	cout << "\n" << "\t Game Round   " << GameInfo.RoundTime;
	cout << "\n" << "\t Player Win  " << GameInfo.PlayerWin<< " Time(s)";
	cout << "\n" << "\t Computer Win " << GameInfo.ComputerWin<< " Time(s)";
	cout << "\n" << "\t Draw    " << GameInfo.Draw << " Time(s)";
	cout << "\n\n" << "----------------------------------------------------------" << "\n";

}

void ShowRoundGame(int NumbRound , stGameInfo &GameInfo)
{

	cout << "\n\n";
	cout << "\n" << "\t----------------Round[" << NumbRound << "]---------------" << endl;
	cout << "\n" <<" \t Player Choice Is [" << GameChoice(GameInfo.enPlayerChoice) <<"]";
	cout << "\n" <<" \t Computer Choice Is [" << GameChoice(GameInfo.enCopmputrChoice) <<"]";
	cout << "\n" <<" \t"<<ChickWinner(GameInfo);
	cout << "\n\n"<<"\t----------------------------------------\n\n";

}

stGameInfo StartRound()
{ 
	stGameInfo GameInfo;

	int NumRound = AskForRound(" Please Enter How Many Rounds From 1 To 10: ");
	GameInfo.RoundTime = NumRound;
	RecedScreen();
	int PlayerChoice = 0;
	int ComputerChoice = 0;
	for (int i = 1 ; i <= NumRound; i++)
	{
		cout << "\n\n\t--------- Round[" << i << "] Beginn ------- \n\n";
		PlayerChoice = AskForRound(" Please Choise Stone[1] : Paper[2] : Scisser[3] : ");
		GameInfo.enPlayerChoice = enGameChoice(PlayerChoice);
		ComputerChoice = CamputerChoice(1, 3);
		GameInfo.enCopmputrChoice = enGameChoice(ComputerChoice);
		ShowRoundGame(i, GameInfo);

	}
	return GameInfo;
	
}

void StartGame()
{
	string AskUser = "Y";
	stGameInfo GameInfo;
	do
	{

		GameInfo =  StartRound();
		FinalResult(GameInfo);
		cout <<" \n\n Would You Like To Play Agin [Y] / [y] : ";
		cin >> AskUser;
		RecedScreen();

	} while (AskUser == "Y" || AskUser == "y");
}


int main()
{
	srand(unsigned(time(NULL)));

	StartGame();

}	
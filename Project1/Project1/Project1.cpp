#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enChoice{stone = 1, paper = 2, scissor = 3};

int readNumber() {

	int num;

	do {

		cout << "How many rounds 1 to 10:\n";
		cin >> num;

	} while (num < 1 && num > 10);

	return num;

}

int randomNumber(int from, int to) {

	int number = rand() % (to - from + 1) + from;

	return number;

}

enChoice userChoice() {

	int number;

	do {

		cout << "Your choice: [1]: Stone, [2]: Paper, [3]: Scissors? ";
		cin >> number;

	} while (number < 1 && number > 3);

	if (number == enChoice::stone)
		return enChoice::stone;
	else if (number == enChoice::paper)
		return enChoice::paper;
	else
		return enChoice::scissor;

}

enChoice computerChoice() {

	int number = randomNumber(1, 3);

	if (number == enChoice::stone)
		return enChoice::stone;
	else if (number == enChoice::paper)
		return enChoice::paper;
	else
		return enChoice::scissor;

}

string winner(enChoice uChoice, enChoice cChoice) {

	if (uChoice == enChoice::stone && cChoice == enChoice::stone) {

		return "No winner";

	}

	else if (uChoice == enChoice::stone && cChoice == enChoice::paper) {

		return "Computer";

	}

	else if (uChoice == enChoice::stone && cChoice == enChoice::scissor) {

		return "User";

	}

	else if (uChoice == enChoice::paper && cChoice == enChoice::stone) {

		return "User";

	}

	else if (uChoice == enChoice::paper && cChoice == enChoice::paper) {

		return "No winner";

	}

	else if (uChoice == enChoice::paper && cChoice == enChoice::scissor) {

		return "Computer";

	}

	else if (uChoice == enChoice::scissor && cChoice == enChoice::stone) {

		return "Computer";

	}

	else if (uChoice == enChoice::scissor && cChoice == enChoice::paper) {

		return "User";

	}

	else if (uChoice == enChoice::scissor && cChoice == enChoice::scissor) {

		return "No winner";

	}

}

void colorScreen(string win) {

	if(win == "User")
		system("color 2F");
	else if (win == "Computer") {

		system("color 4F");
		cout << "\a";
	}
	else if(win == "No winner")
		system("color 6F");

}

void NumberOfWins(string win, int& pWon, int& cWon, int& drawTimes) {

	

	if (win == "User")
		pWon++;

	else if (win == "Computer")
		cWon++;

	else if (win == "No winner")
		drawTimes++;


}

void startGame(int num, int& pWon, int& cWon, int& drawTimes) {

	enChoice uChoice;
	enChoice cChoice;

	for (int i = 1; i <= num; i++) {

		cout << "Round [" << i << "] begins:\n";

		uChoice = userChoice();
		cChoice = computerChoice();

		cout << "__________Round [" << i << "] _____________\n";
		cout << "Player1 choice : " << uChoice << endl;
		cout << "Computer choice: " << cChoice << endl;
		cout << "Round winner   : [" << winner(uChoice, cChoice) << "]" << endl;
		colorScreen(winner(uChoice, cChoice));
		NumberOfWins(winner(uChoice, cChoice), pWon, cWon, drawTimes);
		cout << "_________________________________\n";

	}

}

void printResult(int num, int& pWon, int& cWon, int& drawTimes) {

	string finalWinner = "";

	if (pWon > cWon)
		finalWinner = "User";
	else if (pWon < cWon)
		finalWinner = "Computer";
	else
		finalWinner = "No winner";

	cout << "---------------------------------------------------\n";
	cout << "			+++ G a m e O v e r +++\n";
	cout << "---------------------------------------------------\n";

	cout << "_________________ [Game Results ] _________________\n";
	cout << "Game rounds       : " << num << endl;
	cout << "Player 1 won times: " << pWon << endl;
	cout << "Computer won times: " << cWon << endl;
	cout << "Draw times        : " << drawTimes << endl;
	cout << "Final winner      : " << finalWinner << endl;
	cout << "___________________________________________________\n";

}

int main()
{

	system("color 0F");

	bool again;

	int pWon = 0;
	int cWon = 0;
	int drawTimes = 0;

	int num = readNumber();

	startGame(num, pWon, cWon, drawTimes);
	printResult(num, pWon, cWon, drawTimes);

	cout << "Do you want to play again? ";
	cin >> again;

	while (again) {

		system("cls");
		main();

	}

	return 0;
}
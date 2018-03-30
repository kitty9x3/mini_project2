#include <iostream>

using namespace std;

char player;
char boxes[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void draw()
{
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << boxes[0][0] << "  |  " << boxes[0][1] << "  |  " << boxes[0][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << boxes[1][0] << "  |  " << boxes[1][1] << "  |  " << boxes[1][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << boxes[2][0] << "  |  " << boxes[2][1] << "  |  " << boxes[2][2] << endl;
	cout << "     |     |     " << endl << endl;

}

int input()
{
	int count = 0;
	int player_turn = 0;
	bool valid_move; //checks for occupied boxes and whether player action is legal
		do{
			char turn;
			player_turn++;
			player_turn=(player_turn%2)?1:2;
			if(player_turn == 1){
				player = 'X';
			}
			else {
				player = 'O';
			}
				cout << "Player" << player_turn << "'s turn, pick a box with a number: " << endl;
				cin >> turn;

			if (turn == '1' && boxes[0][0] == '1') {
				boxes[0][0] = player;
				valid_move = true;
			} else if (turn == '2' && boxes[0][1] == '2') {
				boxes[0][1] = player;
				valid_move = true;
			} else if (turn == '3' && boxes[0][2] == '3') {
				boxes[0][2] = player;
				valid_move = true;
			} else if (turn == '4' && boxes[1][0] == '4') {
				boxes[1][0] = player;
				valid_move = true;
			} else if (turn == '5' && boxes[1][1] == '5') {
				boxes[1][1] = player;
				valid_move = true;
			} else if (turn == '6' && boxes[1][2] == '6') {
				boxes[1][2] = player;
				valid_move = true;
			} else if (turn == '7' && boxes[2][0] == '7') {
				boxes[2][0] = player;
				valid_move = true;
			} else if (turn == '8' && boxes[2][1] == '8') {
				boxes[2][1] = player;
				valid_move = true;
			} else if (turn == '9' && boxes[2][2] == '9') {
				boxes[2][2] = player;
				valid_move = true;
			} else {
				cout << "Invalid Move, make another one:" << endl;
				valid_move = false;
				count++;
				if (count == 3){
					cout << "ERROR" << endl;
					return 0;
				}
			}
		} while(!valid_move);
	return 1;
		
}

int checkwin()
{
	if (boxes[0][0] == boxes[0][1] && boxes[0][1] == boxes[0][2]){
		draw();
		cout << "WINNER" << endl;
		return 0;
	}
	else if (boxes[1][0] == boxes[1][1] && boxes[1][1] == boxes[1][2]){
		draw();
		cout << "WINNER" << endl;
		return 0;
	}
	else if (boxes[2][0] == boxes[2][1] && boxes[2][1] == boxes[2][2]){
		draw();
		cout << "WINNER" << endl;
		return 0;
	}
	else if (boxes[0][0] == boxes[1][0] && boxes[1][0] == boxes[2][0]){
		draw();
		cout << "WINNER" << endl;
		return 0;
	}
	else if (boxes[0][1] == boxes[1][1] && boxes[1][1] == boxes[2][1]){
		draw();
		cout << "WINNER" << endl;
		return 0;
	}
	else if (boxes[0][2] == boxes[1][2] && boxes[1][2] == boxes[2][2]){
		draw();
		cout << "WINNER" << endl;	
		return 0;
	}
	else if (boxes[0][0] == boxes[1][1] && boxes[1][1] == boxes[2][2]){
		draw();
		cout << "WINNER" << endl;
		return 0;
	}
	else if (boxes[2][0] == boxes[1][1] && boxes[1][1] == boxes[0][2]){
		draw();
		cout << "WINNER" << endl;
		return 0;
	}
	return 1;
}

int main()
{
	int flag;
	int num;
	cout << "1 or 2 players?: ";
	cin >> num;
	if(num == 1){	//one player
		do{
			draw();
			flag = input();
			flag = checkwin();
		} while (flag==1);
	}
	else if (num == 2){	//two players
		do{
			draw();
			flag = input();
			flag = checkwin();
		} while (flag==1);
	}
	else {
		cout << "ERROR" << endl;
	}

	return 0;
}

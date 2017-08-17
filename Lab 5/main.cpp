#include <iostream>
using namespace std;

void clearGame(char board[][3]) {
	// TODO 1: Clear the values in board[][], reset them to a single space ' '
	// board[][] is the 2-D array representing the game board
	int row, col;

		for (row = 0; row < 3; ++row) {
			for (col = 0; col < 3; ++col) {
				board[row][col] = ' ';
			}
		}
}

void printGameBoard(const char board[][3]) {
	// TODO 2: print out the whole game board as shown in the lab instruction page
	// board[][] is the 2-D array representing the game board
	int row, col;
	// Print the content in a tabular structure
		for (row = 0; row < 3; ++row) {

			cout<<"\t";
			for (col = 0; col < 3; ++col) {
				cout<<"|"<<board[row][col]<<"|";
			}
			cout<<endl;
			cout<<"\t"<<"---------"<<endl;
		}

}

bool checkWin(const char board[][3]) {
	// TODO 3: check the condition required for a player to win the game
	// board[][] is the 2-D array representing the game board
int row,column;
for(row=0;row<3;++row){
	for(column=0;column<3;++column){
		if(board[row][column]!=' '){
			if((row==0||row==1||row==2)&&column==0){
			if(board[row][column]==board[row][column+1]&&
			   board[row][column]==board[row][column+2]){
				return true;
			}
			}
			if((column==0||column==1||column==2)&&row==0){
			if(board[row][column]==board[row+1][column]&&
			   board[row][column]==board[row+2][column]){
				return true;}
			}
			if(row==0&&column==0){
			if(board[row][column]==board[row+1][column+1]&&
			   board[row][column]==board[row+2][column+2]){
				return true;
			}
			}
			if(row==0&&column==2){
			if(board[row][column]==board[row+1][column-1]&&
			   board[row][column]==board[row+2][column-2]){
				return true;
			}
			}
		}

		}
	}
return false;}


bool checkDraw(const char board[][3]) {
	// TODO 4: check the condition required for a "Draw"
	int row,col;
for(row=0;row<3;++row){
	for(col=0;col<3;++col){
		if(board[row][col]!='X'&&board[row][col]!='O'){
			return false;
		}

	}
}

return true;
}





int main() {

	char reply;
	int moveX, moveY;
	char gameArray[3][3];
	// You may reassign the currentPlayer variable to 'X' to represent "switching turn"
	char currentPlayer = 'O';

	do {
		cout << "Welcome to the Tic-tac-toe game!" << endl;
		cout << "Please input the coordinate to place a mark on the game board." << endl;
		cout << "Coordinate ranges from Upper Left Corner(0,0) to Lower Right Corner(2,2)." << endl;
		cout << "Coordinates are in Row-major orders, i.e. (1,2) => 2nd row, 3rd column." << endl;
		cout << "e.g. To place a mark on (1,2), the input will be: 1 2" << endl;

		// Setting up the game
		clearGame(gameArray);
		currentPlayer = 'O';


		// Main game loop
		while(true) {
			cout << currentPlayer << "'s turn" << endl;
			cin >> moveX >> moveY;

			// TODO 5: You should complete the following tasks here
			// 1. Check that the input (moveX, moveY) is a valid move and place the mark if it is valid

			while(moveX>2||moveX<0||moveY>2||moveY<0||gameArray[moveX][moveY]=='X'||gameArray[moveX][moveY]=='O'){
			cout<<"Invalid Move! Please enter again!!!"<<endl;
			cin>> moveX >> moveY;
				}
				gameArray[moveX][moveY]=currentPlayer;

			// 2. Print out the game board, you should call the printGameBoard function here
			printGameBoard(gameArray);
			// 3. Check whether one of the player wins or it is a draw (checkWin and checkDraw should be called here)
			if(checkWin(gameArray)){
				cout<<currentPlayer<<" wins!!"<<endl;
				break;
				}
			else if(checkDraw(gameArray)){
			cout<<"It is a draw!"<<endl;
			break;
			}
			// 4. Switch player and go to the next turn
			if (currentPlayer=='O'){
				currentPlayer= 'X';

			}
			else if(currentPlayer=='X'){
				currentPlayer='O';

			}


		}

		cout << "Continue? (y/n)" << endl;
		cin >> reply;
	} while(reply == 'y');

	return 0;}





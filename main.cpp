#include <iostream>

class Cshell {
	public:
	std::string board[3][3];
	bool winnerExists;
	bool isPlayerX;

	Cshell() // constructor
	{
		isPlayerX = true;
		winnerExists = false;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				board[i][j] = " ";
			}
		}
	}
	void cleanBoard()
	{
		isPlayerX = true;
		winnerExists = false;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				board[i][j] = " ";
			}
		}
	}
	int makeMove(int x, int y) // 1-3, 0-2
	{
		x--;y--;
		if( (x>2 || x<0) || (y>2 || y<0) )
		{
			std::cout << "invalid input !!\n";
			return -1;
		}
		if (board[x][y] != " " )
		{
			std::cout << "This box is already used !!\n";
			return -2;
		}

		if(isPlayerX){
			board[x][y] = "X"; // make move
			isPlayerX=false; // flip player
		}
		else{
			board[x][y] = "O";
			isPlayerX=true;
		}
		return 0;
	}
	std::string winner()
	{
		// row check
		for (int i=0;i<3;i++){
			if(board[i][0] != " " && board[i][0] == board[i][1] && board[i][1] == board[i][2])
				return board[i][0];
		}
		// col check
		for (int i=0;i<3;i++){
			if(board[0][i] != " " && board[0][i] == board[1][i] && board[2][i] == board[1][i])
				return board[0][i];
		}
		// diag check
		if(board[0][0] != " " && board[0][0] == board[1][1] && board[2][2] == board[1][1] )
			return board[0][0];
		if(board[0][2] != " " && board[0][2] == board[1][1] && board[2][0] == board[1][1] )
			return board[0][2];

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(board[i][j] == " ")
					return "none";
			}
		}
		return "draw";
	}

	void draw()
	{
		system("cls");
		std::cout << " "<< board[0][0] <<" | "<< board[0][1] <<" | "<< board[0][2] <<" "<<std::endl;
		std::cout << "---|---|---" << std::endl;
		std::cout << " "<< board[1][0] <<" | "<< board[1][1] <<" | "<< board[1][2] <<" "<<std::endl;
		std::cout << "---|---|---" << std::endl;
		std::cout << " "<< board[2][0] <<" | "<< board[2][1] <<" | "<< board[2][2] <<" "<<std::endl;
	}
	void gameP1(){ // 1 player game logic
		cleanBoard();
		while (true){
			draw();
			
			std::string winnerTmp = winner();
			//std::cout << winnerTmp << std::endl;
			if(winnerTmp == "X"){
				std::cout << "The winner is Player X\n";
				break;
			}else if(winnerTmp == "O"){
				std::cout << "The winner is Player O\n";
				break;
			}else if(winnerTmp == "draw"){
				std::cout << "---Draw---\n";
				break;
			}


			int tmpR;
			int tmpC;
			std::cout << "input ROW : ";
			std::cin >> tmpR;
			std::cout << "input COL : ";
			std::cin >> tmpC;
			while(makeMove(tmpR,tmpC) != 0){
				std::cout << "input ROW : ";
				std::cin >> tmpR;
				std::cout << "input COL : ";
				std::cin >> tmpC;
			}

		}
	}
	void menu(){
		while (true){
			std::string cho;
			std::cout << "1. Single Player\n";
			std::cout << "2. Two Player\n";
			std::cout << "x. Exit !!\nChoose your Option : ";
	
			std::cin >> cho;
	
			if ( cho == "1" ){
				gameP1();
			} else if ( cho == "2" ){
				std::cout << "";//gameP2();
			} else if ( cho == "x" || cho == "X" ){
				break;
			} else {
				std::cout << "invalid Choice, plz try again !!\n";
			}
		}
	}
};

int main()
{
	Cshell game;
	game.menu();

	return 0;
}
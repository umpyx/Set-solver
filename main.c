#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum{
	FILLED = 1, 
	SHADED = 2, 
	EMPTY  = 3,

	ORANGE = 1,
	PURPLE = 2,
	GREEN  = 3,

	OVAL 	 = 1,
	DIAMOND  = 2,
	SQUIGGLE = 3
};

typedef struct card{
    int fill;
    int color;
    int shape;
    int number;
} card;

card makeRandomCard(){
	card output = {
		.fill = (rand() % 4) + 1, 
		.color = (rand() % 4) + 1,
		.number = (rand() % 4) + 1,
		.shape = (rand() % 4) + 1
	};
	return output;
}

int isValid (card card1, card card2, card card3){ //TODO: SOMEHOW OPTIMIZE TO BE LESS UGLY
	if (((card1.fill + card2.fill + card3.fill) % 3) == 0){
		if (((card1.color + card2.color + card3.color) % 3) == 0){
			if (((card1.shape + card2.shape + card3.shape) % 3) == 0){
				if (((card1.number + card2.number + card3.number) % 3) == 0){
					return 0;
				}
				else{
					return -4;
				}
			}
			else{
				return -3;
			}
		}
		else{
			return -2;
		}
	}
	else{
		return -1;
	}
}

int main(int argc, char *argv[]){
	srand(time(NULL));

	card board[5][4] = {
		{makeRandomCard(), makeRandomCard(), makeRandomCard(),},
		{makeRandomCard(), makeRandomCard(), makeRandomCard(),},
		{makeRandomCard(), makeRandomCard(), makeRandomCard(),},
		{makeRandomCard(), makeRandomCard(), makeRandomCard(),},
	};

	if (isValid(board[4][3], board[2][3], board[1][2]) == 0){
		printf("We got a match!");
	}
	
	return 0;
}

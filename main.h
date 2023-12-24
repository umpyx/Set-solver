typedef struct card{
    int fill;
    int color;
    int shape;
    int number;
} card;

card makeRandomCard();

int isValid (card, card, card);

int main (int, char*[]);

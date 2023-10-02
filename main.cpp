// Minesweeper Game

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 25

char myBoard[MAXSIZE][MAXSIZE];
bool realBoard[MAXSIZE][MAXSIZE]; 

int boardSize, noOfMines, movesLeft;

void playMinesweeper();
void setDifficulty();
void setMines();
void setBoard();
bool assignMoves();
void openBox(int, int);
int countAdjacentMines(int, int);
bool isValid(int, int);
bool isMine(int, int);
void displayBoard();
void openAdjacentTiles(int, int);
void exposeMines();

int main() {
    playMinesweeper();
    return 0;
}

// Continue the game untill game over
void playMinesweeper() {
    bool gameOver = false;

    setDifficulty();
    setMines();
    setBoard();

    movesLeft = (boardSize * boardSize) - noOfMines;
    
    while (!gameOver) {
        displayBoard();
        if(movesLeft == 0) {
            printf("\n\n!!!! CONGRATS, YOU HAVE WON !!!!");
            return;
        }
        gameOver = !assignMoves();
    }
}

// To set the difficulty of the game
void setDifficulty() {
    int difficulty;
    printf("1. Easy\n2. Normal\n3. Hard\nYour Choice: ");
    scanf("%d", &difficulty);

    switch (difficulty)
    {
    case 1:
        boardSize = 9;
        noOfMines = 10;
        break;
    case 2:
        boardSize = 16;
        noOfMines = 40;
        break;
    case 3:
        boardSize = 24;
        noOfMines = 99;
        break;
    default:
        boardSize = 9;
        noOfMines = 10;
        break;
    }
}

// To randomly place the mines
void setMines() {
    for(int i = 0; i < noOfMines; i++){
        int row = rand() % boardSize;
        int col = rand() % boardSize;
        if(!isMine(row, col))
            realBoard[row][col] = true;
    }              
}

// To initialize the visible board
void setBoard() {
    for(int i = 0; i < boardSize; i++)
        for(int j = 0; j < boardSize; j++)
            myBoard[i][j] = '_';
}

// To assign the user's move
bool assignMoves() {
    bool validMove = false;
    int row, col;

    while (!validMove) {
        printf("\nEnter row and column: ");
        scanf("%d %d", &row, &col);
        validMove = isValid(row, col);
    }
    
    if(isMine(row, col)) {
        printf("Lost\n");
        exposeMines();
        displayBoard();
        return false;
    } 
    
    openBox(row, col);

    return true;
}

// To open the box and checks whether to open adjacent boxes
void openBox(int row, int col) {
    if(!isValid(row, col)) return;
    if(isMine(row, col)) return;

    if(myBoard[row][col] == '_'){
        int count = countAdjacentMines(row,col);
        if(count == 0) {
            myBoard[row][col] = '#';
            openAdjacentTiles(row, col);
        }  
        else
            myBoard[row][col] = count + '0';
    }
    movesLeft--;
}

// To count the adjacent mines of the tile
int countAdjacentMines(int row, int col) {
    int count = 0;
    for(int i = row-1; i <= row+1; i++)
        for(int j = col-1; j <= col+1; j++){
            if(isValid(i,j) && isMine(i,j))
                if(i != row || j != col)
                    count++;
        }
    return count;
}

// To check validity of user's move
bool isValid(int row, int col) {
    return  (row >= 0) && (row < boardSize) &&
            (col >= 0) && (col < boardSize);
}

// To check if the tile is a mine
bool isMine(int row, int col) {
    return (realBoard[row][col]);
}

// To display the Board to the user
void displayBoard() {
    printf("Total Mines: %d \n", noOfMines);
    for(int i = 0; i < boardSize; i++)
        printf("    %d", i);
    printf("\n");
    for(int i = 0; i < boardSize; i++) {
        printf("%d   ", i);
        for(int j = 0; j < boardSize; j++)
            printf("%c    ", myBoard[i][j]);
        printf("\n");
    } 
}

// To open the adjacent tiles
void openAdjacentTiles(int row, int col) {
    for(int i = row-1; i <= row+1; i++)
        for(int j = col-1; j <= col+1; j++)
            if(isValid(i,j) && !isMine(i,j) && myBoard[i][j] == '_')
                if(i != row || j != col)
                    openBox(i, j);
        
}

void exposeMines() {
    for(int i = 0; i < boardSize; i++)
        for(int j = 0; j < boardSize; j++)
            if(realBoard[i][j] == true)
                myBoard[i][j] = 'X';
}

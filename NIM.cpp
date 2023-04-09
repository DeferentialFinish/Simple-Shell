/*
 Modified By : Nicholas Howland
 Last modified : 2/10/2023
 Program purpose : Improve game code supplied.
  NIM improved by
		- Adding new outputs for wins and losses
		- Printing the game rules
		- adding exciting commentary
		- Removing the magic numbers
		- Printing sybols that represent the remaining objects
		- Adding a play again option

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;



void commentary(int stonesRemaining,int player){
// create a commentator voice that says things when there
// is a specific number of stones left in the bucket
        switch(stonesRemaining){
                case 13:
                        cout<<"##############\nComentator: Lucky Number 13, no idea why its lucky one thing is for sure thats whats left in the bucket\n##############\n";
                        break;
                case 9:
                        cout<<"##############\nComentator: Number nine... Number nine... Number nine... thats what we have left in the bucket.\n##############\n";
                        break;
                case 5:
                        cout<<"##############\nComentator: With only 4 stones remaining things could go either way\n##############\n";
                        break;
                case 3:
                        cout<<"##############\nComentator: With 3 stones left, player "<<player<<" must be sure not to blunder\n##############\n";
                        break;
                case 1:
                        cout<<"##############\nComentator: There is only one way out for "<<player<<" and it is defeat\n##############\n";
                        break;
        }
        cout<< "\n";
}


// function to print out a graphic representation of the items remaining
void remainingStonesGraphic(int count){
        for(int i=1; i<=count; i++){
                        if(i%8==0){// if it is the eighth item then print a new line
                                cout << "\n";
                        }
                                cout << "*";// drop an * to represent another item
                }
                cout << "\n";
}

int computerMove(int remainingStones){
        int move=0;
        switch(remainingStones){// make a determiniation about the moves to be made
// do not take the last stone if you dont have to
                case 4:
                        move=3;
                case 3:
                        move=2;
                case 2:
                        move=1;
// by default make a random move
                default:
                        move = rand()%(remainingStones+1) ; // random computer move
        }
        return move;
}

void gameOfNIM(){
        // ---------------- Variable declarations ---------------------
        int num_objects = 23;
        int current_player = 1;
        int move;
        int comments=0;
        char choice=0;
        // ----------- Beginning of the main game loop ----------------
        cout<<"\n                              The game of NIM\n"<<endl;
        cout<<"The rules are simple, there is a bucket of stones and you cannot be the one who draws the"<<endl;
        cout<<"last stone. You may take anywhere from one to three stones from the bucket. Lastly you"<<endl;
        cout<<"must take at least one stone each turn.\n##############\nCommentator: Human makes the first move\n##############\n"<<endl;

        do{
// do the graphics thing and print out the current number of stones both numerically and
// as a graphic representation.
                commentary(num_objects,current_player);
                cout << "stones remaining: " << num_objects << endl;
                remainingStonesGraphic(num_objects);

// Turn for player one
        if (current_player == 1){
                cout << "Player 1 enter your move: ";cin >> move;// input line
                while (move < 1 || move > num_objects){ // get a legal move from the player
                        cout << "Illegal move. \nEnter a new move (1-3): ";
                        cin.clear();cin.ignore();// stop a neverending loop if the user supplys a charicter
                        cin >> move;
                }
        } else {
// Computer turn sequence linked to an above function
                do {
                        move=computerMove(num_objects);
                } while (move < 1 || move > num_objects);
                cout << "Computer removed " << move << endl;
        }

// subtract the selected number of stones from the stone counter then switch players
                num_objects = num_objects - move;
                current_player = (current_player + 1) % 2;
        } while (num_objects > 0);// continue until no more stones are left in the bucket
        // ------------  end of the game loop --------------------------
        if(current_player==0){
                cout << "##############\nComputer: Better luck next time John Connor, your days are numbered...\nget it? because it was a number game\n";
        }else if(current_player=1){
                cout << "##############\nComputer: Player " << current_player << " has proven their intellectual superiority the humans may be worth more than biofuel. Well done Neo.\n";
        }else{ // expect the unexpected, everyone loves an easter egg
                cout << "Hack all the things\n";
        }
        cin.ignore();
        cin.clear();
}

// create a loop function for the game so that it can be initalized as a play once instance
// or a continuous instance.
void loopGame(){
        char choice=0; // intalize the choice storage area
        gameOfNIM();// start the game of NIM
        do{
                cout << "Play another game?(y/n)"; cin >> choice; // ask the user what they want to do
                if(choice ==121){// if y then start the game again
                        gameOfNIM();
                } else if(choice == 110){ // if no then break the loop
                        break;
                } else{// otherwise print out some more clear instructions
                        cout << "Unknown option supplied, enter y to play again and n to stop playing.\n";
        }
//                cin.clear();cin.ignore();// clear the wierd output if it happens
        }while(choice != 121 || choice != 110);

}


// do the main loop
int main()
{
        srand(time(NULL));// intialize the random number generator
        loopGame();

// test computer random moves
/*
        int tempVar=0;
        int upperBound=27;
        int lowerBound=5;
        int max=-1;
        int min=100;
        for(int a=lowerBound; a < upperBound ; a++){
                for(int i=0;i<100000;i++){
                        tempVar = computerMove(a);
                        if(tempVar<min){min=tempVar;}
                        else if(tempVar>max){max=tempVar;}
                }
                if(max != a){
                        cout << "error on value " << a << endl;
                        cout << "       Max value was: " << max << endl;
                        cout << "       Min value was: " << min << endl;
                }
        }
*/

}

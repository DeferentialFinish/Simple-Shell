/*

 Modified By : Nicholas Howland
 Last modified : 3/28/2023
 Program purpose : Create a racing game

    Customize the Game. Pick a theme for your version of the board game (racing game, zombie apocalypse game, etc.). Modify the "game.txt" file with appropriate actions and messages for your new game.
    Add an introduction. Add an introduction to the game that explains the game and the rules for how to play.
    Improve the output. Modify the output in main() and in the print_board() function to make it easier to read the game board. For example, you could add vertical lines |'s between each square.
    Additional Game Variables. Create a new "score" variable for each of the players. This could be an actual score or another variable such as gold, health, fame, etc. As the game progresses, special squares should cause each players' "score" variable to increase and decrease. Change the victory conditions to match the new variable. For example, the game might end when the first player reaches the goal, but the winner is the player with the most gold (and maybe the first player to reach the goal gets some bonus gold making it more likely that the player will win). Alternatively the game might end when the first player's score reaches zero (for example, if the "score" variable is health). Make sure that the introduction explains this clearly.



    To make this change to the program several related changes will have to be made in the code and in the game file.
        The square class will need to be expanded with one additional variable that keeps track of how much a player's "score" changes when they land on that square.
        The action() function will need to be modified so that it correctly changes the player's "score". Or a new function in the square class will need to be created to change a player's "score".
        Each line in the game.txt file will need to be modified to include an additional value that determines how much a player's score changes by.
        The read_board() and set_square() functions will need to be modified to read the additional value out of the game.txt file and correctly store it in the game objects.
        The victory conditions will need to be modified to check the players' scores or possibly to have a player lose if the their score (e.g. health) reaches zero.

## denotes a to do statement

*/


#include<iostream>
 #include<string>
 #include<fstream>
 #include<ctime>
 #include<cstdlib>
 using namespace std;
                            // Declaration of the square class
class square{
  private:
    int move;
    string message;
    char symbol;
  public:
    square();
    void print();
    int action();
    void set(int,char,string);
};
                            // Function Prototypes
void print_board(square[], int, int);
void read_board(square[]);
void check_position(int &);
                           // Global variables
const int board_length = 20;

int main(){
  int current_player = 1, roll;
  int player1_position = 0, player2_position = 0;
  square the_board[board_length];  // declare an array of squares
cout << "You, a space explorer, are on a distant desert planet. You have laneded here to gather data about" << endl;
cout << "this forign world. Unfortunately you had to drop a portion of your supplies in order to reduce the" << endl;
cout << "weight of your ship and land safely. You are not alone on this desert planet and when you land" << endl;
cout << "you are greeted by another research team, from a rival company. You must race them through the " << endl;
cout << "dunes to retrieve your gear or else you will need to request new gear to be sent from the orbit" << endl;
cout << "station. This could take weeks, and give the opposition the time they need to gain an advantage" << endl;
cout << "in the research wars of 2099. There is a large package containing 2 pieces of equipment as well as" << endl;
cout << "3 pieces of equipment scattered along your path from the opposition, it looks like they had a rough" << endl;
cout << "landing too. If you can recover most of the gear you should be able to make progress while " << endl;
cout << "replacement equipment is on its way from orbit.\n\n You will see a progress bar that shows " << endl;
cout << "how close [Y]ou and the [O]pposition are to your research gear as well" << endl;
cout << "as gear and hazards and equipment along the way." << endl;
cout << "* denotes a stray piece of gear" << endl;
cout << "# denotes a sand dune that if you dont jump it then it will stop you in your tracks for one turn." << endl << endl;
cout << "May the race begin!" << endl;
  srand(time(NULL));
  read_board(the_board);
  print_board(the_board,player1_position,1);
  print_board(the_board,player2_position,2);
  do{
      cout<<"\n\n\nPlayer "<<current_player<<" type enter to roll.\n";
      cin.ignore();
      roll = 1 + (rand() % 5);
// ##conditional and string to denote who the current player is

      cout << "Player "<<current_player<<" rolled a "<<roll<<".\n";
      if(current_player == 1){
         player1_position += roll;
         check_position(player1_position);
         player1_position += the_board[player1_position].action();
         check_position(player1_position);
      }
     else{
        player2_position += roll;
        check_position(player2_position);
        player2_position += the_board[player2_position].action();
        check_position(player2_position);
     }
     print_board(the_board,player1_position,1);
     print_board(the_board,player2_position,2);
     current_player = (current_player % 2) + 1;
  }while((player1_position<board_length-1) && (player2_position<board_length-1));
  current_player = (current_player % 2) + 1;
// ##conditional and string to denote who the current player is
  cout << "\nPlayer " << current_player << " Wins!!!\n";
  cin.ignore();
  return 0;
}


void read_board(square b[]){
     ifstream infile;
     infile.open("game.txt");
     int square_number, square_move;
     string square_message;
     char square_symbol;
     while(!infile.eof()){
         infile >> square_number >> square_move >> square_symbol;
         getline(infile,square_message);
         if(square_number < board_length)
               b[square_number].set(square_move,square_symbol,square_message);
     }
}
void print_board(square b[], int player_position, int player_number){
     for(int i = 0; i < board_length; i++){
         if(i != player_position){// changed the if conditional to have brackets
                        cout << "|";
             b[i].print();
                 }
        else{// changed the else conditional to have brackets and change their icon accordingly
                        if(player_number==1){// opposition icon
                                cout << "O";
                        }
                        else if(player_number==2){// your icon
                                cout << "Y";
                        }
                }
    }
    cout << ": Goal\n";// added a : to the goal output
    for(int i = 0; i < board_length; i++)
         cout << "-";
    cout << "\n";
}
void check_position(int &p){
    if(p < 0)
         p = 0;
    if(p >= board_length)
         p = board_length-1;
}
                           // Functions of the class square
square::square(){
     symbol = ' ';
     move = 0;
     message = "";
}
int square::action(){
     cout << message << endl;
     return move;
}
void square::print(){
     cout << symbol;
}
void square::set(int m, char s, string a_message){
     move = m;
     symbol = s;
     message = a_message;
}

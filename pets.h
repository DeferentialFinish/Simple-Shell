#include <iostream>
using namespace std;

class pet{
   private:
      string name;          // private data member
      int hunger;           // private data member
      int happy;            // private data member
	  int health;			// private data member
	  int energy;			// private data member
   public:
      pet();                // constructor
      void play();          // public member function
      void feed();          // public member function
      void print();         // public member function
      int check_health();   // public member function
      void nap();   // public member function
	  string returnName();
	  void interact();
	  void atrophy();
};

pet::pet(){
     hunger = 50;
     happy = 30;
	 health = 50;
	 energy = 50;
     cout << "Pet's name? (One word) ";
     cin >> name;
}

/*Easy way to return the name of the pet your currently dealing with.*/
string pet::returnName(){
	return name;
}

/*Turn based losses*/
void pet::atrophy(){
	hunger+=2;
	happy-=2;
}


/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Fetch (1) \n Roll over (2) \n";
    cout << "Choice : ";cin >> choice;
    switch(choice){
    case(1):
         happy += 10;
         hunger -= 5;
		 energy -= 5;
         health += 15;
         break;
    case(2):
         happy += 5;
         hunger -= 1;
         energy -= 3;
         health += 3;
         break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
	int randomMessage=rand()%4;
	cout << name << ": ";
	switch(randomMessage){
		case 0:
			cout << "\nMMM, Yummy!\n";
			break;
		case 1:
		    cout << "\nOm Nom Nom\n";
			break;
		case 2:
		    cout << "\n*Crunsh Crunsh Crunch*\n";
			break;
		case 3:
		    cout << "\nWell... its edible\n";
			break;
	}
    hunger -=5;
	energy +=5;

}
void pet::nap(){
    cout << "\n"<<name<<" yawns and curls up in a ball on their favorite pillow.\n";
	happy=30;
    energy += 5;
}

/* Member function print(), prints information about a pet. */
void pet::print(){
    cout << "\nYour pet " << name << " is \n";
    cout << "Happy: " << happy << endl;
    cout << "Hunger: " << hunger << endl;
    cout << "Healthyness: " << health << endl;
    cout << "Energy: " << energy << endl;
	cout << "When you look at " << returnName() << "they are doing the following: \n" << endl;
	if(happy <= 10 && happy >=1){
		cout << "		*Head butts you hard*\n\"Pet me.\"" << endl;		
	}else if (happy <= 20 && happy >=11){
		cout << "		*Head butts you lovingly*\n\"I love to be petted.\"" << endl;
	}else if (happy <= 30 && happy >=21){
		cout <<"		*Makes affectionate noises*" << endl;
	}else if (happy <= 40 && happy >=31){
		cout <<"		*Prances about*\n\"Im so loved!\"" << endl;
	}else if (happy <= 50 && happy >=41){
		cout <<"		*Does a flip*\n\"Whoohoo!\"" << endl;
	}else if(happy > 50){
		cout <<"		*Running in circles*\n\"So... happy... to... be... alive!\""<< endl;
	}
	if(hunger <0){
		cout << "\n		*Hack Huuu, Hack Huuuah, Hack Blarg*\n		*Horks their last meal unceremoniously onto the carpet*\n";
		hunger=0;
	}else if (hunger <= 1 && hunger >=10){
		cout << "\n		*Burps*\n		\"Im full.\"" << endl;
	}else if (hunger <= 11 && hunger >=20){
		cout << "\n		\"Not hungry but I could go for a snack.\"" << endl;
	}else if (hunger <= 21 && hunger >=30){
		cout << "\n		\"Snacks?\"" << endl;
	}else if (hunger <= 31 && hunger >=40){
		cout << "\n		\"When is mealtime?\"" << endl;
	}else if (hunger <= 41 && hunger >=50){
		cout << "\n		\"Oh so we are skipping meals now? Do you think I am fat? Because my ribs say otherwise. When is dinner?\"" << endl;
	}
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet, "<< name << ", has starved.\n";
         return 0;
    }
    if(happy <= 0){
         cout << "\nYour pet, "<< name << ", has died of a broken heart.\n";
         return 0;
    }
	if(energy <= 0){
         cout << "\nYour pet, "<< name << ", fell into a coma from exauhstion.\n";
         return 0;
    }
	if(health <=0){
         cout << "\nYour pet, "<< name << ", died of what seemed to be a heart heart attack.\n";
         return 0;
    }
    return 1;
}

void pet::interact(){
	int choice=0;
	if(check_health()==0){
		cout << "Rest in peace " << returnName() << endl;
	} else{
		print();
		do{
			cout << "How would you like to interact with your pet?\n";
			cout << "(1) Play\n(2) Feed\n(3) Nap\n";
			cin >> choice;
			if(choice > 3 || choice <1){
				cout << "Choose a valid option\n";
			}
		} while (choice > 3 || choice <1);
		switch(choice){
			case 1:
				play();
				break;
			case 2:
				feed();
				break;
			case 3:
				nap();
				break;
		}
	}
}

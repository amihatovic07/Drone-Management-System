// This is a starting section in which the main packages are imported so the program can work properly.
// ----------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>
#include <cctype>

using namespace std;

// This is section for structures which are main objects and which will be the concrete padding of this program.
// ----------------------------------------------------------------------------------------------------

struct position{
	double x;
	double y;
	double z;
};
struct status{
	int battery;
	double damage;
	bool crashed;
};
struct drone{
	position positions;
	double speed;
	status statuses;
};

// This section is for the functions which make small block of code that can be implemented inside main function.
// ----------------------------------------------------------------------------------------------------


void title(){
	cout<<"Drone Management System\n";
	cout<<"-----------------------------------\n";
}
void menu1(){
	title();
	cout<<"1. start drone\n";
	cout<<"2. activity log\n";
	cout<<"3. status\n";
	cout<<"4. exit\n";
}
void menu2(){
	title();
	cout<<"1. move\n";
	cout<<"2. rotate\n";
	cout<<"3. position\n";
	cout<<"4. status\n";
	cout<<"5. stop drone\n";
}
void submenu1(){
	title();
	cout<<"W forward\n";
	cout<<"S backward\n";
	cout<<"Q descend\n";
	cout<<"E ascend\n";
}
void submenu2(){
	title();
	cout<<"A left\n";
	cout<<"D right\n";
}

// This section is main function and it represents executable program block which takes in all the content from declarative program block and that way the workflow is properly formulated.
// ----------------------------------------------------------------------------------------------------

int main(){
	
// local variables which are used directly in the work of program
// ---------------------------------------------------------------
	
	string menuChoice, moveChoice, rotationChoice, menu2Choice;
	int currentStatus = 0;
	
// main do while loop of the program which consists of entire program
// -------------------------------------------------------------------
	
	do{
		
// initialized first menu
// -----------------------
		
		menu1();
		
// asked user for input of his choice of functionalities inside program
// ---------------------------------------------------------------------
		
		cout<<"enter your choice: ";
		cin>>menuChoice;
		
// built-in transformation functions which come with algorithm package and which help with reducing redundancy of data
// --------------------------------------------------------------------------------------------------------------------
		
		transform(menuChoice.begin(), menuChoice.end(), menuChoice.begin(), ::tolower);
		
// started forming if and else conditions
// ---------------------------------------
		
		// condition for exiting the program
		// ----------------------------------
		
		if (menuChoice == "4." || menuChoice == "4" || menuChoice == "exit"){
			return 0;
		} 
		
		// condition for second menu which consists of movement and active work of drone
		// ------------------------------------------------------------------------------
		
		else if (menuChoice == "1" || menuChoice == "1." || menuChoice == "start drone" || menuChoice == "start"){
			cout<<"drone started\n";
			do{
				
				// second menu initialized
				// ------------------------
				
				menu2();
				
				// asked user for his choice input
				// --------------------------------
				cout<<"enter your choice: ";
				cin>>menu2Choice;
				transform(menu2Choice.begin(), menu2Choice.end(), menu2Choice.begin(), ::tolower);
				
			// analyzed user input using if and else conditions
			// -------------------------------------------------
				
				// condition for movement
				// -----------------------
				
				if(menu2Choice == "1" || menu2Choice == "1." || menu2Choice == "move"){
					
					// initialized submenu which gives the user options of movement variations
					// ------------------------------------------------------------------------
					
					submenu1();
					
					// initialized do while loop which consists of user input of movement and conditional analysis of each input, if it fits criteria it is printed out and the loop breaks
					// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
					
					do{
						cout<<"where do you want to move: ";
						cin>>moveChoice;
						transform(moveChoice.begin(), moveChoice.end(), moveChoice.begin(), ::tolower);
						if (moveChoice == "w" || moveChoice == "forward"){
							cout<<"moved forward\n";
							break;
						}
						else if (moveChoice == "s" || moveChoice == "backward"){
							cout<<"moved backward\n";
							break;
						}
						else if (moveChoice == "q" || moveChoice == "descend"){
							cout<<"descended\n";
							break;
						}
						else if (moveChoice == "e" || moveChoice == "ascend"){
							cout<<"ascended\n";
							break;
						}
						else {
							cout<<"wrong input, please try again!\n";
							continue;
						}
					} while (true);
					
				}
				
				// condition for rotation
				// -----------------------
				
				else if(menu2Choice == "2" || menu2Choice == "2." || menu2Choice == "rotate"){
					
					// initialized submenu2 which gives user variations of rotations
					// --------------------------------------------------------------
					
					submenu2();
					
					// initialized do while loop which consists of user input of chosen rotation and analysis of the input via if and else conditions, if it fits criteria it is printed and loop breaks
					// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
					
					do{
						cout<<"how do you want to rotate: ";
						cin>>rotationChoice;
						transform(rotationChoice.begin(), rotationChoice.end(), rotationChoice.begin(), ::tolower);
						if (rotationChoice == "a" || rotationChoice == "left"){
							cout<<"rotated left\n";
							break;
						}
						else if (rotationChoice == "d" || rotationChoice == "right"){
							cout<<"rotated right\n";
							break;
						}
						else {
							cout<<"wrong input, please try again!\n";
							continue;
						}
					} while (true);
				}
				
				// condition for printing out current position
				// --------------------------------------------
				
				else if (menu2Choice == "3" || menu2Choice == "3." || menu2Choice == "position"){
					cout<<"current position is: \n";
				}
				
				// condition for printing out current status 
				// ------------------------------------------
				
				else if(menu2Choice == "4" || menu2Choice == "4." || menu2Choice == "status"){
					cout<<"current status is: \n";
				}
				
				// condition for stopping drone activity and returning to first menu
				// ------------------------------------------------------------------
				
				else if(menu2Choice == "5" || menu2Choice == "5." || menu2Choice == "stop" || menu2Choice == "stop drone"){
					cout<<"drone activity stopped\n";
					break;
				}
				
				// end of do while loop
				// ---------------------
				
			} while (true);
		} 
		
		// condition for activity log which will print out whole activity of drone until predisposed date
		// -----------------------------------------------------------------------------------------------
		
		else if (menuChoice == "2" || menuChoice == "2." || menuChoice == "activity" || menuChoice == "activity log"){
			cout<<"Activity: \n";
		} 
		
		// condition for drone status which will print out current status of drone, while it isn't active
		// -----------------------------------------------------------------------------------------------
		
		else if (menuChoice == "3" || menuChoice == "3." || menuChoice == "status"){
			cout<<"Current status of drone is: \n";
		} 
		
		// condition for all other input which isn't covered with any functionality
		// -------------------------------------------------------------------------
		
		else {
			cout<<"wrong choice, please try again\n";
			continue;
		}
		
		// end of do while loop
		// ---------------------
		
	} while (true);
}

#ifndef MENU_HPP
#define MENU_HPP


//Macros for readablity
#define QUIT 'q'
#define WAIT 'w'

#define MENU "========Menu========\n1 Add or Modify\n2 Remove\n3 Show\n\t[Q]uit\n"


class Menu{
	private:
		char action; //Menu action for any input such as 'q' for quit
			
	public:
		Menu(void);
		
		void print(void);
		void getInput(void);	
	
	
		void start(void);

		
		//OPTION 1	
		void addModify(void);
		
		//OPTION 2
		void remove(void);		

		//OPTION 3
		void show(void);		

		//OPTION 4
		void quit(void);

};


Menu::Menu(void){
	action = QUIT;
}


void Menu::print(void){
	std::cout << MENU << '\n';	
}


void Menu::getInput(void){
	//do{
	//	std::cout << action;
		std::cout << "\nOption : ";
		std::cin >> action;
	//	std::cout << '\n' << sizeof(action) << action;
	//	printf("\nsize : %li\naction : %c", sizeof(action), action);
	//}while(action==WAIT);
}


void Menu::start(void){

	action = WAIT;
	
	while(action!=QUIT){
		Menu::print();
		//std::cin >> action;
		Menu::getInput();
		
		switch(action){
			case '1':{
				Menu::addModify();
				break;	
			}
			case '2':{
				Menu::remove();
				break;	
			}
			case '3':{
				Menu::show();
				break;	
			}
			case QUIT:{
				Menu::quit();
				break;
			}
			default:{
				std::cout << "Input unrecognized, try again\n";
			}	
		}
	}
}

		
//OPTION 1	
void Menu::addModify(void){
	std::cout << "Add or Modify chosen\n\n";
}
		
//OPTION 2
void Menu::remove(void){
	std::cout << "Remove chosen\n\n";
}	

//OPTION 3
void Menu::show(void){
	std::cout << "Show students chosen\n\n";
}	

//OPTION 4
void Menu::quit(void){
	std::cout << "\n\tBye ~,~\n";
}


#endif

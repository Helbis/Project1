#ifndef MENU_HPP
#define MENU_HPP


//Macros for readablity
#define QUIT 'q'
#define WAIT 'w'


class Menu{
	private:
		char action; //Menu action for any input such as 'q' for quit
			
	public:
		Menu(void);
		
		void print(void);
		void getInput(void);	
	
	
		void start(void);

		
		//OPTION 1	
		void addStudent(void);
		
		//OPTION 2
		void modify(void);		

		//OPTION 3
		void remove(void);		

		//OPTION 4
		void show(void);		

		//OPTION 5
		void quit(void);

};


Menu::Menu(void){
	action = WAIT;
}


void Menu::print(void){
	std::cout << "Menu\n";
}


void Menu::getInput(void){
	scanf("%c", result);
}


void Menu::start(void){

	do{
		Menu::print();
		Menu::getInput();
	
	}while(action!=QUIT);
}

		
//OPTION 1	
void Menu::addStudent(void){

}
		
//OPTION 2
void Menu::modify(void){
}		

//OPTION 3
void Menu::remove(void){

}	

//OPTION 4
void Menu::show(void){

}	

//OPTION 5
void Menu::quit(void){

}


#endif

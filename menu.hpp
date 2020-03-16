#ifndef MENU_HPP
#define MENU_HPP


//Macros for readablity
enum MENU_OPTIONS : char {
	ADD_MODIFY='1',
	REMOVE='2',
	SHOW='3',
	LOAD='4',	
	SAVE='5',

	QUIT='q',
	WAIT='w'
};


class Menu{
	private:
		char action; //Menu action for any input such as 'q' for quit
		University university;		
			
	public:
		Menu(void);
	
		bool find(Student temp);
	
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
		void load(void);		

		//OPTION 5
		void save(void);		

		//OPTION 6
		void quit(void);

};


Menu::Menu(void){
	action = QUIT;
}


bool Menu::find(Student temp){
	for(int i=0; i<university.getSize(); i++){
		for(int j=0; j<university.getDegree(i).getSize(); j++){
			if(temp == university.getStudent(i, j)){
				return true;
			}
		}
	}
	
	return false;
}


void Menu::print(void){
	std::cout << "\n\n========Menu========\n";
	std::cout << (char)ADD_MODIFY << " Add or Modify\n";
	std::cout << (char)REMOVE << " Remove\n";
	std::cout << (char)SHOW << " Show\n";	
	std::cout << (char)LOAD << " Load\n";
	std::cout << (char)SAVE << " Save\n";
	std::cout << (char)QUIT << " [Q]uit\n\n";
}


void Menu::getInput(void){
	std::cout << "\nOption : ";
	std::cin >> action;
}


void Menu::start(void){

	action = WAIT;
	
	while(action!=QUIT){
		print();
		//std::cin >> action;
		getInput();
		
		switch(action){
			case ADD_MODIFY:{
				addModify();
				break;	
			}
			case REMOVE:{
				remove();
				break;	
			}
			case SHOW:{
				show();
				break;	
			}
			case LOAD:{
				load();
				break;
			}
			case SAVE:{
				save();
				break;
			}
			case QUIT:{
				quit();
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
	std::string temp_name, temp_DNI, temp_degree;
	char ans;

	std::cout << "Add or Modify chosen\n\n";
	
	std::cout << "Student's name : "; 
		std::cin.ignore(200, '\n');
		//getchar();
		getline(std::cin, temp_name);
	std::cout << "Student's DNI : "; 
		//std::cin.ignore(200, '\n');
		//getchar();
		getline(std::cin, temp_DNI);
	std::cout << "Degree : "; 
		//std::cin.ignore(200, '\n');
		//getchar();
		getline(std::cin, temp_degree);

	std::cout << temp_name << temp_DNI << temp_degree;
	
	Student temp(temp_name, temp_DNI);
	bool found = find(temp);

	if(!found){
		//university.addDegree(temp_degree);
		university.addStudent(temp, temp_degree);
	}else{
		std::cout << "\nDo you want to modify a student? (y/N):\t";
		std::cin >> ans;
		
		if(ans == 'Y' or ans == 'y'){
			//Modify given student
			university.modifyStudent(temp);
		}else{
			//Don't modify just exit	
		}
	}
}
		
//OPTION 2
void Menu::remove(void){
	std::string temp_name, temp_DNI, temp_degree;
	char ans;
	std::cout << "Remove chosen\n\n";

	university.removeEmptyDegrees();

	//Remove students
	std::cout << "Do you want to remove student? (y/N):\t";
		std::cin >> ans;
	
	if(ans == 'y' or ans == 'Y'){
		std::cout << "Student's name : "; 
			std::cin >> temp_name;
		std::cout << "Student's DNI : "; 
			std::cin >> temp_DNI;
		std::cout << "Degree : "; 
			std::cin >> temp_degree;

		Student stu(temp_name, temp_DNI);
		university.removeStudent(stu, temp_degree);
	}
}	

//OPTION 3
void Menu::show(void){
	std::cout << "Show students chosen\n\n";

	std::cout << "University (" << university.getTotalNumStudents() << ")\n";
	for(int i=0; i<university.getSize(); i++){
		//Print degree
		std::cout << "\n\t" << university.getDegree(i).getName() << "\t( " << university.getDegree(i).getSize() << ')';
		
		for(int j=0; j<university.getDegree(i).getSize(); j++){
			//Print all students in a degree
			std::cout << "\n\t\t" << university.getStudent(i, j).getName() << "\t" << university.getStudent(i, j).getDNI();
		}
	}		
}	

//OPTION 4
void Menu::load(void){
	//Load from file
	std::cout << "Loading from file\n";
	university.load();
}


//OPTION 5
void Menu::save(void){
	//Save to file
	std::cout << "Saving to file\n";
	university.save();
}

//OPTION 6
void Menu::quit(void){
	std::cout << "\nBye\n";
}


#endif

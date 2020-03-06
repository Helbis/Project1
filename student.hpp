#ifndef STUDENT_HPP
#define STUDENT_HPP

class Student{ 
	private: 
		std::string	dni; 
		std::string name; 
		bool isEnrolled;
	
	public:
		//Setters
		void setDNI(std::string temp);
		void setName(std::string temp);
		void setEnrollment(bool temp);

		//Getters
		std::string getDNI(void);
		std::string getName(void);
		bool getEntrollment(void);
};

//Setters
void Student::setDNI(std::string temp){
	dni = temp;
}

void Student::setName(std::string temp){
	name = temp;
}

void Student::setEnrollment(bool temp){
	isEnrolled = temp;
}

//Getters
std::string Student::getDNI(void){
	return dni;
}

std::string Student::getName(void){
	return name;
}

bool Student::getEntrollment(void){
	return isEnrolled;
}

#endif

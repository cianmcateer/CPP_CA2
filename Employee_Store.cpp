#include "Employee_Store.h"

Employee_Store::Employee_Store() {
    this->employeeStore = load();
}

std::vector<Employee*> Employee_Store::load() {

    Office* o1 = new Office("Cian McAteer", 22, 40,"cian@email.com", 1200);
    Office* o2 = new Office("John Smith", 27, 35, "john@email.com", 1600);
    Office* o3 = new Office("Matthew McCardle", 44, 38, "matthew@email", 1500);
    Office* o4 = new Office("Jamie Simmons", 30, 25, "jamie@email.com", 900);

    Factory* f1 = new Factory("Barry Smith", 19, 45, 420);
    Factory* f2 = new Factory("Michael Sweeney", 21, 30, 270);
    Factory* f3 = new Factory("Phil Bowlington", 18, 20, 210);
    Factory* f4 = new Factory("Carl Bingham", 25, 10, 400);

    std::vector<Employee*> backup;
    backup.push_back(o1);
    backup.push_back(o2);
    backup.push_back(o3);
    backup.push_back(o4);

    backup.push_back(f1);
    backup.push_back(f2);
    backup.push_back(f3);
    backup.push_back(f4);

    return backup;
}

inline std::vector<Employee*> Employee_Store::getEmployeeStore() const {
    return employeeStore;
}

void Employee_Store::print() {
    std::cout << "Current number of employees: " << employeeStore.size() << "." << std::endl;
    for(Employee* e : employeeStore) {
        e->print();
    }
}

std::string Employee_Store::save() {
	
	std::string details;
	
    for(Employee* e : employeeStore) {
        details = details + e->save()+ "\n";
    }
	
	return details;
}

Employee_Store::~Employee_Store() {
    for(Employee* e : employeeStore) {
        delete e;
    }
    employeeStore.clear();
}

void Employee_Store::add(Employee* e) {
    employeeStore.push_back(e);
}

bool Employee_Store::in_range(int& i) {
    return i < employeeStore.size();
}

void Employee_Store::show_index() {
    for(unsigned int i = 0;i < employeeStore.size();++i) {
        std::cout << "Index: " << i << " Name: " << employeeStore[i]->getName() << "." << std::endl;
    }
}

void Employee_Store::erase(int& index) {
    employeeStore.erase(employeeStore.begin() + index);
}

void Employee_Store::updateEmployee()
{
	bool menu = true;
	int menuSelect;
	std::string search;
	
	int index;
	
	std::string newName;
	int newAge;
	int newHours;
	std::string newEmail;
	float newWage;
	float newSalary;
	
	std::cout << "\nEnter employee name to begin editing"<< std::endl;
	std::cout << "> ";
	std::cin.ignore();
	std::getline(std::cin,search);
	
	for(unsigned int i = 0;i < employeeStore.size();++i) {
      if(search == employeeStore[i]->getName())
	  {
		index = i;
		
		std::cout << "\nEdit "<< employeeStore[index]->getName()<<"'s details" <<std::endl;
			while(menu == true){
			std::cout << "+----------------------------+" << std::endl;
			std::cout << "|      ::Editing Menu::      |" << std::endl;
			std::cout << "|                            |" << std::endl;
			std::cout << "|-Edit name..............[1] |" << std::endl;
			std::cout << "|-Edit age...............[2] |" << std::endl;
			std::cout << "|-Edit hours.............[3] |" << std::endl;
			std::cout << "|-Edit Email.............[4] |" << std::endl;
			std::cout << "|-Edit salary............[5] |" << std::endl;
			std::cout << "|-Edit Wages.............[6] |" << std::endl;
			std::cout << "+----------------------------+" << std::endl;
			std::cout << "\n> ";
			std::cin >> menuSelect;
			std::cin.ignore(); 
			
			switch(menuSelect) {
				case 1 :
					std::cout << "Edit name:";
					std::getline(std::cin,newName);
					employeeStore[index]->setName(newName);
					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<< std::endl;
					break;
				case 2 :
					std::cout << "Edit Age:";
					std::cin >> newAge;
					employeeStore[index]->setAge(newAge);
					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<< std::endl;
					break;
				
				case 3 :
					std::cout << "Edit Hours:";
					std::cin >> newHours;
					employeeStore[index]->setHours(newHours);
					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<< std::endl;
					break;
				case 4 : {
					std::cout << "Edit Email:";
					std::getline(std::cin,newEmail);
					Office* off1 = dynamic_cast<Office*>(employeeStore[index]);
					off1->setEmail(newEmail);
					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<<" "<< off1->getEmail()<<" "<< off1->getSalary()<< std::endl;
					break;
				}
				case 5 : {
					std::cout << "Edit Salary:";
					std::cin >> newSalary;
					Office* off2 = dynamic_cast<Office*>(employeeStore[index]);
					off2->setSalary(newSalary);
					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<< " "<<off2->getEmail()<<" "<< off2->getSalary() << std::endl;
					break;
				}
				case 6 : {
					std::cout << "Edit Wages:";
					std::cin >> newWage;
					Factory* f1 = dynamic_cast<Factory*>(employeeStore[index]);
					f1->setWage(newWage);
					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<<" "<< f1->getWage() << std::endl;
					break;
				}
				case 0 :
					return;
					break;
			}	
		
		}
	  }
	 
    
	
	
	}
	
}

void Employee_Store::sortEmployees() 
{
	std::string search;
	std::cout << "\nEnter any of the following to sort:\n name, age, hours, email, salary, wages \n> " ;
	std::cin.ignore();
	std::getline(std::cin,search);
	std::cout << std::endl;
	
	if(search == "name"){
		sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2){
				return e1->getName() < e2->getName();
		});
	}
	else if(search == "age"){
		sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2){
			return e1->getAge() < e2->getAge();
		});
	}
	else if(search == "hours"){
		sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2){
			return e1->getHours() < e2->getHours();
		});
	}
	else if(search == "email"){
		
		sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2){
			const Office* o1 = dynamic_cast<const Office*>(e1);
			const Office* o2 = dynamic_cast<const Office*>(e2);
			if(o1 != nullptr) {
				return o1->getEmail() < o2->getEmail();
			}
		});
	}
	else if(search == "salary"){
		
		sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2){
			const Office* o1 = dynamic_cast<const Office*>(e1);
			const Office* o2 = dynamic_cast<const Office*>(e2);
			if(o1 != nullptr) {
				return o1->getSalary() < o2->getSalary();
			}
		});
	}
	else if(search == "wages"){
		
		sort(employeeStore.begin(), employeeStore.end(), [](const Employee* e1, const Employee* e2){
			const Factory* f1 = dynamic_cast<const Factory*>(e1);
			const Factory* f2 = dynamic_cast<const Factory*>(e2);
			if(f1 != nullptr) {
				return f1->getWage() < f2->getWage();
			}
		});
	}
	
	print();
	
}

void Employee_Store::saveChanges()
{
	std::ofstream employeefileWrite;
	employeefileWrite.open("save.txt");
	std::string employeeDetails;
	
	employeefileWrite << save();
		
	
}
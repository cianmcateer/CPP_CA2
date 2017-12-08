#include "Employee_Store.h"

Employee_Store::Employee_Store(std::string path)
: employeeStore(read(path)) {}

/**
* Testing and backup data in case
* read file fails
* @author Cian McAteer
* @return backup
*/
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
/**
* @author Ciaran Maher
*/
void Employee_Store::print() {
    std::cout << "Current number of employees: " << employeeStore.size() << "." << std::endl;
    for(Employee* e : employeeStore) {
        e->print();
    }
}

/**
* Destructor must delete heap allocated object pointers
*/
Employee_Store::~Employee_Store() {
    for(Employee* e : employeeStore) {
        delete e;
    }
    employeeStore.clear();
}

/**
* @author Cian McAteer
*/
void Employee_Store::add(Employee* e) {
    employeeStore.push_back(e);
}

/**
* @author Cian McAteer
*/
bool Employee_Store::inRange(int& index) {
    return index < employeeStore.size();
}

/**
* @author Cian McAteer
*/
void Employee_Store::show_index() {
    for(unsigned int i = 0;i < employeeStore.size();++i) {
        std::cout << "Index: " << i << " Name: " << employeeStore[i]->getName() << "." << std::endl;
    }
}

/**
* @author Cian McAteer
*/
void Employee_Store::erase(int& index) {
    employeeStore.erase(employeeStore.begin() + index);
}

/**
* @author Cian McAteer
*/
void Employee_Store::clear() {
    employeeStore.clear();
}

/***
* @author Ciaran Maher
*/
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
	std::string wage;
	std::string newSalary;

	std::cout << "\nEnter employee name to begin editing"<< std::endl;
	std::cout << "> ";
	std::cin.ignore();
	std::getline(std::cin,search);

	for(unsigned int i = 0;i < employeeStore.size();++i) {
      if(search == employeeStore[i]->getName())
	  {
	        index = i;

		    std::cout << "\nEdit "<< employeeStore[index]->getName()<<"'s details" <<std::endl;
			while(menu){
    			std::cout << "+----------------------------+" << std::endl;
    			std::cout << "|      ::Editing Menu::      |" << std::endl;
    			std::cout << "|                            |" << std::endl;
    			std::cout << "|-Edit name..............[1] |" << std::endl;
    			std::cout << "|-Edit age...............[2] |" << std::endl;
    			std::cout << "|-Edit hours.............[3] |" << std::endl;
    			//std::cout << "|-Edit salary............[4] |" << std::endl;
    			std::cout << "+----------------------------+" << std::endl;
    			std::cout << "\n> ";
    			std::cin >> menuSelect;
    			std::cin.ignore();

    			switch(menuSelect) {

                    case 0:
                        return;
                        break;
    				case 1 :
    					std::cout << "Edit name:";
    					std::getline(std::cin,newName);
    					employeeStore[index]->setName(newName);
    					std::cout << employeeStore[index]->getName() << " " << employeeStore[index]->getAge() << " " << employeeStore[index]->getHours() << std::endl;
    					break;
    				case 2 :
    					std::cout << "Edit Age:";
    					std::cin >> newAge;
    					employeeStore[index]->setAge(newAge);
    					std::cout << employeeStore[index]->getName() << " "<< employeeStore[index]->getAge() << " "<< employeeStore[index]->getHours() << std::endl;
    					break;

    				case 3 :
    					std::cout << "Edit Hours:";
    					std::cin >> newHours;
    					employeeStore[index]->setHours(newHours);
    					std::cout <<employeeStore[index]->getName()<<" "<<employeeStore[index]->getAge() <<" "<<employeeStore[index]->getHours()<< std::endl;
    					break;

    			}
		}
	  }
	  else {
		std::cout << std::endl;
		std::cout << search<<" is not an employee" << std::endl;
		std::cout << std::endl;
		break;
	  }

	}

}

/**
* Writes employee objects to save file
* using a virtual save method
* for each subclass
* @author Cian McAteer
* @param fileName
*/
void Employee_Store::save(std::string fileName) {

    std::ofstream employeefileWrite;
	employeefileWrite.open(fileName.c_str());

    if(employeefileWrite.is_open()) {
        for(Employee* e : employeeStore) {
            employeefileWrite << e->save();
        }
    } else {
        std::cerr << "Could not save data" << std::endl;
    }

}

/**
* @author Cian McAteer
*/
void Employee_Store::history() {
    // Append students instead of overwritting students
    std::ofstream employeeRecords("records.txt",std::fstream::in | std::ios::out | std::ios::app);

    if(employeeRecords.is_open()) {
        for(Employee* e : employeeStore) {
            employeeRecords << e-> save();
        }
    } else {
        std::cerr << "Records could not be accessed" << std::endl;
    }
}

/**
* @author Cian McAteer
*/
std::set<Employee*> Employee_Store::getRecords() {
    std::set<Employee*> records;
    std::ifstream history("records.txt");

    if(history.is_open()) {

        std::string line;
        std::set<std::string> lines;

        while(getline(history, line)) {
            lines.insert(line);
        }

        std::string type;
        std::string name;
        int age;
        int hours;
        float wages;

        std::string email;
        float salary;
        for(const std::string& line : lines) {
            std::stringstream ss(line);
            while(ss >> type) {
                if(type == "Factory") {
                    while(ss >> name >> age >> hours >> wages) {
                        std::replace(name.begin(), name.end(), '-', ' ');
                        Employee* e = new Factory(name, age, hours, wages);
                        records.insert(e);
                    }
                } else {
                    while(ss >> name >> age >> hours >> email >> salary) {
                        std::replace(name.begin(), name.end(), '-', ' ');
                        Employee* e = new Office(name, age, hours, email, salary);
                        records.insert(e);
                    }
                }
            }

        }
    } else {
        std::cerr << "Could not retrieve records from database" << std::endl;
    }
    return records;
}

/**
* @author Cian McAteer
*/
void Employee_Store::show_history() {
    std::set<Employee*> records = getRecords();

    for(Employee* e : records) {
        e->print();
    }
}

/**
* @author Ciaran Maher
*/
void Employee_Store::printEmployees(bool type) {

    if(type) {
        for(Employee* e : employeeStore) {
            if(dynamic_cast<Office*>(e)) {
                e->print();
            }
        }
    } else {
        for(Employee* e : employeeStore) {
            if(dynamic_cast<Factory*>(e)) {
                e->print();
            }
        }
    }

}

/**
* @author Cian McAteer
*/
std::vector<Employee*> Employee_Store::read(std::string path) {
    std::ifstream data(path);

    std::vector<Employee*> employees;
    if(data.is_open()) {
        std::string line;
        std::vector<std::string> lines;

        while(getline(data, line)) {
            lines.push_back(line);
        }

        std::string type;
        std::string name;
        int age;
        int hours;
        float wages;

        std::string email;
        float salary;
        for(unsigned int i = 0;i < lines.size();++i) {
            std::stringstream ss(lines[i]);
            while(ss >> type) {

                if(type == "Factory") {
                    while(ss >> name >> age >> hours >> wages) {
                        std::replace(name.begin(), name.end(), '-', ' ');
                        Employee* e = new Factory(name, age, hours, wages);
                        employees.push_back(e);
                    }
                } else {
                    while(ss >> name >> age >> hours >> email >> salary) {
                        std::replace(name.begin(), name.end(), '-', ' ');
                        Employee* e = new Office(name, age, hours, email, salary);
                        employees.push_back(e);
                    }
                }
            }
        }
    } else {
        std::cerr << "Can't open save file" << std::endl;
        employees = load();
        std::cerr << "Back up file has been implemented!" << std::endl;
    }

    return employees;
}

/**
* @author Cian McAteer
*/
std::stack<std::string> Employee_Store::readLog() {
    std::stack<std::string> logs;
    std::ifstream readLogs("logs.txt");

    if(readLogs.is_open()) {
        std::string line;
        while(getline(readLogs, line)) {
            logs.push(line);
        }
    } else {
        std::cerr << "Error opening log file" << std::endl;
    }
    return logs;
}

/**
* @author Ciaran Maher
*/
void Employee_Store::createWebpage() {
    std::ofstream html_page("worker_catalogue.html");
    // HTML header tags
    html_page << "<!DOCTYPE html><html><head>"; // Header tags
    html_page << "<link href=\"worker_page.css\" rel=\"stylesheet\">"; // Style sheet link
    html_page << "</head><body>";
    html_page << "<h1></h1>";
    html_page << "<img>";
    html_page << "<table border='1'>";
    html_page << "<h2>Office Workers</h2>";
    html_page << "<tr><td class='title'>Name</td><td class='title'>Age</td><td class='title'>Hours</td><td class='title'>Email</td><td class='title'>Salary</td></tr>";
    for(Employee* e : employeeStore) {
		if(dynamic_cast<Office*>(e)){
			Office* o = dynamic_cast<Office*>(e);
            html_page << "<tr>";
			html_page << "<td>" << e->getName() << "</td>"; // Converts to HTML string
			html_page << "<td>" << e->getAge() << "</td>"; // Converts to HTML string
			html_page << "<td>" << e->getHours() << "</td>"; // Converts to HTML string
			html_page << "<td>" << o->getEmail() << "</td>"; // Converts to HTML string
			html_page << "<td>" << o->getSalary() << "</td>"; // Converts to HTML string
		}
        html_page << "</tr>";
    }

    html_page << "</table>";
	html_page << "<table border='1'>";
    html_page << "<h2>Factory Workers</h2>";
    html_page << "<tr><td class='title'>Name</td><td class='title'>Age</td><td class='title'>Hours</td><td class='title'>Wages</td></tr>";
    for(Employee* e : employeeStore) {
		if(dynamic_cast<Factory*>(e)){
			Factory* f = dynamic_cast<Factory*>(e);
			html_page << "<tr>";
			html_page << "<td>" << e->getName() << "</td>"; // Converts to HTML string
			html_page << "<td>" << e->getAge() << "</td>"; // Converts to HTML string
			html_page << "<td>" << e->getHours() << "</td>"; // Converts to HTML string
			html_page << "<td>" << f->getWage() << "</td>"; // Converts to HTML string
		}
        html_page << "</tr>";
    }
    html_page << "</table>";

    // Close off page and end connection
    html_page << "</body></html>";
    html_page.close();

}

/**
* @author Cian McAteer
*/
void Employee_Store::displayLogs() {

    std::stack<std::string> logs = readLog();
    std::cout << "Log size " << logs.size() << std::endl;

    while(!logs.empty()) {
        // Print last element added to stack
        std::cout << logs.top() << std::endl;
        logs.pop(); // Pop element off to print next element
    }
}

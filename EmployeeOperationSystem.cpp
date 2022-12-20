/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//-- Clear
//?? not
#include <iostream>

using namespace std;

class Employee
{
private:
  string Name;
  int ID;
  int FirstDay;
  string PhoneNumber;
  string Address;
  int WHours;
  double Salary;
  Employee* next;
public:
    // constructor 
    initialize an object , it call whenever the object of the class called
     Employee ()
   {
     name = "";
     ID = 0;
     FirstDay = 0;
     phoneNumber = "";
     Address = "";
     wHours = 0;
     salary = 0.0;
   }
  Employee(string name, int id,int firstDay,string phoneNumber,string address,int wHours ,double salary){
      this->Name = name;
      this->ID = id;
      this->FirstDay = firstDay;
      this->PhoneNumber = phoneNumber;
      this->Address =address;
      this->WHours =wHours;
      this->Salary = salary;
      this->next = NULL;
  }
  //------setters------
  void setName (string Name)
  {
    this->Name = Name;
  }				
  void setID (int ID)
  {
    this->ID = ID;
  }				
  void setFirstDay (int FirstDay)
  {
    this->FirstDay = FirstDay;
  }				
  void setphoneNumber (string PhoneNumber)
  {
    this->PhoneNumber = PhoneNumber;
  }				
  void setAddress (string Address)
  {
    this->Address = Address;
  }				
  void setwHours (int WHours)
  {
    this->WHours = WHours;
  }				
  void setsalary (double Salary)
  {
    this->Salary = Salary;
  }				
  void setNext (Employee * next)
  {
    this->next = next;
  }
  //------getters------
  string getName ()
  {
    return Name;
  }
  int getID ()
  {
    return ID;
  }
  int getFirstDay ()
  {
    return FirstDay;
  }
  string getphoneNumber ()
  {
    return PhoneNumber;
  }
  string getAddress ()
  {
    return Address;
  }
  int getwHours ()
  {
    return WHours;
  }
  double getsalary ()
  {
    return Salary;
  }
  Employee *getNext ()
  {
    return next;
  }
};

class EmployeeList{
  Employee* head;
public:
    EmployeeList ()
  {
    head = NULL;
  }				//--????
      void checkRecord(int ID){
        bool unique = false;
        Employee* temp = head;
        while(temp != NULL){
                if(temp->getID() == ID){
                    unique = true;
                    break;
                }
                temp = temp->getNext();
                cout<<"There is an Employee with this ID";
                cout<<"try again";
            }
            return unique;
        }
      }



  
  void InsertEmployee (string Name, int ID,int FirstDay, string WhoneNumber, string Address,int wHours, double Salary)
  {
    // node ----?? 
    Employee* newnode = new Employee( Name, ID, FirstDay, phoneNumber, Address, wHours ,salary);
    //insert in the front 
    while(checkRecord (ID)){
    if (head == NULL)
      {
	    head = newnode;
      }
    else
      {
        // new pointer
	      Employee* temp = head;
        while(temp != NULL){
          if(temp->getID() == ID){
          cout<< "Employee with this ID "<<temp->getID()<<"Is already exist"
                    break;
        }
        temp = temp->getNext();
        }
	      while (temp->getNext() != NULL)
	      {
	          temp = temp->getNext();
	      }
	  //insert in the last
         while (temp->getNext() != NULL && (temp->getNext())->getID() < newnode->getID()){
                        temp = temp->getNext();
                    }
                    newEmp->setNext(temp->getNext());
                    temp->setNext(newnode);
      }
    cout << "The Employee was added successfully." << endl;
    }
  }
//----------

//searches for employee info 
void SearchEmployee(int ID){
 Employee* temp = head;
 bool match=false;//is it match for what i have looking for ?
 while(temp!=NULL){
   if(temp->getID()==ID)
    {
      match= true;
      cout<<"Employee Name = "<<temp->getName()<<endl;
      cout<<"Employee ID = "<<temp->getID()<<endl;
      cout <<"First Day of Employee work : "<< temp->getFirstDay () << endl;
      cout <<"Phone number of Employee : "<< temp->getphoneNumber () << endl;
      cout <<"Address of Employee : "<< temp->getAddress () << endl;
      cout <<"work hours of Employee : "<< temp->getwHours () << endl;
      cout <<"Employee Salary = "<<temp->getsalary()<<endl;
    }
  temp=temp->getNext(); //move to the next node
 }
 cout<<"\t-------------"
if(match==false){
 cout<<"There is no record of this employee in this system"<<endl;
  }
 }
 void DeleteEmployee(int ID){
   Employee* prev = NULL;
   Employee* temp = head;
   bool cond = false;// condition == false 
//if head is NULL then the list is empty.
if(head == NULL){
 cout<<"Record is empty."<<endl;
 }
//else finds the finds the employee node and deletes it.
else{
while(temp != NULL){
if(temp->getID() == ID){
 cond = true;//----
break;
 }
 prev = temp;
 temp = temp -> getNext();
 // traversing 
 }
if(cond == true){
if(prev == NULL){
    //delete the only node in the record
 head = head->getNext();
 delete temp;
 }
else{
 prev->setNext(temp->getNext());//?????///
delete temp;
 }
//if found
 cout<<"The Employee record was deleted successfully."<<endl;
  }
//if not found
else{
 cout<<"The Employee ID doesn't exist in the list."<<endl;
  }
 }
 }

//prints all nodes
void ShowEmployee()
{
  Employee* temp = head;

  if(temp == NULL){
                cout<<"Record is empty."<<endl;
                return;
            }

  while (temp != NULL)
    {
      cout << "Employee name : " << temp->getName() << endl;
      cout << "Employee ID : " << temp->getID() << endl;
      cout << "First Day of Employee work : " << temp->getFirstDay() << endl;
      cout << "Phone numver of Employee : " << temp->getphoneNumber() << endl;
      cout << "Address of Employee : " << temp->getAddress() << endl;
      cout << "work hours of Employee : " << temp->getwHours() << endl;
      cout << "salary of Employee : " << temp->getsalary() << endl;

      temp = temp->getNext ();
    }
  cout << endl<<"\n\n";

}

 void UpdateSalary(int ID){
double overtime = 0;
Employee* temp = head;
bool match=false;
while(temp!=NULL){
if(temp->getID()==ID)
 {
        match= true;
        if(temp->getsalary() > 32){
                overtime = temp->getsalary();
                overtime = overtime+(overtime*0.02);
                temp->setsalary(overtime);
        
                cout<<"this Employee "<<temp->getName();
                cout<<"with id   "<<temp->getID()<<endl;
                cout<<"work in overtime so the Salary will increase and it will ==  "<<temp->getsalary()<<endl;
                cout<<"---------------------------------------"<<endl;
        }
 }
        temp=temp->getNext(); //move to the next node
 }
if(match==false){
 cout<<"There is no record of this employee in this system"<<endl;
 cout<<"--------------------------------------------"<<endl;
 }
 }
//-- Clear
//?? not
#include <iostream>

using namespace std;

class Employee
{
private:
  string name;
  int ID;
  int FirstDay;
  string phoneNumber;
  string Address;
  int wHours;
  double salary;
  Employee* next;
public:
    // constructor 
    // initialize an object , it call whenever the object of the class called
     Employee ()
   {
     name = "";
     ID = 0;
     FirstDay = 0;
     phoneNumber = "";
     Address = "";
     wHours = 0;
     salary = 0.0;
   }
  Employee(string name, int ID,int FirstDay,string phoneNumber,string Address,int wHours ,double salary){
      this-> name = name;
      this -> ID = ID;
      this -> FirstDay = FirstDay;
      this -> phoneNumber = phoneNumber;
      this -> Address =Address;
      this -> wHours =wHours;
      this -> salary = salary;
      next = NULL;
  }
  void setName (string name)
  {
    this->name = name;
  }				//---
  void setID (int ID)
  {
    this->ID = ID;
  }				//--
  void setFirstDay (int FirstDay)
  {
    this->FirstDay = FirstDay;
  }				//---
  void setphoneNumber (string phoneNumber)
  {
    this->phoneNumber = phoneNumber;
  }				//---
  void setAddress (string Address)
  {
    this->Address = Address;
  }				//---
  void setwHours (int wHours)
  {
    this->wHours = wHours;
  }				//---
  void setsalary (double salary)
  {
    this->salary = salary;
  }				//---
  void setNext (Employee * next)
  {
    this->next = next;
  }


  //---
  string getName ()
  {
    return name;
  }
  int getID ()
  {
    return ID;
  }
  int getFirstDay ()
  {
    return FirstDay;
  }
  string getphoneNumber ()
  {
    return phoneNumber;
  }
  string getAddress ()
  {
    return Address;
  }
  int getwHours ()
  {
    return wHours;
  }
  double getsalary ()
  {
    return salary;
  }
  Employee *getNext ()
  {
    return next;
  }



};

//----------------------------------------
class EmployeeList{
  Employee* head;
public:
    EmployeeList ()
  {
    head = NULL;
  }				//--????
  void InsertEmployee (string name, int ID,int FirstDay, string phoneNumber, string Address,int wHours, double salary)
  {
    // pointer object 
    Employee* newnode = new Employee( name, ID, FirstDay, phoneNumber, Address, wHours ,salary);
    //insert in the front 
    if (head == NULL)
      {
	    head = newnode;
      }
    else
      {
          // new pointer
	      Employee* temp = head;

	      while (temp->getNext() != NULL)
	      {
	          temp = temp->getNext();
	      }
	  //insert in the last
	      temp->setNext(newnode);
      }
    cout << "The Employee record was added successfully." << endl;
    };
//----------

//searches for employee info 
void SearchEmployee(int ID){
 Employee* temp = head;
 bool match=false;//is it match for what i have looking for ?
 while(temp!=NULL){
   if(temp->getID()==ID)
    {
      match= true;
      cout<<"Employee Name = "<<temp->getName()<<endl;
      cout<<"Employee ID = "<<temp->getID()<<endl;
      cout <<"First Day of Employee work : "<< temp->getFirstDay () << endl;
      cout <<"Phone number of Employee : "<< temp->getphoneNumber () << endl;
      cout <<"Address of Employee : "<< temp->getAddress () << endl;
      cout <<"work hours of Employee : "<< temp->getwHours () << endl;
      cout <<"Employee Salary = "<<temp->getsalary()<<endl;
    }
  temp=temp->getNext(); //move to the next node
 }
if(match==false){
 cout<<"There is no record of this employee in this system"<<endl;
  }
 }
 void DeleteEmployee(int ID){
   Employee* prev = NULL;
   Employee* temp = head;
   bool cond = false;// condition == false 
//if head is NULL then the list is empty.
if(head == NULL){
 cout<<"Record is empty."<<endl;
 }
//else finds the finds the employee node and deletes it.
else{
while(temp != NULL){
if(temp->getID() == ID){
 cond = true;//----
break;
 }
 prev = temp;
 temp = temp -> getNext();
 // traversing 
 }
if(cond == true){
if(prev == NULL){
    //delete the only node in the record
 head = head->getNext();
 delete temp;
 }
else{
 prev->setNext(temp->getNext());//?????///
delete temp;
 }
//if found
 cout<<"The Employee record was deleted successfully."<<endl;
  }
//if not found
else{
 cout<<"The Employee ID doesn't exist in the list."<<endl;
  }
 }
 }

//prints all nodes
void ShowEmployee()
{
  Employee* temp = head;

  while (temp != NULL)
    {
      cout << "Employee name : " << temp->getName() << endl;
      cout << "Employee ID : " << temp->getID() << endl;
      cout << "First Day of Employee work : " << temp->getFirstDay() << endl;
      cout << "Phone numver of Employee : " << temp->getphoneNumber() << endl;
      cout << "Address of Employee : " << temp->getAddress() << endl;
      cout << "work hours of Employee : " << temp->getwHours() << endl;
      cout << "salary of Employee : " << temp->getsalary() << endl;

      temp = temp->getNext ();
    }
  cout << endl;

}

 void UpdateSalary(int ID){
//      int overtime = 32;
//      int newsalary;
//      Employee* node = NULL;
//      Employee* temp = head;
//      if(head == NULL){
//             cout<<"List is empty."<<endl;
//             cout<<"--------------------------------------"<<endl;
//     }
//     //else finds the largest Employee Salary node and prints it.
//     else{
//      while(temp != NULL){
//         if(temp->getsalary() > overtime){
//         newsalary =temp->getsalary();
//       // temp->setsalary(newsalary);
//         newsalary = newsalary+(newsalary*0.02);
//         //temp->setsalary(newsalary);
//         temp->getsalary();
//         }
        
//         }
//         cout<<" this Employee that has overtime: "<<endl;
//         cout << "salary of Employee : " << temp->getsalary() << endl;
//  }
// double overtime = 0;
//  Employee* node = NULL;
//  Employee* temp = head;
// //if head is NULL means the list empty.
// if(head == NULL){
//  cout<<"List is empty."<<endl;
//  cout<<"--------------------------------------"<<endl;
//  }
//else finds the largest Employee Salary node and prints it.
// 
// else{
// while(temp-> getID() == ID){
// if(temp->getsalary() > 32){
//  overtime = temp->getsalary();
//  overtime = overtime+(overtime*0.02);
//  temp->setsalary(overtime);
//  node = temp;
//  }
//  temp = temp->getNext();
//  }
//  cout<<"The Employee with the highest Salary is: "<<endl;
//  cout<<"Employee Name = "<<node->getName()<<endl;
//  cout<<"Employee ID = "<<node->getID()<<endl;
//  cout<<"Employee Salary = "<<node->getsalary()<<endl;
//  cout<<"---------------------------------------"<<endl;
//  }




double overtime = 0;
Employee* temp = head;
bool match=false;
while(temp!=NULL){
if(temp->getID()==ID)
 {
        match= true;
        if(temp->getsalary() > 32){
                overtime = temp->getsalary();
                overtime = overtime+(overtime*0.02);
                temp->setsalary(overtime);
        
                cout<<"this Employee "<<temp->getName();
                cout<<"with id   "<<temp->getID()<<endl;
                cout<<"work in overtime so the Salary will increase and it will ==  "<<temp->getsalary()<<endl;
                cout<<"---------------------------------------"<<endl;
        }
 }
        temp=temp->getNext(); //move to the next node
 }
if(match==false){
 cout<<"There is no record of this employee in this system"<<endl;
 cout<<"--------------------------------------------"<<endl;
 }
 }






//--- it must be node that 

Employee* getHead(){
//returns the head of the current Employee node.
return head;
 }
 };
//--------------------------------------------------
int main ()
{
  int num;
  string name;
  int ID;
  int FirstDay;
  string phoneNumber;
  string Address;
  int wHours;
  double salary;
  EmployeeList *a /*we can name it another name */  = new EmployeeList ();
  //================================================EmployeeList *obj = new EmployeeList ();
  while (1)
    {
      cout << "\t\tPress  1  to INSERT Employee:" << endl;
      cout << "\t\tPress  2  to Search Employee :" << endl;//
      cout << "\t\tPress  3  to DELETE Employee:" << endl;
      cout << "\t\tPress  4  to Show Employee:" << endl;
      cout << "\t\tPress  5  to Update salary" << endl;//
      cout << "\t\tPress  6  to exit:" << endl;

      cout << "\tEnter number from the list: ";
      cin >> num;
      switch (num)
	{
	case 1:
        cout << endl;
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter ID : ";
        cin >> ID;
        cout << "Enter First Day of Work";
        cin >> FirstDay;
      cout << "Enter Phone number";
        cin >> phoneNumber;
      cout << "Enter Address";
        cin >> Address;
      cout << "Enter work hours";
        cin >> wHours;
      cout << "Enter salary";
        cin >> salary;
        cout << endl;
        a->InsertEmployee(name,ID,FirstDay,phoneNumber,Address,wHours,salary);
        break;
     case 2:
        cout << endl;
        cout << "Enter ID: ";
        cin >> ID;
        cout << endl;
      a->SearchEmployee(ID);
        break;
//case 3 to delete Employee.
	case 3:
	  cout << endl;
	  cout << "Employee ID: ";
	  cin >> ID;
	  cout << endl;
	  a->DeleteEmployee(ID);
	  break;
//case 5 for the print list.
	case 4:
	  cout << endl;
	  cout << "Employee ID: ";
	  cin >> ID;
	  cout << endl;
	  a->ShowEmployee();
	  break;
  case 5:
    cout << endl;
    cout << "Enter ID: ";
    cin >> ID;
    cout << endl;
    a->UpdateSalary(ID);
        break; 
	case 6:
	  exit (0);
	default:
	  cout << "invalid choice." << endl;
	  break;
	}
    }
  return 0;
}
Employee* getHead(){
//returns the head of the current Employee node.
return head;
 }
 };
//--------------------------------------------------
int main ()
{
  int num;
  string name;
  int ID;
  int FirstDay;
  string phoneNumber;
  string Address;
  int wHours;
  double salary;
  EmployeeList *a /*we can name it another name */  = new EmployeeList ();
  //================================================EmployeeList *obj = new EmployeeList ();
  while (1)
    {
      cout << "\t\tPress  1  to INSERT Employee:" << endl;
      cout << "\t\tPress  2  to Search Employee :" << endl;//
      cout << "\t\tPress  3  to DELETE Employee:" << endl;
      cout << "\t\tPress  4  to Show Employee:" << endl;
      cout << "\t\tPress  5  to Update salary" << endl;//
      cout << "\t\tPress  6  to exit:" << endl;

      cout << "\tEnter number from the list: ";
      cin >> num;
      switch (num)
	{
	case 1:
        cout << endl;
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter ID : ";
        cin >> ID;
        cout << "Enter First Day of Work";
        cin >> FirstDay;
      cout << "Enter Phone number";
        cin >> phoneNumber;
      cout << "Enter Address";
        cin >> Address;
      cout << "Enter work hours";
        cin >> wHours;
      cout << "Enter salary";
        cin >> salary;
        cout << endl;
        a->InsertEmployee(name,ID,FirstDay,phoneNumber,Address,wHours,salary);
        break;
     case 2:
        cout << endl;
        cout << "Enter ID: ";
        cin >> ID;
        cout << endl;
      a->SearchEmployee(ID);
        break;
//case 3 to delete Employee.
	case 3:
	  cout << endl;
	  cout << "Employee ID: ";
	  cin >> ID;
	  cout << endl;
	  a->DeleteEmployee(ID);
	  break;
//case 5 for the print list.
	case 4:
	  cout << endl;
	  cout << "Employee ID: ";
	  cin >> ID;
	  cout << endl;
	  a->ShowEmployee();
	  break;
  case 5:
    cout << endl;
    cout << "Enter ID: ";
    cin >> ID;
    cout << endl;
    a->UpdateSalary(ID);
        break; 
	case 6:
	  exit (0);
	default:
	  cout << "invalid choice." << endl;
	  break;
	}
    }
  return 0;
}
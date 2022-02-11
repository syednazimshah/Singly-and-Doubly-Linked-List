#include<iostream>
#include<string>
#include<chrono>
using namespace std;
using namespace std::chrono;
class contactlist{
	private:
	struct contact{
	string name;
	string address;
	string email;
	string phoneno;
	contact *next = NULL;
	};
	contact *head;
	public:
		contactlist(){head = NULL;}
	void addcontact(){
		string name, add, email, phone;
		cout<<"\nEnter Name: ";
		getline(cin, name);
		cout<<"\nEnter Phone Number: ";
		getline(cin, phone);
		cout<<"\nEnter Address: ";
		getline(cin, add);
		cout<<"\nEnter Email: ";
		getline(cin, email);
	auto start = chrono::steady_clock::now();
	contact *ptrNew = new contact, *ptrTemp=head;
	ptrNew->name=name;
	ptrNew->phoneno=phone;
	ptrNew->address=add;
	ptrNew->email=email;
	ptrNew->next = NULL;
	if (head == NULL){
		head = ptrNew;
		head->next = NULL;
	}
	else{
	while (ptrTemp->next!=NULL) ptrTemp=ptrTemp->next; 
	ptrTemp->next= ptrNew;
	}
	auto stop = chrono::steady_clock::now();
	auto duration = (stop - start);
	cout <<"\n\nFunction Successfully Executed in "<< chrono:: duration<double,nano>(duration).count() <<" nanoSeconds"<< endl;
	}
void deletecontact(){
		string key;
		cout<<"Please Enter Phone Number to Delete a Contact: ";
		cin>>key;
		auto start = chrono::steady_clock::now();
	contact *ptrCurrent=head, *ptrPrevious;
	
	while (ptrCurrent!=NULL && ptrCurrent->phoneno!=key){
		ptrPrevious=ptrCurrent;
	ptrCurrent = ptrCurrent->next;
}
	if (ptrCurrent == NULL){
		cout<<"\nContact to delete not found in the list";
		return;
	}
	if (ptrCurrent == head){head = head->next;}
	else
		ptrPrevious->next= ptrCurrent->next;
	delete ptrCurrent;
    auto stop = chrono::steady_clock::now();
	auto duration = (stop - start);
	cout <<"\n\nFunction Successfully Executed in "<< chrono:: duration<double,nano>(duration).count() <<" nanoSeconds"<< endl;
}
void search(){
	string key;
	cout<<"Please Enter Name, Email or Address to find a Person: ";
	cin>>key;
	auto start = chrono::steady_clock::now();
	contact *ptrCurrent=head;
	while (ptrCurrent!=NULL && (ptrCurrent->name!=key||ptrCurrent->address!=key||ptrCurrent->email!=key ))	ptrCurrent = ptrCurrent->next;
	if (ptrCurrent == NULL) cout<<"\nContact not found in the list";
	else
	cout<<"\n\n\nName: "<<ptrCurrent->name<<"\nPhone: "<<ptrCurrent->phoneno<<"\nAddress: "<<ptrCurrent->address<<"\nEmail: "<<ptrCurrent->email;
	auto stop = chrono::steady_clock::now();
	auto duration = (stop - start);
	cout <<"\n\nFunction Successfully Executed in "<< chrono:: duration<double,nano>(duration).count() <<" nanoSeconds"<< endl;
}
void displaylist(){
	auto start = chrono::steady_clock::now();
	contact *ptrTemp=head;
	while (ptrTemp!=NULL){
	cout<<"\n\nName: "<<ptrTemp->name<<"\nPhone: "<<ptrTemp->phoneno<<"\nAddress: "<<ptrTemp->address<<"\nEmail: "<<ptrTemp->email;
		ptrTemp=ptrTemp->next;
	}
	auto stop = chrono::steady_clock::now();
	auto duration = (stop - start);
	cout <<"\n\nFunction Successfully Executed in "<< chrono:: duration<double,nano>(duration).count() <<" nanoSeconds"<< endl;
}
};
int main(){
	auto start = chrono::steady_clock::now();
	contactlist listofcontacts;
	auto stop = chrono::steady_clock::now();
	auto duration = (stop - start); 
	cout <<"\n\nClass Instance Successfully created in "<< chrono:: duration<double,nano>(duration).count() <<" nanoSeconds"<< endl;
	system("pause");
	while (true) { 
    int choice = 0;
    cout << "\n1.Add a Contact\n2.View a Contact Information\n3.View all Contacts\n4.Delete a Contact\n5.Exit\n\nSelect a Choice: ";
    cin >> choice;
      switch (choice) { //using switch to perform user choice based tasks
      case 1:
      	cin.ignore();
        listofcontacts.addcontact();
        break;
      case 2:
      	cin.ignore();
        listofcontacts.search();
        break;
      case 3:
        listofcontacts.displaylist();
        break;
      case 4:
      	cin.ignore();
        listofcontacts.deletecontact();
        break;
      case 5:
        return 0;
      default:
        cout << "\nPlease Select a Valid option!!!";
      }
    cout << "\n\n";
    system("pause");
  }
}

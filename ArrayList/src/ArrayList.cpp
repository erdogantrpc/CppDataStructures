#include "ArrayList.hpp"
#include <cstdlib>

int main(){
	ArrayList<string> *names = new ArrayList<string>();
	int option = 0;
	int position;
	string name;
	
	do{
		system("CLS");
		cout<<"1. add name"<<endl;
		cout<<"2. del name"<<endl;
		cout<<"3. del name from position"<<endl;
		cout<<"4. add name from position"<<endl;
		cout<<"5. find position"<<endl;
		cout<<"6. number of names"<<endl;
		cout<<"7. first name"<<endl;
		cout<<"8. last name"<<endl;
		cout<<"9. list names"<<endl;
		cout<<"10. clear names"<<endl;
		cout<<"11. exit"<<endl;
		cout<<"option:";
		cin>>option;
		system("CLS");
		switch(option){
			case 1:
				cout<<"name:";
				cin.ignore();
				getline(cin,name);
				names->add(name);
			break;
			case 2:
				cout<<"name:";
				cin.ignore();
				getline(cin,name);
				names->remove(name);
			break;
			case 3:
				cout<<"position:";
				cin>>position;
				names->removeAt(position);
			break;
			case 4:
				cout<<"position:";
				cin>>position;
				cout<<"name:";
				cin.ignore();
				getline(cin,name);
				names->insert(position, name);
			break;
			case 5:
				cout<<"name:";
				cin.ignore();
				getline(cin,name);
				position = names->indexOf(name);
				cout<<"position:"<<position<<endl;
				cin.ignore();
				cin.get();
			break;
			case 6:
				cout<<"name sayisi:"<<names->size()<<endl;
				cin.ignore();
				cin.get();
			break;
			case 7:
				cout<<"ilk name:"<<names->first()<<endl;
				cin.ignore();
				cin.get();
			break;
			case 8:
				cout<<"son name:"<<names->last()<<endl;
				cin.ignore();
				cin.get();
			break;
			case 9:
				cout<<*names;
				cin.ignore();
				cin.get();
			break;
			case 10:
				names->clear();
			break;
			case 11:
			break;
			default:
				cout<<"wrong option"<<endl;
				cin.ignore();
				cin.get();
			break;
		}
	}while(option != 11);
	
	delete names;
	return 0;
}
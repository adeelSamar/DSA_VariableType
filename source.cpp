#include <iostream>
#include <string>
using namespace std;

struct var{
	void * data;
	int type;

	var(){
		type = 0;
		data = NULL;
	}

    ~var(){
        freeVar();
    }

	template <typename argtype>
	var(argtype arg){
		*(this) = arg;
	}

	void freeVar(){
		if(type == 0)
			return;
		if(type == 1)
			delete (int*)data;
		else if(type == 2)
			delete (double*)data;
		else if(type == 3)
			delete (string*)data;
		else if(type == 4)
			delete (char*)data;
	}

	void operator = (int arg){
		freeVar();
		type = 1;
		data = (int*) new int;
		*((int*)data) = arg;
	}

	void operator = (double arg){
		freeVar();
		type = 2;
		data = (double*) new double;
		*((double*)data) = arg;
	}

	void operator = (string arg){
		freeVar();
		type = 3;
		data = (string*) new string;
		*((string*)data) = arg;
	}

	void operator = (const char * arg){
		freeVar();
		type = 3;
		data = (string*) new string;
		*((string*)data) = arg;
	}

	void operator = (char arg){
		freeVar();
		type = 4;
		data = (char*) new char;
		*((char*)data) = arg;
	}
/*	
	void operator = (var arg){
		this->type = arg.type;
		cout << "Var arg Found";
		
		if(this->type == 1){
			data = (int*)new int;
			*((int*)data) = *((int*)arg.data);
		}
		
		if(this->type == 2){
			data = (double*)new double;
			*((double*)data) = *((double*)arg.data);
		}
		
		if(this->type == 3){
			data = (string*)new string;
			*((string*)data) = *((string*)arg.data);
		}
		
		if(this->type == 4){
			data = (char*)new char;
			*((char*)data) = *((char*)arg.data);
		}
	}
*/
	var(const var& obj){
		freeVar();
		this->type = obj.type;
		this->data = (int*) new int;
		*((int*)data) = *((int*)obj.data);
	}
	

	friend ostream& operator << (ostream& os, const var& obj);
};

ostream& operator << (ostream& os, const var& obj){
	if(obj.type == 1)
		os << *((int*)(obj.data));
	else if(obj.type == 2)
		os << *((double*)(obj.data));
	else if(obj.type == 3)
		os << *((string*)(obj.data));
	else if(obj.type == 4)
		os << *((char*)(obj.data));
	else
		os << "NULL";
}

class superiorLinkedList{
public:
	struct node{
		var data;
		node* next;

		node(){
			next = NULL;
		}

		
		~node(){
//			data.freeVar();
		}
	};

	node* head;

	superiorLinkedList(){
		head  = NULL;
	}

	void insertElementAtEnd(var value){
		if(head == NULL){
			head = new node;
			head->data = value;
			head->next = NULL;
			return;
		}
		node *trav = head;
		
		while(trav->next != NULL)
			trav = trav->next;
		
		cout << value << "SS ";
		var temp = value;
		trav->next = new node;
		trav = trav->next;
		cout << temp << "SS ";
		trav->data = value;
		trav->next = NULL;
	}

	void display(){
		node* trav = head;
		while(trav != NULL){
			cout << trav->data << '\t';
			trav = trav->next;
		}
	}
};

int main(){
	superiorLinkedList sll;
	string d = "sadsfbdf";
//	sll.insertElementAtEnd('s');
    sll.insertElementAtEnd(1);
    sll.insertElementAtEnd(2678);
    sll.insertElementAtEnd(4590);
    cout << endl;
	
	cout << endl;
}
int gmain(){
	string str = " kgs.";

	// Can see that
	var a[10];
	a[0] = "Robin";
	a[1] = " has ";
	a[2] = 10;
	a[3] = " kids";
	a[4] = ", each weighing ";
	a[5] = 66.67;
	a[6] = str;

	var b = 234;
	cout << b << endl;

	for(int i = 0; a[i].type > 0 && a[i].type < 5; i++)
		cout << a[i];
	cout << endl;

	return 0;
}

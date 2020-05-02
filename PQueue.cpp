#include<iostream>
using namespace std;
struct patient
{
	int ID;
	char name[30];
	int age;
	char type;
};
class node
{
	public:
	patient data;
	node *next;
	node()
	{
		next=NULL;
	}
	node(patient x)
	{
		next=NULL;
		data=x;
	}

};
class queue
{
	node *R, *F;
	public:
	queue()
	{
		R=F=NULL;
	}
	void insert(patient x);
	struct patient deletion();
	void display();
	int empty()
	{
		if(R==NULL)
		return 1;
		else
		return 0;
	}
};

void queue::display()
{
	patient x;
	node *p;
	cout<<"\n";
	if(F==NULL)
		cout<<"\nNo patients in this category\n";
	for(p=F;p!=NULL;p=p->next)
	{
		x=p->data;
		cout<<"\n"<<x.ID<<" "<<x.name<<" "<<x.age;
	}
}
void queue::insert(patient x)
{
	if(F==NULL)
		R=F=new node(x);
	else
	{
		R->next=new node(x);
		R=R->next;
	}
}
struct patient queue:: deletion()
{
	node *p;
	patient x;
	if(F==NULL)
	{
		cout<<"\nList is empty\n";
		return x;
	}
	else
	{
		x=F->data;
		p=F;
		F=F->next;
		if(F==NULL)
			R=NULL;
		delete p;
		return(x);
	}
}
class pq
{
	queue q[3];
	public:
	void arrival();
	void service();
	void print();
};
void pq::arrival()
{
	patient x;
	char a;
	cout<<"\nEnter registration number : ";
	cin>>x.ID;
	cout<<"\nEnter name of patient : ";
	cin>>x.name;
	cout<<"\nEnter age of patient : ";
	cin>>x.age;
	cout<<"\nEnter type of patient:\nS for serious\nM for medium illness\nG for general : ";
	cin>>x.type;
	a=x.type;
	switch(a)
	{
		case 'S':
		q[0].insert(x);
		break;
		case 'M':
		q[1].insert(x);
		break;	
		case 'G':
		q[2].insert(x);
		break;	
		default:
		cout<<"\nWrong patient type\n";
	}
}
void pq::service()
{
	int i;
	patient x;
	i=0;
	while(i<3 && q[i].empty())
		i++;
	if(i==3)
		cout<<"\nNo patients left to service";
	else
	{
		x= q[i].deletion();
		cout<<"\n"<<x.ID<<" "<<x.name<<" "<<x.age;
	}
}
void pq:: print()
{
	cout<<"\nSerious patients";
	q[0].display();
	cout<<"\nMedium illness patients";
	q[1].display();
	cout<<"\nGeneral illness patients";
	q[2].display();
}
int main()
{
	int op;
	pq q;
	do
	{
		cout<<"\n1.Arrival of patient \n2.Service a patient \n3.Display \n4.Quit \nEnter your choice";
		cin>>op;	
		switch(op)
		{
			case 1:
			q.arrival();
			break;
			case 2:
			q.service();
			break;
			case 3:
			q.print();
			break;		
		}	
	}while(op>0 && op<4);
	return 0;
}

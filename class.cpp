#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class members{
	private:
		 
		string member_name;
		int member_age;
		
	 
	public:
		int member_id;
		void read();
		void display();
		
	
};
void members::read(){
	cout<<"enter membership id:";
	cin>>member_id;
	cout<<"\nenter member name: ";
	cin>>member_name;
	cout<<"\nenter member age: ";
	cin>>member_age;
}
void members::display(){
	cout<<"\nmembership id: "<< member_id;
	cout<<"\nmember name  : "<< member_name;
	cout<<"\nmember age  : "<< member_age;
 }
 
int main(int argc, char** argv) {
	// members m;
	// m.read();
	// m.display();
	members m[50],temp;
	int choice;
	int n,x,i;
	do{
		cout<<"\n1.Accept\n2.Display\n3.Insert\n4.Delete\n5.Search\n6Upadate\n7.Sort\n8.Exit\n enter your choice";
	    cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"\n how many members";
			cin>>n;
			for(int i=0;i<n;i++){
				m[i].read();
			}
 			break;
		case 2:
			cout<<"\nmember detail";
			for (int i= 0; i<n; i++)
			{
				m[i].display();
  			}
			break;
		case 3:
			int loc;
			cout<<"\nEnter the location";
 			cin>>n;
			if (loc>n)
			{
				cout<<"invalid choice";
			}
			else
			{
				for (int i = n-1; i >=  loc -1; i++)
				{
					 m[i+1] = m[i];
				}
				m[loc -1].read();
				n++;
			}
			break;
		case 4:
			int loc;
			cout<<"\nEnter the number to delete";
 			cin>>x;
			int flag=0;
			for (int i = 0; i < n; i++)
			{
				if(m[i].member_id == x)
				{
					flag=1;
					break;
				}
 			}
			
			if (flag == 0)
			{
				cout<<"element not found";
			}
			else
			{
				for (int i ; i < n-1; i++)
				{
					 m[i] = m[i+1];
				}
				n--;
				m[i].read();
			}
			break;
		case 5:
			int loc;
			cout<<"\nEnter the number to search";
 			cin>>x;
			int flag=0;
			for (int i = 0; i < n; i++)
			{
				if(m[i].member_id == x)
				{
					flag=1;
					break;
				}
 			}
			
			if (flag == 0)
			{
				cout<<"element not found";
			}
			else
			{
				for (int i ; i < n-1; i++)
				{
					 m[i] = m[i+1];
				}
				n--;
				cout<<"element fount at "<<i<<" position"<<endl;
			}
			break;
		case 6:
			int loc;
			cout<<"\nEnter the number to update";
 			cin>>x;
			int flag=0;
			for (int i = 0; i < n; i++)
			{
				if(m[i].member_id == x)
				{
					flag=1;
					break;
				}
 			}
			
			if (flag == 0)
			{
				cout<<"element not found";
			}
			else
			{
				for (int i ; i < n-1; i++)
				{
					 m[i] = m[i+1];
				}
				n--;
				cout<<"element fount at "<<i<<" position"<<endl;
			}
			break;
		case 7:
			members temp;
			for ( i = 0; i < n-1; i++)
			{
			 	for (int j = 0; j < n-1; j++)
				{
					if (m[j].member_id >m[j+1].member_id )
					{
						temp = m[j];
						m[j]=m[j+1];
						m[j+1]=temp;

 					}
  				}
 			}
			break;
		case 8:

			 
			break;
		
		default:
			break;
		}
        

	}while(choice!=n);
	
	return 0;
}

#include <iostream>
#include <string.h>

using namespace std;

int total_rooms = 10;
int price_per_luxury_room = 2000;
int price_per_duplex_room = 1500;
int price_per_normal_room = 1000;
int extra_price_per_ac_room = 500;
int count = 0;
int cid = 1;
class Welcome{
	public:
	void show()
	{
		cout<<"\n1.Book A Room";
		cout<<"\n2.Customers Staying";
		cout<<"\n3.Rooms Allotted";
		cout<<"\n4.Checkout";
		cout<<"\n5.Exit"<<endl;
	}
};
class Hotel{
	protected:
	int c_id;
	char name[20];
	int phone_no;
	char id_proof[20];
	char city[10];
	public:
	int get_cid()
	{
		return c_id;
	}
	virtual void get_data()
	{	c_id = cid;
		cid++;
		cout<<"Enter your name"<<endl;
		cin.getline(name, 20);
		cout<<"Enter your phone no"<<endl;
		cin>>phone_no;
		cout<<"Enter your id proof type"<<endl;
		cin.ignore();
		cin.getline(id_proof, 20);
		cout<<"Enter your city"<<endl;
		cin>>city;
	}
	virtual int get_rooms() = 0;
	virtual void display()
	{
		cout<<"Customer Id: "<<c_id<<endl<<"Name: "<<name<<endl<<"Phone No: "<<phone_no<<endl<<"Id Proof type: "<<id_proof<<endl<<"City: "<<city<<endl;
	}
};
class Room:public Hotel{
	protected:
	int date;
	char month[10];
	int year;
	int no_of_rooms;
	int ac;
	int room_type;
	public:
	void get_data()
	{
		Hotel::get_data();
		cout<<"Enter booking date"<<endl;
		cin>>date;
		cin.ignore();
		cin>>month;
		cin>>year;
		cout<<"Enter 1 for Luxury Room,\n\t 2 for Deluxe Room,\n\t 3 for Normal Room"<<endl;
		cin>>room_type;
		cout<<"Available Rooms: "<<total_rooms<<endl;
		cout<<"Enter the number of rooms required(₹2000 per room)"<<endl;
		cin>>no_of_rooms;
		total_rooms -= no_of_rooms;
		cout<<"Press 1 for ac room or 0 for non ac room"<<endl;
		cin>>ac;
	}
	void display()
	{
		Hotel::display();
		cout<<"Room Booking Date: "<<date<<", "<<month<<", "<<year<<endl;
		cout<<"No of Room booked: "<<no_of_rooms<<endl;
		if(ac == 1)
			cout<<"AC Room: Yes"<<endl;
		else
			cout<<"AC Room: No"<<endl;
		cout<<"Type of Room: ";
		switch(room_type)
		{
			case 1:
				cout<<"Luxury"<<endl;
				break;
			case 2:
				cout<<"Deluxe"<<endl;
				break;
			case 3:
				cout<<"Normal"<<endl;
				break;
			default:
				break;
		}
	}
};
class Bill:public Room{
	float total_bill;
	public:
	int get_rooms()
	{
		return no_of_rooms;
	}
	void display()
	{
		switch(room_type)
		{
			case 1:
				total_bill += price_per_luxury_room*no_of_rooms;
				break;
			case 2:
				total_bill += price_per_duplex_room*no_of_rooms;
				break;
			case 3:
				total_bill += price_per_normal_room*no_of_rooms;
				break;
			default:
				break;
		}
		if(ac == 1)
			total_bill += extra_price_per_ac_room*no_of_rooms;
		Room::display();
		cout<<"Total Bill = "<<total_bill<<endl;
	}
};
Hotel *hptr[10];
Bill a[10];
void enter_record()
{
	int choice;
	do{
		hptr[count] = &a[count];
		hptr[count] -> get_data();
		count++;
		cout<<"Press 1 to continue or 0 to exit";
		cin>>choice;
		cin.ignore();
	}
	while(choice == 1);
}
void show_record()
{
	for(int i = 0; i < count;i ++)
	{
		hptr[i] -> display();
	}
}
void check_out()
{
	int c, id;
	cout<<"Enter the customer id to checkout"<<endl;
	cin>>c;
	for(int i = 0; i < count; i++)
	{
		id = hptr[i] -> get_cid();
		if(c == id)
		{
			total_rooms += hptr[i] -> get_rooms();
			hptr[i] ->display();
		}
	}
	for (int j = c - 1; j < count - 1; j++)
       	{
       		hptr[j] = hptr[j+1];
	}
	count--;
}
void start()
{
	cout<<"\n\t\t\t\t*******************************";
        cout<<"\n\t\t\t\t** WELCOME TO EMIRATES PALACE**";
        cout<<"\n\t\t\t\t*******************************";
}
int main()
{
	start();
	int option;
	Welcome w;
	w.show();
        cin>>option;
        cin.ignore();
	while(option != 5)
	{
		if(option == 1)
		{
			enter_record();
		}
		else if(option == 2)
		{
			show_record();
		}
		else if(option == 3)
		{
			cout<<"Total no of rooms allocated: "<<(10-total_rooms)<<endl;
		}
		else if(option == 4)
		{
			check_out();
		}
		w.show();
		cin>>option;
		if(option == 5)
		{
			cout<<"\n\t\t\t\t*********************";
		    	cout<<"\n\t\t\t\t*Thanks For Visiting*";
		    	cout<<"\n\t\t\t\t*                   *";
		    	cout<<"\n\t\t\t\t*    Visit Again    *";

		    	cout<<"\n\t\t\t\t*********************\n";
		}
	}
	return 0;
}

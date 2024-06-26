#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class productcatalog //Class for Product Categories 
{
protected:
	char category[50];   //Name of the Category
	char subcategory[10]; //Name of the Sub Category
	char product[15]; //Name of the Product
public:
	productcatalog()
	{
		*category = *subcategory = *product = '0';
	}
	void addproduct() //Class for user to add products to Product Catalog
	{
		int choice = 0;
		system("CLS");
		cout << "------------------------------Welcome to Product Catalog------------------------------" << endl;
		cout << endl;

		cout << "Here You can add the products to your Product Catalog" << endl;
		cin.ignore();
		system("CLS");
		cout << "Choose the Category of the Product" << endl;
		cout << "Category : " << endl;
		cout << "1.Food\n2.Personal Hygiene\n3.House Hold Cleaning" << endl;
		cout << "Category : ";
		cin.getline(category, 49);
		cout << "Enter the Choice : ";
		cin >> choice;
		//Menu for product addition
		if (choice == 1)
		{
			cout << "Choose Subchoice " << endl;
			cout << "1.Perishable Goods(PG)\n2.Non Perishable Goods(NPG)" << endl;
			cout << "Sub Category : ";
			cin >> subcategory;
			cout << "Enter the Product : ";
			cin >> product;
			choice = 0;
		}

		if (choice == 2)
		{
			*subcategory = '0';
			cout << "Enter the Product : ";
			cin >> product;
		}
		if (choice == 3)
		{
			*subcategory = '0';
			cout << "Enter the Product : ";
			cin >> product;
		}

		cin.ignore();
	}
	void productlist()
	{

	}
};
class Inventory : public productcatalog   //Class for Inventory whcih inherits from Product Catalog
{
protected:
	char item[15];
	char quantity[10];
	char measurement[15];
	int priceperitem;
public:
	Inventory()
	{
		*item = *quantity = *measurement = '0';
		priceperitem = 0;
	}
	void additem()
	{
		cout << "Enter the Item to add to your Inventory" << endl;
		cin >> item;
		cout << "Enter the quantity of the item to save to your Inventory" << endl;
		cin >> quantity;                                                                //Addition of a product in an inventory
		cout << "Enter the measurement unit of the Item." << endl;
		cin >> measurement;
		cout << "Enter Price Per Item : ";
		cin >> priceperitem;
	}

	char* getitem()
	{                                                //return of item name
		return item;
	}
	int getprice()
	{
		return priceperitem;           //return of item price
	}
};
class FeedBack {
protected:
	char review[30];              //Feedback from customers

public:
	FeedBack()
	{
		*review = '0';
	}
	void givefeedback()
	{
		system("CLS");
		cout << "How Was Your Experince. " << endl;
		cout << "Select the Options" << endl;
		cout << "Poor\nFair\nGood\nExcellent\nExceptional" << endl;
		cout << "Enter your Feedback : ";
		cin >> review;
		ofstream myFile("feedback.dat", ios::binary | ios::app);
		if (myFile.write((char*)&review, sizeof(review)))
			cout << "Object Successfully Inserted" << endl;
		else                                              //FeedBack Input
			cout << "Object Insertion Failed" << endl;
		myFile.close();
		cin.ignore();


	}
	void showfeedback()
	{
		cout << review << endl;       //Preview of the Customer's Feedback
	}

};
class User            //Class for Account Registration and Login
{
	int check;
	char recheck[20];
protected:
	char cnic[20];
	char password[20];
public:
	User()
	{
		check = 0;
		*recheck = *password = *cnic = '0';

	}
	bool makeaccount()  //Function for Account Registration
	{

		system("CLS");
		cout << "Enter your CNIC : ";
		cin >> cnic;

		check = 0;
		if (check == 0)
		{
			cout << "Password Must Have 1 Upper Case, 1 Lower Case and 9 Digits" << endl;
			cout << "Enter Your Password : ";
			cin >> password;
		}

		for (int i = 0; i < 9; i++)
		{
			if ((int)password[i] > 64 && (int)password[i] < 91)
			{
				check++;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if ((int)password[i] > 96 && (int)password[i] < 123)
			{
				check++;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if ((int)password[i] > 47 && (int)password[i] < 58)
			{
				check++;
			}
		}


		if (check == 9)
		{
			cout << "Enter your Password Again : ";
			cin >> recheck;
			if (*password == *recheck)
			{
				cout << "Congratulation! Your Account has been created. " << endl;
				return true;
			}
			else
			{
				cout << "Password Doesnot Match" << endl;
				cout << "Sorry! Account cannot be created" << endl;
			}

		}
		else
		{
			cout << "Wrong Syntax" << endl;
			cout << "Sorry! Account cannot be created" << endl;
			return false;
		}



	}


	char* getcnic()      //Getter for CNIC
	{
		return cnic;
	}
	char* getpassword() //Getter for Password
	{
		return password;
	}
	bool login(char* a, char* b, char* c);

};

class customer : public User, public FeedBack  //Customer Class
{
	char name[10];
	char gender[10];
	char phonenumber[15];
	char address[50];
public:
	customer()
	{
		*phonenumber = *name = *gender = *address = '0';


	}
	//Setters for the Class
	void setname(char* a)
	{
		*name = *a;
	}
	void setgender(char* a)
	{
		*gender = *a;
	}
	void setaddress(char* a)
	{
		*address = *a;
	}
	void setnumber(char* a)
	{
		*phonenumber = *a;

	}
	char* gaddress()
	{
		return address;
	}
	bool login(char* a, char* b, char* c);
	friend int delivery(char* a, char* b, char* c);
	void display()
	{

		cout << "Name : " << name << endl;
		cout << "CNIC : " << cnic << endl;
		cout << "Password : " << password << endl;
		cout << "Phone Number : " << phonenumber << endl;        //Display Function
		cout << "Gender : " << gender << endl;
		cout << "Address : " << address << endl;
	}
};
class admin : public User, public productcatalog        //Admin Class
{
protected:
	string login = "21i2654";
	string password = "Kh2102044";
public:
	bool status(string a, string b)           //Login Status
	{
		if (login == a && password == b)
		{

			cout << "*******************************************LoginSuccessful*******************************************" << endl;
			cin.ignore();
			return true;
		}
		else
		{
			cout << "Invalid ID or Password" << endl;
			cout << "*******************************************LoginFailed*******************************************" << endl;
			cin.ignore();
			return false;
		}
	}
};
class store :public productcatalog, public Inventory //Store Class
{
protected:
	string city;
public:
	store()
	{
		city = '0';
	}
	string makestore(string c)
	{
		string temp;
		string j = ".dat";
		temp = c + j;
		cout << temp << endl;
		city = c;
		cout << "******************************Store has been Created******************************" << endl;
		return temp;
	}
	void destroystore()
	{
		city = '0';
	}

};


class manager : public User, public store    //manager class
{
protected:
	char city[10];
	char name[10];
public:
	manager()
	{
		*city = *name = '0';
	}
	void setname(char* a)
	{
		*name = *a;
	}
	void setCity(char* a)
	{
		*city = *a;
	}
	bool login(char* a, char* b, char* c);

};
bool login(char* a, char* b, char* c)
{
	system("CLS");
	char check[20];                         //Function for checking LogIn Status
	char recheck[20];
	if (*c == 'c' || *c == 'C')
	{
		customer temp;
		ifstream file1("customer.dat", ios::binary | ios::in);
		while (file1.read((char*)&temp, sizeof(temp)))
		{
			*check = *(temp.getcnic());
			*recheck = *(temp.getpassword());
			if (*check == *a && *recheck == *b)
			{
				cout << "Login Successful" << endl;
				*check = *(temp.gaddress());
				return true;
			}
			else
			{
				cout << "You have Entered wrong ID or Password" << endl;
				return false;
			}
		}
		cin.ignore();
	}
	if (*c == 'b' || *c == 'B')
	{
		manager temp;
		*check = *(temp.getcnic());
		*recheck = *(temp.getpassword());

		ifstream file1("manager.dat", ios::binary | ios::in);
		while (file1.read((char*)&temp, sizeof(temp)))
		{

			if (*check == *a)
			{
				cout << "Login Successful" << endl;
				return true;
			}
			else
			{
				cout << "You have Entered wrong ID or Password" << endl;
				return false;
			}
		}
		cin.ignore();

	}
	if (c == "a" || c == "A")
	{
		admin temp;
		ifstream file1("admin.dat", ios::binary | ios::in);
		while (file1.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getcnic() == a)
			{
				cout << "Login Successful" << endl;
				return true;
			}
			else
			{
				cout << "You have Entered wrong ID or Password" << endl;
				return false;
			}
		}

	}

}
char* getaddress(char* a)
{
	return a;
}
class cart :public Inventory
{
	char itemname[20];
	int pieces;
public:
	cart()
	{
		*itemname = '0';
		pieces = 0;
	}
	void fillcart(char* a, int b)
	{
		*itemname = *a;
		pieces = b;
	}
	void showcart()
	{
		system("CLS");
		cout << pieces << " " << itemname << endl;
	}

};
class checkout : public cart
{
protected:
	int amount;
	int delivery_fee;
	int total_bill;
	char number[15];
public:
	checkout()
	{
		amount = delivery_fee = total_bill = 0;
		*number = '0';
	}
	void Checkout(int d, int a, char *z)
	{
		amount = a;
		delivery_fee = d;
		total_bill = a + d;
		*number = *z;
		system("CLS");
		cout << "Thank You For Shopping." << endl;
		cout << "Your Total Bill is : " << total_bill << endl;
		cout << "Please Visit Again." << endl;
		cout << endl;
		cin.ignore();
	}


};
int delivery(char* a, char* b, char* c)
{
	char check[20];                         //Function for checking LogIn Status
	char recheck[20];
	char add[20];
	customer temp;
	ifstream file1("customer.dat", ios::binary | ios::in);
	while (file1.read((char*)&temp, sizeof(temp)))
	{
		*check = *(temp.getcnic());
		*recheck = *(temp.getpassword());
		*add = *(temp.gaddress());
		if (*check == *a && *recheck == *b)
		{
			if (*add == *c)
			{
				return 30;
			}
			else
			{
				return 50;
			}
		}
		else
		{
			return 50;
		}
	}
	cin.ignore();

}

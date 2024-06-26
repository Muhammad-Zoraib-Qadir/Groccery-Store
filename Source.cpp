#include<iostream>
#include<fstream>
#include<string>
#include"Header.h"
using namespace std;
int main()
{
	int branch;
	int choice;
	int count = 0;
	char Choice[1];
	char a[15];
	char b[50];               //Variables
	char c[50];
	char cnic[50];
	char password[50];
	char address[15];
	int price;
	int d;
	char t[15];
	int total = 0;
	string filename;
	bool check;
	while (true)
	{
		cout << "------------------------------WELCOME------------------------------" << endl;
		cout << "-------------------------Enter Your Choice-------------------------" << endl;
		cout << "Admin    : A" << endl;
		cout << "Manager  : B" << endl;             //Main Menu
		cout << "Customer : C" << endl;
		cout << "Your Choice : ";
		cin >> Choice;
		if (*Choice == 'c' || *Choice == 'C')
		{
			customer obj;
			system("CLS");
			cout << "1.Login " << endl;
			cout << "2.Signup " << endl;           //Customer Menu
			cout << "Your Choice : ";
			cin >> choice;
			if (choice == 1)
			{
				system("CLS");
				cout << "------------------------------------------LOGIN MENU------------------------------------------" << endl;
				cout << "Enter your CNIC : ";
				cin >> cnic;
				cout << "Enter your Password : ";
				cin >> password;
				check = login(cnic, password, Choice);
				if (check == 1)
				{											//Login Status Checker
					system("CLS");
					cout << "1.Online Shopping\n2.LogOut" << endl;
					cout << "Choice : ";
					cin >> choice;
					if (choice == 2)
					{
						system("CLS");
						continue;
					}
					if (choice == 1)
					{
						system("CLS");
						cout << "Enter the Desire Store You Want to Shop." << endl;
						cout << "1.Lahore\n2.Islamabad\n3.Karachi" << endl;
						cout << "Enter Your Branch : " << endl;
						cin >> branch;
						if (branch == 1)
						{
							system("CLS");
							char bo[] = "Lahore";
							cout << "Reviews of the Store . " << endl;
							FeedBack temp;
							ifstream myFile("feedback.dat", ios::binary);
							while (myFile.read((char*)&temp, sizeof(temp))) {
								temp.showfeedback();
							}
							myFile.close();
							cin.ignore();
							cout << "Enter 1 to search an item\nEnter 2 to buy item" << endl;
							cin >> branch;
							Inventory s;
							while (branch == 1)
							{

								cout << "Enter the Item to search : ";
								cin >> a;
								Inventory temp;
								ifstream myFile("Lahore.dat", ios::binary);
								count = 0;
								while (myFile.read((char*)&temp, sizeof(temp)))
								{
									if (temp.getitem() == a) {
										cout << "Item Found" << endl;
										cout << temp.getprice();
										price = temp.getprice();
										myFile.close();
										count = 1;

									}
								}
								if (count != 1)
								{
									cout << "Item Not Found" << endl;
								}
								cout << endl;
								cout << endl;
								cout << "Press 1 to search an Item \nPress 2 to Buy an Item." << endl;
								cout << "choice : ";
								cin >> branch;

							}
							if (branch == 2)
							{
								remove("cart.dat");
								while (branch != 0)
								{
									cout << "Enter the Item : ";
									cin >> a;
									cout << "Quantity : ";
									cin >> count;
									cart obj;
									obj.fillcart(a, count);
									ofstream myFile("cart.dat", ios::binary | ios::app);
									if (myFile.write((char*)&obj, sizeof(obj)))              //Binary File handling
										cout << "Object Successfully Inserted" << endl;
									else
										cout << "Object Insertion Failed" << endl;
									myFile.close();
									cin.ignore();
									ifstream myFile1("cart.dat", ios::binary);
									while (myFile1.read((char*)&obj, sizeof(obj))) {
										obj.showcart();
									}
									myFile.close();
									total = total + (count * 50);
									cout << "Enter 1 to continue\nEnter 0 to checkout " << endl;
									cout << "Choice : ";
									cin >> branch;
								}
							}
							if (branch == 0)
							{

								cout << "1.COD\n2.Online Payment(Easypaisa,Jazz Cash etc)" << endl;
								cout << "Enter the Method of the Payment : ";
								cin >> count;
								if (count == 1)
								{
									d = delivery(cnic, password, bo);
									checkout obj;
									obj.Checkout(d, total, 0);

									ofstream myFile("checkout.dat", ios::binary | ios::app);
									if (myFile.write((char*)&obj, sizeof(obj)))              //Binary File handling
										cout << "Object Successfully Inserted" << endl;
									else
										cout << "Object Insertion Failed" << endl;
									myFile.close();
									cin.ignore();
									customer temp;
									temp.givefeedback();
								}
								if (count == 2)
								{
									cout << "Enter Account Number : ";
									cin >> t;
									checkout obj;
									obj.Checkout(0, total, t);

									ofstream myFile("checkout.dat", ios::binary | ios::app);
									if (myFile.write((char*)&obj, sizeof(obj)))              //Binary File handling
										cout << "Object Successfully Inserted" << endl;
									else
										cout << "Object Insertion Failed" << endl;
									myFile.close();
									cin.ignore();
									customer temp;
									temp.givefeedback();
								}
							}
							cin.ignore();
						}
						if (branch == 2)
						{
							char bo[] = "Islamabad";
							system("CLS");
							cout << "Reviews of the Store . " << endl;
							FeedBack temp;
							ifstream myFile("feedback.dat", ios::binary);
							while (myFile.read((char*)&temp, sizeof(temp))) {
								temp.showfeedback();
							}
							myFile.close();
							cin.ignore();
							cout << "Enter 1 to search an item\nEnter 2 to buy item" << endl;
							cin >> branch;
							Inventory s;
							while (branch == 1)
							{

								cout << "Enter the Item to search : ";
								cin >> a;
								Inventory temp;
								ifstream myFile("Islamabad.dat", ios::binary);
								count = 0;
								while (myFile.read((char*)&temp, sizeof(temp)))
								{
									if (temp.getitem() == a) {
										cout << "Item Found" << endl;
										cout << temp.getprice();
										price = temp.getprice();
										myFile.close();
										count = 1;

									}
								}
								if (count != 1)
								{
									cout << "Item Not Found" << endl;
								}
								cout << endl;
								cout << endl;
								cout << "Press 1 to search an Item\nPress 2 to Buy an Item." << endl;
								cout << "choice : ";
								cin >> branch;

							}
							if (branch == 2)
							{
								remove("cart.dat");
								while (branch != 0)
								{
									cout << "Enter the Item : ";
									cin >> a;
									cout << "Quantity : ";
									cin >> count;
									cart obj;
									obj.fillcart(a, count);
									ofstream myFile("cart.dat", ios::binary | ios::app);
									if (myFile.write((char*)&obj, sizeof(obj)))              //Binary File handling
										cout << "Object Successfully Inserted" << endl;
									else
										cout << "Object Insertion Failed" << endl;
									myFile.close();
									cin.ignore();
									ifstream myFile1("cart.dat", ios::binary);
									while (myFile1.read((char*)&obj, sizeof(obj))) {
										obj.showcart();
									}
									myFile.close();

									total = total + (count * 50);
									cout << "Enter 1 to continue\nEnter 0 to checkout " << endl;
									cout << "Choice : ";
									cin >> branch;
								}
							}
							if (branch == 0)
							{
								cout << "1.COD\n2.Online Payment(Easypaisa,Jazz Cash etc)" << endl;
								cout << "Enter the Method of the Payment : ";
								cin >> count;
								if (count == 1)
								{
									d = delivery(cnic, password, bo);
									checkout obj;
									obj.Checkout(d, total, 0);

									ofstream myFile("checkout.dat", ios::binary | ios::app);
									if (myFile.write((char*)&obj, sizeof(obj)))              //Binary File handling
										cout << "Object Successfully Inserted" << endl;
									else
										cout << "Object Insertion Failed" << endl;
									myFile.close();
									cin.ignore();
									customer temp;
									temp.givefeedback();
								}
								if (count == 2)
								{
									cout << "Enter Account Number : ";
									cin >> t;
									checkout obj;
									obj.Checkout(0, total, t);

									ofstream myFile("checkout.dat", ios::binary | ios::app);
									if (myFile.write((char*)&obj, sizeof(obj)))              //Binary File handling
										cout << "Object Successfully Inserted" << endl;
									else
										cout << "Object Insertion Failed" << endl;
									myFile.close();
									cin.ignore();
									customer temp;
									temp.givefeedback();
								}
							}
							cin.ignore();
						}
						if (branch == 3)
						{
							char bo[] = "Karachi";
							system("CLS");
							cout << "Reviews of the Store . " << endl;
							FeedBack temp;
							ifstream myFile("feedback.dat", ios::binary);
							while (myFile.read((char*)&temp, sizeof(temp))) {
								temp.showfeedback();
							}
							myFile.close();
							cin.ignore();
							cout << "Enter 1 to search an item\n Enter 2 to buy item" << endl;
							cin >> branch;
							Inventory s;
							while (branch == 1)
							{

								cout << "Enter the Item to search : ";
								cin >> a;
								Inventory temp;
								ifstream myFile("Karachi.dat", ios::binary);
								count = 0;
								while (myFile.read((char*)&temp, sizeof(temp)))
								{
									if (temp.getitem() == a) {
										cout << "Item Found" << endl;
										cout << temp.getprice();
										price = temp.getprice();
										myFile.close();
										count = 1;

									}
								}
								if (count != 1)
								{
									cout << "Item Not Found" << endl;
								}
								cout << endl;
								cout << endl;
								cout << "Press 1 to search an Item \nPress 2 to Buy an Item." << endl;
								cout << "choice : ";
								cin >> branch;

							}
							if (branch == 2)
							{
								remove("cart.dat");
								while (branch != 0)
								{
									cout << "Enter the Item : ";
									cin >> a;
									cout << "Quantity : ";
									cin >> count;
									cart obj;
									obj.fillcart(a, count);
									ofstream myFile("cart.dat", ios::binary | ios::app);
									if (myFile.write((char*)&obj, sizeof(obj)))              //Binary File handling
										cout << "Object Successfully Inserted" << endl;
									else
										cout << "Object Insertion Failed" << endl;
									myFile.close();
									cin.ignore();
									ifstream myFile1("cart.dat", ios::binary);
									while (myFile1.read((char*)&obj, sizeof(obj))) {
										obj.showcart();
									}
									myFile.close();
									total = total + (count * 50);
									cout << "Enter 1 to continue\nEnter 0 to checkout " << endl;
									cout << "Choice : ";
									cin >> branch;
								}
							}
							if (branch == 0)
							{
								cout << "1.COD\n2.Online Payment(Easypaisa,Jazz Cash etc)" << endl;
								cout << "Enter the Method of the Payment : ";
								cin >> count;
								if (count == 1)
								{
									d = delivery(cnic, password, bo);

									checkout obj;
									obj.Checkout(d, total, 0);

									ofstream myFile("checkout.dat", ios::binary | ios::app);
									if (myFile.write((char*)&obj, sizeof(obj)))              //Binary File handling
										cout << "Object Successfully Inserted" << endl;
									else
										cout << "Object Insertion Failed" << endl;
									myFile.close();
									cin.ignore();
									customer temp;
									temp.givefeedback();
								}
								if (count == 2)
								{
									cout << "Enter Account Number : ";
									cin >> t;
									checkout obj;
									obj.Checkout(0, total, t);

									ofstream myFile("checkout.dat", ios::binary | ios::app);
									if (myFile.write((char*)&obj, sizeof(obj)))              //Binary File handling
										cout << "Object Successfully Inserted" << endl;
									else
										cout << "Object Insertion Failed" << endl;
									myFile.close();
									cin.ignore();
									customer temp;
									temp.givefeedback();
								}
							}
							cin.ignore();
						}
					}
				}
				else
				{
					cout << "Try Again" << endl;
				}
			}
			if (choice == 2)
			{
				system("CLS");

				check = obj.makeaccount();
				*a = *b = *c = '0';      //Account Registration
				if (check == true)
				{

					cout << "Enter Your First Name : ";
					cin >> b;
					obj.setname(b);
					cout << "Enter Your Phone Number : ";
					cin >> a;
					obj.setnumber(a);
					cout << "Enter Your Gender : ";
					cin >> a;
					obj.setgender(a);
					cout << "Enter Your City : ";
					cin >> c;
					obj.setaddress(c);
					ofstream myFile("customer.dat", ios::binary | ios::app);
					if (myFile.write((char*)&obj, sizeof(obj)))              //Binary File handling
						cout << "Object Successfully Inserted" << endl;
					else
						cout << "Object Insertion Failed" << endl;
					myFile.close();
					cin.ignore();

				}
			}

		}
		if (*Choice == 'a' || *Choice == 'A')
		{
			admin member;
			system("CLS");
			ofstream myFile("admin.dat", ios::binary | ios::out);
			if (myFile.write((char*)&member, sizeof(member)))
			{                                                     //Binary File handling

			}
			else
				cout << "Object Insertion Failed" << endl;
			myFile.close();
			cout << "*******************************************Welcome Sir********************************************" << endl;
			cout << endl;
			cout << "***************************************Login to your account***************************************" << endl;
			cout << " ID : ";
			cin >> a;
			cout << "Password : ";                  //LOGIN Menu
			cin >> b;
			check = member.status(a, b);
			if (check == 1)
			{
				system("CLS");
				cout << "***************************************Welcome Back Sir!***************************************" << endl;
				cout << "**********************************What would you like to do?***********************************" << endl;
				cout << endl;				//Main Menu for the Admin
				cout << endl;
				cout << "********************************************1.Stores********************************************" << endl;
				cout << "********************************************2.Accounts********************************************" << endl;
				cout << "********************************************3.Logout********************************************" << endl;
				cout << endl;
				cout << "Your Choice : ";
				cin >> choice;
				if (choice == 3)
				{
					system("CLS");
					continue;

				}
				if (choice == 1)
				{
					system("CLS");
					cout << "1.Make A store" << endl;
					cout << "2.Manage Product Catalog" << endl;

					cout << "Your Choice : ";
					cin >> choice;
					if (choice == 1)
					{
						store s;
						cout << "Enter Location of the Branch : ";
						cin >> c;
						filename = s.makestore(c);
						cout << endl;                                //Store Making
						cout << "Sir!" << endl;
						cout << "Sir you should make a Manager for  the Store!";
						cout << endl;



					}
					if (choice == 2)
					{

						productcatalog temp;
						temp.addproduct();

						ofstream myFile("productcatalog.dat", ios::binary | ios::app);
						if (myFile.write((char*)&temp, sizeof(temp)))
						{                                                     //Binary File Handling
							cout << "Object Inserted Successfully" << endl;
						}
						else
							cout << "Object Insertion Failed" << endl;
						myFile.close();
						choice = 0;
					}

				}
				if (choice == 2)
				{
					system("CLS");
					cout << "Make Manager." << endl;
					cin.ignore();
					cin.ignore();
					manager m;
					check = m.makeaccount();
					*a = *b = *c = '0';
					if (check == 1)
					{
						cout << "Enter Name : ";
						cin >> a;
						cout << "Branch City : ";
						cin >> b;
						m.setname(a);
						m.setCity(b);

					}
					ofstream myFile("manager.dat", ios::binary | ios::app);
					if (myFile.write((char*)&m, sizeof(m)))
						cout << "Object Successfully Inserted" << endl;
					else
						cout << "Object Insertion Failed" << endl;
					myFile.close();
					cin.ignore();

				}
			}
		}
		if (*Choice == 'B' || *Choice == 'b')

		{
			system("CLS");

			cout << "1.Login " << endl;
			cout << "2.Signup " << endl;
			cout << "Your Choice : ";
			cin >> choice;
			if (choice == 2)
			{                                                      //Manager Account Registration
				system("CLS");

				cout << "Admin login recquired to make an account" << endl;
				admin g;
				cout << "Enter ID : ";
				cin >> a;
				cout << "Enter Password : ";
				cin >> b;
				check = g.status(a, b);
				if (check == 1)
				{
					system("CLS");

					cout << "Admin Login Successful" << endl;
					cout << "Now you can make an account" << endl;
					cin.ignore();
					manager m;
					check = m.makeaccount();
					*a = *b = *c = '0';
					if (check == 1)
					{
						cout << "Enter Name : ";
						cin >> a;
						cout << "Branch City : ";
						cin >> b;
						m.setname(a);
						m.setCity(b);

					}
					ofstream myFile("manager.dat", ios::binary | ios::app);
					if (myFile.write((char*)&m, sizeof(m)))
						cout << "Object Successfully Inserted" << endl;
					else
						cout << "Object Insertion Failed" << endl;
					myFile.close();
					cin.ignore();

				}
			}
			if (choice == 1)
			{
				system("CLS");
				cout << "Enter your CNIC : ";
				cin >> a;
				cout << "Enter Your Password : ";
				cin >> b;
				system("CLS");
				cout << "1.Lahore\n2.Islamabad\n3.Karachi" << endl;
				cout << "Enter Your Branch : " << endl;
				cin >> branch;
				//check = login(a, b, Choice);
				check = 1;
				if (check == 1)
				{
					system("CLS");
					cout << "1.Inventory Managment" << endl;
					cout << "2.Search Item" << endl;
					cout << "Enter your Choice : ";
					cin >> choice;
					if (choice == 1)
					{
						system("CLS");
						cout << "1.Add Item\n2.Remove Item" << endl;
						cin >> choice;
						if (choice == 1)
						{
							if (branch == 2)
							{
								system("CLS");
								store s;
								s.additem();

								ofstream myFile("Islamabad.dat", ios::binary | ios::app);
								if (myFile.write((char*)&s, sizeof(s)))
									cout << "Object Successfully Inserted" << endl;
								else
									cout << "Object Insertion Failed" << endl;
								myFile.close();
								cin.ignore();
							}
							if (branch == 1)
							{
								system("CLS");
								Inventory s;
								s.additem();
								ofstream myFile("Lahore.dat", ios::binary | ios::app);
								if (myFile.write((char*)&s, sizeof(s)))
									cout << "Object Successfully Inserted" << endl;
								else
									cout << "Object Insertion Failed" << endl;
								myFile.close();
								cin.ignore();
							}
							if (branch == 3)
							{
								system("CLS");
								store s;
								s.additem();
								ofstream myFile("Karachi.dat", ios::binary | ios::app);
								if (myFile.write((char*)&s, sizeof(s)))
									cout << "Object Successfully Inserted" << endl;
								else
									cout << "Object Insertion Failed" << endl;
								myFile.close();
								cin.ignore();
							}

						}
						if (choice == 2)
						{
							if (branch == 2)
							{
								system("CLS");
								cout << "Enter the Item You Want to Delete : ";
								cin >> c;


								store temp;
								ofstream file("temp.dat", ios::app | ios::binary);
								fstream myFile("Islamabad.dat", ios::in | ios::out | ios::binary);
								while (myFile.read((char*)&temp, sizeof(temp))) {
									if (temp.getitem() != c) {
										file.write((char*)&temp, sizeof(temp));
									}
								}
								myFile.close();
								file.close();
								remove("Islamabad.dat");;
								rename("temp.dat", "Islamabad.dat");

							}
							if (branch == 1)
							{
								system("CLS");
								cout << "Enter the Item You Want to Delete : ";
								cin >> c;
								store temp;
								fstream myFile("Lahore.dat", ios::in | ios::out | ios::binary);
								ofstream myFile_temp("temp.dat", ios::app | ios::binary);
								while (myFile.read((char*)&temp, sizeof(temp))) {
									if (temp.getitem() != c) {
										myFile_temp.write((char*)&temp, sizeof(temp));
									}
								}
								myFile.close();
								myFile_temp.close();
								remove("Lahore.dat");
								char f[] = "Lahore.dat";
								rename("temp.dat", f);
							}
							if (branch == 3)
							{
								system("CLS");
								cout << "Enter the Item You Want to Delete : ";
								cin >> c;
								store temp;
								fstream myFile("Karachi.dat", ios::in | ios::out | ios::binary);
								ofstream myFile_temp("temp.dat", ios::app | ios::binary);
								while (myFile.read((char*)&temp, sizeof(temp))) {
									if (temp.getitem() != c) {
										myFile_temp.write((char*)&temp, sizeof(temp));
									}
								}
								myFile.close();
								myFile_temp.close();
								remove("Karachi.dat");
								char f[] = "Karachi.dat";
								rename("temp.dat", f);
							}
						}
					}
					if (choice == 2)
					{
						system("CLS");
						cout << "1.Lahore\n2.Islamabad\n3.Karachi" << endl;
						cout << "Enter the Store You Want to Search : ";
						cin >> branch;

						if (branch == 2)
						{
							cout << "Enter the Item to search : ";
							cin >> a;
							Inventory temp;
							ifstream myFile("Islamabad.dat", ios::binary);

							while (myFile.read((char*)&temp, sizeof(temp)))
							{
								if (temp.getitem() == a) {
									cout << "Item Found";
									cout << temp.getprice();
								}
								else
								{
									cout << "Item not Found.\n Item is currently Unaviable." << endl;
								}

							}
							cin.ignore();
							myFile.close();
						}
						if (branch == 1)
						{
							cout << "Enter the Item to search : ";
							cin >> a;
							Inventory temp;
							ifstream myFile("Lahore.dat", ios::binary);

							while (myFile.read((char*)&temp, sizeof(temp)))
							{
								if (temp.getitem() == a) {
									cout << "Item Found";
									cout << temp.getprice();
								}
								else
								{
									cout << "Item not Found.\n Item is currently Unaviable." << endl;
								}

							}
							cin.ignore();
							myFile.close();
						}
						if (branch == 3)
						{
							cout << "Enter the Item to search : ";
							cin >> a;
							Inventory temp;
							ifstream myFile("Karachi.dat", ios::binary);

							while (myFile.read((char*)&temp, sizeof(temp)))
							{
								if (temp.getitem() == a) {
									cout << "Item Found : ";
									cout << temp.getprice();
								}
								else
								{
									cout << "Item not Found.\n Item is currently Unaviable." << endl;
								}

							}
							cin.ignore();
							myFile.close();
						}
					}
				}
				else
				{
					cout << "Try Again!" << endl;
				}
			}
		}
		cin.ignore();
		system("CLS");
	}
	return 0;
}
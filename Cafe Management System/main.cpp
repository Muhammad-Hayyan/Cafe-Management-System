#include "i232041.h"

/* 	MUHAMMAD HAYYAN
	23I - 2041
	CY-A
	PF-Project */

int main()
{
	
	bool x=0, x1=0, x3=0, stock=0, emp=0, main=0, logout=0;
	int c1, c2, c3, c4, a=0, item_sold=0;
	
	
	do
	{
	//Printing Menu
	
	cout<<endl<<endl;
	cout<<"\033[97;104;1\t\t\tm  --------------------------------------------------------------------------------------------------------------   \033[0m\n\n\n";
    	cout<<"\033[94;40;1\t\t\tm   _       __________    __________  __  _________   __________     _________   ___________   __________  _____   \033[0m\n";
    	cout<<"\033[94;40;1\t\t\tm  | |     / / ____/ /   / ____/ __ \\/  |/  / ____/  /_  __/ __ \\   / ____/   | / ___/_  __/  / ____/ __ \\/ ___/   \033[0m\n";
    	cout<<"\033[94;40;1\t\t\tm  | | /| / / __/ / /   / /   / / / / /|_/ / __/      / / / / / /  / /_  / /| | \\__ \\ / /    / /   / / / /\\__ \\    \033[0m\n";
    	cout<<"\033[94;40;1\t\t\tm  | |/ |/ / /___/ /___/ /___/ /_/ / /  / / /___     / / / /_/ /  / __/ / ___ |___/ // /    / /___/ /_/ /___/ /    \033[0m\n";
    	cout<<"\033[94;40;1\t\t\tm  |__/|__/_____/_____/\\____/\\____/_/  /_/_____/    /_/  \\____/  /_/   /_/  |_/____//_/     \\____/_____//____/     \033[0m\n\n\n";  
    	cout<<"\033[97;104;1\t\t\tm  --------------------------------------------------------------------------------------------------------------  \033[0m\n";
    
    	cout<<endl<<endl;
	cout<<"\033[93;40;1m\n\t1.\033[0m";
	cout<<" Admin\n";
	cout<<"\033[93;40;1m\n\t2.\033[0m";
	cout<<" Employee\n";
	cout<<"\033[93;40;1m\n\t3.\033[0m";
	cout<<" Student / Staff\n";
	cout<<"\033[93;40;1m\n\t4.\033[0m";
	cout<<" Exit CDS\n";
	cout<<"\n Select one of the options to login (1 - 4) : ";
	cin>>c1;
	
	switch (c1)
	{
		case 1:
			do
			{
			
			cout << "\033[93;40;1m\n\n\tEnter Admin ID: \033[0m";
			loginad(x, x1);			//Function to check admin id and password and returns in bool variables
			
			if (x==1 && x1==1)
			{
				cout << "\033[94;40;1m\n\n________________________________________________________________________________\n\n\n\n\033[0m";
				cout << "\033[94;107;1m\t   [  Welcome! Admin  ]  \t\033[0m"<<endl<<endl<<endl;
				
				do
				{
				
				cout<<"\n\t1. Manage Stock"<<endl;
				cout<<"\n\t2. Manage Employees / Users credentials"<<endl;
				cout<<"\n\t3. Manage Notifications"<<endl;
				cout<<"\n\t4. Manage Online / Scheduled orders"<<endl;
				cout<<"\n\t5. See Complaints"<<endl;
				cout<<"\n\t6. See Statistics"<<endl;
				cout<<"\n\t7. Logout"<<endl;
				Warning();
				cout<<"\n\n Select any Option (1-7) : ";
				cin>>c2;
				
				switch (c2)
				{
					//case for stock
					
					case 1:
						do
						{
							cout<<"\n\t1. Display all Items"<<endl;
							cout<<"\n\t2. Search an Item"<<endl;
							cout<<"\n\t3. Remove an Item"<<endl;
							cout<<"\n\t4. Add an Item"<<endl;
							cout<<"\n\t5. Order Items"<<endl;
							cout<<"\n\t6. Update stock"<<endl;
							cout<<"\n\t7. Sort Stock"<<endl;
							cout<<"\n\t8. Go Back to main menu"<<endl;
							cout<<"\n\n Select Any Option (1-8) : ";
							cin>>c3;
							cout<<endl;
							switch (c3)
							{
								case 1:
									Itdisplay();
									cout<<"\033[34;40;1m\n-------------------------------------------------------\n\n\033[0m";
									break;
								case 2:
									Search();
									cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
									break;
								case 3:
									Remove();
									cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
									break;
								case 4:
									Add();
									cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
									break;
								case 5:
									Order();
									cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
									break;
								case 6:
									Update();
									cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
									break;
								case 7:
									Sort();
									cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
									break;
								case 8:
									stock=1;
									cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
									break;
									
								default:
								cout<<"\033[91;40;1m\n\nInvalid Input! Please enter a number between 1 and 8\n\n\033[0m"<<endl;
									cin.clear();			//this is too validate input if alphaet is entered
									cin.ignore(100, '\n');
									break;
							}
						} while (stock==0);
						break;
						
					//case for employees and users credentials
					
					case 2:
						do
						{
							cout<<"\n\t1. See employees information and credentials"<<endl;
							cout<<"\n\t2. Manage employees credentials"<<endl;
							cout<<"\n\t3. Manage Users credentials"<<endl;
							cout<<"\n\t4. Go back to main menu"<<endl;
							cout<<"\n\n Select Any Option (1-3) : ";
							cin>>c3;
							
							switch(c3)
							{
								case 1:
									cout<<"\n__________________________________________________\n";
									Empdisp();
									cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
									break;
								case 2:
								
								do
								{
									cout<<"\n\t1. Change Credentials"<<endl;
									cout<<"\n\t2. Remove Credentials"<<endl;
									cout<<"\n\t3. Add New Employee Credentials"<<endl;
									cout<<"\n\t4. Go back"<<endl;
									cout<<"\n\n Select Any Option (1-4) : ";
									cin>>c4;
									
									switch(c4)
									{
										case 1:
											cout<<"\n__________________________________________________\n";
											Empdisp();
											Changecred();
								cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
											break;
											
										case 2:
											cout<<"\n__________________________________________________\n";
											Empdisp();
											Removecred();
								cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
											break;
										case 3:
											cout<<"\n__________________________________________________\n";
											Addcred();
									cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
											break;
										case 4:
											emp=1;
											break;
										default:
											cout<<"\n\nInvalid Input! Please Enter a number between 1 and 4\n\n";
											cin.clear();
											cin.ignore(100, '\n');
									}
								} while (x==0); 
								break;
								
								case 3:
									do
									{
									
									x=0;
									cout<<"\n\t1. See All Users Credentials"<<endl;
									cout<<"\n\t2. Change Users Credentials"<<endl;
									cout<<"\n\t3. Remove Credentials"<<endl;
									cout<<"\n\t4. Add New Credentials"<<endl;
									cout<<"\n\t5. Go back"<<endl;
									cout<<"\n\n Select Any Option (1-5) : ";
									cin>>c4;
									
									switch (c4)
									{
										case 1:
											Userdisp();
									cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
											break;
											
										case 2:
											Userdisp();
									cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
											Changeusercred();
											break;
											
										case 3:
											Userdisp();
								cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
											Userrm();
											cout<<"\n-------------------------------------------------------------\n";
											break;
										case 4:
											Addusers();
											break;
											
										case 5:
											
											x=1;
											break;
										default:
											cout<<"\033[91;40;1m\n\tInvalid Input! Enter Between (1-5).\033[0m"<<endl;
											cin.clear();
											cin.ignore(100, '\n');
											
						
											
									}
									
									}while(x==0);
									break;
								case 4:
									x3=1;
									break;
							}
						}while (x3==0);
						break;
						
						case 3:			//For notif
							
							do
							{
							
							x=0;
							cout<<"\n\t1. View Notifications"<<endl;
							cout<<"\n\t2. Add a Notifcation"<<endl;
							cout<<"\n\t3. Delete a Notifcation"<<endl;
							cout<<"\n\t4. Go Back"<<endl;
							cout<<"\n\n Select Any Option (1-4) : ";
							cin>>c4;
							
							switch(c4)
							{		
								case 1:
									ViewNotif();
									cout<<"\033[34;40;1m\n-------------------------------------------------------\n\n\033[0m";
									break;
								case 2:
									cout<<"\033[34;40;1m\n-------------------------------------------------------\n\n\033[0m";
									AddNotif();
									break;
								case 3:
									ViewNotif();
									cout<<"\033[34;40;1m\n-------------------------------------------------------\n\n\033[0m";
									RemNotif();
									break;
								case 4:
									x=1;
									break;
								default:
									cout<<"\033[91;40;1m\n\tInvalid Input! Enter Between (1-4).\033[0m"<<endl;
									cin.clear();
									cin.ignore(100, '\n');
							
							}
							
							}while(x==0);
							break;
						case 4:			//For schedule orders
							Schedule();
							break;
						case 5:			//For complaints
							Complaints();
							cout<<"\033[34;40;1m\n\n\n---------------------------------------------------------------------\n\n\033[0m";
							break;
						case 6:			//Statistics
						cout<<"\033[34;40;1m\n\n\n---------------------------------------------------------------------\n\n\n\033[0m";
							Stats();
							cout<<"\033[34;40;1m\n\n\n---------------------------------------------------------------------\n\n\033[0m";
							break;
						case 7:			//logout
							main=1;
							break;
						default:
							cout<<"\033[91;40;1m\n\tInvalid Input! Enter Between (1-8).\033[0m"<<endl;
							cin.clear();
							cin.ignore(100, '\n');
							break;
				}
				
				} while (main==0);		
				
			}
			else if(x==0 && x1==0)
			{
				cout<<"\033[91;40;1m\n\tWrong Admin ID and Password! Please Try Again.\033[0m"<<endl;
				a++;
			}
			else if(x==0)
			{
				cout<<"\033[91;40;1m\n\tWrong Admin ID! Please Try Again.\033[0m"<<endl;
				a++;
			}
			else
			{
				cout<<"\033[91;40;1m\n\tWrong Password! Please Try Again.\033[0m"<<endl;
				a++;
			}
			if (a>5)		//This will break loop if more than 5 wrong attempts
			{
				cout<<"\033[91;40;1m\n\tToo many wrong attempts! Please try again later.\033[0m"<<endl;
				break;
			}
			
			}while(x==0 || x1==0);		//loop will continue until correct id and password is entered
			
			break;	
			
		case 2:			//for employee login
		
		x=0;
		int p;
		bool y;
		
		cin.ignore();
		do
		{
		
		y = Emplogin(p);		//returns 1 if login successfull
		
		
		if (y==1)
		{
		
			do
			{
			
			cout<<"\n\n\t1. See Items in Stock"<<endl;
			cout<<"\n\t2. Search Items"<<endl;
			cout<<"\n\t3. Take Order"<<endl;
			cout<<"\n\t4. Manage Online/Scheduled Order"<<endl;
			cout<<"\n\t5. Sort Items"<<endl;
			cout<<"\n\t6. Logout"<<endl;
			Notif();
			cout<<"\n\n Select Any Option (1-6) : ";
			cin>>c1;
			
			switch(c1)
			{
				case 1:			//to see items
					cout<<endl<<endl;
					Itdisplay();
					cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
					break;
					
				case 2:			//search items
					cout<<endl<<endl;
					Search();
					cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
					break;
					
				case 3:			//take order
					item_sold=0;
					Itdisplay();
					cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
					item_sold=Emporder();
					cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
					Updsales(p, item_sold);
					break;
					
				case 4:			//see online orders
					Schedule();
					break;
				case 5:
					Sort();
					cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
					break;
				case 6:
					x=1;
					break;
					
				default:
					cout<<"\033[91;40;1m\n\n Invalid Input! Please enter between (1 - 6). \n\n\033[0m"<<endl;
					cin.clear();
					cin.ignore(100, '\n');
					break;
			
			}
			
			}while(x==0);
			
		}
		else
			cout<<"\033[91;40;1m\n\tWrong ID or Password! Please enter again!\n\033[0m"<<endl;
			
		}while(y==0);
			
			
			break;
			
			
		case 3:			//for student login
			x=0;
			p=0;
			y=0;
			
			cin.ignore();
			do
			{
			
			y = Userlogin(p);			//returns 1 if login successfull
			
			if(y==1)
			{
			
				do
				{
				
				cout<<"\n\n\t1. See Menu"<<endl;
				cout<<"\n\t2. Search Items"<<endl;
				cout<<"\n\t3. Schedule an Order"<<endl;
				cout<<"\n\t4. Submit complaint"<<endl;
				cout<<"\n\t5. Sort items in menu"<<endl;
				cout<<"\n\t6. Logout"<<endl;
				Notif();
				cout<<"\n\n Select Any Option (1-6) : ";
				cin>>c1;
				
				switch(c1)
				{
					case 1:
						Menudisp();
						cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
						break;
					
					case 2:
						Usersearch();
						cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
						break;
					case 3:
						Menudisp();
						cout<<"\033[34;40;1m\n\n-------------------------------------------------------\n\n\033[0m";
						Userschedule();
						break;
					case 4:
						AddComplaint();
						break;
					case 5:
						Sort();
						break;
					case 6:
						x=1;
						break;
					default:
						cout<<"\033[91;40;1m\n\n Invalid Input! Please enter between (1 - 6). \n\n\033[0m"<<endl;
						cin.clear();
						cin.ignore(100, '\n');
						break;
						
				
				
				}
				
				}while(x==0);
			
			}
			else
				cout<<"\033[91;40;1m\n\tWrong ID or Password! Please enter again!\n\033[0m"<<endl;
			
			}while(x==0);
			break;
		case 4:			//for exit program
			logout=1;
			break;
		default:
			cout<<"\033[91;40;1m\n\tInvalid Input! Please Enter between (1-4)\n\033[0m"<<endl;
			cin.clear();
			cin.ignore(100, '\n');
			break;
	}
	
	}while(logout==0);
	
}


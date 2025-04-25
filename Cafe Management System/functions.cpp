#include"i232041.h"

/* 	MUHAMMAD HAYYAN
	23I - 2041
	CY-A
	PF-Project */

/****************************************************************************************************************************************************************/

								//Login For ADMIN
						
/****************************************************************************************************************************************************************/

void loginad(bool& x, bool&x1)
{
	char c;
	ifstream fin;
	ifstream fin1;
	ofstream fout;
	char decrypt[20];		//Decrypted password
	char pswd[20];			//Entered password
	char admn[7]={'j','a','w','a','d','\0'};		
	char id[7];			//Entered admin id
	
	//Taking input in id and checking if its correct
	cin>> id;
	if (strcmp(admn, id) == 0)
		x=1;			//Stores 1 in x if user id is correct
	
	
	//Password k liye mene aik encrypted password admin.txt mein store kia hai.Check krny k liye Usko pehly decrypt kr k aik or text file decrypted.txt mein store kia or last mein woh decrypted.txt wali file delete krdi hai.
	 
	cout << "\033[93;40;1m\n\n\tEnter Admin Password: \033[0m";
	cin.ignore();				//ignore because cin previously
	cin.getline(pswd, 20, '\n');		//taking input password
	fin.open("admin.txt");
	fout.open("decrypt.txt", ios::out);
	
	while(!fin.eof())
	{
		//taking each character from encrypted file, decrypting it and storing it in decrypted file
		fin.get(c);		
		c=c-36;
		fout<<c;
		
		if(c==51)			//breaks on last character of password
			break;
	}
	fin.close();
	fout.close();
	
	fin1.open("decrypt.txt");		//taking decrypted password in another array to compare
	fin1.getline(decrypt, 20);
	
	
	if (strcmp(pswd, decrypt)==0)
		x1=1;				//returns 1 if correct password is found
	
	fin1.close();
	remove("decrypt.txt");			//deleting the decrypted password file
	
}

/****************************************************************************************************************************************************************/

						//Stock Functions for admin Are starting from here
						
/****************************************************************************************************************************************************************/


void Itdisplay(void)
{
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;
	//int no_of_items=0;
	//int stockprice=0;
	
	ifstream fin;
	fin.open("stock.txt", ios::in);
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	
	size = count++;
	
	
	char **item;				//Making 2d dynamic array for items 
	item = new char*[size];
	
	int *Id = new int[size];		//Making 1d dynamic arrays
	int *Price = new int[size];
	int *Amount = new int[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array
	{
		item[i] = new char[30];
		
	}
	
	fin.open("stock.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(item[i], 30, '\t'), fin>>Id[i]>>Price[i]>>Amount[i])				//Getting all items in arrays
	{
		fin.ignore();
		i++; 
	}
	fin.close();

	
	//Now outputting all the items
	
	cout<<"\t\t"<<line1<<"\tTotal_Price"<<endl<<endl;
	for (int k=0; k<i; k++)				//k<i because line1 is separated above
	{
		if(Amount[k] == 0)		//yellow color if item is zero
		{
			cout<<endl;
			cout<<"\033[93;40;1m\t\t"<<item[k]<<"\t"<<Id[k]<<"\t"<<Price[k]<<"\t"<<Amount[k]<<"\t"<<Amount[k]*Price[k]<<"\n\033[0m";
		}
		else if(Amount[k] < 10)		//red color if item is less than 10
		{
			cout<<endl;
			cout<<"\033[91;40;1m\t\t"<<item[k]<<"\t"<<Id[k]<<"\t"<<Price[k]<<"\t"<<Amount[k]<<"\t"<<Amount[k]*Price[k]<<"\n\033[0m";
		}
		else
		{
			cout<<endl;
			cout<<"\t\t"<<item[k]<<"\t";
			cout<<Id[k]<<"\t";
			cout<<Price[k]<<"\t";
			cout<<Amount[k]<<"\t";
			cout<<Amount[k]*Price[k]<<"\n";
		}
		//no_of_items = no_of_items + Amount[k];				//this counts number of items in stock
		//stockprice = stockprice + (Amount[k]*Price[k]); 		//this counts total price of stock
		
		cout<<"\t\t_____________________________________"<<endl;
	}
	
	
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
		delete[]item[i];
		
	delete[] item;
	item=NULL;
	
	delete [] Id;
	Id=NULL;
	delete [] Price;
	Price=NULL;
	delete [] Amount;
	Amount=NULL;
		
}


/****************************************************************************************************************************************************************/


void Search(void)
{
	char line1[30];
	char array[30];
	char Search[15];
	int Id_search;
	int count = 0;
	int i=0;
	int size;
	int choice;
	bool x=0;
	
	ifstream fin;
	fin.open("stock.txt", ios::in);
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	size = count++;
	
	
	char **item;				//Making 2d dynamic array for items 
	item = new char*[size];
	
	int *Id = new int[size];		//Making 1d dynamic arrays
	int *Price = new int[size];
	int *Amount = new int[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array (i<size due to double free zsh error)
	{
		item[i] = new char[30];
		
	}
	
	fin.open("stock.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(item[i], 30, '\t'), fin>>Id[i]>>Price[i]>>Amount[i])				//Getting all items in arrays
	{
		fin.ignore();
		i++; 
	}
	fin.close();
	
	//Asking admin to enter choice
	cout<<"\n\n1. Search Any Item with ID";
	cout<<"\n2. Search An Item with Name";
	cout<<"\n\n Select any Option: ";
	cin>>choice;
	
	switch(choice)
	{
	
	case 1:
			cout<<"\n\n Enter ID of item: ";
			cin>>Id_search;
	case 2:
		if(choice==2)					
		{
			cout<<"\n\n Enter Name of item (First letter capital): ";
			cin.ignore();
			cin.getline(Search, 15, '\n');
		}
		
		//mene ID or name search dono k liye same mechanism banaya hai thats why i used if with switch and no breaks
		cout<<endl<<endl;
		
		for (int k=0; k<i; k++)
		{
			if ((strcmp(Search, item[k])==0) || (Id_search==Id[k]))		//check if item if found or not
				{
					cout<<line1<<endl;
					cout<<"______________________________"<<endl<<endl;
					cout<<item[k]<<"\t"<<Id[k]<<"\t"<<Price[k]<<"\t"<<Amount[k]<<endl;
					x=1;
					break;
				}
				
		}
	}
		if (x==0)				//prints if no match found
				cout<<"\n\n No Match Found!\n";
		
		//Deallocating arrays
	
	for (int i=0; i<size; i++)
		delete[]item[i];
		
	delete[] item;
	item=NULL;
	
	delete [] Id;
	Id=NULL;
	delete [] Price;
	Price=NULL;
	delete [] Amount;
	Amount=NULL;		
			
}


/****************************************************************************************************************************************************************/


void Remove(void)
{
	int rm;
	bool x=0;
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;
	
	//Displaying items First (same as Itdisp function)
	ifstream fin;
	fin.open("stock.txt", ios::in);
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	size = count++;
	
	
	char **item;				//Making 2d dynamic array for items 
	item = new char*[size];
	
	int *Id = new int[size];		//Making 1d dynamic arrays
	int *Price = new int[size];
	int *Amount = new int[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array
	{
		item[i] = new char[30];
		
	}
	
	fin.open("stock.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(item[i], 30, '\t'), fin>>Id[i]>>Price[i]>>Amount[i])				//Getting all items in arrays
	{
		fin.ignore();
		i++; 
	}
	fin.close();

	
	//Now outputting all the items
	
	cout<<line1<<"\tTotal_Price"<<endl<<endl;
	for (int k=0; k<i; k++)				//k<i because line1 is separated above
	{
		cout<<endl;
		cout<<item[k]<<"\t";
		cout<<Id[k]<<"\t";
		cout<<Price[k]<<"\t";
		cout<<Amount[k]<<"\t";
		cout<<Amount[k]*Price[k]<<"\n";
		cout<<"_____________________________________"<<endl;
	}
	
	ofstream fout;			//object to write data
	
	do
	{
	
	cout<<"\n\n Enter the ID of item you want to remove: ";
	cin>>rm;
	
	fout.open("stock.txt", ios::out);
	fout<<line1<<endl;
	
	for (int k=0; k<i; k++)
	{
		if (Id[k]==rm)				//checking condition if entered id matches, if it does then it does not writes the data
		{
			cout<<endl<<endl;
			cout<<"\033[34;40;1m"<<item[k]<<" deleted from stock successfully!\n\033[0m";
			x=1;
			
		}
		else					//If ID does not match then writes data
		{
			fout<<item[k]<<"\t";
			fout<<Id[k]<<"\t";
			fout<<Price[k]<<"\t";
			fout<<Amount[k]<<"\n";
		}
		
	}
	fout.close();
	
	if(x==0)				//error message if no ID matches
		cout<<"\033[91;40;1m\nNo Items found with this ID. Please Enter again.\033[0m"<<endl;
	
	}while(x==0);		//This loop will continue until and ID matches or an item is removed
	
	
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
		delete[]item[i];
		
	delete[] item;
	item=NULL;
	
	delete [] Id;
	Id=NULL;
	delete [] Price;
	Price=NULL;
	delete [] Amount;
	Amount=NULL;	
}


/****************************************************************************************************************************************************************/


void Add(void)
{
	
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;
	
	char new_item[15];
	int new_id;
	int new_price;
	int new_amount;
	bool x=0, y=0;
	
	//First of all reading stock file to check if admin enters already stored item
	
	ifstream fin;
	fin.open("stock.txt", ios::in);
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	
	size = count++;
	
	
	char **item;				//Making 2d dynamic array for items 
	item = new char*[size];
	
	int *Id = new int[size];		//Making 1d dynamic arrays
	int *Price = new int[size];
	int *Amount = new int[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array
	{
		item[i] = new char[30];
		
	}
	
	fin.open("stock.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(item[i], 30, '\t'), fin>>Id[i]>>Price[i]>>Amount[i])				//Getting all items in arrays
	{
		fin.ignore();
		i++; 
	}
	fin.close();
	
		//Taking Input from admin about new item
	cin.ignore();
	cout<<"\n\nEnter new item name (first letter capital) : ";
	cin.getline(new_item, 15, '\n');
	
	do
	{
		cout<<"\n\nEnter an ID for the new item : ";
		cin>> new_id;
		
		//Now we are checking if that id already exists or not. If it already exists then it will generate an error message and ask admin to enter the id again. I used do while loop for this.
		
		for (int k=0; k<i; k++)
		{
			if (new_id == Id[k])
			{
				cout<<"\033[91;40;1m\n\nAn item with this ID already exists! Please enter a new ID\n\n\033[0m"<<endl;
				x=1;
				break;
			}
			x=0;
		}
		
	}while(x==1);
	
	cout<<"\n\nEnter price of item you want to set : ";
	cin>>new_price;
	
	do
	{
	cout<<"\n\nEnter quantity of item : ";
	cin>>new_amount;
	
	if(new_amount<1 || new_amount>1000)			//condition to check if entered quantity is greater than 1000
	{
		cout<<"\033[91;40;1m\n\nPlease Enter quantity between 1 to 1000\n\n\033[0m"<<endl;
	}
	else
		y=1;
	}while (y==0);
	
	ofstream fout;
	
	//Adding the new item in file using appehend mode
	fout.open("stock.txt", ios::app);
	fout<<new_item<<"\t";
	fout<<new_id<<"\t";
	fout<<new_price<<"\t";
	fout<<new_amount<<"\n";
	fout.close();
	
	fout.open("itemsales.txt", ios :: app);
	fout<<new_item<<"\t"<<"0"<<"\n";
	fout.close();
	
	cout<<"\033[34;40;1m\n\n" <<new_item<<" added successfully in stock !\n\033[0m"<<endl;
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
		delete[]item[i];
		
	delete[] item;
	item=NULL;
	
	delete [] Id;
	Id=NULL;
	delete [] Price;
	Price=NULL;
	delete [] Amount;
	Amount=NULL;
	
}


/****************************************************************************************************************************************************************/


void Order(void)
{
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;
	int order;
	int qty;
	bool y=0;
	
	ifstream fin;
	fin.open("stock.txt", ios::in);
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	
	size = count++;
	
	
	char **item;				//Making 2d dynamic array for items 
	item = new char*[size];
	
	int *Id = new int[size];		//Making 1d dynamic arrays
	int *Price = new int[size];
	int *Amount = new int[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array
	{
		item[i] = new char[30];
		
	}
	
	fin.open("stock.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(item[i], 30, '\t'), fin>>Id[i]>>Price[i]>>Amount[i])				//Getting all items in arrays
	{
		fin.ignore();
		i++; 
	}
	fin.close();
	
	//Now outputting all items
	
	cout<<line1<<"\tTotal_Price"<<endl<<endl;
	for (int k=0; k<i; k++)				//k<i because line1 is separated above
	{
		cout<<endl;
		cout<<item[k]<<"\t";
		cout<<Id[k]<<"\t";
		cout<<Price[k]<<"\t";
		cout<<Amount[k]<<"\t";
		cout<<Amount[k]*Price[k]<<"\n";
		cout<<"_____________________________________"<<endl;
	}
		
	cout<<"\n\n Enter the ID of item you want to order : ";
	cin>>order;
	
	do
	{
	cout<<"\n\n How much quantity you want to order? : ";
	cin>>qty;
	
	if(qty<1 || qty>998)				//condition to check if quantity is greater than 1000
	{
		cout<<"\033[91;40;1m\n\nPlease Enter quantity between 1 to 1000\n\n\033[0m"<<endl;
	}
	else
		y=1;
	}while (y==0);
	
	ofstream fout;
	fout.open("stock.txt", ios::out);
	fout<<line1<<endl;
	
	for (int k=0; k<i; k++)	
	{
		if (order == Id[k])			//when this condition meets i.e its the same item, it will ordered
		{
			Amount[k] = Amount[k] + qty;
			cout<<"\033[34;40;1m\n\n"<<qty<<" "<<item[k]<<" ordered and will be added to the stock soon.\n\n\033[0m"<<endl;
		}
		
		fout<<item[k]<<"\t";
		fout<<Id[k]<<"\t";
		fout<<Price[k]<<"\t";
		fout<<Amount[k]<<"\n";
	}
	fout.close();
		
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
		delete[]item[i];
		
	delete[] item;
	item=NULL;
	
	delete [] Id;
	Id=NULL;
	delete [] Price;
	Price=NULL;
	delete [] Amount;
	Amount=NULL;
	
}


/****************************************************************************************************************************************************************/


void Update(void)
{
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;
	int entered_id;
	int new_price;
	
	ifstream fin;				//reading from stock txt file
	fin.open("stock.txt", ios::in);
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	
	size = count++;
	
	
	char **item;				//Making 2d dynamic array for items 
	item = new char*[size];
	
	int *Id = new int[size];		//Making 1d dynamic arrays
	int *Price = new int[size];
	int *Amount = new int[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array
	{
		item[i] = new char[30];
		
	}
	
	fin.open("stock.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(item[i], 30, '\t'), fin>>Id[i]>>Price[i]>>Amount[i])				//Getting all items in arrays
	{
		fin.ignore();
		i++; 
	}
	fin.close();
	
	//Now outputting all items
	
	cout<<line1<<"\tTotal_Price"<<endl<<endl;
	for (int k=0; k<i; k++)				//k<i because line1 is separated above
	{
		cout<<endl;
		cout<<item[k]<<"\t";
		cout<<Id[k]<<"\t";
		cout<<Price[k]<<"\t";
		cout<<Amount[k]<<"\t";
		cout<<Amount[k]*Price[k]<<"\n";
		cout<<"_____________________________________"<<endl;
	}
		
		//taking updates from admin
		
	cout<<"\n\n Enter the ID of item you want to change price of : ";
	cin>>entered_id;
	cout<<"\n\n Enter New Price : ";
	cin>>new_price;
	
	ofstream fout;					//writing back to stock txt
	fout.open("stock.txt", ios::out);
	fout<<line1<<endl;
	
	for (int k=0; k<i; k++)	
	{
		if (entered_id == Id[k])		//when this condition meets i.e its the same item then it writes updated info
		{
			Price[k] = new_price;
			cout<<"\033[34;40;1m\n\n Price Of "<<item[k]<<" has been stock updated !\n\n\033[0m"<<endl;
		}
		
		fout<<item[k]<<"\t";
		fout<<Id[k]<<"\t";
		fout<<Price[k]<<"\t";
		fout<<Amount[k]<<"\n";
	}
	fout.close();
		
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
		delete[]item[i];
		
	delete[] item;
	item=NULL;
	
	delete [] Id;
	Id=NULL;
	delete [] Price;
	Price=NULL;
	delete [] Amount;
	Amount=NULL;
}



/****************************************************************************************************************************************************************/

						//Stock Functions for admin Are finished here
						
						//Now functions for admin for credentials of employees / Users
						
/****************************************************************************************************************************************************************/


void Empdisp(void)
{
	
	int count=0;
	int i=0;
	int size;
	char array[30];
	char line1[30];
	char line11[30];
	
	ifstream fin;					//reading from employee credentials file
	fin.open("empcred.txt", ios::in);
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	size = count++;
	
	int *Age = new int[size];		//Making 1d dynamic arrays
	int *Sales = new int[size];
	
	char **Name;				//Making 2d dynamic arrays 
	char **Name1;
	char **Id;
	char **Pass;
	char **Post;
	
	Name = new char*[size];
	Name1 = new char*[size];
	Id = new char*[size];
	Pass = new char*[size];
	Post = new char*[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d arrays
	{
		Name[i] = new char[30];
		Name1[i] = new char[30];
		Id[i] = new char[30];
		Pass[i] = new char[30];
		Post[i] = new char[30];
		
	}
	
	ifstream empinfo;		//this to read from employeesinformation file
	ifstream cred;			//this to read from employeescredentials file
	
	cred.open("empcred.txt", ios :: in);
	cred.getline(line1, 30, '\n');				//Getting first line of file
	
	
	//mene employees k credentials or information k liye 2 alag alag files banai hein. islye dono mein sy read krraha and then i check and print if both matches.
	
	while (cred.getline(Name[i], 30, '\t'), cred.getline(Id[i], 30, '\t'), cred.getline(Pass[i], 30, '\n'))	//Getting all items in arrays
	{
		i++; 
	}
	cred.close();

	empinfo.open("empinfo.txt", ios :: in);
	empinfo.getline(line11, 30, '\n');				//Getting first line of file
	
	i=0;
	while (empinfo.getline(Name1[i], 30, '\t'), empinfo.getline(Post[i], 30, '\t'), empinfo>>Age[i]>>Sales[i])	//Getting all items in arrays
	{
		empinfo.ignore();
		i++; 
	}
	empinfo.close();
	
	for(int k=0; k<i; k++)				//for credentials file loop
	{
		for (int n=0; n<i; n++)			//for information file loop
		{
			if (strcmp(Name1[n], Name[k])==0)			//condition if both name matches i.e its the same person, then prints information
			{
				cout<<"\nName : "<<Name1[n]<<endl<<endl;			//printing employee information
				cout<<"Post : "<<Post[n]<<endl<<endl;
				cout<<"Age : "<<Age[n]<<endl<<endl;
				cout<<"Total Sales (items) : "<<Sales[n]<<endl<<endl;
				break;
			}
		}
		
		//Printing employee account credentials
		cout<<Name[k]<<"'s account credentials : "<<endl<<endl;
		cout<<"- - - - - - - - - - - - - - - \n";
		cout<<"User ID : "<<Id[k]<<endl;
		cout<<"Password: "<<Pass[k]<<endl;
		cout<<"- - - - - - - - - - - - - - - \n";
		cout<<"\n__________________________________________________\n\n";
		
	}
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
	{
		delete[]Name[i];
		delete[]Name1[i];
		delete[]Id[i];
		delete[]Pass[i];
		delete[]Post[i];
	}
		
	delete[] Name;
	delete[] Name1;
	delete[] Id;
	delete[] Pass;
	delete[] Post;
	Name=NULL;
	Name1=NULL;
	Id=NULL;
	Pass=NULL;
	Post=NULL;
	
	delete [] Age;
	Age=NULL;
	delete [] Sales;
	Sales=NULL;
	
}


/****************************************************************************************************************************************************************/


void Changecred(void)
{
	bool x=0;
	int count=0;
	int i=0;
	int size=0;
	char array[30];
	char line1[30];
	char Id1[30];
	char New_id[30];
	char New_pass[30];
	
	ifstream fin;
	fin.open("empcred.txt", ios::in);
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	size = count++;
	
	char **Name;				//Making 2d dynamic arrays 
	char **Id;
	char **Pass;
	
	Name = new char*[size];
	Id = new char*[size];
	Pass = new char*[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d arrays
	{
		Name[i] = new char[30];
		Id[i] = new char[30];
		Pass[i] = new char[30];
		
	}
	
	fin.open("empcred.txt", ios::in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	while (fin.getline(Name[i], 30, '\t'), fin.getline(Id[i], 30, '\t'), fin.getline(Pass[i], 30, '\n'))	   //Getting all creds in arrays
	{
		i++; 
	}
	fin.close();
	
	cin.ignore();
	do
	{
		cout<<"\n\nEnter ID of employee you want to change credentials of : ";
		cin.getline(Id1, 30, '\n');
		
		//Checking if entered ID exists in text file or not. If not it will generate an error message and ask to enter again. I used do while loop for this
		
		for (int k=0; k<i; k++)
		{
			if(strcmp(Id[k],Id1)==0)
			{
				x=1;
				break;
			}
		}
		
		//If no id is matched, it will generate error message 
		if (x==0)			
			cout<<"\033[91;40;1m\n\n No matches found with this ID! Please enter again.\n\n\033[0m"<<endl;
		
	}while(x==0);			//This loop runs until an ID is matches
	
	
	//Taking the new credentials from admin 
	cout<<"\n\nPlease Enter New Credentials Below";
	cout<<"\n\nNew User ID: ";
	cin.getline(New_id, 30, '\n');
	cout<<"\nNew Password: ";
	cin.getline(New_pass, 30, '\n');
	
	ofstream fout;
	fout.open("empcred.txt", ios :: out);
	fout<<line1<<endl;		//writing first line of file
	

	for (int k=0; k<i; k++)
	{
		if(strcmp(Id[k],Id1)==0)		//This condition checks if ID matches. If it matches then it writes the new ID and password
		{
			fout<<Name[k]<<"\t";
			fout<<New_id<<"\t";
			fout<<New_pass<<"\n";
			cout<<"\033[34;40;1m\n\n "<<Name[k]<<"'s credentials changed successfully! \n\n\033[0m"<<endl;
		}
		else					//If it does not matches then credentials remain old ones
		{
			fout<<Name[k]<<"\t";
			fout<<Id[k]<<"\t";
			fout<<Pass[k]<<"\n";
		}
		
	}
	fout.close();
	

	//Deallocating arrays
	for (int i=0; i<size; i++)
	{
		delete[]Name[i];
		delete[]Id[i];
		delete[]Pass[i];
	}
		
	delete[] Name;
	delete[] Id;
	delete[] Pass;

	Name=NULL;
	Id=NULL;
	Pass=NULL;

}


/****************************************************************************************************************************************************************/


void Removecred(void)
{
	bool x=0;
	int count=0;
	int i=0;
	int size;
	char array[30];
	char line1[30];
	char line11[30];
	char Id1[30];
	
	
	ifstream fin;
	fin.open("empcred.txt", ios::in);
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	size = count++;
	
	int *Age = new int[size];		//Making 1d dynamic arrays
	int *Sales = new int[size];
	
	char **Name;				//Making 2d dynamic arrays 
	char **Name1;
	char **Id;
	char **Pass;
	char **Post;
	
	Name = new char*[size];
	Name1 = new char*[size];
	Id = new char*[size];
	Pass = new char*[size];
	Post = new char*[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d arrays
	{
		Name[i] = new char[30];
		Name1[i] = new char[30];
		Id[i] = new char[30];
		Pass[i] = new char[30];
		Post[i] = new char[30];
		
	}
	
	ifstream empinfo;		//this to read from employeesinformation file
	ifstream cred;			//this to read from employeescredentials file
	
	cred.open("empcred.txt", ios :: in);
	cred.getline(line1, 30, '\n');				//Getting first line of credentials file 
	
	
	//mene employees k credentials or information k liye 2 alag alag files banai hein. islye dono mein sy read krraha and then i check and print if both matches.
	
	while (cred.getline(Name[i], 30, '\t'), cred.getline(Id[i], 30, '\t'), cred.getline(Pass[i], 30, '\n'))	//Getting all items in arrays
	{
		i++; 
	}
	cred.close();

	empinfo.open("empinfo.txt", ios :: in);
	empinfo.getline(line11, 30, '\n');				//Getting first line of info file
	
	i=0;
	while (empinfo.getline(Name1[i], 30, '\t'), empinfo.getline(Post[i], 30, '\t'), empinfo>>Age[i]>>Sales[i])	//Getting all items in arrays
	{
		empinfo.ignore();
		i++; 
	}
	empinfo.close();
	
	//Now taking ID from admin whose credentials he want to delete. And first checking if it exists in file or not. If not it prints error text
	cin.ignore();
	do
	{
		cout<<"\n\nEnter ID of employee you want to change credentials of : ";
		cin.getline(Id1, 30, '\n');
		
		//Checking if entered ID exists in text file or not. If not it will generate an error message and ask to enter again. I used do while loop for this
		
		for (int k=0; k<i; k++)
		{
			if(strcmp(Id[k],Id1)==0)
			{
				x=1;
				break;
			}
		}
		
		//If no id is matched, it will generate error message 
		if (x==0)			
			cout<<"\033[91;40;1m\n\n No matches found with this ID! Please enter again.\n\n\033[0m"<<endl;
		
	}while(x==0);			//This loop runs until an ID is matches
	
	
	//Now writing back to files
	
	ofstream fout;				//object to write in credentials file
	ofstream fout1;				//object to write in info file
	
	fout.open("empcred.txt", ios :: out);
	fout<<line1<<endl;				//writing first line of file
	
	fout1.open("empinfo.txt", ios::out);
	fout1<<line1<<endl;				//writing first line of file
	
	for (int k=0; k<i; k++)				//this outer loop is to write back in cred file
	{
		if(strcmp(Id[k], Id1)==0)		//When this condition matches, it does not write into file i.e it gets deleted
		{
			cout<<"\033[34;40;1m\n\n "<<Name[k]<<"'s credentials deleted successfully !\n\n\033[0m"<<endl;
		}
		else
		{
		
			for (int n=0; n<i; n++)			//this inner loop is to write in information file
			{		
				if (strcmp(Name1[n], Name[k])==0)	//condition if both name matches i.e its the same person, then writes information
				{
					fout1<<Name1[k]<<"\t";
					fout1<<Post[k]<<"\t";
					fout1<<Age[k]<<"\t";
					fout1<<Sales[k]<<"\n";
					break;
				}
			}
			
			fout<<Name[k]<<"\t";
			fout<<Id[k]<<"\t";
			fout<<Pass[k]<<"\n";
			
		
		}
		
	
	}
	fout.close();
	fout1.close();
	
	
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
	{
		delete[]Name[i];
		delete[]Name1[i];
		delete[]Id[i];
		delete[]Pass[i];
		delete[]Post[i];
	}
		
	delete[] Name;
	delete[] Name1;
	delete[] Id;
	delete[] Pass;
	delete[] Post;
	Name=NULL;
	Name1=NULL;
	Id=NULL;
	Pass=NULL;
	Post=NULL;
	
	delete [] Age;
	Age=NULL;
	delete [] Sales;
	Sales=NULL;
	
	
}


/****************************************************************************************************************************************************************/


void Addcred(void)
{
	
	char Name[30];
	char Id[30];
	char Pass[30];
	char Post[15];
	int Age;
	int Sales;
	
	//taking data from admin
	cout<<"\n\nTo Enter Credentials of a new employee please enter the follwoing informaton below\n\n";
	cout<<"Name Of Employee : ";
	cin.ignore();
	cin.getline(Name, 30, '\n');
	cout<<"\n\nEnter a UserID Of Employee : ";
	cin.getline(Id, 30, '\n');
	cout<<"\n\nPlease Set A Password for Employee Account : ";
	cin.getline(Pass, 30, '\n');
	cout<<"\n\nPost of Employee in Cafe : ";
	cin.getline(Post, 15, '\n');
	cout<<"\n\nAge of Employee : ";
	cin>>Age;
	cout<<"\n\nTotal Sales of Employee till yet (Enter 0 if non) : ";
	cin>>Sales;
	
	ofstream fout;
	fout.open("empcred.txt", ios :: app);			//writing credentials in cred file in appehend mode
	fout<<Name<<"\t";
	fout<<Id<<"\t";
	fout<<Pass<<"\n";
	fout.close();
	
	fout.open("empinfo.txt", ios :: app);			//writing inforamtion in info file in appehend mode
	fout<<Name<<"\t";
	fout<<Post<<"\t";
	fout<<Age<<"\t";
	fout<<Sales<<"\n";
	
	cout<<"\033[34;40;1m\n\n "<<Name<<"'s credentials and data added successfully !\n\n\033[0m"<<endl;

}


/****************************************************************************************************************************************************************/


void Userdisp(void)
{
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;
	
	ifstream fin;
	fin.open("users.txt", ios::in);			//reading data from users txt
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	
	size = count++;
	
	
	char **Id;
	char **Pass;				//Making 2d dynamic array for items 
	Id = new char*[size];
	Pass = new char*[size];

	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array
	{
		Id[i] = new char[30];
		Pass[i] = new char[30];
		
	}
	
	fin.open("users.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(Id[i], 30, '\t'), fin.getline(Pass[i], 30, '\n'))				//Getting all items in arrays
	{
		i++; 
	}
	fin.close();

	
	for (int k=0; k<i; k++)				//now printing the information
	{
		cout<<"\033[34;40;1m\n\t---------------------------------------------------\n\033[0m";
		cout<<"\n\t\t\t User ID : "<<Id[k]<<endl;
		cout<<"\t\t\t Password : "<<Pass[k]<<endl;
	
	}
	
	
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
	{
		delete[]Id[i];
		delete[]Pass[i];
	}
		

	delete[] Id;
	delete[] Pass;
	Id=NULL;
	Pass=NULL;
	
}

/****************************************************************************************************************************************************************/


void Changeusercred(void)
{
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;
	char Id1[30];
	char New_id[30];
	char New_pass[30];
	bool x=0;
	
	ifstream fin;
	fin.open("users.txt", ios::in);			//Reading data from users txt
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	
	size = count++;
	
	
	char **Id;
	char **Pass;				//Making 2d dynamic array for items 
	Id = new char*[size];
	Pass = new char*[size];

	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array
	{
		Id[i] = new char[30];
		Pass[i] = new char[30];
		
	}
	
	fin.open("users.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(Id[i], 30, '\t'), fin.getline(Pass[i], 30, '\n'))				//Getting all items in arrays
	{
		i++; 
	}
	fin.close();
	
	
	do
	{
	cout<<"\n\nEnter the User ID of user you want to change credentials of : ";
	cin>>Id1;
	
	//Now checking if entered ID exists or not. If not it will promt the user to enter id again. i used do while loop for this
	
	for (int k=0; k<i; k++)		
	{
		if (strcmp(Id[k], Id1)==0)			//If id exists it will store 1 in x and loop breaks
		{
			x=1;
			break;
			
		}
		
	}
	
	if (x==0)
		cout << "\033[91;40;1m\n\n No Matches found with this ID. Please Enter Again! \n\033[0m\n"<<endl;
		
	}while(x==0);				//loop continues until correct ID is entered
	
	//Taking new id and pass from admin
	cout<<"\n\nEnter the New User Id : ";
	cin>>New_id;
	cout<<"\n\nEnter the New Password : ";
	cin>>New_pass;
	
	//writing back to file
	ofstream fout;
	fout.open("users.txt", ios :: out);
	fout<<line1<<endl;
	
	for (int k=0; k<i; k++)
	{
		if(strcmp(Id[k], Id1)==0)		//If this condition satisfies, it writes new credentials. Otherwise old
		{
			fout<<New_id<<"\t";
			fout<<New_pass<<"\n";
			cout << "\033[34;40;1m\n\n Credentials Changed successfully! \n\033[0m\n"<<endl;
		}
		else
		{
			fout<<Id[k]<<"\t";
			fout<<Pass[k]<<"\n";
		}
	}
	fout.close();	
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
	{
		delete[]Id[i];
		delete[]Pass[i];
	}
		

	delete[] Id;
	delete[] Pass;
	Id=NULL;
	Pass=NULL;	
		
		
}

/****************************************************************************************************************************************************************/

void Userrm(void)
{
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;
	char Id1[30];
	bool x=0;
	
	ifstream fin;
	fin.open("users.txt", ios::in);			//Reading data from users txt
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	
	size = count++;
	
	
	char **Id;
	char **Pass;				//Making 2d dynamic array for items 
	Id = new char*[size];
	Pass = new char*[size];

	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array
	{
		Id[i] = new char[30];
		Pass[i] = new char[30];
		
	}
	
	fin.open("users.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(Id[i], 30, '\t'), fin.getline(Pass[i], 30, '\n'))				//Getting all items in arrays
	{
		i++; 
	}
	fin.close();
	
	do
	{
	cout<<"\n\nEnter the User ID of user you want to remove : ";
	cin>>Id1;
	
	//Now checking if entered ID exists or not. If not it will promt the user to enter id again. i used do while loop for this
	
	for (int k=0; k<i; k++)
	{
		if (strcmp(Id[k], Id1)==0)		//If this condition satisfies, the loop breaks and stores 1 in x
		{
			x=1;
			break;
			
		}
		
	}
	
	if (x==0)
		cout << "\033[91;40;1m\n\n No Matches found with this ID. Please Enter Again! \n\033[0m\n"<<endl;
		
	}while(x==0);
	
	
	ofstream fout;
	fout.open("users.txt", ios :: out);			//writing back to users txt
	fout<<line1<<endl;
	
	for (int k=0; k<i; k++)
	{
		if (strcmp(Id[k], Id1)==0)			//when this condition satisfies i.e its the same user, then it does not write
		{
			cout << "\033[34;40;1m\n\n Credentials removed successfully! \n\033[0m\n"<<endl;
		}
		else						//otherwise it writes in file
		{
			fout<<Id[k]<<"\t";
			fout<<Pass[k]<<"\n";
		
		}
	}
	fout.close();
	
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
	{
		delete[]Id[i];
		delete[]Pass[i];
	}
		

	delete[] Id;
	delete[] Pass;
	Id=NULL;
	Pass=NULL;	
	
}

/****************************************************************************************************************************************************************/

void Addusers(void)
{
	char Id1[30];
	char Pass1[30];
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;
	bool x=0;
	
	ifstream fin;
	fin.open("users.txt", ios::in);			//Reading from users txt
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	
	size = count++;
	
	
	char **Id;
	char **Pass;				//Making 2d dynamic array for items 
	Id = new char*[size];
	Pass = new char*[size];

	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array
	{
		Id[i] = new char[30];
		Pass[i] = new char[30];
		
	}
	
	fin.open("users.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(Id[i], 30, '\t'), fin.getline(Pass[i], 30, '\n'))				//Getting all items in arrays
	{
		i++; 
	}
	fin.close();
	
	do
	{
	cout<<"\n\n Enter User ID of User (starting with i) : ";
	cin>>Id1;
	
	//Now checking if entered ID already exists or not. If it already exists it will ask admin to enter again. I used do while loop for this
	for (int k=0; k<i; k++)
	{
		if(strcmp(Id[k], Id1)==0)
		{
			cout << "\033[91;40;1m\n\n A user with this ID already exist! Please enter again \n\033[0m\n"<<endl;
			x=1;
			break;
		}
		x=0;
	}
	
	}while(x==1);
	
	//Taking Password from admin
	cout<<"\n\n Set A Password for User : ";
	cin>>Pass1;
	
	ofstream fout;
	fout.open("users.txt", ios :: app);			//writing in users txt and adding new user
	
	fout<<Id1<<"\t";
	fout<<Pass1<<"\n";
	
	fout.close();
	
	cout << "\033[34;40;1m\n\n Credentials Added successfully! \n\033[0m\n"<<endl;
	
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
	{
		delete[]Id[i];
		delete[]Pass[i];
	}
		

	delete[] Id;
	delete[] Pass;
	Id=NULL;
	Pass=NULL;
	

}

/****************************************************************************************************************************************************************/

void ViewNotif(void)
{
	char Notif[20][100];
	int Number[20];
	char line1[30];
	int i=0;
	
	ifstream fin;
	fin.open("notif.txt", ios :: in);		//reading from notifications file
	fin.getline(line1, 30, '\n');
	
	while(fin>>Number[i], fin.ignore(), fin.getline(Notif[i], 100, '\n'))
	{
		i++;
	}
	fin.close();
	
	//Now printing all the notifications with appropriate formatting
	cout<<endl<<endl;
	cout<<line1<<endl<<endl;
	for (int k=0; k<i; k++)
	{
	cout<<Number[k]<<".\t"<<Notif[k]<<"\n\n";
	}

}


/****************************************************************************************************************************************************************/

void AddNotif(void)
{
	char Notif[20][100];
	int Number[20];
	char line1[30];
	char array[100];
	int i=0;
	char Newnotif[100];
	int newnum;
	int count=0;
	bool x=0;
	
	ifstream fin;
	fin.open("notif.txt", ios :: in);
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	newnum = count-2;      //because it coounts one more line

	
	fin.open("notif.txt", ios :: in);			//reading from notifications txt
	fin.getline(line1, 30, '\n');
	
	while(fin>>Number[i], fin.ignore(), fin.getline(Notif[i], 100, '\n'))		//getting notif in array
	{
		i++;
	}
	fin.close();
	
	do
	{
	for (int k=0; k<i; k++)
	{
		if(newnum == Number[k])
		{
			newnum++;
			x=1;
			break;
		}
		x=0;
	}
	}while (x==1);
	
	//Mene uper ye kia hai k notification k serial number generate krny k liye aik automatic system banaya hai. Jis mein pehly file mein sy lines count hoti or woh serial number ban jata. Phir check krta k ye serial number file mein already mujood hai ya nahi. Agr already hai to serial number mein aik plus hojata then again check hota. Is tarah jab tak new serial number nahi mil jata tab tak loop chalta
	
	cin.ignore();
	cout<<"\n\nEnter The Notification (max 100 letters) : ";
	cin.getline(Newnotif, 100, '\n');
	
	ofstream fout;
	fout.open("notif.txt", ios :: app);
	fout<<newnum<<"\t"<<Newnotif<<"\n";
	fout.close();
	cout << "\033[34;40;1m\n\n Notification Added successfully! \n\033[0m\n"<<endl;

}


/****************************************************************************************************************************************************************/

void RemNotif(void)
{
	char Notif[20][100];
	int Number[20];
	char line1[30];
	int i=0;
	int number1;
	bool x=0;
	
	ifstream fin;
	fin.open("notif.txt", ios :: in);		//reading all notification from notif txt
	fin.getline(line1, 30, '\n');
	
	while(fin>>Number[i], fin.ignore(), fin.getline(Notif[i], 100, '\n'))		
	{
		i++;
	}
	fin.close();	
	
	do
	{	
		cout<<"\n\nEnter the S.no of notification you want to remove : ";		///taking s.no of notif from admin
		cin>>number1;	
			
		//Now checking if that s.no exists or not. If not then it prints an error message 
		for(int k=0; k<i; k++)
		{
			if(number1 == Number[k])		//Loop breaks if notif exists
			{
				x=1;
				break;
			}
		
		}
		if(x==0)
			cout << "\033[91;40;1m\n\n No notifications found with this S.no. Please enter again! \n\033[0m\n"<<endl;
	}while (x==0);
		
	ofstream fout;
	fout.open("notif.txt", ios :: out);			//Now writing back to the file
	fout<<line1<<endl;	
	for(int k=0; k<i; k++)
	{
		if(number1 == Number[k])		//when this condition satisfies, it does not write that corresponding notif
		{
			cout << "\033[34;40;1m\n\n Notifications Deleted successfuly! \n\033[0m\n"<<endl;
		}
		else
		{
			fout<<Number[k]<<"\t"<<Notif[k]<<"\n";
		}
	
	}	
	fout.close();
}

/****************************************************************************************************************************************************************/

void Complaints(void)
{
	char complaint[100];
	
	ifstream fin;
	fin.open("complaints.txt", ios :: in);			//reading from complaints txt
	
	cout<<"\n\t_________________________________________________________________________________\n";
	fin.getline(complaint, 100, '\n');
	while (!fin.eof())
	{
		cout << "\033[93;40;1m\n\t - "<<complaint<<"\n\033[0m";
		cout<<"\n\t_________________________________________________________________________________\n";
		fin.getline(complaint, 100, '\n');
	}
	fin.close();
}



/****************************************************************************************************************************************************************/
void AddComplaint(void)
{
	char complaint[100];
	
	cin.ignore();
	cout<<"\n\nEnter The Complaint (max 100 alphabets): ";			//taking complaint from user
	cin.getline(complaint, 100, '\n');
	
	ofstream fout;
	fout.open("complaints.txt", ios :: app);		//writing complaint in txt file
	{
		fout<<complaint<<endl;
		
	}
	fout.close();
	cout<<"\033[34;40;1m\n\n Complaint added successfully! We will try to solve your problem ASAP. \n\n\033[0m"<<endl;

}

/****************************************************************************************************************************************************************/


#include"i232041.h"

/* 	MUHAMMAD HAYYAN
	23I - 2041
	CY-A
	PF-Project */

/****************************************************************************************************************************************************************/

								//functions for employees
						
/****************************************************************************************************************************************************************/

bool Emplogin(int& p)
{

	int count=0;
	int i=0;
	int size;
	char array[30];
	char line1[30];
	char enter_id[30];
	char enter_pass[30];
	bool y=0;
	
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
	
	
	fin.open("empcred.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(Name[i], 30, '\t'), fin.getline(Id[i], 30, '\t'), fin.getline(Pass[i], 30, '\n'))	//Getting all items in arrays
	{
		i++; 
	}
	fin.close();
			
			//taking ID and PAss
			
		cout << "\033[93;40;1m\n\n\tEnter your ID: \033[0m";
		cin.getline(enter_id, 30, '\n');
		cout << "\033[93;40;1m\n\n\tEnter your Password: \033[0m";
		cin.getline(enter_pass, 30, '\n');
		
		
		for (int k=0; k<i; k++)
		{
			if((strcmp(enter_id, Id[k])==0)&&(strcmp(enter_pass, Pass[k])==0))		//condition if ID and PAss matches
			{
				p=k;		//p is index of employee that is logged in in employee txt files
				cout << "\033[94;40;1m\n\n________________________________________________________________________________\n\n\n\n\033[0m";
				cout << "\033[94;107;1m\t Logged in as  [ "<<Name[p]<<"  ]  \t\033[0m"<<endl<<endl<<endl;
				y=1;
				break;
			}
		
		}

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
	
	return y;
}


/****************************************************************************************************************************************************************/


int Emporder(void)
{
	//First taking data from stock txt 
	
	char line1[30];
	char line11[30];
	char array[30];
	char arr[15][30];
	int arr1[30];
	int count = 0;
	int i=0;
	int j=0;
	int q=0;
	int size;
	int order_id;
	int order_qty;
	int choice;
	int index;
	int total_price=0;
	int total_items=0;
	bool x=0, y=0, z=0, m=0, n=0, r=0;
	
	
	ifstream fin;
	fin.open("stock.txt", ios::in);			//reading from stock txt file
	
	fin.getline(array, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array, 30, '\n');
		count++;
	
	}
	fin.close();
	
	size = count++;
	
	
	char **item;				//Making 2d dynamic array for items 
	char **item_s;
	item_s = new char*[size];
	item = new char*[size];
	
	int *Id = new int[size];		//Making 1d dynamic arrays
	int *Price = new int[size];
	int *Amount = new int[size];
	int *Sold = new int[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array
	{
		item[i] = new char[30];
		item_s[i] = new char[30];
		
	}
	
	fin.open("stock.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(item[i], 30, '\t'), fin>>Id[i]>>Price[i]>>Amount[i])				//Getting all items in arrays
	{
		fin.ignore();
		i++; 
	}
	fin.close();
	
	
	fin.open("itemsales.txt", ios :: in);			//reading from itemsales txt to keep track of sales
	
	while (fin.getline(item_s[q], 30, '\t'), fin>>Sold[q])				//Getting all items in arrays
	{
		fin.ignore();
		q++; 
	}
	fin.close();
	
	
	
	ofstream fout;
	fout.open("receipt.txt", ios :: out);		//now writing in receipt txt for receipt
	fout<<"Items\t\tQuantity\n";
	do
	{
	
	do
	{
	x=0;
	cout<<"\n\nEnter the ID of item ordered : ";
	cin>>order_id;
	
	for (int k=0; k<i; k++)
	{
		if(order_id == Id[k])		//This condition checks if entered ID item exists or not, if not then it asks to enter again
		{
			x=1;
			break;
		}
		
	}
	if (x==0)
		cout<<"\033[91;40;1m\n\n No items found with this ID. Please enter again. \n\n\033[0m"<<endl;
	
	}while(x==0);			//Loop continues until correct ID is found
	
	
	do
	{
	z=0, y=0, m=0;
	
	do
	{
	cout<<"\n\nEnter quantity of item : ";
	cin>>order_qty;
	if(order_qty<1)
	{
		cout<<"\033[91;40;1m\n\n Please Enter quantity greater than 1 \n\n\033[0m"<<endl;
	}
	else
		r=1;
	}while(r==0);			//loop continues until quantity is >1
	
	for (int k=0; k<i; k++)
	{
		if(order_id == Id[k])			//Finding ordered item in stock txt
		{
			if(order_qty <= Amount[k])	//condition checks if ordered quantity is avalable or not
			{
				y=1;
				index = k;
				break;
			}
		}
	}
	
	if(y==0)			//If quantity is not available
	{
		cout<<"\033[91;40;1m\n\n Sorry! That much quantity is not available. \n\n\033[0m"<<endl;
		do
		{
		cout<<"\n\n\t1. Enter quantity again"<<endl;
		cout<<"\n\t2. Exit Order"<<endl;
		cout<<"\n\n Select any option (1-2) : ";
		cin>>choice;
		
		switch (choice)
		{
			case 1:
				m=1;
				break;
			case 2:				//setting flags to 1 if exit order
				m=1;
				z=1;
				n=1;
				break;
			default:
				cout<<"\033[91;40;1m\n\n Invalid Input! Please enter between (1-2).\n\n\033[0m"<<endl;
		}
		
		}while(m==0);		//loop continues until valid input
	}
	else
		break;
		
	}while(z==0);				//Main do while loop continues until exit program or if qty is available
	
	if(y==1)		//if quantity is available
	{
		cout<<"\n\n-------------------------------------------------------------------------------------------";
		fout<<item[index]<<"\t\t"<<order_qty<<"\n";
		for (int k=0; k<i; k++)
		{
			if(order_id == Id[k])			//this counts total price and items ordered
			{
				total_price = total_price + (Price[k]*order_qty);
				total_items = total_items + order_qty;
				break;
			}
		
		}
		
		do
		{
		m=0, n=0;
		cout<<"\033[93;40;1m\n\n\t1. Confirm and generate receipt \n\033[0m";
		cout<<"\033[93;40;1m\n\n\t2. Order more items\n\033[0m";
		cout<<"\033[91;40;1m\n\n\t3. Dismiss Order\n\033[0m";
		cout<<"\n\n Select any option (1-3) : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:			//generates receipt 
				cout<<"\n\n-------------------------------------------------------------------------------------------";
				m=1, n=1;
				cout<<"\033[34;40;1m\n\n\t Order Confirmed!! \n\033[0m";
				fout.close();
				cout<<"\n\n Receipt : \n\n\n";
				fin.open("receipt.txt", ios :: in);			//Reading from receipt txt 
				fin.getline(line11, 30, '\n');
				
				while(fin>>arr[j], fin.ignore(), fin>>arr1[j])		//arr is item and arr1 is quantity
				{
					fin.ignore();
					j++;
				}
				cout<<"\t\t- - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
				cout<<"\t\t\t   "<<line11<<endl<<endl<<endl;
				for (int k=0; k<j; k++)
				{
					cout<<"\t\t\t   "<<arr[k]<<"\t\t"<<arr1[k]<<endl;
					
					cout<<"\t\t\t   - - - - - - - - - - - - \n";
				}
				cout<<"\n\t\t\t   -----------------------\n";
				cout<<"\t\t\t   Total Amount :  Rs."<<total_price<<endl;
				cout<<"\n\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
				
				
				
				for (int c=0; c<j; c++)			//for sales tracking
				{
					for(int k=0; k<q; k++)
					{
						if(strcmp(arr[c],item_s[k])==0)
						{
							Sold[k] = arr1[c];
						}
					
					}
				
				}
				fout.open("itemsales.txt", ios :: out);		//writing in itemsales for sales tracking
				for (int k=0; k<q; k++)
				{
					fout<<item_s[k]<<"\t"<<Sold[k]<<"\n";
				}
				fout.close();
				
				
				//Now updating stock
				for (int c=0; c<j; c++)
				{
					for(int k=0; k<i; k++)
					{
						if(strcmp(arr[c],item[k])==0)
						{
							
							Amount[k]=Amount[k]-arr1[c];
						}
					} 
					
				}
				
				fout.open("stock.txt", ios :: out);
				fout<<line1<<endl;
				for(int k=0; k<i; k++)
				{
					fout<<item[k]<<"\t";
					fout<<Id[k]<<"\t";
					fout<<Price[k]<<"\t";
					fout<<Amount[k]<<"\n";
				
				}
				fout.close();
				
				break;
			case 2:				//if order more items, it will go back to loop
				m=1;
				break;
			case 3:
				m=1, n=1;
				break;
				
			default:
				cout<<"\033[91;40;1m\n\n Invalid Input! Please enter between (1-2).\n\n\033[0m"<<endl;
		}
		
		}while(m==0);
	}
	
	}while(n==0);

	
	
	
		//Deallocating arrays
	
	for (int i=0; i<size; i++)
	{
		delete[]item[i];
		delete[]item_s[i];
	}
		
	delete[] item;
	delete[] item_s;
	item_s=NULL;
	item=NULL;
	
	delete [] Id;
	Id=NULL;
	delete [] Price;
	Price=NULL;
	delete [] Amount;
	Amount=NULL;	
	delete [] Sold;
	Sold=NULL;
	
	return total_items;
	
}

/****************************************************************************************************************************************************************/

void Updsales(int p, int item_sold)
{
	int count=0;
	int i=0;
	int size;
	char array[30];
	char line1[30];
	
	ifstream fin;
	fin.open("empinfo.txt", ios::in);		//reading from employees info file
	
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
	char **Post;
	
	Name = new char*[size];
	Post = new char*[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d arrays
	{
		Name[i] = new char[30];
		Post[i] = new char[30];
		
	}
	
	ifstream empinfo;		//this to read from employeesinformation file

	empinfo.open("empinfo.txt", ios :: in);
	empinfo.getline(line1, 30, '\n');				//Getting first line of file
	
	i=0;
	while (empinfo.getline(Name[i], 30, '\t'), empinfo.getline(Post[i], 30, '\t'), empinfo>>Age[i]>>Sales[i])	//Getting all items in arrays
	{
		empinfo.ignore();
		i++; 
	}
	empinfo.close();
	
	
	for(int k=0; k<i; k++)
	{
		if(strcmp(Name[k], Name[p])==0)			//checks if employee is employee logged in
		{
			Sales[k]=Sales[k]+item_sold;			//update sales of employee
			
		}
	}
	
	ofstream fout;
	fout.open("empinfo.txt", ios :: out);			//writing back in employee info
	fout<<line1<<endl;
	for(int k=0; k<i; k++)
	{
		
		fout<<Name[k]<<"\t";
		fout<<Post[k]<<"\t";
		fout<<Age[k]<<"\t";
		fout<<Sales[k]<<"\n";
	}
	fout.close();
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
	{
		delete[]Name[i];
		delete[]Post[i];
	}
		
	delete[] Name;
	delete[] Post;
	Name=NULL;
	Post=NULL;
	
	delete [] Age;
	Age=NULL;
	delete [] Sales;
	Sales=NULL;
	
}


/****************************************************************************************************************************************************************/


bool Userlogin(int& p)
{
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;
	char enter_id[30];
	char enter_pass[30];
	bool y=0;
	
	ifstream fin;
	fin.open("users.txt", ios::in);
	
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
	

		cout << "\033[93;40;1m\n\n\tEnter your ID: \033[0m";
		cin.getline(enter_id, 30, '\n');
		cout << "\033[93;40;1m\n\n\tEnter your Password: \033[0m";
		cin.getline(enter_pass, 30, '\n');
		
		
		for (int k=0; k<i; k++)
		{
			if((strcmp(enter_id, Id[k])==0)&&(strcmp(enter_pass, Pass[k])==0))		//when both pass and ID is correct it logs in
			{
				p=k;
				cout << "\033[94;40;1m\n\n________________________________________________________________________________\n\n\n\n\033[0m";
				cout << "\033[94;107;1m\t Logged in as  [ "<<Id[p]<<"  ]  \t\033[0m"<<endl<<endl<<endl;
				y=1;
				break;
			}
		
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
	
	return y;
}


/****************************************************************************************************************************************************************/

void Menudisp(void)
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
	
	cout<<"\t\tItems\tId\tPrice\n";
	for (int k=0; k<i; k++)				//k<i because line1 is separated above
	{
		cout<<endl<<"\t\t";
		cout<<item[k]<<"\t";
		cout<<Id[k]<<"\t";
		cout<<Price[k]<<"\n";
		cout<<"\t\t________________________"<<endl;
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

void Usersearch(void)
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
	
	
	//int *arr = new char[size];
	
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
					cout<<"\tItems\tId\tPrice"<<endl;
					cout<<"\t________________________"<<endl<<endl;
					cout<<"\t"<<item[k]<<"\t"<<Id[k]<<"\t"<<Price[k]<<endl;
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



void Userschedule(void)
{
	int sch_id;
	int sch_qty;	
	bool x=0, y=0,z=0, n=0, r=0;
	
	char line1[30];
	char line11[30];
	char array[30];
	char array1[30];
	char sch_items[30][30];
	int SNumber[30];
	int quantity[30];
	int newnum, choice, p;
	int count = 0;
	int count1 = 0;
	int i=0;
	int j=0;
	int size;
	
	//First reading data from stock txt file
	
	ifstream fin;
	fin.open("stock.txt", ios::in);			//reading from stock txt
	
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
	
	
	do
	
	{
	
	
	do
	{
		x=0;
		cout<<"\n\nEnter the ID of item you want to order : ";			//taking input id from user
		cin>>sch_id;
		
		for (int k=0; k<i; k++)
		{
			if(sch_id == Id[k])				//checking if id exists in stock, if not it generates error 
			{
				x=1;
				p=k;
				break;
			}
			
		}
		if (x==0)
			cout<<"\033[91;40;1m\n\n No items found with this ID. Please enter again. \n\n\033[0m"<<endl;
		
	}while(x==0);				//continues if invalid ID
	r=0;
	do
	{
	cout<<"\n\nEnter quantity of item you want to order : ";		//taking quantity of item from user
	cin>>sch_qty;
	
	if(sch_qty<1)
	{
		cout<<"\033[91;40;1m\n\n Please enter quantity greater than 1 !\n\n\033[0m"<<endl;
	}
	else 
		r=1;
	}while(r==0);
	
	//Automation for serial number
	
	newnum=0, count1=0;			//newnum would be serial number
	ifstream fin;
	fin.open("schedule.txt", ios :: in);
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array1, 30, '\n');
		count1++;
	}
	fin.close();
	newnum = count1-2;      //because it coounts one more line

	
	fin.open("schedule.txt", ios :: in);
	fin.getline(line11, 30, '\n');
	j=0;
	while(fin>>SNumber[j], fin.ignore(), fin.getline(sch_items[j], 30, '\t'), fin>>quantity[j])
	{
		j++;
	}
	fin.close();
	
	do
	{
		for (int k=0; k<j; k++)
		{
			if(newnum == SNumber[k])
			{
				newnum++;
				y=1;
				break;
			}
			y=0;
		}
	}while (y==1);
	
	//Mene uper ye kia hai k schedule order k serial number generate krny k liye aik automatic system banaya hai. Jis mein pehly file mein sy lines count hoti or woh serial number ban jata. Phir check krta k ye serial number file mein already mujood hai ya nahi. Agr already hai to serial number mein aik plus hojata then again check hota. Is tarah jab tak new serial number nahi mil jata tab tak loop chalta
	
	//now writing the order in scheduled txt file
	
	ofstream fout;
	fout.open("schedule.txt", ios :: app);
	fout<<newnum<<"\t"<<item[p]<<"\t"<<sch_qty<<"\n";
	fout.close();
	
	do
	{
	cout<<"\n\n\t1. Continue Ordering "<<endl;		//asking user if he want to continue ordering or exit
	cout<<"\n\t2. Exit Order "<<endl;
	cout<<"\n\nSelect any option : ";
	cin>>choice;
	
	switch (choice)
	{
		case 1:
			n=1;
			break;
		case 2:
			cout<<"\033[34;40;1m\n\n Your order has been scheduled successfully ! \n\n\033[0m"<<endl;
			z=1, n=1;
			break;
		default:
			cout<<"\033[91;40;1m\n\n Invalid Input! Please enter between (1 - 2). \n\n\033[0m"<<endl;
			break;
	
	}
	}while(n==0);			//continues if invalid input
	
	}while(z==0);			//continues if continue ordering
	
	
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


void Schedule(void)
{
	char line11[30];
	char sch_item[30][30];				//scheduled items from scheduled file will be stored here
	int Snumber[30];				//S.no of scheduled items from scheduled file will be stored here
	int sch_qty[30];				//Quantity scheduled items from scheduled file will be stored here
	int j=0, choice, order, m, p;
	bool x=0, y=0, z=0;				//different bools are used in different do while loops
	
	//First of all reading from stocks file
	
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;

	ofstream fout;
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
	
	fin.open("schedule.txt", ios :: in);			//Now opening schedule txt and reading from it in arrays
	fin.getline(line11, 30, '\n');
	
	while(fin>>Snumber[j], fin.ignore(), fin.getline(sch_item[j], 30, '\t'), fin>>sch_qty[j])		//Getting all items in arrays
	{
		j++;
		
	}
	fin.close();
	
	do						
	{
	x=0, y=0, z=0;
	
	//Printing the scheduled orders 
	
	cout<<"\n\n\t\tS.No\t\tItem\t\tQuantity\n"<<endl;
	for(int k=0; k<j; k++)
	{
		
		cout<<"\t\t"<<Snumber[k]<<"\t\t"<<sch_item[k]<<"\t\t"<<sch_qty[k]<<"\n";
		cout<<"\n\t  --------------------------------------------------\n\n";
	
	}
	
	cout<<"\n\n-------------------------------------------------------------------------------------------------\n\n";
	cout<<"\n\t 1. Approve Order \n";
	cout<<"\n\t 2. Decline Order \n";
	cout<<"\n\t 3. Go Back \n";
	cout<<"\n\n Select one of the option (1-3) :";			//taking choice from admin/employee 
	cin>>choice;
	
	switch(choice)
	{
		case 1:					//to approve order
			do
			{
			x=0;
			cout<<"\n\n Enter S.No of scheduled order you want to approve : ";
			cin>>order;
			
			for (int k=0; k<j; k++)			//Checking if schedule order with this s no exists or not
			{
				if(order == Snumber[k])
				{
					m=k;			//m is now the index of scheduled order selected
					x=1;
					break;
				}
			
			}
			if (x==0)			//if not then prints error and loop goes on
				cout<<"\033[91;40;1m\n\n No orders found with this S.No. Please enter again ! \n\n\033[0m"<<endl;
				
			}while (x==0);		//loop breaks if entered s.no exists 
			
			for (int k=0; k<i; k++)			//stocks ki file k liye loop
			{
				if(strcmp(sch_item[m], item[k])==0)			//Finding the selected schedule order item from stock
				{
					p=k;						//p is now index of stock item that is scheduled
					
					if(sch_qty[m] <= Amount[k])			//this condition checks k utni items stock mein available hein or not
					{
						y=1;
						z=1;
						
						fout.open("schedule.txt", ios :: out);			
						fout<<line11<<endl;
						for(int s=0; s<j; s++)		//deleting order from schedule txt that is approved
						{
							
							if(Snumber[s] == Snumber[m])		//This does not write data when condition satisfies
							{
								cout<<"\033[34;40;1m\n\n Order Approved Successfully ! \n\n\033[0m"<<endl;
							cout<<"\n\n--------------------------------------------------------------------------------------\n\n";
							
							}
							else
							{
								fout<<Snumber[s]<<"\t"<<sch_item[s]<<"\t"<<sch_qty[s]<<"\n";
							
							}
							
						} 
						fout.close();
						break;
					}
					else		//Generates an error message when not enough quantity is in stock
					{
						cout<<"\033[91;40;1m\n\n Sorry ! "<<sch_qty[m]<<" "<<item[p]<<" not available in stock.\n\n\033[0m"<<endl;
						cout<<"\n\n--------------------------------------------------------------------------------------\n\n";
						z=1;
						break;
					}
				}
			
			}

			if(y==1)			//Updating stock when item is approved 
			{
				
				fout.open("stock.txt", ios :: out);
				fout<<line1<<endl;
				for(int k=0; k<i; k++)
				{
					if(Id[k] == Id[p])
					{
						Amount[k] = Amount[k] - sch_qty[m];
					}
					
					fout<<item[k]<<"\t";
					fout<<Id[k]<<"\t";
					fout<<Price[k]<<"\t";
					fout<<Amount[k]<<"\n";
				
				}
				fout.close();
			
			}
			
			break;
			
		case 2:						//to decline order
			
			do
			{
			x=0;
			cout<<"\n\n Enter S.No of scheduled order you want to Decline : ";
			cin>>order;
			
			for (int k=0; k<j; k++)			//stocks ki file k liye loop
			{
				if(order == Snumber[k])			//Checking if schedule order with this s no exists or not
				{
					x=1;
					
					fout.open("schedule.txt", ios :: out);		//now deleting declined order from schedule txt
					fout<<line11<<endl;
					for(int s=0; s<j; s++)
					{
							
							if(Snumber[s] == Snumber[m])
							{
								cout<<"\033[34;40;1m\n\n Order has been declined  \n\n\033[0m"<<endl;
								z=1;
							
							}
							else
							{
								fout<<Snumber[s]<<"\t"<<sch_item[s]<<"\t"<<sch_qty[s]<<"\n";
							
							}
							
					} 
					fout.close();
					break;
				}
			
			}
			if (x==0)
				cout<<"\033[91;40;1m\n\n No orders found with this S.No. Please enter again ! \n\n\033[0m"<<endl;
				
			}while (x==0);
			
			break;
			
		case 3:						//go back
			z=1;
			break;
			
		default:
			cout<<"\033[91;40;1m\n\n Invalid Input! Please enter between (1 - 3). \n\n\033[0m"<<endl;
			break;
	
	
	}

	}while(z==0);
	
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

void Stats(void)
{

/****************************************************************************************************************************************************************/
//Finding best seller 
	int count=0;
	int i=0, q=0;
	int size;
	char array[30];
	char line1[30];
	int max, best, least;
	int p=0, total_sold=0;
	
	ifstream fin;
	fin.open("empinfo.txt", ios::in);
	
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
	char **Post;
	Name = new char*[size];
	Post = new char*[size];

	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d arrays
	{
		Name[i] = new char[30];
		Post[i] = new char[30];
		
	}
	
	//Now to read from employeesinformation file
	
	fin.open("empinfo.txt", ios :: in);
	fin.getline(line1, 30, '\n');				//Getting first line of file
	
	i=0;
	while (fin.getline(Name[i], 30, '\t'), fin.getline(Post[i], 30, '\t'), fin>>Age[i]>>Sales[i])	//Getting all items in arrays
	{
		fin.ignore();
		i++; 
	}
	fin.close();
	
	max = Sales[0];					//initializing max to 0 index
	for(int k=0; k<i; k++)
	{
		if(Sales[k]>max)			//checks one by one if Sales are greater than max 
		{
			max = Sales[k];			//if confition satisfies then updates max value
			p=k;
		
		}
	}
	
	cout<<"\033[93;40;1m\n\n\t - Best Seller Of the Day is : \033[0m";
	cout<<"\033[92;40;1m"<<Name[p]<<"\n\n\033[0m"<<endl;
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
	{
		delete[]Name[i];
		delete[]Post[i];
	}
		
	delete[] Name;
	delete[] Post;
	Name=NULL;
	Post=NULL;
	
	delete [] Age;
	Age=NULL;
	delete [] Sales;
	Sales=NULL;
	
/****************************************************************************************************************************************************************/
//Now calculating stocks stats

	char line11[30];
	char array1[30];
	int no_of_items=0;
	int stockprice=0;
	float avg;
	i=0;
	count = 0;
	
	fin.open("stock.txt", ios::in);
	
	fin.getline(array1, 30, '\n');		
	while(!fin.eof())				//This loop checks how many lines are in the file
	{
		fin.getline(array1, 30, '\n');
		count++;
	
	}
	fin.close();
	
	size = count++;
	
	
	char **item;				//Making 2d dynamic array for items 
	char **item_s;
	item = new char*[size];
	item_s = new char*[size];
	
	
	int *Id = new int[size];		//Making 1d dynamic arrays
	int *Price = new int[size];
	int *Amount = new int[size];
	int *Sold_it = new int[size];
	
	for (int i=0; i<size; i++)		//Allocating dynamic memory to 2d array
	{
		item[i] = new char[30];
		item_s[i] = new char[30];
		
	}
	
	fin.open("stock.txt", ios :: in);
	fin.getline(line11, 30, '\n');				//Getting first line of file
	
	
	while (fin.getline(item[i], 30, '\t'), fin>>Id[i]>>Price[i]>>Amount[i])				//Getting all items in arrays
	{
		fin.ignore();
		i++; 
	}
	fin.close();
	
	for(int k=0; k<i; k++)
	{
		no_of_items = no_of_items + Amount[k];				//this counts number of items in stock
		stockprice = stockprice + (Amount[k]*Price[k]); 		//this counts total price of stock
	
	}
	
	avg = stockprice/no_of_items;
	cout<<"********************************************************************\n";
	cout<<"*							           *\n";
	cout<<"*		Total Items in stock : "<<no_of_items<<"	   		   *\n";
	cout<<"*					      			   *\n";
	cout<<"*		Total worth of stock : Rs. "<<stockprice<<"		   *\n";
	cout<<"*					      			   *\n";
	cout<<"*		Average Price per Item : Rs. "<<avg<<"		   *\n";
	cout<<"*							           *\n";
	cout<<"********************************************************************\n\n";
	
	
/****************************************************************************************************************************************************************/
//Now calculating sold items best least
	p=0;
	fin.open("itemsales.txt", ios :: in);
	
	while (fin.getline(item_s[q], 30, '\t'), fin>>Sold_it[q])				//Getting all items in arrays
	{
		fin.ignore();
		q++; 
	}
	fin.close();
	
	best = Sold_it[0];
	for(int k=0; k<q; k++)
	{
		if(Sold_it[k]>best)			//checks one by one if sold items are greater than best
		{
			best = Sold_it[k];
			p=k;
		}
	}
	
	cout<<"\033[93;40;1m\n\t - Most sold item is : \033[0m";
	cout<<"\033[92;40;1m"<<item_s[p]<<"\n\n\033[0m"<<endl;
	
	least = Sold_it[0];
	for(int k=0; k<q; k++)
	{
		if(Sold_it[k]<least)			//checks one by one if sold items are less than best
		{
			least = Sold_it[k];
			p=k;
		}
	}
	
	cout<<"\033[93;40;1m\n\t - Least sold item is : \033[0m";
	cout<<"\033[91;40;1m"<<item_s[p]<<"\n\n\033[0m"<<endl;
	
	for(int k=0; k<q; k++)
	{
		total_sold = total_sold + Sold_it[k];			//counting total items sold
		
	}
	
	cout<<"\033[94;40;1m\n\t Total Items Sold : "<<total_sold<<" \033[0m";
	
	//Deallocating arrays
	
	for (int i=0; i<size; i++)
	{
		delete[]item[i];
		delete[]item_s[i];
	}	
	delete[] item;
	delete[] item_s;
	item=NULL;
	item=NULL;
	
	delete [] Id;
	Id=NULL;
	delete [] Price;
	Price=NULL;
	delete [] Amount;
	Amount=NULL;
	delete [] Sold_it;
	Sold_it=NULL;
	
}

/****************************************************************************************************************************************************************/


/****************************************************************************************************************************************************************/


void Sort(void)
{
	char line1[30];
	char array[30];
	int count = 0;
	int i=0;
	int size;
	bool x=0;
	int choice1, choice;
	
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
	
	cout<<"\n\n\t1. Sort by Name"<<endl;
	cout<<"\n\t2. Sort by Price"<<endl;
	cout<<"\n\t3. Sort by Id"<<endl;
	cout<<"\n\t4. Sort by Quantity"<<endl;
	cout<<"\n\t5. Go Back"<<endl;
	cout<<"\n\n Select any option (1-5) : ";
	cin>>choice;
	
	switch (choice)
	{
		case 1:
			cout<<"\n\t1. Ascending"<<endl;
			cout<<"\n\t2. Descedning"<<endl;
			cout<<"\n\n Select any option : ";
			cin>>choice1;
				
			switch (choice1)
			{
				case 1:
					do
					{
					x=0;
					for (int k=0; k<i-1; k++)		//i-1 because loop aik bar zada chal raha tha
					{
						if(item[k][0]>item[k+1][0])		//checks first alphabet of two adjacent indexes and swaps
						{
							swap(item[k], item[k+1]);
							swap(Id[k], Id[k+1]);
							swap(Price[k], Price[k+1]);
							swap(Amount[k], Amount[k+1]);
							x=1;
						}
					}
					
					}while(x==1);			//loop continues until sorted
					
					cout<<"\033[92;40;1m\n\n\t Items Sorted by Name in Ascending order. \n\033[0m"<<endl;
					break;
					
				case 2:
					do
					{
					x=0;
					for (int k=0; k<i-1; k++)
					{
						if(item[k][0]<item[k+1][0])
						{
							swap(item[k], item[k+1]);
							swap(Id[k], Id[k+1]);
							swap(Price[k], Price[k+1]);
							swap(Amount[k], Amount[k+1]);
							x=1;
						}
					}
					
					}while(x==1);
					
					cout<<"\033[92;40;1m\n\n\t Items Sorted by Name in Descending order. \n\033[0m"<<endl;
					break;
				default:
					cout<<"\033[91;40;1m\n\n\tInvalid Input! Please Enter between (1-2)\n\033[0m"<<endl;
					break;
			
			}	
			break;
		case 2:
			cout<<"\n\t1. Ascending"<<endl;
			cout<<"\n\t2. Descedning"<<endl;
			cout<<"\n\n Select any option : ";
			cin>>choice1;
				
			switch (choice1)
			{
				case 1:
					do
					{
					x=0;
					for (int k=0; k<i-1; k++)
					{
						if(Price[k]>Price[k+1])
						{
							swap(item[k], item[k+1]);
							swap(Id[k], Id[k+1]);
							swap(Price[k], Price[k+1]);
							swap(Amount[k], Amount[k+1]);
							x=1;
						}
					}
					
					}while(x==1);
					
					cout<<"\033[92;40;1m\n\n\t Items Sorted by Price in Ascending order. \n\033[0m"<<endl;
					break;
					
				case 2:
					do
					{
					x=0;
					for (int k=0; k<i-1; k++)
					{
						if(Price[k]<Price[k+1])
						{
							swap(item[k], item[k+1]);
							swap(Id[k], Id[k+1]);
							swap(Price[k], Price[k+1]);
							swap(Amount[k], Amount[k+1]);
							x=1;
						}
					}
					
					}while(x==1);
					
					cout<<"\033[92;40;1m\n\n\t Items Sorted by Price in Descending order. \n\033[0m"<<endl;
					break;
					
				default:
					cout<<"\033[91;40;1m\n\n\tInvalid Input! Please Enter between (1-2)\n\033[0m"<<endl;
					break;
			
			}	
			break;
		case 3:
			cout<<"\n\t1. Ascending"<<endl;
			cout<<"\n\t2. Descedning"<<endl;
			cout<<"\n\n Select any option : ";
			cin>>choice1;
				
			switch (choice1)
			{
				case 1:
					do
					{
					x=0;
					for (int k=0; k<i-1; k++)
					{
						if(Id[k]>Id[k+1])
						{
							swap(item[k], item[k+1]);
							swap(Id[k], Id[k+1]);
							swap(Price[k], Price[k+1]);
							swap(Amount[k], Amount[k+1]);
							x=1;
						}
					}
					
					}while(x==1);
					
					cout<<"\033[92;40;1m\n\n\t Items Sorted by ID in Ascending order. \n\033[0m"<<endl;
					break;
					
				case 2:
					do
					{
					x=0;
					for (int k=0; k<i-1; k++)
					{
						if(Id[k]<Id[k+1])
						{
							swap(item[k], item[k+1]);
							swap(Id[k], Id[k+1]);
							swap(Price[k], Price[k+1]);
							swap(Amount[k], Amount[k+1]);
							x=1;
						}
					}
					
					}while(x==1);
					
					cout<<"\033[92;40;1m\n\n\t Items Sorted by ID in Descending order. \n\033[0m"<<endl;
					break;
					
				default:
					cout<<"\033[91;40;1m\n\n\tInvalid Input! Please Enter between (1-2)\n\033[0m"<<endl;
					break;
			
			}	
			break;
		case 4:
			cout<<"\n\t1. Ascending"<<endl;
			cout<<"\n\t2. Descedning"<<endl;
			cout<<"\n\n Select any option : ";
			cin>>choice1;
				
			switch (choice1)
			{
				case 1:
					do
					{
					x=0;
					for (int k=0; k<i-1; k++)
					{
						if(Amount[k]>Amount[k+1])
						{
							swap(item[k], item[k+1]);
							swap(Id[k], Id[k+1]);
							swap(Price[k], Price[k+1]);
							swap(Amount[k], Amount[k+1]);
							x=1;
						}
					}
					
					}while(x==1);
					
					cout<<"\033[92;40;1m\n\n\t Items Sorted by Quantity in Ascending order. \n\033[0m"<<endl;
					break;
					
				case 2:
					do
					{
					x=0;
					for (int k=0; k<i-1; k++)
					{
						if(Amount[k]<Amount[k+1])
						{
							swap(item[k], item[k+1]);
							swap(Id[k], Id[k+1]);
							swap(Price[k], Price[k+1]);
							swap(Amount[k], Amount[k+1]);
							x=1;
						}
					}
					
					}while(x==1);
					
					cout<<"\033[92;40;1m\n\n\t Items Sorted by Quantity in Descending order. \n\033[0m"<<endl;
					break;
					
				default:
					cout<<"\033[91;40;1m\n\n\tInvalid Input! Please Enter between (1-2)\n\033[0m"<<endl;
					break;
			
			}	
			break;
		case 5:
			break;
		default:
			cout<<"\033[91;40;1m\n\n\tInvalid Input! Please Enter between (1-5)\n\033[0m"<<endl;
			break;
	
	
	}
	
	ofstream fout;
	fout.open("stock.txt", ios :: out);
	fout<<line1<<endl;
	
	for(int k=0; k<i; k++)
	{
			fout<<item[k]<<"\t";
			fout<<Id[k]<<"\t";
			fout<<Price[k]<<"\t";
			fout<<Amount[k]<<"\n";
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


void Notif(void)
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
	
	
	cout<<"\033[93;40;1m\n\n - - - - - - - - - - - - - - - - - - - -\n\033[0m";
	cout<<"\033[92;40;1m\nNotifications : \n\n\033[0m";
	for (int k=0; k<i; k++)
	{
	cout << "\033[94;40;1;5m - "<<Notif[k]<<"\n\033[0m";
	}
	cout<<"\033[93;40;1m\n - - - - - - - - - - - - - - - - - - - -\n\n\033[0m";

}

/****************************************************************************************************************************************************************/


void Warning(void)
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
	
	
	for(int k=0; k<i; k++)
	{
		if(Amount[k]<10)		//condition to check if item is lower than threshold (10)
		{
			cout<<endl<<endl;
			cout<<"\033[91;107;1;5m  [ Warning ! "<<item[k]<<" are low in stock  ]   \033[0m"<<endl;
		}
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

/****************************************************************************************************************************************************************/

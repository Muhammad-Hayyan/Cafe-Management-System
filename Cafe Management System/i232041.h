/* 	MUHAMMAD HAYYAN
	23I - 2041
	CY-A
	PF-Project */

#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>

using namespace std;

//Function for admin login
void loginad(bool&, bool&);

//Function to display items of stock
void Itdisplay(void);

//Function to search an item from stock
void Search(void);

//Function to remove an item from stock
void Remove(void);

//Function to add an item to stock
void Add(void);

//Function to order new items for stock
void Order(void);

//Function to update the stock
void Update(void);

//Function to display stock information
void Stockinfo(void);

/****************************************************************************************************************************************************************/

//Function to display employees information and credentials
void Empdisp(void);

//Function to edit employees credentials
void Changecred(void);

//Function to add credentials of a new employee
void Addcred(void);

//Function to remove employees credentials
void Removecred(void);

//Function to display all users who logged in
void Userdisp(void);

//Function to change user credentials
void Changeusercred(void);

//Function to remove user credentials
void Userrm(void);

//Function to add user credentials
void Addusers(void);

//Function to view Notifications
void ViewNotif(void);

//Function to add Notifications
void AddNotif(void);

//Function to remove notifications
void RemNotif(void);

//Function for complaints
void Complaints(void);

//Function for schedule orders
void Schedule(void);

/****************************************************************************************************************************************************************/

//Function for employee login
bool Emplogin(int&);

//Function for employee take order
int Emporder(void);

//Function to update employee sales
void Updsales(int, int);

/****************************************************************************************************************************************************************/

//Function for user login
bool Userlogin(int&);

//function to display menu
void Menudisp(void);

//Function for user search items
void Usersearch(void);

//Function for user to schedule order
void Userschedule(void);

//Function for employee/admin to handle schedule items
void Schedule(void);

//Function for statistics
void Stats(void);

//Function to sort 
void Sort(void);

//Function for notifications
void Notif(void);

//Function for warning for threshold
void Warning(void);

//Function to add complaint
void AddComplaint(void);

/****************************************************************************************************************************************************************/

/****************************************************************************************************************************************************************/

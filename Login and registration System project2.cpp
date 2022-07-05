
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>
#include<stdlib.h> 
#include <conio.h>
using namespace std;
void login();
void registration();
void forgot_password();
void change_password();

int main(){
	int choice;
	cout<<"\t\t\t************************************************************\n\n\n";
	cout<<"\t\t\t                      WELCOME TO THE LOGIN PAGE               \n\n\n";
	cout<<"\t\t\t************************* MENU *****************************\n\n\n\n";
	cout<<"\t| Press 1 to LOGIN                        |"<<endl;
	cout<<"\t| Press 2 to REGISTER                     |"<<endl;
    cout<<"\t| Press 3 to if you forgotten your PASSWORD  |"<<endl;
	cout<<"\t| Press 4 to change the PASSWORD  |"<<endl;
    cout<<"\t| Press 5 to EXIT                         |"<<endl;

    cout<<"\n\t\t\t Please enter your choice : ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
    	case 1:
    	login();
    	break;

    	case 2:
    	registration();
    	break;

    	case 3:
    	forgot_password();
    	break; 

		case 4:
		change_password();
		break;

    	case 5:
		 system("clear");
    	cout<<"\t\t\t THANK YOU SO MUCH FOR VISITING! \n\n";
    	main();
    	break;

    	default:
		 system("clear");
    	
    	cout<<" \t\t\t Please select from the above options \n\n";
    	main();
    }
}
void login(){
	int flag=0;
	string emailid,userID, password, id, pass,emid;
	 system("clear");
	cout<<"\t\t\t\t Please enter your username and password : "<<endl;
	cout<<"\t\t\t USERNAME : ";
	cin>>userID;
	cout<<endl;
	cout<<"\t\t\t PASSWORD : ";
	cin>>password;

	ifstream in("records.txt");
	while(in>>emid>>id>>pass){
		if(id==userID && pass==password){
			flag=1;
			 system("clear");
			break;
		}
	}
	in.close();
	if(flag==1){
		cout<<userID<<"\n Your LOGIN is successfull \n Thanks for logging in ! \n\n";
		main();
	}
	else{
		 system("clear");
		cout<<"\n INVALID CREDINTALS \n Please check your USERNAME and PASSWORD \n\n";
		main();
	}
}
void registration(){
	string remailID, ruserID,rpassword,remid,rusid,rpass;
	 system("clear");
	cout<<"\n\n Enter the EMAIL ID : ";
	cin>>remailID;
	int flag1=0;
	ifstream input1("records.txt");
	while(input1>>remid>>rusid>>rpass){

		if(remid==remailID){
			flag1=1;
			break;
		}
	}
	input1.close();
	if(flag1==1){
		 system("clear");
		cout<<"\n\n This email-id has already been registered \n\n";
		main();
	}
	m:
		cout<<"\n Enter the USER ID : ";
		cin>>ruserID;
		int flag2=0;
	ifstream input2("records.txt");
	while(input2>>remid>>rusid>>rpass){

		if(rusid==ruserID){
			flag2=1;
			break;
		}
	}
	input2.close();
	if(flag2==1){
		 system("clear");
		cout<<"\n\n This user-id has already been taken";
		cout<<"\n\n Please enter the new USER ID";
		goto m;
	}
	int flag3=0;
	int flag4=0;
	int flag5=0;
	cout<<"\n\n Enter the PASSWORD : ";
		cin>>rpassword;
		if(rpassword.size()<=6){
			 system("clear");
			cout<<"\n\n PASSWORD size must be greater than 6";
			goto m;
		}
		for(int i=0;i<rpassword.size();i++){
			if(rpassword[i]>='0' && rpassword[i]<='9'){
				flag3=1;
			}
			if(rpassword[i]>='a' && rpassword[i]<='z'){
				flag4=1;
			}
				if(rpassword[i]>='A' && rpassword[i]<='Z'){
				flag5=1;
			}

		}
		if(flag3==0 || flag4==0|| flag5==0){
			 system("clear");
			cout<<"\n\n Your password must contain atleast one upper case character, lower case character and numeric character ";
			goto m;
		}
		ofstream out("records.txt",ios::app);
		out<<remailID<<' '<<ruserID<<' '<<rpassword<<endl;
		out.close();
		 system("clear");
		cout<<"\n\n\t\t\t Registration is SUCCESSFULL \n\n";
		main();
}
void forgot_password(){
	int option;
	 system("clear");
	cout<<"\t\t\t\t Did you forgot the password! No issue! \n";
	cout<<"Press 1 to search your user id by username \n";
	cout<<"Press 2 to go back to the main \n";
	cout<<"Enter your choice : ";
	cin>>option;
	switch(option)
	{
		case 1 :
		{
		int count=0;
	string suserID,semid,susid,spass;
	cout<<"\n\t\t\tEnter the user name which you remember : ";
	cin>>suserID;
	ifstream f("records.txt");
	while(f>>semid>>susid>>spass){
		if(susid==suserID){
			count=1;
			break;
		}
	}
	f.close();
	if(count==1){
		 system("clear");
		cout<<"\n\n Your account is found ! \n";
		cout<<"\n\n Your password is : "<<spass<<endl<<endl;
		main();
	}
	else{
		 system("clear");
		cout<<" INVALID USER ID! Your account is not found \n\n";
		main();

	}
	break;
}

	case 2 :
	{
    system("clear");
	main();
	break;
}

	default:
	cout<<"\t\t\t Wrong choice! Please try again \n\n"<<endl;
	forgot_password();
}
}
void change_password(){
	int flag=1;
	string email;
	string user;
	string cemailid,cuserid,cpassword,cemid,cusid,cpass;
	 system("clear");
	cout<<"\n\n Please enter your user ID : ";
	cin>>cuserid;
	cout<<"\n\n Please enter your PASSWORD : ";
	cin>>cpassword;
	ofstream f2;
	f2.open("new.txt");

	ifstream f1;
	f1.open("records.txt");

	while( f1>>cemid>>cusid>>cpass ){
		if(cuserid==cusid && cpassword==cpass){
			flag=0;
			email=cemid;
			user=cusid;
		}
		else{
		f2<<cemid<<' '<<cusid<<' '<<cpass<<endl;
	}
	}
	f1.close();
	f2.close();
	if(flag==0){
	remove("records.txt");
		rename("new.txt","records.txt");
		m:
		string password;
	int flag3=0;
	int flag4=0;
	int flag5=0;
		cout<<"\n\n Please enter your new PASSWORD :";
		cin>>password;
			if(password.size()<=6){
			 system("clear");
			cout<<"\n\n PASSWORD size must be greater than 6";
			goto m;
		}
		for(int i=0;i<password.size();i++){
			if(password[i]>='0' && password[i]<='9'){
				flag3=1;
			}
			if(password[i]>='a' && password[i]<='z'){
				flag4=1;
			}
				if(password[i]>='A' && password[i]<='Z'){
				flag5=1;
			}

		}
		if(flag3==0 || flag4==0|| flag5==0){
			 system("clear");
			cout<<"\n\n Your password must contain atleast one upper case character, lower case character and numeric character ";
			goto m;
		}
		ofstream new1("records.txt", ios::app);
		new1<<email<<' '<<user<<' '<<password<<endl;
		new1.close();
		 system("clear");
		cout<<"\n\nCongratulations! Your PASSWORD has been changed successfully \n\n";
		main();
	
	}
	else{
		 system("clear");
		cout<<"\n\n INVALID CREDINTALS \n\n";
		remove("new.text");
		main();
	}
}

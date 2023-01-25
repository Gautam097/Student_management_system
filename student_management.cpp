#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<unistd.h>
using namespace std;
void welcomescreen();
void title();
void mainmenu ();
class student_management
{
    private:
    // Variables for patient Deatails
    char student_name[100];
    char rollno[10];
    char classe[50];
    char address[50];
    char semester[50];
    char Email[20];
    char mobile[20];
    public:
    void  mainmenu();
    void welcomescreen();
    void title();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};

int main()
{
    system("cls");
    student_management system;
system.welcomescreen();
getch();
return 0;

}
void student_management::welcomescreen()
{
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t\t\tWELCOME TO AGC"<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<endl<<endl<<endl;
cout<<"press any key to continue............."<<endl;
getch();
mainmenu();
}
void student_management::title(){
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t\t\t\tAMRITSAR GROUP OF COLLEGE  "<<endl;
cout<<"\t\t\t\t\t\tSTUDENT MANAGEMENT SYSTEM "<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
}
void student_management::mainmenu(){
system("cls");
int choice;
char x;
title();
    cout<<endl<<endl<<endl;
    cout<<"\n\t\t\t\t\t 1. Enter New Record "<<endl;
    cout<<"\n\t\t\t\t\t 2. Display Record "<<endl;
    cout<<"\n\t\t\t\t\t 3. Modify Record"<<endl;
    cout<<"\n\t\t\t\t\t 4. Search Record"<<endl;
    cout<<"\n\t\t\t\t\t 5. Delete Record"<<endl;
    cout<<"\n\t\t\t\t\t 6. Exit"<<endl;

cout<<endl<<endl<<endl<<endl;
cout<<"choose from 1 to 6:-"<<endl;
cin>>choice;
switch(choice)
    {
        case 1:
        do{
            insert();
            cout<<"\n\n\t\t\t Add Another Employee Record Press (Y,N):";
            cin>>x; 
        }while(x=='Y' || x=='y');
        if(x!='Y'|| x!='y'){
            mainmenu();
        }
        break;
        case 2:
        display();
        break;
        case 3:
         do{
            modify();
            cout<<"\n\n\t\t\t Add Another Student Record Press (Y,N):";
            cin>>x; 
        }while(x=='Y' || x=='y');
        if(x!='Y'|| x!='y'){
            mainmenu();
        }
       
        break;
        case 4:
        search();
        break;
        case 5:
        deleted();
        break;
        case 6:
        system("cls");
        cout<<"\n\n\t\t\t>> STUDENT MANAGEMENT SYSTEM- BY GAUATAM KUMAR";
        sleep(9);
        exit(0);
        break;
        default:
        cout<<"\n\n\n\t\t Invalid Choice ...please Try Again..\n";
        break;
    }
    getch();

}

void student_management::insert()
{
    system("cls");
    title();
    fstream file;
    cout<<"\t\t\t\n==========================================================================="<<endl;
    cout<<"\t\t\t\t--------------Student Insert Data----------------------"<<endl;
    cout<<"\t\t\t\n=========================================================================";
    cout<<"\n Enter Student Name :";
    cin >> student_name;
    cout<<"\n Enter student roll number [max 4 digits]:";
    cin>>rollno;
    cout<<"\n Enter student class:";
    cin>>classe;
    cout<<"\n Enter student address :";
    cin>>address;
    cout<<"\n Enter Student semester:";
    cin>>semester;
    cout<<"\n Enter Student Email address:";
    cin>>Email ;
    cout<<"\n Enter student Mobile number :";
    cin>>mobile;
  
  
    file.open("student_record.txt",ios::app | ios::out);
    file<<"   "<< student_name<<"   "<<rollno<<"   "<<classe<<"   "<<address<<"   "<<semester<<"   "<<Email<<"  "<<mobile<<"   ";
    file.close();
}
void student_management::display()
{
    title();
    system("cls");
    title();
    int total =1;
    fstream file;
    cout<<"\n\n\t\t\t==============================================="<<endl;
    cout<<"\n\n\t\t\t\tStudent Record Data"<<endl;
    cout<<"\n\n\t\t\t==============================================="<<endl;
     file.open("student_record.txt",ios::in);
     if(!file)
     {
         cout<<"File not Found....Error opening"<<endl;
         file.close();
     }
     else
     {
         file>>student_name>>rollno>>classe>>address>>semester>>Email>>mobile;
         cout<<"\n\n==================================================================================================================="<<endl;
         cout<<"\n ||   NAME  ||   ROLL NO   ||   CLASS   ||    ADDRESS     ||     SEMESTER    ||        EMAIL         ||  MOBILENOS"<<endl;
         cout<<endl;
         cout<<"======================================================================================================================="<<endl;
         while(!file.eof())
         {
             cout<<endl;
             cout<<total++ <<". "<< student_name<<"\t"<<rollno<<"\t"<<classe<<"\t"<<address<<"\t"<<semester<<"\t"<<Email<<"\t"<<mobile;
             file>>student_name>>rollno>>classe>>address>>semester>>Email>>mobile;
         }
     }
     file.close();
     getch();
     mainmenu();
}
void student_management:: modify()
{
    system("cls");
    title();
    char checkroll[5];
    int found=0;
    fstream file,file1;
    cout<<"\n\n\n========================================================================";
    cout<<"\t\t\t\tStudent Modify Data";
    cout<<"\n\n=========================================================================";
    cout<<endl<<endl;
    file.open("student_record.txt",ios::in);
    if(!file)
     {
         cout<<"File not Found....Error opening"<<endl;
         file.close();
     }
     else
     {
         cout<<"Enter student rollnos: "<<endl;
         cin>>checkroll;
         file1.open("record1.txt",ios::app|ios::out|ios::ate);
         file>>student_name>>rollno>>classe>>address>>semester>>Email>>mobile;
         while(!file.eof())
         {
             if(strcmp(checkroll,rollno)==0)
             {
                cout<<"\n Enter Student Name :";
    cin >> student_name;
    cout<<"\n Enter student roll number [max 4 digits]:";
    cin>>rollno;
    cout<<"\n Enter student class:";
    cin>>classe;
    cout<<"\n Enter student address :";
    cin>>address;
    cout<<"\n Enter Student semester:";
    cin>>semester;
    cout<<"\n Enter Student Email address:";
    cin>>Email ;
    cout<<"\n Enter student Mobile number :";
    cin>>mobile;
  
                cout<<"\n\nSuccessfully Modify Details of Patient";
                file1<<"   "<< student_name<<"   "<<rollno<<"   "<<classe<<"   "<<address<<"   "<<semester<<"  "<<Email<<"   "<<mobile<<" \n  ";
                found++;
             }
             else
             {
                 file1<<"   "<< student_name<<"   "<<rollno<<"   "<<classe<<"   "<<address<<"   "<<semester<<"  "<<Email<<"   "<<mobile<<" \n  ";

             }
             file>>student_name>>rollno>>classe>>address>>semester>>Email>>mobile;
             }
         if (found==0)
         {
             cout<<"\n\n\t\tstudent ID not found...Please Try Again";
         }
         file1.close();
         file.close();
         remove("student_record.txt");
         rename("record1.txt","student_record.txt");
     }
     mainmenu();
}
void student_management::search()
{
    //Display all details according to patient's ID
    system("cls");
    title();
    fstream file;
    char checkroll[5];
    cout<<"\n\t\t\t============================================================================"<<endl;
    cout<<"\t\t\t\tSTUDENT RECORD DATA"<<endl;
    file.open("student_record.txt",ios::in);
    cout<<"\n\nEnter Student rollno::"<<endl;
    cin>>checkroll;
    if(!file)
     {
         cout<<"File not Found....Error opening"<<endl;
         file.close();
     }
     else
    {
        file>>student_name>>rollno>>classe>>address>>semester>>Email>>mobile;
        while(!file.eof())
        {
            if(strcmp(checkroll,rollno)==0)
        {
            cout<<"\n============================================"<<endl;
            cout<<"Student Name :"<<student_name<<"\n";
            cout<<"Student rollno :"<<rollno<<"\n";
            cout<<"class :"<< classe<<"\n";
            cout<<"Address:"<<address<<"\n";
            cout<<"Semester:"<<semester<<"\n";
            cout<<"student email:"<<Email<<"\n";
            cout<<"student Mobile :"<<mobile<<"\n";
            cout<<"\n============================================"<<endl;
        }
        file>>student_name>>rollno>>classe>>address>>semester>>Email>>mobile;
        getch();
        }
    }
    file.close();
    getch();
    mainmenu();
}
void student_management::deleted()
{
    system("cls");
    char checkroll[5];
    fstream file,file1;
    int found=0;
    cout<<"\n\n\t\t\t============================================================"<<endl;
    cout<<"\t\t\t\t\t\t\tSTUDENT  DELETE DATA"<<endl;
    cout<<"\n\n\t\t\t============================================================"<<endl;
    file.open("student_record.txt",ios::in);
    if(!file)
     {
         cout<<"File not Found....Error opening"<<endl;
         file.close();
     }
     else
    {
    cout<<"\nEnter student roll nos to Remove Data :";
    cin>>checkroll;
    file1.open("record1.txt",ios::app|ios::out);
    file>>student_name>>rollno>>classe>>address>>semester>>Email>>mobile;
    while(!file.eof())
    {
        if(strcmp(checkroll,rollno)!=0)
        {
            file1 <<"   "<< student_name<<"   "<<rollno<<"   "<<classe<<"   "<<address<<"   "<<semester<<"  "<<Email<<"   "<< mobile<<" \n  ";
        }
        else
        {
            found++;
            cout<<"\n\t\t\tSuccesfully Delete Data.....";
            getch();
        }
        file>>student_name>>rollno>>classe>>address>>semester>>Email>>mobile;
    }
    if(found==0)
    {
        cout<<"\n\n\tPatient ID Not Found..Please Try Again...";
    }
    file1.close();
    file.close();
    remove("student_record.txt");
    rename("record1.txt","student_record.txt");
    mainmenu();
}
}


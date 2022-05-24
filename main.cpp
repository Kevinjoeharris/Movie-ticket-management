#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<process.h>

class movie                     //Main Class                   
{  char mname[25];
   char lang[20];
   char certi[3];
   long int movieid;
   int duration;
   public:
    void in()                     //Member function to get movie details
    {   cout<<"Enter the movie name   :";
        gets(mname);
        cout<<"Enter the language     :";
        gets(lang);
        cout<<"Enter the certification:";
        gets(certi);
        cout<<"Enter the movie Id     :";
        cin>>movieid;
        cout<<"Enter the duration     :";
        cin>>duration;
     }
     void disp()           //Member function to diplay movie details
     {  cout<<"\n\tMovie ID     :";cout<<movieid;
        cout<<"\n\tMovie Name   :";puts(mname);
        cout<<"\tLanguage     :";puts(lang);
        cout<<"\tCertification:";puts(certi);
        cout<<"\tDuration     :";cout<<duration<<" min";
        cout<<"\n\n";   }
     long int retid()                   //Function to return movieid                  
    {  return movieid; }
 };


  void lineprint(char x='*')   //Function to display a line of                     
 {  cout<<"\n";                                                  character
    for(int i=1;i<=80;i++)
    cout<<x;
    cout<<"\n";
  }
    void display()                    //Function to display movie details           
   {  movie m;
       ifstream f;
       f.open("zineamovies.dat",ios::in|ios::binary);  
      while(f.read((char*)&m,sizeof(m)))
      {
         m.disp();
	   }
         f.close();
    }
 void disp2( int a)              //Function to display movie details  
 {  movie m2;	in bill
    ifstream f2;
    f2.open("zineamovies.dat",ios::in|ios::binary);
    while(f2.read((char*)&m2,sizeof(m2)))
   {
      if(m2.retid()==a)
        m2.disp();
    }
   f2.close();        }
 
 void func1()          //Function to admin side
 {
   clrscr();
   char us[25],pass[10];
   cout<<"________________________WELCOME TO ZINEA MOVIE          COMPLEX________________________";
   cout<<"\n\nLOGIN:";
   cout<<"\nUsername:";gets(us);
   l1:getch();
   cout<<"Password:";
   for(int x=0;x<8;x++)
  {   pass[x]=getch();
      cout<<"*";
    }
  pass[x]='\0';
  if (strcmpi(pass,"password")==0)
    {   cout<<"\nLogin Successful!!!";  }
else
    {  clrscr();
       cout<<"OOPS try again";
       goto l1;
    }
   int ch;
   l2:
   clrscr();
   cout<<"ZINEA MULTIPLEX \n Select your choice:";
   cout<<"\n\t1. Display the movies\n\t2. Add a new     movie\n\t3. Delete  a movie\n\t4. Exit";
   cin>>ch;
   switch(ch)
   {  case 1:
	    display();
	    break;
     case 2:
	    ofstream g;
	    char c;
	    movie n;
	    g.open("zineamovies.dat",ios::app|ios::binary);
	    do
	   {   n.in();
	        g.write((char*)&n,sizeof(n));
	        cout<<"Press y to give one more input";
	        cin>>c;
	    }   while (c=='y');
	    g.close();
	    break;
     case 3:
	    movie m1;
	    ifstream f2;
	    ofstream f3;
	    int found=0;
	    f2.open("zineamovies.dat",ios::in|ios::binary);
	    f3.open("temp.dat",ios::out|ios::binary);
	    cout<<"\nEnter the movie id to be deleted:";
	    int t_id;
	    cin>>t_id;
	    while(f2.read((char*)&m1,sizeof(m1)))
	    {
	     if(t_id!=m1.retid())
		 f3.write((char*)&m1,sizeof(m1));
	     else
		  found=1;
	    }
	    f2.close();
	    f3.close();
	    if(found==1)
	       cout<<"\nRecord has been successfully deleted";
	    else
	       cout<<"\nRecord not found";
	    remove("zineamovies.dat");
	    rename("temp.dat","zineamovies.dat");
	    break;
     case 4:
	   cout<<"\nBack to main menu";
	   return;
     default:
	   cout<<"\nInvalid choice";
   }
   cout<<"\nPress any key......";
   getch();
   goto l2;

 }

void bill1(int r,char row1[1],char col1[1],char cl,int idd)
 {	//Function to generate bill if no. of seats is 1
   clrscr();
   float amount;
   cout<<"\n------------------------------------------------------------------------------- ";
   cout<<"\n\t\t\t\t ZINEA MULTIPLEX  	";
   cout<<"\n-------------------------------------------------------------------------------";
   cout<<"\n\t\t\t\t  ---BILL---		";
   disp2(idd);
   cout<<"\n\tNumber Of Seats: ";
   cout<<"\n\tSeat Number: ";
   cout<<"\n\t\t"<<row1<<col1;
   cout<<"\n\tCost Per Ticket:";
   if(cl=='g')
  {
      amount=r*300;
      cout<<"Rs.300";
      cout<<"\n\tClass:Gold";
      cout<<"\n\tNet Bill Amount:";
     cout<<"Rs."<<amount<<"/-";
     cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
  }
  if(cl=='p')
  {
     amount=r*500;
     cout<<"Rs.500";
     cout<<"\n\tClass:Platinum";
     cout<<"\n\tNet Bill Amount:";
     cout<<"Rs."<<amount<<"/-";
     cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
  }
   getch();

 }

 void bill2(int r,char row1[1],char col1[1],char row2[1],char                                   col2[1],char  cl,int idd)    //Function to generate bill if no. of 
 {	seats is 2
    clrscr();
    float amount;
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\tZINEA MULTIPLEX ";
    cout<<"\n-------------------------------------------------------------------------------  ";
    cout<<"\n\t\t\t\t   ---BILL---";
    disp2(idd);
    cout<<"\n\tNumber Of Seats: "<<"2";
    cout<<"\n\tSeat Numbers: ";
    cout<<"\n\t\tSeat 1:"<<row1<<col1;
    cout<<"\n\t\tSeat 2:"<<row2<<col2;
    cout<<"\n\tCost Per Ticket:";
    if(cl=='g')
   {
      amount=r*300;
      cout<<"Rs.300";
      cout<<"\n\tNet Bill Amount:";
      cout<<"Rs."<<amount<<"/-";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }

   if(cl=='p')
   {
      amount=r*500;
      cout<<"Rs.500";
      cout<<"\n\tNet Bill Amount:";
      cout<<"Rs."<<amount<<"/-";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
   getch();
 }

 void bill3(int r,char row1[1],char col1[1],char row2[1],char col2[1],char  row3[1],char col3[1],char cl,int idd) 
 {               //Function to generate bill if no. of seat is 3
    clrscr();
    float amount;
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\tZINEA MULTIPLEX ";
    cout<<"\n------------------------------------------------------------------------------- ";
    cout<<"\n\t\t\t\t    ---BILL---";
    disp2(idd);
    cout<<"\n\tNumber Of Seats: "<<r;
    cout<<"\n\tSeat Numbers: ";
    cout<<"\n\t\tSeat 1:"<<row1<<col1;
    cout<<"\n\t\tSeat 2:"<<row2<<col2;
    cout<<"\n\t\tSeat 3:"<<row3<<col3;
    cout<<"\n\tCost Per Ticket:";
    If(cl=='g')
   {
       amount=r*300;
       cout<<"Rs.300";
       cout<<"\n\tNet Bill Amount:";
       cout<<"Rs."<<amount<<"/-";
       cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
   if(cl=='p')
   {
        amount=r*500;
       cout<<"Rs.500";
      cout<<"\n\tNet Bill Amount:";
      cout<<"Rs."<<amount<<"/-";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
   getch();
 }

 void bill4(int r,char row1[1],char col1[1],char row2[1],char col2[1],char row3[1],char col3[1],char row4[1],char col4[1],char cl,int idd)
 {                     //Function to generate bill if no. of seats is 4
   clrscr();
   float amount;
   cout<<"\n-------------------------------------------------------------------------------";
   cout<<"\n\t\t\t\tZINEA MULTIPLEX ";
   cout<<"\n-------------------------------------------------------------------------------"; 
   cout<<"\n\t\t\t\t    ---BILL---";
   disp2(idd);
   cout<<"\n\tNumber Of Seats: "<<r;
   cout<<"\n\tSeat Numbers:";
   cout<<"\n\t\tSeat 1:"<<row1<<col1;
   cout<<"\n\t\tSeat 2:"<<row2<<col2;
   cout<<"\n\t\tSeat 3:"<<row3<<col3;
   cout<<"\n\t\tSeat 4:"<<row4<<col4;
   cout<<"\n\tCost Per Ticket:";
   if(cl=='g')
   {
       amount=r*300;
       cout<<"Rs.300";
       cout<<"\n\tNet Bill Amount:";
       cout<<"Rs."<<amount<<"/-";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
   if(cl=='p')
   {
       amount=r*500;
       cout<<"Rs.500";
       cout<<"\n\tNet Bill Amount:";
       cout<<"Rs."<<amount<<"/-";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
     getch();   }

 void bill5(int r,char row1[1],char col1[1],char row2[1],char col2[1],char  row3[1],char col3[1],char row4[1],char col4[1],char row5[1],char col5[1],char cl,int idd)
 {                    //Function to generate bill if no. of seats is 5
    clrscr();
    float amount;
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\tZINEA MULTIPLEX ";
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t    ---BILL---";
    disp2(idd);
    cout<<"\n\tNumber Of Seats: "<<r;
    cout<<"\n\tSeat Numbers: ";
    cout<<"\n\t\tSeat 1:"<<row1<<col1;
    cout<<"\n\t\tSeat 2:"<<row2<<col2;
    cout<<"\n\t\tSeat 3:"<<row3<<col3;
    cout<<"\n\t\tSeat 4:"<<row4<<col4;
    cout<<"\n\t\tSeat 5:"<<row5<<col5;
    cout<<"\n\tCost Per Ticket:";
    if(cl=='g')
   {
        amount=r*300;
        cout<<"Rs.300";
       cout<<"\n\tNet Bill Amount:";
       cout<<"Rs."<<amount<<"/-";
       cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
   }
   if(cl=='p')
   {
       amount=r*500;
      cout<<"Rs.500";
      cout<<"\n\tNet Bill Amount:";
      cout<<"Rs."<<amount<<"/";
      cout<<"\n\t\t\t ENJOY THE CINEMATIC MOMENTS!!!";
    }
    getch();
  }
  void seat(int r,int id)        //Function for seating arrangements
{
    cout<<"\n\t\tA1 | A2 | A3 | A4 | A5 | A6 | A7 | A8 | A9 ";
    cout<<"\n\n\t\tB1 | B2 | B3 | B4 | B5 | B6 | B7 | B8 | B9";
    cout<<"\n\n\t\tC1 | C2 | C3 | C4 | C5 | C6 | C7 | C8 | C9";
    cout<<"\n\n\t\tD1 | D2 | D3 | D4 | D5 | D6 | D7 | D8 | D9";
    cout<<"\n\n\t\tE1 | E2 | E3 | E4 | E5 | E6 | E7 | E8 | E9";
    char row1[1] , col1[1] , row2[1] , col2[1] , row3[1] , col3[1] , row4[1] ,  col4[1] ,row5[1],col5[1];
   char cl;
   if(r==0)
   {   cout<<"\nSORRY!! No Are Seats Available!!!";
       getch();
      exit(1);
     }
   if(r==1)
   {   cout<<"\nSelect Row(A-E):->";
       gets(row1);
       strupr(row1);
       cout<<"\nSelect Column(1-9):->";
       gets(col1);
       cout<<"\nGold Class(g) or Platinum Class(p):";
       cin>>cl;
       bill1(r,row1,col1,cl,id);
    }
    if(r==2)
   {  cout<<"\nSelect Row(A-E) For Seat-1:->";
      gets(row1);
      strupr(row1);
      cout<<"\nSelect Column(1-9) For Seat-1:->";
      gets(col1);
      cout<<"\nSelect Row(A-E) For Seat-2:->";
      gets(row2);
      strupr(row2);
      cout<<"\nSelect Column(1-9) For Seat-2:->";
      gets(col2);
      cout<<"\nGold Class(g) or Platinum Class(p):";
      cin>>cl;
      bill2(r,row1,col1,row2,col2,cl,id);
   }
   if(r==3)
  {  cout<<"\nSelect Row(A-E) For Seat-1:->";
     gets(row1);
     strupr(row1);
     cout<<"\nSelect Column(1-9) For Seat-1:->";
     gets(col1);
     cout<<"\nSelect Row(A-E) For Seat-2:->";
     gets(row2);
     strupr(row2);
     cout<<"\nSelect Column(1-9) For Seat-2:->";
     gets(col2);
     cout<<"\nSelect Row(A-E) For Seat-3:->";
     gets(row3);
     strupr(row3);
     cout<<"\nSelect Column(1-9) For Seat-3:->";
     gets(col3);
     cout<<"\nGold Class(g) or Platinum Class(p):";
     cin>>cl;
     bill3(r,row1,col1,row2,col2,row3,col3,cl,id);
    }
   if(r==4)
  { cout<<"\nSelect Row(A-E) For Seat-1:->";
    gets(row1);
    strupr(row1);
    cout<<"\nSelect Column(1-9) For Seat-1:->";
    gets(col1);
    cout<<"\nSelect Row(A-E) For Seat-2:->";
    gets(row2);
    strupr(row2);
    cout<<"\nSelect Column(1-9) For Seat-2:->";
    gets(col2);
    cout<<"\nSelect Row(A-E) For Seat-3:->";
    gets(row3);
    strupr(row3);
    cout<<"\nSelect Column(1-9) For Seat-3:->";
    gets(col3);
    cout<<"\nSelect Row(A-E) For Seat-4:->";
    gets(row4);
    strupr(row4);
    cout<<"\nSelect Column(1-9) For Seat-4:->";
    gets(col4);
    cout<<"\nGold Class(g) or Platinum Class(p):";
    cin>>cl;
    bill4(r,row1,col1,row2,col2,row3,col3,row4,col4,cl,id);
    }
   if(r==5)
  { cout<<"\nSelect Row(A-E) For Seat-1:->";
    gets(row1);
    strupr(row1);
    cout<<"\nSelect Column(1-9) For Seat-1:->";
    gets(col1);
    cout<<"\nSelect Row(A-E) For Seat-2:->";
    gets(row2);
    strupr(row2);
    cout<<"\nSelect Column(1-9) For Seat-2:->";
    gets(col2);
    cout<<"Select Row(A-E) For Seat-3:->";
    gets(row3);
    strupr(row4);
    cout<<"\nSelect Column(1-9) For Seat-3:->";
    gets(col3);
    cout<<"\nSelect Row(A-E) For Seat-4:->";
    gets(row4);
    strupr(row4);
    cout<<"\nSelect Column(1-9) For Seat-4:->";
    gets(col4);
    cout<<"\nSelect Row(A-E) For Seat-5:->";
    gets(row5);
    strupr(row5);
    cout<<"\nSelect Column(1-9) For Seat-5:->";
    gets(col5);
    cout<<"\nGold Class(g) or Platinum Class(p):";
    cin>>cl;

bill5(r,row1,col1,row2,col2,row3,col3,row4,col4,row5,col5,cl,id);
    }
  }
 void func2()                      //Function to admin side
 {
    int a;
    l3:
    clrscr();
    lineprint('=');
    cout<<"                               ZINEA MULTIPLEX         ";
    lineprint('=');
    cout<<"\n\n\n\t ZINEA MULTIPLEX is the largest and the          most premium film exhibition company in india. Since 2019. “;
   char k;
   cout<<"\n\t\t 1.SELECT THE MOVIE  (PRESS Y)";
   cout<<"\n\t\t 2.BACK TO MAIN MENU (PRESS B)";
   cout<<"\n\n\t\t ENTER YOUR CHOICE:";
   cin>>k; 
   if(k=='Y'||k=='y')
   {
       clrscr();
       cout<<"\nMovies Available:"<<"\n";
       display();
       cout<<"\nEnter a movie ID you wish to watch:";
       int mid,se;
       cin>>mid;
       clrscr();
       cout<<"\n Enter number of seats (max 5):";
       cin>>se;
       seat(se,mid);
       goto l3;
    }
    else if(k=='B'||k=='b')
    {
        return;
    }
    else
    {
       cout<<"\n PRESS ANY VALID KEY..PLEASE";
       goto l3;
    }
 }




 void main()             //Main Program 
 {
     clrscr();
     int mi;
     m1:
     clrscr();
     lineprint();
     cout<<"                              ZINEA MULTIPLEX";
     lineprint();
     cout<<"\n\t\t\t          1.ADMIN \n\t\t\t          2.USER \n\t\t\t          3.EXIT";
     lineprint();
     gotoxy(30,50);
     cout<<"Enter your choice: ";
     gotoxy(40,50);
     cin>>mi;
     cout<<"\n\n\n\n\n\n\n\n\n\n";
     switch(mi)
     {   case 1:
	       func1();
	       break;
         case 2:
	       func2();
	       break;
	case 3:
	       exit(1);       }
     getch();
     goto m1;
}

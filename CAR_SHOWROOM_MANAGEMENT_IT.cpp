//	Header Files
#include<string.h> //strupr(), strcpy(),strcmpi()
#include<iostream>//cin and cout
#include<fstream>//file operations
#include<conio.h> //( getch() and getche() )
#include<time.h>  //( _strdate  )
#include<windows.h> // ( Sleep () )
using namespace std;
// Structure

struct dte
{ int dd,mm,yy;
};
dte d1,d2,d3;

//	Non-member Functions

void mainMenu();//gives options to interact with
void quit();//to terminate the program
void Introduction();//tells what the project does
int check();//which checks the whether a customer can service a car or not
int login();//to login into the program by checking the correct password


//	Class

class car
{ 
  char model[20],color[20],saledate[9],name[25],address[50];
  long price;
  int saleNo,services_count;
  public:
  car();
  void sell();
  void service();
  void modify();
  void del();
  void displayAll();
  void displayCustomer();
  void displayModel();
  void dailySale();
  void service_rpt();
  void updateserv(char* mname,car c1);
};


int main()   //MAIN
{ 
  int log;
  log=login();
  if(log==0)
  { 
    cout<<"\n\nIncorrect Password";
    cout<<"\n Program Terminated !";
    return 0;
  }
  else
  { 
    cout<<"\n\n\t\t\t\t----------------WELCOME--------------------\n\n";
    mainMenu();
  }
  return 0;
}

int login()//checks the validity of the password
{ char pass[25],ch;
  int i=0;
  cout<<"Enter Password : ";
  while(1) 
  { ch=getch();
    if(ch==13) break; //13 is the ascii code for enter/carriage return
    else 
    cout<<"#";
    pass[i++]=ch; //tanya
  }
  pass[i]='\0';
  if(strcmp(pass,"tanya")==0) return 1;
  else return 0;
}

void mainMenu()
{ int option;
  do
  {
    cout<<"\n\n\t\t\t\t   *********SPEEDY WHEELS************";
    cout<<"\n\n\t\t\t\t    -----------MAIN  MENU---------";
    cout<<"\n\n\t\t\t\t   Welcome to Speedy Wheels    ";
    cout<<"\n\n\t\t\t\t------------------------------";
    cout<<"\n\n\t\t\t\t   1. Sell a Car             ";
    cout<<"\n\n\t\t\t\t   2. Car Servicing           ";
    cout<<"\n\n\t\t\t\t   3. Service Report	";
    cout<<"\n\n\t\t\t\t   4. Modify Sale		";
    cout<<"\n\n\t\t\t\t   5. Delete Transaction     ";
    cout<<"\n\n\t\t\t\t   6. Display All            ";
    cout<<"\n\n\t\t\t\t   7. Customer-wise Enquiry  ";
    cout<<"\n\n\t\t\t\t   8. Model-wise Enquiry     ";
    cout<<"\n\n\t\t\t\t   9. Daily Sale Report      ";
    cout<<"\n\n\t\t\t\t  10. Introduction      ";
    cout<<"\n\n\t\t\t\t   0. Exit                ";
    cout<<"\n\n\t\t\t\t------------------------------";
    cout<<"\n\n\t\t\t\t    Enter choice [0-10] : ";

    cin>>option;

    car c1;

    switch (option)
    { case 1: c1.sell(); break;
      case 2: c1.service();break;
      case 3: c1.service_rpt();break;
      case 4: c1.modify(); break;
      case 5: c1.del(); break;
      case 6: c1.displayAll(); break;
      case 7: c1.displayCustomer(); break;
      case 8: c1.displayModel(); break;
      case 9: c1.dailySale(); break;
      case 10:Introduction();break;
      case 0: quit(); break;
      default : cout<<"\n\n\t\t\t\tYOU HAVE ENTERED A WRONG CHOICE !!! TRY AGAIN ....";
                cout<<"\n\n\t\t\t\tPress any key to continue...."; getch() ;break;
    }

  } while (option);
}

void quit()  //when 0 is entered as an option
{ cout<<"\n\n\t\t\t\t";
  char str[]="Thanks for using this software!!!!";
  for (int i=0; str[i]!='\0'; i++)
  { 
    cout<<str[i];
    Sleep(100); //0.1 sec delay in output  , Sleep from windows.h
                // is used to suspend the execution
                //of something for Sleep(n) n miliseconds  
  }
  cout<<"\n\n\t\t\t\t";
  char name[]="BY---TANYA CHHIKARA";
  for (int i=0; name[i]!='\0'; i++)
  { 
    cout<<name[i];
    Sleep(100);//0.1 sec delay in output 
  }
}

car :: car() //contructor of class car, copying empty strings in class members,and 0 in numeric data 
{ strcpy(model," "); 
  strcpy(color," ");
  strcpy(saledate," ");
  strcpy(name," ");
  strcpy(address," ");
  price=0;
  saleNo=0;
  services_count=5;//Number of services left (default :5 )
}

void car :: sell()
{ fstream file("cars.dat",ios::in|ios::app|ios::binary);

  if(!file)
  {
    cout<<"\n\n\t\t\t\tFile 'cars.dat' could not be opened !!";
    return ; //function is terminated and call goes back to the caller func()
  }

  char save;
  car c1;
   cout<<"\n\n\t\t\t\t         SELLING POINT      ";
   cout<<"\n\n\t\t\t\t--------------------------------";

  cin.ignore();
  cout<<"\n\n\t\t\t\tModel Name        : ";
  cin.getline(c1.model,20);
  strupr(c1.model);

  cout<<"\n\n\t\t\t\tColour            : ";
  cin.getline(c1.color,20);
  strupr(c1.color);

  _strdate(c1.saledate);   //stores the current system date 
  cout<<"\n\n\t\t\t\tDate [mm/dd/yy]   : "<<c1.saledate;

  cout<<"\n\n\t\t\t\tCustomer Name     : ";
  cin.getline(c1.name,25);
  strupr(c1.name);

  cout<<"\n\n\t\t\t\tAddress           : ";
  cin.getline(c1.address,50);
  strupr(c1.address);
  
  cout<<"\n\n\t\t\t\tSelling Price     : ";
  cin>>c1.price;

  cout << "\n\n\t\t\t\tWant to save the record (y/n)? : ";
  save=getche();
  
  car t;

  if (save == 'y' || save == 'Y')
  { file.seekg(0,ios::end);

    if (file.tellg() <= 0) //no record in file, therefore saleno=1
    c1.saleNo = 1;
    
    else// let say 2 records are present, get pointer is placed at the starting
    //of the last record and saleno is copied for the last record, say 2 in this case
    //now t.saleno++ means now saleno=3 and 3rd record in written in file
    { int size = sizeof(car);  
      file.seekg(-size,ios::end);
      file.read((char *)&t, sizeof(car));
      t.saleNo++;
      c1.saleNo = t.saleNo;
    }

    file.seekp(0,ios::end);
    file.write((char *)&c1,sizeof(c1));

    cout<<"\n\n\t\t\t\tRecord saved successfully!!!";
    cout<<"\n\n\t\t\t\tPress any key to continue....";
    getch();
  }

  file.close();
}

void car::modify()
{ fstream file ("cars.dat", ios::in|ios::out|ios::binary);

  if(!file)
  { cout<<"\n\n\t\t\t\tFile 'cars.dat' could not be opened !!";
    return;//goes to the mainmenu function
  }

 int salenum;
 cout<<"\n\n\t\t\t\t  Sale Modification";
 cout<<"\n\n\t\t\t\t=====================";

 cout<<"\n\n\t\t\t\tSale Number : "; 
 cin>>salenum;

  car c1;

  int found=0;

  file.seekg(0);

  while (file.read((char *)&c1, sizeof(c1)))
  { 

    if (c1.saleNo == salenum)
    { found = 1;
     cout<<"\n\n\t\t\t\tSale Number          : "<<c1.saleNo;
     cout<<"\n\n\t\t\t\tModel Name           : "<<c1.model;
     cout<<"\n\n\t\t\t\tColour of car        : "<<c1.color;
     cout<<"\n\n\t\t\t\tSale Date            : "<<c1.saledate;
     cout<<"\n\n\t\t\t\tSelling Price (Rs)   : "<<c1.price;
     cout<<"\n\n\t\t\t\tCustomer Name        : "<<c1.name;
     cout<<"\n\n\t\t\t\tAddress              : "<<c1.address;
    break;
    }
  }
  if (found == 0)
  { 
    cout<<"\n\n\t\t\t\tSorry, record not found.";
    file.close();
    return;
  }

  cout<<"\n\n\t\t\t\tPress ENTER for No Change .";

  char newmodel[20];

  cin.ignore();

  cout<<"\n\n\t\t\t\tModel Name           : ";
  cin.getline(newmodel,20);
  strupr(newmodel);

  if (strlen(newmodel)>0)
  strcpy(c1.model,newmodel);

  char newcolor[20];
  cout<<"\n\n\t\t\t\tPress ENTER for No Change .";
  cout<<"\n\n\t\t\t\tColour of car         : ";
  cin.getline(newcolor,20);
  strupr(newcolor);

  if (strlen(newcolor)>0)
  strcpy(c1.color,newcolor);

  char newdate[9];
  cout<<"\n\n\t\t\t\tPress ENTER for No Change .";
  cout<<"\n\n\t\t\t\tSale Date            : ";
  cin.getline(newdate,9);

  if (strlen(newdate)>0)
  strcpy(c1.saledate, newdate);

  char newname[25];
  cout<<"\n\n\t\t\t\tPress ENTER for No Change .";
  cout<<"\n\n\t\t\t\tCustomer Name        : ";
  cin.getline(newname,25);
  strupr(newname);

  if (strlen(newname)>0)
  strcpy(c1.name,newname);

  char newaddress[50];
  cout<<"\n\n\t\t\t\tPress ENTER for No Change .";
  cout<<"\n\n\t\t\t\tAddress              : ";
  cin.getline(newaddress,50);
  strupr(newaddress);

  if (strlen(newaddress)>0)
  strcpy(c1.address,newaddress);

  cout<<"\n\n\t\t\t\tEnter 0 for No Change.";

  long newprice;

  cout<<"\n\n\t\t\t\tSelling Price (Rs.)   : ";
  cin>>newprice;

  if (newprice>0)
  c1.price=newprice;

  char save;
  cout<<"\n\n\t\t\t\tWant to SAVE the changes (y/n) : ";
  save = getche(); //waits for the user to enter a character and displays the entered
                   // character on the screen 

  if (save == 'y' || save == 'Y')
  { int size = sizeof(c1);

    file.seekp(-size,ios::cur);
    file.write((char *)&c1, sizeof(c1));

    cout<<"\n\n\t\t\t\tSale Modified !!!";
    cout<<"\n\n\t\t\t\tPress any key to continue....";
    getch();
  }
  file.close();
}

void car::del()
{ ifstream ifile ("cars.dat", ios::binary);
  ofstream ofile ("temp.dat", ios::binary);

  if(!ifile || !ofile)
  { cout<<"File(s) could not be opened !!";
    return;
  }

  int salenum;

   cout<<"\n\n\t\t\t\t  Sale Deletion ";
   cout<<"\n\n\t\t\t\t=================";

  cout<<"\n\n\t\t\t\tSale No : "; cin>>salenum;

  car c1;

  int found=0;

  while (ifile.read((char *)&c1, sizeof(c1)))
  { if (c1.saleNo == salenum)
    found = 1;
    else
    ofile.write((char *)&c1,sizeof(c1));
  }

  ifile.close();
  ofile.close();

  if (found == 0)
  { 
    cout<<"\n\n\t\t\t\tSorry, record not found.";
    cout << "\n\n\t\t\t\tPress any key to continue......";
  }
  else
  {
    remove("cars.dat");
    rename("temp.dat","cars.dat");
    cout<<"\n\n\t\t\t\tRecord for Sale No. " << salenum << " deleted.";
    cout << "\n\n\t\t\t\tPress any key to continue......";
  }
   getch();
}

void car::displayAll()
{ ifstream ifile ("cars.dat", ios::binary|ios::in);

  if(!ifile)
  { 
    cout<<"\n\n\t\t\t\tFile 'cars.dat' could not be opened !!";
    return;
  }

  car c1;

  while (ifile.read((char *)&c1, sizeof(c1)))
  { 

 cout<<"\n\n\t\t\t\t----------------RECORD------------------";
 cout<<"\n\n\t\t\t\tSale Number          : "<<c1.saleNo;
 cout<<"\n\n\t\t\t\tModel Name           : "<<c1.model;
 cout<<"\n\n\t\t\t\tColour of car        : "<<c1.color;
 cout<<"\n\n\t\t\t\tSale Date            : "<<c1.saledate;
 cout<<"\n\n\t\t\t\tSelling Price (Rs)   : "<<c1.price;
 cout<<"\n\n\t\t\t\tCustomer Name        : "<<c1.name;
 cout<<"\n\n\t\t\t\tAddress              : "<<c1.address;
 cout<<"\n\n\t\t\t\tService left         : "<<c1.services_count;
 cout<<"\n\n\t\t\t\t----------------RECORD------------------";
 cout << "\n\n\t\t\t\tPress any key to see next record......";

    getch();
  }
  ifile.close();
}

void car::displayCustomer()
{ ifstream ifile ("cars.dat", ios::binary);

  if(!ifile)
  { cout<<"File 'cars.dat' could not be opened !!"; 
    return;
  }

  char cname[25];
  cin.ignore();
  cout<<"\n\n\t\t\t\tCustomer-wise display";
  cout<<"\n\n\t\t\t\t=====================";

  cout<<"\n\n\t\t\t\tCustomer Name : ";
  cin.getline(cname,25);

  car c1;

  int found=0;

  while (ifile.read((char *)&c1, sizeof(c1)))
  { 
    if (strcmpi(c1.name, cname) == 0)
    { found = 1;

     cout<<"\n\n\t\t\t\t----------------RECORD------------------";
     cout<<"\n\n\t\t\t\tSale Number          : "<<c1.saleNo;
     cout<<"\n\n\t\t\t\tModel Name           : "<<c1.model;
     cout<<"\n\n\t\t\t\tColour of car        : "<<c1.color;
     cout<<"\n\n\t\t\t\tSale Date            : "<<c1.saledate;
     cout<<"\n\n\t\t\t\tSelling Price (Rs)   : "<<c1.price;
     cout<<"\n\n\t\t\t\tCustomer Name        : "<<c1.name;
     cout<<"\n\n\t\t\t\tAddress              : "<<c1.address;
     cout<<"\n\n\t\t\t\tService left         : "<<c1.services_count;
     cout<<"\n\n\t\t\t\t----------------RECORD------------------";

   
    cout << "\n\n\t\t\t\tPress any key to continue......";
    getch();
    }
  }
  if (found == 0)
  {
    cout<<"\n\n\t\t\t\tSorry, record not found.";
    cout<<"\n\n\t\t\t\tPress any key to continue......";
    getch();
  }

  ifile.close();
}

void car::displayModel()
{ ifstream ifile ("cars.dat", ios::binary|ios::in);

  if(!ifile)
  { cout<<"File 'cars.dat' could not be opened !!";
    return;
  }

  char mname[20];
  cin.ignore();
  cout<<"\n\n\t\t\t\tCar Model-wise display";
  cout<<"\n\n\t\t\t\t======================";

  cout<<"\n\n\t\t\t\tEnter Model Name : ";
  cin.getline(mname,20);

  car c1;

  int found=0;

  while (ifile.read((char *)&c1, sizeof(c1)))
  { 

    if (strcmpi(c1.model, mname) == 0)
    { found = 1;

     cout<<"\n\n\t\t\t\t----------------RECORD------------------";
     cout<<"\n\n\t\t\t\tSale Number          : "<<c1.saleNo;
     cout<<"\n\n\t\t\t\tModel Name           : "<<c1.model;
     cout<<"\n\n\t\t\t\tColour of car        : "<<c1.color;
     cout<<"\n\n\t\t\t\tSale Date            : "<<c1.saledate;
     cout<<"\n\n\t\t\t\tSelling Price (Rs)   : "<<c1.price;
     cout<<"\n\n\t\t\t\tCustomer Name        : "<<c1.name;
     cout<<"\n\n\t\t\t\tAddress              : "<<c1.address;
     cout<<"\n\n\t\t\t\tService left         : "<<c1.services_count;
     cout<<"\n\n\t\t\t\t----------------RECORD------------------";

      cout << "\n\n\t\t\t\tPres any key to continue......";

      getch();
    }
  }
  if (found == 0)
  { 
    cout<<"\n\n\t\t\t\tSorry, record not found.";
    cout << "\n\n\t\t\t\tPress any key to continue......";
    getch();
  }

  ifile.close();
}

void car :: dailySale()
{ ifstream ifile ("cars.dat",ios::binary|ios::in);

  if (!ifile)
  { 
    cout<<"\n\n\t\t\t\tSorry!! cars.dat could not be opened.";
    return;
  }

  char saleDt[9];
  _strdate(saleDt);//current system date  

  cout<<"\n\n\t\t\t\t                Daily Sale Record";
  cout<<"\n\n\t\t\t\t                [As On " << saleDt << "]";
  cout<<"\n\n\t\t\t\t===============================================";
  cout<<"\n\n\t\t\t\tSNo.\t Model\tCustomer\t\t\tSelling Price";
  cout<<"\n\n\t\t\t\t===============================================";

  car c1;

  long totalSales = 0;
  int sno=0;

  while (ifile.read((char *)&c1, sizeof(c1)))
  {
    if (strcmp(c1.saledate, saleDt)==0)
    { 
    cout<<"\n\n\t\t\t\t"<<++sno;
    cout<<"\t"<<c1.model;
    cout<<"\t"<<c1.name;
    cout<<"\t\t\t"<<c1.price;

    totalSales += c1.price;
    }
  }
  cout<<"\n\n\t\t\t\tTotal Sales :" << totalSales;
  cout << "\n\n\t\t\t\tPress any key to continue......";
  ifile.close();
  getch();
}

void car::service()//according to the model name
{ fstream file ("cars.dat", ios::in|ios::out|ios::binary);
  if(!file)
  { cout<<"\n\n\t\t\t\tFile 'cars.dat' could not be opened !!"; 
    return;
  }

  char ch='n';
  cout<<"\n\n\t\t\t\t        Service Info        ";
  cout<<"\n\n\t\t\t\t=============================";
  cout<<"\n\n\t\t\t\tEnter Model name : ";
  char mname[20];
  cin.ignore();
  cin.getline(mname,20);
  car c1;

  int found=0;

  while (file.read((char *)&c1, sizeof(c1)))
{
    if (strcmpi(c1.model, mname) == 0)
    { found = 1;

    cout<<"\n\n\t\t\t\t----------------RECORD------------------";
    cout<<"\n\n\t\t\t\tSale Number          : "<<c1.saleNo;
    cout<<"\n\n\t\t\t\tModel Name           : "<<c1.model;
    cout<<"\n\n\t\t\t\tColour of car        : "<<c1.color;
    cout<<"\n\n\t\t\t\tSale Date            : "<<c1.saledate;
    cout<<"\n\n\t\t\t\tSelling Price (Rs.)   : "<<c1.price;
    cout<<"\n\n\t\t\t\tCustomer Name        : "<<c1.name;
    cout<<"\n\n\t\t\t\tAddress              : "<<c1.address;
    cout<<"\n\n\t\t\t\tService left         : "<<c1.services_count;
    cout<<"\n\n\t\t\t\t----------------RECORD------------------";
    }
}
  if (found == 0)
  { 
    cout<<"\n\n\t\t\t\tSorry, record not found.";
    cout <<"\n\n\t\t\t\tPress any key to continue......";
    getch();
  }
  
  if(found==1)
  { int n;
    cout<<"\n\n\t\t\t\tDo you wish to service this car(y/n): ";
    cin>>ch;
    if (ch=='y' || ch=='Y')
    { 
      fstream file ("cars.dat", ios::in|ios::out|ios::binary);

      while (file.read((char *)&c1, sizeof(c1)))
      if (strcmpi(c1.model, mname) == 0)
      { cout<<"\n\n\t\t\t\tModel Name     : "<<c1.model;
	    cout<<"\n\n\t\t\t\t"<<c1.services_count<< "  services are pending.";
  
	if ((c1.services_count <=5)&&(c1.services_count>0))
	{ cout<<"\n\n\t\t\t\tEnter Sale date (dd<space> mm<space> yy<space> )   : ";
	  cin>>d1.dd>>d1.mm>>d1.yy;
	  cout<<"\n\n\t\t\t\tEnter Current date (dd<space> mm<space> yy<space> )   : ";
	  cin>>d2.dd>>d2.mm>>d2.yy;

	  n=check();

	if (n==0)
	{ cout<<"\n\n\t\t\t\tLast Servicing Date was "<<d3.dd<<"-"<<d3.mm<<"-"<<d3.yy;
	  cout<<"\n\n\t\t\t\tServicing date is expired....";
	  cout<<"\n\n\t\t\t\tPress any key to continue...."; getch(); return;
	}
	  if (n==1)
	{ 
    cout<<"\n\n\t\t\t\tLast Servicing Date is " <<d3.dd<<"-"<<d3.mm<<"-"<<d3.yy;
	  c1.services_count--;
	  cout<<"\n\n\t\t\t\tNow "<<c1.services_count<<" services are left...";
    cout<<"\n\n\t\t\t\tService Updated...Press any key to continue....";
    updateserv(mname,c1);
    getch();
	}
	}
	else //in case 0 services left and n is a junk value 
  {
	cout<<"\n\n\t\t\t\tAll the services offered with Model "<<c1.model<<" are over!!!";
  cout<<"\n\n\t\t\t\tPress any key to continue....";getch();
  }
      }
    }
  }
}

void car :: service_rpt() //till current date all sales are displayed
{ ifstream ifile ("cars.dat",ios::binary);

  if (!ifile)
  { 
    cout<<"\n\n\t\t\t\tSorry!! cars.dat could not be opened.";
    return;
  }

  char saleDt[9];
  _strdate(saleDt);
  cout<<"\n\n\t\t\t\t                Service Report";
  cout<<"\n\n\t\t\t\t                [As On " << saleDt << "]";
  cout<<"\n\n\t\t\t\t===============================================";
  cout<<"\n\n\t\t\t\tSNo.\tModel\tCustomer\tServices left";
  cout<<"\n\n\t\t\t\t===============================================";

  car c1;
  int sno=0;

  while (ifile.read((char *)&c1, sizeof(c1)))
  { 
    { 
    cout<<"\n\n\t\t\t\t"<<++sno;
    cout<<"\t"<<c1.model;
    cout<<"\t"<<c1.name;
    cout<<"\t"<<c1.services_count;
    }
  }
  ifile.close();
  cout << "\n\n\t\t\t\tPress any key to continue......";
  getch();
}
void Introduction()
{ 
  cout<<"\n\t\t\t\tWelcome to Car Showroom Project";
  cout << "\n\t\t\t\tThis project is used to handle the cars in a showroom and for keeping ";
  cout << "\n\t\t\t\tdetailed information of customers and cars in computerized manner.";
  cout << "\n\t\t\t\tIt also handles the following: ";
  cout << "\n\t\t\t\t-Using first option you can add information of sold car.";
  cout << "\n\t\t\t\t-In second option you can update service details.";
  cout << "\n\t\t\t\t-Third option provides you facility to see the current servicing report. ";
  cout << "\n\t\t\t\t-In fourth option you can modify records.";
  cout << "\n\t\t\t\t-Fifth option helps you to delete particular transaction.";
  cout << "\n\t\t\t\t-In sixth option you can see all the records.";
  cout << "\n\t\t\t\t-Seventh option enables you to get customer's details.";
  cout << "\n\t\t\t\t-In eighth option you can get car model details.";
  cout << "\n\t\t\t\t-Ninth option enables you to see daily sales report.";
  cout << "\n\t\t\t\t-Tenth option will help you in using this software.";
  cout << "\n\t\t\t\tNote-:To Exit from the program press 0 (Zero) !!! ";
  cout<<"\n\n\t\t\t\tPress any key to continue...";
  getch();
}

int check()
{ int n;   //d3 contains 5 years later date after saledate
  d3.dd=d1.dd;
  d3.mm=d1.mm;
  d3.yy=(d1.yy+5);

  if (d3.yy<d2.yy)
  n=0;

  else if (d3.yy>d2.yy)
  n=1;

  else if (d3.yy==d2.yy)
  { if (d3.mm<d2.mm)
    n=0;

    else if (d3.mm>d2.mm)
    n=1;

    else if (d3.mm==d2.mm)
    { if (d3.dd<d2.dd)
      n=0;
      else if (d3.dd>d2.dd)
      n=1;
      else if (d3.dd==d2.dd)
      n=1;
    }
  }
  return n;
}
void car::updateserv(char* mname,car c1)
{
  car c2;
  fstream ifile("car.dat",ios::in|ios::out|ios::binary);
  fstream file("cars.dat",ios::in|ios::out|ios::binary);

  while (file.read((char *)&c2, sizeof(c2)))
  { if (strcmpi(c2.model, mname) == 0)
    ifile.write((char *)&c1, sizeof(c1));
    else
    ifile.write((char *)&c2, sizeof(c2));
  }
  cout<<"\n\n\t\t\tTHE UPDATED RECORD IS:";
  cout<<"\n\n\t\t\t\t----------------RECORD------------------";
  cout<<"\n\n\t\t\t\tSale Number          : "<<c1.saleNo;
  cout<<"\n\n\t\t\t\tModel Name           : "<<c1.model;
  cout<<"\n\n\t\t\t\tColour of car        : "<<c1.color;
  cout<<"\n\n\t\t\t\tSale Date            : "<<c1.saledate;
  cout<<"\n\n\t\t\t\tSelling Price (Rs.)   : "<<c1.price;
  cout<<"\n\n\t\t\t\tCustomer Name        : "<<c1.name;
  cout<<"\n\n\t\t\t\tAddress              : "<<c1.address;
  cout<<"\n\n\t\t\t\tService left         : "<<c1.services_count;
  cout<<"\n\n\t\t\t\t----------------RECORD------------------";
  
  file.close();
  ifile.close();

  remove("cars.dat");
  rename("car.dat","cars.dat");
};

#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float disc;
        string pname;

    public:
        void menu();
        void admin();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

void shopping :: menu()
{
    m:
    int choice ;
    string username;
    string password ;

    cout<<"\n\n";
    cout<<"______________________________________\n";
    cout<<"                                      \n";
    cout<<"              MAIN MENU               \n";
    cout<<"                                      \n";
    cout<<"______________________________________\n";
    cout<<"                                      \n";
    cout<<"|   1) Admin       \n";
    cout<<"|                  \n";
    cout<<"|   2) Buyer       \n";
    cout<<"|                  \n";
    cout<<"|   3) Exit        \n";
    cout<<"|                  \n\n";
    cout<<"Please select from above options: ";
    cin>>choice;


    if (!cin)
    {
        cin.clear(); // for clearing the error state  
        cin.ignore(); // for removing the erroneous characters
        cout <<"\n\n" << "Invalid choice! Please select from the given options.";
        goto m;
    }

    switch (choice)
    {
    case 1:
        cout<<"\nPlease login to the menu.  \n\n";
        cout<<"Enter username: ";
        cin>>username;
        cout<<"\nEnter password: ";
        cin>>password ;
        if(username =="saroj14" && password =="3380")
        {
            admin();
        }
        else 
            cout<<"\n\nInvalid username/password.";
        break;

    case 2 :
        {
            buyer();
        }

    case 3 :
        {
            exit(0) ; //succesful termination of program
        }
    
    default:
        {
            cout <<"\n\n" << "Invalid choice! Please select from the given options.";
        }
        
    }

    goto m;
}

void shopping :: admin()
{
    m:
    int choice ;
    cout<<"\n\n";
    cout<<"______________________________________\n";
    cout<<"                                      \n";
    cout<<"              ADMIN MENU              \n";
    cout<<"                                      \n";
    cout<<"______________________________________\n";
    cout<<"                                      \n";
    cout<<"                                      \n";
    cout<<"|___1) Add the product________________|\n";
    cout<<"|                                     \n";
    cout<<"|                                     \n";
    cout<<"|___2) Modify the product_____________|\n";
    cout<<"|                                     \n";
    cout<<"|                                     \n";
    cout<<"|___3) Delete the product_____________|\n";
    cout<<"|                                     \n";
    cout<<"|                                     \n";
    cout<<"|___4) Back to main menu______________|\n";
    cout<<"|                                     \n";
    cout<<"|                                     \n";

    cout<<"Please enter your choice: ";
    cin>>choice;

    if (!cin)
    {
        cin.clear(); // for clearing the error state  
        cin.ignore(); // for removing the erroneous characters
        cout <<"\n\n" << "Invalid choice! Please select from the given options.";
        goto m;
    }

    switch (choice)
    {
    case 1:
        {
            add();
            break;
        }

    case 2:
        {
            edit();
            break;
        }
    
    case 3:
        {
            rem();
            break;
        }

    case 4:
        {
            menu();
            break;
        }
    default:
        cout <<"\n\n" << "Invalid choice! Please select from the given options.";
    }
    goto m;
}

void shopping:: buyer()
{
    m:
    int choice;
    cout<<"______________________________________\n";
    cout<<"                                      \n";
    cout<<"              BUYER MENU              \n";
    cout<<"                                      \n";
    cout<<"______________________________________\n";
    cout<<"                                      \n";
    cout<<"                                      \n";
    cout<<"|___1) Buy new product________________|\n";
    cout<<"|                                     \n";
    cout<<"|                                     \n";
    cout<<"|___2) Go back________________________|\n";
    cout<<"|                                     \n";
    cout<<"|                                     \n";
    cout<<"Enter Your Choice: ";
    cin>>choice;

    if (!cin)
    {
        cin.clear(); // for clearing the error state  
        cin.ignore(); // for removing the erroneous characters
        cout <<"\n\n" << "Invalid choice! Please select from the given options.";
        goto m;
    }

    switch(choice)
    {
        case 1:
            receipt();
            break;

        case 2:
            menu();
            //break; // edited

        default:
            cout <<"\n\n" << "Invalid choice! Please select from the given options.";

    goto m;
}

}

void shopping:: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n";
    cout<<"______________________________________\n";
    cout<<"                                      \n";
    cout<<"           Add new product            \n";
    cout<<"______________________________________\n";

    cout<<"\nEnter product code: ";
    cin>>pcode;
    if (!cin)
    {
        cin.clear(); // for clearing the error state  
        cin.ignore(); // for removing the erroneous characters
        cout <<"\n\n" << "EROOR! Please enter positive integer values only.";
        goto m;
    }
    cout<<"\nEnter name of the product: ";
    cin>>pname;
    cout<<"\nEnter price of the product: ";
    cin>>price;
    cout<<"\nEnter discount on product: ";
    cin>>disc;
    cout<<"\n\n";

    data.open("database.txt", ios::in); //reading mode

    if(!data) // if data is not there
    {
        data.open("database.txt", ios::app|ios::out); //append and writing mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n" ; //append kiya
        data.close();
    }

    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==pcode) token++ ;
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token==1) 
        {   
            goto m;
        } 

        else
        {
            data.open("database.txt", ios::app|ios::out); //append and writing mode
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n" ; //append kiya
            data.close();
        }

        cout<<"Record inserted! \n";
    }

}

void shopping :: edit()
{
    m:
    fstream data, data1;
    int pkey, token=0 , c ;
    float p, d ;
    string n ;

    cout<<"\n\n";
    cout<<"______________________________________\n";
    cout<<"                                      \n";
    cout<<"          Modify the product          \n";
    cout<<"______________________________________\n";

    cout<<"\nEnter the product code : ";
    cin>>pkey;

    if (!cin)
    {
        cin.clear(); // for clearing the error state  
        cin.ignore(); // for removing the erroneous characters
        cout <<"\n\n" << "Invalid choice! Please enter correct product code.";
        goto m;
    }

    cout<<"\n\n";

    data.open("database.txt", ios::in); //reading mode

    if(!data)
    {
        cout<<"File doesn't exist! \n" ;
    }

    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data>>pcode>>pname>>price>>disc;

        while (!data.eof())
        {
            if(pkey == pcode)
            {   
                cout<<"Enter new product code: ";
                cin>>c;
                if (!cin)
                {
                    cin.clear(); // for clearing the error state  
                    cin.ignore(); // for removing the erroneous characters
                    cout <<"\n\n" << "Invalid choice! Please enter correct product code.";
                    goto m;
                }
                cout<<"\nEnter name of the product: ";
                cin>>n;
                cout<<"\nEnter price of the product: ";
                cin>>p;
                cout<<"\nEnter discount on product: ";
                cin>>d;
                cout<<"\n\n";
                data1<<" "<<c <<" "<<n <<" "<<p <<" " << d <<"\n" ;
                cout<<"Record edited! \n" ;
                token++ ;
            }
            
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n" ;
            }
            data>>pcode>>pname>>price>>disc;
        }
        
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"Record not found! \n";
        }
    }
}

void shopping :: rem()
{
    m:
    fstream data, data1;
    int pkey, token=0 ;

    cout<<"\n\n";
    cout<<"______________________________________\n";
    cout<<"                                      \n";
    cout<<"          Remove the product          \n";
    cout<<"______________________________________\n";
    cout<<"\nEnter the product code: ";
    cin>>pkey;
    cout<<"\n\n";

    data.open("database.txt" , ios::in);
    if(!data)
    {
        cout<<"File doesn't exixt! \n";
    }

    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data>>pcode>>pname>>price>>disc;

        while (!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n  Product deleted successfully" ;
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n" ;
            }

            data>>pcode>>pname>>price>>disc;
        }

        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"Record not found! \n";
        }
    }
}

void shopping :: list()
{
    fstream data ;
    data.open("database.txt", ios::in); // reading mode
    cout<<"\n_____________________________________________________\n";
    cout<<"Product Code\t\tName\t\tPrice\n";
    cout<<"_____________________________________________________\n";
    data>>pcode>>pname>>price>>disc;

    while (!data.eof())
    {
        cout<<pcode<<"\t\t\t"<<pname<<"\t\t"<<price<<"\n"; 
        data>>pcode>>pname>>price>>disc;
    }
    data.close();
}

void shopping :: receipt()
{
    m:
    fstream data;

    int arrc[100];
    int arrq[100];
    int choice;
    int c=0 ;
    float amount =0;
    float disc =0;
    float total= 0 ;

    cout<<"\n\n                 | ITEMS AVAILABLE | ";
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"Sorry! empty database. \n";
    }

    else
    {
        data.close();

        list();
        cout<<"___________________________________________________\n";
        cout<<"                                                   \n";
        cout<<"               Please place the order              \n";
        cout<<"                                                   \n";
        cout<<"___________________________________________________\n";
        cout<<"                                                   \n";

        do 
        {
            cout<<"\n\n";
            cout<<"Enter product code :";
            cin>>arrc[c]; // c is our counter
            cout<<"Enter the product quantity: " ;
            cin>>arrq[c] ;
            cout<<"\n";

            for (int i =0; i< c; i++) // for checking that entered code is not duplicate 
            {
                if(arrc[c] == arrc[i])
                {
                        cout<<"Duplicate product code. Please try again! \n" ;
                        goto m;
                }
            }
            c +=1 ;
            cout<<"\nDo you want to buy another product? if yes, then press 1, else press 0 : \n\n";
            cin>>choice ;
        } 
        while (choice == 1);

        cout<<"\n\n______________________________________________RECIEPT______________________________________________\n\n";
        cout<<"\nProduct code\tProduct Name\tQuantity\tPrice\tAmount\tAmount with discount\n" ;

        for(int i =0 ; i<c ;i++)
        {
            data.open("database.txt", ios::in);  //reading mode
            data>>pcode>>pname>>price>>disc;

            while (!data.eof())  // while not data end of
            {
                if(pcode == arrc[i])
                {
                    amount = price*arrq[i];
                    disc = amount - (amount*disc/100) ;
                    total = total + disc ;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t"<<disc<<"\n"; // edited
                }
                data>>pcode>>pname>>price>>disc;
            }
            data.close(); // edited
        }
    }

        cout<<"\n\n___________________________________________________________________________________________________\n";
        cout<<"                                                                                                   \n";
        cout<<"                                          Total Amount :" <<total<<"\n";
        cout<<"                                                                                                   \n";
        cout<<"___________________________________________________________________________________________________\n";
        cout<<"                                                                                                   \n";
}


int main()
{
    shopping s;
    s.menu();

    return 0 ;
}
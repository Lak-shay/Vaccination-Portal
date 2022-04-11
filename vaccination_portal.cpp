#include <iostream>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h> 
#include <limits>
#include <vector>
using namespace std;

void main_menu();

class persons
{

protected:
    string name;
    int age;
    string gender;
    int vacDate;
    string center;
    
public:
    void setname(string name)
    {
        this->name = name;
    }

    void setage(int age)
    {
        this->age = age;
    }

    void setgender(string gender)
    {
        this->gender = gender;
    }

    void set_vdate(int vacdate)
    {
        this->vacDate = vacdate;
    }

    void set_center(string center)
    {
        this->center = center;
    }
};

class payment : public persons
{
private:
    int cardid;
    string mobno;
    string emailid;

public:
    int Id;

    void setcid(int cardid)
    {
        this->cardid = cardid;
    }

    void setmobno(string mobno)
    {
        this->mobno = mobno;
    }

    void setemail(string email)
    {
        this->emailid = email;
    }
   
    void display()
    {
        cout << "\tName : " << name << endl;
        cout << "\tAge : " << age << endl;
        cout << "\tGender : " << gender << endl;
        cout << "\tReference ID : : " << Id << endl;
        cout << "\tVaccination date : " << vacDate << endl;
        cout << "\tVaccination center : " << center << endl;
    }

};

void pay(payment* p)
{
    system("CLS");
    int cardid;
    string mobno;
    string emailid;
    string card_name;
    int refId;

    cout << "\tEnter the cardholder's name : ";
    cin >> card_name;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "\tEnter your mobile number : ";
    cin >> mobno;
    if (mobno.size() != 10)
    {
        cout << "\tPlease enter a valid mobile number ";
        cin >> mobno;
    }
    p->setmobno(mobno);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "\tEnter your card number : ";
    cin >> cardid;
    p->setcid(cardid);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "\tEnter expiry month and year:(mm/yyyy)\t";
	int expiryMonth, expiryYear;
	cin >> expiryMonth;

    while((expiryMonth<=0)||(expiryMonth>12))
    {
        cout << "\tPlease enter the correct month:\t";
        cin >> expiryMonth;
    }

	cout << "\t/";
	cin >> expiryYear;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    char pass[4];
    cout << "\tEnter your cvv : ";
    int i = 0;
    while(i < 3)
    {
        pass[i] = getch();
        cout << "*";
        i++;
    }
    pass[i] = '\0';
}

payment reg()
{
    payment p;
    cout << "\tEnter the details for the person" << endl << endl;

    cout << "\tName : ";
    string input_name;
    cin >> input_name;
    p.setname(input_name);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << endl;

    cout << "\tAge : ";
    int input_age;
    cin >> input_age;
    p.setage(input_age);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << endl;

    cout << "\tGender : ";
    string input_gender;
    cin >> input_gender;
    p.setgender(input_gender);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << endl;
    
    srand (time(NULL));
	int refId = rand() % 400000 + 4000000;
	if (refId < 0)
    {
	    refId = (refId * (-1));
    }
    p.Id = refId;

    char chpay;
    cout << "\tDo you wish to pay the vaccine payment prior to going to the center online (y/n)?\t";
    cin >> chpay;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if(chpay == 'y')
    {
        pay(&p);
        
    }
    else
    {
        cout << "\tPayment will be taken at the vaccination center." << endl;
        
    }
    return p;
}

int main()
{
    vector< pair <string, int> > v;
    v.push_back(make_pair("Aiims", 29));
    v.push_back(make_pair("Safdarjung", 52));
    v.push_back(make_pair("Max", 10));
    v.push_back(make_pair("Fortis", 15));
    v.push_back(make_pair("Aashlok", 73));
    v.push_back(make_pair("Appolo", 22));
    v.push_back(make_pair("Batra", 5));
    v.push_back(make_pair("LHMC", 45));

    int n;
    cout << "\tHow many people do you want to register? You can only register upto 4 people.\t";
    cin >> n;
    payment* store = new payment[n];
    int index = 0;
    char ch;
    do                          // exit controlled loop.
    {
        system("CLS");
        main_menu();
        int choice;
        cin >> choice;
        system("CLS");

        if(choice == 1)                                             // Registration
        {
            cout << "\tYou can register for upto a maximum of 4 people including yourself.\n";

            if(index > n-1)
            {
                cout << "\tYou have already registered " << n << " user(s)." << endl;
                break;
            }

            store[index] = reg();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            bool flag;                                          // Declared bool flag to run the do while loop below.
            do
            {
                int vacdate;
                cout << "\n\tChoose from the given available dates for vaccination:\t15 16 17 18\t";
                cin >> vacdate;
                store[index].set_vdate(vacdate);

                flag = 0;
                cout << "\tThe vaccination centres are displayed as follows" << endl << endl;

                for (int i = 0; i < v.size(); i++)
                {
                    cout << "\t'" << v[i].first << "' : " << "No. of doses available : " << v[i].second << endl << endl;
                }

                string center;
                cout << "\tEnter your required center:\t";
                cin >> center;
                cout << endl;

                for (int i = 0; i < v.size(); i++)
                {
                    if (v[i].first == center)
                    {
                        flag = 1;
                        v[i].second = v[i].second - 1;
                        store[index].set_center(center);
                    }
                }

                if(flag == 0)
                {
                    cout << "\tKindly select the center from the list correctly" << endl;
                }

            } while(flag == 0);
            index++;
        }

        else if(choice == 2)                                    // Registered users info display
        {
            for(int i = 0; i<n; i++)
            {
                store[i].display();
                cout << endl << endl;
            }
        }

        else if(choice == 3)                                    // vaccination centres display
        {
            cout << "\tThe respective centres for vaccination and their remaining doses are listed below:" << endl << endl;
            for(int i = 0; i<v.size(); i++)
            {
                cout << "\t" << v[i].first << " : " << v[i].second << endl;
            }
            cout << endl << endl;
        }

        else if(choice == 4)
        {
            string line;
            ifstream guidelines("covid_guidelines.txt");        
            if(guidelines.is_open() == 1)
            {
                while(getline(guidelines, line))                // Reading every line
                {
                    cout << "\t" << line << endl;
                }
                guidelines.close();
            }
            else
            {
                cout << "Unable to open file" << endl;
            }
            cout << endl;
        }

        else if(choice == 5)                                    // Exit
        {
            break;
        }

        else                                                    // Wrong choice
        {
            cout << "Invalid choice" << endl;
        }

        cout << "\tDo you want to choose another option from the main menu? (y/n)\t";
        cin >> ch;

    } while (ch == 'y');

    getch();                                                    // To hold the application window
    return 0;
}

void main_menu()
{
    cout << "\n\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t VACCINATION PORTAL";
    cout << "\n\t\t\t ----------------------------------";
    cout << "\n\t\t\t\t Welcome User!";
    cout << "\n\n\t\t\t\t <1> New Registeration";
    cout << "\n\t\t\t\t <2> View information";
    cout << "\n\t\t\t\t <3> View Vaccination Centres";
    cout << "\n\t\t\t\t <4> Guidelines for Covid";
    cout << "\n\t\t\t\t <5> Exit \n\n";
    cout << "\t\t\t\tEnter Your Choice :"
         << "\t";
}
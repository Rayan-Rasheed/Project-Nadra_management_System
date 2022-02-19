#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <sstream>
#include <windows.h>
using namespace std;
// -------------------------prototypes start---------------------------------------
void show_header();
void header();
void sign_up();
void load();
void login();
void store();
string parse(string row, int column);
void tempArray_into_Array();
void header();
void clearScreen();
string who();
void wrong_password();
void forget_password();
void add_user();
int mainmenu();
int admin_menu();
int applicantMenu();
void empty();
void add_record();
void tokenshow();
void token_no();
void generate_cnic();
void generate_carona_certificate();
void sahat_card_application();
void sorted_citizen_data();
int large_age();
void NsortedArrays();

void generate_bill();
void search_record();
void statitics_city();
// prototype applicant function----
void header1();
void track_app();
void show_carona_certificate();
void health_card();
void complaints();
void complaints_admin();
void faqs();
void mails();
void del_acoount();
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

//---------------------prototype end-------------------------------------------------------------------------

//***********************************************************************************************************
//--------------------datastructure start---------------------------------------------------------
const int max_record = 100;
// predefine data which will be use in forgot password function**********************
string birth_year = "2000";
string pet_name = "james";
//----end data of forgot password***************************************************

string usernameA[max_record];
string passwordA[max_record];
string roleA[max_record];
string tokenNoA[max_record];
string nameA[max_record];
string lastnameA[max_record];
string genderA[max_record];
string cityA[max_record];
string cnicA[max_record];
string fatherA[max_record];
string motherA[max_record];
string provinceA[max_record];
string t_adressA[max_record];
string p_adressA[max_record];
string brotherA[max_record];
string sisterA[max_record];
string vaccineA[max_record];
string land_type[max_record];
string locationA[max_record];
int vehicalA[max_record];
int doseA[max_record];
int ageA[max_record];
int sorted_age[max_record];
int yearA[max_record];
int monthA[max_record];
int dateA[max_record];
int installmentA[max_record];
int taxA[max_record];
int amountA[max_record];
int house_amountA[max_record];
int assetA[max_record];
int worthA[max_record];
int return_loanA[max_record];
double tokenNumberA[max_record];
double worth_totalA[max_record];
string s_cnicA[max_record];
string s_lastnameA[max_record];
string s_cityA[max_record];
int s_dateA[max_record];
int s_monthA[max_record];
int s_yearA[max_record];
string s_nameA[max_record];
double s_worthTotalA[max_record];
string vstatusA[max_record];
int newageA[max_record];
string complaintsA[max_record];
string emailA[max_record];
string recomendation[max_record];
int incomeA[max_record];
//--------------------datastructure end---------------------------
bool flag = false;
string temp_data[max_record];
string cnic_for_track;
int count_p = 0;
int user_count = 1;
int complaint_count = 0;
string reply_complaint;
int reply_count = 0;
int sahat_idx = 0;
bool sahat_flag = false;
char accept_sahat;
string track_user;
string full_name;
char headerA[6][240];

main()
{
    sign_up();
    load();

    header();

    usernameA[0] = "Rayan";
    passwordA[0] = "rayan@123";
    roleA[0] = "admin";

    int option = mainmenu();
    while (option < 3) // applying whie loop for three mainmenus
    {
        if (option == 1)
        {
            int forget = 0;
            system("cls");

            header();
            while (true)
            {

                string role = who();
                // we are here logging is as admin by providing correct username and password
                if (role != "admin" && role != "staff" && role != "applicant")
                {
                    forget++;
                    wrong_password();
                    if (forget >= 3)

                    { // forget password function
                        forget_password();
                    }
                }
                if ((role == "admin") || (role == "staff"))
                {
                    int option = 0;
                    // if password and username is correct it will be log in into database
                    system("cls");
                    cout << "Login Successfully!" << endl;
                    while (option != 13)
                    {
                        option = admin_menu();
                        if (option == 1)
                        {
                            // adding record of acitizen by providing their information
                            add_record();
                            // store record into file
                            login();
                            count_p = count_p + 1;
                            user_count++; // this is login count
                        }
                        else if (option == 2)
                        {
                            // generating token number against application of citizen
                            if (count_p > 0)
                            {
                                tokenshow();
                            }
                            else
                            {
                                empty();
                            }
                        }
                        else if (option == 3)
                        {
                            // generating cnic
                            if (count_p > 0)
                            {
                                generate_cnic();
                            }
                            else
                            {
                                empty();
                            }
                        }
                        else if (option == 4)
                        {
                            // generating caroan certificatee
                            if (count_p > 0)
                            {
                                generate_carona_certificate();
                            }
                            else
                            {
                                empty();
                            }
                        }
                        else if (option == 5)
                        {
                            if (count_p > 0)
                            {
                                sahat_card_application();
                            }
                            else
                            {
                                empty();
                            }
                        }
                        else if (option == 6)
                        {

                            if (count_p > 0)
                            {
                                // sorting of citizen in database according to their respective ages
                                sorted_citizen_data();
                            }
                            else
                            {
                                empty();
                            }
                        }
                        else if (option == 7)
                        {
                            if (count_p > 0)
                            {
                                // generating bill against the application of citizens
                                generate_bill();
                            }
                            else
                            {

                                empty();
                            }
                        }
                        else if (option == 8)
                        {

                            if (count_p > 0)
                            {
                                // search record of citizen
                                search_record();
                            }
                            else
                            {

                                empty();
                            }
                        }
                        else if (option == 9)
                        {
                            if (count_p > 0)
                            {
                                // showing graph of age in a entered city
                                statitics_city();
                            }
                            else
                            {
                                empty();
                            }
                        }
                        else if (option == 10)
                        {
                            system("cls");
                            if (role == "admin")
                            {
                                add_user();
                            }
                            else
                            {
                                cout << "Permission denied!You have loged in  as a staff " << endl;
                                clearScreen();
                            }
                        }
                        else if (option == 11)
                        {
                            complaints_admin();
                        }
                        else if (option == 12)
                        {
                            system("cls");
                            if (role == "admin")
                            {
                                del_acoount();
                            }
                            else
                            {
                                cout << "Permission denied!You have loged in  as a staff" << endl;
                                clearScreen();
                            }
                        }
                        else if (option > 13)
                        {
                            cout << "In valid option..";
                            getch();
                        }
                        system("cls");
                    }
                }
                if (role == "applicant")
                {
                    int option1 = 0;
                    system("cls");
                    header1();

                    while (option1 != 7)
                    {
                        int option1 = applicantMenu();

                        if (option1 == 1)
                        {
                            system("cls");
                            header1();
                            track_app();
                        }
                        else if (option1 == 2)
                        {
                            show_carona_certificate();
                        }
                        else if (option1 == 3)
                        {
                            health_card();
                        }
                        else if (option1 == 4)
                        {
                            complaints();
                        }
                        else if (option1 == 5)
                        {
                            mails();
                        }
                        else if (option1 == 6)
                        {
                            faqs();
                        }
                        else if (option1 == 7)
                        {
                            system("cls");
                            break;
                        }
                        else if (option1 > 7)
                        {
                            cout << "\nInvalid option";
                            continue;
                        }
                    }
                }
            }
        }
    }
}
void show_header()
{
    for (int i = 0; i < 6; i++)
    {

        for (int j = 0; j < 141; j++)
        {

            cout << headerA[i][j];
        }

        cout << endl;
    }
}
void header()
{
    // load header and show from file
    string s;
    fstream f;
    f.open("header.txt", ios::in);
    for (int i = 0; i < 6; i++)
    {
        getline(f, s);
        for (int j = 0; j < 141; j++)
        {
            headerA[i][j] = s[j];
        }
    }
    f.close();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

    show_header();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    cout << "\n\n\n";
}
// void header()
// {
//     // the header function

//     cout << "*  ****************************************************************************** *" << endl;
//     cout << "*  ****************************************************************************** *" << endl;
//     cout << "*   ____________WELCOME TO NATIONAL MANAGEMENT DATABASE SYSTEM___________________ *" << endl;
//     cout << "*  ****************************************************************************** *" << endl;
//     cout << "*  ****************************************************************************** *" << endl
//          << endl;
// }
void clearScreen()
{
    // clear the screen stop until any key is press
    cout << "Press any key to continue..." << endl;
    getch();
    system("cls");
}
string who()
{
    // login function
    string username;
    string password;
    string out_role;
    cout << "Login to Database>>" << endl;
    cout << "You can login as an ADMIN/EMPLOYE or Applicant\n\n";
    cout << usernameA[user_count];
    cout << roleA[user_count];
    cout << "ENTER USERNAME:";
    cin >> username;
    track_user = username;
    cout << endl;
    int length = 0;

    cout << "ENTER PASSWORD:";
    cin >> password;

    cnic_for_track = password;
    cout << "\n";
    for (int i = 0; i < max_record; i++)
    {
        if (username == usernameA[i] && password == passwordA[i])
        {
            out_role = roleA[i];
        }
    }
    return out_role;
}
void wrong_password()
{
    cout << "Wrong !Username or password" << endl;
    cout << "Press any key to enter again....";
    getch();
    system("cls");
}
void forget_password()
{
    // function that will show option if admin entered wrong passowrd for 3 times or more
    char f;
    cout << "You have entered wrong password more than 3 times!" << endl;
    cout << "To forget password press 'y' or press any other key to try again..";
    cin >> f;
    if (f == 'y')
    {
        string b, p, user;
        cout << "Enter user_name:";

        cin >> user;
        cout << "Enter your birth year:";
        cin >> b;
        cout << "Enter your pet name:";
        cin >> p;
        if (b == birth_year && p == pet_name && user == usernameA[0])
        {
            system("cls");
            string newpassword, confirm;
            cout << "Enter your new password:";
            cin >> newpassword;
            cout << "Confirm your new password:";
            cin >> confirm;
            if (newpassword == confirm)
            {
                passwordA[0] = newpassword;
            }
        }
    }
}
void add_user()
{
    // add user from admin menu function
    header();
    string user, pass, role;
    cout << "Enter username:";
    cin >> user;
    int length = 0;
    while (length < 8)
    {
        cout << "Enter password:";
        cin >> pass;
        length = pass.length();
        if (length < 8)
        {
            cout << "Password must be more than 8 character long with special character.." << endl;
        }
    }

    cout << "Enter role:";
    cin >> role;
    usernameA[user_count] = user;
    passwordA[user_count] = pass;
    roleA[user_count] = role;
    login(); // store password and username hat admin add into file;
    user_count++;
}
int mainmenu()
{
    // main menu
    int opt;
    cout << "Main Menu>> " << endl;
    cout << "1.Login to the Database......" << endl;
    cout << "2.Discription of this database system.." << endl;
    cout << "3.Exit....." << endl;
    cout << endl;
    cout << "Your option......";
    cin >> opt;
    return opt;
}
int admin_menu()
{
    // login as admin menu
    int opt1;
    header();
    cout << "MainMenu>>" << endl;

    cout << "1.Add record of applicant.." << endl;
    cout << "2.Generate token Number for application.." << endl;
    cout << "3.National identity card...." << endl;
    cout << "4.Generate Carona  Certificate.." << endl;
    cout << "5.Health card Aplication.." << endl;
    cout << "6.Citizen data with age and city… " << endl;
    cout << "7.Generate bill.." << endl;
    cout << "8.Search record of citizen.." << endl;
    cout << "9.Age Statitics of citizen with cities " << endl;
    cout << "10.Add users or staff login ......." << endl;
    cout << "11.Complaint section..." << endl;
    cout << "12.Delete accounts.." << endl;
    cout << "13.Logout.." << endl;
    cout << "Your option.....";
    cin >> opt1;
    return opt1;
}
int applicantMenu()
{
    // header();
    int opt1;
    // applicant menu function
    cout << "Main menu for applicant>>" << endl;
    cout << "1.Track your application" << endl;
    cout << "2.Download caroana Certificate" << endl;
    cout << "3.Apply for Health Card " << endl;
    cout << "4.Submit your Complaints" << endl;
    cout << "5.Mails Notification" << endl;
    cout << "6.Frequently Asked question (FAQs) " << endl;
    cout << "7.Logout " << endl;
    cout << " Press your option... ";
    cin >> opt1;
    return opt1;
}
void empty()
{
    system("cls");
    header();
    cout << "No record has been made yet in this database..." << endl;
    clearScreen();
}

void add_record()
{ // adding record of a citizen by providing his personal information

    system("cls");
    header();

    cout << "Enter applicant first name:";
    cin >> nameA[count_p];
    cout << "Enter applicant last name:";
    cin >> lastnameA[count_p];
    cout << "Enter gender:";
    cin >> genderA[count_p];
    getline(cin, t_adressA[count_p]);
    cout << "Enter father name:";
    getline(cin, fatherA[count_p]);

    while (!((yearA[count_p] > 0) && (yearA[count_p] < 2022)))
    {
        cout << "Enter birth year:";
        cin >> yearA[count_p];
        if ((yearA[count_p] < 0) && (yearA[count_p] > 2022))
        {
            cout << "Invalid input.." << endl;
            cout << "Again ";
        }
    }

    while (!((monthA[count_p] > 0) && (monthA[count_p] < 13)))
    {
        cout << "Enter birth month:";
        cin >> monthA[count_p];
    }

    while (!((dateA[count_p] > 0) && (dateA[count_p] <= 31)))
    {
        cout << "Enter birth date:";
        cin >> dateA[count_p];
    }

    int length = 0;
    while (length != 13)
    {

        cout << "Enter CNIC:";
        cin >> cnicA[count_p];
        length = cnicA[count_p].length();
        if (length != 13)
        {
            cout << "Cnic must be 13 digit with no '-' " << endl;
            cout << "Again ";
        }
    }

    cout << "Enter province:";
    cin >> provinceA[count_p];
    cout << "Enter city:";
    cin >> cityA[count_p];
    getline(cin, t_adressA[count_p]);
    cout << "Enter present address:";
    getline(cin, t_adressA[count_p]);
    cout << "Enter permanent address:";
    getline(cin, p_adressA[count_p]);
    int inc = 0.;
    while (inc < 1)
    {
        cout << "Enter income:";
        cin >> inc;
    }
    incomeA[count_p] = inc;
    // income used for recomendation of sehat saholat

    cout << "Enter vaccine name:";

    cin >> vaccineA[count_p];
    int dos = -1;
    while (dos < 0 && dos < 3)
    {
        cout << "Enter vaccine dose:";
        cin >> dos;
    }
    doseA[count_p] = dos;
    // counting age
    ageA[count_p] = 2022 - yearA[count_p];
    newageA[count_p] = ageA[count_p];
    if (ageA[count_p < 18])
    {
        cout << "This applicant is not eligible for Cnic card." << endl;
    }
    // now passing information to userlogin as applicant from admin add record so that user can see his application info

    usernameA[user_count] = nameA[count_p];
    passwordA[user_count] = cnicA[count_p];
    roleA[user_count] = "applicant";
    store();

    clearScreen();
}
void tokenshow()
{
    // generating token number automatically in computrized manner
    system("cls");
    header();
    cout << "The citizen data is successfully entered." << endl;
    cout << "To generate token number for the application of citizen press any key..." << endl;
    getch();
    int a = 0;

    int token;
    for (int i = 1123; i < max_record + 1123; i++)
    {
        tokenNumberA[a] = i;
        a++;
    }
    int i = 0;

    while (i < count_p)
    {
        cout << nameA[i] << " " << lastnameA[i] << "\t"
             << " token number is: " << tokenNumberA[i] << endl;
        i++;
    }
    clearScreen();
}
void token_no()
{
    //-------showing oken number
    cout << "Cnic against their token number are:" << endl;
    for (int i = 0; i < count_p; i++)
    {
        if (newageA[i] < 18)
        {
            cout << i + 1 << ":" << tokenNumberA[i] << "{} Only eligilble for smart card (under 18)}" << endl;
        }
        else
        {
            cout << i + 1 << ":" << tokenNumberA[i] << endl;
        }
    }
}
void generate_cnic()
{
    // this function will print carona vaccination card of citizen by entering his cnic it will automatically search his all data
    system("cls");
    if (tokenNumberA[0] != 0)
    {
        token_no();
        cout << "Press any option...";
        int opt;
        cin >> opt;

        cout << "**ISLAMIC REPUBLIC OF PAKISTAN***" << endl;
        cout << "_____________________________________" << endl;
        cout << "Name:" << nameA[opt - 1] << endl;
        cout << "_____________________________________" << endl;
        cout << "Father Name:" << fatherA[opt - 1] << endl;
        cout << "_____________________________________" << endl;
        cout << "Gender:" << genderA[opt - 1] << " | "
             << "Country:"
             << "Pakistan" << endl;
        cout << "_____________________________________" << endl;
        cout << "Identity no.:" << cnicA[opt - 1] << endl;
        cout << "______________________________________" << endl;
        cout << "Date of birth:" << dateA[opt - 1] << "-" << monthA[opt - 1] << "-" << yearA[opt - 1] << endl;
        cout << "______________________________________" << endl;
        cout << "Present address:" << t_adressA[opt - 1] << endl;
        cout << "______________________________________" << endl;
        cout << "Permanent address:" << p_adressA[opt - 1] << endl;
    }
    else
    {
        cout << "There is no token number against any application of cnic is generated yet!" << endl;
    }
    clearScreen();
}
void generate_carona_certificate()
{
    system("cls");
    header();
    cout << "Enter Cnic:";
    string c;
    cin >> c;
    int index;
    for (int i = 0; i < max_record; i++)
    {
        if (cnicA[i] == c)
        {
            index = i;
        }
    }
    system("cls");
    // generating frc of first citizen
    header();
    cout << "MINISTRY OF NATIONAL HEALTH SERVICES REGULAIONS AND CORDINATION" << endl;
    cout << "IMMUNIZATION CERTIFICATE FOR COVID-19" << endl;
    cout << "Name:" << nameA[index] << endl;
    cout << "Date of birth:" << dateA[index] << "-" << monthA[index] << "-" << yearA[index] << endl;
    cout << "Identity no.:" << cnicA[index] << endl;
    cout << "Has been administrated COVID-19 following vaccination:" << endl;
    cout << "Vaccine name:" << vaccineA[index] << endl;
    cout << "Dose:" << doseA[index] << endl;
    if (doseA[index] == 1)
    {
        vstatusA[index] = "Partially_Vaccinated!";
        cout << vstatusA[index] << endl;
    }
    else
    {
        vstatusA[index] = "Full_vacinated";
        cout << vstatusA[index] << endl;
    }
    clearScreen();
}
void sahat_card_application()
{
    system("cls");

    header();
    // entering land record of citizen

    cout << "Main Menu>>Sehat card issuance>" << endl;
    if (sahat_flag == true)
    {
        cout << "Application for sahat card issuance are following below:" << endl;
        cout << "Name:" << full_name << endl;

        cout << "Cnic:" << cnicA[sahat_idx] << endl;
        cout << "Father name:" << fatherA[sahat_idx] << endl;
        cout << "Press y to accept appplication for issuance of card..";
        cin >> accept_sahat;
        if (accept_sahat == 'y')
        {
            cout << "you have sucessfully accepted application for sahat card issuance for Cnic " << cnicA[sahat_idx] << endl;
        }
    }
    clearScreen();
}
void sorted_citizen_data()
{
    // citizen with sorted age in a sorted manner all the cnic ,name,age will correspondingly displayed in sorted manner

    system("cls");
    NsortedArrays();
    header();
    cout << "Citizen data with sorted age and assets>" << endl;

    cout << "Name"
         << "\t"
         << "\t"
         << "Cnic"
         << "\t"
         << "\t"
         << "City"
         << "\t"
         << "DOB"
         << "\t"
         << "\t"
         << "Age"
         << endl;

    int i = 0;
    while (i < count_p)
    {
        cout << s_nameA[i]
             << " " << s_lastnameA[i]
             << "\t"
             << s_cnicA[i]
             << "\t"
             << s_cityA[i]
             << "\t"
             << s_dateA[i]
             << "-"
             << s_monthA[i]
             << "-"
             << s_yearA[i]
             << "\t"
             << sorted_age[i]

             << endl;
        i++;
    }
    clearScreen();
}
void generate_bill()
{
    // this function will generaate bill
    system("cls");
    header();
    cout << "Main Menu> Payment details>\n\n";
    if (tokenNumberA[0] != 0)
    {
        cout << "Following token number has been generated" << endl;
        token_no();
        cout << "Press any option to generate bill" << endl;
        int opt;
        cin >> opt;

        cout << "Cnic Urgent fee: 2500" << endl;
        cout << "CNIC Regular fee:1000" << endl;
        cout << "Covid-19 immunization certificate fee:100" << endl;
        cout << "What service do applicant want……";
        string service;
        cin >> service;
        cout << "Name:" << nameA[opt - 1] << endl;
        cout << "Cnic:" << cnicA[opt - 2] << endl;
        if (service == "urgent")
        {

            cout << "Total fee: 2600" << endl;
        }
        else
        {
            cout << "Total fee: 1100" << endl;
        }

        clearScreen();
    }
    else
    {

        cout << "Applicant token number against their application is found yet to generate bill" << endl;
    }
    clearScreen();
}
int large_age()
{
    // this function will return largest index for sortting
    int lidx = 0;

    int large = ageA[0];
    for (int i = 0; i <= count_p; i++)
    {
        if (large < ageA[i])
        {
            large = ageA[i];
            lidx = i;
        }
    }
    return lidx;
}
void search_record()
{
    // search record in ddatabase by providing cnic you will get all detail about entered cnic like adress,date of birth

    system("cls");
    header();
    string search;
    cout << "Enter the CNIC of person you want to search in database: ";
    cin >> search;
    bool ind = false;
    for (int i = 0; i < count_p; i++)
    {

        if (search == cnicA[i])
        {
            ind = true;
            cout << "Full Name:" << nameA[i] << " " << lastnameA[i] << endl;
            cout << "Father Name:" << fatherA[i] << endl;
            cout << "Date of Birth:" << dateA[i] << "-" << monthA[i] << "-"
                 << yearA[i] << endl;
            cout << "Nationality:"
                 << "Pakistan" << endl;
            cout << "Present Adress:" << t_adressA[i] << endl;
            cout << "Permanent Adress:" << p_adressA[i] << endl;
            cout << "vacination status:" << vstatusA[i] << endl;
        }
    }
    if (ind == false)
    {
        cout << "No record found in the database of this Cnic number!" << endl;
    }
    clearScreen();
}
void NsortedArrays()
{
    // this function will put sorting index in all neww arrays
    if (flag == false)
    {

        for (int i = 0; i <= count_p; i++)
        {
            // by using concept of sorting with parallel array
            int idx = large_age();
            s_nameA[i] = nameA[idx];
            s_lastnameA[i] = lastnameA[idx];
            sorted_age[i] = ageA[idx];
            s_cnicA[i] = cnicA[idx];
            s_cityA[i] = cityA[idx];
            s_dateA[i] = dateA[idx];
            s_monthA[i] = monthA[idx];
            s_yearA[i] = yearA[idx];
            s_worthTotalA[i] = worth_totalA[idx];

            ageA[idx] = -1;
            cout << s_nameA[0];
            cout << s_nameA[1];
        }
        flag = true;
    }
}
void statitics_city()
{

    // implementing function of showing statitcs graph w.r.t age of required citizen
    header();
    int detect_18 = 0;
    int detect_40 = 0;
    int detect_60 = 0;
    int detect_80 = 0;
    int detect_100 = 0;
    string city;
    system("cls");
    cout << "Enter city you want to see age statitics :";
    cin >> city;
    // cout << ageA[0];
    for (int i = 0; i < count_p; i++)
    {
        if ((newageA[i] <= 18) && (cityA[i] == city))
        {
            detect_18++;
        }
        if ((newageA[i] > 20 && newageA[i] <= 40) && (cityA[i] == city))
        {
            detect_40++;
        }
        if ((newageA[i] > 40 && newageA[i] <= 60) && (cityA[i] == city))
        {
            detect_60++;
        }
        if ((newageA[i] > 60 && newageA[i] <= 80) && (cityA[i] == city))
        {
            detect_80++;
        }
        if ((newageA[i] > 80) && (cityA[i] == city))
        {
            detect_100++;
        }
    }
    cout << "\n\n";
    for (int i = 0; i < 1; i++)
    {
        cout << "__Age__   ";
        for (int j = 0; j < 1; j++)
        {
            cout << "% population";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 1; i++)
    {
        cout << "--<18_year   ";
        for (int j = 0; j < detect_18 * 4; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < 1; i++)
    {
        cout << "20-40_year   ";
        for (int j = 0; j < detect_40 * 4; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < 1; i++)
    {
        cout << "40-60_year   ";
        for (int j = 0; j < detect_60 * 4; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < 1; i++)
    {
        cout << "60-80_year   ";
        for (int j = 0; j < detect_80 * 4; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < 1; i++)
    {
        cout << "->100_year   ";
        for (int j = 0; j < detect_100 * 4; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    clearScreen();
}
void complaints_admin()
{
    system("cls");
    header1();
    if (complaint_count > 0)
    {
        cout << "From:-" << endl;
        cout << "E-mail:" << emailA[complaint_count - 1] << endl;
        cout << "Complaint:-" << endl;
        cout << "\t" << complaintsA[complaint_count - 1] << endl;
        cout << "Press y to reply applicant..";
        char reply;
        cin >> reply;
        if (reply == 'y')
        {

            cout << "Reply to comlaint:-" << endl;
            getline(cin, reply_complaint);
            getline(cin, reply_complaint);
            reply_count++;
        }
    }
    else
    {
        cout << "No comlain to show" << endl;
    }

    clearScreen();
}
void del_acoount()
{
    header();
    string r_user, r_role;
    cout << "Enter the Username you want to remove:";
    cin >> r_user;
    cout << "ENter role:";
    cin >> r_role;
    for (int i = 1; i <= user_count; i++)
    {
        if (r_user == usernameA[i] && r_role == roleA[i])
        {
            usernameA[i] = usernameA[i + 1];
            passwordA[i] = passwordA[i + 1];
            roleA[i] = roleA[i + 1];
            // user_count--;
        }
    }
    login();
}
//__________end fuction implemention of admin____________________________
//-----------start applicant function implementation--------------------
void header1()
{
    cout << "*  ****************************************************************************** *" << endl;
    cout << "*   ______________________WELCOME TO NADRA CITIZEN PORTAL________________________ *" << endl;
    cout << "*  ****************************************************************************** *" << endl;
}
void track_app()
{
    int index;
    if (tokenNumberA[0] == 0)
    {
        cout << "Your application of identity  " << cnic_for_track << "  is in process. "
             << "You will shortly receive you tracking id. " << endl;
    }
    if (tokenNumberA[0] > 0)
    {
        for (int i = 0; i < max_record; i++)
        {
            if (cnicA[i] == cnic_for_track)
            {
                index = i;
            }
        }
        cout << "Your application process with tracking id   " << tokenNumberA[index] << "   of cnic no  " << cnicA[index] << "   has been completed.You will receive your id card soon." << endl;
    }
    clearScreen();
}
void show_carona_certificate()
{
    system("cls");
    header1();
    int index;
    bool flag = false;
    for (int i = 0; i < max_record; i++)
    {
        if (cnicA[i] == cnic_for_track)
        {
            index = i;

            flag = true;
        }
    }
    if (flag == true)
    {
        system("cls");
        // view carona certificate to user
        header();
        cout << "MINISTRY OF NATIONAL HEALTH SERVICES REGULAIONS AND CORDINATION" << endl;
        cout << "IMMUNIZATION CERTIFICATE FOR COVID-19" << endl;
        cout << "Name:" << nameA[index] << endl;
        cout << "Date of birth:" << dateA[index] << "-" << monthA[index] << "-" << yearA[index] << endl;
        cout << "Identity no.:" << cnicA[index] << endl;
        cout << "Has been administrated COVID-19 following vaccination:" << endl;
        cout << "Vaccine name:" << vaccineA[index] << endl;
        cout << "Dose:" << doseA[index] << endl;
        if (doseA[index] == 1)
        {
            vstatusA[index] = "Partially_Vaccinated!";
            cout << vstatusA[index] << endl;
        }
        else
        {
            vstatusA[index] = "Full_vacinated";
            cout << vstatusA[index] << endl;
        }
    }
    else
    {
        cout << "No record found yet.";
    }

    clearScreen();
}
void health_card()
{
    system("cls");
    header1();
    double m_income, loan;

    cout << "Apply for NADRA Health Card>" << endl;

    cout << "Enter your monthly income:";
    cin >> m_income;
    if (m_income > 35000)
    {
        cout << "You are not eligible for  free government Health card!";
    }
    else if (m_income < 35000)
    {
        cout << "You are eligible for NADRA Health Card\n"
             << endl;

        // the output will be

        string cnic_health;
        string f_name;
        cout << "Enter your full name:";
        getline(cin, full_name);
        getline(cin, full_name);

        cout << "Enter your Cnic number:";
        cin >> cnic_health;
        // take cnic and name and give father name
        for (int i = 0; i < max_record; i++)
        {
            if (cnic_health != cnicA[i])
            {

                sahat_flag = true;
                sahat_idx = i;
                cout << "Father name:" << fatherA[i] << endl
                     << endl;
                cout << "Your request for issuance of sehat card has been sent.." << endl;
                cout << "Press any key to continue...";
                getch();
                break;
            }
            else
            {
                cout << "Your record does not found in data base.Please register your queries in complaint section." << endl;
                cout << "Press any key to continue...";
                getch();
                break;
            }
        }
    }
    clearScreen();
}
void faqs()
{
    system("cls");
    header1();
    cout << "FAQs>>" << endl;
    cout << "Q. Do you apply for loan through this portal?" << endl;
    cout << "Ans. No, you can apply for loan through this portal." << endl;
    cout << "Q. How you can receive your id card for that you have applied?" << endl;
    cout << "Ans. Pakistan Post is responsible for sending your idcard to you." << endl;
    cout << "Q. Can you check the status of your application?" << endl;
    cout << "Ans:You can see or track your application and see status of your application." << endl;
    clearScreen();
}
void complaints()
{

    system("cls");
    header1();
    if (reply_count > 0)
    {
        cout << "From:Nadra@gov.pk" << endl;
        cout << "\t" << reply_complaint << endl;
    }
    else if (reply_count == 0)
    {
        cout << "Enter your e-mail adress:";
        cin >> emailA[complaint_count];
        cout << "Enter your complaint here:";
        getline(cin, complaintsA[complaint_count]);
        getline(cin, complaintsA[complaint_count]);

        complaint_count++;
    }
    clearScreen();
}
void mails()
{
    system("cls");
    header1();
    for (int i = 0; i < max_record; i++)
    {
        if (passwordA[i] == cnic_for_track && track_user == usernameA[i])
        {
            if (ageA[i] < 18)
            {
                cout << "From:Nadra@gov.pk" << endl;
                cout << "You are under 18.You can now apply for Nadra jevenille card by visiting your city Nadra branch" << endl;
            }

            if (incomeA[i] < 35000)
            {
                cout << "From:Nadra@gov.pk" << endl;
                cout << "Dear Citizen!As per say your income is less than 35000 you can apply for Health sahulat Card" << endl;
            }
            break;
        }
    }
    clearScreen();
}
void load()
{
    //***********************laoding recorda from file***************************************************

    fstream file;
    string line = " ";
    int count = 0;
    file.open("nadra_data.txt", ios::in);
    while (!file.eof())
    {

        getline(file, line);

        temp_data[0] = parse(line, 1);
        temp_data[1] = parse(line, 2);
        temp_data[2] = parse(line, 3);
        temp_data[3] = parse(line, 4);
        temp_data[4] = parse(line, 5);
        temp_data[5] = parse(line, 6);
        temp_data[6] = parse(line, 7);
        temp_data[7] = parse(line, 8);
        temp_data[8] = parse(line, 9);
        temp_data[9] = parse(line, 10);
        temp_data[10] = parse(line, 11);
        temp_data[11] = parse(line, 12);
        temp_data[12] = parse(line, 13);
        temp_data[13] = parse(line, 14);

        // uploaading temporary arr1ay data into orignal array
        tempArray_into_Array();
        count++;
    }
}
void tempArray_into_Array()
{
    nameA[count_p] = temp_data[0];
    lastnameA[count_p] = temp_data[1];
    genderA[count_p] = temp_data[2];
    fatherA[count_p] = temp_data[3];

    yearA[count_p] = stoi(temp_data[4]);
    monthA[count_p] = stoi(temp_data[5]);
    dateA[count_p] = stoi(temp_data[6]);
    cnicA[count_p] = temp_data[7];
    provinceA[count_p] = temp_data[8];
    cityA[count_p] = temp_data[9];
    t_adressA[count_p] = temp_data[10];
    p_adressA[count_p] = temp_data[11];
    vaccineA[count_p] = temp_data[12];
    doseA[count_p] = stoi(temp_data[13]);
    // age calculation
    ageA[count_p] = 2022 - yearA[count_p];
    newageA[count_p] = ageA[count_p];

    count_p++;
}
string parse(string row, int column)
{

    int commansCount = 1;
    string item;
    int index = 0;
    while (true)
    {
        char ch;
        ch = row[index];
        if (ch == '\0')
            return item;

        if (ch == ',')
        {
            commansCount++;
        }
        else if (commansCount == column)
        {
            item = item + ch;
        }
        index++;
    }

    return item;
}
void store()
{
    fstream file;
    file.open("nadra_data.txt", ios::out);
    for (int i = 0; i <= count_p; i++)
    {
        if (i == count_p)
        {
            file
                << nameA[i] << "," << lastnameA[i] << "," << genderA[i] << "," << fatherA[i] << "," << yearA[i] << "," << monthA[i] << "," << dateA[i] << "," << cnicA[i] << "," << provinceA[i] << "," << cityA[i] << "," << t_adressA[i] << "," << p_adressA[i] << "," << vaccineA[i] << "," << doseA[i];
        }
        else
        {
            file
                << nameA[i] << "," << lastnameA[i] << "," << genderA[i] << "," << fatherA[i] << "," << yearA[i] << "," << monthA[i] << "," << dateA[i] << "," << cnicA[i] << "," << provinceA[i] << "," << cityA[i] << "," << t_adressA[i] << "," << p_adressA[i] << "," << vaccineA[i] << "," << doseA[i] << endl;
        }
    }
    file.close();
}
void sign_up()
{
    fstream file;
    string line;
    int count = 0;
    file.open("sign_up.txt", ios::in);
    user_count = 1;
    while (!file.eof())
    {

        getline(file, line);

        usernameA[user_count] = parse(line, 1);

        passwordA[user_count] = parse(line, 2);

        roleA[user_count] = parse(line, 3);
        user_count++;
    }
}
void login()
{
    fstream file;
    file.open("sign_up.txt", ios::out);
    for (int i = 2; i <= user_count; i++)
    {

        if (i == user_count)
        {
            file << usernameA[i] << "," << passwordA[i] << "," << roleA[i];
        }
        else
        {
            file << usernameA[i] << "," << passwordA[i] << "," << roleA[i] << endl;
        }
    }
}

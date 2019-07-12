#include&lt;iostream .h&gt;
#include&lt;fstream .h&gt;
#include&lt;process .h&gt;
#include&lt;string .h&gt;
#include&lt;stdlib .h&gt;
#include&lt;stdio .h&gt;
#include&lt;ctype .h&gt;
#include&lt;conio .h&gt;
#include&lt;dos .h&gt;
//===========================================================
// THIS CLASS CONTAINS FUNCTIONS RELATED TO DRAW BOX ETC.
//===========================================================
class shape
{
public :
void line_hor(int, int, int, char);
void line_ver(int, int, int, char);
void box(int,int,int,int,char);
};
//===========================================================
// THIS CLASS CONTROL ALL THE FUNCTIONS IN THE MENU
//===========================================================
class control
{
public :
void main_menu(void);
void help(void);
private:
void edit_menu(void);
};
//===========================================================
// THIS CLASS CONTAINS FUNCTIONS RELATED TO INITIAL DEPOSIT
//===========================================================
class initial
{
public :
void add_to_file(int,char t_name[30],char
t_address[60],float);
void display_list(void);
void delete_account(int);
void update_balance(int,float);
void modify(void);
int last_accno(void);
int found_account(int);
char *return_name(int);
char *return_address(int);
float give_balance(int);
int recordno(int);
void display(int);
private:
void modify_account(int,char t_name[30],char t_address[60]);

void box_for_list(void);
int accno;
char name[30],address[60];
float balance;
};
//===========================================================
// THIS CLASS CONTAINS FUNCTIONS RELATED TO TRANSACTIONS
//===========================================================
class account
{
public :
void new_account(void);
void close_account(void);
void display_account(void);
void transaction(void);
void clear(int,int);
private :
void add_to_file(int,int,int,int,char,char
t_type[10],float,float,float);
void delete_account(int);
int no_of_days(int,int,int,int,int,int);
float calculate_interest(int,float);
void display(int);
void box_for_display(int);
int accno;
char type[10]; //Cheque or Cash
int dd,mm,yy; //Date
char tran ; // Deposit or withdrawl
float interest,amount,balance;
};
//===========================================================
// FUNCTION TO DRAW HORIZONTAL LINE
//===========================================================
void shape::line_hor(int column1,int column2,int row,char c)
{
for(column1;column1&lt; =column2;column1++)
{
gotoxy(column1,row);
cout&lt;&lt;c;
}
}
//===========================================================
// FUNCTION TO DRAW VERTICAL LINE
//===========================================================
void shape::line_ver(int row1,int row2,int column,char c)
{
for(row1;row1&lt;=row2;row1++)
{
gotoxy(column,row1);
cout&lt;&lt;c;

}
}

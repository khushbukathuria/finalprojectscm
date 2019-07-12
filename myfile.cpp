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

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
//============================================================
// FUNCTION TO DRAW BOX LINE
//============================================================
void shape::box(int column1,int row1,int column2,int row2,char c)
{
char ch=218;
char c1,c2,c3,c4;
char l1=196,l2=179;
if(c==ch)
{
c1=218;
c2=191;
c3=192;
c4=217;
l1=196;
l2=179;
}
else
{
c1=c;
c2=c;
c3=c;
c4=c;
l1=c;
l2=c;
}
gotoxy(column1,row1);
cout&lt;&lt;c1;
gotoxy(column2,row1);
cout&lt;&lt;c2;
gotoxy(column1,row2);
cout&lt;&lt;c3;
gotoxy(column2,row2);
cout&lt;&lt;c4;
column1++;
column2--;
line_hor(column1,column2,row1,l1);
line_hor(column1,column2,row2,l1);
column1--;
column2++;
row1++;
row2--;
line_ver(row1,row2,column1,l2);
line_ver(row1,row2,column2,l2);
}}
//===========================================================
//THIS FUNTION DISPLAY THE ACCOUNT FOR GIVEN ACCOUNT NO.

//FROM THE FILE INITIAL.DAT
//===========================================================
void initial::display(int t_accno)
{
shape s;
s.box(8,7,73,11,219);
fstream file;
file.open(&quot;INITIAL.DAT&quot;,ios::in);
file.seekg(0,ios::beg);
while(file.read((char*) this,sizeof(initial)))
{
if(t_accno==accno)
{
gotoxy(8,5);
cout&lt; &lt;&quot;ACCOUNT NO. &quot;&lt;&lt;accno;
gotoxy(10,8);
cout&lt;&lt;&quot;NAME :&quot;&lt;&lt;name;
gotoxy(10,9);
cout&lt;&lt;&quot;ADDRERSS :&quot;&lt;&lt;address;
gotoxy(10,10);
cout&lt;&lt;&quot;BALANCE :&quot;&lt;&lt;balance;
break;
}
}
file.close();
}
//=============================================================
//THIS FUNCTION RETURNS NAME FOR THE GIVEN ACCOUNT NO.
//IN THE FILE INITIAL.DAT
//=============================================================
char *initial::return_name(int t_accno)
{
fstream file;
file.open(&quot;INITIAL.DAT&quot;,ios::in);
file.seekg(0,ios::beg);
char t_name[30];
while(file.read((char *) this, sizeof(initial)))
{
if(accno==t_accno)
{
strcpy(t_name,name);
break;
}
}
file.close();
return t_name;
}
//=========================================================
//THIS FUNCTION RETURNS ADDRESS FOR THE GIVEN ACCOUNT NO.
//IN THE FILE INITIAL.DAT
//=========================================================
char *initial::return_address(int t_accno)

{
fstream file;
file.open(&quot;INITIAL.DAT&quot;,ios::in);
file.seekg(0,ios::beg);
char t_address[60];
while(file.read((char *)this, sizeof(initial)))
{
if(accno==t_accno)
{
strcpy(t_address,address);
break;
}
}
file.close();
return t_address;
}
//============================================================
//THIS FUNCTION RETURN BALANCE FOR THE GIVEN ACCOUNT NO.
//IN THE FILE INITIAL.DAT
//============================================================
float initial::give_balance(int t_accno)
{
fstream file;
file.open(&quot;INITIAL.DAT&quot;,ios::in);
file.seekg(0,ios::beg);
float t_balance;
while(file.read((char *)this, sizeof(initial)))
{
if(accno==t_accno)
{
t_balance=balance;
break;
}
}
file.close();
return t_balance;
}
//==========================================================
//THIS FUNCTION RETURN 1 IF THE GIVEN ACCOUNT NO. FOUND
//IN THE FILE INITIAL.DAT
//==========================================================
int initial::found_account(int t_accno)
{
fstream file;
file.open(&quot;INITIAL.DAT&quot;,ios::in);
file.seekg(0,ios::beg);
int found=0;
while(file.read((char *)this, sizeof(initial)))
{
if (accno==t_accno)
{
found=1;

break;
}
}
file.close();
return found;
}

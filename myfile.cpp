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
//============================================================
// FUNCTION TO DISPLAY MAIN MENU AND CALL OTHER FUNCTIONS
//============================================================
void control::main_menu(void)
{
char ch;

while (1)
{
clrscr();
shape s;
s.box(10,5,71,21,219);
s.box(9,4,72,22,218);
textcolor(LIGHTBLUE+BLINK);
textbackground(BLACK);
gotoxy(32,7);
cprintf(&quot; B A N K I N G &quot;);
gotoxy(35,9);
cprintf(&quot; OPTIONS &quot;);
textcolor(LIGHTBLUE);
textbackground(BLACK);
gotoxy(30,11);
cout&lt;&lt;&quot;1: SEE ACCOUNT &quot;;
gotoxy(30,12);
cout&lt;&lt;&quot;2: LIST OF ACCOUNTS &quot;;
gotoxy(30,13);
cout&lt;&lt;&quot;3: TRANSACTIONS &quot;;
gotoxy(30,14);
cout&lt;&lt;&quot;4: OPEN NEW ACCOUNT &quot;;
gotoxy(30,15);
cout&lt;&lt;&quot;5: EDIT ACCOUNTS &quot;;
gotoxy(30,16);
cout&lt;&lt;&quot;6: HELP &quot;;
gotoxy(30,17);
cout&lt;&lt;&quot;0: QUIT &quot;;
gotoxy(30,19);
cout&lt;&lt;&quot; ENTER YOUR CHOICE:&quot;;
ch=getche();
if(ch==27)
break;
else
if(ch==&#39;1&#39;)
{
account a;
a.display_account();
}
else
if(ch==&#39;2&#39;)
{
initial ini;
ini.display_list();
}
else
if(ch==&#39;3&#39;)
{
account a ;
a.transaction();
}
else
if(ch==&#39;4&#39;)
{
account a;
a.new_account();
}

else
if(ch==&#39;5&#39;)
edit_menu();
else
if(ch==&#39;6&#39;)
help();
else
if(ch==&#39;0&#39;)
break;
}
for(int i=25;i&gt;=1;i--)
{
delay(20);
gotoxy(1,i); clreol();
}
}
//=============================================================
// FUNCTION TO DISPLAY EDIT MENU AND CALL OTHER FUNCTION
//=============================================================
void control::edit_menu(void)
{
char ch;
while (1)
{
clrscr();
shape s;
s.box(10,5,71,21,219);
s.box(9,4,72,22,218);
textcolor(LIGHTBLUE);
textbackground(BLACK);
gotoxy(34,10);
cprintf(&quot; EDIT MENU&quot;);
textcolor(LIGHTBLUE);
textbackground(BLACK);
gotoxy(31,12);
cout&lt; &lt;&quot;1: MODIFY ACCOUNT :&quot;;
gotoxy(31,13);
cout&lt;&lt;&quot;2: CLOSE ACCOUNT &quot;;
gotoxy(31,14);
cout&lt;&lt;&quot;0: QUIT &quot;;
gotoxy(31,16);
cout&lt;&lt;&quot;ENTER YOUR CHOICE: &quot;;
ch=getche();
if(ch==27)
break;
else
if(ch==&#39;1&#39;)
{
initial ini;
ini.modify();
break;
}
else
if(ch==&#39;2&#39;)
{

account a;
a.close_account();
break;
}
else
if(ch==&#39;0&#39;)
break;
}
}
//=============================================================
// FUNCTION TO DISPLAY HELP ABOUT PROJECT
//=============================================================
void control::help(void)
{
clrscr();
shape s;
s.box(2,1,79,25,218);
s.box(25,2,54,4,219);
textcolor(LIGHTBLUE+BLINK);
gotoxy(27,3);
cprintf(&quot;WELCOME TO THE PROJECT BANKING &quot;);
textcolor(LIGHTBLUE);
delay(10);
gotoxy(10,6);
cout&lt;&lt;&quot;IN THIS PROJECT YOU CAN KEEP RECORD OF DAILY BANKING &quot;;
delay(10);
gotoxy(10,7);
cout&lt;&lt;&quot; TRANSACTIONS. &quot;;
delay(10);
gotoxy(10,9);
cout&lt;&lt;&quot; THIS PROGRAMME IS CAPABLE OF HOLDING ANY NO. OF ACCOUNTS &quot;;
delay(10);
gotoxy(10,11);
cout&lt;&lt;&quot; # IN FIRST OPTION YOU CAN SEE ACCOUNT OF A PARTICULAR &quot;;
delay(10);
gotoxy(10,12);
cout&lt;&lt;&quot; PERSON BY GIVING SIMPLY ACCOUNT NO. OF THAT PERSON&quot;;
delay(10);
gotoxy(10,14);
cout&lt;&lt;&quot;# IN SECOND OPTION YOUN CAN SEE THE LIST OF ALL ACCOUNTS. &quot;;
delay(10);
gotoxy(10,16);
cout&lt;&lt;&quot;# THROUGH THIRD OPTION YOU CAN DO BANKING TRANSACTIONS &quot;;
delay(10);
gotoxy(10,17);
cout&lt;&lt;&quot; ( DEPOSIT / WITHDRAW )&quot;;
delay(10);
gotoxy(10,19);
cout&lt;&lt;&quot;# IN FOURTH OPTION YOU CAN OPEN NEW ACCOUNT. &quot;;
delay(10);
gotoxy(10,20);
cout&lt;&lt;&quot; NOTE: OPENING AMOUNT SHOULD NOT LESS THAN Rs.500/-. &quot;;
delay(10);
gotoxy(10,22);
cout&lt;&lt;&quot;# IN THE FIFTH OPTION YOU CAN MODIFY OR DELETE ANY ACCOUNT. &quot;;

delay(10);
gotoxy(10,24);
cout&lt;&lt;&quot;# AND LAST OPTION IS QUIT (EXIT TO DOS).&quot;;
delay(10);
textcolor(LIGHTBLUE+BLINK); textbackground(BLACK);
gotoxy(26,25);
cprintf(&quot; PRESS ANY KEY TO CONTINUE &quot;);
textcolor(LIGHTBLUE);textbackground(BLACK);
gotoxy(25,2);
getch();
for(int i=25;i&gt;=1;i--)
{
delay(20);
gotoxy(1,i);clreol();
}
}
//========================================================
//THIS FUNCTION RETURN LAST ACCOUNT NO. IN THE FILE
//INITIAL.DAT
//========================================================
int initial::last_accno(void)
{
fstream file;
file.open(&quot;INITIAL.DAT&quot;, ios::in);
file.seekg(0,ios::beg);
int count=0;
while(file.read((char*)this, sizeof(initial)))
count=accno;
file.close();
return count;
}
//==========================================================
//THIS FUNCTION RETURN RECORD NO. OF THE GIVEN ACCOUNT NO.
//IN THE FILE INITIAL.DAT
//==========================================================
int initial::recordno(int t_accno)
{
fstream file;
file.open(&quot;INITIAL.DAT&quot;,ios::in);
file.seekg(0,ios::beg);
int count=0;
while (file.read((char*)this, sizeof(initial)))
{
count++;
if(t_accno==accno)
break;
}
file.close();
return count;
}

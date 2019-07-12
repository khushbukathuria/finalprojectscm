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
//===========================================================
// THIS FUNCTION DRAWS THE BOX FOR THE LIST OF ACCOUNTS
//===========================================================
void initial::box_for_list()
{
shape s;
s.box(2,1,79,25,218);
s.line_hor(3,78,3,196);
s.line_hor(3,78,5,196);
s.line_hor(3,78,23,196);
textbackground(BLACK);
gotoxy(3,4);
for(int i=1;i&lt;=76;i++)
cprintf(&quot; &quot;);
textbackground(BLACK);
textcolor(LIGHTBLUE);
textbackground(BLACK);
gotoxy(4,4);
cprintf(&quot;ACCOUNT NO. NAME OF PERSON BALANCE&quot;);
textcolor(LIGHTBLUE);
textbackground(BLACK);
int d1,m1,y1;
struct date d;
getdate(&amp;d);
d1=d.da_day;
m1=d.da_mon;
y1=d.da_year;
gotoxy(4,2);
cout&lt;&lt;&quot;DATE: &quot;&lt;&lt;d1&lt;&lt;&quot;/&quot;&lt;&lt;m1&lt;&lt;&quot;/&quot;&lt;&lt;y1;
}
//===========================================================
//THIS FUNCTION DISPLAYS THE LIST OF ACCOUNTS IN FILE
//INITIAL.DAT
//===========================================================
void initial::display_list(void)
{
clrscr();
box_for_list();
int row=6,flag;
fstream file;
file.open(&quot;INITIAL.DAT&quot;, ios::in);
while (file.read((char *)this, sizeof(initial)))
{
flag=0;
delay(10);
gotoxy(7,row);
cout&lt;&lt;accno;

gotoxy(25,row);
cout&lt;&lt;name;
gotoxy(57,row);
cout&lt;&lt;balance;
row++;
if(row==23)
{
flag=1;
row=6;
gotoxy(4,24);
cout&lt;&lt;&quot;PRESS ANY KEY TO CONTINUE...&quot;;
getch();
clrscr();
box_for_list();
}
}
file.close();
(!flag);
{
gotoxy(4,24);
cout&lt;&lt;&quot;PRESS ANY KEY TO CONTINUE...&quot;;
getch();
}
}
//================================================================
//THIS FUNCTION ADDS THE GIVEN DATA INTO THE FILE
//INITIAL.DAT
//================================================================
void initial::add_to_file(int t_accno,char t_name[30],char
t_address[60], float t_balance)
{
accno=t_accno;
strcpy(name,t_name);
strcpy(address,t_address);
balance=t_balance;
fstream file;
file.open(&quot;INITIAL.DAT&quot;,ios::out | ios::app);
file.write((char *) this, sizeof(initial));
file.close();
}
//===============================================================
//THIS FUNCTION DELETES RECORD FOR THE GIVEN ACCOUNT NO.
//FROM THE FILE INITIAL.DAT
//================================================================
void initial::delete_account(int t_accno)
{
fstream file;
file.open(&quot;INITIAL.DAT&quot;,ios::in);
fstream temp;
temp.open(&quot;temp.dat&quot;,ios::out);
file.seekg(0,ios::beg);
while(!file.eof())
{

file.read((char*)this,sizeof(initial));
if(file.eof())
break;
if(accno!=t_accno)
temp.write((char*)this,sizeof(initial));
}
file.close();
temp.close();
file.open(&quot;INITIAL.DAT&quot;,ios::out);
temp.open(&quot;temp.dat&quot;, ios::in);
temp.seekg(0,ios::beg);
while(!temp.eof() )
{
temp.read((char*)this,sizeof(initial));
if(temp.eof())
break;
file.write((char*)this,sizeof(initial));
}
file.close();
temp.close();
}
//================================================================
//THIS FUNCTION UPDATE BALANCE FOR THE GIVEN ACCOUNT NO.
//IN THE FILE INITIAL.DAT
//================================================================
void initial :: update_balance(int t_accno, float t_balance)
{
int recno;
recno=recordno(t_accno);
fstream file;
file.open(&quot;INITIAL.DAT&quot;,ios::out | ios::ate);
balance=t_balance;
int location;
location=(recno-1) * sizeof(initial);
file.seekp(location);
file.write((char *)this, sizeof(initial));
file.close();
}
//===============================================================
//THIS FUNCTION MODIFYS THE RECORD FOR THE GIVEN DATA
//IN THE FILE INITIAL.DAT
//===============================================================
void initial::modify_account(int t_accno,char t_name[30],char
t_address[60])
{
int recno;
recno=recordno(t_accno);
fstream file;
file.open(&quot;INITIAL.DAT&quot;, ios::out | ios::ate);
strcpy(name, t_name);
strcpy(address,t_address);
int location;
location=(recno-1) * sizeof(initial);

file.seekp(location);
file.write((char *) this, sizeof(initial));
file.close();
}
//============================================================
//THIS FUNCTION GIVE THE DATA TO MODIFY THE RECORD IN THE
//FILE INITIAL.DAT
//============================================================
void initial::modify(void)
{
clrscr();
char t_acc[10];
int t, t_accno;
gotoxy(71,1);
cout&lt;&lt;&quot;&amp;lt;0&gt;=EXIT&quot;;
gotoxy(5,5);
cout&lt; &lt;&quot;ENTER THE ACCOUNT NO.&quot;;
gets(t_acc);
t=atoi(t_acc);
t_accno=t;
if(t_accno==0)
return;
clrscr();
if(!found_account(t_accno))
{
gotoxy(5,5);
cout&lt;&lt;&quot;\7ACCOUNT NOT FOUND&quot;;
getch();
return;
}
shape s;
s.box(2,2,79,24,218);
s.line_hor(3,78,4,196);
s.line_hor(3,78,22,196);
gotoxy(71,1);
cout&lt;&lt;&quot;&amp;lt;0&gt;=EXIT&quot;;
textbackground(BLACK);
gotoxy(3,3);
for(int i=1;i&lt; =76;i++) cprintf(&quot; &quot;);
textbackground(BLACK);
textcolor(LIGHTBLUE+BLINK); textbackground(BLACK);
gotoxy(30,3);
cprintf(&quot;MODIFY ACCOUNT SCREEN&quot;);
textcolor(LIGHTBLUE); textbackground(BLACK);
int d1,m1,y1;
struct date d;
getdate(&amp;d);
d1=d.da_day;
m1=d.da_mon;
y1=d.da_year;
gotoxy(62,5);
cout&lt;&lt;&quot;DATE:&quot;&lt;&lt;d1&lt;&lt;&quot;/&quot;&lt;&lt;m1&lt;&lt;&quot;/&quot;&lt;&lt;y1;
char ch;
display(t_accno);
account a;

do
{
a.clear(5,13);
gotoxy(5,13);
cout&lt;&lt;&quot;MODIFY THIS ACCOUNT(Y/N):&quot;;
ch=getche();
if(ch==&#39;0&#39;)
return;
ch=toupper(ch);
}while(ch!=&#39;N&#39; &amp;&amp; ch!=&#39;Y&#39;);
if(ch==&#39;N&#39;)
return;
int modified=0,valid;
char t_name[30], t_address[60];
gotoxy(5,15);
cout&lt;&lt;&quot;NAME :&quot;;
gotoxy(5,16);
cout&lt;&lt;&quot;ADDRESS :&quot;;
do
{
a.clear(15,15);
a.clear(5,23);
gotoxy(5,23);
cout&lt;&lt;&quot;ENTER NAME OR PRESS &lt;ENTER&gt; FOR NO CHANGE&quot;;
valid=1;
gotoxy(15,15);
gets(t_name);
strupr(t_name);
if(t_name[0]==&#39;0&#39;)
return;
if(strlen(t_name)&gt;25)
{
valid=0;
gotoxy(5,23);
cprintf(&quot;\7NAME SHOULD NOT GREATER THAN 25&quot;);
getch();
}
}while(!valid);
if(strlen(t_name)&gt;0)
modified=1;
do
{
a.clear(15,16);
a.clear(5,23);
gotoxy(5,23);
cout&lt; &lt;&quot;ENTER ADDRESS OR PRESS &lt;ENTER&gt; FOR NO CHANGE&quot;;
valid=1;
gotoxy(15,16);
gets(t_address);
strupr(t_address);
if(t_address[0]==&#39;0&#39;)
return;
if(strlen(t_address)&gt;55)
{
valid=0;
gotoxy(5,23);
cprintf(&quot;\7SHOULD NOT BLANK OR GREATER THAN 55&quot;);

getch();
}
}while(!valid);
if(strlen(t_address)&gt;0)
modified=1;
if(!modified)
return;
a.clear(5,23);
do
{
a.clear(5,18);
gotoxy(5,18);
cout&lt; &lt;&quot;DO YOU WANT TO SAVE CHANGES (Y/N):&quot;;
ch=getche();
if(ch==&#39;0&#39;)
return;
ch=toupper(ch);
}while(ch!=&#39;N&#39; &amp;&amp; ch!=&#39;Y&#39;);
if(ch==&#39;N&#39;)
return;
modify_account(t_accno,t_name,t_address);
gotoxy(5,21);
cout&lt;&lt;&quot;\7RECORD MODIFIED&quot;;
gotoxy(5,23);
cout&lt;&lt;&quot;PRESS ANY KEY TO CONTINUE...&quot;;
getch();
}


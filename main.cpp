#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <deque>

using namespace std;




//to print my game area
void printv(vector <char> &v) {
for(char &c : v) {


    cout << c;

}
}

void printm(vector <string> m ) {

    for (const auto& row : m) {
        for (const auto& ch : row) {
            cout << ch;
        }
        cout << endl;
    }

}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}


void getcharWindow( int &cols , int &rows ){

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;

    if (GetConsoleScreenBufferInfo(hConsole, &info)) {
        cols = info.srWindow.Right - info.srWindow.Left + 1;
        rows = info.srWindow.Bottom - info.srWindow.Top + 1;


    }

}




void resetCursorPos() {
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

typedef struct posi{
int x;
int y;

};

void move_O(vector <string> &m , char &c , char &p , posi &h , bool &a , vector<vector<int>> &mi , bool &w , int &key) {

if(key){

if (c){


switch (c)   {
case 'S': if(p !='W') {  m[++h.x][h.y]='O'; a=true; } else {if(p=='W'){c='W';} ;a=false;}  break ;
case 'W': if (p!= 'S')    {m[--h.x][h.y]='O';  a=true;  } else  {if(p=='S'){c='S';} a=false;}  break;
case 'D':if ( p!= 'A') {m[h.x][++h.y]='O' ;  a=true;  } else {  if(p=='A'){c='A';}a=false;} break;
case 'A': if (p!= 'D')  {m[h.x][--h.y]='O' ;  a=true; ; }else {if(p=='D'){c='D';} a=false; } break;


default : a=false; break;
}

if(a){

    if(mi[h.x][h.y]==-1 || mi[h.x][h.y]==1  ) {

        w=false;
    }

    else {mi[h.x][h.y]=1; }

}

}



}



else {

  if (c){


switch (c)   {
case 'S': if(p !='Z') {  m[++h.x][h.y]='O'; a=true; } else {if(p=='Z'){c='Z';} ;a=false;}  break ;
case 'Z': if (p!= 'S')    {m[--h.x][h.y]='O';  a=true;  } else  {if(p=='S'){c='S';} a=false;}  break;
case 'D':if ( p!= 'Q') {m[h.x][++h.y]='O' ;  a=true;  } else {  if(p=='Q'){c='Q';}a=false;} break;
case 'Q': if (p!= 'D')  {m[h.x][--h.y]='O' ;  a=true; ; }else {if(p=='D'){c='D';} a=false; } break;


default : a=false; break;
}

if(a){

    if(mi[h.x][h.y]==-1 || mi[h.x][h.y]==1  ) {

        w=false;
    }

    else {mi[h.x][h.y]=1; }

}

}




}


}







void move_s(vector <string> &m , char &c , posi &t , vector<vector<int>> &mi  , int &key) {


if(key){
switch (c)   {
case 'S':  m[t.x++][t.y]=' ' ;  mi[t.x][t.y]=0 ;   break ;
case 'W':    m[t.x--][t.y]=' ';    mi[t.x][t.y]=0; break;
case 'D': m[t.x][t.y++]=' ' ;    mi[t.x][t.y]=0; break;
case 'A':   m[t.x][t.y--]=' ' ;   mi[t.x][t.y]=0; break;

}
}

else {

   switch (c)   {
case 'S':  m[t.x++][t.y]=' ' ;  mi[t.x][t.y]=0 ;   break ;
case 'Z':    m[t.x--][t.y]=' ';    mi[t.x][t.y]=0; break;
case 'D': m[t.x][t.y++]=' ' ;    mi[t.x][t.y]=0; break;
case 'Q':   m[t.x][t.y--]=' ' ;   mi[t.x][t.y]=0; break;

}

}
}



void fillm(vector <string> &m , int &ii , int &jj){

for(int i=0 ; i< ii ; i++){

    m[i][0]='#';
    m[i][jj-1]='#';

}


for(int i=0 ; i< jj ; i++){

    m[0][i]='#';
    m[ii-1][i]='#';



}



}

void fillM(vector<vector<int>> &mi , int &ii , int &jj){


for(int i=0 ; i< ii ; i++){

    mi[i][0]=-1;
    mi[i][jj-1]=-1;

}


for(int i=0 ; i< jj ; i++){

    mi[0][i]=-1;
    mi[ii-1][i]=-1;



}



}

bool operator==(const posi &a , const posi &b){

return a.x==b.x && a.y==b.y;
}



posi geng(vector<vector<int>> &mi , int &ii , int &jj){
posi g;
do {
  g.x=rand()%(ii-2)+1;
   g.y=rand()%(jj-2)+1;
}
while (mi[g.x][g.y]==1);

return g;


    }








int main() {





srand(time(0));
int ii;
int jj;
int target;
beginn:
cout <<"*********************WECLOM TO THE SNAKE GAME***********************"<<endl << endl;
char key;

 cout << "press C to continue" << endl;
 cout << "press E to end" << endl;
 do {cin >> key;} while(toupper(key)!='C' && toupper(key)!='E' );
 if(key=='E'){
        cout << "\n\n***********************THANKS FOR ENTERING THE GAME !*************************" << endl;
    return 0;
 }


int rows,cols;
getcharWindow(cols, rows);

cout <<"enter the size of your playing area (if the size dont match your srceen , you have to enter it again): "<<endl;
do{
cout << "rows : " <<endl; cin >> ii;} while(ii <10 || ii >=rows)  ;
do{
cout << "columns : " <<endl; cin >> jj;}while(jj<10 || jj >=cols);
int time;
int timeN;
do {
cout << "enter the speed of your snake ! : (speed from 1 to 5)"<<endl;
cin >> timeN;
} while(timeN <1 && timeN>5);

time=600-100*timeN;

do{
cout << "set a target of heads to win : " << endl;
cin >> target;}while (target <2);

int keys;
do{
    cout << "set your keys , 1 for QWERTY , 0 for AZERTY" << endl;
    cin >> keys;
} while (keys!=1 && keys !=0);




hideCursor();
vector <string> m(ii ,string(jj,' ')) ;

printm(m);

fillm(m , ii ,jj);

vector<vector<int>> mi(ii , vector<int>(jj,0));
fillM(mi, ii ,jj);



posi head;
posi tail;

 head.x=rand()%(ii-2)+1;

 head.y=rand()%(jj-2)+1;


 tail=head;


 mi[head.x][head.y]=1;
 m[head.x][head.y]='S';

posi g;
g=geng(mi , ii , jj);


m[g.x][g.y]='O';



char prev='l';key='l';

deque <char> rem;



bool a=false;
bool w=true;
int tt=1;
system("cls");

while(w)
 {





if ( _kbhit()) {

        key=toupper(_getch());

        }

        move_O(m , key ,prev, head  , a , mi , w , keys);
        prev=key;


        if(head==g){a=false;
       g=geng(mi ,ii ,jj);
       m[g.x][g.y]='O';
      tt++;
        rem.push_back(key);
        }

        if(a){

        rem.push_back(key);
mi[tail.x][tail.y]=0;
move_s(m , rem[0] , tail , mi , keys);

rem.pop_front();
}








                resetCursorPos();
                std::this_thread::sleep_for(std::chrono::milliseconds(time));

              printm(m);


if(!w || tt >= target){ break;}




}

system("cls");

if(tt>=target){cout << "you winn , and your score is : " << tt << endl;}
else {if(!w){cout << "you game has ended , your score is : " << tt<< endl;}

else {cout <<"hmmm you cant actualy get to this point only if you eat all area , if u did it good job mate , your score is infinity" <<endl;}

}
char c2;
do{
cout <<"press R to replay :"<<endl;
cout <<"press E to end :"<<endl;
cin >>c2 ; c2=toupper(c2);}
  while( c2!='R' && c2!='E');


if(c2=='R') {system("cls"); goto beginn;}
else {

        cout << "\n\n***********************THANKS FOR PLAYING THE GAME !*************************" << endl;}


    return 0;
}

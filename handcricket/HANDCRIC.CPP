#include<iostream>
#include<conio.h>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<iomanip>

using namespace std;

char p1[100],p2[100];
int tscore=0,tcscore=0,score,cscore,ch,ch2,randnum,a;

void takeInput(int i){
    cout << "Player " << i << " enter your name : " << endl;
    char c = ' ';
    string s = "";

    while(s.empty())
        getline(cin, s);

    if(i == 1)
        strcpy(p1,s.c_str());
    else
        strcpy(p2,s.c_str());

}

void bat()
{
    system("CLS");
    cout<<"IT'S TIME TO BAT!!"<<endl;
    do
    {
        a:
            cout<<"Choose a number from 1 to 10 : ";
            cin>>score;
            if(score>10||score<1)
            {
                cout<<"Try again, stupid!";
                goto a;
            }
            tscore+=score;
            cscore=1+rand()%10;
            cout<<endl<<"Computer chose : "<<cscore<<endl;
            if(score==cscore)
            cout<<"You're OUT!!!!"<<endl;
            cout<<"your score="<<tscore<<endl;
    }while(score!=cscore);
    _getch();
}

void bowl()
{
    system("CLS");
    cout<<"IT'S TIME TO BOWL"<<endl;
    do
    {
        b:
            cout<<"Choose a number from 1 to 10 : ";
            cin>>score;
            if(score>10||score<1)
            {
                cout<<"Try again, stupid!";
                goto b;
            }
            cscore=1+rand()%10;
            cout<<endl<<"Computer chose : "<<cscore<<endl;
            tcscore+=cscore;
            if(score==cscore)
                cout<<"Computer is OUT!!!!"<<endl;
    }while(score!=cscore);
_getch();
}


void bat(int ts)
{
    system("CLS");
    if(ts == -1){
        cout<< p1<<" IT'S TIME TO BAT!!"<<endl;
        cout<<"Press enter to continue";
        _getch();
        bat();
        return;
    }
     if(ts == -2){
        cout<< p2<<" IT'S TIME TO BAT!!"<<endl;
        cout<<"Press enter to continue";
        _getch();
        bat();
        return;
    }
    cout<<"IT'S TIME TO BAT!!"<<endl;
    do
    {
        a:
            cout<<"Choose a number from 1 to 10 : ";
            cin>>score;
            if(score>10||score<1)
            {
                cout<<"Try again, stupid!";
                goto a;
            }
            tscore+=score;
            if(tscore > ts){
                cout<<"Congratulations, " << p1 << " you successfully chased your score. Your final score is "<< tscore <<endl;
                return;
            }
            cscore=1+rand()%10;
            cout<<endl<<"Computer chose : "<<cscore<<endl;
            if(score==cscore)
            cout<<"You're OUT!!!!"<<endl;
            cout<<"your score="<<tscore<<endl;
    }while(score!=cscore);
    _getch();
}

void result()
{
    cout<<"Press enter to continue";
    _getch();
    system("CLS");
    cout<<"Thank you for playing this game. Submit a feedback if you have the time."<<endl<<endl<<endl;
    cout<<"And..... The result is : "<<endl;
    cout<<endl<<p1<<" scored "<<tscore<<" runs"<<endl;
    cout<<endl<<"Computer scored "<<tcscore<<" runs"<<endl<<endl;
    if(tscore>tcscore)
        cout<<p1<<" has won!";
    else if(tscore<tcscore)
        cout<<"Computer has won!";
    else
        cout<<"It's a tie!";
}

void pvc(){
    system("CLS");
    takeInput(1);
    cout<<"Heads or Tails (Enter 1 or 2)"<<endl;
    cin>>ch;
    randnum=1+(rand()%2);
    if(ch==randnum)
    {
        cout<<"You have won the toss"<<endl;
        hi:
            cout<<endl<<"Enter 1 to bat, 2 to bowl"<<endl;
            cin>>ch2;
    }
    else
    {
        cout<<"Computer has won the toss and chose to bowl"<<randnum<<endl;
        ch2=1;
    }
    switch(ch2)
    {
        case 1:
            bat();
            bowl();
            break;
        case 2:
            bowl();
            bat();
            break;
        default:
            cout<<"Stupid";
            goto hi;
    }
    result();
    _getch();

}


void pvp(){
    system("CLS");

    takeInput(1);
    takeInput(2);
    cout <<"Player 1 is" << p1 << endl;
    cout <<"Player 2 is" << p2 << endl;

    cout << "---------";

    cout<< p1 << " choose Heads or Tails (Enter 1 or 2)"<<endl;
    cin>>ch;
    randnum=1+(rand()%2);
    if(ch==randnum)
    {
        cout<< p1<<" has won the toss"<<endl;
        cout<<endl<< p1<<" enter 1 to play first, 2 to play second."<<endl;
        cin>>ch2;
    }
    else
    {
        cout<< p2<<" has won the toss"<<endl;
        cout<<endl<< p2<<" enter 1 to play first, 2 to play second."<<endl;
        cin>>ch2;
    }
    int p1s = 0, p2s = 0;

    if( (ch2 == 1 && ch == randnum) || (ch2 == 2 && ch != randnum) ){
        bat(-1);
        p1s = tscore;
        tscore = 0;
        bat(-2);
        p2s = tscore;
    }else if( (ch2 == 2 && ch == randnum) || (ch2 == 1 && ch != randnum) ){
        bat(-2);
        p2s = tscore;
        tscore = 0;
        bat(-1);
        p1s = tscore;
    }

    int r = abs(p1s - p2s);

    cout<<"Press enter to continue";
    _getch();
    system("CLS");
    cout<<"Thank you for playing this game. Submit a feedback if you have the time."<<endl<<endl<<endl;
    cout<<"And..... The result is : "<<endl;
    cout<<endl<<p1<<" scored "<<p1s<<" runs"<<endl;
    cout<<endl<<p2 << " scored "<<p2s<<" runs"<<endl<<endl;

    if(p1s > p2s){
        cout<< p1<<" won by "  << r << " runs."<<endl;
    }else if (p1s < p2s ){
        cout<< p2<<" won by "  << r << " runs."<<endl;
    }    else
        cout<<"It's a tie!";
    _getch();

}

void pvs(){
    int ts = 0;
    system("CLS");
    takeInput(1);
    cout<<"Enter the score you want to chase."<<endl;
    cin >> ts;
    bat(ts);
    result();
    _getch();
}

void showRules(){
    cout<<endl<<"Rules:"<<endl;
    cout<<"1 - Choose a number from 1-10"<<endl<<endl<<"2 - If opponent's chosen number and your chosen number are the same, the batsman is out"<<endl<<endl<<"3 - The batsman and bowler switches roles after the batsman gets out."<<endl<<endl<<"4 - Whoever gets the highest score wins."<<endl<<endl<<"5 - Have fun!!!"<<endl<<endl;
    cout<<endl<<endl<<"Press any key to continue";
    _getch();

}


int main()
{
    system("CLS");
    int m = 0;
    a:
    cout<<"Welcome to the game of hand cricket!"<<endl;
    cout<<"Choose the mode you want to play."<<endl;
    cout<<"Enter 1 to play vs Computer." <<endl;
    cout<<"Enter 2 to chase a fixed score." <<endl;
    cout<<"Enter 3 to play Player vs Player" <<endl << endl;
    cin >> m;
    cout << endl;

    system("CLS");
    switch(m){
        case 1 :
            cout << "You are playing against computer." << endl << endl;
            showRules();
            pvc();
            break;
        case 2 :
            cout << "You are chasing a custom score." << endl << endl;
            showRules();
            pvs();
            break;
        case 3 :
            cout << "You are playing Player vs Player." << endl << endl;
            showRules();
            pvp();
            break;
        default :
            cout<<"Enter a valid game mode.";
            goto a;

    }
    return 0;
}

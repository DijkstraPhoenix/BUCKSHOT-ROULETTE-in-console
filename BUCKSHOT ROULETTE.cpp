#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
string Playername;
vector<int>gun;
int Live,Blank;
int PlayerHeal,DealerHeal;
int PlayerDam,DealerDam;
int Roundcnt;

void Player_1(void);
void Dealer_1(void);

void colprint(string s,int col)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY|col);
    cout<<s;
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY|7);
}

void printt(string s,int tim)
{
    for(int i=0;i<s.length();i++)
    {
        cout<<s[i];
        Sleep(tim);
    }
}

void printc(string s,int tim,int col)
{
    for(int i=0;i<s.length();i++)
    {
        HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY|col);
        cout<<s[i];
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY|7);
        Sleep(tim);
    }
}

void Load_Arm(int k)
{
    gun.clear();
    Live=1+rand()%(k-1);
    Blank=k-Live;
    int l=Live,b=Blank;
    for(int i=1;i<=k;i++)
    {
        int arm=rand()%2;
        if(l==0)arm=0;
        if(b==0)arm=1;
        gun.push_back(arm);
        if(arm==1)l--;
        else b--;
    }
}

void ShowCond(bool prop,bool final)
{
    if(!final)
    {
        colprint(Playername,6);
        cout<<"  ";
        for(int i=1;i<=PlayerHeal;i++)
            cout<<"$ ";
        cout<<endl;
        colprint("Dealer",6);
        cout<<"  ";
        for(int i=1;i<=DealerHeal;i++)
            cout<<"$ ";
        cout<<endl<<endl;
    }
}

void Player_1(void)
{
    if(Live+Blank==0)
    {
        Load_Arm(2+rand()%3);
        Sleep(1000);
        cout<<Live;
        printc(" live ammunitions ",40,4);
        cout<<", "<<Blank;
        printc(" blank cartridges\n",40,1);
        Sleep(1700);
        system("cls");
        Sleep(500);
    }
    ShowCond(false,false);
    PlayerDam=DealerDam=1;
    Sleep(500);
    printt("-Your round-\n",40);
    Sleep(500);
    cout<<"1 - Shot at the dealer\n2 - Shot at yourself";
    Sleep(200);
    printt("\nYour own choose : ",40);
    int inp;
    cin>>inp;
    Sleep(300);
    system("cls");
    Sleep(300);
    if(inp==1)
    {
        printt("You shot at Dealer\n",40);
        Sleep(800);
        int x=gun[gun.size()-1];
        gun.pop_back();
        if(x==1)
        {
            printt("It's a ",40);
            printc("live ammunition\n",40,4);
            Sleep(500);
            printt("The dealer's health is reduced by ",40);
            cout<<PlayerDam<<endl;
            DealerHeal-=PlayerDam;
            Live--;
        }
        else
        {
            printt("It's a ",40);
            printc("blank cartridge\n",40,1);
            Sleep(500);
            printt("Nothing happend...",40);
            Blank--;
        }
    }
    else
    {
        printt("you shot at Yourself\n",40);
        Sleep(800);
        int x=gun[gun.size()-1];
        gun.pop_back();
        if(x==1)
        {
            printt("It's a ",40);
            printc("live ammunition\n",40,4);
            Sleep(500);
            printt("Your health is reduced by ",40);
            cout<<PlayerDam<<endl;
            PlayerHeal-=PlayerDam;
            Live--;
        }
        else
        {
            printt("It's a ",40);
            printc("blank cartridge\n",40,1);
            Sleep(500);
            printt("Nothing happend...",40);
            Sleep(1000);
            system("cls");
            Blank--;
            if(PlayerHeal>0)
            {
                if(Roundcnt==0)
                {
                    Roundcnt=1;
                    Player_1();
                }
                else
                {
                    Roundcnt=0;
                    Dealer_1();
                }
            }
        }
    }
    Sleep(1000);
    system("cls");
    Roundcnt=0;
    if(DealerHeal>0&&PlayerHeal>0)
        Dealer_1();
}

void Dealer_1(void)
{
    if(Live+Blank==0)
    {
        Load_Arm(2+rand()%3);
        Sleep(1000);
        cout<<Live;
        printc(" live ammunitions ",40,4);
        cout<<", "<<Blank;
        printc(" blank cartridges\n",40,1);
        Sleep(1700);
        system("cls");
        Sleep(500);
    }
    ShowCond(false,false);
    PlayerDam=DealerDam=1;
    Sleep(500);
    printt("-Dealer's round-\n",40);
    Sleep(600);
    system("cls");
    int inp;
    Sleep(300);

    if(Roundcnt=1)inp=1;
    else if(Live==0)inp=0;
    else if(Blank==0)inp=1;
    else if(Live>Blank)
    {
        if((rand()%10)<7)inp=1;
        else inp=0;
    }
    else
    {
        if((rand()%10)<4)inp=1;
        else inp=0;
    }

    if(inp==1)
    {
        printt("Dealer shot at You\n",40);
        Sleep(800);
        int x=gun[gun.size()-1];
        gun.pop_back();
        if(x==1)
        {
            printt("It's a ",40);
            printc("live ammunition\n",40,4);
            Sleep(500);
            printt("Your health is reduced by ",40);
            cout<<DealerDam<<endl;
            PlayerHeal-=DealerDam;
            Live--;
        }
        else
        {
            printt("It's a ",40);
            printc("blank cartridge\n",40,1);
            Sleep(500);
            printt("Nothing happend...",40);
            Blank--;
        }
    }
    else
    {
        printt("Dealer shot at Himself\n",40);
        Sleep(800);
        int x=gun[gun.size()-1];
        gun.pop_back();
        if(x==1)
        {
            printt("It's a ",40);
            printc("live ammunition\n",40,4);
            Sleep(500);
            printt("Dealer's health is reduced by ",40);
            cout<<DealerDam<<endl;
            DealerHeal-=DealerDam;
            Live--;
        }
        else
        {
            printt("It's a ",40);
            printc("blank cartridge\n",40,1);
            Sleep(500);
            printt("Nothing happend...",40);
            Sleep(1000);
            system("cls");
            Blank--;
            if(DealerHeal>0)
            {
                if(Roundcnt==0)
                {
                    Roundcnt=1;
                    Dealer_1();
                }
                else
                {
                    Roundcnt=0;
                    Player_1();
                }
            }
        }
    }
    Sleep(1000);
    system("cls");
    Roundcnt=0;
    if(DealerHeal>0&&PlayerHeal>0)
        Player_1();
}

void Round_1(void)
{
    PlayerHeal=DealerHeal=6;
    PlayerDam=DealerDam=1;
    
    Player_1();
    if(PlayerHeal<1)
    {
        printc("You lost, don't give up !",100,4);
        Sleep(400);
        printc(Playername,150,6);
        Sleep(2000);
        exit(0);
    }
    else
    {
        printc("You won the round!",50,6);
        Sleep(2000);
        system("cls");
    }
}

void Round_2(void)
{

}

int main(void)
{
    srand(time(0));
    Sleep(1000);
    printt("Please sign the agreement : ",35);
    cin>>Playername;
    Sleep(800);
    printt("\"",50);
    printc(Playername,50,6);
    printt("\"",50);
    Sleep(1500);
    system("cls");
    printt("DEALER : Let's play an interesting game. . .",40);
    Sleep(400);
    printt("\nDEALER : I will load the bullets into the gun in a random order. . .",40);
    Sleep(1200);
    system("cls");
    Sleep(500);

    //Round 1
    cout<<"-Round 1-";
    Sleep(800);
    system("cls");
    Round_1();

    //Round 2
    cout<<"-Round 2-";
    Sleep(800);
    system("cls");
    Round_2();

    return 0;
}
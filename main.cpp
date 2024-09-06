#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void print(string word,unordered_map<char,int>&playerguess)
{
    for(int i=0;i<word.length();i++)
    {
        if(playerguess[word[i]] >=1)
        cout<<word[i]<<" ";
        else
        cout<<"_"<<" ";
    }
    cout<<endl;
}
bool check(char guess,unordered_map<char,int>&playerguess,string word,int &correctguess,unordered_map<char,int>&repeat)
{
    bool ans=false;
    for(int i=0;i<word.length();i++)
    {
        if(word[i]==guess && repeat[guess]!=playerguess[guess])
        {
            ans=true;
            playerguess[word[i]]++;
            correctguess++;
        }
    }
    return ans;
}
void printhangman(int wrongguess)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(j==0)
            cout<<"|";
            else if(i==1)
            cout<<"_";
            else if(wrongguess>=1 && i==2 && j==8 && wrongguess!=8)
            cout<<"|";
            else if(wrongguess>=2 && i==3 && j==8)
            cout<<"0";
            else if(wrongguess>=3 && i==4 && j==8)
            cout<<"|";
            else if(wrongguess>=4 && i==4 && j==7)
            cout<<"/";
            else if(wrongguess>=5 && i==4 && j==9)
            cout<<"\\";
            else if(wrongguess>=6 && i==5 && j==7)
            cout<<"/";
            else if(wrongguess>=7 && i==5 && j==9)
            cout<<"\\";
            else
            cout<<" ";
        }
        cout<<endl;
    }
}
int main() {
    
    char ch='y';
    cout<<"WELCOME TO THE  WORLD OF HANGMAN GAME";
    while(ch=='y' || ch=='Y')
    {
    string st[5]={"ankit","prajjwal","shreekesh","yashwant"};
    string ht[5]={"ankura","vdh","anjali","bhoomika" };
    string word=" ";
    srand(static_cast<unsigned int>(time(0)));
    word = st[rand() % 5];
    int index=0;
    for(int i=0;i<5;i++)
    {
        if(word==st[i])
        index=i;
    }
    string hint=ht[index];
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    int wrongguess=0,correctguess=0;
    unordered_map<char,int>guessed;
    unordered_map<char,int>playerguess;
    unordered_map<char,int>repeat;
    for(int i=0;i<word.length();i++)
    {
        repeat[word[i]]++;
    }
    int n=word.length();
    cout<<"YOUR HINT:"<<hint<<endl;
    while(wrongguess<=7)
    {
        char guess;
        print(word,playerguess);
        if(!guessed.empty())
        cout<<"ALREADY GUESSED LETTERS:";
        for(auto i:guessed)
        {
            cout<<"("<<i.first<<")";
        }
        cout<<endl;
        cout<<"ENTER YOUR GUESS:";
        cin>>guess;
        if(guessed[guess]==0)
        guessed[guess]++;
        bool checkguess=check(guess,playerguess,word,correctguess,repeat);
        if(checkguess==false)
        {
            wrongguess++;
            printhangman(wrongguess);
            if(wrongguess<=7)
            cout<<"OOPS INCORRECT GUESS"<<endl;
            if(wrongguess==7)
            cout<<"LAST GUESS REMAINING"<<endl;
            if(wrongguess==8)
            {
                cout<<"************OOPS YOU LOST THE GAME*************"<<endl;
                cout<<"TRY AGAIN!"<<endl;
                break;
            }
        }
        if(correctguess==n)
        {
            cout<<"*************BRAVO! YOU WON THE GAME*************"<<endl;
            break;
        }
        cout<<"GUESS REMAINING:"<<8-wrongguess<<endl;
      }
      char res;
      cout<<"do you want play (y/n):";
      cin>>res;
      
      ch=res;
    }
    return 0;
}

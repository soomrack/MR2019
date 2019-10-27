#include "mylibrary_test.h"
using namespace std;

void Quest(void){
    string name,old,fraction,king, ans;
    vector <char> Old;
    vector <char> Old_true;
    string *letter=&old;

    cout<<"Welcome to our quest\n";
    cout<<"Write your Name\n";
    cin>>name;
    cout<<"Nice to meet you, "<<name<<"\n";
    cout<<"How old are you?\n";
    cin>>old;
    for(int i=0;i<old.length();i++){
        Old.push_back((*letter)[i]);
    }
    for(char b:Old){
        if ((int)b<=58 && (int)b>=47)
            Old_true.push_back(b);
    }
    for(char b:Old_true){
        cout<<b;
    }
    cout<<", great\n";
    cout<<"Lets check your brain\n"<<"Please, calculate some sample\n";
    cout<<"Count true answer "<<0<<"/3\n";
    cout<<"2+5=\n";
    cin>>ans;
    while(ans!="7"){
        cout<<"Its false, rty again\n";
        cin>>ans;
    }
    cout<<"Count true answer "<<1<<"/3\n";
    cout<<"5*7=\n";
    cin>>ans;
    while(ans!="35"){
        cout<<"Its false, rty again\n";
        cin>>ans;
    }
    cout<<"Count true answer "<<2<<"/3\n";
    cout<<"5!=\n";
    cin>>ans;
    while(ans!="120"){
        cout<<"Its false, try again\n";
        cin>>ans;
    }
    cout<<"Count true answer "<<3<<"/3\n";
    cout<< "Great, whats about games?)\n"<<"Chose one fraction\n";
    cout<<"For the Horde or for the Alliance, write your answer\n";
    cin>>fraction;
    while(fraction!="Alliance"&&fraction!="Horde"){
        cout<<"Its false fraction, try again";
        cin>>fraction;
    }
    if(fraction=="Alliance"){
        cout<<"Lets check your knowledge of this game world\n";
        cout<<"Who is a king of Humans:\nAnduin\nSaurfang\nJaina\nSilwana\n";
        cin>>king;
        while(king!="Anduin"){
            cout<<"Its false,try again\n";
            cin>>king;
        }
    }else{
        cout<<"Lets check your knowledge of this game world\n";
        cout<<"Who is a chief of Humans:\nAnduin\nSaurfang\nJaina\nSilwana\n";
        cin>>king;
        while(king!="Silwana"){
            cout<<"Its false,try again\n";
            cin>>king;
        }
        cout<< "You are the best,come back, as will continuation of test!";
    }


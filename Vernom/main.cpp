#include <iostream>
using namespace std;
int main()
{
    string Word,key,E_Word="";
    puts("Enter The Word To Make Vernom Encryption:");
    cin>>Word;
    puts("Enter The Key To Make Vernom Encryption:");
    cin>>key;
    int n = Word.size();
    int x = key.size();
    cout<<"The Word: "<<Word<<"\nThe Encrypted Word: ";
    for(int i=0;i<n;i++){int j=0;
        while(x>j&&i<n){
           cout<<char((((Word[i]-'a')+(key[j]-'a'))%26)+'a');
           //cout<<Word[i]<<" "<<key[j]<<" "<<char((((Word[i]-'a')+(key[j]-'a'))%26)+'a')<<"\n";
           j++;i++;
        }
        i--;
    }
    return 0;
}

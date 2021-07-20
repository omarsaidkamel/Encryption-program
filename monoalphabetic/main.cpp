#include <iostream>
#include <stdlib.h>
using namespace std;
string Word;bool b[26];int y[26];
int main()
{
    puts("Enter The Word To Make Mono Alphabetic Encryption:");
    cin>>Word;
    int n = Word.size();
    cout<<"The Word: "<<Word<<"\nThe Encrypted Word: ";
    for(int i=0;i<26;i++){
        while(1){
          int x = rand()%26;
          if(!b[x] && x != i){
            y[i] = x;b[x] = 1;
            break;
          }
        }
    }
    for(int i=0;i<n;i++) cout<<(char)(y[Word[i]-'a']+'a');
    return 0;
}

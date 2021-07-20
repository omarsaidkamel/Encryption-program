#include <iostream>
#include <stdlib.h>
using namespace std;
string Word;bool b[26];int y[26],ch[26];
int main()
{
    puts("Enter The Word To Make Mono Alphabetic Encryption:");
    cin>>Word;
    int n = Word.size();
    for(int i=0;i<26;i++){
        while(1){
          int x = rand()%26;
          if(!b[x] && x != i){
            y[i] = x;b[x] = 1;
            break;
          }
        }
    }int x,w=1,u=0;
    for(int i=0;i<n;i++){
      printf("Enter Shift number %d:\n",i+1);
      scanf("%d",&x);
      ch[i] = x;u++;
      if(i+1!=n){
          puts("1 - Add another one.\n2 - Exit.");
          scanf("%d",&w);
          if(w==2)break;
      }
    }
    cout<<"The Word: "<<Word<<"\nThe Encrypted Word: ";
    for(int i=0;i<n;i++){
      for(int j=0;j<u&&i<n;j++){
         cout<<char(y[((Word[i]-'a')+ch[j])%26]+'a');i++;
      }i--;
    }
    return 0;
}
    //for(int i=0;i<26;i++)cout<<char('a'+i)<<" "<<char(y[i]+'a')<<"\n";

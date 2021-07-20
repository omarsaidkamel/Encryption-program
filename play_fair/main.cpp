#include <iostream>
using namespace std;
char c[6][6],px[102]; string Word,Key;bool x[26];int h,l,r=1;
int main()
{
    puts("Enter The Word To Make Play Fair Encryption:");
    cin>>Word;
    puts("Enter The Key To Make Play Fair Encryption:");
    cin>>Key;
    int n = Key.size();
    //Clear the word from repeated Letters and i&&j
    for(int i=0;i<n;i++){
      if(!x[Key[i]-'a']){
           if((Key[i]=='i'&& x['j'-'a']) || (Key[i]=='j'&& x['i'-'a']))continue;
           px[h] = Key[i];
           x[Key[i]-'a'] = 1;h++;
       }
    }
    //insert the clear word in 2D array
    for(int i=0;i<5;i++){
     for(int j=0;j<5;j++){
       if((i*5)+j<h) c[i][j] = px[(i*5)+j];
     }
    }
    //fill the 2D array with the remaining Letters
    for(char i='a';i<='z';i++){
        if(!x[i-'a']){
            if((i=='i'&& x['j'-'a']) || (i=='j'&& x['i'-'a']))continue;
            if(i=='i')x['i'-'a']=1;
            c[h/5][h%5] = i;
            h++;
        }
    }
    int t = Word.size();char a,b;int ax,ay,bx,by;
    cout<<"The Word: "<<Word<<"\nThe Encrypted Word: ";
    while(l<t||r<t){
      if(l<t&&r>=t){
         if(Word[l]=='x'){
            a = Word[l]; b = 'e';
            l++;
         }
         else {
            a = Word[l]; b = 'x';
            l++;
         }
      }
      else {
          if(Word[l] == Word[r] && Word[r]=='x'){
            a = Word[l]; b = 'e';
            l++;r++;
          }
          else if(Word[l] == Word[r]){
            a = Word[l]; b = 'x';
            l++;r++;
          }
          else {
            a = Word[l]; b = Word[r];
            l+=2;r=l+1;
          }
      }
      if(a=='i' && !x['i'-'a'])a='j';
      if(a=='j' && !x['j'-'a'])a='i';
      if(b=='i' && !x['i'-'a'])b='j';
      if(b=='j' && !x['j'-'a'])b='i';
      for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(c[i][j] == a){ax=i;ay=j;}
            if(c[i][j] == b){bx=i;by=j;}
        }
      }
      if(ax == bx) cout<<c[ax][(ay+1)%5]<<c[bx][(by+1)%5];
      else if(ay == by) cout<<c[(ax+1)%5][ay]<<c[(bx+1)%5][by];
      else cout<<c[ax][by]<<c[bx][ay];
    }/*puts("");
    for(int i=0;i<5;i++){
     for(int j=0;j<5;j++){
            cout<<c[i][j];
     }
     puts("");
    }*/

    return 0;
}

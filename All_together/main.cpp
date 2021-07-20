#include <iostream>
using namespace std;
int main()
{
    int test;
    puts("Enter Number to make the Encryption\n1-caeser\n2-Play Fair\n3-Monoalphabetic\n4-Polyalphabetic\n5-Vernom\n6-Rail fence");
    scanf("%d",&test);
    if(test==1){
        int key;
        string Word;
        puts("Enter The Word To Make caesar Encryption:");
        cin>>Word;
        puts("Enter The Key To Make caesar Encryption:");
        scanf("%d",&key);
        int n = Word.size();
        cout<<"The Word: "<<Word<<"\nThe Encrypted Word: ";
        for(int i=0;i<n;i++) cout<<(char) (((key + (Word[i]-'a'))%26)+'a');
    }
    else if(test==2){
        char c[6][6],px[102];bool zz[26];string Word,Key;int h=0,l=0,r=1;fill(zz,zz+26,0);
        puts("Enter The Word To Make Play Fair Encryption:");
        cin>>Word;
        puts("Enter The Key To Make Play Fair Encryption:");
        cin>>Key;
        int n = Key.size();
        //Clear the Key from repeated Letters and i&&j
        for(int i=0;i<n;i++){
          if(!zz[Key[i]-'a']){
               if((Key[i]=='i'&& zz['j'-'a']) || (Key[i]=='j'&& zz['i'-'a']))continue;
               px[h] = Key[i];
               zz[Key[i]-'a'] = 1;h++;
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
            if(!zz[i-'a']){
                if((i=='i'&& zz['j'-'a']) || (i=='j'&& zz['i'-'a']))continue;
                if(i=='i')zz['i'-'a']=1;
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
          if(a=='i' && !zz['i'-'a'])a='j';
          if(a=='j' && !zz['j'-'a'])a='i';
          if(b=='i' && !zz['i'-'a'])b='j';
          if(b=='j' && !zz['j'-'a'])b='i';
          for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(c[i][j] == a){ax=i;ay=j;}
                if(c[i][j] == b){bx=i;by=j;}
            }
          }
          if(ax == bx) cout<<c[ax][(ay+1)%5]<<c[bx][(by+1)%5];
          else if(ay == by) cout<<c[(ax+1)%5][ay]<<c[(bx+1)%5][by];
          else cout<<c[ax][by]<<c[bx][ay];
        }
    }
    else if(test==3){
        string Word;bool b[26];int y[26];fill(b,b+26,0);
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
    }
    else if(test==4){
        string Word;bool b[26];int y[26],ch[26];fill(b,b+26,0);
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
    }
    else if(test==5){
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
    }
    else if(test==6){
        string Word;int key;
        puts("Enter The Word To Make rail fence Encryption:");
        cin>>Word;
        puts("Enter The Key To Make rail fence Encryption:");
        scanf("%d",&key);
        int n = Word.size();
        cout<<"The Word: "<<Word<<"\nThe Encrypted Word: ";
        for(int i=0;i<key;i++){
           for(int j=0;j<n;j++){
             if(j%key==i)cout<<Word[j];
           }
        }
    }
    else puts("Invalid Number");
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
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
    return 0;
}

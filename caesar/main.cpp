#include <iostream>
using namespace std;
int main()
{
    int key;
    string Word;
    puts("Enter The Word To Make caesar Encryption:");
    cin>>Word;
    puts("Enter The Key To Make caesar Encryption:");
    scanf("%d",&key);
    int n = Word.size();
    cout<<"The Word: "<<Word<<"\nThe Encrypted Word: ";
    for(int i=0;i<n;i++) cout<<(char) (((key + (Word[i]-'a'))%26)+'a'); 
    return 0;
}

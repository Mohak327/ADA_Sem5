#include <bits/stdc++.h>
using namespace std;
const int t = 256;
const int w = 1283;

void rabinKarpSearch(string text,string pattern){

    int tlen = text.length();
    int plen = pattern.length();
    int flag;
    int c=1,i=0;

    //Calculate hash_p(hash value of pattern) and hash_0
    int hash_p=0,hash=0;
    while(i<plen){
        hash_p=(hash_p*t + pattern[i])%w;
        hash=(hash*t + text[i])%w;
        i++;
    }

     //Calculate (t^(plen-1))%w
    for(int i=1;i<=plen-1;i++)
        c=(c*t)%w;

    i=0;
    while(i<=tlen-plen){
       if(hash_p==hash){
            flag=1;
            for(int j=0;j<plen;j++){
                if(pattern[j]==text[i+j]){
                    continue;
                }
                else{
                    flag = 0;
                    break;
                }
           }
            if(flag==1)cout<<i<<" ";
       }


       //Calculate hash value of next window
       //hash_i+1 = t * {hash_i - text[i] * t^(plen-1)} + text[i+plen]
       if(i<tlen-plen){
           hash=((t*(hash-text[i]*c))+text[i+plen])%w;
            if(hash<0){
                hash = hash + w;
            }
       }
       i++;
    }
}



int main()
{
    string pattern, text;
    cout << "Enter text: ";
    cin >> text;
    cout << "Entern pattern to be searched: ";
    cin >> pattern;
    rabinKarpSearch(text,pattern);
    return 0;
}
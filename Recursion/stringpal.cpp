#include <bits/stdc++.h>
using namespace std;


bool pal(string str){
    

    if(str.size() ==0 || str.size() == 1 ){
        
        return true;
        
    } 
    else if(str[0] == str[str.size()-1]){
        
        return (pal(str.substr(1,str.size()-2)));
        
    }
    else{
          
        return false;
      
    }
}

//tail rec

bool pal(string str,int s){
    

    if(str.size() ==0 || str.size() == 1 ){
        
        return true;
        
    } 
    else if(str[0] == str[str.size()-1]){
        
        return true*(pal(str.substr(1,str.size()-2)));
        
    }
    else{
          
        return false;
      
    }
}


int main() {
    string str;
    cin>>str;
    cout<< pal(str);
    return 0;
}
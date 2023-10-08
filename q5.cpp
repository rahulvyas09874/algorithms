#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int aa;
    int i;
    vector<int> vec1;
    cout<<"";
    cin>>n;
    for(i=0;n>i;i++){
        cout<<"";
        cin>>aa;
        vec1.push_back(aa);
    }
    cout<<i<<endl;
    // for(auto & element : vec1){
    //     cout<< element<<" ";
    reverse(vec1.begin(), vec1.end());
    for (int i = 0; i < vec1.size(); i++){
        cout << vec1[i] << " ";
    }

}
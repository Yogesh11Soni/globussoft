#include <iostream>
#include <vector>
using namespace std;
int contestants[40001] = {0};
vector<int> results;
void wash(int num){  int count = 0;  for (int i = num+ 1;i <= 40000;i++) {  if (contestants[i] == 0) {  count++;  if (count == num) {  contestants[i] = 1;  count=0;  }  }  } } int main() {
   results.push_back(0);  for (int i = 2;i <= 40000;i++) {  if (contestants[i] == 0) {  results.push_back(i);  wash(i);  }  }  int n ;  cin >> n;  while (n != 0) {
 cout<<results[n]<<endl;
 cin >> n;
 }
 return 0;
}
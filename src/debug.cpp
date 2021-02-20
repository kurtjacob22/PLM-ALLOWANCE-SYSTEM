#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int linear_search(vector<string> v, string a){  
   for (int i = 0; i < v.size(); i++){  
      if (v[i] == a)
         return i;
   }
   return -1;
}

void print(vector<int> a){  
   for (int i = 0; i < a.size(); i++)
      cout << a[i] << " ";
   cout << "\n";
}

void rand_seed(){  
   int seed = static_cast<int>(time(0));
   srand(seed);
}

int rand_int(int a, int b){  
   return a + rand() % (b - a + 1);
}

int main()
{  
   rand_seed();
   vector<int> v(20);
   for (int i = 0; i < v.size(); i++)
      v[i] = rand_int(1, 100);
   print(v);
   cout << "Enter number to search for: ";
   int n;
   cin >> n;
   int j = linear_search(v, n);
   cout << "Found in position " << j << "\n";
   return 0;
}
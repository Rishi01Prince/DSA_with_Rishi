#include <bits/stdc++.h>
using namespace std;

// Better : T -- O(n ) ; Auxi-- > O(1)
int IterativeMethod(int a)
{
  int ans = 1;
  for (int i = 1; i <= a; i++)
  {
    ans = ans * i;
  }
  return ans;
}

// T -- O(n ) ; Auxi-- > O(n)
int RecursiveMethod(int n)
{
  if (n == 0)
  {
    return 1;
  }
  return n * RecursiveMethod(n - 1);
}

int TrailingZero(int a)
{
  int Zero = 0;
  for (int i = 5; i <= a; i = i * 5)
  {
    Zero = Zero + (a / i);
  }
  return Zero;
}

// Works for Prime Number
int NoofPowercanhaveofX(int num, int X)
{
  int Power = 0;
  for (int i = X; i <= num; i = i * X)
  {

    Power = Power + (num / i);
  }
  return Power;
}

int main()
{
  int num, X;
  cin >> num;
  cin >> X;
  cout << IterativeMethod(num) << endl;
  cout << RecursiveMethod(num) << endl;
  cout << TrailingZero(num) << endl;
  cout << NoofPowercanhaveofX(num, X);

  return 0;
}
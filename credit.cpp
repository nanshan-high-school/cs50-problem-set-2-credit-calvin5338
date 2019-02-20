#include <iostream>
using namespace std;

int main() 
{
  long int cardnum;
  cout << "請輸入你的信用卡號:";
  cin >> cardnum;

  int sum = 0;
  int times = 0;
  string company = "";


  do {
    int digit = 0;
    digit = cardnum % 10; //取當前最後一位數
    cardnum /= 10; //去掉最後一位數

    //卡號剩前2位時, 判斷發卡公司
    if(cardnum >= 10 && cardnum <= 99) 
    {
      if(cardnum >= 40 && cardnum <= 49) 
      {
        company = "Visa Card";
      } 
      else if(cardnum >= 51 && cardnum <= 55) 
      {
        company = "Master Card";
      } 
      else 
      {
        company = "無效卡!";
      }
    }

    //奇數位時, 權重乘2
    if(times % 2 == 1)
    {
      digit *= 2;
    }

    //digit為2位數時, 相加
    if(digit >= 10)
    {
      int ones = digit % 10;
      int tens = digit / 10;
      digit = ones + tens;
    }

    //加總
    sum += digit;

    //換位數
    times += 1;
  } while(cardnum > 0);


  //驗證碼
  if (sum % 10 != 0)
  {
    cout << "無效卡";
  }
  else
  {
    cout << company;
  }
}

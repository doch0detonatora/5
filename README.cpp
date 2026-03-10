#include <cmath>
#include <iostream>
using namespace std;
class Clock{
protected: // Comment
  int seconds;
public:
  Clock(int h,int m,int s): seconds(s+m*60+h*3600){}
  int getH(){return seconds / 3600;}
  int getM(){return seconds % 3600 / 60;}
  int getS(){return seconds % 3600 % 60;}
  void print(){
    int h=getH(), m=getM(),s=getS();
    cout<<h/10<<h%10<<":"<<m/10<<m%10<<":"<<s/10<<s%10<<endl;
  }
};
class Timer: public Clock{
public:
  void tic(){
    if(seconds==0){
      cout<<"Done!\n";
      return;
    }
    seconds--; //вычитание
  }
  Timer(int h=0,int m=0,int s=0): Clock(h,m,s){}
};
int main() {
    int h, m, s, t;
    cin >> h >> m >> s >> t;
    Timer c(h, m, s);
    Clock anticheat(h, m, s); //Проверка, что описаны оба класса
    for (int i = 0; i < t; i++) {
        c.tic();
        c.print();
    }
    return 0;
}

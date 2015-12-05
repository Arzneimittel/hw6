#include <iostream>
#include <fstream>

using namespace std;


void K_Vektoren(double* k,const double a, const double b, const double c,double x, double y,double z){
     k[0] = a * (y-x); 
     k[1] = x * (b-z) -y;
     k[2] = x*y - c*z;
}
int main(void){
  const double t1=0.0,t2=100.0,dt=0.1,a=10,b=28,c=8/3;
  double x=1,y=1,z=1;
  const int N = ((t2-t1)/dt) +1 ;
  double k1[3],k2[3],k3[3],k4[3];
  ofstream out("kutta_0.1.txt");
  out << t1 << "\t" << x << "\t" << y << "\t" << z << endl;
  for(int i=1; i<N ;i++){
    K_Vektoren(k1,a,b,c,x,y,z);
    K_Vektoren(k2,a,b,c,x+((dt/2)*k1[0]),y+((dt/2)*k1[1]),z+((dt/2)*k1[2]));
    K_Vektoren(k3,a,b,c,x+((dt/2)*k2[0]),y+((dt/2)*k2[1]),z+((dt/2)*k2[2]));
    K_Vektoren(k4,a,b,c,x+((dt/1)*k3[0]),y+((dt/1)*k3[1]),z+((dt/1)*k3[2]));
    x+= (dt/6) * (k1[0] + 2*k2[0] + 2*k3[0] + k4[0]);
    y+= (dt/6) * (k1[1] + 2*k2[1] + 2*k3[1] + k4[1]);
    z+= (dt/6) * (k1[2] + 2*k2[2] + 2*k3[2] + k4[2]);
    out << i*dt << "\t" << x << "\t" << y << "\t" << z << endl;
  }
  out.close();
  return 0;
}
#include<cstdio>
#include<cmath>

using namespace std;

double f(int p, int q, int r, int s, int t, int u, double x){
  double p1 = (double) p*exp(-1);
  double q1 = (double) q*sin(x);
  double r1 = (double) r*cos(x);
  double s1 = (double) s*tan(x);
  double t1 = (double) t*pow(x,2);
  double u1 = (double) u;
  return (double) p1 + q1 + r1 + s1 + t1 + u1;
}

int main(){
  int p, q, r, s, t, u;
  double x;
  for(double k=0; k<=1; k = k + 0.00001){
    if(f(0,0,0,0,-2,1,k) == 0){
      printf("%f\n %f\n", k, f(0,0,0,0,-2,1,k));
    }
    //printf("%f -> %f\n", k, f(0,0,0,0,-2,-1,k));
  }

  
  return 0;
}
//0.7071

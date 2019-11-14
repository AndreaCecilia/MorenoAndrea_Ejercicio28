#include <iostream>
#include <cmath>

// Inicializo las funciones
float velx(float t, float y0, float y1, float z0, float z1); //Returns y0
float acelx(float t, float y0, float y1, float z0, float z1); //Returns  y1
float vely(float t, float y0, float y1, float z0, float z1); //Returns z0
float acely(float t, float y0, float y1, float z0, float z1); //Returns  z1
void rk4(float t, float dt, float & y0, float & y1,float & z0, float & z1);


const float k = 0.7;
const float g = -9.81;
const float dt = 0.01;

int main(void)
{
    float y0=10;
    float z0=10;
    float z1=0;
    float y1=0;
    for(int i=0;i<30; i+=dt){

    std::cout<<velx(i, y0, y1, z0, z1)<<" "<<acelx(i, y0, y1, z0, z1)<<" "<<vely(i, y0, y1, z0, z1)<<acely(i, y0, y1, z0, z1)<<std::endl;
    
    rk4(i, dt, y0, y1, z0, z1);
    }
    return 0;
}



float velx(float t, float y0, float y1, float z0, float z1)
{
  return y0;

  }//Returns y0
float acelx(float t, float y0, float y1, float z0, float z1){
  double v=sqrt(y0*y0+z0*z0);
  y1=-k*y0*y0/v;
  return y1;
} //Returns  y1
float vely(float t, float y0, float y1, float z0, float z1)
{
  return z0;
} //Returns z0
float acely(float t, float y0, float y1, float z0, float z1){
  double v=sqrt(y0*y0+z0*z0);
  z1=-g-k*z0*z0/v;
  return z1;
} //Returns  z1
void rk4(float t, float dt, float & y0, float & y1,float & z0, float & z1) // metodo de runge kutta 4 orden
{
  float k10,k11,k12,k13, k20, k21,k22,k23,k30, k31,k32,k33,k40, k41,k42,k43;
  k10 = dt*velx(t, y0, y1, z0, z1 );
  k11 = dt*acelx(t, y0, y1, z0,z1 );
  k12 = dt*vely(t, y0, y1, z0,z1 );
  k13 = dt*acely(t, y0, y1, z0,z1 );
  k20 = dt*velx(t+dt/2, y0 + k10/2, y1+ k11/2, z0+k12/2, z1+k13/2);
  k21 = dt*acelx(t+dt/2, y0 + k10/2, y1+ k11/2, z0+k12/2, z1+k13/2);
  k22 = dt*vely(t+dt/2, y0 + k10/2, y1+ k11/2, z0+k12/2, z1+k13/2);
  k23 = dt*acely(t+dt/2, y0 + k10/2, y1+ k11/2, z0+k12/2, z1+k13/2);
  k30 = dt*velx(t+dt/2, y0 + k20/2, y1+ k21/2, z0+k22/2, z1+k23/2);
  k31 = dt*acelx(t+dt/2, y0 + k20/2, y1+ k21/2, z0+k22/2, z1+k23/2);
  k32 = dt*vely(t+dt/2, y0 + k20/2, y1+ k21/2, z0+k22/2, z1+k23/2);
  k33 = dt*acely(t+dt/2, y0 + k20/2, y1+ k21/2, z0+k22/2, z1+k23/2);
  k40 = dt*velx(t + dt, y0 + k30, y1 + k31, z0 +k32, z1+k33);
  k41 = dt*vely(t + dt, y0 + k30, y1 + k31, z0 +k32, z1+k33);
  k42 = dt*acelx(t + dt, y0 + k30, y1 + k31, z0 +k32, z1+k33);
  k43 = dt*acely(t + dt, y0 + k30, y1 + k31, z0 +k32, z1+k33);
  y0 = y0 + (1.0/6.0)*(k10 + 2*k20 + 2*k30 + k40);
  y1 = y1 + (1.0/6.0)*(k11 + 2*k21 + 2*k31 + k41);
  z0 = z0 + (1.0/6.0)*(k12 + 2*k22 + 2*k32 + k42);
  z1 = z1 + (1.0/6.0)*(k13 + 2*k23 + 2*k33 + k43);
}
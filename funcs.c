#include<stdio.h>
#include<math.h>
#include"funcs.h"



static float vhh,omega_m,omega_l,omegabhsqr,coH0;
static float ZZ[1001],codis[1001],ZZ_spl[1001];

/*--------------------------------------------------------------------------------*/

void initialize_model(float omega_m1,float omegabhsqr1,float hh)
{
  int ii,jj;
  float zz;

  vhh=hh;
  omega_m=omega_m1;
  omegabhsqr=omegabhsqr1;

  for(ii=0;ii<=1000;ii++)
    {
      zz=(float)ii*.1; // for redshift 0 to 100=1000*.1
      ZZ[ii]=zz;
      codis[ii]=rnu(1420./(1.+zz));
    }
}

/*--------------------------------------------------------------------------------*/

/*calculate conformal distance (r(\nu) )for given observed frequency(in MHz)*/

float rnu(float nu)
{
  float func(float x);
  float y;

  coH0=3.e3/vhh;    /*coH0 =c/H_0 in terms of Mpc*/

  y=simp(func,1000,nu/1420.,1.);
  y=y*coH0; 
  return(y);
}

/*--------------------------------------------------------------------------------*/

float func( float x)
{
  return(pow(func_E(x)*x*x,-1.));
}

/*--------------------------------------------------------------------------------*/

float func_E(float x)
{
  /*----------------Returns E= H/H_0------------*/ 
  float tt;
  omega_l=1.-omega_m;

  tt=omega_m*pow(x,-3)+omega_l;
  return(sqrt(tt));
}

/*--------------------------------------------------------------------------------*/

/* This function does integration using simpson's rule */

float simp(float (*func)(float),int n,float a,float b)
{      
        int i;
        float y=0.0;
        float sump,sumq,sumr,h;
        h = (b-a)/(1.0*n); 
        sump = func(a)+func(b);
	sumq=0.0;
	sumr=0.0;
	for(i=1;i<n;i+=2)
           {          
	     sumq=sumq+func(a+i*h);
            }
	for(i=2;i<n-1;i+=2)
          {
	    sumr=sumr+func(a+i*h);
	  }
	y=h*(sump + 4*sumq+ 2*sumr)/3.0 ;

      return(y);
}

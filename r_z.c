#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#include<fftw3.h>
#include"funcs.h"


int main()
{
  FILE *fp, *fp1;
  
  float z_start,z_end, *z;
  
  float omegam,omegabh2,hh,r_zstart,codis,zz;
  
  int Nz, ii=0;

  /*--------------------------------------------------------------------------------*/
  
  /*read input from file*/
  fp=fopen("input","r");
  
  fscanf(fp,"%f%f%f",&omegam,&omegabh2,&hh);
  fscanf(fp,"%d",&Nz);

  z=(float*)calloc(Nz,sizeof(float)); // array to store Noutput
  
  for(ii=0;ii<Nz;ii++)
    fscanf(fp,"%f",&z[ii]);
  
  fclose(fp);
  
  /*--------------------------------------------------------------------------------*/
  
  initialize_model(omegam,omegabh2,hh);

  printf("%d\n", Nz);
  for(ii=0;ii<Nz;ii++)
    {
      //z=z_start+ii*0.0001;
      r_zstart=rnu(1420./(1.+z[ii])); // distance at z_start
      printf("%f\t%f\n", z[ii], r_zstart);
    }
}

typedef struct {
  float re;
  float im;
}complex;

#define pi 3.1416

void initialize_rho_d();
void initialize_filter(float Rf1,float nuf1,int ch_lower_end1,int ch_uper_end1);
void initialize_filter_sim();
float filter_amp(float u,float delnu);
complex filter(float u,float v,float thetax,float thetay,float delnu);
complex filter_matched(float u,float v,float thetax,float thetay,float delnu);
float check_filter_amp();
float S_nu(float nu);
float *vectorDD(long nl, long nh);
void free_vectorDD(float *v, long nl, long nh);
void nrerrorDD(char error_text[]);
void splineDD(float x[], float y[], int n, float yp1, float ypn, float y2[]);
void splintDD(float xa[], float ya[], float y2a[], int n, float x, float *y);


void initialize_model(float omega_m1,float omegabhsqr1,float hh);
float rnu(float nu);
float func( float x);
float func_E(float x);
float r2z(float x);
float Inu0(float z,float xbarh1);
float rnup(float nu);
float simp(float (*func)(float),int n,float a,float b);
float  simp_2d(float (*func_2d)(float,float),int n1,float a1,float b1);
float rho_d_spl(float d);
float rho_U(float U,float nu);
float func_rho_U(float U,float nu);

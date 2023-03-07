#ifndef _MY_LIB_U_
#define _MY_LIB_U_

#include <math.h>
#include "osqp/osqp.h"
#include <Eigen/Eigen>
#include <stdlib.h>


/*******************************************/
/*  combine two matrices as raw  */
/*******************************************/

void csc_combine(c_int A_nzmax, c_int A_n, c_int A_m, c_int* A_p, c_int* A_i, c_float* A_var,
    c_int B_nzmax, c_int B_n, c_int B_m, c_int* B_p, c_int* B_i, c_float* B_var,
     c_int& C_nzmax, c_int& C_n, c_int& C_m, c_int  p[], c_int ii[], c_float var[]){
    if (A_n != B_n) 
    {
        ROS_ERROR_STREAM("Conbine error!\n");
    }
    C_n = A_n;
    C_m = A_m + B_m;
    C_nzmax = A_nzmax + B_nzmax;
    p[0] = 0;    
    for (size_t i = 0; i < C_n; i++)
    {
        p[i+1] = A_p[i+1] + B_p[i+1];
    }
    int index = 0;
    for (size_t i = 0; i < C_n; i++)
    {
        
        for (size_t j = 0; j < A_p[i+1]-A_p[i]; j++)
        {
            
            var[index]  = A_var[A_p[i]+j];
            ii[index]   = A_i[A_p[i]+j];
            index ++;
        }
        for (size_t j = 0; j < B_p[i+1]-B_p[i]; j++)
        {
           
            var[index]  = B_var[B_p[i]+j];
            ii[index]   = B_i[B_p[i]+j] + A_m;
            index ++;
        }
    }
}

/*******************************************/
/*  combine two matrices as diag */
/*******************************************/

bool csc_diag_combine(c_int A_nzmax, c_int A_n, c_int A_m, c_int* A_p, c_int* A_i, c_float* A_var,
    c_int B_nzmax, c_int B_n, c_int B_m, c_int* B_p, c_int* B_i, c_float* B_var,
     c_int& C_nzmax, c_int& C_n, c_int& C_m, c_int  C_p[], c_int C_i[], c_float C_var[]){
    C_n = A_n + B_n;
    C_m = A_m + B_m;
    C_nzmax = A_nzmax + B_nzmax;
    for (size_t i = 0; i < C_nzmax; i++)
    {
        if (i < A_nzmax)
        {
            C_var[i] = A_var[i];
            C_i[i]   = A_i[i];
        }
        else
        {
            C_var[i] = B_var[i - A_nzmax];
            C_i[i]   = B_i[i - A_nzmax] + A_m;
            // printf("i = %d\n",i);
            // printf("C_var[i] = %f\n",C_var[i]);
        }
    }
    for (size_t i = 0; i < C_n + 1; i++)
    {
        if (i < A_n + 1)
        {
            C_p[i] = A_p[i];
        }
        else
        {
            C_p[i] = C_p[i - 1] + B_p[i - A_n ] - B_p[i - A_n -1];
            // printf("C_p[i]=%d\n",C_p[i]);
        }
    }
}

/*******************************************/
/*  printf CSC  matrix */
/*******************************************/

bool csc_show(csc* C){
    c_float temp = 0;
    // c_float aaaaaa[18][18];
    for (size_t i = 0; i < C->m; i++)
    {
        for (size_t j = 0; j < C->n; j++)
        {
            temp = 0;
            for (size_t t = 0; t < C->p[j+1]-C->p[j]; t++)
            {
                if (i==C->i[C->p[j]+t])
                {
                    temp = C->x[C->p[j]+t];
                } 
            }
           printf("%f\t",temp);//  printf("%d\t",C->p[j+1]-C->p[j]);// 
        //    aaaaaa[i][j] = temp;
        }
        printf("\n");
    }
    // printf("aaaaaa[14][13]=%f\n",aaaaaa[14][13]);
    return 1;
}

bool vector_show(c_float vec[], c_int size){
    for (size_t i = 0; i < size; i++)
    {
        printf("%f\n",vec[i]);
    }
    return 1;
}

bool fvector_show(float vec[], int size){
    for (size_t i = 0; i < size; i++)
    {
        printf("%f\n",vec[i]);
    }
    return 1;
}

bool dvector_show(double vec[], int size){
    for (size_t i = 0; i < size; i++)
    {
        printf("%f\n",vec[i]);
    }
    return 1;
}

/*******************************************/
/*       factorial                  	   */
/*******************************************/
int fac(int n)
{
	int f;
	if(n<0)
		printf("n<0,data error!");
	else if(n==0||n==1)
		f=1;
	else
		f=fac(n-1)*n;
	return(f);
}

/*******************************************/
/*  calculate distance between two point  */
/*******************************************/

float distance(Eigen::Vector3d point1,Eigen::Vector3d point2){
    return sqrt(     (point2(0)-point1(0))*(point2(0)-point1(0)) 
    +  (point2(1)-point1(01))*(point2(1)-point1(1))  
    +  (point2(2)-point1(2))*(point2(2)-point1(2))    );
}

/*******************************************/
/*  copy csc   */
/*******************************************/
void csc_copy(c_int B_nzmax, c_int B_n, c_int B_m, c_int* B_p, c_int* B_i, c_float* B_var,
        c_int& C_nzmax, c_int& C_n, c_int& C_m, c_int  C_p[], c_int C_i[], c_float C_var[]){
    C_nzmax = B_nzmax;
    C_n     = B_n;
    C_m     = B_m;
    for (size_t i = 0; i < C_n+1; i++)
    {
        C_p[i] = B_p[i];
    }
    for (size_t i = 0; i < C_nzmax; i++)
    {
        C_i[i] = B_i[i];
        C_var[i] = B_var[i];
    }
}

/*******************************************/
/*    Creation of integer vector 	   */
/*******************************************/
int *intVector(int n)
{
		//_CrtDumpMemoryLeaks();
		// _CrtSetBreakAlloc(147); 
	//int *vec = (int*)malloc(n*sizeof(int));
	int *vec = NULL;
	vec = (int*)malloc(5*n*sizeof(int));
	return(vec);
}

/*********************************************/
/* 	Create a double Vector		     */
/*********************************************/
double *doubleVector(int n){
	double *vec = (double*)malloc(5*n*sizeof(double));
	return(vec);
}

/*********************************************/
/* 	Create a c_int Vector		     */
/*********************************************/
c_int *c_intVector(int n){
	c_int *vec = (c_int*)malloc(n*sizeof(c_int));
	return(vec);
}


/*********************************************/
/* 	Create a c_float Vector		     */
/*********************************************/
c_float *c_floatVector(int n){
	c_float *vec = (c_float*)malloc(n*sizeof(c_float));
	return(vec);
}

/*******************************************/
/*    Creation of integer MATRIX 	   */
/*******************************************/
int **intMatrix(int n,int m){
	int i;
	int **mat = (int**) malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		mat[i] = (int*) malloc(m*sizeof(int));
	return(mat);
}


/*********************************************/
/* 	Create a double MATRIX		     */
/*********************************************/
double **doubleMatrix(int n,int m){
	int i;
	double **mat = (double**) malloc(n*sizeof(double*));
	for(i=0;i<n;i++)
		mat[i] = (double*) malloc(m*sizeof(double));
	return(mat);
}


/*********************************************/
/*  	Free integer matrix			  */
/*********************************************/
void freeIntMat(int **mat,int n,int m){
	/* the column size is not used but is required only
	for debugging purpose
	*/
	int i;
	for(i=0;i<n;i++)
		free(mat[i]);
	free(mat);
}

/*********************************************/
/*   	Free double matrix			  */
/*********************************************/
void freeDoubleMat(double **mat,int n,int m){
	/* the column size is not used but is required only
	for debugging purpose
	*/
	int i;
	for(i=0;i<n;i++)
		free(mat[i]);
	free(mat);
}

// ▼这个函数还存在问题会出现段错误，还不能用
void fullMatrix2CSC(Eigen::MatrixXd& Jacob_, csc* csc_matrix){
     int m = Jacob_.rows();
     int n = Jacob_.cols();
     c_int csc_max_num = n*m;
     c_float* csc_var =  c_floatVector(n*m);
     c_int*   csc_row = c_intVector(n*m);
     c_int*   csc_col = c_intVector(n+1);
     csc_col[0] = 0;
     for (size_t i = 0; i < n; i++)//列
     {
        for (size_t j = 0; j < m; j++)// 行
        {
            csc_var[i*m + j] = Jacob_(j,i);
            csc_row[i*m + j] = j;
        }
        csc_col[i+1] = m*(i+1);
     }
     csc_matrix->m = m;
     csc_matrix->n = n;
     csc_matrix->nzmax = csc_max_num;
     csc_matrix->x = csc_var;
     csc_matrix->p = csc_col;
     csc_matrix->i = csc_row;
}

c_float max_3(c_float x1, c_float x2, c_float x3){
    c_float x =x1;
    if (x< x2)
    {
       x = x2;
    }
    if (x< x3)
    {
       x = x3;
    }
    return x;
}
c_float min_3(c_float x1, c_float x2, c_float x3){
    c_float x =x1;
    if (x > x2)
    {
       x = x2;
    }
    if (x > x3)
    {
       x = x3;
    }
    return x;
}


#endif

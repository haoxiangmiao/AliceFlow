// ���� my_linalg.h:
// ����������� ���������� ��������� 
// ���������� �������� �������.
// ������ v0.01 ���� 2011
// ������������� ������� ���� ������� �������� �������.
// 1. (��������) ������� ����.
// 2. (��������� ��������) �������� ���������� �� � ��.
// ------------------------------------------------------
// ��������� � ������� ����.
// ���������������: 
// a) ������� � ����������� �������.
// b) ������������ � ��������������.
// ��� ����������� �������:
// ������� �������������� ������ ��������������. (������������ ������������ ������������).
// ��� ����� ������������� ������, � ������� ������� � �����
// ���������� ���������� �������� ����������� �������������������.
// ����������� ��������� ��������� �������� �������� ����������� ������ 
// � ������� �������������� ����� ��������� (������ �������������� ������������)
// ��� �������������� (� ������ ����� ��������� ����� ��������� �������� ����������� 
// ������ ) ������������ ������� �������� �������  ����� � ���������� ��������, ���
// ������������ �� ������, �� ���������� �� ��������������.

#include "sparse_gauss.c" // ����� ������ ��� ����������� �������
// ��� �������
// calculateSPARSEgaussArray - ������ ����������� ���� ������� ���������� ������.
// initIMatrix - ��������� ����������� ������.
// setValueIMatrix, addValueIMatrix - ��������� � ���������� �������� � ����������� �������.

//#define doublereal double

// ��� ����������� �������� ����������� �������:
// ��������� ������� ������� ����:
typedef struct tagNONZEROELEM {
	doublereal aij;
	integer key; // ����� �������
    struct tagNONZEROELEM* next; // ��������� �� ��������� ������� � ������
} NONZEROELEM; 

// ��� ��������� �������� �������
typedef struct tagSIMPLESPARSE {
	// ������ ����������
   NONZEROELEM** root; // ������ ��������� ��������� ������ ������
   integer n; // ����� ��������� ���������
   //integer POOL_SIZE; // ������ ������� ��������� ���������:
   // n - ��������, POOL_SIZE - ������ �� ������.
   //integer incCLUSTER_SIZE; // ��� ��������� ������
} SIMPLESPARSE;

// ���� ������ ������� ����
typedef struct Tequation {
	doublereal ap, ae, an, aw, as, b;
	integer iP, iE, iN, iW, iS;
} equation;


// ������ ���� ������� ���������� ������
// ��� ������ �������� �������� � ��� 
// ����� ������������� �������.
// �������� ��� �������������� ������� A nodes*nodes.
void eqsolve_simple_gauss(doublereal **A, integer nodes, doublereal *b, doublereal *x);

// ������ ���� ������� ���������� ����������
// ������� ����������� ������ ���� ������������.
// ��� ����� ������������� �������. ��������������
// ������� ����� ������� � �� ��������� ��� �����.
// �� �������������� � ������ � ��� ���� ����������� 
// ������ ���������� ������.
// ��. ������ ���������� � �������: ��� ��� ��������������
// � ��������� ����������. 1986 ���.
void eqsolv_simple_holesskii(doublereal **A, integer nodes, doublereal *b, doublereal *x);

// ������� �������� ������� �������
// ���������� ������. ���������� � ������������ ���� 
// �������� ������ ���� ���.
// ������� A �������� � � �� ������������ �������� �������.
void inverse_matrix_simple(doublereal** &A, integer nodes, bool flag);

// ������� ������������ ���� ����������
// ������ nodes*nodes C=A*B. ��������� 
// ������������ � ������� B.
void multiply_matrix_simple(doublereal **A1, doublereal **A2, integer nodes);

// ��������� ��������� ������� ������������ ��� ��������������� ��� �������
// ������ �������� ����������� ��������:

// 1. ��������� ���������� ������ ������� n*n:
//              t=m*p.
// �� ��������� ������ ��������� �������� � ������� t. 
void multi_m(doublereal **m, doublereal **p, doublereal **t, integer n);

// 2. ���������������� ���������� ������� m ��������
// n*n. �� ��������� ������ ��������� ����������������
// �������� � m.
void tr_m(doublereal **m, integer n);

// 3. ���������� ������������ ���������������
// ������� ��� ������������ ������� A �������� 
// n*n. ������� ������������� �������� A[f][g].
doublereal max_el(doublereal **A, integer n, integer& f, integer& g);

// 4. �������� ������ ������� � ������: A=B.
// ������� ���������� �������� n*n
void matr_copy(doublereal **A1, doublereal **A2, integer n);

// 5. ������� ��������� ���� ���������� ������ ������������ 
// ���� ������� n*n (����� ���������):
//                A=hi*A.
// ����� hi - �������������� ������� ��������:
// hi[f][f] = cosfi;
// hi[g][g] = cosfi;
// hi[f][g] = +sinfi;
// hi[g][f] = -sinfi;
// ����� f � g ������� ��������� ���������.
// ��������� ���������� � ����.
// �� ��������� ������ ��������� �������� � �������� ������� A.
// ������ ������� hi� ��������� ������ ��� ���� ������ ������ ��������
// (cosfi � sinfi), ��� ��������� ����������� ��������� ������ � ��������������.
// rab - ������� ������ ����������� 2*n. �� ������������ ��� �������� ���������.
void multi_m_left(doublereal **A, doublereal **rab, integer n, integer f, integer g, doublereal cosfi, doublereal sinfi);

// 6. ������� ��������� ���� ���������� ������ ������������ 
// ���� ������� n*n (������ ���������):
//                A=A*hi.
// ����� hi - �������������� ������� ��������:
// hi[f][f] = cosfi;
// hi[g][g] = cosfi;
// hi[f][g] = -sinfi;
// hi[g][f] = +sinfi;
// ����� f � g ������� ��������� ���������.
// ��������� ���������� � ����.
// �� ��������� ������ ��������� �������� � �������� ������� A.
// ������ ������� hi ��������� ������ ��� ���� ������ ������ ��������
// ��� ��������� ����������� ��������� ������ � ��������������.
// rab - ������� ������ ����������� 2*n. �� ������������ ��� �������� ���������.
void multi_m_right(doublereal **A, doublereal **rab, integer n, integer f, integer g, doublereal cosfi, doublereal sinfi); 
   
// ������� �������� ������ ������ �������� �� � ����
//      A-lambda_scal*E=0
// ������� ���������� �������� � �� �������� ������������,
// ��� �������� ��������������� ��������� epsilon.
void jacobi_matrix_simple(doublereal **A, doublereal **U, doublereal *lambda, integer nodes, doublereal epsilon);

// ����������� ����������.
void BubbleSortGSEP1(doublereal *a, integer *mask, integer n);

// ������ ���������� ������������ �������� ����������� ��������
//   GSEP1: 
void GSEP1(doublereal **A1, doublereal **A2, doublereal **U, doublereal *lambda, integer *mask, integer nodes, doublereal epsilon);

// ����� ������ ��� ��������� ������� A ��������
//              nodes x 2*icolx+1, ���
//   2*icolx+1 - ������ �����. ��� ��� ��� �������
//  A ��������� ���������� �� ��� ��������� ��������
//  ������� ���������� ������ ������ �����.
//  b - ������ ������ ����� ����, x - ������ �������.
//  ��������� ��������� ���������� � ����.
//  ��� ������������ ����������� �������� ��������������
//  ������ �, ������� �������� ����� ������.
//  ����� ���� ������� 1777-1855.
//  � ���������� ������ ������� � ��������.
//  ��� ����������� ��������� �� ��������� � ���
//  ������ ����� ����� ���� ������ ��� nodes 
//  ����� � ��� ���� ������� ������������� ��������� ���������� 
//  � ���� ������ ������������ (����������), ���� �� ��������� 
//  ����������� �������� ���������� ������ �����.
void eqsolve_lenta_gauss(doublereal **A, integer nodes, integer icolx, doublereal *b, doublereal *x);

// ����� (�����) ������-������� ����������-������� SOR
// ��� ������� ���� � ������� �������� � n*n
// �������� ��������������, �� � ������������ 
// �������������. ������� � ��������������
// ��������� ����������� (�������������).
// b - ������ �����, x - ���������� �������, 
// eps - �������� ����������� �������.
// omega - ����������� ����������� �������� ����������.
void Seidel(doublereal **A, doublereal *b, doublereal *x, integer n, doublereal eps, doublereal omega);

// ���������� ������������ �� ���� 
// ������������ �����.
//doublereal fmax(doublereal fA, doublereal fB);

// ����������� ��� ��������� �������� �������� 
// � ������ ����� �� ���� ������� ����� ������� �������.
// �������� ���������� ����� � ����� ���������,
// ������� ���� ����� ������������ �������.
void SOR(equation* &sl, doublereal* &x, integer n);


// ����������� ��� ��������� �������� �������� 
// � ������ ����� �� ���� ������� ����� ������� �������.
// �������� ���������� ����� � ����� ���������,
// ������� ���� ����� ������������ �������.
void SOR3D(equation3D* &sl, equation3D_bon* &slb, doublereal* &x,  doublereal* x_cor, integer maxelm, integer maxbound, integer iVar, doublereal alpha);

// ����� ���������� ����������
// ��� ����� ������������� ������� ����.

// ��������� ������� �� ������
doublereal* MatrixByVector(doublereal** H,doublereal* V,integer n);

// ��������� ����� �������
// ��� ���������� ������ �������� ������� �������������������� ������� 1.0e-4
// �������� ���������� ������ �� CFX �� �������.
// ���� ����� �������� �� ������� ���������� ����� 1.0e-3.
// �������� ����� �� ������ �� CFX.
doublereal NormaV(doublereal *V, integer n);

// ��������� ������������ ���� ��������
doublereal Scal(doublereal *v1, doublereal *v2, integer n);

//----------����� ����������� ����������---------------
/* ������� ���������:
*  A - ������������� ������� ����,
*  dV - ������ ������ �����, 
*  x - ��������� ����������� � ������� ��� NULL.
*  n - ����������� ���� An*n.
*  ������� A ���������� ������������ ����������� � 
*  ������������ (������������ ������������ ������������).
*  ���������� �������� ���������� 1000, �.�. ��������������,
*  ��� ���� ������� �� ������� �� 1000 �������� �� ��� � �� �������.
*  �������� ������ �� ������� ������� � ���������� ���������:
*  dterminatedTResudual.
*/
doublereal *SoprGrad(doublereal **A, doublereal *dV, doublereal *x, integer n);

// ����������� ������������ ������������ ����������� ������� 
// � CRS ������� ��������:

// ��������� ������� �� ������
// ������������ ������ �������� CRS
// ����������� ������� A (val, col_ind, row_ptr) ���������� �������� n*n.
// ����� ��������� ����� ����� ����������� � ����� n.
void MatrixCRSByVector(doublereal* val, integer* col_ind, integer* row_ptr, doublereal* V, doublereal* &tmp, integer n);

// ��������� ����������������� ������� �� ������
// (������������, ��������, � ������ BiCG - ������������ ����������)
// ��� �������� (�� ����������������� �������) ������������ ������ �������� CRS
// ����������� ������� A (val, col_ind, row_ptr) ���������� �������� n*n.
// ����� ��������� ����� ����� ����������� � ����� n.
doublereal* MatrixTransposeCRSByVector(doublereal* val, integer* col_ind, integer* row_ptr, doublereal* V, integer n);


/* ������� ���������:
*  val, col_ind, row_ptr - ����������� ������� ���� � ������� CRS,
*  dV - ������ ������ �����, 
*  x - ��������� ����������� � ������� ��� NULL.
*  n - ����������� ���� An*n.
*  ����������� ������� A (val, col_ind, row_ptr) ���������� �������� n*n.
*  ����� ��������� ����� ����� ����������� � ����� n.
*  ������� A ���������� ������������ ����������� � 
*  ������������ (������������ ������������ ������������).
*  ���������� �������� ���������� 1000, �.�. ��������������,
*  ��� ���� ������� �� ������� �� 1000 �������� �� ��� � �� �������.
*  �������� ������ �� ������� ������� � ���������� ���������:
*  dterminatedTResudual.
*/
doublereal *SoprGradCRS(doublereal *val, integer* col_ind, integer* row_ptr, doublereal *dV, doublereal *x, integer n);

// ����� ������������ ����������
// ��� �������� �������������� ������� � (val, col_ind, row_ptr).
// ����������������� �� ������ ��������, ������: "������
// ������� ���� ������� �����������".
// dV - ������ ����� ����,
// x - ��������� ����������� � ������� ��� NULL.
// n - ����������� � n*n.
// ���������� �������� ���������� 2000.
// �������� ������ �� ������� ������� � ���������� ���������:
//  dterminatedTResudual.
void BiSoprGradCRS(doublereal *val, integer* col_ind, integer* row_ptr, doublereal *dV, doublereal* &x, integer n, integer maxit);

// ������ ��� �� ����������� ���������������� ������� L.
// ������������ ������������ ����������� �������
// ���� A ������������ �������� ����������� ��������� 
// A~=L*transpose(L); L - ������ ����������� �������.
// L - �������� � ��������� ����:
// 1. ldiag - ������������ �������� L.
// 2. lltr - ��������������� �������� � �������� �������,
// �.�. �������� ����������. 
// 3. jptr - ��������������� ������ �������� ��� lltr, 
// 4. iptr - ���������� � ������ ��������� ������ ��� lltr.
// f - ������ ������ ����� �������� nodes.
// ���������� ������ z=inverse(L)*f;
// ������ f ��������.
// ������ (CSIR - ������):
//  L = 
//  9.0   0.0   0.0   0.0   0.0   0.0   0.0   
//  0.0   11.0   0.0   0.0   0.0   0.0   0.0   
//  0.0   2.0   10.0   0.0   0.0   0.0   0.0   
//  3.0   1.0   2.0   9.0   0.0   0.0   0.0   
//  1.0   0.0   0.0   1.0   12.0   0.0   0.0   
//  0.0   0.0   0.0   0.0   0.0   8.0   0.0   
//  1.0   2.0   0.0   0.0   1.0   0.0   8.0   
// ------------------------------------------
// ldiag: 9.0 11.0 10.0 9.0 12.0 8.0 8.0
// lltr: 2.0 3.0 1.0 2.0 1.0 1.0 1.0 2.0 1.0
// jptr: 1 0 1 2 0 3 0 1 4
// iptr: 0 0 0 1 4 6 6 9
//-------------------------------------------
doublereal* inverseL(doublereal* f, doublereal* ldiag, doublereal* lltr, integer* jptr, integer* iptr, integer n);

// ������ ��� �� ����������� ���������������� ������� L.
// ������������ ������������ ����������� �������
// ���� A ������������ �������� ����������� ��������� 
// A~=L*transpose(L); L - ������ ����������� �������.
// L - �������� � ��������� ����:
// 1. val - ������������ � ��������������� �������� L.
// � ���������� �������. 
// 3. indx - ��������������� ������ ����� ��� val, 
// 4. pntr - ���������� � ������ ���������� �������.
// f - ������ ������ ����� �������� nodes.
// ���������� ������ z=inverse(L)*f;
// ������ f ��������.
// ������ (CSIR - ������):
//  L = 
//  9.0   0.0   0.0   0.0   0.0   0.0   0.0   
//  0.0   11.0   0.0   0.0   0.0   0.0   0.0   
//  0.0   2.0   10.0   0.0   0.0   0.0   0.0   
//  3.0   1.0   2.0   9.0   0.0   0.0   0.0   
//  1.0   0.0   0.0   1.0   12.0   0.0   0.0   
//  0.0   0.0   0.0   0.0   0.0   8.0   0.0   
//  1.0   2.0   0.0   0.0   1.0   0.0   8.0   
// ------------------------------------------
// val: 9.0 3.0 1.0 1.0 11.0 2.0 1.0 2.0 10.0 2.0 9.0 1.0 12.0 1.0 8.0 8.0
// indx: 0 3 4 6 1 2 3 6 2 3 3 4 4 6 5 6
// pntr: 0 4 8 10 12 14 15 16
//-------------------------------------------
void inverseL_ITL(doublereal* f, doublereal* val, integer* indx, integer* pntr, doublereal* &z, integer n);

// �������� ��� �� ����������� ����������������� ������� U.
// ������������ ������������ ����������� �������
// ���� A ������������ �������� ����������� ��������� 
// A~=L*transpose(L); L - ������ ����������� �������.
// U=transpose(L);
// U - �������� � ��������� ����:
// 1. udiag - ������������ �������� U.
// 2. uutr - ��������������� �������� � ���������� �������,
// �.�. �������� ������������. 
// ��� ������� �����������, ��:
// 3. jptr - ��������������� ������ �������� ��� lltr, 
// 4. iptr - ���������� � ������ ��������� ������ ��� lltr.
// f - ������ ������ ����� �������� nodes.
// ���������� ������ z=inverse(U)*f;
// ������ f ��������.
// ������ (CSIR - ������):
//  U=transpose(L) = 
//  9.0   0.0   0.0   3.0   1.0   0.0   1.0   
//  0.0   11.0   2.0   1.0   0.0   0.0   2.0   
//  0.0   0.0   10.0   2.0   0.0   0.0   0.0   
//  0.0   0.0   0.0   9.0   1.0   0.0   0.0   
//  0.0   0.0   0.0   0.0   12.0   0.0   1.0   
//  0.0   0.0   0.0   0.0   0.0   8.0   0.0   
//  0.0   0.0   0.0   0.0   0.0   0.0   8.0   
// ------------------------------------------
// udiag==ldiag: 9.0 11.0 10.0 9.0 12.0 8.0 8.0
// uutr==lltr: 2.0 3.0 1.0 2.0 1.0 1.0 1.0 2.0 1.0
// jptr: 1 0 1 2 0 3 0 1 4
// iptr: 0 0 0 1 4 6 6 9
//-------------------------------------------
doublereal* inverseU(doublereal* f, doublereal* udiag, doublereal* uutr, integer* jptr, integer* iptr, integer n);

// �������� ��� �� ����������� ����������������� ������� U.
// ������������ ������������ ����������� �������
// ���� A ������������ �������� ����������� ��������� 
// A~=L*transpose(L); L - ������ ����������� �������.
// U=transpose(L); - ������� ����������� �������.
// U - �������� � ��������� ����:
// 1. val - ������������ � ��������������� �������� U (� ��������� �������).
// 2. indx - ��������������� ������ ��������, 
// 3. pntr - ���������� � ������ ��������� ������ ��� val.
// f - ������ ������ ����� �������� nodes.
// ���������� ������ z=inverse(U)*f;
// ������ f ��������.
// ������ (CSIR_ITL - ������):
//  U=transpose(L) = 
//  9.0   0.0   0.0   3.0   1.0   0.0   1.0   
//  0.0   11.0   2.0   1.0   0.0   0.0   2.0   
//  0.0   0.0   10.0   2.0   0.0   0.0   0.0   
//  0.0   0.0   0.0   9.0   1.0   0.0   0.0   
//  0.0   0.0   0.0   0.0   12.0   0.0   1.0   
//  0.0   0.0   0.0   0.0   0.0   8.0   0.0   
//  0.0   0.0   0.0   0.0   0.0   0.0   8.0 
// ------------------------------------------
// val: 9.0 3.0 1.0 1.0 11.0 2.0 1.0 2.0 10.0 2.0 9.0 1.0 12.0 1.0 8.0 8.0
// indx: 0 3 4 6 1 2 3 6 2 3 3 4 4 6 5 6
// pntr: 0 4 8 10 12 14 15 16
//-------------------------------------------
void inverseU_ITL(doublereal* f, doublereal* val, integer* indx, integer* pntr, doublereal* &z, integer n);

// ��������� �� ������� CSIR � ������ CSIR_ITL
// �������:
// CSIR: ldiag, lltr, jptr, iptr
// CSIR_ITL: val, indx, pntr
// ������:
// A = 
// 9.0   0.0   0.0   3.0   1.0   0.0   1.0    
// 0.0   11.0   2.0   1.0   0.0   0.0   2.0    
// 0.0   2.0   10.0   2.0   0.0   0.0   0.0    
// 3.0   1.0   2.0   9.0   1.0   0.0   0.0    
// 1.0   0.0   0.0   1.0   12.0   0.0   1.0    
// 0.0   0.0   0.0   0.0   0.0   8.0   0.0    
// 1.0   2.0   0.0   0.0   1.0   0.0   8.0 
// ------------------------------------------
// ������ CSIR:
// ldiag: 9.0 11.0 10.0 9.0 12.0 8.0 8.0
// lltr: 2.0 3.0 1.0 2.0 1.0 1.0 1.0 2.0 1.0
// jptr: 1 0 1 2 0 3 0 1 4
// iptr: 0 0 0 1 4 6 6 9
//-------------------------------------------
//��������� ����������� ������ CSIR_ITL
//val: 9.0 3.0 1.0 1.0 11.0 2.0 1.0 2.0 10.0 2.0 9.0 1.0 12.0 1.0 8.0 8.0 
//indx: 0 3 4 6 1 2 3 6 2 3 3 4 4 6 5 6 
//pntr: 0 4 8 10 12 14 15 16 
//--------------------------------------------
void convertCSIRtoCSIR_ITL(doublereal *ldiag, doublereal *lltr, integer *jptr, integer *iptr, integer n, integer nz, doublereal* &val, integer* &indx, integer* &pntr, integer nnz);

// �������� ���������� ���������
// ��� ������������ ����������� ������������
// ������� � �������� n*n.
// n - ����������� ������� ����
// ������� val ���������� � � ��� ������������
// �������� ���������� ��������� IC(0).
// ������:
// A = 
// 9.0   0.0   0.0   3.0   1.0   0.0   1.0    
// 0.0   11.0   2.0   1.0   0.0   0.0   2.0    
// 0.0   2.0   10.0   2.0   0.0   0.0   0.0    
// 3.0   1.0   2.0   9.0   1.0   0.0   0.0    
// 1.0   0.0   0.0   1.0   12.0   0.0   1.0    
// 0.0   0.0   0.0   0.0   0.0   8.0   0.0    
// 1.0   2.0   0.0   0.0   1.0   0.0   8.0 
//������ CSIR_ITL (������� ����������� �������� ���������).
// val: 9.0 3.0 1.0 1.0 11.0 2.0 1.0 2.0 10.0 2.0 9.0 1.0 12.0 1.0 8.0 8.0 
// indx: 0 3 4 6 1 2 3 6 2 3 3 4 4 6 5 6 
// pntr: 0 4 8 10 12 14 15 16 
//--------------------------------------------
// ��������� ������������ ��� ����������:
// ���������� ������ val (indx � pntr �������� ��� ���������):
// val (factorization)= 
// 3.0
// 1.0
// 0.3333333333333333
// 0.3333333333333333
// 3.3166247903554
// 0.6030226891555273
// 0.30151134457776363
// 0.6030226891555273
// 3.1622776601683795
// 0.6324555320336759
// 2.932575659723036
// 0.34099716973523675
// 3.4472773213410837
// 0.2578524458667825
// 2.8284271247461903
// 2.7310738989293286
//-------------------------------------------
void IC0Factor_ITL(doublereal* val, integer* indx, integer* pntr, integer n);

// ���������������� �������� ���������� ���������.
// (���������� ������� IC0Factor_ITL).
void IC0FactorModify_ITL(doublereal* val, integer* indx, integer* pntr, integer n);

// ��������� �� ������� CSIR_ITL � ������ CSIR (�������� ��������������)
// ������ ��� ��� ������� �������������� ���������� �������!!!
// �������:
// CSIR_ITL: val, indx, pntr
// CSIR: ldiag, lltr, jptr, iptr
// ������:
// A = 
// 9.0   0.0   0.0   3.0   1.0   0.0   1.0    
// 0.0   11.0   2.0   1.0   0.0   0.0   2.0    
// 0.0   2.0   10.0   2.0   0.0   0.0   0.0    
// 3.0   1.0   2.0   9.0   1.0   0.0   0.0    
// 1.0   0.0   0.0   1.0   12.0   0.0   1.0    
// 0.0   0.0   0.0   0.0   0.0   8.0   0.0    
// 1.0   2.0   0.0   0.0   1.0   0.0   8.0 
// ------------------------------------------
//��������� ����������� ������ CSIR_ITL
//val: 9.0 3.0 1.0 1.0 11.0 2.0 1.0 2.0 10.0 2.0 9.0 1.0 12.0 1.0 8.0 8.0 
//indx: 0 3 4 6 1 2 3 6 2 3 3 4 4 6 5 6 
//pntr: 0 4 8 10 12 14 15 16 
//--------------------------------------------
// ������ CSIR:
// ldiag: 9.0 11.0 10.0 9.0 12.0 8.0 8.0
// lltr: 2.0 3.0 1.0 2.0 1.0 1.0 1.0 2.0 1.0
// jptr: 1 0 1 2 0 3 0 1 4
// iptr: 0 0 0 1 4 6 6 9
//-------------------------------------------
void convertCSIR_ITLtoCSIR(doublereal* ldiag, doublereal* lltr, integer* jptr, integer* iptr, integer n, integer nz, doublereal* val, integer* indx, integer* pntr, integer nnz);

// �������� ���������� ��������� IC(0).
// ������� ������ ������ ����������� ������������ ������� � ������� CSIR.
// ������ ��������� ���� �������������� � ������� CSIR_ITL ���������� �������� ITL.
void ICFactor0(doublereal* ldiag, doublereal* lltr, integer* jptr, integer* iptr, integer n, integer nz);

// ��������� ������������ ������������ �����������  ������� �� ������ 
// ������������ ������ �������� CSIR. � ���� ��������� �������� ������ ��������������� �������� altr. 
// ����������� SPD ������� A (adiag, altr, jptr, iptr) ���������� �������� n*n.
// ����� ��������� ����� ����� ����������� � ����� n.
// ������:
// A = 
// 9.0   0.0   0.0   3.0   1.0   0.0   1.0    
// 0.0   11.0   2.0   1.0   0.0   0.0   2.0    
// 0.0   2.0   10.0   2.0   0.0   0.0   0.0    
// 3.0   1.0   2.0   9.0   1.0   0.0   0.0    
// 1.0   0.0   0.0   1.0   12.0   0.0   1.0    
// 0.0   0.0   0.0   0.0   0.0   8.0   0.0    
// 1.0   2.0   0.0   0.0   1.0   0.0   8.0 
// ------------------------------------------
// ������ CSIR:
// adiag: 9.0 11.0 10.0 9.0 12.0 8.0 8.0
// altr: 2.0 3.0 1.0 2.0 1.0 1.0 1.0 2.0 1.0
// jptr: 1 0 1 2 0 3 0 1 4
// iptr: 0 0 0 1 4 6 6 9
//-------------------------------------------
void SPDMatrixCSIRByVector(doublereal* adiag, doublereal* altr, integer* jptr, integer* iptr, doublereal* V, doublereal* &tmp, integer n);

// ��������� �������������� ������������ �����������  ������� �� ������ 
// ������������ ������ �������� CSIR.  
// ����������� ������� A (adiag, altr, autr, jptr, iptr) ���������� �������� n*n.
// ����� ��������� ����� ����� ����������� � ����� n.
// ��������� adiag �������� ��������. ������ ����������� altr �������� ���������.
// ������� ����������� �������� �� �������� autr. ������� ������� (������� ��������� 
// ��������� ) �������������� ������������. ������ jptr - ������ �������� ��� ������� 
// ������������, ������ iptr - ���������� ��� ���������� ����� ������ ��� ������� ������������.
// ������:
// A = 
// 9.0   0.0   0.0   3.0   1.0   0.0   1.0    
// 0.0   11.0   2.0   1.0   0.0   0.0   2.0    
// 0.0   1.0   10.0   2.0   0.0   0.0   0.0    
// 2.0   1.0   2.0   9.0   1.0   0.0   0.0    
// 1.0   0.0   0.0   1.0   12.0   0.0   1.0    
// 0.0   0.0   0.0   0.0   0.0   8.0   0.0    
// 2.0   2.0   0.0   0.0   3.0   0.0   8.0 
// ------------------------------------------
// ������ CSIR:
// adiag: 9.0 11.0 10.0 9.0 12.0 8.0 8.0
// altr: 1.0  2.0 1.0 2.0  1.0 1.0  2.0 2.0 3.0
// autr: 2.0 3.0 1.0 2.0 1.0 1.0 1.0 2.0
// jptr: 1 0 1 2 0 3 0 1 4
// iptr: 0 0 0 1 4 6 6 9
//-------------------------------------------
doublereal* MatrixCSIRByVector(doublereal* adiag, doublereal* altr, doublereal* autr, integer* jptr, integer* iptr, doublereal* V, integer n);

// ��������� ����������������� �������������� ������������ �����������  ������� �� ������ 
// ������������ ������ �������� CSIR.  
// ����������� ������� A (adiag, altr, autr, jptr, iptr) ���������� �������� n*n. �������� 
// ������ �������� �������, � ���������� � ����������������� �������.
// ����� ��������� ����� ����� ����������� � ����� n.
// ��������� adiag �������� ��������. ������ ����������� altr �������� ���������.
// ������� ����������� �������� �� �������� autr. ������� ������� (������� ��������� 
// ��������� ) �������������� ������������. ������ jptr - ������ �������� ��� ������� 
// ������������, ������ iptr - ���������� ��� ���������� ����� ������ ��� ������� ������������.
// ������:
// A = 
// 9.0   0.0   0.0   3.0   1.0   0.0   1.0    
// 0.0   11.0   2.0   1.0   0.0   0.0   2.0    
// 0.0   1.0   10.0   2.0   0.0   0.0   0.0    
// 2.0   1.0   2.0   9.0   1.0   0.0   0.0    
// 1.0   0.0   0.0   1.0   12.0   0.0   1.0    
// 0.0   0.0   0.0   0.0   0.0   8.0   0.0    
// 2.0   2.0   0.0   0.0   3.0   0.0   8.0 
// ------------------------------------------
// ������ CSIR:
// adiag: 9.0 11.0 10.0 9.0 12.0 8.0 8.0
// altr: 1.0  2.0 1.0 2.0  1.0 1.0  2.0 2.0 3.0
// autr: 2.0 3.0 1.0 2.0 1.0 1.0 1.0 2.0
// jptr: 1 0 1 2 0 3 0 1 4
// iptr: 0 0 0 1 4 6 6 9
//-------------------------------------------
doublereal* MatrixTransposeCSIRByVector(doublereal* adiag, doublereal* altr, doublereal* autr, integer* jptr, integer* iptr, doublereal* V, integer n);


/* ����� ���������� ���������� �������� � ������� [1952]
*  ������� ���������:
*  adiag, altr, jptr, iptr - ����������� ������� ���� � ������� CSIR,
*  dV - ������ ������ �����, 
*  x - ��������� ����������� � ������� ��� NULL.
*  n - ����������� ���� An*n.
*  nz - ����������� �������� altr, jptr.
*  ����������� ������� A (adiag, altr, jptr, iptr) ���������� �������� n*n.
*  ����� ��������� ����� ����� ����������� � ����� n.
*  ������� A ���������� ������������ ����������� � 
*  ������������ (������������ ������������ ������������).
*  �������� ������ ������ ����������� � ���������� altr � adiag.
*  ���������� �������� ���������� 1000, �.�. ��������������,
*  ��� ���� ������� �� ������� �� 1000 �������� �� ��� � �� �������.
*  �������� ������ �� ������� ������� � ���������� ���������:
*  dterminatedTResudual.
*  � �������� ������������������� �������� �������� ���������� ���������:
*  M^(-1)==transpose(L)^(-1)*L^(-1); // ���������� �������������������.
*/
doublereal *SoprGradCSIR(doublereal* adiag, doublereal* altr, integer* jptr, integer* iptr, doublereal *dV, doublereal *x, integer n, integer nz0);

// ������� ���������� ���� ������������� ������� ���� �.
// ������� ���� � ������� � CSIR �������: adiag, altr, jptr, iptr.
// �������� ���������� ��������� ��� � ������������ � ���������� � ����:
// A = L*transpose(L); � ������� �����������. ������� jptr �  iptr �������� ���� ��.
// ����� �������: A~=inverse(L)*A*inverse(transpose(L)) ���� ����������� � ������������ ����������.
// ������ ����� ��������������� ������� ����� ���: dV~=inverse(L)*dV.
// ������� ���� ����� ����� A~*x~=dV~; => x~=transpose(L)*x; => x=inverse(transpose(L))*x~;
// ������������������ �������� ����������� ��������� ��������� ���������� �������� ��� ������� ����,
// �������� ������������ �������������� ������� ����.
doublereal *SoprGradCSIR2(doublereal* adiag, doublereal* altr, integer* jptr, integer* iptr, doublereal *dV, doublereal *x, integer n, integer nz0);

/* ����� ���������� ���������� �������� � ������� [1952]
*  ������� ���������:
*  M - ����������� ������� ���� � ������� SIMPLESPARSE,
*  dV - ������ ������ �����, 
*  x - ��������� ����������� � ������� ��� NULL.
*  n - ����������� ���� An*n.
*
*  ����������� ������� M ���������� �������� n*n.
*  ����� ��������� ����� ����� ����������� � ����� n.
*  ������� M �������������� ������������ ����������� � 
*  ������������ (������������ ������������ ������������).
*  �������� ������ ��������� ��������. 
*  ���������� �������� ���������� 1000, �.�. ��������������,
*  ��� ���� ������� �� ������� �� 1000 �������� �� ��� � �� �������.
*  �������� ������ �� ������� ������� � ���������� ���������:
*  dterminatedTResudual.
*  � �������� ������������������� �������� �������� ���������� ���������:
*  K^(-1)==transpose(L)^(-1)*L^(-1); // ���������� �������������������.
*  ������� ���������� (�������� ��� ������� ������).
*/
void ICCG(SIMPLESPARSE &M, doublereal *dV, doublereal* &x, integer n, bool bdistwall, integer maxiter);

// �������� �.�. ����������� [1993]
// ��� �������� �������������� ������.
// ���������������� �� ����������
// "��������� ������ ������� ������ ���������" [2004]
// �������������� ���������������� ������������ ������������.
doublereal* SoloveichikAlgCSIR_SPD(integer isize, // ������ ���������� �������
						doublereal* adiag, doublereal* altr, integer* jptr, integer* iptr, // ������� ����
                         doublereal *dV,  // ������ ������ �����
                         const doublereal *dX0, // ������ ���������� �����������
                         bool bconsole_message); // �������� �� �������� ������� �� ������� ?

// �������� �.�. ����������� [1993]
// ��� �������� �������������� ������.
// ����� ������������ ��� ������������ � ������������ ����������� �������.
// � ������������������� �������� ����������� ���������.
// ���������������� �� ����������
// "��������� ������ ������� ������ ���������" [2004]
// �������������� ���������������� ������������ ������������.
doublereal* SoloveichikAlgCSIR_SPDgood(integer isize, integer nz0,// ������ ���������� �������
						doublereal* adiag, doublereal* altr, integer* jptr, integer* iptr, // ������� ����
                         doublereal *dV,  // ������ ������ �����
                         const doublereal *dX0, // ������ ���������� �����������
                         bool bconsole_message); // �������� �� �������� ������� �� ������� ?

// �������� �.�. ����������� [1993]
// ��� �������� �������������� ������.
// ���������������� �� ����������
// "��������� ������ ������� ������ ���������" [2004]
// �������������� ���������������� ������������ ������������.
void SoloveichikAlgCRS(integer isize, // ������ ���������� �������
						doublereal *val, integer* col_ind, integer* row_ptr, // ������� ����
                         doublereal *dV,  // ������ ������ �����
                         const doublereal* &dX0, // ������ ���������� �����������
                         bool bconsole_message, integer maxit); // �������� �� �������� ������� �� ������� ?

// �������������� ����������� �������
void initsimplesparse(SIMPLESPARSE &M, integer nodes);

// ��������� ��������� ������� �
// ���������� ����������� ������� M
void addelmsimplesparse(SIMPLESPARSE &M, doublereal aij, integer i, integer j, bool bset);

// ������������ ������ ��� ������� SIMPLESPARSE
void simplesparsefree(SIMPLESPARSE &M, integer nodes);

// ��� ��������� ������� ���� ��������� ������������������ ���������
// ����������. ����� ����� ����������� ������� ����������.
// ������ �������� � ����� ����� "The C programming language".
// swap: ����� ������� v[i] � v[j]
void swap(integer* &v, integer i, integer j);

// ��� �������� PivotList
integer PivotList(integer* &list, integer first, integer last);

// ������� ���������� �. �����.
// ����������������� � �������������� ��. ��������� ������ ����������
// ���. 106.
void QuickSort(integer* &list, integer first, integer last);

// ����������� ���������� ������ �������� ����������� �������
// � ������ CRS. ����� nodes - ���������.
void simplesparsetoCRS(SIMPLESPARSE &M, doublereal* &val, integer* &col_ind, integer* &row_ptr, integer nodes);

// ����������� equation3D  ������ �������� � CRS ������.
// ���� ��������� ����� ���������������: �������� ����������� ������ ����������.
// �.�. ������ SIMPLESPARSE ������� ������� ����� ������.
integer equation3DtoCRS(equation3D* &sl, equation3D_bon* &slb, doublereal* &val, 
	integer* &col_ind, integer* &row_ptr, integer maxelm, integer maxbound, 
	doublereal alpharelax, bool ballocmemory
	, BLOCK* &b, integer &lb, SOURCE* &s, integer &ls);

// ���������� �� ������� ������.
// ����������� ���������� ������ �������� ����������� �������
// � ������ CSIR. ����� nodes - ���������.
// ��� �������� ������ ��� SPD ������.
// ������������ ������������ ����������� ������,
// �������� ������ ������ �����������.
void simplesparsetoCSIR(SIMPLESPARSE &M, doublereal* &adiag, doublereal* &altr, integer* &jptr, integer* &iptr, integer nodes);

// ������ ������� � �������
void printM_and_CSIR(SIMPLESPARSE &sparseM, integer  n);

// ���������� �� ������� ������.
// ����������� ���������� ������ �������� ����������� �������
// � ������ CSIR_ITL. ����� nodes - ���������.
// ��� �������� ������ ��� SPD ������.
// ������������ ������������ ����������� ������,
// �������� ������ ������� �����������.
// ������ ���������� ������ ������.
void simplesparsetoCSIR_ITLSPD(SIMPLESPARSE &M, doublereal* &val, integer* &indx, integer* &pntr, integer nodes);

/* �������� LU ���������� ��� �������������� ������
*  ������ � n*n=
*    9.0 0.0 0.0 3.0 1.0 0.0 1.0
*    0.0 11.0 2.0 1.0 0.0 0.0 2.0 
*    0.0 1.0 10.0 2.0 0.0 0.0 0.0 
*    2.0 1.0 2.0 9.0 1.0 0.0 0.0 
*    1.0 0.0 0.0 1.0 12.0 0.0 1.0 
*    0.0 0.0 0.0 0.0 0.0 8.0 0.0
*    2.0  2.0 0.0 0.0 3.0 0.0 8.0
*-----------------------------------------
*  ������������� (� ���� ���� ������ ��������� �� ���� ���������):
*  ������� ����������� ������� �������� ���������, � ������ ������
*  �������� ������������� �� �������� ������� ��������.
*  U_val:   1.0, 1.0, 3.0, 9.0,   2.0, 1.0, 2.0, 11.0,   2.0, 10.0, 1.0, 9.0, 1.0,12.0, 8.0, 8.0
*  U_ind:   6, 4, 3, 0,  6, 3, 2, 1,  3,2, 4,3, 6,4, 5, 6
*  U_ptr:   0, 4, 8, 10, 12, 14, 15, 16
*  ������ ����������� ������� �������� �����������, � ������ �������
*  �������� ������������� �� �������� ������� �����.
*  L_val:  2.0, 1.0, 2.0, 9.0,    2.0, 1.0, 1.0, 11.0,  2.0, 10.0, 1.0, 9.0,  3.0, 12.0, 8.0, 8.0
*  L_ind:  6, 4, 3, 0,  6, 3, 2, 1,   3, 2,  4,3,  6, 4, 5, 6
*  L_ptr:  0, 4, 8, 10, 12, 14, 15, 16
*----------------------------------------------
* ��������� ILU ����������:
* U_val: 1.0, 1.0, 3.0, 9.0, 2.0, 1.0, 2.0, 11.0, 2.0, 10.0, 1.0, 9.0, 1.0, 12.0, 8.0, 8.0.
* L_val: 0.222, 0.111, 0.222, 1.0, -1.273, 0.091, 0.091, 1.0, 0.2, 1.0, 0.111, 1.0, -0.417, 1.0, 1.0, 1.0.
*/
void ILU0_Decomp_ITL(doublereal* &U_val, integer* &U_ind, integer* &U_ptr, doublereal* &L_val, integer* &L_ind, integer* &L_ptr, integer n);

// �������� LU ���������� � ������� ����������� �� ����� �. �����
// Iterative Methods for Sparse linear systems.
// �� ���� ������� ������� � � CRS �������.
// �� ������ ������� luval � CRS ������� � ������� L �� ��������� 1.0,
// uptr - ��������� �� ������������ ��������.
//void ilu0_Saadtest(); // ���������
void ilu0_Saad(integer n, doublereal* a, integer* ja, integer* ia, doublereal* &luval, integer* &uptr, integer &icode);

/* ����� ������������ ����������
* ��� �������� �������������� ������� � (val, col_ind, row_ptr).
* ����������������� �� ������ ��������, ������: "������
* ������� ���� ������� �����������".
* dV - ������ ����� ����,
* x - ��������� ����������� � ������� ��� NULL.
* n - ����������� � n*n.
* ���������� �������� ���������� maxiter.
* �������� ������ �� ������� ������� � ���������� ���������:
*  dterminatedTResudual.
* ������ ����� ����������. ���� ������� ������ ������ r_tilda, �� 
* ������� ����� ����� ����������. ����������� �� ����� ������� r_tilda:
* ������� ����� ��������� ������������ Scal(r,r_tilda,n) != 0.0.
*/
void BiSoprGrad(IMatrix *xO, equation3D* &sl, equation3D_bon* &slb,
	doublereal *dV, doublereal* &x, integer maxelm, integer maxbound,
	bool bSaad, doublereal alpharelax, integer  maxiter,
	BLOCK* &b, integer &lb, SOURCE* &s_loc, integer &ls);

// �������� �.�. ����������� [1993]
// ��� �������� �������������� ������.
// ���������������� �� ����������
// "��������� ������ ������� ������ ���������" [2004]
// �������������� ���������������� ������������ ������������.
// �������� ILU0 �������������������.
void SoloveichikAlg( IMatrix *xO, equation3D* &sl, equation3D_bon* &slb,// ����������� ������� ����
					     integer maxelm, integer maxbound, // ����� ���������� � ��������� ��
                         doublereal *dV,  // ������ ������ �����
                         doublereal* &dX0, // ������ ���������� �����������
                         bool bconsole_message, // �������� �� �������� ������� �� ������� ?
						 bool bSaad, // ���� bSaad==true �� ������������ ilu0 ���������� �� ����� �. ����� ����� ������������ ITL ilu0 ����������. 
						 integer imaxiter, doublereal alpharelax,
	BLOCK* &b, integer &lb, SOURCE* &s_loc, integer &ls); // ����������� ���������� ���-�� ��������

// ����� ��� ��� ������ Bi-CGStab
void Bi_CGStabCRS(integer n, doublereal *val, integer* col_ind, integer* row_ptr, doublereal *dV, doublereal* &dX0, integer maxit);

// ����� ��� ��� ������ Bi-CGStab
// �������� ��� �������� �������������� ������������ ������.
// ������� ������������������� ILU(0).
// ����� �������� ����������� ������� BiCG � GMRES(1). 
void Bi_CGStab(IMatrix *xO, equation3D* &sl, equation3D_bon* &slb,
			   integer maxelm, integer maxbound,
			   doublereal *dV, doublereal* &dX0, integer maxit, 
	doublereal alpharelax , integer* &ifrontregulationgl, integer* &ibackregulationgl, 
	integer inumber_iteration_SIMPLE);

// �.�.�����, �.�.������ 
// ��������� ������������� ������������� ������ � ���������������� �������.
// ������� �������� ���������������� ������������. ���������� � �������� �2(14) 2011���.
// �������� ������� �� ������ ��������� ���������� LR1 � Bi-CGStab P.
// LR1 - ������������ ����� ������������ ��� � ����� �. ���������: ������
// ������� ������ �������� (�������� ������) � ������ ������-�������.
// Bi-CGStab P - �������� ������� ��� ��� ������ � �������������������: ������ Bi-CG � GMRES(1).
// ������ ���������, ������������ � ������������� � AliceFlow_v0_06 ���������� 
// 24 ������� 2011 ���� �� ������ ���������� ����������.
void LR1sK(FLOW &f, equation3D* &sl, equation3D_bon* &slb,
	       doublereal *val, integer* col_ind, integer* row_ptr,
		   integer maxelm, integer maxbound, integer iVar,
		   doublereal *dV, doublereal* &dX0, integer maxit, bool &bprintmessage, bool bexporttecplot);

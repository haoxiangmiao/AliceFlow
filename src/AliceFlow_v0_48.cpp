// AliceFlow_v0_48.cpp
// 27 ������� 2020 PMIS aggregator, FF1 amg interpolation. Acomp=3.0;
// ��� � ������������ ����������� ������ �������� 2006. 
// ������ ���������� PMIS ��� � �� ����� 2004���.
// 12 ������ 2020 iluk ������������ ��� amg1r5 ���������.
// 10 ������� 2019 ���������������� ������ �������������� K-Omega SST ������� (RANS). 
// 2 ������� 2019 ���������������� ������ �������������� �������� ��������� (RANS).
// 4 ������� 2019; 03 ������ 2019 �������������� ������������ gcc (g++ 9.1). GNU project. 
// ������������ nan, inf � ������ ������������.
// ��������� � ����� ������� � �������� /FP:strict 
// (C/C++ -> Code Generation ->> Floating Pint Model).
// �������� �++ ����������: ��, � SEH ������������ (/EHa)
// 7-8 ��� 2019 ����������� �������������� ������������� ����� amgcl ������ ��������.
// 6 ������ 2019 ��������������� � visual studio community edition 2019 (open source).
// 25.03.2019 ����� ������������ PVS-Studio 6.0
// 19 �����(03) 2019 ���������� ������������� �� ���� ������.
// 6.05.2018 LINK: fatal error LNK1102: ������������ ������ 2015 VS community.
// ����� � ���������� � ������ /bigobj
// ��������� ���������� ��� cuda:
// Tools->Options->Text Editor->File Extension ������ cu � ������ ������ add.
// 9 ���� 2017 ������� �� 64 ������ ����� int64_t.
// 15 ������ 2017 ��������������� � vs community edition 2017 (open source).
// 1 ������� 2016 �������������� �� nvidia cuda 8.0. 
// ���� ����� ������� � ����� ��� ������������� � ������ ����. 
// 11 ������ 2016 ���� ������� cl_agl_amg_v0_14.
// 15 ������� 2015 ����. ������ � Visual Studio 2015.
// AliceFlow_v0_21.cpp
// 15 ������� 2015. ������ � Visual Studio 2013.
// AliceFlow_v0_20.cpp
// 14 ������� 2015 ������������� ���������� ����������������� lusol �
// ilu2 decomposition �� 2 ������.
// 
// AliceFlow_v0_07.cpp �� ������  AliceFlow_v0_06.cpp, �� ������ � LES ������� ��������������.
// ��������� �� ������ ������������ � �������� ������ � ������ �������������� Germano.
// 17 ������ 2013 ����. ���������� ����������������� lusol_.
// 1 ������ 2013. ������ � Visual Studio 2012.
//
// AliceFlow_v0_06.cpp:
// 3D ��������� AliceFlow_v0_06.cpp ��������� �������� AliceFlowv0_05.cpp
// �������� �� ������, ��������� ������������ � ����������������.
// 
// ��������� AliceFlow_v0_05.cpp, 
// ���������� ������� AliceFlow_v0_03.cpp, ����������� 
// ���� �� ������� ����������� ��������������
// � ������ ����������� �� ���� �������.
// � ���� �� ��������� ������������ 
// ������������� ����������������� HEX 
// ��������� �����.
// begin one 17 ��� 2011 ����.
//
// 3D ��������� AliceFlowv0_05.cpp 
// ������������ ��������� ��������:
// 1. ��������� ��������������� �����.
// 2. �������� � ���������� ���� ��������
//    ������ ����������� ��� ������ ������� ����.
// 3. ������ ������� ����.
// 4. �������� ����.
// 5. ������� � ������������ tecplot360.
// begin two 30 ���� 2011 ����.
// begin three 14 ������� 2011 ����. ������ �� Visual Studio 2010.
// begin four 12 ����� 2012 ����. (�� ������� ����� �. ������ - ������� �� ���).
//
// �������� ������� ��������� ����� � ����������� ���� TGF2023_*
// ����� 0.2x120��� �������� 100 �������� (10-20��).
 

// ���������������� � ������ ���� ������ ���������� 
//�������������� ������������ gcc (g++ 9.1) �� GNU.
#include "stdafx.h"
//#include "pch.h"

// ����������������� � ������ ���� ������ ���������� 
//�������������� ������������ g++ (g++ 9.1) �� GNU.
// g++ AliceFlow_v0_48.cpp -fopenmp 2> gcc_log.txt
// gcc_log.txt - ���� � ���������������� ����������� �����������.
//#define MINGW_COMPILLER 1

#ifdef MINGW_COMPILLER

// ���� float 32 ���� �� ������� - �� ������� ������� ����������� ������������ ��������������� ��������.
// ��� float (���� ���������� ��������������� �������� ����� ����� ����) ���� � ���� ������� ����� ��������
// �� ��������� � ����� double (12 ������ 7).
// ��� float128 128 ��� ������� � 32 ���� ��������� ��� ��� double 64 ����. �� ���� ���������� �������� 
// 31 ������ 38 � ���� double. ������ �� ���������� � double �� �������� � � ���� float128. ������� ������������ 
// ����������� ������ ���������� �� ���� �������.
// �� ��������� ������������� ������������ ������ ��� double.


/*
// �������� ����������
// boost.org/doc/libs/1_65_1/libs/math/example/float128_example.cpp

// ��������� ��������. ��� __float128
//#include <quadmath.h>
#include <boost/cstdfloat.hpp> // For float_64_t, float128_t. Must be first include!
//#include <boost/config.hpp>
#include <boost/multiprecision/float128.hpp>
//#include <boost/math/special_functions/gamma.hpp>
#include <boost/math/special_functions.hpp> // For gamma function.
#include <boost/math/constants/calculate_constants.hpp> // For constants pi, e ...
#include <typeinfo> //

#include <cmath> // for pow function
*/
/*
C:\AliceFlow_v0_48_GCC>g++ -std=c++11 -fexceptions -std=gnu++17 -g -fext-numeric-literals -II:\modular-boost\libs\math\include -Ii:\modular-boost -c AliceFlow_v0_48.cpp -o obj\Debug\AliceFlow_v0_48.o
C:\AliceFlow_v0_48_GCC>g++ -o bin\Debug\AliceFlow_v0_48.exe obj\Debug\AliceFlow_v0_48.o -lquadmath
*/

//#include <iostream>

//using namespace boost::multiprecision;

//#include <stdlib.h>
//#include <stdio.h>

#endif



// /fp:except option
//#pragma float_control( except, on )

// ��� std::locale::global(std::locale("en_US.UTF-8"));
// �� ��������.
//#include <locale.h>

//using namespace std;

// ������ ������ ��� ���� cuda c.

//#include "cuda_runtime.h"
//#include "device_launch_parameters.h"


#include <iostream>

#include <stdio.h>
#include <string.h>
#include <cinttypes> // ��� ���� 64 ������� ������ ����� int64_t

#include <stdlib.h> 
#include <omp.h> // OpenMP
//-Xcompiler "/openmp" 

//#define NOMINMAX // �����������������
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h> // �����������������

// ���������������� � ������ ���� ������ NOT NUMBER �������������.
//#define MY_DEBUG_NOT_NUMBER

unsigned int calculation_main_start_time_global_Depend = 0; // ������ ����� ��.

// ���� ������ �� Oz
bool b_one_cell_z = false;


// ����� ������� ����������. 
// ��������� �� ���������� ������������.
// ���� ������ ���������� ����� 4 �������.
int number_processors_global_var = 1;

int number_cores() {
	return number_processors_global_var;

	// 4 xeon 2630 v4.
	// ���� ������ ���������� ����� 4 �������.
} 

//using namespace System;

// 0 - ������ ������ ��� ����������� ���������� ���������� windows.
#define _CUDA_IS_ACTIVE_ 0

// ������������ ����������.
#define doubleprecision 1
#if doubleprecision == 1
#ifdef MINGW_COMPILLER
// ��������� ��������.
//#define doublereal __float128
//#define doublereal  _Quad
//#define doublereal float128
//#define doublereal float // 32 ���
#define doublereal double // 64 ���
#else
//#define doublereal  _Quad
//#define doublereal float128
#define doublereal double // 64 ���
//#define doublereal long double //double // ������ ������������� ����� ������� ��������
//#define doublereal Decimal // decimal
#endif
#else
#define doublereal float //float // ������ ������������� ����� ��������� ��������
#endif

#define doubleintprecision 1


#if doubleintprecision == 1
// �������� !!! ��� ���� int64_t �� �������� ��� ������� ���������� ViennaCL.
// ���������� ������ �������� AMGCL �������� � � ����� int64_t. 
#define integer int64_t
#else
#define integer int
#endif


//const integer parabola_MNK = 0; // ����������� �� �������� ����������� �� ������� ���������� ���������.
	// ��������: line_MNK ����� �� ������������, �.�. ���������������� �����������, �� ������� ������
	// ������� tgf2023_01 ��� ���������� ��� ����� ������� ����������� �� ���������, ����������� ����� ������������� �� ����������
	// ����� ��� 40 ���������� �������� � �����. �������� ���� ������������.
//const integer line_MNK = 1; // ������� ���� ������� ������, ������ ��������� �� ������� ��� �� ������ ������.
// ������ ����� ����� �� ������������� ������������ ! ����� ���������� ����������.
//const integer cubic_parabola = 2; // ���������� �������� �� 4 ������ � �� �� �����������.

enum ORDER_INTERPOLATION { parabola_MNK, line_MNK, cubic_parabola};
enum ORDER_DERIVATIVE { FIRST_ORDER=1, SECOND_ORDER=2};

const integer ZERO_INIT = 0;
const integer RANDOM_INIT = 1;

// ��� ������� solve_Thermal(...);
const integer bARRAYrealesation = 1; // �� ������ ���������������� �������, �� ������� � ��������������� ������ �������� �������� ��������������.
const integer bAVLrealesation = 2; // �� ������ ��� ������.

const integer iGLOBAL_RESTART_LIMIT = 6;
bool bglobal_restart_06_10_2018 = false;
// ��� ��������� �� �� ����� ���������� �� �� ������� ��� ����� ���� �������� ��� ������������.
bool bglobal_restart_06_10_2018_stagnation[iGLOBAL_RESTART_LIMIT+1] = {false,false,false, false,false,false, false};
integer iPnodes_count_shadow_memo = 0;

// ���������� ������ �������������� � ������������� ������, ��� �������� �� ����� ����������. 
doublereal d_GLOBAL_POWER_HEAT_GENERATION_IN_CURRENT_MODEL = 0.0; // ��
doublereal d_my_optimetric1_6_12_2019 = 0.0;// ���������� ���������� ��� �����������.
doublereal d_my_optimetric2_6_12_2019 = 0.0;// ���������� ���������� ��� �����������.
doublereal d_my_optimetric3_6_12_2019 = 0.0;// ���������� ���������� ��� �����������.

// ��������� ��������������� xyplot �������� ��� �������.
// 5.01.2018
typedef struct Tpatcher_for_print_in_report {
	doublereal fminimum = -1.0e+30, fmaximum = 1.0e+30;
	integer idir=1; // 0 - X, 1 - Y, 2 - Z.
} Patcher_for_print_in_report;

Patcher_for_print_in_report pfpir; // xyplot �������.

// 9 september 2017.
// ������ �� ������������ ����������� ������ � ����� ���������� �������� ������.
// �������� �������� �������� ��� ������������ �����, �.�. ����� ������ ��� �������� �� ������, � ���� ���������� 
// ������� ������. ������ ������� ������ �������� ������� �� ������������� ���� ���������� ��� ����� ����� � 
// ����������� ����������������� �������� ���������� �� ����� �����.
integer ireconstruction_free_construct_alloc = 1; // 0 - off, 1 - on.
// ���������� �� �������� � ��������� ����
// �� ��������� ������� ������ ���� �� �������.
integer ianimation_write_on = 0; // 0 - off, 1 - on.

// ��� ���������� ���������� �� ������ 300 �������� 
// ������� �� ��������� vel*rGradual_changes � ����� 
// ������ �������������������
// � ����������� ��� �� ��������� vel.
// 1.0 - �� ������������. �� ������������� 0.1!!!
doublereal rGradual_changes = 1.0; 

// 1 - �������� ������ amg1r6.f ������; 
// 0 - �������� amg1r5.f � ����.
integer AMG1R6_LABEL = 0; 
integer nrd_LABEL = 1131;
integer nru_LABEL = 1131;
doublereal ecg2_LABEL = 0.25; // strong threshold amg1r5
doublereal ewt2_LABEL = 0.35; // F to F threshold amg1r5
bool b_iluk_amg1r5_LABEL_D = false; // ����
bool b_iluk_amg1r5_LABEL_U = false; // �����
// stabilization_amg1r5_algorithm:
// 0 - none(amg1r5); 1 - BiCGStab + amg1r5; 2 - FGMRes+amg1r5;
enum AMG1R5_OUT_ITERATOR {NONE_only_amg1r5,  BiCGStab_plus_amg1r5,  FGMRes_plus_amg1r5};
AMG1R5_OUT_ITERATOR stabilization_amg1r5_algorithm = BiCGStab_plus_amg1r5; // BiCGStab + amg1r5.

// ������������� ��������� �������� ����������.
// ������ �������� ��� ���� ��������� �������.
// initialization value.
doublereal starting_speed_Vx = 0.0;
doublereal starting_speed_Vy = 0.0;
doublereal starting_speed_Vz = 0.0;

// ������� ����� ��� XY-Plot (variation Plot).
// �� ��������� ������� �����, ����� ������� �������� �����, � ����������� 
// ����� ����� ����� �� ���� ���������� ������������� ������� ���������.
doublereal Tochka_position_X0_for_XY_Plot = 0.0;
doublereal Tochka_position_Y0_for_XY_Plot = 0.0;
doublereal Tochka_position_Z0_for_XY_Plot = 0.0;
integer idirectional_for_XY_Plot = 0; // 0 - Ox axis. 

// ��� iVar==TEMP && lw==1 ����� �� ������� ����� ������������ ����� ������������ ����������� ����� V ������� ���������� ����� 0.5K.
bool bPhysics_stop = false;
// ������ ��������� ���������� ����������� ������ ��� ����.
bool bPhysics_PTBSH_memory = false;
// ������ ������ ������������� � ������ ����:
bool bonly_solid_calculation = false;

// ����� ��� ������������� ������������� ������ �� ������������� �����.
// 3 ������� 2015 ����� ����� �������� ����� GUI ������������
// � ����� � ��� ���������� ��������������� �������� � ����� ������ ����.
// ������������ �����
#define UNEVEN_MUSCL 1017  // van Leer (1977)
#define UNEVEN_SOUCUP 1018 // MINMOD
#define UNEVEN_HLPA 1019
#define UNEVEN_SMART 1020 // Gaskell and Lau (1988)
#define UNEVEN_WACEB 1021
#define UNEVEN_SMARTER 1022
#define UNEVEN_STOIC 1023 // Darwish (1993)
#define UNEVEN_CLAM 1024
#define UNEVEN_OSHER 1025 // Chakravarthy and Osher (1983)
#define UNEVEN_VONOS 1026
#define UNEVEN_LPPA 1027
#define UNEVEN_EXPONENTIAL 1028
#define UNEVEN_SUPER_C 1029
#define UNEVEN_ISNAS 1030
#define UNEVEN_CUBISTA 1031
#define UNEVEN_GAMMA 1032 // ����� � ���������� beta_m
#define UNEVEN_COPLA 1033 // 1 08 2015
#define UNEVEN_SECBC 1034 // 2 08 2015 Yu et al., (2001b) ��������, �������.
#define UNEVEN_SGSD 1035 // 3 08 2015 Li and Tao (2002)



bool bglobal_first_start_radiation = true;

// ���� �� ������ �������������� ������ ������������� � ������� ����.
bool bglobal_unsteady_temperature_determinant = false;

// ����� ��������� ����������:
// simplemeshgen == 0 ��� unevensimplemeshgen ==1.
// �� ��������� ������������ simplemeshgen == 0.
integer iswitchMeshGenerator = 0; // ������� �������� ���������.
// �������������� ��� ������������ �������������.
integer steady_or_unsteady_global_determinant = 0; // 0 - steady, 1- unsteady.

// ������������ �� ���������� �������� ������������ ��������� �����.
bool b_on_adaptive_local_refinement_mesh = false;
integer itype_ALICE_Mesh = 1;// ��� ���� �����.

// ������ 2 (���� �� ��������� ������).
typedef struct TPiecewiseConstantTimeStepLaw {
	doublereal time=0.0, timestep=0.0, m=0.0;
} PiecewiseConstantTimeStepLawTimeStepLaw;


typedef struct TTimeStepLaw
{
	// 0 - Linear, 
	// 1 - Square Wave,
	// 2 - Square Wave 2, 
	// 3 - Hot Cold (���������� �.�.)
	// 4 - Piecewise Constant 20.12.2019 - ����� ��������� �������� �������������.
	integer id_law=0; 
	doublereal Factor_a_for_Linear=0.2;
	doublereal tau=60.0E-6; // ������������ �������� ��� Square Wave
	// 06_03_2017 ���������� ����� ���� � �������.
	doublereal Q=10.0; // ���������� ��� Square Wave.
	// ���������� ����� ��� ��������������� Square Wave 2.
	doublereal m1=1.0, tau1=0.0, tau2=0.0, tau_pause=0.0, T_all=0.0;
	integer n_cycle=20; // 20 ������.
	// hot cold reshime (double linear)
	doublereal on_time_double_linear=3.0; //3c ��������.
	// 4 ����� ��������� ���� �� �������.
	integer n_string_PiecewiseConst = 0;
	PiecewiseConstantTimeStepLawTimeStepLaw* table_law_piecewise_constant = nullptr;

} TimeStepLaw;

TimeStepLaw glTSL;

// 24 ������� 2016. 
// ��� ��������� ����� ���������� ����� � ����� 0.14 ��������.
typedef struct TQuickNonlinearBoundaryCondition {
	doublereal emissivity=0.8;
	doublereal Tamb=20.0, dS=0.0;
	doublereal film_coefficient=3.0;
	bool bactive=false;
	bool bStefanBolcman_q_on = false;
	bool bNewtonRichman_q_on=false;

} QuickNonlinearBoundaryCondition;

QuickNonlinearBoundaryCondition* qnbc = nullptr;
integer iadd_qnbc_maxelm = 0; // ��� ����������� ������
bool b_sign_on_nonlinear_bc = false;


// ������� �� �� SIMPLE ����������.
// ��� ����� ��� ����� ������ ��������� ������� ��� ��������� �������������.
// ������ BiCGStab_internal3 ��������.
bool bSIMPLErun_now_for_temperature = false;
// ���������� �������� SIMPLE ��������� 
// ������� ����� ������������ � ����������.
integer number_iteration_SIMPLE_algorithm = 0; // default - 0
// ��� ����� ��� ����� ������ ��������� ������� ��� ��������� �������������
// ��� ������� amg1r5 ���������� ����� � ������������ ����������.
bool bSIMPLErun_now_for_natural_convection = false;
// �������������� ������ ���������� ��� �����������.
doublereal* told_temperature_global_for_HOrelax = nullptr;

/*
��� ���������� ������� ���������� ����� ������������ ����������� �����.
��� ����� ����� ��� ���� �� ��������������� ��-����� �� ���������.
������� �������������� ������ ��������� � ���� ��� ���������������� ����� ������ ���� �����������
��� ��������� ����� ����������� ������� ����������� � ������ �����. � �������� ����������������
������ ������� ��������������.
*/
bool *sourse2Dproblem=nullptr;
doublereal *conductivity2Dinsource=nullptr;

// �������������� ������ ����������.
bool bHORF = false;
bool bdontstartsolver = false;
doublereal* bPamendment_source_old = nullptr;
doublereal* bsource_term_radiation_for_relax = nullptr;
doublereal* b_buffer_correct_source = nullptr;
// �� ��������� ������������ �����_0.14 �� ������ �� ��������.
bool bfirst_start_nonlinear_process = true;

// ������� �������-������� �� ������� ��� �����������.
integer adiabatic_vs_heat_transfer_coeff = 0; // 0 - adiabatic wall, 1 - Newton Richman condition, 2 - Stefan Bolcman condition, 3 - mix condition.
// ��� ���������� ��������� ������� �� ������ ���� ������ ���� ��������� ����� V ������. 
bool breakRUMBAcalc_for_nonlinear_boundary_condition = false;
bool bvacuumPrism = false; // ������� ��������� �����������.
bool bdouble_vacuum_PRISM = false; // ������� ��������� ����������. ��� ����� ��� ��������� ���������� ������� - ��������� �� ������ ������.
bool bBlockStefanBolcman = false; // ���� true �� ��������� ������� ���������.
doublereal film_coefficient = 0.0; // ����������� �����������.
doublereal operating_temperature_for_film_coeff = 20.0; // Tamb for Newton-Richman condition.
// ���� ��������� ���� ���������� ����� ���������������� ��������� operating_temperature_for_film_coeff
// �� � ������� �������-������� �� ������� ������� �������� ����� (���������� ������� �������) ��� ���
// ������� �������� �������������� � ���������� ������� ������� ������� � ����������� ������������ � ������������
// ��������������� ��������. ����� ����� �������� ������������ ���������� blocker_Newton_Richman.
bool blocker_Newton_Richman = true;


// 1 - ������������ ������ ������� ����.
// 0 - ������������ � �������� � �������� ����.
integer ionly_solid_visible = 0;

// ������������ ����� �������������� ������������� ������� � ���������� ��� ��� ������ BiCGStab+ILU2.
// 0 - �������� BiCGStab + ILU2.
// 1 - �������� ����� ���� � ������ ������� ��������������� �������������� ������ amg1r5 (r6).
// 2 - BiCGStab + ADI (Lr1sk).
// 3 - Gibrid: velocity bicgstab + ilu(lfil), Pressure - ����� v0.14.
// 4 - BiCGStab + AINV N.S.Bridson nvidia cusp 0.5.1 library.
// 5 - AMGCL bicgstab+samg ����� �������.
// 6 - Nvidia cusp 0.5.1 library BiCGStab +samg.
// 7 - Algebraic Multigrid ����� v0.14.
integer iswitchsolveramg_vs_BiCGstab_plus_ILU2 = 0; // BiCGStab + ILU2.
// 0 - BiCGStab+ILU6, 1 - Direct, 2 - ����� 0.14
// for Stress Solver
integer iswitchsolveramg_vs_BiCGstab_plus_ILU6 = 0; // BiCGStab + ILU6.

bool bwait = false; // ���� false �� �� ���������� getchar().
// ���� ������ ����� �������� �� 1e-10 �� ��������� ������ ����� ������ ����
#define admission 1.0e-30 //1.0e-10 // ��� ����������� ���������� ���� ������������ �����.

unsigned int calculation_vorst_seach_time = 0;

// ���� ����������� ������ �������� 
// ����������� � 200 �������� ������� 
// �� ������ ������ �� ����� (������).
// � ������ ���������� ����������� ������ TEMPERATURE_FAILURE_DC
// �� ������� ���������� ��������������� ��������� � ����� ����
// ��� ������������ ������ ��������� �������������� ����� �� ���������.
#define TEMPERATURE_FAILURE_DC 5000.2


// �������� ����� ��������� ��������� ������� �������� �������������
// ���������� �������. ��. ��� ����������� � ����� ������ �. ���������.
// BETA_PRECISION 1.0 4/3=1.333333333 6/5=1.2
#define BETA_PRECISION 1.0

// UDS  ��. my_approx_convective.c
unsigned int iFLOWScheme = 2; // ��������������� ������� �������
unsigned int iTEMPScheme = 2; // ��������������� ������� �������

// �������� ����� ������ ���������� �������� SIMPLEC
// SIMPLEC Van Doormal and Raithby, 1984 ���.
// SIMPLEC ���������� �� SIMPLE ������ � ���� �����:
// 1. � SIMPLEC �� ������������ ������ ���������� ��� �������� ��� ��������� ��������, �.�. alphaP=1.0.
// 2. � SIMPLEC ������ ����� ��������������� tau ~ alpha/(1-alpha), � � SIMPLE tau ~ alpha. 
// � ��������� ��������� ��������� ���������.
#define SIMPLE_Carretto 0 // �������� SIMPLE Carretto et al., 1973 ������������ �� ���������.
#define SIMPLEC_Van_Doormal_and_Raithby 1 // �������� SIMPLEC Van Doormal and Raithby, 1984 ���.
unsigned int iSIMPLE_alg = SIMPLE_Carretto;// SIMPLE_Carretto SIMPLEC_Van_Doormal_and_Raithby

// �������� ������� ���� ��� ���� ������� ��� �����
// (residual,residual) ��� () ��������� ������������ � R^n.
// �������� ���� ��������� ������ �������� �� �������� ������������� 
// ����. ��������� � ������ ����������� �� ��������� ����� �� �������
// ������ ������������ ������ (FVM). ������� ��� ��������� ����� ��������������
// ������������� ������� � ������ mysolverv0_03.c. ��� ������������� ���������� ��,
// ��� ���� �� ����� ������ ������ ������ ��� ������������ �������� ����������� �������,
// ����� ������� ��� ����������� �������� �������� ������� ��� ������� ������ �������� �������������
// �� ������ ����� �������� ��������� (����������). ��� ����� ���������.
// ��� ���������� ������ �������� ������� �������������������� ������� 1.0e-4
// �������� ���������� ������ �� CFX �� �������.
// ���� ����� �������� �� ������� ���������� ����� 1.0e-3.
// �������� ����� �� ������ �� CFX.
doublereal dterminatedTResudual = 1e-5; // ��� ��� Congruate Gradients � ����� BiCGStab_internal3.

doublereal globalEndTimeUnsteadyTemperatureCalculation = 1.0; // ���������� ����� ��� �������������� ������������� ������������� � ������ ����. 

// � ���� ���� ����� ������������ ���������� � ������
// �������� ��������� ����.
FILE *fp_statistic_convergence=NULL;
// � ���� ���� ����� �������������� ������ ����.
// ��� ����� ��� ������� ��������� �������� � ���������.
// �� �������� ���������� ��� ���� �������� ���������� � ���������� ��������������� ��������.
FILE *fp_log=NULL;

// ������������ ��� ��������� ������� 
// ������ ������������ �������������.
bool bsolid_static_only = false;

const integer inumcore = 2; // ����� ���� ����������
const bool bparallelizm_old = false;

// ��������� ������ �������:
typedef struct TPARBOUND {
	integer ileft_start = -1, ileft_finish = -2;
	integer iright_start = -1, iright_finish = -2;
	integer iseparate_start = -1, iseparate_finish = -2;
	bool active=false; // ���������� ������������.
} PARBOUND;


// ��������� ������ ������������ ��� �����������������.
typedef struct TPARDATA {
	integer ncore=2; // 1, 2, 4, 8.
	integer *inumerate=nullptr;
	// ��� ��� ncore==2;
	PARBOUND b0;
	// ��� ��� ncore==4;
	PARBOUND b00, b01;
	// ��� ��� ncore==8;
	PARBOUND b000, b001, b010, b011;
} PARDATA;

PARDATA nd;

// ������������ � ����� ��� ��������� �����.
doublereal* rthdsd_no_radiosity_patch = nullptr;

// ��� ��������� (���� bdroblenie4=true)
// ������ �� ����� ������ ����� ��������� � �������� ��������� ��������.
typedef struct TALICE_PARTITION {
	bool bdroblenie4=false;
	integer iNODE1=-1, iNODE2=-1, iNODE3=-1, iNODE4=-1;
} ALICE_PARTITION;


#include "adaptive_local_refinement_mesh.cpp" // ����
#include "constr_struct.cpp" // ���������� �������� ������ TEMPER � FLOW
#include "uniformsimplemeshgen.cpp" // �������� ���������

#include "my_LR.c" // ������������ �����

// 8 ������ 2016.
const bool bvery_big_memory = true; // true ��� ������ � ���� �� ������ � ����������� ������. ��� ����������� ������� �� ��������.

// ������ ����������� �������� ������ ���������� � ����� MenterSST.cpp.
const doublereal K_limiter_min = 1.0e-14; // 1.0e-14 Fluent limits
const doublereal Omega_limiter_min = 1.0; // 1.0; ����� ����� ������������. // 1.0e-20 Fluent limits
const doublereal Epsilon_limiter_min = 1.0e-20; // 1.0e-14; TODO ������� ���������... 1.0e-20 Fluent limits

UNION* my_union = nullptr; // ��� �����������.

// ���������� ����������
TEMPER t;
integer flow_interior = 0; // ��������� ����� FLUID ���
FLOW* f = nullptr;


// ������� �������� � ��������� tecplot360
#include "my_export_tecplot3.c"

#include "my_material_properties.c" // ���������� �������� ������� ����������


#include "my_linalg.cpp" // ���������� ������� �������� �������
// ��� �������: 
// eqsolve_simple_gauss - ������ ���� ������� ���������� ������
// eqsolv_simple_holesskii - ������ ���� ������� ���������� ����������

// ������������� ����������� ��������� ���������-��������
// �� ����������� �����
#include "pamendment3.c"

#include "shortest_distance.cpp" // ���������� ����������� ���������� �� ������


// ���������� � ������� ���������� ������� ������������ �� 
// icepak user guide.
typedef struct TFLUENT_RESIDUAL{
	// ������ ������� ���������� �� ������ ����� ������� ����.
	// ������� ������������� � ���������� FLUENT
	// �.�. ����������� �� ������� fluent.
	doublereal res_vx=1.0; // ������� X ��������
	doublereal res_vy=1.0; // ������� Y ��������
	doublereal res_vz=1.0; // ������� Z ��������
	doublereal res_no_balance=1.0; // ������������������ ��������� �����.
	doublereal operating_value_b=1.0; // �������� ������������������ ���������� ����� � ���������� ��������.
	doublereal res_nusha=1.0; // ������� ���������������� ������������ ������������ ��������.
	doublereal res_turb_kinetik_energy = 1.0; // ������� ������������ ������� ������������ ��������� � ������ SST K-Omega.
	doublereal res_turb_omega = 1.0; // ������� �������� �������� ���������� ������������ ������� ������������ ��������� � ������ SST K-Omega.
	doublereal res_turb_kinetik_energy_std_ke = 1.0; // ������� ������������ ������� ������������ ��������� � ����������� ������ k-epsilon
	doublereal res_turb_epsilon = 1.0; // ������� �������� ���������� ������������ ������� ������������ ��������� � ����������� ������ k-epsilon

} FLUENT_RESIDUAL;


// ���������� ��������
#include "mysolverv0_03.c"


// �������������� ������ ��� �����������
// �� ������ ������������� �������,
// � ����� �������������� ������ ��� 
// ������������� �� ������ ������������� �������.
#include "my_unsteady_temperature.c"

// ������������� ��� ������������ ���������.
#include "my_nested_dissection.cpp"

#include <ctime> // ��� ������ ������� ����������.

integer ltdp=0; // ���������� �������� �������� ��������� �� ����������� � �������� �����.
TEMP_DEP_POWER* gtdps=nullptr; // Garber temperature depend power sequence. 

// ���� ������ ����������:
integer lmatmax=0; // ������������ ����� ����������
TPROP* matlist=nullptr; // ��������� ���� ������ ����������

void check_data(TEMPER t) {
	if (t.potent != nullptr) {
		for (integer i = 0; i < t.maxelm + t.maxbound; i++) {
			if (t.potent[i] != t.potent[i]) {
				printf("t.potent[%lld] is %e\n",i, t.potent[i]);
				system("pause");
			}
		}
	}
} // check_data



int main_body(char ch_EXPORT_ALICE_ONLY = 'y') {
	//printLOGO();

	//system("PAUSE");

	

	// ���������� ������, ���������� � ������, �������.
	integer lb = 0, ls = 0, lw = 0, lu = 0;
	BLOCK* b = nullptr; // ������ ������
	SOURCE* s = nullptr; // ������ ����������
	WALL* w = nullptr; // ������ ������ ������

	// ��� ��� � ������ bFULL_AUTOMATIC ������� ������������ �������� �
	// ������� ������������ �������, �� �������� ������� ����������� ���� ���� ���, �
	// ��� ��������� ��������� ���� ��������� � ������ ���-�������.
	// 20mm ���� ��������� � 1��� 9� �� 53� �� ���� ������ bFULL_AUTOMATIC.
	// ���-������� ��� automatic
	// ��������� ����������� ������ ��� ���-�������.
	shorter_hash_X = new doublereal[isize_shorter_hash];
	shorter_hash_Y = new doublereal[isize_shorter_hash];
	shorter_hash_Z = new doublereal[isize_shorter_hash];
	bshorter_hash_X = new bool[isize_shorter_hash];
	bshorter_hash_Y = new bool[isize_shorter_hash];
	bshorter_hash_Z = new bool[isize_shorter_hash];


	// �������������, ���������� ��.
	pfpir.fmaximum = 1.0e+30;
	pfpir.fminimum = -1.0e+30;
	pfpir.idir = 1;


	// 22.01.2017 �������������.
	eqin.fluidinfo = nullptr;
	t.rootBT = nullptr;
	t.rootSN = nullptr;
	t.rootWE = nullptr;

	// 29 10 2016.
	// ������������� ����� ������ � ILU ������.
	milu_gl_buffer.alu_copy = nullptr;
	milu_gl_buffer.jlu_copy = nullptr;
	milu_gl_buffer.ju_copy = nullptr;

	my_amg_manager_init();

	// ����� �������.
	calculation_main_start_time_global_Depend = 0; // ������ ����� ��.
	unsigned int calculation_main_end_time = 0; // ��������� ����� ��.
	unsigned int calculation_main_seach_time = 0; // ����� ���������� ������� ���� � ��.

	calculation_main_start_time_global_Depend = clock(); // ������ ������ �����.

	bool bextendedprint = false; // ������ �� ��������� ����� ������������ �����.


	//std::locale::global(std::locale("en_US.UTF-8"));
	//system("mode con cols=166 lines=12000");
	// � ������� ��� ���� ����� �������� ���� ������ � ������� ����� ������� � ������� ���
	//HANDLE hOCol = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hOCol, FOREGROUND_GREEN);
	// ��������� ��������� ������� (����� ���)	
	//SetConsoleTextAttribute(hOCol, BACKGROUND_BLUE |
	//	BACKGROUND_GREEN |
	//	BACKGROUND_RED |
	//	BACKGROUND_INTENSITY);

	//system("cls");
	// ���������� � ���, ��� ����� ��� ���������� ���� ��� ��� ��������� �����.

	// ��� ��������.
	// �� ������ ������ �����������. 
	doublereal* xpos = nullptr, * ypos = nullptr, * zpos = nullptr;
	doublereal* xposadd = nullptr, * yposadd = nullptr, * zposadd = nullptr;


	printf("AliceFlow 3D x64 v0.48\n");
#ifdef _OPENMP 
	omp_set_num_threads(inumcore); // ��������� ����� �������
#endif

	errno_t err = 0;
#ifdef MINGW_COMPILLER
	fp_log = fopen64("log.txt", "w");
	if (fp_log == nullptr) err = 1;
#else
	err = fopen_s(&fp_log, "log.txt", "w");
#endif

	if (err != 0) {
		printf("Error open file log.txt\n");
		printf("Please, press any key to continue...\n");
		//system("PAUSE");
		system("pause");
		exit(0);
	}

	if (fp_log != nullptr) {

		//ilu0_Saadtest();
		//printf("the end Saad ilu0 test\n");
		//system("PAUSE");

		// ���������� ����� �� ������ �� ����.
		//integer inx=120, iny=64, inz=64;
		integer inx = 30, iny = 30, inz = 30;
		integer inxadd = -1, inyadd = -1, inzadd = -1;
		doublereal dgx = 0.0, dgy = 0.0, dgz = 0.0; // ���� �������
		doublereal operatingtemperature = 20.0; // Operating Temperature 20.0 ����. �.

		lu = 0;
		// lu, my_union
		loadFromFile();
		premeshin("premeshin.txt", lmatmax, lb, ls, lw, matlist, b, s, w,
			dgx, dgy, dgz, inx, iny, inz, operatingtemperature, ltdp, gtdps, lu, my_union);
		freeStringList();

		// ��������� ���� �� ����� �� ������� ��������
		// ����� ������, ������ � ���������� �����. 02.08.2019.
		BODY_CHECK(b, lb, w, lw, s, ls);

		init_QSBid(lb, b, w, lw, s, ls); // ��� ���������� ������ ������� myisblock_id.


		if ((steady_or_unsteady_global_determinant == 3) || (steady_or_unsteady_global_determinant == 9)) {
			// ��� ������� ��������� ������������� �� ������� ������ load.txt ����.
			remove("load.txt");
		}


		if (1 && steady_or_unsteady_global_determinant == 8) {
			// �������������� ����� � ������������ ����������.
			// ��� ��������� �������. 05.01.2018.
			tecplot360patcher_for_print_in_report();
			exit(1);
		}

		integer iCabinetMarker = 0;
		if (0 == iswitchMeshGenerator) {
			simplemeshgen(xpos, ypos, zpos, inx, iny, inz, lb, ls, lw, b, s, w, lu, my_union, matlist,
				xposadd, yposadd, zposadd, inxadd, inyadd, inzadd, iCabinetMarker);
		}
		else if (1 == iswitchMeshGenerator) {
			unevensimplemeshgen(xpos, ypos, zpos, inx, iny, inz, lb, ls, lw, b, s, w, lu, my_union, matlist,
				dgx, dgy, dgz, xposadd, yposadd, zposadd, inxadd, inyadd, inzadd, iCabinetMarker);
			// ��������� ������������� ����� � �������������� ������������� ���������������.
		}
		else if (2 == iswitchMeshGenerator) {
			// � ��������� ������� coarse Mesh ��� � Icepak.
			// �������� ������ ����������� ��������������-���������������, � 
			// ������� ������������� ���������� ����������� �����, �.�. CPU �������� � 4��� �
			// ���������� ����������������� ��������� ������� ������� ��������.
			coarsemeshgen(xpos, ypos, zpos, inx, iny, inz, lb, ls, lw, b, s, w, lu, my_union, matlist,
				xposadd, yposadd, zposadd, inxadd, inyadd, inzadd, iCabinetMarker);
		}
		else {
#if doubleintprecision == 1
			printf("error: yuor mesh generator is undefined %lld\n", iswitchMeshGenerator);
#else
			printf("error: yuor mesh generator is undefined %d\n", iswitchMeshGenerator);
#endif

			system("pause");
			exit(1);
		}


		// ������ ��������� ����� � ������������.
		for (integer iu = 0; iu < lu; iu++) {
			my_union[iu].inxadd = -1;
			my_union[iu].inyadd = -1;
			my_union[iu].inzadd = -1;
			my_union[iu].xposadd = nullptr;
			my_union[iu].yposadd = nullptr;
			my_union[iu].zposadd = nullptr;
			my_union[iu].xpos = nullptr;
			my_union[iu].ypos = nullptr;
			my_union[iu].zpos = nullptr;
			integer iup1 = iu + 1;
			switch (my_union[iu].iswitchMeshGenerator) {
			case 0: simplemeshgen(my_union[iu].xpos, my_union[iu].ypos, my_union[iu].zpos,
				my_union[iu].inx, my_union[iu].iny, my_union[iu].inz, lb, ls, lw, b, s, w, lu, my_union, matlist,
				my_union[iu].xposadd, my_union[iu].yposadd, my_union[iu].zposadd, my_union[iu].inxadd,
				my_union[iu].inyadd, my_union[iu].inzadd, iup1);
				break;
			case 1: unevensimplemeshgen(my_union[iu].xpos, my_union[iu].ypos, my_union[iu].zpos, my_union[iu].inx,
				my_union[iu].iny, my_union[iu].inz, lb, ls, lw, b, s, w, lu, my_union, matlist,
				dgx, dgy, dgz, my_union[iu].xposadd, my_union[iu].yposadd, my_union[iu].zposadd,
				my_union[iu].inxadd, my_union[iu].inyadd, my_union[iu].inzadd, iup1);
				// ��������� ������������� ����� � �������������� ������������� ���������������.
				break;
			case 2: coarsemeshgen(my_union[iu].xpos, my_union[iu].ypos, my_union[iu].zpos,
				my_union[iu].inx, my_union[iu].iny, my_union[iu].inz, lb, ls, lw, b, s, w, lu, my_union, matlist,
				my_union[iu].xposadd, my_union[iu].yposadd, my_union[iu].zposadd, my_union[iu].inxadd,
				my_union[iu].inyadd, my_union[iu].inzadd, iup1);
				break;
			default:
				coarsemeshgen(my_union[iu].xpos, my_union[iu].ypos, my_union[iu].zpos,
					my_union[iu].inx, my_union[iu].iny, my_union[iu].inz, lb, ls, lw, b, s, w, lu, my_union, matlist,
					my_union[iu].xposadd, my_union[iu].yposadd, my_union[iu].zposadd, my_union[iu].inxadd,
					my_union[iu].inyadd, my_union[iu].inzadd, iup1);
				break;
			}
			// ��������� ������������ ������ addboundary_rudiment � �� addboundary, ��� ��� � �������� ����� 
			// �������� �� ����������� ��� ���������� ����� ��������. 14.03.2019.
			// ����������� ��������� ����� ���������� �������� ����� ����� �������. 
			// ��������� �������� ����� ����������� �������� ��� ��������� �������� �������������.
			for (integer i76 = 0; i76 <= inx; i76++) {
				// ��������� ���������� �������� ����� ��������.
				if ((xpos[i76] >= my_union[iu].xS) && (xpos[i76] <= my_union[iu].xE)) {
					addboundary_rudiment(my_union[iu].xpos, my_union[iu].inx, xpos[i76], YZ, b, lb, w, lw, s, ls);
				}
			}
			Sort_method(my_union[iu].xpos, my_union[iu].inx);
			for (integer i76 = 0; i76 <= iny; i76++) {
				// ��������� ���������� �������� ����� ��������.
				if ((ypos[i76] >= my_union[iu].yS) && (ypos[i76] <= my_union[iu].yE)) {
					addboundary_rudiment(my_union[iu].ypos, my_union[iu].iny, ypos[i76], XZ, b, lb, w, lw, s, ls);
				}
			}
			Sort_method(my_union[iu].ypos, my_union[iu].iny);
			for (integer i76 = 0; i76 <= inz; i76++) {
				// ��������� ���������� �������� ����� ��������.
				if ((zpos[i76] >= my_union[iu].zS) && (zpos[i76] <= my_union[iu].zE)) {
					addboundary_rudiment(my_union[iu].zpos, my_union[iu].inz, zpos[i76], XY, b, lb, w, lw, s, ls);
				}
			}
			Sort_method(my_union[iu].zpos, my_union[iu].inz);
		}



		if (b_on_adaptive_local_refinement_mesh) {
			// ������ 1TT113 22.03.2018:
			// AliceCorse 1266911 ����, � ����������������� ���������� 93592. 
			// 40��� 33� ������ ���������� �������������� �� 10000�.
			// ����� ���������� ����� 2��� 6�. 14 ������� ��������.
			// AliceFine 1092571 ����, � ����������������� ���������� 8050.
			// AliceFine (��������� �����) 1335076 ����, � ����������������� ���������� 93448.
			// ����� ���������� ����� 4��� 25�. 14 ������� ��������.
			// ����� ���������� ����� (��������� �����) 6��� 32�. 14 ������� ��������.



			printf("starting ALICE\n");
			if (0) {
				if (1 == itype_ALICE_Mesh) {
					// ��� ������ �� � ���� ������ ������ �� ������� �������� ����������� ������.
					doublereal* xpos_copy = nullptr;
					// 10 ������� ������� �������� ���������.
					const integer jiterM = my_amg_manager.nu1_Temperature;
					// ������������� ��������� ������� ��������� �������.
					for (integer jiter = 0; jiter < jiterM; jiter++) {
						xpos_copy = new doublereal[2 * (inx + 1) - 1];
						for (integer i74 = 0; i74 < inx; i74++) {
							xpos_copy[2 * i74] = xpos[i74];
							xpos_copy[2 * i74 + 1] = 0.5 * (xpos[i74] + xpos[i74 + 1]);
						}
						xpos_copy[2 * (inx + 1) - 2] = xpos[inx];
						delete[] xpos;
						xpos = nullptr;
						xpos = new doublereal[2 * (inx + 1) - 1];
						for (integer i74 = 0; i74 < 2 * (inx + 1) - 1; i74++) {
							xpos[i74] = xpos_copy[i74];
						}
						delete[] xpos_copy;
						xpos_copy = nullptr;
						inx = 2 * (inx + 1) - 2;
					}

					for (integer jiter = 0; jiter < jiterM; jiter++) {
						xpos_copy = new doublereal[2 * (iny + 1) - 1];
						for (integer i74 = 0; i74 < iny; i74++) {
							xpos_copy[2 * i74] = ypos[i74];
							xpos_copy[2 * i74 + 1] = 0.5 * (ypos[i74] + ypos[i74 + 1]);
						}
						xpos_copy[2 * (iny + 1) - 2] = ypos[iny];
						delete[] ypos;
						ypos = nullptr;
						ypos = new doublereal[2 * (iny + 1) - 1];
						for (integer i74 = 0; i74 < 2 * (iny + 1) - 1; i74++) {
							ypos[i74] = xpos_copy[i74];
						}
						delete[] xpos_copy;
						xpos_copy = nullptr;
						iny = 2 * (iny + 1) - 2;
					}

					for (integer jiter = 0; jiter < jiterM; jiter++) {
						xpos_copy = new doublereal[2 * (inz + 1) - 1];
						for (integer i74 = 0; i74 < inz; i74++) {
							xpos_copy[2 * i74] = zpos[i74];
							xpos_copy[2 * i74 + 1] = 0.5 * (zpos[i74] + zpos[i74 + 1]);
						}
						xpos_copy[2 * (inz + 1) - 2] = zpos[inz];
						delete[] zpos;
						zpos = nullptr;
						zpos = new doublereal[2 * (inz + 1) - 1];
						for (integer i74 = 0; i74 < 2 * (inz + 1) - 1; i74++) {
							zpos[i74] = xpos_copy[i74];
						}
						delete[] xpos_copy;
						xpos_copy = nullptr;
						inz = 2 * (inz + 1) - 2;
					}
				}
			}

			// ��� ������� ������� �������� �� ������ ������������ �������,
			// � ������ �������� �� ��������� ���� � ��������� new ��� malloc.
			integer maxelm_loc = (inx + 1) * (iny + 1) * (inz + 1);
			bool bOkal = alice_mesh(xpos, ypos, zpos, inx, iny, inz, b, lb, lw, w, s, ls, maxelm_loc, xposadd, yposadd, zposadd, inxadd, inyadd, inzadd);
			//system("PAUSE");



			if (0 || itype_ALICE_Mesh == 1/*1*/) {
				// �������� ��������� ���������.

				/*
				����� ���� ������� ����������� �� ��������� �������� �����
				��� ������� ������������������� �������� ����� ������������
				�� �� ����� ������������� ���� ��������� AliceMedium �����
				� ��� ��������� ���������� � ����� �������� ����� �� ����������.
				��� ���� ����� �������� ����� �� ��������� ���������� �����
				� ��� ������ ����� ����� ��������� ��������.
				17.08.2019
				*/
				doublereal dSTOP_flag1 = 1.0e+4; // ����� ���������� �����.
				doublereal dSTOP_flag2 = 1.0e+1; // ����� ���������� �����.

				while (!bOkal) {
					printf("repeat call ALICE...\n");
					//system("PAUSE");

					/* 3.09.2017
					���� ����� ����� ������� ����� ��� ��������� ������ ��������������� �������������� ����� �������
					����� �������. ������ ������� ������� ������������� ������ � ���������� ���� �� ����� ����������� �������������
					����� ���� ������ ���� ����� ������ ���������. � ���������� �������� ������������� ����������� ��������. ������ �����
					��������� ������� ������ �������������� ����� ����� �� ������� ����� ����� ��� ������������ ����� (�.�. ����� ����������
					��� ���������� ����� �������� ����� ������� ����� ������ �������� ����� ���������� �� ����� ��� �� 1. ������� ������
					����� ����������� ��� ��������� ������ ������ � ������� if_disbalnce(...) � ��� ������ ����� ������ ����������� �������
					�������� ��������������� ����� �������� �����. �������� ����������� ������ � ������������ �� �������� ������� � ����������
					���� ����� ���������� ������ ������ ������ ������� ����� ��� �������� ����������� �������� �����.
					*/


					// ����� ���������� ������ �� ��� octree ������ � ����������� �����.
					printf("free octree start...\n");
					//system("PAUSE");
					//system("PAUSE");
					free_octree(oc_global, maxelm_loc);
					delete[] my_ALICE_STACK;
					top_ALICE_STACK = 0;
					printf("free octree end...\n");
					doublereal t_1 = NormaV(xpos, inx + 1);
					doublereal t_2 = NormaV(ypos, iny + 1);
					doublereal t_3 = NormaV(zpos, inz + 1);
					dSTOP_flag2 = sqrt(t_1 * t_1 + t_2 * t_2 + t_3 * t_3);
					printf("comparison mesh %e \n", fabs(dSTOP_flag2 - dSTOP_flag1));
					//system("pause");

					// ����� ���������� ��������� �����.
					delete[] xpos;
					xpos = nullptr;
					inx = 0;
					delete[] ypos;
					ypos = nullptr;
					iny = 0;
					delete[] zpos;
					zpos = nullptr;
					inz = 0;

					printf("free xpos, ypos, zpos\n");
					//system("PAUSE");

					integer iCabinetMarker = 0;
					if (0 == iswitchMeshGenerator) {
						simplemeshgen(xpos, ypos, zpos, inx, iny, inz, lb, ls, lw, b, s, w, lu, my_union,
							matlist, xposadd, yposadd, zposadd, inxadd, inyadd, inzadd, iCabinetMarker);
					}
					else if (1 == iswitchMeshGenerator) {
						unevensimplemeshgen(xpos, ypos, zpos, inx, iny, inz, lb, ls, lw, b, s, w, lu, my_union,
							matlist, dgx, dgy, dgz, xposadd, yposadd, zposadd, inxadd, inyadd, inzadd, iCabinetMarker); // ��������� ������������� ����� � �������������� ������������� ���������������.
					}
					else if (2 == iswitchMeshGenerator) {
						// � ��������� ������� coarse Mesh ��� � ANSYS Icepak.
						// �������� ������ ����������� ��������������-���������������, � 
						// ������� ������������� ���������� ����������� �����, �.�. CPU �������� � 4��� �
						// ���������� ����������������� ��������� ������� ������� ��������.
						coarsemeshgen(xpos, ypos, zpos, inx, iny, inz, lb, ls, lw, b, s, w, lu, my_union,
							matlist, xposadd, yposadd, zposadd, inxadd, inyadd, inzadd, iCabinetMarker);
					}
					else {
#if doubleintprecision == 1
						printf("error: yuor mesh generator is undefined %lld\n", iswitchMeshGenerator);
#else
						printf("error: yuor mesh generator is undefined %d\n", iswitchMeshGenerator);
#endif

						system("pause");
						exit(1);
					}
					// ����� ������ ���� �����������.

					printf("new construct xpos, ypos, zpos\n");
					//system("PAUSE");

					bOkal = alice_mesh(xpos, ypos, zpos, inx, iny, inz, b, lb, lw, w, s, ls, maxelm_loc, xposadd, yposadd, zposadd, inxadd, inyadd, inzadd);

					if (fabs(dSTOP_flag2 - dSTOP_flag1) < 1.0e-20) {
						bOkal = true;
						break;
					}
					dSTOP_flag1 = dSTOP_flag2;

					//system("PAUSE");
				}
			}
			printf("end ALICE\n");
		}

		iCabinetMarker = 0;
		load_TEMPER_and_FLOW(t, f, inx, iny, inz, xpos, ypos, zpos, flow_interior,
			b, lb, lw, w, s, ls, lu, my_union, operatingtemperature, matlist, bextendedprint,
			dgx, dgy, dgz, b_on_adaptive_local_refinement_mesh, false, iCabinetMarker);

		t.operatingtemperature = operatingtemperature;


		for (integer iu = 0; iu < lu; iu++) {
			integer iup1 = iu + 1;
			load_TEMPER_and_FLOW(my_union[iu].t, my_union[iu].f,
				my_union[iu].inx, my_union[iu].iny, my_union[iu].inz,
				my_union[iu].xpos, my_union[iu].ypos, my_union[iu].zpos,
				my_union[iu].flow_interior,
				b, lb, lw, w, s, ls, lu, my_union, operatingtemperature, matlist, bextendedprint,
				dgx, dgy, dgz, b_on_adaptive_local_refinement_mesh, false, iup1);

			my_union[iu].t.operatingtemperature = operatingtemperature;
		}




		// ��� ����� ������ ����� ��� ������� �������������� ������.
		t.inx_copy = inx;
		t.iny_copy = iny;
		t.inz_copy = inz;
		t.operatingtemperature_copy = operatingtemperature;
		t.xpos_copy = new doublereal[inx + 1];
		t.ypos_copy = new doublereal[iny + 1];
		t.zpos_copy = new doublereal[inz + 1];
		// ������ ���������� ����� ��� �������� ����������� ������,
		// ��������� ������ ����� ��������� �� ��� � ����� ������������� 
		// ���� ����������.
		for (integer i_7 = 0; i_7 < inx + 1; i_7++) {
			t.xpos_copy[i_7] = xpos[i_7];
		}
		for (integer i_7 = 0; i_7 < iny + 1; i_7++) {
			t.ypos_copy[i_7] = ypos[i_7];
		}
		for (integer i_7 = 0; i_7 < inz + 1; i_7++) {
			t.zpos_copy[i_7] = zpos[i_7];
		}

		for (integer iu = 0; iu < lu; iu++) {
			// ��� ����� ������ ����� ��� ������� �������������� ������.
			my_union[iu].t.inx_copy = my_union[iu].inx;
			my_union[iu].t.iny_copy = my_union[iu].iny;
			my_union[iu].t.inz_copy = my_union[iu].inz;
			my_union[iu].t.operatingtemperature_copy = operatingtemperature;
			my_union[iu].t.xpos_copy = new doublereal[my_union[iu].inx + 1];
			my_union[iu].t.ypos_copy = new doublereal[my_union[iu].iny + 1];
			my_union[iu].t.zpos_copy = new doublereal[my_union[iu].inz + 1];
			// ������ ���������� ����� ��� �������� ����������� ������,
			// ��������� ������ ����� ��������� �� ��� � ����� ������������� 
			// ���� ����������.
			for (integer i_7 = 0; i_7 < my_union[iu].inx + 1; i_7++) {
				my_union[iu].t.xpos_copy[i_7] = my_union[iu].xpos[i_7];
			}
			for (integer i_7 = 0; i_7 < my_union[iu].iny + 1; i_7++) {
				my_union[iu].t.ypos_copy[i_7] = my_union[iu].ypos[i_7];
			}
			for (integer i_7 = 0; i_7 < my_union[iu].inz + 1; i_7++) {
				my_union[iu].t.zpos_copy[i_7] = my_union[iu].zpos[i_7];
			}
		}

		// ������������ ����������� ������ �� ��� octree ������.
		if (b_on_adaptive_local_refinement_mesh) {
			printf("free octree start...\n");
			//system("PAUSE");
			//system("PAUSE");
			integer maxelm_loc = (inx + 1) * (iny + 1) * (inz + 1);
			free_octree(oc_global, maxelm_loc);
			delete[] my_ALICE_STACK;
			top_ALICE_STACK = 0;
			printf("free octree end...\n");
			//system("PAUSE");
			//system("PAUSE");
		}

		if (0) {
			xyplot(f, flow_interior, t);
			printf("after load temper and flow. OK.\n");
			//system("PAUSE"); // debug avtosave
			system("pause");
		}

		// �� ���� ����� ���������� ����� �� �������� ���������������.
		if (!b_on_adaptive_local_refinement_mesh) {
			// ������ ���������� � �������� ������ ��� ������������� ������ LR:
			if (2 == iswitchsolveramg_vs_BiCGstab_plus_ILU2) {
				// Lr1sk algorithm
				constr_line(f, flow_interior);  // ��� �������������
			}
			t.rootBT = nullptr;
			t.rootSN = nullptr;
			t.rootWE = nullptr;
			if (2 == iswitchsolveramg_vs_BiCGstab_plus_ILU2) {
				// Lr1sk algorithm
				constr_line_temp(t, b, lb); // ��� ����������������
				printf("LR preprocessing finish...\n");
			}
		}

		// ���������� ������ ��� ��������������� �������������� ������.

		amgGM.a = nullptr;
		amgGM.f = nullptr;
		amgGM.ia = nullptr;
		amgGM.ig = nullptr;
		amgGM.ja = nullptr;
		amgGM.u = nullptr;
		amgGM.nda = -1;
		amgGM.ndf = -1;
		amgGM.ndia = -1;
		amgGM.ndig = -1;
		amgGM.ndja = -1;
		amgGM.ndu = -1;


		//PARDATA nd;
		nd.ncore = 2; // ��� ����.
		// �� ��������� ��� ��������� ���������.
		nd.b0.active = false;
		nd.b00.active = false;
		nd.b01.active = false;
		nd.b000.active = false;
		nd.b001.active = false;
		nd.b010.active = false;
		nd.b011.active = false;
		if (0 && (1 == flow_interior)) {
			calc_front(f, f[0], t, flow_interior, ls, lw, w, nd, b, lb, s);
			// ���������� ��������� !
			printf("separator compleate...\n");
			//system("PAUSE");
		}



		t.free_temper_level1 = false; // ������ ���������������� ������������ ������ ����������� ��� ������ ������� ����� �������� ������.
		t.free_temper_level2 = false; // ������������ ������ ��� �������� ������� ��� ���������� � � SIMPLESPARSE ������.	

		printf("construction of all structures...\n");
		printf("mesh check start...\n");
		const doublereal d_zalipanie = 1.0e-23;// ������
#if doubleintprecision == 1
		doublereal minimum_gap = 1.0e60;
		for (integer i = 0; i < inx; i++) {
			if ((xpos[i + 1] - xpos[i]) < minimum_gap) minimum_gap = (xpos[i + 1] - xpos[i]);
			if ((xpos[i + 1] - xpos[i]) < d_zalipanie) {
				//printf("error: zalipanie po X: xpos[%lld]=%e xpos[%lld]=%e inx=%lld\n", i, xpos[i], i + 1, xpos[i + 1], inx);
				std::cout << "error: zalipanie po X: xpos[" << i << "]=" << xpos[i] << " xpos[" << i + 1 << "]=" << xpos[i + 1] << " inx=" << inx << std::endl;
				std::cout << "tolerance zalipanie=" << d_zalipanie << std::endl;
				system("pause");
			}
		}
		std::cout << "minimum gap X=" << minimum_gap << std::endl;
		minimum_gap = 1.0e60;
		for (integer i = 0; i < iny; i++) {
			if ((ypos[i + 1] - ypos[i]) < minimum_gap) minimum_gap = (ypos[i + 1] - ypos[i]);
			if ((ypos[i + 1] - ypos[i]) < d_zalipanie) {
				//printf("error: zalipanie po Y: ypos[%lld]=%e ypos[%lld]=%e iny=%lld\n", i, ypos[i], i + 1, ypos[i + 1], iny);
				std::cout << "error: zalipanie po Y: ypos[" << i << "]=" << ypos[i] << " ypos[" << i + 1 << "]=" << ypos[i + 1] << " iny=" << iny << std::endl;
				std::cout << "tolerance zalipanie=" << d_zalipanie << std::endl;
				system("pause");
			}
		}
		std::cout << "minimum gap Y=" << minimum_gap << std::endl;
		minimum_gap = 1.0e60;
		for (integer i = 0; i < inz; i++) {
			if ((zpos[i + 1] - zpos[i]) < minimum_gap) minimum_gap = (zpos[i + 1] - zpos[i]);
			if ((zpos[i + 1] - zpos[i]) < d_zalipanie) {
				//printf("error: zalipanie po Z: zpos[%lld]=%e zpos[%lld]=%e inz=%lld\n", i, zpos[i], i + 1, zpos[i + 1], inz);
				std::cout << "error: zalipanie po Z: zpos[" << i << "]=" << zpos[i] << " zpos[" << i + 1 << "]=" << zpos[i + 1] << " inz=" << inz << std::endl;
				std::cout << "tolerance zalipanie=" << d_zalipanie << std::endl;
				system("pause");
			}
		}
		std::cout << "minimum gap Z=" << minimum_gap << std::endl;
		for (integer iP = 0; iP < t.maxelm; iP++) {
			if ((t.nvtx[0][iP] == 0) || (t.nvtx[1][iP] == 0) || (t.nvtx[2][iP] == 0) || (t.nvtx[3][iP] == 0) || (t.nvtx[4][iP] == 0) || (t.nvtx[5][iP] == 0) || (t.nvtx[6][iP] == 0) || (t.nvtx[7][iP] == 0)) {
				printf("nvtx[%lld]: %lld %lld %lld %lld %lld %lld %lld %lld \n", iP, t.nvtx[0][iP] - 1, t.nvtx[1][iP] - 1, t.nvtx[2][iP] - 1, t.nvtx[3][iP] - 1, t.nvtx[4][iP] - 1, t.nvtx[5][iP] - 1, t.nvtx[6][iP] - 1, t.nvtx[7][iP] - 1);
			}
		}
#else
		doublereal minimum_gap = 1.0e60;
		for (integer i = 0; i < inx; i++) {
			if ((xpos[i + 1] - xpos[i]) < minimum_gap) minimum_gap = (xpos[i + 1] - xpos[i]);
			if ((xpos[i + 1] - xpos[i]) < d_zalipanie) {
				//printf("error: zalipanie po X: xpos[%d]=%e xpos[%d]=%e inx=%d\n", i, xpos[i], i + 1, xpos[i + 1], inx);
				std::cout << "error: zalipanie po X: xpos[" << i << "]=" << xpos[i] << " xpos[" << i + 1 << "]=" << xpos[i + 1] << " inx=" << inx << std::endl;
				std::cout << "tolerance zalipanie=" << d_zalipanie << std::endl;
				system("pause");
			}
		}
		std::cout << "minimum gap X=" << minimum_gap << std::endl;
		minimum_gap = 1.0e60;
		for (integer i = 0; i < iny; i++) {
			if ((ypos[i + 1] - ypos[i]) < minimum_gap) minimum_gap = (ypos[i + 1] - ypos[i]);
			if ((ypos[i + 1] - ypos[i]) < d_zalipanie) {
				//	printf("error: zalipanie po Y: ypos[%d]=%e ypos[%d]=%e iny=%d\n", i, ypos[i], i + 1, ypos[i + 1], iny);
				std::cout << "error: zalipanie po Y: ypos[" << i << "]=" << ypos[i] << " ypos[" << i + 1 << "]=" << ypos[i + 1] << " iny=" << iny << std::endl;
				std::cout << "tolerance zalipanie=" << d_zalipanie << std::endl;
				system("pause");
			}
		}
		std::cout << "minimum gap Y=" << minimum_gap << std::endl;
		minimum_gap = 1.0e60;
		for (integer i = 0; i < inz; i++) {
			if ((zpos[i + 1] - zpos[i]) < minimum_gap) minimum_gap = (zpos[i + 1] - zpos[i]);
			if ((zpos[i + 1] - zpos[i]) < d_zalipanie) {
				//		printf("error: zalipanie po Z: zpos[%d]=%e zpos[%d]=%e inz=%d\n", i, zpos[i], i + 1, zpos[i + 1], inz);
				std::cout << "error: zalipanie po Z: zpos[" << i << "]=" << zpos[i] << " zpos[" << i + 1 << "]=" << zpos[i + 1] << " inz=" << inz << std::endl;
				std::cout << "tolerance zalipanie=" << d_zalipanie << std::endl;
				system("pause");
			}
		}
		std::cout << "minimum gap Z=" << minimum_gap << std::endl;
		for (integer iP = 0; iP < t.maxelm; iP++) {
			if ((t.nvtx[0][iP] == 0) || (t.nvtx[1][iP] == 0) || (t.nvtx[2][iP] == 0) || (t.nvtx[3][iP] == 0) || (t.nvtx[4][iP] == 0) || (t.nvtx[5][iP] == 0) || (t.nvtx[6][iP] == 0) || (t.nvtx[7][iP] == 0)) {
				printf("nvtx[%d]: %d %d %d %d %d %d %d %d \n", iP, t.nvtx[0][iP] - 1, t.nvtx[1][iP] - 1, t.nvtx[2][iP] - 1, t.nvtx[3][iP] - 1, t.nvtx[4][iP] - 1, t.nvtx[5][iP] - 1, t.nvtx[6][iP] - 1, t.nvtx[7][iP] - 1);
			}
		}
#endif


		// �� ����� ������ ������ ���� � ��������� ����������� ������� �������������.
		// ������� ������������� O(h!2) ������� ������� ������������ ��������� ������������ ������,
		// �.�. ������� �� ����������� ��������� �����.
		for (integer i = 0; i < flow_interior; i++) {
#if doubleintprecision == 1
			printf("FLUID %lld\n", i);
#else
			printf("FLUID %d\n", i);
#endif

			// �������� � ������� ���������������� ��������� ��� �������� ��������.
			f[i].resICCG = rterminate_residual_ICCG_Oh2(f[i]); // O(h!2)
			//printf("residual O(h!2) is equal=%e\n", f[i].resICCG);
			std::cout << "residual O(h!2) is equal=" << f[i].resICCG << std::endl;
			f[i].resLR1sk = rterminate_residual_LR1sk_Oh3(f[i]); // O(h!3)
			//printf("residual O(h!3) is equal=%e\n", f[i].resLR1sk);
			std::cout << "residual O(h!3) is equal=" << f[i].resLR1sk << std::endl;
		}
		printf("TEMPERATURE\n");
		t.resLR1sk = rterminate_residual_LR1sk_temp_Oh3(t); // O(h!3)		
		//printf("temp residual O(h!3) is equal=%e\n", t.resLR1sk);
		std::cout << "temp residual O(h!3) is equal=" << t.resLR1sk << std::endl;
		printf("mesh check.\n");
		if (bwait) {
			//system("PAUSE");
			system("pause");
		}

		sourse2Dproblem = new bool[t.maxbound];
		conductivity2Dinsource = new doublereal[t.maxbound];
		// ������ ���������� ������������� ����� ��� ������������ �������.
		bsource_term_radiation_for_relax = new doublereal[t.maxelm];
		for (integer i_init = 0; i_init < t.maxelm; i_init++) bsource_term_radiation_for_relax[i_init] = 0.0;
		b_buffer_correct_source = new doublereal[t.maxelm];


		// ������� continity ����� ���������� �� ��������� � ������ 1e0.
		doublereal* continity_start = nullptr;
		continity_start = new doublereal[flow_interior];
		if (continity_start == nullptr) {
			// ������������ ������ �� ������ ������������.
			printf("Problem: not enough memory on your equipment for continity start in main...\n");
			printf("Please any key to exit...\n");
			exit(1);
		}
		for (integer i = 0; i < flow_interior; i++) continity_start[i] = 1.0;

		integer* inumber_iteration_SIMPLE = nullptr;
		inumber_iteration_SIMPLE = new integer[flow_interior];
		if (nullptr == inumber_iteration_SIMPLE) {
			// ������������ ������ �� ������ ������������.
			printf("Problem: not enough memory on your equipment for inumber_iteration_SIMPLE in main...\n");
			printf("Please any key to exit...\n");
			exit(1);
		}
		for (integer i = 0; i < flow_interior; i++) inumber_iteration_SIMPLE[i] = 0; // ��������� �������� ��������� SIMPLE ��� ������ FLUID ����.

		// ���������� ��������� ������� �� ����� ��� ������������� �������
		bool breadOk = false;
		avtoreadvalue(f, t, flow_interior, inumber_iteration_SIMPLE, continity_start, breadOk, b, lb, s, ls, w, lw);
		// ���� ���������� ������ ���������, �� breadOk==false � ��� ������ ��� ���� �������� ������ �� �������� �������� ��� �������������.

		if (b_on_adaptive_local_refinement_mesh) {
			// ��������� ������������ ���� �����.
			printf("the invariant correctness...\n");
			ANES_ALICE_CORRECT(t.maxnod, t.pa, t.maxelm, t.nvtx);
		}

		// ������� ���������� ���������� � ��������� tecplot360:
		// ����� ������������ ��� �������� ����������� �����.
		if (0) {
			exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, b, lb);
			printf("read values. OK.\n");
			//system("PAUSE"); // debug avtosave
			system("pause");
		}



		/*for (integer i=0; i<lw; i++) {
		printf("%e  \n",w[i].Tamb);
		}
		//exporttecplotxy360T_3D(t.maxelm, t.ncell, t.nvtx, t.nvtxcell, t.pa, t.potent);
		exporttecplotxy360T_3D_part2(t.maxelm, t.potent);
		system("PAUSE"); // debug
		*/

		// 29.01.2017
		// if (1 && steady_or_unsteady_global_determinant == 2)  
		// �� �� ������ �������� ����� �� ������� �������.
		if (1 && 2 == steady_or_unsteady_global_determinant) {
			// ����� �������.
			unsigned int calculation_start_time = 0; // ������ ����� ��.
			unsigned int calculation_end_time = 0; // ��������� ����� ��.
			unsigned int calculation_seach_time = 0; // ����� ���������� ������� ���� � ��.

			calculation_start_time = clock(); // ������ ������ �����.

			// ������������ ������� ����������� ��������� ������������ � .stl �������.
			// 09.09.2019.
			export_User_Geom_in_STL_format(t);

			// ���������� ����� ������.
			massa_cabinet(t, f, inx, iny, inz,
				xpos, ypos, zpos, flow_interior,
				b, lb, operatingtemperature,
				matlist);

			calculation_end_time = clock(); // ������ ��������� �����.
			calculation_seach_time = calculation_end_time - calculation_start_time;
			unsigned int im = 0, is = 0, ims = 0;
			im = (unsigned int)(calculation_seach_time / 60000); // ������
			is = (unsigned int)((calculation_seach_time - 60000 * im) / 1000); // �������
			ims = (unsigned int)((calculation_seach_time - 60000 * im - 1000 * is) / 10); // ������������ ������� �� 10

			printf("time export to tecplot360 is:  %u minute %u second %u millisecond\n", im, is, 10 * ims);

			// ������� ����� � tecplot 360.
			if (1) {
				if (!b_on_adaptive_local_refinement_mesh) {
					if (0 == lu) {
						// ������� ���������� ���������� � ��������� tecplot360:
						exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, b, lb);
					}
					else {
						//exporttecplotxy360T_3D_part2_assembles(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, lu, my_union);
						// ����� ��� ��������.
						exporttecplot_assembles_mesh(t, lu, my_union);
					}
				}
				else {
					// ������� � ��������� tecplot �����������.
					//� ���� �����.
					//ANES_tecplot360_export_temperature(t.maxnod, t.pa, t.maxelm, t.nvtx, t.potent, t,0,b,lb);
				}
			}


		}

		//char ch_EXPORT_ALICE_ONLY = 'y';

		// steady Temperature Finite Volume Method
		if (1 && (0 == steady_or_unsteady_global_determinant) && (1==eqin.itemper)) {

			// ����� �������.
			unsigned int calculation_start_time = 0; // ������ ����� ��.
			unsigned int calculation_end_time = 0; // ��������� ����� ��.
			unsigned int calculation_seach_time = 0; // ����� ���������� ������� ���� � ��.

			calculation_start_time = clock(); // ������ ������ �����.

			for (integer i7 = 0; i7 < t.maxelm + t.maxbound; i7++) t.potent[i7] = operating_temperature_for_film_coeff; // �������������.

			// ������ ������ ������������� � ������ ����.
			bonly_solid_calculation = true;

			// �������� ����������� ���������� �� ����������� ������.
			if (1 == lw) {
				bPhysics_stop = true;
				if (lb < 11) {
					// ��� ����������� ��������:
					// MD40, AuSn, Cu, AuSn, SiC, GaN. cabinet and hollow.
					bPhysics_PTBSH_memory = true;
				}
			}

			if (adiabatic_vs_heat_transfer_coeff == 1) {
				// �� �������������� ��������� ��������� ����� ��������� �� ��������������� ��� ������ ������ ����.
				//for (integer i7 = 0; i7<t.maxelm + t.maxbound; i7++) t.potent[i7] = 0.57*operating_temperature_for_film_coeff;
			}

			// ����� �������������� ��� �� ������ ������������ ������ ������ ����������������.
			bsolid_static_only = true;
			bool bcleantemp = false;
			// ������� ��� ����������� ����.
			//if (1 == eqin.itemper) 
			{
				bcleantemp = true;
				for (integer i = 0; i < flow_interior; i++) {
					if (1 == eqin.fluidinfo[i].iflow) bcleantemp = false;
				}
				// ���� bcleantemp==true �� �� ������ ������ ������ ������������� ��� ����� ���������.
			}

			if (1 || bcleantemp) {
				// ������� ������������ ���������� (��� ��������) ������ ������ ���������������� � ��������� �������. 
				printf("solution of pure heat...\n");
				printf("please, press any key to continue...\n");
				if (bwait) {
					//system("PAUSE");
					system("pause");
				}

				// ��� ������������ ������������� ����������� ��������.
				bool bprintmessage = true; // �������� �� ��������� �� �������.

				doublereal dbeta = 1.0; // ������ ������� ������������� �� �������.
				bool bmyconvective = false;
				if (starting_speed_Vx * starting_speed_Vx + starting_speed_Vy * starting_speed_Vy + starting_speed_Vz * starting_speed_Vz > 1.0e-30) {
					if (f[0].maxelm > 0) {
						bmyconvective = true;
					}
				}
				else {
					// �������� ������������� ��������� ��������.
					errno_t err_inicialization_data = 0;
					FILE* fp_inicialization_data = NULL;
#ifdef MINGW_COMPILLER
					fp_inicialization_data = fopen64("load.txt", "r");
					if (fp_inicialization_data == NULL) err_inicialization_data = 1;
#else
					err_inicialization_data = fopen_s(&fp_inicialization_data, "load.txt", "r");
#endif
					if (0 == err_inicialization_data) {
						// �������� ������ � ���� ������������.
						if (f[0].maxelm > 0) {
							// ������ � ������ ������� ������ ����� �� ������ ������ � ����������.
							bmyconvective = true;
						}
						fclose(fp_inicialization_data);
					}
					//printf("maxelm flow = %lld\n",f[0].maxelm);
					//system("PAUSE");
				}

				// if (flow_interior>0) bmyconvective=true;
				// ������ ���������� ����������,
				// ��������� ��� �������� ������� ���-��� 1983
				doublereal** rhie_chow = nullptr;
				QuickMemVorst m;
				m.ballocCRSt = false; // �������� ������
				m.bsignalfreeCRSt = true; // � ����� �����������.
				// ������������� ����������.
				m.tval = nullptr;
				m.tcol_ind = nullptr;
				m.trow_ptr = nullptr;
				m.tri = nullptr;
				m.troc = nullptr;
				m.ts = nullptr;
				m.tt = nullptr;
				m.tvi = nullptr;
				m.tpi = nullptr;
				m.tdx = nullptr;
				m.tdax = nullptr;
				m.ty = nullptr;
				m.tz = nullptr;
				m.ta = nullptr;
				m.tja = nullptr;
				m.tia = nullptr;
				m.talu = nullptr;
				m.tjlu = nullptr;
				m.tju = nullptr;
				m.tiw = nullptr;
				m.tlevs = nullptr;
				m.tw = nullptr;
				m.tjw = nullptr;
				m.icount_vel = 100000; // ����� ������� �����.			

				{
					integer* color = nullptr;
					integer dist_max = 3;
					calculate_color_for_temperature(color, t,inx,xpos);

					// ���� flow_interior == 0 �� f[0] ������ ���������� ��������  
					solve_nonlinear_temp(f[0], f, t,
						rhie_chow,
						b, lb, s, ls, w, lw,
						dbeta, flow_interior,
						bmyconvective, nullptr, 0.001, 0.001,
						false,
						matlist, 0,
						bprintmessage,
						gtdps, ltdp, 1.0, // ��������� �������� ������ 1.0 �������� ��� �������� �������.
						m, nullptr, // �������� � ����������� ���������� ����. 
						nullptr,
						lu, my_union, color, dist_max); // �������� ����� ����� ������� � ����������� ���������� ����.
					delete[] color;
				}

				while ((bglobal_restart_06_10_2018)) {

					// ��������� ����� ���� ����������� ���������. ��������� ������������ ������.
					if (t.potent != nullptr) {
						delete[] t.potent;
						t.potent = nullptr;
						t.potent = new doublereal[t.maxelm + t.maxbound];
						for (integer i7 = 0; i7 < t.maxelm + t.maxbound; i7++) t.potent[i7] = operating_temperature_for_film_coeff; // �������������.
						if (bsource_term_radiation_for_relax != nullptr) {
							delete[] bsource_term_radiation_for_relax;
							bsource_term_radiation_for_relax = nullptr;
							bsource_term_radiation_for_relax = new doublereal[t.maxelm];
						}
						if (sourse2Dproblem != nullptr) {
							delete[] sourse2Dproblem;
							sourse2Dproblem = nullptr;
							sourse2Dproblem = new bool[t.maxbound];
						}
						if (conductivity2Dinsource != nullptr) {
							delete[] conductivity2Dinsource;
							conductivity2Dinsource = nullptr;
							conductivity2Dinsource = new doublereal[t.maxbound];
						}

						if (rthdsd_no_radiosity_patch != nullptr) {
							delete[]	rthdsd_no_radiosity_patch;
							rthdsd_no_radiosity_patch = nullptr;
						}

						if (b_buffer_correct_source != nullptr) {
							delete[] b_buffer_correct_source;
							b_buffer_correct_source = nullptr;
							b_buffer_correct_source = new doublereal[t.maxelm];
						}

						if (t.slau != nullptr) {
							delete[] t.slau;
							t.slau = nullptr;
							t.slau = new equation3D[t.maxelm]; // ������������ ������� ���� ��� ���������� ��.
							if (t.slau == nullptr) {
								// ������������ ������ �� ������ ������������.
								printf("Problem: not enough memory on your equipment for slau temperature constr struct...\n");
								printf("Please any key to exit...\n");
								//system("PAUSE");
								system("pause");
								exit(1);
							}
						}

						if (t.slau_bon != nullptr) {
							delete[] t.slau_bon;
							t.slau_bon = nullptr;
							t.slau_bon = new equation3D_bon[t.maxbound]; // ������������ ������� ���� ��� ��������� ��
							if (t.slau_bon == nullptr) {
								// ������������ ������ �� ������ ������������.
								printf("Problem: not enough memory on your equipment for slau boundary temperature constr struct...\n");
								printf("Please any key to exit...\n");
								//system("PAUSE");
								system("pause");
								exit(1);
							}
						}
					}
					//bglobal_restart_06_10_2018 = false;

					integer* color = nullptr;
					integer dist_max = 3;
					calculate_color_for_temperature(color, t,inx,xpos);


					// ���� flow_interior == 0 �� f[0] ������ ���������� ��������  
					solve_nonlinear_temp(f[0], f, t,
						rhie_chow,
						b, lb, s, ls, w, lw,
						dbeta, flow_interior,
						bmyconvective, nullptr, 0.001, 0.001,
						false,
						matlist, 0,
						bprintmessage,
						gtdps, ltdp, 1.0, m,
						nullptr, // �������� � ����������� ���������� ����. 
						nullptr,
						lu, my_union, color, dist_max); // �������� ����� ����� ������� � ����������� ���������� ����.
									   // ��������� �������� ������ 1.0 �������� ��� �������� �������.
					delete[] color;

				}

				// ��������� ������� ����������� � ������ �������.
				doublereal Tavg_fluid = 0.0;
				doublereal ic_avg_Temp_fluid = 0.0;
				for (integer i_7 = 0; i_7 < f[0].maxelm; i_7++) {
					if ((f[0].ptr[i_7] >= 0) && (f[0].ptr[i_7] < t.maxelm)) {
						Tavg_fluid += t.potent[f[0].ptr[i_7]];
						ic_avg_Temp_fluid += 1.0;
					}
				}
				if (ic_avg_Temp_fluid > 1.0e-30) {
					Tavg_fluid /= ic_avg_Temp_fluid;
					printf("average fluid temperature is %e\n", Tavg_fluid);
				}
				else {
					//printf("no fluid cell\n");
				}

				// ���������� ����� ������.
				massa_cabinet(t, f, inx, iny, inz,
					xpos, ypos, zpos, flow_interior,
					b, lb, operatingtemperature,
					matlist);

				// 10.10.2017
				// ���������� ���������� ������� ����� ���������.
				xyplot_temp(t, t.potent);
				//printf("graphics writing sucseful\n");
				//system("PAUSE");

				if (1) {
					if (!b_on_adaptive_local_refinement_mesh) {

						// ������� ���������� ���������� � ��������� tecplot360:
						exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, b, lb);
					}
					else {
						if (b_on_adaptive_local_refinement_mesh) {
							calculation_main_end_time = clock(); // ������ ��������� �����.
							unsigned int calculation_main_seach_time = calculation_main_end_time - calculation_main_start_time_global_Depend;

							// ����� ����� ���������� �� ������������� ������������ ���������.
							int im = 0, is = 0, ims = 0;
							im = (int)(calculation_main_seach_time / 60000); // ������
							is = (int)((calculation_main_seach_time - 60000 * im) / 1000); // �������
							ims = (int)((calculation_main_seach_time - 60000 * im - 1000 * is) / 10); // ������������ ������� �� 10

							printf("time calculation is:  %d minute %d second %d millisecond\n", im, is, 10 * ims);

							//printf("Would you like to save the result on the ALICE grid ? y/n\n");
							//ch_EXPORT_ALICE_ONLY = getchar(); // ����� ������ getchar();
							//ch_EXPORT_ALICE_ONLY = 'y';
						}
						if (ch_EXPORT_ALICE_ONLY == 'y') {
							// ������� � ��������� tecplot �����������.
							//� ���� �����.
						    ANES_tecplot360_export_temperature(t.maxnod, t.pa, t.maxelm, t.nvtx, t.potent, t, f, 0, b, lb);
						}

					}
				}

			}

			doublereal tmaxfinish = -273.15; // ���������� ����.
			// ���������� �������� ������������ ����������� ������ ��������� ������� � �� � ��������:
			//for (integer i = 0; i < t.maxelm + t.maxbound; i++) tmaxfinish = fmax(tmaxfinish, fabs(t.potent[i]));
			// 23 ������� 2015
			// �� ��������� ������ ���������� ����� �� ����� ��������� ������� �����������, �������
			// �������� �� ������� ����� � ��������� ����������� ������ �� ���������� ��. 
			for (integer i = 0; i < t.maxelm; i++) tmaxfinish = fmax(tmaxfinish, t.potent[i]);

			FILE* fp = NULL;
			errno_t err1 = 0;
#ifdef MINGW_COMPILLER
			fp = fopen64("report.txt", "w");
			if (fp == NULL) err1 = 1;
#else
			err1 = fopen_s(&fp, "report.txt", "w");
#endif
			// �������� ����� ��� ������.
			if ((err1) != 0) {
				printf("Create File report.txt Error\n");
				//system("PAUSE");
				system("pause");
			}
			else {
				// ������ ���������
				fprintf(fp, "Maximum Temperature %.2f\n", tmaxfinish);
				fclose(fp);
			}
			// 1 - solver/solid_static/
			report_temperature(flow_interior, f, t, b, lb, s, ls, w, lw, 0);
			// �������� ������ �������� ����� �������� ������� ������.
			// �������� ���������� (���������) �� ������� ����� �������� ����� � ��,
			// ���������� ����� �������� ������� ������. 28.10.2019
			report_out_boundary(f[0], t, ls, lw, w, b, lb, matlist, f[0].OpTemp);

			
			if (ch_EXPORT_ALICE_ONLY != 'y') {

				calculation_end_time = clock(); // ������ ��������� �����.
				calculation_seach_time = calculation_end_time - calculation_start_time;
				unsigned int im = 0, is = 0, ims = 0;
				im = (unsigned int)(calculation_seach_time / 60000); // ������
				is = (unsigned int)((calculation_seach_time - 60000 * im) / 1000); // �������
				ims = (unsigned int)((calculation_seach_time - 60000 * im - 1000 * is) / 10); // ������������ ������� �� 10

				printf("time calculation is:  %u minute %u second %u millisecond\n", im, is, 10 * ims);

				// �� �������� ������ ������� ����������� (11.4� ����� �� ���� Coarse )
				// ����������� ����������� �����. 

				// 25.11.2017
				// 1. �������� ������ � ����������� � ����� �� ����.
				// 2. ��������� �� � ����������� ������.
				// 3. ���������� ������.
				// 4. ��������� ������� ���������� ������������� �����.
				// 5. ��������� ������ � ����������� � ���� �� ������� ���������� ������������� �����.
				// 6. ��������������� ����������� � ����������� �� ����������������� ����� �������� ������.
				// 7.1 Tecplot �������� ������������� �� ��� ���� �� ����������������� ����� � � ������� � � ������. 
				// 7.2 ������������ �� ���� ����� � ������ ���� �������� ����� ���������� ���� �� ����������������� (���� tecplot�).


				if (b_on_adaptive_local_refinement_mesh) {
					// 1. ��������� x,y,z,T,nvtx, m_sizeT, m_size_nvtx.
					doublereal* x_buf = nullptr;
					doublereal* y_buf = nullptr;
					doublereal* z_buf = nullptr;
					doublereal* t_buf = nullptr;
					integer** nvtx_buf = nullptr;
					integer m_sizeT = 0, m_size_nvtx = 0;

					ANES_tecplot360_export_temperature_preobrazovatel(t.maxnod, t.pa, t.maxelm, t.nvtx, t.potent, t, x_buf, y_buf, z_buf, t_buf, nvtx_buf, m_sizeT, m_size_nvtx, operatingtemperature);

					// 2. ������������ ������.
					// ������������ ����������� ������.
					if (t.xpos_copy != nullptr) {
						delete[] t.xpos_copy;
						t.xpos_copy = nullptr;
					}
					if (t.ypos_copy != nullptr) {
						delete[] t.ypos_copy;
						t.ypos_copy = nullptr;
					}
					if (t.zpos_copy != nullptr) {
						delete[] t.zpos_copy;
						t.zpos_copy = nullptr;
					}


					if (bsource_term_radiation_for_relax != nullptr) {
						delete[] bsource_term_radiation_for_relax; // ���������� ������������ ������ ������������ �������.
						bsource_term_radiation_for_relax = nullptr;
					}
					if (b_buffer_correct_source != nullptr) {
						delete[] b_buffer_correct_source;
						b_buffer_correct_source = nullptr;
					}

					if (rthdsd_no_radiosity_patch != nullptr) {
						delete[] rthdsd_no_radiosity_patch;
						rthdsd_no_radiosity_patch = nullptr;
					}
					

					// ������� ��������� ���������� ��������� ������� � ����� 0.14 ��������.
					if (qnbc != nullptr) {
						delete[] qnbc;
						qnbc = nullptr;
						iadd_qnbc_maxelm = 0;
					}

					// ����� ���������� ����������� ������ �� ��� ���� �������� ������:
					free_level1_temp(t);
					free_level2_temp(t); // ������������ ������ �� ��� ������.
										 // ����������� ������ ��� LR ������.
					if (t.rootWE != nullptr) {
						free_root(t.rootWE, t.iWE);
					}
					if (t.rootSN != nullptr) {
						free_root(t.rootSN, t.iSN);
					}
					if (t.rootBT != nullptr) {
						free_root(t.rootBT, t.iBT);
					}
					if (t.rootWE != nullptr) {
						delete[] t.rootWE;
						t.rootWE = nullptr;
					}
					if (t.rootSN != nullptr) {
						delete[] t.rootSN;
						t.rootSN = nullptr;
					}
					if (t.rootBT != nullptr) {
						delete[] t.rootBT;
						t.rootBT = nullptr;
					}

					if (bvery_big_memory) {
						if (t.database.x != nullptr) {
							free(t.database.x);
						}
						if (t.database.y != nullptr) {
							free(t.database.y);
						}
						if (t.database.z != nullptr) {
							free(t.database.z);
						}
						if (t.database.nvtxcell != nullptr) {
							for (integer i = 0; i <= 7; i++) {
								delete[] t.database.nvtxcell[i];
							}
							delete[] t.database.nvtxcell;
						}
						if (t.database.ptr != nullptr) {
							if (t.database.ptr[0] != nullptr) {
								delete[] t.database.ptr[0];
							}
							if (t.database.ptr[1] != nullptr) {
								delete[] t.database.ptr[1];
							}
							delete[] t.database.ptr;
						}
					}

					// ������������ ������ ��� LR �����.
					free_level1_flow(f, flow_interior);
					free_level2_flow(f, flow_interior); // ������������ ������ �� ��� ������.

					if (sourse2Dproblem != nullptr) {
						delete[] sourse2Dproblem;
						sourse2Dproblem = nullptr;
					}
					if (conductivity2Dinsource != nullptr) {
						delete[] conductivity2Dinsource;
						conductivity2Dinsource = nullptr;
					}

					if (x_jacoby_buffer != nullptr) {
						// 30 ������� 2016. 
						// � seidelsor2 ������ ������������� �� ����� ������ ���������� �.�. �����.
						// ������������ ������ �� ��� Jacobi buffer.
						delete[] x_jacoby_buffer;
					}


					
					// ������������ ����� ������ � ILU �������.
					//if (milu_gl_buffer.alu_copy != nullptr) delete[] milu_gl_buffer.alu_copy;
					//if (milu_gl_buffer.jlu_copy != nullptr) delete[] milu_gl_buffer.jlu_copy;
					//if (milu_gl_buffer.ju_copy != nullptr) delete[] milu_gl_buffer.ju_copy;
					//milu_gl_buffer.alu_copy = nullptr;
					//milu_gl_buffer.jlu_copy = nullptr;
					//milu_gl_buffer.ju_copy = nullptr;
					
					flow_interior = 0;

					// 3. ���������� ������� �����.

					b_on_adaptive_local_refinement_mesh = false;
					iCabinetMarker = 0;
					load_TEMPER_and_FLOW(t, f, inx, iny, inz, xpos, ypos, zpos, flow_interior,
						b, lb, lw, w, s, ls, lu, my_union, operatingtemperature, matlist, bextendedprint,
						dgx, dgy, dgz, b_on_adaptive_local_refinement_mesh, false, iCabinetMarker);

					t.operatingtemperature = operatingtemperature;


					// ��� ����� ������ ����� ��� ������� �������������� ������.
					t.inx_copy = inx;
					t.iny_copy = iny;
					t.inz_copy = inz;
					t.operatingtemperature_copy = operatingtemperature;
					t.xpos_copy = new doublereal[inx + 1];
					t.ypos_copy = new doublereal[iny + 1];
					t.zpos_copy = new doublereal[inz + 1];
					// ������ ���������� ����� ��� �������� ����������� ������,
					// ��������� ������ ����� ��������� �� ��� � ����� ������������� 
					// ���� ����c�����.
					for (integer i_7 = 0; i_7 < inx + 1; i_7++) {
						t.xpos_copy[i_7] = xpos[i_7];
					}
					for (integer i_7 = 0; i_7 < iny + 1; i_7++) {
						t.ypos_copy[i_7] = ypos[i_7];
					}
					for (integer i_7 = 0; i_7 < inz + 1; i_7++) {
						t.zpos_copy[i_7] = zpos[i_7];
					}

					t.free_temper_level1 = false; // ������ ���������������� ������������ ������ ����������� ��� ������ ������� ����� �������� ������.
					t.free_temper_level2 = false; // ������������ ������ ��� �������� ������� ��� ���������� � � SIMPLESPARSE ������.	


					// 4. ������������ ��� �����������.
					ALICE_2_Structural(t.maxnod, t.pa, t.maxelm, t.nvtx, t.potent, x_buf, y_buf, z_buf, t_buf, nvtx_buf, m_sizeT, m_size_nvtx, t.operatingtemperature_copy);


					if (x_buf != nullptr) {
						delete[] x_buf;
						x_buf = nullptr;
					}
					if (y_buf != nullptr) {
						delete[] y_buf;
						y_buf = nullptr;
					}
					if (z_buf != nullptr) {
						delete[] z_buf;
						z_buf = nullptr;
					}
					if (t_buf != nullptr) {
						delete[] t_buf;
						t_buf = nullptr;
					}
					if (nvtx_buf != nullptr) {
						for (integer i_1 = 0; i_1 < 8; i_1++) {
							if (nvtx_buf[i_1] != nullptr) {
								delete[] nvtx_buf[i_1];
								nvtx_buf[i_1] = nullptr;
							}
						}
						delete[] nvtx_buf;
						nvtx_buf = nullptr;
					}
					m_sizeT = 0, m_size_nvtx = 0;
					// 5. ������� ������� � tecplot.
					exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, b, lb);
				}
			}
			else {
				// �������� ������������ �� ���� ����� ������ ���� � ������ �����, �������
				// ��� ������������ �������� ������������ ����� ������� �� ����������������� �����.
				// � ������� �� ���� ����� ��� ������ �� tecplot�.
				// �������� �� ���� ����� �����. ����� �������� ������� �������� ��� ���� ����������, ��
				// ��������� �������� ������� ������� �� ����� ������� (������������ �����) ������ � ������
				// ��������������� ������ ���� ������ ����� ����� ���� ����� ��������� (������ ������� �����������).

				// ������� � ��������� tecplot �����������.
				// � ���� �����.
				//ANES_tecplot360_export_temperature(t.maxnod, t.pa, t.maxelm, t.nvtx, t.potent,t,0,b,lb);
			}
			


		}

		// steady Temperature Finite Element Method
		if (1 && (0 == steady_or_unsteady_global_determinant) && (eqin.itemper == 2)) {

			// ����� �������.
			unsigned int calculation_start_time = 0; // ������ ����� ��.
			unsigned int calculation_end_time = 0; // ��������� ����� ��.
			unsigned int calculation_seach_time = 0; // ����� ���������� ������� ���� � ��.

			calculation_start_time = clock(); // ������ ������ �����.

			for (integer i7 = 0; i7 < t.maxelm + t.maxbound; i7++) t.potent[i7] = operating_temperature_for_film_coeff; // �������������.

			// ������ ������ Static Structural.
			bonly_solid_calculation = true;

			// �������� ����������� ���������� �� ����������� ������.
			if (lw == 1) {
				bPhysics_stop = true;
				if (lb < 11) {
					// ��� ����������� ��������:
					// MD40, AuSn, Cu, AuSn, SiC, GaN. cabinet and hollow.
					bPhysics_PTBSH_memory = true;
				}
			}

			if (adiabatic_vs_heat_transfer_coeff == 1) {
				// �� �������������� ��������� ��������� ����� ��������� �� ��������������� ��� ������ ������ ����.
				//for (integer i7 = 0; i7<t.maxelm + t.maxbound; i7++) t.potent[i7] = 0.57*operating_temperature_for_film_coeff;
			}

			// ����� �������������� ��� �� ������ ������������ ������ ������ ����������������.
			bsolid_static_only = true;
			bool bcleantemp = false;
			// �� ���� ������ ������ ������ ���������������� ������
			// ������ ������������� ��������.
			//if (2 == eqin.itemper)
			{
				bcleantemp = true;
				for (integer i = 0; i < flow_interior; i++) {
					if (eqin.fluidinfo[i].iflow == 1) bcleantemp = false;
				}
				// ���� bcleantemp==true �� �� ������ ������ ������ ������������� ��� ����� ���������.
			}
			if (1 || bcleantemp) {
				// ������� ������������ ���������� (��� ��������) ������ ������ ���������������� � ��������� �������. 
				printf("solution of pure Static Structural...\n");
				printf("please, press any key to continue...\n");
				if (bwait) {
					//system("PAUSE");
					system("pause");
				}

				// ��� ������������ ������������� ����������� ��������.
				bool bprintmessage = true; // �������� �� ��������� �� �������.

				doublereal dbeta = 1.0; // ������ ������� ������������� �� �������.
				bool bmyconvective = false;
				if (starting_speed_Vx * starting_speed_Vx + starting_speed_Vy * starting_speed_Vy + starting_speed_Vz * starting_speed_Vz > 1.0e-30) {
					if (f[0].maxelm > 0) {
						bmyconvective = true;
					}
				}
				else {
					// �������� ������������� ��������� ��������.
					errno_t err_inicialization_data = 0;
					FILE* fp_inicialization_data = NULL;
#ifdef MINGW_COMPILLER
					fp_inicialization_data = fopen64("load.txt", "r");
					if (fp_inicialization_data == NULL) err_inicialization_data = 1;
#else
					err_inicialization_data = fopen_s(&fp_inicialization_data, "load.txt", "r");
#endif

					if (err_inicialization_data == 0) {
						// �������� ������ � ���� ������������.
						if (f[0].maxelm > 0) {
							bmyconvective = true;
						}
						fclose(fp_inicialization_data);
					}
				}

				// if (flow_interior>0) bmyconvective=true;
				// ������ ���������� ����������,
				// ��������� ��� �������� ������� ���-��� 1983
				doublereal** rhie_chow = nullptr;
				QuickMemVorst m;
				m.ballocCRSt = false; // �������� ������
				m.bsignalfreeCRSt = true; // � ����� �����������.

										  // ������������� ����������.
				m.tval = nullptr;
				m.tcol_ind = nullptr;
				m.trow_ptr = nullptr;
				m.tri = nullptr;
				m.troc = nullptr;
				m.ts = nullptr;
				m.tt = nullptr;
				m.tvi = nullptr;
				m.tpi = nullptr;
				m.tdx = nullptr;
				m.tdax = nullptr;
				m.ty = nullptr;
				m.tz = nullptr;
				m.ta = nullptr;
				m.tja = nullptr;
				m.tia = nullptr;
				m.talu = nullptr;
				m.tjlu = nullptr;
				m.tju = nullptr;
				m.tiw = nullptr;
				m.tlevs = nullptr;
				m.tw = nullptr;
				m.tjw = nullptr;
				m.icount_vel = 100000; // ����� ������� �����.

				bPhysics_stop = false;

				// ����������� 19.05.2018

				doublereal* lstub = nullptr;
				integer maxelm_global_ret = 0;
				solve_Thermal(t, f, matlist, w, lw, lu, b, lb, m, false, 
					operatingtemperature, false, 0.0, lstub, lstub,
					maxelm_global_ret, 1.0, bAVLrealesation);


				/*
				// ���� flow_interior == 0 �� f[0] ������ ���������� ��������
				solve_nonlinear_temp(f[0], f, t,
				rhie_chow,
				b, lb, s, ls, w, lw,
				dbeta, flow_interior,
				bmyconvective, nullptr, 0.001, 0.001,
				false,
				matlist, 0,
				bprintmessage,
				gtdps, ltdp, 1.0, m,
				nullptr, // �������� � ����������� ���������� ����.
				nullptr); // �������� ����� ����� ������� � ����������� ���������� ����.
				// ��������� �������� ������ 1.0 �������� ��� �������� �������.
				*/
				// ���������� ����� ������.
				massa_cabinet(t, f, inx, iny, inz,
					xpos, ypos, zpos, flow_interior,
					b, lb, operatingtemperature,
					matlist);


				calculation_end_time = clock(); // ������ ��������� �����.
				calculation_seach_time = calculation_end_time - calculation_start_time;
				unsigned int im = 0, is = 0, ims = 0;
				im = (unsigned int)(calculation_seach_time / 60000); // ������
				is = (unsigned int)((calculation_seach_time - 60000 * im) / 1000); // �������
				ims = (unsigned int)((calculation_seach_time - 60000 * im - 1000 * is) / 10); // ������������ ������� �� 10

				printf("time calculation is:  %u minute %u second %u millisecond\n", im, is, 10 * ims);

				if (1) {
					if (!b_on_adaptive_local_refinement_mesh) {
						// ������� ���������� ���������� � ��������� tecplot360:
						exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, b, lb);
					}
					else {
						// ������� � ��������� tecplot �����������.
						//� ���� �����.
						ANES_tecplot360_export_temperature(t.maxnod, t.pa, t.maxelm, t.nvtx, t.potent, t, f, 0, b, lb);
					}
				}

			}

			doublereal tmaxfinish = -273.15; // ���������� ����.
											 // ���������� �������� ������������ ����������� ������ ��������� ������� � �� � ��������:
											 //for (integer i = 0; i < t.maxelm + t.maxbound; i++) tmaxfinish = fmax(tmaxfinish, fabs(t.potent[i]));
											 // 23 ������� 2015
											 // �� ��������� ������ ���������� ����� �� ����� ��������� ������� �����������, �������
											 // �������� �� ������� ����� � ��������� ����������� ������ �� ���������� ��. 
			for (integer i = 0; i < t.maxelm; i++) tmaxfinish = fmax(tmaxfinish, t.potent[i]);

			doublereal totaldeform_max = -1.0e+30;
			for (integer i = 0; i < t.maxelm; i++) totaldeform_max = fmax(totaldeform_max, t.total_deformation[TOTALDEFORMATION][i]);

			FILE* fp = NULL;
			errno_t err1 = 0;
#ifdef MINGW_COMPILLER
			fp = fopen64("report.txt", "w");
			if (fp == NULL) err1 = 1;
#else
			err1 = fopen_s(&fp, "report.txt", "w");
#endif
			// �������� ����� ��� ������.
			if ((err1) != 0) {
				printf("Create File report.txt Error\n");
				//system("PAUSE");
				system("pause");
			}
			else {
				// ������ ���������
				fprintf(fp, "Maximum Temperature %.2f\n", tmaxfinish);
				fclose(fp);
			}
			// 1 - solver/solid_static/
			report_temperature(flow_interior, f, t, b, lb, s, ls, w, lw, 0);


		}

		// steady Static Structural
		if (1 && steady_or_unsteady_global_determinant == 5) {


			// ����� �������.
			unsigned int calculation_start_time = 0; // ������ ����� ��.
			unsigned int calculation_end_time = 0; // ��������� ����� ��.
			unsigned int calculation_seach_time = 0; // ����� ���������� ������� ���� � ��.

			calculation_start_time = clock(); // ������ ������ �����.

			for (integer i7 = 0; i7 < t.maxelm + t.maxbound; i7++) t.potent[i7] = operating_temperature_for_film_coeff; // �������������.

			// ������ ������ Static Structural.
			bonly_solid_calculation = true;

			// �������� ����������� ���������� �� ����������� ������.
			if (lw == 1) {
				bPhysics_stop = true;
				if (lb < 11) {
					// ��� ����������� ��������:
					// MD40, AuSn, Cu, AuSn, SiC, GaN. cabinet and hollow.
					bPhysics_PTBSH_memory = true;
				}
			}

			if (adiabatic_vs_heat_transfer_coeff == 1) {
				// �� �������������� ��������� ��������� ����� ��������� �� ��������������� ��� ������ ������ ����.
				//for (integer i7 = 0; i7<t.maxelm + t.maxbound; i7++) t.potent[i7] = 0.57*operating_temperature_for_film_coeff;
			}

			// ����� �������������� ��� �� ������ ������������ ������ ������ ����������������.
			bsolid_static_only = true;
			bool bcleantemp = false;
			if (eqin.itemper == 1) {
				bcleantemp = true;
				for (integer i = 0; i < flow_interior; i++) {
					if (eqin.fluidinfo[i].iflow == 1) bcleantemp = false;
				}
				// ���� bcleantemp==true �� �� ������ ������ ������ ������������� ��� ����� ���������.
			}
			if (1 || bcleantemp) {
				// ������� ������������ ���������� (��� ��������) ������ ������ ���������������� � ��������� �������. 
				printf("solution of pure Static Structural...\n");
				printf("please, press any key to continue...\n");
				if (bwait) {
					//system("PAUSE");
					system("pause");
				}

				// ��� ������������ ������������� ����������� ��������.
				bool bprintmessage = true; // �������� �� ��������� �� �������.

				doublereal dbeta = 1.0; // ������ ������� ������������� �� �������.
				bool bmyconvective = false;
				if (starting_speed_Vx * starting_speed_Vx + starting_speed_Vy * starting_speed_Vy + starting_speed_Vz * starting_speed_Vz > 1.0e-30) {
					if (f[0].maxelm > 0) {
						bmyconvective = true;
					}
				}
				else {
					// �������� ������������� ��������� ��������.
					errno_t err_inicialization_data = 0;
					FILE* fp_inicialization_data = NULL;
#ifdef MINGW_COMPILLER
					fp_inicialization_data = fopen64("load.txt", "r");
					if (fp_inicialization_data == NULL) err_inicialization_data = 1;
#else
					err_inicialization_data = fopen_s(&fp_inicialization_data, "load.txt", "r");
#endif

					if (err_inicialization_data == 0) {
						// �������� ������ � ���� ������������.
						if (f[0].maxelm > 0) {
							bmyconvective = true;
						}
						fclose(fp_inicialization_data);
					}
				}

				// if (flow_interior>0) bmyconvective=true;
				// ������ ���������� ����������,
				// ��������� ��� �������� ������� ���-���
				doublereal** rhie_chow = nullptr;
				QuickMemVorst m;
				m.ballocCRSt = false; // �������� ������
				m.bsignalfreeCRSt = true; // � ����� �����������.

				// ������������� ����������.
				m.tval = nullptr;
				m.tcol_ind = nullptr;
				m.trow_ptr = nullptr;
				m.tri = nullptr;
				m.troc = nullptr;
				m.ts = nullptr;
				m.tt = nullptr;
				m.tvi = nullptr;
				m.tpi = nullptr;
				m.tdx = nullptr;
				m.tdax = nullptr;
				m.ty = nullptr;
				m.tz = nullptr;
				m.ta = nullptr;
				m.tja = nullptr;
				m.tia = nullptr;
				m.talu = nullptr;
				m.tjlu = nullptr;
				m.tju = nullptr;
				m.tiw = nullptr;
				m.tlevs = nullptr;
				m.tw = nullptr;
				m.tjw = nullptr;
				m.icount_vel = 100000; // ����� ������� �����.

				bPhysics_stop = false;
				// ����� ������� Static Structural.
				// �������� 19.05.2018
				//solve_Structural(t, w, lw, m, false, operatingtemperature);
				bPhysics_stop = true;
				// ����������� 19.05.2018

				//doublereal* lstub = nullptr;
				//integer maxelm_global_ret = 0;
				//solve_Thermal(t, f, matlist, w, lw, lu, b, lb, m, false, operatingtemperature,false, 0.0, lstub, lstub, maxelm_global_ret, 1.0);


				/*
				// ���� flow_interior == 0 �� f[0] ������ ���������� ��������
				solve_nonlinear_temp(f[0], f, t,
				rhie_chow,
				b, lb, s, ls, w, lw,
				dbeta, flow_interior,
				bmyconvective, nullptr, 0.001, 0.001,
				false,
				matlist, 0,
				bprintmessage,
				gtdps, ltdp, 1.0, m,
				nullptr, // �������� � ����������� ���������� ����.
				nullptr); // �������� ����� ����� ������� � ����������� ���������� ����.
				// ��������� �������� ������ 1.0 �������� ��� �������� �������.
				*/
				// ���������� ����� ������.
				massa_cabinet(t, f, inx, iny, inz,
					xpos, ypos, zpos, flow_interior,
					b, lb, operatingtemperature,
					matlist);


				calculation_end_time = clock(); // ������ ��������� �����.
				calculation_seach_time = calculation_end_time - calculation_start_time;
				unsigned int im = 0, is = 0, ims = 0;
				im = (unsigned int)(calculation_seach_time / 60000); // ������
				is = (unsigned int)((calculation_seach_time - 60000 * im) / 1000); // �������
				ims = (unsigned int)((calculation_seach_time - 60000 * im - 1000 * is) / 10); // ������������ ������� �� 10

				printf("time calculation is:  %u minute %u second %u millisecond\n", im, is, 10 * ims);

				if (1) {
					if (!b_on_adaptive_local_refinement_mesh) {
						// ������� ���������� ���������� � ��������� tecplot360:
						exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, b, lb);
					}
					else {
						// ������� � ��������� tecplot �����������.
						//� ���� �����.
						ANES_tecplot360_export_temperature(t.maxnod, t.pa, t.maxelm, t.nvtx, t.potent, t, f, 0, b, lb);
					}
				}

			}

			doublereal tmaxfinish = -273.15; // ���������� ����.
											 // ���������� �������� ������������ ����������� ������ ��������� ������� � �� � ��������:
											 //for (integer i = 0; i < t.maxelm + t.maxbound; i++) tmaxfinish = fmax(tmaxfinish, fabs(t.potent[i]));
											 // 23 ������� 2015
											 // �� ��������� ������ ���������� ����� �� ����� ��������� ������� �����������, �������
											 // �������� �� ������� ����� � ��������� ����������� ������ �� ���������� ��. 
			for (integer i = 0; i < t.maxelm; i++) tmaxfinish = fmax(tmaxfinish, t.potent[i]);

			doublereal totaldeform_max = -1.0e+30;
			for (integer i = 0; i < t.maxelm; i++) totaldeform_max = fmax(totaldeform_max, t.total_deformation[TOTALDEFORMATION][i]);

			FILE* fp = NULL;
			errno_t err1 = 0;
#ifdef MINGW_COMPILLER
			fp = fopen64("report.txt", "w");
			if (fp == NULL) err1 = 1;
#else
			err1 = fopen_s(&fp, "report.txt", "w");
#endif
			// �������� ����� ��� ������.
			if ((err1) != 0) {
				printf("Create File report.txt Error\n");
				//system("PAUSE");
				system("pause");
			}
			else {
				// ������ ���������
				fprintf(fp, "Maximum Temperature %.2f\n", tmaxfinish);
				fclose(fp);
			}
			// 1 - solver/solid_static/
			report_temperature(flow_interior, f, t, b, lb, s, ls, w, lw, 0);



		}

		// steady Static Structural and Temperature (Thermal Stress).
		if (1 && steady_or_unsteady_global_determinant == 6) {

			// ����� �������.
			unsigned int calculation_start_time = 0; // ������ ����� ��.
			unsigned int calculation_end_time = 0; // ��������� ����� ��.
			unsigned int calculation_seach_time = 0; // ����� ���������� ������� ���� � ��.

			calculation_start_time = clock(); // ������ ������ �����.

			for (integer i7 = 0; i7 < t.maxelm + t.maxbound; i7++) t.potent[i7] = operating_temperature_for_film_coeff; // �������������.

			// ������ �������������, � ����� Static Structural.
			bonly_solid_calculation = true;

			// �������� ����������� ���������� �� ����������� ������.
			if (lw == 1) {
				bPhysics_stop = true;
				if (lb < 11) {
					// ��� ����������� ��������:
					// MD40, AuSn, Cu, AuSn, SiC, GaN. cabinet and hollow.
					bPhysics_PTBSH_memory = true;
				}
			}

			if (adiabatic_vs_heat_transfer_coeff == 1) {
				// �� �������������� ��������� ��������� ����� ��������� �� ��������������� ��� ������ ������ ����.
				//for (integer i7 = 0; i7<t.maxelm + t.maxbound; i7++) t.potent[i7] = 0.57*operating_temperature_for_film_coeff;
			}

			// ����� �������������� ��� �� ������ ������������ ������ ������ ����������������.
			bsolid_static_only = true;
			bool bcleantemp = false;
			if (eqin.itemper == 1) {
				bcleantemp = true;
				for (integer i = 0; i < flow_interior; i++) {
					if (eqin.fluidinfo[i].iflow == 1) bcleantemp = false;
				}
				// ���� bcleantemp==true �� �� ������ ������ ������ ������������� ��� ����� ���������.
			}
			if (1 || bcleantemp) {
				// ������� ������������ ���������� (��� ��������) ������ ������ ���������������� � ��������� �������. 
				printf("solution of pure Static Structural...\n");
				printf("please, press any key to continue...\n");
				if (bwait) {
					//system("PAUSE");
					system("pause");
				}

				// ��� ������������ ������������� ����������� ��������.
				bool bprintmessage = true; // �������� �� ��������� �� �������.

				doublereal dbeta = 1.0; // ������ ������� ������������� �� �������.
				bool bmyconvective = false;
				if (starting_speed_Vx * starting_speed_Vx + starting_speed_Vy * starting_speed_Vy + starting_speed_Vz * starting_speed_Vz > 1.0e-30) {
					if (f[0].maxelm > 0) {
						bmyconvective = true;
					}
				}
				else {
					// �������� ������������� ��������� ��������.
					errno_t err_inicialization_data = 0;
					FILE* fp_inicialization_data = NULL;
#ifdef MINGW_COMPILLER
					fp_inicialization_data = fopen64("load.txt", "r");
					if (fp_inicialization_data == NULL) err_inicialization_data = 1;
#else
					err_inicialization_data = fopen_s(&fp_inicialization_data, "load.txt", "r");
#endif

					if (err_inicialization_data == 0) {
						// �������� ������ � ���� ������������.
						if (f[0].maxelm > 0) {
							bmyconvective = true;
						}
						fclose(fp_inicialization_data);
					}
				}

				// if (flow_interior>0) bmyconvective=true;
				// ������ ���������� ����������,
				// ��������� ��� �������� ������� ���-��� 1983
				doublereal** rhie_chow = nullptr;
				QuickMemVorst m;
				m.ballocCRSt = false; // �������� ������
				m.bsignalfreeCRSt = true; // � ����� �����������.

										  // ������������� ����������.
				m.tval = nullptr;
				m.tcol_ind = nullptr;
				m.trow_ptr = nullptr;
				m.tri = nullptr;
				m.troc = nullptr;
				m.ts = nullptr;
				m.tt = nullptr;
				m.tvi = nullptr;
				m.tpi = nullptr;
				m.tdx = nullptr;
				m.tdax = nullptr;
				m.ty = nullptr;
				m.tz = nullptr;
				m.ta = nullptr;
				m.tja = nullptr;
				m.tia = nullptr;
				m.talu = nullptr;
				m.tjlu = nullptr;
				m.tju = nullptr;
				m.tiw = nullptr;
				m.tlevs = nullptr;
				m.tw = nullptr;
				m.tjw = nullptr;
				m.icount_vel = 100000; // ����� ������� �����.



				integer* color = nullptr;
				integer dist_max = 3;
				calculate_color_for_temperature(color, t,inx,xpos);

				// ���� flow_interior == 0 �� f[0] ������ ���������� ��������
				solve_nonlinear_temp(f[0], f, t,
					rhie_chow,
					b, lb, s, ls, w, lw,
					dbeta, flow_interior,
					bmyconvective, nullptr, 0.001, 0.001,
					false,
					matlist, 0,
					bprintmessage,
					gtdps, ltdp, 1.0, // ��������� �������� ������ 1.0 �������� ��� �������� �������.
					m, nullptr, // �������� � ����������� ���������� ����.
					nullptr,
					lu, my_union, color, dist_max); // �������� ����� ����� ������� � ����������� ���������� ����.
				    delete[] color;
					

					//bPhysics_stop = false;
					// ����� ������� Static Structural.
				solve_Structural(t, w, lw, m, true, operatingtemperature, b, lb);
				//bPhysics_stop = true;

				// ���������� ����� ������.
				massa_cabinet(t, f, inx, iny, inz,
					xpos, ypos, zpos, flow_interior,
					b, lb, operatingtemperature,
					matlist);

				calculation_end_time = clock(); // ������ ��������� �����.
				calculation_seach_time = calculation_end_time - calculation_start_time;
				unsigned int im = 0, is = 0, ims = 0;
				im = (unsigned int)(calculation_seach_time / 60000); // ������
				is = (unsigned int)((calculation_seach_time - 60000 * im) / 1000); // �������
				ims = (unsigned int)((calculation_seach_time - 60000 * im - 1000 * is) / 10); // ������������ ������� �� 10

				printf("time calculation is:  %u minute %u second %u millisecond\n", im, is, 10 * ims);

				if (1) {
					if (!b_on_adaptive_local_refinement_mesh) {
						// ������� ���������� ���������� � ��������� tecplot360:
						exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, b, lb);
					}
					else {
						// ������� � ��������� tecplot �����������.
						//� ���� �����.
						ANES_tecplot360_export_temperature(t.maxnod, t.pa, t.maxelm, t.nvtx, t.potent, t, f, 0, b, lb);
					}
				}

			}

			doublereal tmaxfinish = -273.15; // ���������� ����.
											 // ���������� �������� ������������ ����������� ������ ��������� ������� � �� � ��������:
											 //for (integer i = 0; i < t.maxelm + t.maxbound; i++) tmaxfinish = fmax(tmaxfinish, fabs(t.potent[i]));
											 // 23 ������� 2015
											 // �� ��������� ������ ���������� ����� �� ����� ��������� ������� �����������, �������
											 // �������� �� ������� ����� � ��������� ����������� ������ �� ���������� ��. 
			for (integer i = 0; i < t.maxelm; i++) tmaxfinish = fmax(tmaxfinish, t.potent[i]);

			doublereal totaldeform_max = -1.0e+30;
			for (integer i = 0; i < t.maxelm; i++) totaldeform_max = fmax(totaldeform_max, t.total_deformation[TOTALDEFORMATION][i]);

			FILE* fp = NULL;
			errno_t err1 = 0;
#ifdef MINGW_COMPILLER
			fp = fopen64("report.txt", "w");
			if (fp == NULL) err1 = 1;
#else
			err1 = fopen_s(&fp, "report.txt", "w");
#endif

			// �������� ����� ��� ������.
			if ((err1) != 0) {
				printf("Create File report.txt Error\n");
				//system("PAUSE");
				system("pause");
			}
			else {
				// ������ ���������
				fprintf(fp, "Maximum Temperature %.2f\n", tmaxfinish);
				fclose(fp);
			}
			// 1 - solver/solid_static/
			report_temperature(flow_interior, f, t, b, lb, s, ls, w, lw, 0);
			// �������� ������ �������� ����� �������� ������� ������.
			// �������� ���������� (���������) �� ������� ����� �������� ����� � ��,
			// ���������� ����� �������� ������� ������. 28,10,2019
			report_out_boundary(f[0], t, ls, lw, w, b, lb, matlist, f[0].OpTemp);


		}



		/*
		if (b_on_adaptive_local_refinement_mesh) {
		printf("t.maxbound=%d\n", t.maxbound);
		printf("v dvuch shagah ot ALICE sborki. \n");
		system("PAUSE");
		exit(1);  // ����� ����������� ������������ ��������� ���������� ���������� �������� ������������ �����.
		}

		if (b_on_adaptive_local_refinement_mesh) {
		printf("Solve temperature is compleate. \n");
		system("PAUSE");
		exit(1);  // ����� ����������� ������������ ��������� ���������� ���������� �������� ������������ �����.
		}
		*/

		//system("pause");

		if (1 && ((steady_or_unsteady_global_determinant == 1) || (steady_or_unsteady_global_determinant == 7))) {
			// �������������� ����������������.

			// ������ ������ ������������� � ������ ����.
			bonly_solid_calculation = true;

			// �������� ����������� ���������� �� ����������� ������.
			// ��� ���������� �������� ������ �� ���� �������� �������� ����������.
			if (lw == 1) {
				bPhysics_stop = true;
				if (lb < 11) {
					// ��� ����������� ��������:
					// MD40, AuSn, Cu, AuSn, SiC, GaN. cabinet and hollow.
					bPhysics_PTBSH_memory = true;
				}
			}

			bglobal_unsteady_temperature_determinant = true;
			// ����� �������������� ��� �� ������ ������ ������ ����������������.
			// ��������� 13 �������� bconvective
			// �� ����������� �������� ��������, �������� ������� ����������� ����������,
			// ����������� �� ����������� ��������� �����. ������� ������� ������������� �� 
			// ������� ������� ����������� ������ �����.
			// ��� ������������� ����� � ������������� ��������� 
			// ���������� ��������� ������� ������������� � ������� �� ������
			// ��� ��������� ����������� � ������ ������� �� 5 �������� �� ���� ��������� � 167�������� � �������.
			// ��� ��������� �������� � icepak ����� 120 ��������, ��� ������ � ��������� ����������� Rt 
			// (�������� 6.875��, RT=16K/W) � �����������������
			// ������.
			doublereal dbeta = 1.3333333;//1.0; // ���� 1.0 �� ������ ������� ������������� �� �������.
			dbeta = 1.0; // ����� ���������� ��������.
			// ������ ���������� ����������,
			// ��������� ��� �������� ������� ���-��� 1983
			doublereal** rhie_chow = nullptr;
			//solve_nonlinear_temp(f[0], f, t, rhie_chow, b, lb, s, ls, w, lw, dbeta, flow_interior, false, nullptr, 0.001, false);
			bool bsecond_T_solver = false;
			if (steady_or_unsteady_global_determinant == 7) {
				// ������������� ������ �� ������ ���������� ������ ������� 10.11.2018.
				bsecond_T_solver = true;
			}
			unsteady_temperature_calculation(f[0], f, t,
				rhie_chow,
				b, lb, s, ls, w, lw,
				dbeta, flow_interior,
				matlist,
				operatingtemperature,
				gtdps, ltdp, lu, my_union, bsecond_T_solver,inx, xpos); // �������������� ������������� ������

			// ��������� ������� ����������� � ������ �������.
			doublereal Tavg_fluid = 0.0;
			doublereal ic_avg_Temp_fluid = 0.0;
			for (integer i_7 = 0; i_7 < f[0].maxelm; i_7++) {
				if ((f[0].ptr[i_7] >= 0) && (f[0].ptr[i_7] < t.maxelm)) {
					Tavg_fluid += t.potent[f[0].ptr[i_7]];
					ic_avg_Temp_fluid += 1.0;
				}
			}
			if (ic_avg_Temp_fluid > 1.0e-30) {
				Tavg_fluid /= ic_avg_Temp_fluid;
				printf("average fluid temperature is %e\n", Tavg_fluid);
			}
			else {
				//printf("no fluid cell\n");
			}

			// ���������� ����� ������.
			massa_cabinet(t, f, inx, iny, inz,
				xpos, ypos, zpos, flow_interior,
				b, lb, operatingtemperature,
				matlist);

			if (!bsecond_T_solver) {
				if (!b_on_adaptive_local_refinement_mesh) {
					// ������� ���������� ���������� � ��������� tecplot360:
					exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, b, lb);
				}
				else {
					// ������� � ��������� tecplot �����������.
					//� ���� �����.
					ANES_tecplot360_export_temperature(t.maxnod, t.pa, t.maxelm, t.nvtx, t.potent, t, f, 0, b, lb);
				}


				doublereal tmaxfinish = -273.15;
				// ���������� �������� ������������ ����������� ������ ��������� ������� � �� � ��������:
				for (integer i = 0; i < t.maxelm + t.maxbound; i++) tmaxfinish = fmax(tmaxfinish, t.potent[i]);
				FILE* fp = NULL;
				errno_t err1 = 0;
#ifdef MINGW_COMPILLER
				fp = fopen64("report.txt", "w");
				if (fp == NULL) err1 = 1;
#else
				err1 = fopen_s(&fp, "report.txt", "w");
#endif
				// �������� ����� ��� ������.
				if ((err1) != 0) {
					printf("Create File report.txt Error\n");
					//system("PAUSE");
					system("pause");
				}
				else {
					// ������ ���������
					fprintf(fp, "Maximum Temperature %.2f\n", tmaxfinish);
					fclose(fp);
				}
				// 1 - solver/solid_static/
				report_temperature(flow_interior, f, t, b, lb, s, ls, w, lw, 0);
				// �������� ������ �������� ����� �������� ������� ������.
				// �������� ���������� (���������) �� ������� ����� �������� ����� � ��,
				// ���������� ����� �������� ������� ������. 28,10,2019
				report_out_boundary(f[0], t, ls, lw, w, b, lb, matlist, f[0].OpTemp);
			}
			else {
				printf("THIS IS SECOND UNSTEADY TEMPERATURE SOLVER ON ALL MESHES.\n");
				printf("NO EXPOPRT TECPLOT.\n");
				printf("NO PRINT REPORT.\n");
			}
			printf("calculation complete...\n");
			// system("PAUSE");
		}

		

		// ������� ���������� ���������� � ��������� tecplot360:
		// ����� ������������ ��� �������� ����������� �����.
		if (false) {
			exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, b, lb);
			printf("read values. OK.\n");
			if (bwait) {
				//system("PAUSE"); // debug avtosave
				system("pause");
			}
		}

		if ((1 && steady_or_unsteady_global_determinant == 3)) {
			// Fluid dynamic ������������ �������������� �������.
#ifdef _OPENMP
			// �������������� � ������������� ������� cfd �� openMP 08.05.2019.
			printf("CFD not work in OPENMP ON and bparallelismold is true.\n");
			printf("uskorenie ot OPENMP otsutstvuet. Rabotaen odnopotochnaq versiq.\n");
			printf("variable bparallelismold must be equal false.\n");
			//system("PAUSE");
#endif

			told_temperature_global_for_HOrelax = new doublereal[t.maxelm + t.maxbound];
			bSIMPLErun_now_for_temperature = true;

			if (dgx * dgx + dgy * dgy + dgz * dgz > 1.0e-20) {
				// ���� ����� ��������� �������� �� ��� fluid ���������� ����������� ����������.
				bool bbussinesk_7 = false;
#pragma omp parallel for
				for (integer i_8 = 0; i_8 < f[0].maxelm; i_8++) {
					integer ib = t.whot_is_block[f[0].ptr[i_8]];
					if (ib > -1) {
						if (b[ib].itype == FLUID) {
							integer i_7 = b[ib].imatid;
							if (matlist[i_7].bBussineskApproach) bbussinesk_7 = true;
						}
					}
				}
				if (bbussinesk_7) {
					bSIMPLErun_now_for_natural_convection = true;
				}
			}
			bHORF = true;
			bPamendment_source_old = new doublereal[f[0].maxelm + f[0].maxbound];
			for (integer i5 = 0; i5 < f[0].maxelm + f[0].maxbound; i5++) bPamendment_source_old[i5] = 0.0;
			// exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint);
			//system("PAUSE");
			if (dgx * dgx + dgy * dgy + dgz * dgz > 1.0e-20) {
				// ���� ����� ��������� �������� �� ��� fluid ���������� ����������� ����������.
				bool bbussinesk_7 = false;
#pragma omp parallel for
				for (integer i_8 = 0; i_8 < f[0].maxelm; i_8++) {
					integer ib = t.whot_is_block[f[0].ptr[i_8]];
					if (ib > -1) {
						if (b[ib].itype == FLUID) {
							integer i_7 = b[ib].imatid;
							if (matlist[i_7].bBussineskApproach) {
								bbussinesk_7 = true;
							}
						}
					}
				}
				if (bbussinesk_7) {
					printf("Bussinesk approach Operating Temperature=%e\n", f[0].OpTemp); // Operating Temperature);
				}
			}

			//exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0);
			//system("PAUSE");

			// ������������ ����������������� ��������.
			steady_cfd_calculation(breadOk,
				eqin, dgx, dgy, dgz,
				continity_start,
				inumber_iteration_SIMPLE,
				flow_interior, f, t, b, lb,
				s, ls, w, lw, matlist,
				gtdps, ltdp, bextendedprint, lu, my_union,inx,xpos);
			// xyplot( f, 0, t);
			// boundarylayer_info(f, t, flow_interior, w, lw);
			// 2 - solver/conjugate_heat_transfer_static/
			report_temperature(flow_interior, f, t, b, lb, s, ls, w, lw, 0/*2*/);
			// �������� ������ �������� ����� �������� ������� ������.
			// �������� ���������� (���������) �� ������� ����� �������� ����� � ��,
			// ���������� ����� �������� ������� ������. 28,10,2019
			report_out_boundary(f[0], t, ls, lw, w, b, lb, matlist, f[0].OpTemp);

			// ���������� ����� ������.
			massa_cabinet(t, f, inx, iny, inz,
				xpos, ypos, zpos, flow_interior,
				b, lb, operatingtemperature,
				matlist);

			// ������� ���������� ���������� � ��������� tecplot360:
			if (!b_on_adaptive_local_refinement_mesh) {
				exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, b, lb);
			}
			else {
				ANES_tecplot360_export_temperature(t.maxnod, t.pa, t.maxelm, t.nvtx, t.potent, t, f, 0, b, lb);
			}

			save_velocity_for_init(t.maxelm, t.ncell, f, t, flow_interior);
			// exporttecplotxy360T_3D_part2_rev(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint,b,lb);
			delete[] bPamendment_source_old;
			bPamendment_source_old = nullptr;
			delete[] told_temperature_global_for_HOrelax;
			told_temperature_global_for_HOrelax = nullptr;
		}
		if ((1 && (steady_or_unsteady_global_determinant == 9))) {


#ifdef _OPENMP
			// �������������� � ������������� ������� cfd �� openMP 08.05.2019.
			printf("Unsteady CFD not work in OPENMP ON and bparallelismold is true.\n");
			printf("uskorenie ot OPENMP otsutstvuet. Rabotaen odnopotochnaq versiq.\n");
			printf("variable bparallelismold must be equal false.\n");
			//system("PAUSE");
#endif

			told_temperature_global_for_HOrelax = new doublereal[t.maxelm + t.maxbound];
			bSIMPLErun_now_for_temperature = true;


			if (dgx * dgx + dgy * dgy + dgz * dgz > 1.0e-20) {
				// ���� ����� ��������� �������� �� ��� fluid ���������� ����������� ����������.
				bool bbussinesk_7 = false;
#pragma omp parallel for
				for (integer i_8 = 0; i_8 < f[0].maxelm; i_8++) {
					integer ib = t.whot_is_block[f[0].ptr[i_8]];
					if (ib > -1) {
						if (b[ib].itype == FLUID) {
							integer i_7 = b[ib].imatid;
							if (matlist[i_7].bBussineskApproach) bbussinesk_7 = true;
						}
					}
				}
				if (bbussinesk_7) {
					bSIMPLErun_now_for_natural_convection = true;
				}
			}

			bHORF = true;
			bPamendment_source_old = new doublereal[f[0].maxelm + f[0].maxbound];
			for (integer i5 = 0; i5 < f[0].maxelm + f[0].maxbound; i5++) bPamendment_source_old[i5] = 0.0;

			// exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint);
			//system("PAUSE");
			if (dgx * dgx + dgy * dgy + dgz * dgz > 1.0e-20) {
				// ���� ����� ��������� �������� �� ��� fluid ���������� ����������� ����������.
				bool bbussinesk_7 = false;
#pragma omp parallel for
				for (integer i_8 = 0; i_8 < f[0].maxelm; i_8++) {
					integer ib = t.whot_is_block[f[0].ptr[i_8]];
					if (ib > -1) {
						if (b[ib].itype == FLUID) {
							integer i_7 = b[ib].imatid;
							if (matlist[i_7].bBussineskApproach) {
								bbussinesk_7 = true;
							}
						}
					}
				}
				if (bbussinesk_7) {
					printf("Bussinesk approach Operating Temperature=%e\n", f[0].OpTemp); // Operating Temperature);
				}
			}

			//exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0);
			//system("PAUSE");

			if (1) {
				printf("Sorry unsteady cfd calcuation dont support... 21.07.2019\n");
				printf("Your may send your message to kirill7785@mail.ru.\n");
				system("pause");
			}
			else {
				// �������������� ����������������� ��������:
				usteady_cfd_calculation(breadOk, eqin,
					dgx, dgy, dgz,
					continity_start,
					inumber_iteration_SIMPLE,
					flow_interior,
					f, t,
					b, lb, s, ls,
					w, lw, matlist, gtdps, ltdp, bextendedprint, lu, my_union,inx,xpos);
			}

			//xyplot( f, 0, t);
			// boundarylayer_info(f, t, flow_interior, w, lw);
			// 2 - solver/conjugate_heat_transfer_static/
			report_temperature(flow_interior, f, t, b, lb, s, ls, w, lw, 0/*2*/);

			// ���������� ����� ������.
			massa_cabinet(t, f, inx, iny, inz,
				xpos, ypos, zpos, flow_interior,
				b, lb, operatingtemperature,
				matlist);

			// ������� ���������� ���������� � ��������� tecplot360:
			if (!b_on_adaptive_local_refinement_mesh) {
				exporttecplotxy360T_3D_part2(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint, 0, b, lb);
			}
			else {
				ANES_tecplot360_export_temperature(t.maxnod, t.pa, t.maxelm, t.nvtx, t.potent, t, f, 0, b, lb);
			}

			save_velocity_for_init(t.maxelm, t.ncell, f, t, flow_interior);
			// exporttecplotxy360T_3D_part2_rev(t.maxelm, t.ncell, f, t, flow_interior, 0, bextendedprint,b,lb);

			delete[] bPamendment_source_old;
			bPamendment_source_old = nullptr;
			delete[] told_temperature_global_for_HOrelax;
			told_temperature_global_for_HOrelax = nullptr;

		}

		fclose(fp_log); // �������� ����� ����.


		if (continity_start != nullptr) {
			delete[] continity_start;
			continity_start = nullptr;
		}

		if (inumber_iteration_SIMPLE != nullptr) {
			delete[] inumber_iteration_SIMPLE;
			inumber_iteration_SIMPLE = nullptr;
		}

	}

	// ������������ ����������� ������.
	if (t.xpos_copy != nullptr) {
		delete[] t.xpos_copy;
		t.xpos_copy = nullptr;
	}
	if (t.ypos_copy != nullptr) {
		delete[] t.ypos_copy;
		t.ypos_copy = nullptr;
	}
	if (t.zpos_copy != nullptr) {
		delete[] t.zpos_copy;
		t.zpos_copy = nullptr;
	}

	// ������������ ����������� ������.
	if (xposadd != nullptr) {
		delete[] xposadd;
		xposadd = nullptr;
	}
	if (yposadd != nullptr) {
		delete[] yposadd;
		yposadd = nullptr;
	}
	if (zposadd != nullptr) {
		delete[] zposadd;
		zposadd = nullptr;
	}


	// ������������ ����������� ������.
	if (xpos != nullptr) {
		delete[] xpos;
		xpos = nullptr;
	}
	if (ypos != nullptr) {
		delete[] ypos;
		ypos = nullptr;
	}
	if (zpos != nullptr) {
		delete[] zpos;
		zpos = nullptr;
	}

	if (bsource_term_radiation_for_relax != nullptr) {
		delete[] bsource_term_radiation_for_relax; // ���������� ������������ ������ ������������ �������.
		bsource_term_radiation_for_relax = nullptr;
	}
	if (b_buffer_correct_source != nullptr) {
		delete[] b_buffer_correct_source;
		b_buffer_correct_source = nullptr;
	}

	printf("free memory begin...\n");
	if (bwait) {
		//system("PAUSE");
		system("pause");
	}

	if (rthdsd_no_radiosity_patch != nullptr) {
		delete[] rthdsd_no_radiosity_patch;
		rthdsd_no_radiosity_patch = nullptr;
	}


	// ������� ��������� ���������� ��������� ������� � ����� 0.14 ��������.
	if (qnbc != nullptr) {
		delete[] qnbc;
		qnbc = nullptr;
		iadd_qnbc_maxelm = 0;
	}

	// ������������ ������ �� ��� amg1r5.
	if (amgGM.a != nullptr) {
		delete[] amgGM.a;
		amgGM.a = nullptr;
	}
	if (amgGM.ia != nullptr) {
		delete[] amgGM.ia;
		amgGM.ia = nullptr;
	}
	if (amgGM.ja != nullptr) {
		delete[] amgGM.ja;
		amgGM.ja = nullptr;
	}
	if (amgGM.u != nullptr) {
		delete[] amgGM.u;
		amgGM.u = nullptr;
	}
	if (amgGM.f != nullptr) {
		delete[] amgGM.f;
		amgGM.f = nullptr;
	}
	if (amgGM.ig != nullptr) {
		delete[] amgGM.ig;
		amgGM.ig = nullptr;
	}

	amgGM.nda = -1;
	amgGM.ndf = -1;
	amgGM.ndia = -1;
	amgGM.ndig = -1;
	amgGM.ndja = -1;
	amgGM.ndu = -1;

	for (integer i_7 = 0; i_7 < lb; i_7++) {
		if (b[i_7].temp_Sc != nullptr) {
			delete[] b[i_7].temp_Sc;
			b[i_7].temp_Sc = nullptr;
		}
		if (b[i_7].arr_Sc != nullptr) {
			delete[] b[i_7].arr_Sc;
			b[i_7].arr_Sc = nullptr;
		}
		if (b[i_7].g.hi != nullptr) {
			delete[] b[i_7].g.hi;
			b[i_7].g.hi = nullptr;
		}
		if (b[i_7].g.xi != nullptr) {
			delete[] b[i_7].g.xi;
			b[i_7].g.xi = nullptr;
		}
		if (b[i_7].g.yi != nullptr) {
			delete[] b[i_7].g.yi;
			b[i_7].g.yi = nullptr;
		}
		if (b[i_7].g.zi != nullptr) {
			delete[] b[i_7].g.zi;
			b[i_7].g.zi = nullptr;
		}
	}
	delete[] b; delete[] s; delete[] w; // ������������ ������
	b = nullptr;
	s = nullptr;
	w = nullptr;
	for (integer i_7 = 0; i_7 < lmatmax; i_7++) {
		if (matlist[i_7].arr_cp != nullptr) {
			delete[] matlist[i_7].arr_cp;
			matlist[i_7].arr_cp = nullptr;
		}
		if (matlist[i_7].temp_cp != nullptr) {
			delete[] matlist[i_7].temp_cp;
			matlist[i_7].temp_cp = nullptr;
		}
		if (matlist[i_7].arr_lam != nullptr) {
			delete[] matlist[i_7].arr_lam;
			matlist[i_7].arr_lam = nullptr;
		}
		if (matlist[i_7].temp_lam != nullptr) {
			delete[] matlist[i_7].temp_lam;
			matlist[i_7].temp_lam = nullptr;
		}
	}
	delete[] matlist;
	matlist = nullptr;
	delete[] gtdps;
	gtdps = nullptr;
	if (eqin.fluidinfo != nullptr) {
		delete[] eqin.fluidinfo;
		eqin.fluidinfo = nullptr;
	}
	// ����� ���������� ����������� ������ �� ��� ���� �������� ������:
	free_level1_temp(t);
	free_level2_temp(t); // ������������ ������ �� ��� ������.
	// ����������� ������ ��� LR ������.
	free_root(t.rootWE, t.iWE);
	free_root(t.rootSN, t.iSN);
	free_root(t.rootBT, t.iBT);
	if (t.rootWE != nullptr) {
		delete[] t.rootWE;
		t.rootWE = nullptr;
	}
	if (t.rootSN != nullptr) {
		delete[] t.rootSN;
		t.rootSN = nullptr;
	}
	if (t.rootBT != nullptr) {
		delete[] t.rootBT;
		t.rootBT = nullptr;
	}
	// ������������ ������ ��� LR �����.
	free_level1_flow(f, flow_interior);
	free_level2_flow(f, flow_interior); // ������������ ������ �� ��� ������.

	delete[] f;
	f = nullptr;

	if (sourse2Dproblem != nullptr) {
		delete[] sourse2Dproblem;
		sourse2Dproblem = nullptr;
	}
	if (conductivity2Dinsource != nullptr) {
		delete[] conductivity2Dinsource;
		conductivity2Dinsource = nullptr;
	}

	if (x_jacoby_buffer != nullptr) {
		// 30 ������� 2016. 
		// � seidelsor2 ������ ������������� �� ����� ������ ���������� �.�. �����.
		// ������������ ������ �� ��� Jacobi buffer.
		delete[] x_jacoby_buffer;
		x_jacoby_buffer = nullptr;
	}

	if (bvery_big_memory) {
		if (t.database.x != nullptr) {
			free(t.database.x);
			t.database.x = nullptr;
		}
		if (t.database.y != nullptr) {
			free(t.database.y);
			t.database.y = nullptr;
		}
		if (t.database.z != nullptr) {
			free(t.database.z);
			t.database.z = nullptr;
		}
		if (t.database.nvtxcell != nullptr) {
			for (integer i = 0; i <= 7; i++) {
				delete[] t.database.nvtxcell[i];
			}
			delete[] t.database.nvtxcell;
			t.database.nvtxcell = nullptr;
		}
		if (t.database.ptr != nullptr) {
			if (t.database.ptr[0] != nullptr) {
				delete[] t.database.ptr[0];
			}
			if (t.database.ptr[1] != nullptr) {
				delete[] t.database.ptr[1];
			}
			delete[] t.database.ptr;
			t.database.ptr = nullptr;
		}
	}

	for (integer i63 = 0; i63 < lu; i63++) {
		// ����� ���������� ����������� ������ �� ��� ���� �������� ������:
		free_level1_temp(my_union[i63].t);
		free_level2_temp(my_union[i63].t); // ������������ ������ �� ��� ������.

		// ����������� ������ ��� LR ������.
		free_root(my_union[i63].t.rootWE, my_union[i63].t.iWE);
		free_root(my_union[i63].t.rootSN, my_union[i63].t.iSN);
		free_root(my_union[i63].t.rootBT, my_union[i63].t.iBT);
		if (my_union[i63].t.rootWE != nullptr) {
			delete[] my_union[i63].t.rootWE;
			my_union[i63].t.rootWE = nullptr;
		}
		if (my_union[i63].t.rootSN != nullptr) {
			delete[] my_union[i63].t.rootSN;
			my_union[i63].t.rootSN = nullptr;
		}
		if (my_union[i63].t.rootBT != nullptr) {
			delete[] my_union[i63].t.rootBT;
			my_union[i63].t.rootBT = nullptr;
		}

		// ������������ ������ ��� LR �����.
		free_level1_flow(my_union[i63].f, my_union[i63].flow_interior);
		free_level2_flow(my_union[i63].f, my_union[i63].flow_interior); // ������������ ������ �� ��� ������.

		delete[] my_union[i63].f;
		my_union[i63].f = nullptr;

		if (bvery_big_memory) {
			if (my_union[i63].t.database.x != nullptr) {
				free(my_union[i63].t.database.x);
				my_union[i63].t.database.x = nullptr;
			}
			if (my_union[i63].t.database.y != nullptr) {
				free(my_union[i63].t.database.y);
				my_union[i63].t.database.y = nullptr;
			}
			if (my_union[i63].t.database.z != nullptr) {
				free(my_union[i63].t.database.z);
				my_union[i63].t.database.z = nullptr;
			}
			if (my_union[i63].t.database.nvtxcell != nullptr) {
				for (integer i = 0; i <= 7; i++) {
					delete[] my_union[i63].t.database.nvtxcell[i];
				}
				delete[] my_union[i63].t.database.nvtxcell;
				my_union[i63].t.database.nvtxcell = nullptr;
			}
			if (my_union[i63].t.database.ptr != nullptr) {
				if (my_union[i63].t.database.ptr[0] != nullptr) {
					delete[] my_union[i63].t.database.ptr[0];
				}
				if (my_union[i63].t.database.ptr[1] != nullptr) {
					delete[] my_union[i63].t.database.ptr[1];
				}
				delete[] my_union[i63].t.database.ptr;
				my_union[i63].t.database.ptr = nullptr;
			}
		}
	}

	// ������������ ����� ������ � ILU ������.
	if (milu_gl_buffer.alu_copy != nullptr) delete[] milu_gl_buffer.alu_copy;
	if (milu_gl_buffer.jlu_copy != nullptr) delete[] milu_gl_buffer.jlu_copy;
	if (milu_gl_buffer.ju_copy != nullptr) delete[] milu_gl_buffer.ju_copy;
	milu_gl_buffer.alu_copy = nullptr;
	milu_gl_buffer.jlu_copy = nullptr;
	milu_gl_buffer.ju_copy = nullptr;

	free_QSBid(); // ��� ���������� ������ ������� myisblock_id.

	flow_interior = 0;
	printf("free memory finish...\n");

	if (1 && steady_or_unsteady_global_determinant == 2) {
		// ��� ������ ����� ��������� ����������.
		printf("Mesh generation procedure is finish.\n");
	}
	else {
		printf("Calculation procedure is finish.\n");
	}

	if (bwait) {
		printf("Please, press any key to exit...\n");
		//system("PAUSE");
		system("pause");
	}

	// ������������ ����������� ������ �� ��� ������ ���������
	// ���� �� �������.
	if (glTSL.table_law_piecewise_constant != nullptr) {
		delete[] glTSL.table_law_piecewise_constant;
		glTSL.table_law_piecewise_constant = nullptr;
	}

	// ��� ��� � ������ bFULL_AUTOMATIC ������� ������������ �������� �
	// ������� ������������ �������, �� �������� ������� ����������� ���� ���� ���, �
	// ��� ��������� ��������� ���� ��������� � ������ ���-�������.
	// 20mm ���� ��������� � 1��� 9� �� 53� �� ���� ������ bFULL_AUTOMATIC.
	// ���-������� ��� automatic
	// ������������ ����������� ������ �� ��� ���-�������.
	delete[] shorter_hash_X;
	delete[] shorter_hash_Y;
	delete[] shorter_hash_Z;
	delete[] bshorter_hash_X;
	delete[] bshorter_hash_Y;
	delete[] bshorter_hash_Z;

	// ����������� ������ �� ��� ������� �����.
	//delete[] StringList;

	calculation_main_end_time = clock();
	calculation_main_seach_time = calculation_main_end_time - calculation_main_start_time_global_Depend;


	/*printf("time=%d statistic vorst=%3.2f %% \n",calculation_main_seach_time,(float)(100.0*calculation_vorst_seach_time/calculation_main_seach_time));
	system("PAUSE");
	*/



	// ����� ����� ����������.
	int im = 0, is = 0, ims = 0;
	im = (int)(calculation_main_seach_time / 60000); // ������
	is = (int)((calculation_main_seach_time - 60000 * im) / 1000); // �������
	ims = (int)((calculation_main_seach_time - 60000 * im - 1000 * is) / 10); // ������������ ������� �� 10

	printf("time calculation is:  %d minute %d second %d millisecond\n", im, is, 10 * ims);

	if (1 && (steady_or_unsteady_global_determinant != 8)) {
		//system("pause");
		//46.321
		//31.655
	}

	return calculation_main_seach_time;
} // main_body

int main(void)
{

	// ��������� ��������� � ������� Windows
	// ������ ����������� ����� � ������� �����.
	//setlocale(LC_ALL, "");
	system("mode con cols=166 lines=12000");

	char ch_EXPORT_ALICE_ONLY = 'y';

	if (0) {
		// �����������. ������� �� ������ ��� ����������:
		// d_my_optimetric1_6_12_2019;
		// d_my_optimetric2_6_12_2019;
		// d_my_optimetric3_6_12_2019.
		// � ���������� �������� ���������.
		// ��� ����������� ��� ���������� ��������� �������� � ��� � 
		// � ������ ��������� �� ���������.
		// ��� ����������
		//int in_optimetric = 21;
		int* time_optimetric = new int[1000];
		doublereal* op_comp = new doublereal[1000];
		int iscan_optimetric = 0;
		for (d_my_optimetric1_6_12_2019 = 0.33; d_my_optimetric1_6_12_2019 < 0.7; d_my_optimetric1_6_12_2019 += 0.01) {
			//for (d_my_optimetric2_6_12_2019 = 0.09; d_my_optimetric2_6_12_2019 < 0.95; d_my_optimetric2_6_12_2019 += 0.005) {
				//for (d_my_optimetric3_6_12_2019 = 0.11; d_my_optimetric3_6_12_2019 < 0.12; d_my_optimetric3_6_12_2019 += 0.01) {
					//printf("%e %e %e %d\n", d_my_optimetric1_6_12_2019, d_my_optimetric2_6_12_2019, d_my_optimetric3_6_12_2019, time_optimetric[iscan_optimetric]);
					//printf("%e %d\n", d_my_optimetric1_6_12_2019, time_optimetric[iscan_optimetric]);
					time_optimetric[iscan_optimetric] = main_body(ch_EXPORT_ALICE_ONLY);
					op_comp[iscan_optimetric] = d_my_optimetric2_6_12_2019;
					iscan_optimetric++;
					
				//}
			//}
		}

		printf("\n\n\n");
		iscan_optimetric = 0;
		for (d_my_optimetric1_6_12_2019 = 0.33; d_my_optimetric1_6_12_2019 < 0.7; d_my_optimetric1_6_12_2019 += 0.01) {
			//for (d_my_optimetric2_6_12_2019 = 0.09; d_my_optimetric2_6_12_2019 < 0.95; d_my_optimetric2_6_12_2019 += 0.005) {
				//for (d_my_optimetric3_6_12_2019 = 0.11; d_my_optimetric3_6_12_2019 < 0.12; d_my_optimetric3_6_12_2019 += 0.01) {
					//printf("%e %e %e %d\n", d_my_optimetric1_6_12_2019, d_my_optimetric2_6_12_2019, d_my_optimetric3_6_12_2019, time_optimetric[iscan_optimetric]);
					printf("%e CA=%e %d\n", d_my_optimetric1_6_12_2019, op_comp[iscan_optimetric], time_optimetric[iscan_optimetric]);
					iscan_optimetric++;
				//}
			//}
		}
		delete[] time_optimetric;
		delete[] op_comp;
	}
	if (0) {
		// �����������. ������� �� ������ ����� ����������.
		// d_my_optimetric1_6_12_2019.
		// � ���������� �������� ���������.
		// ��� ����������� ��� ���������� ��������� �������� � ��� � 
		// � ������ �������� � ���������.
		// ���� ����������
		int in_optimetric = 21;
		int* time_optimetric = new int[300];
		int iscan_optimetric = 0;
		for (d_my_optimetric1_6_12_2019 = 0.0; d_my_optimetric1_6_12_2019 < 0.02; d_my_optimetric1_6_12_2019 += 0.002) {
			printf("%e %d\n", d_my_optimetric1_6_12_2019, time_optimetric[iscan_optimetric]);
			time_optimetric[iscan_optimetric] = main_body(ch_EXPORT_ALICE_ONLY);
			iscan_optimetric++;
		}

		printf("\n\n\n");
		iscan_optimetric = 0;
		for (d_my_optimetric1_6_12_2019 = 0.0; d_my_optimetric1_6_12_2019 < 0.02; d_my_optimetric1_6_12_2019 += 0.002) {
			printf("%e %d\n", d_my_optimetric1_6_12_2019, time_optimetric[iscan_optimetric]);
			iscan_optimetric++;
		}
		delete[] time_optimetric;
	}
	if (1) {
		main_body(ch_EXPORT_ALICE_ONLY);
	}

	// ����������� ������ �� ��� ������� �����.
	delete[] StringList;

	


	system("pause");
	return 0;
}
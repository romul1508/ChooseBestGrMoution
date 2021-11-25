// This file is part of ChooseBestGrMoution.

// ChooseBestGrMoution is free software : you can redistribute itand /or modify
// it under the terms of the GNU Lesser Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// ChooseBestGrMoution is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU Lesser Public License for more details.

// You should have received a copy of the GNU Lesser Public License
// along with ChooseBestGrMoution.If not, see < http://www.gnu.org/licenses/>.


////////////////////////////////////////////////////////////////
// ChooseBestGrMoution.exe solves the following problem
// 
// The city transport company wants to introduce such a scheme for the movement of city buses, 
// which will reduce gas pollution in the city by reducing the number of buses used (and at the same time the cost of salaries for drivers, repairs, etc.). 
// It turned out that to meet the needs of citizens on this route from 0:00 to 4:00 at least 4 buses must run, from 4:00 to 8:00 at least 8, 
// from 8:00 to 12:00 at least 10, from 12:00 to 16:00 at least 7, from 16:00 to 20:00 at least 12, from 20:00 to 24:00 at least 4. 
// In this case, each bus must be on the line continuously for 8 hours (one change). Help the company set up a timetable.
//----------------------------------------------------------

// Solution (See project folder /doc)
// In accordance with the conditions of the problem, namely, 
// the fact that at least 12 buses must be involved from 16:00 to 20 : 00, 
// we can conclude that this is the minimum number of buses(A, B, C, D, E, F, G, H, I, K, L, M).

// As a result of solving this problem, 
// it turned out that at the output several equivalent traffic schedules are obtained. 
// The main assessment criterion is the total number of hours spent by all buses, 
// while the best schedule of movement along the route is the one 
// that requires the minimum time spent in shifts.

// Here are two equivalent optimal time schedules : 208 hours.
// 1. Bus A operates in three shifts, 24 hours a day.
//   Bus B also operates 24 hours in three shifts.
//   The C bus operates in two shifts, the first working from 12 : 00 to 20 : 00 and the second from 20 : 00 to 4 : 00.
//   Bus D, like bus C, is used in two shifts, and operates from 12 : 00 to 20 : 00 (first shift) and from 20 : 00 to 4 : 00 (second shift).
//   The remaining eight buses are used in two shifts from 4 : 00 to 20 : 00.

// 2. Bus A operates from 12 : 00 to 20 : 00.
//   Bus B operates from 12 : 00 to 20 : 00.
//   Buses C, D, E, F, G, H operate in two shifts from 4 : 00 to 20 : 00.
//   Each of the buses I, K, L, M is operated in three shifts, 24 hours a day.
/////////////////////////////////////////////////////////////////////

// author: Roman Ermakov
// e-mail: romul1508@gmail.com
// sinc 17.11.2021
// version: 1.0
// ChooseBestGrMoution Copyright (C) 2021 Roman Ermakov
// All rights reserved

#include <string.h>
#include <string>
#include <fstream>
#include <iostream>

typedef struct bus_schedule_t
{
	int			A;	
	int			B;
	int 		C;
	int			D;
	int			E;
	int			F;
	int			G;
	int			H;
	int			I;
	int			K;
	int			L;
	int			M;
}bus_schedule_t;

using namespace std;

// returns the number of buses
int iter_calc_times(int A, int code, int N_bus)
{
	int temp;
	temp = A & code;
	if(temp == code)
		N_bus++;
	return N_bus;
}
//--------------------------------
// Calculates the optimal movement
int optimal_motion_calculation(bus_schedule_t *ptrBusSchedule, bus_schedule_t *ptrOptimalBusSchedule, int *pOptimalSum, int *pNumCalc)
{
	int result;
	int code;
	int N_bus_16_20;
	int min_sum_bus_16_20;
	int N_bus_12_16;
	int min_sum_bus_12_16;
	int N_bus_8_12;
	int min_sum_bus_8_12;
	int N_bus_4_8;
	int min_sum_bus_4_8;
	int N_bus_0_4;
	int min_sum_bus_0_4;
	int N_bus_20_24;
	int min_sum_bus_20_24;
	//--------------------
	int num_calc;
	int optimal_sum;
	int sum;

	char str[140];

	result = 1;					// if the optimal solution is found
	code = 1;
	num_calc = 0;
	//------------
	N_bus_16_20 = 0;
	min_sum_bus_16_20 = 12;
	//------------
	N_bus_12_16 = 0;
	min_sum_bus_12_16 = 7;
	//--------------------
	N_bus_8_12 = 0;
	min_sum_bus_8_12 = 10;
	//--------------------
	N_bus_4_8 = 0;
	min_sum_bus_4_8 = 8;
	//--------------------
	N_bus_0_4 = 0;
	min_sum_bus_0_4 = 4;
	//--------------------
	N_bus_20_24 = 0;
	min_sum_bus_20_24 = 4;
	//--------------------
	optimal_sum = *pOptimalSum;
	sum = 1000;
	//--------------------
	// calculation of the number of buses and hours spent in shifts from 16-00 to 20-00
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->A, code, N_bus_16_20);
	//---------------------
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->B, code, N_bus_16_20);
	//---------------------
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->C, code, N_bus_16_20);
	//---------------------
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->D, code, N_bus_16_20);
	//---------------------
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->E, code, N_bus_16_20);
	//------------------------
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->F, code, N_bus_16_20);
	//-------------------------
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->G, code, N_bus_16_20);
	//-------------------------
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->H, code, N_bus_16_20);
	//-------------------------
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->I, code, N_bus_16_20);
	//-------------------------
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->K, code, N_bus_16_20);
	//-------------------------
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->L, code, N_bus_16_20);
	//-------------------------
	N_bus_16_20 = iter_calc_times(ptrBusSchedule->M, code, N_bus_16_20);
	//-------------------------
	if(N_bus_16_20 < min_sum_bus_16_20)
	{
		result = 0;
		return result;
	}
	//-------------------------
	// calculation of the number of buses and hours spent in shifts between 12-00 and 16-00
	//-------------------------
	code = 2;
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->A, code, N_bus_12_16);
	//-------------------------
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->B, code, N_bus_12_16);
	//-------------------------
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->C, code, N_bus_12_16);
	//-------------------------
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->D, code, N_bus_12_16);
	//-------------------------
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->E, code, N_bus_12_16);
	//-------------------------
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->F, code, N_bus_12_16);
	//-------------------------
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->G, code, N_bus_12_16);
	//-------------------------
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->H, code, N_bus_12_16);
	//-------------------------
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->I, code, N_bus_12_16);
	//-------------------------
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->K, code, N_bus_12_16);
	//-------------------------
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->L, code, N_bus_12_16);
	//-------------------------
	//-------------------------
	N_bus_12_16 = iter_calc_times(ptrBusSchedule->M, code, N_bus_12_16);
	//-------------------------
	if(N_bus_12_16 < min_sum_bus_12_16)
	{
		result = 0;
		return result;
	}
	//-------------------------
	//-------------------------
	// calculation of the number of buses and hours spent in shifts from 8-00 to 12-00
	//-------------------------
	code = 4;
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->A, code, N_bus_8_12);
	//-------------------------
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->B, code, N_bus_8_12);
	//-------------------------
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->C, code, N_bus_8_12);
	//-------------------------
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->D, code, N_bus_8_12);
	//-------------------------
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->E, code, N_bus_8_12);
	//-------------------------
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->F, code, N_bus_8_12);
	//-------------------------
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->G, code, N_bus_8_12);
	//-------------------------
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->H, code, N_bus_8_12);
	//-------------------------
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->I, code, N_bus_8_12);
	//-------------------------
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->K, code, N_bus_8_12);
	//-------------------------
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->L, code, N_bus_8_12);
	//-------------------------
	//-------------------------
	N_bus_8_12 = iter_calc_times(ptrBusSchedule->M, code, N_bus_8_12);
	//-------------------------
	if(N_bus_8_12 < min_sum_bus_8_12)
	{
		result = 0;
		return result;
	}
	//-------------------------
	//-------------------------
	// calculation of the number of buses and hours spent in shifts from 4-00 to 8-00
	//-------------------------
	code = 8;
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->A, code, N_bus_4_8);
	//-------------------------
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->B, code, N_bus_4_8);
	//-------------------------
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->C, code, N_bus_4_8);
	//-------------------------
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->D, code, N_bus_4_8);
	//-------------------------
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->E, code, N_bus_4_8);
	//-------------------------
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->F, code, N_bus_4_8);
	//-------------------------
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->G, code, N_bus_4_8);
	//-------------------------
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->H, code, N_bus_4_8);
	//-------------------------
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->I, code, N_bus_4_8);
	//-------------------------
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->K, code, N_bus_4_8);
	//-------------------------
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->L, code, N_bus_4_8);
	//-------------------------
	//-------------------------
	N_bus_4_8 = iter_calc_times(ptrBusSchedule->M, code, N_bus_4_8);
	//-------------------------
	if(N_bus_4_8 < min_sum_bus_4_8)
	{
		result = 0;
		return result;
	}
	//-------------------------
	//-------------------------
	// calculation of the number of buses and hours spent in shifts from 0-00 to 4-00
	//-------------------------
	code = 16;
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->A, code, N_bus_0_4);
	//-------------------------
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->B, code, N_bus_0_4);
	//-------------------------
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->C, code, N_bus_0_4);
	//-------------------------
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->D, code, N_bus_0_4);
	//-------------------------
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->E, code, N_bus_0_4);
	//-------------------------
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->F, code, N_bus_0_4);
	//-------------------------
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->G, code, N_bus_0_4);
	//-------------------------
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->H, code, N_bus_0_4);
	//-------------------------
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->I, code, N_bus_0_4);
	//-------------------------
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->K, code, N_bus_0_4);
	//-------------------------
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->L, code, N_bus_0_4);
	//-------------------------
	//-------------------------
	N_bus_0_4 = iter_calc_times(ptrBusSchedule->M, code, N_bus_0_4);
	//-------------------------

	//-------------------------
	if(N_bus_0_4 < min_sum_bus_0_4)
	{
		result = 0;
		return result;
	}
	//-------------------------
	//-------------------------
	// calculation of the number of buses and hours spent in shifts from 20-00 to 24-00
	//-------------------------
	code = 32;
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->A, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->B, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->C, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->D, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->E, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->F, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->G, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->H, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->I, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->K, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->L, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	N_bus_20_24 = iter_calc_times(ptrBusSchedule->M, code, N_bus_20_24);
	//-------------------------
	//-------------------------
	if(N_bus_20_24 < min_sum_bus_20_24)
	{
		result = 0;
		return result;
	}
	//-------------------------
	sum = N_bus_16_20 + N_bus_12_16 + N_bus_8_12 + N_bus_4_8 + N_bus_0_4 + N_bus_20_24;
	if(sum < optimal_sum)
	{
		string csv_string;
		string name_csv;// = "out"
		num_calc = *pNumCalc;
		num_calc++;
		*pOptimalSum = sum;

		sprintf(str, "out%d.csv", num_calc);
		name_csv = str;
		// ofstream outfile( "out.csv" );
		ofstream outfile( name_csv.c_str() );
		*pNumCalc = num_calc;
		memcpy(ptrOptimalBusSchedule, ptrBusSchedule, sizeof(bus_schedule_t) );
		//--------------
		// save the currently found optimal solution
		//--------------
		sprintf(str, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d\n", 
			ptrOptimalBusSchedule->A, ptrOptimalBusSchedule->B, 
			ptrOptimalBusSchedule->C, ptrOptimalBusSchedule->D,
			ptrOptimalBusSchedule->E, ptrOptimalBusSchedule->F,
			ptrOptimalBusSchedule->G, ptrOptimalBusSchedule->H,
			ptrOptimalBusSchedule->I, ptrOptimalBusSchedule->K,
			ptrOptimalBusSchedule->K, ptrOptimalBusSchedule->M, sum);
		csv_string = str;
		outfile << csv_string;
	}
	//-------------------------

	return result;
}
//-----------------------------------------------
int main()
{
	int a, b, c, d, e, g, f, h, i, k, l, m, A, B, C, D, E, F, G, H, I, K, L, M;
	int A_op, B_op, C_op, D_op, E_op, F_op, G_op, H_op, I_op, K_op, L_op, M_op;
	bool is_calc = true;
	//-------------
	bool isIncLEqv7 = false;
	bool isIncKEqv7 = false;
	//-------------
	int optimalSum = 1000;
	int num_calc = 0;		// the file number with the best solution
	//-------------
	double inc = 0;
	//-------------
	int S[8] = {3, 15, 27, 33, 39, 45, 51, 63};
	//------------
	bus_schedule_t bus_schedule;
	bus_schedule_t optimalBusSchedule;
	//-------------
	// for the best option
	optimalBusSchedule.A = 127;
	optimalBusSchedule.B = 127;
	optimalBusSchedule.C = 127;
	optimalBusSchedule.D = 127;
	optimalBusSchedule.E = 127;
	optimalBusSchedule.F = 127;
	optimalBusSchedule.G = 127;
	optimalBusSchedule.H = 127;
	optimalBusSchedule.I = 127;
	optimalBusSchedule.K = 127;
	optimalBusSchedule.L = 127;
	optimalBusSchedule.M = 127;
	//------------

	for(a = 0; a < 8; a++)		// for 1st bus 
	{
		
		bus_schedule.A = S[a];
		for(b = 0; b < 8; b++)		// for the 2nd bus
		{
			bus_schedule.B = S[b];
			for(c = 0; c < 8; c++)		// for the 3rd bus
			{
				bus_schedule.C = S[c];

				for(d = 0; d < 8; d++)		// for the 4th bus
				{
					bus_schedule.D = S[d];
					for(e = 0; e < 8; e++)		// for the 5th bus
					{
						bus_schedule.E = S[e];
						for(f = 0; f < 8; f++)		// for the 6th bus
						{
							bus_schedule.F = S[f];
							for(g = 0; g < 8; g++)		// for the 7th bus
							{
								bus_schedule.G = S[g];
								for(h = 0; h < 8; h++)		// for the 8th bus
								{ 
									bus_schedule.H = S[h];
									for(i = 0; i < 8; i++)		// for the 9th bus
									{
										bus_schedule.I = S[i];
										for(k = 0; k < 8; k++)		// for the 10th bus
										{
											if(k == 7)
												isIncKEqv7 = true;
											
											bus_schedule.K = S[k];
											for(l = 0; l < 8; l++)		// for the 11th bus
											{
												if(l == 7)
													isIncLEqv7 = true;
												
												bus_schedule.L = S[l];
												for(m = 0; m < 8; m++)		// for the 12th bus
												{
													bus_schedule.M = S[m];
													//-------------------------
													// further calculation and verification with the best option
													
														optimal_motion_calculation(&bus_schedule, &optimalBusSchedule, &optimalSum, &num_calc);
														
													if(m == 7)
													{
														if(isIncLEqv7 && isIncKEqv7)
														{
															inc = inc + 343;
															cout << inc << endl;
															isIncLEqv7 = false;
															isIncKEqv7 = false;
														}														
													} // end if(m == 7)
												} // end for(m = 0; m < 22; m++)																						
											} // end for(l = 0; l < 22; l++)
										} // end for(k = 0; k < 22; k++)
									} // end for(i = 0; i < 22; i++)
								} // end for(h = 0; h < 22; h++)
							} // end for(g = 0; g < 22; g++)												
						} // end for(f = 0; f < 22; f++) 										
					} // for(e = 0; e < 22; e++)								
				} // for(d = 0; d < 22; d++)						
			} // for(c = 0; c < 22; c++)				
		} // for(b = 0; b < 22; b++)
	} // for(a = 0; a < 22; a++)

	return 0;
}

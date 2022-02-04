// TestHiGHS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Highs.h"
#include <cassert>

using std::cout;
using std::endl;

int main()
{
    // Create and populate a HighsModel instance for the LP
 //
 // Min    f  =  x_0 +  x_1 + 3
 // s.t.                x_1 <= 7
 //        5 <=  x_0 + 2x_1 <= 15
 //        6 <= 3x_0 + 2x_1
 // 0 <= x_0 <= 4; 1 <= x_1
 //
 // Although the first constraint could be expressed as an upper
 // bound on x_1, it serves to illustrate a non-trivial packed
 // column-wise matrix.
 //
    HighsModel model;
    model.lp_.num_col_ = 2;
    model.lp_.num_row_ = 3;
    model.lp_.sense_ = ObjSense::kMinimize;
    model.lp_.offset_ = 3;
    model.lp_.col_cost_ = { 1.0, 1.0 };
    model.lp_.col_lower_ = { 0.0, 1.0 };
    model.lp_.col_upper_ = { 4.0, 1.0e30 };
    model.lp_.row_lower_ = { -1.0e30, 5.0, 6.0 };
    model.lp_.row_upper_ = { 7.0, 15.0, 1.0e30 };

    // Here the orientation of the matrix is column-wise
    model.lp_.format_ = MatrixFormat::kColwise;
    // a_start_ has num_col_1 entries, and the last entry is the number
    // of nonzeros in A, allowing the number of nonzeros in the last
    // column to be defined
    model.lp_.a_start_ = { 0, 2, 5 };
    model.lp_.a_index_ = { 1, 2, 0, 1, 2 };
    model.lp_.a_value_= { 1.0, 3.0, 1.0, 2.0, 2.0 };
    //
// Create a Highs instance
    Highs highs;
    HighsStatus return_status;

}
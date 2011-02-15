/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010 by Joel Andersson, Moritz Diehl, K.U.Leuven. All rights reserved.
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef OCP_SOLVER_HPP
#define OCP_SOLVER_HPP

#include <vector>

#include "fx.hpp"

namespace CasADi{

  /// Input arguments of an OCP Solver
  enum OCPInput{
    /// Time grid
    OCP_T,   
    /// Differential state lower bound                             
    OCP_LBX,
    /// Differential state upper bound  
    OCP_UBX, 
    /// Differential state initial guess  
    OCP_X_INIT,    
    OCP_LBZ, OCP_UBZ, OCP_Z_INIT,     
    OCP_LBXP, OCP_UBXP, OCP_XP_INIT,   // State deriatives with bounds
    OCP_LBU, OCP_UBU, OCP_U_INIT,     // Controls with bounds and initial guess
    OCP_LBP, OCP_UBP, OCP_P_INIT,    // Parameters with bounds and initial guess
    OCP_LBH, OCP_UBH,               // Bounds for the point constraints
    OCP_LBG, OCP_UBG,              // Bounds for the coupling constraints
    OCP_NUM_IN
  };
  
  /// Outputs arguments of an OCP Solver
  enum OCPOutput{
    OCP_X_OPT, 
    OCP_U_OPT, 
    OCP_Z_OPT, 
    OCP_XP_OPT, 
    OCP_NUM_OUT
  };
    
  // Forward declaration of internal class
  class OCPSolverInternal;

  /** \brief Base class for OCP solvers
   *
   * Available options:
   * "number_of_parameters", OT_INTEGER,  0
   * "number_of_grid_points", OT_INTEGER,  20
   * "final_time",OT_REAL, 1.0
   *
   * OCPSolver is an CasADi::FX mapping from CasADi::OCPInput to CasADi::OCPOutput
   *
      \author Joel Andersson
      \date 2011
  */ 
  class OCPSolver : public FX{
  public:

    /// Default constructor
    OCPSolver();

    /// Access functions of the node
    OCPSolverInternal* operator->();

    /// Const access functions of the node
    const OCPSolverInternal* operator->() const;
    
  };

} // namespace CasADi


#endif // OCP_SOLVER_HPP


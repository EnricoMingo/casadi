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

#ifndef COLLOCATION_HPP
#define COLLOCATION_HPP

#include "../casadi/fx/ocp_solver.hpp"
#include "../casadi/fx/nlp_solver.hpp"

namespace CasADi{
  namespace OptimalControl{
  
    class CollocationInternal;
    
  /** \brief Direct collocation
   *
   *   \author Joel Andersson
   *   \date 2012
  */ 
class Collocation : public OCPSolver{
  public:
    /// Default constructor
    Collocation();
  
    /// Constructor
    explicit Collocation(const FX& ffcn, const FX& mfcn, const FX& cfcn=FX(), const FX& rfcn=FX());

    /// Access functions of the node
    CollocationInternal* operator->();

    /// Const access functions of the node
    const CollocationInternal* operator->() const;
    
    /// Get the variables
    void getGuess(std::vector<double>& V_init) const;
    
    /// Get the variables
    void getVariableBounds(std::vector<double>& V_min, std::vector<double>& V_max) const;
    
    /// Get the constraints
    void getConstraintBounds(std::vector<double>& G_min, std::vector<double>& G_max) const;

    /// Set the optimal solution
    void setOptimalSolution( const std::vector<double> &V_opt );
    
    /// Access the underlying NLPSolver object
    NLPSolver getNLPSolver() const;

    /// Prints out a human readable report about possible constraint violations, after solving 
    void reportConstraints(std::ostream &stream=std::cout);

    /// Return the report as a string
    std::string getReportConstraints() { std::stringstream s; reportConstraints(s); return s.str(); }
};
                        
  } // namespace OptimalControl
} // namespace CasADi


#endif // COLLOCATION_HPP

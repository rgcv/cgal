// Copyright (c) 2009 INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
// You can redistribute it and/or modify it under the terms of the GNU
// General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
//
// Author(s)     : Stephane Tayeb
//
//******************************************************************************
// File Description : 
//******************************************************************************

#ifndef CGAL_MESH_3_SLIVER_CRITERIA_H
#define CGAL_MESH_3_SLIVER_CRITERIA_H

#include <CGAL/Mesh_3/min_dihedral_angle.h>
#include <CGAL/Mesh_3/radius_ratio.h>

namespace CGAL {

namespace Mesh_3 {

template<typename K>
class Sliver_criterion
{
  typedef typename K::Tetrahedron_3 Tetrahedron_3;
  
public:
  virtual const double get_max_value() const = 0;
  //Sliver_perturber performs perturbation "unit-per-unit"
  // so it needs to know how much is a unit for each criterion
  virtual const double get_perturbation_unit() const = 0;

  // returns the value of the criterion, if t is a sliver
  // optional<double>() otherwise
  virtual boost::optional<double> operator()(const Tetrahedron_3& t) const = 0;

  virtual void before_move(const Tetrahedron_3& t) = 0;
  virtual bool valid_move(const Tetrahedron_3& t) = 0;
};
  
template <typename K>
class Min_dihedral_angle_criterion : public Sliver_criterion<K>
{
  typedef typename K::Tetrahedron_3 Tetrahedron_3;
  typedef Min_dihedral_angle_criterion<typename K> Dihedral_angle_criterion;

public:
  static double default_value;
  static double max_value;
  static double min_value;

  virtual const double get_max_value() const { return 90.; }
  virtual const double get_perturbation_unit() const { return 1.; }

  virtual boost::optional<double> operator()(const Tetrahedron_3& t) const
  {
    return CGAL::to_double(minimum_dihedral_angle(t, K()));
  }

  virtual void before_move(const Tetrahedron_3& t)
  {
  }
  virtual bool valid_move(const Tetrahedron_3& t)
  {
    return true;
  }

public:
  Dihedral_angle_criterion(const double& sliver_bound_ = default_value)
    : sliver_bound(sliver_bound_)
  {}

private:
  double sliver_bound;  
};

template<typename K> double Min_dihedral_angle_criterion<K>::default_value = 12.; 
template<typename K> double Min_dihedral_angle_criterion<K>::max_value = 90.; 
template<typename K> double Min_dihedral_angle_criterion<K>::min_value = 0.; 
  
template <typename K>
class Radius_ratio_criterion : public Sliver_criterion<K>
{
  typedef typename K::Tetrahedron_3 Tetrahedron_3;
  typedef Radius_ratio_criterion<typename K> RR_criterion;
  
public:
  static double default_value;
  static double max_value;
  static double min_value;

  virtual const double get_max_value() const { return 1.; }
  virtual const double get_perturbation_unit() const { return 0.05; }

  virtual boost::optional<double> operator()(const Tetrahedron_3& t) const
  {
    return CGAL::to_double(radius_ratio(t, K()));
  }
  
  virtual void before_move(const Tetrahedron_3& t)
  {
  }
  virtual bool valid_move(const Tetrahedron_3& t)
  {
    return true;
  }

public:
  RR_criterion(const double& sliver_bound_ = default_value)
    : sliver_bound(sliver_bound_)
  {}

private:
  double sliver_bound;  
};

template<typename K> double Radius_ratio_criterion<K>::default_value = 0.25; 
template<typename K> double Radius_ratio_criterion<K>::max_value = 1.;
template<typename K> double Radius_ratio_criterion<K>::min_value = 0.; 
  
} // end namespace Mesh_3
  
} // end namespace CGAL




#endif // CGAL_MESH_3_SLIVER_CRITERIA_H

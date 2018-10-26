////
//  Copyright: Copyright (c) MOSEK ApS, Denmark. All rights reserved.
//
//  File:      lo1.cc
//
//  Purpose: Demonstrates how to solve the problem
//
//  maximize 3*x0 + 1*x1 + 5*x2 + x3
//  such that
//           3*x0 + 1*x1 + 2*x2        = 30,
//           2*x0 + 1*x1 + 3*x2 + 1*x3 > 15,
//                  2*x1 +      + 3*x3 < 25
//  and
//           x0,x1,x2,x3 > 0,
//           0 < x1 < 10
////

#include <iostream>
#include <fusion.h>
using namespace mosek::fusion;
using namespace monty;

int lo1()
{
  // Create a model with the name 'lo1'
  Model::t M = new Model("lo1"); auto _M = finally([&]() { M->dispose(); });

  M->setLogHandler([ = ](const std::string & msg) { std::cout << msg << std::flush; } );

  ////////////////////
  //  The X's
  ////////////////////
  auto A1 = new_array_ptr<double, 1>({ 3.0, 1.0, 2.0, 0.0 });
  auto A2 = new_array_ptr<double, 1>({ 2.0, 1.0, 3.0, 1.0 });
  auto A3 = new_array_ptr<double, 1>({ 0.0, 2.0, 0.0, 3.0 });
  auto c  = new_array_ptr<double, 1>({ 3.0, 1.0, 5.0, 1.0 });

  // Create variable 'x' of length 4
  Variable::t x = M->variable("x", 4, Domain::greaterThan(0.0));

  // Create constraints
  M->constraint(x->index(1), Domain::lessThan(10.0));
  M->constraint("c1", Expr::dot(A1, x), Domain::equalsTo(30.0));
  M->constraint("c2", Expr::dot(A2, x), Domain::greaterThan(15.0));
  M->constraint("c3", Expr::dot(A3, x), Domain::lessThan(25.0));

  ////////////////////
  //  The Y's
  ////////////////////
  auto Ay1 = new_array_ptr<double, 1>({ 3.0, 1.0, 2.0, 0.0 });
  auto Ay2 = new_array_ptr<double, 1>({ 2.0, 1.0, 3.0, 1.0 });
  auto Ay3 = new_array_ptr<double, 1>({ 0.0, 2.0, 0.0, 3.0 });
  auto cy  = new_array_ptr<double, 1>({ 3.0, 1.0, 5.0, 1.0 });
  Variable::t y = M->variable("y", 4, Domain::greaterThan(0.0));

  // Create constraints
  M->constraint(y->index(1), Domain::lessThan(10.0));
  M->constraint("cy1", Expr::dot(Ay1, y), Domain::equalsTo(30.0));
  M->constraint("cy2", Expr::dot(Ay2, y), Domain::greaterThan(15.0));
  M->constraint("cy3", Expr::dot(Ay3, y), Domain::lessThan(25.0));

  //////////////////////////////////////
  // Set the objective function to (c^t * x)
  //////////////////////////////////////
  M->objective("objx", ObjectiveSense::Maximize, Expr::dot(c, x));
  M->objective("objy", ObjectiveSense::Maximize, Expr::dot(cy, y));

  //////////////////////////////////////
  // Solve the problem
  //////////////////////////////////////
  M->solve();

  // Get the solution values
  auto sol = x->level();
  std::cout << "[x0,x1,x2,x3] = " << (*sol) << "\n";
  auto soly = y->level();
  std::cout << "[y0,y1,y2,y3] = " << (*soly) << "\n";
}

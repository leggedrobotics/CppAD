// BEGIN SHORT COPYRIGHT
/* -----------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-05 Bradley M. Bell

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
------------------------------------------------------------------------ */
// END SHORT COPYRIGHT

/*
Test of CondExp with AD< AD< Base > > types
*/

# include <CppAD/CppAD.h>

typedef CppAD::AD< double >     ADdouble;
typedef CppAD::AD< ADdouble > ADADdouble;

bool CondExpAD(void)
{	bool ok = true;

	using namespace CppAD;
	size_t n = 3;
	size_t m = 8;

	// ADdouble independent variable vector
	CppADvector< ADdouble > Xa(n);
	Xa[0] = -1.;
	Xa[1] =  0.;
	Xa[2] =  1.;
	Independent(Xa);

	// ADdouble independent variable vector
	CppADvector< ADADdouble > Xaa(n);
	Xaa[0] = Xa[0];
	Xaa[1] = Xa[1];
	Xaa[2] = Xa[2];
	Independent(Xaa);

	// ADADdouble parameter
	ADADdouble p = ADADdouble(Xa[0]);
	ADADdouble q = ADADdouble(Xa[1]);
	ADADdouble r = ADADdouble(Xa[2]);

	// ADADdouble dependent variable vector
	CppADvector< ADADdouble > Yaa(m);

	// CondExp(parameter, parameter, parameter)
	Yaa[0] = CondExp(p, q, r);

	// CondExp(parameter, parameter, variable)
	Yaa[1] = CondExp(p, q, Xaa[2]);

	// CondExp(parameter, varaible, parameter)
	Yaa[2] = CondExp(p, Xaa[1], r);

	// CondExp(parameter, variable, variable)
	Yaa[3] = CondExp(p, Xaa[1], Xaa[2]);

	// CondExp(variable, variable, variable)
	Yaa[5] = CondExp(Xaa[0], Xaa[1], Xaa[2]);

	// CondExp(variable, variable, parameter)
	Yaa[4] = CondExp(Xaa[0], Xaa[1], r);

	// CondExp(variable, parameter, variable)
	Yaa[6] =  CondExp(Xaa[0], q, Xaa[2]);

	// CondExp(variable, parameter, parameter)
	Yaa[7] =  CondExp(Xaa[0], q, r);

	// create fa: Xaa -> Yaa function object
	ADFun< ADdouble > fa(Xaa, Yaa);

	// function values 
	CppADvector< ADdouble > Ya(m);
	Ya  = fa.Forward(0, Xa);

	// create f: Xa -> Ya function object
	ADFun<double> f(Xa, Ya);

	// check result of function evaluation
	CppADvector<double> x(n);
	CppADvector<double> y(m);
	x[0] = 1.;
	x[1] = 0.;
	x[2] = -1.;
	y = f.Forward(0, x);
	size_t i;
	for(i = 0; i < m; i++)
	{	// y[i] = CondExp(x[0], x[1], x[2])
		if( x[0] > 0 )
			ok &= (y[i] == x[1]);
		else	ok &= (y[i] == x[2]);
	}

	// check forward mode derivatives
	CppADvector<double> dx(n);
	CppADvector<double> dy(m);
	dx[0] = 1.;
	dx[1] = 2.;
	dx[2] = 3.;
	dy    = f.Forward(1, dx);
	for(i = 0; i < m; i++)
	{	if( x[0] > 0. )
			ok &= (dy[i] == dx[1]);
		else	ok &= (dy[i] == dx[2]);
	}

	// calculate Jacobian
	CppADvector<double> J(m * n);
	size_t j;
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
			J[i * n + j] = 0.;
		if( x[0] > 0. )
			J[i * n + 1] = 1.;
		else	J[i * n + 2] = 1.;
	}

	// check reverse mode derivatives
	for(i = 0; i < m; i++)
		dy[i] = double(i);
	dx    = f.Reverse(1, dy);
	double sum;
	for(j = 0; j < n; j++)
	{	sum = 0;
		for(i = 0; i < m; i++)
			sum += dy[i] * J[i * n + j];
		ok &= (sum == dx[j]);
	}

	return ok;
}
// END PROGRAM

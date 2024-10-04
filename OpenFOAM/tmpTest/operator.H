/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2017 OpenFOAM Foundation
    Copyright (C) 2016-2023 OpenCFD Ltd.
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Description
    Overloading the "+" operator globally to handle 
    std::shared_ptr<fvVectorMatrix> objects

\*---------------------------------------------------------------------------*/

#ifndef Foam_operator_H
#define Foam_operator_H

#include "fvCFD.H"
#include "memory"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
template<class Type>
std::shared_ptr<Foam::fvMatrix<Type>> Foam::operator+
(
    const std::shared_ptr<fvMatrix<Type>>& tA,
    const std::shared_ptr<fvMatrix<Type>>& tB
)
{
    std::shared_ptr<fvMatrix<Type>> tC(new fvMatrix<Type>(*tA));
    *tC += *tB;
    return tC;
}
}

#endif

// ************************************************************************* //

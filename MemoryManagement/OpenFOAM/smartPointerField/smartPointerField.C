/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2016 OpenFOAM Foundation
    Copyright (C) 2019 OpenCFD Ltd.
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

Application
    smartPointerField.C

Description
    Smart Pointer Efficiency Demo in OpenFOAM for Field<Type>

    Demonstrates the efficiency of using smart pointers (tmp<Type>) 
    versus deep copying in handling large fields. We initialize a scalar
    field and pass it to functions that are supposed to some calculations.
    One function use tmp<> while the other does not.

    Author: Saeed Salehi, saeed.salehi@chalmers.se
    The proghram is Inspired by examples from the Book:
    Marić et al. "The OpenFOAM® Technology Primer"

\*---------------------------------------------------------------------------*/

#include "infoField.H"

using namespace Foam;
typedef infoField<scalar> infoScalarField;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

template <typename Type>
Type someOperationValue(const Type& t)
{
    // One copy construction for the temporary.
    Type temp = t;
    temp *= 2; // ... some operations on the field.

    return temp;
}

template <typename Type>
tmp<Type> someOperationPointer(const Type& t)
{
    // One copy construction for the temporary.
    tmp<Type> ttemp = tmp<Type>(new Type(t));

    Type& temp = ttemp.ref();
    temp *= 2; // ... some operations on the field.

    return ttemp;
}

int main(int argc, char *argv[])
{
    Info << "Hello" << endl;

    Info << "Constructing the initial field" << endl;
    infoScalarField initialField(1e07, 1); // Large field construction.
    
    infoScalarField finalField;            // Final field for the value return
    tmp<infoScalarField> tfinalField;      // Final field for the pointer return
    
    Info << nl << "Calling someOperationValue" << endl;
    finalField = someOperationValue(initialField);
    Info << "First element of someOperationValue result: " << finalField[0] << endl;

    Info << nl <<"Calling someOperationPointer" << endl;
    tfinalField = someOperationPointer(initialField);
    Info << "First element of someOperationPointer result: " << tfinalField()[0] << endl;

    Info << nl << "Bye" << endl;
    return 0;
}

// To profile: 
// valgrind --tool=callgrind --simulate-cache=yes smartPointerField
// kcachegrind callgrind.out.*****

// ************************************************************************* //

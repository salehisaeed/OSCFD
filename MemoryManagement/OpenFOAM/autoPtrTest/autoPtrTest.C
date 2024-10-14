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
    autoPtrTest.C

Description
    some basic functionalities of autoPtr class in OpenFOAM

    Author: Saeed Salehi, saeed.salehi@chalmers.se

\*---------------------------------------------------------------------------*/

#include "Field.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    Info << "Hello" << endl;

    autoPtr<scalarField> fieldPtr(new scalarField(10, 1));

    // Output the pointer address and data
    Info<< "pointer: " << name(fieldPtr) << nl;
    Info<< "content: " << fieldPtr() << nl;

    // Copy the pointer (Is it possible?)
    autoPtr<scalarField> fieldPtrCopy (fieldPtr);

    //Accessing both pointers
    Info<< "pointer: " << name(fieldPtrCopy) << nl;
    Info<< "pointer: " << name(fieldPtr) << nl;

    Info << "Bye" << endl;

    return 0;
}

// ************************************************************************* //

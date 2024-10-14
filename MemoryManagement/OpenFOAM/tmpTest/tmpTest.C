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
    tmpTest.C

Description
    some basic functionalities of tmp in OpenFOAM

    Author: Saeed Salehi, saeed.salehi@chalmers.se

\*---------------------------------------------------------------------------*/

#include "Field.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    Info << "Hello" << endl;

    tmp<scalarField> tfield(new scalarField(10, 1));
    Info<< "address: " << name(tfield.get()) << nl;
    Info<< "reference count: " << tfield->use_count() << nl;

    tmp<scalarField> tfieldCopy1(tfield);
    Info<< "address: " << name(tfieldCopy1.get()) << nl;
    Info<< "reference count: " << tfield->use_count() << nl;

    // tmp<scalarField> tfieldCopy2(tfieldCopy1); // Runtime error

    tfieldCopy1.clear();
    Info<< "reference count: " << tfield->use_count() << nl;

    Info << "Bye" << endl;

    return 0;
}

// ************************************************************************* //

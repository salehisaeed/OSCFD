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
    icoFoam

Description
    Experimenting with the smart pointers to see how the temporary objects are handled

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "pisoControl.H"
// #include <memory> //not nedded as it is already loaded in OpenFOAM
#include "operator.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"
    #include "createFields.H"

    fvVectorMatrix ddt(fvm::ddt(U));
    fvVectorMatrix div(fvm::div(phi, U));

    fvVectorMatrix sum1 = ddt + div;
    tmp<fvVectorMatrix> sum2 = ddt + div;

    std::shared_ptr<fvVectorMatrix> sharedPtr_m2 = std::make_shared<fvVectorMatrix>(ddt);
    std::shared_ptr<fvVectorMatrix> sharedPtr_m1 = std::make_shared<fvVectorMatrix>(div);

    fvVectorMatrix sum5 = *sharedPtr_m1 + *sharedPtr_m2;
    std::shared_ptr<fvVectorMatrix> sum6 = sharedPtr_m1 + sharedPtr_m2;

    return 0;
}

// ************************************************************************* //

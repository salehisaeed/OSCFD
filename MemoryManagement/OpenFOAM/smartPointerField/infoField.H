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
    A derived class of Field<Type> that provides some extra information 

\*---------------------------------------------------------------------------*/

#ifndef Foam_infoField_H
#define Foam_infoField_H

#include "Field.H"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
template<class Type>
class infoField
:
    public Field<Type>
{
public:

    infoField()
    :
        Field<Type>()
    {
        Info << "empty constructor" << endl;
    }

    infoField(const infoField<Type>& other)
    :
        Field<Type>(other)
    {
        Info << "copy constructor" << endl;
    }

    infoField(label size, Type value)
    :
        Field<Type>(size, value)
    {
        Info << "size, value constructor" << endl;
    }

    ~infoField()
    {
        Info << "destructor" << endl;
    }

    void operator=(const infoField<Type>& other)
    {
        if (this != &other)
        {
            Field<Type>::operator=(other);
            Info << "assignment operator" << endl;
        }
    }
};

} // End namespace Foam
 
#endif

// ************************************************************************* //

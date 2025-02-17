/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2016-2021 hyStrath
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of hyStrath, a derivative work of OpenFOAM.

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

Class
    Foam::mhdModel::noMHD

Description
    Dummy MHD model for 'none' option

SourceFiles
    noMHD.C

\*---------------------------------------------------------------------------*/

#ifndef noMHD_H
#define noMHD_H

#include "mhdModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace mhd
{

/*---------------------------------------------------------------------------*\
                            Class noMHD Declaration
\*---------------------------------------------------------------------------*/

class noMHD
:
    public mhdModel
{
    // Private Member Functions

        //- Disallow default bitwise copy construct
        noMHD(const noMHD&);

        //- Disallow default bitwise assignment
        void operator=(const noMHD&);


public:

    //- Runtime type information
    TypeName("noMHD");


    // Constructors

        //- Construct from components
        noMHD(const rho2ReactionThermo& thermo);

        //- Construct from components
        noMHD(const dictionary& dict, const rho2ReactionThermo& thermo);


    //- Destructor
    virtual ~noMHD();


    // Member functions

        // Edit

          //- Read mhdProperties dictionary
          virtual bool read();
          
          //- Update MHD model
          virtual void update(const volVectorField& U);
          
          //- Return non-const access to the electric field
          virtual volVectorField& E();
        
          //- Return non-const access to the electric potential field
          virtual volScalarField& elecPot();
          
          //- Return non-const access to the total magnetic field
          virtual volVectorField& B();
          
        //Access
       
          //- Joule heating: source term in the total energy equation
          virtual tmp<volScalarField> jouleHeating
          (
              const volVectorField& U
          ) const;
            
          //- Lorentz force: source term in the momentum equations
          virtual tmp<volVectorField> lorentzForce() const;
          
          //- Return const access to the electrical conductivity field
          virtual const volTensorField& sigma() const;
         
          //- Return const access to the electric field
          virtual const volVectorField& E() const;
        
          //- Return const access to the electric potential field
          virtual const volScalarField& elecPot() const;
          
          //- Return const access to the total magnetic field
          virtual const volVectorField& B() const;

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace mhd
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //

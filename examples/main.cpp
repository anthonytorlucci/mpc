#include <iostream>

// examples
/* utilities */
#include "mpcx_constants.hpp"
#include "mpcx_printtensorcomponents.hpp"
#include "mpcx_accumulator.hpp"
#include "mpcx_innerproductor.hpp"
#include "mpcx_arithmeticaverage.hpp"
#include "mpcx_harmonicaverage.hpp"
#include "mpcx_kdeltaidentitytensor.hpp"
#include "mpcx_magandnorm.hpp"
// TODO: blitz2eigen and eigen2blitz
// TODO: unwrapper
// TODO: exactpolynomial roots
// TODO: lin- log- and geomspace (functions base)
#include "mpcx_coordinatemapping.hpp"


/* core */
#include "mpcx_tensorrank2componentindex.hpp"
#include "mpcx_tensorrank4componentindex.hpp"
#include "mpcx_tensorrank2component.hpp"
#include "mpcx_tensorrank4component.hpp"
#include "mpcx_symmetrytypes.hpp"
#include "mpcx_stiffnesscompliance_csrelationship.hpp"


/* data */
#include "mpcx_mineraldata.hpp"
#include "mpcx_symmetrymatrixrepresentation.hpp"


/* rockphysics */
#include "mpcx_rockphysicstransforms.hpp"
#include "mpcx_tensorinvariants.hpp"
#include "mpcx_fluidphase.hpp"
#include "mpcx_solidphase.hpp"
#include "mpcx_mixinglaws.hpp"


/* transformation */
#include "mpcx_eulerangles.hpp"
#include "mpcx_transformation.hpp"


/* mechanics */
#include "mpcx_greenchristoffel.hpp"
#include "mpcx_quartzvelsinX0X1plane.hpp"
#include "mpcx_orientationdistribution.hpp"



int main() {
    std::cout << "MPC EXAMPLES \n" << std::endl;

    /* utilites */
    //mpcexamples::mpcConstants();
    //mpcexamples::mpcPrintTensorComponents();
    //mpcexamples::mpcAccumulator();
    //mpcexamples::mpcInnerProductor();
    //mpcexamples::mpcArithmeticAverage();
    //mpcexamples::mpcHarmonicAverage();
    //mpcexamples::mpcKroneckerDeltaAndIdentityTensor();
    //mpcexamples::mpcMagnitudeAndNorms();
    // TODO: blitz2eigen and eigen2blitz
    // TODO: unwrapper
    // TODO: exactpolynomial roots
    // TODO: lin- log- and geomspace (functions base)
    //mpcexamples::mpcCoordinateMapping();

    /* core */
    //mpcexamples::mpcTensorRank2ComponentIndex();
    //mpcexamples::mpcTensorRank4ComponentIndex();
    //mpcexamples::mpcTensorRank2Component();
    //mpcexamples::mpcTensorRank4Component();
    //mpcexamples::mpcSymmetryTypes();
    //mpcexamples::mpcStiffnessComplianceCSRelationship();

    /* data */
    //mpcexamples::mpcMineralData();
    //mpcexamples::mpcSymmetryMatrixRepresentation();

    /* rockphysics */
    //mpcexamples::mpcRockPhysicsTransforms();
    //mpcexamples::mpcTensorInvariants();
    //mpcexamples::mpcFluidPhase();
    //mpcexamples::mpcSolidPhase();
    mpcexamples::mpcMixingLaws();  // TODO:


    /* transformation */
    //mpcexamples::mpcEulerAngles();
    //mpcexamples::mpcTransformation();


    /* mechanics */
    //mpcexamples::mpcGreenChristoffel();

    //mpcexamples::mpcQuartzVelsInX0X1Plane();
    //mpcexamples::mpcOrientationDistribution();


    return 0;
}
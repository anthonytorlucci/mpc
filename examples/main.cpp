#include <iostream>

// examples
#include "mpcx_tensorrank2componentindex.hpp"
#include "mpcx_tensorrank4componentindex.hpp"
#include "mpcx_tensorrank2component.hpp"
#include "mpcx_tensorrank4component.hpp"
#include "mpcx_symmetrytypes.hpp"
#include "mpcx_symmetrymatrixrepresentation.hpp"
#include "mpcx_hookeslaw_csrelationship.hpp"
#include "mpcx_transformation.hpp"
#include "mpcx_mineraldata.hpp"
#include "mpcx_rockphysicstransforms.hpp"
#include "mpcx_tensorinvariants.hpp"
#include "mpcx_greenchristoffel.hpp"
#include "mpcx_mixinglaws.hpp"
#include "mpcx_quartzvelsinX0X1plane.hpp"
#include "mpcx_orientationdistribution.hpp"
#include "mpcx_coordinatemapping.hpp"
#include "mpcx_moreeulerangles.hpp"

int main() {
    std::cout << "MPC EXAMPLES \n" << std::endl;

    //mpcexamples::mpcTensorRank2ComponentIndex();
    //mpcexamples::mpcTensorRank4ComponentIndex();
    //mpcexamples::mpcTensorRank2Component();
    //mpcexamples::mpcTensorRank4Component();
    //mpcexamples::mpcSymmetryTypes();
    //mpcexamples::mpcSymmetryMatrixRepresentation();
    //mpcexamples::mpcHookesLawCSRelationship();
    //mpcexamples::mpcTransformation();
    //mpcexamples::mpcMineralData();
    mpcexamples::mpcRockPhysicsTransforms();
    //mpcexamples::mpcTensorInvariants();
    //mpcexamples::mpcGreenChristoffel();
    //mpcexamples::mpcMixingLaws();
    //mpcexamples::mpcQuartzVelsInX0X1Plane();
    //mpcexamples::mpcOrientationDistribution();
    //mpcexamples::mpcCoordinateMapping();
    //mpcexamples::mpcMoreEulerAngles();

    return 0;
}
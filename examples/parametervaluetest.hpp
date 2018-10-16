#ifndef PARAMETERVALUETEST_H
#define PARAMETERVALUETEST_H

#include <iostream>

// mpc
#include <mpc/core/symmetrygrouptypes.hpp>
#include <mpc/core/cstypes.hpp>

namespace mpcexamples {

template <bool B>
class BooleanTypeParameterValueTest {
    friend std::ostream& operator<<( std::ostream& os, const BooleanTypeParameterValueTest& t ) {
        os << "using parameter type bool and value " << B;
        return os;
    }
};

template <int N>
class IntTypeParameterValueTest {
    friend std::ostream& operator<<( std::ostream& os, const IntTypeParameterValueTest& t ) {
        os << "using parameter type int and value " << N;
        return os;
    }
};

template <mpc::core::SymmetryGroupEnumeration S>
class SymmetryGroupEnumerationTypeParameterValueTest {
    friend std::ostream& operator<<( std::ostream& os, const SymmetryGroupEnumerationTypeParameterValueTest& t ) {
        os << "using parameter type SymmetryGroupEnumeration and value " << S;
        return os;
    }
};

template <mpc::core::CSEnumeration C>
class CSEnumerationTypeParameterValueTest {
    friend std::ostream& operator<<( std::ostream& os, const CSEnumerationTypeParameterValueTest& t ) {
        os << "using parameter type CSEnumeration and value " << C;
        return os;
    }
};

} // namespace mpcuserguide

#endif // PARAMETERVALUETEST_H

/**
 *    @file cstypes.hpp
 *    @brief stiffness and compliance sructs used as types for template specializations
 *
 *
 *    @author Anthony Torlucci
 *    @date 9/16/2018
 */

#ifndef MPC_CSENUMERATION_H
#define MPC_CSENUMERATION_H

#include <iostream>

// blitz
#include <blitz/array.h>

// mpc

namespace mpc {
namespace core {

enum class CSEnumeration {
        STIFFNESS,
        COMPLIANCE
};

struct CSEnumerationInterface {

//    SYMMETRY symmetry;

        static std::string ToStr(CSEnumeration cs_enum) {
                switch (cs_enum) {
                case CSEnumeration::STIFFNESS:
                        return "stiffness";
                case CSEnumeration::COMPLIANCE:
                        return "compliance";
                }

                return std::string();
        }
};

inline std::ostream& operator<<(std::ostream& os, CSEnumeration cs_enum) {
        os << CSEnumerationInterface::ToStr(cs_enum);
        return os;
}

typedef std::integral_constant<CSEnumeration, CSEnumeration::STIFFNESS> cs_stiffness_t;
typedef std::integral_constant<CSEnumeration, CSEnumeration::COMPLIANCE> cs_compliance_t;

struct CSBase {};

// specializations
struct StiffnessType : public CSBase {
        const CSEnumeration cs_enumeration = CSEnumeration::STIFFNESS;
        constexpr static inline CSEnumeration CSEnum() {
                return CSEnumeration::STIFFNESS;
        }
};

struct ComplianceType : public CSBase {
        const CSEnumeration cs_enumeration = CSEnumeration::COMPLIANCE;
        constexpr static inline CSEnumeration CSEnum() {
                return CSEnumeration::COMPLIANCE;
        }
};

} // namespace core
} // namespace mpc


#endif // MPC_CSENUMERATION_H

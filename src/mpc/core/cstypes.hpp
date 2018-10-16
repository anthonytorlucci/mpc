/**
 *    @file cstypes.hpp
 *    @brief stiffness and compliance sructs used as types for template specializations
 *
 *
 *    @author Anthony Torlucci
 *    @date 2018/10/14
 */

#ifndef MPC_CSTYPES_H
#define MPC_CSTYPES_H

#include <iostream>

// blitz
#include <blitz/array.h>

// mpc

namespace mpc {
    namespace core {

        /**
         * \enum CSEnumeration
         * \brief stiffness compliance types enumeration
         */
        enum class CSEnumeration {
            STIFFNESS,
            COMPLIANCE
        };

        /**
         * \class CSEnumerationInterface
         * \brief interface to convert enum to std::string
         */
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

        /**
         * \typedef cs_stiffness_t
         */
        typedef std::integral_constant<CSEnumeration, CSEnumeration::STIFFNESS> cs_stiffness_t;

        /**
         * \typedef cs_compliance_t
         */
        typedef std::integral_constant<CSEnumeration, CSEnumeration::COMPLIANCE> cs_compliance_t;

        /**
         * \class CSBase
         * \brief base class for stiffness compliance types
         *
         * mpc template specializations rely on this class for static_assert()
         */
        struct CSBase {};

        /**
         * \class StiffnessType
         * \brief simple class used mainly for template specializations in mpc
         */
        struct StiffnessType : public CSBase {
            const CSEnumeration cs_enumeration = CSEnumeration::STIFFNESS;
            constexpr static inline CSEnumeration CSEnum() {
                return CSEnumeration::STIFFNESS;
            }
        };

        /**
         * \class ComplianceType
         * \brief simple class used mainly for template specializations in mpc
         */
        struct ComplianceType : public CSBase {
            const CSEnumeration cs_enumeration = CSEnumeration::COMPLIANCE;
            constexpr static inline CSEnumeration CSEnum() {
                return CSEnumeration::COMPLIANCE;
            }
        };

    } // namespace core
} // namespace mpc


#endif // MPC_CSTYPES_H

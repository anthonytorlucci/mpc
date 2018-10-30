/**
 *    \file unitconversion.hpp
 *    \brief convert between different units
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/27
 */

#ifndef MPC_UNITCONVERSION_H
#define MPC_UNITCONVERSION_H

// c++
#include <tuple>
#include <type_traits>
#include <cmath>

// blitz

//mpc


namespace mpc {
    namespace utilities {

        // Simple functions for converting between units.
        // SHOULD BE REPLACED WITH COMPLETE DIMENSIONAL ANALYSIS LIBRARY WITH IMPLICIT CONVERSIONS

        // TODO: additional convenicence functions for dimensional analysis
        // REF: Mavko, Mukerji, and Dvorkin, 2009, The Rock Physics Handbook, second edition: Cambridge University Press
        // =============================================================================================================
        // MASS/WEIGHT
        /*! \fn T grams2kilograms(T val)
            \brief converts the input quantity grams to kilograms
            \param val input quantity in grams

            \warning not type safe!
         */
        template <typename T>
        constexpr T grams2kilograms(T val) {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            return val * 0.001;
        }

        /*! \fn T kilograms2grams(T val)
            \brief converts the input quantity kilograms to grams
            \param val input quantity in kilograms

            \warning not type safe!
         */
        template <typename T>
        constexpr T kilograms2grams(T val) {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            return val * 1000;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T kilograms2pounds(T val) {
            static_assert(std::is_floating_point<T>::value, "Type T must be of type float, double, or long double");
            return val * 2.204623;
        }


        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T pounds2kilograms(T val) {
            return val * 0.4535924;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T grams2pounds(T val) {
            return val * 0.002204623;
        }

        /*! \fn T
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T pounds2grams(T val) {
            return val * 453.5924;
        }


        // =============================================================================================================
        // LENGTH
        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T meters2inches(T val) {
            return val * 39.37;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T meters2feet(T val) {
            return val * 3.2808399;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T centimeters2inches(T val) {
            return val * 0.3937;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T centimeter2feet(T val) {
            return val * 0.032808399;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T centimeters2meters(T val) {
            return val * 100;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T meters2centimeters(T val) {
            return val * 0.01;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T inches2centimeters(T val) {
            return val * 2.540005;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T inches2meters(T val) {
            return val * 0.02540005;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T feet2centimeters(T val) {
            return val * 30.48006;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T feet2meters(T val) {
            return val * 0.3048006;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T kilometers2miles(T val) {
            return val * 0.62137;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T miles2kilometers(T val) {
            return val * 1.60935;
        }

        // ======================================================================
        // VELOCITY / SLOWNESS / TRANSIT-TIME
        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T meterspersecond2feetpersecond(T val) {
            return val * 3.2808;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T feetpersecond2meterspersecond(T val) {
            return val * 0.3048;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T milesperfhour2kilometersperhour(T val) {
            return val * 1.609;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T milesperhour2meterspersecond(T val) {
            return val * 0.447;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T milesperhour2feetpersecond(T val) {
            return val * 1.47;
        }


        // ======================================================================
        // AREA
        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T meterssquared2centimeterssquared(T val) {
            return val * 10000;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T meterssquared2feetsquared(T val) {
            return val * 10.764;
        }

        // TODO: complete

        // ======================================================================
        // DENSITY
        // TODO: complete


        // ======================================================================
        // VOLUME

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T cubicmeter2cubicfoot(T val) {
            return val * 35.3147;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T cubicfoot2cubicmeter(T val) {
            return val * 0.0283168;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T cubicmeter2cubiccentimeter(T val) {
            return val * 1E+6;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T cubiccentimeter2cubicmeter(T val) {
            return val * 1E-6;
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T cubicfoot2cubiccentimeter(T val) {
            T m3 = cubicfoot2cubicmeter(val);
            return cubicmeter2cubiccentimeter(m3);
        }

        /*! \fn
            \brief
            \param

            \warning not type safe!
         */
        template <typename T>
        constexpr T cubiccentimeter2cubicfoot(T val) {
            T m3 = cubiccentimeter2cubicmeter(val);
            return cubicmeter2cubicfoot(m3);
        }

        // ======================================================================
        // FORCE


        // ======================================================================
        // PRESSURE

        // ======================================================================
        // PRESSURE GRADIENTS( OR MUD WEIGHT TO PRESSURE GRADIENT)

        // ======================================================================
        // MUD DENSITY TO PRESSURE GRADIENT

        // ======================================================================
        // VISCOSITY

        // ======================================================================
        // PERMEABILITY

        // ======================================================================
        // GAS-OIL RATIO

        // ======================================================================
        // OTHER CONVERSIONS




    } // namespace utilities
} // namespace mpc

#endif // MPC_UNITCONVERSION_H

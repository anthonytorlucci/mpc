/**
 *    \file scalarcomposites.hpp
 *    \brief simple scalar composites ...
 *
 *    These classes are a simplified abstraction of a composite material.  The input rock properties are scalar values and the effective rock properties are scalar functions.  Certain assumptions are made that reduce the complex mathematics of micromechanics to simple averaging ...
 *
 *                                  FluidPhase             SolidPhase
 *    effective density             arithmetic average     arithmetic average
 *    effective bulk modulus        harmonic average       Voigt Ruess Hill average
 *    effective shear modulus       N/A                    Voigt Ruess Hill average
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_SCALARCOMPOSITES_H
#define MPC_SCALARCOMPOSITES_H

// c++
#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <tuple>
#include <utility>

// mpc
#include "mpc/utilities/arithmeticaverage.hpp"
#include "mpc/utilities/harmonicaverage.hpp"
#include "mpc/rockphysics/rockphysicstransformstypes.hpp"

/**
* \namespace mpc
*/
namespace mpc {
    namespace rockphysics {

        // https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern

        // refs
        /*
         * Mavko, Gary, Mukerji, Tapan, Dvorkin, Jack, 2009, The Rock Physics Handbook - Tools for Seismic Analysis of Porous Media: Cambridge University Press.
         *
         * Avseth, Per, Mukerji, Tapan, Mavko, Gary, 2005, Quantitative Seismic Interpretation - Applying Rock Physics Tools to Reduce Interpretation Risk: Cambridge University Press.
         *
         * Vernik, Lev, 2016, Seismic Petrophysics in Quantitative Interpretation: SEG
         *
         * Smith, Tad M., Sondergeld, Carl H., Rai, Chandra, S., 2003, Gassman fluid substitution: A tutorial: GEOPHYSICS, 68, 2, 430-440.
         *
         * Dvorkin, Jack, Gutierrez, Mario A., Grana, Dario, 2014, Seismic Reflections of Rock Properties: Cambridge University Press.
         */

        template <typename T, typename U>
        class ScalarCompositesBase {
            static_assert(std::is_arithmetic<T>::value, "Type T must be arithmetic");
            //static_assert(std::is_base_of<ScalarCompositesBase,U>::value, "U must be derived from mpc::rockphysics::ScalarCompositeBase.");
        protected:
            mpc::rockphysics::DensityType<T> effective_density_type = mpc::rockphysics::DensityType<T>(1.0);
            mpc::rockphysics::BulkModulusType<T> effective_bulkmodulus_type = mpc::rockphysics::BulkModulusType<T>(1.0);
            mpc::rockphysics::ShearModulusType<T> effective_shearmodulus_type = mpc::rockphysics::ShearModulusType<T>(1.0);
            std::vector< mpc::rockphysics::BulkModulusType<T> > bulkmodulus_type_vector;
            std::vector< mpc::rockphysics::ShearModulusType<T> > shearmodulus_type_vector;
            std::vector< mpc::rockphysics::DensityType<T> > density_type_vector;
            std::vector< mpc::rockphysics::VolumeFractionType<T> > volumefraction_type_vector;

        private:
            void NormalizeVolumeFractionTypeVector() {
                // if the sum of the elements in volumefraction_type_vector is not one, normalize
                // TODO: two loops is ugly; how can this better?
                //std::cout << "normalized volume fraction called" << std::endl;
                T tmp = 0;
                for (auto vf_type : volumefraction_type_vector) {
                    tmp += vf_type.value;
                }
                //std::cout << "normalized volume fraction sum : " << tmp << std::endl;
                if (tmp != 1.0) {
                    for (auto &vf_type : volumefraction_type_vector) {
                        vf_type.value /= tmp;
                    }
                }

            }

        public:
            ScalarCompositesBase() : effective_bulkmodulus_type(mpc::rockphysics::BulkModulusType<T>(1.0)),
                effective_shearmodulus_type(mpc::rockphysics::ShearModulusType<T>(1.0)),
                effective_density_type(mpc::rockphysics::DensityType<T>(1.0)) {
                //
                //std::cout << "ScalarCompositesBase default constructor called" << std::endl;
            }

            ScalarCompositesBase(const std::vector< std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T>, mpc::rockphysics::VolumeFractionType<T> > >& vec) {
                // f : std::function<void()> object that tells ScalarCompositeBase how to update the effective moduli

                //std::cout << "ScalarCompositesBase(vec) constructor called" << std::endl;
                SetCompositeComponents(vec);
            }

            void SetCompositeComponents(const std::vector< std::tuple<T,T,T,T> >& vec) {
                //std::cout << "ScalarCompositesBase::SetComponents(...) called." << std::endl;
                // no type saftey !!!
                volumefraction_type_vector.clear();
                bulkmodulus_type_vector.clear();
                shearmodulus_type_vector.clear();
                density_type_vector.clear();
                for (auto v : vec) {
                    T K = std::get<0>(v);
                    bulkmodulus_type_vector.push_back(mpc::rockphysics::BulkModulusType<T>(K));
                    T mu = std::get<1>(v);
                    shearmodulus_type_vector.push_back(mpc::rockphysics::ShearModulusType<T>(mu));
                    T rho = std::get<2>(v);
                    density_type_vector.push_back(mpc::rockphysics::DensityType<T>(rho));
                    T vf = std::get<3>(v);
                    volumefraction_type_vector.push_back(mpc::rockphysics::VolumeFractionType<T>(vf));
                }
                NormalizeVolumeFractionTypeVector();
                // update the effective values
                std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > effective_values = U::EffectiveValues(bulkmodulus_type_vector, shearmodulus_type_vector, density_type_vector, volumefraction_type_vector);
                // TODO: assign effective values
                effective_bulkmodulus_type = std::get<0>(effective_values);
                effective_shearmodulus_type = std::get<1>(effective_values);
                effective_density_type = std::get<2>(effective_values);
            }

            void SetCompositeComponents(const std::vector< std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T>, mpc::rockphysics::VolumeFractionType<T> > >& vec) {
                //std::cout << "ScalarCompositesBase::SetComponents(...) called." << std::endl;
                //
                volumefraction_type_vector.clear();
                bulkmodulus_type_vector.clear();
                shearmodulus_type_vector.clear();
                density_type_vector.clear();
                for (auto v : vec) {
                    // s => std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T>, mpc::rockphysics::VolumeFractionType<T>
                    bulkmodulus_type_vector.push_back(std::get<0>(v));
                    shearmodulus_type_vector.push_back(std::get<1>(v));
                    density_type_vector.push_back(std::get<2>(v));
                    volumefraction_type_vector.push_back(std::get<3>(v));
                }
                NormalizeVolumeFractionTypeVector();
                // update the effective values
                std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > effective_values = U::EffectiveValues(bulkmodulus_type_vector, shearmodulus_type_vector, density_type_vector, volumefraction_type_vector);
                // TODO: assign effective values
                effective_bulkmodulus_type = std::get<0>(effective_values);
                effective_shearmodulus_type = std::get<1>(effective_values);
                effective_density_type = std::get<2>(effective_values);
            }

            // accessors / mutators
            mpc::rockphysics::DensityType<T> EffectiveDensityType() {
                //std::cout << "ScalarCompositesBase::EffectiveDensityType() called." << std::endl;
                return effective_density_type;
            }

            mpc::rockphysics::BulkModulusType<T> EffectiveBulkModulusType() {
                //std::cout << "ScalarCompositesBase::EffectiveBulkModulusType() called." << std::endl;
                return effective_bulkmodulus_type;
            }

            mpc::rockphysics::ShearModulusType<T> EffectiveShearModulusType() {
                //std::cout << "ScalarCompositesBase::EffectiveShearModulusType() called." << std::endl;
                return effective_shearmodulus_type;
            }

            std::vector< mpc::rockphysics::BulkModulusType<T> > BulkModulusTypeVector() {
                //std::cout << "ScalarCompositesBase::BulkModulusTypeVector() called." << std::endl;
                return bulkmodulus_type_vector;
            }
            void BulkModulusTypeVector(std::vector< mpc::rockphysics::BulkModulusType<T> > K_type_vec) {
                //std::cout << "ScalarCompositesBase::BulkModulusTypeVector(...) called." << std::endl;
                bulkmodulus_type_vector.clear();
                bulkmodulus_type_vector = K_type_vec;
                // update the effective values
                std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > effective_values = U::EffectiveValues(bulkmodulus_type_vector, shearmodulus_type_vector, density_type_vector, volumefraction_type_vector);
                // TODO: assign effective values
                effective_bulkmodulus_type = std::get<0>(effective_values);
                effective_shearmodulus_type = std::get<1>(effective_values);
                effective_density_type = std::get<2>(effective_values);
            }
            void BulkModulusTypeVector(std::vector<T>& K_vec) {
                //std::cout << "ScalarCompositesBase::BulkModulusTypeVector(...) called." << std::endl;
                // no type saftey !!!
                bulkmodulus_type_vector.clear();
                for (auto v : K_vec) {
                    bulkmodulus_type_vector.push_back(mpc::rockphysics::BulkModulusType<T>(v));
                }
                // update the effective values
                std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > effective_values = U::EffectiveValues(bulkmodulus_type_vector, shearmodulus_type_vector, density_type_vector, volumefraction_type_vector);
                // TODO: assign effective values
                effective_bulkmodulus_type = std::get<0>(effective_values);
                effective_shearmodulus_type = std::get<1>(effective_values);
                effective_density_type = std::get<2>(effective_values);
            }

            std::vector< mpc::rockphysics::ShearModulusType<T> > ShearModulusTypeVector() {
                //std::cout << "ScalarCompositesBase::ShearModulusTypeVector() called." << std::endl;
                return shearmodulus_type_vector;
            }
            void ShearModulusTypeVector(std::vector< mpc::rockphysics::ShearModulusType<T> > mu_type_vec) {
                //std::cout << "ScalarCompositesBase::ShearModulusTypeVector(...) called." << std::endl;
                shearmodulus_type_vector.clear();
                shearmodulus_type_vector = mu_type_vec;
                // update the effective values
                std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > effective_values = U::EffectiveValues(bulkmodulus_type_vector, shearmodulus_type_vector, density_type_vector, volumefraction_type_vector);
                // TODO: assign effective values
                effective_bulkmodulus_type = std::get<0>(effective_values);
                effective_shearmodulus_type = std::get<1>(effective_values);
                effective_density_type = std::get<2>(effective_values);
            }
            void ShearModulusTypeVector(std::vector<T>& mu_vec) {
                //std::cout << "ScalarCompositesBase::ShearModulusTypeVector(...) called." << std::endl;
                // no type saftey !!!
                shearmodulus_type_vector.clear();
                for (auto v : mu_vec) {
                    shearmodulus_type_vector.push_back(mpc::rockphysics::ShearModulusType<T>(v));
                }
                // update the effective values
                std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > effective_values = U::EffectiveValues(bulkmodulus_type_vector, shearmodulus_type_vector, density_type_vector, volumefraction_type_vector);
                // TODO: assign effective values
                effective_bulkmodulus_type = std::get<0>(effective_values);
                effective_shearmodulus_type = std::get<1>(effective_values);
                effective_density_type = std::get<2>(effective_values);
            }

            std::vector< mpc::rockphysics::DensityType<T> > DensityTypeVector() {
                //std::cout << "ScalarCompositesBase::DensityTypeVector() called." << std::endl;
                return density_type_vector;
            }
            void DensityTypeVector(std::vector< mpc::rockphysics::DensityType<T> > rho_type_vec) {
                //std::cout << "ScalarCompositesBase::DensityTypeVector(...) called." << std::endl;
                density_type_vector.clear();
                density_type_vector = rho_type_vec;
                // update the effective values
                std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > effective_values = U::EffectiveValues(bulkmodulus_type_vector, shearmodulus_type_vector, density_type_vector, volumefraction_type_vector);
                // TODO: assign effective values
                effective_bulkmodulus_type = std::get<0>(effective_values);
                effective_shearmodulus_type = std::get<1>(effective_values);
                effective_density_type = std::get<2>(effective_values);
            }
            void DensityTypeVector(std::vector<T>& rho_vec) {
                //std::cout << "ScalarCompositesBase::DensityTypeVector(...) called." << std::endl;
                // no type saftey !!!
                density_type_vector.clear();
                for (auto v : rho_vec) {
                    density_type_vector.push_back(mpc::rockphysics::DensityType<T>(v));
                }
                // update the effective values
                std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > effective_values = U::EffectiveValues(bulkmodulus_type_vector, shearmodulus_type_vector, density_type_vector, volumefraction_type_vector);
                // TODO: assign effective values
                effective_bulkmodulus_type = std::get<0>(effective_values);
                effective_shearmodulus_type = std::get<1>(effective_values);
                effective_density_type = std::get<2>(effective_values);
            }


            std::vector< mpc::rockphysics::VolumeFractionType<T> > VolumeFractionTypeVector() {
                //std::cout << "ScalarCompositesBase::VolumeFractionTypeVector() called." << std::endl;
                return volumefraction_type_vector;
            }
            void VolumeFractionTypeVector(std::vector< mpc::rockphysics::VolumeFractionType<T> > vf_type_vec) {
                //std::cout << "ScalarCompositesBase::VolumeFractionTypeVector(...) called." << std::endl;
                volumefraction_type_vector.clear();
                volumefraction_type_vector = vf_type_vec;
                NormalizeVolumeFractionTypeVector();
                // update the effective values
                std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > effective_values = U::EffectiveValues(bulkmodulus_type_vector, shearmodulus_type_vector, density_type_vector, volumefraction_type_vector);
                // TODO: assign effective values
                effective_bulkmodulus_type = std::get<0>(effective_values);
                effective_shearmodulus_type = std::get<1>(effective_values);
                effective_density_type = std::get<2>(effective_values);
            }
            void VolumeFractionTypeVector(std::vector<T>& vf_vec) {
                //std::cout << "ScalarCompositesBase::VolumeFractionTypeVector(...) called." << std::endl;
                // no type saftey !!!
                volumefraction_type_vector.clear();
                for (auto v : vf_vec) {
                    volumefraction_type_vector.push_back(mpc::rockphysics::VolumeFractionType<T>(v));
                }
                NormalizeVolumeFractionTypeVector();
                // update the effective values
                std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > effective_values = U::EffectiveValues(bulkmodulus_type_vector, shearmodulus_type_vector, density_type_vector, volumefraction_type_vector);
                // TODO: assign effective values
                effective_bulkmodulus_type = std::get<0>(effective_values);
                effective_shearmodulus_type = std::get<1>(effective_values);
                effective_density_type = std::get<2>(effective_values);
            }

            // used in base class to calculate the effective values which are set in the base class member functions
            static std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > EffectiveValues(const std::vector< mpc::rockphysics::BulkModulusType<T> >& K_vec, const std::vector< mpc::rockphysics::ShearModulusType<T> >& mu_vec, const std::vector< mpc::rockphysics::DensityType<T> >& rho_vec, const std::vector< mpc::rockphysics::VolumeFractionType<T> >& vf_vec) {
                /*
                 * Precondition: all std::vectors are same size
                 */
                //std::cout << "ScalarCompositeBase::EffectiveValues() called." << std::endl;

                // initialize output variables
                mpc::rockphysics::BulkModulusType<T> K_type = mpc::rockphysics::BulkModulusType<T>(1.0);
                mpc::rockphysics::ShearModulusType<T> mu_type = mpc::rockphysics::ShearModulusType<T>(1.0);
                mpc::rockphysics::DensityType<T> rho_type = mpc::rockphysics::DensityType<T>(1.0);

                mpc::utilities::WeightedArithmeticAverage<T,0> arithmetic_average_fo; // mass balance, Voigt bounds
                //mpc::utilities::WeightedHarmonicAverage<T,0> harmonic_average_fo; // Ruess bounds

                // the above function objects require std::vector<T>, so ...
                int number_of_components = int(vf_vec.size());
                std::vector<T> K_vec_values(number_of_components);
                std::vector<T> mu_vec_values(number_of_components);
                std::vector<T> rho_vec_values(number_of_components);
                std::vector<T> vf_vec_values(number_of_components);
                for (int i=0; i<number_of_components; ++i) {
                    K_vec_values[i] = K_vec[i].value;
                    mu_vec_values[i] = mu_vec[i].value;
                    rho_vec_values[i] = rho_vec[i].value;
                    vf_vec_values[i] = vf_vec[i].value;
                }

                K_type.value = arithmetic_average_fo(K_vec_values, vf_vec_values);
                mu_type.value = arithmetic_average_fo(mu_vec_values, vf_vec_values);
                rho_type.value = arithmetic_average_fo(rho_vec_values, vf_vec_values);  // mass balance

                return std::make_tuple(K_type, mu_type, rho_type);
            }

        };


        // =============================================================================================================
        template <typename T>
        class FluidPhase : public ScalarCompositesBase< T, FluidPhase<T> > {

            using ScalarCompositesBase<T,FluidPhase>::effective_bulkmodulus_type;
            using ScalarCompositesBase<T,FluidPhase>::effective_shearmodulus_type;
            using ScalarCompositesBase<T,FluidPhase>::effective_density_type;
            using ScalarCompositesBase<T,FluidPhase>::bulkmodulus_type_vector;
            using ScalarCompositesBase<T,FluidPhase>::shearmodulus_type_vector;
            using ScalarCompositesBase<T,FluidPhase>::density_type_vector;
            using ScalarCompositesBase<T,FluidPhase>::volumefraction_type_vector;

        private:
            FluidPhase() {}  // no defualt constructor

        public:
            FluidPhase(const std::vector< std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T>, mpc::rockphysics::VolumeFractionType<T> > >& vec) : ScalarCompositesBase<T,FluidPhase>(vec) {}

            // used in base class to calculate the effective values which are set in the base class member functions
            static std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > EffectiveValues(const std::vector< mpc::rockphysics::BulkModulusType<T> >& K_vec, const std::vector< mpc::rockphysics::ShearModulusType<T> >& mu_vec, const std::vector< mpc::rockphysics::DensityType<T> >& rho_vec, const std::vector< mpc::rockphysics::VolumeFractionType<T> >& vf_vec) {
                /*
                 * Precondition: all std::vectors are same size
                 */
                //std::cout << "FluidPhase::EffectiveValues() called." << std::endl;

                // initialize output variables
                mpc::rockphysics::BulkModulusType<T> K_type = mpc::rockphysics::BulkModulusType<T>(1.0);
                mpc::rockphysics::ShearModulusType<T> mu_type = mpc::rockphysics::ShearModulusType<T>(1.0);
                mpc::rockphysics::DensityType<T> rho_type = mpc::rockphysics::DensityType<T>(1.0);

                mpc::utilities::WeightedArithmeticAverage<T,0> arithmetic_average_fo; // mass balance, Voigt bounds
                mpc::utilities::WeightedHarmonicAverage<T,0> harmonic_average_fo; // Ruess bounds

                // the above function objects require std::vector<T>, so ...
                int number_of_components = int(vf_vec.size());
                std::vector<T> K_vec_values(number_of_components);
                std::vector<T> mu_vec_values(number_of_components);
                std::vector<T> rho_vec_values(number_of_components);
                std::vector<T> vf_vec_values(number_of_components);
                for (int i=0; i<number_of_components; ++i) {
                    K_vec_values[i] = K_vec[i].value;
                    mu_vec_values[i] = mu_vec[i].value;
                    rho_vec_values[i] = rho_vec[i].value;
                    vf_vec_values[i] = vf_vec[i].value;
                }

                // [Dvorkin, et al., 2014, p. 16-17] "... If all individual fluid phases remain in perfect hydraulic communication, that is, the pressure in the gas is the same as in the oil and the same as in the water, the effective bulk modulus of such an immiscible system (K_f) is ..." [harmonic average]
                K_type.value = harmonic_average_fo(K_vec_values, vf_vec_values);
                mu_type.value = 0;
                rho_type.value = arithmetic_average_fo(rho_vec_values, vf_vec_values);  // mass balance

                return std::make_tuple(K_type, mu_type, rho_type);
            }



        };

        // =============================================================================================================
        template <typename T>
        class SolidPhase : public ScalarCompositesBase< T, SolidPhase<T> > {

            using ScalarCompositesBase<T,SolidPhase>::effective_bulkmodulus_type;
            using ScalarCompositesBase<T,SolidPhase>::effective_shearmodulus_type;
            using ScalarCompositesBase<T,SolidPhase>::effective_density_type;
            using ScalarCompositesBase<T,SolidPhase>::bulkmodulus_type_vector;
            using ScalarCompositesBase<T,SolidPhase>::shearmodulus_type_vector;
            using ScalarCompositesBase<T,SolidPhase>::density_type_vector;
            using ScalarCompositesBase<T,SolidPhase>::volumefraction_type_vector;

        private:
            SolidPhase() {}  // no defualt constructor

        public:
            SolidPhase(const std::vector< std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T>, mpc::rockphysics::VolumeFractionType<T> > >& vec) : ScalarCompositesBase<T,SolidPhase>(vec) {}

            // used in base class to calculate the effective values which are set in the base class member functions
            static std::tuple<mpc::rockphysics::BulkModulusType<T>, mpc::rockphysics::ShearModulusType<T>, mpc::rockphysics::DensityType<T> > EffectiveValues(const std::vector< mpc::rockphysics::BulkModulusType<T> >& K_vec, const std::vector< mpc::rockphysics::ShearModulusType<T> >& mu_vec, const std::vector< mpc::rockphysics::DensityType<T> >& rho_vec, const std::vector< mpc::rockphysics::VolumeFractionType<T> >& vf_vec) {
                /*
                 * Precondition: all std::vectors are same size
                 */
                //std::cout << "SolidPhase::EffectiveValues() called." << std::endl;

                // initialize output variables
                mpc::rockphysics::BulkModulusType<T> K_type = mpc::rockphysics::BulkModulusType<T>(1.0);
                mpc::rockphysics::ShearModulusType<T> mu_type = mpc::rockphysics::ShearModulusType<T>(1.0);
                mpc::rockphysics::DensityType<T> rho_type = mpc::rockphysics::DensityType<T>(1.0);

                mpc::utilities::WeightedArithmeticAverage<T,0> arithmetic_average_fo; // mass balance, Voigt bounds
                mpc::utilities::WeightedHarmonicAverage<T,0> harmonic_average_fo; // Ruess bounds

                // the above function objects require std::vector<T>, so ...
                int number_of_components = int(vf_vec.size());
                std::vector<T> K_vec_values(number_of_components);
                std::vector<T> mu_vec_values(number_of_components);
                std::vector<T> rho_vec_values(number_of_components);
                std::vector<T> vf_vec_values(number_of_components);
                for (int i=0; i<number_of_components; ++i) {
                    K_vec_values[i] = K_vec[i].value;
                    mu_vec_values[i] = mu_vec[i].value;
                    rho_vec_values[i] = rho_vec[i].value;
                    vf_vec_values[i] = vf_vec[i].value;
                }

                T K_voigt = arithmetic_average_fo(K_vec_values, vf_vec_values);
                T K_ruess = harmonic_average_fo(K_vec_values, vf_vec_values);
                K_type.value = 0.5 * (K_voigt + K_ruess);  // VRH

                T mu_voigt = arithmetic_average_fo(mu_vec_values, vf_vec_values);
                T mu_ruess = harmonic_average_fo(mu_vec_values, vf_vec_values);
                mu_type.value = 0.5 * (mu_voigt + mu_ruess);  // VRH

                rho_type.value = arithmetic_average_fo(rho_vec_values, vf_vec_values);  // mass balance

                return std::make_tuple(K_type, mu_type, rho_type);
            }

            std::pair< mpc::rockphysics::BulkModulusType<T>,mpc::rockphysics::ShearModulusType<T> > VoigtUpperBound() {
                //
                // initialize output variables
                mpc::rockphysics::BulkModulusType<T> K_type = mpc::rockphysics::BulkModulusType<T>(1.0);
                mpc::rockphysics::ShearModulusType<T> mu_type = mpc::rockphysics::ShearModulusType<T>(1.0);
                //mpc::rockphysics::DensityType<T> rho_type = mpc::rockphysics::DensityType<T>(1.0);

                mpc::utilities::WeightedArithmeticAverage<T,0> arithmetic_average_fo;

                // the above function objects require std::vector<T>, so ...
                int number_of_components = int(volumefraction_type_vector.size());
                std::vector<T> K_vec_values(number_of_components);
                std::vector<T> mu_vec_values(number_of_components);
                //std::vector<T> rho_vec_values(number_of_components);
                std::vector<T> vf_vec_values(number_of_components);
                for (int i=0; i<number_of_components; ++i) {
                    K_vec_values[i] = bulkmodulus_type_vector[i].value;
                    mu_vec_values[i] = shearmodulus_type_vector[i].value;
                    //rho_vec_values[i] = density_type_vector[i].value;
                    vf_vec_values[i] = volumefraction_type_vector[i].value;
                }

                T K_voigt = arithmetic_average_fo(K_vec_values, vf_vec_values);
                K_type.value = K_voigt;

                T mu_voigt = arithmetic_average_fo(mu_vec_values, vf_vec_values);
                mu_type.value = mu_voigt;

                return std::make_tuple(K_type, mu_type);
            }

            std::pair< mpc::rockphysics::BulkModulusType<T>,mpc::rockphysics::ShearModulusType<T> > RuessLowerBound() {
                //
                // initialize output variables
                mpc::rockphysics::BulkModulusType<T> K_type = mpc::rockphysics::BulkModulusType<T>(1.0);
                mpc::rockphysics::ShearModulusType<T> mu_type = mpc::rockphysics::ShearModulusType<T>(1.0);
                //mpc::rockphysics::DensityType<T> rho_type = mpc::rockphysics::DensityType<T>(1.0);

                mpc::utilities::WeightedHarmonicAverage<T,0> harmonic_average_fo; // Ruess bounds

                // the above function objects require std::vector<T>, so ...
                int number_of_components = int(volumefraction_type_vector.size());
                std::vector<T> K_vec_values(number_of_components);
                std::vector<T> mu_vec_values(number_of_components);
                //std::vector<T> rho_vec_values(number_of_components);
                std::vector<T> vf_vec_values(number_of_components);
                for (int i=0; i<number_of_components; ++i) {
                    K_vec_values[i] = bulkmodulus_type_vector[i].value;
                    mu_vec_values[i] = shearmodulus_type_vector[i].value;
                    //rho_vec_values[i] = density_type_vector[i].value;
                    vf_vec_values[i] = volumefraction_type_vector[i].value;
                }

                T K_voigt = harmonic_average_fo(K_vec_values, vf_vec_values);
                K_type.value = K_voigt;

                T mu_voigt = harmonic_average_fo(mu_vec_values, vf_vec_values);
                mu_type.value = mu_voigt;

                return std::make_tuple(K_type, mu_type);
            }



        };






    }  // namespace rockphysics
}  // namespace mpc

#endif // MPC_SCALARCOMPOSITES_H

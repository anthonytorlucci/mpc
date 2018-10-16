/**
 *    \file transformerhelperpermutations.hpp
 *    \brief helper functions that generate the permutations of the indices
 * used by the transformer function object
 *
 *    \author Anthony Torlucci
 *    \date 2018/10/14
 */

#ifndef MPC_TRANSFORMER_HELPER_PERMUTATIONS_H
#define MPC_TRANSFORMER_HELPER_PERMUTATIONS_H

// c++
#include <vector>

// blitz
#include <blitz/array.h>
#include <blitz/tinyvec2.h>

// mpc

// TODO: The transformation of a tensor is a linear weighted average;  This file generates the
// TODO: permutations for each rotation tensor.

namespace mpc {
    namespace transformation {

        // rank 1 polymorphic function
        static void permutations_for_linear_transformations(std::vector<int>& iper)
        {
            //int rank = 1;
            //double reciprocal_of_rank = 1.0 / rank;  // not really needed, but makes the code cleaner and easier to understand
            //int order = int(std::pow(iper.size(), reciprocal_of_rank));  // again, overly verbose
            //static_assert(int(iper.size()) == int(std::pow(order, rank)), "iper must have have pow(order,rank) number of elements");

            int counter = 0; // maximum value for counter is pow(order,rank)
            for (int i=0; i<3; ++i) {
                iper[counter] = i;
                ++counter;
            }
        }

        // rank 2 polymorphic function
        static void permutations_for_linear_transformations(std::vector<int>& iper, std::vector<int>& jper)
        {
            //int rank = 2;
            //double reciprocal_of_rank = 1.0 / rank;  // not really needed, but makes the code cleaner and easier to understand
            //int order = int(std::pow(iper.size(), reciprocal_of_rank));
            //static_assert(iper.size() == int(std::pow(order, rank)), "iper must have have pow(order,rank) number of elements");
            //static_assert(jper.size() == int(std::pow(order, rank)), "jper must have have pow(order,rank) number of elements");

            int counter = 0; // maximum value for counter is pow(order,rank); same as length of referenced arrays
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    iper[counter] = i;
                    jper[counter] = j;
                    ++counter;
                }
            }
        }

        // rank 3 polymorphic function
        static void permutations_for_linear_transformations(std::vector<int>& iper, std::vector<int>& jper, std::vector<int>& kper)
        {
            //int rank = 3;
            //double reciprocal_of_rank = 1.0 / rank;  // not really needed, but makes the code cleaner and easier to understand
            //int order = int(std::pow(iper.size(), reciprocal_of_rank));
            //static_assert(iper.size() == int(std::pow(order, rank)), "iper must have have pow(order,rank) number of elements");
            //static_assert(jper.size() == int(std::pow(order, rank)), "jper must have have pow(order,rank) number of elements");

            int counter = 0; // maximum value for counter is pow(order,rank); same as length of referenced arrays
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        iper[counter] = i;
                        jper[counter] = j;
                        kper[counter] = k;
                        ++counter;
                    }
                }
            }
        }

        // rank 4 polymorphic function
        static void permutations_for_linear_transformations(std::vector<int>& iper, std::vector<int>& jper, std::vector<int>& kper, std::vector<int>& lper)
        {
            //int rank = 4;
            //double reciprocal_of_rank = 1.0 / rank;  // not really needed, but makes the code cleaner and easier to understand
            //int order = int(std::pow(iper.size(), reciprocal_of_rank));
            //static_assert(iper.size() == int(std::pow(order, rank)), "iper must have have pow(order,rank) number of elements");
            //static_assert(jper.size() == int(std::pow(order, rank)), "jper must have have pow(order,rank) number of elements");

            int counter = 0; // maximum value for counter is pow(order,rank); same as length of referenced arrays
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        for (int l=0; l<3; ++l) {
                            iper[counter] = i;
                            jper[counter] = j;
                            kper[counter] = k;
                            lper[counter] = l;
                            ++counter;
                        }
                    }
                }
            }
        }

        // rank 5 polymorphic function
        static void permutations_for_linear_transformations(std::vector<int>& iper, std::vector<int>& jper, std::vector<int>& kper, std::vector<int>& lper, std::vector<int>& mper)
        {
            //int rank = 5;
            //double reciprocal_of_rank = 1.0 / rank;  // not really needed, but makes the code cleaner and easier to understand
            //int order = int(std::pow(iper.size(), reciprocal_of_rank));
            //static_assert(iper.size() == int(std::pow(order, rank)), "iper must have have pow(order,rank) number of elements");
            //static_assert(jper.size() == int(std::pow(order, rank)), "jper must have have pow(order,rank) number of elements");

            int counter = 0; // maximum value for counter is pow(order,rank); same as length of referenced arrays
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        for (int l=0; l<3; ++l) {
                            for (int m=0; m<3; ++m) {
                                iper[counter] = i;
                                jper[counter] = j;
                                kper[counter] = k;
                                lper[counter] = l;
                                mper[counter] = m;
                                ++counter;
                            }
                        }
                    }
                }
            }
        }

        // rank 6 polymorphic function
        static void permutations_for_linear_transformations(std::vector<int>& iper, std::vector<int>& jper, std::vector<int>& kper, std::vector<int>& lper, std::vector<int>& mper, std::vector<int>& nper)
        {
            //int rank = 6;
            //double reciprocal_of_rank = 1.0 / rank;  // not really needed, but makes the code cleaner and easier to understand
            //int order = int(std::pow(iper.size(), reciprocal_of_rank));
            //static_assert(iper.size() == int(std::pow(order, rank)), "iper must have have pow(order,rank) number of elements");
            //static_assert(jper.size() == int(std::pow(order, rank)), "jper must have have pow(order,rank) number of elements");

            int counter = 0; // maximum value for counter is pow(order,rank); same as length of referenced arrays
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        for (int l=0; l<3; ++l) {
                            for (int m=0; m<3; ++m) {
                                for (int n=0; n<3; ++n) {
                                    iper[counter] = i;
                                    jper[counter] = j;
                                    kper[counter] = k;
                                    lper[counter] = l;
                                    mper[counter] = m;
                                    nper[counter] = n;
                                    ++counter;
                                }
                            }
                        }
                    }
                }
            }
        }

        // rank 7 polymorphic function
        static void permutations_for_linear_transformations(std::vector<int>& iper, std::vector<int>& jper, std::vector<int>& kper, std::vector<int>& lper, std::vector<int>& mper, std::vector<int>& nper, std::vector<int>& pper)
        {
            //int rank = 7;
            //double reciprocal_of_rank = 1.0 / rank;  // not really needed, but makes the code cleaner and easier to understand
            //int order = int(std::pow(iper.size(), reciprocal_of_rank));
            //static_assert(iper.size() == int(std::pow(order, rank)), "iper must have have pow(order,rank) number of elements");
            //static_assert(jper.size() == int(std::pow(order, rank)), "jper must have have pow(order,rank) number of elements");

            int counter = 0; // maximum value for counter is pow(order,rank); same as length of referenced arrays
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        for (int l=0; l<3; ++l) {
                            for (int m=0; m<3; ++m) {
                                for (int n=0; n<3; ++n) {
                                    for (int p=0; p<3; ++p) {
                                        iper[counter] = i;
                                        jper[counter] = j;
                                        kper[counter] = k;
                                        lper[counter] = l;
                                        mper[counter] = m;
                                        nper[counter] = n;
                                        pper[counter] = p;
                                        ++counter;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // rank 8 polymorphic function
        static void permutations_for_linear_transformations(std::vector<int>& iper, std::vector<int>& jper, std::vector<int>& kper, std::vector<int>& lper, std::vector<int>& mper, std::vector<int>& nper, std::vector<int>& pper, std::vector<int>& qper)
        {
            //int rank = 8;
            //double reciprocal_of_rank = 1.0 / rank;  // not really needed, but makes the code cleaner and easier to understand
            //int order = int(std::pow(iper.size(), reciprocal_of_rank));
            //static_assert(iper.size() == int(std::pow(order, rank)), "iper must have have pow(order,rank) number of elements");
            //static_assert(jper.size() == int(std::pow(order, rank)), "jper must have have pow(order,rank) number of elements");

            int counter = 0; // maximum value for counter is pow(order,rank); same as length of referenced arrays
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        for (int l=0; l<3; ++l) {
                            for (int m=0; m<3; ++m) {
                                for (int n=0; n<3; ++n) {
                                    for (int p=0; p<3; ++p) {
                                        for (int q=0; q<3; ++q) {
                                            iper[counter] = i;
                                            jper[counter] = j;
                                            kper[counter] = k;
                                            lper[counter] = l;
                                            mper[counter] = m;
                                            nper[counter] = n;
                                            pper[counter] = p;
                                            qper[counter] = q;
                                            ++counter;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // rank 9 polymorphic function
        static void permutations_for_linear_transformations(std::vector<int>& iper, std::vector<int>& jper, std::vector<int>& kper, std::vector<int>& lper, std::vector<int>& mper, std::vector<int>& nper, std::vector<int>& pper, std::vector<int>& qper, std::vector<int>& rper)
        {
            //int rank = 9;
            //double reciprocal_of_rank = 1.0 / rank;  // not really needed, but makes the code cleaner and easier to understand
            //int order = int(std::pow(iper.size(), reciprocal_of_rank));
            //static_assert(iper.size() == int(std::pow(order, rank)), "iper must have have pow(order,rank) number of elements");
            //static_assert(jper.size() == int(std::pow(order, rank)), "jper must have have pow(order,rank) number of elements");

            int counter = 0; // maximum value for counter is pow(order,rank); same as length of referenced arrays
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        for (int l=0; l<3; ++l) {
                            for (int m=0; m<3; ++m) {
                                for (int n=0; n<3; ++n) {
                                    for (int p=0; p<3; ++p) {
                                        for (int q=0; q<3; ++q) {
                                            for (int r=0; r<3; ++r) {
                                                iper[counter] = i;
                                                jper[counter] = j;
                                                kper[counter] = k;
                                                lper[counter] = l;
                                                mper[counter] = m;
                                                nper[counter] = n;
                                                pper[counter] = p;
                                                qper[counter] = q;
                                                rper[counter] = r;
                                                ++counter;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // rank 10 polymorphic function
        static void permutations_for_linear_transformations(std::vector<int>& iper, std::vector<int>& jper, std::vector<int>& kper, std::vector<int>& lper, std::vector<int>& mper, std::vector<int>& nper, std::vector<int>& pper, std::vector<int>& qper, std::vector<int>& rper, std::vector<int>& sper)
        {
            //int rank = 10;
            //double reciprocal_of_rank = 1.0 / rank;  // not really needed, but makes the code cleaner and easier to understand
            //int order = int(std::pow(iper.size(), reciprocal_of_rank));
            //static_assert(iper.size() == int(std::pow(order, rank)), "iper must have have pow(order,rank) number of elements");
            //static_assert(jper.size() == int(std::pow(order, rank)), "jper must have have pow(order,rank) number of elements");

            int counter = 0; // maximum value for counter is pow(order,rank); same as length of referenced arrays
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        for (int l=0; l<3; ++l) {
                            for (int m=0; m<3; ++m) {
                                for (int n=0; n<3; ++n) {
                                    for (int p=0; p<3; ++p) {
                                        for (int q=0; q<3; ++q) {
                                            for (int r=0; r<3; ++r) {
                                                for (int s=0; s<3; ++s) {
                                                    iper[counter] = i;
                                                    jper[counter] = j;
                                                    kper[counter] = k;
                                                    lper[counter] = l;
                                                    mper[counter] = m;
                                                    nper[counter] = n;
                                                    pper[counter] = p;
                                                    qper[counter] = q;
                                                    rper[counter] = r;
                                                    sper[counter] = s;
                                                    ++counter;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // rank 11 polymorphic function
        static void permutations_for_linear_transformations(std::vector<int>& iper, std::vector<int>& jper, std::vector<int>& kper, std::vector<int>& lper, std::vector<int>& mper, std::vector<int>& nper, std::vector<int>& pper, std::vector<int>& qper, std::vector<int>& rper, std::vector<int>& sper, std::vector<int>& tper)
        {
            //int rank = 11;
            //double reciprocal_of_rank = 1.0 / rank;  // not really needed, but makes the code cleaner and easier to understand
            //int order = int(std::pow(iper.size(), reciprocal_of_rank));
            //static_assert(iper.size() == int(std::pow(order, rank)), "iper must have have pow(order,rank) number of elements");
            //static_assert(jper.size() == int(std::pow(order, rank)), "jper must have have pow(order,rank) number of elements");

            int counter = 0; // maximum value for counter is pow(order,rank); same as length of referenced arrays
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        for (int l=0; l<3; ++l) {
                            for (int m=0; m<3; ++m) {
                                for (int n=0; n<3; ++n) {
                                    for (int p=0; p<3; ++p) {
                                        for (int q=0; q<3; ++q) {
                                            for (int r=0; r<3; ++r) {
                                                for (int s=0; s<3; ++s) {
                                                    for (int t=0; t<3; ++t) {
                                                        iper[counter] = i;
                                                        jper[counter] = j;
                                                        kper[counter] = k;
                                                        lper[counter] = l;
                                                        mper[counter] = m;
                                                        nper[counter] = n;
                                                        pper[counter] = p;
                                                        qper[counter] = q;
                                                        rper[counter] = r;
                                                        sper[counter] = s;
                                                        tper[counter] = t;
                                                        ++counter;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    }  // END namespace transformation
}  // END namespace mpc

#endif // MPC_TRANSFORMER_HELPER_PERMUTATIONS_H

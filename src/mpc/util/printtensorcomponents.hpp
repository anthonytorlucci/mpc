/**
*    @file printtensorcomponents.hpp
*    @brief function object used to print the tensor components from a
* blitz array
*
*    @author Anthony Torlucci
*    @date 9/16/2018
*/

#ifndef MPC_PRINT_TENSOR_COMPONENTS_H
#define MPC_PRINT_TENSOR_COMPONENTS_H

// c++ standard
#include <iostream>
#include <string>

// blitz
#include "blitz/array.h"

namespace mpc {
namespace util {

template <typename T, int Rank>
struct PrintTensorComponents {
    // print the individual components of a tensor
    void operator()(blitz::Array<T,Rank>& tensor) {}
};

// partial specialization Rank 1
template <typename T>
struct PrintTensorComponents<T,1>
{
    void operator()(blitz::Array<T,1>& tensor)
    {
        for (int i=0; i<3; ++i) {
            T val = tensor(i);
            std::string str = "component(";
            str.append(std::to_string(i));
            str.append(") : ");
            std::cout << str << val << std::endl;
        }
        std::cout << "" << std::endl;
    }
};

// partial specialization Rank 2
template <typename T>
struct PrintTensorComponents<T,2>
{
    void operator()(blitz::Array<T,2>& tensor)
    {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                T val = tensor(i,j);
                std::string str = "component(";
                str.append(std::to_string(i));
                str.append(",");
                str.append(std::to_string(j));
                str.append(") : ");
                std::cout << str << val << std::endl;
            }
        }
        std::cout << "" << std::endl;
    }
};

// partial specialization Rank 3
template <typename T>
struct PrintTensorComponents<T,3>
{
    void operator()(blitz::Array<T,3>& tensor)
    {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    T val = tensor(i,j,k);
                    std::string str = "component(";
                    str.append(std::to_string(i));
                    str.append(",");
                    str.append(std::to_string(j));
                    str.append(",");
                    str.append(std::to_string(k));
                    str.append(") : ");
                    std::cout << str << val << std::endl;
                }
            }
        }
        std::cout << "" << std::endl;
    }
};

// partial specialization Rank 4
template <typename T>
struct PrintTensorComponents<T,4>
{
    void operator()(blitz::Array<T,4>& tensor)
    {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l){
                        T val = tensor(i,j,k,l);
                        std::string str = "component(";
                        str.append(std::to_string(i));
                        str.append(",");
                        str.append(std::to_string(j));
                        str.append(",");
                        str.append(std::to_string(k));
                        str.append(",");
                        str.append(std::to_string(l));
                        str.append(") : ");
                        std::cout << str << val << std::endl;
                    }
                }
            }
        }
        std::cout << "" << std::endl;
    }
};

// partial specialization Rank 5
template <typename T>
struct PrintTensorComponents<T,5>
{
    void operator()(blitz::Array<T,5>& tensor)
    {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l){
                        for (int m=0; m<3; ++m) {
                            T val = tensor(i,j,k,l,m);
                            std::string str = "component(";
                            str.append(std::to_string(i));
                            str.append(",");
                            str.append(std::to_string(j));
                            str.append(",");
                            str.append(std::to_string(k));
                            str.append(",");
                            str.append(std::to_string(l));
                            str.append(",");
                            str.append(std::to_string(m));
                            str.append(") : ");

                            std::cout << str << val << std::endl;
                        }
                    }
                }
            }
        }
        std::cout << "" << std::endl;
    }
};

// partial specialization Rank 6
template <typename T>
struct PrintTensorComponents<T,6>
{
    void operator()(blitz::Array<T,6>& tensor)
    {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l){
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                T val = tensor(i,j,k,l,m,n);
                                std::string str = "component(";
                                str.append(std::to_string(i));
                                str.append(",");
                                str.append(std::to_string(j));
                                str.append(",");
                                str.append(std::to_string(k));
                                str.append(",");
                                str.append(std::to_string(l));
                                str.append(",");
                                str.append(std::to_string(m));
                                str.append(",");
                                str.append(std::to_string(n));
                                str.append(") : ");

                                std::cout << str << val << std::endl;
                            }
                        }
                    }
                }
            }
        }
        std::cout << "" << std::endl;
    }
};

// partial specialization Rank 7
template <typename T>
struct PrintTensorComponents<T,7>
{
    void operator()(blitz::Array<T,7>& tensor)
    {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l){
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                for (int p=0; p<3; ++p) {
                                    T val = tensor(i,j,k,l,m,n,p);
                                    std::string str = "component(";
                                    str.append(std::to_string(i));
                                    str.append(",");
                                    str.append(std::to_string(j));
                                    str.append(",");
                                    str.append(std::to_string(k));
                                    str.append(",");
                                    str.append(std::to_string(l));
                                    str.append(",");
                                    str.append(std::to_string(m));
                                    str.append(",");
                                    str.append(std::to_string(n));
                                    str.append(",");
                                    str.append(std::to_string(p));
                                    str.append(") : ");

                                    std::cout << str << val << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        std::cout << "" << std::endl;
    }
};

// partial specialization Rank 8
template <typename T>
struct PrintTensorComponents<T,8>
{
    void operator()(blitz::Array<T,8>& tensor)
    {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l){
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                for (int p=0; p<3; ++p) {
                                    for (int q=0; q<3; ++q) {
                                        T val = tensor(i,j,k,l,m,n,p,q);
                                        std::string str = "component(";
                                        str.append(std::to_string(i));
                                        str.append(",");
                                        str.append(std::to_string(j));
                                        str.append(",");
                                        str.append(std::to_string(k));
                                        str.append(",");
                                        str.append(std::to_string(l));
                                        str.append(",");
                                        str.append(std::to_string(m));
                                        str.append(",");
                                        str.append(std::to_string(n));
                                        str.append(",");
                                        str.append(std::to_string(p));
                                        str.append(",");
                                        str.append(std::to_string(q));
                                        str.append(") : ");

                                        std::cout << str << val << std::endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        std::cout << "" << std::endl;
    }
};

// partial specialization Rank 9
template <typename T>
struct PrintTensorComponents<T,9>
{
    void operator()(blitz::Array<T,9>& tensor)
    {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l){
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                for (int p=0; p<3; ++p) {
                                    for (int q=0; q<3; ++q) {
                                        for (int r=0; r<3; ++r) {
                                            T val = tensor(i,j,k,l,m,n,p,q,r);
                                            std::string str = "component(";
                                            str.append(std::to_string(i));
                                            str.append(",");
                                            str.append(std::to_string(j));
                                            str.append(",");
                                            str.append(std::to_string(k));
                                            str.append(",");
                                            str.append(std::to_string(l));
                                            str.append(",");
                                            str.append(std::to_string(m));
                                            str.append(",");
                                            str.append(std::to_string(n));
                                            str.append(",");
                                            str.append(std::to_string(p));
                                            str.append(",");
                                            str.append(std::to_string(q));
                                            str.append(",");
                                            str.append(std::to_string(r));
                                            str.append(") : ");

                                            std::cout << str << val << std::endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        std::cout << "" << std::endl;
    }
};

// partial specialization Rank 10
template <typename T>
struct PrintTensorComponents<T,10>
{
    void operator()(blitz::Array<T,10>& tensor)
    {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l){
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                for (int p=0; p<3; ++p) {
                                    for (int q=0; q<3; ++q) {
                                        for (int r=0; r<3; ++r) {
                                            for (int s=0; s<3; ++s) {
                                                T val = tensor(i,j,k,l,m,n,p,q,r,s);
                                                std::string str = "component(";
                                                str.append(std::to_string(i));
                                                str.append(",");
                                                str.append(std::to_string(j));
                                                str.append(",");
                                                str.append(std::to_string(k));
                                                str.append(",");
                                                str.append(std::to_string(l));
                                                str.append(",");
                                                str.append(std::to_string(m));
                                                str.append(",");
                                                str.append(std::to_string(n));
                                                str.append(",");
                                                str.append(std::to_string(p));
                                                str.append(",");
                                                str.append(std::to_string(q));
                                                str.append(",");
                                                str.append(std::to_string(r));
                                                str.append(",");
                                                str.append(std::to_string(s));
                                                str.append(") : ");

                                                std::cout << str << val << std::endl;
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
        std::cout << "" << std::endl;
    }
};

// partial specialization Rank 11
template <typename T>
struct PrintTensorComponents<T,11>
{
    void operator()(blitz::Array<T,11>& tensor)
    {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    for (int l=0; l<3; ++l){
                        for (int m=0; m<3; ++m) {
                            for (int n=0; n<3; ++n) {
                                for (int p=0; p<3; ++p) {
                                    for (int q=0; q<3; ++q) {
                                        for (int r=0; r<3; ++r) {
                                            for (int s=0; s<3; ++s) {
                                                for (int t=0; t<3; ++t) {
                                                    T val = tensor(i,j,k,l,m,n,p,q,r,s,t);
                                                    std::string str = "component(";
                                                    str.append(std::to_string(i));
                                                    str.append(",");
                                                    str.append(std::to_string(j));
                                                    str.append(",");
                                                    str.append(std::to_string(k));
                                                    str.append(",");
                                                    str.append(std::to_string(l));
                                                    str.append(",");
                                                    str.append(std::to_string(m));
                                                    str.append(",");
                                                    str.append(std::to_string(n));
                                                    str.append(",");
                                                    str.append(std::to_string(p));
                                                    str.append(",");
                                                    str.append(std::to_string(q));
                                                    str.append(",");
                                                    str.append(std::to_string(r));
                                                    str.append(",");
                                                    str.append(std::to_string(s));
                                                    str.append(",");
                                                    str.append(std::to_string(t));
                                                    str.append(") : ");

                                                    std::cout << str << val << std::endl;
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
        std::cout << "" << std::endl;
    }
};

}  // end namespace util
}  // end namespace mpc

#endif //MPC_PRINT_TENSOR_COMPONENTS_H

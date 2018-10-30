# mpcexamples
mechanical properties of crystals and polycrystalline aggregates

---
### utilities
The utilities namespace is reserved mainly for functions and function objects that independent of the data structures in mpc.  These functions are *helper* functions used throughout the mpc library.

#### constants
template object for the number pi.
[mpcexamples::mpcConstants()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_constants.cpp)
```
const double PI = mpc::utilities::PI<double>;
const double TWO_PI = 2.0 * PI;
const double PI_OVER_TWO = 0.5 * PI;

std::cout << "PI /2  : " << PI_OVER_TWO << std::endl;
std::cout << "PI     : " << PI << std::endl;
std::cout << "TWO PI : " << TWO_PI << std::endl;
```
    PI /2  : 1.5708
    PI     : 3.14159
    TWO PI : 6.28319

#### print tensor components
function object for printing out component indices and values of multidimensional blitz arrays when each index has the same range, e.g. 0,1,2 like that of tensors.
[mpcexamples::mpcPrintTensorComponents()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_printtensorcomponents.cpp)
```c++
std::cout << "tensor Rank 1 Order 3\n" << std::endl;
mpc::utilities::PrintTensorComponents<double,1> PrintTensorComponents1;
// blitz::Array<double,1> tensorR1D3
auto tensorR1D3 = mpcexamples::GetRank01ExampleTensor<double>(3);
PrintTensorComponents1(tensorR1D3);
```
    tensor Rank 1 Order 3

    component(0) : 1
    component(1) : 2
    component(2) : 3
```c++
std::cout << "tensor Rank 2 Order 3\n" << std::endl;
mpc::utilities::PrintTensorComponents<double,2> PrintTensorComponents2;
// blitz::Array<double,2> tensorR2D3
auto tensorR2D3 = mpcexamples::GetRank02ExampleTensor<double>(3);
PrintTensorComponents2(tensorR2D3);
```
    tensor Rank 2 Order 3

    component(0,0) : 1.1
    component(0,1) : 1.2
    component(0,2) : 1.3
    component(1,0) : 2.1
    component(1,1) : 2.2
    component(1,2) : 2.3
    component(2,0) : 3.1
    component(2,1) : 3.2
    component(2,2) : 3.3
```c++
std::cout << "tensor Rank 3 Order 3\n" << std::endl;
mpc::utilities::PrintTensorComponents<double,3> PrintTensorComponents3;
// blitz::Array<double,3> tensorR3D3
auto tensorR3D3 = mpcexamples::GetRank03ExampleTensor<double>(3);
PrintTensorComponents3(tensorR3D3);
```
    tensor Rank 3 Order 3

    component(0,0,0) : 1.11
    component(0,0,1) : 1.12
    component(0,0,2) : 1.13
    component(0,1,0) : 1.21
    component(0,1,1) : 1.22
    component(0,1,2) : 1.23
    component(0,2,0) : 1.31
    component(0,2,1) : 1.32
    component(0,2,2) : 1.33
    component(1,0,0) : 2.11
    component(1,0,1) : 2.12
    component(1,0,2) : 2.13
    component(1,1,0) : 2.21
    component(1,1,1) : 2.22
    component(1,1,2) : 2.23
    component(1,2,0) : 2.31
    component(1,2,1) : 2.32
    component(1,2,2) : 2.33
    component(2,0,0) : 3.11
    component(2,0,1) : 3.12
    component(2,0,2) : 3.13
    component(2,1,0) : 3.21
    component(2,1,1) : 3.22
    component(2,1,2) : 3.23
    component(2,2,0) : 3.31
    component(2,2,1) : 3.32
    component(2,2,2) : 3.33
```c++
std::cout << "tensor Rank 4 Order 3\n" << std::endl;
mpc::utilities::PrintTensorComponents<double,4> PrintTensorComponents4;
// blitz::Array<double,4> tensorR4D3
auto tensorR4D3 = mpcexamples::GetRank04ExampleTensor<double>(3);
PrintTensorComponents4(tensorR4D3);
```
    tensor Rank 4 Order 3

    component(0,0,0,0) : 1.111
    component(0,0,0,1) : 1.112
    component(0,0,0,2) : 1.113
    component(0,0,1,0) : 1.121
    component(0,0,1,1) : 1.122
    component(0,0,1,2) : 1.123
    component(0,0,2,0) : 1.131
    component(0,0,2,1) : 1.132
    component(0,0,2,2) : 1.133
    component(0,1,0,0) : 1.211
    component(0,1,0,1) : 1.212
    component(0,1,0,2) : 1.213
    component(0,1,1,0) : 1.221
    component(0,1,1,1) : 1.222
    component(0,1,1,2) : 1.223
    component(0,1,2,0) : 1.231
    component(0,1,2,1) : 1.232
    component(0,1,2,2) : 1.233
    component(0,2,0,0) : 1.311
    component(0,2,0,1) : 1.312
    component(0,2,0,2) : 1.313
    component(0,2,1,0) : 1.321
    component(0,2,1,1) : 1.322
    component(0,2,1,2) : 1.323
    component(0,2,2,0) : 1.331
    component(0,2,2,1) : 1.332
    component(0,2,2,2) : 1.333
    component(1,0,0,0) : 2.111
    component(1,0,0,1) : 2.112
    component(1,0,0,2) : 2.113
    component(1,0,1,0) : 2.121
    component(1,0,1,1) : 2.122
    component(1,0,1,2) : 2.123
    component(1,0,2,0) : 2.131
    component(1,0,2,1) : 2.132
    component(1,0,2,2) : 2.133
    component(1,1,0,0) : 2.211
    component(1,1,0,1) : 2.212
    component(1,1,0,2) : 2.213
    component(1,1,1,0) : 2.221
    component(1,1,1,1) : 2.222
    component(1,1,1,2) : 2.223
    component(1,1,2,0) : 2.231
    component(1,1,2,1) : 2.232
    component(1,1,2,2) : 2.233
    component(1,2,0,0) : 2.311
    component(1,2,0,1) : 2.312
    component(1,2,0,2) : 2.313
    component(1,2,1,0) : 2.321
    component(1,2,1,1) : 2.322
    component(1,2,1,2) : 2.323
    component(1,2,2,0) : 2.331
    component(1,2,2,1) : 2.332
    component(1,2,2,2) : 2.333
    component(2,0,0,0) : 3.111
    component(2,0,0,1) : 3.112
    component(2,0,0,2) : 3.113
    component(2,0,1,0) : 3.121
    component(2,0,1,1) : 3.122
    component(2,0,1,2) : 3.123
    component(2,0,2,0) : 3.131
    component(2,0,2,1) : 3.132
    component(2,0,2,2) : 3.133
    component(2,1,0,0) : 3.211
    component(2,1,0,1) : 3.212
    component(2,1,0,2) : 3.213
    component(2,1,1,0) : 3.221
    component(2,1,1,1) : 3.222
    component(2,1,1,2) : 3.223
    component(2,1,2,0) : 3.231
    component(2,1,2,1) : 3.232
    component(2,1,2,2) : 3.233
    component(2,2,0,0) : 3.311
    component(2,2,0,1) : 3.312
    component(2,2,0,2) : 3.313
    component(2,2,1,0) : 3.321
    component(2,2,1,1) : 3.322
    component(2,2,1,2) : 3.323
    component(2,2,2,0) : 3.331
    component(2,2,2,1) : 3.332
    component(2,2,2,2) : 3.333


#### accumulator and innerproductor
The accumulator function object *accumulates* multidimensional arrays by either summing or multiplying sub-arrays of dimension N-1 for an N-dimensional array.  The operation acts on the nth axis of the array and always returns an array of dimension N-1.
[mpcexamples::mpcAccumulator()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_accumulator.cpp)

```cpp
blitz::Array<double,1> tensorR1D3 = mpcexamples::GetRank01ExampleTensor<double>(3);
std::cout << "extents: " << tensorR1D3.extent(0) << std::endl;
mpc::utilities::AccumulatorSum<double,1> accumulator_sum_R1D3_fo;  // function object
double asumR1D3 = accumulator_sum_R1D3_fo(tensorR1D3);
std::cout << "accumulator sum R1D3 " << std::endl;
std::cout << asumR1D3 << std::endl;
```
    extents: 3
    accumulator sum R1D3
    6

```cpp
blitz::Array<double,2> tensorR2D3 = mpcexamples::GetRank02ExampleTensor<double>(3);
std::cout << "extent 0: " << tensorR2D3.extent(0) << std::endl;
std::cout << "extent 1: " << tensorR2D3.extent(1) << std::endl;
mpc::utilities::AccumulatorSum<double,2> accumulator_sum_R2D3_fo;  // function object
blitz::Array<double,1> asumR2D3 = accumulator_sum_R2D3_fo(tensorR2D3);
std::cout << "accumulator sum R2D3 " << std::endl;
PrintTensorComponents1(asumR2D3);
```
    extent 0: 3
    extent 1: 3
    accumulator sum R2D3
    component(0) : 3.6
    component(1) : 6.6
    component(2) : 9.6

```cpp
blitz::Array<double,3> tensorR3D3 = mpcexamples::GetRank03ExampleTensor<double>(3);
std::cout << "extent 0: " << tensorR3D3.extent(0) << std::endl;
std::cout << "extent 1: " << tensorR3D3.extent(1) << std::endl;
std::cout << "extent 2: " << tensorR3D3.extent(2) << std::endl;
mpc::utilities::AccumulatorSum<double,3> accumulator_sum_R3D3_fo;
blitz::Array<double,2> asumR3D3 = accumulator_sum_R3D3_fo(tensorR3D3);
std::cout << "accumulator sum R3D3 " << std::endl;
PrintTensorComponents2(asumR3D3);
std::cout << "" << std::endl;
```
    extent 0: 3
    extent 1: 3
    extent 2: 3
    accumulator sum R3D3
    component(0,0) : 3.36
    component(0,1) : 3.66
    component(0,2) : 3.96
    component(1,0) : 6.36
    component(1,1) : 6.66
    component(1,2) : 6.96
    component(2,0) : 9.36
    component(2,1) : 9.66
    component(2,2) : 9.96



```cpp
blitz::Array<double,4> tensorR4D3 = mpcexamples::GetRank04ExampleTensor<double>(3);
std::cout << "extent 0: " << tensorR4D3.extent(0) << std::endl;
std::cout << "extent 1: " << tensorR4D3.extent(1) << std::endl;
std::cout << "extent 2: " << tensorR4D3.extent(2) << std::endl;
std::cout << "extent 2: " << tensorR4D3.extent(3) << std::endl;
mpc::utilities::AccumulatorSum<double,4> accumulator_sum_R4D3_fo;
blitz::Array<double,3> asumR4D3 = accumulator_sum_R4D3_fo(tensorR4D3);
std::cout << "accumulator sum R4D3: " << std::endl;
PrintTensorComponents3(asumR4D3);
std::cout << "" << std::endl;
```
    extent 0: 3
    extent 1: 3
    extent 2: 3
    extent 2: 3
    accumulator sum R4D3:
    component(0,0,0) : 3.336
    component(0,0,1) : 3.366
    component(0,0,2) : 3.396
    component(0,1,0) : 3.636
    component(0,1,1) : 3.666
    component(0,1,2) : 3.696
    component(0,2,0) : 3.936
    component(0,2,1) : 3.966
    component(0,2,2) : 3.996
    component(1,0,0) : 6.336
    component(1,0,1) : 6.366
    component(1,0,2) : 6.396
    component(1,1,0) : 6.636
    component(1,1,1) : 6.666
    component(1,1,2) : 6.696
    component(1,2,0) : 6.936
    component(1,2,1) : 6.966
    component(1,2,2) : 6.996
    component(2,0,0) : 9.336
    component(2,0,1) : 9.366
    component(2,0,2) : 9.396
    component(2,1,0) : 9.636
    component(2,1,1) : 9.666
    component(2,1,2) : 9.696
    component(2,2,0) : 9.936
    component(2,2,1) : 9.966
    component(2,2,2) : 9.996

```cpp
blitz::Array<double,1> tensorR1D3 = mpcexamples::GetRank01ExampleTensor<double>(3);
std::cout << "extents: " << tensorR1D3.extent(0) << std::endl;
mpc::utilities::AccumulatorProduct<double,1> accumulator_product_R1D3_fo;
double aprodR1D3 = accumulator_product_R1D3_fo(tensorR1D3);
std::cout << "accumulator product R1D3 " << std::endl;
std::cout << aprodR1D3 << std::endl;
std::cout << "" << std::endl;
```
    extents: 3
    accumulator product R1D3
    6

```cpp
blitz::Array<double,2> tensorR2D3 = mpcexamples::GetRank02ExampleTensor<double>(3);
std::cout << "extent 0: " << tensorR2D3.extent(0) << std::endl;
std::cout << "extent 1: " << tensorR2D3.extent(1) << std::endl;
mpc::utilities::AccumulatorProduct<double,2> accumulator_product_R2D3_fo;
blitz::Array<double,1> aprodR2D3 = accumulator_product_R2D3_fo(tensorR2D3);
std::cout << "accumulator product R2D3 " << std::endl;
PrintTensorComponents1(aprodR2D3);
std::cout << "" << std::endl;
```
    extent 0: 3
    extent 1: 3
    accumulator product R2D3
    component(0) : 1.716
    component(1) : 10.626
    component(2) : 32.736

```cpp
blitz::Array<double,3> tensorR3D3 = mpcexamples::GetRank03ExampleTensor<double>(3);
std::cout << "extent 0: " << tensorR3D3.extent(0) << std::endl;
std::cout << "extent 1: " << tensorR3D3.extent(1) << std::endl;
std::cout << "extent 2: " << tensorR3D3.extent(2) << std::endl;
mpc::utilities::AccumulatorProduct<double,3> accumulator_product_R3D3_fo;
blitz::Array<double,2> aprodR3D3 = accumulator_product_R3D3_fo(tensorR3D3);
std::cout << "accumulator product R3D3 " << std::endl;
PrintTensorComponents2(aprodR3D3);
std::cout << "" << std::endl;
```
    extent 0: 3
    extent 1: 3
    extent 2: 3
    accumulator product R3D3
    component(0,0) : 1.40482
    component(0,1) : 1.81573
    component(0,2) : 2.29984
    component(1,0) : 9.52792
    component(1,1) : 10.9408
    component(1,2) : 12.4869
    component(2,0) : 30.371
    component(2,1) : 33.3859
    component(2,2) : 36.594

```cpp
blitz::Array<double,4> tensorR4D3 = mpcexamples::GetRank04ExampleTensor<double>(3);
std::cout << "extent 0: " << tensorR4D3.extent(0) << std::endl;
std::cout << "extent 1: " << tensorR4D3.extent(1) << std::endl;
std::cout << "extent 2: " << tensorR4D3.extent(2) << std::endl;
std::cout << "extent 3: " << tensorR4D3.extent(3) << std::endl;
mpc::utilities::AccumulatorProduct<double,4> accumulator_product_R4D3_fo;
blitz::Array<double,3> aprodR4D3 = accumulator_product_R4D3_fo(tensorR4D3);
std::cout << "accumulator product R4D3 " << std::endl;
PrintTensorComponents3(aprodR4D3);
```
    extent 0: 3
    extent 1: 3
    extent 2: 3
    extent 3: 3
    accumulator product R4D3
    component(0,0,0) : 1.37504
    component(0,0,1) : 1.41247
    component(0,0,2) : 1.45057
    component(0,1,0) : 1.78036
    component(0,1,1) : 1.82479
    component(0,1,2) : 1.86996
    component(0,2,0) : 2.2584
    component(0,2,1) : 2.31044
    component(0,2,2) : 2.36327
    component(1,0,0) : 9.42067
    component(1,0,1) : 9.55512
    component(1,0,2) : 9.69084
    component(1,1,0) : 10.8232
    component(1,1,1) : 10.9706
    component(1,1,2) : 11.1194
    component(1,2,0) : 12.3584
    component(1,2,1) : 12.5195
    component(1,2,2) : 12.6819
    component(2,0,0) : 30.1383
    component(2,0,1) : 30.4298
    component(2,0,2) : 30.7231
    component(2,1,0) : 33.138
    component(2,1,1) : 33.4485
    component(2,1,2) : 33.7609
    component(2,2,0) : 36.3305
    component(2,2,1) : 36.6605
    component(2,2,2) : 36.9926

The innerproductor function object is similar to the accumulator function object except there are (only) two inputs and the operation is the sum of the product of the two arrays.  For a one-dimensional array of length 3, i.e. a vector in 3-dimensional space, the innerproductor function object is equivalent to the *dot product* or *inner product* of two vectors.  Hence the name.  However, this function object in mpc::utilities is more general and takes any N-dimensional array of arbitrary shape and returns the inner product as long as the two inputs have the same shape.
[mpcexamples::mpcInnerProductor()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_innerproductor.cpp)

```cpp
blitz::Array<double,1> tensorR1D3 = mpcexamples::GetRank01ExampleTensor<double>(3);
blitz::Array<double,1> tensorR1D3b(tensorR1D3.shape());
tensorR1D3b = tensorR1D3 * 10.0;
mpc::utilities::InnerProductor<double,1> inner_productor_R1D3_fo;  // function object
double ipR1D3 = inner_productor_R1D3_fo(tensorR1D3,tensorR1D3b);
std::cout << "innerProductorR1D3 " << std::endl;
std::cout << ipR1D3 << std::endl;
```
    innerProductorR1D3
    140

```cpp
blitz::Array<double,2> tensorR2D3 = mpcexamples::GetRank02ExampleTensor<double>(3);
blitz::Array<double,2> tensorR2D3b(tensorR2D3.shape());
tensorR2D3b = tensorR2D3 * 10.0;
mpc::utilities::InnerProductor<double,2> inner_productor_R2D3_fo;
blitz::Array<double,1> ipR2D3 = inner_productor_R2D3_fo(tensorR2D3,tensorR2D3b);
std::cout << "innerProductorR2D3 " << std::endl;
PrintTensorComponents1(ipR2D3);
```
    innerProductorR2D3
    component(0) : 43.4
    component(1) : 145.4
    component(2) : 307.4

```cpp
blitz::Array<double,3> tensorR3D3 = mpcexamples::GetRank03ExampleTensor<double>(3);
blitz::Array<double,3> tensorR3D3b(tensorR3D3.shape());
tensorR3D3b = tensorR3D3 * 10.0;
mpc::utilities::InnerProductor<double,3> inner_productor_R3D3_fo;
blitz::Array<double,2> ipR3D3 = inner_productor_R3D3_fo(tensorR3D3,tensorR3D3b);
std::cout << "innerProductorR3D3 " << std::endl;
PrintTensorComponents2(ipR3D3);
```
    innerProductorR3D3
    component(0,0) : 37.634
    component(0,1) : 44.654
    component(0,2) : 52.274
    component(1,0) : 134.834
    component(1,1) : 147.854
    component(1,2) : 161.474
    component(2,0) : 292.034
    component(2,1) : 311.054
    component(2,2) : 330.674

```cpp
blitz::Array<double,4> tensorR4D3 = mpcexamples::GetRank04ExampleTensor<double>(3);
blitz::Array<double,4> tensorR4D3b(tensorR4D3.shape());
tensorR4D3b = tensorR4D3 * 10.0;
mpc::utilities::InnerProductor<double,4> inner_productor_R4D3_fo;
blitz::Array<double,3> ipR4D3 = inner_productor_R4D3_fo(tensorR4D3,tensorR4D3b);
std::cout << "innerProductorR4D3 " << std::endl;
PrintTensorComponents3(ipR4D3);
```
    innerProductorR4D3
    component(0,0,0) : 37.0963
    component(0,0,1) : 37.7665
    component(0,0,2) : 38.4427
    component(0,1,0) : 44.0683
    component(0,1,1) : 44.7985
    component(0,1,2) : 45.5347
    component(0,2,0) : 51.6403
    component(0,2,1) : 52.4305
    component(0,2,2) : 53.2267
    component(1,0,0) : 133.816
    component(1,0,1) : 135.087
    component(1,0,2) : 136.363
    component(1,1,0) : 146.788
    component(1,1,1) : 148.119
    component(1,1,2) : 149.455
    component(1,2,0) : 160.36
    component(1,2,1) : 161.751
    component(1,2,2) : 163.147
    component(2,0,0) : 290.536
    component(2,0,1) : 292.407
    component(2,0,2) : 294.283
    component(2,1,0) : 309.508
    component(2,1,1) : 311.439
    component(2,1,2) : 313.375
    component(2,2,0) : 329.08
    component(2,2,1) : 331.071
    component(2,2,2) : 333.067

#### arithmetic and harmonic averaging
Arithmetic and harmonic averages are seen everywhere ...

These function objects are a general abstraction of the equations ...

[mpcexamples::mpcArithmeticAverage()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_arithmeticaverage.cpp)

```cpp
// weights for tests
std::vector<double> vec_weights4 = {0.1, 0.2, 0.3, 0.4};
std::cout << "weights[0] : " << vec_weights4[0] << std::endl;
std::cout << "weights[1] : " << vec_weights4[1] << std::endl;
std::cout << "weights[2] : " << vec_weights4[2] << std::endl;
std::cout << "weights[3] : " << vec_weights4[3] << std::endl;
std::cout << "" << std::endl;

// output single values
std::vector<double> vec_values4 = {1.0, 2.0, 3.0, 4.0};
std::cout << "values[0] : " << vec_values4[0] << std::endl;
std::cout << "values[1] : " << vec_values4[1] << std::endl;
std::cout << "values[2] : " << vec_values4[2] << std::endl;
std::cout << "values[3] : " << vec_values4[3] << std::endl;
std::cout << "" << std::endl;

mpc::utilities::WeightedArithmeticAverage<double,0> aavg0;
double aavg0_value = aavg0(vec_values4, vec_weights4);
std::cout << "average value 0 : " << aavg0_value << std::endl;
std::cout << "" << std::endl;

// compile data for example functions
blitz::Array<double, 1> tensorR1D3_0 = mpcexamples::GetRank01ExampleTensor<double>(3);
blitz::Array<double, 1> tensorR1D3_1 = blitz::Array<double,1>(tensorR1D3_0.shape());
tensorR1D3_1 = tensorR1D3_0 * 5.0;
blitz::Array<double, 1> tensorR1D3_2 = blitz::Array<double,1>(tensorR1D3_0.shape());
tensorR1D3_2 = tensorR1D3_0 * 10.0;
blitz::Array<double, 1> tensorR1D3_3 = blitz::Array<double,1>(tensorR1D3_0.shape());
tensorR1D3_3 = tensorR1D3_0 * 15.0;

std::vector<blitz::Array<double,1>> vec_R1D3;
vec_R1D3.push_back(tensorR1D3_0);
vec_R1D3.push_back(tensorR1D3_1);
vec_R1D3.push_back(tensorR1D3_2);
vec_R1D3.push_back(tensorR1D3_3);

mpc::utilities::WeightedArithmeticAverage<double,1> aavg1;
blitz::Array<double,1> aavg1_R1D3 = aavg1(vec_R1D3, vec_weights4);
std::cout << "arithmetic average R1D3 (1) : " << aavg1_R1D3(0) << std::endl;
std::cout << "arithmetic average R1D3 (2) : " << aavg1_R1D3(1) << std::endl;
std::cout << "arithmetic average R1D3 (3) : " << aavg1_R1D3(2) << std::endl;
std::cout << "" << std::endl;


blitz::Array<double, 2> tensorR2D3_0 = mpcexamples::GetRank02ExampleTensor<double>(3);
blitz::Array<double, 2> tensorR2D3_1 = blitz::Array<double,2>(tensorR2D3_0.shape());
tensorR2D3_1 = tensorR2D3_0 * 5.0;
blitz::Array<double, 2> tensorR2D3_2 = blitz::Array<double,2>(tensorR2D3_0.shape());
tensorR2D3_2 = tensorR2D3_0 * 10.0;
blitz::Array<double, 2> tensorR2D3_3 = blitz::Array<double,2>(tensorR2D3_0.shape());
tensorR2D3_3 = tensorR2D3_0 * 15.0;

std::vector<blitz::Array<double,2>> vec_R2D3;
vec_R2D3.push_back(tensorR2D3_0);
vec_R2D3.push_back(tensorR2D3_1);
vec_R2D3.push_back(tensorR2D3_2);
vec_R2D3.push_back(tensorR2D3_3);

mpc::utilities::WeightedArithmeticAverage<double,2> aavg2;
blitz::Array<double,2> aavg2_R2D3 = aavg2(vec_R2D3, vec_weights4);
std::cout << "arithmetic average R2D3 (1,1) : " << aavg2_R2D3(0,0) << std::endl;
std::cout << "arithmetic average R2D3 (1,2) : " << aavg2_R2D3(0,1) << std::endl;
std::cout << "arithmetic average R2D3 (1,3) : " << aavg2_R2D3(0,2) << std::endl;
std::cout << "arithmetic average R2D3 (2,1) : " << aavg2_R2D3(1,0) << std::endl;
std::cout << "arithmetic average R2D3 (2,2) : " << aavg2_R2D3(1,1) << std::endl;
std::cout << "arithmetic average R2D3 (2,3) : " << aavg2_R2D3(1,2) << std::endl;
std::cout << "arithmetic average R2D3 (3,1) : " << aavg2_R2D3(2,0) << std::endl;
std::cout << "arithmetic average R2D3 (3,2) : " << aavg2_R2D3(2,1) << std::endl;
std::cout << "arithmetic average R2D3 (3,3) : " << aavg2_R2D3(2,2) << std::endl;
std::cout << "" << std::endl;
```
    weights[0] : 0.1
    weights[1] : 0.2
    weights[2] : 0.3
    weights[3] : 0.4

    values[0] : 1
    values[1] : 2
    values[2] : 3
    values[3] : 4

    average value 0 : 3

    arithmetic average R1D3 (1) : 10.1
    arithmetic average R1D3 (2) : 20.2
    arithmetic average R1D3 (3) : 30.3

    arithmetic average R2D3 (1,1) : 11.11
    arithmetic average R2D3 (1,2) : 12.12
    arithmetic average R2D3 (1,3) : 13.13
    arithmetic average R2D3 (2,1) : 21.21
    arithmetic average R2D3 (2,2) : 22.22
    arithmetic average R2D3 (2,3) : 23.23
    arithmetic average R2D3 (3,1) : 31.31
    arithmetic average R2D3 (3,2) : 32.32
    arithmetic average R2D3 (3,3) : 33.33

[mpcexamples::mpcHarmonicAverage()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_harmonicaverage.cpp)
```cpp
// weights for tests
    std::vector<double> vec_weights4 = {0.1, 0.2, 0.3, 0.4};
    std::cout << "weights[0] : " << vec_weights4[0] << std::endl;
    std::cout << "weights[1] : " << vec_weights4[1] << std::endl;
    std::cout << "weights[2] : " << vec_weights4[2] << std::endl;
    std::cout << "weights[3] : " << vec_weights4[3] << std::endl;
    std::cout << "" << std::endl;

    // output single values
    std::vector<double> vec_values4 = {1.0, 2.0, 3.0, 4.0};
    std::cout << "values[0] : " << vec_values4[0] << std::endl;
    std::cout << "values[1] : " << vec_values4[1] << std::endl;
    std::cout << "values[2] : " << vec_values4[2] << std::endl;
    std::cout << "values[3] : " << vec_values4[3] << std::endl;
    std::cout << "" << std::endl;

    mpc::utilities::WeightedHarmonicAverage<double,0> aavg0;
    double aavg0_value = aavg0(vec_values4, vec_weights4);
    std::cout << "average value 0 : " << aavg0_value << std::endl;
    std::cout << "" << std::endl;

    // compile data for example functions
    blitz::Array<double, 1> tensorR1D3_0 = mpcexamples::GetRank01ExampleTensor<double>(3);
    blitz::Array<double, 1> tensorR1D3_1 = blitz::Array<double,1>(tensorR1D3_0.shape());
    tensorR1D3_1 = tensorR1D3_0 * 5.0;
    blitz::Array<double, 1> tensorR1D3_2 = blitz::Array<double,1>(tensorR1D3_0.shape());
    tensorR1D3_2 = tensorR1D3_0 * 10.0;
    blitz::Array<double, 1> tensorR1D3_3 = blitz::Array<double,1>(tensorR1D3_0.shape());
    tensorR1D3_3 = tensorR1D3_0 * 15.0;

    std::vector<blitz::Array<double,1>> vec_R1D3;
    vec_R1D3.push_back(tensorR1D3_0);
    vec_R1D3.push_back(tensorR1D3_1);
    vec_R1D3.push_back(tensorR1D3_2);
    vec_R1D3.push_back(tensorR1D3_3);

    mpc::utilities::WeightedHarmonicAverage<double,1> aavg1;
    blitz::Array<double,1> aavg1_R1D3 = aavg1(vec_R1D3, vec_weights4);
    std::cout << "harmonic average R1D3 (1) : " << aavg1_R1D3(0) << std::endl;
    std::cout << "harmonic average R1D3 (2) : " << aavg1_R1D3(1) << std::endl;
    std::cout << "harmonic average R1D3 (3) : " << aavg1_R1D3(2) << std::endl;
    std::cout << "" << std::endl;


    blitz::Array<double, 2> tensorR2D3_0 = mpcexamples::GetRank02ExampleTensor<double>(3);
    blitz::Array<double, 2> tensorR2D3_1 = blitz::Array<double,2>(tensorR2D3_0.shape());
    tensorR2D3_1 = tensorR2D3_0 * 5.0;
    blitz::Array<double, 2> tensorR2D3_2 = blitz::Array<double,2>(tensorR2D3_0.shape());
    tensorR2D3_2 = tensorR2D3_0 * 10.0;
    blitz::Array<double, 2> tensorR2D3_3 = blitz::Array<double,2>(tensorR2D3_0.shape());
    tensorR2D3_3 = tensorR2D3_0 * 15.0;

    std::vector<blitz::Array<double,2>> vec_R2D3;
    vec_R2D3.push_back(tensorR2D3_0);
    vec_R2D3.push_back(tensorR2D3_1);
    vec_R2D3.push_back(tensorR2D3_2);
    vec_R2D3.push_back(tensorR2D3_3);

    mpc::utilities::WeightedHarmonicAverage<double,2> aavg2;
    blitz::Array<double,2> aavg2_R2D3 = aavg2(vec_R2D3, vec_weights4);
    std::cout << "harmonic average R2D3 (1,1) : " << aavg2_R2D3(0,0) << std::endl;
    std::cout << "harmonic average R2D3 (1,2) : " << aavg2_R2D3(0,1) << std::endl;
    std::cout << "harmonic average R2D3 (1,3) : " << aavg2_R2D3(0,2) << std::endl;
    std::cout << "harmonic average R2D3 (2,1) : " << aavg2_R2D3(1,0) << std::endl;
    std::cout << "harmonic average R2D3 (2,2) : " << aavg2_R2D3(1,1) << std::endl;
    std::cout << "harmonic average R2D3 (2,3) : " << aavg2_R2D3(1,2) << std::endl;
    std::cout << "harmonic average R2D3 (3,1) : " << aavg2_R2D3(2,0) << std::endl;
    std::cout << "harmonic average R2D3 (3,2) : " << aavg2_R2D3(2,1) << std::endl;
    std::cout << "harmonic average R2D3 (3,3) : " << aavg2_R2D3(2,2) << std::endl;
    std::cout << "" << std::endl;
```
    weights[0] : 0.1
    weights[1] : 0.2
    weights[2] : 0.3
    weights[3] : 0.4

    values[0] : 1
    values[1] : 2
    values[2] : 3
    values[3] : 4

    average value 0 : 2.5

    harmonic average R1D3 (1) : 5.08475
    harmonic average R1D3 (2) : 10.1695
    harmonic average R1D3 (3) : 15.2542

    harmonic average R2D3 (1,1) : 5.59322
    harmonic average R2D3 (1,2) : 6.10169
    harmonic average R2D3 (1,3) : 6.61017
    harmonic average R2D3 (2,1) : 10.678
    harmonic average R2D3 (2,2) : 11.1864
    harmonic average R2D3 (2,3) : 11.6949
    harmonic average R2D3 (3,1) : 15.7627
    harmonic average R2D3 (3,2) : 16.2712
    harmonic average R2D3 (3,3) : 16.7797

> see Thomsen, 2014, Lecture 1, page 9

#### kronecker delta and identity tensor
The Kronecker delta is a second rank identity tensor, i.e. has the value 1 when i=j and 0 when i != j.  mpc provides a standard template function that returns a two dimensional blitz array.  mpc also provides a compile-time template function object when i and j are known at compile-time.  The Kroncker delta is used ubiquitously throughout mechanics.
[mpcexamples::mpcKroneckerDeltaAndIdentityTensor()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_kdeltaidentitytensor.cpp)
```cpp
blitz::Array<double,2> kdelta = mpc::utilities::KroneckerDelta<double,3>();
PrintTensorComponents2(kdelta);
```
    component(0,0) : 1
    component(0,1) : 0
    component(0,2) : 0
    component(1,0) : 0
    component(1,1) : 1
    component(1,2) : 0
    component(2,0) : 0
    component(2,1) : 0
    component(2,2) : 1

Another common tensor related to the Kroncker delta is the fourth rank identity tensor.  One place this is used is when defining the relationship between stiffness and compliance tensors.
```cpp
```

#### magnitude and norm
Common functions when dealing with vectors.  mpc::utilities::Magnitude is a great example of how Accumulator sum is an abstraction of more concrete ideas.  In this case, the magnitude is the square root of the sum of the squares.

[mpcexamples::mpcMagnitudeAndNorms()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_magandnorm.cpp)
```cpp
mpc::utilities::PrintTensorComponents<double,1> PrintTensorComponents1;
// blitz::Array<double,1> tensorR1D3
auto tensorR1D3 = mpcexamples::GetRank01ExampleTensor<double>(3);
PrintTensorComponents1(tensorR1D3);

double mag = mpc::utilities::Magnitude(tensorR1D3);  // template type deduced from input
std::cout << "magnitude : " << mag << "\n" << std::endl;

blitz::Array<double,1> normalized_tensorR1D3 = mpc::utilities::Normal(tensorR1D3);
PrintTensorComponents1(normalized_tensorR1D3);

// normalize in place;  WARNING!!! this will change the components of the input array
mpc::utilities::Normalize(tensorR1D3);
PrintTensorComponents1(tensorR1D3);
```
    component(0) : 1
    component(1) : 2
    component(2) : 3

    magnitude : 3.74166

    component(0) : 0.267261
    component(1) : 0.534522
    component(2) : 0.801784

    component(0) : 0.267261
    component(1) : 0.534522
    component(2) : 0.801784

#### blitz2eigen and eigen2blitz
to be completed ...

#### unwrapper
Used for *unwrapping* a multi-dimensional array into a single 1D array.  Used in the transformation objects and functions.
to be completed ...

#### exactpolynomial roots
to be completed ...

#### lin- log- and geomspace (functions base)
to be completed ...

#### coordinate mapping
Function Objects and functions for mapping between different coordinate systems.
> TODO: more examples!!

The following example illustrates the mapping of \(r,\theta\) on a disk to Cartesian coordinates and then finding the z component such that the magnitude is one, that is map to a hemisphere of radius one.

[mpcexamples::mpcCoordinateMapping()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_coordinatemapping.cpp)
```cpp
const int NUM_ELEMS = 4;

const double PI = mpc::utilities::PI<double>;
const double TWO_PI = 2.0 * PI;
const double PI_OVER_TWO = 0.5 * PI;

double colattitude = 0;  // relative to x3 axis
double azimuth = 0;      // in 2d plane
double smallradius = 0;  // in 2d plane
double x = 0;
double y = 0;
double z = 0;
double xyarg = 0;
double mag = 0;
int cntr = 0;

blitz::Array<double,1> normal_vector = blitz::Array<double,1>(3);
normal_vector = 1,0,0;

mpc::utilities::CoordinateMapping<double,mpc::utilities::CartesianCoordinateType,mpc::utilities::CylindricalCoordinateType> coordinate_mapping_fo;

std::tuple<double,double,double> coords{};

// =================================================================================================================
/* (x,y) on a disk */
std::cout << "mapping on a disk" << std::endl;
std::vector<double> small_radius_linspace = mpc::utilities::Linspace(0.0 + (1.0 / NUM_ELEMS), 1.0, NUM_ELEMS);  // (0,1]

std::vector<double> azimuth_linspace = mpc::utilities::Linspace(0.0, TWO_PI - (TWO_PI/double(NUM_ELEMS)), NUM_ELEMS);  // [0,2pi)


for (auto rho : small_radius_linspace) {
    //
    for (auto theta : azimuth_linspace) {
        //
        coords = coordinate_mapping_fo(rho,theta,0);  // set z to zero for the x-y plane
        x = std::get<0>(coords);
        y = std::get<1>(coords);
        //z = std::get<2>(coords);
        xyarg = std::abs(1.0 - std::pow(x,2) - std::pow(y,2));
        z = sqrt(xyarg);
        normal_vector = x, y, z;
        std::cout << rho << ", " << theta << std::endl;
        std::cout << xyarg << std::endl;
        std::cout << normal_vector << std::endl;
        mag = mpc::utilities::Magnitude(normal_vector);
        //std::cout << "magnitude : " << mag << std::endl;  // obviously, this should be one

        // corresponding negative
        z *= -1.0;
        normal_vector = x, y, z;
        std::cout << normal_vector << std::endl;
        mag = mpc::utilities::Magnitude(normal_vector);
        //std::cout << "magnitude : " << mag << std::endl;  // obviously, this should be one
    }
}
```
    mapping on a disk
    0.25, 0
    0.9375
    (0,2)
    [ 0.25 0 0.968246 ]

    (0,2)
    [ 0.25 0 -0.968246 ]

    0.25, 1.5708
    0.9375
    (0,2)
    [ 1.53081e-17 0.25 0.968246 ]

    (0,2)
    [ 1.53081e-17 0.25 -0.968246 ]

    0.25, 3.14159
    0.9375
    (0,2)
    [ -0.25 3.06162e-17 0.968246 ]

    (0,2)
    [ -0.25 3.06162e-17 -0.968246 ]

    0.25, 4.71239
    0.9375
    (0,2)
    [ -4.59243e-17 -0.25 0.968246 ]

    (0,2)
    [ -4.59243e-17 -0.25 -0.968246 ]

    0.5, 0
    0.75
    (0,2)
    [ 0.5 0 0.866025 ]

    (0,2)
    [ 0.5 0 -0.866025 ]

    0.5, 1.5708
    0.75
    (0,2)
    [ 3.06162e-17 0.5 0.866025 ]

    (0,2)
    [ 3.06162e-17 0.5 -0.866025 ]

    0.5, 3.14159
    0.75
    (0,2)
    [ -0.5 6.12323e-17 0.866025 ]

    (0,2)
    [ -0.5 6.12323e-17 -0.866025 ]

    0.5, 4.71239
    0.75
    (0,2)
    [ -9.18485e-17 -0.5 0.866025 ]

    (0,2)
    [ -9.18485e-17 -0.5 -0.866025 ]

    0.75, 0
    0.4375
    (0,2)
    [ 0.75 0 0.661438 ]

    (0,2)
    [ 0.75 0 -0.661438 ]

    0.75, 1.5708
    0.4375
    (0,2)
    [ 4.59243e-17 0.75 0.661438 ]

    (0,2)
    [ 4.59243e-17 0.75 -0.661438 ]

    0.75, 3.14159
    0.4375
    (0,2)
    [ -0.75 9.18485e-17 0.661438 ]

    (0,2)
    [ -0.75 9.18485e-17 -0.661438 ]

    0.75, 4.71239
    0.4375
    (0,2)
    [ -1.37773e-16 -0.75 0.661438 ]

    (0,2)
    [ -1.37773e-16 -0.75 -0.661438 ]

    1, 0
    0
    (0,2)
    [ 1 0 0 ]

    (0,2)
    [ 1 0 -0 ]

    1, 1.5708
    0
    (0,2)
    [ 6.12323e-17 1 0 ]

    (0,2)
    [ 6.12323e-17 1 -0 ]

    1, 3.14159
    1.49976e-32
    (0,2)
    [ -1 1.22465e-16 1.22465e-16 ]

    (0,2)
    [ -1 1.22465e-16 -1.22465e-16 ]

    1, 4.71239
    0
    (0,2)
    [ -1.83697e-16 -1 0 ]

    (0,2)
    [ -1.83697e-16 -1 -0 ]


#### unit conversion
Simple functions for converting between units.
> should be replaced with complete dimensional analysis library like boost::units with implicit unit conversion

#### matrix notation
> work is needed when shifting from matrix notation to tensors and vice versa;  functions and the objects the algorithms work on are different when using matrix notation and using the full tensor solution.

to be completed.


### references
* Bass, J.D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63.
* Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
* Smith, Tad M., Sondergeld, Carl H., Rai, Chandra S., 2003, Gassmann fluid substitutions: A tutorial: GEOPHYSICS, 68, 2, 430-440
* Thomsen, Leon, 2014, Understanding seismic anisotropy in exploration and exploitation, second edition: Society of Exploration Geophysics.

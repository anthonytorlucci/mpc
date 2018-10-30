# mpcexamples
mechanical properties of crystals and polycrystalline aggregates

---
### core data structures
#### terminology and mpc conventions

While stress and strain can be measured in two dimensions and possibly any curvilinear coordinate system, this higher level of abstraction was considered beyond the scope of the project.  Therefore, all tensors are considered to be Cartesian tensors in a three-dimensional space.

Like most computational libraries, mpc has a few core data structures, most notably, the <span style="font-family:Courier New; font-size:4em;">Stiffness Tensor</span> class and <span style="font-family:Courier New; font-size:4em;">Compliance Tensor</span> class which are used ubiquitously throughout the library to describe the mathematical objects, the stiffness tensor and compliance tensor, respectively.  Before we can use these classes, we must discuss the terminology of tensors used in the library and the abstract data types that form the foundation of the library generated from these concepts.

As previously mentioned, we will do our investigation in three-dimensional space calculating the stiffness and compliance of a representative volume; therefore, the indices will take the range i,j,... = 0,1,2. This is known as the *range convention*. Note that mpc is written in c++ and uses the c++ convention of zero-based indexing.  This is different from mathematical languages like fortran and the literature which uses the indices i,j,... = 1,2,3. The second convention to note, which we have already used, is the *summation convention* for which we define the *rank* of a tensor as the number of *free* indices - those indices which do not repeat. For example, the stiffness and compliance tensors are of rank four corresponding to the free indices *i*, *j*, *k*, and *l*. The stress and strain tensors are of rank two corresponding to the free indices *i* and *j*, or *k* and *l*. A vector is of rank one and written in suffix notation as \(v_i\) where *i* takes the range 0,1,2 in three dimensional space. Finally, a scalar value is a tensor of rank zero and written without a free index as \(\alpha\). Note that a tensor with a *dummy* index is also a scalar value, e.g. \(\alpha_{ii}\).  These *invariants* are very important in tensor analysis and will be discussed later.


#### TensorComponentIndex
Tensors in mpc are represented as multi-dimensional arrays in which each dimension corresponds to an index and the values in that dimension correspond to the range convention of the tensor. mpc defines this index with a template class:

    TensorRankNComponentIndex<N>

For example,

[mpcexamples::mpcTensorRank2ComponentIndex()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_tensorrank2componentindex.cpp)

```cpp
mpc::core::TensorRankNComponentIndex<2> index00 = mpc::core::TensorRankNComponentIndex<2>(0,0);
std::cout << "index(0,0) : " << index00 << std::endl;
mpc::core::TensorRankNComponentIndex<2> index01 = mpc::core::TensorRankNComponentIndex<2>(0,1);
std::cout << "index(0,1) : " << index01 << std::endl;
mpc::core::TensorRankNComponentIndex<2> index02 = mpc::core::TensorRankNComponentIndex<2>(0,2);
std::cout << "index(0,2) : " << index02 << std::endl;
mpc::core::TensorRankNComponentIndex<2> index10 = mpc::core::TensorRankNComponentIndex<2>(1,0);
std::cout << "index(1,0) : " << index10 << std::endl;
mpc::core::TensorRankNComponentIndex<2> index11 = mpc::core::TensorRankNComponentIndex<2>(1,1);
std::cout << "index(1,1) : " << index11 << std::endl;
mpc::core::TensorRankNComponentIndex<2> index12 = mpc::core::TensorRankNComponentIndex<2>(1,2);
std::cout << "index(1,2) : " << index12 << std::endl;
mpc::core::TensorRankNComponentIndex<2> index20 = mpc::core::TensorRankNComponentIndex<2>(2,0);
std::cout << "index(2,0) : " << index20 << std::endl;
mpc::core::TensorRankNComponentIndex<2> index21 = mpc::core::TensorRankNComponentIndex<2>(2,1);
std::cout << "index(2,1) : " << index21 << std::endl;
mpc::core::TensorRankNComponentIndex<2> index22 = mpc::core::TensorRankNComponentIndex<2>(2,2);
std::cout << "index(2,2) : " << index22 << std::endl;
```
Output

    index(0,0) : [0,0]
    index(0,1) : [0,1]
    index(0,2) : [0,2]
    index(1,0) : [1,0]
    index(1,1) : [1,1]
    index(1,2) : [1,2]
    index(2,0) : [2,0]
    index(2,1) : [2,1]
    index(2,2) : [2,2]    


A tensor component index of rank 2 has two member functions defined in the class: FirstIndex() and SecondIndex() which retrieve the index values from the first index and the second index, respectively. These are also constexpr functions and can be called at compile time and therefore known to the compiler and can be used in other constexpr functions, but NOT as template parameter values. In addition, there are four non-member functions that overload the operators "==", "!=", "<", and ">" for comparison. The less than and greater than operators don't really make sense for an index, but are necessary because std::less<Key> is the default comparson operator used in std::set, an STL container used ubiquitously throughout the MPC library.  Therefore, mpc defines index ordering as:

00 < 01 < 02 < 10 < 11 < 12 < 20 < 21 < 22

```cpp
std::vector<mpc::core::TensorRank2ComponentIndex> vec_indexXX{
    index00,
    index01,
    index02,
    index10,
    index11,
    index12,
    index20,
    index21,
    index22
};
int first_indexXX;
int second_indexXX;
for (auto indexXX : vec_indexXX) {
    first_indexXX = indexXX.FirstIndex();
    std::cout << indexXX << " FirstIndex() :  " << first_indexXX << std::endl;
    second_indexXX = indexXX.SecondIndex();
    std::cout << indexXX << " SecondIndex() : " << second_indexXX << std::endl;
}
```
Output:

    [0,0] FirstIndex() :  0
    [0,0] SecondIndex() : 0
    [0,1] FirstIndex() :  0
    [0,1] SecondIndex() : 1
    [0,2] FirstIndex() :  0
    [0,2] SecondIndex() : 2
    [1,0] FirstIndex() :  1
    [1,0] SecondIndex() : 0
    [1,1] FirstIndex() :  1
    [1,1] SecondIndex() : 1
    [1,2] FirstIndex() :  1
    [1,2] SecondIndex() : 2
    [2,0] FirstIndex() :  2
    [2,0] SecondIndex() : 0
    [2,1] FirstIndex() :  2
    [2,1] SecondIndex() : 1
    [2,2] FirstIndex() :  2
    [2,2] SecondIndex() : 2

```cpp
std::cout << "" << std::endl;
for (auto indexXX : vec_indexXX) {
    std::cout << indexXX << " == " << index11 << " : " << (indexXX == index11) << std::endl;
    std::cout << indexXX << " != " << index11 << " : " << (indexXX != index11) << std::endl;
    std::cout << indexXX << " <  " << index11 << " : " << (indexXX < index11) << std::endl;
    std::cout << indexXX << " >  " << index11 << " : " << (indexXX > index11) << std::endl;
    std::cout << indexXX << " <= " << index11 << " : " << (indexXX <= index11) << std::endl;
    std::cout << indexXX << " >= " << index11 << " : " << (indexXX >= index11) << std::endl;
}
```
Output

    [0,0] == [1,1] : false
    [0,0] != [1,1] : true
    [0,0] <  [1,1] : true
    [0,0] >  [1,1] : false
    [0,0] <= [1,1] : true
    [0,0] >= [1,1] : false
    [0,1] == [1,1] : false
    [0,1] != [1,1] : true
    [0,1] <  [1,1] : true
    [0,1] >  [1,1] : false
    [0,1] <= [1,1] : true
    [0,1] >= [1,1] : false
    [0,2] == [1,1] : false
    [0,2] != [1,1] : true
    [0,2] <  [1,1] : true
    [0,2] >  [1,1] : false
    [0,2] <= [1,1] : true
    [0,2] >= [1,1] : false
    [1,0] == [1,1] : false
    [1,0] != [1,1] : true
    [1,0] <  [1,1] : true
    [1,0] >  [1,1] : false
    [1,0] <= [1,1] : true
    [1,0] >= [1,1] : false
    [1,1] == [1,1] : true
    [1,1] != [1,1] : false
    [1,1] <  [1,1] : false
    [1,1] >  [1,1] : false
    [1,1] <= [1,1] : true
    [1,1] >= [1,1] : true
    [1,2] == [1,1] : false
    [1,2] != [1,1] : true
    [1,2] <  [1,1] : false
    [1,2] >  [1,1] : true
    [1,2] <= [1,1] : false
    [1,2] >= [1,1] : true
    [2,0] == [1,1] : false
    [2,0] != [1,1] : true
    [2,0] <  [1,1] : false
    [2,0] >  [1,1] : true
    [2,0] <= [1,1] : false
    [2,0] >= [1,1] : true
    [2,1] == [1,1] : false
    [2,1] != [1,1] : true
    [2,1] <  [1,1] : false
    [2,1] >  [1,1] : true
    [2,1] <= [1,1] : false
    [2,1] >= [1,1] : true
    [2,2] == [1,1] : false
    [2,2] != [1,1] : true
    [2,2] <  [1,1] : false
    [2,2] >  [1,1] : true
    [2,2] <= [1,1] : false
    [2,2] >= [1,1] : true

<code>TensorRankNComponentIndex<2></code> also provides an inline function to return the index value using the subscript operator.

```cpp
std::cout << index00 << " index using operator [0] : " << index00[0] << std::endl;
std::cout << index00 << " index using operator [1] : " << index00[1] << std::endl;
std::cout << index01 << " index using operator [0] : " << index01[0] << std::endl;
std::cout << index01 << " index using operator [1] : " << index01[1] << std::endl;
std::cout << index02 << " index using operator [0] : " << index02[0] << std::endl;
std::cout << index02 << " index using operator [1] : " << index02[1] << std::endl;
std::cout << index10 << " index using operator [0] : " << index10[0] << std::endl;
std::cout << index10 << " index using operator [1] : " << index10[1] << std::endl;
std::cout << index11 << " index using operator [0] : " << index11[0] << std::endl;
std::cout << index11 << " index using operator [1] : " << index11[1] << std::endl;
std::cout << index12 << " index using operator [0] : " << index12[0] << std::endl;
std::cout << index12 << " index using operator [1] : " << index12[1] << std::endl;
std::cout << index20 << " index using operator [0] : " << index20[0] << std::endl;
std::cout << index20 << " index using operator [1] : " << index20[1] << std::endl;
std::cout << index21 << " index using operator [0] : " << index21[0] << std::endl;
std::cout << index21 << " index using operator [1] : " << index21[1] << std::endl;
std::cout << index22 << " index using operator [0] : " << index22[0] << std::endl;
std::cout << index22 << " index using operator [1] : " << index22[1] << std::endl;
```
Output

    [0,0] index using operator [0] : 0
    [0,0] index using operator [1] : 0
    [0,1] index using operator [0] : 0
    [0,1] index using operator [1] : 1
    [0,2] index using operator [0] : 0
    [0,2] index using operator [1] : 2
    [1,0] index using operator [0] : 1
    [1,0] index using operator [1] : 0
    [1,1] index using operator [0] : 1
    [1,1] index using operator [1] : 1
    [1,2] index using operator [0] : 1
    [1,2] index using operator [1] : 2
    [2,0] index using operator [0] : 2
    [2,0] index using operator [1] : 0
    [2,1] index using operator [0] : 2
    [2,1] index using operator [1] : 1
    [2,2] index using operator [0] : 2
    [2,2] index using operator [1] : 2

For convenience, mpc provides an alias for the second rank tensor component index with the using directive:

```cpp
using TensorRank2ComponentIndex = TensorRankNComponentIndex<2>;
```

Writing a tensor component index with the alias may be easier to read. For example,

```cpp
std::cout << "index(0,0) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(0,0) << std::endl;
std::cout << "index(0,1) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(0,1) << std::endl;
std::cout << "index(0,2) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(0,2) << std::endl;
std::cout << "index(1,0) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(1,0) << std::endl;
std::cout << "index(1,1) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(1,1) << std::endl;
std::cout << "index(1,2) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(1,2) << std::endl;
std::cout << "index(2,0) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(2,0) << std::endl;
std::cout << "index(2,1) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(2,1) << std::endl;
std::cout << "index(2,2) using TensorRank2 alias type definition : " << mpc::core::TensorRank2ComponentIndex(2,2) << std::endl;
```
Output

    index(0,0) using TensorRank2 alias type definition : [0,0]
    index(0,1) using TensorRank2 alias type definition : [0,1]
    index(0,2) using TensorRank2 alias type definition : [0,2]
    index(1,0) using TensorRank2 alias type definition : [1,0]
    index(1,1) using TensorRank2 alias type definition : [1,1]
    index(1,2) using TensorRank2 alias type definition : [1,2]
    index(2,0) using TensorRank2 alias type definition : [2,0]
    index(2,1) using TensorRank2 alias type definition : [2,1]
    index(2,2) using TensorRank2 alias type definition : [2,2]

Since the underlying data structure for mpc is a blitz array, it is often convenient to insert a value into the tensor member variable using <code>blitz::TinyVector<int,2></code> to refer to the index from the <code>TensorRankNComponent<2></code>.  The <code>TensorRankNComponentIndex<2></code> class provides a static member function to do just this...

```cpp
blitz::TinyVector<int,2> blitz_index00 = mpc::core::TensorRankNComponentIndex<2>::ToBlitzTinyVector(index00);
std::cout << "TinyVector blitz_index00 : " << blitz_index00 << std::endl;

blitz::TinyVector<int,2> blitz_index01 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index01);
std::cout << "TinyVector blitz_index01 : " << blitz_index01 << std::endl;

blitz::TinyVector<int,2> blitz_index02 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index02);
std::cout << "TinyVector blitz_index02 : " << blitz_index02 << std::endl;

blitz::TinyVector<int,2> blitz_index10 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index10);
std::cout << "TinyVector blitz_index10 : " << blitz_index10 << std::endl;

blitz::TinyVector<int,2> blitz_index11 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index11);
std::cout << "TinyVector blitz_index11 : " << blitz_index11 << std::endl;

blitz::TinyVector<int,2> blitz_index12 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index12);
std::cout << "TinyVector blitz_index12 : " << blitz_index12 << std::endl;

blitz::TinyVector<int,2> blitz_index20 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index20);
std::cout << "TinyVector blitz_index20 : " << blitz_index20 << std::endl;

blitz::TinyVector<int,2> blitz_index21 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index21);
std::cout << "TinyVector blitz_index21 : " << blitz_index21 << std::endl;

blitz::TinyVector<int,2> blitz_index22 = mpc::core::TensorRank2ComponentIndex::ToBlitzTinyVector(index22);
std::cout << "TinyVector blitz_index22 : " << blitz_index22 << std::endl;
```
Output

    TinyVector blitz_index00 : (0,0)
    TinyVector blitz_index01 : (0,1)
    TinyVector blitz_index02 : (0,2)
    TinyVector blitz_index10 : (1,0)
    TinyVector blitz_index11 : (1,1)
    TinyVector blitz_index12 : (1,2)
    TinyVector blitz_index20 : (2,0)
    TinyVector blitz_index21 : (2,1)
    TinyVector blitz_index22 : (2,2)

The index itself is very powerful. Two additional functions are defined to get the number of aliases and the aliases themselves. For a second rank tensor aliases are defined as the symmetrical components. That is to say, <code>A(i,j) = A(j,i)</code>, and thus the nine components of a second rank tensor in 3 dimensional space reduces to just 6.

Definition of aliases in mpc for a second rank symmetrical tensor:
* X00 >> (11)
* X01 >> (01), (10)
* X02 >> (02), (20)
* X10 >> (01), (10)
* X11 >> (22)
* X12 >> (12), (21)
* X20 >> (02), (20)
* X21 >> (12), (21)
* X22 >> (22)

Let's combine indices in a <code>std::set<T></code> which itself is powerful tool and has some interesting properties and algorithms. The next section illustrates useful functions that take advantage of these properties and algorithms. Why use <code>std::set<T></code> and not <code>std::vector<T></code>? A set will automatically check if the value being inserted is already present. We want all components in a set to be unique becauase they map to one and only one component in the actual tensor.

Some useful algorithms in the STL library for <code>std::set<T></code> are:
* includes()
* set_union()
* set_intersection()
* set_difference()
* set_symmetrical_difference()

>see Stroustrup, 2013, The C++ Programming Language, fourth ed.,  p. 947

Note that the values in a set are ordered. Set tests for equality with another element already in the set using <code>std::less<Key></code>. An index has no natrual order, but mpc defines it like this

        00 < 01 < 02 < 10 < 11 < 12 < 20 < 21 < 22

Containers of <code>TensorRankNComponentIndex<N></code> can now be sorted or stored in ordered containers like <code>std::set<T></code>.

```cpp
int num_aliases00 = mpc::core::TensorRank2IndexNumberOfAliases(index00);
std::cout << "number of aliases for index00 : " << num_aliases00 << std::endl;
std::set<mpc::core::TensorRank2ComponentIndex> set_aliases00 = mpc::core::TensorRank2IndexAliases(index00); // no aliases
for (auto alias : set_aliases00) {
    std::cout << "rank2 alias of 00 : " << alias << std::endl;
}

int num_aliases01 = mpc::core::TensorRank2IndexNumberOfAliases(index01);
std::cout << "number of aliases for index01 : " << num_aliases01 << std::endl;
std::set<mpc::core::TensorRank2ComponentIndex> set_aliases01 = mpc::core::TensorRank2IndexAliases(index01);
for (auto alias : set_aliases01) {
    std::cout << "rank2 alias of 01 : " << alias << std::endl;
}

int num_aliases02 = mpc::core::TensorRank2IndexNumberOfAliases(index02);
std::cout << "number of aliases for index02 : " << num_aliases02 << std::endl;
std::set<mpc::core::TensorRank2ComponentIndex> set_aliases02 = mpc::core::TensorRank2IndexAliases(index02);
for (auto alias : set_aliases02) {
    std::cout << "rank2 alias of 02 : " << alias << std::endl;
}

int num_aliases10 = mpc::core::TensorRank2IndexNumberOfAliases(index10);
std::cout << "number of aliases for index10 : " << num_aliases10 << std::endl;
std::set<mpc::core::TensorRank2ComponentIndex> set_aliases10 = mpc::core::TensorRank2IndexAliases(index10);
for (auto alias : set_aliases10) {
    std::cout << "rank2 alias of 10 : " << alias << std::endl;
}

int num_aliases11 = mpc::core::TensorRank2IndexNumberOfAliases(index11);
std::cout << "number of aliases for index11 : " << num_aliases11 << std::endl;
std::set<mpc::core::TensorRank2ComponentIndex> set_aliases11 = mpc::core::TensorRank2IndexAliases(index11);
for (auto alias : set_aliases11) {
    std::cout << "rank2 alias of 11 : " << alias << std::endl;
}

int num_aliases12 = mpc::core::TensorRank2IndexNumberOfAliases(index12);
std::cout << "number of aliases for index12 : " << num_aliases12 << std::endl;
std::set<mpc::core::TensorRank2ComponentIndex> set_aliases12 = mpc::core::TensorRank2IndexAliases(index12);
for (auto alias : set_aliases12) {
    std::cout << "rank2 alias of 12 : " << alias << std::endl;
}

int num_aliases20 = mpc::core::TensorRank2IndexNumberOfAliases(index20);
std::cout << "number of aliases for index20 : " << num_aliases20 << std::endl;
std::set<mpc::core::TensorRank2ComponentIndex> set_aliases20 = mpc::core::TensorRank2IndexAliases(index20);
for (auto alias : set_aliases20) {
    std::cout << "rank2 alias of 20 : " << alias << std::endl;
}

int num_aliases21 = mpc::core::TensorRank2IndexNumberOfAliases(index21);
std::cout << "number of aliases for index21 : " << num_aliases21 << std::endl;
std::set<mpc::core::TensorRank2ComponentIndex> set_aliases21 = mpc::core::TensorRank2IndexAliases(index21);
for (auto alias : set_aliases21) {
    std::cout << "rank2 alias of 21 : " << alias << std::endl;
}

int num_aliases22 = mpc::core::TensorRank2IndexNumberOfAliases(index22);
std::cout << "number of aliases for index22 : " << num_aliases22 << std::endl;
std::set<mpc::core::TensorRank2ComponentIndex> set_aliases22 = mpc::core::TensorRank2IndexAliases(index22);
for (auto alias : set_aliases22) {
    std::cout << "rank2 alias of 22 : " << alias << std::endl;
}
```
Output

    number of aliases for index00 : 1
    rank2 alias of 00 : [0,0]
    number of aliases for index01 : 2
    rank2 alias of 01 : [0,1]
    rank2 alias of 01 : [1,0]
    number of aliases for index02 : 2
    rank2 alias of 02 : [0,2]
    rank2 alias of 02 : [2,0]
    number of aliases for index10 : 2
    rank2 alias of 10 : [0,1]
    rank2 alias of 10 : [1,0]
    number of aliases for index11 : 1
    rank2 alias of 11 : [1,1]
    number of aliases for index12 : 2
    rank2 alias of 12 : [1,2]
    rank2 alias of 12 : [2,1]
    number of aliases for index20 : 2
    rank2 alias of 20 : [0,2]
    rank2 alias of 20 : [2,0]
    number of aliases for index21 : 2
    rank2 alias of 21 : [1,2]
    rank2 alias of 21 : [2,1]
    number of aliases for index22 : 1
    rank2 alias of 22 : [2,2]

Currently, mpc provides two predicates (callable that returns a value testable as a bool - see [C++ named requirements: Predicate](https://en.cppreference.com/w/cpp/named_req/Predicate) ) for <code>TensorRankNCompoentIndex<N></code> where N is either 2 or 4: <code>...IsAlias(...)</code> and <code>...HasAlias(...)</code>. The definiton of aliases is defined by symmetry.

```cpp
bool indexXX_has_alias;
bool indexXX_is_alias_indexXX;

for (auto indexXX : vec_indexXX) {
    indexXX_has_alias = mpc::core::TensorRank2ComponentIndexHasAlias(indexXX);
    std::cout << indexXX << " index has alias ? : " << indexXX_has_alias << std::endl;
    indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index00);
    std::cout << indexXX << " is_alias " << index00 << " ? " << indexXX_is_alias_indexXX << std::endl;
    indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index01);
    std::cout << indexXX << " is_alias " << index01 << " ? " << indexXX_is_alias_indexXX << std::endl;
    indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index02);
    std::cout << indexXX << " is_alias " << index02 << " ? " << indexXX_is_alias_indexXX << std::endl;
    indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index10);
    std::cout << indexXX << " is_alias " << index10 << " ? " << indexXX_is_alias_indexXX << std::endl;
    indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index12);
    std::cout << indexXX << " is_alias " << index12 << " ? " << indexXX_is_alias_indexXX << std::endl;
    indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index20);
    std::cout << indexXX << " is_alias " << index20 << " ? " << indexXX_is_alias_indexXX << std::endl;
    indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index21);
    std::cout << indexXX << " is_alias " << index21 << " ? " << indexXX_is_alias_indexXX << std::endl;
    indexXX_is_alias_indexXX = mpc::core::TensorRank2ComponentIndexIsAlias(indexXX, index22);
    std::cout << indexXX << " is_alias " << index22 << " ? " << indexXX_is_alias_indexXX << std::endl;
}
```
Output

    [0,0] index has alias ? : false
    [0,0] is_alias [0,0] ? true
    [0,0] is_alias [0,1] ? false
    [0,0] is_alias [0,2] ? false
    [0,0] is_alias [1,0] ? false
    [0,0] is_alias [1,2] ? false
    [0,0] is_alias [2,0] ? false
    [0,0] is_alias [2,1] ? false
    [0,0] is_alias [2,2] ? false
    [0,1] index has alias ? : true
    [0,1] is_alias [0,0] ? false
    [0,1] is_alias [0,1] ? true
    [0,1] is_alias [0,2] ? false
    [0,1] is_alias [1,0] ? true
    [0,1] is_alias [1,2] ? false
    [0,1] is_alias [2,0] ? false
    [0,1] is_alias [2,1] ? false
    [0,1] is_alias [2,2] ? false
    [0,2] index has alias ? : true
    [0,2] is_alias [0,0] ? false
    [0,2] is_alias [0,1] ? false
    [0,2] is_alias [0,2] ? true
    [0,2] is_alias [1,0] ? false
    [0,2] is_alias [1,2] ? false
    [0,2] is_alias [2,0] ? true
    [0,2] is_alias [2,1] ? false
    [0,2] is_alias [2,2] ? false
    [1,0] index has alias ? : true
    [1,0] is_alias [0,0] ? false
    [1,0] is_alias [0,1] ? true
    [1,0] is_alias [0,2] ? false
    [1,0] is_alias [1,0] ? true
    [1,0] is_alias [1,2] ? false
    [1,0] is_alias [2,0] ? false
    [1,0] is_alias [2,1] ? false
    [1,0] is_alias [2,2] ? false
    [1,1] index has alias ? : false
    [1,1] is_alias [0,0] ? false
    [1,1] is_alias [0,1] ? false
    [1,1] is_alias [0,2] ? false
    [1,1] is_alias [1,0] ? false
    [1,1] is_alias [1,2] ? false
    [1,1] is_alias [2,0] ? false
    [1,1] is_alias [2,1] ? false
    [1,1] is_alias [2,2] ? false
    [1,2] index has alias ? : true
    [1,2] is_alias [0,0] ? false
    [1,2] is_alias [0,1] ? false
    [1,2] is_alias [0,2] ? false
    [1,2] is_alias [1,0] ? false
    [1,2] is_alias [1,2] ? true
    [1,2] is_alias [2,0] ? false
    [1,2] is_alias [2,1] ? true
    [1,2] is_alias [2,2] ? false
    [2,0] index has alias ? : true
    [2,0] is_alias [0,0] ? false
    [2,0] is_alias [0,1] ? false
    [2,0] is_alias [0,2] ? true
    [2,0] is_alias [1,0] ? false
    [2,0] is_alias [1,2] ? false
    [2,0] is_alias [2,0] ? true
    [2,0] is_alias [2,1] ? false
    [2,0] is_alias [2,2] ? false
    [2,1] index has alias ? : true
    [2,1] is_alias [0,0] ? false
    [2,1] is_alias [0,1] ? false
    [2,1] is_alias [0,2] ? false
    [2,1] is_alias [1,0] ? false
    [2,1] is_alias [1,2] ? true
    [2,1] is_alias [2,0] ? false
    [2,1] is_alias [2,1] ? true
    [2,1] is_alias [2,2] ? false
    [2,2] index has alias ? : false
    [2,2] is_alias [0,0] ? false
    [2,2] is_alias [0,1] ? false
    [2,2] is_alias [0,2] ? false
    [2,2] is_alias [1,0] ? false
    [2,2] is_alias [1,2] ? false
    [2,2] is_alias [2,0] ? false
    [2,2] is_alias [2,1] ? false
    [2,2] is_alias [2,2] ? true

Reduced components ...
```cpp
mpc::core::TensorRank2ComponentIndex index00_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index00);
std::cout << "index00 reduced : " << index00_reduced << std::endl;
mpc::core::TensorRank2ComponentIndex index01_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index01);
std::cout << "index01 reduced : " << index01_reduced << std::endl;
mpc::core::TensorRank2ComponentIndex index02_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index02);
std::cout << "index02 reduced : " << index02_reduced << std::endl;
mpc::core::TensorRank2ComponentIndex index10_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index10);
std::cout << "index10 reduced : " << index10_reduced << std::endl;
mpc::core::TensorRank2ComponentIndex index11_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index11);
std::cout << "index11 reduced : " << index11_reduced << std::endl;
mpc::core::TensorRank2ComponentIndex index12_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index12);
std::cout << "index12 reduced : " << index12_reduced << std::endl;
mpc::core::TensorRank2ComponentIndex index20_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index20);
std::cout << "index20 reduced : " << index20_reduced << std::endl;
mpc::core::TensorRank2ComponentIndex index21_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index21);
std::cout << "index21 reduced : " << index21_reduced << std::endl;
mpc::core::TensorRank2ComponentIndex index22_reduced = mpc::core::ReducedTensorRank2ComponentIndex(index22);
std::cout << "index22 reduced : " << index22_reduced << std::endl;
```
Output

    index00 reduced : [0,0]
    index01 reduced : [0,1]
    index02 reduced : [0,2]
    index10 reduced : [0,1]
    index11 reduced : [1,1]
    index12 reduced : [1,2]
    index20 reduced : [0,2]
    index21 reduced : [1,2]
    index22 reduced : [2,2]

Now for the fun stuff!  MPC relies heavily on template specializations and uses compile-time computations to achieve optimization and (in my opinion equally important) error handling using the c++ type system...  
The preferred method for creating component indexes is to use the templated form prefixed by the letter C; the major difference is that the member functions that retieve the index values CAN be used as template parameter values and therefore can be used for compile-time computation or compile-time optimization via selection in the form of user-defined specialization...
```cpp
mpc::core::CTensorRank2ComponentIndex<0,0> cindex00 = mpc::core::CTensorRank2ComponentIndex<0,0>();
auto ctest00 = mpcexamples::IntTypeParameterValueTest<cindex00.FirstIndex()>();
std::cout << "ctest00 FirstIndex() : " << ctest00 << std::endl;

mpc::core::CTensorRank2ComponentIndex<0,1> cindex01 = mpc::core::CTensorRank2ComponentIndex<0,1>();
auto ctest01 = mpcexamples::IntTypeParameterValueTest<cindex01.FirstIndex()>();
std::cout << "ctest01 FirstIndex() : " << ctest01 << std::endl;

mpc::core::CTensorRank2ComponentIndex<0,2> cindex02 = mpc::core::CTensorRank2ComponentIndex<0,2>();
auto ctest02 = mpcexamples::IntTypeParameterValueTest<cindex02.FirstIndex()>();
std::cout << "ctest02 FirstIndex() : " << ctest02 << std::endl;

mpc::core::CTensorRank2ComponentIndex<1,0> cindex10 = mpc::core::CTensorRank2ComponentIndex<1,0>();
auto ctest10 = mpcexamples::IntTypeParameterValueTest<cindex10.FirstIndex()>();
std::cout << "ctest10 FirstIndex() : " << ctest10 << std::endl;

mpc::core::CTensorRank2ComponentIndex<1,1> cindex11 = mpc::core::CTensorRank2ComponentIndex<1,1>();
auto ctest11 = mpcexamples::IntTypeParameterValueTest<cindex11.FirstIndex()>();
std::cout << "ctest11 FirstIndex() : " << ctest11 << std::endl;

mpc::core::CTensorRank2ComponentIndex<1,2> cindex12 = mpc::core::CTensorRank2ComponentIndex<1,2>();
auto ctest12 = mpcexamples::IntTypeParameterValueTest<cindex12.FirstIndex()>();
std::cout << "ctest12 FirstIndex() : " << ctest12 << std::endl;

mpc::core::CTensorRank2ComponentIndex<2,0> cindex20 = mpc::core::CTensorRank2ComponentIndex<2,0>();
auto ctest20 = mpcexamples::IntTypeParameterValueTest<cindex20.FirstIndex()>();
std::cout << "ctest20 FirstIndex() : " << ctest20 << std::endl;

mpc::core::CTensorRank2ComponentIndex<2,1> cindex21 = mpc::core::CTensorRank2ComponentIndex<2,1>();
auto ctest21 = mpcexamples::IntTypeParameterValueTest<cindex21.FirstIndex()>();
std::cout << "ctest21 FirstIndex() : " << ctest21 << std::endl;

mpc::core::CTensorRank2ComponentIndex<2,2> cindex22 = mpc::core::CTensorRank2ComponentIndex<2,2>();
auto ctest22 = mpcexamples::IntTypeParameterValueTest<cindex22.FirstIndex()>();
std::cout << "ctest22 FirstIndex() : " << ctest22 << std::endl;
```
Output

    ctest00 FirstIndex() : using parameter type int and value 0
    ctest01 FirstIndex() : using parameter type int and value 0
    ctest02 FirstIndex() : using parameter type int and value 0
    ctest10 FirstIndex() : using parameter type int and value 1
    ctest11 FirstIndex() : using parameter type int and value 1
    ctest12 FirstIndex() : using parameter type int and value 1
    ctest20 FirstIndex() : using parameter type int and value 2
    ctest21 FirstIndex() : using parameter type int and value 2
    ctest22 FirstIndex() : using parameter type int and value 2

overloaded operators
```cpp
// I=0, J=0
std::cout << "cindex : " << cindex00 << " == " << cindex11 << " : " << (cindex00 == cindex11) << std::endl;
std::cout << "cindex : " << cindex00 << " != " << cindex11 << " : " << (cindex00 != cindex11) << std::endl;
std::cout << "cindex : " << cindex00 << " <  " << cindex11 << " : " << (cindex00 < cindex11) << std::endl;
std::cout << "cindex : " << cindex00 << " >  " << cindex11 << " : " << (cindex00 > cindex11) << std::endl;
std::cout << "cindex : " << cindex00 << " <= " << cindex11 << " : " << (cindex00 <= cindex11) << std::endl;
std::cout << "cindex : " << cindex00 << " >= " << cindex11 << " : " << (cindex00 >= cindex11) << std::endl;

// I=0, J=1
std::cout << "cindex : " << cindex01 << " == " << cindex11 << " : " << (cindex01 == cindex11) << std::endl;
std::cout << "cindex : " << cindex01 << " != " << cindex11 << " : " << (cindex01 != cindex11) << std::endl;
std::cout << "cindex : " << cindex01 << " <  " << cindex11 << " : " << (cindex01 < cindex11) << std::endl;
std::cout << "cindex : " << cindex01 << " >  " << cindex11 << " : " << (cindex01 > cindex11) << std::endl;
std::cout << "cindex : " << cindex01 << " <= " << cindex11 << " : " << (cindex01 <= cindex11) << std::endl;
std::cout << "cindex : " << cindex01 << " >= " << cindex11 << " : " << (cindex01 >= cindex11) << std::endl;

// I=0, J=2
std::cout << "cindex : " << cindex02 << " == " << cindex11 << " : " << (cindex02 == cindex11) << std::endl;
std::cout << "cindex : " << cindex02 << " != " << cindex11 << " : " << (cindex02 != cindex11) << std::endl;
std::cout << "cindex : " << cindex02 << " <  " << cindex11 << " : " << (cindex02 < cindex11) << std::endl;
std::cout << "cindex : " << cindex02 << " >  " << cindex11 << " : " << (cindex02 > cindex11) << std::endl;
std::cout << "cindex : " << cindex02 << " <= " << cindex11 << " : " << (cindex02 <= cindex11) << std::endl;
std::cout << "cindex : " << cindex02 << " >= " << cindex11 << " : " << (cindex02 >= cindex11) << std::endl;

// I=1, J=0
std::cout << "cindex : " << cindex10 << " == " << cindex11 << " : " << (cindex10 == cindex11) << std::endl;
std::cout << "cindex : " << cindex10 << " != " << cindex11 << " : " << (cindex10 != cindex11) << std::endl;
std::cout << "cindex : " << cindex10 << " <  " << cindex11 << " : " << (cindex10 < cindex11) << std::endl;
std::cout << "cindex : " << cindex10 << " >  " << cindex11 << " : " << (cindex10 > cindex11) << std::endl;
std::cout << "cindex : " << cindex10 << " <= " << cindex11 << " : " << (cindex10 <= cindex11) << std::endl;
std::cout << "cindex : " << cindex10 << " >= " << cindex11 << " : " << (cindex10 >= cindex11) << std::endl;

// I=1, J=1
std::cout << "cindex : " << cindex11 << " == " << cindex11 << " : " << (cindex11 == cindex11) << std::endl;
std::cout << "cindex : " << cindex11 << " != " << cindex11 << " : " << (cindex11 != cindex11) << std::endl;
std::cout << "cindex : " << cindex11 << " <  " << cindex11 << " : " << (cindex11 < cindex11) << std::endl;
std::cout << "cindex : " << cindex11 << " >  " << cindex11 << " : " << (cindex11 > cindex11) << std::endl;
std::cout << "cindex : " << cindex11 << " <= " << cindex11 << " : " << (cindex11 <= cindex11) << std::endl;
std::cout << "cindex : " << cindex11 << " >= " << cindex11 << " : " << (cindex11 >= cindex11) << std::endl;

// I=1, J=2
std::cout << "cindex : " << cindex12 << " == " << cindex11 << " : " << (cindex12 == cindex11) << std::endl;
std::cout << "cindex : " << cindex12 << " != " << cindex11 << " : " << (cindex12 != cindex11) << std::endl;
std::cout << "cindex : " << cindex12 << " <  " << cindex11 << " : " << (cindex12 < cindex11) << std::endl;
std::cout << "cindex : " << cindex12 << " >  " << cindex11 << " : " << (cindex12 > cindex11) << std::endl;
std::cout << "cindex : " << cindex12 << " <= " << cindex11 << " : " << (cindex12 <= cindex11) << std::endl;
std::cout << "cindex : " << cindex12 << " >= " << cindex11 << " : " << (cindex12 >= cindex11) << std::endl;

// I=2, J=0
std::cout << "cindex : " << cindex20 << " == " << cindex11 << " : " << (cindex20 == cindex11) << std::endl;
std::cout << "cindex : " << cindex20 << " != " << cindex11 << " : " << (cindex20 != cindex11) << std::endl;
std::cout << "cindex : " << cindex20 << " <  " << cindex11 << " : " << (cindex20 < cindex11) << std::endl;
std::cout << "cindex : " << cindex20 << " >  " << cindex11 << " : " << (cindex20 > cindex11) << std::endl;
std::cout << "cindex : " << cindex20 << " <= " << cindex11 << " : " << (cindex20 <= cindex11) << std::endl;
std::cout << "cindex : " << cindex20 << " >= " << cindex11 << " : " << (cindex20 >= cindex11) << std::endl;

// I=2, J=1
std::cout << "cindex : " << cindex21 << " == " << cindex11 << " : " << (cindex21 == cindex11) << std::endl;
std::cout << "cindex : " << cindex21 << " != " << cindex11 << " : " << (cindex21 != cindex11) << std::endl;
std::cout << "cindex : " << cindex21 << " <  " << cindex11 << " : " << (cindex21 < cindex11) << std::endl;
std::cout << "cindex : " << cindex21 << " >  " << cindex11 << " : " << (cindex21 > cindex11) << std::endl;
std::cout << "cindex : " << cindex21 << " <= " << cindex11 << " : " << (cindex21 <= cindex11) << std::endl;
std::cout << "cindex : " << cindex21 << " >= " << cindex11 << " : " << (cindex21 >= cindex11) << std::endl;

// I=2, J=2
std::cout << "cindex : " << cindex22 << " == " << cindex11 << " : " << (cindex22 == cindex11) << std::endl;
std::cout << "cindex : " << cindex22 << " != " << cindex11 << " : " << (cindex22 != cindex11) << std::endl;
std::cout << "cindex : " << cindex22 << " <  " << cindex11 << " : " << (cindex22 < cindex11) << std::endl;
std::cout << "cindex : " << cindex22 << " >  " << cindex11 << " : " << (cindex22 > cindex11) << std::endl;
std::cout << "cindex : " << cindex22 << " <= " << cindex11 << " : " << (cindex22 <= cindex11) << std::endl;
std::cout << "cindex : " << cindex22 << " >= " << cindex11 << " : " << (cindex22 >= cindex11) << std::endl;
```
Output

    cindex : [0,0] == [1,1] : false
    cindex : [0,0] != [1,1] : true
    cindex : [0,0] <  [1,1] : true
    cindex : [0,0] >  [1,1] : false
    cindex : [0,0] <= [1,1] : true
    cindex : [0,0] >= [1,1] : false
    cindex : [0,1] == [1,1] : false
    cindex : [0,1] != [1,1] : true
    cindex : [0,1] <  [1,1] : true
    cindex : [0,1] >  [1,1] : false
    cindex : [0,1] <= [1,1] : true
    cindex : [0,1] >= [1,1] : false
    cindex : [0,2] == [1,1] : false
    cindex : [0,2] != [1,1] : true
    cindex : [0,2] <  [1,1] : true
    cindex : [0,2] >  [1,1] : false
    cindex : [0,2] <= [1,1] : true
    cindex : [0,2] >= [1,1] : false
    cindex : [1,0] == [1,1] : false
    cindex : [1,0] != [1,1] : true
    cindex : [1,0] <  [1,1] : true
    cindex : [1,0] >  [1,1] : false
    cindex : [1,0] <= [1,1] : true
    cindex : [1,0] >= [1,1] : false
    cindex : [1,1] == [1,1] : true
    cindex : [1,1] != [1,1] : false
    cindex : [1,1] <  [1,1] : false
    cindex : [1,1] >  [1,1] : false
    cindex : [1,1] <= [1,1] : true
    cindex : [1,1] >= [1,1] : true
    cindex : [1,2] == [1,1] : false
    cindex : [1,2] != [1,1] : true
    cindex : [1,2] <  [1,1] : false
    cindex : [1,2] >  [1,1] : true
    cindex : [1,2] <= [1,1] : false
    cindex : [1,2] >= [1,1] : true
    cindex : [2,0] == [1,1] : false
    cindex : [2,0] != [1,1] : true
    cindex : [2,0] <  [1,1] : false
    cindex : [2,0] >  [1,1] : true
    cindex : [2,0] <= [1,1] : false
    cindex : [2,0] >= [1,1] : true
    cindex : [2,1] == [1,1] : false
    cindex : [2,1] != [1,1] : true
    cindex : [2,1] <  [1,1] : false
    cindex : [2,1] >  [1,1] : true
    cindex : [2,1] <= [1,1] : false
    cindex : [2,1] >= [1,1] : true
    cindex : [2,2] == [1,1] : false
    cindex : [2,2] != [1,1] : true
    cindex : [2,2] <  [1,1] : false
    cindex : [2,2] >  [1,1] : true
    cindex : [2,2] <= [1,1] : false
    cindex : [2,2] >= [1,1] : true

Where compile-time computation is not needed and "plain" TensorRank2ComponentIndex or TensorRank4ComponentIndex will suffice, a static_cast<T> can be used to cast the CTensorRank2ComponentIndex or CTensorRank4ComponentIndex to a plain TensorRankNComponentIndex<N>.  For example ...
```cpp
std::cout << "casting to normal index for rank 2..." << std::endl;
mpc::core::TensorRank2ComponentIndex index00cast = static_cast<mpc::core::TensorRank2ComponentIndex>(mpc::core::CTensorRank2ComponentIndex<0,0>());
std::cout << "index00cast : " << index00cast << std::endl;

mpc::core::TensorRank2ComponentIndex index00castagain = static_cast<mpc::core::TensorRank2ComponentIndex>(cindex00);
std::cout << "index00 cast from cindex00 : " << index00castagain << std::endl;

mpc::core::TensorRank2ComponentIndex index01cast = static_cast<mpc::core::TensorRank2ComponentIndex>(mpc::core::CTensorRank2ComponentIndex<0,1>());
std::cout << "index01cast : " << index01cast << std::endl;

mpc::core::TensorRank2ComponentIndex index01castagain = static_cast<mpc::core::TensorRank2ComponentIndex>(cindex01);
std::cout << "index01 cast from cindex01 : " << index01castagain << std::endl;

mpc::core::TensorRank2ComponentIndex index02cast = static_cast<mpc::core::TensorRank2ComponentIndex>(mpc::core::CTensorRank2ComponentIndex<0,2>());
std::cout << "index02cast : " << index02cast << std::endl;

mpc::core::TensorRank2ComponentIndex index02castagain = static_cast<mpc::core::TensorRank2ComponentIndex>(cindex02);
std::cout << "index02 cast from cindex02 : " << index02castagain << std::endl;
```
Output

    casting to normal index for rank 2...
    index00cast : [0,0]
    index00 cast from cindex00 : [0,0]
    index01cast : [0,1]
    index01 cast from cindex01 : [0,1]
    index02cast : [0,2]
    index02 cast from cindex02 : [0,2]

Currently, MPC provides two predicates (callable that returns a value testable as a bool; see [Predicate](https://en.cppreference.com/w/cpp/named_req/Predicate) for <code>TensorRankNCompoentIndex<></code> where N is either 2 or 4: ...IsAlias(...) and ...HasAlias(...).  The definiton of aliases is defined by symmetry...

```cpp
bool cindexXX_has_alias;
bool cindexXX_is_alias_cindexXX;
std::cout << "\n compile-time predicates" << std::endl;

// cindex00
cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex00);
std::cout << cindex00 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex00);
std::cout << cindex00 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex01);
std::cout << cindex00 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex02);
std::cout << cindex00 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex10);
std::cout << cindex00 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex11);
std::cout << cindex00 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex12);
std::cout << cindex00 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex20);
std::cout << cindex00 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex21);
std::cout << cindex00 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex00,cindex22);
std::cout << cindex00 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

// cindex01
cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex01);
std::cout << cindex01 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex00);
std::cout << cindex01 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex01);
std::cout << cindex01 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex02);
std::cout << cindex01 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex10);
std::cout << cindex01 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex11);
std::cout << cindex01 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex12);
std::cout << cindex01 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex20);
std::cout << cindex01 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex21);
std::cout << cindex01 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex01,cindex22);
std::cout << cindex01 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

// cindex02
cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex02);
std::cout << cindex02 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex00);
std::cout << cindex02 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex01);
std::cout << cindex02 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex02);
std::cout << cindex02 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex10);
std::cout << cindex02 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex11);
std::cout << cindex02 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex12);
std::cout << cindex02 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex20);
std::cout << cindex02 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex21);
std::cout << cindex02 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex02,cindex22);
std::cout << cindex02 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

// cindex10
cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex10);
std::cout << cindex10 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex00);
std::cout << cindex10 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex01);
std::cout << cindex10 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex02);
std::cout << cindex10 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex10);
std::cout << cindex10 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex11);
std::cout << cindex10 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex12);
std::cout << cindex10 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex20);
std::cout << cindex10 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex21);
std::cout << cindex10 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex10,cindex22);
std::cout << cindex10 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

// cindex11
cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex11);
std::cout << cindex11 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex00);
std::cout << cindex11 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex01);
std::cout << cindex11 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex02);
std::cout << cindex11 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex10);
std::cout << cindex11 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex11);
std::cout << cindex11 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex12);
std::cout << cindex11 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex20);
std::cout << cindex11 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex21);
std::cout << cindex11 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex11,cindex22);
std::cout << cindex11 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

// cindex12
cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex12);
std::cout << cindex12 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex00);
std::cout << cindex12 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex01);
std::cout << cindex12 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex02);
std::cout << cindex12 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex10);
std::cout << cindex12 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex11);
std::cout << cindex12 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex12);
std::cout << cindex12 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex20);
std::cout << cindex12 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex21);
std::cout << cindex12 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex12,cindex22);
std::cout << cindex12 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

// cindex20
cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex20);
std::cout << cindex20 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex00);
std::cout << cindex20 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex01);
std::cout << cindex20 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex02);
std::cout << cindex20 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex10);
std::cout << cindex20 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex11);
std::cout << cindex20 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex12);
std::cout << cindex20 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex20);
std::cout << cindex20 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex21);
std::cout << cindex20 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex20,cindex22);
std::cout << cindex20 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

// cindex21
cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex21);
std::cout << cindex21 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex00);
std::cout << cindex21 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex01);
std::cout << cindex21 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex02);
std::cout << cindex21 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex10);
std::cout << cindex21 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex11);
std::cout << cindex21 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex12);
std::cout << cindex21 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex20);
std::cout << cindex21 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex21);
std::cout << cindex21 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex21,cindex22);
std::cout << cindex21 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;

// cindex22
cindexXX_has_alias = mpc::core::CComponentIndexHasAlias(cindex22);
std::cout << cindex22 << " cindex has alias ? : " << cindexXX_has_alias << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex00);
std::cout << cindex22 << " c is_alias " << cindex00 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex01);
std::cout << cindex22 << " c is_alias " << cindex01 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex02);
std::cout << cindex22 << " c is_alias " << cindex02 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex10);
std::cout << cindex22 << " c is_alias " << cindex10 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex11);
std::cout << cindex22 << " c is_alias " << cindex11 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex12);
std::cout << cindex22 << " c is_alias " << cindex12 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex20);
std::cout << cindex22 << " c is_alias " << cindex20 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex21);
std::cout << cindex22 << " c is_alias " << cindex21 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
cindexXX_is_alias_cindexXX = mpc::core::CComponentIndexIsAlias(cindex22,cindex22);
std::cout << cindex22 << " c is_alias " << cindex22 << " ? " << cindexXX_is_alias_cindexXX << std::endl;
```
Output

    compile-time predicates
    [0,0] cindex has alias ? : false
    [0,0] c is_alias [0,0] ? true
    [0,0] c is_alias [0,1] ? false
    [0,0] c is_alias [0,2] ? false
    [0,0] c is_alias [1,0] ? false
    [0,0] c is_alias [1,1] ? false
    [0,0] c is_alias [1,2] ? false
    [0,0] c is_alias [2,0] ? false
    [0,0] c is_alias [2,1] ? false
    [0,0] c is_alias [2,2] ? false
    [0,1] cindex has alias ? : true
    [0,1] c is_alias [0,0] ? false
    [0,1] c is_alias [0,1] ? true
    [0,1] c is_alias [0,2] ? false
    [0,1] c is_alias [1,0] ? true
    [0,1] c is_alias [1,1] ? false
    [0,1] c is_alias [1,2] ? false
    [0,1] c is_alias [2,0] ? false
    [0,1] c is_alias [2,1] ? false
    [0,1] c is_alias [2,2] ? false
    [0,2] cindex has alias ? : true
    [0,2] c is_alias [0,0] ? false
    [0,2] c is_alias [0,1] ? false
    [0,2] c is_alias [0,2] ? true
    [0,2] c is_alias [1,0] ? false
    [0,2] c is_alias [1,1] ? false
    [0,2] c is_alias [1,2] ? false
    [0,2] c is_alias [2,0] ? true
    [0,2] c is_alias [2,1] ? false
    [0,2] c is_alias [2,2] ? false
    [1,0] cindex has alias ? : true
    [1,0] c is_alias [0,0] ? false
    [1,0] c is_alias [0,1] ? true
    [1,0] c is_alias [0,2] ? false
    [1,0] c is_alias [1,0] ? true
    [1,0] c is_alias [1,1] ? false
    [1,0] c is_alias [1,2] ? false
    [1,0] c is_alias [2,0] ? false
    [1,0] c is_alias [2,1] ? false
    [1,0] c is_alias [2,2] ? false
    [1,1] cindex has alias ? : false
    [1,1] c is_alias [0,0] ? false
    [1,1] c is_alias [0,1] ? false
    [1,1] c is_alias [0,2] ? false
    [1,1] c is_alias [1,0] ? false
    [1,1] c is_alias [1,1] ? true
    [1,1] c is_alias [1,2] ? false
    [1,1] c is_alias [2,0] ? false
    [1,1] c is_alias [2,1] ? false
    [1,1] c is_alias [2,2] ? false
    [1,2] cindex has alias ? : true
    [1,2] c is_alias [0,0] ? false
    [1,2] c is_alias [0,1] ? false
    [1,2] c is_alias [0,2] ? false
    [1,2] c is_alias [1,0] ? false
    [1,2] c is_alias [1,1] ? false
    [1,2] c is_alias [1,2] ? true
    [1,2] c is_alias [2,0] ? false
    [1,2] c is_alias [2,1] ? true
    [1,2] c is_alias [2,2] ? false
    [2,0] cindex has alias ? : true
    [2,0] c is_alias [0,0] ? false
    [2,0] c is_alias [0,1] ? false
    [2,0] c is_alias [0,2] ? true
    [2,0] c is_alias [1,0] ? false
    [2,0] c is_alias [1,1] ? false
    [2,0] c is_alias [1,2] ? false
    [2,0] c is_alias [2,0] ? true
    [2,0] c is_alias [2,1] ? false
    [2,0] c is_alias [2,2] ? false
    [2,1] cindex has alias ? : true
    [2,1] c is_alias [0,0] ? false
    [2,1] c is_alias [0,1] ? false
    [2,1] c is_alias [0,2] ? false
    [2,1] c is_alias [1,0] ? false
    [2,1] c is_alias [1,1] ? false
    [2,1] c is_alias [1,2] ? true
    [2,1] c is_alias [2,0] ? false
    [2,1] c is_alias [2,1] ? true
    [2,1] c is_alias [2,2] ? false
    [2,2] cindex has alias ? : false
    [2,2] c is_alias [0,0] ? false
    [2,2] c is_alias [0,1] ? false
    [2,2] c is_alias [0,2] ? false
    [2,2] c is_alias [1,0] ? false
    [2,2] c is_alias [1,1] ? false
    [2,2] c is_alias [1,2] ? false
    [2,2] c is_alias [2,0] ? false
    [2,2] c is_alias [2,1] ? false
    [2,2] c is_alias [2,2] ? true

---

A component index for a tensor of rank 4 is also defined in <code>mpc/core/tensorcomponentindex.h</code> and can be constructed in a similar manner to a tensor component of rank 2.  It also has a constexpr constructor and constexpr member functions to retrieve the index values.

[mpcexamples::mpcTensorRank4ComponentIndex()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_tensorrank4componentindex.cpp)

```cpp
mpc::core::TensorRankNComponentIndex<4> index0000 = mpc::core::TensorRankNComponentIndex<4>(0,0,0,0);
std::cout << "index(0,0,0,0) : " << index0000 << std::endl;
std::cout << "FirstIndex() :   " << index0000.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index0000.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index0000.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index0000.FourthIndex() << std::endl;
std::cout << index0000 << " index using operator [0] : " << index0000[0] << std::endl;
std::cout << index0000 << " index using operator [1] : " << index0000[1] << std::endl;
std::cout << index0000 << " index using operator [2] : " << index0000[2] << std::endl;
std::cout << index0000 << " index using operator [3] : " << index0000[3] << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0001 = mpc::core::TensorRankNComponentIndex<4>(0,0,0,1);
std::cout << "index(0,0,0,1) : " << index0001 << std::endl;
std::cout << "FirstIndex() :   " << index0001.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index0001.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index0001.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index0001.FourthIndex() << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0002 = mpc::core::TensorRankNComponentIndex<4>(0,0,0,2);
std::cout << "index(0,0,0,2) : " << index0002 << std::endl;
std::cout << "FirstIndex() :   " << index0002.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index0002.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index0002.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index0002.FourthIndex() << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0010 = mpc::core::TensorRankNComponentIndex<4>(0,0,1,0);
std::cout << "index(0,0,1,0) : " << index0010 << std::endl;
std::cout << "FirstIndex() :   " << index0010.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index0010.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index0010.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index0010.FourthIndex() << std::endl;
std::cout << index0010 << " index using operator [0] : " << index0010[0] << std::endl;
std::cout << index0010 << " index using operator [1] : " << index0010[1] << std::endl;
std::cout << index0010 << " index using operator [2] : " << index0010[2] << std::endl;
std::cout << index0010 << " index using operator [3] : " << index0010[3] << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0011 = mpc::core::TensorRankNComponentIndex<4>(0,0,1,1);
std::cout << "index(0,0,1,1) : " << index0011 << std::endl;
std::cout << "FirstIndex() :   " << index0011.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index0011.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index0011.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index0011.FourthIndex() << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0012 = mpc::core::TensorRankNComponentIndex<4>(0,0,1,2);
std::cout << "index(0,0,1,2) : " << index0012 << std::endl;
std::cout << "FirstIndex() :   " << index0012.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index0012.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index0012.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index0012.FourthIndex() << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0020 = mpc::core::TensorRankNComponentIndex<4>(0,0,2,0);
std::cout << "index(0,0,2,0) : " << index0020 << std::endl;
std::cout << "FirstIndex() :   " << index0020.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index0020.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index0020.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index0020.FourthIndex() << std::endl;
std::cout << index0020 << " index using operator [0] : " << index0020[0] << std::endl;
std::cout << index0020 << " index using operator [1] : " << index0020[1] << std::endl;
std::cout << index0020 << " index using operator [2] : " << index0020[2] << std::endl;
std::cout << index0020 << " index using operator [3] : " << index0020[3] << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0021 = mpc::core::TensorRankNComponentIndex<4>(0,0,2,1);
std::cout << "index(0,0,2,1) : " << index0021 << std::endl;
std::cout << "FirstIndex() :   " << index0021.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index0021.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index0021.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index0021.FourthIndex() << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0022 = mpc::core::TensorRankNComponentIndex<4>(0,0,2,2);
std::cout << "index(0,0,2,2) : " << index0022 << std::endl;
std::cout << "FirstIndex() :   " << index0022.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index0022.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index0022.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index0022.FourthIndex() << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0100 = mpc::core::TensorRankNComponentIndex<4>(0,1,0,0);
std::cout << "index(0,1,0,0) : " << index0100 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0101 = mpc::core::TensorRankNComponentIndex<4>(0,1,0,1);
std::cout << "index(0,1,0,1) : " << index0101 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0102 = mpc::core::TensorRankNComponentIndex<4>(0,1,0,2);
std::cout << "index(0,1,0,2) : " << index0102 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0110 = mpc::core::TensorRankNComponentIndex<4>(0,1,1,0);
std::cout << "index(0,1,1,0) : " << index0110 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0111 = mpc::core::TensorRankNComponentIndex<4>(0,1,1,1);
std::cout << "index(0,1,1,1) : " << index0111 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0112 = mpc::core::TensorRankNComponentIndex<4>(0,1,1,2);
std::cout << "index(0,1,1,2) : " << index0112 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0120 = mpc::core::TensorRankNComponentIndex<4>(0,1,2,0);
std::cout << "index(0,1,2,0) : " << index0120 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0121 = mpc::core::TensorRankNComponentIndex<4>(0,1,2,1);
std::cout << "index(0,1,2,1) : " << index0121 << std::endl;
std::cout << "FirstIndex() :   " << index0121.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index0121.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index0121.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index0121.FourthIndex() << std::endl;
std::cout << index0121 << " index using operator [0] : " << index0121[0] << std::endl;
std::cout << index0121 << " index using operator [1] : " << index0121[1] << std::endl;
std::cout << index0121 << " index using operator [2] : " << index0121[2] << std::endl;
std::cout << index0121 << " index using operator [3] : " << index0121[3] << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0122 = mpc::core::TensorRankNComponentIndex<4>(0,1,2,2);
std::cout << "index(0,1,2,2) : " << index0122 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0200 = mpc::core::TensorRankNComponentIndex<4>(0,2,0,0);
std::cout << "index(0,2,0,0) : " << index0200 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0201 = mpc::core::TensorRankNComponentIndex<4>(0,2,0,1);
std::cout << "index(0,2,0,1) : " << index0201 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0202 = mpc::core::TensorRankNComponentIndex<4>(0,2,0,2);
std::cout << "index(0,2,0,2) : " << index0202 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0210 = mpc::core::TensorRankNComponentIndex<4>(0,2,1,0);
std::cout << "index(0,2,1,0) : " << index0210 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0211 = mpc::core::TensorRankNComponentIndex<4>(0,2,1,1);
std::cout << "index(0,2,1,1) : " << index0211 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0212 = mpc::core::TensorRankNComponentIndex<4>(0,2,1,2);
std::cout << "index(0,2,1,2) : " << index0212 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0220 = mpc::core::TensorRankNComponentIndex<4>(0,2,2,0);
std::cout << "index(0,2,2,0) : " << index0220 << std::endl;
std::cout << "FirstIndex() :   " << index0220.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index0220.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index0220.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index0220.FourthIndex() << std::endl;
std::cout << index0220 << " index using operator [0] : " << index0220[0] << std::endl;
std::cout << index0220 << " index using operator [1] : " << index0220[1] << std::endl;
std::cout << index0220 << " index using operator [2] : " << index0220[2] << std::endl;
std::cout << index0220 << " index using operator [3] : " << index0220[3] << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0221 = mpc::core::TensorRankNComponentIndex<4>(0,2,2,1);
std::cout << "index(0,2,2,1) : " << index0221 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index0222 = mpc::core::TensorRankNComponentIndex<4>(0,2,2,2);
std::cout << "index(0,2,2,2) : " << index0222 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1000 = mpc::core::TensorRankNComponentIndex<4>(1,0,0,0);
std::cout << "index(1,0,0,0) : " << index1000 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1001 = mpc::core::TensorRankNComponentIndex<4>(1,0,0,1);
std::cout << "index(1,0,0,1) : " << index1001 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1002 = mpc::core::TensorRankNComponentIndex<4>(1,0,0,2);
std::cout << "index(1,0,0,2) : " << index1002 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1010 = mpc::core::TensorRankNComponentIndex<4>(1,0,1,0);
std::cout << "index(1,0,1,0) : " << index1010 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1011 = mpc::core::TensorRankNComponentIndex<4>(1,0,1,1);
std::cout << "index(1,0,1,1) : " << index1011 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1012 = mpc::core::TensorRankNComponentIndex<4>(1,0,1,2);
std::cout << "index(1,0,1,2) : " << index1012 << std::endl;
std::cout << "FirstIndex() :   " << index1012.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index1012.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index1012.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index1012.FourthIndex() << std::endl;
std::cout << index1012 << " index using operator [0] : " << index1012[0] << std::endl;
std::cout << index1012 << " index using operator [1] : " << index1012[1] << std::endl;
std::cout << index1012 << " index using operator [2] : " << index1012[2] << std::endl;
std::cout << index1012 << " index using operator [3] : " << index1012[3] << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1020 = mpc::core::TensorRankNComponentIndex<4>(1,0,2,0);
std::cout << "index(1,0,2,0) : " << index1020 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1021 = mpc::core::TensorRankNComponentIndex<4>(1,0,2,1);
std::cout << "index(1,0,2,1) : " << index1021 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1022 = mpc::core::TensorRankNComponentIndex<4>(1,0,2,2);
std::cout << "index(1,0,2,2) : " << index1022 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1100 = mpc::core::TensorRankNComponentIndex<4>(1,1,0,0);
std::cout << "index(1,1,0,0) : " << index1100 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1101 = mpc::core::TensorRankNComponentIndex<4>(1,1,0,1);
std::cout << "index(1,1,0,1) : " << index1101 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1102 = mpc::core::TensorRankNComponentIndex<4>(1,1,0,2);
std::cout << "index(1,1,0,2) : " << index1102 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1110 = mpc::core::TensorRankNComponentIndex<4>(1,1,1,0);
std::cout << "index(1,1,1,0) : " << index1110 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1111 = mpc::core::TensorRankNComponentIndex<4>(1,1,1,1);
std::cout << "index(1,1,1,1) : " << index1111 << std::endl;
std::cout << "FirstIndex() :   " << index1111.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index1111.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index1111.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index1111.FourthIndex() << std::endl;
std::cout << index1111 << " index using operator [0] : " << index1111[0] << std::endl;
std::cout << index1111 << " index using operator [1] : " << index1111[1] << std::endl;
std::cout << index1111 << " index using operator [2] : " << index1111[2] << std::endl;
std::cout << index1111 << " index using operator [3] : " << index1111[3] << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1112 = mpc::core::TensorRankNComponentIndex<4>(1,1,1,2);
std::cout << "index(1,1,1,2) : " << index1112 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1120 = mpc::core::TensorRankNComponentIndex<4>(1,1,2,0);
std::cout << "index(1,1,2,0) : " << index1120 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1121 = mpc::core::TensorRankNComponentIndex<4>(1,1,2,1);
std::cout << "index(1,1,2,1) : " << index1121 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1122 = mpc::core::TensorRankNComponentIndex<4>(1,1,2,2);
std::cout << "index(1,1,2,2) : " << index1122 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1200 = mpc::core::TensorRankNComponentIndex<4>(1,2,0,0);
std::cout << "index(1,2,0,0) : " << index1200 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1201 = mpc::core::TensorRankNComponentIndex<4>(1,2,0,1);
std::cout << "index(1,2,0,1) : " << index1201 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1202 = mpc::core::TensorRankNComponentIndex<4>(1,2,0,2);
std::cout << "index(1,2,0,2) : " << index1202 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1210 = mpc::core::TensorRankNComponentIndex<4>(1,2,1,0);
std::cout << "index(1,2,1,0) : " << index1210 << std::endl;
std::cout << "FirstIndex() :   " << index1210.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index1210.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index1210.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index1210.FourthIndex() << std::endl;
std::cout << index1210 << " index using operator [0] : " << index1210[0] << std::endl;
std::cout << index1210 << " index using operator [1] : " << index1210[1] << std::endl;
std::cout << index1210 << " index using operator [2] : " << index1210[2] << std::endl;
std::cout << index1210 << " index using operator [3] : " << index1210[3] << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1211 = mpc::core::TensorRankNComponentIndex<4>(1,2,1,1);
std::cout << "index(1,2,1,1) : " << index1211 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1212 = mpc::core::TensorRankNComponentIndex<4>(1,2,1,2);
std::cout << "index(1,2,1,2) : " << index1212 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1220 = mpc::core::TensorRankNComponentIndex<4>(1,2,2,0);
std::cout << "index(1,2,2,0) : " << index1220 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1221 = mpc::core::TensorRankNComponentIndex<4>(1,2,2,1);
std::cout << "index(1,2,2,1) : " << index1221 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index1222 = mpc::core::TensorRankNComponentIndex<4>(1,2,2,2);
std::cout << "index(1,2,2,2) : " << index1222 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2000 = mpc::core::TensorRankNComponentIndex<4>(2,0,0,0);
std::cout << "index(2,0,0,0) : " << index2000 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2001 = mpc::core::TensorRankNComponentIndex<4>(2,0,0,1);
std::cout << "index(2,0,0,1) : " << index2001 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2002 = mpc::core::TensorRankNComponentIndex<4>(2,0,0,2);
std::cout << "index(2,0,0,2) : " << index2002 << std::endl;
std::cout << "FirstIndex() :   " << index2002.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index2002.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index2002.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index2002.FourthIndex() << std::endl;
std::cout << index2002 << " index using operator [0] : " << index2002[0] << std::endl;
std::cout << index2002 << " index using operator [1] : " << index2002[1] << std::endl;
std::cout << index2002 << " index using operator [2] : " << index2002[2] << std::endl;
std::cout << index2002 << " index using operator [3] : " << index2002[3] << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2010 = mpc::core::TensorRankNComponentIndex<4>(2,0,1,0);
std::cout << "index(2,0,1,0) : " << index2010 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2011 = mpc::core::TensorRankNComponentIndex<4>(2,0,1,1);
std::cout << "index(2,0,1,1) : " << index2011 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2012 = mpc::core::TensorRankNComponentIndex<4>(2,0,1,2);
std::cout << "index(2,0,1,2) : " << index2012 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2020 = mpc::core::TensorRankNComponentIndex<4>(2,0,2,0);
std::cout << "index(2,0,2,0) : " << index2020 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2021 = mpc::core::TensorRankNComponentIndex<4>(2,0,2,1);
std::cout << "index(2,0,2,1) : " << index2021 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2022 = mpc::core::TensorRankNComponentIndex<4>(2,0,2,2);
std::cout << "index(2,0,2,2) : " << index2022 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2100 = mpc::core::TensorRankNComponentIndex<4>(2,1,0,0);
std::cout << "index(2,1,0,0) : " << index2100 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2101 = mpc::core::TensorRankNComponentIndex<4>(2,1,0,1);
std::cout << "index(2,1,0,1) : " << index2101 << std::endl;
std::cout << "FirstIndex() :   " << index2101.FirstIndex() << std::endl;
std::cout << "SecondIndex() :  " << index2101.SecondIndex() << std::endl;
std::cout << "ThirdIndex() :   " << index2101.ThirdIndex() << std::endl;
std::cout << "FourthIndex() :  " << index2101.FourthIndex() << std::endl;
std::cout << index2101 << " index using operator [0] : " << index2101[0] << std::endl;
std::cout << index2101 << " index using operator [1] : " << index2101[1] << std::endl;
std::cout << index2101 << " index using operator [2] : " << index2101[2] << std::endl;
std::cout << index2101 << " index using operator [3] : " << index2101[3] << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2102 = mpc::core::TensorRankNComponentIndex<4>(2,1,0,2);
std::cout << "index(2,1,0,2) : " << index2102 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2110 = mpc::core::TensorRankNComponentIndex<4>(2,1,1,0);
std::cout << "index(2,1,1,0) : " << index2110 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2111 = mpc::core::TensorRankNComponentIndex<4>(2,1,1,1);
std::cout << "index(2,1,1,1) : " << index2111 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2112 = mpc::core::TensorRankNComponentIndex<4>(2,1,1,2);
std::cout << "index(2,1,1,2) : " << index2112 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2120 = mpc::core::TensorRankNComponentIndex<4>(2,1,2,0);
std::cout << "index(2,1,2,0) : " << index2120 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2121 = mpc::core::TensorRankNComponentIndex<4>(2,1,2,1);
std::cout << "index(2,1,2,1) : " << index2121 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2122 = mpc::core::TensorRankNComponentIndex<4>(2,1,2,2);
std::cout << "index(2,1,2,2) : " << index2122 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2200 = mpc::core::TensorRankNComponentIndex<4>(2,2,0,0);
std::cout << "index(2,2,0,0) : " << index2200 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2201 = mpc::core::TensorRankNComponentIndex<4>(2,2,0,1);
std::cout << "index(2,2,0,1) : " << index2201 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2202 = mpc::core::TensorRankNComponentIndex<4>(2,2,0,2);
std::cout << "index(2,2,0,2) : " << index2202 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2210 = mpc::core::TensorRankNComponentIndex<4>(2,2,1,0);
std::cout << "index(2,2,1,0) : " << index2210 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2211 = mpc::core::TensorRankNComponentIndex<4>(2,2,1,1);
std::cout << "index(2,2,1,1) : " << index2211 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2212 = mpc::core::TensorRankNComponentIndex<4>(2,2,1,2);
std::cout << "index(2,2,1,2) : " << index2212 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2220 = mpc::core::TensorRankNComponentIndex<4>(2,2,2,0);
std::cout << "index(2,2,2,0) : " << index2220 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2221 = mpc::core::TensorRankNComponentIndex<4>(2,2,2,1);
std::cout << "index(2,2,2,1) : " << index2221 << std::endl;
mpc::core::TensorRankNComponentIndex<4> index2222 = mpc::core::TensorRankNComponentIndex<4>(2,2,2,2);
std::cout << "index(2,2,2,2) : " << index2222 << std::endl;
```
Output

    index(0,0,0,0) : [0,0,0,0]
    FirstIndex() :   0
    SecondIndex() :  0
    ThirdIndex() :   0
    FourthIndex() :  0
    [0,0,0,0] index using operator [0] : 0
    [0,0,0,0] index using operator [1] : 0
    [0,0,0,0] index using operator [2] : 0
    [0,0,0,0] index using operator [3] : 0
    index(0,0,0,1) : [0,0,0,1]
    FirstIndex() :   0
    SecondIndex() :  0
    ThirdIndex() :   0
    FourthIndex() :  1
    index(0,0,0,2) : [0,0,0,2]
    FirstIndex() :   0
    SecondIndex() :  0
    ThirdIndex() :   0
    FourthIndex() :  2
    index(0,0,1,0) : [0,0,1,0]
    FirstIndex() :   0
    SecondIndex() :  0
    ThirdIndex() :   1
    FourthIndex() :  0
    [0,0,1,0] index using operator [0] : 0
    [0,0,1,0] index using operator [1] : 0
    [0,0,1,0] index using operator [2] : 1
    [0,0,1,0] index using operator [3] : 0
    index(0,0,1,1) : [0,0,1,1]
    FirstIndex() :   0
    SecondIndex() :  0
    ThirdIndex() :   1
    FourthIndex() :  1
    index(0,0,1,2) : [0,0,1,2]
    FirstIndex() :   0
    SecondIndex() :  0
    ThirdIndex() :   1
    FourthIndex() :  2
    index(0,0,2,0) : [0,0,2,0]
    FirstIndex() :   0
    SecondIndex() :  0
    ThirdIndex() :   2
    FourthIndex() :  0
    [0,0,2,0] index using operator [0] : 0
    [0,0,2,0] index using operator [1] : 0
    [0,0,2,0] index using operator [2] : 2
    [0,0,2,0] index using operator [3] : 0
    index(0,0,2,1) : [0,0,2,1]
    FirstIndex() :   0
    SecondIndex() :  0
    ThirdIndex() :   2
    FourthIndex() :  1
    index(0,0,2,2) : [0,0,2,2]
    FirstIndex() :   0
    SecondIndex() :  0
    ThirdIndex() :   2
    FourthIndex() :  2
    index(0,1,0,0) : [0,1,0,0]
    index(0,1,0,1) : [0,1,0,1]
    index(0,1,0,2) : [0,1,0,2]
    index(0,1,1,0) : [0,1,1,0]
    index(0,1,1,1) : [0,1,1,1]
    index(0,1,1,2) : [0,1,1,2]
    index(0,1,2,0) : [0,1,2,0]
    index(0,1,2,1) : [0,1,2,1]
    FirstIndex() :   0
    SecondIndex() :  1
    ThirdIndex() :   2
    FourthIndex() :  1
    [0,1,2,1] index using operator [0] : 0
    [0,1,2,1] index using operator [1] : 1
    [0,1,2,1] index using operator [2] : 2
    [0,1,2,1] index using operator [3] : 1
    index(0,1,2,2) : [0,1,2,2]
    index(0,2,0,0) : [0,2,0,0]
    index(0,2,0,1) : [0,2,0,1]
    index(0,2,0,2) : [0,2,0,2]
    index(0,2,1,0) : [0,2,1,0]
    index(0,2,1,1) : [0,2,1,1]
    index(0,2,1,2) : [0,2,1,2]
    index(0,2,2,0) : [0,2,2,0]
    FirstIndex() :   0
    SecondIndex() :  2
    ThirdIndex() :   2
    FourthIndex() :  0
    [0,2,2,0] index using operator [0] : 0
    [0,2,2,0] index using operator [1] : 2
    [0,2,2,0] index using operator [2] : 2
    [0,2,2,0] index using operator [3] : 0
    index(0,2,2,1) : [0,2,2,1]
    index(0,2,2,2) : [0,2,2,2]
    index(1,0,0,0) : [1,0,0,0]
    index(1,0,0,1) : [1,0,0,1]
    index(1,0,0,2) : [1,0,0,2]
    index(1,0,1,0) : [1,0,1,0]
    index(1,0,1,1) : [1,0,1,1]
    index(1,0,1,2) : [1,0,1,2]
    FirstIndex() :   1
    SecondIndex() :  0
    ThirdIndex() :   1
    FourthIndex() :  2
    [1,0,1,2] index using operator [0] : 1
    [1,0,1,2] index using operator [1] : 0
    [1,0,1,2] index using operator [2] : 1
    [1,0,1,2] index using operator [3] : 2
    index(1,0,2,0) : [1,0,2,0]
    index(1,0,2,1) : [1,0,2,1]
    index(1,0,2,2) : [1,0,2,2]
    index(1,1,0,0) : [1,1,0,0]
    index(1,1,0,1) : [1,1,0,1]
    index(1,1,0,2) : [1,1,0,2]
    index(1,1,1,0) : [1,1,1,0]
    index(1,1,1,1) : [1,1,1,1]
    FirstIndex() :   1
    SecondIndex() :  1
    ThirdIndex() :   1
    FourthIndex() :  1
    [1,1,1,1] index using operator [0] : 1
    [1,1,1,1] index using operator [1] : 1
    [1,1,1,1] index using operator [2] : 1
    [1,1,1,1] index using operator [3] : 1
    index(1,1,1,2) : [1,1,1,2]
    index(1,1,2,0) : [1,1,2,0]
    index(1,1,2,1) : [1,1,2,1]
    index(1,1,2,2) : [1,1,2,2]
    index(1,2,0,0) : [1,2,0,0]
    index(1,2,0,1) : [1,2,0,1]
    index(1,2,0,2) : [1,2,0,2]
    index(1,2,1,0) : [1,2,1,0]
    FirstIndex() :   1
    SecondIndex() :  2
    ThirdIndex() :   1
    FourthIndex() :  0
    [1,2,1,0] index using operator [0] : 1
    [1,2,1,0] index using operator [1] : 2
    [1,2,1,0] index using operator [2] : 1
    [1,2,1,0] index using operator [3] : 0
    index(1,2,1,1) : [1,2,1,1]
    index(1,2,1,2) : [1,2,1,2]
    index(1,2,2,0) : [1,2,2,0]
    index(1,2,2,1) : [1,2,2,1]
    index(1,2,2,2) : [1,2,2,2]
    index(2,0,0,0) : [2,0,0,0]
    index(2,0,0,1) : [2,0,0,1]
    index(2,0,0,2) : [2,0,0,2]
    FirstIndex() :   2
    SecondIndex() :  0
    ThirdIndex() :   0
    FourthIndex() :  2
    [2,0,0,2] index using operator [0] : 2
    [2,0,0,2] index using operator [1] : 0
    [2,0,0,2] index using operator [2] : 0
    [2,0,0,2] index using operator [3] : 2
    index(2,0,1,0) : [2,0,1,0]
    index(2,0,1,1) : [2,0,1,1]
    index(2,0,1,2) : [2,0,1,2]
    index(2,0,2,0) : [2,0,2,0]
    index(2,0,2,1) : [2,0,2,1]
    index(2,0,2,2) : [2,0,2,2]
    index(2,1,0,0) : [2,1,0,0]
    index(2,1,0,1) : [2,1,0,1]
    FirstIndex() :   2
    SecondIndex() :  1
    ThirdIndex() :   0
    FourthIndex() :  1
    [2,1,0,1] index using operator [0] : 2
    [2,1,0,1] index using operator [1] : 1
    [2,1,0,1] index using operator [2] : 0
    [2,1,0,1] index using operator [3] : 1
    index(2,1,0,2) : [2,1,0,2]
    index(2,1,1,0) : [2,1,1,0]
    index(2,1,1,1) : [2,1,1,1]
    index(2,1,1,2) : [2,1,1,2]
    index(2,1,2,0) : [2,1,2,0]
    index(2,1,2,1) : [2,1,2,1]
    index(2,1,2,2) : [2,1,2,2]
    index(2,2,0,0) : [2,2,0,0]
    index(2,2,0,1) : [2,2,0,1]
    index(2,2,0,2) : [2,2,0,2]
    index(2,2,1,0) : [2,2,1,0]
    index(2,2,1,1) : [2,2,1,1]
    index(2,2,1,2) : [2,2,1,2]
    index(2,2,2,0) : [2,2,2,0]
    index(2,2,2,1) : [2,2,2,1]
    index(2,2,2,2) : [2,2,2,2]

Operators for fourth rank tensors same as those for second rank tensors...

```cpp
std::vector<mpc::core::TensorRank4ComponentIndex> vec_indexXXXX{
    index0000, index0001, index0002,
    index0010, index0011, index0012,
    index0020, index0021, index0022,
    index0100, index0101, index0102,
    index0110, index0111, index0112,
    index0120, index0121, index0122,
    index0200, index0201, index0202,
    index0210, index0211, index0212,
    index0220, index0221, index0222,
    index1000, index1001, index1002,
    index1010, index1011, index1012,
    index1020, index1021, index1022,
    index1100, index1101, index1102,
    index1110, index1111, index1112,
    index1120, index1121, index1122,
    index1200, index1201, index1202,
    index1210, index1211, index1212,
    index1220, index1221, index1222,
    index2000, index2001, index2002,
    index2010, index2011, index2012,
    index2020, index2021, index2022,
    index2100, index2101, index2102,
    index2110, index2111, index2112,
    index2120, index2121, index2122,
    index2200, index2201, index2202,
    index2210, index2211, index2212,
    index2220, index2221, index2222
};

for (auto indexXXXX : vec_indexXXXX) {
    std::cout << indexXXXX << " == " << index1111 << " : " << (indexXXXX == index1111) << std::endl;
    std::cout << indexXXXX << " != " << index1111 << " : " << (indexXXXX != index1111) << std::endl;
    std::cout << indexXXXX << " <  " << index1111 << " : " << (indexXXXX < index1111) << std::endl;
    std::cout << indexXXXX << " >  " << index1111 << " : " << (indexXXXX > index1111) << std::endl;
    std::cout << indexXXXX << " <= " << index1111 << " : " << (indexXXXX <= index1111) << std::endl;
    std::cout << indexXXXX << " >= " << index1111 << " : " << (indexXXXX >= index1111) << std::endl;
}
```
Output

    [0,0,0,0] == [1,1,1,1] : false
    [0,0,0,0] != [1,1,1,1] : true
    [0,0,0,0] <  [1,1,1,1] : true
    [0,0,0,0] >  [1,1,1,1] : false
    [0,0,0,0] <= [1,1,1,1] : true
    [0,0,0,0] >= [1,1,1,1] : false
    [0,0,0,1] == [1,1,1,1] : false
    [0,0,0,1] != [1,1,1,1] : true
    [0,0,0,1] <  [1,1,1,1] : true
    [0,0,0,1] >  [1,1,1,1] : false
    [0,0,0,1] <= [1,1,1,1] : true
    [0,0,0,1] >= [1,1,1,1] : false
    [0,0,0,2] == [1,1,1,1] : false
    [0,0,0,2] != [1,1,1,1] : true
    [0,0,0,2] <  [1,1,1,1] : true
    [0,0,0,2] >  [1,1,1,1] : false
    [0,0,0,2] <= [1,1,1,1] : true
    [0,0,0,2] >= [1,1,1,1] : false
    [0,0,1,0] == [1,1,1,1] : false
    [0,0,1,0] != [1,1,1,1] : true
    [0,0,1,0] <  [1,1,1,1] : true
    [0,0,1,0] >  [1,1,1,1] : false
    [0,0,1,0] <= [1,1,1,1] : true
    [0,0,1,0] >= [1,1,1,1] : false
    [0,0,1,1] == [1,1,1,1] : false
    [0,0,1,1] != [1,1,1,1] : true
    [0,0,1,1] <  [1,1,1,1] : true
    [0,0,1,1] >  [1,1,1,1] : false
    [0,0,1,1] <= [1,1,1,1] : true
    [0,0,1,1] >= [1,1,1,1] : false
    [0,0,1,2] == [1,1,1,1] : false
    [0,0,1,2] != [1,1,1,1] : true
    [0,0,1,2] <  [1,1,1,1] : true
    [0,0,1,2] >  [1,1,1,1] : false
    [0,0,1,2] <= [1,1,1,1] : true
    [0,0,1,2] >= [1,1,1,1] : false
    [0,0,2,0] == [1,1,1,1] : false
    [0,0,2,0] != [1,1,1,1] : true
    [0,0,2,0] <  [1,1,1,1] : true
    [0,0,2,0] >  [1,1,1,1] : false
    [0,0,2,0] <= [1,1,1,1] : true
    [0,0,2,0] >= [1,1,1,1] : false
    [0,0,2,1] == [1,1,1,1] : false
    [0,0,2,1] != [1,1,1,1] : true
    [0,0,2,1] <  [1,1,1,1] : true
    [0,0,2,1] >  [1,1,1,1] : false
    [0,0,2,1] <= [1,1,1,1] : true
    [0,0,2,1] >= [1,1,1,1] : false
    [0,0,2,2] == [1,1,1,1] : false
    [0,0,2,2] != [1,1,1,1] : true
    [0,0,2,2] <  [1,1,1,1] : true
    [0,0,2,2] >  [1,1,1,1] : false
    [0,0,2,2] <= [1,1,1,1] : true
    [0,0,2,2] >= [1,1,1,1] : false
    [0,1,0,0] == [1,1,1,1] : false
    [0,1,0,0] != [1,1,1,1] : true
    [0,1,0,0] <  [1,1,1,1] : true
    [0,1,0,0] >  [1,1,1,1] : false
    [0,1,0,0] <= [1,1,1,1] : true
    [0,1,0,0] >= [1,1,1,1] : false
    [0,1,0,1] == [1,1,1,1] : false
    [0,1,0,1] != [1,1,1,1] : true
    [0,1,0,1] <  [1,1,1,1] : true
    [0,1,0,1] >  [1,1,1,1] : false
    [0,1,0,1] <= [1,1,1,1] : true
    [0,1,0,1] >= [1,1,1,1] : false
    [0,1,0,2] == [1,1,1,1] : false
    [0,1,0,2] != [1,1,1,1] : true
    [0,1,0,2] <  [1,1,1,1] : true
    [0,1,0,2] >  [1,1,1,1] : false
    [0,1,0,2] <= [1,1,1,1] : true
    [0,1,0,2] >= [1,1,1,1] : false
    [0,1,1,0] == [1,1,1,1] : false
    [0,1,1,0] != [1,1,1,1] : true
    [0,1,1,0] <  [1,1,1,1] : true
    [0,1,1,0] >  [1,1,1,1] : false
    [0,1,1,0] <= [1,1,1,1] : true
    [0,1,1,0] >= [1,1,1,1] : false
    [0,1,1,1] == [1,1,1,1] : false
    [0,1,1,1] != [1,1,1,1] : true
    [0,1,1,1] <  [1,1,1,1] : true
    [0,1,1,1] >  [1,1,1,1] : false
    [0,1,1,1] <= [1,1,1,1] : true
    [0,1,1,1] >= [1,1,1,1] : false
    [0,1,1,2] == [1,1,1,1] : false
    [0,1,1,2] != [1,1,1,1] : true
    [0,1,1,2] <  [1,1,1,1] : true
    [0,1,1,2] >  [1,1,1,1] : false
    [0,1,1,2] <= [1,1,1,1] : true
    [0,1,1,2] >= [1,1,1,1] : false
    [0,1,2,0] == [1,1,1,1] : false
    [0,1,2,0] != [1,1,1,1] : true
    [0,1,2,0] <  [1,1,1,1] : true
    [0,1,2,0] >  [1,1,1,1] : false
    [0,1,2,0] <= [1,1,1,1] : true
    [0,1,2,0] >= [1,1,1,1] : false
    [0,1,2,1] == [1,1,1,1] : false
    [0,1,2,1] != [1,1,1,1] : true
    [0,1,2,1] <  [1,1,1,1] : true
    [0,1,2,1] >  [1,1,1,1] : false
    [0,1,2,1] <= [1,1,1,1] : true
    [0,1,2,1] >= [1,1,1,1] : false
    [0,1,2,2] == [1,1,1,1] : false
    [0,1,2,2] != [1,1,1,1] : true
    [0,1,2,2] <  [1,1,1,1] : true
    [0,1,2,2] >  [1,1,1,1] : false
    [0,1,2,2] <= [1,1,1,1] : true
    [0,1,2,2] >= [1,1,1,1] : false
    [0,2,0,0] == [1,1,1,1] : false
    [0,2,0,0] != [1,1,1,1] : true
    [0,2,0,0] <  [1,1,1,1] : true
    [0,2,0,0] >  [1,1,1,1] : false
    [0,2,0,0] <= [1,1,1,1] : true
    [0,2,0,0] >= [1,1,1,1] : false
    [0,2,0,1] == [1,1,1,1] : false
    [0,2,0,1] != [1,1,1,1] : true
    [0,2,0,1] <  [1,1,1,1] : true
    [0,2,0,1] >  [1,1,1,1] : false
    [0,2,0,1] <= [1,1,1,1] : true
    [0,2,0,1] >= [1,1,1,1] : false
    [0,2,0,2] == [1,1,1,1] : false
    [0,2,0,2] != [1,1,1,1] : true
    [0,2,0,2] <  [1,1,1,1] : true
    [0,2,0,2] >  [1,1,1,1] : false
    [0,2,0,2] <= [1,1,1,1] : true
    [0,2,0,2] >= [1,1,1,1] : false
    [0,2,1,0] == [1,1,1,1] : false
    [0,2,1,0] != [1,1,1,1] : true
    [0,2,1,0] <  [1,1,1,1] : true
    [0,2,1,0] >  [1,1,1,1] : false
    [0,2,1,0] <= [1,1,1,1] : true
    [0,2,1,0] >= [1,1,1,1] : false
    [0,2,1,1] == [1,1,1,1] : false
    [0,2,1,1] != [1,1,1,1] : true
    [0,2,1,1] <  [1,1,1,1] : true
    [0,2,1,1] >  [1,1,1,1] : false
    [0,2,1,1] <= [1,1,1,1] : true
    [0,2,1,1] >= [1,1,1,1] : false
    [0,2,1,2] == [1,1,1,1] : false
    [0,2,1,2] != [1,1,1,1] : true
    [0,2,1,2] <  [1,1,1,1] : true
    [0,2,1,2] >  [1,1,1,1] : false
    [0,2,1,2] <= [1,1,1,1] : true
    [0,2,1,2] >= [1,1,1,1] : false
    [0,2,2,0] == [1,1,1,1] : false
    [0,2,2,0] != [1,1,1,1] : true
    [0,2,2,0] <  [1,1,1,1] : true
    [0,2,2,0] >  [1,1,1,1] : false
    [0,2,2,0] <= [1,1,1,1] : true
    [0,2,2,0] >= [1,1,1,1] : false
    [0,2,2,1] == [1,1,1,1] : false
    [0,2,2,1] != [1,1,1,1] : true
    [0,2,2,1] <  [1,1,1,1] : true
    [0,2,2,1] >  [1,1,1,1] : false
    [0,2,2,1] <= [1,1,1,1] : true
    [0,2,2,1] >= [1,1,1,1] : false
    [0,2,2,2] == [1,1,1,1] : false
    [0,2,2,2] != [1,1,1,1] : true
    [0,2,2,2] <  [1,1,1,1] : true
    [0,2,2,2] >  [1,1,1,1] : false
    [0,2,2,2] <= [1,1,1,1] : true
    [0,2,2,2] >= [1,1,1,1] : false
    [1,0,0,0] == [1,1,1,1] : false
    [1,0,0,0] != [1,1,1,1] : true
    [1,0,0,0] <  [1,1,1,1] : true
    [1,0,0,0] >  [1,1,1,1] : false
    [1,0,0,0] <= [1,1,1,1] : true
    [1,0,0,0] >= [1,1,1,1] : false
    [1,0,0,1] == [1,1,1,1] : false
    [1,0,0,1] != [1,1,1,1] : true
    [1,0,0,1] <  [1,1,1,1] : true
    [1,0,0,1] >  [1,1,1,1] : false
    [1,0,0,1] <= [1,1,1,1] : true
    [1,0,0,1] >= [1,1,1,1] : false
    [1,0,0,2] == [1,1,1,1] : false
    [1,0,0,2] != [1,1,1,1] : true
    [1,0,0,2] <  [1,1,1,1] : true
    [1,0,0,2] >  [1,1,1,1] : false
    [1,0,0,2] <= [1,1,1,1] : true
    [1,0,0,2] >= [1,1,1,1] : false
    [1,0,1,0] == [1,1,1,1] : false
    [1,0,1,0] != [1,1,1,1] : true
    [1,0,1,0] <  [1,1,1,1] : true
    [1,0,1,0] >  [1,1,1,1] : false
    [1,0,1,0] <= [1,1,1,1] : true
    [1,0,1,0] >= [1,1,1,1] : false
    [1,0,1,1] == [1,1,1,1] : false
    [1,0,1,1] != [1,1,1,1] : true
    [1,0,1,1] <  [1,1,1,1] : true
    [1,0,1,1] >  [1,1,1,1] : false
    [1,0,1,1] <= [1,1,1,1] : true
    [1,0,1,1] >= [1,1,1,1] : false
    [1,0,1,2] == [1,1,1,1] : false
    [1,0,1,2] != [1,1,1,1] : true
    [1,0,1,2] <  [1,1,1,1] : true
    [1,0,1,2] >  [1,1,1,1] : false
    [1,0,1,2] <= [1,1,1,1] : true
    [1,0,1,2] >= [1,1,1,1] : false
    [1,0,2,0] == [1,1,1,1] : false
    [1,0,2,0] != [1,1,1,1] : true
    [1,0,2,0] <  [1,1,1,1] : true
    [1,0,2,0] >  [1,1,1,1] : false
    [1,0,2,0] <= [1,1,1,1] : true
    [1,0,2,0] >= [1,1,1,1] : false
    [1,0,2,1] == [1,1,1,1] : false
    [1,0,2,1] != [1,1,1,1] : true
    [1,0,2,1] <  [1,1,1,1] : true
    [1,0,2,1] >  [1,1,1,1] : false
    [1,0,2,1] <= [1,1,1,1] : true
    [1,0,2,1] >= [1,1,1,1] : false
    [1,0,2,2] == [1,1,1,1] : false
    [1,0,2,2] != [1,1,1,1] : true
    [1,0,2,2] <  [1,1,1,1] : true
    [1,0,2,2] >  [1,1,1,1] : false
    [1,0,2,2] <= [1,1,1,1] : true
    [1,0,2,2] >= [1,1,1,1] : false
    [1,1,0,0] == [1,1,1,1] : false
    [1,1,0,0] != [1,1,1,1] : true
    [1,1,0,0] <  [1,1,1,1] : true
    [1,1,0,0] >  [1,1,1,1] : false
    [1,1,0,0] <= [1,1,1,1] : true
    [1,1,0,0] >= [1,1,1,1] : false
    [1,1,0,1] == [1,1,1,1] : false
    [1,1,0,1] != [1,1,1,1] : true
    [1,1,0,1] <  [1,1,1,1] : true
    [1,1,0,1] >  [1,1,1,1] : false
    [1,1,0,1] <= [1,1,1,1] : true
    [1,1,0,1] >= [1,1,1,1] : false
    [1,1,0,2] == [1,1,1,1] : false
    [1,1,0,2] != [1,1,1,1] : true
    [1,1,0,2] <  [1,1,1,1] : true
    [1,1,0,2] >  [1,1,1,1] : false
    [1,1,0,2] <= [1,1,1,1] : true
    [1,1,0,2] >= [1,1,1,1] : false
    [1,1,1,0] == [1,1,1,1] : false
    [1,1,1,0] != [1,1,1,1] : true
    [1,1,1,0] <  [1,1,1,1] : true
    [1,1,1,0] >  [1,1,1,1] : false
    [1,1,1,0] <= [1,1,1,1] : true
    [1,1,1,0] >= [1,1,1,1] : false
    [1,1,1,1] == [1,1,1,1] : true
    [1,1,1,1] != [1,1,1,1] : false
    [1,1,1,1] <  [1,1,1,1] : false
    [1,1,1,1] >  [1,1,1,1] : false
    [1,1,1,1] <= [1,1,1,1] : true
    [1,1,1,1] >= [1,1,1,1] : true
    [1,1,1,2] == [1,1,1,1] : false
    [1,1,1,2] != [1,1,1,1] : true
    [1,1,1,2] <  [1,1,1,1] : false
    [1,1,1,2] >  [1,1,1,1] : true
    [1,1,1,2] <= [1,1,1,1] : false
    [1,1,1,2] >= [1,1,1,1] : true
    [1,1,2,0] == [1,1,1,1] : false
    [1,1,2,0] != [1,1,1,1] : true
    [1,1,2,0] <  [1,1,1,1] : false
    [1,1,2,0] >  [1,1,1,1] : true
    [1,1,2,0] <= [1,1,1,1] : false
    [1,1,2,0] >= [1,1,1,1] : true
    [1,1,2,1] == [1,1,1,1] : false
    [1,1,2,1] != [1,1,1,1] : true
    [1,1,2,1] <  [1,1,1,1] : false
    [1,1,2,1] >  [1,1,1,1] : true
    [1,1,2,1] <= [1,1,1,1] : false
    [1,1,2,1] >= [1,1,1,1] : true
    [1,1,2,2] == [1,1,1,1] : false
    [1,1,2,2] != [1,1,1,1] : true
    [1,1,2,2] <  [1,1,1,1] : false
    [1,1,2,2] >  [1,1,1,1] : true
    [1,1,2,2] <= [1,1,1,1] : false
    [1,1,2,2] >= [1,1,1,1] : true
    [1,2,0,0] == [1,1,1,1] : false
    [1,2,0,0] != [1,1,1,1] : true
    [1,2,0,0] <  [1,1,1,1] : false
    [1,2,0,0] >  [1,1,1,1] : true
    [1,2,0,0] <= [1,1,1,1] : false
    [1,2,0,0] >= [1,1,1,1] : true
    [1,2,0,1] == [1,1,1,1] : false
    [1,2,0,1] != [1,1,1,1] : true
    [1,2,0,1] <  [1,1,1,1] : false
    [1,2,0,1] >  [1,1,1,1] : true
    [1,2,0,1] <= [1,1,1,1] : false
    [1,2,0,1] >= [1,1,1,1] : true
    [1,2,0,2] == [1,1,1,1] : false
    [1,2,0,2] != [1,1,1,1] : true
    [1,2,0,2] <  [1,1,1,1] : false
    [1,2,0,2] >  [1,1,1,1] : true
    [1,2,0,2] <= [1,1,1,1] : false
    [1,2,0,2] >= [1,1,1,1] : true
    [1,2,1,0] == [1,1,1,1] : false
    [1,2,1,0] != [1,1,1,1] : true
    [1,2,1,0] <  [1,1,1,1] : false
    [1,2,1,0] >  [1,1,1,1] : true
    [1,2,1,0] <= [1,1,1,1] : false
    [1,2,1,0] >= [1,1,1,1] : true
    [1,2,1,1] == [1,1,1,1] : false
    [1,2,1,1] != [1,1,1,1] : true
    [1,2,1,1] <  [1,1,1,1] : false
    [1,2,1,1] >  [1,1,1,1] : true
    [1,2,1,1] <= [1,1,1,1] : false
    [1,2,1,1] >= [1,1,1,1] : true
    [1,2,1,2] == [1,1,1,1] : false
    [1,2,1,2] != [1,1,1,1] : true
    [1,2,1,2] <  [1,1,1,1] : false
    [1,2,1,2] >  [1,1,1,1] : true
    [1,2,1,2] <= [1,1,1,1] : false
    [1,2,1,2] >= [1,1,1,1] : true
    [1,2,2,0] == [1,1,1,1] : false
    [1,2,2,0] != [1,1,1,1] : true
    [1,2,2,0] <  [1,1,1,1] : false
    [1,2,2,0] >  [1,1,1,1] : true
    [1,2,2,0] <= [1,1,1,1] : false
    [1,2,2,0] >= [1,1,1,1] : true
    [1,2,2,1] == [1,1,1,1] : false
    [1,2,2,1] != [1,1,1,1] : true
    [1,2,2,1] <  [1,1,1,1] : false
    [1,2,2,1] >  [1,1,1,1] : true
    [1,2,2,1] <= [1,1,1,1] : false
    [1,2,2,1] >= [1,1,1,1] : true
    [1,2,2,2] == [1,1,1,1] : false
    [1,2,2,2] != [1,1,1,1] : true
    [1,2,2,2] <  [1,1,1,1] : false
    [1,2,2,2] >  [1,1,1,1] : true
    [1,2,2,2] <= [1,1,1,1] : false
    [1,2,2,2] >= [1,1,1,1] : true
    [2,0,0,0] == [1,1,1,1] : false
    [2,0,0,0] != [1,1,1,1] : true
    [2,0,0,0] <  [1,1,1,1] : false
    [2,0,0,0] >  [1,1,1,1] : true
    [2,0,0,0] <= [1,1,1,1] : false
    [2,0,0,0] >= [1,1,1,1] : true
    [2,0,0,1] == [1,1,1,1] : false
    [2,0,0,1] != [1,1,1,1] : true
    [2,0,0,1] <  [1,1,1,1] : false
    [2,0,0,1] >  [1,1,1,1] : true
    [2,0,0,1] <= [1,1,1,1] : false
    [2,0,0,1] >= [1,1,1,1] : true
    [2,0,0,2] == [1,1,1,1] : false
    [2,0,0,2] != [1,1,1,1] : true
    [2,0,0,2] <  [1,1,1,1] : false
    [2,0,0,2] >  [1,1,1,1] : true
    [2,0,0,2] <= [1,1,1,1] : false
    [2,0,0,2] >= [1,1,1,1] : true
    [2,0,1,0] == [1,1,1,1] : false
    [2,0,1,0] != [1,1,1,1] : true
    [2,0,1,0] <  [1,1,1,1] : false
    [2,0,1,0] >  [1,1,1,1] : true
    [2,0,1,0] <= [1,1,1,1] : false
    [2,0,1,0] >= [1,1,1,1] : true
    [2,0,1,1] == [1,1,1,1] : false
    [2,0,1,1] != [1,1,1,1] : true
    [2,0,1,1] <  [1,1,1,1] : false
    [2,0,1,1] >  [1,1,1,1] : true
    [2,0,1,1] <= [1,1,1,1] : false
    [2,0,1,1] >= [1,1,1,1] : true
    [2,0,1,2] == [1,1,1,1] : false
    [2,0,1,2] != [1,1,1,1] : true
    [2,0,1,2] <  [1,1,1,1] : false
    [2,0,1,2] >  [1,1,1,1] : true
    [2,0,1,2] <= [1,1,1,1] : false
    [2,0,1,2] >= [1,1,1,1] : true
    [2,0,2,0] == [1,1,1,1] : false
    [2,0,2,0] != [1,1,1,1] : true
    [2,0,2,0] <  [1,1,1,1] : false
    [2,0,2,0] >  [1,1,1,1] : true
    [2,0,2,0] <= [1,1,1,1] : false
    [2,0,2,0] >= [1,1,1,1] : true
    [2,0,2,1] == [1,1,1,1] : false
    [2,0,2,1] != [1,1,1,1] : true
    [2,0,2,1] <  [1,1,1,1] : false
    [2,0,2,1] >  [1,1,1,1] : true
    [2,0,2,1] <= [1,1,1,1] : false
    [2,0,2,1] >= [1,1,1,1] : true
    [2,0,2,2] == [1,1,1,1] : false
    [2,0,2,2] != [1,1,1,1] : true
    [2,0,2,2] <  [1,1,1,1] : false
    [2,0,2,2] >  [1,1,1,1] : true
    [2,0,2,2] <= [1,1,1,1] : false
    [2,0,2,2] >= [1,1,1,1] : true
    [2,1,0,0] == [1,1,1,1] : false
    [2,1,0,0] != [1,1,1,1] : true
    [2,1,0,0] <  [1,1,1,1] : false
    [2,1,0,0] >  [1,1,1,1] : true
    [2,1,0,0] <= [1,1,1,1] : false
    [2,1,0,0] >= [1,1,1,1] : true
    [2,1,0,1] == [1,1,1,1] : false
    [2,1,0,1] != [1,1,1,1] : true
    [2,1,0,1] <  [1,1,1,1] : false
    [2,1,0,1] >  [1,1,1,1] : true
    [2,1,0,1] <= [1,1,1,1] : false
    [2,1,0,1] >= [1,1,1,1] : true
    [2,1,0,2] == [1,1,1,1] : false
    [2,1,0,2] != [1,1,1,1] : true
    [2,1,0,2] <  [1,1,1,1] : false
    [2,1,0,2] >  [1,1,1,1] : true
    [2,1,0,2] <= [1,1,1,1] : false
    [2,1,0,2] >= [1,1,1,1] : true
    [2,1,1,0] == [1,1,1,1] : false
    [2,1,1,0] != [1,1,1,1] : true
    [2,1,1,0] <  [1,1,1,1] : false
    [2,1,1,0] >  [1,1,1,1] : true
    [2,1,1,0] <= [1,1,1,1] : false
    [2,1,1,0] >= [1,1,1,1] : true
    [2,1,1,1] == [1,1,1,1] : false
    [2,1,1,1] != [1,1,1,1] : true
    [2,1,1,1] <  [1,1,1,1] : false
    [2,1,1,1] >  [1,1,1,1] : true
    [2,1,1,1] <= [1,1,1,1] : false
    [2,1,1,1] >= [1,1,1,1] : true
    [2,1,1,2] == [1,1,1,1] : false
    [2,1,1,2] != [1,1,1,1] : true
    [2,1,1,2] <  [1,1,1,1] : false
    [2,1,1,2] >  [1,1,1,1] : true
    [2,1,1,2] <= [1,1,1,1] : false
    [2,1,1,2] >= [1,1,1,1] : true
    [2,1,2,0] == [1,1,1,1] : false
    [2,1,2,0] != [1,1,1,1] : true
    [2,1,2,0] <  [1,1,1,1] : false
    [2,1,2,0] >  [1,1,1,1] : true
    [2,1,2,0] <= [1,1,1,1] : false
    [2,1,2,0] >= [1,1,1,1] : true
    [2,1,2,1] == [1,1,1,1] : false
    [2,1,2,1] != [1,1,1,1] : true
    [2,1,2,1] <  [1,1,1,1] : false
    [2,1,2,1] >  [1,1,1,1] : true
    [2,1,2,1] <= [1,1,1,1] : false
    [2,1,2,1] >= [1,1,1,1] : true
    [2,1,2,2] == [1,1,1,1] : false
    [2,1,2,2] != [1,1,1,1] : true
    [2,1,2,2] <  [1,1,1,1] : false
    [2,1,2,2] >  [1,1,1,1] : true
    [2,1,2,2] <= [1,1,1,1] : false
    [2,1,2,2] >= [1,1,1,1] : true
    [2,2,0,0] == [1,1,1,1] : false
    [2,2,0,0] != [1,1,1,1] : true
    [2,2,0,0] <  [1,1,1,1] : false
    [2,2,0,0] >  [1,1,1,1] : true
    [2,2,0,0] <= [1,1,1,1] : false
    [2,2,0,0] >= [1,1,1,1] : true
    [2,2,0,1] == [1,1,1,1] : false
    [2,2,0,1] != [1,1,1,1] : true
    [2,2,0,1] <  [1,1,1,1] : false
    [2,2,0,1] >  [1,1,1,1] : true
    [2,2,0,1] <= [1,1,1,1] : false
    [2,2,0,1] >= [1,1,1,1] : true
    [2,2,0,2] == [1,1,1,1] : false
    [2,2,0,2] != [1,1,1,1] : true
    [2,2,0,2] <  [1,1,1,1] : false
    [2,2,0,2] >  [1,1,1,1] : true
    [2,2,0,2] <= [1,1,1,1] : false
    [2,2,0,2] >= [1,1,1,1] : true
    [2,2,1,0] == [1,1,1,1] : false
    [2,2,1,0] != [1,1,1,1] : true
    [2,2,1,0] <  [1,1,1,1] : false
    [2,2,1,0] >  [1,1,1,1] : true
    [2,2,1,0] <= [1,1,1,1] : false
    [2,2,1,0] >= [1,1,1,1] : true
    [2,2,1,1] == [1,1,1,1] : false
    [2,2,1,1] != [1,1,1,1] : true
    [2,2,1,1] <  [1,1,1,1] : false
    [2,2,1,1] >  [1,1,1,1] : true
    [2,2,1,1] <= [1,1,1,1] : false
    [2,2,1,1] >= [1,1,1,1] : true
    [2,2,1,2] == [1,1,1,1] : false
    [2,2,1,2] != [1,1,1,1] : true
    [2,2,1,2] <  [1,1,1,1] : false
    [2,2,1,2] >  [1,1,1,1] : true
    [2,2,1,2] <= [1,1,1,1] : false
    [2,2,1,2] >= [1,1,1,1] : true
    [2,2,2,0] == [1,1,1,1] : false
    [2,2,2,0] != [1,1,1,1] : true
    [2,2,2,0] <  [1,1,1,1] : false
    [2,2,2,0] >  [1,1,1,1] : true
    [2,2,2,0] <= [1,1,1,1] : false
    [2,2,2,0] >= [1,1,1,1] : true
    [2,2,2,1] == [1,1,1,1] : false
    [2,2,2,1] != [1,1,1,1] : true
    [2,2,2,1] <  [1,1,1,1] : false
    [2,2,2,1] >  [1,1,1,1] : true
    [2,2,2,1] <= [1,1,1,1] : false
    [2,2,2,1] >= [1,1,1,1] : true
    [2,2,2,2] == [1,1,1,1] : false
    [2,2,2,2] != [1,1,1,1] : true
    [2,2,2,2] <  [1,1,1,1] : false
    [2,2,2,2] >  [1,1,1,1] : true
    [2,2,2,2] <= [1,1,1,1] : false
    [2,2,2,2] >= [1,1,1,1] : true

mpc provides an alias for the fourth rank tensor component index with the using directive:

```cpp
using TensorRank4ComponentIndex = TensorRankNComponentIndex<4>;
```

which can be used like

```cpp
mpc::core::TensorRank4ComponentIndex index0022usingalias = mpc::core::TensorRank4ComponentIndex(0,0,2,2);
```

Another example of creating <code>blitz::TinyVector<int,4></code> from a <pre>TensorRank4CompoentIndex</pre>.

```cpp
blitz::TinyVector<int,4> blitz_indexXXXX = blitz::TinyVector<int,4>(0,0,0,0);
for (auto indexXXXX : vec_indexXXXX) {
    blitz_indexXXXX = mpc::core::TensorRankNComponentIndex<4>::ToBlitzTinyVector(indexXXXX);
    std::cout << "TinyVector blitz_index " << indexXXXX << " : " << blitz_indexXXXX << std::endl;
}
```
Output

    TinyVector blitz_index [0,0,0,0] : (0,0,0,0)
    TinyVector blitz_index [0,0,0,1] : (0,0,0,1)
    TinyVector blitz_index [0,0,0,2] : (0,0,0,2)
    TinyVector blitz_index [0,0,1,0] : (0,0,1,0)
    TinyVector blitz_index [0,0,1,1] : (0,0,1,1)
    TinyVector blitz_index [0,0,1,2] : (0,0,1,2)
    TinyVector blitz_index [0,0,2,0] : (0,0,2,0)
    TinyVector blitz_index [0,0,2,1] : (0,0,2,1)
    TinyVector blitz_index [0,0,2,2] : (0,0,2,2)
    TinyVector blitz_index [0,1,0,0] : (0,1,0,0)
    TinyVector blitz_index [0,1,0,1] : (0,1,0,1)
    TinyVector blitz_index [0,1,0,2] : (0,1,0,2)
    TinyVector blitz_index [0,1,1,0] : (0,1,1,0)
    TinyVector blitz_index [0,1,1,1] : (0,1,1,1)
    TinyVector blitz_index [0,1,1,2] : (0,1,1,2)
    TinyVector blitz_index [0,1,2,0] : (0,1,2,0)
    TinyVector blitz_index [0,1,2,1] : (0,1,2,1)
    TinyVector blitz_index [0,1,2,2] : (0,1,2,2)
    TinyVector blitz_index [0,2,0,0] : (0,2,0,0)
    TinyVector blitz_index [0,2,0,1] : (0,2,0,1)
    TinyVector blitz_index [0,2,0,2] : (0,2,0,2)
    TinyVector blitz_index [0,2,1,0] : (0,2,1,0)
    TinyVector blitz_index [0,2,1,1] : (0,2,1,1)
    TinyVector blitz_index [0,2,1,2] : (0,2,1,2)
    TinyVector blitz_index [0,2,2,0] : (0,2,2,0)
    TinyVector blitz_index [0,2,2,1] : (0,2,2,1)
    TinyVector blitz_index [0,2,2,2] : (0,2,2,2)
    TinyVector blitz_index [1,0,0,0] : (1,0,0,0)
    TinyVector blitz_index [1,0,0,1] : (1,0,0,1)
    TinyVector blitz_index [1,0,0,2] : (1,0,0,2)
    TinyVector blitz_index [1,0,1,0] : (1,0,1,0)
    TinyVector blitz_index [1,0,1,1] : (1,0,1,1)
    TinyVector blitz_index [1,0,1,2] : (1,0,1,2)
    TinyVector blitz_index [1,0,2,0] : (1,0,2,0)
    TinyVector blitz_index [1,0,2,1] : (1,0,2,1)
    TinyVector blitz_index [1,0,2,2] : (1,0,2,2)
    TinyVector blitz_index [1,1,0,0] : (1,1,0,0)
    TinyVector blitz_index [1,1,0,1] : (1,1,0,1)
    TinyVector blitz_index [1,1,0,2] : (1,1,0,2)
    TinyVector blitz_index [1,1,1,0] : (1,1,1,0)
    TinyVector blitz_index [1,1,1,1] : (1,1,1,1)
    TinyVector blitz_index [1,1,1,2] : (1,1,1,2)
    TinyVector blitz_index [1,1,2,0] : (1,1,2,0)
    TinyVector blitz_index [1,1,2,1] : (1,1,2,1)
    TinyVector blitz_index [1,1,2,2] : (1,1,2,2)
    TinyVector blitz_index [1,2,0,0] : (1,2,0,0)
    TinyVector blitz_index [1,2,0,1] : (1,2,0,1)
    TinyVector blitz_index [1,2,0,2] : (1,2,0,2)
    TinyVector blitz_index [1,2,1,0] : (1,2,1,0)
    TinyVector blitz_index [1,2,1,1] : (1,2,1,1)
    TinyVector blitz_index [1,2,1,2] : (1,2,1,2)
    TinyVector blitz_index [1,2,2,0] : (1,2,2,0)
    TinyVector blitz_index [1,2,2,1] : (1,2,2,1)
    TinyVector blitz_index [1,2,2,2] : (1,2,2,2)
    TinyVector blitz_index [2,0,0,0] : (2,0,0,0)
    TinyVector blitz_index [2,0,0,1] : (2,0,0,1)
    TinyVector blitz_index [2,0,0,2] : (2,0,0,2)
    TinyVector blitz_index [2,0,1,0] : (2,0,1,0)
    TinyVector blitz_index [2,0,1,1] : (2,0,1,1)
    TinyVector blitz_index [2,0,1,2] : (2,0,1,2)
    TinyVector blitz_index [2,0,2,0] : (2,0,2,0)
    TinyVector blitz_index [2,0,2,1] : (2,0,2,1)
    TinyVector blitz_index [2,0,2,2] : (2,0,2,2)
    TinyVector blitz_index [2,1,0,0] : (2,1,0,0)
    TinyVector blitz_index [2,1,0,1] : (2,1,0,1)
    TinyVector blitz_index [2,1,0,2] : (2,1,0,2)
    TinyVector blitz_index [2,1,1,0] : (2,1,1,0)
    TinyVector blitz_index [2,1,1,1] : (2,1,1,1)
    TinyVector blitz_index [2,1,1,2] : (2,1,1,2)
    TinyVector blitz_index [2,1,2,0] : (2,1,2,0)
    TinyVector blitz_index [2,1,2,1] : (2,1,2,1)
    TinyVector blitz_index [2,1,2,2] : (2,1,2,2)
    TinyVector blitz_index [2,2,0,0] : (2,2,0,0)
    TinyVector blitz_index [2,2,0,1] : (2,2,0,1)
    TinyVector blitz_index [2,2,0,2] : (2,2,0,2)
    TinyVector blitz_index [2,2,1,0] : (2,2,1,0)
    TinyVector blitz_index [2,2,1,1] : (2,2,1,1)
    TinyVector blitz_index [2,2,1,2] : (2,2,1,2)
    TinyVector blitz_index [2,2,2,0] : (2,2,2,0)
    TinyVector blitz_index [2,2,2,1] : (2,2,2,1)
    TinyVector blitz_index [2,2,2,2] : (2,2,2,2)

An index has no natrual order, but MPC defines it like this for 4th rank tensor component indices:            
* 0000 < 0001 < 0002 < 0010 < 0011 < ... < 2220 < 2221 < 2222

Containers of <code>TensorRankNComponentIndex<N></code> can now be sorted or stored in ordered containers like <code>std::set<T></code>.

For fourth rank tensors, symmetry is a bit more complicated.  We must define what we mean by symmetrical.

(triclinic symmetry; all other symmmetries are considered specializations of triclinic)

c(i,j,k,l) = c(j,i,k,l) = c(i,j,l,k) = c(l,k,i,j)

* X11 >> (1111)
* X12 >> (1122), (2211)
* X13 >> (1133), (3311)
* X14 >> (1123), (1132), (2311), (3211)
* X15 >> (1113), (1131), (1311), (3111)
* X16 >> (1112), (1121), (1211), (2111)
* X22 >> (2222)
* X23 >> (2233), (3322)
* X24 >> (2223), (2232), (2322), (3222)
* X25 >> (2213), (2231), (1322), (3122)
* X26 >> (2212), (2221), (1222), (2122)
* X33 >> (3333)
* X34 >> (3323), (3332), (2333), (3233)
* X35 >> (3313), (3331), (1333), (3133)
* X36 >> (3312), (3321), (1233), (2133)
* X44 >> (2323), (2332), (3223), (3232)
* X45 >> (2313), (2331), (3213), (3231), (1323), (3123), (1332), (3132)
* X46 >> (2312), (2321), (3212), (3221), (1223), (2123), (1232), (2132)
* X55 >> (1313), (1331), (3113), (3131)
* X56 >> (1312), (1321), (3112), (3121), (1213), (2113), (1231), (2131)
* X66 >> (1212), (1221), (2112), (2121)

NOTE that the above is in one-based index notation to match the literature. mpc uses zero-based indexing for the rest of us who aren't exclusively MATLAB and/or fortran programmers:

* X00 >> (0000)
* X01 >> (0011), (1100)
* X02 >> (0022), (2200)
* X03 >> (0012), (0021), (1200), (2100)
* X04 >> (0002), (0020), (0200), (2000)
* X05 >> (0001), (0010), (0100), (1000)
* X11 >> (1111)
* X12 >> (1122), (2211)
* X13 >> (1112), (1121), (1211), (2111)
* X14 >> (1102), (1120), (0211), (2011)
* X15 >> (1101), (1110), (0111), (1011)
* X22 >> (2222)
* X23 >> (2212), (2221), (1222), (2122)
* X24 >> (2202), (2220), (0222), (2022)
* X25 >> (2201), (2210), (0122), (1022)
* X33 >> (1212), (1221), (2112), (2121)
* X34 >> (1202), (1220), (2102), (2120), (0212), (2012), (0221), (2021)
* X35 >> (1201), (1210), (2101), (2110), (0112), (1012), (0121), (1021)
* X44 >> (0202), (0220), (2002), (2020)
* X45 >> (0201), (0210), (2001), (2010), (0102), (1002), (0120), (1020)
* X55 >> (0101), (0110), (1001), (1010)

A more detailed discussion of symmetry as it pertains to the mechanical properties of crystals, specifically elasticity, is postponed until later.  I assume the user has some knowledge of this concept as it is fundamental to any research in solid mechanics. An entire section is devoted to this subject as it pertains to MPC, i.e., how mpc uses these properties and encapsulates them in their own classes...

When working only a set of components, it is sometimes easiest to work with the "reduced" indices.  A "reduced" index depends on its symmetry.  The idea is extract the least index from a set of indices that should be equal or equal and opposite in sign.  These sets are referred to as groupings or links in mpc.

IMPORTANT!!!  Indices that should be zero valued according to the symmetry rules are NOT reduced.  Reduced indices have values that either equal or equal and opposite in sign;  indices whose values are derived from 2 (or more) other indices are left alone and reduced according to triclinic symmetry rules.  This concept of reduced indices is unique (as far as I know) to mpc and is still a work in progress.

```cpp
mpc::core::TensorRank4ComponentIndex indexXXXX_reduced = mpc::core::TensorRank4ComponentIndex(index0000);
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex(indexXXXX);
    std::cout << indexXXXX << " reduced : " << indexXXXX_reduced << std::endl;
}
```
Output

    [0,0,0,0] reduced : [0,0,0,0]
    [0,0,0,1] reduced : [0,0,0,1]
    [0,0,0,2] reduced : [0,0,0,2]
    [0,0,1,0] reduced : [0,0,1,0]
    [0,0,1,1] reduced : [0,0,1,1]
    [0,0,1,2] reduced : [0,0,1,2]
    [0,0,2,0] reduced : [0,0,2,0]
    [0,0,2,1] reduced : [0,0,2,1]
    [0,0,2,2] reduced : [0,0,2,2]
    [0,1,0,0] reduced : [0,1,0,0]
    [0,1,0,1] reduced : [0,1,0,1]
    [0,1,0,2] reduced : [0,1,0,2]
    [0,1,1,0] reduced : [0,1,1,0]
    [0,1,1,1] reduced : [0,1,1,1]
    [0,1,1,2] reduced : [0,1,1,2]
    [0,1,2,0] reduced : [0,1,2,0]
    [0,1,2,1] reduced : [0,1,2,1]
    [0,1,2,2] reduced : [0,1,2,2]
    [0,2,0,0] reduced : [0,2,0,0]
    [0,2,0,1] reduced : [0,2,0,1]
    [0,2,0,2] reduced : [0,2,0,2]
    [0,2,1,0] reduced : [0,2,1,0]
    [0,2,1,1] reduced : [0,2,1,1]
    [0,2,1,2] reduced : [0,2,1,2]
    [0,2,2,0] reduced : [0,2,2,0]
    [0,2,2,1] reduced : [0,2,2,1]
    [0,2,2,2] reduced : [0,2,2,2]
    [1,0,0,0] reduced : [1,0,0,0]
    [1,0,0,1] reduced : [1,0,0,1]
    [1,0,0,2] reduced : [1,0,0,2]
    [1,0,1,0] reduced : [1,0,1,0]
    [1,0,1,1] reduced : [1,0,1,1]
    [1,0,1,2] reduced : [1,0,1,2]
    [1,0,2,0] reduced : [1,0,2,0]
    [1,0,2,1] reduced : [1,0,2,1]
    [1,0,2,2] reduced : [1,0,2,2]
    [1,1,0,0] reduced : [1,1,0,0]
    [1,1,0,1] reduced : [1,1,0,1]
    [1,1,0,2] reduced : [1,1,0,2]
    [1,1,1,0] reduced : [1,1,1,0]
    [1,1,1,1] reduced : [1,1,1,1]
    [1,1,1,2] reduced : [1,1,1,2]
    [1,1,2,0] reduced : [1,1,2,0]
    [1,1,2,1] reduced : [1,1,2,1]
    [1,1,2,2] reduced : [1,1,2,2]
    [1,2,0,0] reduced : [1,2,0,0]
    [1,2,0,1] reduced : [1,2,0,1]
    [1,2,0,2] reduced : [1,2,0,2]
    [1,2,1,0] reduced : [1,2,1,0]
    [1,2,1,1] reduced : [1,2,1,1]
    [1,2,1,2] reduced : [1,2,1,2]
    [1,2,2,0] reduced : [1,2,2,0]
    [1,2,2,1] reduced : [1,2,2,1]
    [1,2,2,2] reduced : [1,2,2,2]
    [2,0,0,0] reduced : [2,0,0,0]
    [2,0,0,1] reduced : [2,0,0,1]
    [2,0,0,2] reduced : [2,0,0,2]
    [2,0,1,0] reduced : [2,0,1,0]
    [2,0,1,1] reduced : [2,0,1,1]
    [2,0,1,2] reduced : [2,0,1,2]
    [2,0,2,0] reduced : [2,0,2,0]
    [2,0,2,1] reduced : [2,0,2,1]
    [2,0,2,2] reduced : [2,0,2,2]
    [2,1,0,0] reduced : [2,1,0,0]
    [2,1,0,1] reduced : [2,1,0,1]
    [2,1,0,2] reduced : [2,1,0,2]
    [2,1,1,0] reduced : [2,1,1,0]
    [2,1,1,1] reduced : [2,1,1,1]
    [2,1,1,2] reduced : [2,1,1,2]
    [2,1,2,0] reduced : [2,1,2,0]
    [2,1,2,1] reduced : [2,1,2,1]
    [2,1,2,2] reduced : [2,1,2,2]
    [2,2,0,0] reduced : [2,2,0,0]
    [2,2,0,1] reduced : [2,2,0,1]
    [2,2,0,2] reduced : [2,2,0,2]
    [2,2,1,0] reduced : [2,2,1,0]
    [2,2,1,1] reduced : [2,2,1,1]
    [2,2,1,2] reduced : [2,2,1,2]
    [2,2,2,0] reduced : [2,2,2,0]
    [2,2,2,1] reduced : [2,2,2,1]
    [2,2,2,2] reduced : [2,2,2,2]

```cpp
int p, q; // used to hold temporary values of the voigt indices
std::cout << "" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    p = mpc::utilities::GetVoigtMatrixIndex(indexXXXX.FirstIndex(), indexXXXX.SecondIndex());
    q = mpc::utilities::GetVoigtMatrixIndex(indexXXXX.ThirdIndex(), indexXXXX.FourthIndex());
    //
    std::cout << "" << std::endl;
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " triclinic symmetry reduced : " << indexXXXX_reduced << std::endl;
    // polymorphic
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));
    std::cout << mpc::core::TensorRank2ComponentIndex(p,q) << " (matrix notation) reduced : " << indexXXXX_reduced << std::endl;

    std::cout << "" << std::endl;
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " monoclinicx2 symmetry reduced : " << indexXXXX_reduced << std::endl;
    // TODO: illustrate zero values...
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));



    std::cout << "" << std::endl;
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " monoclinicx3 symmetry reduced : " << indexXXXX_reduced << std::endl;
    // TODO: illustrate zero values...
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));


    std::cout << "" << std::endl;
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(indexXXXX);
        std::cout << indexXXXX << " orthorhombic symmetry reduced : " << indexXXXX_reduced << std::endl;
    // TODO: illustrate zero values...
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));



    std::cout << "" << std::endl;
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " hexagonal symmetry reduced : " << indexXXXX_reduced << std::endl;
    // TODO: illustrate zero values...
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));


    std::cout << "" << std::endl;
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " tetragonal7 symmetry reduced : " << indexXXXX_reduced << std::endl;
    // TODO: illustrate zero values...
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));


    std::cout << "" << std::endl;
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " tetragonal6 symmetry reduced : " << indexXXXX_reduced << std::endl;
    // TODO: illustrate zero values...
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));


    std::cout << "" << std::endl;
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " trigonal7 symmetry reduced : " << indexXXXX_reduced << std::endl;
    // TODO: illustrate zero values...
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));


    std::cout << "" << std::endl;
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " trigonal6 symmetry reduced : " << indexXXXX_reduced << std::endl;
    // TODO: illustrate zero values...
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));


    std::cout << "" << std::endl;
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " cubic symmetry reduced : " << indexXXXX_reduced << std::endl;
    // TODO: illustrate zero values...
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));


    std::cout << "" << std::endl;
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " isotropic symmetry reduced : " << indexXXXX_reduced << std::endl;
    // TODO: illustrate zero values...
    indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank2ComponentIndex(p,q));

}
```
Output

    [0,0,0,0] triclinic symmetry reduced : [0,0,0,0]
    [0,0] (matrix notation) reduced : [0,0,0,0]

    [0,0,0,0] monoclinicx2 symmetry reduced : [0,0,0,0]

    [0,0,0,0] monoclinicx3 symmetry reduced : [0,0,0,0]

    [0,0,0,0] orthorhombic symmetry reduced : [0,0,0,0]

    [0,0,0,0] hexagonal symmetry reduced : [0,0,0,0]

    [0,0,0,0] tetragonal7 symmetry reduced : [0,0,0,0]

    [0,0,0,0] tetragonal6 symmetry reduced : [0,0,0,0]

    [0,0,0,0] trigonal7 symmetry reduced : [0,0,0,0]

    [0,0,0,0] trigonal6 symmetry reduced : [0,0,0,0]

    [0,0,0,0] cubic symmetry reduced : [0,0,0,0]

    [0,0,0,0] isotropic symmetry reduced : [0,0,0,0]

    [0,0,0,1] triclinic symmetry reduced : [0,0,0,1]
    [0,5] (matrix notation) reduced : [0,0,0,1]

    [0,0,0,1] monoclinicx2 symmetry reduced : [0,0,0,1]

    [0,0,0,1] monoclinicx3 symmetry reduced : [0,0,0,1]

    [0,0,0,1] orthorhombic symmetry reduced : [0,0,0,1]

    [0,0,0,1] hexagonal symmetry reduced : [0,0,0,1]

    [0,0,0,1] tetragonal7 symmetry reduced : [0,0,0,1]

    [0,0,0,1] tetragonal6 symmetry reduced : [0,0,0,1]

    [0,0,0,1] trigonal7 symmetry reduced : [0,0,0,1]

    [0,0,0,1] trigonal6 symmetry reduced : [0,0,0,1]

    [0,0,0,1] cubic symmetry reduced : [0,0,0,1]

    [0,0,0,1] isotropic symmetry reduced : [0,0,0,1]

    [0,0,0,2] triclinic symmetry reduced : [0,0,0,2]
    [0,4] (matrix notation) reduced : [0,0,0,2]

    [0,0,0,2] monoclinicx2 symmetry reduced : [0,0,0,2]

    [0,0,0,2] monoclinicx3 symmetry reduced : [0,0,0,2]

    [0,0,0,2] orthorhombic symmetry reduced : [0,0,0,2]

    [0,0,0,2] hexagonal symmetry reduced : [0,0,0,2]

    [0,0,0,2] tetragonal7 symmetry reduced : [0,0,0,2]

    [0,0,0,2] tetragonal6 symmetry reduced : [0,0,0,2]

    [0,0,0,2] trigonal7 symmetry reduced : [0,0,0,2]

    [0,0,0,2] trigonal6 symmetry reduced : [0,0,0,2]

    [0,0,0,2] cubic symmetry reduced : [0,0,0,2]

    [0,0,0,2] isotropic symmetry reduced : [0,0,0,2]

    [0,0,1,0] triclinic symmetry reduced : [0,0,0,1]
    [0,5] (matrix notation) reduced : [0,0,0,1]

    [0,0,1,0] monoclinicx2 symmetry reduced : [0,0,1,0]

    [0,0,1,0] monoclinicx3 symmetry reduced : [0,0,0,1]

    [0,0,1,0] orthorhombic symmetry reduced : [0,0,1,0]

    [0,0,1,0] hexagonal symmetry reduced : [0,0,1,0]

    [0,0,1,0] tetragonal7 symmetry reduced : [0,0,0,1]

    [0,0,1,0] tetragonal6 symmetry reduced : [0,0,1,0]

    [0,0,1,0] trigonal7 symmetry reduced : [0,0,1,0]

    [0,0,1,0] trigonal6 symmetry reduced : [0,0,1,0]

    [0,0,1,0] cubic symmetry reduced : [0,0,1,0]

    [0,0,1,0] isotropic symmetry reduced : [0,0,1,0]

    [0,0,1,1] triclinic symmetry reduced : [0,0,1,1]
    [0,1] (matrix notation) reduced : [0,0,1,1]

    [0,0,1,1] monoclinicx2 symmetry reduced : [0,0,1,1]

    [0,0,1,1] monoclinicx3 symmetry reduced : [0,0,1,1]

    [0,0,1,1] orthorhombic symmetry reduced : [0,0,1,1]

    [0,0,1,1] hexagonal symmetry reduced : [0,0,1,1]

    [0,0,1,1] tetragonal7 symmetry reduced : [0,0,1,1]

    [0,0,1,1] tetragonal6 symmetry reduced : [0,0,1,1]

    [0,0,1,1] trigonal7 symmetry reduced : [0,0,1,1]

    [0,0,1,1] trigonal6 symmetry reduced : [0,0,1,1]

    [0,0,1,1] cubic symmetry reduced : [0,0,1,1]

    [0,0,1,1] isotropic symmetry reduced : [0,0,1,1]

    [0,0,1,2] triclinic symmetry reduced : [0,0,1,2]
    [0,3] (matrix notation) reduced : [0,0,1,2]

    [0,0,1,2] monoclinicx2 symmetry reduced : [0,0,1,2]

    [0,0,1,2] monoclinicx3 symmetry reduced : [0,0,1,2]

    [0,0,1,2] orthorhombic symmetry reduced : [0,0,1,2]

    [0,0,1,2] hexagonal symmetry reduced : [0,0,1,2]

    [0,0,1,2] tetragonal7 symmetry reduced : [0,0,1,2]

    [0,0,1,2] tetragonal6 symmetry reduced : [0,0,1,2]

    [0,0,1,2] trigonal7 symmetry reduced : [0,0,1,2]

    [0,0,1,2] trigonal6 symmetry reduced : [0,0,1,2]

    [0,0,1,2] cubic symmetry reduced : [0,0,1,2]

    [0,0,1,2] isotropic symmetry reduced : [0,0,1,2]

    [0,0,2,0] triclinic symmetry reduced : [0,0,0,2]
    [0,4] (matrix notation) reduced : [0,0,0,2]

    [0,0,2,0] monoclinicx2 symmetry reduced : [0,0,0,2]

    [0,0,2,0] monoclinicx3 symmetry reduced : [0,0,2,0]

    [0,0,2,0] orthorhombic symmetry reduced : [0,0,2,0]

    [0,0,2,0] hexagonal symmetry reduced : [0,0,2,0]

    [0,0,2,0] tetragonal7 symmetry reduced : [0,0,2,0]

    [0,0,2,0] tetragonal6 symmetry reduced : [0,0,2,0]

    [0,0,2,0] trigonal7 symmetry reduced : [0,0,0,2]

    [0,0,2,0] trigonal6 symmetry reduced : [0,0,2,0]

    [0,0,2,0] cubic symmetry reduced : [0,0,2,0]

    [0,0,2,0] isotropic symmetry reduced : [0,0,2,0]

    [0,0,2,1] triclinic symmetry reduced : [0,0,1,2]
    [0,3] (matrix notation) reduced : [0,0,1,2]

    [0,0,2,1] monoclinicx2 symmetry reduced : [0,0,2,1]

    [0,0,2,1] monoclinicx3 symmetry reduced : [0,0,2,1]

    [0,0,2,1] orthorhombic symmetry reduced : [0,0,2,1]

    [0,0,2,1] hexagonal symmetry reduced : [0,0,2,1]

    [0,0,2,1] tetragonal7 symmetry reduced : [0,0,2,1]

    [0,0,2,1] tetragonal6 symmetry reduced : [0,0,2,1]

    [0,0,2,1] trigonal7 symmetry reduced : [0,0,1,2]

    [0,0,2,1] trigonal6 symmetry reduced : [0,0,1,2]

    [0,0,2,1] cubic symmetry reduced : [0,0,2,1]

    [0,0,2,1] isotropic symmetry reduced : [0,0,2,1]

    [0,0,2,2] triclinic symmetry reduced : [0,0,2,2]
    [0,2] (matrix notation) reduced : [0,0,2,2]

    [0,0,2,2] monoclinicx2 symmetry reduced : [0,0,2,2]

    [0,0,2,2] monoclinicx3 symmetry reduced : [0,0,2,2]

    [0,0,2,2] orthorhombic symmetry reduced : [0,0,2,2]

    [0,0,2,2] hexagonal symmetry reduced : [0,0,2,2]

    [0,0,2,2] tetragonal7 symmetry reduced : [0,0,2,2]

    [0,0,2,2] tetragonal6 symmetry reduced : [0,0,2,2]

    [0,0,2,2] trigonal7 symmetry reduced : [0,0,2,2]

    [0,0,2,2] trigonal6 symmetry reduced : [0,0,2,2]

    [0,0,2,2] cubic symmetry reduced : [0,0,1,1]

    [0,0,2,2] isotropic symmetry reduced : [0,0,1,1]

    [0,1,0,0] triclinic symmetry reduced : [0,0,0,1]
    [5,0] (matrix notation) reduced : [0,0,0,1]

    [0,1,0,0] monoclinicx2 symmetry reduced : [0,1,0,0]

    [0,1,0,0] monoclinicx3 symmetry reduced : [0,0,0,1]

    [0,1,0,0] orthorhombic symmetry reduced : [0,1,0,0]

    [0,1,0,0] hexagonal symmetry reduced : [0,1,0,0]

    [0,1,0,0] tetragonal7 symmetry reduced : [0,0,0,1]

    [0,1,0,0] tetragonal6 symmetry reduced : [0,1,0,0]

    [0,1,0,0] trigonal7 symmetry reduced : [0,1,0,0]

    [0,1,0,0] trigonal6 symmetry reduced : [0,1,0,0]

    [0,1,0,0] cubic symmetry reduced : [0,1,0,0]

    [0,1,0,0] isotropic symmetry reduced : [0,1,0,0]

    [0,1,0,1] triclinic symmetry reduced : [0,1,0,1]
    [5,5] (matrix notation) reduced : [0,1,0,1]

    [0,1,0,1] monoclinicx2 symmetry reduced : [0,1,0,1]

    [0,1,0,1] monoclinicx3 symmetry reduced : [0,1,0,1]

    [0,1,0,1] orthorhombic symmetry reduced : [0,1,0,1]

    [0,1,0,1] hexagonal symmetry reduced : [0,1,0,1]

    [0,1,0,1] tetragonal7 symmetry reduced : [0,1,0,1]

    [0,1,0,1] tetragonal6 symmetry reduced : [0,1,0,1]

    [0,1,0,1] trigonal7 symmetry reduced : [0,1,0,1]

    [0,1,0,1] trigonal6 symmetry reduced : [0,1,0,1]

    [0,1,0,1] cubic symmetry reduced : [0,1,0,1]

    [0,1,0,1] isotropic symmetry reduced : [0,1,0,1]

    [0,1,0,2] triclinic symmetry reduced : [0,1,0,2]
    [5,4] (matrix notation) reduced : [0,1,0,2]

    [0,1,0,2] monoclinicx2 symmetry reduced : [0,1,0,2]

    [0,1,0,2] monoclinicx3 symmetry reduced : [0,1,0,2]

    [0,1,0,2] orthorhombic symmetry reduced : [0,1,0,2]

    [0,1,0,2] hexagonal symmetry reduced : [0,1,0,2]

    [0,1,0,2] tetragonal7 symmetry reduced : [0,1,0,2]

    [0,1,0,2] tetragonal6 symmetry reduced : [0,1,0,2]

    [0,1,0,2] trigonal7 symmetry reduced : [0,0,1,2]

    [0,1,0,2] trigonal6 symmetry reduced : [0,0,1,2]

    [0,1,0,2] cubic symmetry reduced : [0,1,0,2]

    [0,1,0,2] isotropic symmetry reduced : [0,1,0,2]

    [0,1,1,0] triclinic symmetry reduced : [0,1,0,1]
    [5,5] (matrix notation) reduced : [0,1,0,1]

    [0,1,1,0] monoclinicx2 symmetry reduced : [0,1,0,1]

    [0,1,1,0] monoclinicx3 symmetry reduced : [0,1,0,1]

    [0,1,1,0] orthorhombic symmetry reduced : [0,1,0,1]

    [0,1,1,0] hexagonal symmetry reduced : [0,1,0,1]

    [0,1,1,0] tetragonal7 symmetry reduced : [0,1,0,1]

    [0,1,1,0] tetragonal6 symmetry reduced : [0,1,0,1]

    [0,1,1,0] trigonal7 symmetry reduced : [0,1,0,1]

    [0,1,1,0] trigonal6 symmetry reduced : [0,1,0,1]

    [0,1,1,0] cubic symmetry reduced : [0,1,0,1]

    [0,1,1,0] isotropic symmetry reduced : [0,1,0,1]

    [0,1,1,1] triclinic symmetry reduced : [0,1,1,1]
    [5,1] (matrix notation) reduced : [0,1,1,1]

    [0,1,1,1] monoclinicx2 symmetry reduced : [0,1,1,1]

    [0,1,1,1] monoclinicx3 symmetry reduced : [0,1,1,1]

    [0,1,1,1] orthorhombic symmetry reduced : [0,1,1,1]

    [0,1,1,1] hexagonal symmetry reduced : [0,1,1,1]

    [0,1,1,1] tetragonal7 symmetry reduced : [0,0,0,1]

    [0,1,1,1] tetragonal6 symmetry reduced : [0,1,1,1]

    [0,1,1,1] trigonal7 symmetry reduced : [0,1,1,1]

    [0,1,1,1] trigonal6 symmetry reduced : [0,1,1,1]

    [0,1,1,1] cubic symmetry reduced : [0,1,1,1]

    [0,1,1,1] isotropic symmetry reduced : [0,1,1,1]

    [0,1,1,2] triclinic symmetry reduced : [0,1,1,2]
    [5,3] (matrix notation) reduced : [0,1,1,2]

    [0,1,1,2] monoclinicx2 symmetry reduced : [0,1,1,2]

    [0,1,1,2] monoclinicx3 symmetry reduced : [0,1,1,2]

    [0,1,1,2] orthorhombic symmetry reduced : [0,1,1,2]

    [0,1,1,2] hexagonal symmetry reduced : [0,1,1,2]

    [0,1,1,2] tetragonal7 symmetry reduced : [0,1,1,2]

    [0,1,1,2] tetragonal6 symmetry reduced : [0,1,1,2]

    [0,1,1,2] trigonal7 symmetry reduced : [0,0,0,2]

    [0,1,1,2] trigonal6 symmetry reduced : [0,1,1,2]

    [0,1,1,2] cubic symmetry reduced : [0,1,1,2]

    [0,1,1,2] isotropic symmetry reduced : [0,1,1,2]

    [0,1,2,0] triclinic symmetry reduced : [0,1,0,2]
    [5,4] (matrix notation) reduced : [0,1,0,2]

    [0,1,2,0] monoclinicx2 symmetry reduced : [0,1,2,0]

    [0,1,2,0] monoclinicx3 symmetry reduced : [0,1,2,0]

    [0,1,2,0] orthorhombic symmetry reduced : [0,1,2,0]

    [0,1,2,0] hexagonal symmetry reduced : [0,1,2,0]

    [0,1,2,0] tetragonal7 symmetry reduced : [0,1,2,0]

    [0,1,2,0] tetragonal6 symmetry reduced : [0,1,2,0]

    [0,1,2,0] trigonal7 symmetry reduced : [0,0,1,2]

    [0,1,2,0] trigonal6 symmetry reduced : [0,0,1,2]

    [0,1,2,0] cubic symmetry reduced : [0,1,2,0]

    [0,1,2,0] isotropic symmetry reduced : [0,1,2,0]

    [0,1,2,1] triclinic symmetry reduced : [0,1,1,2]
    [5,3] (matrix notation) reduced : [0,1,1,2]

    [0,1,2,1] monoclinicx2 symmetry reduced : [0,1,1,2]

    [0,1,2,1] monoclinicx3 symmetry reduced : [0,1,2,1]

    [0,1,2,1] orthorhombic symmetry reduced : [0,1,2,1]

    [0,1,2,1] hexagonal symmetry reduced : [0,1,2,1]

    [0,1,2,1] tetragonal7 symmetry reduced : [0,1,2,1]

    [0,1,2,1] tetragonal6 symmetry reduced : [0,1,2,1]

    [0,1,2,1] trigonal7 symmetry reduced : [0,0,0,2]

    [0,1,2,1] trigonal6 symmetry reduced : [0,1,2,1]

    [0,1,2,1] cubic symmetry reduced : [0,1,2,1]

    [0,1,2,1] isotropic symmetry reduced : [0,1,2,1]

    [0,1,2,2] triclinic symmetry reduced : [0,1,2,2]
    [5,2] (matrix notation) reduced : [0,1,2,2]

    [0,1,2,2] monoclinicx2 symmetry reduced : [0,1,2,2]

    [0,1,2,2] monoclinicx3 symmetry reduced : [0,1,2,2]

    [0,1,2,2] orthorhombic symmetry reduced : [0,1,2,2]

    [0,1,2,2] hexagonal symmetry reduced : [0,1,2,2]

    [0,1,2,2] tetragonal7 symmetry reduced : [0,1,2,2]

    [0,1,2,2] tetragonal6 symmetry reduced : [0,1,2,2]

    [0,1,2,2] trigonal7 symmetry reduced : [0,1,2,2]

    [0,1,2,2] trigonal6 symmetry reduced : [0,1,2,2]

    [0,1,2,2] cubic symmetry reduced : [0,1,2,2]

    [0,1,2,2] isotropic symmetry reduced : [0,1,2,2]

    [0,2,0,0] triclinic symmetry reduced : [0,0,0,2]
    [4,0] (matrix notation) reduced : [0,0,0,2]

    [0,2,0,0] monoclinicx2 symmetry reduced : [0,0,0,2]

    [0,2,0,0] monoclinicx3 symmetry reduced : [0,2,0,0]

    [0,2,0,0] orthorhombic symmetry reduced : [0,2,0,0]

    [0,2,0,0] hexagonal symmetry reduced : [0,2,0,0]

    [0,2,0,0] tetragonal7 symmetry reduced : [0,2,0,0]

    [0,2,0,0] tetragonal6 symmetry reduced : [0,2,0,0]

    [0,2,0,0] trigonal7 symmetry reduced : [0,0,0,2]

    [0,2,0,0] trigonal6 symmetry reduced : [0,2,0,0]

    [0,2,0,0] cubic symmetry reduced : [0,2,0,0]

    [0,2,0,0] isotropic symmetry reduced : [0,2,0,0]

    [0,2,0,1] triclinic symmetry reduced : [0,1,0,2]
    [4,5] (matrix notation) reduced : [0,1,0,2]

    [0,2,0,1] monoclinicx2 symmetry reduced : [0,2,0,1]

    [0,2,0,1] monoclinicx3 symmetry reduced : [0,2,0,1]

    [0,2,0,1] orthorhombic symmetry reduced : [0,2,0,1]

    [0,2,0,1] hexagonal symmetry reduced : [0,2,0,1]

    [0,2,0,1] tetragonal7 symmetry reduced : [0,2,0,1]

    [0,2,0,1] tetragonal6 symmetry reduced : [0,2,0,1]

    [0,2,0,1] trigonal7 symmetry reduced : [0,0,1,2]

    [0,2,0,1] trigonal6 symmetry reduced : [0,0,1,2]

    [0,2,0,1] cubic symmetry reduced : [0,2,0,1]

    [0,2,0,1] isotropic symmetry reduced : [0,2,0,1]

    [0,2,0,2] triclinic symmetry reduced : [0,2,0,2]
    [4,4] (matrix notation) reduced : [0,2,0,2]

    [0,2,0,2] monoclinicx2 symmetry reduced : [0,2,0,2]

    [0,2,0,2] monoclinicx3 symmetry reduced : [0,2,0,2]

    [0,2,0,2] orthorhombic symmetry reduced : [0,2,0,2]

    [0,2,0,2] hexagonal symmetry reduced : [0,2,0,2]

    [0,2,0,2] tetragonal7 symmetry reduced : [0,2,0,2]

    [0,2,0,2] tetragonal6 symmetry reduced : [0,2,0,2]

    [0,2,0,2] trigonal7 symmetry reduced : [0,2,0,2]

    [0,2,0,2] trigonal6 symmetry reduced : [0,2,0,2]

    [0,2,0,2] cubic symmetry reduced : [0,1,0,1]

    [0,2,0,2] isotropic symmetry reduced : [0,1,0,1]

    [0,2,1,0] triclinic symmetry reduced : [0,1,0,2]
    [4,5] (matrix notation) reduced : [0,1,0,2]

    [0,2,1,0] monoclinicx2 symmetry reduced : [0,2,1,0]

    [0,2,1,0] monoclinicx3 symmetry reduced : [0,2,1,0]

    [0,2,1,0] orthorhombic symmetry reduced : [0,2,1,0]

    [0,2,1,0] hexagonal symmetry reduced : [0,2,1,0]

    [0,2,1,0] tetragonal7 symmetry reduced : [0,2,1,0]

    [0,2,1,0] tetragonal6 symmetry reduced : [0,2,1,0]

    [0,2,1,0] trigonal7 symmetry reduced : [0,0,1,2]

    [0,2,1,0] trigonal6 symmetry reduced : [0,0,1,2]

    [0,2,1,0] cubic symmetry reduced : [0,2,1,0]

    [0,2,1,0] isotropic symmetry reduced : [0,2,1,0]

    [0,2,1,1] triclinic symmetry reduced : [0,2,1,1]
    [4,1] (matrix notation) reduced : [0,2,1,1]

    [0,2,1,1] monoclinicx2 symmetry reduced : [0,2,1,1]

    [0,2,1,1] monoclinicx3 symmetry reduced : [0,2,1,1]

    [0,2,1,1] orthorhombic symmetry reduced : [0,2,1,1]

    [0,2,1,1] hexagonal symmetry reduced : [0,2,1,1]

    [0,2,1,1] tetragonal7 symmetry reduced : [0,2,1,1]

    [0,2,1,1] tetragonal6 symmetry reduced : [0,2,1,1]

    [0,2,1,1] trigonal7 symmetry reduced : [0,0,0,2]

    [0,2,1,1] trigonal6 symmetry reduced : [0,2,1,1]

    [0,2,1,1] cubic symmetry reduced : [0,2,1,1]

    [0,2,1,1] isotropic symmetry reduced : [0,2,1,1]

    [0,2,1,2] triclinic symmetry reduced : [0,2,1,2]
    [4,3] (matrix notation) reduced : [0,2,1,2]

    [0,2,1,2] monoclinicx2 symmetry reduced : [0,2,1,2]

    [0,2,1,2] monoclinicx3 symmetry reduced : [0,2,1,2]

    [0,2,1,2] orthorhombic symmetry reduced : [0,2,1,2]

    [0,2,1,2] hexagonal symmetry reduced : [0,2,1,2]

    [0,2,1,2] tetragonal7 symmetry reduced : [0,2,1,2]

    [0,2,1,2] tetragonal6 symmetry reduced : [0,2,1,2]

    [0,2,1,2] trigonal7 symmetry reduced : [0,2,1,2]

    [0,2,1,2] trigonal6 symmetry reduced : [0,2,1,2]

    [0,2,1,2] cubic symmetry reduced : [0,2,1,2]

    [0,2,1,2] isotropic symmetry reduced : [0,2,1,2]

    [0,2,2,0] triclinic symmetry reduced : [0,2,0,2]
    [4,4] (matrix notation) reduced : [0,2,0,2]

    [0,2,2,0] monoclinicx2 symmetry reduced : [0,2,0,2]

    [0,2,2,0] monoclinicx3 symmetry reduced : [0,2,0,2]

    [0,2,2,0] orthorhombic symmetry reduced : [0,2,0,2]

    [0,2,2,0] hexagonal symmetry reduced : [0,2,0,2]

    [0,2,2,0] tetragonal7 symmetry reduced : [0,2,0,2]

    [0,2,2,0] tetragonal6 symmetry reduced : [0,2,0,2]

    [0,2,2,0] trigonal7 symmetry reduced : [0,2,0,2]

    [0,2,2,0] trigonal6 symmetry reduced : [0,2,0,2]

    [0,2,2,0] cubic symmetry reduced : [0,1,0,1]

    [0,2,2,0] isotropic symmetry reduced : [0,1,0,1]

    [0,2,2,1] triclinic symmetry reduced : [0,2,1,2]
    [4,3] (matrix notation) reduced : [0,2,1,2]

    [0,2,2,1] monoclinicx2 symmetry reduced : [0,2,2,1]

    [0,2,2,1] monoclinicx3 symmetry reduced : [0,2,1,2]

    [0,2,2,1] orthorhombic symmetry reduced : [0,2,2,1]

    [0,2,2,1] hexagonal symmetry reduced : [0,2,2,1]

    [0,2,2,1] tetragonal7 symmetry reduced : [0,2,2,1]

    [0,2,2,1] tetragonal6 symmetry reduced : [0,2,2,1]

    [0,2,2,1] trigonal7 symmetry reduced : [0,2,2,1]

    [0,2,2,1] trigonal6 symmetry reduced : [0,2,2,1]

    [0,2,2,1] cubic symmetry reduced : [0,2,2,1]

    [0,2,2,1] isotropic symmetry reduced : [0,2,2,1]

    [0,2,2,2] triclinic symmetry reduced : [0,2,2,2]
    [4,2] (matrix notation) reduced : [0,2,2,2]

    [0,2,2,2] monoclinicx2 symmetry reduced : [0,2,2,2]

    [0,2,2,2] monoclinicx3 symmetry reduced : [0,2,2,2]

    [0,2,2,2] orthorhombic symmetry reduced : [0,2,2,2]

    [0,2,2,2] hexagonal symmetry reduced : [0,2,2,2]

    [0,2,2,2] tetragonal7 symmetry reduced : [0,2,2,2]

    [0,2,2,2] tetragonal6 symmetry reduced : [0,2,2,2]

    [0,2,2,2] trigonal7 symmetry reduced : [0,2,2,2]

    [0,2,2,2] trigonal6 symmetry reduced : [0,2,2,2]

    [0,2,2,2] cubic symmetry reduced : [0,2,2,2]

    [0,2,2,2] isotropic symmetry reduced : [0,2,2,2]

    [1,0,0,0] triclinic symmetry reduced : [0,0,0,1]
    [5,0] (matrix notation) reduced : [0,0,0,1]

    [1,0,0,0] monoclinicx2 symmetry reduced : [1,0,0,0]

    [1,0,0,0] monoclinicx3 symmetry reduced : [0,0,0,1]

    [1,0,0,0] orthorhombic symmetry reduced : [1,0,0,0]

    [1,0,0,0] hexagonal symmetry reduced : [1,0,0,0]

    [1,0,0,0] tetragonal7 symmetry reduced : [0,0,0,1]

    [1,0,0,0] tetragonal6 symmetry reduced : [1,0,0,0]

    [1,0,0,0] trigonal7 symmetry reduced : [1,0,0,0]

    [1,0,0,0] trigonal6 symmetry reduced : [1,0,0,0]

    [1,0,0,0] cubic symmetry reduced : [1,0,0,0]

    [1,0,0,0] isotropic symmetry reduced : [1,0,0,0]

    [1,0,0,1] triclinic symmetry reduced : [0,1,0,1]
    [5,5] (matrix notation) reduced : [0,1,0,1]

    [1,0,0,1] monoclinicx2 symmetry reduced : [0,1,0,1]

    [1,0,0,1] monoclinicx3 symmetry reduced : [0,1,0,1]

    [1,0,0,1] orthorhombic symmetry reduced : [0,1,0,1]

    [1,0,0,1] hexagonal symmetry reduced : [0,1,0,1]

    [1,0,0,1] tetragonal7 symmetry reduced : [0,1,0,1]

    [1,0,0,1] tetragonal6 symmetry reduced : [0,1,0,1]

    [1,0,0,1] trigonal7 symmetry reduced : [0,1,0,1]

    [1,0,0,1] trigonal6 symmetry reduced : [0,1,0,1]

    [1,0,0,1] cubic symmetry reduced : [0,1,0,1]

    [1,0,0,1] isotropic symmetry reduced : [0,1,0,1]

    [1,0,0,2] triclinic symmetry reduced : [0,1,0,2]
    [5,4] (matrix notation) reduced : [0,1,0,2]

    [1,0,0,2] monoclinicx2 symmetry reduced : [1,0,0,2]

    [1,0,0,2] monoclinicx3 symmetry reduced : [1,0,0,2]

    [1,0,0,2] orthorhombic symmetry reduced : [1,0,0,2]

    [1,0,0,2] hexagonal symmetry reduced : [1,0,0,2]

    [1,0,0,2] tetragonal7 symmetry reduced : [1,0,0,2]

    [1,0,0,2] tetragonal6 symmetry reduced : [1,0,0,2]

    [1,0,0,2] trigonal7 symmetry reduced : [0,0,1,2]

    [1,0,0,2] trigonal6 symmetry reduced : [0,0,1,2]

    [1,0,0,2] cubic symmetry reduced : [1,0,0,2]

    [1,0,0,2] isotropic symmetry reduced : [1,0,0,2]

    [1,0,1,0] triclinic symmetry reduced : [0,1,0,1]
    [5,5] (matrix notation) reduced : [0,1,0,1]

    [1,0,1,0] monoclinicx2 symmetry reduced : [0,1,0,1]

    [1,0,1,0] monoclinicx3 symmetry reduced : [0,1,0,1]

    [1,0,1,0] orthorhombic symmetry reduced : [0,1,0,1]

    [1,0,1,0] hexagonal symmetry reduced : [0,1,0,1]

    [1,0,1,0] tetragonal7 symmetry reduced : [0,1,0,1]

    [1,0,1,0] tetragonal6 symmetry reduced : [0,1,0,1]

    [1,0,1,0] trigonal7 symmetry reduced : [0,1,0,1]

    [1,0,1,0] trigonal6 symmetry reduced : [0,1,0,1]

    [1,0,1,0] cubic symmetry reduced : [0,1,0,1]

    [1,0,1,0] isotropic symmetry reduced : [0,1,0,1]

    [1,0,1,1] triclinic symmetry reduced : [0,1,1,1]
    [5,1] (matrix notation) reduced : [0,1,1,1]

    [1,0,1,1] monoclinicx2 symmetry reduced : [1,0,1,1]

    [1,0,1,1] monoclinicx3 symmetry reduced : [0,1,1,1]

    [1,0,1,1] orthorhombic symmetry reduced : [1,0,1,1]

    [1,0,1,1] hexagonal symmetry reduced : [1,0,1,1]

    [1,0,1,1] tetragonal7 symmetry reduced : [0,0,0,1]

    [1,0,1,1] tetragonal6 symmetry reduced : [1,0,1,1]

    [1,0,1,1] trigonal7 symmetry reduced : [1,0,1,1]

    [1,0,1,1] trigonal6 symmetry reduced : [1,0,1,1]

    [1,0,1,1] cubic symmetry reduced : [1,0,1,1]

    [1,0,1,1] isotropic symmetry reduced : [1,0,1,1]

    [1,0,1,2] triclinic symmetry reduced : [0,1,1,2]
    [5,3] (matrix notation) reduced : [0,1,1,2]

    [1,0,1,2] monoclinicx2 symmetry reduced : [0,1,1,2]

    [1,0,1,2] monoclinicx3 symmetry reduced : [1,0,1,2]

    [1,0,1,2] orthorhombic symmetry reduced : [1,0,1,2]

    [1,0,1,2] hexagonal symmetry reduced : [1,0,1,2]

    [1,0,1,2] tetragonal7 symmetry reduced : [1,0,1,2]

    [1,0,1,2] tetragonal6 symmetry reduced : [1,0,1,2]

    [1,0,1,2] trigonal7 symmetry reduced : [0,0,0,2]

    [1,0,1,2] trigonal6 symmetry reduced : [1,0,1,2]

    [1,0,1,2] cubic symmetry reduced : [1,0,1,2]

    [1,0,1,2] isotropic symmetry reduced : [1,0,1,2]

    [1,0,2,0] triclinic symmetry reduced : [0,1,0,2]
    [5,4] (matrix notation) reduced : [0,1,0,2]

    [1,0,2,0] monoclinicx2 symmetry reduced : [1,0,2,0]

    [1,0,2,0] monoclinicx3 symmetry reduced : [1,0,2,0]

    [1,0,2,0] orthorhombic symmetry reduced : [1,0,2,0]

    [1,0,2,0] hexagonal symmetry reduced : [1,0,2,0]

    [1,0,2,0] tetragonal7 symmetry reduced : [1,0,2,0]

    [1,0,2,0] tetragonal6 symmetry reduced : [1,0,2,0]

    [1,0,2,0] trigonal7 symmetry reduced : [0,0,1,2]

    [1,0,2,0] trigonal6 symmetry reduced : [0,0,1,2]

    [1,0,2,0] cubic symmetry reduced : [1,0,2,0]

    [1,0,2,0] isotropic symmetry reduced : [1,0,2,0]

    [1,0,2,1] triclinic symmetry reduced : [0,1,1,2]
    [5,3] (matrix notation) reduced : [0,1,1,2]

    [1,0,2,1] monoclinicx2 symmetry reduced : [0,1,1,2]

    [1,0,2,1] monoclinicx3 symmetry reduced : [1,0,2,1]

    [1,0,2,1] orthorhombic symmetry reduced : [1,0,2,1]

    [1,0,2,1] hexagonal symmetry reduced : [1,0,2,1]

    [1,0,2,1] tetragonal7 symmetry reduced : [1,0,2,1]

    [1,0,2,1] tetragonal6 symmetry reduced : [1,0,2,1]

    [1,0,2,1] trigonal7 symmetry reduced : [0,0,0,2]

    [1,0,2,1] trigonal6 symmetry reduced : [1,0,2,1]

    [1,0,2,1] cubic symmetry reduced : [1,0,2,1]

    [1,0,2,1] isotropic symmetry reduced : [1,0,2,1]

    [1,0,2,2] triclinic symmetry reduced : [0,1,2,2]
    [5,2] (matrix notation) reduced : [0,1,2,2]

    [1,0,2,2] monoclinicx2 symmetry reduced : [1,0,2,2]

    [1,0,2,2] monoclinicx3 symmetry reduced : [0,1,2,2]

    [1,0,2,2] orthorhombic symmetry reduced : [1,0,2,2]

    [1,0,2,2] hexagonal symmetry reduced : [1,0,2,2]

    [1,0,2,2] tetragonal7 symmetry reduced : [1,0,2,2]

    [1,0,2,2] tetragonal6 symmetry reduced : [1,0,2,2]

    [1,0,2,2] trigonal7 symmetry reduced : [1,0,2,2]

    [1,0,2,2] trigonal6 symmetry reduced : [1,0,2,2]

    [1,0,2,2] cubic symmetry reduced : [1,0,2,2]

    [1,0,2,2] isotropic symmetry reduced : [1,0,2,2]

    [1,1,0,0] triclinic symmetry reduced : [0,0,1,1]
    [1,0] (matrix notation) reduced : [0,0,1,1]

    [1,1,0,0] monoclinicx2 symmetry reduced : [0,0,1,1]

    [1,1,0,0] monoclinicx3 symmetry reduced : [0,0,1,1]

    [1,1,0,0] orthorhombic symmetry reduced : [0,0,1,1]

    [1,1,0,0] hexagonal symmetry reduced : [0,0,1,1]

    [1,1,0,0] tetragonal7 symmetry reduced : [0,0,1,1]

    [1,1,0,0] tetragonal6 symmetry reduced : [0,0,1,1]

    [1,1,0,0] trigonal7 symmetry reduced : [0,0,1,1]

    [1,1,0,0] trigonal6 symmetry reduced : [0,0,1,1]

    [1,1,0,0] cubic symmetry reduced : [0,0,1,1]

    [1,1,0,0] isotropic symmetry reduced : [0,0,1,1]

    [1,1,0,1] triclinic symmetry reduced : [0,1,1,1]
    [1,5] (matrix notation) reduced : [0,1,1,1]

    [1,1,0,1] monoclinicx2 symmetry reduced : [1,1,0,1]

    [1,1,0,1] monoclinicx3 symmetry reduced : [0,1,1,1]

    [1,1,0,1] orthorhombic symmetry reduced : [1,1,0,1]

    [1,1,0,1] hexagonal symmetry reduced : [1,1,0,1]

    [1,1,0,1] tetragonal7 symmetry reduced : [0,0,0,1]

    [1,1,0,1] tetragonal6 symmetry reduced : [1,1,0,1]

    [1,1,0,1] trigonal7 symmetry reduced : [1,1,0,1]

    [1,1,0,1] trigonal6 symmetry reduced : [1,1,0,1]

    [1,1,0,1] cubic symmetry reduced : [1,1,0,1]

    [1,1,0,1] isotropic symmetry reduced : [1,1,0,1]

    [1,1,0,2] triclinic symmetry reduced : [0,2,1,1]
    [1,4] (matrix notation) reduced : [0,2,1,1]

    [1,1,0,2] monoclinicx2 symmetry reduced : [0,2,1,1]

    [1,1,0,2] monoclinicx3 symmetry reduced : [1,1,0,2]

    [1,1,0,2] orthorhombic symmetry reduced : [1,1,0,2]

    [1,1,0,2] hexagonal symmetry reduced : [1,1,0,2]

    [1,1,0,2] tetragonal7 symmetry reduced : [1,1,0,2]

    [1,1,0,2] tetragonal6 symmetry reduced : [1,1,0,2]

    [1,1,0,2] trigonal7 symmetry reduced : [0,0,0,2]

    [1,1,0,2] trigonal6 symmetry reduced : [1,1,0,2]

    [1,1,0,2] cubic symmetry reduced : [1,1,0,2]

    [1,1,0,2] isotropic symmetry reduced : [1,1,0,2]

    [1,1,1,0] triclinic symmetry reduced : [0,1,1,1]
    [1,5] (matrix notation) reduced : [0,1,1,1]

    [1,1,1,0] monoclinicx2 symmetry reduced : [1,1,1,0]

    [1,1,1,0] monoclinicx3 symmetry reduced : [0,1,1,1]

    [1,1,1,0] orthorhombic symmetry reduced : [1,1,1,0]

    [1,1,1,0] hexagonal symmetry reduced : [1,1,1,0]

    [1,1,1,0] tetragonal7 symmetry reduced : [0,0,0,1]

    [1,1,1,0] tetragonal6 symmetry reduced : [1,1,1,0]

    [1,1,1,0] trigonal7 symmetry reduced : [1,1,1,0]

    [1,1,1,0] trigonal6 symmetry reduced : [1,1,1,0]

    [1,1,1,0] cubic symmetry reduced : [1,1,1,0]

    [1,1,1,0] isotropic symmetry reduced : [1,1,1,0]

    [1,1,1,1] triclinic symmetry reduced : [1,1,1,1]
    [1,1] (matrix notation) reduced : [1,1,1,1]

    [1,1,1,1] monoclinicx2 symmetry reduced : [1,1,1,1]

    [1,1,1,1] monoclinicx3 symmetry reduced : [1,1,1,1]

    [1,1,1,1] orthorhombic symmetry reduced : [1,1,1,1]

    [1,1,1,1] hexagonal symmetry reduced : [0,0,0,0]

    [1,1,1,1] tetragonal7 symmetry reduced : [0,0,0,0]

    [1,1,1,1] tetragonal6 symmetry reduced : [0,0,0,0]

    [1,1,1,1] trigonal7 symmetry reduced : [0,0,0,0]

    [1,1,1,1] trigonal6 symmetry reduced : [0,0,0,0]

    [1,1,1,1] cubic symmetry reduced : [0,0,0,0]

    [1,1,1,1] isotropic symmetry reduced : [0,0,0,0]

    [1,1,1,2] triclinic symmetry reduced : [1,1,1,2]
    [1,3] (matrix notation) reduced : [1,1,1,2]

    [1,1,1,2] monoclinicx2 symmetry reduced : [1,1,1,2]

    [1,1,1,2] monoclinicx3 symmetry reduced : [1,1,1,2]

    [1,1,1,2] orthorhombic symmetry reduced : [1,1,1,2]

    [1,1,1,2] hexagonal symmetry reduced : [1,1,1,2]

    [1,1,1,2] tetragonal7 symmetry reduced : [1,1,1,2]

    [1,1,1,2] tetragonal6 symmetry reduced : [1,1,1,2]

    [1,1,1,2] trigonal7 symmetry reduced : [0,0,1,2]

    [1,1,1,2] trigonal6 symmetry reduced : [0,0,1,2]

    [1,1,1,2] cubic symmetry reduced : [1,1,1,2]

    [1,1,1,2] isotropic symmetry reduced : [1,1,1,2]

    [1,1,2,0] triclinic symmetry reduced : [0,2,1,1]
    [1,4] (matrix notation) reduced : [0,2,1,1]

    [1,1,2,0] monoclinicx2 symmetry reduced : [0,2,1,1]

    [1,1,2,0] monoclinicx3 symmetry reduced : [1,1,2,0]

    [1,1,2,0] orthorhombic symmetry reduced : [1,1,2,0]

    [1,1,2,0] hexagonal symmetry reduced : [1,1,2,0]

    [1,1,2,0] tetragonal7 symmetry reduced : [1,1,2,0]

    [1,1,2,0] tetragonal6 symmetry reduced : [1,1,2,0]

    [1,1,2,0] trigonal7 symmetry reduced : [0,0,0,2]

    [1,1,2,0] trigonal6 symmetry reduced : [1,1,2,0]

    [1,1,2,0] cubic symmetry reduced : [1,1,2,0]

    [1,1,2,0] isotropic symmetry reduced : [1,1,2,0]

    [1,1,2,1] triclinic symmetry reduced : [1,1,1,2]
    [1,3] (matrix notation) reduced : [1,1,1,2]

    [1,1,2,1] monoclinicx2 symmetry reduced : [1,1,2,1]

    [1,1,2,1] monoclinicx3 symmetry reduced : [1,1,2,1]

    [1,1,2,1] orthorhombic symmetry reduced : [1,1,2,1]

    [1,1,2,1] hexagonal symmetry reduced : [1,1,2,1]

    [1,1,2,1] tetragonal7 symmetry reduced : [1,1,2,1]

    [1,1,2,1] tetragonal6 symmetry reduced : [1,1,2,1]

    [1,1,2,1] trigonal7 symmetry reduced : [0,0,1,2]

    [1,1,2,1] trigonal6 symmetry reduced : [0,0,1,2]

    [1,1,2,1] cubic symmetry reduced : [1,1,2,1]

    [1,1,2,1] isotropic symmetry reduced : [1,1,2,1]

    [1,1,2,2] triclinic symmetry reduced : [1,1,2,2]
    [1,2] (matrix notation) reduced : [1,1,2,2]

    [1,1,2,2] monoclinicx2 symmetry reduced : [1,1,2,2]

    [1,1,2,2] monoclinicx3 symmetry reduced : [1,1,2,2]

    [1,1,2,2] orthorhombic symmetry reduced : [1,1,2,2]

    [1,1,2,2] hexagonal symmetry reduced : [0,0,2,2]

    [1,1,2,2] tetragonal7 symmetry reduced : [0,0,2,2]

    [1,1,2,2] tetragonal6 symmetry reduced : [0,0,2,2]

    [1,1,2,2] trigonal7 symmetry reduced : [0,0,2,2]

    [1,1,2,2] trigonal6 symmetry reduced : [0,0,2,2]

    [1,1,2,2] cubic symmetry reduced : [0,0,1,1]

    [1,1,2,2] isotropic symmetry reduced : [0,0,1,1]

    [1,2,0,0] triclinic symmetry reduced : [0,0,1,2]
    [3,0] (matrix notation) reduced : [0,0,1,2]

    [1,2,0,0] monoclinicx2 symmetry reduced : [1,2,0,0]

    [1,2,0,0] monoclinicx3 symmetry reduced : [1,2,0,0]

    [1,2,0,0] orthorhombic symmetry reduced : [1,2,0,0]

    [1,2,0,0] hexagonal symmetry reduced : [1,2,0,0]

    [1,2,0,0] tetragonal7 symmetry reduced : [1,2,0,0]

    [1,2,0,0] tetragonal6 symmetry reduced : [1,2,0,0]

    [1,2,0,0] trigonal7 symmetry reduced : [0,0,1,2]

    [1,2,0,0] trigonal6 symmetry reduced : [0,0,1,2]

    [1,2,0,0] cubic symmetry reduced : [1,2,0,0]

    [1,2,0,0] isotropic symmetry reduced : [1,2,0,0]

    [1,2,0,1] triclinic symmetry reduced : [0,1,1,2]
    [3,5] (matrix notation) reduced : [0,1,1,2]

    [1,2,0,1] monoclinicx2 symmetry reduced : [0,1,1,2]

    [1,2,0,1] monoclinicx3 symmetry reduced : [1,2,0,1]

    [1,2,0,1] orthorhombic symmetry reduced : [1,2,0,1]

    [1,2,0,1] hexagonal symmetry reduced : [1,2,0,1]

    [1,2,0,1] tetragonal7 symmetry reduced : [1,2,0,1]

    [1,2,0,1] tetragonal6 symmetry reduced : [1,2,0,1]

    [1,2,0,1] trigonal7 symmetry reduced : [0,0,0,2]

    [1,2,0,1] trigonal6 symmetry reduced : [1,2,0,1]

    [1,2,0,1] cubic symmetry reduced : [1,2,0,1]

    [1,2,0,1] isotropic symmetry reduced : [1,2,0,1]

    [1,2,0,2] triclinic symmetry reduced : [0,2,1,2]
    [3,4] (matrix notation) reduced : [0,2,1,2]

    [1,2,0,2] monoclinicx2 symmetry reduced : [1,2,0,2]

    [1,2,0,2] monoclinicx3 symmetry reduced : [0,2,1,2]

    [1,2,0,2] orthorhombic symmetry reduced : [1,2,0,2]

    [1,2,0,2] hexagonal symmetry reduced : [1,2,0,2]

    [1,2,0,2] tetragonal7 symmetry reduced : [1,2,0,2]

    [1,2,0,2] tetragonal6 symmetry reduced : [1,2,0,2]

    [1,2,0,2] trigonal7 symmetry reduced : [1,2,0,2]

    [1,2,0,2] trigonal6 symmetry reduced : [1,2,0,2]

    [1,2,0,2] cubic symmetry reduced : [1,2,0,2]

    [1,2,0,2] isotropic symmetry reduced : [1,2,0,2]

    [1,2,1,0] triclinic symmetry reduced : [0,1,1,2]
    [3,5] (matrix notation) reduced : [0,1,1,2]

    [1,2,1,0] monoclinicx2 symmetry reduced : [0,1,1,2]

    [1,2,1,0] monoclinicx3 symmetry reduced : [1,2,1,0]

    [1,2,1,0] orthorhombic symmetry reduced : [1,2,1,0]

    [1,2,1,0] hexagonal symmetry reduced : [1,2,1,0]

    [1,2,1,0] tetragonal7 symmetry reduced : [1,2,1,0]

    [1,2,1,0] tetragonal6 symmetry reduced : [1,2,1,0]

    [1,2,1,0] trigonal7 symmetry reduced : [0,0,0,2]

    [1,2,1,0] trigonal6 symmetry reduced : [1,2,1,0]

    [1,2,1,0] cubic symmetry reduced : [1,2,1,0]

    [1,2,1,0] isotropic symmetry reduced : [1,2,1,0]

    [1,2,1,1] triclinic symmetry reduced : [1,1,1,2]
    [3,1] (matrix notation) reduced : [1,1,1,2]

    [1,2,1,1] monoclinicx2 symmetry reduced : [1,2,1,1]

    [1,2,1,1] monoclinicx3 symmetry reduced : [1,2,1,1]

    [1,2,1,1] orthorhombic symmetry reduced : [1,2,1,1]

    [1,2,1,1] hexagonal symmetry reduced : [1,2,1,1]

    [1,2,1,1] tetragonal7 symmetry reduced : [1,2,1,1]

    [1,2,1,1] tetragonal6 symmetry reduced : [1,2,1,1]

    [1,2,1,1] trigonal7 symmetry reduced : [0,0,1,2]

    [1,2,1,1] trigonal6 symmetry reduced : [0,0,1,2]

    [1,2,1,1] cubic symmetry reduced : [1,2,1,1]

    [1,2,1,1] isotropic symmetry reduced : [1,2,1,1]

    [1,2,1,2] triclinic symmetry reduced : [1,2,1,2]
    [3,3] (matrix notation) reduced : [1,2,1,2]

    [1,2,1,2] monoclinicx2 symmetry reduced : [1,2,1,2]

    [1,2,1,2] monoclinicx3 symmetry reduced : [1,2,1,2]

    [1,2,1,2] orthorhombic symmetry reduced : [1,2,1,2]

    [1,2,1,2] hexagonal symmetry reduced : [0,2,0,2]

    [1,2,1,2] tetragonal7 symmetry reduced : [0,2,0,2]

    [1,2,1,2] tetragonal6 symmetry reduced : [0,2,0,2]

    [1,2,1,2] trigonal7 symmetry reduced : [0,2,0,2]

    [1,2,1,2] trigonal6 symmetry reduced : [0,2,0,2]

    [1,2,1,2] cubic symmetry reduced : [0,1,0,1]

    [1,2,1,2] isotropic symmetry reduced : [0,1,0,1]

    [1,2,2,0] triclinic symmetry reduced : [0,2,1,2]
    [3,4] (matrix notation) reduced : [0,2,1,2]

    [1,2,2,0] monoclinicx2 symmetry reduced : [1,2,2,0]

    [1,2,2,0] monoclinicx3 symmetry reduced : [0,2,1,2]

    [1,2,2,0] orthorhombic symmetry reduced : [1,2,2,0]

    [1,2,2,0] hexagonal symmetry reduced : [1,2,2,0]

    [1,2,2,0] tetragonal7 symmetry reduced : [1,2,2,0]

    [1,2,2,0] tetragonal6 symmetry reduced : [1,2,2,0]

    [1,2,2,0] trigonal7 symmetry reduced : [1,2,2,0]

    [1,2,2,0] trigonal6 symmetry reduced : [1,2,2,0]

    [1,2,2,0] cubic symmetry reduced : [1,2,2,0]

    [1,2,2,0] isotropic symmetry reduced : [1,2,2,0]

    [1,2,2,1] triclinic symmetry reduced : [1,2,1,2]
    [3,3] (matrix notation) reduced : [1,2,1,2]

    [1,2,2,1] monoclinicx2 symmetry reduced : [1,2,1,2]

    [1,2,2,1] monoclinicx3 symmetry reduced : [1,2,1,2]

    [1,2,2,1] orthorhombic symmetry reduced : [1,2,1,2]

    [1,2,2,1] hexagonal symmetry reduced : [0,2,0,2]

    [1,2,2,1] tetragonal7 symmetry reduced : [0,2,0,2]

    [1,2,2,1] tetragonal6 symmetry reduced : [0,2,0,2]

    [1,2,2,1] trigonal7 symmetry reduced : [0,2,0,2]

    [1,2,2,1] trigonal6 symmetry reduced : [0,2,0,2]

    [1,2,2,1] cubic symmetry reduced : [0,1,0,1]

    [1,2,2,1] isotropic symmetry reduced : [0,1,0,1]

    [1,2,2,2] triclinic symmetry reduced : [1,2,2,2]
    [3,2] (matrix notation) reduced : [1,2,2,2]

    [1,2,2,2] monoclinicx2 symmetry reduced : [1,2,2,2]

    [1,2,2,2] monoclinicx3 symmetry reduced : [1,2,2,2]

    [1,2,2,2] orthorhombic symmetry reduced : [1,2,2,2]

    [1,2,2,2] hexagonal symmetry reduced : [1,2,2,2]

    [1,2,2,2] tetragonal7 symmetry reduced : [1,2,2,2]

    [1,2,2,2] tetragonal6 symmetry reduced : [1,2,2,2]

    [1,2,2,2] trigonal7 symmetry reduced : [1,2,2,2]

    [1,2,2,2] trigonal6 symmetry reduced : [1,2,2,2]

    [1,2,2,2] cubic symmetry reduced : [1,2,2,2]

    [1,2,2,2] isotropic symmetry reduced : [1,2,2,2]

    [2,0,0,0] triclinic symmetry reduced : [0,0,0,2]
    [4,0] (matrix notation) reduced : [0,0,0,2]

    [2,0,0,0] monoclinicx2 symmetry reduced : [0,0,0,2]

    [2,0,0,0] monoclinicx3 symmetry reduced : [2,0,0,0]

    [2,0,0,0] orthorhombic symmetry reduced : [2,0,0,0]

    [2,0,0,0] hexagonal symmetry reduced : [2,0,0,0]

    [2,0,0,0] tetragonal7 symmetry reduced : [2,0,0,0]

    [2,0,0,0] tetragonal6 symmetry reduced : [2,0,0,0]

    [2,0,0,0] trigonal7 symmetry reduced : [0,0,0,2]

    [2,0,0,0] trigonal6 symmetry reduced : [2,0,0,0]

    [2,0,0,0] cubic symmetry reduced : [2,0,0,0]

    [2,0,0,0] isotropic symmetry reduced : [2,0,0,0]

    [2,0,0,1] triclinic symmetry reduced : [0,1,0,2]
    [4,5] (matrix notation) reduced : [0,1,0,2]

    [2,0,0,1] monoclinicx2 symmetry reduced : [2,0,0,1]

    [2,0,0,1] monoclinicx3 symmetry reduced : [2,0,0,1]

    [2,0,0,1] orthorhombic symmetry reduced : [2,0,0,1]

    [2,0,0,1] hexagonal symmetry reduced : [2,0,0,1]

    [2,0,0,1] tetragonal7 symmetry reduced : [2,0,0,1]

    [2,0,0,1] tetragonal6 symmetry reduced : [2,0,0,1]

    [2,0,0,1] trigonal7 symmetry reduced : [0,0,1,2]

    [2,0,0,1] trigonal6 symmetry reduced : [0,0,1,2]

    [2,0,0,1] cubic symmetry reduced : [2,0,0,1]

    [2,0,0,1] isotropic symmetry reduced : [2,0,0,1]

    [2,0,0,2] triclinic symmetry reduced : [0,2,0,2]
    [4,4] (matrix notation) reduced : [0,2,0,2]

    [2,0,0,2] monoclinicx2 symmetry reduced : [0,2,0,2]

    [2,0,0,2] monoclinicx3 symmetry reduced : [0,2,0,2]

    [2,0,0,2] orthorhombic symmetry reduced : [0,2,0,2]

    [2,0,0,2] hexagonal symmetry reduced : [0,2,0,2]

    [2,0,0,2] tetragonal7 symmetry reduced : [0,2,0,2]

    [2,0,0,2] tetragonal6 symmetry reduced : [0,2,0,2]

    [2,0,0,2] trigonal7 symmetry reduced : [0,2,0,2]

    [2,0,0,2] trigonal6 symmetry reduced : [0,2,0,2]

    [2,0,0,2] cubic symmetry reduced : [0,1,0,1]

    [2,0,0,2] isotropic symmetry reduced : [0,1,0,1]

    [2,0,1,0] triclinic symmetry reduced : [0,1,0,2]
    [4,5] (matrix notation) reduced : [0,1,0,2]

    [2,0,1,0] monoclinicx2 symmetry reduced : [2,0,1,0]

    [2,0,1,0] monoclinicx3 symmetry reduced : [2,0,1,0]

    [2,0,1,0] orthorhombic symmetry reduced : [2,0,1,0]

    [2,0,1,0] hexagonal symmetry reduced : [2,0,1,0]

    [2,0,1,0] tetragonal7 symmetry reduced : [2,0,1,0]

    [2,0,1,0] tetragonal6 symmetry reduced : [2,0,1,0]

    [2,0,1,0] trigonal7 symmetry reduced : [0,0,1,2]

    [2,0,1,0] trigonal6 symmetry reduced : [0,0,1,2]

    [2,0,1,0] cubic symmetry reduced : [2,0,1,0]

    [2,0,1,0] isotropic symmetry reduced : [2,0,1,0]

    [2,0,1,1] triclinic symmetry reduced : [0,2,1,1]
    [4,1] (matrix notation) reduced : [0,2,1,1]

    [2,0,1,1] monoclinicx2 symmetry reduced : [0,2,1,1]

    [2,0,1,1] monoclinicx3 symmetry reduced : [2,0,1,1]

    [2,0,1,1] orthorhombic symmetry reduced : [2,0,1,1]

    [2,0,1,1] hexagonal symmetry reduced : [2,0,1,1]

    [2,0,1,1] tetragonal7 symmetry reduced : [2,0,1,1]

    [2,0,1,1] tetragonal6 symmetry reduced : [2,0,1,1]

    [2,0,1,1] trigonal7 symmetry reduced : [0,0,0,2]

    [2,0,1,1] trigonal6 symmetry reduced : [2,0,1,1]

    [2,0,1,1] cubic symmetry reduced : [2,0,1,1]

    [2,0,1,1] isotropic symmetry reduced : [2,0,1,1]

    [2,0,1,2] triclinic symmetry reduced : [0,2,1,2]
    [4,3] (matrix notation) reduced : [0,2,1,2]

    [2,0,1,2] monoclinicx2 symmetry reduced : [2,0,1,2]

    [2,0,1,2] monoclinicx3 symmetry reduced : [0,2,1,2]

    [2,0,1,2] orthorhombic symmetry reduced : [2,0,1,2]

    [2,0,1,2] hexagonal symmetry reduced : [2,0,1,2]

    [2,0,1,2] tetragonal7 symmetry reduced : [2,0,1,2]

    [2,0,1,2] tetragonal6 symmetry reduced : [2,0,1,2]

    [2,0,1,2] trigonal7 symmetry reduced : [2,0,1,2]

    [2,0,1,2] trigonal6 symmetry reduced : [2,0,1,2]

    [2,0,1,2] cubic symmetry reduced : [2,0,1,2]

    [2,0,1,2] isotropic symmetry reduced : [2,0,1,2]

    [2,0,2,0] triclinic symmetry reduced : [0,2,0,2]
    [4,4] (matrix notation) reduced : [0,2,0,2]

    [2,0,2,0] monoclinicx2 symmetry reduced : [0,2,0,2]

    [2,0,2,0] monoclinicx3 symmetry reduced : [0,2,0,2]

    [2,0,2,0] orthorhombic symmetry reduced : [0,2,0,2]

    [2,0,2,0] hexagonal symmetry reduced : [0,2,0,2]

    [2,0,2,0] tetragonal7 symmetry reduced : [0,2,0,2]

    [2,0,2,0] tetragonal6 symmetry reduced : [0,2,0,2]

    [2,0,2,0] trigonal7 symmetry reduced : [0,2,0,2]

    [2,0,2,0] trigonal6 symmetry reduced : [0,2,0,2]

    [2,0,2,0] cubic symmetry reduced : [0,1,0,1]

    [2,0,2,0] isotropic symmetry reduced : [0,1,0,1]

    [2,0,2,1] triclinic symmetry reduced : [0,2,1,2]
    [4,3] (matrix notation) reduced : [0,2,1,2]

    [2,0,2,1] monoclinicx2 symmetry reduced : [2,0,2,1]

    [2,0,2,1] monoclinicx3 symmetry reduced : [0,2,1,2]

    [2,0,2,1] orthorhombic symmetry reduced : [2,0,2,1]

    [2,0,2,1] hexagonal symmetry reduced : [2,0,2,1]

    [2,0,2,1] tetragonal7 symmetry reduced : [2,0,2,1]

    [2,0,2,1] tetragonal6 symmetry reduced : [2,0,2,1]

    [2,0,2,1] trigonal7 symmetry reduced : [2,0,2,1]

    [2,0,2,1] trigonal6 symmetry reduced : [2,0,2,1]

    [2,0,2,1] cubic symmetry reduced : [2,0,2,1]

    [2,0,2,1] isotropic symmetry reduced : [2,0,2,1]

    [2,0,2,2] triclinic symmetry reduced : [0,2,2,2]
    [4,2] (matrix notation) reduced : [0,2,2,2]

    [2,0,2,2] monoclinicx2 symmetry reduced : [0,2,2,2]

    [2,0,2,2] monoclinicx3 symmetry reduced : [2,0,2,2]

    [2,0,2,2] orthorhombic symmetry reduced : [2,0,2,2]

    [2,0,2,2] hexagonal symmetry reduced : [2,0,2,2]

    [2,0,2,2] tetragonal7 symmetry reduced : [2,0,2,2]

    [2,0,2,2] tetragonal6 symmetry reduced : [2,0,2,2]

    [2,0,2,2] trigonal7 symmetry reduced : [2,0,2,2]

    [2,0,2,2] trigonal6 symmetry reduced : [2,0,2,2]

    [2,0,2,2] cubic symmetry reduced : [2,0,2,2]

    [2,0,2,2] isotropic symmetry reduced : [2,0,2,2]

    [2,1,0,0] triclinic symmetry reduced : [0,0,1,2]
    [3,0] (matrix notation) reduced : [0,0,1,2]

    [2,1,0,0] monoclinicx2 symmetry reduced : [2,1,0,0]

    [2,1,0,0] monoclinicx3 symmetry reduced : [2,1,0,0]

    [2,1,0,0] orthorhombic symmetry reduced : [2,1,0,0]

    [2,1,0,0] hexagonal symmetry reduced : [2,1,0,0]

    [2,1,0,0] tetragonal7 symmetry reduced : [2,1,0,0]

    [2,1,0,0] tetragonal6 symmetry reduced : [2,1,0,0]

    [2,1,0,0] trigonal7 symmetry reduced : [0,0,1,2]

    [2,1,0,0] trigonal6 symmetry reduced : [0,0,1,2]

    [2,1,0,0] cubic symmetry reduced : [2,1,0,0]

    [2,1,0,0] isotropic symmetry reduced : [2,1,0,0]

    [2,1,0,1] triclinic symmetry reduced : [0,1,1,2]
    [3,5] (matrix notation) reduced : [0,1,1,2]

    [2,1,0,1] monoclinicx2 symmetry reduced : [0,1,1,2]

    [2,1,0,1] monoclinicx3 symmetry reduced : [2,1,0,1]

    [2,1,0,1] orthorhombic symmetry reduced : [2,1,0,1]

    [2,1,0,1] hexagonal symmetry reduced : [2,1,0,1]

    [2,1,0,1] tetragonal7 symmetry reduced : [2,1,0,1]

    [2,1,0,1] tetragonal6 symmetry reduced : [2,1,0,1]

    [2,1,0,1] trigonal7 symmetry reduced : [0,0,0,2]

    [2,1,0,1] trigonal6 symmetry reduced : [2,1,0,1]

    [2,1,0,1] cubic symmetry reduced : [2,1,0,1]

    [2,1,0,1] isotropic symmetry reduced : [2,1,0,1]

    [2,1,0,2] triclinic symmetry reduced : [0,2,1,2]
    [3,4] (matrix notation) reduced : [0,2,1,2]

    [2,1,0,2] monoclinicx2 symmetry reduced : [2,1,0,2]

    [2,1,0,2] monoclinicx3 symmetry reduced : [0,2,1,2]

    [2,1,0,2] orthorhombic symmetry reduced : [2,1,0,2]

    [2,1,0,2] hexagonal symmetry reduced : [2,1,0,2]

    [2,1,0,2] tetragonal7 symmetry reduced : [2,1,0,2]

    [2,1,0,2] tetragonal6 symmetry reduced : [2,1,0,2]

    [2,1,0,2] trigonal7 symmetry reduced : [2,1,0,2]

    [2,1,0,2] trigonal6 symmetry reduced : [2,1,0,2]

    [2,1,0,2] cubic symmetry reduced : [2,1,0,2]

    [2,1,0,2] isotropic symmetry reduced : [2,1,0,2]

    [2,1,1,0] triclinic symmetry reduced : [0,1,1,2]
    [3,5] (matrix notation) reduced : [0,1,1,2]

    [2,1,1,0] monoclinicx2 symmetry reduced : [0,1,1,2]

    [2,1,1,0] monoclinicx3 symmetry reduced : [2,1,1,0]

    [2,1,1,0] orthorhombic symmetry reduced : [2,1,1,0]

    [2,1,1,0] hexagonal symmetry reduced : [2,1,1,0]

    [2,1,1,0] tetragonal7 symmetry reduced : [2,1,1,0]

    [2,1,1,0] tetragonal6 symmetry reduced : [2,1,1,0]

    [2,1,1,0] trigonal7 symmetry reduced : [0,0,0,2]

    [2,1,1,0] trigonal6 symmetry reduced : [2,1,1,0]

    [2,1,1,0] cubic symmetry reduced : [2,1,1,0]

    [2,1,1,0] isotropic symmetry reduced : [2,1,1,0]

    [2,1,1,1] triclinic symmetry reduced : [1,1,1,2]
    [3,1] (matrix notation) reduced : [1,1,1,2]

    [2,1,1,1] monoclinicx2 symmetry reduced : [2,1,1,1]

    [2,1,1,1] monoclinicx3 symmetry reduced : [2,1,1,1]

    [2,1,1,1] orthorhombic symmetry reduced : [2,1,1,1]

    [2,1,1,1] hexagonal symmetry reduced : [2,1,1,1]

    [2,1,1,1] tetragonal7 symmetry reduced : [2,1,1,1]

    [2,1,1,1] tetragonal6 symmetry reduced : [2,1,1,1]

    [2,1,1,1] trigonal7 symmetry reduced : [0,0,1,2]

    [2,1,1,1] trigonal6 symmetry reduced : [0,0,1,2]

    [2,1,1,1] cubic symmetry reduced : [2,1,1,1]

    [2,1,1,1] isotropic symmetry reduced : [2,1,1,1]

    [2,1,1,2] triclinic symmetry reduced : [1,2,1,2]
    [3,3] (matrix notation) reduced : [1,2,1,2]

    [2,1,1,2] monoclinicx2 symmetry reduced : [1,2,1,2]

    [2,1,1,2] monoclinicx3 symmetry reduced : [1,2,1,2]

    [2,1,1,2] orthorhombic symmetry reduced : [1,2,1,2]

    [2,1,1,2] hexagonal symmetry reduced : [0,2,0,2]

    [2,1,1,2] tetragonal7 symmetry reduced : [0,2,0,2]

    [2,1,1,2] tetragonal6 symmetry reduced : [0,2,0,2]

    [2,1,1,2] trigonal7 symmetry reduced : [0,2,0,2]

    [2,1,1,2] trigonal6 symmetry reduced : [0,2,0,2]

    [2,1,1,2] cubic symmetry reduced : [0,1,0,1]

    [2,1,1,2] isotropic symmetry reduced : [0,1,0,1]

    [2,1,2,0] triclinic symmetry reduced : [0,2,1,2]
    [3,4] (matrix notation) reduced : [0,2,1,2]

    [2,1,2,0] monoclinicx2 symmetry reduced : [2,1,2,0]

    [2,1,2,0] monoclinicx3 symmetry reduced : [0,2,1,2]

    [2,1,2,0] orthorhombic symmetry reduced : [2,1,2,0]

    [2,1,2,0] hexagonal symmetry reduced : [2,1,2,0]

    [2,1,2,0] tetragonal7 symmetry reduced : [2,1,2,0]

    [2,1,2,0] tetragonal6 symmetry reduced : [2,1,2,0]

    [2,1,2,0] trigonal7 symmetry reduced : [2,1,2,0]

    [2,1,2,0] trigonal6 symmetry reduced : [2,1,2,0]

    [2,1,2,0] cubic symmetry reduced : [2,1,2,0]

    [2,1,2,0] isotropic symmetry reduced : [2,1,2,0]

    [2,1,2,1] triclinic symmetry reduced : [1,2,1,2]
    [3,3] (matrix notation) reduced : [1,2,1,2]

    [2,1,2,1] monoclinicx2 symmetry reduced : [1,2,1,2]

    [2,1,2,1] monoclinicx3 symmetry reduced : [1,2,1,2]

    [2,1,2,1] orthorhombic symmetry reduced : [1,2,1,2]

    [2,1,2,1] hexagonal symmetry reduced : [0,2,0,2]

    [2,1,2,1] tetragonal7 symmetry reduced : [0,2,0,2]

    [2,1,2,1] tetragonal6 symmetry reduced : [0,2,0,2]

    [2,1,2,1] trigonal7 symmetry reduced : [0,2,0,2]

    [2,1,2,1] trigonal6 symmetry reduced : [0,2,0,2]

    [2,1,2,1] cubic symmetry reduced : [0,1,0,1]

    [2,1,2,1] isotropic symmetry reduced : [0,1,0,1]

    [2,1,2,2] triclinic symmetry reduced : [1,2,2,2]
    [3,2] (matrix notation) reduced : [1,2,2,2]

    [2,1,2,2] monoclinicx2 symmetry reduced : [2,1,2,2]

    [2,1,2,2] monoclinicx3 symmetry reduced : [2,1,2,2]

    [2,1,2,2] orthorhombic symmetry reduced : [2,1,2,2]

    [2,1,2,2] hexagonal symmetry reduced : [2,1,2,2]

    [2,1,2,2] tetragonal7 symmetry reduced : [2,1,2,2]

    [2,1,2,2] tetragonal6 symmetry reduced : [2,1,2,2]

    [2,1,2,2] trigonal7 symmetry reduced : [2,1,2,2]

    [2,1,2,2] trigonal6 symmetry reduced : [2,1,2,2]

    [2,1,2,2] cubic symmetry reduced : [2,1,2,2]

    [2,1,2,2] isotropic symmetry reduced : [2,1,2,2]

    [2,2,0,0] triclinic symmetry reduced : [0,0,2,2]
    [2,0] (matrix notation) reduced : [0,0,2,2]

    [2,2,0,0] monoclinicx2 symmetry reduced : [0,0,2,2]

    [2,2,0,0] monoclinicx3 symmetry reduced : [0,0,2,2]

    [2,2,0,0] orthorhombic symmetry reduced : [0,0,2,2]

    [2,2,0,0] hexagonal symmetry reduced : [0,0,2,2]

    [2,2,0,0] tetragonal7 symmetry reduced : [0,0,2,2]

    [2,2,0,0] tetragonal6 symmetry reduced : [0,0,2,2]

    [2,2,0,0] trigonal7 symmetry reduced : [0,0,2,2]

    [2,2,0,0] trigonal6 symmetry reduced : [0,0,2,2]

    [2,2,0,0] cubic symmetry reduced : [0,0,1,1]

    [2,2,0,0] isotropic symmetry reduced : [0,0,1,1]

    [2,2,0,1] triclinic symmetry reduced : [0,1,2,2]
    [2,5] (matrix notation) reduced : [0,1,2,2]

    [2,2,0,1] monoclinicx2 symmetry reduced : [2,2,0,1]

    [2,2,0,1] monoclinicx3 symmetry reduced : [0,1,2,2]

    [2,2,0,1] orthorhombic symmetry reduced : [2,2,0,1]

    [2,2,0,1] hexagonal symmetry reduced : [2,2,0,1]

    [2,2,0,1] tetragonal7 symmetry reduced : [2,2,0,1]

    [2,2,0,1] tetragonal6 symmetry reduced : [2,2,0,1]

    [2,2,0,1] trigonal7 symmetry reduced : [2,2,0,1]

    [2,2,0,1] trigonal6 symmetry reduced : [2,2,0,1]

    [2,2,0,1] cubic symmetry reduced : [2,2,0,1]

    [2,2,0,1] isotropic symmetry reduced : [2,2,0,1]

    [2,2,0,2] triclinic symmetry reduced : [0,2,2,2]
    [2,4] (matrix notation) reduced : [0,2,2,2]

    [2,2,0,2] monoclinicx2 symmetry reduced : [0,2,2,2]

    [2,2,0,2] monoclinicx3 symmetry reduced : [2,2,0,2]

    [2,2,0,2] orthorhombic symmetry reduced : [2,2,0,2]

    [2,2,0,2] hexagonal symmetry reduced : [2,2,0,2]

    [2,2,0,2] tetragonal7 symmetry reduced : [2,2,0,2]

    [2,2,0,2] tetragonal6 symmetry reduced : [2,2,0,2]

    [2,2,0,2] trigonal7 symmetry reduced : [2,2,0,2]

    [2,2,0,2] trigonal6 symmetry reduced : [2,2,0,2]

    [2,2,0,2] cubic symmetry reduced : [2,2,0,2]

    [2,2,0,2] isotropic symmetry reduced : [2,2,0,2]

    [2,2,1,0] triclinic symmetry reduced : [0,1,2,2]
    [2,5] (matrix notation) reduced : [0,1,2,2]

    [2,2,1,0] monoclinicx2 symmetry reduced : [2,2,1,0]

    [2,2,1,0] monoclinicx3 symmetry reduced : [0,1,2,2]

    [2,2,1,0] orthorhombic symmetry reduced : [2,2,1,0]

    [2,2,1,0] hexagonal symmetry reduced : [2,2,1,0]

    [2,2,1,0] tetragonal7 symmetry reduced : [2,2,1,0]

    [2,2,1,0] tetragonal6 symmetry reduced : [2,2,1,0]

    [2,2,1,0] trigonal7 symmetry reduced : [2,2,1,0]

    [2,2,1,0] trigonal6 symmetry reduced : [2,2,1,0]

    [2,2,1,0] cubic symmetry reduced : [2,2,1,0]

    [2,2,1,0] isotropic symmetry reduced : [2,2,1,0]

    [2,2,1,1] triclinic symmetry reduced : [1,1,2,2]
    [2,1] (matrix notation) reduced : [1,1,2,2]

    [2,2,1,1] monoclinicx2 symmetry reduced : [1,1,2,2]

    [2,2,1,1] monoclinicx3 symmetry reduced : [1,1,2,2]

    [2,2,1,1] orthorhombic symmetry reduced : [1,1,2,2]

    [2,2,1,1] hexagonal symmetry reduced : [0,0,2,2]

    [2,2,1,1] tetragonal7 symmetry reduced : [0,0,2,2]

    [2,2,1,1] tetragonal6 symmetry reduced : [0,0,2,2]

    [2,2,1,1] trigonal7 symmetry reduced : [0,0,2,2]

    [2,2,1,1] trigonal6 symmetry reduced : [0,0,2,2]

    [2,2,1,1] cubic symmetry reduced : [0,0,1,1]

    [2,2,1,1] isotropic symmetry reduced : [0,0,1,1]

    [2,2,1,2] triclinic symmetry reduced : [1,2,2,2]
    [2,3] (matrix notation) reduced : [1,2,2,2]

    [2,2,1,2] monoclinicx2 symmetry reduced : [2,2,1,2]

    [2,2,1,2] monoclinicx3 symmetry reduced : [2,2,1,2]

    [2,2,1,2] orthorhombic symmetry reduced : [2,2,1,2]

    [2,2,1,2] hexagonal symmetry reduced : [2,2,1,2]

    [2,2,1,2] tetragonal7 symmetry reduced : [2,2,1,2]

    [2,2,1,2] tetragonal6 symmetry reduced : [2,2,1,2]

    [2,2,1,2] trigonal7 symmetry reduced : [2,2,1,2]

    [2,2,1,2] trigonal6 symmetry reduced : [2,2,1,2]

    [2,2,1,2] cubic symmetry reduced : [2,2,1,2]

    [2,2,1,2] isotropic symmetry reduced : [2,2,1,2]

    [2,2,2,0] triclinic symmetry reduced : [0,2,2,2]
    [2,4] (matrix notation) reduced : [0,2,2,2]

    [2,2,2,0] monoclinicx2 symmetry reduced : [0,2,2,2]

    [2,2,2,0] monoclinicx3 symmetry reduced : [2,2,2,0]

    [2,2,2,0] orthorhombic symmetry reduced : [2,2,2,0]

    [2,2,2,0] hexagonal symmetry reduced : [2,2,2,0]

    [2,2,2,0] tetragonal7 symmetry reduced : [2,2,2,0]

    [2,2,2,0] tetragonal6 symmetry reduced : [2,2,2,0]

    [2,2,2,0] trigonal7 symmetry reduced : [2,2,2,0]

    [2,2,2,0] trigonal6 symmetry reduced : [2,2,2,0]

    [2,2,2,0] cubic symmetry reduced : [2,2,2,0]

    [2,2,2,0] isotropic symmetry reduced : [2,2,2,0]

    [2,2,2,1] triclinic symmetry reduced : [1,2,2,2]
    [2,3] (matrix notation) reduced : [1,2,2,2]

    [2,2,2,1] monoclinicx2 symmetry reduced : [2,2,2,1]

    [2,2,2,1] monoclinicx3 symmetry reduced : [2,2,2,1]

    [2,2,2,1] orthorhombic symmetry reduced : [2,2,2,1]

    [2,2,2,1] hexagonal symmetry reduced : [2,2,2,1]

    [2,2,2,1] tetragonal7 symmetry reduced : [2,2,2,1]

    [2,2,2,1] tetragonal6 symmetry reduced : [2,2,2,1]

    [2,2,2,1] trigonal7 symmetry reduced : [2,2,2,1]

    [2,2,2,1] trigonal6 symmetry reduced : [2,2,2,1]

    [2,2,2,1] cubic symmetry reduced : [2,2,2,1]

    [2,2,2,1] isotropic symmetry reduced : [2,2,2,1]

    [2,2,2,2] triclinic symmetry reduced : [2,2,2,2]
    [2,2] (matrix notation) reduced : [2,2,2,2]

    [2,2,2,2] monoclinicx2 symmetry reduced : [2,2,2,2]

    [2,2,2,2] monoclinicx3 symmetry reduced : [2,2,2,2]

    [2,2,2,2] orthorhombic symmetry reduced : [2,2,2,2]

    [2,2,2,2] hexagonal symmetry reduced : [2,2,2,2]

    [2,2,2,2] tetragonal7 symmetry reduced : [2,2,2,2]

    [2,2,2,2] tetragonal6 symmetry reduced : [2,2,2,2]

    [2,2,2,2] trigonal7 symmetry reduced : [2,2,2,2]

    [2,2,2,2] trigonal6 symmetry reduced : [2,2,2,2]

    [2,2,2,2] cubic symmetry reduced : [0,0,0,0]

    [2,2,2,2] isotropic symmetry reduced : [0,0,0,0]

The number of aliases in a reduced set can be determined from the following script
```cpp
int alias_counter = 0;
mpc::core::TensorRank4ComponentIndex indexXXXX_test = mpc::core::TensorRank4ComponentIndex(0,0,0,0);
std::set<mpc::core::TensorRank4ComponentIndex> reduced_set{};



std::cout << "\n=== none aliases a.k.a. reduced set" << std::endl;
// none
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::NoneSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::NoneSymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << std::endl;
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::NoneSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== triclinic aliases a.k.a. reduced set" << std::endl;
// triclinic
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::TriclinicSymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                // just a check...
                if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                    std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                }
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::TriclinicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== monoclinicx2 aliases a.k.a. reduced set" << std::endl;
// monoclinicx2
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX2SymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                    std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                }
                // print the matrix notation
                p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                if (p<q) {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                } else {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                }
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::MonoclinicX2SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== monoclinicx3 aliases a.k.a. reduced set" << std::endl;
// monoclinicx3
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::MonoclinicX3SymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                    std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                }
                // print the matrix notation
                p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                if (p<q) {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                } else {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                }
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::MonoclinicX3SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== orthorhombic aliases a.k.a. reduced set" << std::endl;
// orthorhombic
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::OrthorhombicSymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter
                          << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))<< std::endl;
                if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                    std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                }
                // print the matrix notation
                p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                if (p<q) {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                } else {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                }
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::OrthorhombicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== hexagonal aliases a.k.a. reduced set" << std::endl;
// hexagonal
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::HexagonalSymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                    std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                }
                // print the matrix notation
                p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                if (p<q) {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                } else {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                }
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::HexagonalSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== tetragonal7 aliases a.k.a. reduced set" << std::endl;
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal7SymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                    std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                }
                // print the matrix notation
                p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                if (p<q) {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                } else {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                }
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::Tetragonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== tetragonal6 aliases a.k.a. reduced set" << std::endl;
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Tetragonal6SymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                    std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                }
                // print the matrix notation
                p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                if (p<q) {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                } else {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                }
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::Tetragonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== trigonal7 aliases a.k.a. reduced set" << std::endl;
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal7SymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                    std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                }
                // print the matrix notation
                p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                if (p<q) {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                } else {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                }
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::Trigonal7SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== trigonal6 aliases a.k.a. reduced set" << std::endl;
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::Trigonal6SymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                    std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                }
                // print the matrix notation
                p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                if (p<q) {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                } else {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                }
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::Trigonal6SymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== cubic aliases a.k.a. reduced set" << std::endl;
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::CubicSymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                    std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                }
                // print the matrix notation
                p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                if (p<q) {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                } else {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                }
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::CubicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== isotropic aliases a.k.a. reduced set" << std::endl;
for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
        for (int k=0; k<3; ++k) {
            for (int l=0; l<3; ++l) {
                alias_counter = 0;
                indexXXXX_reduced = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto indexXXXX : vec_indexXXXX) {
                    indexXXXX_test = mpc::core::ReducedTensorRank4ComponentIndex<mpc::core::IsotropicSymmetryGroupType>(indexXXXX);
                    if (indexXXXX_reduced == indexXXXX_test) ++alias_counter;
                }
                std::cout << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << " alias_counter : " << alias_counter << " ? " << mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l)) << std::endl;
                if (alias_counter != mpc::core::TensorRank4IndexNumberOfAliases<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l))) {
                    std::cout << "    something went wrong!!! at index : " << mpc::core::TensorRank4ComponentIndex(i,j,k,l) << std::endl;
                }
                // print the matrix notation
                p = mpc::utilities::GetVoigtMatrixIndex(i, j);
                q = mpc::utilities::GetVoigtMatrixIndex(k, l);
                if (p<q) {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(p,q) << std::endl;
                } else {
                    std::cout << "  " << mpc::core::TensorRank2ComponentIndex(q,p) << std::endl;
                }
                reduced_set = mpc::core::TensorRank4IndexAliases<mpc::core::IsotropicSymmetryGroupType>(mpc::core::TensorRank4ComponentIndex(i,j,k,l));
                for (auto ss : reduced_set) {
                    std::cout << "    " << ss << std::endl;
                }
            }
        }
    }
}
```
Output

    === none aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 1
        [0,0,0,0]
    [0,0,0,1] alias_counter : 1
        [0,0,0,1]
    [0,0,0,2] alias_counter : 1
        [0,0,0,2]
    [0,0,1,0] alias_counter : 1
        [0,0,1,0]
    [0,0,1,1] alias_counter : 1
        [0,0,1,1]
    [0,0,1,2] alias_counter : 1
        [0,0,1,2]
    [0,0,2,0] alias_counter : 1
        [0,0,2,0]
    [0,0,2,1] alias_counter : 1
        [0,0,2,1]
    [0,0,2,2] alias_counter : 1
        [0,0,2,2]
    [0,1,0,0] alias_counter : 1
        [0,1,0,0]
    [0,1,0,1] alias_counter : 1
        [0,1,0,1]
    [0,1,0,2] alias_counter : 1
        [0,1,0,2]
    [0,1,1,0] alias_counter : 1
        [0,1,1,0]
    [0,1,1,1] alias_counter : 1
        [0,1,1,1]
    [0,1,1,2] alias_counter : 1
        [0,1,1,2]
    [0,1,2,0] alias_counter : 1
        [0,1,2,0]
    [0,1,2,1] alias_counter : 1
        [0,1,2,1]
    [0,1,2,2] alias_counter : 1
        [0,1,2,2]
    [0,2,0,0] alias_counter : 1
        [0,2,0,0]
    [0,2,0,1] alias_counter : 1
        [0,2,0,1]
    [0,2,0,2] alias_counter : 1
        [0,2,0,2]
    [0,2,1,0] alias_counter : 1
        [0,2,1,0]
    [0,2,1,1] alias_counter : 1
        [0,2,1,1]
    [0,2,1,2] alias_counter : 1
        [0,2,1,2]
    [0,2,2,0] alias_counter : 1
        [0,2,2,0]
    [0,2,2,1] alias_counter : 1
        [0,2,2,1]
    [0,2,2,2] alias_counter : 1
        [0,2,2,2]
    [1,0,0,0] alias_counter : 1
        [1,0,0,0]
    [1,0,0,1] alias_counter : 1
        [1,0,0,1]
    [1,0,0,2] alias_counter : 1
        [1,0,0,2]
    [1,0,1,0] alias_counter : 1
        [1,0,1,0]
    [1,0,1,1] alias_counter : 1
        [1,0,1,1]
    [1,0,1,2] alias_counter : 1
        [1,0,1,2]
    [1,0,2,0] alias_counter : 1
        [1,0,2,0]
    [1,0,2,1] alias_counter : 1
        [1,0,2,1]
    [1,0,2,2] alias_counter : 1
        [1,0,2,2]
    [1,1,0,0] alias_counter : 1
        [1,1,0,0]
    [1,1,0,1] alias_counter : 1
        [1,1,0,1]
    [1,1,0,2] alias_counter : 1
        [1,1,0,2]
    [1,1,1,0] alias_counter : 1
        [1,1,1,0]
    [1,1,1,1] alias_counter : 1
        [1,1,1,1]
    [1,1,1,2] alias_counter : 1
        [1,1,1,2]
    [1,1,2,0] alias_counter : 1
        [1,1,2,0]
    [1,1,2,1] alias_counter : 1
        [1,1,2,1]
    [1,1,2,2] alias_counter : 1
        [1,1,2,2]
    [1,2,0,0] alias_counter : 1
        [1,2,0,0]
    [1,2,0,1] alias_counter : 1
        [1,2,0,1]
    [1,2,0,2] alias_counter : 1
        [1,2,0,2]
    [1,2,1,0] alias_counter : 1
        [1,2,1,0]
    [1,2,1,1] alias_counter : 1
        [1,2,1,1]
    [1,2,1,2] alias_counter : 1
        [1,2,1,2]
    [1,2,2,0] alias_counter : 1
        [1,2,2,0]
    [1,2,2,1] alias_counter : 1
        [1,2,2,1]
    [1,2,2,2] alias_counter : 1
        [1,2,2,2]
    [2,0,0,0] alias_counter : 1
        [2,0,0,0]
    [2,0,0,1] alias_counter : 1
        [2,0,0,1]
    [2,0,0,2] alias_counter : 1
        [2,0,0,2]
    [2,0,1,0] alias_counter : 1
        [2,0,1,0]
    [2,0,1,1] alias_counter : 1
        [2,0,1,1]
    [2,0,1,2] alias_counter : 1
        [2,0,1,2]
    [2,0,2,0] alias_counter : 1
        [2,0,2,0]
    [2,0,2,1] alias_counter : 1
        [2,0,2,1]
    [2,0,2,2] alias_counter : 1
        [2,0,2,2]
    [2,1,0,0] alias_counter : 1
        [2,1,0,0]
    [2,1,0,1] alias_counter : 1
        [2,1,0,1]
    [2,1,0,2] alias_counter : 1
        [2,1,0,2]
    [2,1,1,0] alias_counter : 1
        [2,1,1,0]
    [2,1,1,1] alias_counter : 1
        [2,1,1,1]
    [2,1,1,2] alias_counter : 1
        [2,1,1,2]
    [2,1,2,0] alias_counter : 1
        [2,1,2,0]
    [2,1,2,1] alias_counter : 1
        [2,1,2,1]
    [2,1,2,2] alias_counter : 1
        [2,1,2,2]
    [2,2,0,0] alias_counter : 1
        [2,2,0,0]
    [2,2,0,1] alias_counter : 1
        [2,2,0,1]
    [2,2,0,2] alias_counter : 1
        [2,2,0,2]
    [2,2,1,0] alias_counter : 1
        [2,2,1,0]
    [2,2,1,1] alias_counter : 1
        [2,2,1,1]
    [2,2,1,2] alias_counter : 1
        [2,2,1,2]
    [2,2,2,0] alias_counter : 1
        [2,2,2,0]
    [2,2,2,1] alias_counter : 1
        [2,2,2,1]
    [2,2,2,2] alias_counter : 1
        [2,2,2,2]

    === triclinic aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 1 ? 1
        [0,0,0,0]
    [0,0,0,1] alias_counter : 4 ? 4
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [1,0,0,0]
    [0,0,0,2] alias_counter : 4 ? 4
        [0,0,0,2]
        [0,0,2,0]
        [0,2,0,0]
        [2,0,0,0]
    [0,0,1,0] alias_counter : 4 ? 4
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [1,0,0,0]
    [0,0,1,1] alias_counter : 2 ? 2
        [0,0,1,1]
        [1,1,0,0]
    [0,0,1,2] alias_counter : 4 ? 4
        [0,0,1,2]
        [0,0,2,1]
        [1,2,0,0]
        [2,1,0,0]
    [0,0,2,0] alias_counter : 4 ? 4
        [0,0,0,2]
        [0,0,2,0]
        [0,2,0,0]
        [2,0,0,0]
    [0,0,2,1] alias_counter : 4 ? 4
        [0,0,1,2]
        [0,0,2,1]
        [1,2,0,0]
        [2,1,0,0]
    [0,0,2,2] alias_counter : 2 ? 2
        [0,0,2,2]
        [2,2,0,0]
    [0,1,0,0] alias_counter : 4 ? 4
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [1,0,0,0]
    [0,1,0,1] alias_counter : 4 ? 4
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,0,2] alias_counter : 8 ? 8
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [2,0,0,1]
        [2,0,1,0]
    [0,1,1,0] alias_counter : 4 ? 4
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,1,1] alias_counter : 4 ? 4
        [0,1,1,1]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [0,1,1,2] alias_counter : 8 ? 8
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [0,1,2,0] alias_counter : 8 ? 8
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [2,0,0,1]
        [2,0,1,0]
    [0,1,2,1] alias_counter : 8 ? 8
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [0,1,2,2] alias_counter : 4 ? 4
        [0,1,2,2]
        [1,0,2,2]
        [2,2,0,1]
        [2,2,1,0]
    [0,2,0,0] alias_counter : 4 ? 4
        [0,0,0,2]
        [0,0,2,0]
        [0,2,0,0]
        [2,0,0,0]
    [0,2,0,1] alias_counter : 8 ? 8
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [2,0,0,1]
        [2,0,1,0]
    [0,2,0,2] alias_counter : 4 ? 4
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [0,2,1,0] alias_counter : 8 ? 8
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [2,0,0,1]
        [2,0,1,0]
    [0,2,1,1] alias_counter : 4 ? 4
        [0,2,1,1]
        [1,1,0,2]
        [1,1,2,0]
        [2,0,1,1]
    [0,2,1,2] alias_counter : 8 ? 8
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [0,2,2,0] alias_counter : 4 ? 4
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [0,2,2,1] alias_counter : 8 ? 8
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [0,2,2,2] alias_counter : 4 ? 4
        [0,2,2,2]
        [2,0,2,2]
        [2,2,0,2]
        [2,2,2,0]
    [1,0,0,0] alias_counter : 4 ? 4
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [1,0,0,0]
    [1,0,0,1] alias_counter : 4 ? 4
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,0,2] alias_counter : 8 ? 8
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [2,0,0,1]
        [2,0,1,0]
    [1,0,1,0] alias_counter : 4 ? 4
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,1,1] alias_counter : 4 ? 4
        [0,1,1,1]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [1,0,1,2] alias_counter : 8 ? 8
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [1,0,2,0] alias_counter : 8 ? 8
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [2,0,0,1]
        [2,0,1,0]
    [1,0,2,1] alias_counter : 8 ? 8
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [1,0,2,2] alias_counter : 4 ? 4
        [0,1,2,2]
        [1,0,2,2]
        [2,2,0,1]
        [2,2,1,0]
    [1,1,0,0] alias_counter : 2 ? 2
        [0,0,1,1]
        [1,1,0,0]
    [1,1,0,1] alias_counter : 4 ? 4
        [0,1,1,1]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [1,1,0,2] alias_counter : 4 ? 4
        [0,2,1,1]
        [1,1,0,2]
        [1,1,2,0]
        [2,0,1,1]
    [1,1,1,0] alias_counter : 4 ? 4
        [0,1,1,1]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [1,1,1,1] alias_counter : 1 ? 1
        [1,1,1,1]
    [1,1,1,2] alias_counter : 4 ? 4
        [1,1,1,2]
        [1,1,2,1]
        [1,2,1,1]
        [2,1,1,1]
    [1,1,2,0] alias_counter : 4 ? 4
        [0,2,1,1]
        [1,1,0,2]
        [1,1,2,0]
        [2,0,1,1]
    [1,1,2,1] alias_counter : 4 ? 4
        [1,1,1,2]
        [1,1,2,1]
        [1,2,1,1]
        [2,1,1,1]
    [1,1,2,2] alias_counter : 2 ? 2
        [1,1,2,2]
        [2,2,1,1]
    [1,2,0,0] alias_counter : 4 ? 4
        [0,0,1,2]
        [0,0,2,1]
        [1,2,0,0]
        [2,1,0,0]
    [1,2,0,1] alias_counter : 8 ? 8
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [1,2,0,2] alias_counter : 8 ? 8
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [1,2,1,0] alias_counter : 8 ? 8
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [1,2,1,1] alias_counter : 4 ? 4
        [1,1,1,2]
        [1,1,2,1]
        [1,2,1,1]
        [2,1,1,1]
    [1,2,1,2] alias_counter : 4 ? 4
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,0] alias_counter : 8 ? 8
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [1,2,2,1] alias_counter : 4 ? 4
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,2] alias_counter : 4 ? 4
        [1,2,2,2]
        [2,1,2,2]
        [2,2,1,2]
        [2,2,2,1]
    [2,0,0,0] alias_counter : 4 ? 4
        [0,0,0,2]
        [0,0,2,0]
        [0,2,0,0]
        [2,0,0,0]
    [2,0,0,1] alias_counter : 8 ? 8
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [2,0,0,1]
        [2,0,1,0]
    [2,0,0,2] alias_counter : 4 ? 4
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [2,0,1,0] alias_counter : 8 ? 8
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [2,0,0,1]
        [2,0,1,0]
    [2,0,1,1] alias_counter : 4 ? 4
        [0,2,1,1]
        [1,1,0,2]
        [1,1,2,0]
        [2,0,1,1]
    [2,0,1,2] alias_counter : 8 ? 8
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [2,0,2,0] alias_counter : 4 ? 4
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [2,0,2,1] alias_counter : 8 ? 8
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [2,0,2,2] alias_counter : 4 ? 4
        [0,2,2,2]
        [2,0,2,2]
        [2,2,0,2]
        [2,2,2,0]
    [2,1,0,0] alias_counter : 4 ? 4
        [0,0,1,2]
        [0,0,2,1]
        [1,2,0,0]
        [2,1,0,0]
    [2,1,0,1] alias_counter : 8 ? 8
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [2,1,0,2] alias_counter : 8 ? 8
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [2,1,1,0] alias_counter : 8 ? 8
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [2,1,1,1] alias_counter : 4 ? 4
        [1,1,1,2]
        [1,1,2,1]
        [1,2,1,1]
        [2,1,1,1]
    [2,1,1,2] alias_counter : 4 ? 4
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,0] alias_counter : 8 ? 8
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [2,1,2,1] alias_counter : 4 ? 4
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,2] alias_counter : 4 ? 4
        [1,2,2,2]
        [2,1,2,2]
        [2,2,1,2]
        [2,2,2,1]
    [2,2,0,0] alias_counter : 2 ? 2
        [0,0,2,2]
        [2,2,0,0]
    [2,2,0,1] alias_counter : 4 ? 4
        [0,1,2,2]
        [1,0,2,2]
        [2,2,0,1]
        [2,2,1,0]
    [2,2,0,2] alias_counter : 4 ? 4
        [0,2,2,2]
        [2,0,2,2]
        [2,2,0,2]
        [2,2,2,0]
    [2,2,1,0] alias_counter : 4 ? 4
        [0,1,2,2]
        [1,0,2,2]
        [2,2,0,1]
        [2,2,1,0]
    [2,2,1,1] alias_counter : 2 ? 2
        [1,1,2,2]
        [2,2,1,1]
    [2,2,1,2] alias_counter : 4 ? 4
        [1,2,2,2]
        [2,1,2,2]
        [2,2,1,2]
        [2,2,2,1]
    [2,2,2,0] alias_counter : 4 ? 4
        [0,2,2,2]
        [2,0,2,2]
        [2,2,0,2]
        [2,2,2,0]
    [2,2,2,1] alias_counter : 4 ? 4
        [1,2,2,2]
        [2,1,2,2]
        [2,2,1,2]
        [2,2,2,1]
    [2,2,2,2] alias_counter : 1 ? 1
        [2,2,2,2]

    === monoclinicx2 aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 1 ? 1
      [0,0]
        [0,0,0,0]
    [0,0,0,1] alias_counter : 1 ? 1
      [0,5]
        [0,0,0,1]
    [0,0,0,2] alias_counter : 4 ? 4
      [0,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,2,0,0]
        [2,0,0,0]
    [0,0,1,0] alias_counter : 1 ? 1
      [0,5]
        [0,0,1,0]
    [0,0,1,1] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [0,0,1,2] alias_counter : 1 ? 1
      [0,3]
        [0,0,1,2]
    [0,0,2,0] alias_counter : 4 ? 4
      [0,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,2,0,0]
        [2,0,0,0]
    [0,0,2,1] alias_counter : 1 ? 1
      [0,3]
        [0,0,2,1]
    [0,0,2,2] alias_counter : 2 ? 2
      [0,2]
        [0,0,2,2]
        [2,2,0,0]
    [0,1,0,0] alias_counter : 1 ? 1
      [0,5]
        [0,1,0,0]
    [0,1,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,0,2] alias_counter : 1 ? 1
      [4,5]
        [0,1,0,2]
    [0,1,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,1,1] alias_counter : 1 ? 1
      [1,5]
        [0,1,1,1]
    [0,1,1,2] alias_counter : 8 ? 8
      [3,5]
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [0,1,2,0] alias_counter : 1 ? 1
      [4,5]
        [0,1,2,0]
    [0,1,2,1] alias_counter : 8 ? 8
      [3,5]
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [0,1,2,2] alias_counter : 1 ? 1
      [2,5]
        [0,1,2,2]
    [0,2,0,0] alias_counter : 4 ? 4
      [0,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,2,0,0]
        [2,0,0,0]
    [0,2,0,1] alias_counter : 1 ? 1
      [4,5]
        [0,2,0,1]
    [0,2,0,2] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [0,2,1,0] alias_counter : 1 ? 1
      [4,5]
        [0,2,1,0]
    [0,2,1,1] alias_counter : 4 ? 4
      [1,4]
        [0,2,1,1]
        [1,1,0,2]
        [1,1,2,0]
        [2,0,1,1]
    [0,2,1,2] alias_counter : 1 ? 1
      [3,4]
        [0,2,1,2]
    [0,2,2,0] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [0,2,2,1] alias_counter : 1 ? 1
      [3,4]
        [0,2,2,1]
    [0,2,2,2] alias_counter : 4 ? 4
      [2,4]
        [0,2,2,2]
        [2,0,2,2]
        [2,2,0,2]
        [2,2,2,0]
    [1,0,0,0] alias_counter : 1 ? 1
      [0,5]
        [1,0,0,0]
    [1,0,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,0,2] alias_counter : 1 ? 1
      [4,5]
        [1,0,0,2]
    [1,0,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,1,1] alias_counter : 1 ? 1
      [1,5]
        [1,0,1,1]
    [1,0,1,2] alias_counter : 8 ? 8
      [3,5]
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [1,0,2,0] alias_counter : 1 ? 1
      [4,5]
        [1,0,2,0]
    [1,0,2,1] alias_counter : 8 ? 8
      [3,5]
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [1,0,2,2] alias_counter : 1 ? 1
      [2,5]
        [1,0,2,2]
    [1,1,0,0] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [1,1,0,1] alias_counter : 1 ? 1
      [1,5]
        [1,1,0,1]
    [1,1,0,2] alias_counter : 4 ? 4
      [1,4]
        [0,2,1,1]
        [1,1,0,2]
        [1,1,2,0]
        [2,0,1,1]
    [1,1,1,0] alias_counter : 1 ? 1
      [1,5]
        [1,1,1,0]
    [1,1,1,1] alias_counter : 1 ? 1
      [1,1]
        [1,1,1,1]
    [1,1,1,2] alias_counter : 1 ? 1
      [1,3]
        [1,1,1,2]
    [1,1,2,0] alias_counter : 4 ? 4
      [1,4]
        [0,2,1,1]
        [1,1,0,2]
        [1,1,2,0]
        [2,0,1,1]
    [1,1,2,1] alias_counter : 1 ? 1
      [1,3]
        [1,1,2,1]
    [1,1,2,2] alias_counter : 2 ? 2
      [1,2]
        [1,1,2,2]
        [2,2,1,1]
    [1,2,0,0] alias_counter : 1 ? 1
      [0,3]
        [1,2,0,0]
    [1,2,0,1] alias_counter : 8 ? 8
      [3,5]
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [1,2,0,2] alias_counter : 1 ? 1
      [3,4]
        [1,2,0,2]
    [1,2,1,0] alias_counter : 8 ? 8
      [3,5]
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [1,2,1,1] alias_counter : 1 ? 1
      [1,3]
        [1,2,1,1]
    [1,2,1,2] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,0] alias_counter : 1 ? 1
      [3,4]
        [1,2,2,0]
    [1,2,2,1] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,2] alias_counter : 1 ? 1
      [2,3]
        [1,2,2,2]
    [2,0,0,0] alias_counter : 4 ? 4
      [0,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,2,0,0]
        [2,0,0,0]
    [2,0,0,1] alias_counter : 1 ? 1
      [4,5]
        [2,0,0,1]
    [2,0,0,2] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [2,0,1,0] alias_counter : 1 ? 1
      [4,5]
        [2,0,1,0]
    [2,0,1,1] alias_counter : 4 ? 4
      [1,4]
        [0,2,1,1]
        [1,1,0,2]
        [1,1,2,0]
        [2,0,1,1]
    [2,0,1,2] alias_counter : 1 ? 1
      [3,4]
        [2,0,1,2]
    [2,0,2,0] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [2,0,2,1] alias_counter : 1 ? 1
      [3,4]
        [2,0,2,1]
    [2,0,2,2] alias_counter : 4 ? 4
      [2,4]
        [0,2,2,2]
        [2,0,2,2]
        [2,2,0,2]
        [2,2,2,0]
    [2,1,0,0] alias_counter : 1 ? 1
      [0,3]
        [2,1,0,0]
    [2,1,0,1] alias_counter : 8 ? 8
      [3,5]
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [2,1,0,2] alias_counter : 1 ? 1
      [3,4]
        [2,1,0,2]
    [2,1,1,0] alias_counter : 8 ? 8
      [3,5]
        [0,1,1,2]
        [0,1,2,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,2,0,1]
        [1,2,1,0]
        [2,1,0,1]
        [2,1,1,0]
    [2,1,1,1] alias_counter : 1 ? 1
      [1,3]
        [2,1,1,1]
    [2,1,1,2] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,0] alias_counter : 1 ? 1
      [3,4]
        [2,1,2,0]
    [2,1,2,1] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,2] alias_counter : 1 ? 1
      [2,3]
        [2,1,2,2]
    [2,2,0,0] alias_counter : 2 ? 2
      [0,2]
        [0,0,2,2]
        [2,2,0,0]
    [2,2,0,1] alias_counter : 1 ? 1
      [2,5]
        [2,2,0,1]
    [2,2,0,2] alias_counter : 4 ? 4
      [2,4]
        [0,2,2,2]
        [2,0,2,2]
        [2,2,0,2]
        [2,2,2,0]
    [2,2,1,0] alias_counter : 1 ? 1
      [2,5]
        [2,2,1,0]
    [2,2,1,1] alias_counter : 2 ? 2
      [1,2]
        [1,1,2,2]
        [2,2,1,1]
    [2,2,1,2] alias_counter : 1 ? 1
      [2,3]
        [2,2,1,2]
    [2,2,2,0] alias_counter : 4 ? 4
      [2,4]
        [0,2,2,2]
        [2,0,2,2]
        [2,2,0,2]
        [2,2,2,0]
    [2,2,2,1] alias_counter : 1 ? 1
      [2,3]
        [2,2,2,1]
    [2,2,2,2] alias_counter : 1 ? 1
      [2,2]
        [2,2,2,2]

    === monoclinicx3 aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 1 ? 1
      [0,0]
        [0,0,0,0]
    [0,0,0,1] alias_counter : 4 ? 4
      [0,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [1,0,0,0]
    [0,0,0,2] alias_counter : 1 ? 1
      [0,4]
        [0,0,0,2]
    [0,0,1,0] alias_counter : 4 ? 4
      [0,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [1,0,0,0]
    [0,0,1,1] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [0,0,1,2] alias_counter : 1 ? 1
      [0,3]
        [0,0,1,2]
    [0,0,2,0] alias_counter : 1 ? 1
      [0,4]
        [0,0,2,0]
    [0,0,2,1] alias_counter : 1 ? 1
      [0,3]
        [0,0,2,1]
    [0,0,2,2] alias_counter : 2 ? 2
      [0,2]
        [0,0,2,2]
        [2,2,0,0]
    [0,1,0,0] alias_counter : 4 ? 4
      [0,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [1,0,0,0]
    [0,1,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,0,2] alias_counter : 1 ? 1
      [4,5]
        [0,1,0,2]
    [0,1,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,1,1] alias_counter : 4 ? 4
      [1,5]
        [0,1,1,1]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [0,1,1,2] alias_counter : 1 ? 1
      [3,5]
        [0,1,1,2]
    [0,1,2,0] alias_counter : 1 ? 1
      [4,5]
        [0,1,2,0]
    [0,1,2,1] alias_counter : 1 ? 1
      [3,5]
        [0,1,2,1]
    [0,1,2,2] alias_counter : 4 ? 4
      [2,5]
        [0,1,2,2]
        [1,0,2,2]
        [2,2,0,1]
        [2,2,1,0]
    [0,2,0,0] alias_counter : 1 ? 1
      [0,4]
        [0,2,0,0]
    [0,2,0,1] alias_counter : 1 ? 1
      [4,5]
        [0,2,0,1]
    [0,2,0,2] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [0,2,1,0] alias_counter : 1 ? 1
      [4,5]
        [0,2,1,0]
    [0,2,1,1] alias_counter : 1 ? 1
      [1,4]
        [0,2,1,1]
    [0,2,1,2] alias_counter : 8 ? 8
      [3,4]
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [0,2,2,0] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [0,2,2,1] alias_counter : 8 ? 8
      [3,4]
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [0,2,2,2] alias_counter : 1 ? 1
      [2,4]
        [0,2,2,2]
    [1,0,0,0] alias_counter : 4 ? 4
      [0,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [1,0,0,0]
    [1,0,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,0,2] alias_counter : 1 ? 1
      [4,5]
        [1,0,0,2]
    [1,0,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,1,1] alias_counter : 4 ? 4
      [1,5]
        [0,1,1,1]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [1,0,1,2] alias_counter : 1 ? 1
      [3,5]
        [1,0,1,2]
    [1,0,2,0] alias_counter : 1 ? 1
      [4,5]
        [1,0,2,0]
    [1,0,2,1] alias_counter : 1 ? 1
      [3,5]
        [1,0,2,1]
    [1,0,2,2] alias_counter : 4 ? 4
      [2,5]
        [0,1,2,2]
        [1,0,2,2]
        [2,2,0,1]
        [2,2,1,0]
    [1,1,0,0] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [1,1,0,1] alias_counter : 4 ? 4
      [1,5]
        [0,1,1,1]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [1,1,0,2] alias_counter : 1 ? 1
      [1,4]
        [1,1,0,2]
    [1,1,1,0] alias_counter : 4 ? 4
      [1,5]
        [0,1,1,1]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [1,1,1,1] alias_counter : 1 ? 1
      [1,1]
        [1,1,1,1]
    [1,1,1,2] alias_counter : 1 ? 1
      [1,3]
        [1,1,1,2]
    [1,1,2,0] alias_counter : 1 ? 1
      [1,4]
        [1,1,2,0]
    [1,1,2,1] alias_counter : 1 ? 1
      [1,3]
        [1,1,2,1]
    [1,1,2,2] alias_counter : 2 ? 2
      [1,2]
        [1,1,2,2]
        [2,2,1,1]
    [1,2,0,0] alias_counter : 1 ? 1
      [0,3]
        [1,2,0,0]
    [1,2,0,1] alias_counter : 1 ? 1
      [3,5]
        [1,2,0,1]
    [1,2,0,2] alias_counter : 8 ? 8
      [3,4]
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [1,2,1,0] alias_counter : 1 ? 1
      [3,5]
        [1,2,1,0]
    [1,2,1,1] alias_counter : 1 ? 1
      [1,3]
        [1,2,1,1]
    [1,2,1,2] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,0] alias_counter : 8 ? 8
      [3,4]
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [1,2,2,1] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,2] alias_counter : 1 ? 1
      [2,3]
        [1,2,2,2]
    [2,0,0,0] alias_counter : 1 ? 1
      [0,4]
        [2,0,0,0]
    [2,0,0,1] alias_counter : 1 ? 1
      [4,5]
        [2,0,0,1]
    [2,0,0,2] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [2,0,1,0] alias_counter : 1 ? 1
      [4,5]
        [2,0,1,0]
    [2,0,1,1] alias_counter : 1 ? 1
      [1,4]
        [2,0,1,1]
    [2,0,1,2] alias_counter : 8 ? 8
      [3,4]
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [2,0,2,0] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [2,0,2,1] alias_counter : 8 ? 8
      [3,4]
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [2,0,2,2] alias_counter : 1 ? 1
      [2,4]
        [2,0,2,2]
    [2,1,0,0] alias_counter : 1 ? 1
      [0,3]
        [2,1,0,0]
    [2,1,0,1] alias_counter : 1 ? 1
      [3,5]
        [2,1,0,1]
    [2,1,0,2] alias_counter : 8 ? 8
      [3,4]
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [2,1,1,0] alias_counter : 1 ? 1
      [3,5]
        [2,1,1,0]
    [2,1,1,1] alias_counter : 1 ? 1
      [1,3]
        [2,1,1,1]
    [2,1,1,2] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,0] alias_counter : 8 ? 8
      [3,4]
        [0,2,1,2]
        [0,2,2,1]
        [1,2,0,2]
        [1,2,2,0]
        [2,0,1,2]
        [2,0,2,1]
        [2,1,0,2]
        [2,1,2,0]
    [2,1,2,1] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,2] alias_counter : 1 ? 1
      [2,3]
        [2,1,2,2]
    [2,2,0,0] alias_counter : 2 ? 2
      [0,2]
        [0,0,2,2]
        [2,2,0,0]
    [2,2,0,1] alias_counter : 4 ? 4
      [2,5]
        [0,1,2,2]
        [1,0,2,2]
        [2,2,0,1]
        [2,2,1,0]
    [2,2,0,2] alias_counter : 1 ? 1
      [2,4]
        [2,2,0,2]
    [2,2,1,0] alias_counter : 4 ? 4
      [2,5]
        [0,1,2,2]
        [1,0,2,2]
        [2,2,0,1]
        [2,2,1,0]
    [2,2,1,1] alias_counter : 2 ? 2
      [1,2]
        [1,1,2,2]
        [2,2,1,1]
    [2,2,1,2] alias_counter : 1 ? 1
      [2,3]
        [2,2,1,2]
    [2,2,2,0] alias_counter : 1 ? 1
      [2,4]
        [2,2,2,0]
    [2,2,2,1] alias_counter : 1 ? 1
      [2,3]
        [2,2,2,1]
    [2,2,2,2] alias_counter : 1 ? 1
      [2,2]
        [2,2,2,2]

    === orthorhombic aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 1 ? 1
      [0,0]
        [0,0,0,0]
    [0,0,0,1] alias_counter : 1 ? 1
      [0,5]
        [0,0,0,1]
    [0,0,0,2] alias_counter : 1 ? 1
      [0,4]
        [0,0,0,2]
    [0,0,1,0] alias_counter : 1 ? 1
      [0,5]
        [0,0,1,0]
    [0,0,1,1] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [0,0,1,2] alias_counter : 1 ? 1
      [0,3]
        [0,0,1,2]
    [0,0,2,0] alias_counter : 1 ? 1
      [0,4]
        [0,0,2,0]
    [0,0,2,1] alias_counter : 1 ? 1
      [0,3]
        [0,0,2,1]
    [0,0,2,2] alias_counter : 2 ? 2
      [0,2]
        [0,0,2,2]
        [2,2,0,0]
    [0,1,0,0] alias_counter : 1 ? 1
      [0,5]
        [0,1,0,0]
    [0,1,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,0,2] alias_counter : 1 ? 1
      [4,5]
        [0,1,0,2]
    [0,1,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,1,1] alias_counter : 1 ? 1
      [1,5]
        [0,1,1,1]
    [0,1,1,2] alias_counter : 1 ? 1
      [3,5]
        [0,1,1,2]
    [0,1,2,0] alias_counter : 1 ? 1
      [4,5]
        [0,1,2,0]
    [0,1,2,1] alias_counter : 1 ? 1
      [3,5]
        [0,1,2,1]
    [0,1,2,2] alias_counter : 1 ? 1
      [2,5]
        [0,1,2,2]
    [0,2,0,0] alias_counter : 1 ? 1
      [0,4]
        [0,2,0,0]
    [0,2,0,1] alias_counter : 1 ? 1
      [4,5]
        [0,2,0,1]
    [0,2,0,2] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [0,2,1,0] alias_counter : 1 ? 1
      [4,5]
        [0,2,1,0]
    [0,2,1,1] alias_counter : 1 ? 1
      [1,4]
        [0,2,1,1]
    [0,2,1,2] alias_counter : 1 ? 1
      [3,4]
        [0,2,1,2]
    [0,2,2,0] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [0,2,2,1] alias_counter : 1 ? 1
      [3,4]
        [0,2,2,1]
    [0,2,2,2] alias_counter : 1 ? 1
      [2,4]
        [0,2,2,2]
    [1,0,0,0] alias_counter : 1 ? 1
      [0,5]
        [1,0,0,0]
    [1,0,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,0,2] alias_counter : 1 ? 1
      [4,5]
        [1,0,0,2]
    [1,0,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,1,1] alias_counter : 1 ? 1
      [1,5]
        [1,0,1,1]
    [1,0,1,2] alias_counter : 1 ? 1
      [3,5]
        [1,0,1,2]
    [1,0,2,0] alias_counter : 1 ? 1
      [4,5]
        [1,0,2,0]
    [1,0,2,1] alias_counter : 1 ? 1
      [3,5]
        [1,0,2,1]
    [1,0,2,2] alias_counter : 1 ? 1
      [2,5]
        [1,0,2,2]
    [1,1,0,0] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [1,1,0,1] alias_counter : 1 ? 1
      [1,5]
        [1,1,0,1]
    [1,1,0,2] alias_counter : 1 ? 1
      [1,4]
        [1,1,0,2]
    [1,1,1,0] alias_counter : 1 ? 1
      [1,5]
        [1,1,1,0]
    [1,1,1,1] alias_counter : 1 ? 1
      [1,1]
        [1,1,1,1]
    [1,1,1,2] alias_counter : 1 ? 1
      [1,3]
        [1,1,1,2]
    [1,1,2,0] alias_counter : 1 ? 1
      [1,4]
        [1,1,2,0]
    [1,1,2,1] alias_counter : 1 ? 1
      [1,3]
        [1,1,2,1]
    [1,1,2,2] alias_counter : 2 ? 2
      [1,2]
        [1,1,2,2]
        [2,2,1,1]
    [1,2,0,0] alias_counter : 1 ? 1
      [0,3]
        [1,2,0,0]
    [1,2,0,1] alias_counter : 1 ? 1
      [3,5]
        [1,2,0,1]
    [1,2,0,2] alias_counter : 1 ? 1
      [3,4]
        [1,2,0,2]
    [1,2,1,0] alias_counter : 1 ? 1
      [3,5]
        [1,2,1,0]
    [1,2,1,1] alias_counter : 1 ? 1
      [1,3]
        [1,2,1,1]
    [1,2,1,2] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,0] alias_counter : 1 ? 1
      [3,4]
        [1,2,2,0]
    [1,2,2,1] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,2] alias_counter : 1 ? 1
      [2,3]
        [1,2,2,2]
    [2,0,0,0] alias_counter : 1 ? 1
      [0,4]
        [2,0,0,0]
    [2,0,0,1] alias_counter : 1 ? 1
      [4,5]
        [2,0,0,1]
    [2,0,0,2] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [2,0,1,0] alias_counter : 1 ? 1
      [4,5]
        [2,0,1,0]
    [2,0,1,1] alias_counter : 1 ? 1
      [1,4]
        [2,0,1,1]
    [2,0,1,2] alias_counter : 1 ? 1
      [3,4]
        [2,0,1,2]
    [2,0,2,0] alias_counter : 4 ? 4
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [2,0,0,2]
        [2,0,2,0]
    [2,0,2,1] alias_counter : 1 ? 1
      [3,4]
        [2,0,2,1]
    [2,0,2,2] alias_counter : 1 ? 1
      [2,4]
        [2,0,2,2]
    [2,1,0,0] alias_counter : 1 ? 1
      [0,3]
        [2,1,0,0]
    [2,1,0,1] alias_counter : 1 ? 1
      [3,5]
        [2,1,0,1]
    [2,1,0,2] alias_counter : 1 ? 1
      [3,4]
        [2,1,0,2]
    [2,1,1,0] alias_counter : 1 ? 1
      [3,5]
        [2,1,1,0]
    [2,1,1,1] alias_counter : 1 ? 1
      [1,3]
        [2,1,1,1]
    [2,1,1,2] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,0] alias_counter : 1 ? 1
      [3,4]
        [2,1,2,0]
    [2,1,2,1] alias_counter : 4 ? 4
      [3,3]
        [1,2,1,2]
        [1,2,2,1]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,2] alias_counter : 1 ? 1
      [2,3]
        [2,1,2,2]
    [2,2,0,0] alias_counter : 2 ? 2
      [0,2]
        [0,0,2,2]
        [2,2,0,0]
    [2,2,0,1] alias_counter : 1 ? 1
      [2,5]
        [2,2,0,1]
    [2,2,0,2] alias_counter : 1 ? 1
      [2,4]
        [2,2,0,2]
    [2,2,1,0] alias_counter : 1 ? 1
      [2,5]
        [2,2,1,0]
    [2,2,1,1] alias_counter : 2 ? 2
      [1,2]
        [1,1,2,2]
        [2,2,1,1]
    [2,2,1,2] alias_counter : 1 ? 1
      [2,3]
        [2,2,1,2]
    [2,2,2,0] alias_counter : 1 ? 1
      [2,4]
        [2,2,2,0]
    [2,2,2,1] alias_counter : 1 ? 1
      [2,3]
        [2,2,2,1]
    [2,2,2,2] alias_counter : 1 ? 1
      [2,2]
        [2,2,2,2]

    === hexagonal aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 2 ? 2
      [0,0]
        [0,0,0,0]
        [1,1,1,1]
    [0,0,0,1] alias_counter : 1 ? 1
      [0,5]
        [0,0,0,1]
    [0,0,0,2] alias_counter : 1 ? 1
      [0,4]
        [0,0,0,2]
    [0,0,1,0] alias_counter : 1 ? 1
      [0,5]
        [0,0,1,0]
    [0,0,1,1] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [0,0,1,2] alias_counter : 1 ? 1
      [0,3]
        [0,0,1,2]
    [0,0,2,0] alias_counter : 1 ? 1
      [0,4]
        [0,0,2,0]
    [0,0,2,1] alias_counter : 1 ? 1
      [0,3]
        [0,0,2,1]
    [0,0,2,2] alias_counter : 4 ? 4
      [0,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [0,1,0,0] alias_counter : 1 ? 1
      [0,5]
        [0,1,0,0]
    [0,1,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,0,2] alias_counter : 1 ? 1
      [4,5]
        [0,1,0,2]
    [0,1,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,1,1] alias_counter : 1 ? 1
      [1,5]
        [0,1,1,1]
    [0,1,1,2] alias_counter : 1 ? 1
      [3,5]
        [0,1,1,2]
    [0,1,2,0] alias_counter : 1 ? 1
      [4,5]
        [0,1,2,0]
    [0,1,2,1] alias_counter : 1 ? 1
      [3,5]
        [0,1,2,1]
    [0,1,2,2] alias_counter : 1 ? 1
      [2,5]
        [0,1,2,2]
    [0,2,0,0] alias_counter : 1 ? 1
      [0,4]
        [0,2,0,0]
    [0,2,0,1] alias_counter : 1 ? 1
      [4,5]
        [0,2,0,1]
    [0,2,0,2] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,1,0] alias_counter : 1 ? 1
      [4,5]
        [0,2,1,0]
    [0,2,1,1] alias_counter : 1 ? 1
      [1,4]
        [0,2,1,1]
    [0,2,1,2] alias_counter : 1 ? 1
      [3,4]
        [0,2,1,2]
    [0,2,2,0] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,2,1] alias_counter : 1 ? 1
      [3,4]
        [0,2,2,1]
    [0,2,2,2] alias_counter : 1 ? 1
      [2,4]
        [0,2,2,2]
    [1,0,0,0] alias_counter : 1 ? 1
      [0,5]
        [1,0,0,0]
    [1,0,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,0,2] alias_counter : 1 ? 1
      [4,5]
        [1,0,0,2]
    [1,0,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,1,1] alias_counter : 1 ? 1
      [1,5]
        [1,0,1,1]
    [1,0,1,2] alias_counter : 1 ? 1
      [3,5]
        [1,0,1,2]
    [1,0,2,0] alias_counter : 1 ? 1
      [4,5]
        [1,0,2,0]
    [1,0,2,1] alias_counter : 1 ? 1
      [3,5]
        [1,0,2,1]
    [1,0,2,2] alias_counter : 1 ? 1
      [2,5]
        [1,0,2,2]
    [1,1,0,0] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [1,1,0,1] alias_counter : 1 ? 1
      [1,5]
        [1,1,0,1]
    [1,1,0,2] alias_counter : 1 ? 1
      [1,4]
        [1,1,0,2]
    [1,1,1,0] alias_counter : 1 ? 1
      [1,5]
        [1,1,1,0]
    [1,1,1,1] alias_counter : 2 ? 2
      [1,1]
        [0,0,0,0]
        [1,1,1,1]
    [1,1,1,2] alias_counter : 1 ? 1
      [1,3]
        [1,1,1,2]
    [1,1,2,0] alias_counter : 1 ? 1
      [1,4]
        [1,1,2,0]
    [1,1,2,1] alias_counter : 1 ? 1
      [1,3]
        [1,1,2,1]
    [1,1,2,2] alias_counter : 4 ? 4
      [1,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [1,2,0,0] alias_counter : 1 ? 1
      [0,3]
        [1,2,0,0]
    [1,2,0,1] alias_counter : 1 ? 1
      [3,5]
        [1,2,0,1]
    [1,2,0,2] alias_counter : 1 ? 1
      [3,4]
        [1,2,0,2]
    [1,2,1,0] alias_counter : 1 ? 1
      [3,5]
        [1,2,1,0]
    [1,2,1,1] alias_counter : 1 ? 1
      [1,3]
        [1,2,1,1]
    [1,2,1,2] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,0] alias_counter : 1 ? 1
      [3,4]
        [1,2,2,0]
    [1,2,2,1] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,2] alias_counter : 1 ? 1
      [2,3]
        [1,2,2,2]
    [2,0,0,0] alias_counter : 1 ? 1
      [0,4]
        [2,0,0,0]
    [2,0,0,1] alias_counter : 1 ? 1
      [4,5]
        [2,0,0,1]
    [2,0,0,2] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,1,0] alias_counter : 1 ? 1
      [4,5]
        [2,0,1,0]
    [2,0,1,1] alias_counter : 1 ? 1
      [1,4]
        [2,0,1,1]
    [2,0,1,2] alias_counter : 1 ? 1
      [3,4]
        [2,0,1,2]
    [2,0,2,0] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,2,1] alias_counter : 1 ? 1
      [3,4]
        [2,0,2,1]
    [2,0,2,2] alias_counter : 1 ? 1
      [2,4]
        [2,0,2,2]
    [2,1,0,0] alias_counter : 1 ? 1
      [0,3]
        [2,1,0,0]
    [2,1,0,1] alias_counter : 1 ? 1
      [3,5]
        [2,1,0,1]
    [2,1,0,2] alias_counter : 1 ? 1
      [3,4]
        [2,1,0,2]
    [2,1,1,0] alias_counter : 1 ? 1
      [3,5]
        [2,1,1,0]
    [2,1,1,1] alias_counter : 1 ? 1
      [1,3]
        [2,1,1,1]
    [2,1,1,2] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,0] alias_counter : 1 ? 1
      [3,4]
        [2,1,2,0]
    [2,1,2,1] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,2] alias_counter : 1 ? 1
      [2,3]
        [2,1,2,2]
    [2,2,0,0] alias_counter : 4 ? 4
      [0,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,0,1] alias_counter : 1 ? 1
      [2,5]
        [2,2,0,1]
    [2,2,0,2] alias_counter : 1 ? 1
      [2,4]
        [2,2,0,2]
    [2,2,1,0] alias_counter : 1 ? 1
      [2,5]
        [2,2,1,0]
    [2,2,1,1] alias_counter : 4 ? 4
      [1,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,1,2] alias_counter : 1 ? 1
      [2,3]
        [2,2,1,2]
    [2,2,2,0] alias_counter : 1 ? 1
      [2,4]
        [2,2,2,0]
    [2,2,2,1] alias_counter : 1 ? 1
      [2,3]
        [2,2,2,1]
    [2,2,2,2] alias_counter : 1 ? 1
      [2,2]
        [2,2,2,2]

    === tetragonal7 aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 2 ? 2
      [0,0]
        [0,0,0,0]
        [1,1,1,1]
    [0,0,0,1] alias_counter : 8 ? 8
      [0,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [0,1,1,1]
        [1,0,0,0]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [0,0,0,2] alias_counter : 1 ? 1
      [0,4]
        [0,0,0,2]
    [0,0,1,0] alias_counter : 8 ? 8
      [0,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [0,1,1,1]
        [1,0,0,0]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [0,0,1,1] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [0,0,1,2] alias_counter : 1 ? 1
      [0,3]
        [0,0,1,2]
    [0,0,2,0] alias_counter : 1 ? 1
      [0,4]
        [0,0,2,0]
    [0,0,2,1] alias_counter : 1 ? 1
      [0,3]
        [0,0,2,1]
    [0,0,2,2] alias_counter : 4 ? 4
      [0,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [0,1,0,0] alias_counter : 8 ? 8
      [0,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [0,1,1,1]
        [1,0,0,0]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [0,1,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,0,2] alias_counter : 1 ? 1
      [4,5]
        [0,1,0,2]
    [0,1,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,1,1] alias_counter : 8 ? 8
      [1,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [0,1,1,1]
        [1,0,0,0]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [0,1,1,2] alias_counter : 1 ? 1
      [3,5]
        [0,1,1,2]
    [0,1,2,0] alias_counter : 1 ? 1
      [4,5]
        [0,1,2,0]
    [0,1,2,1] alias_counter : 1 ? 1
      [3,5]
        [0,1,2,1]
    [0,1,2,2] alias_counter : 1 ? 1
      [2,5]
        [0,1,2,2]
    [0,2,0,0] alias_counter : 1 ? 1
      [0,4]
        [0,2,0,0]
    [0,2,0,1] alias_counter : 1 ? 1
      [4,5]
        [0,2,0,1]
    [0,2,0,2] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,1,0] alias_counter : 1 ? 1
      [4,5]
        [0,2,1,0]
    [0,2,1,1] alias_counter : 1 ? 1
      [1,4]
        [0,2,1,1]
    [0,2,1,2] alias_counter : 1 ? 1
      [3,4]
        [0,2,1,2]
    [0,2,2,0] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,2,1] alias_counter : 1 ? 1
      [3,4]
        [0,2,2,1]
    [0,2,2,2] alias_counter : 1 ? 1
      [2,4]
        [0,2,2,2]
    [1,0,0,0] alias_counter : 8 ? 8
      [0,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [0,1,1,1]
        [1,0,0,0]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [1,0,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,0,2] alias_counter : 1 ? 1
      [4,5]
        [1,0,0,2]
    [1,0,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,1,1] alias_counter : 8 ? 8
      [1,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [0,1,1,1]
        [1,0,0,0]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [1,0,1,2] alias_counter : 1 ? 1
      [3,5]
        [1,0,1,2]
    [1,0,2,0] alias_counter : 1 ? 1
      [4,5]
        [1,0,2,0]
    [1,0,2,1] alias_counter : 1 ? 1
      [3,5]
        [1,0,2,1]
    [1,0,2,2] alias_counter : 1 ? 1
      [2,5]
        [1,0,2,2]
    [1,1,0,0] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [1,1,0,1] alias_counter : 8 ? 8
      [1,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [0,1,1,1]
        [1,0,0,0]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [1,1,0,2] alias_counter : 1 ? 1
      [1,4]
        [1,1,0,2]
    [1,1,1,0] alias_counter : 8 ? 8
      [1,5]
        [0,0,0,1]
        [0,0,1,0]
        [0,1,0,0]
        [0,1,1,1]
        [1,0,0,0]
        [1,0,1,1]
        [1,1,0,1]
        [1,1,1,0]
    [1,1,1,1] alias_counter : 2 ? 2
      [1,1]
        [0,0,0,0]
        [1,1,1,1]
    [1,1,1,2] alias_counter : 1 ? 1
      [1,3]
        [1,1,1,2]
    [1,1,2,0] alias_counter : 1 ? 1
      [1,4]
        [1,1,2,0]
    [1,1,2,1] alias_counter : 1 ? 1
      [1,3]
        [1,1,2,1]
    [1,1,2,2] alias_counter : 4 ? 4
      [1,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [1,2,0,0] alias_counter : 1 ? 1
      [0,3]
        [1,2,0,0]
    [1,2,0,1] alias_counter : 1 ? 1
      [3,5]
        [1,2,0,1]
    [1,2,0,2] alias_counter : 1 ? 1
      [3,4]
        [1,2,0,2]
    [1,2,1,0] alias_counter : 1 ? 1
      [3,5]
        [1,2,1,0]
    [1,2,1,1] alias_counter : 1 ? 1
      [1,3]
        [1,2,1,1]
    [1,2,1,2] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,0] alias_counter : 1 ? 1
      [3,4]
        [1,2,2,0]
    [1,2,2,1] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,2] alias_counter : 1 ? 1
      [2,3]
        [1,2,2,2]
    [2,0,0,0] alias_counter : 1 ? 1
      [0,4]
        [2,0,0,0]
    [2,0,0,1] alias_counter : 1 ? 1
      [4,5]
        [2,0,0,1]
    [2,0,0,2] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,1,0] alias_counter : 1 ? 1
      [4,5]
        [2,0,1,0]
    [2,0,1,1] alias_counter : 1 ? 1
      [1,4]
        [2,0,1,1]
    [2,0,1,2] alias_counter : 1 ? 1
      [3,4]
        [2,0,1,2]
    [2,0,2,0] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,2,1] alias_counter : 1 ? 1
      [3,4]
        [2,0,2,1]
    [2,0,2,2] alias_counter : 1 ? 1
      [2,4]
        [2,0,2,2]
    [2,1,0,0] alias_counter : 1 ? 1
      [0,3]
        [2,1,0,0]
    [2,1,0,1] alias_counter : 1 ? 1
      [3,5]
        [2,1,0,1]
    [2,1,0,2] alias_counter : 1 ? 1
      [3,4]
        [2,1,0,2]
    [2,1,1,0] alias_counter : 1 ? 1
      [3,5]
        [2,1,1,0]
    [2,1,1,1] alias_counter : 1 ? 1
      [1,3]
        [2,1,1,1]
    [2,1,1,2] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,0] alias_counter : 1 ? 1
      [3,4]
        [2,1,2,0]
    [2,1,2,1] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,2] alias_counter : 1 ? 1
      [2,3]
        [2,1,2,2]
    [2,2,0,0] alias_counter : 4 ? 4
      [0,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,0,1] alias_counter : 1 ? 1
      [2,5]
        [2,2,0,1]
    [2,2,0,2] alias_counter : 1 ? 1
      [2,4]
        [2,2,0,2]
    [2,2,1,0] alias_counter : 1 ? 1
      [2,5]
        [2,2,1,0]
    [2,2,1,1] alias_counter : 4 ? 4
      [1,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,1,2] alias_counter : 1 ? 1
      [2,3]
        [2,2,1,2]
    [2,2,2,0] alias_counter : 1 ? 1
      [2,4]
        [2,2,2,0]
    [2,2,2,1] alias_counter : 1 ? 1
      [2,3]
        [2,2,2,1]
    [2,2,2,2] alias_counter : 1 ? 1
      [2,2]
        [2,2,2,2]

    === tetragonal6 aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 2 ? 2
      [0,0]
        [0,0,0,0]
        [1,1,1,1]
    [0,0,0,1] alias_counter : 1 ? 1
      [0,5]
        [0,0,0,1]
    [0,0,0,2] alias_counter : 1 ? 1
      [0,4]
        [0,0,0,2]
    [0,0,1,0] alias_counter : 1 ? 1
      [0,5]
        [0,0,1,0]
    [0,0,1,1] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [0,0,1,2] alias_counter : 1 ? 1
      [0,3]
        [0,0,1,2]
    [0,0,2,0] alias_counter : 1 ? 1
      [0,4]
        [0,0,2,0]
    [0,0,2,1] alias_counter : 1 ? 1
      [0,3]
        [0,0,2,1]
    [0,0,2,2] alias_counter : 4 ? 4
      [0,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [0,1,0,0] alias_counter : 1 ? 1
      [0,5]
        [0,1,0,0]
    [0,1,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,0,2] alias_counter : 1 ? 1
      [4,5]
        [0,1,0,2]
    [0,1,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,1,1] alias_counter : 1 ? 1
      [1,5]
        [0,1,1,1]
    [0,1,1,2] alias_counter : 1 ? 1
      [3,5]
        [0,1,1,2]
    [0,1,2,0] alias_counter : 1 ? 1
      [4,5]
        [0,1,2,0]
    [0,1,2,1] alias_counter : 1 ? 1
      [3,5]
        [0,1,2,1]
    [0,1,2,2] alias_counter : 1 ? 1
      [2,5]
        [0,1,2,2]
    [0,2,0,0] alias_counter : 1 ? 1
      [0,4]
        [0,2,0,0]
    [0,2,0,1] alias_counter : 1 ? 1
      [4,5]
        [0,2,0,1]
    [0,2,0,2] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,1,0] alias_counter : 1 ? 1
      [4,5]
        [0,2,1,0]
    [0,2,1,1] alias_counter : 1 ? 1
      [1,4]
        [0,2,1,1]
    [0,2,1,2] alias_counter : 1 ? 1
      [3,4]
        [0,2,1,2]
    [0,2,2,0] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,2,1] alias_counter : 1 ? 1
      [3,4]
        [0,2,2,1]
    [0,2,2,2] alias_counter : 1 ? 1
      [2,4]
        [0,2,2,2]
    [1,0,0,0] alias_counter : 1 ? 1
      [0,5]
        [1,0,0,0]
    [1,0,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,0,2] alias_counter : 1 ? 1
      [4,5]
        [1,0,0,2]
    [1,0,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,1,1] alias_counter : 1 ? 1
      [1,5]
        [1,0,1,1]
    [1,0,1,2] alias_counter : 1 ? 1
      [3,5]
        [1,0,1,2]
    [1,0,2,0] alias_counter : 1 ? 1
      [4,5]
        [1,0,2,0]
    [1,0,2,1] alias_counter : 1 ? 1
      [3,5]
        [1,0,2,1]
    [1,0,2,2] alias_counter : 1 ? 1
      [2,5]
        [1,0,2,2]
    [1,1,0,0] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [1,1,0,1] alias_counter : 1 ? 1
      [1,5]
        [1,1,0,1]
    [1,1,0,2] alias_counter : 1 ? 1
      [1,4]
        [1,1,0,2]
    [1,1,1,0] alias_counter : 1 ? 1
      [1,5]
        [1,1,1,0]
    [1,1,1,1] alias_counter : 2 ? 2
      [1,1]
        [0,0,0,0]
        [1,1,1,1]
    [1,1,1,2] alias_counter : 1 ? 1
      [1,3]
        [1,1,1,2]
    [1,1,2,0] alias_counter : 1 ? 1
      [1,4]
        [1,1,2,0]
    [1,1,2,1] alias_counter : 1 ? 1
      [1,3]
        [1,1,2,1]
    [1,1,2,2] alias_counter : 4 ? 4
      [1,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [1,2,0,0] alias_counter : 1 ? 1
      [0,3]
        [1,2,0,0]
    [1,2,0,1] alias_counter : 1 ? 1
      [3,5]
        [1,2,0,1]
    [1,2,0,2] alias_counter : 1 ? 1
      [3,4]
        [1,2,0,2]
    [1,2,1,0] alias_counter : 1 ? 1
      [3,5]
        [1,2,1,0]
    [1,2,1,1] alias_counter : 1 ? 1
      [1,3]
        [1,2,1,1]
    [1,2,1,2] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,0] alias_counter : 1 ? 1
      [3,4]
        [1,2,2,0]
    [1,2,2,1] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,2] alias_counter : 1 ? 1
      [2,3]
        [1,2,2,2]
    [2,0,0,0] alias_counter : 1 ? 1
      [0,4]
        [2,0,0,0]
    [2,0,0,1] alias_counter : 1 ? 1
      [4,5]
        [2,0,0,1]
    [2,0,0,2] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,1,0] alias_counter : 1 ? 1
      [4,5]
        [2,0,1,0]
    [2,0,1,1] alias_counter : 1 ? 1
      [1,4]
        [2,0,1,1]
    [2,0,1,2] alias_counter : 1 ? 1
      [3,4]
        [2,0,1,2]
    [2,0,2,0] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,2,1] alias_counter : 1 ? 1
      [3,4]
        [2,0,2,1]
    [2,0,2,2] alias_counter : 1 ? 1
      [2,4]
        [2,0,2,2]
    [2,1,0,0] alias_counter : 1 ? 1
      [0,3]
        [2,1,0,0]
    [2,1,0,1] alias_counter : 1 ? 1
      [3,5]
        [2,1,0,1]
    [2,1,0,2] alias_counter : 1 ? 1
      [3,4]
        [2,1,0,2]
    [2,1,1,0] alias_counter : 1 ? 1
      [3,5]
        [2,1,1,0]
    [2,1,1,1] alias_counter : 1 ? 1
      [1,3]
        [2,1,1,1]
    [2,1,1,2] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,0] alias_counter : 1 ? 1
      [3,4]
        [2,1,2,0]
    [2,1,2,1] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,2] alias_counter : 1 ? 1
      [2,3]
        [2,1,2,2]
    [2,2,0,0] alias_counter : 4 ? 4
      [0,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,0,1] alias_counter : 1 ? 1
      [2,5]
        [2,2,0,1]
    [2,2,0,2] alias_counter : 1 ? 1
      [2,4]
        [2,2,0,2]
    [2,2,1,0] alias_counter : 1 ? 1
      [2,5]
        [2,2,1,0]
    [2,2,1,1] alias_counter : 4 ? 4
      [1,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,1,2] alias_counter : 1 ? 1
      [2,3]
        [2,2,1,2]
    [2,2,2,0] alias_counter : 1 ? 1
      [2,4]
        [2,2,2,0]
    [2,2,2,1] alias_counter : 1 ? 1
      [2,3]
        [2,2,2,1]
    [2,2,2,2] alias_counter : 1 ? 1
      [2,2]
        [2,2,2,2]

    === trigonal7 aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 2 ? 2
      [0,0]
        [0,0,0,0]
        [1,1,1,1]
    [0,0,0,1] alias_counter : 1 ? 1
      [0,5]
        [0,0,0,1]
    [0,0,0,2] alias_counter : 16 ? 16
      [0,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [0,0,1,0] alias_counter : 1 ? 1
      [0,5]
        [0,0,1,0]
    [0,0,1,1] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [0,0,1,2] alias_counter : 16 ? 16
      [0,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,0,2,0] alias_counter : 16 ? 16
      [0,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [0,0,2,1] alias_counter : 16 ? 16
      [0,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,0,2,2] alias_counter : 4 ? 4
      [0,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [0,1,0,0] alias_counter : 1 ? 1
      [0,5]
        [0,1,0,0]
    [0,1,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,0,2] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,1,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,1,1] alias_counter : 1 ? 1
      [1,5]
        [0,1,1,1]
    [0,1,1,2] alias_counter : 16 ? 16
      [3,5]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [0,1,2,0] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,1,2,1] alias_counter : 16 ? 16
      [3,5]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [0,1,2,2] alias_counter : 1 ? 1
      [2,5]
        [0,1,2,2]
    [0,2,0,0] alias_counter : 16 ? 16
      [0,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [0,2,0,1] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,2,0,2] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,1,0] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,2,1,1] alias_counter : 16 ? 16
      [1,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [0,2,1,2] alias_counter : 1 ? 1
      [3,4]
        [0,2,1,2]
    [0,2,2,0] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,2,1] alias_counter : 1 ? 1
      [3,4]
        [0,2,2,1]
    [0,2,2,2] alias_counter : 1 ? 1
      [2,4]
        [0,2,2,2]
    [1,0,0,0] alias_counter : 1 ? 1
      [0,5]
        [1,0,0,0]
    [1,0,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,0,2] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,0,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,1,1] alias_counter : 1 ? 1
      [1,5]
        [1,0,1,1]
    [1,0,1,2] alias_counter : 16 ? 16
      [3,5]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [1,0,2,0] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,0,2,1] alias_counter : 16 ? 16
      [3,5]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [1,0,2,2] alias_counter : 1 ? 1
      [2,5]
        [1,0,2,2]
    [1,1,0,0] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [1,1,0,1] alias_counter : 1 ? 1
      [1,5]
        [1,1,0,1]
    [1,1,0,2] alias_counter : 16 ? 16
      [1,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [1,1,1,0] alias_counter : 1 ? 1
      [1,5]
        [1,1,1,0]
    [1,1,1,1] alias_counter : 2 ? 2
      [1,1]
        [0,0,0,0]
        [1,1,1,1]
    [1,1,1,2] alias_counter : 16 ? 16
      [1,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,1,2,0] alias_counter : 16 ? 16
      [1,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [1,1,2,1] alias_counter : 16 ? 16
      [1,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,1,2,2] alias_counter : 4 ? 4
      [1,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [1,2,0,0] alias_counter : 16 ? 16
      [0,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,2,0,1] alias_counter : 16 ? 16
      [3,5]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [1,2,0,2] alias_counter : 1 ? 1
      [3,4]
        [1,2,0,2]
    [1,2,1,0] alias_counter : 16 ? 16
      [3,5]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [1,2,1,1] alias_counter : 16 ? 16
      [1,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,2,1,2] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,0] alias_counter : 1 ? 1
      [3,4]
        [1,2,2,0]
    [1,2,2,1] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,2] alias_counter : 1 ? 1
      [2,3]
        [1,2,2,2]
    [2,0,0,0] alias_counter : 16 ? 16
      [0,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [2,0,0,1] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [2,0,0,2] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,1,0] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [2,0,1,1] alias_counter : 16 ? 16
      [1,4]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [2,0,1,2] alias_counter : 1 ? 1
      [3,4]
        [2,0,1,2]
    [2,0,2,0] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,2,1] alias_counter : 1 ? 1
      [3,4]
        [2,0,2,1]
    [2,0,2,2] alias_counter : 1 ? 1
      [2,4]
        [2,0,2,2]
    [2,1,0,0] alias_counter : 16 ? 16
      [0,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [2,1,0,1] alias_counter : 16 ? 16
      [3,5]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [2,1,0,2] alias_counter : 1 ? 1
      [3,4]
        [2,1,0,2]
    [2,1,1,0] alias_counter : 16 ? 16
      [3,5]
        [0,0,0,2]
        [0,0,2,0]
        [0,1,1,2]
        [0,1,2,1]
        [0,2,0,0]
        [0,2,1,1]
        [1,0,1,2]
        [1,0,2,1]
        [1,1,0,2]
        [1,1,2,0]
        [1,2,0,1]
        [1,2,1,0]
        [2,0,0,0]
        [2,0,1,1]
        [2,1,0,1]
        [2,1,1,0]
    [2,1,1,1] alias_counter : 16 ? 16
      [1,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [2,1,1,2] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,0] alias_counter : 1 ? 1
      [3,4]
        [2,1,2,0]
    [2,1,2,1] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,2] alias_counter : 1 ? 1
      [2,3]
        [2,1,2,2]
    [2,2,0,0] alias_counter : 4 ? 4
      [0,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,0,1] alias_counter : 1 ? 1
      [2,5]
        [2,2,0,1]
    [2,2,0,2] alias_counter : 1 ? 1
      [2,4]
        [2,2,0,2]
    [2,2,1,0] alias_counter : 1 ? 1
      [2,5]
        [2,2,1,0]
    [2,2,1,1] alias_counter : 4 ? 4
      [1,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,1,2] alias_counter : 1 ? 1
      [2,3]
        [2,2,1,2]
    [2,2,2,0] alias_counter : 1 ? 1
      [2,4]
        [2,2,2,0]
    [2,2,2,1] alias_counter : 1 ? 1
      [2,3]
        [2,2,2,1]
    [2,2,2,2] alias_counter : 1 ? 1
      [2,2]
        [2,2,2,2]

    === trigonal6 aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 2 ? 2
      [0,0]
        [0,0,0,0]
        [1,1,1,1]
    [0,0,0,1] alias_counter : 1 ? 1
      [0,5]
        [0,0,0,1]
    [0,0,0,2] alias_counter : 1 ? 1
      [0,4]
        [0,0,0,2]
    [0,0,1,0] alias_counter : 1 ? 1
      [0,5]
        [0,0,1,0]
    [0,0,1,1] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [0,0,1,2] alias_counter : 16 ? 16
      [0,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,0,2,0] alias_counter : 1 ? 1
      [0,4]
        [0,0,2,0]
    [0,0,2,1] alias_counter : 16 ? 16
      [0,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,0,2,2] alias_counter : 4 ? 4
      [0,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [0,1,0,0] alias_counter : 1 ? 1
      [0,5]
        [0,1,0,0]
    [0,1,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,0,2] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,1,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [0,1,1,1] alias_counter : 1 ? 1
      [1,5]
        [0,1,1,1]
    [0,1,1,2] alias_counter : 1 ? 1
      [3,5]
        [0,1,1,2]
    [0,1,2,0] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,1,2,1] alias_counter : 1 ? 1
      [3,5]
        [0,1,2,1]
    [0,1,2,2] alias_counter : 1 ? 1
      [2,5]
        [0,1,2,2]
    [0,2,0,0] alias_counter : 1 ? 1
      [0,4]
        [0,2,0,0]
    [0,2,0,1] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,2,0,2] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,1,0] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [0,2,1,1] alias_counter : 1 ? 1
      [1,4]
        [0,2,1,1]
    [0,2,1,2] alias_counter : 1 ? 1
      [3,4]
        [0,2,1,2]
    [0,2,2,0] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,2,1] alias_counter : 1 ? 1
      [3,4]
        [0,2,2,1]
    [0,2,2,2] alias_counter : 1 ? 1
      [2,4]
        [0,2,2,2]
    [1,0,0,0] alias_counter : 1 ? 1
      [0,5]
        [1,0,0,0]
    [1,0,0,1] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,0,2] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,0,1,0] alias_counter : 4 ? 4
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [1,0,0,1]
        [1,0,1,0]
    [1,0,1,1] alias_counter : 1 ? 1
      [1,5]
        [1,0,1,1]
    [1,0,1,2] alias_counter : 1 ? 1
      [3,5]
        [1,0,1,2]
    [1,0,2,0] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,0,2,1] alias_counter : 1 ? 1
      [3,5]
        [1,0,2,1]
    [1,0,2,2] alias_counter : 1 ? 1
      [2,5]
        [1,0,2,2]
    [1,1,0,0] alias_counter : 2 ? 2
      [0,1]
        [0,0,1,1]
        [1,1,0,0]
    [1,1,0,1] alias_counter : 1 ? 1
      [1,5]
        [1,1,0,1]
    [1,1,0,2] alias_counter : 1 ? 1
      [1,4]
        [1,1,0,2]
    [1,1,1,0] alias_counter : 1 ? 1
      [1,5]
        [1,1,1,0]
    [1,1,1,1] alias_counter : 2 ? 2
      [1,1]
        [0,0,0,0]
        [1,1,1,1]
    [1,1,1,2] alias_counter : 16 ? 16
      [1,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,1,2,0] alias_counter : 1 ? 1
      [1,4]
        [1,1,2,0]
    [1,1,2,1] alias_counter : 16 ? 16
      [1,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,1,2,2] alias_counter : 4 ? 4
      [1,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [1,2,0,0] alias_counter : 16 ? 16
      [0,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,2,0,1] alias_counter : 1 ? 1
      [3,5]
        [1,2,0,1]
    [1,2,0,2] alias_counter : 1 ? 1
      [3,4]
        [1,2,0,2]
    [1,2,1,0] alias_counter : 1 ? 1
      [3,5]
        [1,2,1,0]
    [1,2,1,1] alias_counter : 16 ? 16
      [1,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [1,2,1,2] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,0] alias_counter : 1 ? 1
      [3,4]
        [1,2,2,0]
    [1,2,2,1] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,2] alias_counter : 1 ? 1
      [2,3]
        [1,2,2,2]
    [2,0,0,0] alias_counter : 1 ? 1
      [0,4]
        [2,0,0,0]
    [2,0,0,1] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [2,0,0,2] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,1,0] alias_counter : 16 ? 16
      [4,5]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [2,0,1,1] alias_counter : 1 ? 1
      [1,4]
        [2,0,1,1]
    [2,0,1,2] alias_counter : 1 ? 1
      [3,4]
        [2,0,1,2]
    [2,0,2,0] alias_counter : 8 ? 8
      [4,4]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,2,1] alias_counter : 1 ? 1
      [3,4]
        [2,0,2,1]
    [2,0,2,2] alias_counter : 1 ? 1
      [2,4]
        [2,0,2,2]
    [2,1,0,0] alias_counter : 16 ? 16
      [0,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [2,1,0,1] alias_counter : 1 ? 1
      [3,5]
        [2,1,0,1]
    [2,1,0,2] alias_counter : 1 ? 1
      [3,4]
        [2,1,0,2]
    [2,1,1,0] alias_counter : 1 ? 1
      [3,5]
        [2,1,1,0]
    [2,1,1,1] alias_counter : 16 ? 16
      [1,3]
        [0,0,1,2]
        [0,0,2,1]
        [0,1,0,2]
        [0,1,2,0]
        [0,2,0,1]
        [0,2,1,0]
        [1,0,0,2]
        [1,0,2,0]
        [1,1,1,2]
        [1,1,2,1]
        [1,2,0,0]
        [1,2,1,1]
        [2,0,0,1]
        [2,0,1,0]
        [2,1,0,0]
        [2,1,1,1]
    [2,1,1,2] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,0] alias_counter : 1 ? 1
      [3,4]
        [2,1,2,0]
    [2,1,2,1] alias_counter : 8 ? 8
      [3,3]
        [0,2,0,2]
        [0,2,2,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,2] alias_counter : 1 ? 1
      [2,3]
        [2,1,2,2]
    [2,2,0,0] alias_counter : 4 ? 4
      [0,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,0,1] alias_counter : 1 ? 1
      [2,5]
        [2,2,0,1]
    [2,2,0,2] alias_counter : 1 ? 1
      [2,4]
        [2,2,0,2]
    [2,2,1,0] alias_counter : 1 ? 1
      [2,5]
        [2,2,1,0]
    [2,2,1,1] alias_counter : 4 ? 4
      [1,2]
        [0,0,2,2]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,1,2] alias_counter : 1 ? 1
      [2,3]
        [2,2,1,2]
    [2,2,2,0] alias_counter : 1 ? 1
      [2,4]
        [2,2,2,0]
    [2,2,2,1] alias_counter : 1 ? 1
      [2,3]
        [2,2,2,1]
    [2,2,2,2] alias_counter : 1 ? 1
      [2,2]
        [2,2,2,2]

    === cubic aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 3 ? 3
      [0,0]
        [0,0,0,0]
        [1,1,1,1]
        [2,2,2,2]
    [0,0,0,1] alias_counter : 1 ? 1
      [0,5]
        [0,0,0,1]
    [0,0,0,2] alias_counter : 1 ? 1
      [0,4]
        [0,0,0,2]
    [0,0,1,0] alias_counter : 1 ? 1
      [0,5]
        [0,0,1,0]
    [0,0,1,1] alias_counter : 6 ? 6
      [0,1]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [0,0,1,2] alias_counter : 1 ? 1
      [0,3]
        [0,0,1,2]
    [0,0,2,0] alias_counter : 1 ? 1
      [0,4]
        [0,0,2,0]
    [0,0,2,1] alias_counter : 1 ? 1
      [0,3]
        [0,0,2,1]
    [0,0,2,2] alias_counter : 6 ? 6
      [0,2]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [0,1,0,0] alias_counter : 1 ? 1
      [0,5]
        [0,1,0,0]
    [0,1,0,1] alias_counter : 12 ? 12
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,1,0,2] alias_counter : 1 ? 1
      [4,5]
        [0,1,0,2]
    [0,1,1,0] alias_counter : 12 ? 12
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,1,1,1] alias_counter : 1 ? 1
      [1,5]
        [0,1,1,1]
    [0,1,1,2] alias_counter : 1 ? 1
      [3,5]
        [0,1,1,2]
    [0,1,2,0] alias_counter : 1 ? 1
      [4,5]
        [0,1,2,0]
    [0,1,2,1] alias_counter : 1 ? 1
      [3,5]
        [0,1,2,1]
    [0,1,2,2] alias_counter : 1 ? 1
      [2,5]
        [0,1,2,2]
    [0,2,0,0] alias_counter : 1 ? 1
      [0,4]
        [0,2,0,0]
    [0,2,0,1] alias_counter : 1 ? 1
      [4,5]
        [0,2,0,1]
    [0,2,0,2] alias_counter : 12 ? 12
      [4,4]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,1,0] alias_counter : 1 ? 1
      [4,5]
        [0,2,1,0]
    [0,2,1,1] alias_counter : 1 ? 1
      [1,4]
        [0,2,1,1]
    [0,2,1,2] alias_counter : 1 ? 1
      [3,4]
        [0,2,1,2]
    [0,2,2,0] alias_counter : 12 ? 12
      [4,4]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,2,1] alias_counter : 1 ? 1
      [3,4]
        [0,2,2,1]
    [0,2,2,2] alias_counter : 1 ? 1
      [2,4]
        [0,2,2,2]
    [1,0,0,0] alias_counter : 1 ? 1
      [0,5]
        [1,0,0,0]
    [1,0,0,1] alias_counter : 12 ? 12
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,0,0,2] alias_counter : 1 ? 1
      [4,5]
        [1,0,0,2]
    [1,0,1,0] alias_counter : 12 ? 12
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,0,1,1] alias_counter : 1 ? 1
      [1,5]
        [1,0,1,1]
    [1,0,1,2] alias_counter : 1 ? 1
      [3,5]
        [1,0,1,2]
    [1,0,2,0] alias_counter : 1 ? 1
      [4,5]
        [1,0,2,0]
    [1,0,2,1] alias_counter : 1 ? 1
      [3,5]
        [1,0,2,1]
    [1,0,2,2] alias_counter : 1 ? 1
      [2,5]
        [1,0,2,2]
    [1,1,0,0] alias_counter : 6 ? 6
      [0,1]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [1,1,0,1] alias_counter : 1 ? 1
      [1,5]
        [1,1,0,1]
    [1,1,0,2] alias_counter : 1 ? 1
      [1,4]
        [1,1,0,2]
    [1,1,1,0] alias_counter : 1 ? 1
      [1,5]
        [1,1,1,0]
    [1,1,1,1] alias_counter : 3 ? 3
      [1,1]
        [0,0,0,0]
        [1,1,1,1]
        [2,2,2,2]
    [1,1,1,2] alias_counter : 1 ? 1
      [1,3]
        [1,1,1,2]
    [1,1,2,0] alias_counter : 1 ? 1
      [1,4]
        [1,1,2,0]
    [1,1,2,1] alias_counter : 1 ? 1
      [1,3]
        [1,1,2,1]
    [1,1,2,2] alias_counter : 6 ? 6
      [1,2]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [1,2,0,0] alias_counter : 1 ? 1
      [0,3]
        [1,2,0,0]
    [1,2,0,1] alias_counter : 1 ? 1
      [3,5]
        [1,2,0,1]
    [1,2,0,2] alias_counter : 1 ? 1
      [3,4]
        [1,2,0,2]
    [1,2,1,0] alias_counter : 1 ? 1
      [3,5]
        [1,2,1,0]
    [1,2,1,1] alias_counter : 1 ? 1
      [1,3]
        [1,2,1,1]
    [1,2,1,2] alias_counter : 12 ? 12
      [3,3]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,0] alias_counter : 1 ? 1
      [3,4]
        [1,2,2,0]
    [1,2,2,1] alias_counter : 12 ? 12
      [3,3]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,2] alias_counter : 1 ? 1
      [2,3]
        [1,2,2,2]
    [2,0,0,0] alias_counter : 1 ? 1
      [0,4]
        [2,0,0,0]
    [2,0,0,1] alias_counter : 1 ? 1
      [4,5]
        [2,0,0,1]
    [2,0,0,2] alias_counter : 12 ? 12
      [4,4]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,1,0] alias_counter : 1 ? 1
      [4,5]
        [2,0,1,0]
    [2,0,1,1] alias_counter : 1 ? 1
      [1,4]
        [2,0,1,1]
    [2,0,1,2] alias_counter : 1 ? 1
      [3,4]
        [2,0,1,2]
    [2,0,2,0] alias_counter : 12 ? 12
      [4,4]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,2,1] alias_counter : 1 ? 1
      [3,4]
        [2,0,2,1]
    [2,0,2,2] alias_counter : 1 ? 1
      [2,4]
        [2,0,2,2]
    [2,1,0,0] alias_counter : 1 ? 1
      [0,3]
        [2,1,0,0]
    [2,1,0,1] alias_counter : 1 ? 1
      [3,5]
        [2,1,0,1]
    [2,1,0,2] alias_counter : 1 ? 1
      [3,4]
        [2,1,0,2]
    [2,1,1,0] alias_counter : 1 ? 1
      [3,5]
        [2,1,1,0]
    [2,1,1,1] alias_counter : 1 ? 1
      [1,3]
        [2,1,1,1]
    [2,1,1,2] alias_counter : 12 ? 12
      [3,3]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,0] alias_counter : 1 ? 1
      [3,4]
        [2,1,2,0]
    [2,1,2,1] alias_counter : 12 ? 12
      [3,3]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,2] alias_counter : 1 ? 1
      [2,3]
        [2,1,2,2]
    [2,2,0,0] alias_counter : 6 ? 6
      [0,2]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,0,1] alias_counter : 1 ? 1
      [2,5]
        [2,2,0,1]
    [2,2,0,2] alias_counter : 1 ? 1
      [2,4]
        [2,2,0,2]
    [2,2,1,0] alias_counter : 1 ? 1
      [2,5]
        [2,2,1,0]
    [2,2,1,1] alias_counter : 6 ? 6
      [1,2]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,1,2] alias_counter : 1 ? 1
      [2,3]
        [2,2,1,2]
    [2,2,2,0] alias_counter : 1 ? 1
      [2,4]
        [2,2,2,0]
    [2,2,2,1] alias_counter : 1 ? 1
      [2,3]
        [2,2,2,1]
    [2,2,2,2] alias_counter : 3 ? 3
      [2,2]
        [0,0,0,0]
        [1,1,1,1]
        [2,2,2,2]

    === isotropic aliases a.k.a. reduced set
    [0,0,0,0] alias_counter : 3 ? 3
      [0,0]
        [0,0,0,0]
        [1,1,1,1]
        [2,2,2,2]
    [0,0,0,1] alias_counter : 1 ? 1
      [0,5]
        [0,0,0,1]
    [0,0,0,2] alias_counter : 1 ? 1
      [0,4]
        [0,0,0,2]
    [0,0,1,0] alias_counter : 1 ? 1
      [0,5]
        [0,0,1,0]
    [0,0,1,1] alias_counter : 6 ? 6
      [0,1]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [0,0,1,2] alias_counter : 1 ? 1
      [0,3]
        [0,0,1,2]
    [0,0,2,0] alias_counter : 1 ? 1
      [0,4]
        [0,0,2,0]
    [0,0,2,1] alias_counter : 1 ? 1
      [0,3]
        [0,0,2,1]
    [0,0,2,2] alias_counter : 6 ? 6
      [0,2]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [0,1,0,0] alias_counter : 1 ? 1
      [0,5]
        [0,1,0,0]
    [0,1,0,1] alias_counter : 12 ? 12
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,1,0,2] alias_counter : 1 ? 1
      [4,5]
        [0,1,0,2]
    [0,1,1,0] alias_counter : 12 ? 12
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,1,1,1] alias_counter : 1 ? 1
      [1,5]
        [0,1,1,1]
    [0,1,1,2] alias_counter : 1 ? 1
      [3,5]
        [0,1,1,2]
    [0,1,2,0] alias_counter : 1 ? 1
      [4,5]
        [0,1,2,0]
    [0,1,2,1] alias_counter : 1 ? 1
      [3,5]
        [0,1,2,1]
    [0,1,2,2] alias_counter : 1 ? 1
      [2,5]
        [0,1,2,2]
    [0,2,0,0] alias_counter : 1 ? 1
      [0,4]
        [0,2,0,0]
    [0,2,0,1] alias_counter : 1 ? 1
      [4,5]
        [0,2,0,1]
    [0,2,0,2] alias_counter : 12 ? 12
      [4,4]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,1,0] alias_counter : 1 ? 1
      [4,5]
        [0,2,1,0]
    [0,2,1,1] alias_counter : 1 ? 1
      [1,4]
        [0,2,1,1]
    [0,2,1,2] alias_counter : 1 ? 1
      [3,4]
        [0,2,1,2]
    [0,2,2,0] alias_counter : 12 ? 12
      [4,4]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [0,2,2,1] alias_counter : 1 ? 1
      [3,4]
        [0,2,2,1]
    [0,2,2,2] alias_counter : 1 ? 1
      [2,4]
        [0,2,2,2]
    [1,0,0,0] alias_counter : 1 ? 1
      [0,5]
        [1,0,0,0]
    [1,0,0,1] alias_counter : 12 ? 12
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,0,0,2] alias_counter : 1 ? 1
      [4,5]
        [1,0,0,2]
    [1,0,1,0] alias_counter : 12 ? 12
      [5,5]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,0,1,1] alias_counter : 1 ? 1
      [1,5]
        [1,0,1,1]
    [1,0,1,2] alias_counter : 1 ? 1
      [3,5]
        [1,0,1,2]
    [1,0,2,0] alias_counter : 1 ? 1
      [4,5]
        [1,0,2,0]
    [1,0,2,1] alias_counter : 1 ? 1
      [3,5]
        [1,0,2,1]
    [1,0,2,2] alias_counter : 1 ? 1
      [2,5]
        [1,0,2,2]
    [1,1,0,0] alias_counter : 6 ? 6
      [0,1]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [1,1,0,1] alias_counter : 1 ? 1
      [1,5]
        [1,1,0,1]
    [1,1,0,2] alias_counter : 1 ? 1
      [1,4]
        [1,1,0,2]
    [1,1,1,0] alias_counter : 1 ? 1
      [1,5]
        [1,1,1,0]
    [1,1,1,1] alias_counter : 3 ? 3
      [1,1]
        [0,0,0,0]
        [1,1,1,1]
        [2,2,2,2]
    [1,1,1,2] alias_counter : 1 ? 1
      [1,3]
        [1,1,1,2]
    [1,1,2,0] alias_counter : 1 ? 1
      [1,4]
        [1,1,2,0]
    [1,1,2,1] alias_counter : 1 ? 1
      [1,3]
        [1,1,2,1]
    [1,1,2,2] alias_counter : 6 ? 6
      [1,2]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [1,2,0,0] alias_counter : 1 ? 1
      [0,3]
        [1,2,0,0]
    [1,2,0,1] alias_counter : 1 ? 1
      [3,5]
        [1,2,0,1]
    [1,2,0,2] alias_counter : 1 ? 1
      [3,4]
        [1,2,0,2]
    [1,2,1,0] alias_counter : 1 ? 1
      [3,5]
        [1,2,1,0]
    [1,2,1,1] alias_counter : 1 ? 1
      [1,3]
        [1,2,1,1]
    [1,2,1,2] alias_counter : 12 ? 12
      [3,3]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,0] alias_counter : 1 ? 1
      [3,4]
        [1,2,2,0]
    [1,2,2,1] alias_counter : 12 ? 12
      [3,3]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [1,2,2,2] alias_counter : 1 ? 1
      [2,3]
        [1,2,2,2]
    [2,0,0,0] alias_counter : 1 ? 1
      [0,4]
        [2,0,0,0]
    [2,0,0,1] alias_counter : 1 ? 1
      [4,5]
        [2,0,0,1]
    [2,0,0,2] alias_counter : 12 ? 12
      [4,4]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,1,0] alias_counter : 1 ? 1
      [4,5]
        [2,0,1,0]
    [2,0,1,1] alias_counter : 1 ? 1
      [1,4]
        [2,0,1,1]
    [2,0,1,2] alias_counter : 1 ? 1
      [3,4]
        [2,0,1,2]
    [2,0,2,0] alias_counter : 12 ? 12
      [4,4]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,0,2,1] alias_counter : 1 ? 1
      [3,4]
        [2,0,2,1]
    [2,0,2,2] alias_counter : 1 ? 1
      [2,4]
        [2,0,2,2]
    [2,1,0,0] alias_counter : 1 ? 1
      [0,3]
        [2,1,0,0]
    [2,1,0,1] alias_counter : 1 ? 1
      [3,5]
        [2,1,0,1]
    [2,1,0,2] alias_counter : 1 ? 1
      [3,4]
        [2,1,0,2]
    [2,1,1,0] alias_counter : 1 ? 1
      [3,5]
        [2,1,1,0]
    [2,1,1,1] alias_counter : 1 ? 1
      [1,3]
        [2,1,1,1]
    [2,1,1,2] alias_counter : 12 ? 12
      [3,3]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,0] alias_counter : 1 ? 1
      [3,4]
        [2,1,2,0]
    [2,1,2,1] alias_counter : 12 ? 12
      [3,3]
        [0,1,0,1]
        [0,1,1,0]
        [0,2,0,2]
        [0,2,2,0]
        [1,0,0,1]
        [1,0,1,0]
        [1,2,1,2]
        [1,2,2,1]
        [2,0,0,2]
        [2,0,2,0]
        [2,1,1,2]
        [2,1,2,1]
    [2,1,2,2] alias_counter : 1 ? 1
      [2,3]
        [2,1,2,2]
    [2,2,0,0] alias_counter : 6 ? 6
      [0,2]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,0,1] alias_counter : 1 ? 1
      [2,5]
        [2,2,0,1]
    [2,2,0,2] alias_counter : 1 ? 1
      [2,4]
        [2,2,0,2]
    [2,2,1,0] alias_counter : 1 ? 1
      [2,5]
        [2,2,1,0]
    [2,2,1,1] alias_counter : 6 ? 6
      [1,2]
        [0,0,1,1]
        [0,0,2,2]
        [1,1,0,0]
        [1,1,2,2]
        [2,2,0,0]
        [2,2,1,1]
    [2,2,1,2] alias_counter : 1 ? 1
      [2,3]
        [2,2,1,2]
    [2,2,2,0] alias_counter : 1 ? 1
      [2,4]
        [2,2,2,0]
    [2,2,2,1] alias_counter : 1 ? 1
      [2,3]
        [2,2,2,1]
    [2,2,2,2] alias_counter : 3 ? 3
      [2,2]
        [0,0,0,0]
        [1,1,1,1]
        [2,2,2,2]

Symmetry group type predicates
```cpp
bool indexXXXX_predicate;
mpc::core::TensorRank4ComponentIndex index_test = index0000;

std::cout << "\n=== none symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::NoneSymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::NoneSymmetryGroupType>(indexXXXX, index_test);
                    //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== triclinic symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::TriclinicSymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::TriclinicSymmetryGroupType>(indexXXXX, index_test);
                    std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== monoclinicx2 symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::MonoclinicX2SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::MonoclinicX2SymmetryGroupType>(indexXXXX, index_test);
                    //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== monoclinicx3 symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::MonoclinicX3SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::MonoclinicX3SymmetryGroupType>(indexXXXX, index_test);
                    //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== orthorhombic symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::OrthorhombicSymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::OrthorhombicSymmetryGroupType>(indexXXXX, index_test);
                    //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}


std::cout << "\n=== hexagonal symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::HexagonalSymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::HexagonalSymmetryGroupType>(indexXXXX, index_test);
                    //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== tetragonal7 symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::Tetragonal7SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::Tetragonal7SymmetryGroupType>(indexXXXX, index_test);
                    //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== tetragonal6 symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::Tetragonal6SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::Tetragonal6SymmetryGroupType>(indexXXXX, index_test);
                    //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== trigonal7 symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::Trigonal7SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::Trigonal7SymmetryGroupType>(indexXXXX, index_test);
                    //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== trigonal6 symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::Trigonal6SymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::Trigonal6SymmetryGroupType>(indexXXXX, index_test);
                    //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== cubic symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::CubicSymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::CubicSymmetryGroupType>(indexXXXX, index_test);
                    //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}

std::cout << "\n=== isotropic symmetry group type predicates" << std::endl;
for (auto indexXXXX : vec_indexXXXX) {
    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexHasAlias<mpc::core::IsotropicSymmetryGroupType>(indexXXXX);
    std::cout << indexXXXX << " index has alias ? : " << indexXXXX_predicate << std::endl;

    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            for (int k=0; k<3; ++k) {
                for (int l=0; l<3; ++l) {
                    index_test = mpc::core::TensorRank4ComponentIndex(i,j,k,l);
                    indexXXXX_predicate = mpc::core::TensorRank4ComponentIndexIsAlias<mpc::core::IsotropicSymmetryGroupType>(indexXXXX, index_test);
                    //std::cout << indexXXXX << " is_alias " << index_test << " ? " << indexXXXX_predicate << std::endl;
                }
            }
        }
    }
}
```
Output

    === none symmetry group type predicates
    [0,0,0,0] index has alias ? : false
    [0,0,0,1] index has alias ? : false
    [0,0,0,2] index has alias ? : false
    [0,0,1,0] index has alias ? : false
    [0,0,1,1] index has alias ? : false
    [0,0,1,2] index has alias ? : false
    [0,0,2,0] index has alias ? : false
    [0,0,2,1] index has alias ? : false
    [0,0,2,2] index has alias ? : false
    [0,1,0,0] index has alias ? : false
    [0,1,0,1] index has alias ? : false
    [0,1,0,2] index has alias ? : false
    [0,1,1,0] index has alias ? : false
    [0,1,1,1] index has alias ? : false
    [0,1,1,2] index has alias ? : false
    [0,1,2,0] index has alias ? : false
    [0,1,2,1] index has alias ? : false
    [0,1,2,2] index has alias ? : false
    [0,2,0,0] index has alias ? : false
    [0,2,0,1] index has alias ? : false
    [0,2,0,2] index has alias ? : false
    [0,2,1,0] index has alias ? : false
    [0,2,1,1] index has alias ? : false
    [0,2,1,2] index has alias ? : false
    [0,2,2,0] index has alias ? : false
    [0,2,2,1] index has alias ? : false
    [0,2,2,2] index has alias ? : false
    [1,0,0,0] index has alias ? : false
    [1,0,0,1] index has alias ? : false
    [1,0,0,2] index has alias ? : false
    [1,0,1,0] index has alias ? : false
    [1,0,1,1] index has alias ? : false
    [1,0,1,2] index has alias ? : false
    [1,0,2,0] index has alias ? : false
    [1,0,2,1] index has alias ? : false
    [1,0,2,2] index has alias ? : false
    [1,1,0,0] index has alias ? : false
    [1,1,0,1] index has alias ? : false
    [1,1,0,2] index has alias ? : false
    [1,1,1,0] index has alias ? : false
    [1,1,1,1] index has alias ? : false
    [1,1,1,2] index has alias ? : false
    [1,1,2,0] index has alias ? : false
    [1,1,2,1] index has alias ? : false
    [1,1,2,2] index has alias ? : false
    [1,2,0,0] index has alias ? : false
    [1,2,0,1] index has alias ? : false
    [1,2,0,2] index has alias ? : false
    [1,2,1,0] index has alias ? : false
    [1,2,1,1] index has alias ? : false
    [1,2,1,2] index has alias ? : false
    [1,2,2,0] index has alias ? : false
    [1,2,2,1] index has alias ? : false
    [1,2,2,2] index has alias ? : false
    [2,0,0,0] index has alias ? : false
    [2,0,0,1] index has alias ? : false
    [2,0,0,2] index has alias ? : false
    [2,0,1,0] index has alias ? : false
    [2,0,1,1] index has alias ? : false
    [2,0,1,2] index has alias ? : false
    [2,0,2,0] index has alias ? : false
    [2,0,2,1] index has alias ? : false
    [2,0,2,2] index has alias ? : false
    [2,1,0,0] index has alias ? : false
    [2,1,0,1] index has alias ? : false
    [2,1,0,2] index has alias ? : false
    [2,1,1,0] index has alias ? : false
    [2,1,1,1] index has alias ? : false
    [2,1,1,2] index has alias ? : false
    [2,1,2,0] index has alias ? : false
    [2,1,2,1] index has alias ? : false
    [2,1,2,2] index has alias ? : false
    [2,2,0,0] index has alias ? : false
    [2,2,0,1] index has alias ? : false
    [2,2,0,2] index has alias ? : false
    [2,2,1,0] index has alias ? : false
    [2,2,1,1] index has alias ? : false
    [2,2,1,2] index has alias ? : false
    [2,2,2,0] index has alias ? : false
    [2,2,2,1] index has alias ? : false
    [2,2,2,2] index has alias ? : false

    === triclinic symmetry group type predicates
    [0,0,0,0] index has alias ? : false
    [0,0,0,0] is_alias [0,0,0,0] ? false
    [0,0,0,0] is_alias [0,0,0,1] ? false
    [0,0,0,0] is_alias [0,0,0,2] ? false
    [0,0,0,0] is_alias [0,0,1,0] ? false
    [0,0,0,0] is_alias [0,0,1,1] ? false
    [0,0,0,0] is_alias [0,0,1,2] ? false
    [0,0,0,0] is_alias [0,0,2,0] ? false
    [0,0,0,0] is_alias [0,0,2,1] ? false
    [0,0,0,0] is_alias [0,0,2,2] ? false
    [0,0,0,0] is_alias [0,1,0,0] ? false
    [0,0,0,0] is_alias [0,1,0,1] ? false
    [0,0,0,0] is_alias [0,1,0,2] ? false
    [0,0,0,0] is_alias [0,1,1,0] ? false
    [0,0,0,0] is_alias [0,1,1,1] ? false
    [0,0,0,0] is_alias [0,1,1,2] ? false
    [0,0,0,0] is_alias [0,1,2,0] ? false
    [0,0,0,0] is_alias [0,1,2,1] ? false
    [0,0,0,0] is_alias [0,1,2,2] ? false
    [0,0,0,0] is_alias [0,2,0,0] ? false
    [0,0,0,0] is_alias [0,2,0,1] ? false
    [0,0,0,0] is_alias [0,2,0,2] ? false
    [0,0,0,0] is_alias [0,2,1,0] ? false
    [0,0,0,0] is_alias [0,2,1,1] ? false
    [0,0,0,0] is_alias [0,2,1,2] ? false
    [0,0,0,0] is_alias [0,2,2,0] ? false
    [0,0,0,0] is_alias [0,2,2,1] ? false
    [0,0,0,0] is_alias [0,2,2,2] ? false
    [0,0,0,0] is_alias [1,0,0,0] ? false
    [0,0,0,0] is_alias [1,0,0,1] ? false
    [0,0,0,0] is_alias [1,0,0,2] ? false
    [0,0,0,0] is_alias [1,0,1,0] ? false
    [0,0,0,0] is_alias [1,0,1,1] ? false
    [0,0,0,0] is_alias [1,0,1,2] ? false
    [0,0,0,0] is_alias [1,0,2,0] ? false
    [0,0,0,0] is_alias [1,0,2,1] ? false
    [0,0,0,0] is_alias [1,0,2,2] ? false
    [0,0,0,0] is_alias [1,1,0,0] ? false
    [0,0,0,0] is_alias [1,1,0,1] ? false
    [0,0,0,0] is_alias [1,1,0,2] ? false
    [0,0,0,0] is_alias [1,1,1,0] ? false
    [0,0,0,0] is_alias [1,1,1,1] ? false
    [0,0,0,0] is_alias [1,1,1,2] ? false
    [0,0,0,0] is_alias [1,1,2,0] ? false
    [0,0,0,0] is_alias [1,1,2,1] ? false
    [0,0,0,0] is_alias [1,1,2,2] ? false
    [0,0,0,0] is_alias [1,2,0,0] ? false
    [0,0,0,0] is_alias [1,2,0,1] ? false
    [0,0,0,0] is_alias [1,2,0,2] ? false
    [0,0,0,0] is_alias [1,2,1,0] ? false
    [0,0,0,0] is_alias [1,2,1,1] ? false
    [0,0,0,0] is_alias [1,2,1,2] ? false
    [0,0,0,0] is_alias [1,2,2,0] ? false
    [0,0,0,0] is_alias [1,2,2,1] ? false
    [0,0,0,0] is_alias [1,2,2,2] ? false
    [0,0,0,0] is_alias [2,0,0,0] ? false
    [0,0,0,0] is_alias [2,0,0,1] ? false
    [0,0,0,0] is_alias [2,0,0,2] ? false
    [0,0,0,0] is_alias [2,0,1,0] ? false
    [0,0,0,0] is_alias [2,0,1,1] ? false
    [0,0,0,0] is_alias [2,0,1,2] ? false
    [0,0,0,0] is_alias [2,0,2,0] ? false
    [0,0,0,0] is_alias [2,0,2,1] ? false
    [0,0,0,0] is_alias [2,0,2,2] ? false
    [0,0,0,0] is_alias [2,1,0,0] ? false
    [0,0,0,0] is_alias [2,1,0,1] ? false
    [0,0,0,0] is_alias [2,1,0,2] ? false
    [0,0,0,0] is_alias [2,1,1,0] ? false
    [0,0,0,0] is_alias [2,1,1,1] ? false
    [0,0,0,0] is_alias [2,1,1,2] ? false
    [0,0,0,0] is_alias [2,1,2,0] ? false
    [0,0,0,0] is_alias [2,1,2,1] ? false
    [0,0,0,0] is_alias [2,1,2,2] ? false
    [0,0,0,0] is_alias [2,2,0,0] ? false
    [0,0,0,0] is_alias [2,2,0,1] ? false
    [0,0,0,0] is_alias [2,2,0,2] ? false
    [0,0,0,0] is_alias [2,2,1,0] ? false
    [0,0,0,0] is_alias [2,2,1,1] ? false
    [0,0,0,0] is_alias [2,2,1,2] ? false
    [0,0,0,0] is_alias [2,2,2,0] ? false
    [0,0,0,0] is_alias [2,2,2,1] ? false
    [0,0,0,0] is_alias [2,2,2,2] ? false
    [0,0,0,1] index has alias ? : true
    [0,0,0,1] is_alias [0,0,0,0] ? false
    [0,0,0,1] is_alias [0,0,0,1] ? false
    [0,0,0,1] is_alias [0,0,0,2] ? false
    [0,0,0,1] is_alias [0,0,1,0] ? true
    [0,0,0,1] is_alias [0,0,1,1] ? false
    [0,0,0,1] is_alias [0,0,1,2] ? false
    [0,0,0,1] is_alias [0,0,2,0] ? false
    [0,0,0,1] is_alias [0,0,2,1] ? false
    [0,0,0,1] is_alias [0,0,2,2] ? false
    [0,0,0,1] is_alias [0,1,0,0] ? true
    [0,0,0,1] is_alias [0,1,0,1] ? false
    [0,0,0,1] is_alias [0,1,0,2] ? false
    [0,0,0,1] is_alias [0,1,1,0] ? false
    [0,0,0,1] is_alias [0,1,1,1] ? false
    [0,0,0,1] is_alias [0,1,1,2] ? false
    [0,0,0,1] is_alias [0,1,2,0] ? false
    [0,0,0,1] is_alias [0,1,2,1] ? false
    [0,0,0,1] is_alias [0,1,2,2] ? false
    [0,0,0,1] is_alias [0,2,0,0] ? false
    [0,0,0,1] is_alias [0,2,0,1] ? false
    [0,0,0,1] is_alias [0,2,0,2] ? false
    [0,0,0,1] is_alias [0,2,1,0] ? false
    [0,0,0,1] is_alias [0,2,1,1] ? false
    [0,0,0,1] is_alias [0,2,1,2] ? false
    [0,0,0,1] is_alias [0,2,2,0] ? false
    [0,0,0,1] is_alias [0,2,2,1] ? false
    [0,0,0,1] is_alias [0,2,2,2] ? false
    [0,0,0,1] is_alias [1,0,0,0] ? true
    [0,0,0,1] is_alias [1,0,0,1] ? false
    [0,0,0,1] is_alias [1,0,0,2] ? false
    [0,0,0,1] is_alias [1,0,1,0] ? false
    [0,0,0,1] is_alias [1,0,1,1] ? false
    [0,0,0,1] is_alias [1,0,1,2] ? false
    [0,0,0,1] is_alias [1,0,2,0] ? false
    [0,0,0,1] is_alias [1,0,2,1] ? false
    [0,0,0,1] is_alias [1,0,2,2] ? false
    [0,0,0,1] is_alias [1,1,0,0] ? false
    [0,0,0,1] is_alias [1,1,0,1] ? false
    [0,0,0,1] is_alias [1,1,0,2] ? false
    [0,0,0,1] is_alias [1,1,1,0] ? false
    [0,0,0,1] is_alias [1,1,1,1] ? false
    [0,0,0,1] is_alias [1,1,1,2] ? false
    [0,0,0,1] is_alias [1,1,2,0] ? false
    [0,0,0,1] is_alias [1,1,2,1] ? false
    [0,0,0,1] is_alias [1,1,2,2] ? false
    [0,0,0,1] is_alias [1,2,0,0] ? false
    [0,0,0,1] is_alias [1,2,0,1] ? false
    [0,0,0,1] is_alias [1,2,0,2] ? false
    [0,0,0,1] is_alias [1,2,1,0] ? false
    [0,0,0,1] is_alias [1,2,1,1] ? false
    [0,0,0,1] is_alias [1,2,1,2] ? false
    [0,0,0,1] is_alias [1,2,2,0] ? false
    [0,0,0,1] is_alias [1,2,2,1] ? false
    [0,0,0,1] is_alias [1,2,2,2] ? false
    [0,0,0,1] is_alias [2,0,0,0] ? false
    [0,0,0,1] is_alias [2,0,0,1] ? false
    [0,0,0,1] is_alias [2,0,0,2] ? false
    [0,0,0,1] is_alias [2,0,1,0] ? false
    [0,0,0,1] is_alias [2,0,1,1] ? false
    [0,0,0,1] is_alias [2,0,1,2] ? false
    [0,0,0,1] is_alias [2,0,2,0] ? false
    [0,0,0,1] is_alias [2,0,2,1] ? false
    [0,0,0,1] is_alias [2,0,2,2] ? false
    [0,0,0,1] is_alias [2,1,0,0] ? false
    [0,0,0,1] is_alias [2,1,0,1] ? false
    [0,0,0,1] is_alias [2,1,0,2] ? false
    [0,0,0,1] is_alias [2,1,1,0] ? false
    [0,0,0,1] is_alias [2,1,1,1] ? false
    [0,0,0,1] is_alias [2,1,1,2] ? false
    [0,0,0,1] is_alias [2,1,2,0] ? false
    [0,0,0,1] is_alias [2,1,2,1] ? false
    [0,0,0,1] is_alias [2,1,2,2] ? false
    [0,0,0,1] is_alias [2,2,0,0] ? false
    [0,0,0,1] is_alias [2,2,0,1] ? false
    [0,0,0,1] is_alias [2,2,0,2] ? false
    [0,0,0,1] is_alias [2,2,1,0] ? false
    [0,0,0,1] is_alias [2,2,1,1] ? false
    [0,0,0,1] is_alias [2,2,1,2] ? false
    [0,0,0,1] is_alias [2,2,2,0] ? false
    [0,0,0,1] is_alias [2,2,2,1] ? false
    [0,0,0,1] is_alias [2,2,2,2] ? false
    [0,0,0,2] index has alias ? : true
    [0,0,0,2] is_alias [0,0,0,0] ? false
    [0,0,0,2] is_alias [0,0,0,1] ? false
    [0,0,0,2] is_alias [0,0,0,2] ? false
    [0,0,0,2] is_alias [0,0,1,0] ? false
    [0,0,0,2] is_alias [0,0,1,1] ? false
    [0,0,0,2] is_alias [0,0,1,2] ? false
    [0,0,0,2] is_alias [0,0,2,0] ? true
    [0,0,0,2] is_alias [0,0,2,1] ? false
    [0,0,0,2] is_alias [0,0,2,2] ? false
    [0,0,0,2] is_alias [0,1,0,0] ? false
    [0,0,0,2] is_alias [0,1,0,1] ? false
    [0,0,0,2] is_alias [0,1,0,2] ? false
    [0,0,0,2] is_alias [0,1,1,0] ? false
    [0,0,0,2] is_alias [0,1,1,1] ? false
    [0,0,0,2] is_alias [0,1,1,2] ? false
    [0,0,0,2] is_alias [0,1,2,0] ? false
    [0,0,0,2] is_alias [0,1,2,1] ? false
    [0,0,0,2] is_alias [0,1,2,2] ? false
    [0,0,0,2] is_alias [0,2,0,0] ? true
    [0,0,0,2] is_alias [0,2,0,1] ? false
    [0,0,0,2] is_alias [0,2,0,2] ? false
    [0,0,0,2] is_alias [0,2,1,0] ? false
    [0,0,0,2] is_alias [0,2,1,1] ? false
    [0,0,0,2] is_alias [0,2,1,2] ? false
    [0,0,0,2] is_alias [0,2,2,0] ? false
    [0,0,0,2] is_alias [0,2,2,1] ? false
    [0,0,0,2] is_alias [0,2,2,2] ? false
    [0,0,0,2] is_alias [1,0,0,0] ? false
    [0,0,0,2] is_alias [1,0,0,1] ? false
    [0,0,0,2] is_alias [1,0,0,2] ? false
    [0,0,0,2] is_alias [1,0,1,0] ? false
    [0,0,0,2] is_alias [1,0,1,1] ? false
    [0,0,0,2] is_alias [1,0,1,2] ? false
    [0,0,0,2] is_alias [1,0,2,0] ? false
    [0,0,0,2] is_alias [1,0,2,1] ? false
    [0,0,0,2] is_alias [1,0,2,2] ? false
    [0,0,0,2] is_alias [1,1,0,0] ? false
    [0,0,0,2] is_alias [1,1,0,1] ? false
    [0,0,0,2] is_alias [1,1,0,2] ? false
    [0,0,0,2] is_alias [1,1,1,0] ? false
    [0,0,0,2] is_alias [1,1,1,1] ? false
    [0,0,0,2] is_alias [1,1,1,2] ? false
    [0,0,0,2] is_alias [1,1,2,0] ? false
    [0,0,0,2] is_alias [1,1,2,1] ? false
    [0,0,0,2] is_alias [1,1,2,2] ? false
    [0,0,0,2] is_alias [1,2,0,0] ? false
    [0,0,0,2] is_alias [1,2,0,1] ? false
    [0,0,0,2] is_alias [1,2,0,2] ? false
    [0,0,0,2] is_alias [1,2,1,0] ? false
    [0,0,0,2] is_alias [1,2,1,1] ? false
    [0,0,0,2] is_alias [1,2,1,2] ? false
    [0,0,0,2] is_alias [1,2,2,0] ? false
    [0,0,0,2] is_alias [1,2,2,1] ? false
    [0,0,0,2] is_alias [1,2,2,2] ? false
    [0,0,0,2] is_alias [2,0,0,0] ? true
    [0,0,0,2] is_alias [2,0,0,1] ? false
    [0,0,0,2] is_alias [2,0,0,2] ? false
    [0,0,0,2] is_alias [2,0,1,0] ? false
    [0,0,0,2] is_alias [2,0,1,1] ? false
    [0,0,0,2] is_alias [2,0,1,2] ? false
    [0,0,0,2] is_alias [2,0,2,0] ? false
    [0,0,0,2] is_alias [2,0,2,1] ? false
    [0,0,0,2] is_alias [2,0,2,2] ? false
    [0,0,0,2] is_alias [2,1,0,0] ? false
    [0,0,0,2] is_alias [2,1,0,1] ? false
    [0,0,0,2] is_alias [2,1,0,2] ? false
    [0,0,0,2] is_alias [2,1,1,0] ? false
    [0,0,0,2] is_alias [2,1,1,1] ? false
    [0,0,0,2] is_alias [2,1,1,2] ? false
    [0,0,0,2] is_alias [2,1,2,0] ? false
    [0,0,0,2] is_alias [2,1,2,1] ? false
    [0,0,0,2] is_alias [2,1,2,2] ? false
    [0,0,0,2] is_alias [2,2,0,0] ? false
    [0,0,0,2] is_alias [2,2,0,1] ? false
    [0,0,0,2] is_alias [2,2,0,2] ? false
    [0,0,0,2] is_alias [2,2,1,0] ? false
    [0,0,0,2] is_alias [2,2,1,1] ? false
    [0,0,0,2] is_alias [2,2,1,2] ? false
    [0,0,0,2] is_alias [2,2,2,0] ? false
    [0,0,0,2] is_alias [2,2,2,1] ? false
    [0,0,0,2] is_alias [2,2,2,2] ? false
    [0,0,1,0] index has alias ? : true
    [0,0,1,0] is_alias [0,0,0,0] ? false
    [0,0,1,0] is_alias [0,0,0,1] ? true
    [0,0,1,0] is_alias [0,0,0,2] ? false
    [0,0,1,0] is_alias [0,0,1,0] ? false
    [0,0,1,0] is_alias [0,0,1,1] ? false
    [0,0,1,0] is_alias [0,0,1,2] ? false
    [0,0,1,0] is_alias [0,0,2,0] ? false
    [0,0,1,0] is_alias [0,0,2,1] ? false
    [0,0,1,0] is_alias [0,0,2,2] ? false
    [0,0,1,0] is_alias [0,1,0,0] ? true
    [0,0,1,0] is_alias [0,1,0,1] ? false
    [0,0,1,0] is_alias [0,1,0,2] ? false
    [0,0,1,0] is_alias [0,1,1,0] ? false
    [0,0,1,0] is_alias [0,1,1,1] ? false
    [0,0,1,0] is_alias [0,1,1,2] ? false
    [0,0,1,0] is_alias [0,1,2,0] ? false
    [0,0,1,0] is_alias [0,1,2,1] ? false
    [0,0,1,0] is_alias [0,1,2,2] ? false
    [0,0,1,0] is_alias [0,2,0,0] ? false
    [0,0,1,0] is_alias [0,2,0,1] ? false
    [0,0,1,0] is_alias [0,2,0,2] ? false
    [0,0,1,0] is_alias [0,2,1,0] ? false
    [0,0,1,0] is_alias [0,2,1,1] ? false
    [0,0,1,0] is_alias [0,2,1,2] ? false
    [0,0,1,0] is_alias [0,2,2,0] ? false
    [0,0,1,0] is_alias [0,2,2,1] ? false
    [0,0,1,0] is_alias [0,2,2,2] ? false
    [0,0,1,0] is_alias [1,0,0,0] ? true
    [0,0,1,0] is_alias [1,0,0,1] ? false
    [0,0,1,0] is_alias [1,0,0,2] ? false
    [0,0,1,0] is_alias [1,0,1,0] ? false
    [0,0,1,0] is_alias [1,0,1,1] ? false
    [0,0,1,0] is_alias [1,0,1,2] ? false
    [0,0,1,0] is_alias [1,0,2,0] ? false
    [0,0,1,0] is_alias [1,0,2,1] ? false
    [0,0,1,0] is_alias [1,0,2,2] ? false
    [0,0,1,0] is_alias [1,1,0,0] ? false
    [0,0,1,0] is_alias [1,1,0,1] ? false
    [0,0,1,0] is_alias [1,1,0,2] ? false
    [0,0,1,0] is_alias [1,1,1,0] ? false
    [0,0,1,0] is_alias [1,1,1,1] ? false
    [0,0,1,0] is_alias [1,1,1,2] ? false
    [0,0,1,0] is_alias [1,1,2,0] ? false
    [0,0,1,0] is_alias [1,1,2,1] ? false
    [0,0,1,0] is_alias [1,1,2,2] ? false
    [0,0,1,0] is_alias [1,2,0,0] ? false
    [0,0,1,0] is_alias [1,2,0,1] ? false
    [0,0,1,0] is_alias [1,2,0,2] ? false
    [0,0,1,0] is_alias [1,2,1,0] ? false
    [0,0,1,0] is_alias [1,2,1,1] ? false
    [0,0,1,0] is_alias [1,2,1,2] ? false
    [0,0,1,0] is_alias [1,2,2,0] ? false
    [0,0,1,0] is_alias [1,2,2,1] ? false
    [0,0,1,0] is_alias [1,2,2,2] ? false
    [0,0,1,0] is_alias [2,0,0,0] ? false
    [0,0,1,0] is_alias [2,0,0,1] ? false
    [0,0,1,0] is_alias [2,0,0,2] ? false
    [0,0,1,0] is_alias [2,0,1,0] ? false
    [0,0,1,0] is_alias [2,0,1,1] ? false
    [0,0,1,0] is_alias [2,0,1,2] ? false
    [0,0,1,0] is_alias [2,0,2,0] ? false
    [0,0,1,0] is_alias [2,0,2,1] ? false
    [0,0,1,0] is_alias [2,0,2,2] ? false
    [0,0,1,0] is_alias [2,1,0,0] ? false
    [0,0,1,0] is_alias [2,1,0,1] ? false
    [0,0,1,0] is_alias [2,1,0,2] ? false
    [0,0,1,0] is_alias [2,1,1,0] ? false
    [0,0,1,0] is_alias [2,1,1,1] ? false
    [0,0,1,0] is_alias [2,1,1,2] ? false
    [0,0,1,0] is_alias [2,1,2,0] ? false
    [0,0,1,0] is_alias [2,1,2,1] ? false
    [0,0,1,0] is_alias [2,1,2,2] ? false
    [0,0,1,0] is_alias [2,2,0,0] ? false
    [0,0,1,0] is_alias [2,2,0,1] ? false
    [0,0,1,0] is_alias [2,2,0,2] ? false
    [0,0,1,0] is_alias [2,2,1,0] ? false
    [0,0,1,0] is_alias [2,2,1,1] ? false
    [0,0,1,0] is_alias [2,2,1,2] ? false
    [0,0,1,0] is_alias [2,2,2,0] ? false
    [0,0,1,0] is_alias [2,2,2,1] ? false
    [0,0,1,0] is_alias [2,2,2,2] ? false
    [0,0,1,1] index has alias ? : true
    [0,0,1,1] is_alias [0,0,0,0] ? false
    [0,0,1,1] is_alias [0,0,0,1] ? false
    [0,0,1,1] is_alias [0,0,0,2] ? false
    [0,0,1,1] is_alias [0,0,1,0] ? false
    [0,0,1,1] is_alias [0,0,1,1] ? false
    [0,0,1,1] is_alias [0,0,1,2] ? false
    [0,0,1,1] is_alias [0,0,2,0] ? false
    [0,0,1,1] is_alias [0,0,2,1] ? false
    [0,0,1,1] is_alias [0,0,2,2] ? false
    [0,0,1,1] is_alias [0,1,0,0] ? false
    [0,0,1,1] is_alias [0,1,0,1] ? false
    [0,0,1,1] is_alias [0,1,0,2] ? false
    [0,0,1,1] is_alias [0,1,1,0] ? false
    [0,0,1,1] is_alias [0,1,1,1] ? false
    [0,0,1,1] is_alias [0,1,1,2] ? false
    [0,0,1,1] is_alias [0,1,2,0] ? false
    [0,0,1,1] is_alias [0,1,2,1] ? false
    [0,0,1,1] is_alias [0,1,2,2] ? false
    [0,0,1,1] is_alias [0,2,0,0] ? false
    [0,0,1,1] is_alias [0,2,0,1] ? false
    [0,0,1,1] is_alias [0,2,0,2] ? false
    [0,0,1,1] is_alias [0,2,1,0] ? false
    [0,0,1,1] is_alias [0,2,1,1] ? false
    [0,0,1,1] is_alias [0,2,1,2] ? false
    [0,0,1,1] is_alias [0,2,2,0] ? false
    [0,0,1,1] is_alias [0,2,2,1] ? false
    [0,0,1,1] is_alias [0,2,2,2] ? false
    [0,0,1,1] is_alias [1,0,0,0] ? false
    [0,0,1,1] is_alias [1,0,0,1] ? false
    [0,0,1,1] is_alias [1,0,0,2] ? false
    [0,0,1,1] is_alias [1,0,1,0] ? false
    [0,0,1,1] is_alias [1,0,1,1] ? false
    [0,0,1,1] is_alias [1,0,1,2] ? false
    [0,0,1,1] is_alias [1,0,2,0] ? false
    [0,0,1,1] is_alias [1,0,2,1] ? false
    [0,0,1,1] is_alias [1,0,2,2] ? false
    [0,0,1,1] is_alias [1,1,0,0] ? true
    [0,0,1,1] is_alias [1,1,0,1] ? false
    [0,0,1,1] is_alias [1,1,0,2] ? false
    [0,0,1,1] is_alias [1,1,1,0] ? false
    [0,0,1,1] is_alias [1,1,1,1] ? false
    [0,0,1,1] is_alias [1,1,1,2] ? false
    [0,0,1,1] is_alias [1,1,2,0] ? false
    [0,0,1,1] is_alias [1,1,2,1] ? false
    [0,0,1,1] is_alias [1,1,2,2] ? false
    [0,0,1,1] is_alias [1,2,0,0] ? false
    [0,0,1,1] is_alias [1,2,0,1] ? false
    [0,0,1,1] is_alias [1,2,0,2] ? false
    [0,0,1,1] is_alias [1,2,1,0] ? false
    [0,0,1,1] is_alias [1,2,1,1] ? false
    [0,0,1,1] is_alias [1,2,1,2] ? false
    [0,0,1,1] is_alias [1,2,2,0] ? false
    [0,0,1,1] is_alias [1,2,2,1] ? false
    [0,0,1,1] is_alias [1,2,2,2] ? false
    [0,0,1,1] is_alias [2,0,0,0] ? false
    [0,0,1,1] is_alias [2,0,0,1] ? false
    [0,0,1,1] is_alias [2,0,0,2] ? false
    [0,0,1,1] is_alias [2,0,1,0] ? false
    [0,0,1,1] is_alias [2,0,1,1] ? false
    [0,0,1,1] is_alias [2,0,1,2] ? false
    [0,0,1,1] is_alias [2,0,2,0] ? false
    [0,0,1,1] is_alias [2,0,2,1] ? false
    [0,0,1,1] is_alias [2,0,2,2] ? false
    [0,0,1,1] is_alias [2,1,0,0] ? false
    [0,0,1,1] is_alias [2,1,0,1] ? false
    [0,0,1,1] is_alias [2,1,0,2] ? false
    [0,0,1,1] is_alias [2,1,1,0] ? false
    [0,0,1,1] is_alias [2,1,1,1] ? false
    [0,0,1,1] is_alias [2,1,1,2] ? false
    [0,0,1,1] is_alias [2,1,2,0] ? false
    [0,0,1,1] is_alias [2,1,2,1] ? false
    [0,0,1,1] is_alias [2,1,2,2] ? false
    [0,0,1,1] is_alias [2,2,0,0] ? false
    [0,0,1,1] is_alias [2,2,0,1] ? false
    [0,0,1,1] is_alias [2,2,0,2] ? false
    [0,0,1,1] is_alias [2,2,1,0] ? false
    [0,0,1,1] is_alias [2,2,1,1] ? false
    [0,0,1,1] is_alias [2,2,1,2] ? false
    [0,0,1,1] is_alias [2,2,2,0] ? false
    [0,0,1,1] is_alias [2,2,2,1] ? false
    [0,0,1,1] is_alias [2,2,2,2] ? false
    [0,0,1,2] index has alias ? : true
    [0,0,1,2] is_alias [0,0,0,0] ? false
    [0,0,1,2] is_alias [0,0,0,1] ? false
    [0,0,1,2] is_alias [0,0,0,2] ? false
    [0,0,1,2] is_alias [0,0,1,0] ? false
    [0,0,1,2] is_alias [0,0,1,1] ? false
    [0,0,1,2] is_alias [0,0,1,2] ? false
    [0,0,1,2] is_alias [0,0,2,0] ? false
    [0,0,1,2] is_alias [0,0,2,1] ? true
    [0,0,1,2] is_alias [0,0,2,2] ? false
    [0,0,1,2] is_alias [0,1,0,0] ? false
    [0,0,1,2] is_alias [0,1,0,1] ? false
    [0,0,1,2] is_alias [0,1,0,2] ? false
    [0,0,1,2] is_alias [0,1,1,0] ? false
    [0,0,1,2] is_alias [0,1,1,1] ? false
    [0,0,1,2] is_alias [0,1,1,2] ? false
    [0,0,1,2] is_alias [0,1,2,0] ? false
    [0,0,1,2] is_alias [0,1,2,1] ? false
    [0,0,1,2] is_alias [0,1,2,2] ? false
    [0,0,1,2] is_alias [0,2,0,0] ? false
    [0,0,1,2] is_alias [0,2,0,1] ? false
    [0,0,1,2] is_alias [0,2,0,2] ? false
    [0,0,1,2] is_alias [0,2,1,0] ? false
    [0,0,1,2] is_alias [0,2,1,1] ? false
    [0,0,1,2] is_alias [0,2,1,2] ? false
    [0,0,1,2] is_alias [0,2,2,0] ? false
    [0,0,1,2] is_alias [0,2,2,1] ? false
    [0,0,1,2] is_alias [0,2,2,2] ? false
    [0,0,1,2] is_alias [1,0,0,0] ? false
    [0,0,1,2] is_alias [1,0,0,1] ? false
    [0,0,1,2] is_alias [1,0,0,2] ? false
    [0,0,1,2] is_alias [1,0,1,0] ? false
    [0,0,1,2] is_alias [1,0,1,1] ? false
    [0,0,1,2] is_alias [1,0,1,2] ? false
    [0,0,1,2] is_alias [1,0,2,0] ? false
    [0,0,1,2] is_alias [1,0,2,1] ? false
    [0,0,1,2] is_alias [1,0,2,2] ? false
    [0,0,1,2] is_alias [1,1,0,0] ? false
    [0,0,1,2] is_alias [1,1,0,1] ? false
    [0,0,1,2] is_alias [1,1,0,2] ? false
    [0,0,1,2] is_alias [1,1,1,0] ? false
    [0,0,1,2] is_alias [1,1,1,1] ? false
    [0,0,1,2] is_alias [1,1,1,2] ? false
    [0,0,1,2] is_alias [1,1,2,0] ? false
    [0,0,1,2] is_alias [1,1,2,1] ? false
    [0,0,1,2] is_alias [1,1,2,2] ? false
    [0,0,1,2] is_alias [1,2,0,0] ? true
    [0,0,1,2] is_alias [1,2,0,1] ? false
    [0,0,1,2] is_alias [1,2,0,2] ? false
    [0,0,1,2] is_alias [1,2,1,0] ? false
    [0,0,1,2] is_alias [1,2,1,1] ? false
    [0,0,1,2] is_alias [1,2,1,2] ? false
    [0,0,1,2] is_alias [1,2,2,0] ? false
    [0,0,1,2] is_alias [1,2,2,1] ? false
    [0,0,1,2] is_alias [1,2,2,2] ? false
    [0,0,1,2] is_alias [2,0,0,0] ? false
    [0,0,1,2] is_alias [2,0,0,1] ? false
    [0,0,1,2] is_alias [2,0,0,2] ? false
    [0,0,1,2] is_alias [2,0,1,0] ? false
    [0,0,1,2] is_alias [2,0,1,1] ? false
    [0,0,1,2] is_alias [2,0,1,2] ? false
    [0,0,1,2] is_alias [2,0,2,0] ? false
    [0,0,1,2] is_alias [2,0,2,1] ? false
    [0,0,1,2] is_alias [2,0,2,2] ? false
    [0,0,1,2] is_alias [2,1,0,0] ? true
    [0,0,1,2] is_alias [2,1,0,1] ? false
    [0,0,1,2] is_alias [2,1,0,2] ? false
    [0,0,1,2] is_alias [2,1,1,0] ? false
    [0,0,1,2] is_alias [2,1,1,1] ? false
    [0,0,1,2] is_alias [2,1,1,2] ? false
    [0,0,1,2] is_alias [2,1,2,0] ? false
    [0,0,1,2] is_alias [2,1,2,1] ? false
    [0,0,1,2] is_alias [2,1,2,2] ? false
    [0,0,1,2] is_alias [2,2,0,0] ? false
    [0,0,1,2] is_alias [2,2,0,1] ? false
    [0,0,1,2] is_alias [2,2,0,2] ? false
    [0,0,1,2] is_alias [2,2,1,0] ? false
    [0,0,1,2] is_alias [2,2,1,1] ? false
    [0,0,1,2] is_alias [2,2,1,2] ? false
    [0,0,1,2] is_alias [2,2,2,0] ? false
    [0,0,1,2] is_alias [2,2,2,1] ? false
    [0,0,1,2] is_alias [2,2,2,2] ? false
    [0,0,2,0] index has alias ? : true
    [0,0,2,0] is_alias [0,0,0,0] ? false
    [0,0,2,0] is_alias [0,0,0,1] ? false
    [0,0,2,0] is_alias [0,0,0,2] ? true
    [0,0,2,0] is_alias [0,0,1,0] ? false
    [0,0,2,0] is_alias [0,0,1,1] ? false
    [0,0,2,0] is_alias [0,0,1,2] ? false
    [0,0,2,0] is_alias [0,0,2,0] ? false
    [0,0,2,0] is_alias [0,0,2,1] ? false
    [0,0,2,0] is_alias [0,0,2,2] ? false
    [0,0,2,0] is_alias [0,1,0,0] ? false
    [0,0,2,0] is_alias [0,1,0,1] ? false
    [0,0,2,0] is_alias [0,1,0,2] ? false
    [0,0,2,0] is_alias [0,1,1,0] ? false
    [0,0,2,0] is_alias [0,1,1,1] ? false
    [0,0,2,0] is_alias [0,1,1,2] ? false
    [0,0,2,0] is_alias [0,1,2,0] ? false
    [0,0,2,0] is_alias [0,1,2,1] ? false
    [0,0,2,0] is_alias [0,1,2,2] ? false
    [0,0,2,0] is_alias [0,2,0,0] ? true
    [0,0,2,0] is_alias [0,2,0,1] ? false
    [0,0,2,0] is_alias [0,2,0,2] ? false
    [0,0,2,0] is_alias [0,2,1,0] ? false
    [0,0,2,0] is_alias [0,2,1,1] ? false
    [0,0,2,0] is_alias [0,2,1,2] ? false
    [0,0,2,0] is_alias [0,2,2,0] ? false
    [0,0,2,0] is_alias [0,2,2,1] ? false
    [0,0,2,0] is_alias [0,2,2,2] ? false
    [0,0,2,0] is_alias [1,0,0,0] ? false
    [0,0,2,0] is_alias [1,0,0,1] ? false
    [0,0,2,0] is_alias [1,0,0,2] ? false
    [0,0,2,0] is_alias [1,0,1,0] ? false
    [0,0,2,0] is_alias [1,0,1,1] ? false
    [0,0,2,0] is_alias [1,0,1,2] ? false
    [0,0,2,0] is_alias [1,0,2,0] ? false
    [0,0,2,0] is_alias [1,0,2,1] ? false
    [0,0,2,0] is_alias [1,0,2,2] ? false
    [0,0,2,0] is_alias [1,1,0,0] ? false
    [0,0,2,0] is_alias [1,1,0,1] ? false
    [0,0,2,0] is_alias [1,1,0,2] ? false
    [0,0,2,0] is_alias [1,1,1,0] ? false
    [0,0,2,0] is_alias [1,1,1,1] ? false
    [0,0,2,0] is_alias [1,1,1,2] ? false
    [0,0,2,0] is_alias [1,1,2,0] ? false
    [0,0,2,0] is_alias [1,1,2,1] ? false
    [0,0,2,0] is_alias [1,1,2,2] ? false
    [0,0,2,0] is_alias [1,2,0,0] ? false
    [0,0,2,0] is_alias [1,2,0,1] ? false
    [0,0,2,0] is_alias [1,2,0,2] ? false
    [0,0,2,0] is_alias [1,2,1,0] ? false
    [0,0,2,0] is_alias [1,2,1,1] ? false
    [0,0,2,0] is_alias [1,2,1,2] ? false
    [0,0,2,0] is_alias [1,2,2,0] ? false
    [0,0,2,0] is_alias [1,2,2,1] ? false
    [0,0,2,0] is_alias [1,2,2,2] ? false
    [0,0,2,0] is_alias [2,0,0,0] ? true
    [0,0,2,0] is_alias [2,0,0,1] ? false
    [0,0,2,0] is_alias [2,0,0,2] ? false
    [0,0,2,0] is_alias [2,0,1,0] ? false
    [0,0,2,0] is_alias [2,0,1,1] ? false
    [0,0,2,0] is_alias [2,0,1,2] ? false
    [0,0,2,0] is_alias [2,0,2,0] ? false
    [0,0,2,0] is_alias [2,0,2,1] ? false
    [0,0,2,0] is_alias [2,0,2,2] ? false
    [0,0,2,0] is_alias [2,1,0,0] ? false
    [0,0,2,0] is_alias [2,1,0,1] ? false
    [0,0,2,0] is_alias [2,1,0,2] ? false
    [0,0,2,0] is_alias [2,1,1,0] ? false
    [0,0,2,0] is_alias [2,1,1,1] ? false
    [0,0,2,0] is_alias [2,1,1,2] ? false
    [0,0,2,0] is_alias [2,1,2,0] ? false
    [0,0,2,0] is_alias [2,1,2,1] ? false
    [0,0,2,0] is_alias [2,1,2,2] ? false
    [0,0,2,0] is_alias [2,2,0,0] ? false
    [0,0,2,0] is_alias [2,2,0,1] ? false
    [0,0,2,0] is_alias [2,2,0,2] ? false
    [0,0,2,0] is_alias [2,2,1,0] ? false
    [0,0,2,0] is_alias [2,2,1,1] ? false
    [0,0,2,0] is_alias [2,2,1,2] ? false
    [0,0,2,0] is_alias [2,2,2,0] ? false
    [0,0,2,0] is_alias [2,2,2,1] ? false
    [0,0,2,0] is_alias [2,2,2,2] ? false
    [0,0,2,1] index has alias ? : true
    [0,0,2,1] is_alias [0,0,0,0] ? false
    [0,0,2,1] is_alias [0,0,0,1] ? false
    [0,0,2,1] is_alias [0,0,0,2] ? false
    [0,0,2,1] is_alias [0,0,1,0] ? false
    [0,0,2,1] is_alias [0,0,1,1] ? false
    [0,0,2,1] is_alias [0,0,1,2] ? true
    [0,0,2,1] is_alias [0,0,2,0] ? false
    [0,0,2,1] is_alias [0,0,2,1] ? false
    [0,0,2,1] is_alias [0,0,2,2] ? false
    [0,0,2,1] is_alias [0,1,0,0] ? false
    [0,0,2,1] is_alias [0,1,0,1] ? false
    [0,0,2,1] is_alias [0,1,0,2] ? false
    [0,0,2,1] is_alias [0,1,1,0] ? false
    [0,0,2,1] is_alias [0,1,1,1] ? false
    [0,0,2,1] is_alias [0,1,1,2] ? false
    [0,0,2,1] is_alias [0,1,2,0] ? false
    [0,0,2,1] is_alias [0,1,2,1] ? false
    [0,0,2,1] is_alias [0,1,2,2] ? false
    [0,0,2,1] is_alias [0,2,0,0] ? false
    [0,0,2,1] is_alias [0,2,0,1] ? false
    [0,0,2,1] is_alias [0,2,0,2] ? false
    [0,0,2,1] is_alias [0,2,1,0] ? false
    [0,0,2,1] is_alias [0,2,1,1] ? false
    [0,0,2,1] is_alias [0,2,1,2] ? false
    [0,0,2,1] is_alias [0,2,2,0] ? false
    [0,0,2,1] is_alias [0,2,2,1] ? false
    [0,0,2,1] is_alias [0,2,2,2] ? false
    [0,0,2,1] is_alias [1,0,0,0] ? false
    [0,0,2,1] is_alias [1,0,0,1] ? false
    [0,0,2,1] is_alias [1,0,0,2] ? false
    [0,0,2,1] is_alias [1,0,1,0] ? false
    [0,0,2,1] is_alias [1,0,1,1] ? false
    [0,0,2,1] is_alias [1,0,1,2] ? false
    [0,0,2,1] is_alias [1,0,2,0] ? false
    [0,0,2,1] is_alias [1,0,2,1] ? false
    [0,0,2,1] is_alias [1,0,2,2] ? false
    [0,0,2,1] is_alias [1,1,0,0] ? false
    [0,0,2,1] is_alias [1,1,0,1] ? false
    [0,0,2,1] is_alias [1,1,0,2] ? false
    [0,0,2,1] is_alias [1,1,1,0] ? false
    [0,0,2,1] is_alias [1,1,1,1] ? false
    [0,0,2,1] is_alias [1,1,1,2] ? false
    [0,0,2,1] is_alias [1,1,2,0] ? false
    [0,0,2,1] is_alias [1,1,2,1] ? false
    [0,0,2,1] is_alias [1,1,2,2] ? false
    [0,0,2,1] is_alias [1,2,0,0] ? true
    [0,0,2,1] is_alias [1,2,0,1] ? false
    [0,0,2,1] is_alias [1,2,0,2] ? false
    [0,0,2,1] is_alias [1,2,1,0] ? false
    [0,0,2,1] is_alias [1,2,1,1] ? false
    [0,0,2,1] is_alias [1,2,1,2] ? false
    [0,0,2,1] is_alias [1,2,2,0] ? false
    [0,0,2,1] is_alias [1,2,2,1] ? false
    [0,0,2,1] is_alias [1,2,2,2] ? false
    [0,0,2,1] is_alias [2,0,0,0] ? false
    [0,0,2,1] is_alias [2,0,0,1] ? false
    [0,0,2,1] is_alias [2,0,0,2] ? false
    [0,0,2,1] is_alias [2,0,1,0] ? false
    [0,0,2,1] is_alias [2,0,1,1] ? false
    [0,0,2,1] is_alias [2,0,1,2] ? false
    [0,0,2,1] is_alias [2,0,2,0] ? false
    [0,0,2,1] is_alias [2,0,2,1] ? false
    [0,0,2,1] is_alias [2,0,2,2] ? false
    [0,0,2,1] is_alias [2,1,0,0] ? true
    [0,0,2,1] is_alias [2,1,0,1] ? false
    [0,0,2,1] is_alias [2,1,0,2] ? false
    [0,0,2,1] is_alias [2,1,1,0] ? false
    [0,0,2,1] is_alias [2,1,1,1] ? false
    [0,0,2,1] is_alias [2,1,1,2] ? false
    [0,0,2,1] is_alias [2,1,2,0] ? false
    [0,0,2,1] is_alias [2,1,2,1] ? false
    [0,0,2,1] is_alias [2,1,2,2] ? false
    [0,0,2,1] is_alias [2,2,0,0] ? false
    [0,0,2,1] is_alias [2,2,0,1] ? false
    [0,0,2,1] is_alias [2,2,0,2] ? false
    [0,0,2,1] is_alias [2,2,1,0] ? false
    [0,0,2,1] is_alias [2,2,1,1] ? false
    [0,0,2,1] is_alias [2,2,1,2] ? false
    [0,0,2,1] is_alias [2,2,2,0] ? false
    [0,0,2,1] is_alias [2,2,2,1] ? false
    [0,0,2,1] is_alias [2,2,2,2] ? false
    [0,0,2,2] index has alias ? : true
    [0,0,2,2] is_alias [0,0,0,0] ? false
    [0,0,2,2] is_alias [0,0,0,1] ? false
    [0,0,2,2] is_alias [0,0,0,2] ? false
    [0,0,2,2] is_alias [0,0,1,0] ? false
    [0,0,2,2] is_alias [0,0,1,1] ? false
    [0,0,2,2] is_alias [0,0,1,2] ? false
    [0,0,2,2] is_alias [0,0,2,0] ? false
    [0,0,2,2] is_alias [0,0,2,1] ? false
    [0,0,2,2] is_alias [0,0,2,2] ? false
    [0,0,2,2] is_alias [0,1,0,0] ? false
    [0,0,2,2] is_alias [0,1,0,1] ? false
    [0,0,2,2] is_alias [0,1,0,2] ? false
    [0,0,2,2] is_alias [0,1,1,0] ? false
    [0,0,2,2] is_alias [0,1,1,1] ? false
    [0,0,2,2] is_alias [0,1,1,2] ? false
    [0,0,2,2] is_alias [0,1,2,0] ? false
    [0,0,2,2] is_alias [0,1,2,1] ? false
    [0,0,2,2] is_alias [0,1,2,2] ? false
    [0,0,2,2] is_alias [0,2,0,0] ? false
    [0,0,2,2] is_alias [0,2,0,1] ? false
    [0,0,2,2] is_alias [0,2,0,2] ? false
    [0,0,2,2] is_alias [0,2,1,0] ? false
    [0,0,2,2] is_alias [0,2,1,1] ? false
    [0,0,2,2] is_alias [0,2,1,2] ? false
    [0,0,2,2] is_alias [0,2,2,0] ? false
    [0,0,2,2] is_alias [0,2,2,1] ? false
    [0,0,2,2] is_alias [0,2,2,2] ? false
    [0,0,2,2] is_alias [1,0,0,0] ? false
    [0,0,2,2] is_alias [1,0,0,1] ? false
    [0,0,2,2] is_alias [1,0,0,2] ? false
    [0,0,2,2] is_alias [1,0,1,0] ? false
    [0,0,2,2] is_alias [1,0,1,1] ? false
    [0,0,2,2] is_alias [1,0,1,2] ? false
    [0,0,2,2] is_alias [1,0,2,0] ? false
    [0,0,2,2] is_alias [1,0,2,1] ? false
    [0,0,2,2] is_alias [1,0,2,2] ? false
    [0,0,2,2] is_alias [1,1,0,0] ? false
    [0,0,2,2] is_alias [1,1,0,1] ? false
    [0,0,2,2] is_alias [1,1,0,2] ? false
    [0,0,2,2] is_alias [1,1,1,0] ? false
    [0,0,2,2] is_alias [1,1,1,1] ? false
    [0,0,2,2] is_alias [1,1,1,2] ? false
    [0,0,2,2] is_alias [1,1,2,0] ? false
    [0,0,2,2] is_alias [1,1,2,1] ? false
    [0,0,2,2] is_alias [1,1,2,2] ? false
    [0,0,2,2] is_alias [1,2,0,0] ? false
    [0,0,2,2] is_alias [1,2,0,1] ? false
    [0,0,2,2] is_alias [1,2,0,2] ? false
    [0,0,2,2] is_alias [1,2,1,0] ? false
    [0,0,2,2] is_alias [1,2,1,1] ? false
    [0,0,2,2] is_alias [1,2,1,2] ? false
    [0,0,2,2] is_alias [1,2,2,0] ? false
    [0,0,2,2] is_alias [1,2,2,1] ? false
    [0,0,2,2] is_alias [1,2,2,2] ? false
    [0,0,2,2] is_alias [2,0,0,0] ? false
    [0,0,2,2] is_alias [2,0,0,1] ? false
    [0,0,2,2] is_alias [2,0,0,2] ? false
    [0,0,2,2] is_alias [2,0,1,0] ? false
    [0,0,2,2] is_alias [2,0,1,1] ? false
    [0,0,2,2] is_alias [2,0,1,2] ? false
    [0,0,2,2] is_alias [2,0,2,0] ? false
    [0,0,2,2] is_alias [2,0,2,1] ? false
    [0,0,2,2] is_alias [2,0,2,2] ? false
    [0,0,2,2] is_alias [2,1,0,0] ? false
    [0,0,2,2] is_alias [2,1,0,1] ? false
    [0,0,2,2] is_alias [2,1,0,2] ? false
    [0,0,2,2] is_alias [2,1,1,0] ? false
    [0,0,2,2] is_alias [2,1,1,1] ? false
    [0,0,2,2] is_alias [2,1,1,2] ? false
    [0,0,2,2] is_alias [2,1,2,0] ? false
    [0,0,2,2] is_alias [2,1,2,1] ? false
    [0,0,2,2] is_alias [2,1,2,2] ? false
    [0,0,2,2] is_alias [2,2,0,0] ? true
    [0,0,2,2] is_alias [2,2,0,1] ? false
    [0,0,2,2] is_alias [2,2,0,2] ? false
    [0,0,2,2] is_alias [2,2,1,0] ? false
    [0,0,2,2] is_alias [2,2,1,1] ? false
    [0,0,2,2] is_alias [2,2,1,2] ? false
    [0,0,2,2] is_alias [2,2,2,0] ? false
    [0,0,2,2] is_alias [2,2,2,1] ? false
    [0,0,2,2] is_alias [2,2,2,2] ? false
    [0,1,0,0] index has alias ? : true
    [0,1,0,0] is_alias [0,0,0,0] ? false
    [0,1,0,0] is_alias [0,0,0,1] ? true
    [0,1,0,0] is_alias [0,0,0,2] ? false
    [0,1,0,0] is_alias [0,0,1,0] ? true
    [0,1,0,0] is_alias [0,0,1,1] ? false
    [0,1,0,0] is_alias [0,0,1,2] ? false
    [0,1,0,0] is_alias [0,0,2,0] ? false
    [0,1,0,0] is_alias [0,0,2,1] ? false
    [0,1,0,0] is_alias [0,0,2,2] ? false
    [0,1,0,0] is_alias [0,1,0,0] ? false
    [0,1,0,0] is_alias [0,1,0,1] ? false
    [0,1,0,0] is_alias [0,1,0,2] ? false
    [0,1,0,0] is_alias [0,1,1,0] ? false
    [0,1,0,0] is_alias [0,1,1,1] ? false
    [0,1,0,0] is_alias [0,1,1,2] ? false
    [0,1,0,0] is_alias [0,1,2,0] ? false
    [0,1,0,0] is_alias [0,1,2,1] ? false
    [0,1,0,0] is_alias [0,1,2,2] ? false
    [0,1,0,0] is_alias [0,2,0,0] ? false
    [0,1,0,0] is_alias [0,2,0,1] ? false
    [0,1,0,0] is_alias [0,2,0,2] ? false
    [0,1,0,0] is_alias [0,2,1,0] ? false
    [0,1,0,0] is_alias [0,2,1,1] ? false
    [0,1,0,0] is_alias [0,2,1,2] ? false
    [0,1,0,0] is_alias [0,2,2,0] ? false
    [0,1,0,0] is_alias [0,2,2,1] ? false
    [0,1,0,0] is_alias [0,2,2,2] ? false
    [0,1,0,0] is_alias [1,0,0,0] ? true
    [0,1,0,0] is_alias [1,0,0,1] ? false
    [0,1,0,0] is_alias [1,0,0,2] ? false
    [0,1,0,0] is_alias [1,0,1,0] ? false
    [0,1,0,0] is_alias [1,0,1,1] ? false
    [0,1,0,0] is_alias [1,0,1,2] ? false
    [0,1,0,0] is_alias [1,0,2,0] ? false
    [0,1,0,0] is_alias [1,0,2,1] ? false
    [0,1,0,0] is_alias [1,0,2,2] ? false
    [0,1,0,0] is_alias [1,1,0,0] ? false
    [0,1,0,0] is_alias [1,1,0,1] ? false
    [0,1,0,0] is_alias [1,1,0,2] ? false
    [0,1,0,0] is_alias [1,1,1,0] ? false
    [0,1,0,0] is_alias [1,1,1,1] ? false
    [0,1,0,0] is_alias [1,1,1,2] ? false
    [0,1,0,0] is_alias [1,1,2,0] ? false
    [0,1,0,0] is_alias [1,1,2,1] ? false
    [0,1,0,0] is_alias [1,1,2,2] ? false
    [0,1,0,0] is_alias [1,2,0,0] ? false
    [0,1,0,0] is_alias [1,2,0,1] ? false
    [0,1,0,0] is_alias [1,2,0,2] ? false
    [0,1,0,0] is_alias [1,2,1,0] ? false
    [0,1,0,0] is_alias [1,2,1,1] ? false
    [0,1,0,0] is_alias [1,2,1,2] ? false
    [0,1,0,0] is_alias [1,2,2,0] ? false
    [0,1,0,0] is_alias [1,2,2,1] ? false
    [0,1,0,0] is_alias [1,2,2,2] ? false
    [0,1,0,0] is_alias [2,0,0,0] ? false
    [0,1,0,0] is_alias [2,0,0,1] ? false
    [0,1,0,0] is_alias [2,0,0,2] ? false
    [0,1,0,0] is_alias [2,0,1,0] ? false
    [0,1,0,0] is_alias [2,0,1,1] ? false
    [0,1,0,0] is_alias [2,0,1,2] ? false
    [0,1,0,0] is_alias [2,0,2,0] ? false
    [0,1,0,0] is_alias [2,0,2,1] ? false
    [0,1,0,0] is_alias [2,0,2,2] ? false
    [0,1,0,0] is_alias [2,1,0,0] ? false
    [0,1,0,0] is_alias [2,1,0,1] ? false
    [0,1,0,0] is_alias [2,1,0,2] ? false
    [0,1,0,0] is_alias [2,1,1,0] ? false
    [0,1,0,0] is_alias [2,1,1,1] ? false
    [0,1,0,0] is_alias [2,1,1,2] ? false
    [0,1,0,0] is_alias [2,1,2,0] ? false
    [0,1,0,0] is_alias [2,1,2,1] ? false
    [0,1,0,0] is_alias [2,1,2,2] ? false
    [0,1,0,0] is_alias [2,2,0,0] ? false
    [0,1,0,0] is_alias [2,2,0,1] ? false
    [0,1,0,0] is_alias [2,2,0,2] ? false
    [0,1,0,0] is_alias [2,2,1,0] ? false
    [0,1,0,0] is_alias [2,2,1,1] ? false
    [0,1,0,0] is_alias [2,2,1,2] ? false
    [0,1,0,0] is_alias [2,2,2,0] ? false
    [0,1,0,0] is_alias [2,2,2,1] ? false
    [0,1,0,0] is_alias [2,2,2,2] ? false
    [0,1,0,1] index has alias ? : true
    [0,1,0,1] is_alias [0,0,0,0] ? false
    [0,1,0,1] is_alias [0,0,0,1] ? false
    [0,1,0,1] is_alias [0,0,0,2] ? false
    [0,1,0,1] is_alias [0,0,1,0] ? false
    [0,1,0,1] is_alias [0,0,1,1] ? false
    [0,1,0,1] is_alias [0,0,1,2] ? false
    [0,1,0,1] is_alias [0,0,2,0] ? false
    [0,1,0,1] is_alias [0,0,2,1] ? false
    [0,1,0,1] is_alias [0,0,2,2] ? false
    [0,1,0,1] is_alias [0,1,0,0] ? false
    [0,1,0,1] is_alias [0,1,0,1] ? false
    [0,1,0,1] is_alias [0,1,0,2] ? false
    [0,1,0,1] is_alias [0,1,1,0] ? true
    [0,1,0,1] is_alias [0,1,1,1] ? false
    [0,1,0,1] is_alias [0,1,1,2] ? false
    [0,1,0,1] is_alias [0,1,2,0] ? false
    [0,1,0,1] is_alias [0,1,2,1] ? false
    [0,1,0,1] is_alias [0,1,2,2] ? false
    [0,1,0,1] is_alias [0,2,0,0] ? false
    [0,1,0,1] is_alias [0,2,0,1] ? false
    [0,1,0,1] is_alias [0,2,0,2] ? false
    [0,1,0,1] is_alias [0,2,1,0] ? false
    [0,1,0,1] is_alias [0,2,1,1] ? false
    [0,1,0,1] is_alias [0,2,1,2] ? false
    [0,1,0,1] is_alias [0,2,2,0] ? false
    [0,1,0,1] is_alias [0,2,2,1] ? false
    [0,1,0,1] is_alias [0,2,2,2] ? false
    [0,1,0,1] is_alias [1,0,0,0] ? false
    [0,1,0,1] is_alias [1,0,0,1] ? true
    [0,1,0,1] is_alias [1,0,0,2] ? false
    [0,1,0,1] is_alias [1,0,1,0] ? true
    [0,1,0,1] is_alias [1,0,1,1] ? false
    [0,1,0,1] is_alias [1,0,1,2] ? false
    [0,1,0,1] is_alias [1,0,2,0] ? false
    [0,1,0,1] is_alias [1,0,2,1] ? false
    [0,1,0,1] is_alias [1,0,2,2] ? false
    [0,1,0,1] is_alias [1,1,0,0] ? false
    [0,1,0,1] is_alias [1,1,0,1] ? false
    [0,1,0,1] is_alias [1,1,0,2] ? false
    [0,1,0,1] is_alias [1,1,1,0] ? false
    [0,1,0,1] is_alias [1,1,1,1] ? false
    [0,1,0,1] is_alias [1,1,1,2] ? false
    [0,1,0,1] is_alias [1,1,2,0] ? false
    [0,1,0,1] is_alias [1,1,2,1] ? false
    [0,1,0,1] is_alias [1,1,2,2] ? false
    [0,1,0,1] is_alias [1,2,0,0] ? false
    [0,1,0,1] is_alias [1,2,0,1] ? false
    [0,1,0,1] is_alias [1,2,0,2] ? false
    [0,1,0,1] is_alias [1,2,1,0] ? false
    [0,1,0,1] is_alias [1,2,1,1] ? false
    [0,1,0,1] is_alias [1,2,1,2] ? false
    [0,1,0,1] is_alias [1,2,2,0] ? false
    [0,1,0,1] is_alias [1,2,2,1] ? false
    [0,1,0,1] is_alias [1,2,2,2] ? false
    [0,1,0,1] is_alias [2,0,0,0] ? false
    [0,1,0,1] is_alias [2,0,0,1] ? false
    [0,1,0,1] is_alias [2,0,0,2] ? false
    [0,1,0,1] is_alias [2,0,1,0] ? false
    [0,1,0,1] is_alias [2,0,1,1] ? false
    [0,1,0,1] is_alias [2,0,1,2] ? false
    [0,1,0,1] is_alias [2,0,2,0] ? false
    [0,1,0,1] is_alias [2,0,2,1] ? false
    [0,1,0,1] is_alias [2,0,2,2] ? false
    [0,1,0,1] is_alias [2,1,0,0] ? false
    [0,1,0,1] is_alias [2,1,0,1] ? false
    [0,1,0,1] is_alias [2,1,0,2] ? false
    [0,1,0,1] is_alias [2,1,1,0] ? false
    [0,1,0,1] is_alias [2,1,1,1] ? false
    [0,1,0,1] is_alias [2,1,1,2] ? false
    [0,1,0,1] is_alias [2,1,2,0] ? false
    [0,1,0,1] is_alias [2,1,2,1] ? false
    [0,1,0,1] is_alias [2,1,2,2] ? false
    [0,1,0,1] is_alias [2,2,0,0] ? false
    [0,1,0,1] is_alias [2,2,0,1] ? false
    [0,1,0,1] is_alias [2,2,0,2] ? false
    [0,1,0,1] is_alias [2,2,1,0] ? false
    [0,1,0,1] is_alias [2,2,1,1] ? false
    [0,1,0,1] is_alias [2,2,1,2] ? false
    [0,1,0,1] is_alias [2,2,2,0] ? false
    [0,1,0,1] is_alias [2,2,2,1] ? false
    [0,1,0,1] is_alias [2,2,2,2] ? false
    [0,1,0,2] index has alias ? : true
    [0,1,0,2] is_alias [0,0,0,0] ? false
    [0,1,0,2] is_alias [0,0,0,1] ? false
    [0,1,0,2] is_alias [0,0,0,2] ? false
    [0,1,0,2] is_alias [0,0,1,0] ? false
    [0,1,0,2] is_alias [0,0,1,1] ? false
    [0,1,0,2] is_alias [0,0,1,2] ? false
    [0,1,0,2] is_alias [0,0,2,0] ? false
    [0,1,0,2] is_alias [0,0,2,1] ? false
    [0,1,0,2] is_alias [0,0,2,2] ? false
    [0,1,0,2] is_alias [0,1,0,0] ? false
    [0,1,0,2] is_alias [0,1,0,1] ? false
    [0,1,0,2] is_alias [0,1,0,2] ? false
    [0,1,0,2] is_alias [0,1,1,0] ? false
    [0,1,0,2] is_alias [0,1,1,1] ? false
    [0,1,0,2] is_alias [0,1,1,2] ? false
    [0,1,0,2] is_alias [0,1,2,0] ? true
    [0,1,0,2] is_alias [0,1,2,1] ? false
    [0,1,0,2] is_alias [0,1,2,2] ? false
    [0,1,0,2] is_alias [0,2,0,0] ? false
    [0,1,0,2] is_alias [0,2,0,1] ? true
    [0,1,0,2] is_alias [0,2,0,2] ? false
    [0,1,0,2] is_alias [0,2,1,0] ? true
    [0,1,0,2] is_alias [0,2,1,1] ? false
    [0,1,0,2] is_alias [0,2,1,2] ? false
    [0,1,0,2] is_alias [0,2,2,0] ? false
    [0,1,0,2] is_alias [0,2,2,1] ? false
    [0,1,0,2] is_alias [0,2,2,2] ? false
    [0,1,0,2] is_alias [1,0,0,0] ? false
    [0,1,0,2] is_alias [1,0,0,1] ? false
    [0,1,0,2] is_alias [1,0,0,2] ? true
    [0,1,0,2] is_alias [1,0,1,0] ? false
    [0,1,0,2] is_alias [1,0,1,1] ? false
    [0,1,0,2] is_alias [1,0,1,2] ? false
    [0,1,0,2] is_alias [1,0,2,0] ? true
    [0,1,0,2] is_alias [1,0,2,1] ? false
    [0,1,0,2] is_alias [1,0,2,2] ? false
    [0,1,0,2] is_alias [1,1,0,0] ? false
    [0,1,0,2] is_alias [1,1,0,1] ? false
    [0,1,0,2] is_alias [1,1,0,2] ? false
    [0,1,0,2] is_alias [1,1,1,0] ? false
    [0,1,0,2] is_alias [1,1,1,1] ? false
    [0,1,0,2] is_alias [1,1,1,2] ? false
    [0,1,0,2] is_alias [1,1,2,0] ? false
    [0,1,0,2] is_alias [1,1,2,1] ? false
    [0,1,0,2] is_alias [1,1,2,2] ? false
    [0,1,0,2] is_alias [1,2,0,0] ? false
    [0,1,0,2] is_alias [1,2,0,1] ? false
    [0,1,0,2] is_alias [1,2,0,2] ? false
    [0,1,0,2] is_alias [1,2,1,0] ? false
    [0,1,0,2] is_alias [1,2,1,1] ? false
    [0,1,0,2] is_alias [1,2,1,2] ? false
    [0,1,0,2] is_alias [1,2,2,0] ? false
    [0,1,0,2] is_alias [1,2,2,1] ? false
    [0,1,0,2] is_alias [1,2,2,2] ? false
    [0,1,0,2] is_alias [2,0,0,0] ? false
    [0,1,0,2] is_alias [2,0,0,1] ? true
    [0,1,0,2] is_alias [2,0,0,2] ? false
    [0,1,0,2] is_alias [2,0,1,0] ? true
    [0,1,0,2] is_alias [2,0,1,1] ? false
    [0,1,0,2] is_alias [2,0,1,2] ? false
    [0,1,0,2] is_alias [2,0,2,0] ? false
    [0,1,0,2] is_alias [2,0,2,1] ? false
    [0,1,0,2] is_alias [2,0,2,2] ? false
    [0,1,0,2] is_alias [2,1,0,0] ? false
    [0,1,0,2] is_alias [2,1,0,1] ? false
    [0,1,0,2] is_alias [2,1,0,2] ? false
    [0,1,0,2] is_alias [2,1,1,0] ? false
    [0,1,0,2] is_alias [2,1,1,1] ? false
    [0,1,0,2] is_alias [2,1,1,2] ? false
    [0,1,0,2] is_alias [2,1,2,0] ? false
    [0,1,0,2] is_alias [2,1,2,1] ? false
    [0,1,0,2] is_alias [2,1,2,2] ? false
    [0,1,0,2] is_alias [2,2,0,0] ? false
    [0,1,0,2] is_alias [2,2,0,1] ? false
    [0,1,0,2] is_alias [2,2,0,2] ? false
    [0,1,0,2] is_alias [2,2,1,0] ? false
    [0,1,0,2] is_alias [2,2,1,1] ? false
    [0,1,0,2] is_alias [2,2,1,2] ? false
    [0,1,0,2] is_alias [2,2,2,0] ? false
    [0,1,0,2] is_alias [2,2,2,1] ? false
    [0,1,0,2] is_alias [2,2,2,2] ? false
    [0,1,1,0] index has alias ? : true
    [0,1,1,0] is_alias [0,0,0,0] ? false
    [0,1,1,0] is_alias [0,0,0,1] ? false
    [0,1,1,0] is_alias [0,0,0,2] ? false
    [0,1,1,0] is_alias [0,0,1,0] ? false
    [0,1,1,0] is_alias [0,0,1,1] ? false
    [0,1,1,0] is_alias [0,0,1,2] ? false
    [0,1,1,0] is_alias [0,0,2,0] ? false
    [0,1,1,0] is_alias [0,0,2,1] ? false
    [0,1,1,0] is_alias [0,0,2,2] ? false
    [0,1,1,0] is_alias [0,1,0,0] ? false
    [0,1,1,0] is_alias [0,1,0,1] ? true
    [0,1,1,0] is_alias [0,1,0,2] ? false
    [0,1,1,0] is_alias [0,1,1,0] ? false
    [0,1,1,0] is_alias [0,1,1,1] ? false
    [0,1,1,0] is_alias [0,1,1,2] ? false
    [0,1,1,0] is_alias [0,1,2,0] ? false
    [0,1,1,0] is_alias [0,1,2,1] ? false
    [0,1,1,0] is_alias [0,1,2,2] ? false
    [0,1,1,0] is_alias [0,2,0,0] ? false
    [0,1,1,0] is_alias [0,2,0,1] ? false
    [0,1,1,0] is_alias [0,2,0,2] ? false
    [0,1,1,0] is_alias [0,2,1,0] ? false
    [0,1,1,0] is_alias [0,2,1,1] ? false
    [0,1,1,0] is_alias [0,2,1,2] ? false
    [0,1,1,0] is_alias [0,2,2,0] ? false
    [0,1,1,0] is_alias [0,2,2,1] ? false
    [0,1,1,0] is_alias [0,2,2,2] ? false
    [0,1,1,0] is_alias [1,0,0,0] ? false
    [0,1,1,0] is_alias [1,0,0,1] ? true
    [0,1,1,0] is_alias [1,0,0,2] ? false
    [0,1,1,0] is_alias [1,0,1,0] ? true
    [0,1,1,0] is_alias [1,0,1,1] ? false
    [0,1,1,0] is_alias [1,0,1,2] ? false
    [0,1,1,0] is_alias [1,0,2,0] ? false
    [0,1,1,0] is_alias [1,0,2,1] ? false
    [0,1,1,0] is_alias [1,0,2,2] ? false
    [0,1,1,0] is_alias [1,1,0,0] ? false
    [0,1,1,0] is_alias [1,1,0,1] ? false
    [0,1,1,0] is_alias [1,1,0,2] ? false
    [0,1,1,0] is_alias [1,1,1,0] ? false
    [0,1,1,0] is_alias [1,1,1,1] ? false
    [0,1,1,0] is_alias [1,1,1,2] ? false
    [0,1,1,0] is_alias [1,1,2,0] ? false
    [0,1,1,0] is_alias [1,1,2,1] ? false
    [0,1,1,0] is_alias [1,1,2,2] ? false
    [0,1,1,0] is_alias [1,2,0,0] ? false
    [0,1,1,0] is_alias [1,2,0,1] ? false
    [0,1,1,0] is_alias [1,2,0,2] ? false
    [0,1,1,0] is_alias [1,2,1,0] ? false
    [0,1,1,0] is_alias [1,2,1,1] ? false
    [0,1,1,0] is_alias [1,2,1,2] ? false
    [0,1,1,0] is_alias [1,2,2,0] ? false
    [0,1,1,0] is_alias [1,2,2,1] ? false
    [0,1,1,0] is_alias [1,2,2,2] ? false
    [0,1,1,0] is_alias [2,0,0,0] ? false
    [0,1,1,0] is_alias [2,0,0,1] ? false
    [0,1,1,0] is_alias [2,0,0,2] ? false
    [0,1,1,0] is_alias [2,0,1,0] ? false
    [0,1,1,0] is_alias [2,0,1,1] ? false
    [0,1,1,0] is_alias [2,0,1,2] ? false
    [0,1,1,0] is_alias [2,0,2,0] ? false
    [0,1,1,0] is_alias [2,0,2,1] ? false
    [0,1,1,0] is_alias [2,0,2,2] ? false
    [0,1,1,0] is_alias [2,1,0,0] ? false
    [0,1,1,0] is_alias [2,1,0,1] ? false
    [0,1,1,0] is_alias [2,1,0,2] ? false
    [0,1,1,0] is_alias [2,1,1,0] ? false
    [0,1,1,0] is_alias [2,1,1,1] ? false
    [0,1,1,0] is_alias [2,1,1,2] ? false
    [0,1,1,0] is_alias [2,1,2,0] ? false
    [0,1,1,0] is_alias [2,1,2,1] ? false
    [0,1,1,0] is_alias [2,1,2,2] ? false
    [0,1,1,0] is_alias [2,2,0,0] ? false
    [0,1,1,0] is_alias [2,2,0,1] ? false
    [0,1,1,0] is_alias [2,2,0,2] ? false
    [0,1,1,0] is_alias [2,2,1,0] ? false
    [0,1,1,0] is_alias [2,2,1,1] ? false
    [0,1,1,0] is_alias [2,2,1,2] ? false
    [0,1,1,0] is_alias [2,2,2,0] ? false
    [0,1,1,0] is_alias [2,2,2,1] ? false
    [0,1,1,0] is_alias [2,2,2,2] ? false
    [0,1,1,1] index has alias ? : true
    [0,1,1,1] is_alias [0,0,0,0] ? false
    [0,1,1,1] is_alias [0,0,0,1] ? false
    [0,1,1,1] is_alias [0,0,0,2] ? false
    [0,1,1,1] is_alias [0,0,1,0] ? false
    [0,1,1,1] is_alias [0,0,1,1] ? false
    [0,1,1,1] is_alias [0,0,1,2] ? false
    [0,1,1,1] is_alias [0,0,2,0] ? false
    [0,1,1,1] is_alias [0,0,2,1] ? false
    [0,1,1,1] is_alias [0,0,2,2] ? false
    [0,1,1,1] is_alias [0,1,0,0] ? false
    [0,1,1,1] is_alias [0,1,0,1] ? false
    [0,1,1,1] is_alias [0,1,0,2] ? false
    [0,1,1,1] is_alias [0,1,1,0] ? false
    [0,1,1,1] is_alias [0,1,1,1] ? false
    [0,1,1,1] is_alias [0,1,1,2] ? false
    [0,1,1,1] is_alias [0,1,2,0] ? false
    [0,1,1,1] is_alias [0,1,2,1] ? false
    [0,1,1,1] is_alias [0,1,2,2] ? false
    [0,1,1,1] is_alias [0,2,0,0] ? false
    [0,1,1,1] is_alias [0,2,0,1] ? false
    [0,1,1,1] is_alias [0,2,0,2] ? false
    [0,1,1,1] is_alias [0,2,1,0] ? false
    [0,1,1,1] is_alias [0,2,1,1] ? false
    [0,1,1,1] is_alias [0,2,1,2] ? false
    [0,1,1,1] is_alias [0,2,2,0] ? false
    [0,1,1,1] is_alias [0,2,2,1] ? false
    [0,1,1,1] is_alias [0,2,2,2] ? false
    [0,1,1,1] is_alias [1,0,0,0] ? false
    [0,1,1,1] is_alias [1,0,0,1] ? false
    [0,1,1,1] is_alias [1,0,0,2] ? false
    [0,1,1,1] is_alias [1,0,1,0] ? false
    [0,1,1,1] is_alias [1,0,1,1] ? true
    [0,1,1,1] is_alias [1,0,1,2] ? false
    [0,1,1,1] is_alias [1,0,2,0] ? false
    [0,1,1,1] is_alias [1,0,2,1] ? false
    [0,1,1,1] is_alias [1,0,2,2] ? false
    [0,1,1,1] is_alias [1,1,0,0] ? false
    [0,1,1,1] is_alias [1,1,0,1] ? true
    [0,1,1,1] is_alias [1,1,0,2] ? false
    [0,1,1,1] is_alias [1,1,1,0] ? true
    [0,1,1,1] is_alias [1,1,1,1] ? false
    [0,1,1,1] is_alias [1,1,1,2] ? false
    [0,1,1,1] is_alias [1,1,2,0] ? false
    [0,1,1,1] is_alias [1,1,2,1] ? false
    [0,1,1,1] is_alias [1,1,2,2] ? false
    [0,1,1,1] is_alias [1,2,0,0] ? false
    [0,1,1,1] is_alias [1,2,0,1] ? false
    [0,1,1,1] is_alias [1,2,0,2] ? false
    [0,1,1,1] is_alias [1,2,1,0] ? false
    [0,1,1,1] is_alias [1,2,1,1] ? false
    [0,1,1,1] is_alias [1,2,1,2] ? false
    [0,1,1,1] is_alias [1,2,2,0] ? false
    [0,1,1,1] is_alias [1,2,2,1] ? false
    [0,1,1,1] is_alias [1,2,2,2] ? false
    [0,1,1,1] is_alias [2,0,0,0] ? false
    [0,1,1,1] is_alias [2,0,0,1] ? false
    [0,1,1,1] is_alias [2,0,0,2] ? false
    [0,1,1,1] is_alias [2,0,1,0] ? false
    [0,1,1,1] is_alias [2,0,1,1] ? false
    [0,1,1,1] is_alias [2,0,1,2] ? false
    [0,1,1,1] is_alias [2,0,2,0] ? false
    [0,1,1,1] is_alias [2,0,2,1] ? false
    [0,1,1,1] is_alias [2,0,2,2] ? false
    [0,1,1,1] is_alias [2,1,0,0] ? false
    [0,1,1,1] is_alias [2,1,0,1] ? false
    [0,1,1,1] is_alias [2,1,0,2] ? false
    [0,1,1,1] is_alias [2,1,1,0] ? false
    [0,1,1,1] is_alias [2,1,1,1] ? false
    [0,1,1,1] is_alias [2,1,1,2] ? false
    [0,1,1,1] is_alias [2,1,2,0] ? false
    [0,1,1,1] is_alias [2,1,2,1] ? false
    [0,1,1,1] is_alias [2,1,2,2] ? false
    [0,1,1,1] is_alias [2,2,0,0] ? false
    [0,1,1,1] is_alias [2,2,0,1] ? false
    [0,1,1,1] is_alias [2,2,0,2] ? false
    [0,1,1,1] is_alias [2,2,1,0] ? false
    [0,1,1,1] is_alias [2,2,1,1] ? false
    [0,1,1,1] is_alias [2,2,1,2] ? false
    [0,1,1,1] is_alias [2,2,2,0] ? false
    [0,1,1,1] is_alias [2,2,2,1] ? false
    [0,1,1,1] is_alias [2,2,2,2] ? false
    [0,1,1,2] index has alias ? : true
    [0,1,1,2] is_alias [0,0,0,0] ? false
    [0,1,1,2] is_alias [0,0,0,1] ? false
    [0,1,1,2] is_alias [0,0,0,2] ? false
    [0,1,1,2] is_alias [0,0,1,0] ? false
    [0,1,1,2] is_alias [0,0,1,1] ? false
    [0,1,1,2] is_alias [0,0,1,2] ? false
    [0,1,1,2] is_alias [0,0,2,0] ? false
    [0,1,1,2] is_alias [0,0,2,1] ? false
    [0,1,1,2] is_alias [0,0,2,2] ? false
    [0,1,1,2] is_alias [0,1,0,0] ? false
    [0,1,1,2] is_alias [0,1,0,1] ? false
    [0,1,1,2] is_alias [0,1,0,2] ? false
    [0,1,1,2] is_alias [0,1,1,0] ? false
    [0,1,1,2] is_alias [0,1,1,1] ? false
    [0,1,1,2] is_alias [0,1,1,2] ? false
    [0,1,1,2] is_alias [0,1,2,0] ? false
    [0,1,1,2] is_alias [0,1,2,1] ? true
    [0,1,1,2] is_alias [0,1,2,2] ? false
    [0,1,1,2] is_alias [0,2,0,0] ? false
    [0,1,1,2] is_alias [0,2,0,1] ? false
    [0,1,1,2] is_alias [0,2,0,2] ? false
    [0,1,1,2] is_alias [0,2,1,0] ? false
    [0,1,1,2] is_alias [0,2,1,1] ? false
    [0,1,1,2] is_alias [0,2,1,2] ? false
    [0,1,1,2] is_alias [0,2,2,0] ? false
    [0,1,1,2] is_alias [0,2,2,1] ? false
    [0,1,1,2] is_alias [0,2,2,2] ? false
    [0,1,1,2] is_alias [1,0,0,0] ? false
    [0,1,1,2] is_alias [1,0,0,1] ? false
    [0,1,1,2] is_alias [1,0,0,2] ? false
    [0,1,1,2] is_alias [1,0,1,0] ? false
    [0,1,1,2] is_alias [1,0,1,1] ? false
    [0,1,1,2] is_alias [1,0,1,2] ? true
    [0,1,1,2] is_alias [1,0,2,0] ? false
    [0,1,1,2] is_alias [1,0,2,1] ? true
    [0,1,1,2] is_alias [1,0,2,2] ? false
    [0,1,1,2] is_alias [1,1,0,0] ? false
    [0,1,1,2] is_alias [1,1,0,1] ? false
    [0,1,1,2] is_alias [1,1,0,2] ? false
    [0,1,1,2] is_alias [1,1,1,0] ? false
    [0,1,1,2] is_alias [1,1,1,1] ? false
    [0,1,1,2] is_alias [1,1,1,2] ? false
    [0,1,1,2] is_alias [1,1,2,0] ? false
    [0,1,1,2] is_alias [1,1,2,1] ? false
    [0,1,1,2] is_alias [1,1,2,2] ? false
    [0,1,1,2] is_alias [1,2,0,0] ? false
    [0,1,1,2] is_alias [1,2,0,1] ? true
    [0,1,1,2] is_alias [1,2,0,2] ? false
    [0,1,1,2] is_alias [1,2,1,0] ? true
    [0,1,1,2] is_alias [1,2,1,1] ? false
    [0,1,1,2] is_alias [1,2,1,2] ? false
    [0,1,1,2] is_alias [1,2,2,0] ? false
    [0,1,1,2] is_alias [1,2,2,1] ? false
    [0,1,1,2] is_alias [1,2,2,2] ? false
    [0,1,1,2] is_alias [2,0,0,0] ? false
    [0,1,1,2] is_alias [2,0,0,1] ? false
    [0,1,1,2] is_alias [2,0,0,2] ? false
    [0,1,1,2] is_alias [2,0,1,0] ? false
    [0,1,1,2] is_alias [2,0,1,1] ? false
    [0,1,1,2] is_alias [2,0,1,2] ? false
    [0,1,1,2] is_alias [2,0,2,0] ? false
    [0,1,1,2] is_alias [2,0,2,1] ? false
    [0,1,1,2] is_alias [2,0,2,2] ? false
    [0,1,1,2] is_alias [2,1,0,0] ? false
    [0,1,1,2] is_alias [2,1,0,1] ? true
    [0,1,1,2] is_alias [2,1,0,2] ? false
    [0,1,1,2] is_alias [2,1,1,0] ? true
    [0,1,1,2] is_alias [2,1,1,1] ? false
    [0,1,1,2] is_alias [2,1,1,2] ? false
    [0,1,1,2] is_alias [2,1,2,0] ? false
    [0,1,1,2] is_alias [2,1,2,1] ? false
    [0,1,1,2] is_alias [2,1,2,2] ? false
    [0,1,1,2] is_alias [2,2,0,0] ? false
    [0,1,1,2] is_alias [2,2,0,1] ? false
    [0,1,1,2] is_alias [2,2,0,2] ? false
    [0,1,1,2] is_alias [2,2,1,0] ? false
    [0,1,1,2] is_alias [2,2,1,1] ? false
    [0,1,1,2] is_alias [2,2,1,2] ? false
    [0,1,1,2] is_alias [2,2,2,0] ? false
    [0,1,1,2] is_alias [2,2,2,1] ? false
    [0,1,1,2] is_alias [2,2,2,2] ? false
    [0,1,2,0] index has alias ? : true
    [0,1,2,0] is_alias [0,0,0,0] ? false
    [0,1,2,0] is_alias [0,0,0,1] ? false
    [0,1,2,0] is_alias [0,0,0,2] ? false
    [0,1,2,0] is_alias [0,0,1,0] ? false
    [0,1,2,0] is_alias [0,0,1,1] ? false
    [0,1,2,0] is_alias [0,0,1,2] ? false
    [0,1,2,0] is_alias [0,0,2,0] ? false
    [0,1,2,0] is_alias [0,0,2,1] ? false
    [0,1,2,0] is_alias [0,0,2,2] ? false
    [0,1,2,0] is_alias [0,1,0,0] ? false
    [0,1,2,0] is_alias [0,1,0,1] ? false
    [0,1,2,0] is_alias [0,1,0,2] ? true
    [0,1,2,0] is_alias [0,1,1,0] ? false
    [0,1,2,0] is_alias [0,1,1,1] ? false
    [0,1,2,0] is_alias [0,1,1,2] ? false
    [0,1,2,0] is_alias [0,1,2,0] ? false
    [0,1,2,0] is_alias [0,1,2,1] ? false
    [0,1,2,0] is_alias [0,1,2,2] ? false
    [0,1,2,0] is_alias [0,2,0,0] ? false
    [0,1,2,0] is_alias [0,2,0,1] ? true
    [0,1,2,0] is_alias [0,2,0,2] ? false
    [0,1,2,0] is_alias [0,2,1,0] ? true
    [0,1,2,0] is_alias [0,2,1,1] ? false
    [0,1,2,0] is_alias [0,2,1,2] ? false
    [0,1,2,0] is_alias [0,2,2,0] ? false
    [0,1,2,0] is_alias [0,2,2,1] ? false
    [0,1,2,0] is_alias [0,2,2,2] ? false
    [0,1,2,0] is_alias [1,0,0,0] ? false
    [0,1,2,0] is_alias [1,0,0,1] ? false
    [0,1,2,0] is_alias [1,0,0,2] ? true
    [0,1,2,0] is_alias [1,0,1,0] ? false
    [0,1,2,0] is_alias [1,0,1,1] ? false
    [0,1,2,0] is_alias [1,0,1,2] ? false
    [0,1,2,0] is_alias [1,0,2,0] ? true
    [0,1,2,0] is_alias [1,0,2,1] ? false
    [0,1,2,0] is_alias [1,0,2,2] ? false
    [0,1,2,0] is_alias [1,1,0,0] ? false
    [0,1,2,0] is_alias [1,1,0,1] ? false
    [0,1,2,0] is_alias [1,1,0,2] ? false
    [0,1,2,0] is_alias [1,1,1,0] ? false
    [0,1,2,0] is_alias [1,1,1,1] ? false
    [0,1,2,0] is_alias [1,1,1,2] ? false
    [0,1,2,0] is_alias [1,1,2,0] ? false
    [0,1,2,0] is_alias [1,1,2,1] ? false
    [0,1,2,0] is_alias [1,1,2,2] ? false
    [0,1,2,0] is_alias [1,2,0,0] ? false
    [0,1,2,0] is_alias [1,2,0,1] ? false
    [0,1,2,0] is_alias [1,2,0,2] ? false
    [0,1,2,0] is_alias [1,2,1,0] ? false
    [0,1,2,0] is_alias [1,2,1,1] ? false
    [0,1,2,0] is_alias [1,2,1,2] ? false
    [0,1,2,0] is_alias [1,2,2,0] ? false
    [0,1,2,0] is_alias [1,2,2,1] ? false
    [0,1,2,0] is_alias [1,2,2,2] ? false
    [0,1,2,0] is_alias [2,0,0,0] ? false
    [0,1,2,0] is_alias [2,0,0,1] ? true
    [0,1,2,0] is_alias [2,0,0,2] ? false
    [0,1,2,0] is_alias [2,0,1,0] ? true
    [0,1,2,0] is_alias [2,0,1,1] ? false
    [0,1,2,0] is_alias [2,0,1,2] ? false
    [0,1,2,0] is_alias [2,0,2,0] ? false
    [0,1,2,0] is_alias [2,0,2,1] ? false
    [0,1,2,0] is_alias [2,0,2,2] ? false
    [0,1,2,0] is_alias [2,1,0,0] ? false
    [0,1,2,0] is_alias [2,1,0,1] ? false
    [0,1,2,0] is_alias [2,1,0,2] ? false
    [0,1,2,0] is_alias [2,1,1,0] ? false
    [0,1,2,0] is_alias [2,1,1,1] ? false
    [0,1,2,0] is_alias [2,1,1,2] ? false
    [0,1,2,0] is_alias [2,1,2,0] ? false
    [0,1,2,0] is_alias [2,1,2,1] ? false
    [0,1,2,0] is_alias [2,1,2,2] ? false
    [0,1,2,0] is_alias [2,2,0,0] ? false
    [0,1,2,0] is_alias [2,2,0,1] ? false
    [0,1,2,0] is_alias [2,2,0,2] ? false
    [0,1,2,0] is_alias [2,2,1,0] ? false
    [0,1,2,0] is_alias [2,2,1,1] ? false
    [0,1,2,0] is_alias [2,2,1,2] ? false
    [0,1,2,0] is_alias [2,2,2,0] ? false
    [0,1,2,0] is_alias [2,2,2,1] ? false
    [0,1,2,0] is_alias [2,2,2,2] ? false
    [0,1,2,1] index has alias ? : true
    [0,1,2,1] is_alias [0,0,0,0] ? false
    [0,1,2,1] is_alias [0,0,0,1] ? false
    [0,1,2,1] is_alias [0,0,0,2] ? false
    [0,1,2,1] is_alias [0,0,1,0] ? false
    [0,1,2,1] is_alias [0,0,1,1] ? false
    [0,1,2,1] is_alias [0,0,1,2] ? false
    [0,1,2,1] is_alias [0,0,2,0] ? false
    [0,1,2,1] is_alias [0,0,2,1] ? false
    [0,1,2,1] is_alias [0,0,2,2] ? false
    [0,1,2,1] is_alias [0,1,0,0] ? false
    [0,1,2,1] is_alias [0,1,0,1] ? false
    [0,1,2,1] is_alias [0,1,0,2] ? false
    [0,1,2,1] is_alias [0,1,1,0] ? false
    [0,1,2,1] is_alias [0,1,1,1] ? false
    [0,1,2,1] is_alias [0,1,1,2] ? true
    [0,1,2,1] is_alias [0,1,2,0] ? false
    [0,1,2,1] is_alias [0,1,2,1] ? false
    [0,1,2,1] is_alias [0,1,2,2] ? false
    [0,1,2,1] is_alias [0,2,0,0] ? false
    [0,1,2,1] is_alias [0,2,0,1] ? false
    [0,1,2,1] is_alias [0,2,0,2] ? false
    [0,1,2,1] is_alias [0,2,1,0] ? false
    [0,1,2,1] is_alias [0,2,1,1] ? false
    [0,1,2,1] is_alias [0,2,1,2] ? false
    [0,1,2,1] is_alias [0,2,2,0] ? false
    [0,1,2,1] is_alias [0,2,2,1] ? false
    [0,1,2,1] is_alias [0,2,2,2] ? false
    [0,1,2,1] is_alias [1,0,0,0] ? false
    [0,1,2,1] is_alias [1,0,0,1] ? false
    [0,1,2,1] is_alias [1,0,0,2] ? false
    [0,1,2,1] is_alias [1,0,1,0] ? false
    [0,1,2,1] is_alias [1,0,1,1] ? false
    [0,1,2,1] is_alias [1,0,1,2] ? true
    [0,1,2,1] is_alias [1,0,2,0] ? false
    [0,1,2,1] is_alias [1,0,2,1] ? true
    [0,1,2,1] is_alias [1,0,2,2] ? false
    [0,1,2,1] is_alias [1,1,0,0] ? false
    [0,1,2,1] is_alias [1,1,0,1] ? false
    [0,1,2,1] is_alias [1,1,0,2] ? false
    [0,1,2,1] is_alias [1,1,1,0] ? false
    [0,1,2,1] is_alias [1,1,1,1] ? false
    [0,1,2,1] is_alias [1,1,1,2] ? false
    [0,1,2,1] is_alias [1,1,2,0] ? false
    [0,1,2,1] is_alias [1,1,2,1] ? false
    [0,1,2,1] is_alias [1,1,2,2] ? false
    [0,1,2,1] is_alias [1,2,0,0] ? false
    [0,1,2,1] is_alias [1,2,0,1] ? true
    [0,1,2,1] is_alias [1,2,0,2] ? false
    [0,1,2,1] is_alias [1,2,1,0] ? true
    [0,1,2,1] is_alias [1,2,1,1] ? false
    [0,1,2,1] is_alias [1,2,1,2] ? false
    [0,1,2,1] is_alias [1,2,2,0] ? false
    [0,1,2,1] is_alias [1,2,2,1] ? false
    [0,1,2,1] is_alias [1,2,2,2] ? false
    [0,1,2,1] is_alias [2,0,0,0] ? false
    [0,1,2,1] is_alias [2,0,0,1] ? false
    [0,1,2,1] is_alias [2,0,0,2] ? false
    [0,1,2,1] is_alias [2,0,1,0] ? false
    [0,1,2,1] is_alias [2,0,1,1] ? false
    [0,1,2,1] is_alias [2,0,1,2] ? false
    [0,1,2,1] is_alias [2,0,2,0] ? false
    [0,1,2,1] is_alias [2,0,2,1] ? false
    [0,1,2,1] is_alias [2,0,2,2] ? false
    [0,1,2,1] is_alias [2,1,0,0] ? false
    [0,1,2,1] is_alias [2,1,0,1] ? true
    [0,1,2,1] is_alias [2,1,0,2] ? false
    [0,1,2,1] is_alias [2,1,1,0] ? true
    [0,1,2,1] is_alias [2,1,1,1] ? false
    [0,1,2,1] is_alias [2,1,1,2] ? false
    [0,1,2,1] is_alias [2,1,2,0] ? false
    [0,1,2,1] is_alias [2,1,2,1] ? false
    [0,1,2,1] is_alias [2,1,2,2] ? false
    [0,1,2,1] is_alias [2,2,0,0] ? false
    [0,1,2,1] is_alias [2,2,0,1] ? false
    [0,1,2,1] is_alias [2,2,0,2] ? false
    [0,1,2,1] is_alias [2,2,1,0] ? false
    [0,1,2,1] is_alias [2,2,1,1] ? false
    [0,1,2,1] is_alias [2,2,1,2] ? false
    [0,1,2,1] is_alias [2,2,2,0] ? false
    [0,1,2,1] is_alias [2,2,2,1] ? false
    [0,1,2,1] is_alias [2,2,2,2] ? false
    [0,1,2,2] index has alias ? : true
    [0,1,2,2] is_alias [0,0,0,0] ? false
    [0,1,2,2] is_alias [0,0,0,1] ? false
    [0,1,2,2] is_alias [0,0,0,2] ? false
    [0,1,2,2] is_alias [0,0,1,0] ? false
    [0,1,2,2] is_alias [0,0,1,1] ? false
    [0,1,2,2] is_alias [0,0,1,2] ? false
    [0,1,2,2] is_alias [0,0,2,0] ? false
    [0,1,2,2] is_alias [0,0,2,1] ? false
    [0,1,2,2] is_alias [0,0,2,2] ? false
    [0,1,2,2] is_alias [0,1,0,0] ? false
    [0,1,2,2] is_alias [0,1,0,1] ? false
    [0,1,2,2] is_alias [0,1,0,2] ? false
    [0,1,2,2] is_alias [0,1,1,0] ? false
    [0,1,2,2] is_alias [0,1,1,1] ? false
    [0,1,2,2] is_alias [0,1,1,2] ? false
    [0,1,2,2] is_alias [0,1,2,0] ? false
    [0,1,2,2] is_alias [0,1,2,1] ? false
    [0,1,2,2] is_alias [0,1,2,2] ? false
    [0,1,2,2] is_alias [0,2,0,0] ? false
    [0,1,2,2] is_alias [0,2,0,1] ? false
    [0,1,2,2] is_alias [0,2,0,2] ? false
    [0,1,2,2] is_alias [0,2,1,0] ? false
    [0,1,2,2] is_alias [0,2,1,1] ? false
    [0,1,2,2] is_alias [0,2,1,2] ? false
    [0,1,2,2] is_alias [0,2,2,0] ? false
    [0,1,2,2] is_alias [0,2,2,1] ? false
    [0,1,2,2] is_alias [0,2,2,2] ? false
    [0,1,2,2] is_alias [1,0,0,0] ? false
    [0,1,2,2] is_alias [1,0,0,1] ? false
    [0,1,2,2] is_alias [1,0,0,2] ? false
    [0,1,2,2] is_alias [1,0,1,0] ? false
    [0,1,2,2] is_alias [1,0,1,1] ? false
    [0,1,2,2] is_alias [1,0,1,2] ? false
    [0,1,2,2] is_alias [1,0,2,0] ? false
    [0,1,2,2] is_alias [1,0,2,1] ? false
    [0,1,2,2] is_alias [1,0,2,2] ? true
    [0,1,2,2] is_alias [1,1,0,0] ? false
    [0,1,2,2] is_alias [1,1,0,1] ? false
    [0,1,2,2] is_alias [1,1,0,2] ? false
    [0,1,2,2] is_alias [1,1,1,0] ? false
    [0,1,2,2] is_alias [1,1,1,1] ? false
    [0,1,2,2] is_alias [1,1,1,2] ? false
    [0,1,2,2] is_alias [1,1,2,0] ? false
    [0,1,2,2] is_alias [1,1,2,1] ? false
    [0,1,2,2] is_alias [1,1,2,2] ? false
    [0,1,2,2] is_alias [1,2,0,0] ? false
    [0,1,2,2] is_alias [1,2,0,1] ? false
    [0,1,2,2] is_alias [1,2,0,2] ? false
    [0,1,2,2] is_alias [1,2,1,0] ? false
    [0,1,2,2] is_alias [1,2,1,1] ? false
    [0,1,2,2] is_alias [1,2,1,2] ? false
    [0,1,2,2] is_alias [1,2,2,0] ? false
    [0,1,2,2] is_alias [1,2,2,1] ? false
    [0,1,2,2] is_alias [1,2,2,2] ? false
    [0,1,2,2] is_alias [2,0,0,0] ? false
    [0,1,2,2] is_alias [2,0,0,1] ? false
    [0,1,2,2] is_alias [2,0,0,2] ? false
    [0,1,2,2] is_alias [2,0,1,0] ? false
    [0,1,2,2] is_alias [2,0,1,1] ? false
    [0,1,2,2] is_alias [2,0,1,2] ? false
    [0,1,2,2] is_alias [2,0,2,0] ? false
    [0,1,2,2] is_alias [2,0,2,1] ? false
    [0,1,2,2] is_alias [2,0,2,2] ? false
    [0,1,2,2] is_alias [2,1,0,0] ? false
    [0,1,2,2] is_alias [2,1,0,1] ? false
    [0,1,2,2] is_alias [2,1,0,2] ? false
    [0,1,2,2] is_alias [2,1,1,0] ? false
    [0,1,2,2] is_alias [2,1,1,1] ? false
    [0,1,2,2] is_alias [2,1,1,2] ? false
    [0,1,2,2] is_alias [2,1,2,0] ? false
    [0,1,2,2] is_alias [2,1,2,1] ? false
    [0,1,2,2] is_alias [2,1,2,2] ? false
    [0,1,2,2] is_alias [2,2,0,0] ? false
    [0,1,2,2] is_alias [2,2,0,1] ? true
    [0,1,2,2] is_alias [2,2,0,2] ? false
    [0,1,2,2] is_alias [2,2,1,0] ? true
    [0,1,2,2] is_alias [2,2,1,1] ? false
    [0,1,2,2] is_alias [2,2,1,2] ? false
    [0,1,2,2] is_alias [2,2,2,0] ? false
    [0,1,2,2] is_alias [2,2,2,1] ? false
    [0,1,2,2] is_alias [2,2,2,2] ? false
    [0,2,0,0] index has alias ? : true
    [0,2,0,0] is_alias [0,0,0,0] ? false
    [0,2,0,0] is_alias [0,0,0,1] ? false
    [0,2,0,0] is_alias [0,0,0,2] ? true
    [0,2,0,0] is_alias [0,0,1,0] ? false
    [0,2,0,0] is_alias [0,0,1,1] ? false
    [0,2,0,0] is_alias [0,0,1,2] ? false
    [0,2,0,0] is_alias [0,0,2,0] ? true
    [0,2,0,0] is_alias [0,0,2,1] ? false
    [0,2,0,0] is_alias [0,0,2,2] ? false
    [0,2,0,0] is_alias [0,1,0,0] ? false
    [0,2,0,0] is_alias [0,1,0,1] ? false
    [0,2,0,0] is_alias [0,1,0,2] ? false
    [0,2,0,0] is_alias [0,1,1,0] ? false
    [0,2,0,0] is_alias [0,1,1,1] ? false
    [0,2,0,0] is_alias [0,1,1,2] ? false
    [0,2,0,0] is_alias [0,1,2,0] ? false
    [0,2,0,0] is_alias [0,1,2,1] ? false
    [0,2,0,0] is_alias [0,1,2,2] ? false
    [0,2,0,0] is_alias [0,2,0,0] ? false
    [0,2,0,0] is_alias [0,2,0,1] ? false
    [0,2,0,0] is_alias [0,2,0,2] ? false
    [0,2,0,0] is_alias [0,2,1,0] ? false
    [0,2,0,0] is_alias [0,2,1,1] ? false
    [0,2,0,0] is_alias [0,2,1,2] ? false
    [0,2,0,0] is_alias [0,2,2,0] ? false
    [0,2,0,0] is_alias [0,2,2,1] ? false
    [0,2,0,0] is_alias [0,2,2,2] ? false
    [0,2,0,0] is_alias [1,0,0,0] ? false
    [0,2,0,0] is_alias [1,0,0,1] ? false
    [0,2,0,0] is_alias [1,0,0,2] ? false
    [0,2,0,0] is_alias [1,0,1,0] ? false
    [0,2,0,0] is_alias [1,0,1,1] ? false
    [0,2,0,0] is_alias [1,0,1,2] ? false
    [0,2,0,0] is_alias [1,0,2,0] ? false
    [0,2,0,0] is_alias [1,0,2,1] ? false
    [0,2,0,0] is_alias [1,0,2,2] ? false
    [0,2,0,0] is_alias [1,1,0,0] ? false
    [0,2,0,0] is_alias [1,1,0,1] ? false
    [0,2,0,0] is_alias [1,1,0,2] ? false
    [0,2,0,0] is_alias [1,1,1,0] ? false
    [0,2,0,0] is_alias [1,1,1,1] ? false
    [0,2,0,0] is_alias [1,1,1,2] ? false
    [0,2,0,0] is_alias [1,1,2,0] ? false
    [0,2,0,0] is_alias [1,1,2,1] ? false
    [0,2,0,0] is_alias [1,1,2,2] ? false
    [0,2,0,0] is_alias [1,2,0,0] ? false
    [0,2,0,0] is_alias [1,2,0,1] ? false
    [0,2,0,0] is_alias [1,2,0,2] ? false
    [0,2,0,0] is_alias [1,2,1,0] ? false
    [0,2,0,0] is_alias [1,2,1,1] ? false
    [0,2,0,0] is_alias [1,2,1,2] ? false
    [0,2,0,0] is_alias [1,2,2,0] ? false
    [0,2,0,0] is_alias [1,2,2,1] ? false
    [0,2,0,0] is_alias [1,2,2,2] ? false
    [0,2,0,0] is_alias [2,0,0,0] ? true
    [0,2,0,0] is_alias [2,0,0,1] ? false
    [0,2,0,0] is_alias [2,0,0,2] ? false
    [0,2,0,0] is_alias [2,0,1,0] ? false
    [0,2,0,0] is_alias [2,0,1,1] ? false
    [0,2,0,0] is_alias [2,0,1,2] ? false
    [0,2,0,0] is_alias [2,0,2,0] ? false
    [0,2,0,0] is_alias [2,0,2,1] ? false
    [0,2,0,0] is_alias [2,0,2,2] ? false
    [0,2,0,0] is_alias [2,1,0,0] ? false
    [0,2,0,0] is_alias [2,1,0,1] ? false
    [0,2,0,0] is_alias [2,1,0,2] ? false
    [0,2,0,0] is_alias [2,1,1,0] ? false
    [0,2,0,0] is_alias [2,1,1,1] ? false
    [0,2,0,0] is_alias [2,1,1,2] ? false
    [0,2,0,0] is_alias [2,1,2,0] ? false
    [0,2,0,0] is_alias [2,1,2,1] ? false
    [0,2,0,0] is_alias [2,1,2,2] ? false
    [0,2,0,0] is_alias [2,2,0,0] ? false
    [0,2,0,0] is_alias [2,2,0,1] ? false
    [0,2,0,0] is_alias [2,2,0,2] ? false
    [0,2,0,0] is_alias [2,2,1,0] ? false
    [0,2,0,0] is_alias [2,2,1,1] ? false
    [0,2,0,0] is_alias [2,2,1,2] ? false
    [0,2,0,0] is_alias [2,2,2,0] ? false
    [0,2,0,0] is_alias [2,2,2,1] ? false
    [0,2,0,0] is_alias [2,2,2,2] ? false
    [0,2,0,1] index has alias ? : true
    [0,2,0,1] is_alias [0,0,0,0] ? false
    [0,2,0,1] is_alias [0,0,0,1] ? false
    [0,2,0,1] is_alias [0,0,0,2] ? false
    [0,2,0,1] is_alias [0,0,1,0] ? false
    [0,2,0,1] is_alias [0,0,1,1] ? false
    [0,2,0,1] is_alias [0,0,1,2] ? false
    [0,2,0,1] is_alias [0,0,2,0] ? false
    [0,2,0,1] is_alias [0,0,2,1] ? false
    [0,2,0,1] is_alias [0,0,2,2] ? false
    [0,2,0,1] is_alias [0,1,0,0] ? false
    [0,2,0,1] is_alias [0,1,0,1] ? false
    [0,2,0,1] is_alias [0,1,0,2] ? true
    [0,2,0,1] is_alias [0,1,1,0] ? false
    [0,2,0,1] is_alias [0,1,1,1] ? false
    [0,2,0,1] is_alias [0,1,1,2] ? false
    [0,2,0,1] is_alias [0,1,2,0] ? true
    [0,2,0,1] is_alias [0,1,2,1] ? false
    [0,2,0,1] is_alias [0,1,2,2] ? false
    [0,2,0,1] is_alias [0,2,0,0] ? false
    [0,2,0,1] is_alias [0,2,0,1] ? false
    [0,2,0,1] is_alias [0,2,0,2] ? false
    [0,2,0,1] is_alias [0,2,1,0] ? true
    [0,2,0,1] is_alias [0,2,1,1] ? false
    [0,2,0,1] is_alias [0,2,1,2] ? false
    [0,2,0,1] is_alias [0,2,2,0] ? false
    [0,2,0,1] is_alias [0,2,2,1] ? false
    [0,2,0,1] is_alias [0,2,2,2] ? false
    [0,2,0,1] is_alias [1,0,0,0] ? false
    [0,2,0,1] is_alias [1,0,0,1] ? false
    [0,2,0,1] is_alias [1,0,0,2] ? true
    [0,2,0,1] is_alias [1,0,1,0] ? false
    [0,2,0,1] is_alias [1,0,1,1] ? false
    [0,2,0,1] is_alias [1,0,1,2] ? false
    [0,2,0,1] is_alias [1,0,2,0] ? true
    [0,2,0,1] is_alias [1,0,2,1] ? false
    [0,2,0,1] is_alias [1,0,2,2] ? false
    [0,2,0,1] is_alias [1,1,0,0] ? false
    [0,2,0,1] is_alias [1,1,0,1] ? false
    [0,2,0,1] is_alias [1,1,0,2] ? false
    [0,2,0,1] is_alias [1,1,1,0] ? false
    [0,2,0,1] is_alias [1,1,1,1] ? false
    [0,2,0,1] is_alias [1,1,1,2] ? false
    [0,2,0,1] is_alias [1,1,2,0] ? false
    [0,2,0,1] is_alias [1,1,2,1] ? false
    [0,2,0,1] is_alias [1,1,2,2] ? false
    [0,2,0,1] is_alias [1,2,0,0] ? false
    [0,2,0,1] is_alias [1,2,0,1] ? false
    [0,2,0,1] is_alias [1,2,0,2] ? false
    [0,2,0,1] is_alias [1,2,1,0] ? false
    [0,2,0,1] is_alias [1,2,1,1] ? false
    [0,2,0,1] is_alias [1,2,1,2] ? false
    [0,2,0,1] is_alias [1,2,2,0] ? false
    [0,2,0,1] is_alias [1,2,2,1] ? false
    [0,2,0,1] is_alias [1,2,2,2] ? false
    [0,2,0,1] is_alias [2,0,0,0] ? false
    [0,2,0,1] is_alias [2,0,0,1] ? true
    [0,2,0,1] is_alias [2,0,0,2] ? false
    [0,2,0,1] is_alias [2,0,1,0] ? true
    [0,2,0,1] is_alias [2,0,1,1] ? false
    [0,2,0,1] is_alias [2,0,1,2] ? false
    [0,2,0,1] is_alias [2,0,2,0] ? false
    [0,2,0,1] is_alias [2,0,2,1] ? false
    [0,2,0,1] is_alias [2,0,2,2] ? false
    [0,2,0,1] is_alias [2,1,0,0] ? false
    [0,2,0,1] is_alias [2,1,0,1] ? false
    [0,2,0,1] is_alias [2,1,0,2] ? false
    [0,2,0,1] is_alias [2,1,1,0] ? false
    [0,2,0,1] is_alias [2,1,1,1] ? false
    [0,2,0,1] is_alias [2,1,1,2] ? false
    [0,2,0,1] is_alias [2,1,2,0] ? false
    [0,2,0,1] is_alias [2,1,2,1] ? false
    [0,2,0,1] is_alias [2,1,2,2] ? false
    [0,2,0,1] is_alias [2,2,0,0] ? false
    [0,2,0,1] is_alias [2,2,0,1] ? false
    [0,2,0,1] is_alias [2,2,0,2] ? false
    [0,2,0,1] is_alias [2,2,1,0] ? false
    [0,2,0,1] is_alias [2,2,1,1] ? false
    [0,2,0,1] is_alias [2,2,1,2] ? false
    [0,2,0,1] is_alias [2,2,2,0] ? false
    [0,2,0,1] is_alias [2,2,2,1] ? false
    [0,2,0,1] is_alias [2,2,2,2] ? false
    [0,2,0,2] index has alias ? : true
    [0,2,0,2] is_alias [0,0,0,0] ? false
    [0,2,0,2] is_alias [0,0,0,1] ? false
    [0,2,0,2] is_alias [0,0,0,2] ? false
    [0,2,0,2] is_alias [0,0,1,0] ? false
    [0,2,0,2] is_alias [0,0,1,1] ? false
    [0,2,0,2] is_alias [0,0,1,2] ? false
    [0,2,0,2] is_alias [0,0,2,0] ? false
    [0,2,0,2] is_alias [0,0,2,1] ? false
    [0,2,0,2] is_alias [0,0,2,2] ? false
    [0,2,0,2] is_alias [0,1,0,0] ? false
    [0,2,0,2] is_alias [0,1,0,1] ? false
    [0,2,0,2] is_alias [0,1,0,2] ? false
    [0,2,0,2] is_alias [0,1,1,0] ? false
    [0,2,0,2] is_alias [0,1,1,1] ? false
    [0,2,0,2] is_alias [0,1,1,2] ? false
    [0,2,0,2] is_alias [0,1,2,0] ? false
    [0,2,0,2] is_alias [0,1,2,1] ? false
    [0,2,0,2] is_alias [0,1,2,2] ? false
    [0,2,0,2] is_alias [0,2,0,0] ? false
    [0,2,0,2] is_alias [0,2,0,1] ? false
    [0,2,0,2] is_alias [0,2,0,2] ? false
    [0,2,0,2] is_alias [0,2,1,0] ? false
    [0,2,0,2] is_alias [0,2,1,1] ? false
    [0,2,0,2] is_alias [0,2,1,2] ? false
    [0,2,0,2] is_alias [0,2,2,0] ? true
    [0,2,0,2] is_alias [0,2,2,1] ? false
    [0,2,0,2] is_alias [0,2,2,2] ? false
    [0,2,0,2] is_alias [1,0,0,0] ? false
    [0,2,0,2] is_alias [1,0,0,1] ? false
    [0,2,0,2] is_alias [1,0,0,2] ? false
    [0,2,0,2] is_alias [1,0,1,0] ? false
    [0,2,0,2] is_alias [1,0,1,1] ? false
    [0,2,0,2] is_alias [1,0,1,2] ? false
    [0,2,0,2] is_alias [1,0,2,0] ? false
    [0,2,0,2] is_alias [1,0,2,1] ? false
    [0,2,0,2] is_alias [1,0,2,2] ? false
    [0,2,0,2] is_alias [1,1,0,0] ? false
    [0,2,0,2] is_alias [1,1,0,1] ? false
    [0,2,0,2] is_alias [1,1,0,2] ? false
    [0,2,0,2] is_alias [1,1,1,0] ? false
    [0,2,0,2] is_alias [1,1,1,1] ? false
    [0,2,0,2] is_alias [1,1,1,2] ? false
    [0,2,0,2] is_alias [1,1,2,0] ? false
    [0,2,0,2] is_alias [1,1,2,1] ? false
    [0,2,0,2] is_alias [1,1,2,2] ? false
    [0,2,0,2] is_alias [1,2,0,0] ? false
    [0,2,0,2] is_alias [1,2,0,1] ? false
    [0,2,0,2] is_alias [1,2,0,2] ? false
    [0,2,0,2] is_alias [1,2,1,0] ? false
    [0,2,0,2] is_alias [1,2,1,1] ? false
    [0,2,0,2] is_alias [1,2,1,2] ? false
    [0,2,0,2] is_alias [1,2,2,0] ? false
    [0,2,0,2] is_alias [1,2,2,1] ? false
    [0,2,0,2] is_alias [1,2,2,2] ? false
    [0,2,0,2] is_alias [2,0,0,0] ? false
    [0,2,0,2] is_alias [2,0,0,1] ? false
    [0,2,0,2] is_alias [2,0,0,2] ? true
    [0,2,0,2] is_alias [2,0,1,0] ? false
    [0,2,0,2] is_alias [2,0,1,1] ? false
    [0,2,0,2] is_alias [2,0,1,2] ? false
    [0,2,0,2] is_alias [2,0,2,0] ? true
    [0,2,0,2] is_alias [2,0,2,1] ? false
    [0,2,0,2] is_alias [2,0,2,2] ? false
    [0,2,0,2] is_alias [2,1,0,0] ? false
    [0,2,0,2] is_alias [2,1,0,1] ? false
    [0,2,0,2] is_alias [2,1,0,2] ? false
    [0,2,0,2] is_alias [2,1,1,0] ? false
    [0,2,0,2] is_alias [2,1,1,1] ? false
    [0,2,0,2] is_alias [2,1,1,2] ? false
    [0,2,0,2] is_alias [2,1,2,0] ? false
    [0,2,0,2] is_alias [2,1,2,1] ? false
    [0,2,0,2] is_alias [2,1,2,2] ? false
    [0,2,0,2] is_alias [2,2,0,0] ? false
    [0,2,0,2] is_alias [2,2,0,1] ? false
    [0,2,0,2] is_alias [2,2,0,2] ? false
    [0,2,0,2] is_alias [2,2,1,0] ? false
    [0,2,0,2] is_alias [2,2,1,1] ? false
    [0,2,0,2] is_alias [2,2,1,2] ? false
    [0,2,0,2] is_alias [2,2,2,0] ? false
    [0,2,0,2] is_alias [2,2,2,1] ? false
    [0,2,0,2] is_alias [2,2,2,2] ? false
    [0,2,1,0] index has alias ? : true
    [0,2,1,0] is_alias [0,0,0,0] ? false
    [0,2,1,0] is_alias [0,0,0,1] ? false
    [0,2,1,0] is_alias [0,0,0,2] ? false
    [0,2,1,0] is_alias [0,0,1,0] ? false
    [0,2,1,0] is_alias [0,0,1,1] ? false
    [0,2,1,0] is_alias [0,0,1,2] ? false
    [0,2,1,0] is_alias [0,0,2,0] ? false
    [0,2,1,0] is_alias [0,0,2,1] ? false
    [0,2,1,0] is_alias [0,0,2,2] ? false
    [0,2,1,0] is_alias [0,1,0,0] ? false
    [0,2,1,0] is_alias [0,1,0,1] ? false
    [0,2,1,0] is_alias [0,1,0,2] ? true
    [0,2,1,0] is_alias [0,1,1,0] ? false
    [0,2,1,0] is_alias [0,1,1,1] ? false
    [0,2,1,0] is_alias [0,1,1,2] ? false
    [0,2,1,0] is_alias [0,1,2,0] ? true
    [0,2,1,0] is_alias [0,1,2,1] ? false
    [0,2,1,0] is_alias [0,1,2,2] ? false
    [0,2,1,0] is_alias [0,2,0,0] ? false
    [0,2,1,0] is_alias [0,2,0,1] ? true
    [0,2,1,0] is_alias [0,2,0,2] ? false
    [0,2,1,0] is_alias [0,2,1,0] ? false
    [0,2,1,0] is_alias [0,2,1,1] ? false
    [0,2,1,0] is_alias [0,2,1,2] ? false
    [0,2,1,0] is_alias [0,2,2,0] ? false
    [0,2,1,0] is_alias [0,2,2,1] ? false
    [0,2,1,0] is_alias [0,2,2,2] ? false
    [0,2,1,0] is_alias [1,0,0,0] ? false
    [0,2,1,0] is_alias [1,0,0,1] ? false
    [0,2,1,0] is_alias [1,0,0,2] ? true
    [0,2,1,0] is_alias [1,0,1,0] ? false
    [0,2,1,0] is_alias [1,0,1,1] ? false
    [0,2,1,0] is_alias [1,0,1,2] ? false
    [0,2,1,0] is_alias [1,0,2,0] ? true
    [0,2,1,0] is_alias [1,0,2,1] ? false
    [0,2,1,0] is_alias [1,0,2,2] ? false
    [0,2,1,0] is_alias [1,1,0,0] ? false
    [0,2,1,0] is_alias [1,1,0,1] ? false
    [0,2,1,0] is_alias [1,1,0,2] ? false
    [0,2,1,0] is_alias [1,1,1,0] ? false
    [0,2,1,0] is_alias [1,1,1,1] ? false
    [0,2,1,0] is_alias [1,1,1,2] ? false
    [0,2,1,0] is_alias [1,1,2,0] ? false
    [0,2,1,0] is_alias [1,1,2,1] ? false
    [0,2,1,0] is_alias [1,1,2,2] ? false
    [0,2,1,0] is_alias [1,2,0,0] ? false
    [0,2,1,0] is_alias [1,2,0,1] ? false
    [0,2,1,0] is_alias [1,2,0,2] ? false
    [0,2,1,0] is_alias [1,2,1,0] ? false
    [0,2,1,0] is_alias [1,2,1,1] ? false
    [0,2,1,0] is_alias [1,2,1,2] ? false
    [0,2,1,0] is_alias [1,2,2,0] ? false
    [0,2,1,0] is_alias [1,2,2,1] ? false
    [0,2,1,0] is_alias [1,2,2,2] ? false
    [0,2,1,0] is_alias [2,0,0,0] ? false
    [0,2,1,0] is_alias [2,0,0,1] ? true
    [0,2,1,0] is_alias [2,0,0,2] ? false
    [0,2,1,0] is_alias [2,0,1,0] ? true
    [0,2,1,0] is_alias [2,0,1,1] ? false
    [0,2,1,0] is_alias [2,0,1,2] ? false
    [0,2,1,0] is_alias [2,0,2,0] ? false
    [0,2,1,0] is_alias [2,0,2,1] ? false
    [0,2,1,0] is_alias [2,0,2,2] ? false
    [0,2,1,0] is_alias [2,1,0,0] ? false
    [0,2,1,0] is_alias [2,1,0,1] ? false
    [0,2,1,0] is_alias [2,1,0,2] ? false
    [0,2,1,0] is_alias [2,1,1,0] ? false
    [0,2,1,0] is_alias [2,1,1,1] ? false
    [0,2,1,0] is_alias [2,1,1,2] ? false
    [0,2,1,0] is_alias [2,1,2,0] ? false
    [0,2,1,0] is_alias [2,1,2,1] ? false
    [0,2,1,0] is_alias [2,1,2,2] ? false
    [0,2,1,0] is_alias [2,2,0,0] ? false
    [0,2,1,0] is_alias [2,2,0,1] ? false
    [0,2,1,0] is_alias [2,2,0,2] ? false
    [0,2,1,0] is_alias [2,2,1,0] ? false
    [0,2,1,0] is_alias [2,2,1,1] ? false
    [0,2,1,0] is_alias [2,2,1,2] ? false
    [0,2,1,0] is_alias [2,2,2,0] ? false
    [0,2,1,0] is_alias [2,2,2,1] ? false
    [0,2,1,0] is_alias [2,2,2,2] ? false
    [0,2,1,1] index has alias ? : true
    [0,2,1,1] is_alias [0,0,0,0] ? false
    [0,2,1,1] is_alias [0,0,0,1] ? false
    [0,2,1,1] is_alias [0,0,0,2] ? false
    [0,2,1,1] is_alias [0,0,1,0] ? false
    [0,2,1,1] is_alias [0,0,1,1] ? false
    [0,2,1,1] is_alias [0,0,1,2] ? false
    [0,2,1,1] is_alias [0,0,2,0] ? false
    [0,2,1,1] is_alias [0,0,2,1] ? false
    [0,2,1,1] is_alias [0,0,2,2] ? false
    [0,2,1,1] is_alias [0,1,0,0] ? false
    [0,2,1,1] is_alias [0,1,0,1] ? false
    [0,2,1,1] is_alias [0,1,0,2] ? false
    [0,2,1,1] is_alias [0,1,1,0] ? false
    [0,2,1,1] is_alias [0,1,1,1] ? false
    [0,2,1,1] is_alias [0,1,1,2] ? false
    [0,2,1,1] is_alias [0,1,2,0] ? false
    [0,2,1,1] is_alias [0,1,2,1] ? false
    [0,2,1,1] is_alias [0,1,2,2] ? false
    [0,2,1,1] is_alias [0,2,0,0] ? false
    [0,2,1,1] is_alias [0,2,0,1] ? false
    [0,2,1,1] is_alias [0,2,0,2] ? false
    [0,2,1,1] is_alias [0,2,1,0] ? false
    [0,2,1,1] is_alias [0,2,1,1] ? false
    [0,2,1,1] is_alias [0,2,1,2] ? false
    [0,2,1,1] is_alias [0,2,2,0] ? false
    [0,2,1,1] is_alias [0,2,2,1] ? false
    [0,2,1,1] is_alias [0,2,2,2] ? false
    [0,2,1,1] is_alias [1,0,0,0] ? false
    [0,2,1,1] is_alias [1,0,0,1] ? false
    [0,2,1,1] is_alias [1,0,0,2] ? false
    [0,2,1,1] is_alias [1,0,1,0] ? false
    [0,2,1,1] is_alias [1,0,1,1] ? false
    [0,2,1,1] is_alias [1,0,1,2] ? false
    [0,2,1,1] is_alias [1,0,2,0] ? false
    [0,2,1,1] is_alias [1,0,2,1] ? false
    [0,2,1,1] is_alias [1,0,2,2] ? false
    [0,2,1,1] is_alias [1,1,0,0] ? false
    [0,2,1,1] is_alias [1,1,0,1] ? false
    [0,2,1,1] is_alias [1,1,0,2] ? true
    [0,2,1,1] is_alias [1,1,1,0] ? false
    [0,2,1,1] is_alias [1,1,1,1] ? false
    [0,2,1,1] is_alias [1,1,1,2] ? false
    [0,2,1,1] is_alias [1,1,2,0] ? true
    [0,2,1,1] is_alias [1,1,2,1] ? false
    [0,2,1,1] is_alias [1,1,2,2] ? false
    [0,2,1,1] is_alias [1,2,0,0] ? false
    [0,2,1,1] is_alias [1,2,0,1] ? false
    [0,2,1,1] is_alias [1,2,0,2] ? false
    [0,2,1,1] is_alias [1,2,1,0] ? false
    [0,2,1,1] is_alias [1,2,1,1] ? false
    [0,2,1,1] is_alias [1,2,1,2] ? false
    [0,2,1,1] is_alias [1,2,2,0] ? false
    [0,2,1,1] is_alias [1,2,2,1] ? false
    [0,2,1,1] is_alias [1,2,2,2] ? false
    [0,2,1,1] is_alias [2,0,0,0] ? false
    [0,2,1,1] is_alias [2,0,0,1] ? false
    [0,2,1,1] is_alias [2,0,0,2] ? false
    [0,2,1,1] is_alias [2,0,1,0] ? false
    [0,2,1,1] is_alias [2,0,1,1] ? true
    [0,2,1,1] is_alias [2,0,1,2] ? false
    [0,2,1,1] is_alias [2,0,2,0] ? false
    [0,2,1,1] is_alias [2,0,2,1] ? false
    [0,2,1,1] is_alias [2,0,2,2] ? false
    [0,2,1,1] is_alias [2,1,0,0] ? false
    [0,2,1,1] is_alias [2,1,0,1] ? false
    [0,2,1,1] is_alias [2,1,0,2] ? false
    [0,2,1,1] is_alias [2,1,1,0] ? false
    [0,2,1,1] is_alias [2,1,1,1] ? false
    [0,2,1,1] is_alias [2,1,1,2] ? false
    [0,2,1,1] is_alias [2,1,2,0] ? false
    [0,2,1,1] is_alias [2,1,2,1] ? false
    [0,2,1,1] is_alias [2,1,2,2] ? false
    [0,2,1,1] is_alias [2,2,0,0] ? false
    [0,2,1,1] is_alias [2,2,0,1] ? false
    [0,2,1,1] is_alias [2,2,0,2] ? false
    [0,2,1,1] is_alias [2,2,1,0] ? false
    [0,2,1,1] is_alias [2,2,1,1] ? false
    [0,2,1,1] is_alias [2,2,1,2] ? false
    [0,2,1,1] is_alias [2,2,2,0] ? false
    [0,2,1,1] is_alias [2,2,2,1] ? false
    [0,2,1,1] is_alias [2,2,2,2] ? false
    [0,2,1,2] index has alias ? : true
    [0,2,1,2] is_alias [0,0,0,0] ? false
    [0,2,1,2] is_alias [0,0,0,1] ? false
    [0,2,1,2] is_alias [0,0,0,2] ? false
    [0,2,1,2] is_alias [0,0,1,0] ? false
    [0,2,1,2] is_alias [0,0,1,1] ? false
    [0,2,1,2] is_alias [0,0,1,2] ? false
    [0,2,1,2] is_alias [0,0,2,0] ? false
    [0,2,1,2] is_alias [0,0,2,1] ? false
    [0,2,1,2] is_alias [0,0,2,2] ? false
    [0,2,1,2] is_alias [0,1,0,0] ? false
    [0,2,1,2] is_alias [0,1,0,1] ? false
    [0,2,1,2] is_alias [0,1,0,2] ? false
    [0,2,1,2] is_alias [0,1,1,0] ? false
    [0,2,1,2] is_alias [0,1,1,1] ? false
    [0,2,1,2] is_alias [0,1,1,2] ? false
    [0,2,1,2] is_alias [0,1,2,0] ? false
    [0,2,1,2] is_alias [0,1,2,1] ? false
    [0,2,1,2] is_alias [0,1,2,2] ? false
    [0,2,1,2] is_alias [0,2,0,0] ? false
    [0,2,1,2] is_alias [0,2,0,1] ? false
    [0,2,1,2] is_alias [0,2,0,2] ? false
    [0,2,1,2] is_alias [0,2,1,0] ? false
    [0,2,1,2] is_alias [0,2,1,1] ? false
    [0,2,1,2] is_alias [0,2,1,2] ? false
    [0,2,1,2] is_alias [0,2,2,0] ? false
    [0,2,1,2] is_alias [0,2,2,1] ? true
    [0,2,1,2] is_alias [0,2,2,2] ? false
    [0,2,1,2] is_alias [1,0,0,0] ? false
    [0,2,1,2] is_alias [1,0,0,1] ? false
    [0,2,1,2] is_alias [1,0,0,2] ? false
    [0,2,1,2] is_alias [1,0,1,0] ? false
    [0,2,1,2] is_alias [1,0,1,1] ? false
    [0,2,1,2] is_alias [1,0,1,2] ? false
    [0,2,1,2] is_alias [1,0,2,0] ? false
    [0,2,1,2] is_alias [1,0,2,1] ? false
    [0,2,1,2] is_alias [1,0,2,2] ? false
    [0,2,1,2] is_alias [1,1,0,0] ? false
    [0,2,1,2] is_alias [1,1,0,1] ? false
    [0,2,1,2] is_alias [1,1,0,2] ? false
    [0,2,1,2] is_alias [1,1,1,0] ? false
    [0,2,1,2] is_alias [1,1,1,1] ? false
    [0,2,1,2] is_alias [1,1,1,2] ? false
    [0,2,1,2] is_alias [1,1,2,0] ? false
    [0,2,1,2] is_alias [1,1,2,1] ? false
    [0,2,1,2] is_alias [1,1,2,2] ? false
    [0,2,1,2] is_alias [1,2,0,0] ? false
    [0,2,1,2] is_alias [1,2,0,1] ? false
    [0,2,1,2] is_alias [1,2,0,2] ? true
    [0,2,1,2] is_alias [1,2,1,0] ? false
    [0,2,1,2] is_alias [1,2,1,1] ? false
    [0,2,1,2] is_alias [1,2,1,2] ? false
    [0,2,1,2] is_alias [1,2,2,0] ? true
    [0,2,1,2] is_alias [1,2,2,1] ? false
    [0,2,1,2] is_alias [1,2,2,2] ? false
    [0,2,1,2] is_alias [2,0,0,0] ? false
    [0,2,1,2] is_alias [2,0,0,1] ? false
    [0,2,1,2] is_alias [2,0,0,2] ? false
    [0,2,1,2] is_alias [2,0,1,0] ? false
    [0,2,1,2] is_alias [2,0,1,1] ? false
    [0,2,1,2] is_alias [2,0,1,2] ? true
    [0,2,1,2] is_alias [2,0,2,0] ? false
    [0,2,1,2] is_alias [2,0,2,1] ? true
    [0,2,1,2] is_alias [2,0,2,2] ? false
    [0,2,1,2] is_alias [2,1,0,0] ? false
    [0,2,1,2] is_alias [2,1,0,1] ? false
    [0,2,1,2] is_alias [2,1,0,2] ? true
    [0,2,1,2] is_alias [2,1,1,0] ? false
    [0,2,1,2] is_alias [2,1,1,1] ? false
    [0,2,1,2] is_alias [2,1,1,2] ? false
    [0,2,1,2] is_alias [2,1,2,0] ? true
    [0,2,1,2] is_alias [2,1,2,1] ? false
    [0,2,1,2] is_alias [2,1,2,2] ? false
    [0,2,1,2] is_alias [2,2,0,0] ? false
    [0,2,1,2] is_alias [2,2,0,1] ? false
    [0,2,1,2] is_alias [2,2,0,2] ? false
    [0,2,1,2] is_alias [2,2,1,0] ? false
    [0,2,1,2] is_alias [2,2,1,1] ? false
    [0,2,1,2] is_alias [2,2,1,2] ? false
    [0,2,1,2] is_alias [2,2,2,0] ? false
    [0,2,1,2] is_alias [2,2,2,1] ? false
    [0,2,1,2] is_alias [2,2,2,2] ? false
    [0,2,2,0] index has alias ? : true
    [0,2,2,0] is_alias [0,0,0,0] ? false
    [0,2,2,0] is_alias [0,0,0,1] ? false
    [0,2,2,0] is_alias [0,0,0,2] ? false
    [0,2,2,0] is_alias [0,0,1,0] ? false
    [0,2,2,0] is_alias [0,0,1,1] ? false
    [0,2,2,0] is_alias [0,0,1,2] ? false
    [0,2,2,0] is_alias [0,0,2,0] ? false
    [0,2,2,0] is_alias [0,0,2,1] ? false
    [0,2,2,0] is_alias [0,0,2,2] ? false
    [0,2,2,0] is_alias [0,1,0,0] ? false
    [0,2,2,0] is_alias [0,1,0,1] ? false
    [0,2,2,0] is_alias [0,1,0,2] ? false
    [0,2,2,0] is_alias [0,1,1,0] ? false
    [0,2,2,0] is_alias [0,1,1,1] ? false
    [0,2,2,0] is_alias [0,1,1,2] ? false
    [0,2,2,0] is_alias [0,1,2,0] ? false
    [0,2,2,0] is_alias [0,1,2,1] ? false
    [0,2,2,0] is_alias [0,1,2,2] ? false
    [0,2,2,0] is_alias [0,2,0,0] ? false
    [0,2,2,0] is_alias [0,2,0,1] ? false
    [0,2,2,0] is_alias [0,2,0,2] ? true
    [0,2,2,0] is_alias [0,2,1,0] ? false
    [0,2,2,0] is_alias [0,2,1,1] ? false
    [0,2,2,0] is_alias [0,2,1,2] ? false
    [0,2,2,0] is_alias [0,2,2,0] ? false
    [0,2,2,0] is_alias [0,2,2,1] ? false
    [0,2,2,0] is_alias [0,2,2,2] ? false
    [0,2,2,0] is_alias [1,0,0,0] ? false
    [0,2,2,0] is_alias [1,0,0,1] ? false
    [0,2,2,0] is_alias [1,0,0,2] ? false
    [0,2,2,0] is_alias [1,0,1,0] ? false
    [0,2,2,0] is_alias [1,0,1,1] ? false
    [0,2,2,0] is_alias [1,0,1,2] ? false
    [0,2,2,0] is_alias [1,0,2,0] ? false
    [0,2,2,0] is_alias [1,0,2,1] ? false
    [0,2,2,0] is_alias [1,0,2,2] ? false
    [0,2,2,0] is_alias [1,1,0,0] ? false
    [0,2,2,0] is_alias [1,1,0,1] ? false
    [0,2,2,0] is_alias [1,1,0,2] ? false
    [0,2,2,0] is_alias [1,1,1,0] ? false
    [0,2,2,0] is_alias [1,1,1,1] ? false
    [0,2,2,0] is_alias [1,1,1,2] ? false
    [0,2,2,0] is_alias [1,1,2,0] ? false
    [0,2,2,0] is_alias [1,1,2,1] ? false
    [0,2,2,0] is_alias [1,1,2,2] ? false
    [0,2,2,0] is_alias [1,2,0,0] ? false
    [0,2,2,0] is_alias [1,2,0,1] ? false
    [0,2,2,0] is_alias [1,2,0,2] ? false
    [0,2,2,0] is_alias [1,2,1,0] ? false
    [0,2,2,0] is_alias [1,2,1,1] ? false
    [0,2,2,0] is_alias [1,2,1,2] ? false
    [0,2,2,0] is_alias [1,2,2,0] ? false
    [0,2,2,0] is_alias [1,2,2,1] ? false
    [0,2,2,0] is_alias [1,2,2,2] ? false
    [0,2,2,0] is_alias [2,0,0,0] ? false
    [0,2,2,0] is_alias [2,0,0,1] ? false
    [0,2,2,0] is_alias [2,0,0,2] ? true
    [0,2,2,0] is_alias [2,0,1,0] ? false
    [0,2,2,0] is_alias [2,0,1,1] ? false
    [0,2,2,0] is_alias [2,0,1,2] ? false
    [0,2,2,0] is_alias [2,0,2,0] ? true
    [0,2,2,0] is_alias [2,0,2,1] ? false
    [0,2,2,0] is_alias [2,0,2,2] ? false
    [0,2,2,0] is_alias [2,1,0,0] ? false
    [0,2,2,0] is_alias [2,1,0,1] ? false
    [0,2,2,0] is_alias [2,1,0,2] ? false
    [0,2,2,0] is_alias [2,1,1,0] ? false
    [0,2,2,0] is_alias [2,1,1,1] ? false
    [0,2,2,0] is_alias [2,1,1,2] ? false
    [0,2,2,0] is_alias [2,1,2,0] ? false
    [0,2,2,0] is_alias [2,1,2,1] ? false
    [0,2,2,0] is_alias [2,1,2,2] ? false
    [0,2,2,0] is_alias [2,2,0,0] ? false
    [0,2,2,0] is_alias [2,2,0,1] ? false
    [0,2,2,0] is_alias [2,2,0,2] ? false
    [0,2,2,0] is_alias [2,2,1,0] ? false
    [0,2,2,0] is_alias [2,2,1,1] ? false
    [0,2,2,0] is_alias [2,2,1,2] ? false
    [0,2,2,0] is_alias [2,2,2,0] ? false
    [0,2,2,0] is_alias [2,2,2,1] ? false
    [0,2,2,0] is_alias [2,2,2,2] ? false
    [0,2,2,1] index has alias ? : true
    [0,2,2,1] is_alias [0,0,0,0] ? false
    [0,2,2,1] is_alias [0,0,0,1] ? false
    [0,2,2,1] is_alias [0,0,0,2] ? false
    [0,2,2,1] is_alias [0,0,1,0] ? false
    [0,2,2,1] is_alias [0,0,1,1] ? false
    [0,2,2,1] is_alias [0,0,1,2] ? false
    [0,2,2,1] is_alias [0,0,2,0] ? false
    [0,2,2,1] is_alias [0,0,2,1] ? false
    [0,2,2,1] is_alias [0,0,2,2] ? false
    [0,2,2,1] is_alias [0,1,0,0] ? false
    [0,2,2,1] is_alias [0,1,0,1] ? false
    [0,2,2,1] is_alias [0,1,0,2] ? false
    [0,2,2,1] is_alias [0,1,1,0] ? false
    [0,2,2,1] is_alias [0,1,1,1] ? false
    [0,2,2,1] is_alias [0,1,1,2] ? false
    [0,2,2,1] is_alias [0,1,2,0] ? false
    [0,2,2,1] is_alias [0,1,2,1] ? false
    [0,2,2,1] is_alias [0,1,2,2] ? false
    [0,2,2,1] is_alias [0,2,0,0] ? false
    [0,2,2,1] is_alias [0,2,0,1] ? false
    [0,2,2,1] is_alias [0,2,0,2] ? false
    [0,2,2,1] is_alias [0,2,1,0] ? false
    [0,2,2,1] is_alias [0,2,1,1] ? false
    [0,2,2,1] is_alias [0,2,1,2] ? true
    [0,2,2,1] is_alias [0,2,2,0] ? false
    [0,2,2,1] is_alias [0,2,2,1] ? false
    [0,2,2,1] is_alias [0,2,2,2] ? false
    [0,2,2,1] is_alias [1,0,0,0] ? false
    [0,2,2,1] is_alias [1,0,0,1] ? false
    [0,2,2,1] is_alias [1,0,0,2] ? false
    [0,2,2,1] is_alias [1,0,1,0] ? false
    [0,2,2,1] is_alias [1,0,1,1] ? false
    [0,2,2,1] is_alias [1,0,1,2] ? false
    [0,2,2,1] is_alias [1,0,2,0] ? false
    [0,2,2,1] is_alias [1,0,2,1] ? false
    [0,2,2,1] is_alias [1,0,2,2] ? false
    [0,2,2,1] is_alias [1,1,0,0] ? false
    [0,2,2,1] is_alias [1,1,0,1] ? false
    [0,2,2,1] is_alias [1,1,0,2] ? false
    [0,2,2,1] is_alias [1,1,1,0] ? false
    [0,2,2,1] is_alias [1,1,1,1] ? false
    [0,2,2,1] is_alias [1,1,1,2] ? false
    [0,2,2,1] is_alias [1,1,2,0] ? false
    [0,2,2,1] is_alias [1,1,2,1] ? false
    [0,2,2,1] is_alias [1,1,2,2] ? false
    [0,2,2,1] is_alias [1,2,0,0] ? false
    [0,2,2,1] is_alias [1,2,0,1] ? false
    [0,2,2,1] is_alias [1,2,0,2] ? true
    [0,2,2,1] is_alias [1,2,1,0] ? false
    [0,2,2,1] is_alias [1,2,1,1] ? false
    [0,2,2,1] is_alias [1,2,1,2] ? false
    [0,2,2,1] is_alias [1,2,2,0] ? true
    [0,2,2,1] is_alias [1,2,2,1] ? false
    [0,2,2,1] is_alias [1,2,2,2] ? false
    [0,2,2,1] is_alias [2,0,0,0] ? false
    [0,2,2,1] is_alias [2,0,0,1] ? false
    [0,2,2,1] is_alias [2,0,0,2] ? false
    [0,2,2,1] is_alias [2,0,1,0] ? false
    [0,2,2,1] is_alias [2,0,1,1] ? false
    [0,2,2,1] is_alias [2,0,1,2] ? true
    [0,2,2,1] is_alias [2,0,2,0] ? false
    [0,2,2,1] is_alias [2,0,2,1] ? true
    [0,2,2,1] is_alias [2,0,2,2] ? false
    [0,2,2,1] is_alias [2,1,0,0] ? false
    [0,2,2,1] is_alias [2,1,0,1] ? false
    [0,2,2,1] is_alias [2,1,0,2] ? true
    [0,2,2,1] is_alias [2,1,1,0] ? false
    [0,2,2,1] is_alias [2,1,1,1] ? false
    [0,2,2,1] is_alias [2,1,1,2] ? false
    [0,2,2,1] is_alias [2,1,2,0] ? true
    [0,2,2,1] is_alias [2,1,2,1] ? false
    [0,2,2,1] is_alias [2,1,2,2] ? false
    [0,2,2,1] is_alias [2,2,0,0] ? false
    [0,2,2,1] is_alias [2,2,0,1] ? false
    [0,2,2,1] is_alias [2,2,0,2] ? false
    [0,2,2,1] is_alias [2,2,1,0] ? false
    [0,2,2,1] is_alias [2,2,1,1] ? false
    [0,2,2,1] is_alias [2,2,1,2] ? false
    [0,2,2,1] is_alias [2,2,2,0] ? false
    [0,2,2,1] is_alias [2,2,2,1] ? false
    [0,2,2,1] is_alias [2,2,2,2] ? false
    [0,2,2,2] index has alias ? : true
    [0,2,2,2] is_alias [0,0,0,0] ? false
    [0,2,2,2] is_alias [0,0,0,1] ? false
    [0,2,2,2] is_alias [0,0,0,2] ? false
    [0,2,2,2] is_alias [0,0,1,0] ? false
    [0,2,2,2] is_alias [0,0,1,1] ? false
    [0,2,2,2] is_alias [0,0,1,2] ? false
    [0,2,2,2] is_alias [0,0,2,0] ? false
    [0,2,2,2] is_alias [0,0,2,1] ? false
    [0,2,2,2] is_alias [0,0,2,2] ? false
    [0,2,2,2] is_alias [0,1,0,0] ? false
    [0,2,2,2] is_alias [0,1,0,1] ? false
    [0,2,2,2] is_alias [0,1,0,2] ? false
    [0,2,2,2] is_alias [0,1,1,0] ? false
    [0,2,2,2] is_alias [0,1,1,1] ? false
    [0,2,2,2] is_alias [0,1,1,2] ? false
    [0,2,2,2] is_alias [0,1,2,0] ? false
    [0,2,2,2] is_alias [0,1,2,1] ? false
    [0,2,2,2] is_alias [0,1,2,2] ? false
    [0,2,2,2] is_alias [0,2,0,0] ? false
    [0,2,2,2] is_alias [0,2,0,1] ? false
    [0,2,2,2] is_alias [0,2,0,2] ? false
    [0,2,2,2] is_alias [0,2,1,0] ? false
    [0,2,2,2] is_alias [0,2,1,1] ? false
    [0,2,2,2] is_alias [0,2,1,2] ? false
    [0,2,2,2] is_alias [0,2,2,0] ? false
    [0,2,2,2] is_alias [0,2,2,1] ? false
    [0,2,2,2] is_alias [0,2,2,2] ? false
    [0,2,2,2] is_alias [1,0,0,0] ? false
    [0,2,2,2] is_alias [1,0,0,1] ? false
    [0,2,2,2] is_alias [1,0,0,2] ? false
    [0,2,2,2] is_alias [1,0,1,0] ? false
    [0,2,2,2] is_alias [1,0,1,1] ? false
    [0,2,2,2] is_alias [1,0,1,2] ? false
    [0,2,2,2] is_alias [1,0,2,0] ? false
    [0,2,2,2] is_alias [1,0,2,1] ? false
    [0,2,2,2] is_alias [1,0,2,2] ? false
    [0,2,2,2] is_alias [1,1,0,0] ? false
    [0,2,2,2] is_alias [1,1,0,1] ? false
    [0,2,2,2] is_alias [1,1,0,2] ? false
    [0,2,2,2] is_alias [1,1,1,0] ? false
    [0,2,2,2] is_alias [1,1,1,1] ? false
    [0,2,2,2] is_alias [1,1,1,2] ? false
    [0,2,2,2] is_alias [1,1,2,0] ? false
    [0,2,2,2] is_alias [1,1,2,1] ? false
    [0,2,2,2] is_alias [1,1,2,2] ? false
    [0,2,2,2] is_alias [1,2,0,0] ? false
    [0,2,2,2] is_alias [1,2,0,1] ? false
    [0,2,2,2] is_alias [1,2,0,2] ? false
    [0,2,2,2] is_alias [1,2,1,0] ? false
    [0,2,2,2] is_alias [1,2,1,1] ? false
    [0,2,2,2] is_alias [1,2,1,2] ? false
    [0,2,2,2] is_alias [1,2,2,0] ? false
    [0,2,2,2] is_alias [1,2,2,1] ? false
    [0,2,2,2] is_alias [1,2,2,2] ? false
    [0,2,2,2] is_alias [2,0,0,0] ? false
    [0,2,2,2] is_alias [2,0,0,1] ? false
    [0,2,2,2] is_alias [2,0,0,2] ? false
    [0,2,2,2] is_alias [2,0,1,0] ? false
    [0,2,2,2] is_alias [2,0,1,1] ? false
    [0,2,2,2] is_alias [2,0,1,2] ? false
    [0,2,2,2] is_alias [2,0,2,0] ? false
    [0,2,2,2] is_alias [2,0,2,1] ? false
    [0,2,2,2] is_alias [2,0,2,2] ? true
    [0,2,2,2] is_alias [2,1,0,0] ? false
    [0,2,2,2] is_alias [2,1,0,1] ? false
    [0,2,2,2] is_alias [2,1,0,2] ? false
    [0,2,2,2] is_alias [2,1,1,0] ? false
    [0,2,2,2] is_alias [2,1,1,1] ? false
    [0,2,2,2] is_alias [2,1,1,2] ? false
    [0,2,2,2] is_alias [2,1,2,0] ? false
    [0,2,2,2] is_alias [2,1,2,1] ? false
    [0,2,2,2] is_alias [2,1,2,2] ? false
    [0,2,2,2] is_alias [2,2,0,0] ? false
    [0,2,2,2] is_alias [2,2,0,1] ? false
    [0,2,2,2] is_alias [2,2,0,2] ? true
    [0,2,2,2] is_alias [2,2,1,0] ? false
    [0,2,2,2] is_alias [2,2,1,1] ? false
    [0,2,2,2] is_alias [2,2,1,2] ? false
    [0,2,2,2] is_alias [2,2,2,0] ? true
    [0,2,2,2] is_alias [2,2,2,1] ? false
    [0,2,2,2] is_alias [2,2,2,2] ? false
    [1,0,0,0] index has alias ? : true
    [1,0,0,0] is_alias [0,0,0,0] ? false
    [1,0,0,0] is_alias [0,0,0,1] ? true
    [1,0,0,0] is_alias [0,0,0,2] ? false
    [1,0,0,0] is_alias [0,0,1,0] ? true
    [1,0,0,0] is_alias [0,0,1,1] ? false
    [1,0,0,0] is_alias [0,0,1,2] ? false
    [1,0,0,0] is_alias [0,0,2,0] ? false
    [1,0,0,0] is_alias [0,0,2,1] ? false
    [1,0,0,0] is_alias [0,0,2,2] ? false
    [1,0,0,0] is_alias [0,1,0,0] ? true
    [1,0,0,0] is_alias [0,1,0,1] ? false
    [1,0,0,0] is_alias [0,1,0,2] ? false
    [1,0,0,0] is_alias [0,1,1,0] ? false
    [1,0,0,0] is_alias [0,1,1,1] ? false
    [1,0,0,0] is_alias [0,1,1,2] ? false
    [1,0,0,0] is_alias [0,1,2,0] ? false
    [1,0,0,0] is_alias [0,1,2,1] ? false
    [1,0,0,0] is_alias [0,1,2,2] ? false
    [1,0,0,0] is_alias [0,2,0,0] ? false
    [1,0,0,0] is_alias [0,2,0,1] ? false
    [1,0,0,0] is_alias [0,2,0,2] ? false
    [1,0,0,0] is_alias [0,2,1,0] ? false
    [1,0,0,0] is_alias [0,2,1,1] ? false
    [1,0,0,0] is_alias [0,2,1,2] ? false
    [1,0,0,0] is_alias [0,2,2,0] ? false
    [1,0,0,0] is_alias [0,2,2,1] ? false
    [1,0,0,0] is_alias [0,2,2,2] ? false
    [1,0,0,0] is_alias [1,0,0,0] ? false
    [1,0,0,0] is_alias [1,0,0,1] ? false
    [1,0,0,0] is_alias [1,0,0,2] ? false
    [1,0,0,0] is_alias [1,0,1,0] ? false
    [1,0,0,0] is_alias [1,0,1,1] ? false
    [1,0,0,0] is_alias [1,0,1,2] ? false
    [1,0,0,0] is_alias [1,0,2,0] ? false
    [1,0,0,0] is_alias [1,0,2,1] ? false
    [1,0,0,0] is_alias [1,0,2,2] ? false
    [1,0,0,0] is_alias [1,1,0,0] ? false
    [1,0,0,0] is_alias [1,1,0,1] ? false
    [1,0,0,0] is_alias [1,1,0,2] ? false
    [1,0,0,0] is_alias [1,1,1,0] ? false
    [1,0,0,0] is_alias [1,1,1,1] ? false
    [1,0,0,0] is_alias [1,1,1,2] ? false
    [1,0,0,0] is_alias [1,1,2,0] ? false
    [1,0,0,0] is_alias [1,1,2,1] ? false
    [1,0,0,0] is_alias [1,1,2,2] ? false
    [1,0,0,0] is_alias [1,2,0,0] ? false
    [1,0,0,0] is_alias [1,2,0,1] ? false
    [1,0,0,0] is_alias [1,2,0,2] ? false
    [1,0,0,0] is_alias [1,2,1,0] ? false
    [1,0,0,0] is_alias [1,2,1,1] ? false
    [1,0,0,0] is_alias [1,2,1,2] ? false
    [1,0,0,0] is_alias [1,2,2,0] ? false
    [1,0,0,0] is_alias [1,2,2,1] ? false
    [1,0,0,0] is_alias [1,2,2,2] ? false
    [1,0,0,0] is_alias [2,0,0,0] ? false
    [1,0,0,0] is_alias [2,0,0,1] ? false
    [1,0,0,0] is_alias [2,0,0,2] ? false
    [1,0,0,0] is_alias [2,0,1,0] ? false
    [1,0,0,0] is_alias [2,0,1,1] ? false
    [1,0,0,0] is_alias [2,0,1,2] ? false
    [1,0,0,0] is_alias [2,0,2,0] ? false
    [1,0,0,0] is_alias [2,0,2,1] ? false
    [1,0,0,0] is_alias [2,0,2,2] ? false
    [1,0,0,0] is_alias [2,1,0,0] ? false
    [1,0,0,0] is_alias [2,1,0,1] ? false
    [1,0,0,0] is_alias [2,1,0,2] ? false
    [1,0,0,0] is_alias [2,1,1,0] ? false
    [1,0,0,0] is_alias [2,1,1,1] ? false
    [1,0,0,0] is_alias [2,1,1,2] ? false
    [1,0,0,0] is_alias [2,1,2,0] ? false
    [1,0,0,0] is_alias [2,1,2,1] ? false
    [1,0,0,0] is_alias [2,1,2,2] ? false
    [1,0,0,0] is_alias [2,2,0,0] ? false
    [1,0,0,0] is_alias [2,2,0,1] ? false
    [1,0,0,0] is_alias [2,2,0,2] ? false
    [1,0,0,0] is_alias [2,2,1,0] ? false
    [1,0,0,0] is_alias [2,2,1,1] ? false
    [1,0,0,0] is_alias [2,2,1,2] ? false
    [1,0,0,0] is_alias [2,2,2,0] ? false
    [1,0,0,0] is_alias [2,2,2,1] ? false
    [1,0,0,0] is_alias [2,2,2,2] ? false
    [1,0,0,1] index has alias ? : true
    [1,0,0,1] is_alias [0,0,0,0] ? false
    [1,0,0,1] is_alias [0,0,0,1] ? false
    [1,0,0,1] is_alias [0,0,0,2] ? false
    [1,0,0,1] is_alias [0,0,1,0] ? false
    [1,0,0,1] is_alias [0,0,1,1] ? false
    [1,0,0,1] is_alias [0,0,1,2] ? false
    [1,0,0,1] is_alias [0,0,2,0] ? false
    [1,0,0,1] is_alias [0,0,2,1] ? false
    [1,0,0,1] is_alias [0,0,2,2] ? false
    [1,0,0,1] is_alias [0,1,0,0] ? false
    [1,0,0,1] is_alias [0,1,0,1] ? true
    [1,0,0,1] is_alias [0,1,0,2] ? false
    [1,0,0,1] is_alias [0,1,1,0] ? true
    [1,0,0,1] is_alias [0,1,1,1] ? false
    [1,0,0,1] is_alias [0,1,1,2] ? false
    [1,0,0,1] is_alias [0,1,2,0] ? false
    [1,0,0,1] is_alias [0,1,2,1] ? false
    [1,0,0,1] is_alias [0,1,2,2] ? false
    [1,0,0,1] is_alias [0,2,0,0] ? false
    [1,0,0,1] is_alias [0,2,0,1] ? false
    [1,0,0,1] is_alias [0,2,0,2] ? false
    [1,0,0,1] is_alias [0,2,1,0] ? false
    [1,0,0,1] is_alias [0,2,1,1] ? false
    [1,0,0,1] is_alias [0,2,1,2] ? false
    [1,0,0,1] is_alias [0,2,2,0] ? false
    [1,0,0,1] is_alias [0,2,2,1] ? false
    [1,0,0,1] is_alias [0,2,2,2] ? false
    [1,0,0,1] is_alias [1,0,0,0] ? false
    [1,0,0,1] is_alias [1,0,0,1] ? false
    [1,0,0,1] is_alias [1,0,0,2] ? false
    [1,0,0,1] is_alias [1,0,1,0] ? true
    [1,0,0,1] is_alias [1,0,1,1] ? false
    [1,0,0,1] is_alias [1,0,1,2] ? false
    [1,0,0,1] is_alias [1,0,2,0] ? false
    [1,0,0,1] is_alias [1,0,2,1] ? false
    [1,0,0,1] is_alias [1,0,2,2] ? false
    [1,0,0,1] is_alias [1,1,0,0] ? false
    [1,0,0,1] is_alias [1,1,0,1] ? false
    [1,0,0,1] is_alias [1,1,0,2] ? false
    [1,0,0,1] is_alias [1,1,1,0] ? false
    [1,0,0,1] is_alias [1,1,1,1] ? false
    [1,0,0,1] is_alias [1,1,1,2] ? false
    [1,0,0,1] is_alias [1,1,2,0] ? false
    [1,0,0,1] is_alias [1,1,2,1] ? false
    [1,0,0,1] is_alias [1,1,2,2] ? false
    [1,0,0,1] is_alias [1,2,0,0] ? false
    [1,0,0,1] is_alias [1,2,0,1] ? false
    [1,0,0,1] is_alias [1,2,0,2] ? false
    [1,0,0,1] is_alias [1,2,1,0] ? false
    [1,0,0,1] is_alias [1,2,1,1] ? false
    [1,0,0,1] is_alias [1,2,1,2] ? false
    [1,0,0,1] is_alias [1,2,2,0] ? false
    [1,0,0,1] is_alias [1,2,2,1] ? false
    [1,0,0,1] is_alias [1,2,2,2] ? false
    [1,0,0,1] is_alias [2,0,0,0] ? false
    [1,0,0,1] is_alias [2,0,0,1] ? false
    [1,0,0,1] is_alias [2,0,0,2] ? false
    [1,0,0,1] is_alias [2,0,1,0] ? false
    [1,0,0,1] is_alias [2,0,1,1] ? false
    [1,0,0,1] is_alias [2,0,1,2] ? false
    [1,0,0,1] is_alias [2,0,2,0] ? false
    [1,0,0,1] is_alias [2,0,2,1] ? false
    [1,0,0,1] is_alias [2,0,2,2] ? false
    [1,0,0,1] is_alias [2,1,0,0] ? false
    [1,0,0,1] is_alias [2,1,0,1] ? false
    [1,0,0,1] is_alias [2,1,0,2] ? false
    [1,0,0,1] is_alias [2,1,1,0] ? false
    [1,0,0,1] is_alias [2,1,1,1] ? false
    [1,0,0,1] is_alias [2,1,1,2] ? false
    [1,0,0,1] is_alias [2,1,2,0] ? false
    [1,0,0,1] is_alias [2,1,2,1] ? false
    [1,0,0,1] is_alias [2,1,2,2] ? false
    [1,0,0,1] is_alias [2,2,0,0] ? false
    [1,0,0,1] is_alias [2,2,0,1] ? false
    [1,0,0,1] is_alias [2,2,0,2] ? false
    [1,0,0,1] is_alias [2,2,1,0] ? false
    [1,0,0,1] is_alias [2,2,1,1] ? false
    [1,0,0,1] is_alias [2,2,1,2] ? false
    [1,0,0,1] is_alias [2,2,2,0] ? false
    [1,0,0,1] is_alias [2,2,2,1] ? false
    [1,0,0,1] is_alias [2,2,2,2] ? false
    [1,0,0,2] index has alias ? : true
    [1,0,0,2] is_alias [0,0,0,0] ? false
    [1,0,0,2] is_alias [0,0,0,1] ? false
    [1,0,0,2] is_alias [0,0,0,2] ? false
    [1,0,0,2] is_alias [0,0,1,0] ? false
    [1,0,0,2] is_alias [0,0,1,1] ? false
    [1,0,0,2] is_alias [0,0,1,2] ? false
    [1,0,0,2] is_alias [0,0,2,0] ? false
    [1,0,0,2] is_alias [0,0,2,1] ? false
    [1,0,0,2] is_alias [0,0,2,2] ? false
    [1,0,0,2] is_alias [0,1,0,0] ? false
    [1,0,0,2] is_alias [0,1,0,1] ? false
    [1,0,0,2] is_alias [0,1,0,2] ? true
    [1,0,0,2] is_alias [0,1,1,0] ? false
    [1,0,0,2] is_alias [0,1,1,1] ? false
    [1,0,0,2] is_alias [0,1,1,2] ? false
    [1,0,0,2] is_alias [0,1,2,0] ? true
    [1,0,0,2] is_alias [0,1,2,1] ? false
    [1,0,0,2] is_alias [0,1,2,2] ? false
    [1,0,0,2] is_alias [0,2,0,0] ? false
    [1,0,0,2] is_alias [0,2,0,1] ? true
    [1,0,0,2] is_alias [0,2,0,2] ? false
    [1,0,0,2] is_alias [0,2,1,0] ? true
    [1,0,0,2] is_alias [0,2,1,1] ? false
    [1,0,0,2] is_alias [0,2,1,2] ? false
    [1,0,0,2] is_alias [0,2,2,0] ? false
    [1,0,0,2] is_alias [0,2,2,1] ? false
    [1,0,0,2] is_alias [0,2,2,2] ? false
    [1,0,0,2] is_alias [1,0,0,0] ? false
    [1,0,0,2] is_alias [1,0,0,1] ? false
    [1,0,0,2] is_alias [1,0,0,2] ? false
    [1,0,0,2] is_alias [1,0,1,0] ? false
    [1,0,0,2] is_alias [1,0,1,1] ? false
    [1,0,0,2] is_alias [1,0,1,2] ? false
    [1,0,0,2] is_alias [1,0,2,0] ? true
    [1,0,0,2] is_alias [1,0,2,1] ? false
    [1,0,0,2] is_alias [1,0,2,2] ? false
    [1,0,0,2] is_alias [1,1,0,0] ? false
    [1,0,0,2] is_alias [1,1,0,1] ? false
    [1,0,0,2] is_alias [1,1,0,2] ? false
    [1,0,0,2] is_alias [1,1,1,0] ? false
    [1,0,0,2] is_alias [1,1,1,1] ? false
    [1,0,0,2] is_alias [1,1,1,2] ? false
    [1,0,0,2] is_alias [1,1,2,0] ? false
    [1,0,0,2] is_alias [1,1,2,1] ? false
    [1,0,0,2] is_alias [1,1,2,2] ? false
    [1,0,0,2] is_alias [1,2,0,0] ? false
    [1,0,0,2] is_alias [1,2,0,1] ? false
    [1,0,0,2] is_alias [1,2,0,2] ? false
    [1,0,0,2] is_alias [1,2,1,0] ? false
    [1,0,0,2] is_alias [1,2,1,1] ? false
    [1,0,0,2] is_alias [1,2,1,2] ? false
    [1,0,0,2] is_alias [1,2,2,0] ? false
    [1,0,0,2] is_alias [1,2,2,1] ? false
    [1,0,0,2] is_alias [1,2,2,2] ? false
    [1,0,0,2] is_alias [2,0,0,0] ? false
    [1,0,0,2] is_alias [2,0,0,1] ? true
    [1,0,0,2] is_alias [2,0,0,2] ? false
    [1,0,0,2] is_alias [2,0,1,0] ? true
    [1,0,0,2] is_alias [2,0,1,1] ? false
    [1,0,0,2] is_alias [2,0,1,2] ? false
    [1,0,0,2] is_alias [2,0,2,0] ? false
    [1,0,0,2] is_alias [2,0,2,1] ? false
    [1,0,0,2] is_alias [2,0,2,2] ? false
    [1,0,0,2] is_alias [2,1,0,0] ? false
    [1,0,0,2] is_alias [2,1,0,1] ? false
    [1,0,0,2] is_alias [2,1,0,2] ? false
    [1,0,0,2] is_alias [2,1,1,0] ? false
    [1,0,0,2] is_alias [2,1,1,1] ? false
    [1,0,0,2] is_alias [2,1,1,2] ? false
    [1,0,0,2] is_alias [2,1,2,0] ? false
    [1,0,0,2] is_alias [2,1,2,1] ? false
    [1,0,0,2] is_alias [2,1,2,2] ? false
    [1,0,0,2] is_alias [2,2,0,0] ? false
    [1,0,0,2] is_alias [2,2,0,1] ? false
    [1,0,0,2] is_alias [2,2,0,2] ? false
    [1,0,0,2] is_alias [2,2,1,0] ? false
    [1,0,0,2] is_alias [2,2,1,1] ? false
    [1,0,0,2] is_alias [2,2,1,2] ? false
    [1,0,0,2] is_alias [2,2,2,0] ? false
    [1,0,0,2] is_alias [2,2,2,1] ? false
    [1,0,0,2] is_alias [2,2,2,2] ? false
    [1,0,1,0] index has alias ? : true
    [1,0,1,0] is_alias [0,0,0,0] ? false
    [1,0,1,0] is_alias [0,0,0,1] ? false
    [1,0,1,0] is_alias [0,0,0,2] ? false
    [1,0,1,0] is_alias [0,0,1,0] ? false
    [1,0,1,0] is_alias [0,0,1,1] ? false
    [1,0,1,0] is_alias [0,0,1,2] ? false
    [1,0,1,0] is_alias [0,0,2,0] ? false
    [1,0,1,0] is_alias [0,0,2,1] ? false
    [1,0,1,0] is_alias [0,0,2,2] ? false
    [1,0,1,0] is_alias [0,1,0,0] ? false
    [1,0,1,0] is_alias [0,1,0,1] ? true
    [1,0,1,0] is_alias [0,1,0,2] ? false
    [1,0,1,0] is_alias [0,1,1,0] ? true
    [1,0,1,0] is_alias [0,1,1,1] ? false
    [1,0,1,0] is_alias [0,1,1,2] ? false
    [1,0,1,0] is_alias [0,1,2,0] ? false
    [1,0,1,0] is_alias [0,1,2,1] ? false
    [1,0,1,0] is_alias [0,1,2,2] ? false
    [1,0,1,0] is_alias [0,2,0,0] ? false
    [1,0,1,0] is_alias [0,2,0,1] ? false
    [1,0,1,0] is_alias [0,2,0,2] ? false
    [1,0,1,0] is_alias [0,2,1,0] ? false
    [1,0,1,0] is_alias [0,2,1,1] ? false
    [1,0,1,0] is_alias [0,2,1,2] ? false
    [1,0,1,0] is_alias [0,2,2,0] ? false
    [1,0,1,0] is_alias [0,2,2,1] ? false
    [1,0,1,0] is_alias [0,2,2,2] ? false
    [1,0,1,0] is_alias [1,0,0,0] ? false
    [1,0,1,0] is_alias [1,0,0,1] ? true
    [1,0,1,0] is_alias [1,0,0,2] ? false
    [1,0,1,0] is_alias [1,0,1,0] ? false
    [1,0,1,0] is_alias [1,0,1,1] ? false
    [1,0,1,0] is_alias [1,0,1,2] ? false
    [1,0,1,0] is_alias [1,0,2,0] ? false
    [1,0,1,0] is_alias [1,0,2,1] ? false
    [1,0,1,0] is_alias [1,0,2,2] ? false
    [1,0,1,0] is_alias [1,1,0,0] ? false
    [1,0,1,0] is_alias [1,1,0,1] ? false
    [1,0,1,0] is_alias [1,1,0,2] ? false
    [1,0,1,0] is_alias [1,1,1,0] ? false
    [1,0,1,0] is_alias [1,1,1,1] ? false
    [1,0,1,0] is_alias [1,1,1,2] ? false
    [1,0,1,0] is_alias [1,1,2,0] ? false
    [1,0,1,0] is_alias [1,1,2,1] ? false
    [1,0,1,0] is_alias [1,1,2,2] ? false
    [1,0,1,0] is_alias [1,2,0,0] ? false
    [1,0,1,0] is_alias [1,2,0,1] ? false
    [1,0,1,0] is_alias [1,2,0,2] ? false
    [1,0,1,0] is_alias [1,2,1,0] ? false
    [1,0,1,0] is_alias [1,2,1,1] ? false
    [1,0,1,0] is_alias [1,2,1,2] ? false
    [1,0,1,0] is_alias [1,2,2,0] ? false
    [1,0,1,0] is_alias [1,2,2,1] ? false
    [1,0,1,0] is_alias [1,2,2,2] ? false
    [1,0,1,0] is_alias [2,0,0,0] ? false
    [1,0,1,0] is_alias [2,0,0,1] ? false
    [1,0,1,0] is_alias [2,0,0,2] ? false
    [1,0,1,0] is_alias [2,0,1,0] ? false
    [1,0,1,0] is_alias [2,0,1,1] ? false
    [1,0,1,0] is_alias [2,0,1,2] ? false
    [1,0,1,0] is_alias [2,0,2,0] ? false
    [1,0,1,0] is_alias [2,0,2,1] ? false
    [1,0,1,0] is_alias [2,0,2,2] ? false
    [1,0,1,0] is_alias [2,1,0,0] ? false
    [1,0,1,0] is_alias [2,1,0,1] ? false
    [1,0,1,0] is_alias [2,1,0,2] ? false
    [1,0,1,0] is_alias [2,1,1,0] ? false
    [1,0,1,0] is_alias [2,1,1,1] ? false
    [1,0,1,0] is_alias [2,1,1,2] ? false
    [1,0,1,0] is_alias [2,1,2,0] ? false
    [1,0,1,0] is_alias [2,1,2,1] ? false
    [1,0,1,0] is_alias [2,1,2,2] ? false
    [1,0,1,0] is_alias [2,2,0,0] ? false
    [1,0,1,0] is_alias [2,2,0,1] ? false
    [1,0,1,0] is_alias [2,2,0,2] ? false
    [1,0,1,0] is_alias [2,2,1,0] ? false
    [1,0,1,0] is_alias [2,2,1,1] ? false
    [1,0,1,0] is_alias [2,2,1,2] ? false
    [1,0,1,0] is_alias [2,2,2,0] ? false
    [1,0,1,0] is_alias [2,2,2,1] ? false
    [1,0,1,0] is_alias [2,2,2,2] ? false
    [1,0,1,1] index has alias ? : true
    [1,0,1,1] is_alias [0,0,0,0] ? false
    [1,0,1,1] is_alias [0,0,0,1] ? false
    [1,0,1,1] is_alias [0,0,0,2] ? false
    [1,0,1,1] is_alias [0,0,1,0] ? false
    [1,0,1,1] is_alias [0,0,1,1] ? false
    [1,0,1,1] is_alias [0,0,1,2] ? false
    [1,0,1,1] is_alias [0,0,2,0] ? false
    [1,0,1,1] is_alias [0,0,2,1] ? false
    [1,0,1,1] is_alias [0,0,2,2] ? false
    [1,0,1,1] is_alias [0,1,0,0] ? false
    [1,0,1,1] is_alias [0,1,0,1] ? false
    [1,0,1,1] is_alias [0,1,0,2] ? false
    [1,0,1,1] is_alias [0,1,1,0] ? false
    [1,0,1,1] is_alias [0,1,1,1] ? true
    [1,0,1,1] is_alias [0,1,1,2] ? false
    [1,0,1,1] is_alias [0,1,2,0] ? false
    [1,0,1,1] is_alias [0,1,2,1] ? false
    [1,0,1,1] is_alias [0,1,2,2] ? false
    [1,0,1,1] is_alias [0,2,0,0] ? false
    [1,0,1,1] is_alias [0,2,0,1] ? false
    [1,0,1,1] is_alias [0,2,0,2] ? false
    [1,0,1,1] is_alias [0,2,1,0] ? false
    [1,0,1,1] is_alias [0,2,1,1] ? false
    [1,0,1,1] is_alias [0,2,1,2] ? false
    [1,0,1,1] is_alias [0,2,2,0] ? false
    [1,0,1,1] is_alias [0,2,2,1] ? false
    [1,0,1,1] is_alias [0,2,2,2] ? false
    [1,0,1,1] is_alias [1,0,0,0] ? false
    [1,0,1,1] is_alias [1,0,0,1] ? false
    [1,0,1,1] is_alias [1,0,0,2] ? false
    [1,0,1,1] is_alias [1,0,1,0] ? false
    [1,0,1,1] is_alias [1,0,1,1] ? false
    [1,0,1,1] is_alias [1,0,1,2] ? false
    [1,0,1,1] is_alias [1,0,2,0] ? false
    [1,0,1,1] is_alias [1,0,2,1] ? false
    [1,0,1,1] is_alias [1,0,2,2] ? false
    [1,0,1,1] is_alias [1,1,0,0] ? false
    [1,0,1,1] is_alias [1,1,0,1] ? true
    [1,0,1,1] is_alias [1,1,0,2] ? false
    [1,0,1,1] is_alias [1,1,1,0] ? true
    [1,0,1,1] is_alias [1,1,1,1] ? false
    [1,0,1,1] is_alias [1,1,1,2] ? false
    [1,0,1,1] is_alias [1,1,2,0] ? false
    [1,0,1,1] is_alias [1,1,2,1] ? false
    [1,0,1,1] is_alias [1,1,2,2] ? false
    [1,0,1,1] is_alias [1,2,0,0] ? false
    [1,0,1,1] is_alias [1,2,0,1] ? false
    [1,0,1,1] is_alias [1,2,0,2] ? false
    [1,0,1,1] is_alias [1,2,1,0] ? false
    [1,0,1,1] is_alias [1,2,1,1] ? false
    [1,0,1,1] is_alias [1,2,1,2] ? false
    [1,0,1,1] is_alias [1,2,2,0] ? false
    [1,0,1,1] is_alias [1,2,2,1] ? false
    [1,0,1,1] is_alias [1,2,2,2] ? false
    [1,0,1,1] is_alias [2,0,0,0] ? false
    [1,0,1,1] is_alias [2,0,0,1] ? false
    [1,0,1,1] is_alias [2,0,0,2] ? false
    [1,0,1,1] is_alias [2,0,1,0] ? false
    [1,0,1,1] is_alias [2,0,1,1] ? false
    [1,0,1,1] is_alias [2,0,1,2] ? false
    [1,0,1,1] is_alias [2,0,2,0] ? false
    [1,0,1,1] is_alias [2,0,2,1] ? false
    [1,0,1,1] is_alias [2,0,2,2] ? false
    [1,0,1,1] is_alias [2,1,0,0] ? false
    [1,0,1,1] is_alias [2,1,0,1] ? false
    [1,0,1,1] is_alias [2,1,0,2] ? false
    [1,0,1,1] is_alias [2,1,1,0] ? false
    [1,0,1,1] is_alias [2,1,1,1] ? false
    [1,0,1,1] is_alias [2,1,1,2] ? false
    [1,0,1,1] is_alias [2,1,2,0] ? false
    [1,0,1,1] is_alias [2,1,2,1] ? false
    [1,0,1,1] is_alias [2,1,2,2] ? false
    [1,0,1,1] is_alias [2,2,0,0] ? false
    [1,0,1,1] is_alias [2,2,0,1] ? false
    [1,0,1,1] is_alias [2,2,0,2] ? false
    [1,0,1,1] is_alias [2,2,1,0] ? false
    [1,0,1,1] is_alias [2,2,1,1] ? false
    [1,0,1,1] is_alias [2,2,1,2] ? false
    [1,0,1,1] is_alias [2,2,2,0] ? false
    [1,0,1,1] is_alias [2,2,2,1] ? false
    [1,0,1,1] is_alias [2,2,2,2] ? false
    [1,0,1,2] index has alias ? : true
    [1,0,1,2] is_alias [0,0,0,0] ? false
    [1,0,1,2] is_alias [0,0,0,1] ? false
    [1,0,1,2] is_alias [0,0,0,2] ? false
    [1,0,1,2] is_alias [0,0,1,0] ? false
    [1,0,1,2] is_alias [0,0,1,1] ? false
    [1,0,1,2] is_alias [0,0,1,2] ? false
    [1,0,1,2] is_alias [0,0,2,0] ? false
    [1,0,1,2] is_alias [0,0,2,1] ? false
    [1,0,1,2] is_alias [0,0,2,2] ? false
    [1,0,1,2] is_alias [0,1,0,0] ? false
    [1,0,1,2] is_alias [0,1,0,1] ? false
    [1,0,1,2] is_alias [0,1,0,2] ? false
    [1,0,1,2] is_alias [0,1,1,0] ? false
    [1,0,1,2] is_alias [0,1,1,1] ? false
    [1,0,1,2] is_alias [0,1,1,2] ? true
    [1,0,1,2] is_alias [0,1,2,0] ? false
    [1,0,1,2] is_alias [0,1,2,1] ? true
    [1,0,1,2] is_alias [0,1,2,2] ? false
    [1,0,1,2] is_alias [0,2,0,0] ? false
    [1,0,1,2] is_alias [0,2,0,1] ? false
    [1,0,1,2] is_alias [0,2,0,2] ? false
    [1,0,1,2] is_alias [0,2,1,0] ? false
    [1,0,1,2] is_alias [0,2,1,1] ? false
    [1,0,1,2] is_alias [0,2,1,2] ? false
    [1,0,1,2] is_alias [0,2,2,0] ? false
    [1,0,1,2] is_alias [0,2,2,1] ? false
    [1,0,1,2] is_alias [0,2,2,2] ? false
    [1,0,1,2] is_alias [1,0,0,0] ? false
    [1,0,1,2] is_alias [1,0,0,1] ? false
    [1,0,1,2] is_alias [1,0,0,2] ? false
    [1,0,1,2] is_alias [1,0,1,0] ? false
    [1,0,1,2] is_alias [1,0,1,1] ? false
    [1,0,1,2] is_alias [1,0,1,2] ? false
    [1,0,1,2] is_alias [1,0,2,0] ? false
    [1,0,1,2] is_alias [1,0,2,1] ? true
    [1,0,1,2] is_alias [1,0,2,2] ? false
    [1,0,1,2] is_alias [1,1,0,0] ? false
    [1,0,1,2] is_alias [1,1,0,1] ? false
    [1,0,1,2] is_alias [1,1,0,2] ? false
    [1,0,1,2] is_alias [1,1,1,0] ? false
    [1,0,1,2] is_alias [1,1,1,1] ? false
    [1,0,1,2] is_alias [1,1,1,2] ? false
    [1,0,1,2] is_alias [1,1,2,0] ? false
    [1,0,1,2] is_alias [1,1,2,1] ? false
    [1,0,1,2] is_alias [1,1,2,2] ? false
    [1,0,1,2] is_alias [1,2,0,0] ? false
    [1,0,1,2] is_alias [1,2,0,1] ? true
    [1,0,1,2] is_alias [1,2,0,2] ? false
    [1,0,1,2] is_alias [1,2,1,0] ? true
    [1,0,1,2] is_alias [1,2,1,1] ? false
    [1,0,1,2] is_alias [1,2,1,2] ? false
    [1,0,1,2] is_alias [1,2,2,0] ? false
    [1,0,1,2] is_alias [1,2,2,1] ? false
    [1,0,1,2] is_alias [1,2,2,2] ? false
    [1,0,1,2] is_alias [2,0,0,0] ? false
    [1,0,1,2] is_alias [2,0,0,1] ? false
    [1,0,1,2] is_alias [2,0,0,2] ? false
    [1,0,1,2] is_alias [2,0,1,0] ? false
    [1,0,1,2] is_alias [2,0,1,1] ? false
    [1,0,1,2] is_alias [2,0,1,2] ? false
    [1,0,1,2] is_alias [2,0,2,0] ? false
    [1,0,1,2] is_alias [2,0,2,1] ? false
    [1,0,1,2] is_alias [2,0,2,2] ? false
    [1,0,1,2] is_alias [2,1,0,0] ? false
    [1,0,1,2] is_alias [2,1,0,1] ? true
    [1,0,1,2] is_alias [2,1,0,2] ? false
    [1,0,1,2] is_alias [2,1,1,0] ? true
    [1,0,1,2] is_alias [2,1,1,1] ? false
    [1,0,1,2] is_alias [2,1,1,2] ? false
    [1,0,1,2] is_alias [2,1,2,0] ? false
    [1,0,1,2] is_alias [2,1,2,1] ? false
    [1,0,1,2] is_alias [2,1,2,2] ? false
    [1,0,1,2] is_alias [2,2,0,0] ? false
    [1,0,1,2] is_alias [2,2,0,1] ? false
    [1,0,1,2] is_alias [2,2,0,2] ? false
    [1,0,1,2] is_alias [2,2,1,0] ? false
    [1,0,1,2] is_alias [2,2,1,1] ? false
    [1,0,1,2] is_alias [2,2,1,2] ? false
    [1,0,1,2] is_alias [2,2,2,0] ? false
    [1,0,1,2] is_alias [2,2,2,1] ? false
    [1,0,1,2] is_alias [2,2,2,2] ? false
    [1,0,2,0] index has alias ? : true
    [1,0,2,0] is_alias [0,0,0,0] ? false
    [1,0,2,0] is_alias [0,0,0,1] ? false
    [1,0,2,0] is_alias [0,0,0,2] ? false
    [1,0,2,0] is_alias [0,0,1,0] ? false
    [1,0,2,0] is_alias [0,0,1,1] ? false
    [1,0,2,0] is_alias [0,0,1,2] ? false
    [1,0,2,0] is_alias [0,0,2,0] ? false
    [1,0,2,0] is_alias [0,0,2,1] ? false
    [1,0,2,0] is_alias [0,0,2,2] ? false
    [1,0,2,0] is_alias [0,1,0,0] ? false
    [1,0,2,0] is_alias [0,1,0,1] ? false
    [1,0,2,0] is_alias [0,1,0,2] ? true
    [1,0,2,0] is_alias [0,1,1,0] ? false
    [1,0,2,0] is_alias [0,1,1,1] ? false
    [1,0,2,0] is_alias [0,1,1,2] ? false
    [1,0,2,0] is_alias [0,1,2,0] ? true
    [1,0,2,0] is_alias [0,1,2,1] ? false
    [1,0,2,0] is_alias [0,1,2,2] ? false
    [1,0,2,0] is_alias [0,2,0,0] ? false
    [1,0,2,0] is_alias [0,2,0,1] ? true
    [1,0,2,0] is_alias [0,2,0,2] ? false
    [1,0,2,0] is_alias [0,2,1,0] ? true
    [1,0,2,0] is_alias [0,2,1,1] ? false
    [1,0,2,0] is_alias [0,2,1,2] ? false
    [1,0,2,0] is_alias [0,2,2,0] ? false
    [1,0,2,0] is_alias [0,2,2,1] ? false
    [1,0,2,0] is_alias [0,2,2,2] ? false
    [1,0,2,0] is_alias [1,0,0,0] ? false
    [1,0,2,0] is_alias [1,0,0,1] ? false
    [1,0,2,0] is_alias [1,0,0,2] ? true
    [1,0,2,0] is_alias [1,0,1,0] ? false
    [1,0,2,0] is_alias [1,0,1,1] ? false
    [1,0,2,0] is_alias [1,0,1,2] ? false
    [1,0,2,0] is_alias [1,0,2,0] ? false
    [1,0,2,0] is_alias [1,0,2,1] ? false
    [1,0,2,0] is_alias [1,0,2,2] ? false
    [1,0,2,0] is_alias [1,1,0,0] ? false
    [1,0,2,0] is_alias [1,1,0,1] ? false
    [1,0,2,0] is_alias [1,1,0,2] ? false
    [1,0,2,0] is_alias [1,1,1,0] ? false
    [1,0,2,0] is_alias [1,1,1,1] ? false
    [1,0,2,0] is_alias [1,1,1,2] ? false
    [1,0,2,0] is_alias [1,1,2,0] ? false
    [1,0,2,0] is_alias [1,1,2,1] ? false
    [1,0,2,0] is_alias [1,1,2,2] ? false
    [1,0,2,0] is_alias [1,2,0,0] ? false
    [1,0,2,0] is_alias [1,2,0,1] ? false
    [1,0,2,0] is_alias [1,2,0,2] ? false
    [1,0,2,0] is_alias [1,2,1,0] ? false
    [1,0,2,0] is_alias [1,2,1,1] ? false
    [1,0,2,0] is_alias [1,2,1,2] ? false
    [1,0,2,0] is_alias [1,2,2,0] ? false
    [1,0,2,0] is_alias [1,2,2,1] ? false
    [1,0,2,0] is_alias [1,2,2,2] ? false
    [1,0,2,0] is_alias [2,0,0,0] ? false
    [1,0,2,0] is_alias [2,0,0,1] ? true
    [1,0,2,0] is_alias [2,0,0,2] ? false
    [1,0,2,0] is_alias [2,0,1,0] ? true
    [1,0,2,0] is_alias [2,0,1,1] ? false
    [1,0,2,0] is_alias [2,0,1,2] ? false
    [1,0,2,0] is_alias [2,0,2,0] ? false
    [1,0,2,0] is_alias [2,0,2,1] ? false
    [1,0,2,0] is_alias [2,0,2,2] ? false
    [1,0,2,0] is_alias [2,1,0,0] ? false
    [1,0,2,0] is_alias [2,1,0,1] ? false
    [1,0,2,0] is_alias [2,1,0,2] ? false
    [1,0,2,0] is_alias [2,1,1,0] ? false
    [1,0,2,0] is_alias [2,1,1,1] ? false
    [1,0,2,0] is_alias [2,1,1,2] ? false
    [1,0,2,0] is_alias [2,1,2,0] ? false
    [1,0,2,0] is_alias [2,1,2,1] ? false
    [1,0,2,0] is_alias [2,1,2,2] ? false
    [1,0,2,0] is_alias [2,2,0,0] ? false
    [1,0,2,0] is_alias [2,2,0,1] ? false
    [1,0,2,0] is_alias [2,2,0,2] ? false
    [1,0,2,0] is_alias [2,2,1,0] ? false
    [1,0,2,0] is_alias [2,2,1,1] ? false
    [1,0,2,0] is_alias [2,2,1,2] ? false
    [1,0,2,0] is_alias [2,2,2,0] ? false
    [1,0,2,0] is_alias [2,2,2,1] ? false
    [1,0,2,0] is_alias [2,2,2,2] ? false
    [1,0,2,1] index has alias ? : true
    [1,0,2,1] is_alias [0,0,0,0] ? false
    [1,0,2,1] is_alias [0,0,0,1] ? false
    [1,0,2,1] is_alias [0,0,0,2] ? false
    [1,0,2,1] is_alias [0,0,1,0] ? false
    [1,0,2,1] is_alias [0,0,1,1] ? false
    [1,0,2,1] is_alias [0,0,1,2] ? false
    [1,0,2,1] is_alias [0,0,2,0] ? false
    [1,0,2,1] is_alias [0,0,2,1] ? false
    [1,0,2,1] is_alias [0,0,2,2] ? false
    [1,0,2,1] is_alias [0,1,0,0] ? false
    [1,0,2,1] is_alias [0,1,0,1] ? false
    [1,0,2,1] is_alias [0,1,0,2] ? false
    [1,0,2,1] is_alias [0,1,1,0] ? false
    [1,0,2,1] is_alias [0,1,1,1] ? false
    [1,0,2,1] is_alias [0,1,1,2] ? true
    [1,0,2,1] is_alias [0,1,2,0] ? false
    [1,0,2,1] is_alias [0,1,2,1] ? true
    [1,0,2,1] is_alias [0,1,2,2] ? false
    [1,0,2,1] is_alias [0,2,0,0] ? false
    [1,0,2,1] is_alias [0,2,0,1] ? false
    [1,0,2,1] is_alias [0,2,0,2] ? false
    [1,0,2,1] is_alias [0,2,1,0] ? false
    [1,0,2,1] is_alias [0,2,1,1] ? false
    [1,0,2,1] is_alias [0,2,1,2] ? false
    [1,0,2,1] is_alias [0,2,2,0] ? false
    [1,0,2,1] is_alias [0,2,2,1] ? false
    [1,0,2,1] is_alias [0,2,2,2] ? false
    [1,0,2,1] is_alias [1,0,0,0] ? false
    [1,0,2,1] is_alias [1,0,0,1] ? false
    [1,0,2,1] is_alias [1,0,0,2] ? false
    [1,0,2,1] is_alias [1,0,1,0] ? false
    [1,0,2,1] is_alias [1,0,1,1] ? false
    [1,0,2,1] is_alias [1,0,1,2] ? true
    [1,0,2,1] is_alias [1,0,2,0] ? false
    [1,0,2,1] is_alias [1,0,2,1] ? false
    [1,0,2,1] is_alias [1,0,2,2] ? false
    [1,0,2,1] is_alias [1,1,0,0] ? false
    [1,0,2,1] is_alias [1,1,0,1] ? false
    [1,0,2,1] is_alias [1,1,0,2] ? false
    [1,0,2,1] is_alias [1,1,1,0] ? false
    [1,0,2,1] is_alias [1,1,1,1] ? false
    [1,0,2,1] is_alias [1,1,1,2] ? false
    [1,0,2,1] is_alias [1,1,2,0] ? false
    [1,0,2,1] is_alias [1,1,2,1] ? false
    [1,0,2,1] is_alias [1,1,2,2] ? false
    [1,0,2,1] is_alias [1,2,0,0] ? false
    [1,0,2,1] is_alias [1,2,0,1] ? true
    [1,0,2,1] is_alias [1,2,0,2] ? false
    [1,0,2,1] is_alias [1,2,1,0] ? true
    [1,0,2,1] is_alias [1,2,1,1] ? false
    [1,0,2,1] is_alias [1,2,1,2] ? false
    [1,0,2,1] is_alias [1,2,2,0] ? false
    [1,0,2,1] is_alias [1,2,2,1] ? false
    [1,0,2,1] is_alias [1,2,2,2] ? false
    [1,0,2,1] is_alias [2,0,0,0] ? false
    [1,0,2,1] is_alias [2,0,0,1] ? false
    [1,0,2,1] is_alias [2,0,0,2] ? false
    [1,0,2,1] is_alias [2,0,1,0] ? false
    [1,0,2,1] is_alias [2,0,1,1] ? false
    [1,0,2,1] is_alias [2,0,1,2] ? false
    [1,0,2,1] is_alias [2,0,2,0] ? false
    [1,0,2,1] is_alias [2,0,2,1] ? false
    [1,0,2,1] is_alias [2,0,2,2] ? false
    [1,0,2,1] is_alias [2,1,0,0] ? false
    [1,0,2,1] is_alias [2,1,0,1] ? true
    [1,0,2,1] is_alias [2,1,0,2] ? false
    [1,0,2,1] is_alias [2,1,1,0] ? true
    [1,0,2,1] is_alias [2,1,1,1] ? false
    [1,0,2,1] is_alias [2,1,1,2] ? false
    [1,0,2,1] is_alias [2,1,2,0] ? false
    [1,0,2,1] is_alias [2,1,2,1] ? false
    [1,0,2,1] is_alias [2,1,2,2] ? false
    [1,0,2,1] is_alias [2,2,0,0] ? false
    [1,0,2,1] is_alias [2,2,0,1] ? false
    [1,0,2,1] is_alias [2,2,0,2] ? false
    [1,0,2,1] is_alias [2,2,1,0] ? false
    [1,0,2,1] is_alias [2,2,1,1] ? false
    [1,0,2,1] is_alias [2,2,1,2] ? false
    [1,0,2,1] is_alias [2,2,2,0] ? false
    [1,0,2,1] is_alias [2,2,2,1] ? false
    [1,0,2,1] is_alias [2,2,2,2] ? false
    [1,0,2,2] index has alias ? : true
    [1,0,2,2] is_alias [0,0,0,0] ? false
    [1,0,2,2] is_alias [0,0,0,1] ? false
    [1,0,2,2] is_alias [0,0,0,2] ? false
    [1,0,2,2] is_alias [0,0,1,0] ? false
    [1,0,2,2] is_alias [0,0,1,1] ? false
    [1,0,2,2] is_alias [0,0,1,2] ? false
    [1,0,2,2] is_alias [0,0,2,0] ? false
    [1,0,2,2] is_alias [0,0,2,1] ? false
    [1,0,2,2] is_alias [0,0,2,2] ? false
    [1,0,2,2] is_alias [0,1,0,0] ? false
    [1,0,2,2] is_alias [0,1,0,1] ? false
    [1,0,2,2] is_alias [0,1,0,2] ? false
    [1,0,2,2] is_alias [0,1,1,0] ? false
    [1,0,2,2] is_alias [0,1,1,1] ? false
    [1,0,2,2] is_alias [0,1,1,2] ? false
    [1,0,2,2] is_alias [0,1,2,0] ? false
    [1,0,2,2] is_alias [0,1,2,1] ? false
    [1,0,2,2] is_alias [0,1,2,2] ? true
    [1,0,2,2] is_alias [0,2,0,0] ? false
    [1,0,2,2] is_alias [0,2,0,1] ? false
    [1,0,2,2] is_alias [0,2,0,2] ? false
    [1,0,2,2] is_alias [0,2,1,0] ? false
    [1,0,2,2] is_alias [0,2,1,1] ? false
    [1,0,2,2] is_alias [0,2,1,2] ? false
    [1,0,2,2] is_alias [0,2,2,0] ? false
    [1,0,2,2] is_alias [0,2,2,1] ? false
    [1,0,2,2] is_alias [0,2,2,2] ? false
    [1,0,2,2] is_alias [1,0,0,0] ? false
    [1,0,2,2] is_alias [1,0,0,1] ? false
    [1,0,2,2] is_alias [1,0,0,2] ? false
    [1,0,2,2] is_alias [1,0,1,0] ? false
    [1,0,2,2] is_alias [1,0,1,1] ? false
    [1,0,2,2] is_alias [1,0,1,2] ? false
    [1,0,2,2] is_alias [1,0,2,0] ? false
    [1,0,2,2] is_alias [1,0,2,1] ? false
    [1,0,2,2] is_alias [1,0,2,2] ? false
    [1,0,2,2] is_alias [1,1,0,0] ? false
    [1,0,2,2] is_alias [1,1,0,1] ? false
    [1,0,2,2] is_alias [1,1,0,2] ? false
    [1,0,2,2] is_alias [1,1,1,0] ? false
    [1,0,2,2] is_alias [1,1,1,1] ? false
    [1,0,2,2] is_alias [1,1,1,2] ? false
    [1,0,2,2] is_alias [1,1,2,0] ? false
    [1,0,2,2] is_alias [1,1,2,1] ? false
    [1,0,2,2] is_alias [1,1,2,2] ? false
    [1,0,2,2] is_alias [1,2,0,0] ? false
    [1,0,2,2] is_alias [1,2,0,1] ? false
    [1,0,2,2] is_alias [1,2,0,2] ? false
    [1,0,2,2] is_alias [1,2,1,0] ? false
    [1,0,2,2] is_alias [1,2,1,1] ? false
    [1,0,2,2] is_alias [1,2,1,2] ? false
    [1,0,2,2] is_alias [1,2,2,0] ? false
    [1,0,2,2] is_alias [1,2,2,1] ? false
    [1,0,2,2] is_alias [1,2,2,2] ? false
    [1,0,2,2] is_alias [2,0,0,0] ? false
    [1,0,2,2] is_alias [2,0,0,1] ? false
    [1,0,2,2] is_alias [2,0,0,2] ? false
    [1,0,2,2] is_alias [2,0,1,0] ? false
    [1,0,2,2] is_alias [2,0,1,1] ? false
    [1,0,2,2] is_alias [2,0,1,2] ? false
    [1,0,2,2] is_alias [2,0,2,0] ? false
    [1,0,2,2] is_alias [2,0,2,1] ? false
    [1,0,2,2] is_alias [2,0,2,2] ? false
    [1,0,2,2] is_alias [2,1,0,0] ? false
    [1,0,2,2] is_alias [2,1,0,1] ? false
    [1,0,2,2] is_alias [2,1,0,2] ? false
    [1,0,2,2] is_alias [2,1,1,0] ? false
    [1,0,2,2] is_alias [2,1,1,1] ? false
    [1,0,2,2] is_alias [2,1,1,2] ? false
    [1,0,2,2] is_alias [2,1,2,0] ? false
    [1,0,2,2] is_alias [2,1,2,1] ? false
    [1,0,2,2] is_alias [2,1,2,2] ? false
    [1,0,2,2] is_alias [2,2,0,0] ? false
    [1,0,2,2] is_alias [2,2,0,1] ? true
    [1,0,2,2] is_alias [2,2,0,2] ? false
    [1,0,2,2] is_alias [2,2,1,0] ? true
    [1,0,2,2] is_alias [2,2,1,1] ? false
    [1,0,2,2] is_alias [2,2,1,2] ? false
    [1,0,2,2] is_alias [2,2,2,0] ? false
    [1,0,2,2] is_alias [2,2,2,1] ? false
    [1,0,2,2] is_alias [2,2,2,2] ? false
    [1,1,0,0] index has alias ? : true
    [1,1,0,0] is_alias [0,0,0,0] ? false
    [1,1,0,0] is_alias [0,0,0,1] ? false
    [1,1,0,0] is_alias [0,0,0,2] ? false
    [1,1,0,0] is_alias [0,0,1,0] ? false
    [1,1,0,0] is_alias [0,0,1,1] ? true
    [1,1,0,0] is_alias [0,0,1,2] ? false
    [1,1,0,0] is_alias [0,0,2,0] ? false
    [1,1,0,0] is_alias [0,0,2,1] ? false
    [1,1,0,0] is_alias [0,0,2,2] ? false
    [1,1,0,0] is_alias [0,1,0,0] ? false
    [1,1,0,0] is_alias [0,1,0,1] ? false
    [1,1,0,0] is_alias [0,1,0,2] ? false
    [1,1,0,0] is_alias [0,1,1,0] ? false
    [1,1,0,0] is_alias [0,1,1,1] ? false
    [1,1,0,0] is_alias [0,1,1,2] ? false
    [1,1,0,0] is_alias [0,1,2,0] ? false
    [1,1,0,0] is_alias [0,1,2,1] ? false
    [1,1,0,0] is_alias [0,1,2,2] ? false
    [1,1,0,0] is_alias [0,2,0,0] ? false
    [1,1,0,0] is_alias [0,2,0,1] ? false
    [1,1,0,0] is_alias [0,2,0,2] ? false
    [1,1,0,0] is_alias [0,2,1,0] ? false
    [1,1,0,0] is_alias [0,2,1,1] ? false
    [1,1,0,0] is_alias [0,2,1,2] ? false
    [1,1,0,0] is_alias [0,2,2,0] ? false
    [1,1,0,0] is_alias [0,2,2,1] ? false
    [1,1,0,0] is_alias [0,2,2,2] ? false
    [1,1,0,0] is_alias [1,0,0,0] ? false
    [1,1,0,0] is_alias [1,0,0,1] ? false
    [1,1,0,0] is_alias [1,0,0,2] ? false
    [1,1,0,0] is_alias [1,0,1,0] ? false
    [1,1,0,0] is_alias [1,0,1,1] ? false
    [1,1,0,0] is_alias [1,0,1,2] ? false
    [1,1,0,0] is_alias [1,0,2,0] ? false
    [1,1,0,0] is_alias [1,0,2,1] ? false
    [1,1,0,0] is_alias [1,0,2,2] ? false
    [1,1,0,0] is_alias [1,1,0,0] ? false
    [1,1,0,0] is_alias [1,1,0,1] ? false
    [1,1,0,0] is_alias [1,1,0,2] ? false
    [1,1,0,0] is_alias [1,1,1,0] ? false
    [1,1,0,0] is_alias [1,1,1,1] ? false
    [1,1,0,0] is_alias [1,1,1,2] ? false
    [1,1,0,0] is_alias [1,1,2,0] ? false
    [1,1,0,0] is_alias [1,1,2,1] ? false
    [1,1,0,0] is_alias [1,1,2,2] ? false
    [1,1,0,0] is_alias [1,2,0,0] ? false
    [1,1,0,0] is_alias [1,2,0,1] ? false
    [1,1,0,0] is_alias [1,2,0,2] ? false
    [1,1,0,0] is_alias [1,2,1,0] ? false
    [1,1,0,0] is_alias [1,2,1,1] ? false
    [1,1,0,0] is_alias [1,2,1,2] ? false
    [1,1,0,0] is_alias [1,2,2,0] ? false
    [1,1,0,0] is_alias [1,2,2,1] ? false
    [1,1,0,0] is_alias [1,2,2,2] ? false
    [1,1,0,0] is_alias [2,0,0,0] ? false
    [1,1,0,0] is_alias [2,0,0,1] ? false
    [1,1,0,0] is_alias [2,0,0,2] ? false
    [1,1,0,0] is_alias [2,0,1,0] ? false
    [1,1,0,0] is_alias [2,0,1,1] ? false
    [1,1,0,0] is_alias [2,0,1,2] ? false
    [1,1,0,0] is_alias [2,0,2,0] ? false
    [1,1,0,0] is_alias [2,0,2,1] ? false
    [1,1,0,0] is_alias [2,0,2,2] ? false
    [1,1,0,0] is_alias [2,1,0,0] ? false
    [1,1,0,0] is_alias [2,1,0,1] ? false
    [1,1,0,0] is_alias [2,1,0,2] ? false
    [1,1,0,0] is_alias [2,1,1,0] ? false
    [1,1,0,0] is_alias [2,1,1,1] ? false
    [1,1,0,0] is_alias [2,1,1,2] ? false
    [1,1,0,0] is_alias [2,1,2,0] ? false
    [1,1,0,0] is_alias [2,1,2,1] ? false
    [1,1,0,0] is_alias [2,1,2,2] ? false
    [1,1,0,0] is_alias [2,2,0,0] ? false
    [1,1,0,0] is_alias [2,2,0,1] ? false
    [1,1,0,0] is_alias [2,2,0,2] ? false
    [1,1,0,0] is_alias [2,2,1,0] ? false
    [1,1,0,0] is_alias [2,2,1,1] ? false
    [1,1,0,0] is_alias [2,2,1,2] ? false
    [1,1,0,0] is_alias [2,2,2,0] ? false
    [1,1,0,0] is_alias [2,2,2,1] ? false
    [1,1,0,0] is_alias [2,2,2,2] ? false
    [1,1,0,1] index has alias ? : true
    [1,1,0,1] is_alias [0,0,0,0] ? false
    [1,1,0,1] is_alias [0,0,0,1] ? false
    [1,1,0,1] is_alias [0,0,0,2] ? false
    [1,1,0,1] is_alias [0,0,1,0] ? false
    [1,1,0,1] is_alias [0,0,1,1] ? false
    [1,1,0,1] is_alias [0,0,1,2] ? false
    [1,1,0,1] is_alias [0,0,2,0] ? false
    [1,1,0,1] is_alias [0,0,2,1] ? false
    [1,1,0,1] is_alias [0,0,2,2] ? false
    [1,1,0,1] is_alias [0,1,0,0] ? false
    [1,1,0,1] is_alias [0,1,0,1] ? false
    [1,1,0,1] is_alias [0,1,0,2] ? false
    [1,1,0,1] is_alias [0,1,1,0] ? false
    [1,1,0,1] is_alias [0,1,1,1] ? true
    [1,1,0,1] is_alias [0,1,1,2] ? false
    [1,1,0,1] is_alias [0,1,2,0] ? false
    [1,1,0,1] is_alias [0,1,2,1] ? false
    [1,1,0,1] is_alias [0,1,2,2] ? false
    [1,1,0,1] is_alias [0,2,0,0] ? false
    [1,1,0,1] is_alias [0,2,0,1] ? false
    [1,1,0,1] is_alias [0,2,0,2] ? false
    [1,1,0,1] is_alias [0,2,1,0] ? false
    [1,1,0,1] is_alias [0,2,1,1] ? false
    [1,1,0,1] is_alias [0,2,1,2] ? false
    [1,1,0,1] is_alias [0,2,2,0] ? false
    [1,1,0,1] is_alias [0,2,2,1] ? false
    [1,1,0,1] is_alias [0,2,2,2] ? false
    [1,1,0,1] is_alias [1,0,0,0] ? false
    [1,1,0,1] is_alias [1,0,0,1] ? false
    [1,1,0,1] is_alias [1,0,0,2] ? false
    [1,1,0,1] is_alias [1,0,1,0] ? false
    [1,1,0,1] is_alias [1,0,1,1] ? true
    [1,1,0,1] is_alias [1,0,1,2] ? false
    [1,1,0,1] is_alias [1,0,2,0] ? false
    [1,1,0,1] is_alias [1,0,2,1] ? false
    [1,1,0,1] is_alias [1,0,2,2] ? false
    [1,1,0,1] is_alias [1,1,0,0] ? false
    [1,1,0,1] is_alias [1,1,0,1] ? false
    [1,1,0,1] is_alias [1,1,0,2] ? false
    [1,1,0,1] is_alias [1,1,1,0] ? true
    [1,1,0,1] is_alias [1,1,1,1] ? false
    [1,1,0,1] is_alias [1,1,1,2] ? false
    [1,1,0,1] is_alias [1,1,2,0] ? false
    [1,1,0,1] is_alias [1,1,2,1] ? false
    [1,1,0,1] is_alias [1,1,2,2] ? false
    [1,1,0,1] is_alias [1,2,0,0] ? false
    [1,1,0,1] is_alias [1,2,0,1] ? false
    [1,1,0,1] is_alias [1,2,0,2] ? false
    [1,1,0,1] is_alias [1,2,1,0] ? false
    [1,1,0,1] is_alias [1,2,1,1] ? false
    [1,1,0,1] is_alias [1,2,1,2] ? false
    [1,1,0,1] is_alias [1,2,2,0] ? false
    [1,1,0,1] is_alias [1,2,2,1] ? false
    [1,1,0,1] is_alias [1,2,2,2] ? false
    [1,1,0,1] is_alias [2,0,0,0] ? false
    [1,1,0,1] is_alias [2,0,0,1] ? false
    [1,1,0,1] is_alias [2,0,0,2] ? false
    [1,1,0,1] is_alias [2,0,1,0] ? false
    [1,1,0,1] is_alias [2,0,1,1] ? false
    [1,1,0,1] is_alias [2,0,1,2] ? false
    [1,1,0,1] is_alias [2,0,2,0] ? false
    [1,1,0,1] is_alias [2,0,2,1] ? false
    [1,1,0,1] is_alias [2,0,2,2] ? false
    [1,1,0,1] is_alias [2,1,0,0] ? false
    [1,1,0,1] is_alias [2,1,0,1] ? false
    [1,1,0,1] is_alias [2,1,0,2] ? false
    [1,1,0,1] is_alias [2,1,1,0] ? false
    [1,1,0,1] is_alias [2,1,1,1] ? false
    [1,1,0,1] is_alias [2,1,1,2] ? false
    [1,1,0,1] is_alias [2,1,2,0] ? false
    [1,1,0,1] is_alias [2,1,2,1] ? false
    [1,1,0,1] is_alias [2,1,2,2] ? false
    [1,1,0,1] is_alias [2,2,0,0] ? false
    [1,1,0,1] is_alias [2,2,0,1] ? false
    [1,1,0,1] is_alias [2,2,0,2] ? false
    [1,1,0,1] is_alias [2,2,1,0] ? false
    [1,1,0,1] is_alias [2,2,1,1] ? false
    [1,1,0,1] is_alias [2,2,1,2] ? false
    [1,1,0,1] is_alias [2,2,2,0] ? false
    [1,1,0,1] is_alias [2,2,2,1] ? false
    [1,1,0,1] is_alias [2,2,2,2] ? false
    [1,1,0,2] index has alias ? : true
    [1,1,0,2] is_alias [0,0,0,0] ? false
    [1,1,0,2] is_alias [0,0,0,1] ? false
    [1,1,0,2] is_alias [0,0,0,2] ? false
    [1,1,0,2] is_alias [0,0,1,0] ? false
    [1,1,0,2] is_alias [0,0,1,1] ? false
    [1,1,0,2] is_alias [0,0,1,2] ? false
    [1,1,0,2] is_alias [0,0,2,0] ? false
    [1,1,0,2] is_alias [0,0,2,1] ? false
    [1,1,0,2] is_alias [0,0,2,2] ? false
    [1,1,0,2] is_alias [0,1,0,0] ? false
    [1,1,0,2] is_alias [0,1,0,1] ? false
    [1,1,0,2] is_alias [0,1,0,2] ? false
    [1,1,0,2] is_alias [0,1,1,0] ? false
    [1,1,0,2] is_alias [0,1,1,1] ? false
    [1,1,0,2] is_alias [0,1,1,2] ? false
    [1,1,0,2] is_alias [0,1,2,0] ? false
    [1,1,0,2] is_alias [0,1,2,1] ? false
    [1,1,0,2] is_alias [0,1,2,2] ? false
    [1,1,0,2] is_alias [0,2,0,0] ? false
    [1,1,0,2] is_alias [0,2,0,1] ? false
    [1,1,0,2] is_alias [0,2,0,2] ? false
    [1,1,0,2] is_alias [0,2,1,0] ? false
    [1,1,0,2] is_alias [0,2,1,1] ? true
    [1,1,0,2] is_alias [0,2,1,2] ? false
    [1,1,0,2] is_alias [0,2,2,0] ? false
    [1,1,0,2] is_alias [0,2,2,1] ? false
    [1,1,0,2] is_alias [0,2,2,2] ? false
    [1,1,0,2] is_alias [1,0,0,0] ? false
    [1,1,0,2] is_alias [1,0,0,1] ? false
    [1,1,0,2] is_alias [1,0,0,2] ? false
    [1,1,0,2] is_alias [1,0,1,0] ? false
    [1,1,0,2] is_alias [1,0,1,1] ? false
    [1,1,0,2] is_alias [1,0,1,2] ? false
    [1,1,0,2] is_alias [1,0,2,0] ? false
    [1,1,0,2] is_alias [1,0,2,1] ? false
    [1,1,0,2] is_alias [1,0,2,2] ? false
    [1,1,0,2] is_alias [1,1,0,0] ? false
    [1,1,0,2] is_alias [1,1,0,1] ? false
    [1,1,0,2] is_alias [1,1,0,2] ? false
    [1,1,0,2] is_alias [1,1,1,0] ? false
    [1,1,0,2] is_alias [1,1,1,1] ? false
    [1,1,0,2] is_alias [1,1,1,2] ? false
    [1,1,0,2] is_alias [1,1,2,0] ? true
    [1,1,0,2] is_alias [1,1,2,1] ? false
    [1,1,0,2] is_alias [1,1,2,2] ? false
    [1,1,0,2] is_alias [1,2,0,0] ? false
    [1,1,0,2] is_alias [1,2,0,1] ? false
    [1,1,0,2] is_alias [1,2,0,2] ? false
    [1,1,0,2] is_alias [1,2,1,0] ? false
    [1,1,0,2] is_alias [1,2,1,1] ? false
    [1,1,0,2] is_alias [1,2,1,2] ? false
    [1,1,0,2] is_alias [1,2,2,0] ? false
    [1,1,0,2] is_alias [1,2,2,1] ? false
    [1,1,0,2] is_alias [1,2,2,2] ? false
    [1,1,0,2] is_alias [2,0,0,0] ? false
    [1,1,0,2] is_alias [2,0,0,1] ? false
    [1,1,0,2] is_alias [2,0,0,2] ? false
    [1,1,0,2] is_alias [2,0,1,0] ? false
    [1,1,0,2] is_alias [2,0,1,1] ? true
    [1,1,0,2] is_alias [2,0,1,2] ? false
    [1,1,0,2] is_alias [2,0,2,0] ? false
    [1,1,0,2] is_alias [2,0,2,1] ? false
    [1,1,0,2] is_alias [2,0,2,2] ? false
    [1,1,0,2] is_alias [2,1,0,0] ? false
    [1,1,0,2] is_alias [2,1,0,1] ? false
    [1,1,0,2] is_alias [2,1,0,2] ? false
    [1,1,0,2] is_alias [2,1,1,0] ? false
    [1,1,0,2] is_alias [2,1,1,1] ? false
    [1,1,0,2] is_alias [2,1,1,2] ? false
    [1,1,0,2] is_alias [2,1,2,0] ? false
    [1,1,0,2] is_alias [2,1,2,1] ? false
    [1,1,0,2] is_alias [2,1,2,2] ? false
    [1,1,0,2] is_alias [2,2,0,0] ? false
    [1,1,0,2] is_alias [2,2,0,1] ? false
    [1,1,0,2] is_alias [2,2,0,2] ? false
    [1,1,0,2] is_alias [2,2,1,0] ? false
    [1,1,0,2] is_alias [2,2,1,1] ? false
    [1,1,0,2] is_alias [2,2,1,2] ? false
    [1,1,0,2] is_alias [2,2,2,0] ? false
    [1,1,0,2] is_alias [2,2,2,1] ? false
    [1,1,0,2] is_alias [2,2,2,2] ? false
    [1,1,1,0] index has alias ? : true
    [1,1,1,0] is_alias [0,0,0,0] ? false
    [1,1,1,0] is_alias [0,0,0,1] ? false
    [1,1,1,0] is_alias [0,0,0,2] ? false
    [1,1,1,0] is_alias [0,0,1,0] ? false
    [1,1,1,0] is_alias [0,0,1,1] ? false
    [1,1,1,0] is_alias [0,0,1,2] ? false
    [1,1,1,0] is_alias [0,0,2,0] ? false
    [1,1,1,0] is_alias [0,0,2,1] ? false
    [1,1,1,0] is_alias [0,0,2,2] ? false
    [1,1,1,0] is_alias [0,1,0,0] ? false
    [1,1,1,0] is_alias [0,1,0,1] ? false
    [1,1,1,0] is_alias [0,1,0,2] ? false
    [1,1,1,0] is_alias [0,1,1,0] ? false
    [1,1,1,0] is_alias [0,1,1,1] ? true
    [1,1,1,0] is_alias [0,1,1,2] ? false
    [1,1,1,0] is_alias [0,1,2,0] ? false
    [1,1,1,0] is_alias [0,1,2,1] ? false
    [1,1,1,0] is_alias [0,1,2,2] ? false
    [1,1,1,0] is_alias [0,2,0,0] ? false
    [1,1,1,0] is_alias [0,2,0,1] ? false
    [1,1,1,0] is_alias [0,2,0,2] ? false
    [1,1,1,0] is_alias [0,2,1,0] ? false
    [1,1,1,0] is_alias [0,2,1,1] ? false
    [1,1,1,0] is_alias [0,2,1,2] ? false
    [1,1,1,0] is_alias [0,2,2,0] ? false
    [1,1,1,0] is_alias [0,2,2,1] ? false
    [1,1,1,0] is_alias [0,2,2,2] ? false
    [1,1,1,0] is_alias [1,0,0,0] ? false
    [1,1,1,0] is_alias [1,0,0,1] ? false
    [1,1,1,0] is_alias [1,0,0,2] ? false
    [1,1,1,0] is_alias [1,0,1,0] ? false
    [1,1,1,0] is_alias [1,0,1,1] ? true
    [1,1,1,0] is_alias [1,0,1,2] ? false
    [1,1,1,0] is_alias [1,0,2,0] ? false
    [1,1,1,0] is_alias [1,0,2,1] ? false
    [1,1,1,0] is_alias [1,0,2,2] ? false
    [1,1,1,0] is_alias [1,1,0,0] ? false
    [1,1,1,0] is_alias [1,1,0,1] ? true
    [1,1,1,0] is_alias [1,1,0,2] ? false
    [1,1,1,0] is_alias [1,1,1,0] ? false
    [1,1,1,0] is_alias [1,1,1,1] ? false
    [1,1,1,0] is_alias [1,1,1,2] ? false
    [1,1,1,0] is_alias [1,1,2,0] ? false
    [1,1,1,0] is_alias [1,1,2,1] ? false
    [1,1,1,0] is_alias [1,1,2,2] ? false
    [1,1,1,0] is_alias [1,2,0,0] ? false
    [1,1,1,0] is_alias [1,2,0,1] ? false
    [1,1,1,0] is_alias [1,2,0,2] ? false
    [1,1,1,0] is_alias [1,2,1,0] ? false
    [1,1,1,0] is_alias [1,2,1,1] ? false
    [1,1,1,0] is_alias [1,2,1,2] ? false
    [1,1,1,0] is_alias [1,2,2,0] ? false
    [1,1,1,0] is_alias [1,2,2,1] ? false
    [1,1,1,0] is_alias [1,2,2,2] ? false
    [1,1,1,0] is_alias [2,0,0,0] ? false
    [1,1,1,0] is_alias [2,0,0,1] ? false
    [1,1,1,0] is_alias [2,0,0,2] ? false
    [1,1,1,0] is_alias [2,0,1,0] ? false
    [1,1,1,0] is_alias [2,0,1,1] ? false
    [1,1,1,0] is_alias [2,0,1,2] ? false
    [1,1,1,0] is_alias [2,0,2,0] ? false
    [1,1,1,0] is_alias [2,0,2,1] ? false
    [1,1,1,0] is_alias [2,0,2,2] ? false
    [1,1,1,0] is_alias [2,1,0,0] ? false
    [1,1,1,0] is_alias [2,1,0,1] ? false
    [1,1,1,0] is_alias [2,1,0,2] ? false
    [1,1,1,0] is_alias [2,1,1,0] ? false
    [1,1,1,0] is_alias [2,1,1,1] ? false
    [1,1,1,0] is_alias [2,1,1,2] ? false
    [1,1,1,0] is_alias [2,1,2,0] ? false
    [1,1,1,0] is_alias [2,1,2,1] ? false
    [1,1,1,0] is_alias [2,1,2,2] ? false
    [1,1,1,0] is_alias [2,2,0,0] ? false
    [1,1,1,0] is_alias [2,2,0,1] ? false
    [1,1,1,0] is_alias [2,2,0,2] ? false
    [1,1,1,0] is_alias [2,2,1,0] ? false
    [1,1,1,0] is_alias [2,2,1,1] ? false
    [1,1,1,0] is_alias [2,2,1,2] ? false
    [1,1,1,0] is_alias [2,2,2,0] ? false
    [1,1,1,0] is_alias [2,2,2,1] ? false
    [1,1,1,0] is_alias [2,2,2,2] ? false
    [1,1,1,1] index has alias ? : false
    [1,1,1,1] is_alias [0,0,0,0] ? false
    [1,1,1,1] is_alias [0,0,0,1] ? false
    [1,1,1,1] is_alias [0,0,0,2] ? false
    [1,1,1,1] is_alias [0,0,1,0] ? false
    [1,1,1,1] is_alias [0,0,1,1] ? false
    [1,1,1,1] is_alias [0,0,1,2] ? false
    [1,1,1,1] is_alias [0,0,2,0] ? false
    [1,1,1,1] is_alias [0,0,2,1] ? false
    [1,1,1,1] is_alias [0,0,2,2] ? false
    [1,1,1,1] is_alias [0,1,0,0] ? false
    [1,1,1,1] is_alias [0,1,0,1] ? false
    [1,1,1,1] is_alias [0,1,0,2] ? false
    [1,1,1,1] is_alias [0,1,1,0] ? false
    [1,1,1,1] is_alias [0,1,1,1] ? false
    [1,1,1,1] is_alias [0,1,1,2] ? false
    [1,1,1,1] is_alias [0,1,2,0] ? false
    [1,1,1,1] is_alias [0,1,2,1] ? false
    [1,1,1,1] is_alias [0,1,2,2] ? false
    [1,1,1,1] is_alias [0,2,0,0] ? false
    [1,1,1,1] is_alias [0,2,0,1] ? false
    [1,1,1,1] is_alias [0,2,0,2] ? false
    [1,1,1,1] is_alias [0,2,1,0] ? false
    [1,1,1,1] is_alias [0,2,1,1] ? false
    [1,1,1,1] is_alias [0,2,1,2] ? false
    [1,1,1,1] is_alias [0,2,2,0] ? false
    [1,1,1,1] is_alias [0,2,2,1] ? false
    [1,1,1,1] is_alias [0,2,2,2] ? false
    [1,1,1,1] is_alias [1,0,0,0] ? false
    [1,1,1,1] is_alias [1,0,0,1] ? false
    [1,1,1,1] is_alias [1,0,0,2] ? false
    [1,1,1,1] is_alias [1,0,1,0] ? false
    [1,1,1,1] is_alias [1,0,1,1] ? false
    [1,1,1,1] is_alias [1,0,1,2] ? false
    [1,1,1,1] is_alias [1,0,2,0] ? false
    [1,1,1,1] is_alias [1,0,2,1] ? false
    [1,1,1,1] is_alias [1,0,2,2] ? false
    [1,1,1,1] is_alias [1,1,0,0] ? false
    [1,1,1,1] is_alias [1,1,0,1] ? false
    [1,1,1,1] is_alias [1,1,0,2] ? false
    [1,1,1,1] is_alias [1,1,1,0] ? false
    [1,1,1,1] is_alias [1,1,1,1] ? false
    [1,1,1,1] is_alias [1,1,1,2] ? false
    [1,1,1,1] is_alias [1,1,2,0] ? false
    [1,1,1,1] is_alias [1,1,2,1] ? false
    [1,1,1,1] is_alias [1,1,2,2] ? false
    [1,1,1,1] is_alias [1,2,0,0] ? false
    [1,1,1,1] is_alias [1,2,0,1] ? false
    [1,1,1,1] is_alias [1,2,0,2] ? false
    [1,1,1,1] is_alias [1,2,1,0] ? false
    [1,1,1,1] is_alias [1,2,1,1] ? false
    [1,1,1,1] is_alias [1,2,1,2] ? false
    [1,1,1,1] is_alias [1,2,2,0] ? false
    [1,1,1,1] is_alias [1,2,2,1] ? false
    [1,1,1,1] is_alias [1,2,2,2] ? false
    [1,1,1,1] is_alias [2,0,0,0] ? false
    [1,1,1,1] is_alias [2,0,0,1] ? false
    [1,1,1,1] is_alias [2,0,0,2] ? false
    [1,1,1,1] is_alias [2,0,1,0] ? false
    [1,1,1,1] is_alias [2,0,1,1] ? false
    [1,1,1,1] is_alias [2,0,1,2] ? false
    [1,1,1,1] is_alias [2,0,2,0] ? false
    [1,1,1,1] is_alias [2,0,2,1] ? false
    [1,1,1,1] is_alias [2,0,2,2] ? false
    [1,1,1,1] is_alias [2,1,0,0] ? false
    [1,1,1,1] is_alias [2,1,0,1] ? false
    [1,1,1,1] is_alias [2,1,0,2] ? false
    [1,1,1,1] is_alias [2,1,1,0] ? false
    [1,1,1,1] is_alias [2,1,1,1] ? false
    [1,1,1,1] is_alias [2,1,1,2] ? false
    [1,1,1,1] is_alias [2,1,2,0] ? false
    [1,1,1,1] is_alias [2,1,2,1] ? false
    [1,1,1,1] is_alias [2,1,2,2] ? false
    [1,1,1,1] is_alias [2,2,0,0] ? false
    [1,1,1,1] is_alias [2,2,0,1] ? false
    [1,1,1,1] is_alias [2,2,0,2] ? false
    [1,1,1,1] is_alias [2,2,1,0] ? false
    [1,1,1,1] is_alias [2,2,1,1] ? false
    [1,1,1,1] is_alias [2,2,1,2] ? false
    [1,1,1,1] is_alias [2,2,2,0] ? false
    [1,1,1,1] is_alias [2,2,2,1] ? false
    [1,1,1,1] is_alias [2,2,2,2] ? false
    [1,1,1,2] index has alias ? : true
    [1,1,1,2] is_alias [0,0,0,0] ? false
    [1,1,1,2] is_alias [0,0,0,1] ? false
    [1,1,1,2] is_alias [0,0,0,2] ? false
    [1,1,1,2] is_alias [0,0,1,0] ? false
    [1,1,1,2] is_alias [0,0,1,1] ? false
    [1,1,1,2] is_alias [0,0,1,2] ? false
    [1,1,1,2] is_alias [0,0,2,0] ? false
    [1,1,1,2] is_alias [0,0,2,1] ? false
    [1,1,1,2] is_alias [0,0,2,2] ? false
    [1,1,1,2] is_alias [0,1,0,0] ? false
    [1,1,1,2] is_alias [0,1,0,1] ? false
    [1,1,1,2] is_alias [0,1,0,2] ? false
    [1,1,1,2] is_alias [0,1,1,0] ? false
    [1,1,1,2] is_alias [0,1,1,1] ? false
    [1,1,1,2] is_alias [0,1,1,2] ? false
    [1,1,1,2] is_alias [0,1,2,0] ? false
    [1,1,1,2] is_alias [0,1,2,1] ? false
    [1,1,1,2] is_alias [0,1,2,2] ? false
    [1,1,1,2] is_alias [0,2,0,0] ? false
    [1,1,1,2] is_alias [0,2,0,1] ? false
    [1,1,1,2] is_alias [0,2,0,2] ? false
    [1,1,1,2] is_alias [0,2,1,0] ? false
    [1,1,1,2] is_alias [0,2,1,1] ? false
    [1,1,1,2] is_alias [0,2,1,2] ? false
    [1,1,1,2] is_alias [0,2,2,0] ? false
    [1,1,1,2] is_alias [0,2,2,1] ? false
    [1,1,1,2] is_alias [0,2,2,2] ? false
    [1,1,1,2] is_alias [1,0,0,0] ? false
    [1,1,1,2] is_alias [1,0,0,1] ? false
    [1,1,1,2] is_alias [1,0,0,2] ? false
    [1,1,1,2] is_alias [1,0,1,0] ? false
    [1,1,1,2] is_alias [1,0,1,1] ? false
    [1,1,1,2] is_alias [1,0,1,2] ? false
    [1,1,1,2] is_alias [1,0,2,0] ? false
    [1,1,1,2] is_alias [1,0,2,1] ? false
    [1,1,1,2] is_alias [1,0,2,2] ? false
    [1,1,1,2] is_alias [1,1,0,0] ? false
    [1,1,1,2] is_alias [1,1,0,1] ? false
    [1,1,1,2] is_alias [1,1,0,2] ? false
    [1,1,1,2] is_alias [1,1,1,0] ? false
    [1,1,1,2] is_alias [1,1,1,1] ? false
    [1,1,1,2] is_alias [1,1,1,2] ? false
    [1,1,1,2] is_alias [1,1,2,0] ? false
    [1,1,1,2] is_alias [1,1,2,1] ? true
    [1,1,1,2] is_alias [1,1,2,2] ? false
    [1,1,1,2] is_alias [1,2,0,0] ? false
    [1,1,1,2] is_alias [1,2,0,1] ? false
    [1,1,1,2] is_alias [1,2,0,2] ? false
    [1,1,1,2] is_alias [1,2,1,0] ? false
    [1,1,1,2] is_alias [1,2,1,1] ? true
    [1,1,1,2] is_alias [1,2,1,2] ? false
    [1,1,1,2] is_alias [1,2,2,0] ? false
    [1,1,1,2] is_alias [1,2,2,1] ? false
    [1,1,1,2] is_alias [1,2,2,2] ? false
    [1,1,1,2] is_alias [2,0,0,0] ? false
    [1,1,1,2] is_alias [2,0,0,1] ? false
    [1,1,1,2] is_alias [2,0,0,2] ? false
    [1,1,1,2] is_alias [2,0,1,0] ? false
    [1,1,1,2] is_alias [2,0,1,1] ? false
    [1,1,1,2] is_alias [2,0,1,2] ? false
    [1,1,1,2] is_alias [2,0,2,0] ? false
    [1,1,1,2] is_alias [2,0,2,1] ? false
    [1,1,1,2] is_alias [2,0,2,2] ? false
    [1,1,1,2] is_alias [2,1,0,0] ? false
    [1,1,1,2] is_alias [2,1,0,1] ? false
    [1,1,1,2] is_alias [2,1,0,2] ? false
    [1,1,1,2] is_alias [2,1,1,0] ? false
    [1,1,1,2] is_alias [2,1,1,1] ? true
    [1,1,1,2] is_alias [2,1,1,2] ? false
    [1,1,1,2] is_alias [2,1,2,0] ? false
    [1,1,1,2] is_alias [2,1,2,1] ? false
    [1,1,1,2] is_alias [2,1,2,2] ? false
    [1,1,1,2] is_alias [2,2,0,0] ? false
    [1,1,1,2] is_alias [2,2,0,1] ? false
    [1,1,1,2] is_alias [2,2,0,2] ? false
    [1,1,1,2] is_alias [2,2,1,0] ? false
    [1,1,1,2] is_alias [2,2,1,1] ? false
    [1,1,1,2] is_alias [2,2,1,2] ? false
    [1,1,1,2] is_alias [2,2,2,0] ? false
    [1,1,1,2] is_alias [2,2,2,1] ? false
    [1,1,1,2] is_alias [2,2,2,2] ? false
    [1,1,2,0] index has alias ? : true
    [1,1,2,0] is_alias [0,0,0,0] ? false
    [1,1,2,0] is_alias [0,0,0,1] ? false
    [1,1,2,0] is_alias [0,0,0,2] ? false
    [1,1,2,0] is_alias [0,0,1,0] ? false
    [1,1,2,0] is_alias [0,0,1,1] ? false
    [1,1,2,0] is_alias [0,0,1,2] ? false
    [1,1,2,0] is_alias [0,0,2,0] ? false
    [1,1,2,0] is_alias [0,0,2,1] ? false
    [1,1,2,0] is_alias [0,0,2,2] ? false
    [1,1,2,0] is_alias [0,1,0,0] ? false
    [1,1,2,0] is_alias [0,1,0,1] ? false
    [1,1,2,0] is_alias [0,1,0,2] ? false
    [1,1,2,0] is_alias [0,1,1,0] ? false
    [1,1,2,0] is_alias [0,1,1,1] ? false
    [1,1,2,0] is_alias [0,1,1,2] ? false
    [1,1,2,0] is_alias [0,1,2,0] ? false
    [1,1,2,0] is_alias [0,1,2,1] ? false
    [1,1,2,0] is_alias [0,1,2,2] ? false
    [1,1,2,0] is_alias [0,2,0,0] ? false
    [1,1,2,0] is_alias [0,2,0,1] ? false
    [1,1,2,0] is_alias [0,2,0,2] ? false
    [1,1,2,0] is_alias [0,2,1,0] ? false
    [1,1,2,0] is_alias [0,2,1,1] ? true
    [1,1,2,0] is_alias [0,2,1,2] ? false
    [1,1,2,0] is_alias [0,2,2,0] ? false
    [1,1,2,0] is_alias [0,2,2,1] ? false
    [1,1,2,0] is_alias [0,2,2,2] ? false
    [1,1,2,0] is_alias [1,0,0,0] ? false
    [1,1,2,0] is_alias [1,0,0,1] ? false
    [1,1,2,0] is_alias [1,0,0,2] ? false
    [1,1,2,0] is_alias [1,0,1,0] ? false
    [1,1,2,0] is_alias [1,0,1,1] ? false
    [1,1,2,0] is_alias [1,0,1,2] ? false
    [1,1,2,0] is_alias [1,0,2,0] ? false
    [1,1,2,0] is_alias [1,0,2,1] ? false
    [1,1,2,0] is_alias [1,0,2,2] ? false
    [1,1,2,0] is_alias [1,1,0,0] ? false
    [1,1,2,0] is_alias [1,1,0,1] ? false
    [1,1,2,0] is_alias [1,1,0,2] ? true
    [1,1,2,0] is_alias [1,1,1,0] ? false
    [1,1,2,0] is_alias [1,1,1,1] ? false
    [1,1,2,0] is_alias [1,1,1,2] ? false
    [1,1,2,0] is_alias [1,1,2,0] ? false
    [1,1,2,0] is_alias [1,1,2,1] ? false
    [1,1,2,0] is_alias [1,1,2,2] ? false
    [1,1,2,0] is_alias [1,2,0,0] ? false
    [1,1,2,0] is_alias [1,2,0,1] ? false
    [1,1,2,0] is_alias [1,2,0,2] ? false
    [1,1,2,0] is_alias [1,2,1,0] ? false
    [1,1,2,0] is_alias [1,2,1,1] ? false
    [1,1,2,0] is_alias [1,2,1,2] ? false
    [1,1,2,0] is_alias [1,2,2,0] ? false
    [1,1,2,0] is_alias [1,2,2,1] ? false
    [1,1,2,0] is_alias [1,2,2,2] ? false
    [1,1,2,0] is_alias [2,0,0,0] ? false
    [1,1,2,0] is_alias [2,0,0,1] ? false
    [1,1,2,0] is_alias [2,0,0,2] ? false
    [1,1,2,0] is_alias [2,0,1,0] ? false
    [1,1,2,0] is_alias [2,0,1,1] ? true
    [1,1,2,0] is_alias [2,0,1,2] ? false
    [1,1,2,0] is_alias [2,0,2,0] ? false
    [1,1,2,0] is_alias [2,0,2,1] ? false
    [1,1,2,0] is_alias [2,0,2,2] ? false
    [1,1,2,0] is_alias [2,1,0,0] ? false
    [1,1,2,0] is_alias [2,1,0,1] ? false
    [1,1,2,0] is_alias [2,1,0,2] ? false
    [1,1,2,0] is_alias [2,1,1,0] ? false
    [1,1,2,0] is_alias [2,1,1,1] ? false
    [1,1,2,0] is_alias [2,1,1,2] ? false
    [1,1,2,0] is_alias [2,1,2,0] ? false
    [1,1,2,0] is_alias [2,1,2,1] ? false
    [1,1,2,0] is_alias [2,1,2,2] ? false
    [1,1,2,0] is_alias [2,2,0,0] ? false
    [1,1,2,0] is_alias [2,2,0,1] ? false
    [1,1,2,0] is_alias [2,2,0,2] ? false
    [1,1,2,0] is_alias [2,2,1,0] ? false
    [1,1,2,0] is_alias [2,2,1,1] ? false
    [1,1,2,0] is_alias [2,2,1,2] ? false
    [1,1,2,0] is_alias [2,2,2,0] ? false
    [1,1,2,0] is_alias [2,2,2,1] ? false
    [1,1,2,0] is_alias [2,2,2,2] ? false
    [1,1,2,1] index has alias ? : true
    [1,1,2,1] is_alias [0,0,0,0] ? false
    [1,1,2,1] is_alias [0,0,0,1] ? false
    [1,1,2,1] is_alias [0,0,0,2] ? false
    [1,1,2,1] is_alias [0,0,1,0] ? false
    [1,1,2,1] is_alias [0,0,1,1] ? false
    [1,1,2,1] is_alias [0,0,1,2] ? false
    [1,1,2,1] is_alias [0,0,2,0] ? false
    [1,1,2,1] is_alias [0,0,2,1] ? false
    [1,1,2,1] is_alias [0,0,2,2] ? false
    [1,1,2,1] is_alias [0,1,0,0] ? false
    [1,1,2,1] is_alias [0,1,0,1] ? false
    [1,1,2,1] is_alias [0,1,0,2] ? false
    [1,1,2,1] is_alias [0,1,1,0] ? false
    [1,1,2,1] is_alias [0,1,1,1] ? false
    [1,1,2,1] is_alias [0,1,1,2] ? false
    [1,1,2,1] is_alias [0,1,2,0] ? false
    [1,1,2,1] is_alias [0,1,2,1] ? false
    [1,1,2,1] is_alias [0,1,2,2] ? false
    [1,1,2,1] is_alias [0,2,0,0] ? false
    [1,1,2,1] is_alias [0,2,0,1] ? false
    [1,1,2,1] is_alias [0,2,0,2] ? false
    [1,1,2,1] is_alias [0,2,1,0] ? false
    [1,1,2,1] is_alias [0,2,1,1] ? false
    [1,1,2,1] is_alias [0,2,1,2] ? false
    [1,1,2,1] is_alias [0,2,2,0] ? false
    [1,1,2,1] is_alias [0,2,2,1] ? false
    [1,1,2,1] is_alias [0,2,2,2] ? false
    [1,1,2,1] is_alias [1,0,0,0] ? false
    [1,1,2,1] is_alias [1,0,0,1] ? false
    [1,1,2,1] is_alias [1,0,0,2] ? false
    [1,1,2,1] is_alias [1,0,1,0] ? false
    [1,1,2,1] is_alias [1,0,1,1] ? false
    [1,1,2,1] is_alias [1,0,1,2] ? false
    [1,1,2,1] is_alias [1,0,2,0] ? false
    [1,1,2,1] is_alias [1,0,2,1] ? false
    [1,1,2,1] is_alias [1,0,2,2] ? false
    [1,1,2,1] is_alias [1,1,0,0] ? false
    [1,1,2,1] is_alias [1,1,0,1] ? false
    [1,1,2,1] is_alias [1,1,0,2] ? false
    [1,1,2,1] is_alias [1,1,1,0] ? false
    [1,1,2,1] is_alias [1,1,1,1] ? false
    [1,1,2,1] is_alias [1,1,1,2] ? true
    [1,1,2,1] is_alias [1,1,2,0] ? false
    [1,1,2,1] is_alias [1,1,2,1] ? false
    [1,1,2,1] is_alias [1,1,2,2] ? false
    [1,1,2,1] is_alias [1,2,0,0] ? false
    [1,1,2,1] is_alias [1,2,0,1] ? false
    [1,1,2,1] is_alias [1,2,0,2] ? false
    [1,1,2,1] is_alias [1,2,1,0] ? false
    [1,1,2,1] is_alias [1,2,1,1] ? true
    [1,1,2,1] is_alias [1,2,1,2] ? false
    [1,1,2,1] is_alias [1,2,2,0] ? false
    [1,1,2,1] is_alias [1,2,2,1] ? false
    [1,1,2,1] is_alias [1,2,2,2] ? false
    [1,1,2,1] is_alias [2,0,0,0] ? false
    [1,1,2,1] is_alias [2,0,0,1] ? false
    [1,1,2,1] is_alias [2,0,0,2] ? false
    [1,1,2,1] is_alias [2,0,1,0] ? false
    [1,1,2,1] is_alias [2,0,1,1] ? false
    [1,1,2,1] is_alias [2,0,1,2] ? false
    [1,1,2,1] is_alias [2,0,2,0] ? false
    [1,1,2,1] is_alias [2,0,2,1] ? false
    [1,1,2,1] is_alias [2,0,2,2] ? false
    [1,1,2,1] is_alias [2,1,0,0] ? false
    [1,1,2,1] is_alias [2,1,0,1] ? false
    [1,1,2,1] is_alias [2,1,0,2] ? false
    [1,1,2,1] is_alias [2,1,1,0] ? false
    [1,1,2,1] is_alias [2,1,1,1] ? true
    [1,1,2,1] is_alias [2,1,1,2] ? false
    [1,1,2,1] is_alias [2,1,2,0] ? false
    [1,1,2,1] is_alias [2,1,2,1] ? false
    [1,1,2,1] is_alias [2,1,2,2] ? false
    [1,1,2,1] is_alias [2,2,0,0] ? false
    [1,1,2,1] is_alias [2,2,0,1] ? false
    [1,1,2,1] is_alias [2,2,0,2] ? false
    [1,1,2,1] is_alias [2,2,1,0] ? false
    [1,1,2,1] is_alias [2,2,1,1] ? false
    [1,1,2,1] is_alias [2,2,1,2] ? false
    [1,1,2,1] is_alias [2,2,2,0] ? false
    [1,1,2,1] is_alias [2,2,2,1] ? false
    [1,1,2,1] is_alias [2,2,2,2] ? false
    [1,1,2,2] index has alias ? : true
    [1,1,2,2] is_alias [0,0,0,0] ? false
    [1,1,2,2] is_alias [0,0,0,1] ? false
    [1,1,2,2] is_alias [0,0,0,2] ? false
    [1,1,2,2] is_alias [0,0,1,0] ? false
    [1,1,2,2] is_alias [0,0,1,1] ? false
    [1,1,2,2] is_alias [0,0,1,2] ? false
    [1,1,2,2] is_alias [0,0,2,0] ? false
    [1,1,2,2] is_alias [0,0,2,1] ? false
    [1,1,2,2] is_alias [0,0,2,2] ? false
    [1,1,2,2] is_alias [0,1,0,0] ? false
    [1,1,2,2] is_alias [0,1,0,1] ? false
    [1,1,2,2] is_alias [0,1,0,2] ? false
    [1,1,2,2] is_alias [0,1,1,0] ? false
    [1,1,2,2] is_alias [0,1,1,1] ? false
    [1,1,2,2] is_alias [0,1,1,2] ? false
    [1,1,2,2] is_alias [0,1,2,0] ? false
    [1,1,2,2] is_alias [0,1,2,1] ? false
    [1,1,2,2] is_alias [0,1,2,2] ? false
    [1,1,2,2] is_alias [0,2,0,0] ? false
    [1,1,2,2] is_alias [0,2,0,1] ? false
    [1,1,2,2] is_alias [0,2,0,2] ? false
    [1,1,2,2] is_alias [0,2,1,0] ? false
    [1,1,2,2] is_alias [0,2,1,1] ? false
    [1,1,2,2] is_alias [0,2,1,2] ? false
    [1,1,2,2] is_alias [0,2,2,0] ? false
    [1,1,2,2] is_alias [0,2,2,1] ? false
    [1,1,2,2] is_alias [0,2,2,2] ? false
    [1,1,2,2] is_alias [1,0,0,0] ? false
    [1,1,2,2] is_alias [1,0,0,1] ? false
    [1,1,2,2] is_alias [1,0,0,2] ? false
    [1,1,2,2] is_alias [1,0,1,0] ? false
    [1,1,2,2] is_alias [1,0,1,1] ? false
    [1,1,2,2] is_alias [1,0,1,2] ? false
    [1,1,2,2] is_alias [1,0,2,0] ? false
    [1,1,2,2] is_alias [1,0,2,1] ? false
    [1,1,2,2] is_alias [1,0,2,2] ? false
    [1,1,2,2] is_alias [1,1,0,0] ? false
    [1,1,2,2] is_alias [1,1,0,1] ? false
    [1,1,2,2] is_alias [1,1,0,2] ? false
    [1,1,2,2] is_alias [1,1,1,0] ? false
    [1,1,2,2] is_alias [1,1,1,1] ? false
    [1,1,2,2] is_alias [1,1,1,2] ? false
    [1,1,2,2] is_alias [1,1,2,0] ? false
    [1,1,2,2] is_alias [1,1,2,1] ? false
    [1,1,2,2] is_alias [1,1,2,2] ? false
    [1,1,2,2] is_alias [1,2,0,0] ? false
    [1,1,2,2] is_alias [1,2,0,1] ? false
    [1,1,2,2] is_alias [1,2,0,2] ? false
    [1,1,2,2] is_alias [1,2,1,0] ? false
    [1,1,2,2] is_alias [1,2,1,1] ? false
    [1,1,2,2] is_alias [1,2,1,2] ? false
    [1,1,2,2] is_alias [1,2,2,0] ? false
    [1,1,2,2] is_alias [1,2,2,1] ? false
    [1,1,2,2] is_alias [1,2,2,2] ? false
    [1,1,2,2] is_alias [2,0,0,0] ? false
    [1,1,2,2] is_alias [2,0,0,1] ? false
    [1,1,2,2] is_alias [2,0,0,2] ? false
    [1,1,2,2] is_alias [2,0,1,0] ? false
    [1,1,2,2] is_alias [2,0,1,1] ? false
    [1,1,2,2] is_alias [2,0,1,2] ? false
    [1,1,2,2] is_alias [2,0,2,0] ? false
    [1,1,2,2] is_alias [2,0,2,1] ? false
    [1,1,2,2] is_alias [2,0,2,2] ? false
    [1,1,2,2] is_alias [2,1,0,0] ? false
    [1,1,2,2] is_alias [2,1,0,1] ? false
    [1,1,2,2] is_alias [2,1,0,2] ? false
    [1,1,2,2] is_alias [2,1,1,0] ? false
    [1,1,2,2] is_alias [2,1,1,1] ? false
    [1,1,2,2] is_alias [2,1,1,2] ? false
    [1,1,2,2] is_alias [2,1,2,0] ? false
    [1,1,2,2] is_alias [2,1,2,1] ? false
    [1,1,2,2] is_alias [2,1,2,2] ? false
    [1,1,2,2] is_alias [2,2,0,0] ? false
    [1,1,2,2] is_alias [2,2,0,1] ? false
    [1,1,2,2] is_alias [2,2,0,2] ? false
    [1,1,2,2] is_alias [2,2,1,0] ? false
    [1,1,2,2] is_alias [2,2,1,1] ? true
    [1,1,2,2] is_alias [2,2,1,2] ? false
    [1,1,2,2] is_alias [2,2,2,0] ? false
    [1,1,2,2] is_alias [2,2,2,1] ? false
    [1,1,2,2] is_alias [2,2,2,2] ? false
    [1,2,0,0] index has alias ? : true
    [1,2,0,0] is_alias [0,0,0,0] ? false
    [1,2,0,0] is_alias [0,0,0,1] ? false
    [1,2,0,0] is_alias [0,0,0,2] ? false
    [1,2,0,0] is_alias [0,0,1,0] ? false
    [1,2,0,0] is_alias [0,0,1,1] ? false
    [1,2,0,0] is_alias [0,0,1,2] ? true
    [1,2,0,0] is_alias [0,0,2,0] ? false
    [1,2,0,0] is_alias [0,0,2,1] ? true
    [1,2,0,0] is_alias [0,0,2,2] ? false
    [1,2,0,0] is_alias [0,1,0,0] ? false
    [1,2,0,0] is_alias [0,1,0,1] ? false
    [1,2,0,0] is_alias [0,1,0,2] ? false
    [1,2,0,0] is_alias [0,1,1,0] ? false
    [1,2,0,0] is_alias [0,1,1,1] ? false
    [1,2,0,0] is_alias [0,1,1,2] ? false
    [1,2,0,0] is_alias [0,1,2,0] ? false
    [1,2,0,0] is_alias [0,1,2,1] ? false
    [1,2,0,0] is_alias [0,1,2,2] ? false
    [1,2,0,0] is_alias [0,2,0,0] ? false
    [1,2,0,0] is_alias [0,2,0,1] ? false
    [1,2,0,0] is_alias [0,2,0,2] ? false
    [1,2,0,0] is_alias [0,2,1,0] ? false
    [1,2,0,0] is_alias [0,2,1,1] ? false
    [1,2,0,0] is_alias [0,2,1,2] ? false
    [1,2,0,0] is_alias [0,2,2,0] ? false
    [1,2,0,0] is_alias [0,2,2,1] ? false
    [1,2,0,0] is_alias [0,2,2,2] ? false
    [1,2,0,0] is_alias [1,0,0,0] ? false
    [1,2,0,0] is_alias [1,0,0,1] ? false
    [1,2,0,0] is_alias [1,0,0,2] ? false
    [1,2,0,0] is_alias [1,0,1,0] ? false
    [1,2,0,0] is_alias [1,0,1,1] ? false
    [1,2,0,0] is_alias [1,0,1,2] ? false
    [1,2,0,0] is_alias [1,0,2,0] ? false
    [1,2,0,0] is_alias [1,0,2,1] ? false
    [1,2,0,0] is_alias [1,0,2,2] ? false
    [1,2,0,0] is_alias [1,1,0,0] ? false
    [1,2,0,0] is_alias [1,1,0,1] ? false
    [1,2,0,0] is_alias [1,1,0,2] ? false
    [1,2,0,0] is_alias [1,1,1,0] ? false
    [1,2,0,0] is_alias [1,1,1,1] ? false
    [1,2,0,0] is_alias [1,1,1,2] ? false
    [1,2,0,0] is_alias [1,1,2,0] ? false
    [1,2,0,0] is_alias [1,1,2,1] ? false
    [1,2,0,0] is_alias [1,1,2,2] ? false
    [1,2,0,0] is_alias [1,2,0,0] ? false
    [1,2,0,0] is_alias [1,2,0,1] ? false
    [1,2,0,0] is_alias [1,2,0,2] ? false
    [1,2,0,0] is_alias [1,2,1,0] ? false
    [1,2,0,0] is_alias [1,2,1,1] ? false
    [1,2,0,0] is_alias [1,2,1,2] ? false
    [1,2,0,0] is_alias [1,2,2,0] ? false
    [1,2,0,0] is_alias [1,2,2,1] ? false
    [1,2,0,0] is_alias [1,2,2,2] ? false
    [1,2,0,0] is_alias [2,0,0,0] ? false
    [1,2,0,0] is_alias [2,0,0,1] ? false
    [1,2,0,0] is_alias [2,0,0,2] ? false
    [1,2,0,0] is_alias [2,0,1,0] ? false
    [1,2,0,0] is_alias [2,0,1,1] ? false
    [1,2,0,0] is_alias [2,0,1,2] ? false
    [1,2,0,0] is_alias [2,0,2,0] ? false
    [1,2,0,0] is_alias [2,0,2,1] ? false
    [1,2,0,0] is_alias [2,0,2,2] ? false
    [1,2,0,0] is_alias [2,1,0,0] ? true
    [1,2,0,0] is_alias [2,1,0,1] ? false
    [1,2,0,0] is_alias [2,1,0,2] ? false
    [1,2,0,0] is_alias [2,1,1,0] ? false
    [1,2,0,0] is_alias [2,1,1,1] ? false
    [1,2,0,0] is_alias [2,1,1,2] ? false
    [1,2,0,0] is_alias [2,1,2,0] ? false
    [1,2,0,0] is_alias [2,1,2,1] ? false
    [1,2,0,0] is_alias [2,1,2,2] ? false
    [1,2,0,0] is_alias [2,2,0,0] ? false
    [1,2,0,0] is_alias [2,2,0,1] ? false
    [1,2,0,0] is_alias [2,2,0,2] ? false
    [1,2,0,0] is_alias [2,2,1,0] ? false
    [1,2,0,0] is_alias [2,2,1,1] ? false
    [1,2,0,0] is_alias [2,2,1,2] ? false
    [1,2,0,0] is_alias [2,2,2,0] ? false
    [1,2,0,0] is_alias [2,2,2,1] ? false
    [1,2,0,0] is_alias [2,2,2,2] ? false
    [1,2,0,1] index has alias ? : true
    [1,2,0,1] is_alias [0,0,0,0] ? false
    [1,2,0,1] is_alias [0,0,0,1] ? false
    [1,2,0,1] is_alias [0,0,0,2] ? false
    [1,2,0,1] is_alias [0,0,1,0] ? false
    [1,2,0,1] is_alias [0,0,1,1] ? false
    [1,2,0,1] is_alias [0,0,1,2] ? false
    [1,2,0,1] is_alias [0,0,2,0] ? false
    [1,2,0,1] is_alias [0,0,2,1] ? false
    [1,2,0,1] is_alias [0,0,2,2] ? false
    [1,2,0,1] is_alias [0,1,0,0] ? false
    [1,2,0,1] is_alias [0,1,0,1] ? false
    [1,2,0,1] is_alias [0,1,0,2] ? false
    [1,2,0,1] is_alias [0,1,1,0] ? false
    [1,2,0,1] is_alias [0,1,1,1] ? false
    [1,2,0,1] is_alias [0,1,1,2] ? true
    [1,2,0,1] is_alias [0,1,2,0] ? false
    [1,2,0,1] is_alias [0,1,2,1] ? true
    [1,2,0,1] is_alias [0,1,2,2] ? false
    [1,2,0,1] is_alias [0,2,0,0] ? false
    [1,2,0,1] is_alias [0,2,0,1] ? false
    [1,2,0,1] is_alias [0,2,0,2] ? false
    [1,2,0,1] is_alias [0,2,1,0] ? false
    [1,2,0,1] is_alias [0,2,1,1] ? false
    [1,2,0,1] is_alias [0,2,1,2] ? false
    [1,2,0,1] is_alias [0,2,2,0] ? false
    [1,2,0,1] is_alias [0,2,2,1] ? false
    [1,2,0,1] is_alias [0,2,2,2] ? false
    [1,2,0,1] is_alias [1,0,0,0] ? false
    [1,2,0,1] is_alias [1,0,0,1] ? false
    [1,2,0,1] is_alias [1,0,0,2] ? false
    [1,2,0,1] is_alias [1,0,1,0] ? false
    [1,2,0,1] is_alias [1,0,1,1] ? false
    [1,2,0,1] is_alias [1,0,1,2] ? true
    [1,2,0,1] is_alias [1,0,2,0] ? false
    [1,2,0,1] is_alias [1,0,2,1] ? true
    [1,2,0,1] is_alias [1,0,2,2] ? false
    [1,2,0,1] is_alias [1,1,0,0] ? false
    [1,2,0,1] is_alias [1,1,0,1] ? false
    [1,2,0,1] is_alias [1,1,0,2] ? false
    [1,2,0,1] is_alias [1,1,1,0] ? false
    [1,2,0,1] is_alias [1,1,1,1] ? false
    [1,2,0,1] is_alias [1,1,1,2] ? false
    [1,2,0,1] is_alias [1,1,2,0] ? false
    [1,2,0,1] is_alias [1,1,2,1] ? false
    [1,2,0,1] is_alias [1,1,2,2] ? false
    [1,2,0,1] is_alias [1,2,0,0] ? false
    [1,2,0,1] is_alias [1,2,0,1] ? false
    [1,2,0,1] is_alias [1,2,0,2] ? false
    [1,2,0,1] is_alias [1,2,1,0] ? true
    [1,2,0,1] is_alias [1,2,1,1] ? false
    [1,2,0,1] is_alias [1,2,1,2] ? false
    [1,2,0,1] is_alias [1,2,2,0] ? false
    [1,2,0,1] is_alias [1,2,2,1] ? false
    [1,2,0,1] is_alias [1,2,2,2] ? false
    [1,2,0,1] is_alias [2,0,0,0] ? false
    [1,2,0,1] is_alias [2,0,0,1] ? false
    [1,2,0,1] is_alias [2,0,0,2] ? false
    [1,2,0,1] is_alias [2,0,1,0] ? false
    [1,2,0,1] is_alias [2,0,1,1] ? false
    [1,2,0,1] is_alias [2,0,1,2] ? false
    [1,2,0,1] is_alias [2,0,2,0] ? false
    [1,2,0,1] is_alias [2,0,2,1] ? false
    [1,2,0,1] is_alias [2,0,2,2] ? false
    [1,2,0,1] is_alias [2,1,0,0] ? false
    [1,2,0,1] is_alias [2,1,0,1] ? true
    [1,2,0,1] is_alias [2,1,0,2] ? false
    [1,2,0,1] is_alias [2,1,1,0] ? true
    [1,2,0,1] is_alias [2,1,1,1] ? false
    [1,2,0,1] is_alias [2,1,1,2] ? false
    [1,2,0,1] is_alias [2,1,2,0] ? false
    [1,2,0,1] is_alias [2,1,2,1] ? false
    [1,2,0,1] is_alias [2,1,2,2] ? false
    [1,2,0,1] is_alias [2,2,0,0] ? false
    [1,2,0,1] is_alias [2,2,0,1] ? false
    [1,2,0,1] is_alias [2,2,0,2] ? false
    [1,2,0,1] is_alias [2,2,1,0] ? false
    [1,2,0,1] is_alias [2,2,1,1] ? false
    [1,2,0,1] is_alias [2,2,1,2] ? false
    [1,2,0,1] is_alias [2,2,2,0] ? false
    [1,2,0,1] is_alias [2,2,2,1] ? false
    [1,2,0,1] is_alias [2,2,2,2] ? false
    [1,2,0,2] index has alias ? : true
    [1,2,0,2] is_alias [0,0,0,0] ? false
    [1,2,0,2] is_alias [0,0,0,1] ? false
    [1,2,0,2] is_alias [0,0,0,2] ? false
    [1,2,0,2] is_alias [0,0,1,0] ? false
    [1,2,0,2] is_alias [0,0,1,1] ? false
    [1,2,0,2] is_alias [0,0,1,2] ? false
    [1,2,0,2] is_alias [0,0,2,0] ? false
    [1,2,0,2] is_alias [0,0,2,1] ? false
    [1,2,0,2] is_alias [0,0,2,2] ? false
    [1,2,0,2] is_alias [0,1,0,0] ? false
    [1,2,0,2] is_alias [0,1,0,1] ? false
    [1,2,0,2] is_alias [0,1,0,2] ? false
    [1,2,0,2] is_alias [0,1,1,0] ? false
    [1,2,0,2] is_alias [0,1,1,1] ? false
    [1,2,0,2] is_alias [0,1,1,2] ? false
    [1,2,0,2] is_alias [0,1,2,0] ? false
    [1,2,0,2] is_alias [0,1,2,1] ? false
    [1,2,0,2] is_alias [0,1,2,2] ? false
    [1,2,0,2] is_alias [0,2,0,0] ? false
    [1,2,0,2] is_alias [0,2,0,1] ? false
    [1,2,0,2] is_alias [0,2,0,2] ? false
    [1,2,0,2] is_alias [0,2,1,0] ? false
    [1,2,0,2] is_alias [0,2,1,1] ? false
    [1,2,0,2] is_alias [0,2,1,2] ? true
    [1,2,0,2] is_alias [0,2,2,0] ? false
    [1,2,0,2] is_alias [0,2,2,1] ? true
    [1,2,0,2] is_alias [0,2,2,2] ? false
    [1,2,0,2] is_alias [1,0,0,0] ? false
    [1,2,0,2] is_alias [1,0,0,1] ? false
    [1,2,0,2] is_alias [1,0,0,2] ? false
    [1,2,0,2] is_alias [1,0,1,0] ? false
    [1,2,0,2] is_alias [1,0,1,1] ? false
    [1,2,0,2] is_alias [1,0,1,2] ? false
    [1,2,0,2] is_alias [1,0,2,0] ? false
    [1,2,0,2] is_alias [1,0,2,1] ? false
    [1,2,0,2] is_alias [1,0,2,2] ? false
    [1,2,0,2] is_alias [1,1,0,0] ? false
    [1,2,0,2] is_alias [1,1,0,1] ? false
    [1,2,0,2] is_alias [1,1,0,2] ? false
    [1,2,0,2] is_alias [1,1,1,0] ? false
    [1,2,0,2] is_alias [1,1,1,1] ? false
    [1,2,0,2] is_alias [1,1,1,2] ? false
    [1,2,0,2] is_alias [1,1,2,0] ? false
    [1,2,0,2] is_alias [1,1,2,1] ? false
    [1,2,0,2] is_alias [1,1,2,2] ? false
    [1,2,0,2] is_alias [1,2,0,0] ? false
    [1,2,0,2] is_alias [1,2,0,1] ? false
    [1,2,0,2] is_alias [1,2,0,2] ? false
    [1,2,0,2] is_alias [1,2,1,0] ? false
    [1,2,0,2] is_alias [1,2,1,1] ? false
    [1,2,0,2] is_alias [1,2,1,2] ? false
    [1,2,0,2] is_alias [1,2,2,0] ? true
    [1,2,0,2] is_alias [1,2,2,1] ? false
    [1,2,0,2] is_alias [1,2,2,2] ? false
    [1,2,0,2] is_alias [2,0,0,0] ? false
    [1,2,0,2] is_alias [2,0,0,1] ? false
    [1,2,0,2] is_alias [2,0,0,2] ? false
    [1,2,0,2] is_alias [2,0,1,0] ? false
    [1,2,0,2] is_alias [2,0,1,1] ? false
    [1,2,0,2] is_alias [2,0,1,2] ? true
    [1,2,0,2] is_alias [2,0,2,0] ? false
    [1,2,0,2] is_alias [2,0,2,1] ? true
    [1,2,0,2] is_alias [2,0,2,2] ? false
    [1,2,0,2] is_alias [2,1,0,0] ? false
    [1,2,0,2] is_alias [2,1,0,1] ? false
    [1,2,0,2] is_alias [2,1,0,2] ? true
    [1,2,0,2] is_alias [2,1,1,0] ? false
    [1,2,0,2] is_alias [2,1,1,1] ? false
    [1,2,0,2] is_alias [2,1,1,2] ? false
    [1,2,0,2] is_alias [2,1,2,0] ? true
    [1,2,0,2] is_alias [2,1,2,1] ? false
    [1,2,0,2] is_alias [2,1,2,2] ? false
    [1,2,0,2] is_alias [2,2,0,0] ? false
    [1,2,0,2] is_alias [2,2,0,1] ? false
    [1,2,0,2] is_alias [2,2,0,2] ? false
    [1,2,0,2] is_alias [2,2,1,0] ? false
    [1,2,0,2] is_alias [2,2,1,1] ? false
    [1,2,0,2] is_alias [2,2,1,2] ? false
    [1,2,0,2] is_alias [2,2,2,0] ? false
    [1,2,0,2] is_alias [2,2,2,1] ? false
    [1,2,0,2] is_alias [2,2,2,2] ? false
    [1,2,1,0] index has alias ? : true
    [1,2,1,0] is_alias [0,0,0,0] ? false
    [1,2,1,0] is_alias [0,0,0,1] ? false
    [1,2,1,0] is_alias [0,0,0,2] ? false
    [1,2,1,0] is_alias [0,0,1,0] ? false
    [1,2,1,0] is_alias [0,0,1,1] ? false
    [1,2,1,0] is_alias [0,0,1,2] ? false
    [1,2,1,0] is_alias [0,0,2,0] ? false
    [1,2,1,0] is_alias [0,0,2,1] ? false
    [1,2,1,0] is_alias [0,0,2,2] ? false
    [1,2,1,0] is_alias [0,1,0,0] ? false
    [1,2,1,0] is_alias [0,1,0,1] ? false
    [1,2,1,0] is_alias [0,1,0,2] ? false
    [1,2,1,0] is_alias [0,1,1,0] ? false
    [1,2,1,0] is_alias [0,1,1,1] ? false
    [1,2,1,0] is_alias [0,1,1,2] ? true
    [1,2,1,0] is_alias [0,1,2,0] ? false
    [1,2,1,0] is_alias [0,1,2,1] ? true
    [1,2,1,0] is_alias [0,1,2,2] ? false
    [1,2,1,0] is_alias [0,2,0,0] ? false
    [1,2,1,0] is_alias [0,2,0,1] ? false
    [1,2,1,0] is_alias [0,2,0,2] ? false
    [1,2,1,0] is_alias [0,2,1,0] ? false
    [1,2,1,0] is_alias [0,2,1,1] ? false
    [1,2,1,0] is_alias [0,2,1,2] ? false
    [1,2,1,0] is_alias [0,2,2,0] ? false
    [1,2,1,0] is_alias [0,2,2,1] ? false
    [1,2,1,0] is_alias [0,2,2,2] ? false
    [1,2,1,0] is_alias [1,0,0,0] ? false
    [1,2,1,0] is_alias [1,0,0,1] ? false
    [1,2,1,0] is_alias [1,0,0,2] ? false
    [1,2,1,0] is_alias [1,0,1,0] ? false
    [1,2,1,0] is_alias [1,0,1,1] ? false
    [1,2,1,0] is_alias [1,0,1,2] ? true
    [1,2,1,0] is_alias [1,0,2,0] ? false
    [1,2,1,0] is_alias [1,0,2,1] ? true
    [1,2,1,0] is_alias [1,0,2,2] ? false
    [1,2,1,0] is_alias [1,1,0,0] ? false
    [1,2,1,0] is_alias [1,1,0,1] ? false
    [1,2,1,0] is_alias [1,1,0,2] ? false
    [1,2,1,0] is_alias [1,1,1,0] ? false
    [1,2,1,0] is_alias [1,1,1,1] ? false
    [1,2,1,0] is_alias [1,1,1,2] ? false
    [1,2,1,0] is_alias [1,1,2,0] ? false
    [1,2,1,0] is_alias [1,1,2,1] ? false
    [1,2,1,0] is_alias [1,1,2,2] ? false
    [1,2,1,0] is_alias [1,2,0,0] ? false
    [1,2,1,0] is_alias [1,2,0,1] ? true
    [1,2,1,0] is_alias [1,2,0,2] ? false
    [1,2,1,0] is_alias [1,2,1,0] ? false
    [1,2,1,0] is_alias [1,2,1,1] ? false
    [1,2,1,0] is_alias [1,2,1,2] ? false
    [1,2,1,0] is_alias [1,2,2,0] ? false
    [1,2,1,0] is_alias [1,2,2,1] ? false
    [1,2,1,0] is_alias [1,2,2,2] ? false
    [1,2,1,0] is_alias [2,0,0,0] ? false
    [1,2,1,0] is_alias [2,0,0,1] ? false
    [1,2,1,0] is_alias [2,0,0,2] ? false
    [1,2,1,0] is_alias [2,0,1,0] ? false
    [1,2,1,0] is_alias [2,0,1,1] ? false
    [1,2,1,0] is_alias [2,0,1,2] ? false
    [1,2,1,0] is_alias [2,0,2,0] ? false
    [1,2,1,0] is_alias [2,0,2,1] ? false
    [1,2,1,0] is_alias [2,0,2,2] ? false
    [1,2,1,0] is_alias [2,1,0,0] ? false
    [1,2,1,0] is_alias [2,1,0,1] ? true
    [1,2,1,0] is_alias [2,1,0,2] ? false
    [1,2,1,0] is_alias [2,1,1,0] ? true
    [1,2,1,0] is_alias [2,1,1,1] ? false
    [1,2,1,0] is_alias [2,1,1,2] ? false
    [1,2,1,0] is_alias [2,1,2,0] ? false
    [1,2,1,0] is_alias [2,1,2,1] ? false
    [1,2,1,0] is_alias [2,1,2,2] ? false
    [1,2,1,0] is_alias [2,2,0,0] ? false
    [1,2,1,0] is_alias [2,2,0,1] ? false
    [1,2,1,0] is_alias [2,2,0,2] ? false
    [1,2,1,0] is_alias [2,2,1,0] ? false
    [1,2,1,0] is_alias [2,2,1,1] ? false
    [1,2,1,0] is_alias [2,2,1,2] ? false
    [1,2,1,0] is_alias [2,2,2,0] ? false
    [1,2,1,0] is_alias [2,2,2,1] ? false
    [1,2,1,0] is_alias [2,2,2,2] ? false
    [1,2,1,1] index has alias ? : true
    [1,2,1,1] is_alias [0,0,0,0] ? false
    [1,2,1,1] is_alias [0,0,0,1] ? false
    [1,2,1,1] is_alias [0,0,0,2] ? false
    [1,2,1,1] is_alias [0,0,1,0] ? false
    [1,2,1,1] is_alias [0,0,1,1] ? false
    [1,2,1,1] is_alias [0,0,1,2] ? false
    [1,2,1,1] is_alias [0,0,2,0] ? false
    [1,2,1,1] is_alias [0,0,2,1] ? false
    [1,2,1,1] is_alias [0,0,2,2] ? false
    [1,2,1,1] is_alias [0,1,0,0] ? false
    [1,2,1,1] is_alias [0,1,0,1] ? false
    [1,2,1,1] is_alias [0,1,0,2] ? false
    [1,2,1,1] is_alias [0,1,1,0] ? false
    [1,2,1,1] is_alias [0,1,1,1] ? false
    [1,2,1,1] is_alias [0,1,1,2] ? false
    [1,2,1,1] is_alias [0,1,2,0] ? false
    [1,2,1,1] is_alias [0,1,2,1] ? false
    [1,2,1,1] is_alias [0,1,2,2] ? false
    [1,2,1,1] is_alias [0,2,0,0] ? false
    [1,2,1,1] is_alias [0,2,0,1] ? false
    [1,2,1,1] is_alias [0,2,0,2] ? false
    [1,2,1,1] is_alias [0,2,1,0] ? false
    [1,2,1,1] is_alias [0,2,1,1] ? false
    [1,2,1,1] is_alias [0,2,1,2] ? false
    [1,2,1,1] is_alias [0,2,2,0] ? false
    [1,2,1,1] is_alias [0,2,2,1] ? false
    [1,2,1,1] is_alias [0,2,2,2] ? false
    [1,2,1,1] is_alias [1,0,0,0] ? false
    [1,2,1,1] is_alias [1,0,0,1] ? false
    [1,2,1,1] is_alias [1,0,0,2] ? false
    [1,2,1,1] is_alias [1,0,1,0] ? false
    [1,2,1,1] is_alias [1,0,1,1] ? false
    [1,2,1,1] is_alias [1,0,1,2] ? false
    [1,2,1,1] is_alias [1,0,2,0] ? false
    [1,2,1,1] is_alias [1,0,2,1] ? false
    [1,2,1,1] is_alias [1,0,2,2] ? false
    [1,2,1,1] is_alias [1,1,0,0] ? false
    [1,2,1,1] is_alias [1,1,0,1] ? false
    [1,2,1,1] is_alias [1,1,0,2] ? false
    [1,2,1,1] is_alias [1,1,1,0] ? false
    [1,2,1,1] is_alias [1,1,1,1] ? false
    [1,2,1,1] is_alias [1,1,1,2] ? true
    [1,2,1,1] is_alias [1,1,2,0] ? false
    [1,2,1,1] is_alias [1,1,2,1] ? true
    [1,2,1,1] is_alias [1,1,2,2] ? false
    [1,2,1,1] is_alias [1,2,0,0] ? false
    [1,2,1,1] is_alias [1,2,0,1] ? false
    [1,2,1,1] is_alias [1,2,0,2] ? false
    [1,2,1,1] is_alias [1,2,1,0] ? false
    [1,2,1,1] is_alias [1,2,1,1] ? false
    [1,2,1,1] is_alias [1,2,1,2] ? false
    [1,2,1,1] is_alias [1,2,2,0] ? false
    [1,2,1,1] is_alias [1,2,2,1] ? false
    [1,2,1,1] is_alias [1,2,2,2] ? false
    [1,2,1,1] is_alias [2,0,0,0] ? false
    [1,2,1,1] is_alias [2,0,0,1] ? false
    [1,2,1,1] is_alias [2,0,0,2] ? false
    [1,2,1,1] is_alias [2,0,1,0] ? false
    [1,2,1,1] is_alias [2,0,1,1] ? false
    [1,2,1,1] is_alias [2,0,1,2] ? false
    [1,2,1,1] is_alias [2,0,2,0] ? false
    [1,2,1,1] is_alias [2,0,2,1] ? false
    [1,2,1,1] is_alias [2,0,2,2] ? false
    [1,2,1,1] is_alias [2,1,0,0] ? false
    [1,2,1,1] is_alias [2,1,0,1] ? false
    [1,2,1,1] is_alias [2,1,0,2] ? false
    [1,2,1,1] is_alias [2,1,1,0] ? false
    [1,2,1,1] is_alias [2,1,1,1] ? true
    [1,2,1,1] is_alias [2,1,1,2] ? false
    [1,2,1,1] is_alias [2,1,2,0] ? false
    [1,2,1,1] is_alias [2,1,2,1] ? false
    [1,2,1,1] is_alias [2,1,2,2] ? false
    [1,2,1,1] is_alias [2,2,0,0] ? false
    [1,2,1,1] is_alias [2,2,0,1] ? false
    [1,2,1,1] is_alias [2,2,0,2] ? false
    [1,2,1,1] is_alias [2,2,1,0] ? false
    [1,2,1,1] is_alias [2,2,1,1] ? false
    [1,2,1,1] is_alias [2,2,1,2] ? false
    [1,2,1,1] is_alias [2,2,2,0] ? false
    [1,2,1,1] is_alias [2,2,2,1] ? false
    [1,2,1,1] is_alias [2,2,2,2] ? false
    [1,2,1,2] index has alias ? : true
    [1,2,1,2] is_alias [0,0,0,0] ? false
    [1,2,1,2] is_alias [0,0,0,1] ? false
    [1,2,1,2] is_alias [0,0,0,2] ? false
    [1,2,1,2] is_alias [0,0,1,0] ? false
    [1,2,1,2] is_alias [0,0,1,1] ? false
    [1,2,1,2] is_alias [0,0,1,2] ? false
    [1,2,1,2] is_alias [0,0,2,0] ? false
    [1,2,1,2] is_alias [0,0,2,1] ? false
    [1,2,1,2] is_alias [0,0,2,2] ? false
    [1,2,1,2] is_alias [0,1,0,0] ? false
    [1,2,1,2] is_alias [0,1,0,1] ? false
    [1,2,1,2] is_alias [0,1,0,2] ? false
    [1,2,1,2] is_alias [0,1,1,0] ? false
    [1,2,1,2] is_alias [0,1,1,1] ? false
    [1,2,1,2] is_alias [0,1,1,2] ? false
    [1,2,1,2] is_alias [0,1,2,0] ? false
    [1,2,1,2] is_alias [0,1,2,1] ? false
    [1,2,1,2] is_alias [0,1,2,2] ? false
    [1,2,1,2] is_alias [0,2,0,0] ? false
    [1,2,1,2] is_alias [0,2,0,1] ? false
    [1,2,1,2] is_alias [0,2,0,2] ? false
    [1,2,1,2] is_alias [0,2,1,0] ? false
    [1,2,1,2] is_alias [0,2,1,1] ? false
    [1,2,1,2] is_alias [0,2,1,2] ? false
    [1,2,1,2] is_alias [0,2,2,0] ? false
    [1,2,1,2] is_alias [0,2,2,1] ? false
    [1,2,1,2] is_alias [0,2,2,2] ? false
    [1,2,1,2] is_alias [1,0,0,0] ? false
    [1,2,1,2] is_alias [1,0,0,1] ? false
    [1,2,1,2] is_alias [1,0,0,2] ? false
    [1,2,1,2] is_alias [1,0,1,0] ? false
    [1,2,1,2] is_alias [1,0,1,1] ? false
    [1,2,1,2] is_alias [1,0,1,2] ? false
    [1,2,1,2] is_alias [1,0,2,0] ? false
    [1,2,1,2] is_alias [1,0,2,1] ? false
    [1,2,1,2] is_alias [1,0,2,2] ? false
    [1,2,1,2] is_alias [1,1,0,0] ? false
    [1,2,1,2] is_alias [1,1,0,1] ? false
    [1,2,1,2] is_alias [1,1,0,2] ? false
    [1,2,1,2] is_alias [1,1,1,0] ? false
    [1,2,1,2] is_alias [1,1,1,1] ? false
    [1,2,1,2] is_alias [1,1,1,2] ? false
    [1,2,1,2] is_alias [1,1,2,0] ? false
    [1,2,1,2] is_alias [1,1,2,1] ? false
    [1,2,1,2] is_alias [1,1,2,2] ? false
    [1,2,1,2] is_alias [1,2,0,0] ? false
    [1,2,1,2] is_alias [1,2,0,1] ? false
    [1,2,1,2] is_alias [1,2,0,2] ? false
    [1,2,1,2] is_alias [1,2,1,0] ? false
    [1,2,1,2] is_alias [1,2,1,1] ? false
    [1,2,1,2] is_alias [1,2,1,2] ? false
    [1,2,1,2] is_alias [1,2,2,0] ? false
    [1,2,1,2] is_alias [1,2,2,1] ? true
    [1,2,1,2] is_alias [1,2,2,2] ? false
    [1,2,1,2] is_alias [2,0,0,0] ? false
    [1,2,1,2] is_alias [2,0,0,1] ? false
    [1,2,1,2] is_alias [2,0,0,2] ? false
    [1,2,1,2] is_alias [2,0,1,0] ? false
    [1,2,1,2] is_alias [2,0,1,1] ? false
    [1,2,1,2] is_alias [2,0,1,2] ? false
    [1,2,1,2] is_alias [2,0,2,0] ? false
    [1,2,1,2] is_alias [2,0,2,1] ? false
    [1,2,1,2] is_alias [2,0,2,2] ? false
    [1,2,1,2] is_alias [2,1,0,0] ? false
    [1,2,1,2] is_alias [2,1,0,1] ? false
    [1,2,1,2] is_alias [2,1,0,2] ? false
    [1,2,1,2] is_alias [2,1,1,0] ? false
    [1,2,1,2] is_alias [2,1,1,1] ? false
    [1,2,1,2] is_alias [2,1,1,2] ? true
    [1,2,1,2] is_alias [2,1,2,0] ? false
    [1,2,1,2] is_alias [2,1,2,1] ? true
    [1,2,1,2] is_alias [2,1,2,2] ? false
    [1,2,1,2] is_alias [2,2,0,0] ? false
    [1,2,1,2] is_alias [2,2,0,1] ? false
    [1,2,1,2] is_alias [2,2,0,2] ? false
    [1,2,1,2] is_alias [2,2,1,0] ? false
    [1,2,1,2] is_alias [2,2,1,1] ? false
    [1,2,1,2] is_alias [2,2,1,2] ? false
    [1,2,1,2] is_alias [2,2,2,0] ? false
    [1,2,1,2] is_alias [2,2,2,1] ? false
    [1,2,1,2] is_alias [2,2,2,2] ? false
    [1,2,2,0] index has alias ? : true
    [1,2,2,0] is_alias [0,0,0,0] ? false
    [1,2,2,0] is_alias [0,0,0,1] ? false
    [1,2,2,0] is_alias [0,0,0,2] ? false
    [1,2,2,0] is_alias [0,0,1,0] ? false
    [1,2,2,0] is_alias [0,0,1,1] ? false
    [1,2,2,0] is_alias [0,0,1,2] ? false
    [1,2,2,0] is_alias [0,0,2,0] ? false
    [1,2,2,0] is_alias [0,0,2,1] ? false
    [1,2,2,0] is_alias [0,0,2,2] ? false
    [1,2,2,0] is_alias [0,1,0,0] ? false
    [1,2,2,0] is_alias [0,1,0,1] ? false
    [1,2,2,0] is_alias [0,1,0,2] ? false
    [1,2,2,0] is_alias [0,1,1,0] ? false
    [1,2,2,0] is_alias [0,1,1,1] ? false
    [1,2,2,0] is_alias [0,1,1,2] ? false
    [1,2,2,0] is_alias [0,1,2,0] ? false
    [1,2,2,0] is_alias [0,1,2,1] ? false
    [1,2,2,0] is_alias [0,1,2,2] ? false
    [1,2,2,0] is_alias [0,2,0,0] ? false
    [1,2,2,0] is_alias [0,2,0,1] ? false
    [1,2,2,0] is_alias [0,2,0,2] ? false
    [1,2,2,0] is_alias [0,2,1,0] ? false
    [1,2,2,0] is_alias [0,2,1,1] ? false
    [1,2,2,0] is_alias [0,2,1,2] ? true
    [1,2,2,0] is_alias [0,2,2,0] ? false
    [1,2,2,0] is_alias [0,2,2,1] ? true
    [1,2,2,0] is_alias [0,2,2,2] ? false
    [1,2,2,0] is_alias [1,0,0,0] ? false
    [1,2,2,0] is_alias [1,0,0,1] ? false
    [1,2,2,0] is_alias [1,0,0,2] ? false
    [1,2,2,0] is_alias [1,0,1,0] ? false
    [1,2,2,0] is_alias [1,0,1,1] ? false
    [1,2,2,0] is_alias [1,0,1,2] ? false
    [1,2,2,0] is_alias [1,0,2,0] ? false
    [1,2,2,0] is_alias [1,0,2,1] ? false
    [1,2,2,0] is_alias [1,0,2,2] ? false
    [1,2,2,0] is_alias [1,1,0,0] ? false
    [1,2,2,0] is_alias [1,1,0,1] ? false
    [1,2,2,0] is_alias [1,1,0,2] ? false
    [1,2,2,0] is_alias [1,1,1,0] ? false
    [1,2,2,0] is_alias [1,1,1,1] ? false
    [1,2,2,0] is_alias [1,1,1,2] ? false
    [1,2,2,0] is_alias [1,1,2,0] ? false
    [1,2,2,0] is_alias [1,1,2,1] ? false
    [1,2,2,0] is_alias [1,1,2,2] ? false
    [1,2,2,0] is_alias [1,2,0,0] ? false
    [1,2,2,0] is_alias [1,2,0,1] ? false
    [1,2,2,0] is_alias [1,2,0,2] ? true
    [1,2,2,0] is_alias [1,2,1,0] ? false
    [1,2,2,0] is_alias [1,2,1,1] ? false
    [1,2,2,0] is_alias [1,2,1,2] ? false
    [1,2,2,0] is_alias [1,2,2,0] ? false
    [1,2,2,0] is_alias [1,2,2,1] ? false
    [1,2,2,0] is_alias [1,2,2,2] ? false
    [1,2,2,0] is_alias [2,0,0,0] ? false
    [1,2,2,0] is_alias [2,0,0,1] ? false
    [1,2,2,0] is_alias [2,0,0,2] ? false
    [1,2,2,0] is_alias [2,0,1,0] ? false
    [1,2,2,0] is_alias [2,0,1,1] ? false
    [1,2,2,0] is_alias [2,0,1,2] ? true
    [1,2,2,0] is_alias [2,0,2,0] ? false
    [1,2,2,0] is_alias [2,0,2,1] ? true
    [1,2,2,0] is_alias [2,0,2,2] ? false
    [1,2,2,0] is_alias [2,1,0,0] ? false
    [1,2,2,0] is_alias [2,1,0,1] ? false
    [1,2,2,0] is_alias [2,1,0,2] ? true
    [1,2,2,0] is_alias [2,1,1,0] ? false
    [1,2,2,0] is_alias [2,1,1,1] ? false
    [1,2,2,0] is_alias [2,1,1,2] ? false
    [1,2,2,0] is_alias [2,1,2,0] ? true
    [1,2,2,0] is_alias [2,1,2,1] ? false
    [1,2,2,0] is_alias [2,1,2,2] ? false
    [1,2,2,0] is_alias [2,2,0,0] ? false
    [1,2,2,0] is_alias [2,2,0,1] ? false
    [1,2,2,0] is_alias [2,2,0,2] ? false
    [1,2,2,0] is_alias [2,2,1,0] ? false
    [1,2,2,0] is_alias [2,2,1,1] ? false
    [1,2,2,0] is_alias [2,2,1,2] ? false
    [1,2,2,0] is_alias [2,2,2,0] ? false
    [1,2,2,0] is_alias [2,2,2,1] ? false
    [1,2,2,0] is_alias [2,2,2,2] ? false
    [1,2,2,1] index has alias ? : true
    [1,2,2,1] is_alias [0,0,0,0] ? false
    [1,2,2,1] is_alias [0,0,0,1] ? false
    [1,2,2,1] is_alias [0,0,0,2] ? false
    [1,2,2,1] is_alias [0,0,1,0] ? false
    [1,2,2,1] is_alias [0,0,1,1] ? false
    [1,2,2,1] is_alias [0,0,1,2] ? false
    [1,2,2,1] is_alias [0,0,2,0] ? false
    [1,2,2,1] is_alias [0,0,2,1] ? false
    [1,2,2,1] is_alias [0,0,2,2] ? false
    [1,2,2,1] is_alias [0,1,0,0] ? false
    [1,2,2,1] is_alias [0,1,0,1] ? false
    [1,2,2,1] is_alias [0,1,0,2] ? false
    [1,2,2,1] is_alias [0,1,1,0] ? false
    [1,2,2,1] is_alias [0,1,1,1] ? false
    [1,2,2,1] is_alias [0,1,1,2] ? false
    [1,2,2,1] is_alias [0,1,2,0] ? false
    [1,2,2,1] is_alias [0,1,2,1] ? false
    [1,2,2,1] is_alias [0,1,2,2] ? false
    [1,2,2,1] is_alias [0,2,0,0] ? false
    [1,2,2,1] is_alias [0,2,0,1] ? false
    [1,2,2,1] is_alias [0,2,0,2] ? false
    [1,2,2,1] is_alias [0,2,1,0] ? false
    [1,2,2,1] is_alias [0,2,1,1] ? false
    [1,2,2,1] is_alias [0,2,1,2] ? false
    [1,2,2,1] is_alias [0,2,2,0] ? false
    [1,2,2,1] is_alias [0,2,2,1] ? false
    [1,2,2,1] is_alias [0,2,2,2] ? false
    [1,2,2,1] is_alias [1,0,0,0] ? false
    [1,2,2,1] is_alias [1,0,0,1] ? false
    [1,2,2,1] is_alias [1,0,0,2] ? false
    [1,2,2,1] is_alias [1,0,1,0] ? false
    [1,2,2,1] is_alias [1,0,1,1] ? false
    [1,2,2,1] is_alias [1,0,1,2] ? false
    [1,2,2,1] is_alias [1,0,2,0] ? false
    [1,2,2,1] is_alias [1,0,2,1] ? false
    [1,2,2,1] is_alias [1,0,2,2] ? false
    [1,2,2,1] is_alias [1,1,0,0] ? false
    [1,2,2,1] is_alias [1,1,0,1] ? false
    [1,2,2,1] is_alias [1,1,0,2] ? false
    [1,2,2,1] is_alias [1,1,1,0] ? false
    [1,2,2,1] is_alias [1,1,1,1] ? false
    [1,2,2,1] is_alias [1,1,1,2] ? false
    [1,2,2,1] is_alias [1,1,2,0] ? false
    [1,2,2,1] is_alias [1,1,2,1] ? false
    [1,2,2,1] is_alias [1,1,2,2] ? false
    [1,2,2,1] is_alias [1,2,0,0] ? false
    [1,2,2,1] is_alias [1,2,0,1] ? false
    [1,2,2,1] is_alias [1,2,0,2] ? false
    [1,2,2,1] is_alias [1,2,1,0] ? false
    [1,2,2,1] is_alias [1,2,1,1] ? false
    [1,2,2,1] is_alias [1,2,1,2] ? true
    [1,2,2,1] is_alias [1,2,2,0] ? false
    [1,2,2,1] is_alias [1,2,2,1] ? false
    [1,2,2,1] is_alias [1,2,2,2] ? false
    [1,2,2,1] is_alias [2,0,0,0] ? false
    [1,2,2,1] is_alias [2,0,0,1] ? false
    [1,2,2,1] is_alias [2,0,0,2] ? false
    [1,2,2,1] is_alias [2,0,1,0] ? false
    [1,2,2,1] is_alias [2,0,1,1] ? false
    [1,2,2,1] is_alias [2,0,1,2] ? false
    [1,2,2,1] is_alias [2,0,2,0] ? false
    [1,2,2,1] is_alias [2,0,2,1] ? false
    [1,2,2,1] is_alias [2,0,2,2] ? false
    [1,2,2,1] is_alias [2,1,0,0] ? false
    [1,2,2,1] is_alias [2,1,0,1] ? false
    [1,2,2,1] is_alias [2,1,0,2] ? false
    [1,2,2,1] is_alias [2,1,1,0] ? false
    [1,2,2,1] is_alias [2,1,1,1] ? false
    [1,2,2,1] is_alias [2,1,1,2] ? true
    [1,2,2,1] is_alias [2,1,2,0] ? false
    [1,2,2,1] is_alias [2,1,2,1] ? true
    [1,2,2,1] is_alias [2,1,2,2] ? false
    [1,2,2,1] is_alias [2,2,0,0] ? false
    [1,2,2,1] is_alias [2,2,0,1] ? false
    [1,2,2,1] is_alias [2,2,0,2] ? false
    [1,2,2,1] is_alias [2,2,1,0] ? false
    [1,2,2,1] is_alias [2,2,1,1] ? false
    [1,2,2,1] is_alias [2,2,1,2] ? false
    [1,2,2,1] is_alias [2,2,2,0] ? false
    [1,2,2,1] is_alias [2,2,2,1] ? false
    [1,2,2,1] is_alias [2,2,2,2] ? false
    [1,2,2,2] index has alias ? : true
    [1,2,2,2] is_alias [0,0,0,0] ? false
    [1,2,2,2] is_alias [0,0,0,1] ? false
    [1,2,2,2] is_alias [0,0,0,2] ? false
    [1,2,2,2] is_alias [0,0,1,0] ? false
    [1,2,2,2] is_alias [0,0,1,1] ? false
    [1,2,2,2] is_alias [0,0,1,2] ? false
    [1,2,2,2] is_alias [0,0,2,0] ? false
    [1,2,2,2] is_alias [0,0,2,1] ? false
    [1,2,2,2] is_alias [0,0,2,2] ? false
    [1,2,2,2] is_alias [0,1,0,0] ? false
    [1,2,2,2] is_alias [0,1,0,1] ? false
    [1,2,2,2] is_alias [0,1,0,2] ? false
    [1,2,2,2] is_alias [0,1,1,0] ? false
    [1,2,2,2] is_alias [0,1,1,1] ? false
    [1,2,2,2] is_alias [0,1,1,2] ? false
    [1,2,2,2] is_alias [0,1,2,0] ? false
    [1,2,2,2] is_alias [0,1,2,1] ? false
    [1,2,2,2] is_alias [0,1,2,2] ? false
    [1,2,2,2] is_alias [0,2,0,0] ? false
    [1,2,2,2] is_alias [0,2,0,1] ? false
    [1,2,2,2] is_alias [0,2,0,2] ? false
    [1,2,2,2] is_alias [0,2,1,0] ? false
    [1,2,2,2] is_alias [0,2,1,1] ? false
    [1,2,2,2] is_alias [0,2,1,2] ? false
    [1,2,2,2] is_alias [0,2,2,0] ? false
    [1,2,2,2] is_alias [0,2,2,1] ? false
    [1,2,2,2] is_alias [0,2,2,2] ? false
    [1,2,2,2] is_alias [1,0,0,0] ? false
    [1,2,2,2] is_alias [1,0,0,1] ? false
    [1,2,2,2] is_alias [1,0,0,2] ? false
    [1,2,2,2] is_alias [1,0,1,0] ? false
    [1,2,2,2] is_alias [1,0,1,1] ? false
    [1,2,2,2] is_alias [1,0,1,2] ? false
    [1,2,2,2] is_alias [1,0,2,0] ? false
    [1,2,2,2] is_alias [1,0,2,1] ? false
    [1,2,2,2] is_alias [1,0,2,2] ? false
    [1,2,2,2] is_alias [1,1,0,0] ? false
    [1,2,2,2] is_alias [1,1,0,1] ? false
    [1,2,2,2] is_alias [1,1,0,2] ? false
    [1,2,2,2] is_alias [1,1,1,0] ? false
    [1,2,2,2] is_alias [1,1,1,1] ? false
    [1,2,2,2] is_alias [1,1,1,2] ? false
    [1,2,2,2] is_alias [1,1,2,0] ? false
    [1,2,2,2] is_alias [1,1,2,1] ? false
    [1,2,2,2] is_alias [1,1,2,2] ? false
    [1,2,2,2] is_alias [1,2,0,0] ? false
    [1,2,2,2] is_alias [1,2,0,1] ? false
    [1,2,2,2] is_alias [1,2,0,2] ? false
    [1,2,2,2] is_alias [1,2,1,0] ? false
    [1,2,2,2] is_alias [1,2,1,1] ? false
    [1,2,2,2] is_alias [1,2,1,2] ? false
    [1,2,2,2] is_alias [1,2,2,0] ? false
    [1,2,2,2] is_alias [1,2,2,1] ? false
    [1,2,2,2] is_alias [1,2,2,2] ? false
    [1,2,2,2] is_alias [2,0,0,0] ? false
    [1,2,2,2] is_alias [2,0,0,1] ? false
    [1,2,2,2] is_alias [2,0,0,2] ? false
    [1,2,2,2] is_alias [2,0,1,0] ? false
    [1,2,2,2] is_alias [2,0,1,1] ? false
    [1,2,2,2] is_alias [2,0,1,2] ? false
    [1,2,2,2] is_alias [2,0,2,0] ? false
    [1,2,2,2] is_alias [2,0,2,1] ? false
    [1,2,2,2] is_alias [2,0,2,2] ? false
    [1,2,2,2] is_alias [2,1,0,0] ? false
    [1,2,2,2] is_alias [2,1,0,1] ? false
    [1,2,2,2] is_alias [2,1,0,2] ? false
    [1,2,2,2] is_alias [2,1,1,0] ? false
    [1,2,2,2] is_alias [2,1,1,1] ? false
    [1,2,2,2] is_alias [2,1,1,2] ? false
    [1,2,2,2] is_alias [2,1,2,0] ? false
    [1,2,2,2] is_alias [2,1,2,1] ? false
    [1,2,2,2] is_alias [2,1,2,2] ? true
    [1,2,2,2] is_alias [2,2,0,0] ? false
    [1,2,2,2] is_alias [2,2,0,1] ? false
    [1,2,2,2] is_alias [2,2,0,2] ? false
    [1,2,2,2] is_alias [2,2,1,0] ? false
    [1,2,2,2] is_alias [2,2,1,1] ? false
    [1,2,2,2] is_alias [2,2,1,2] ? true
    [1,2,2,2] is_alias [2,2,2,0] ? false
    [1,2,2,2] is_alias [2,2,2,1] ? true
    [1,2,2,2] is_alias [2,2,2,2] ? false
    [2,0,0,0] index has alias ? : true
    [2,0,0,0] is_alias [0,0,0,0] ? false
    [2,0,0,0] is_alias [0,0,0,1] ? false
    [2,0,0,0] is_alias [0,0,0,2] ? true
    [2,0,0,0] is_alias [0,0,1,0] ? false
    [2,0,0,0] is_alias [0,0,1,1] ? false
    [2,0,0,0] is_alias [0,0,1,2] ? false
    [2,0,0,0] is_alias [0,0,2,0] ? true
    [2,0,0,0] is_alias [0,0,2,1] ? false
    [2,0,0,0] is_alias [0,0,2,2] ? false
    [2,0,0,0] is_alias [0,1,0,0] ? false
    [2,0,0,0] is_alias [0,1,0,1] ? false
    [2,0,0,0] is_alias [0,1,0,2] ? false
    [2,0,0,0] is_alias [0,1,1,0] ? false
    [2,0,0,0] is_alias [0,1,1,1] ? false
    [2,0,0,0] is_alias [0,1,1,2] ? false
    [2,0,0,0] is_alias [0,1,2,0] ? false
    [2,0,0,0] is_alias [0,1,2,1] ? false
    [2,0,0,0] is_alias [0,1,2,2] ? false
    [2,0,0,0] is_alias [0,2,0,0] ? true
    [2,0,0,0] is_alias [0,2,0,1] ? false
    [2,0,0,0] is_alias [0,2,0,2] ? false
    [2,0,0,0] is_alias [0,2,1,0] ? false
    [2,0,0,0] is_alias [0,2,1,1] ? false
    [2,0,0,0] is_alias [0,2,1,2] ? false
    [2,0,0,0] is_alias [0,2,2,0] ? false
    [2,0,0,0] is_alias [0,2,2,1] ? false
    [2,0,0,0] is_alias [0,2,2,2] ? false
    [2,0,0,0] is_alias [1,0,0,0] ? false
    [2,0,0,0] is_alias [1,0,0,1] ? false
    [2,0,0,0] is_alias [1,0,0,2] ? false
    [2,0,0,0] is_alias [1,0,1,0] ? false
    [2,0,0,0] is_alias [1,0,1,1] ? false
    [2,0,0,0] is_alias [1,0,1,2] ? false
    [2,0,0,0] is_alias [1,0,2,0] ? false
    [2,0,0,0] is_alias [1,0,2,1] ? false
    [2,0,0,0] is_alias [1,0,2,2] ? false
    [2,0,0,0] is_alias [1,1,0,0] ? false
    [2,0,0,0] is_alias [1,1,0,1] ? false
    [2,0,0,0] is_alias [1,1,0,2] ? false
    [2,0,0,0] is_alias [1,1,1,0] ? false
    [2,0,0,0] is_alias [1,1,1,1] ? false
    [2,0,0,0] is_alias [1,1,1,2] ? false
    [2,0,0,0] is_alias [1,1,2,0] ? false
    [2,0,0,0] is_alias [1,1,2,1] ? false
    [2,0,0,0] is_alias [1,1,2,2] ? false
    [2,0,0,0] is_alias [1,2,0,0] ? false
    [2,0,0,0] is_alias [1,2,0,1] ? false
    [2,0,0,0] is_alias [1,2,0,2] ? false
    [2,0,0,0] is_alias [1,2,1,0] ? false
    [2,0,0,0] is_alias [1,2,1,1] ? false
    [2,0,0,0] is_alias [1,2,1,2] ? false
    [2,0,0,0] is_alias [1,2,2,0] ? false
    [2,0,0,0] is_alias [1,2,2,1] ? false
    [2,0,0,0] is_alias [1,2,2,2] ? false
    [2,0,0,0] is_alias [2,0,0,0] ? false
    [2,0,0,0] is_alias [2,0,0,1] ? false
    [2,0,0,0] is_alias [2,0,0,2] ? false
    [2,0,0,0] is_alias [2,0,1,0] ? false
    [2,0,0,0] is_alias [2,0,1,1] ? false
    [2,0,0,0] is_alias [2,0,1,2] ? false
    [2,0,0,0] is_alias [2,0,2,0] ? false
    [2,0,0,0] is_alias [2,0,2,1] ? false
    [2,0,0,0] is_alias [2,0,2,2] ? false
    [2,0,0,0] is_alias [2,1,0,0] ? false
    [2,0,0,0] is_alias [2,1,0,1] ? false
    [2,0,0,0] is_alias [2,1,0,2] ? false
    [2,0,0,0] is_alias [2,1,1,0] ? false
    [2,0,0,0] is_alias [2,1,1,1] ? false
    [2,0,0,0] is_alias [2,1,1,2] ? false
    [2,0,0,0] is_alias [2,1,2,0] ? false
    [2,0,0,0] is_alias [2,1,2,1] ? false
    [2,0,0,0] is_alias [2,1,2,2] ? false
    [2,0,0,0] is_alias [2,2,0,0] ? false
    [2,0,0,0] is_alias [2,2,0,1] ? false
    [2,0,0,0] is_alias [2,2,0,2] ? false
    [2,0,0,0] is_alias [2,2,1,0] ? false
    [2,0,0,0] is_alias [2,2,1,1] ? false
    [2,0,0,0] is_alias [2,2,1,2] ? false
    [2,0,0,0] is_alias [2,2,2,0] ? false
    [2,0,0,0] is_alias [2,2,2,1] ? false
    [2,0,0,0] is_alias [2,2,2,2] ? false
    [2,0,0,1] index has alias ? : true
    [2,0,0,1] is_alias [0,0,0,0] ? false
    [2,0,0,1] is_alias [0,0,0,1] ? false
    [2,0,0,1] is_alias [0,0,0,2] ? false
    [2,0,0,1] is_alias [0,0,1,0] ? false
    [2,0,0,1] is_alias [0,0,1,1] ? false
    [2,0,0,1] is_alias [0,0,1,2] ? false
    [2,0,0,1] is_alias [0,0,2,0] ? false
    [2,0,0,1] is_alias [0,0,2,1] ? false
    [2,0,0,1] is_alias [0,0,2,2] ? false
    [2,0,0,1] is_alias [0,1,0,0] ? false
    [2,0,0,1] is_alias [0,1,0,1] ? false
    [2,0,0,1] is_alias [0,1,0,2] ? true
    [2,0,0,1] is_alias [0,1,1,0] ? false
    [2,0,0,1] is_alias [0,1,1,1] ? false
    [2,0,0,1] is_alias [0,1,1,2] ? false
    [2,0,0,1] is_alias [0,1,2,0] ? true
    [2,0,0,1] is_alias [0,1,2,1] ? false
    [2,0,0,1] is_alias [0,1,2,2] ? false
    [2,0,0,1] is_alias [0,2,0,0] ? false
    [2,0,0,1] is_alias [0,2,0,1] ? true
    [2,0,0,1] is_alias [0,2,0,2] ? false
    [2,0,0,1] is_alias [0,2,1,0] ? true
    [2,0,0,1] is_alias [0,2,1,1] ? false
    [2,0,0,1] is_alias [0,2,1,2] ? false
    [2,0,0,1] is_alias [0,2,2,0] ? false
    [2,0,0,1] is_alias [0,2,2,1] ? false
    [2,0,0,1] is_alias [0,2,2,2] ? false
    [2,0,0,1] is_alias [1,0,0,0] ? false
    [2,0,0,1] is_alias [1,0,0,1] ? false
    [2,0,0,1] is_alias [1,0,0,2] ? true
    [2,0,0,1] is_alias [1,0,1,0] ? false
    [2,0,0,1] is_alias [1,0,1,1] ? false
    [2,0,0,1] is_alias [1,0,1,2] ? false
    [2,0,0,1] is_alias [1,0,2,0] ? true
    [2,0,0,1] is_alias [1,0,2,1] ? false
    [2,0,0,1] is_alias [1,0,2,2] ? false
    [2,0,0,1] is_alias [1,1,0,0] ? false
    [2,0,0,1] is_alias [1,1,0,1] ? false
    [2,0,0,1] is_alias [1,1,0,2] ? false
    [2,0,0,1] is_alias [1,1,1,0] ? false
    [2,0,0,1] is_alias [1,1,1,1] ? false
    [2,0,0,1] is_alias [1,1,1,2] ? false
    [2,0,0,1] is_alias [1,1,2,0] ? false
    [2,0,0,1] is_alias [1,1,2,1] ? false
    [2,0,0,1] is_alias [1,1,2,2] ? false
    [2,0,0,1] is_alias [1,2,0,0] ? false
    [2,0,0,1] is_alias [1,2,0,1] ? false
    [2,0,0,1] is_alias [1,2,0,2] ? false
    [2,0,0,1] is_alias [1,2,1,0] ? false
    [2,0,0,1] is_alias [1,2,1,1] ? false
    [2,0,0,1] is_alias [1,2,1,2] ? false
    [2,0,0,1] is_alias [1,2,2,0] ? false
    [2,0,0,1] is_alias [1,2,2,1] ? false
    [2,0,0,1] is_alias [1,2,2,2] ? false
    [2,0,0,1] is_alias [2,0,0,0] ? false
    [2,0,0,1] is_alias [2,0,0,1] ? false
    [2,0,0,1] is_alias [2,0,0,2] ? false
    [2,0,0,1] is_alias [2,0,1,0] ? true
    [2,0,0,1] is_alias [2,0,1,1] ? false
    [2,0,0,1] is_alias [2,0,1,2] ? false
    [2,0,0,1] is_alias [2,0,2,0] ? false
    [2,0,0,1] is_alias [2,0,2,1] ? false
    [2,0,0,1] is_alias [2,0,2,2] ? false
    [2,0,0,1] is_alias [2,1,0,0] ? false
    [2,0,0,1] is_alias [2,1,0,1] ? false
    [2,0,0,1] is_alias [2,1,0,2] ? false
    [2,0,0,1] is_alias [2,1,1,0] ? false
    [2,0,0,1] is_alias [2,1,1,1] ? false
    [2,0,0,1] is_alias [2,1,1,2] ? false
    [2,0,0,1] is_alias [2,1,2,0] ? false
    [2,0,0,1] is_alias [2,1,2,1] ? false
    [2,0,0,1] is_alias [2,1,2,2] ? false
    [2,0,0,1] is_alias [2,2,0,0] ? false
    [2,0,0,1] is_alias [2,2,0,1] ? false
    [2,0,0,1] is_alias [2,2,0,2] ? false
    [2,0,0,1] is_alias [2,2,1,0] ? false
    [2,0,0,1] is_alias [2,2,1,1] ? false
    [2,0,0,1] is_alias [2,2,1,2] ? false
    [2,0,0,1] is_alias [2,2,2,0] ? false
    [2,0,0,1] is_alias [2,2,2,1] ? false
    [2,0,0,1] is_alias [2,2,2,2] ? false
    [2,0,0,2] index has alias ? : true
    [2,0,0,2] is_alias [0,0,0,0] ? false
    [2,0,0,2] is_alias [0,0,0,1] ? false
    [2,0,0,2] is_alias [0,0,0,2] ? false
    [2,0,0,2] is_alias [0,0,1,0] ? false
    [2,0,0,2] is_alias [0,0,1,1] ? false
    [2,0,0,2] is_alias [0,0,1,2] ? false
    [2,0,0,2] is_alias [0,0,2,0] ? false
    [2,0,0,2] is_alias [0,0,2,1] ? false
    [2,0,0,2] is_alias [0,0,2,2] ? false
    [2,0,0,2] is_alias [0,1,0,0] ? false
    [2,0,0,2] is_alias [0,1,0,1] ? false
    [2,0,0,2] is_alias [0,1,0,2] ? false
    [2,0,0,2] is_alias [0,1,1,0] ? false
    [2,0,0,2] is_alias [0,1,1,1] ? false
    [2,0,0,2] is_alias [0,1,1,2] ? false
    [2,0,0,2] is_alias [0,1,2,0] ? false
    [2,0,0,2] is_alias [0,1,2,1] ? false
    [2,0,0,2] is_alias [0,1,2,2] ? false
    [2,0,0,2] is_alias [0,2,0,0] ? false
    [2,0,0,2] is_alias [0,2,0,1] ? false
    [2,0,0,2] is_alias [0,2,0,2] ? true
    [2,0,0,2] is_alias [0,2,1,0] ? false
    [2,0,0,2] is_alias [0,2,1,1] ? false
    [2,0,0,2] is_alias [0,2,1,2] ? false
    [2,0,0,2] is_alias [0,2,2,0] ? true
    [2,0,0,2] is_alias [0,2,2,1] ? false
    [2,0,0,2] is_alias [0,2,2,2] ? false
    [2,0,0,2] is_alias [1,0,0,0] ? false
    [2,0,0,2] is_alias [1,0,0,1] ? false
    [2,0,0,2] is_alias [1,0,0,2] ? false
    [2,0,0,2] is_alias [1,0,1,0] ? false
    [2,0,0,2] is_alias [1,0,1,1] ? false
    [2,0,0,2] is_alias [1,0,1,2] ? false
    [2,0,0,2] is_alias [1,0,2,0] ? false
    [2,0,0,2] is_alias [1,0,2,1] ? false
    [2,0,0,2] is_alias [1,0,2,2] ? false
    [2,0,0,2] is_alias [1,1,0,0] ? false
    [2,0,0,2] is_alias [1,1,0,1] ? false
    [2,0,0,2] is_alias [1,1,0,2] ? false
    [2,0,0,2] is_alias [1,1,1,0] ? false
    [2,0,0,2] is_alias [1,1,1,1] ? false
    [2,0,0,2] is_alias [1,1,1,2] ? false
    [2,0,0,2] is_alias [1,1,2,0] ? false
    [2,0,0,2] is_alias [1,1,2,1] ? false
    [2,0,0,2] is_alias [1,1,2,2] ? false
    [2,0,0,2] is_alias [1,2,0,0] ? false
    [2,0,0,2] is_alias [1,2,0,1] ? false
    [2,0,0,2] is_alias [1,2,0,2] ? false
    [2,0,0,2] is_alias [1,2,1,0] ? false
    [2,0,0,2] is_alias [1,2,1,1] ? false
    [2,0,0,2] is_alias [1,2,1,2] ? false
    [2,0,0,2] is_alias [1,2,2,0] ? false
    [2,0,0,2] is_alias [1,2,2,1] ? false
    [2,0,0,2] is_alias [1,2,2,2] ? false
    [2,0,0,2] is_alias [2,0,0,0] ? false
    [2,0,0,2] is_alias [2,0,0,1] ? false
    [2,0,0,2] is_alias [2,0,0,2] ? false
    [2,0,0,2] is_alias [2,0,1,0] ? false
    [2,0,0,2] is_alias [2,0,1,1] ? false
    [2,0,0,2] is_alias [2,0,1,2] ? false
    [2,0,0,2] is_alias [2,0,2,0] ? true
    [2,0,0,2] is_alias [2,0,2,1] ? false
    [2,0,0,2] is_alias [2,0,2,2] ? false
    [2,0,0,2] is_alias [2,1,0,0] ? false
    [2,0,0,2] is_alias [2,1,0,1] ? false
    [2,0,0,2] is_alias [2,1,0,2] ? false
    [2,0,0,2] is_alias [2,1,1,0] ? false
    [2,0,0,2] is_alias [2,1,1,1] ? false
    [2,0,0,2] is_alias [2,1,1,2] ? false
    [2,0,0,2] is_alias [2,1,2,0] ? false
    [2,0,0,2] is_alias [2,1,2,1] ? false
    [2,0,0,2] is_alias [2,1,2,2] ? false
    [2,0,0,2] is_alias [2,2,0,0] ? false
    [2,0,0,2] is_alias [2,2,0,1] ? false
    [2,0,0,2] is_alias [2,2,0,2] ? false
    [2,0,0,2] is_alias [2,2,1,0] ? false
    [2,0,0,2] is_alias [2,2,1,1] ? false
    [2,0,0,2] is_alias [2,2,1,2] ? false
    [2,0,0,2] is_alias [2,2,2,0] ? false
    [2,0,0,2] is_alias [2,2,2,1] ? false
    [2,0,0,2] is_alias [2,2,2,2] ? false
    [2,0,1,0] index has alias ? : true
    [2,0,1,0] is_alias [0,0,0,0] ? false
    [2,0,1,0] is_alias [0,0,0,1] ? false
    [2,0,1,0] is_alias [0,0,0,2] ? false
    [2,0,1,0] is_alias [0,0,1,0] ? false
    [2,0,1,0] is_alias [0,0,1,1] ? false
    [2,0,1,0] is_alias [0,0,1,2] ? false
    [2,0,1,0] is_alias [0,0,2,0] ? false
    [2,0,1,0] is_alias [0,0,2,1] ? false
    [2,0,1,0] is_alias [0,0,2,2] ? false
    [2,0,1,0] is_alias [0,1,0,0] ? false
    [2,0,1,0] is_alias [0,1,0,1] ? false
    [2,0,1,0] is_alias [0,1,0,2] ? true
    [2,0,1,0] is_alias [0,1,1,0] ? false
    [2,0,1,0] is_alias [0,1,1,1] ? false
    [2,0,1,0] is_alias [0,1,1,2] ? false
    [2,0,1,0] is_alias [0,1,2,0] ? true
    [2,0,1,0] is_alias [0,1,2,1] ? false
    [2,0,1,0] is_alias [0,1,2,2] ? false
    [2,0,1,0] is_alias [0,2,0,0] ? false
    [2,0,1,0] is_alias [0,2,0,1] ? true
    [2,0,1,0] is_alias [0,2,0,2] ? false
    [2,0,1,0] is_alias [0,2,1,0] ? true
    [2,0,1,0] is_alias [0,2,1,1] ? false
    [2,0,1,0] is_alias [0,2,1,2] ? false
    [2,0,1,0] is_alias [0,2,2,0] ? false
    [2,0,1,0] is_alias [0,2,2,1] ? false
    [2,0,1,0] is_alias [0,2,2,2] ? false
    [2,0,1,0] is_alias [1,0,0,0] ? false
    [2,0,1,0] is_alias [1,0,0,1] ? false
    [2,0,1,0] is_alias [1,0,0,2] ? true
    [2,0,1,0] is_alias [1,0,1,0] ? false
    [2,0,1,0] is_alias [1,0,1,1] ? false
    [2,0,1,0] is_alias [1,0,1,2] ? false
    [2,0,1,0] is_alias [1,0,2,0] ? true
    [2,0,1,0] is_alias [1,0,2,1] ? false
    [2,0,1,0] is_alias [1,0,2,2] ? false
    [2,0,1,0] is_alias [1,1,0,0] ? false
    [2,0,1,0] is_alias [1,1,0,1] ? false
    [2,0,1,0] is_alias [1,1,0,2] ? false
    [2,0,1,0] is_alias [1,1,1,0] ? false
    [2,0,1,0] is_alias [1,1,1,1] ? false
    [2,0,1,0] is_alias [1,1,1,2] ? false
    [2,0,1,0] is_alias [1,1,2,0] ? false
    [2,0,1,0] is_alias [1,1,2,1] ? false
    [2,0,1,0] is_alias [1,1,2,2] ? false
    [2,0,1,0] is_alias [1,2,0,0] ? false
    [2,0,1,0] is_alias [1,2,0,1] ? false
    [2,0,1,0] is_alias [1,2,0,2] ? false
    [2,0,1,0] is_alias [1,2,1,0] ? false
    [2,0,1,0] is_alias [1,2,1,1] ? false
    [2,0,1,0] is_alias [1,2,1,2] ? false
    [2,0,1,0] is_alias [1,2,2,0] ? false
    [2,0,1,0] is_alias [1,2,2,1] ? false
    [2,0,1,0] is_alias [1,2,2,2] ? false
    [2,0,1,0] is_alias [2,0,0,0] ? false
    [2,0,1,0] is_alias [2,0,0,1] ? true
    [2,0,1,0] is_alias [2,0,0,2] ? false
    [2,0,1,0] is_alias [2,0,1,0] ? false
    [2,0,1,0] is_alias [2,0,1,1] ? false
    [2,0,1,0] is_alias [2,0,1,2] ? false
    [2,0,1,0] is_alias [2,0,2,0] ? false
    [2,0,1,0] is_alias [2,0,2,1] ? false
    [2,0,1,0] is_alias [2,0,2,2] ? false
    [2,0,1,0] is_alias [2,1,0,0] ? false
    [2,0,1,0] is_alias [2,1,0,1] ? false
    [2,0,1,0] is_alias [2,1,0,2] ? false
    [2,0,1,0] is_alias [2,1,1,0] ? false
    [2,0,1,0] is_alias [2,1,1,1] ? false
    [2,0,1,0] is_alias [2,1,1,2] ? false
    [2,0,1,0] is_alias [2,1,2,0] ? false
    [2,0,1,0] is_alias [2,1,2,1] ? false
    [2,0,1,0] is_alias [2,1,2,2] ? false
    [2,0,1,0] is_alias [2,2,0,0] ? false
    [2,0,1,0] is_alias [2,2,0,1] ? false
    [2,0,1,0] is_alias [2,2,0,2] ? false
    [2,0,1,0] is_alias [2,2,1,0] ? false
    [2,0,1,0] is_alias [2,2,1,1] ? false
    [2,0,1,0] is_alias [2,2,1,2] ? false
    [2,0,1,0] is_alias [2,2,2,0] ? false
    [2,0,1,0] is_alias [2,2,2,1] ? false
    [2,0,1,0] is_alias [2,2,2,2] ? false
    [2,0,1,1] index has alias ? : true
    [2,0,1,1] is_alias [0,0,0,0] ? false
    [2,0,1,1] is_alias [0,0,0,1] ? false
    [2,0,1,1] is_alias [0,0,0,2] ? false
    [2,0,1,1] is_alias [0,0,1,0] ? false
    [2,0,1,1] is_alias [0,0,1,1] ? false
    [2,0,1,1] is_alias [0,0,1,2] ? false
    [2,0,1,1] is_alias [0,0,2,0] ? false
    [2,0,1,1] is_alias [0,0,2,1] ? false
    [2,0,1,1] is_alias [0,0,2,2] ? false
    [2,0,1,1] is_alias [0,1,0,0] ? false
    [2,0,1,1] is_alias [0,1,0,1] ? false
    [2,0,1,1] is_alias [0,1,0,2] ? false
    [2,0,1,1] is_alias [0,1,1,0] ? false
    [2,0,1,1] is_alias [0,1,1,1] ? false
    [2,0,1,1] is_alias [0,1,1,2] ? false
    [2,0,1,1] is_alias [0,1,2,0] ? false
    [2,0,1,1] is_alias [0,1,2,1] ? false
    [2,0,1,1] is_alias [0,1,2,2] ? false
    [2,0,1,1] is_alias [0,2,0,0] ? false
    [2,0,1,1] is_alias [0,2,0,1] ? false
    [2,0,1,1] is_alias [0,2,0,2] ? false
    [2,0,1,1] is_alias [0,2,1,0] ? false
    [2,0,1,1] is_alias [0,2,1,1] ? true
    [2,0,1,1] is_alias [0,2,1,2] ? false
    [2,0,1,1] is_alias [0,2,2,0] ? false
    [2,0,1,1] is_alias [0,2,2,1] ? false
    [2,0,1,1] is_alias [0,2,2,2] ? false
    [2,0,1,1] is_alias [1,0,0,0] ? false
    [2,0,1,1] is_alias [1,0,0,1] ? false
    [2,0,1,1] is_alias [1,0,0,2] ? false
    [2,0,1,1] is_alias [1,0,1,0] ? false
    [2,0,1,1] is_alias [1,0,1,1] ? false
    [2,0,1,1] is_alias [1,0,1,2] ? false
    [2,0,1,1] is_alias [1,0,2,0] ? false
    [2,0,1,1] is_alias [1,0,2,1] ? false
    [2,0,1,1] is_alias [1,0,2,2] ? false
    [2,0,1,1] is_alias [1,1,0,0] ? false
    [2,0,1,1] is_alias [1,1,0,1] ? false
    [2,0,1,1] is_alias [1,1,0,2] ? true
    [2,0,1,1] is_alias [1,1,1,0] ? false
    [2,0,1,1] is_alias [1,1,1,1] ? false
    [2,0,1,1] is_alias [1,1,1,2] ? false
    [2,0,1,1] is_alias [1,1,2,0] ? true
    [2,0,1,1] is_alias [1,1,2,1] ? false
    [2,0,1,1] is_alias [1,1,2,2] ? false
    [2,0,1,1] is_alias [1,2,0,0] ? false
    [2,0,1,1] is_alias [1,2,0,1] ? false
    [2,0,1,1] is_alias [1,2,0,2] ? false
    [2,0,1,1] is_alias [1,2,1,0] ? false
    [2,0,1,1] is_alias [1,2,1,1] ? false
    [2,0,1,1] is_alias [1,2,1,2] ? false
    [2,0,1,1] is_alias [1,2,2,0] ? false
    [2,0,1,1] is_alias [1,2,2,1] ? false
    [2,0,1,1] is_alias [1,2,2,2] ? false
    [2,0,1,1] is_alias [2,0,0,0] ? false
    [2,0,1,1] is_alias [2,0,0,1] ? false
    [2,0,1,1] is_alias [2,0,0,2] ? false
    [2,0,1,1] is_alias [2,0,1,0] ? false
    [2,0,1,1] is_alias [2,0,1,1] ? false
    [2,0,1,1] is_alias [2,0,1,2] ? false
    [2,0,1,1] is_alias [2,0,2,0] ? false
    [2,0,1,1] is_alias [2,0,2,1] ? false
    [2,0,1,1] is_alias [2,0,2,2] ? false
    [2,0,1,1] is_alias [2,1,0,0] ? false
    [2,0,1,1] is_alias [2,1,0,1] ? false
    [2,0,1,1] is_alias [2,1,0,2] ? false
    [2,0,1,1] is_alias [2,1,1,0] ? false
    [2,0,1,1] is_alias [2,1,1,1] ? false
    [2,0,1,1] is_alias [2,1,1,2] ? false
    [2,0,1,1] is_alias [2,1,2,0] ? false
    [2,0,1,1] is_alias [2,1,2,1] ? false
    [2,0,1,1] is_alias [2,1,2,2] ? false
    [2,0,1,1] is_alias [2,2,0,0] ? false
    [2,0,1,1] is_alias [2,2,0,1] ? false
    [2,0,1,1] is_alias [2,2,0,2] ? false
    [2,0,1,1] is_alias [2,2,1,0] ? false
    [2,0,1,1] is_alias [2,2,1,1] ? false
    [2,0,1,1] is_alias [2,2,1,2] ? false
    [2,0,1,1] is_alias [2,2,2,0] ? false
    [2,0,1,1] is_alias [2,2,2,1] ? false
    [2,0,1,1] is_alias [2,2,2,2] ? false
    [2,0,1,2] index has alias ? : true
    [2,0,1,2] is_alias [0,0,0,0] ? false
    [2,0,1,2] is_alias [0,0,0,1] ? false
    [2,0,1,2] is_alias [0,0,0,2] ? false
    [2,0,1,2] is_alias [0,0,1,0] ? false
    [2,0,1,2] is_alias [0,0,1,1] ? false
    [2,0,1,2] is_alias [0,0,1,2] ? false
    [2,0,1,2] is_alias [0,0,2,0] ? false
    [2,0,1,2] is_alias [0,0,2,1] ? false
    [2,0,1,2] is_alias [0,0,2,2] ? false
    [2,0,1,2] is_alias [0,1,0,0] ? false
    [2,0,1,2] is_alias [0,1,0,1] ? false
    [2,0,1,2] is_alias [0,1,0,2] ? false
    [2,0,1,2] is_alias [0,1,1,0] ? false
    [2,0,1,2] is_alias [0,1,1,1] ? false
    [2,0,1,2] is_alias [0,1,1,2] ? false
    [2,0,1,2] is_alias [0,1,2,0] ? false
    [2,0,1,2] is_alias [0,1,2,1] ? false
    [2,0,1,2] is_alias [0,1,2,2] ? false
    [2,0,1,2] is_alias [0,2,0,0] ? false
    [2,0,1,2] is_alias [0,2,0,1] ? false
    [2,0,1,2] is_alias [0,2,0,2] ? false
    [2,0,1,2] is_alias [0,2,1,0] ? false
    [2,0,1,2] is_alias [0,2,1,1] ? false
    [2,0,1,2] is_alias [0,2,1,2] ? true
    [2,0,1,2] is_alias [0,2,2,0] ? false
    [2,0,1,2] is_alias [0,2,2,1] ? true
    [2,0,1,2] is_alias [0,2,2,2] ? false
    [2,0,1,2] is_alias [1,0,0,0] ? false
    [2,0,1,2] is_alias [1,0,0,1] ? false
    [2,0,1,2] is_alias [1,0,0,2] ? false
    [2,0,1,2] is_alias [1,0,1,0] ? false
    [2,0,1,2] is_alias [1,0,1,1] ? false
    [2,0,1,2] is_alias [1,0,1,2] ? false
    [2,0,1,2] is_alias [1,0,2,0] ? false
    [2,0,1,2] is_alias [1,0,2,1] ? false
    [2,0,1,2] is_alias [1,0,2,2] ? false
    [2,0,1,2] is_alias [1,1,0,0] ? false
    [2,0,1,2] is_alias [1,1,0,1] ? false
    [2,0,1,2] is_alias [1,1,0,2] ? false
    [2,0,1,2] is_alias [1,1,1,0] ? false
    [2,0,1,2] is_alias [1,1,1,1] ? false
    [2,0,1,2] is_alias [1,1,1,2] ? false
    [2,0,1,2] is_alias [1,1,2,0] ? false
    [2,0,1,2] is_alias [1,1,2,1] ? false
    [2,0,1,2] is_alias [1,1,2,2] ? false
    [2,0,1,2] is_alias [1,2,0,0] ? false
    [2,0,1,2] is_alias [1,2,0,1] ? false
    [2,0,1,2] is_alias [1,2,0,2] ? true
    [2,0,1,2] is_alias [1,2,1,0] ? false
    [2,0,1,2] is_alias [1,2,1,1] ? false
    [2,0,1,2] is_alias [1,2,1,2] ? false
    [2,0,1,2] is_alias [1,2,2,0] ? true
    [2,0,1,2] is_alias [1,2,2,1] ? false
    [2,0,1,2] is_alias [1,2,2,2] ? false
    [2,0,1,2] is_alias [2,0,0,0] ? false
    [2,0,1,2] is_alias [2,0,0,1] ? false
    [2,0,1,2] is_alias [2,0,0,2] ? false
    [2,0,1,2] is_alias [2,0,1,0] ? false
    [2,0,1,2] is_alias [2,0,1,1] ? false
    [2,0,1,2] is_alias [2,0,1,2] ? false
    [2,0,1,2] is_alias [2,0,2,0] ? false
    [2,0,1,2] is_alias [2,0,2,1] ? true
    [2,0,1,2] is_alias [2,0,2,2] ? false
    [2,0,1,2] is_alias [2,1,0,0] ? false
    [2,0,1,2] is_alias [2,1,0,1] ? false
    [2,0,1,2] is_alias [2,1,0,2] ? true
    [2,0,1,2] is_alias [2,1,1,0] ? false
    [2,0,1,2] is_alias [2,1,1,1] ? false
    [2,0,1,2] is_alias [2,1,1,2] ? false
    [2,0,1,2] is_alias [2,1,2,0] ? true
    [2,0,1,2] is_alias [2,1,2,1] ? false
    [2,0,1,2] is_alias [2,1,2,2] ? false
    [2,0,1,2] is_alias [2,2,0,0] ? false
    [2,0,1,2] is_alias [2,2,0,1] ? false
    [2,0,1,2] is_alias [2,2,0,2] ? false
    [2,0,1,2] is_alias [2,2,1,0] ? false
    [2,0,1,2] is_alias [2,2,1,1] ? false
    [2,0,1,2] is_alias [2,2,1,2] ? false
    [2,0,1,2] is_alias [2,2,2,0] ? false
    [2,0,1,2] is_alias [2,2,2,1] ? false
    [2,0,1,2] is_alias [2,2,2,2] ? false
    [2,0,2,0] index has alias ? : true
    [2,0,2,0] is_alias [0,0,0,0] ? false
    [2,0,2,0] is_alias [0,0,0,1] ? false
    [2,0,2,0] is_alias [0,0,0,2] ? false
    [2,0,2,0] is_alias [0,0,1,0] ? false
    [2,0,2,0] is_alias [0,0,1,1] ? false
    [2,0,2,0] is_alias [0,0,1,2] ? false
    [2,0,2,0] is_alias [0,0,2,0] ? false
    [2,0,2,0] is_alias [0,0,2,1] ? false
    [2,0,2,0] is_alias [0,0,2,2] ? false
    [2,0,2,0] is_alias [0,1,0,0] ? false
    [2,0,2,0] is_alias [0,1,0,1] ? false
    [2,0,2,0] is_alias [0,1,0,2] ? false
    [2,0,2,0] is_alias [0,1,1,0] ? false
    [2,0,2,0] is_alias [0,1,1,1] ? false
    [2,0,2,0] is_alias [0,1,1,2] ? false
    [2,0,2,0] is_alias [0,1,2,0] ? false
    [2,0,2,0] is_alias [0,1,2,1] ? false
    [2,0,2,0] is_alias [0,1,2,2] ? false
    [2,0,2,0] is_alias [0,2,0,0] ? false
    [2,0,2,0] is_alias [0,2,0,1] ? false
    [2,0,2,0] is_alias [0,2,0,2] ? true
    [2,0,2,0] is_alias [0,2,1,0] ? false
    [2,0,2,0] is_alias [0,2,1,1] ? false
    [2,0,2,0] is_alias [0,2,1,2] ? false
    [2,0,2,0] is_alias [0,2,2,0] ? true
    [2,0,2,0] is_alias [0,2,2,1] ? false
    [2,0,2,0] is_alias [0,2,2,2] ? false
    [2,0,2,0] is_alias [1,0,0,0] ? false
    [2,0,2,0] is_alias [1,0,0,1] ? false
    [2,0,2,0] is_alias [1,0,0,2] ? false
    [2,0,2,0] is_alias [1,0,1,0] ? false
    [2,0,2,0] is_alias [1,0,1,1] ? false
    [2,0,2,0] is_alias [1,0,1,2] ? false
    [2,0,2,0] is_alias [1,0,2,0] ? false
    [2,0,2,0] is_alias [1,0,2,1] ? false
    [2,0,2,0] is_alias [1,0,2,2] ? false
    [2,0,2,0] is_alias [1,1,0,0] ? false
    [2,0,2,0] is_alias [1,1,0,1] ? false
    [2,0,2,0] is_alias [1,1,0,2] ? false
    [2,0,2,0] is_alias [1,1,1,0] ? false
    [2,0,2,0] is_alias [1,1,1,1] ? false
    [2,0,2,0] is_alias [1,1,1,2] ? false
    [2,0,2,0] is_alias [1,1,2,0] ? false
    [2,0,2,0] is_alias [1,1,2,1] ? false
    [2,0,2,0] is_alias [1,1,2,2] ? false
    [2,0,2,0] is_alias [1,2,0,0] ? false
    [2,0,2,0] is_alias [1,2,0,1] ? false
    [2,0,2,0] is_alias [1,2,0,2] ? false
    [2,0,2,0] is_alias [1,2,1,0] ? false
    [2,0,2,0] is_alias [1,2,1,1] ? false
    [2,0,2,0] is_alias [1,2,1,2] ? false
    [2,0,2,0] is_alias [1,2,2,0] ? false
    [2,0,2,0] is_alias [1,2,2,1] ? false
    [2,0,2,0] is_alias [1,2,2,2] ? false
    [2,0,2,0] is_alias [2,0,0,0] ? false
    [2,0,2,0] is_alias [2,0,0,1] ? false
    [2,0,2,0] is_alias [2,0,0,2] ? true
    [2,0,2,0] is_alias [2,0,1,0] ? false
    [2,0,2,0] is_alias [2,0,1,1] ? false
    [2,0,2,0] is_alias [2,0,1,2] ? false
    [2,0,2,0] is_alias [2,0,2,0] ? false
    [2,0,2,0] is_alias [2,0,2,1] ? false
    [2,0,2,0] is_alias [2,0,2,2] ? false
    [2,0,2,0] is_alias [2,1,0,0] ? false
    [2,0,2,0] is_alias [2,1,0,1] ? false
    [2,0,2,0] is_alias [2,1,0,2] ? false
    [2,0,2,0] is_alias [2,1,1,0] ? false
    [2,0,2,0] is_alias [2,1,1,1] ? false
    [2,0,2,0] is_alias [2,1,1,2] ? false
    [2,0,2,0] is_alias [2,1,2,0] ? false
    [2,0,2,0] is_alias [2,1,2,1] ? false
    [2,0,2,0] is_alias [2,1,2,2] ? false
    [2,0,2,0] is_alias [2,2,0,0] ? false
    [2,0,2,0] is_alias [2,2,0,1] ? false
    [2,0,2,0] is_alias [2,2,0,2] ? false
    [2,0,2,0] is_alias [2,2,1,0] ? false
    [2,0,2,0] is_alias [2,2,1,1] ? false
    [2,0,2,0] is_alias [2,2,1,2] ? false
    [2,0,2,0] is_alias [2,2,2,0] ? false
    [2,0,2,0] is_alias [2,2,2,1] ? false
    [2,0,2,0] is_alias [2,2,2,2] ? false
    [2,0,2,1] index has alias ? : true
    [2,0,2,1] is_alias [0,0,0,0] ? false
    [2,0,2,1] is_alias [0,0,0,1] ? false
    [2,0,2,1] is_alias [0,0,0,2] ? false
    [2,0,2,1] is_alias [0,0,1,0] ? false
    [2,0,2,1] is_alias [0,0,1,1] ? false
    [2,0,2,1] is_alias [0,0,1,2] ? false
    [2,0,2,1] is_alias [0,0,2,0] ? false
    [2,0,2,1] is_alias [0,0,2,1] ? false
    [2,0,2,1] is_alias [0,0,2,2] ? false
    [2,0,2,1] is_alias [0,1,0,0] ? false
    [2,0,2,1] is_alias [0,1,0,1] ? false
    [2,0,2,1] is_alias [0,1,0,2] ? false
    [2,0,2,1] is_alias [0,1,1,0] ? false
    [2,0,2,1] is_alias [0,1,1,1] ? false
    [2,0,2,1] is_alias [0,1,1,2] ? false
    [2,0,2,1] is_alias [0,1,2,0] ? false
    [2,0,2,1] is_alias [0,1,2,1] ? false
    [2,0,2,1] is_alias [0,1,2,2] ? false
    [2,0,2,1] is_alias [0,2,0,0] ? false
    [2,0,2,1] is_alias [0,2,0,1] ? false
    [2,0,2,1] is_alias [0,2,0,2] ? false
    [2,0,2,1] is_alias [0,2,1,0] ? false
    [2,0,2,1] is_alias [0,2,1,1] ? false
    [2,0,2,1] is_alias [0,2,1,2] ? true
    [2,0,2,1] is_alias [0,2,2,0] ? false
    [2,0,2,1] is_alias [0,2,2,1] ? true
    [2,0,2,1] is_alias [0,2,2,2] ? false
    [2,0,2,1] is_alias [1,0,0,0] ? false
    [2,0,2,1] is_alias [1,0,0,1] ? false
    [2,0,2,1] is_alias [1,0,0,2] ? false
    [2,0,2,1] is_alias [1,0,1,0] ? false
    [2,0,2,1] is_alias [1,0,1,1] ? false
    [2,0,2,1] is_alias [1,0,1,2] ? false
    [2,0,2,1] is_alias [1,0,2,0] ? false
    [2,0,2,1] is_alias [1,0,2,1] ? false
    [2,0,2,1] is_alias [1,0,2,2] ? false
    [2,0,2,1] is_alias [1,1,0,0] ? false
    [2,0,2,1] is_alias [1,1,0,1] ? false
    [2,0,2,1] is_alias [1,1,0,2] ? false
    [2,0,2,1] is_alias [1,1,1,0] ? false
    [2,0,2,1] is_alias [1,1,1,1] ? false
    [2,0,2,1] is_alias [1,1,1,2] ? false
    [2,0,2,1] is_alias [1,1,2,0] ? false
    [2,0,2,1] is_alias [1,1,2,1] ? false
    [2,0,2,1] is_alias [1,1,2,2] ? false
    [2,0,2,1] is_alias [1,2,0,0] ? false
    [2,0,2,1] is_alias [1,2,0,1] ? false
    [2,0,2,1] is_alias [1,2,0,2] ? true
    [2,0,2,1] is_alias [1,2,1,0] ? false
    [2,0,2,1] is_alias [1,2,1,1] ? false
    [2,0,2,1] is_alias [1,2,1,2] ? false
    [2,0,2,1] is_alias [1,2,2,0] ? true
    [2,0,2,1] is_alias [1,2,2,1] ? false
    [2,0,2,1] is_alias [1,2,2,2] ? false
    [2,0,2,1] is_alias [2,0,0,0] ? false
    [2,0,2,1] is_alias [2,0,0,1] ? false
    [2,0,2,1] is_alias [2,0,0,2] ? false
    [2,0,2,1] is_alias [2,0,1,0] ? false
    [2,0,2,1] is_alias [2,0,1,1] ? false
    [2,0,2,1] is_alias [2,0,1,2] ? true
    [2,0,2,1] is_alias [2,0,2,0] ? false
    [2,0,2,1] is_alias [2,0,2,1] ? false
    [2,0,2,1] is_alias [2,0,2,2] ? false
    [2,0,2,1] is_alias [2,1,0,0] ? false
    [2,0,2,1] is_alias [2,1,0,1] ? false
    [2,0,2,1] is_alias [2,1,0,2] ? true
    [2,0,2,1] is_alias [2,1,1,0] ? false
    [2,0,2,1] is_alias [2,1,1,1] ? false
    [2,0,2,1] is_alias [2,1,1,2] ? false
    [2,0,2,1] is_alias [2,1,2,0] ? true
    [2,0,2,1] is_alias [2,1,2,1] ? false
    [2,0,2,1] is_alias [2,1,2,2] ? false
    [2,0,2,1] is_alias [2,2,0,0] ? false
    [2,0,2,1] is_alias [2,2,0,1] ? false
    [2,0,2,1] is_alias [2,2,0,2] ? false
    [2,0,2,1] is_alias [2,2,1,0] ? false
    [2,0,2,1] is_alias [2,2,1,1] ? false
    [2,0,2,1] is_alias [2,2,1,2] ? false
    [2,0,2,1] is_alias [2,2,2,0] ? false
    [2,0,2,1] is_alias [2,2,2,1] ? false
    [2,0,2,1] is_alias [2,2,2,2] ? false
    [2,0,2,2] index has alias ? : true
    [2,0,2,2] is_alias [0,0,0,0] ? false
    [2,0,2,2] is_alias [0,0,0,1] ? false
    [2,0,2,2] is_alias [0,0,0,2] ? false
    [2,0,2,2] is_alias [0,0,1,0] ? false
    [2,0,2,2] is_alias [0,0,1,1] ? false
    [2,0,2,2] is_alias [0,0,1,2] ? false
    [2,0,2,2] is_alias [0,0,2,0] ? false
    [2,0,2,2] is_alias [0,0,2,1] ? false
    [2,0,2,2] is_alias [0,0,2,2] ? false
    [2,0,2,2] is_alias [0,1,0,0] ? false
    [2,0,2,2] is_alias [0,1,0,1] ? false
    [2,0,2,2] is_alias [0,1,0,2] ? false
    [2,0,2,2] is_alias [0,1,1,0] ? false
    [2,0,2,2] is_alias [0,1,1,1] ? false
    [2,0,2,2] is_alias [0,1,1,2] ? false
    [2,0,2,2] is_alias [0,1,2,0] ? false
    [2,0,2,2] is_alias [0,1,2,1] ? false
    [2,0,2,2] is_alias [0,1,2,2] ? false
    [2,0,2,2] is_alias [0,2,0,0] ? false
    [2,0,2,2] is_alias [0,2,0,1] ? false
    [2,0,2,2] is_alias [0,2,0,2] ? false
    [2,0,2,2] is_alias [0,2,1,0] ? false
    [2,0,2,2] is_alias [0,2,1,1] ? false
    [2,0,2,2] is_alias [0,2,1,2] ? false
    [2,0,2,2] is_alias [0,2,2,0] ? false
    [2,0,2,2] is_alias [0,2,2,1] ? false
    [2,0,2,2] is_alias [0,2,2,2] ? true
    [2,0,2,2] is_alias [1,0,0,0] ? false
    [2,0,2,2] is_alias [1,0,0,1] ? false
    [2,0,2,2] is_alias [1,0,0,2] ? false
    [2,0,2,2] is_alias [1,0,1,0] ? false
    [2,0,2,2] is_alias [1,0,1,1] ? false
    [2,0,2,2] is_alias [1,0,1,2] ? false
    [2,0,2,2] is_alias [1,0,2,0] ? false
    [2,0,2,2] is_alias [1,0,2,1] ? false
    [2,0,2,2] is_alias [1,0,2,2] ? false
    [2,0,2,2] is_alias [1,1,0,0] ? false
    [2,0,2,2] is_alias [1,1,0,1] ? false
    [2,0,2,2] is_alias [1,1,0,2] ? false
    [2,0,2,2] is_alias [1,1,1,0] ? false
    [2,0,2,2] is_alias [1,1,1,1] ? false
    [2,0,2,2] is_alias [1,1,1,2] ? false
    [2,0,2,2] is_alias [1,1,2,0] ? false
    [2,0,2,2] is_alias [1,1,2,1] ? false
    [2,0,2,2] is_alias [1,1,2,2] ? false
    [2,0,2,2] is_alias [1,2,0,0] ? false
    [2,0,2,2] is_alias [1,2,0,1] ? false
    [2,0,2,2] is_alias [1,2,0,2] ? false
    [2,0,2,2] is_alias [1,2,1,0] ? false
    [2,0,2,2] is_alias [1,2,1,1] ? false
    [2,0,2,2] is_alias [1,2,1,2] ? false
    [2,0,2,2] is_alias [1,2,2,0] ? false
    [2,0,2,2] is_alias [1,2,2,1] ? false
    [2,0,2,2] is_alias [1,2,2,2] ? false
    [2,0,2,2] is_alias [2,0,0,0] ? false
    [2,0,2,2] is_alias [2,0,0,1] ? false
    [2,0,2,2] is_alias [2,0,0,2] ? false
    [2,0,2,2] is_alias [2,0,1,0] ? false
    [2,0,2,2] is_alias [2,0,1,1] ? false
    [2,0,2,2] is_alias [2,0,1,2] ? false
    [2,0,2,2] is_alias [2,0,2,0] ? false
    [2,0,2,2] is_alias [2,0,2,1] ? false
    [2,0,2,2] is_alias [2,0,2,2] ? false
    [2,0,2,2] is_alias [2,1,0,0] ? false
    [2,0,2,2] is_alias [2,1,0,1] ? false
    [2,0,2,2] is_alias [2,1,0,2] ? false
    [2,0,2,2] is_alias [2,1,1,0] ? false
    [2,0,2,2] is_alias [2,1,1,1] ? false
    [2,0,2,2] is_alias [2,1,1,2] ? false
    [2,0,2,2] is_alias [2,1,2,0] ? false
    [2,0,2,2] is_alias [2,1,2,1] ? false
    [2,0,2,2] is_alias [2,1,2,2] ? false
    [2,0,2,2] is_alias [2,2,0,0] ? false
    [2,0,2,2] is_alias [2,2,0,1] ? false
    [2,0,2,2] is_alias [2,2,0,2] ? true
    [2,0,2,2] is_alias [2,2,1,0] ? false
    [2,0,2,2] is_alias [2,2,1,1] ? false
    [2,0,2,2] is_alias [2,2,1,2] ? false
    [2,0,2,2] is_alias [2,2,2,0] ? true
    [2,0,2,2] is_alias [2,2,2,1] ? false
    [2,0,2,2] is_alias [2,2,2,2] ? false
    [2,1,0,0] index has alias ? : true
    [2,1,0,0] is_alias [0,0,0,0] ? false
    [2,1,0,0] is_alias [0,0,0,1] ? false
    [2,1,0,0] is_alias [0,0,0,2] ? false
    [2,1,0,0] is_alias [0,0,1,0] ? false
    [2,1,0,0] is_alias [0,0,1,1] ? false
    [2,1,0,0] is_alias [0,0,1,2] ? true
    [2,1,0,0] is_alias [0,0,2,0] ? false
    [2,1,0,0] is_alias [0,0,2,1] ? true
    [2,1,0,0] is_alias [0,0,2,2] ? false
    [2,1,0,0] is_alias [0,1,0,0] ? false
    [2,1,0,0] is_alias [0,1,0,1] ? false
    [2,1,0,0] is_alias [0,1,0,2] ? false
    [2,1,0,0] is_alias [0,1,1,0] ? false
    [2,1,0,0] is_alias [0,1,1,1] ? false
    [2,1,0,0] is_alias [0,1,1,2] ? false
    [2,1,0,0] is_alias [0,1,2,0] ? false
    [2,1,0,0] is_alias [0,1,2,1] ? false
    [2,1,0,0] is_alias [0,1,2,2] ? false
    [2,1,0,0] is_alias [0,2,0,0] ? false
    [2,1,0,0] is_alias [0,2,0,1] ? false
    [2,1,0,0] is_alias [0,2,0,2] ? false
    [2,1,0,0] is_alias [0,2,1,0] ? false
    [2,1,0,0] is_alias [0,2,1,1] ? false
    [2,1,0,0] is_alias [0,2,1,2] ? false
    [2,1,0,0] is_alias [0,2,2,0] ? false
    [2,1,0,0] is_alias [0,2,2,1] ? false
    [2,1,0,0] is_alias [0,2,2,2] ? false
    [2,1,0,0] is_alias [1,0,0,0] ? false
    [2,1,0,0] is_alias [1,0,0,1] ? false
    [2,1,0,0] is_alias [1,0,0,2] ? false
    [2,1,0,0] is_alias [1,0,1,0] ? false
    [2,1,0,0] is_alias [1,0,1,1] ? false
    [2,1,0,0] is_alias [1,0,1,2] ? false
    [2,1,0,0] is_alias [1,0,2,0] ? false
    [2,1,0,0] is_alias [1,0,2,1] ? false
    [2,1,0,0] is_alias [1,0,2,2] ? false
    [2,1,0,0] is_alias [1,1,0,0] ? false
    [2,1,0,0] is_alias [1,1,0,1] ? false
    [2,1,0,0] is_alias [1,1,0,2] ? false
    [2,1,0,0] is_alias [1,1,1,0] ? false
    [2,1,0,0] is_alias [1,1,1,1] ? false
    [2,1,0,0] is_alias [1,1,1,2] ? false
    [2,1,0,0] is_alias [1,1,2,0] ? false
    [2,1,0,0] is_alias [1,1,2,1] ? false
    [2,1,0,0] is_alias [1,1,2,2] ? false
    [2,1,0,0] is_alias [1,2,0,0] ? true
    [2,1,0,0] is_alias [1,2,0,1] ? false
    [2,1,0,0] is_alias [1,2,0,2] ? false
    [2,1,0,0] is_alias [1,2,1,0] ? false
    [2,1,0,0] is_alias [1,2,1,1] ? false
    [2,1,0,0] is_alias [1,2,1,2] ? false
    [2,1,0,0] is_alias [1,2,2,0] ? false
    [2,1,0,0] is_alias [1,2,2,1] ? false
    [2,1,0,0] is_alias [1,2,2,2] ? false
    [2,1,0,0] is_alias [2,0,0,0] ? false
    [2,1,0,0] is_alias [2,0,0,1] ? false
    [2,1,0,0] is_alias [2,0,0,2] ? false
    [2,1,0,0] is_alias [2,0,1,0] ? false
    [2,1,0,0] is_alias [2,0,1,1] ? false
    [2,1,0,0] is_alias [2,0,1,2] ? false
    [2,1,0,0] is_alias [2,0,2,0] ? false
    [2,1,0,0] is_alias [2,0,2,1] ? false
    [2,1,0,0] is_alias [2,0,2,2] ? false
    [2,1,0,0] is_alias [2,1,0,0] ? false
    [2,1,0,0] is_alias [2,1,0,1] ? false
    [2,1,0,0] is_alias [2,1,0,2] ? false
    [2,1,0,0] is_alias [2,1,1,0] ? false
    [2,1,0,0] is_alias [2,1,1,1] ? false
    [2,1,0,0] is_alias [2,1,1,2] ? false
    [2,1,0,0] is_alias [2,1,2,0] ? false
    [2,1,0,0] is_alias [2,1,2,1] ? false
    [2,1,0,0] is_alias [2,1,2,2] ? false
    [2,1,0,0] is_alias [2,2,0,0] ? false
    [2,1,0,0] is_alias [2,2,0,1] ? false
    [2,1,0,0] is_alias [2,2,0,2] ? false
    [2,1,0,0] is_alias [2,2,1,0] ? false
    [2,1,0,0] is_alias [2,2,1,1] ? false
    [2,1,0,0] is_alias [2,2,1,2] ? false
    [2,1,0,0] is_alias [2,2,2,0] ? false
    [2,1,0,0] is_alias [2,2,2,1] ? false
    [2,1,0,0] is_alias [2,2,2,2] ? false
    [2,1,0,1] index has alias ? : true
    [2,1,0,1] is_alias [0,0,0,0] ? false
    [2,1,0,1] is_alias [0,0,0,1] ? false
    [2,1,0,1] is_alias [0,0,0,2] ? false
    [2,1,0,1] is_alias [0,0,1,0] ? false
    [2,1,0,1] is_alias [0,0,1,1] ? false
    [2,1,0,1] is_alias [0,0,1,2] ? false
    [2,1,0,1] is_alias [0,0,2,0] ? false
    [2,1,0,1] is_alias [0,0,2,1] ? false
    [2,1,0,1] is_alias [0,0,2,2] ? false
    [2,1,0,1] is_alias [0,1,0,0] ? false
    [2,1,0,1] is_alias [0,1,0,1] ? false
    [2,1,0,1] is_alias [0,1,0,2] ? false
    [2,1,0,1] is_alias [0,1,1,0] ? false
    [2,1,0,1] is_alias [0,1,1,1] ? false
    [2,1,0,1] is_alias [0,1,1,2] ? true
    [2,1,0,1] is_alias [0,1,2,0] ? false
    [2,1,0,1] is_alias [0,1,2,1] ? true
    [2,1,0,1] is_alias [0,1,2,2] ? false
    [2,1,0,1] is_alias [0,2,0,0] ? false
    [2,1,0,1] is_alias [0,2,0,1] ? false
    [2,1,0,1] is_alias [0,2,0,2] ? false
    [2,1,0,1] is_alias [0,2,1,0] ? false
    [2,1,0,1] is_alias [0,2,1,1] ? false
    [2,1,0,1] is_alias [0,2,1,2] ? false
    [2,1,0,1] is_alias [0,2,2,0] ? false
    [2,1,0,1] is_alias [0,2,2,1] ? false
    [2,1,0,1] is_alias [0,2,2,2] ? false
    [2,1,0,1] is_alias [1,0,0,0] ? false
    [2,1,0,1] is_alias [1,0,0,1] ? false
    [2,1,0,1] is_alias [1,0,0,2] ? false
    [2,1,0,1] is_alias [1,0,1,0] ? false
    [2,1,0,1] is_alias [1,0,1,1] ? false
    [2,1,0,1] is_alias [1,0,1,2] ? true
    [2,1,0,1] is_alias [1,0,2,0] ? false
    [2,1,0,1] is_alias [1,0,2,1] ? true
    [2,1,0,1] is_alias [1,0,2,2] ? false
    [2,1,0,1] is_alias [1,1,0,0] ? false
    [2,1,0,1] is_alias [1,1,0,1] ? false
    [2,1,0,1] is_alias [1,1,0,2] ? false
    [2,1,0,1] is_alias [1,1,1,0] ? false
    [2,1,0,1] is_alias [1,1,1,1] ? false
    [2,1,0,1] is_alias [1,1,1,2] ? false
    [2,1,0,1] is_alias [1,1,2,0] ? false
    [2,1,0,1] is_alias [1,1,2,1] ? false
    [2,1,0,1] is_alias [1,1,2,2] ? false
    [2,1,0,1] is_alias [1,2,0,0] ? false
    [2,1,0,1] is_alias [1,2,0,1] ? true
    [2,1,0,1] is_alias [1,2,0,2] ? false
    [2,1,0,1] is_alias [1,2,1,0] ? true
    [2,1,0,1] is_alias [1,2,1,1] ? false
    [2,1,0,1] is_alias [1,2,1,2] ? false
    [2,1,0,1] is_alias [1,2,2,0] ? false
    [2,1,0,1] is_alias [1,2,2,1] ? false
    [2,1,0,1] is_alias [1,2,2,2] ? false
    [2,1,0,1] is_alias [2,0,0,0] ? false
    [2,1,0,1] is_alias [2,0,0,1] ? false
    [2,1,0,1] is_alias [2,0,0,2] ? false
    [2,1,0,1] is_alias [2,0,1,0] ? false
    [2,1,0,1] is_alias [2,0,1,1] ? false
    [2,1,0,1] is_alias [2,0,1,2] ? false
    [2,1,0,1] is_alias [2,0,2,0] ? false
    [2,1,0,1] is_alias [2,0,2,1] ? false
    [2,1,0,1] is_alias [2,0,2,2] ? false
    [2,1,0,1] is_alias [2,1,0,0] ? false
    [2,1,0,1] is_alias [2,1,0,1] ? false
    [2,1,0,1] is_alias [2,1,0,2] ? false
    [2,1,0,1] is_alias [2,1,1,0] ? true
    [2,1,0,1] is_alias [2,1,1,1] ? false
    [2,1,0,1] is_alias [2,1,1,2] ? false
    [2,1,0,1] is_alias [2,1,2,0] ? false
    [2,1,0,1] is_alias [2,1,2,1] ? false
    [2,1,0,1] is_alias [2,1,2,2] ? false
    [2,1,0,1] is_alias [2,2,0,0] ? false
    [2,1,0,1] is_alias [2,2,0,1] ? false
    [2,1,0,1] is_alias [2,2,0,2] ? false
    [2,1,0,1] is_alias [2,2,1,0] ? false
    [2,1,0,1] is_alias [2,2,1,1] ? false
    [2,1,0,1] is_alias [2,2,1,2] ? false
    [2,1,0,1] is_alias [2,2,2,0] ? false
    [2,1,0,1] is_alias [2,2,2,1] ? false
    [2,1,0,1] is_alias [2,2,2,2] ? false
    [2,1,0,2] index has alias ? : true
    [2,1,0,2] is_alias [0,0,0,0] ? false
    [2,1,0,2] is_alias [0,0,0,1] ? false
    [2,1,0,2] is_alias [0,0,0,2] ? false
    [2,1,0,2] is_alias [0,0,1,0] ? false
    [2,1,0,2] is_alias [0,0,1,1] ? false
    [2,1,0,2] is_alias [0,0,1,2] ? false
    [2,1,0,2] is_alias [0,0,2,0] ? false
    [2,1,0,2] is_alias [0,0,2,1] ? false
    [2,1,0,2] is_alias [0,0,2,2] ? false
    [2,1,0,2] is_alias [0,1,0,0] ? false
    [2,1,0,2] is_alias [0,1,0,1] ? false
    [2,1,0,2] is_alias [0,1,0,2] ? false
    [2,1,0,2] is_alias [0,1,1,0] ? false
    [2,1,0,2] is_alias [0,1,1,1] ? false
    [2,1,0,2] is_alias [0,1,1,2] ? false
    [2,1,0,2] is_alias [0,1,2,0] ? false
    [2,1,0,2] is_alias [0,1,2,1] ? false
    [2,1,0,2] is_alias [0,1,2,2] ? false
    [2,1,0,2] is_alias [0,2,0,0] ? false
    [2,1,0,2] is_alias [0,2,0,1] ? false
    [2,1,0,2] is_alias [0,2,0,2] ? false
    [2,1,0,2] is_alias [0,2,1,0] ? false
    [2,1,0,2] is_alias [0,2,1,1] ? false
    [2,1,0,2] is_alias [0,2,1,2] ? true
    [2,1,0,2] is_alias [0,2,2,0] ? false
    [2,1,0,2] is_alias [0,2,2,1] ? true
    [2,1,0,2] is_alias [0,2,2,2] ? false
    [2,1,0,2] is_alias [1,0,0,0] ? false
    [2,1,0,2] is_alias [1,0,0,1] ? false
    [2,1,0,2] is_alias [1,0,0,2] ? false
    [2,1,0,2] is_alias [1,0,1,0] ? false
    [2,1,0,2] is_alias [1,0,1,1] ? false
    [2,1,0,2] is_alias [1,0,1,2] ? false
    [2,1,0,2] is_alias [1,0,2,0] ? false
    [2,1,0,2] is_alias [1,0,2,1] ? false
    [2,1,0,2] is_alias [1,0,2,2] ? false
    [2,1,0,2] is_alias [1,1,0,0] ? false
    [2,1,0,2] is_alias [1,1,0,1] ? false
    [2,1,0,2] is_alias [1,1,0,2] ? false
    [2,1,0,2] is_alias [1,1,1,0] ? false
    [2,1,0,2] is_alias [1,1,1,1] ? false
    [2,1,0,2] is_alias [1,1,1,2] ? false
    [2,1,0,2] is_alias [1,1,2,0] ? false
    [2,1,0,2] is_alias [1,1,2,1] ? false
    [2,1,0,2] is_alias [1,1,2,2] ? false
    [2,1,0,2] is_alias [1,2,0,0] ? false
    [2,1,0,2] is_alias [1,2,0,1] ? false
    [2,1,0,2] is_alias [1,2,0,2] ? true
    [2,1,0,2] is_alias [1,2,1,0] ? false
    [2,1,0,2] is_alias [1,2,1,1] ? false
    [2,1,0,2] is_alias [1,2,1,2] ? false
    [2,1,0,2] is_alias [1,2,2,0] ? true
    [2,1,0,2] is_alias [1,2,2,1] ? false
    [2,1,0,2] is_alias [1,2,2,2] ? false
    [2,1,0,2] is_alias [2,0,0,0] ? false
    [2,1,0,2] is_alias [2,0,0,1] ? false
    [2,1,0,2] is_alias [2,0,0,2] ? false
    [2,1,0,2] is_alias [2,0,1,0] ? false
    [2,1,0,2] is_alias [2,0,1,1] ? false
    [2,1,0,2] is_alias [2,0,1,2] ? true
    [2,1,0,2] is_alias [2,0,2,0] ? false
    [2,1,0,2] is_alias [2,0,2,1] ? true
    [2,1,0,2] is_alias [2,0,2,2] ? false
    [2,1,0,2] is_alias [2,1,0,0] ? false
    [2,1,0,2] is_alias [2,1,0,1] ? false
    [2,1,0,2] is_alias [2,1,0,2] ? false
    [2,1,0,2] is_alias [2,1,1,0] ? false
    [2,1,0,2] is_alias [2,1,1,1] ? false
    [2,1,0,2] is_alias [2,1,1,2] ? false
    [2,1,0,2] is_alias [2,1,2,0] ? true
    [2,1,0,2] is_alias [2,1,2,1] ? false
    [2,1,0,2] is_alias [2,1,2,2] ? false
    [2,1,0,2] is_alias [2,2,0,0] ? false
    [2,1,0,2] is_alias [2,2,0,1] ? false
    [2,1,0,2] is_alias [2,2,0,2] ? false
    [2,1,0,2] is_alias [2,2,1,0] ? false
    [2,1,0,2] is_alias [2,2,1,1] ? false
    [2,1,0,2] is_alias [2,2,1,2] ? false
    [2,1,0,2] is_alias [2,2,2,0] ? false
    [2,1,0,2] is_alias [2,2,2,1] ? false
    [2,1,0,2] is_alias [2,2,2,2] ? false
    [2,1,1,0] index has alias ? : true
    [2,1,1,0] is_alias [0,0,0,0] ? false
    [2,1,1,0] is_alias [0,0,0,1] ? false
    [2,1,1,0] is_alias [0,0,0,2] ? false
    [2,1,1,0] is_alias [0,0,1,0] ? false
    [2,1,1,0] is_alias [0,0,1,1] ? false
    [2,1,1,0] is_alias [0,0,1,2] ? false
    [2,1,1,0] is_alias [0,0,2,0] ? false
    [2,1,1,0] is_alias [0,0,2,1] ? false
    [2,1,1,0] is_alias [0,0,2,2] ? false
    [2,1,1,0] is_alias [0,1,0,0] ? false
    [2,1,1,0] is_alias [0,1,0,1] ? false
    [2,1,1,0] is_alias [0,1,0,2] ? false
    [2,1,1,0] is_alias [0,1,1,0] ? false
    [2,1,1,0] is_alias [0,1,1,1] ? false
    [2,1,1,0] is_alias [0,1,1,2] ? true
    [2,1,1,0] is_alias [0,1,2,0] ? false
    [2,1,1,0] is_alias [0,1,2,1] ? true
    [2,1,1,0] is_alias [0,1,2,2] ? false
    [2,1,1,0] is_alias [0,2,0,0] ? false
    [2,1,1,0] is_alias [0,2,0,1] ? false
    [2,1,1,0] is_alias [0,2,0,2] ? false
    [2,1,1,0] is_alias [0,2,1,0] ? false
    [2,1,1,0] is_alias [0,2,1,1] ? false
    [2,1,1,0] is_alias [0,2,1,2] ? false
    [2,1,1,0] is_alias [0,2,2,0] ? false
    [2,1,1,0] is_alias [0,2,2,1] ? false
    [2,1,1,0] is_alias [0,2,2,2] ? false
    [2,1,1,0] is_alias [1,0,0,0] ? false
    [2,1,1,0] is_alias [1,0,0,1] ? false
    [2,1,1,0] is_alias [1,0,0,2] ? false
    [2,1,1,0] is_alias [1,0,1,0] ? false
    [2,1,1,0] is_alias [1,0,1,1] ? false
    [2,1,1,0] is_alias [1,0,1,2] ? true
    [2,1,1,0] is_alias [1,0,2,0] ? false
    [2,1,1,0] is_alias [1,0,2,1] ? true
    [2,1,1,0] is_alias [1,0,2,2] ? false
    [2,1,1,0] is_alias [1,1,0,0] ? false
    [2,1,1,0] is_alias [1,1,0,1] ? false
    [2,1,1,0] is_alias [1,1,0,2] ? false
    [2,1,1,0] is_alias [1,1,1,0] ? false
    [2,1,1,0] is_alias [1,1,1,1] ? false
    [2,1,1,0] is_alias [1,1,1,2] ? false
    [2,1,1,0] is_alias [1,1,2,0] ? false
    [2,1,1,0] is_alias [1,1,2,1] ? false
    [2,1,1,0] is_alias [1,1,2,2] ? false
    [2,1,1,0] is_alias [1,2,0,0] ? false
    [2,1,1,0] is_alias [1,2,0,1] ? true
    [2,1,1,0] is_alias [1,2,0,2] ? false
    [2,1,1,0] is_alias [1,2,1,0] ? true
    [2,1,1,0] is_alias [1,2,1,1] ? false
    [2,1,1,0] is_alias [1,2,1,2] ? false
    [2,1,1,0] is_alias [1,2,2,0] ? false
    [2,1,1,0] is_alias [1,2,2,1] ? false
    [2,1,1,0] is_alias [1,2,2,2] ? false
    [2,1,1,0] is_alias [2,0,0,0] ? false
    [2,1,1,0] is_alias [2,0,0,1] ? false
    [2,1,1,0] is_alias [2,0,0,2] ? false
    [2,1,1,0] is_alias [2,0,1,0] ? false
    [2,1,1,0] is_alias [2,0,1,1] ? false
    [2,1,1,0] is_alias [2,0,1,2] ? false
    [2,1,1,0] is_alias [2,0,2,0] ? false
    [2,1,1,0] is_alias [2,0,2,1] ? false
    [2,1,1,0] is_alias [2,0,2,2] ? false
    [2,1,1,0] is_alias [2,1,0,0] ? false
    [2,1,1,0] is_alias [2,1,0,1] ? true
    [2,1,1,0] is_alias [2,1,0,2] ? false
    [2,1,1,0] is_alias [2,1,1,0] ? false
    [2,1,1,0] is_alias [2,1,1,1] ? false
    [2,1,1,0] is_alias [2,1,1,2] ? false
    [2,1,1,0] is_alias [2,1,2,0] ? false
    [2,1,1,0] is_alias [2,1,2,1] ? false
    [2,1,1,0] is_alias [2,1,2,2] ? false
    [2,1,1,0] is_alias [2,2,0,0] ? false
    [2,1,1,0] is_alias [2,2,0,1] ? false
    [2,1,1,0] is_alias [2,2,0,2] ? false
    [2,1,1,0] is_alias [2,2,1,0] ? false
    [2,1,1,0] is_alias [2,2,1,1] ? false
    [2,1,1,0] is_alias [2,2,1,2] ? false
    [2,1,1,0] is_alias [2,2,2,0] ? false
    [2,1,1,0] is_alias [2,2,2,1] ? false
    [2,1,1,0] is_alias [2,2,2,2] ? false
    [2,1,1,1] index has alias ? : true
    [2,1,1,1] is_alias [0,0,0,0] ? false
    [2,1,1,1] is_alias [0,0,0,1] ? false
    [2,1,1,1] is_alias [0,0,0,2] ? false
    [2,1,1,1] is_alias [0,0,1,0] ? false
    [2,1,1,1] is_alias [0,0,1,1] ? false
    [2,1,1,1] is_alias [0,0,1,2] ? false
    [2,1,1,1] is_alias [0,0,2,0] ? false
    [2,1,1,1] is_alias [0,0,2,1] ? false
    [2,1,1,1] is_alias [0,0,2,2] ? false
    [2,1,1,1] is_alias [0,1,0,0] ? false
    [2,1,1,1] is_alias [0,1,0,1] ? false
    [2,1,1,1] is_alias [0,1,0,2] ? false
    [2,1,1,1] is_alias [0,1,1,0] ? false
    [2,1,1,1] is_alias [0,1,1,1] ? false
    [2,1,1,1] is_alias [0,1,1,2] ? false
    [2,1,1,1] is_alias [0,1,2,0] ? false
    [2,1,1,1] is_alias [0,1,2,1] ? false
    [2,1,1,1] is_alias [0,1,2,2] ? false
    [2,1,1,1] is_alias [0,2,0,0] ? false
    [2,1,1,1] is_alias [0,2,0,1] ? false
    [2,1,1,1] is_alias [0,2,0,2] ? false
    [2,1,1,1] is_alias [0,2,1,0] ? false
    [2,1,1,1] is_alias [0,2,1,1] ? false
    [2,1,1,1] is_alias [0,2,1,2] ? false
    [2,1,1,1] is_alias [0,2,2,0] ? false
    [2,1,1,1] is_alias [0,2,2,1] ? false
    [2,1,1,1] is_alias [0,2,2,2] ? false
    [2,1,1,1] is_alias [1,0,0,0] ? false
    [2,1,1,1] is_alias [1,0,0,1] ? false
    [2,1,1,1] is_alias [1,0,0,2] ? false
    [2,1,1,1] is_alias [1,0,1,0] ? false
    [2,1,1,1] is_alias [1,0,1,1] ? false
    [2,1,1,1] is_alias [1,0,1,2] ? false
    [2,1,1,1] is_alias [1,0,2,0] ? false
    [2,1,1,1] is_alias [1,0,2,1] ? false
    [2,1,1,1] is_alias [1,0,2,2] ? false
    [2,1,1,1] is_alias [1,1,0,0] ? false
    [2,1,1,1] is_alias [1,1,0,1] ? false
    [2,1,1,1] is_alias [1,1,0,2] ? false
    [2,1,1,1] is_alias [1,1,1,0] ? false
    [2,1,1,1] is_alias [1,1,1,1] ? false
    [2,1,1,1] is_alias [1,1,1,2] ? true
    [2,1,1,1] is_alias [1,1,2,0] ? false
    [2,1,1,1] is_alias [1,1,2,1] ? true
    [2,1,1,1] is_alias [1,1,2,2] ? false
    [2,1,1,1] is_alias [1,2,0,0] ? false
    [2,1,1,1] is_alias [1,2,0,1] ? false
    [2,1,1,1] is_alias [1,2,0,2] ? false
    [2,1,1,1] is_alias [1,2,1,0] ? false
    [2,1,1,1] is_alias [1,2,1,1] ? true
    [2,1,1,1] is_alias [1,2,1,2] ? false
    [2,1,1,1] is_alias [1,2,2,0] ? false
    [2,1,1,1] is_alias [1,2,2,1] ? false
    [2,1,1,1] is_alias [1,2,2,2] ? false
    [2,1,1,1] is_alias [2,0,0,0] ? false
    [2,1,1,1] is_alias [2,0,0,1] ? false
    [2,1,1,1] is_alias [2,0,0,2] ? false
    [2,1,1,1] is_alias [2,0,1,0] ? false
    [2,1,1,1] is_alias [2,0,1,1] ? false
    [2,1,1,1] is_alias [2,0,1,2] ? false
    [2,1,1,1] is_alias [2,0,2,0] ? false
    [2,1,1,1] is_alias [2,0,2,1] ? false
    [2,1,1,1] is_alias [2,0,2,2] ? false
    [2,1,1,1] is_alias [2,1,0,0] ? false
    [2,1,1,1] is_alias [2,1,0,1] ? false
    [2,1,1,1] is_alias [2,1,0,2] ? false
    [2,1,1,1] is_alias [2,1,1,0] ? false
    [2,1,1,1] is_alias [2,1,1,1] ? false
    [2,1,1,1] is_alias [2,1,1,2] ? false
    [2,1,1,1] is_alias [2,1,2,0] ? false
    [2,1,1,1] is_alias [2,1,2,1] ? false
    [2,1,1,1] is_alias [2,1,2,2] ? false
    [2,1,1,1] is_alias [2,2,0,0] ? false
    [2,1,1,1] is_alias [2,2,0,1] ? false
    [2,1,1,1] is_alias [2,2,0,2] ? false
    [2,1,1,1] is_alias [2,2,1,0] ? false
    [2,1,1,1] is_alias [2,2,1,1] ? false
    [2,1,1,1] is_alias [2,2,1,2] ? false
    [2,1,1,1] is_alias [2,2,2,0] ? false
    [2,1,1,1] is_alias [2,2,2,1] ? false
    [2,1,1,1] is_alias [2,2,2,2] ? false
    [2,1,1,2] index has alias ? : true
    [2,1,1,2] is_alias [0,0,0,0] ? false
    [2,1,1,2] is_alias [0,0,0,1] ? false
    [2,1,1,2] is_alias [0,0,0,2] ? false
    [2,1,1,2] is_alias [0,0,1,0] ? false
    [2,1,1,2] is_alias [0,0,1,1] ? false
    [2,1,1,2] is_alias [0,0,1,2] ? false
    [2,1,1,2] is_alias [0,0,2,0] ? false
    [2,1,1,2] is_alias [0,0,2,1] ? false
    [2,1,1,2] is_alias [0,0,2,2] ? false
    [2,1,1,2] is_alias [0,1,0,0] ? false
    [2,1,1,2] is_alias [0,1,0,1] ? false
    [2,1,1,2] is_alias [0,1,0,2] ? false
    [2,1,1,2] is_alias [0,1,1,0] ? false
    [2,1,1,2] is_alias [0,1,1,1] ? false
    [2,1,1,2] is_alias [0,1,1,2] ? false
    [2,1,1,2] is_alias [0,1,2,0] ? false
    [2,1,1,2] is_alias [0,1,2,1] ? false
    [2,1,1,2] is_alias [0,1,2,2] ? false
    [2,1,1,2] is_alias [0,2,0,0] ? false
    [2,1,1,2] is_alias [0,2,0,1] ? false
    [2,1,1,2] is_alias [0,2,0,2] ? false
    [2,1,1,2] is_alias [0,2,1,0] ? false
    [2,1,1,2] is_alias [0,2,1,1] ? false
    [2,1,1,2] is_alias [0,2,1,2] ? false
    [2,1,1,2] is_alias [0,2,2,0] ? false
    [2,1,1,2] is_alias [0,2,2,1] ? false
    [2,1,1,2] is_alias [0,2,2,2] ? false
    [2,1,1,2] is_alias [1,0,0,0] ? false
    [2,1,1,2] is_alias [1,0,0,1] ? false
    [2,1,1,2] is_alias [1,0,0,2] ? false
    [2,1,1,2] is_alias [1,0,1,0] ? false
    [2,1,1,2] is_alias [1,0,1,1] ? false
    [2,1,1,2] is_alias [1,0,1,2] ? false
    [2,1,1,2] is_alias [1,0,2,0] ? false
    [2,1,1,2] is_alias [1,0,2,1] ? false
    [2,1,1,2] is_alias [1,0,2,2] ? false
    [2,1,1,2] is_alias [1,1,0,0] ? false
    [2,1,1,2] is_alias [1,1,0,1] ? false
    [2,1,1,2] is_alias [1,1,0,2] ? false
    [2,1,1,2] is_alias [1,1,1,0] ? false
    [2,1,1,2] is_alias [1,1,1,1] ? false
    [2,1,1,2] is_alias [1,1,1,2] ? false
    [2,1,1,2] is_alias [1,1,2,0] ? false
    [2,1,1,2] is_alias [1,1,2,1] ? false
    [2,1,1,2] is_alias [1,1,2,2] ? false
    [2,1,1,2] is_alias [1,2,0,0] ? false
    [2,1,1,2] is_alias [1,2,0,1] ? false
    [2,1,1,2] is_alias [1,2,0,2] ? false
    [2,1,1,2] is_alias [1,2,1,0] ? false
    [2,1,1,2] is_alias [1,2,1,1] ? false
    [2,1,1,2] is_alias [1,2,1,2] ? true
    [2,1,1,2] is_alias [1,2,2,0] ? false
    [2,1,1,2] is_alias [1,2,2,1] ? true
    [2,1,1,2] is_alias [1,2,2,2] ? false
    [2,1,1,2] is_alias [2,0,0,0] ? false
    [2,1,1,2] is_alias [2,0,0,1] ? false
    [2,1,1,2] is_alias [2,0,0,2] ? false
    [2,1,1,2] is_alias [2,0,1,0] ? false
    [2,1,1,2] is_alias [2,0,1,1] ? false
    [2,1,1,2] is_alias [2,0,1,2] ? false
    [2,1,1,2] is_alias [2,0,2,0] ? false
    [2,1,1,2] is_alias [2,0,2,1] ? false
    [2,1,1,2] is_alias [2,0,2,2] ? false
    [2,1,1,2] is_alias [2,1,0,0] ? false
    [2,1,1,2] is_alias [2,1,0,1] ? false
    [2,1,1,2] is_alias [2,1,0,2] ? false
    [2,1,1,2] is_alias [2,1,1,0] ? false
    [2,1,1,2] is_alias [2,1,1,1] ? false
    [2,1,1,2] is_alias [2,1,1,2] ? false
    [2,1,1,2] is_alias [2,1,2,0] ? false
    [2,1,1,2] is_alias [2,1,2,1] ? true
    [2,1,1,2] is_alias [2,1,2,2] ? false
    [2,1,1,2] is_alias [2,2,0,0] ? false
    [2,1,1,2] is_alias [2,2,0,1] ? false
    [2,1,1,2] is_alias [2,2,0,2] ? false
    [2,1,1,2] is_alias [2,2,1,0] ? false
    [2,1,1,2] is_alias [2,2,1,1] ? false
    [2,1,1,2] is_alias [2,2,1,2] ? false
    [2,1,1,2] is_alias [2,2,2,0] ? false
    [2,1,1,2] is_alias [2,2,2,1] ? false
    [2,1,1,2] is_alias [2,2,2,2] ? false
    [2,1,2,0] index has alias ? : true
    [2,1,2,0] is_alias [0,0,0,0] ? false
    [2,1,2,0] is_alias [0,0,0,1] ? false
    [2,1,2,0] is_alias [0,0,0,2] ? false
    [2,1,2,0] is_alias [0,0,1,0] ? false
    [2,1,2,0] is_alias [0,0,1,1] ? false
    [2,1,2,0] is_alias [0,0,1,2] ? false
    [2,1,2,0] is_alias [0,0,2,0] ? false
    [2,1,2,0] is_alias [0,0,2,1] ? false
    [2,1,2,0] is_alias [0,0,2,2] ? false
    [2,1,2,0] is_alias [0,1,0,0] ? false
    [2,1,2,0] is_alias [0,1,0,1] ? false
    [2,1,2,0] is_alias [0,1,0,2] ? false
    [2,1,2,0] is_alias [0,1,1,0] ? false
    [2,1,2,0] is_alias [0,1,1,1] ? false
    [2,1,2,0] is_alias [0,1,1,2] ? false
    [2,1,2,0] is_alias [0,1,2,0] ? false
    [2,1,2,0] is_alias [0,1,2,1] ? false
    [2,1,2,0] is_alias [0,1,2,2] ? false
    [2,1,2,0] is_alias [0,2,0,0] ? false
    [2,1,2,0] is_alias [0,2,0,1] ? false
    [2,1,2,0] is_alias [0,2,0,2] ? false
    [2,1,2,0] is_alias [0,2,1,0] ? false
    [2,1,2,0] is_alias [0,2,1,1] ? false
    [2,1,2,0] is_alias [0,2,1,2] ? true
    [2,1,2,0] is_alias [0,2,2,0] ? false
    [2,1,2,0] is_alias [0,2,2,1] ? true
    [2,1,2,0] is_alias [0,2,2,2] ? false
    [2,1,2,0] is_alias [1,0,0,0] ? false
    [2,1,2,0] is_alias [1,0,0,1] ? false
    [2,1,2,0] is_alias [1,0,0,2] ? false
    [2,1,2,0] is_alias [1,0,1,0] ? false
    [2,1,2,0] is_alias [1,0,1,1] ? false
    [2,1,2,0] is_alias [1,0,1,2] ? false
    [2,1,2,0] is_alias [1,0,2,0] ? false
    [2,1,2,0] is_alias [1,0,2,1] ? false
    [2,1,2,0] is_alias [1,0,2,2] ? false
    [2,1,2,0] is_alias [1,1,0,0] ? false
    [2,1,2,0] is_alias [1,1,0,1] ? false
    [2,1,2,0] is_alias [1,1,0,2] ? false
    [2,1,2,0] is_alias [1,1,1,0] ? false
    [2,1,2,0] is_alias [1,1,1,1] ? false
    [2,1,2,0] is_alias [1,1,1,2] ? false
    [2,1,2,0] is_alias [1,1,2,0] ? false
    [2,1,2,0] is_alias [1,1,2,1] ? false
    [2,1,2,0] is_alias [1,1,2,2] ? false
    [2,1,2,0] is_alias [1,2,0,0] ? false
    [2,1,2,0] is_alias [1,2,0,1] ? false
    [2,1,2,0] is_alias [1,2,0,2] ? true
    [2,1,2,0] is_alias [1,2,1,0] ? false
    [2,1,2,0] is_alias [1,2,1,1] ? false
    [2,1,2,0] is_alias [1,2,1,2] ? false
    [2,1,2,0] is_alias [1,2,2,0] ? true
    [2,1,2,0] is_alias [1,2,2,1] ? false
    [2,1,2,0] is_alias [1,2,2,2] ? false
    [2,1,2,0] is_alias [2,0,0,0] ? false
    [2,1,2,0] is_alias [2,0,0,1] ? false
    [2,1,2,0] is_alias [2,0,0,2] ? false
    [2,1,2,0] is_alias [2,0,1,0] ? false
    [2,1,2,0] is_alias [2,0,1,1] ? false
    [2,1,2,0] is_alias [2,0,1,2] ? true
    [2,1,2,0] is_alias [2,0,2,0] ? false
    [2,1,2,0] is_alias [2,0,2,1] ? true
    [2,1,2,0] is_alias [2,0,2,2] ? false
    [2,1,2,0] is_alias [2,1,0,0] ? false
    [2,1,2,0] is_alias [2,1,0,1] ? false
    [2,1,2,0] is_alias [2,1,0,2] ? true
    [2,1,2,0] is_alias [2,1,1,0] ? false
    [2,1,2,0] is_alias [2,1,1,1] ? false
    [2,1,2,0] is_alias [2,1,1,2] ? false
    [2,1,2,0] is_alias [2,1,2,0] ? false
    [2,1,2,0] is_alias [2,1,2,1] ? false
    [2,1,2,0] is_alias [2,1,2,2] ? false
    [2,1,2,0] is_alias [2,2,0,0] ? false
    [2,1,2,0] is_alias [2,2,0,1] ? false
    [2,1,2,0] is_alias [2,2,0,2] ? false
    [2,1,2,0] is_alias [2,2,1,0] ? false
    [2,1,2,0] is_alias [2,2,1,1] ? false
    [2,1,2,0] is_alias [2,2,1,2] ? false
    [2,1,2,0] is_alias [2,2,2,0] ? false
    [2,1,2,0] is_alias [2,2,2,1] ? false
    [2,1,2,0] is_alias [2,2,2,2] ? false
    [2,1,2,1] index has alias ? : true
    [2,1,2,1] is_alias [0,0,0,0] ? false
    [2,1,2,1] is_alias [0,0,0,1] ? false
    [2,1,2,1] is_alias [0,0,0,2] ? false
    [2,1,2,1] is_alias [0,0,1,0] ? false
    [2,1,2,1] is_alias [0,0,1,1] ? false
    [2,1,2,1] is_alias [0,0,1,2] ? false
    [2,1,2,1] is_alias [0,0,2,0] ? false
    [2,1,2,1] is_alias [0,0,2,1] ? false
    [2,1,2,1] is_alias [0,0,2,2] ? false
    [2,1,2,1] is_alias [0,1,0,0] ? false
    [2,1,2,1] is_alias [0,1,0,1] ? false
    [2,1,2,1] is_alias [0,1,0,2] ? false
    [2,1,2,1] is_alias [0,1,1,0] ? false
    [2,1,2,1] is_alias [0,1,1,1] ? false
    [2,1,2,1] is_alias [0,1,1,2] ? false
    [2,1,2,1] is_alias [0,1,2,0] ? false
    [2,1,2,1] is_alias [0,1,2,1] ? false
    [2,1,2,1] is_alias [0,1,2,2] ? false
    [2,1,2,1] is_alias [0,2,0,0] ? false
    [2,1,2,1] is_alias [0,2,0,1] ? false
    [2,1,2,1] is_alias [0,2,0,2] ? false
    [2,1,2,1] is_alias [0,2,1,0] ? false
    [2,1,2,1] is_alias [0,2,1,1] ? false
    [2,1,2,1] is_alias [0,2,1,2] ? false
    [2,1,2,1] is_alias [0,2,2,0] ? false
    [2,1,2,1] is_alias [0,2,2,1] ? false
    [2,1,2,1] is_alias [0,2,2,2] ? false
    [2,1,2,1] is_alias [1,0,0,0] ? false
    [2,1,2,1] is_alias [1,0,0,1] ? false
    [2,1,2,1] is_alias [1,0,0,2] ? false
    [2,1,2,1] is_alias [1,0,1,0] ? false
    [2,1,2,1] is_alias [1,0,1,1] ? false
    [2,1,2,1] is_alias [1,0,1,2] ? false
    [2,1,2,1] is_alias [1,0,2,0] ? false
    [2,1,2,1] is_alias [1,0,2,1] ? false
    [2,1,2,1] is_alias [1,0,2,2] ? false
    [2,1,2,1] is_alias [1,1,0,0] ? false
    [2,1,2,1] is_alias [1,1,0,1] ? false
    [2,1,2,1] is_alias [1,1,0,2] ? false
    [2,1,2,1] is_alias [1,1,1,0] ? false
    [2,1,2,1] is_alias [1,1,1,1] ? false
    [2,1,2,1] is_alias [1,1,1,2] ? false
    [2,1,2,1] is_alias [1,1,2,0] ? false
    [2,1,2,1] is_alias [1,1,2,1] ? false
    [2,1,2,1] is_alias [1,1,2,2] ? false
    [2,1,2,1] is_alias [1,2,0,0] ? false
    [2,1,2,1] is_alias [1,2,0,1] ? false
    [2,1,2,1] is_alias [1,2,0,2] ? false
    [2,1,2,1] is_alias [1,2,1,0] ? false
    [2,1,2,1] is_alias [1,2,1,1] ? false
    [2,1,2,1] is_alias [1,2,1,2] ? true
    [2,1,2,1] is_alias [1,2,2,0] ? false
    [2,1,2,1] is_alias [1,2,2,1] ? true
    [2,1,2,1] is_alias [1,2,2,2] ? false
    [2,1,2,1] is_alias [2,0,0,0] ? false
    [2,1,2,1] is_alias [2,0,0,1] ? false
    [2,1,2,1] is_alias [2,0,0,2] ? false
    [2,1,2,1] is_alias [2,0,1,0] ? false
    [2,1,2,1] is_alias [2,0,1,1] ? false
    [2,1,2,1] is_alias [2,0,1,2] ? false
    [2,1,2,1] is_alias [2,0,2,0] ? false
    [2,1,2,1] is_alias [2,0,2,1] ? false
    [2,1,2,1] is_alias [2,0,2,2] ? false
    [2,1,2,1] is_alias [2,1,0,0] ? false
    [2,1,2,1] is_alias [2,1,0,1] ? false
    [2,1,2,1] is_alias [2,1,0,2] ? false
    [2,1,2,1] is_alias [2,1,1,0] ? false
    [2,1,2,1] is_alias [2,1,1,1] ? false
    [2,1,2,1] is_alias [2,1,1,2] ? true
    [2,1,2,1] is_alias [2,1,2,0] ? false
    [2,1,2,1] is_alias [2,1,2,1] ? false
    [2,1,2,1] is_alias [2,1,2,2] ? false
    [2,1,2,1] is_alias [2,2,0,0] ? false
    [2,1,2,1] is_alias [2,2,0,1] ? false
    [2,1,2,1] is_alias [2,2,0,2] ? false
    [2,1,2,1] is_alias [2,2,1,0] ? false
    [2,1,2,1] is_alias [2,2,1,1] ? false
    [2,1,2,1] is_alias [2,2,1,2] ? false
    [2,1,2,1] is_alias [2,2,2,0] ? false
    [2,1,2,1] is_alias [2,2,2,1] ? false
    [2,1,2,1] is_alias [2,2,2,2] ? false
    [2,1,2,2] index has alias ? : true
    [2,1,2,2] is_alias [0,0,0,0] ? false
    [2,1,2,2] is_alias [0,0,0,1] ? false
    [2,1,2,2] is_alias [0,0,0,2] ? false
    [2,1,2,2] is_alias [0,0,1,0] ? false
    [2,1,2,2] is_alias [0,0,1,1] ? false
    [2,1,2,2] is_alias [0,0,1,2] ? false
    [2,1,2,2] is_alias [0,0,2,0] ? false
    [2,1,2,2] is_alias [0,0,2,1] ? false
    [2,1,2,2] is_alias [0,0,2,2] ? false
    [2,1,2,2] is_alias [0,1,0,0] ? false
    [2,1,2,2] is_alias [0,1,0,1] ? false
    [2,1,2,2] is_alias [0,1,0,2] ? false
    [2,1,2,2] is_alias [0,1,1,0] ? false
    [2,1,2,2] is_alias [0,1,1,1] ? false
    [2,1,2,2] is_alias [0,1,1,2] ? false
    [2,1,2,2] is_alias [0,1,2,0] ? false
    [2,1,2,2] is_alias [0,1,2,1] ? false
    [2,1,2,2] is_alias [0,1,2,2] ? false
    [2,1,2,2] is_alias [0,2,0,0] ? false
    [2,1,2,2] is_alias [0,2,0,1] ? false
    [2,1,2,2] is_alias [0,2,0,2] ? false
    [2,1,2,2] is_alias [0,2,1,0] ? false
    [2,1,2,2] is_alias [0,2,1,1] ? false
    [2,1,2,2] is_alias [0,2,1,2] ? false
    [2,1,2,2] is_alias [0,2,2,0] ? false
    [2,1,2,2] is_alias [0,2,2,1] ? false
    [2,1,2,2] is_alias [0,2,2,2] ? false
    [2,1,2,2] is_alias [1,0,0,0] ? false
    [2,1,2,2] is_alias [1,0,0,1] ? false
    [2,1,2,2] is_alias [1,0,0,2] ? false
    [2,1,2,2] is_alias [1,0,1,0] ? false
    [2,1,2,2] is_alias [1,0,1,1] ? false
    [2,1,2,2] is_alias [1,0,1,2] ? false
    [2,1,2,2] is_alias [1,0,2,0] ? false
    [2,1,2,2] is_alias [1,0,2,1] ? false
    [2,1,2,2] is_alias [1,0,2,2] ? false
    [2,1,2,2] is_alias [1,1,0,0] ? false
    [2,1,2,2] is_alias [1,1,0,1] ? false
    [2,1,2,2] is_alias [1,1,0,2] ? false
    [2,1,2,2] is_alias [1,1,1,0] ? false
    [2,1,2,2] is_alias [1,1,1,1] ? false
    [2,1,2,2] is_alias [1,1,1,2] ? false
    [2,1,2,2] is_alias [1,1,2,0] ? false
    [2,1,2,2] is_alias [1,1,2,1] ? false
    [2,1,2,2] is_alias [1,1,2,2] ? false
    [2,1,2,2] is_alias [1,2,0,0] ? false
    [2,1,2,2] is_alias [1,2,0,1] ? false
    [2,1,2,2] is_alias [1,2,0,2] ? false
    [2,1,2,2] is_alias [1,2,1,0] ? false
    [2,1,2,2] is_alias [1,2,1,1] ? false
    [2,1,2,2] is_alias [1,2,1,2] ? false
    [2,1,2,2] is_alias [1,2,2,0] ? false
    [2,1,2,2] is_alias [1,2,2,1] ? false
    [2,1,2,2] is_alias [1,2,2,2] ? true
    [2,1,2,2] is_alias [2,0,0,0] ? false
    [2,1,2,2] is_alias [2,0,0,1] ? false
    [2,1,2,2] is_alias [2,0,0,2] ? false
    [2,1,2,2] is_alias [2,0,1,0] ? false
    [2,1,2,2] is_alias [2,0,1,1] ? false
    [2,1,2,2] is_alias [2,0,1,2] ? false
    [2,1,2,2] is_alias [2,0,2,0] ? false
    [2,1,2,2] is_alias [2,0,2,1] ? false
    [2,1,2,2] is_alias [2,0,2,2] ? false
    [2,1,2,2] is_alias [2,1,0,0] ? false
    [2,1,2,2] is_alias [2,1,0,1] ? false
    [2,1,2,2] is_alias [2,1,0,2] ? false
    [2,1,2,2] is_alias [2,1,1,0] ? false
    [2,1,2,2] is_alias [2,1,1,1] ? false
    [2,1,2,2] is_alias [2,1,1,2] ? false
    [2,1,2,2] is_alias [2,1,2,0] ? false
    [2,1,2,2] is_alias [2,1,2,1] ? false
    [2,1,2,2] is_alias [2,1,2,2] ? false
    [2,1,2,2] is_alias [2,2,0,0] ? false
    [2,1,2,2] is_alias [2,2,0,1] ? false
    [2,1,2,2] is_alias [2,2,0,2] ? false
    [2,1,2,2] is_alias [2,2,1,0] ? false
    [2,1,2,2] is_alias [2,2,1,1] ? false
    [2,1,2,2] is_alias [2,2,1,2] ? true
    [2,1,2,2] is_alias [2,2,2,0] ? false
    [2,1,2,2] is_alias [2,2,2,1] ? true
    [2,1,2,2] is_alias [2,2,2,2] ? false
    [2,2,0,0] index has alias ? : true
    [2,2,0,0] is_alias [0,0,0,0] ? false
    [2,2,0,0] is_alias [0,0,0,1] ? false
    [2,2,0,0] is_alias [0,0,0,2] ? false
    [2,2,0,0] is_alias [0,0,1,0] ? false
    [2,2,0,0] is_alias [0,0,1,1] ? false
    [2,2,0,0] is_alias [0,0,1,2] ? false
    [2,2,0,0] is_alias [0,0,2,0] ? false
    [2,2,0,0] is_alias [0,0,2,1] ? false
    [2,2,0,0] is_alias [0,0,2,2] ? true
    [2,2,0,0] is_alias [0,1,0,0] ? false
    [2,2,0,0] is_alias [0,1,0,1] ? false
    [2,2,0,0] is_alias [0,1,0,2] ? false
    [2,2,0,0] is_alias [0,1,1,0] ? false
    [2,2,0,0] is_alias [0,1,1,1] ? false
    [2,2,0,0] is_alias [0,1,1,2] ? false
    [2,2,0,0] is_alias [0,1,2,0] ? false
    [2,2,0,0] is_alias [0,1,2,1] ? false
    [2,2,0,0] is_alias [0,1,2,2] ? false
    [2,2,0,0] is_alias [0,2,0,0] ? false
    [2,2,0,0] is_alias [0,2,0,1] ? false
    [2,2,0,0] is_alias [0,2,0,2] ? false
    [2,2,0,0] is_alias [0,2,1,0] ? false
    [2,2,0,0] is_alias [0,2,1,1] ? false
    [2,2,0,0] is_alias [0,2,1,2] ? false
    [2,2,0,0] is_alias [0,2,2,0] ? false
    [2,2,0,0] is_alias [0,2,2,1] ? false
    [2,2,0,0] is_alias [0,2,2,2] ? false
    [2,2,0,0] is_alias [1,0,0,0] ? false
    [2,2,0,0] is_alias [1,0,0,1] ? false
    [2,2,0,0] is_alias [1,0,0,2] ? false
    [2,2,0,0] is_alias [1,0,1,0] ? false
    [2,2,0,0] is_alias [1,0,1,1] ? false
    [2,2,0,0] is_alias [1,0,1,2] ? false
    [2,2,0,0] is_alias [1,0,2,0] ? false
    [2,2,0,0] is_alias [1,0,2,1] ? false
    [2,2,0,0] is_alias [1,0,2,2] ? false
    [2,2,0,0] is_alias [1,1,0,0] ? false
    [2,2,0,0] is_alias [1,1,0,1] ? false
    [2,2,0,0] is_alias [1,1,0,2] ? false
    [2,2,0,0] is_alias [1,1,1,0] ? false
    [2,2,0,0] is_alias [1,1,1,1] ? false
    [2,2,0,0] is_alias [1,1,1,2] ? false
    [2,2,0,0] is_alias [1,1,2,0] ? false
    [2,2,0,0] is_alias [1,1,2,1] ? false
    [2,2,0,0] is_alias [1,1,2,2] ? false
    [2,2,0,0] is_alias [1,2,0,0] ? false
    [2,2,0,0] is_alias [1,2,0,1] ? false
    [2,2,0,0] is_alias [1,2,0,2] ? false
    [2,2,0,0] is_alias [1,2,1,0] ? false
    [2,2,0,0] is_alias [1,2,1,1] ? false
    [2,2,0,0] is_alias [1,2,1,2] ? false
    [2,2,0,0] is_alias [1,2,2,0] ? false
    [2,2,0,0] is_alias [1,2,2,1] ? false
    [2,2,0,0] is_alias [1,2,2,2] ? false
    [2,2,0,0] is_alias [2,0,0,0] ? false
    [2,2,0,0] is_alias [2,0,0,1] ? false
    [2,2,0,0] is_alias [2,0,0,2] ? false
    [2,2,0,0] is_alias [2,0,1,0] ? false
    [2,2,0,0] is_alias [2,0,1,1] ? false
    [2,2,0,0] is_alias [2,0,1,2] ? false
    [2,2,0,0] is_alias [2,0,2,0] ? false
    [2,2,0,0] is_alias [2,0,2,1] ? false
    [2,2,0,0] is_alias [2,0,2,2] ? false
    [2,2,0,0] is_alias [2,1,0,0] ? false
    [2,2,0,0] is_alias [2,1,0,1] ? false
    [2,2,0,0] is_alias [2,1,0,2] ? false
    [2,2,0,0] is_alias [2,1,1,0] ? false
    [2,2,0,0] is_alias [2,1,1,1] ? false
    [2,2,0,0] is_alias [2,1,1,2] ? false
    [2,2,0,0] is_alias [2,1,2,0] ? false
    [2,2,0,0] is_alias [2,1,2,1] ? false
    [2,2,0,0] is_alias [2,1,2,2] ? false
    [2,2,0,0] is_alias [2,2,0,0] ? false
    [2,2,0,0] is_alias [2,2,0,1] ? false
    [2,2,0,0] is_alias [2,2,0,2] ? false
    [2,2,0,0] is_alias [2,2,1,0] ? false
    [2,2,0,0] is_alias [2,2,1,1] ? false
    [2,2,0,0] is_alias [2,2,1,2] ? false
    [2,2,0,0] is_alias [2,2,2,0] ? false
    [2,2,0,0] is_alias [2,2,2,1] ? false
    [2,2,0,0] is_alias [2,2,2,2] ? false
    [2,2,0,1] index has alias ? : true
    [2,2,0,1] is_alias [0,0,0,0] ? false
    [2,2,0,1] is_alias [0,0,0,1] ? false
    [2,2,0,1] is_alias [0,0,0,2] ? false
    [2,2,0,1] is_alias [0,0,1,0] ? false
    [2,2,0,1] is_alias [0,0,1,1] ? false
    [2,2,0,1] is_alias [0,0,1,2] ? false
    [2,2,0,1] is_alias [0,0,2,0] ? false
    [2,2,0,1] is_alias [0,0,2,1] ? false
    [2,2,0,1] is_alias [0,0,2,2] ? false
    [2,2,0,1] is_alias [0,1,0,0] ? false
    [2,2,0,1] is_alias [0,1,0,1] ? false
    [2,2,0,1] is_alias [0,1,0,2] ? false
    [2,2,0,1] is_alias [0,1,1,0] ? false
    [2,2,0,1] is_alias [0,1,1,1] ? false
    [2,2,0,1] is_alias [0,1,1,2] ? false
    [2,2,0,1] is_alias [0,1,2,0] ? false
    [2,2,0,1] is_alias [0,1,2,1] ? false
    [2,2,0,1] is_alias [0,1,2,2] ? true
    [2,2,0,1] is_alias [0,2,0,0] ? false
    [2,2,0,1] is_alias [0,2,0,1] ? false
    [2,2,0,1] is_alias [0,2,0,2] ? false
    [2,2,0,1] is_alias [0,2,1,0] ? false
    [2,2,0,1] is_alias [0,2,1,1] ? false
    [2,2,0,1] is_alias [0,2,1,2] ? false
    [2,2,0,1] is_alias [0,2,2,0] ? false
    [2,2,0,1] is_alias [0,2,2,1] ? false
    [2,2,0,1] is_alias [0,2,2,2] ? false
    [2,2,0,1] is_alias [1,0,0,0] ? false
    [2,2,0,1] is_alias [1,0,0,1] ? false
    [2,2,0,1] is_alias [1,0,0,2] ? false
    [2,2,0,1] is_alias [1,0,1,0] ? false
    [2,2,0,1] is_alias [1,0,1,1] ? false
    [2,2,0,1] is_alias [1,0,1,2] ? false
    [2,2,0,1] is_alias [1,0,2,0] ? false
    [2,2,0,1] is_alias [1,0,2,1] ? false
    [2,2,0,1] is_alias [1,0,2,2] ? true
    [2,2,0,1] is_alias [1,1,0,0] ? false
    [2,2,0,1] is_alias [1,1,0,1] ? false
    [2,2,0,1] is_alias [1,1,0,2] ? false
    [2,2,0,1] is_alias [1,1,1,0] ? false
    [2,2,0,1] is_alias [1,1,1,1] ? false
    [2,2,0,1] is_alias [1,1,1,2] ? false
    [2,2,0,1] is_alias [1,1,2,0] ? false
    [2,2,0,1] is_alias [1,1,2,1] ? false
    [2,2,0,1] is_alias [1,1,2,2] ? false
    [2,2,0,1] is_alias [1,2,0,0] ? false
    [2,2,0,1] is_alias [1,2,0,1] ? false
    [2,2,0,1] is_alias [1,2,0,2] ? false
    [2,2,0,1] is_alias [1,2,1,0] ? false
    [2,2,0,1] is_alias [1,2,1,1] ? false
    [2,2,0,1] is_alias [1,2,1,2] ? false
    [2,2,0,1] is_alias [1,2,2,0] ? false
    [2,2,0,1] is_alias [1,2,2,1] ? false
    [2,2,0,1] is_alias [1,2,2,2] ? false
    [2,2,0,1] is_alias [2,0,0,0] ? false
    [2,2,0,1] is_alias [2,0,0,1] ? false
    [2,2,0,1] is_alias [2,0,0,2] ? false
    [2,2,0,1] is_alias [2,0,1,0] ? false
    [2,2,0,1] is_alias [2,0,1,1] ? false
    [2,2,0,1] is_alias [2,0,1,2] ? false
    [2,2,0,1] is_alias [2,0,2,0] ? false
    [2,2,0,1] is_alias [2,0,2,1] ? false
    [2,2,0,1] is_alias [2,0,2,2] ? false
    [2,2,0,1] is_alias [2,1,0,0] ? false
    [2,2,0,1] is_alias [2,1,0,1] ? false
    [2,2,0,1] is_alias [2,1,0,2] ? false
    [2,2,0,1] is_alias [2,1,1,0] ? false
    [2,2,0,1] is_alias [2,1,1,1] ? false
    [2,2,0,1] is_alias [2,1,1,2] ? false
    [2,2,0,1] is_alias [2,1,2,0] ? false
    [2,2,0,1] is_alias [2,1,2,1] ? false
    [2,2,0,1] is_alias [2,1,2,2] ? false
    [2,2,0,1] is_alias [2,2,0,0] ? false
    [2,2,0,1] is_alias [2,2,0,1] ? false
    [2,2,0,1] is_alias [2,2,0,2] ? false
    [2,2,0,1] is_alias [2,2,1,0] ? true
    [2,2,0,1] is_alias [2,2,1,1] ? false
    [2,2,0,1] is_alias [2,2,1,2] ? false
    [2,2,0,1] is_alias [2,2,2,0] ? false
    [2,2,0,1] is_alias [2,2,2,1] ? false
    [2,2,0,1] is_alias [2,2,2,2] ? false
    [2,2,0,2] index has alias ? : true
    [2,2,0,2] is_alias [0,0,0,0] ? false
    [2,2,0,2] is_alias [0,0,0,1] ? false
    [2,2,0,2] is_alias [0,0,0,2] ? false
    [2,2,0,2] is_alias [0,0,1,0] ? false
    [2,2,0,2] is_alias [0,0,1,1] ? false
    [2,2,0,2] is_alias [0,0,1,2] ? false
    [2,2,0,2] is_alias [0,0,2,0] ? false
    [2,2,0,2] is_alias [0,0,2,1] ? false
    [2,2,0,2] is_alias [0,0,2,2] ? false
    [2,2,0,2] is_alias [0,1,0,0] ? false
    [2,2,0,2] is_alias [0,1,0,1] ? false
    [2,2,0,2] is_alias [0,1,0,2] ? false
    [2,2,0,2] is_alias [0,1,1,0] ? false
    [2,2,0,2] is_alias [0,1,1,1] ? false
    [2,2,0,2] is_alias [0,1,1,2] ? false
    [2,2,0,2] is_alias [0,1,2,0] ? false
    [2,2,0,2] is_alias [0,1,2,1] ? false
    [2,2,0,2] is_alias [0,1,2,2] ? false
    [2,2,0,2] is_alias [0,2,0,0] ? false
    [2,2,0,2] is_alias [0,2,0,1] ? false
    [2,2,0,2] is_alias [0,2,0,2] ? false
    [2,2,0,2] is_alias [0,2,1,0] ? false
    [2,2,0,2] is_alias [0,2,1,1] ? false
    [2,2,0,2] is_alias [0,2,1,2] ? false
    [2,2,0,2] is_alias [0,2,2,0] ? false
    [2,2,0,2] is_alias [0,2,2,1] ? false
    [2,2,0,2] is_alias [0,2,2,2] ? true
    [2,2,0,2] is_alias [1,0,0,0] ? false
    [2,2,0,2] is_alias [1,0,0,1] ? false
    [2,2,0,2] is_alias [1,0,0,2] ? false
    [2,2,0,2] is_alias [1,0,1,0] ? false
    [2,2,0,2] is_alias [1,0,1,1] ? false
    [2,2,0,2] is_alias [1,0,1,2] ? false
    [2,2,0,2] is_alias [1,0,2,0] ? false
    [2,2,0,2] is_alias [1,0,2,1] ? false
    [2,2,0,2] is_alias [1,0,2,2] ? false
    [2,2,0,2] is_alias [1,1,0,0] ? false
    [2,2,0,2] is_alias [1,1,0,1] ? false
    [2,2,0,2] is_alias [1,1,0,2] ? false
    [2,2,0,2] is_alias [1,1,1,0] ? false
    [2,2,0,2] is_alias [1,1,1,1] ? false
    [2,2,0,2] is_alias [1,1,1,2] ? false
    [2,2,0,2] is_alias [1,1,2,0] ? false
    [2,2,0,2] is_alias [1,1,2,1] ? false
    [2,2,0,2] is_alias [1,1,2,2] ? false
    [2,2,0,2] is_alias [1,2,0,0] ? false
    [2,2,0,2] is_alias [1,2,0,1] ? false
    [2,2,0,2] is_alias [1,2,0,2] ? false
    [2,2,0,2] is_alias [1,2,1,0] ? false
    [2,2,0,2] is_alias [1,2,1,1] ? false
    [2,2,0,2] is_alias [1,2,1,2] ? false
    [2,2,0,2] is_alias [1,2,2,0] ? false
    [2,2,0,2] is_alias [1,2,2,1] ? false
    [2,2,0,2] is_alias [1,2,2,2] ? false
    [2,2,0,2] is_alias [2,0,0,0] ? false
    [2,2,0,2] is_alias [2,0,0,1] ? false
    [2,2,0,2] is_alias [2,0,0,2] ? false
    [2,2,0,2] is_alias [2,0,1,0] ? false
    [2,2,0,2] is_alias [2,0,1,1] ? false
    [2,2,0,2] is_alias [2,0,1,2] ? false
    [2,2,0,2] is_alias [2,0,2,0] ? false
    [2,2,0,2] is_alias [2,0,2,1] ? false
    [2,2,0,2] is_alias [2,0,2,2] ? true
    [2,2,0,2] is_alias [2,1,0,0] ? false
    [2,2,0,2] is_alias [2,1,0,1] ? false
    [2,2,0,2] is_alias [2,1,0,2] ? false
    [2,2,0,2] is_alias [2,1,1,0] ? false
    [2,2,0,2] is_alias [2,1,1,1] ? false
    [2,2,0,2] is_alias [2,1,1,2] ? false
    [2,2,0,2] is_alias [2,1,2,0] ? false
    [2,2,0,2] is_alias [2,1,2,1] ? false
    [2,2,0,2] is_alias [2,1,2,2] ? false
    [2,2,0,2] is_alias [2,2,0,0] ? false
    [2,2,0,2] is_alias [2,2,0,1] ? false
    [2,2,0,2] is_alias [2,2,0,2] ? false
    [2,2,0,2] is_alias [2,2,1,0] ? false
    [2,2,0,2] is_alias [2,2,1,1] ? false
    [2,2,0,2] is_alias [2,2,1,2] ? false
    [2,2,0,2] is_alias [2,2,2,0] ? true
    [2,2,0,2] is_alias [2,2,2,1] ? false
    [2,2,0,2] is_alias [2,2,2,2] ? false
    [2,2,1,0] index has alias ? : true
    [2,2,1,0] is_alias [0,0,0,0] ? false
    [2,2,1,0] is_alias [0,0,0,1] ? false
    [2,2,1,0] is_alias [0,0,0,2] ? false
    [2,2,1,0] is_alias [0,0,1,0] ? false
    [2,2,1,0] is_alias [0,0,1,1] ? false
    [2,2,1,0] is_alias [0,0,1,2] ? false
    [2,2,1,0] is_alias [0,0,2,0] ? false
    [2,2,1,0] is_alias [0,0,2,1] ? false
    [2,2,1,0] is_alias [0,0,2,2] ? false
    [2,2,1,0] is_alias [0,1,0,0] ? false
    [2,2,1,0] is_alias [0,1,0,1] ? false
    [2,2,1,0] is_alias [0,1,0,2] ? false
    [2,2,1,0] is_alias [0,1,1,0] ? false
    [2,2,1,0] is_alias [0,1,1,1] ? false
    [2,2,1,0] is_alias [0,1,1,2] ? false
    [2,2,1,0] is_alias [0,1,2,0] ? false
    [2,2,1,0] is_alias [0,1,2,1] ? false
    [2,2,1,0] is_alias [0,1,2,2] ? true
    [2,2,1,0] is_alias [0,2,0,0] ? false
    [2,2,1,0] is_alias [0,2,0,1] ? false
    [2,2,1,0] is_alias [0,2,0,2] ? false
    [2,2,1,0] is_alias [0,2,1,0] ? false
    [2,2,1,0] is_alias [0,2,1,1] ? false
    [2,2,1,0] is_alias [0,2,1,2] ? false
    [2,2,1,0] is_alias [0,2,2,0] ? false
    [2,2,1,0] is_alias [0,2,2,1] ? false
    [2,2,1,0] is_alias [0,2,2,2] ? false
    [2,2,1,0] is_alias [1,0,0,0] ? false
    [2,2,1,0] is_alias [1,0,0,1] ? false
    [2,2,1,0] is_alias [1,0,0,2] ? false
    [2,2,1,0] is_alias [1,0,1,0] ? false
    [2,2,1,0] is_alias [1,0,1,1] ? false
    [2,2,1,0] is_alias [1,0,1,2] ? false
    [2,2,1,0] is_alias [1,0,2,0] ? false
    [2,2,1,0] is_alias [1,0,2,1] ? false
    [2,2,1,0] is_alias [1,0,2,2] ? true
    [2,2,1,0] is_alias [1,1,0,0] ? false
    [2,2,1,0] is_alias [1,1,0,1] ? false
    [2,2,1,0] is_alias [1,1,0,2] ? false
    [2,2,1,0] is_alias [1,1,1,0] ? false
    [2,2,1,0] is_alias [1,1,1,1] ? false
    [2,2,1,0] is_alias [1,1,1,2] ? false
    [2,2,1,0] is_alias [1,1,2,0] ? false
    [2,2,1,0] is_alias [1,1,2,1] ? false
    [2,2,1,0] is_alias [1,1,2,2] ? false
    [2,2,1,0] is_alias [1,2,0,0] ? false
    [2,2,1,0] is_alias [1,2,0,1] ? false
    [2,2,1,0] is_alias [1,2,0,2] ? false
    [2,2,1,0] is_alias [1,2,1,0] ? false
    [2,2,1,0] is_alias [1,2,1,1] ? false
    [2,2,1,0] is_alias [1,2,1,2] ? false
    [2,2,1,0] is_alias [1,2,2,0] ? false
    [2,2,1,0] is_alias [1,2,2,1] ? false
    [2,2,1,0] is_alias [1,2,2,2] ? false
    [2,2,1,0] is_alias [2,0,0,0] ? false
    [2,2,1,0] is_alias [2,0,0,1] ? false
    [2,2,1,0] is_alias [2,0,0,2] ? false
    [2,2,1,0] is_alias [2,0,1,0] ? false
    [2,2,1,0] is_alias [2,0,1,1] ? false
    [2,2,1,0] is_alias [2,0,1,2] ? false
    [2,2,1,0] is_alias [2,0,2,0] ? false
    [2,2,1,0] is_alias [2,0,2,1] ? false
    [2,2,1,0] is_alias [2,0,2,2] ? false
    [2,2,1,0] is_alias [2,1,0,0] ? false
    [2,2,1,0] is_alias [2,1,0,1] ? false
    [2,2,1,0] is_alias [2,1,0,2] ? false
    [2,2,1,0] is_alias [2,1,1,0] ? false
    [2,2,1,0] is_alias [2,1,1,1] ? false
    [2,2,1,0] is_alias [2,1,1,2] ? false
    [2,2,1,0] is_alias [2,1,2,0] ? false
    [2,2,1,0] is_alias [2,1,2,1] ? false
    [2,2,1,0] is_alias [2,1,2,2] ? false
    [2,2,1,0] is_alias [2,2,0,0] ? false
    [2,2,1,0] is_alias [2,2,0,1] ? true
    [2,2,1,0] is_alias [2,2,0,2] ? false
    [2,2,1,0] is_alias [2,2,1,0] ? false
    [2,2,1,0] is_alias [2,2,1,1] ? false
    [2,2,1,0] is_alias [2,2,1,2] ? false
    [2,2,1,0] is_alias [2,2,2,0] ? false
    [2,2,1,0] is_alias [2,2,2,1] ? false
    [2,2,1,0] is_alias [2,2,2,2] ? false
    [2,2,1,1] index has alias ? : true
    [2,2,1,1] is_alias [0,0,0,0] ? false
    [2,2,1,1] is_alias [0,0,0,1] ? false
    [2,2,1,1] is_alias [0,0,0,2] ? false
    [2,2,1,1] is_alias [0,0,1,0] ? false
    [2,2,1,1] is_alias [0,0,1,1] ? false
    [2,2,1,1] is_alias [0,0,1,2] ? false
    [2,2,1,1] is_alias [0,0,2,0] ? false
    [2,2,1,1] is_alias [0,0,2,1] ? false
    [2,2,1,1] is_alias [0,0,2,2] ? false
    [2,2,1,1] is_alias [0,1,0,0] ? false
    [2,2,1,1] is_alias [0,1,0,1] ? false
    [2,2,1,1] is_alias [0,1,0,2] ? false
    [2,2,1,1] is_alias [0,1,1,0] ? false
    [2,2,1,1] is_alias [0,1,1,1] ? false
    [2,2,1,1] is_alias [0,1,1,2] ? false
    [2,2,1,1] is_alias [0,1,2,0] ? false
    [2,2,1,1] is_alias [0,1,2,1] ? false
    [2,2,1,1] is_alias [0,1,2,2] ? false
    [2,2,1,1] is_alias [0,2,0,0] ? false
    [2,2,1,1] is_alias [0,2,0,1] ? false
    [2,2,1,1] is_alias [0,2,0,2] ? false
    [2,2,1,1] is_alias [0,2,1,0] ? false
    [2,2,1,1] is_alias [0,2,1,1] ? false
    [2,2,1,1] is_alias [0,2,1,2] ? false
    [2,2,1,1] is_alias [0,2,2,0] ? false
    [2,2,1,1] is_alias [0,2,2,1] ? false
    [2,2,1,1] is_alias [0,2,2,2] ? false
    [2,2,1,1] is_alias [1,0,0,0] ? false
    [2,2,1,1] is_alias [1,0,0,1] ? false
    [2,2,1,1] is_alias [1,0,0,2] ? false
    [2,2,1,1] is_alias [1,0,1,0] ? false
    [2,2,1,1] is_alias [1,0,1,1] ? false
    [2,2,1,1] is_alias [1,0,1,2] ? false
    [2,2,1,1] is_alias [1,0,2,0] ? false
    [2,2,1,1] is_alias [1,0,2,1] ? false
    [2,2,1,1] is_alias [1,0,2,2] ? false
    [2,2,1,1] is_alias [1,1,0,0] ? false
    [2,2,1,1] is_alias [1,1,0,1] ? false
    [2,2,1,1] is_alias [1,1,0,2] ? false
    [2,2,1,1] is_alias [1,1,1,0] ? false
    [2,2,1,1] is_alias [1,1,1,1] ? false
    [2,2,1,1] is_alias [1,1,1,2] ? false
    [2,2,1,1] is_alias [1,1,2,0] ? false
    [2,2,1,1] is_alias [1,1,2,1] ? false
    [2,2,1,1] is_alias [1,1,2,2] ? true
    [2,2,1,1] is_alias [1,2,0,0] ? false
    [2,2,1,1] is_alias [1,2,0,1] ? false
    [2,2,1,1] is_alias [1,2,0,2] ? false
    [2,2,1,1] is_alias [1,2,1,0] ? false
    [2,2,1,1] is_alias [1,2,1,1] ? false
    [2,2,1,1] is_alias [1,2,1,2] ? false
    [2,2,1,1] is_alias [1,2,2,0] ? false
    [2,2,1,1] is_alias [1,2,2,1] ? false
    [2,2,1,1] is_alias [1,2,2,2] ? false
    [2,2,1,1] is_alias [2,0,0,0] ? false
    [2,2,1,1] is_alias [2,0,0,1] ? false
    [2,2,1,1] is_alias [2,0,0,2] ? false
    [2,2,1,1] is_alias [2,0,1,0] ? false
    [2,2,1,1] is_alias [2,0,1,1] ? false
    [2,2,1,1] is_alias [2,0,1,2] ? false
    [2,2,1,1] is_alias [2,0,2,0] ? false
    [2,2,1,1] is_alias [2,0,2,1] ? false
    [2,2,1,1] is_alias [2,0,2,2] ? false
    [2,2,1,1] is_alias [2,1,0,0] ? false
    [2,2,1,1] is_alias [2,1,0,1] ? false
    [2,2,1,1] is_alias [2,1,0,2] ? false
    [2,2,1,1] is_alias [2,1,1,0] ? false
    [2,2,1,1] is_alias [2,1,1,1] ? false
    [2,2,1,1] is_alias [2,1,1,2] ? false
    [2,2,1,1] is_alias [2,1,2,0] ? false
    [2,2,1,1] is_alias [2,1,2,1] ? false
    [2,2,1,1] is_alias [2,1,2,2] ? false
    [2,2,1,1] is_alias [2,2,0,0] ? false
    [2,2,1,1] is_alias [2,2,0,1] ? false
    [2,2,1,1] is_alias [2,2,0,2] ? false
    [2,2,1,1] is_alias [2,2,1,0] ? false
    [2,2,1,1] is_alias [2,2,1,1] ? false
    [2,2,1,1] is_alias [2,2,1,2] ? false
    [2,2,1,1] is_alias [2,2,2,0] ? false
    [2,2,1,1] is_alias [2,2,2,1] ? false
    [2,2,1,1] is_alias [2,2,2,2] ? false
    [2,2,1,2] index has alias ? : true
    [2,2,1,2] is_alias [0,0,0,0] ? false
    [2,2,1,2] is_alias [0,0,0,1] ? false
    [2,2,1,2] is_alias [0,0,0,2] ? false
    [2,2,1,2] is_alias [0,0,1,0] ? false
    [2,2,1,2] is_alias [0,0,1,1] ? false
    [2,2,1,2] is_alias [0,0,1,2] ? false
    [2,2,1,2] is_alias [0,0,2,0] ? false
    [2,2,1,2] is_alias [0,0,2,1] ? false
    [2,2,1,2] is_alias [0,0,2,2] ? false
    [2,2,1,2] is_alias [0,1,0,0] ? false
    [2,2,1,2] is_alias [0,1,0,1] ? false
    [2,2,1,2] is_alias [0,1,0,2] ? false
    [2,2,1,2] is_alias [0,1,1,0] ? false
    [2,2,1,2] is_alias [0,1,1,1] ? false
    [2,2,1,2] is_alias [0,1,1,2] ? false
    [2,2,1,2] is_alias [0,1,2,0] ? false
    [2,2,1,2] is_alias [0,1,2,1] ? false
    [2,2,1,2] is_alias [0,1,2,2] ? false
    [2,2,1,2] is_alias [0,2,0,0] ? false
    [2,2,1,2] is_alias [0,2,0,1] ? false
    [2,2,1,2] is_alias [0,2,0,2] ? false
    [2,2,1,2] is_alias [0,2,1,0] ? false
    [2,2,1,2] is_alias [0,2,1,1] ? false
    [2,2,1,2] is_alias [0,2,1,2] ? false
    [2,2,1,2] is_alias [0,2,2,0] ? false
    [2,2,1,2] is_alias [0,2,2,1] ? false
    [2,2,1,2] is_alias [0,2,2,2] ? false
    [2,2,1,2] is_alias [1,0,0,0] ? false
    [2,2,1,2] is_alias [1,0,0,1] ? false
    [2,2,1,2] is_alias [1,0,0,2] ? false
    [2,2,1,2] is_alias [1,0,1,0] ? false
    [2,2,1,2] is_alias [1,0,1,1] ? false
    [2,2,1,2] is_alias [1,0,1,2] ? false
    [2,2,1,2] is_alias [1,0,2,0] ? false
    [2,2,1,2] is_alias [1,0,2,1] ? false
    [2,2,1,2] is_alias [1,0,2,2] ? false
    [2,2,1,2] is_alias [1,1,0,0] ? false
    [2,2,1,2] is_alias [1,1,0,1] ? false
    [2,2,1,2] is_alias [1,1,0,2] ? false
    [2,2,1,2] is_alias [1,1,1,0] ? false
    [2,2,1,2] is_alias [1,1,1,1] ? false
    [2,2,1,2] is_alias [1,1,1,2] ? false
    [2,2,1,2] is_alias [1,1,2,0] ? false
    [2,2,1,2] is_alias [1,1,2,1] ? false
    [2,2,1,2] is_alias [1,1,2,2] ? false
    [2,2,1,2] is_alias [1,2,0,0] ? false
    [2,2,1,2] is_alias [1,2,0,1] ? false
    [2,2,1,2] is_alias [1,2,0,2] ? false
    [2,2,1,2] is_alias [1,2,1,0] ? false
    [2,2,1,2] is_alias [1,2,1,1] ? false
    [2,2,1,2] is_alias [1,2,1,2] ? false
    [2,2,1,2] is_alias [1,2,2,0] ? false
    [2,2,1,2] is_alias [1,2,2,1] ? false
    [2,2,1,2] is_alias [1,2,2,2] ? true
    [2,2,1,2] is_alias [2,0,0,0] ? false
    [2,2,1,2] is_alias [2,0,0,1] ? false
    [2,2,1,2] is_alias [2,0,0,2] ? false
    [2,2,1,2] is_alias [2,0,1,0] ? false
    [2,2,1,2] is_alias [2,0,1,1] ? false
    [2,2,1,2] is_alias [2,0,1,2] ? false
    [2,2,1,2] is_alias [2,0,2,0] ? false
    [2,2,1,2] is_alias [2,0,2,1] ? false
    [2,2,1,2] is_alias [2,0,2,2] ? false
    [2,2,1,2] is_alias [2,1,0,0] ? false
    [2,2,1,2] is_alias [2,1,0,1] ? false
    [2,2,1,2] is_alias [2,1,0,2] ? false
    [2,2,1,2] is_alias [2,1,1,0] ? false
    [2,2,1,2] is_alias [2,1,1,1] ? false
    [2,2,1,2] is_alias [2,1,1,2] ? false
    [2,2,1,2] is_alias [2,1,2,0] ? false
    [2,2,1,2] is_alias [2,1,2,1] ? false
    [2,2,1,2] is_alias [2,1,2,2] ? true
    [2,2,1,2] is_alias [2,2,0,0] ? false
    [2,2,1,2] is_alias [2,2,0,1] ? false
    [2,2,1,2] is_alias [2,2,0,2] ? false
    [2,2,1,2] is_alias [2,2,1,0] ? false
    [2,2,1,2] is_alias [2,2,1,1] ? false
    [2,2,1,2] is_alias [2,2,1,2] ? false
    [2,2,1,2] is_alias [2,2,2,0] ? false
    [2,2,1,2] is_alias [2,2,2,1] ? true
    [2,2,1,2] is_alias [2,2,2,2] ? false
    [2,2,2,0] index has alias ? : true
    [2,2,2,0] is_alias [0,0,0,0] ? false
    [2,2,2,0] is_alias [0,0,0,1] ? false
    [2,2,2,0] is_alias [0,0,0,2] ? false
    [2,2,2,0] is_alias [0,0,1,0] ? false
    [2,2,2,0] is_alias [0,0,1,1] ? false
    [2,2,2,0] is_alias [0,0,1,2] ? false
    [2,2,2,0] is_alias [0,0,2,0] ? false
    [2,2,2,0] is_alias [0,0,2,1] ? false
    [2,2,2,0] is_alias [0,0,2,2] ? false
    [2,2,2,0] is_alias [0,1,0,0] ? false
    [2,2,2,0] is_alias [0,1,0,1] ? false
    [2,2,2,0] is_alias [0,1,0,2] ? false
    [2,2,2,0] is_alias [0,1,1,0] ? false
    [2,2,2,0] is_alias [0,1,1,1] ? false
    [2,2,2,0] is_alias [0,1,1,2] ? false
    [2,2,2,0] is_alias [0,1,2,0] ? false
    [2,2,2,0] is_alias [0,1,2,1] ? false
    [2,2,2,0] is_alias [0,1,2,2] ? false
    [2,2,2,0] is_alias [0,2,0,0] ? false
    [2,2,2,0] is_alias [0,2,0,1] ? false
    [2,2,2,0] is_alias [0,2,0,2] ? false
    [2,2,2,0] is_alias [0,2,1,0] ? false
    [2,2,2,0] is_alias [0,2,1,1] ? false
    [2,2,2,0] is_alias [0,2,1,2] ? false
    [2,2,2,0] is_alias [0,2,2,0] ? false
    [2,2,2,0] is_alias [0,2,2,1] ? false
    [2,2,2,0] is_alias [0,2,2,2] ? true
    [2,2,2,0] is_alias [1,0,0,0] ? false
    [2,2,2,0] is_alias [1,0,0,1] ? false
    [2,2,2,0] is_alias [1,0,0,2] ? false
    [2,2,2,0] is_alias [1,0,1,0] ? false
    [2,2,2,0] is_alias [1,0,1,1] ? false
    [2,2,2,0] is_alias [1,0,1,2] ? false
    [2,2,2,0] is_alias [1,0,2,0] ? false
    [2,2,2,0] is_alias [1,0,2,1] ? false
    [2,2,2,0] is_alias [1,0,2,2] ? false
    [2,2,2,0] is_alias [1,1,0,0] ? false
    [2,2,2,0] is_alias [1,1,0,1] ? false
    [2,2,2,0] is_alias [1,1,0,2] ? false
    [2,2,2,0] is_alias [1,1,1,0] ? false
    [2,2,2,0] is_alias [1,1,1,1] ? false
    [2,2,2,0] is_alias [1,1,1,2] ? false
    [2,2,2,0] is_alias [1,1,2,0] ? false
    [2,2,2,0] is_alias [1,1,2,1] ? false
    [2,2,2,0] is_alias [1,1,2,2] ? false
    [2,2,2,0] is_alias [1,2,0,0] ? false
    [2,2,2,0] is_alias [1,2,0,1] ? false
    [2,2,2,0] is_alias [1,2,0,2] ? false
    [2,2,2,0] is_alias [1,2,1,0] ? false
    [2,2,2,0] is_alias [1,2,1,1] ? false
    [2,2,2,0] is_alias [1,2,1,2] ? false
    [2,2,2,0] is_alias [1,2,2,0] ? false
    [2,2,2,0] is_alias [1,2,2,1] ? false
    [2,2,2,0] is_alias [1,2,2,2] ? false
    [2,2,2,0] is_alias [2,0,0,0] ? false
    [2,2,2,0] is_alias [2,0,0,1] ? false
    [2,2,2,0] is_alias [2,0,0,2] ? false
    [2,2,2,0] is_alias [2,0,1,0] ? false
    [2,2,2,0] is_alias [2,0,1,1] ? false
    [2,2,2,0] is_alias [2,0,1,2] ? false
    [2,2,2,0] is_alias [2,0,2,0] ? false
    [2,2,2,0] is_alias [2,0,2,1] ? false
    [2,2,2,0] is_alias [2,0,2,2] ? true
    [2,2,2,0] is_alias [2,1,0,0] ? false
    [2,2,2,0] is_alias [2,1,0,1] ? false
    [2,2,2,0] is_alias [2,1,0,2] ? false
    [2,2,2,0] is_alias [2,1,1,0] ? false
    [2,2,2,0] is_alias [2,1,1,1] ? false
    [2,2,2,0] is_alias [2,1,1,2] ? false
    [2,2,2,0] is_alias [2,1,2,0] ? false
    [2,2,2,0] is_alias [2,1,2,1] ? false
    [2,2,2,0] is_alias [2,1,2,2] ? false
    [2,2,2,0] is_alias [2,2,0,0] ? false
    [2,2,2,0] is_alias [2,2,0,1] ? false
    [2,2,2,0] is_alias [2,2,0,2] ? true
    [2,2,2,0] is_alias [2,2,1,0] ? false
    [2,2,2,0] is_alias [2,2,1,1] ? false
    [2,2,2,0] is_alias [2,2,1,2] ? false
    [2,2,2,0] is_alias [2,2,2,0] ? false
    [2,2,2,0] is_alias [2,2,2,1] ? false
    [2,2,2,0] is_alias [2,2,2,2] ? false
    [2,2,2,1] index has alias ? : true
    [2,2,2,1] is_alias [0,0,0,0] ? false
    [2,2,2,1] is_alias [0,0,0,1] ? false
    [2,2,2,1] is_alias [0,0,0,2] ? false
    [2,2,2,1] is_alias [0,0,1,0] ? false
    [2,2,2,1] is_alias [0,0,1,1] ? false
    [2,2,2,1] is_alias [0,0,1,2] ? false
    [2,2,2,1] is_alias [0,0,2,0] ? false
    [2,2,2,1] is_alias [0,0,2,1] ? false
    [2,2,2,1] is_alias [0,0,2,2] ? false
    [2,2,2,1] is_alias [0,1,0,0] ? false
    [2,2,2,1] is_alias [0,1,0,1] ? false
    [2,2,2,1] is_alias [0,1,0,2] ? false
    [2,2,2,1] is_alias [0,1,1,0] ? false
    [2,2,2,1] is_alias [0,1,1,1] ? false
    [2,2,2,1] is_alias [0,1,1,2] ? false
    [2,2,2,1] is_alias [0,1,2,0] ? false
    [2,2,2,1] is_alias [0,1,2,1] ? false
    [2,2,2,1] is_alias [0,1,2,2] ? false
    [2,2,2,1] is_alias [0,2,0,0] ? false
    [2,2,2,1] is_alias [0,2,0,1] ? false
    [2,2,2,1] is_alias [0,2,0,2] ? false
    [2,2,2,1] is_alias [0,2,1,0] ? false
    [2,2,2,1] is_alias [0,2,1,1] ? false
    [2,2,2,1] is_alias [0,2,1,2] ? false
    [2,2,2,1] is_alias [0,2,2,0] ? false
    [2,2,2,1] is_alias [0,2,2,1] ? false
    [2,2,2,1] is_alias [0,2,2,2] ? false
    [2,2,2,1] is_alias [1,0,0,0] ? false
    [2,2,2,1] is_alias [1,0,0,1] ? false
    [2,2,2,1] is_alias [1,0,0,2] ? false
    [2,2,2,1] is_alias [1,0,1,0] ? false
    [2,2,2,1] is_alias [1,0,1,1] ? false
    [2,2,2,1] is_alias [1,0,1,2] ? false
    [2,2,2,1] is_alias [1,0,2,0] ? false
    [2,2,2,1] is_alias [1,0,2,1] ? false
    [2,2,2,1] is_alias [1,0,2,2] ? false
    [2,2,2,1] is_alias [1,1,0,0] ? false
    [2,2,2,1] is_alias [1,1,0,1] ? false
    [2,2,2,1] is_alias [1,1,0,2] ? false
    [2,2,2,1] is_alias [1,1,1,0] ? false
    [2,2,2,1] is_alias [1,1,1,1] ? false
    [2,2,2,1] is_alias [1,1,1,2] ? false
    [2,2,2,1] is_alias [1,1,2,0] ? false
    [2,2,2,1] is_alias [1,1,2,1] ? false
    [2,2,2,1] is_alias [1,1,2,2] ? false
    [2,2,2,1] is_alias [1,2,0,0] ? false
    [2,2,2,1] is_alias [1,2,0,1] ? false
    [2,2,2,1] is_alias [1,2,0,2] ? false
    [2,2,2,1] is_alias [1,2,1,0] ? false
    [2,2,2,1] is_alias [1,2,1,1] ? false
    [2,2,2,1] is_alias [1,2,1,2] ? false
    [2,2,2,1] is_alias [1,2,2,0] ? false
    [2,2,2,1] is_alias [1,2,2,1] ? false
    [2,2,2,1] is_alias [1,2,2,2] ? true
    [2,2,2,1] is_alias [2,0,0,0] ? false
    [2,2,2,1] is_alias [2,0,0,1] ? false
    [2,2,2,1] is_alias [2,0,0,2] ? false
    [2,2,2,1] is_alias [2,0,1,0] ? false
    [2,2,2,1] is_alias [2,0,1,1] ? false
    [2,2,2,1] is_alias [2,0,1,2] ? false
    [2,2,2,1] is_alias [2,0,2,0] ? false
    [2,2,2,1] is_alias [2,0,2,1] ? false
    [2,2,2,1] is_alias [2,0,2,2] ? false
    [2,2,2,1] is_alias [2,1,0,0] ? false
    [2,2,2,1] is_alias [2,1,0,1] ? false
    [2,2,2,1] is_alias [2,1,0,2] ? false
    [2,2,2,1] is_alias [2,1,1,0] ? false
    [2,2,2,1] is_alias [2,1,1,1] ? false
    [2,2,2,1] is_alias [2,1,1,2] ? false
    [2,2,2,1] is_alias [2,1,2,0] ? false
    [2,2,2,1] is_alias [2,1,2,1] ? false
    [2,2,2,1] is_alias [2,1,2,2] ? true
    [2,2,2,1] is_alias [2,2,0,0] ? false
    [2,2,2,1] is_alias [2,2,0,1] ? false
    [2,2,2,1] is_alias [2,2,0,2] ? false
    [2,2,2,1] is_alias [2,2,1,0] ? false
    [2,2,2,1] is_alias [2,2,1,1] ? false
    [2,2,2,1] is_alias [2,2,1,2] ? true
    [2,2,2,1] is_alias [2,2,2,0] ? false
    [2,2,2,1] is_alias [2,2,2,1] ? false
    [2,2,2,1] is_alias [2,2,2,2] ? false
    [2,2,2,2] index has alias ? : false
    [2,2,2,2] is_alias [0,0,0,0] ? false
    [2,2,2,2] is_alias [0,0,0,1] ? false
    [2,2,2,2] is_alias [0,0,0,2] ? false
    [2,2,2,2] is_alias [0,0,1,0] ? false
    [2,2,2,2] is_alias [0,0,1,1] ? false
    [2,2,2,2] is_alias [0,0,1,2] ? false
    [2,2,2,2] is_alias [0,0,2,0] ? false
    [2,2,2,2] is_alias [0,0,2,1] ? false
    [2,2,2,2] is_alias [0,0,2,2] ? false
    [2,2,2,2] is_alias [0,1,0,0] ? false
    [2,2,2,2] is_alias [0,1,0,1] ? false
    [2,2,2,2] is_alias [0,1,0,2] ? false
    [2,2,2,2] is_alias [0,1,1,0] ? false
    [2,2,2,2] is_alias [0,1,1,1] ? false
    [2,2,2,2] is_alias [0,1,1,2] ? false
    [2,2,2,2] is_alias [0,1,2,0] ? false
    [2,2,2,2] is_alias [0,1,2,1] ? false
    [2,2,2,2] is_alias [0,1,2,2] ? false
    [2,2,2,2] is_alias [0,2,0,0] ? false
    [2,2,2,2] is_alias [0,2,0,1] ? false
    [2,2,2,2] is_alias [0,2,0,2] ? false
    [2,2,2,2] is_alias [0,2,1,0] ? false
    [2,2,2,2] is_alias [0,2,1,1] ? false
    [2,2,2,2] is_alias [0,2,1,2] ? false
    [2,2,2,2] is_alias [0,2,2,0] ? false
    [2,2,2,2] is_alias [0,2,2,1] ? false
    [2,2,2,2] is_alias [0,2,2,2] ? false
    [2,2,2,2] is_alias [1,0,0,0] ? false
    [2,2,2,2] is_alias [1,0,0,1] ? false
    [2,2,2,2] is_alias [1,0,0,2] ? false
    [2,2,2,2] is_alias [1,0,1,0] ? false
    [2,2,2,2] is_alias [1,0,1,1] ? false
    [2,2,2,2] is_alias [1,0,1,2] ? false
    [2,2,2,2] is_alias [1,0,2,0] ? false
    [2,2,2,2] is_alias [1,0,2,1] ? false
    [2,2,2,2] is_alias [1,0,2,2] ? false
    [2,2,2,2] is_alias [1,1,0,0] ? false
    [2,2,2,2] is_alias [1,1,0,1] ? false
    [2,2,2,2] is_alias [1,1,0,2] ? false
    [2,2,2,2] is_alias [1,1,1,0] ? false
    [2,2,2,2] is_alias [1,1,1,1] ? false
    [2,2,2,2] is_alias [1,1,1,2] ? false
    [2,2,2,2] is_alias [1,1,2,0] ? false
    [2,2,2,2] is_alias [1,1,2,1] ? false
    [2,2,2,2] is_alias [1,1,2,2] ? false
    [2,2,2,2] is_alias [1,2,0,0] ? false
    [2,2,2,2] is_alias [1,2,0,1] ? false
    [2,2,2,2] is_alias [1,2,0,2] ? false
    [2,2,2,2] is_alias [1,2,1,0] ? false
    [2,2,2,2] is_alias [1,2,1,1] ? false
    [2,2,2,2] is_alias [1,2,1,2] ? false
    [2,2,2,2] is_alias [1,2,2,0] ? false
    [2,2,2,2] is_alias [1,2,2,1] ? false
    [2,2,2,2] is_alias [1,2,2,2] ? false
    [2,2,2,2] is_alias [2,0,0,0] ? false
    [2,2,2,2] is_alias [2,0,0,1] ? false
    [2,2,2,2] is_alias [2,0,0,2] ? false
    [2,2,2,2] is_alias [2,0,1,0] ? false
    [2,2,2,2] is_alias [2,0,1,1] ? false
    [2,2,2,2] is_alias [2,0,1,2] ? false
    [2,2,2,2] is_alias [2,0,2,0] ? false
    [2,2,2,2] is_alias [2,0,2,1] ? false
    [2,2,2,2] is_alias [2,0,2,2] ? false
    [2,2,2,2] is_alias [2,1,0,0] ? false
    [2,2,2,2] is_alias [2,1,0,1] ? false
    [2,2,2,2] is_alias [2,1,0,2] ? false
    [2,2,2,2] is_alias [2,1,1,0] ? false
    [2,2,2,2] is_alias [2,1,1,1] ? false
    [2,2,2,2] is_alias [2,1,1,2] ? false
    [2,2,2,2] is_alias [2,1,2,0] ? false
    [2,2,2,2] is_alias [2,1,2,1] ? false
    [2,2,2,2] is_alias [2,1,2,2] ? false
    [2,2,2,2] is_alias [2,2,0,0] ? false
    [2,2,2,2] is_alias [2,2,0,1] ? false
    [2,2,2,2] is_alias [2,2,0,2] ? false
    [2,2,2,2] is_alias [2,2,1,0] ? false
    [2,2,2,2] is_alias [2,2,1,1] ? false
    [2,2,2,2] is_alias [2,2,1,2] ? false
    [2,2,2,2] is_alias [2,2,2,0] ? false
    [2,2,2,2] is_alias [2,2,2,1] ? false
    [2,2,2,2] is_alias [2,2,2,2] ? false

    === monoclinicx2 symmetry group type predicates
    [0,0,0,0] index has alias ? : false
    [0,0,0,1] index has alias ? : false
    [0,0,0,2] index has alias ? : true
    [0,0,1,0] index has alias ? : false
    [0,0,1,1] index has alias ? : true
    [0,0,1,2] index has alias ? : false
    [0,0,2,0] index has alias ? : true
    [0,0,2,1] index has alias ? : false
    [0,0,2,2] index has alias ? : true
    [0,1,0,0] index has alias ? : false
    [0,1,0,1] index has alias ? : true
    [0,1,0,2] index has alias ? : false
    [0,1,1,0] index has alias ? : true
    [0,1,1,1] index has alias ? : false
    [0,1,1,2] index has alias ? : true
    [0,1,2,0] index has alias ? : false
    [0,1,2,1] index has alias ? : true
    [0,1,2,2] index has alias ? : false
    [0,2,0,0] index has alias ? : true
    [0,2,0,1] index has alias ? : false
    [0,2,0,2] index has alias ? : true
    [0,2,1,0] index has alias ? : false
    [0,2,1,1] index has alias ? : true
    [0,2,1,2] index has alias ? : false
    [0,2,2,0] index has alias ? : true
    [0,2,2,1] index has alias ? : false
    [0,2,2,2] index has alias ? : true
    [1,0,0,0] index has alias ? : false
    [1,0,0,1] index has alias ? : true
    [1,0,0,2] index has alias ? : false
    [1,0,1,0] index has alias ? : true
    [1,0,1,1] index has alias ? : false
    [1,0,1,2] index has alias ? : true
    [1,0,2,0] index has alias ? : false
    [1,0,2,1] index has alias ? : true
    [1,0,2,2] index has alias ? : false
    [1,1,0,0] index has alias ? : true
    [1,1,0,1] index has alias ? : false
    [1,1,0,2] index has alias ? : true
    [1,1,1,0] index has alias ? : false
    [1,1,1,1] index has alias ? : false
    [1,1,1,2] index has alias ? : false
    [1,1,2,0] index has alias ? : true
    [1,1,2,1] index has alias ? : false
    [1,1,2,2] index has alias ? : true
    [1,2,0,0] index has alias ? : false
    [1,2,0,1] index has alias ? : true
    [1,2,0,2] index has alias ? : false
    [1,2,1,0] index has alias ? : true
    [1,2,1,1] index has alias ? : false
    [1,2,1,2] index has alias ? : true
    [1,2,2,0] index has alias ? : false
    [1,2,2,1] index has alias ? : true
    [1,2,2,2] index has alias ? : false
    [2,0,0,0] index has alias ? : true
    [2,0,0,1] index has alias ? : false
    [2,0,0,2] index has alias ? : true
    [2,0,1,0] index has alias ? : false
    [2,0,1,1] index has alias ? : true
    [2,0,1,2] index has alias ? : false
    [2,0,2,0] index has alias ? : true
    [2,0,2,1] index has alias ? : false
    [2,0,2,2] index has alias ? : true
    [2,1,0,0] index has alias ? : false
    [2,1,0,1] index has alias ? : true
    [2,1,0,2] index has alias ? : false
    [2,1,1,0] index has alias ? : true
    [2,1,1,1] index has alias ? : false
    [2,1,1,2] index has alias ? : true
    [2,1,2,0] index has alias ? : false
    [2,1,2,1] index has alias ? : true
    [2,1,2,2] index has alias ? : false
    [2,2,0,0] index has alias ? : true
    [2,2,0,1] index has alias ? : false
    [2,2,0,2] index has alias ? : true
    [2,2,1,0] index has alias ? : false
    [2,2,1,1] index has alias ? : true
    [2,2,1,2] index has alias ? : false
    [2,2,2,0] index has alias ? : true
    [2,2,2,1] index has alias ? : false
    [2,2,2,2] index has alias ? : false

    === monoclinicx3 symmetry group type predicates
    [0,0,0,0] index has alias ? : false
    [0,0,0,1] index has alias ? : true
    [0,0,0,2] index has alias ? : false
    [0,0,1,0] index has alias ? : true
    [0,0,1,1] index has alias ? : true
    [0,0,1,2] index has alias ? : false
    [0,0,2,0] index has alias ? : false
    [0,0,2,1] index has alias ? : false
    [0,0,2,2] index has alias ? : true
    [0,1,0,0] index has alias ? : true
    [0,1,0,1] index has alias ? : true
    [0,1,0,2] index has alias ? : false
    [0,1,1,0] index has alias ? : true
    [0,1,1,1] index has alias ? : true
    [0,1,1,2] index has alias ? : false
    [0,1,2,0] index has alias ? : false
    [0,1,2,1] index has alias ? : false
    [0,1,2,2] index has alias ? : true
    [0,2,0,0] index has alias ? : false
    [0,2,0,1] index has alias ? : false
    [0,2,0,2] index has alias ? : true
    [0,2,1,0] index has alias ? : false
    [0,2,1,1] index has alias ? : false
    [0,2,1,2] index has alias ? : true
    [0,2,2,0] index has alias ? : true
    [0,2,2,1] index has alias ? : true
    [0,2,2,2] index has alias ? : false
    [1,0,0,0] index has alias ? : true
    [1,0,0,1] index has alias ? : true
    [1,0,0,2] index has alias ? : false
    [1,0,1,0] index has alias ? : true
    [1,0,1,1] index has alias ? : true
    [1,0,1,2] index has alias ? : false
    [1,0,2,0] index has alias ? : false
    [1,0,2,1] index has alias ? : false
    [1,0,2,2] index has alias ? : true
    [1,1,0,0] index has alias ? : true
    [1,1,0,1] index has alias ? : true
    [1,1,0,2] index has alias ? : false
    [1,1,1,0] index has alias ? : true
    [1,1,1,1] index has alias ? : false
    [1,1,1,2] index has alias ? : false
    [1,1,2,0] index has alias ? : false
    [1,1,2,1] index has alias ? : false
    [1,1,2,2] index has alias ? : true
    [1,2,0,0] index has alias ? : false
    [1,2,0,1] index has alias ? : false
    [1,2,0,2] index has alias ? : true
    [1,2,1,0] index has alias ? : false
    [1,2,1,1] index has alias ? : false
    [1,2,1,2] index has alias ? : true
    [1,2,2,0] index has alias ? : true
    [1,2,2,1] index has alias ? : true
    [1,2,2,2] index has alias ? : false
    [2,0,0,0] index has alias ? : false
    [2,0,0,1] index has alias ? : false
    [2,0,0,2] index has alias ? : true
    [2,0,1,0] index has alias ? : false
    [2,0,1,1] index has alias ? : false
    [2,0,1,2] index has alias ? : true
    [2,0,2,0] index has alias ? : true
    [2,0,2,1] index has alias ? : true
    [2,0,2,2] index has alias ? : false
    [2,1,0,0] index has alias ? : false
    [2,1,0,1] index has alias ? : false
    [2,1,0,2] index has alias ? : true
    [2,1,1,0] index has alias ? : false
    [2,1,1,1] index has alias ? : false
    [2,1,1,2] index has alias ? : true
    [2,1,2,0] index has alias ? : true
    [2,1,2,1] index has alias ? : true
    [2,1,2,2] index has alias ? : false
    [2,2,0,0] index has alias ? : true
    [2,2,0,1] index has alias ? : true
    [2,2,0,2] index has alias ? : false
    [2,2,1,0] index has alias ? : true
    [2,2,1,1] index has alias ? : true
    [2,2,1,2] index has alias ? : false
    [2,2,2,0] index has alias ? : false
    [2,2,2,1] index has alias ? : false
    [2,2,2,2] index has alias ? : false

    === orthorhombic symmetry group type predicates
    [0,0,0,0] index has alias ? : false
    [0,0,0,1] index has alias ? : false
    [0,0,0,2] index has alias ? : false
    [0,0,1,0] index has alias ? : false
    [0,0,1,1] index has alias ? : true
    [0,0,1,2] index has alias ? : false
    [0,0,2,0] index has alias ? : false
    [0,0,2,1] index has alias ? : false
    [0,0,2,2] index has alias ? : true
    [0,1,0,0] index has alias ? : false
    [0,1,0,1] index has alias ? : true
    [0,1,0,2] index has alias ? : false
    [0,1,1,0] index has alias ? : true
    [0,1,1,1] index has alias ? : false
    [0,1,1,2] index has alias ? : false
    [0,1,2,0] index has alias ? : false
    [0,1,2,1] index has alias ? : false
    [0,1,2,2] index has alias ? : false
    [0,2,0,0] index has alias ? : false
    [0,2,0,1] index has alias ? : false
    [0,2,0,2] index has alias ? : true
    [0,2,1,0] index has alias ? : false
    [0,2,1,1] index has alias ? : false
    [0,2,1,2] index has alias ? : false
    [0,2,2,0] index has alias ? : true
    [0,2,2,1] index has alias ? : false
    [0,2,2,2] index has alias ? : false
    [1,0,0,0] index has alias ? : false
    [1,0,0,1] index has alias ? : true
    [1,0,0,2] index has alias ? : false
    [1,0,1,0] index has alias ? : true
    [1,0,1,1] index has alias ? : false
    [1,0,1,2] index has alias ? : false
    [1,0,2,0] index has alias ? : false
    [1,0,2,1] index has alias ? : false
    [1,0,2,2] index has alias ? : false
    [1,1,0,0] index has alias ? : true
    [1,1,0,1] index has alias ? : false
    [1,1,0,2] index has alias ? : false
    [1,1,1,0] index has alias ? : false
    [1,1,1,1] index has alias ? : false
    [1,1,1,2] index has alias ? : false
    [1,1,2,0] index has alias ? : false
    [1,1,2,1] index has alias ? : false
    [1,1,2,2] index has alias ? : true
    [1,2,0,0] index has alias ? : false
    [1,2,0,1] index has alias ? : false
    [1,2,0,2] index has alias ? : false
    [1,2,1,0] index has alias ? : false
    [1,2,1,1] index has alias ? : false
    [1,2,1,2] index has alias ? : true
    [1,2,2,0] index has alias ? : false
    [1,2,2,1] index has alias ? : true
    [1,2,2,2] index has alias ? : false
    [2,0,0,0] index has alias ? : false
    [2,0,0,1] index has alias ? : false
    [2,0,0,2] index has alias ? : true
    [2,0,1,0] index has alias ? : false
    [2,0,1,1] index has alias ? : false
    [2,0,1,2] index has alias ? : false
    [2,0,2,0] index has alias ? : true
    [2,0,2,1] index has alias ? : false
    [2,0,2,2] index has alias ? : false
    [2,1,0,0] index has alias ? : false
    [2,1,0,1] index has alias ? : false
    [2,1,0,2] index has alias ? : false
    [2,1,1,0] index has alias ? : false
    [2,1,1,1] index has alias ? : false
    [2,1,1,2] index has alias ? : true
    [2,1,2,0] index has alias ? : false
    [2,1,2,1] index has alias ? : true
    [2,1,2,2] index has alias ? : false
    [2,2,0,0] index has alias ? : true
    [2,2,0,1] index has alias ? : false
    [2,2,0,2] index has alias ? : false
    [2,2,1,0] index has alias ? : false
    [2,2,1,1] index has alias ? : true
    [2,2,1,2] index has alias ? : false
    [2,2,2,0] index has alias ? : false
    [2,2,2,1] index has alias ? : false
    [2,2,2,2] index has alias ? : false

    === hexagonal symmetry group type predicates
    [0,0,0,0] index has alias ? : true
    [0,0,0,1] index has alias ? : false
    [0,0,0,2] index has alias ? : false
    [0,0,1,0] index has alias ? : false
    [0,0,1,1] index has alias ? : true
    [0,0,1,2] index has alias ? : false
    [0,0,2,0] index has alias ? : false
    [0,0,2,1] index has alias ? : false
    [0,0,2,2] index has alias ? : true
    [0,1,0,0] index has alias ? : false
    [0,1,0,1] index has alias ? : true
    [0,1,0,2] index has alias ? : false
    [0,1,1,0] index has alias ? : true
    [0,1,1,1] index has alias ? : false
    [0,1,1,2] index has alias ? : false
    [0,1,2,0] index has alias ? : false
    [0,1,2,1] index has alias ? : false
    [0,1,2,2] index has alias ? : false
    [0,2,0,0] index has alias ? : false
    [0,2,0,1] index has alias ? : false
    [0,2,0,2] index has alias ? : true
    [0,2,1,0] index has alias ? : false
    [0,2,1,1] index has alias ? : false
    [0,2,1,2] index has alias ? : false
    [0,2,2,0] index has alias ? : true
    [0,2,2,1] index has alias ? : false
    [0,2,2,2] index has alias ? : false
    [1,0,0,0] index has alias ? : false
    [1,0,0,1] index has alias ? : true
    [1,0,0,2] index has alias ? : false
    [1,0,1,0] index has alias ? : true
    [1,0,1,1] index has alias ? : false
    [1,0,1,2] index has alias ? : false
    [1,0,2,0] index has alias ? : false
    [1,0,2,1] index has alias ? : false
    [1,0,2,2] index has alias ? : false
    [1,1,0,0] index has alias ? : true
    [1,1,0,1] index has alias ? : false
    [1,1,0,2] index has alias ? : false
    [1,1,1,0] index has alias ? : false
    [1,1,1,1] index has alias ? : true
    [1,1,1,2] index has alias ? : false
    [1,1,2,0] index has alias ? : false
    [1,1,2,1] index has alias ? : false
    [1,1,2,2] index has alias ? : true
    [1,2,0,0] index has alias ? : false
    [1,2,0,1] index has alias ? : false
    [1,2,0,2] index has alias ? : false
    [1,2,1,0] index has alias ? : false
    [1,2,1,1] index has alias ? : false
    [1,2,1,2] index has alias ? : true
    [1,2,2,0] index has alias ? : false
    [1,2,2,1] index has alias ? : true
    [1,2,2,2] index has alias ? : false
    [2,0,0,0] index has alias ? : false
    [2,0,0,1] index has alias ? : false
    [2,0,0,2] index has alias ? : true
    [2,0,1,0] index has alias ? : false
    [2,0,1,1] index has alias ? : false
    [2,0,1,2] index has alias ? : false
    [2,0,2,0] index has alias ? : true
    [2,0,2,1] index has alias ? : false
    [2,0,2,2] index has alias ? : false
    [2,1,0,0] index has alias ? : false
    [2,1,0,1] index has alias ? : false
    [2,1,0,2] index has alias ? : false
    [2,1,1,0] index has alias ? : false
    [2,1,1,1] index has alias ? : false
    [2,1,1,2] index has alias ? : true
    [2,1,2,0] index has alias ? : false
    [2,1,2,1] index has alias ? : true
    [2,1,2,2] index has alias ? : false
    [2,2,0,0] index has alias ? : true
    [2,2,0,1] index has alias ? : false
    [2,2,0,2] index has alias ? : false
    [2,2,1,0] index has alias ? : false
    [2,2,1,1] index has alias ? : true
    [2,2,1,2] index has alias ? : false
    [2,2,2,0] index has alias ? : false
    [2,2,2,1] index has alias ? : false
    [2,2,2,2] index has alias ? : false

    === tetragonal7 symmetry group type predicates
    [0,0,0,0] index has alias ? : true
    [0,0,0,1] index has alias ? : true
    [0,0,0,2] index has alias ? : false
    [0,0,1,0] index has alias ? : true
    [0,0,1,1] index has alias ? : true
    [0,0,1,2] index has alias ? : false
    [0,0,2,0] index has alias ? : false
    [0,0,2,1] index has alias ? : false
    [0,0,2,2] index has alias ? : true
    [0,1,0,0] index has alias ? : true
    [0,1,0,1] index has alias ? : true
    [0,1,0,2] index has alias ? : false
    [0,1,1,0] index has alias ? : true
    [0,1,1,1] index has alias ? : true
    [0,1,1,2] index has alias ? : false
    [0,1,2,0] index has alias ? : false
    [0,1,2,1] index has alias ? : false
    [0,1,2,2] index has alias ? : false
    [0,2,0,0] index has alias ? : false
    [0,2,0,1] index has alias ? : false
    [0,2,0,2] index has alias ? : true
    [0,2,1,0] index has alias ? : false
    [0,2,1,1] index has alias ? : false
    [0,2,1,2] index has alias ? : false
    [0,2,2,0] index has alias ? : true
    [0,2,2,1] index has alias ? : false
    [0,2,2,2] index has alias ? : false
    [1,0,0,0] index has alias ? : true
    [1,0,0,1] index has alias ? : true
    [1,0,0,2] index has alias ? : false
    [1,0,1,0] index has alias ? : true
    [1,0,1,1] index has alias ? : true
    [1,0,1,2] index has alias ? : false
    [1,0,2,0] index has alias ? : false
    [1,0,2,1] index has alias ? : false
    [1,0,2,2] index has alias ? : false
    [1,1,0,0] index has alias ? : true
    [1,1,0,1] index has alias ? : true
    [1,1,0,2] index has alias ? : false
    [1,1,1,0] index has alias ? : true
    [1,1,1,1] index has alias ? : true
    [1,1,1,2] index has alias ? : false
    [1,1,2,0] index has alias ? : false
    [1,1,2,1] index has alias ? : false
    [1,1,2,2] index has alias ? : true
    [1,2,0,0] index has alias ? : false
    [1,2,0,1] index has alias ? : false
    [1,2,0,2] index has alias ? : false
    [1,2,1,0] index has alias ? : false
    [1,2,1,1] index has alias ? : false
    [1,2,1,2] index has alias ? : true
    [1,2,2,0] index has alias ? : false
    [1,2,2,1] index has alias ? : true
    [1,2,2,2] index has alias ? : false
    [2,0,0,0] index has alias ? : false
    [2,0,0,1] index has alias ? : false
    [2,0,0,2] index has alias ? : true
    [2,0,1,0] index has alias ? : false
    [2,0,1,1] index has alias ? : false
    [2,0,1,2] index has alias ? : false
    [2,0,2,0] index has alias ? : true
    [2,0,2,1] index has alias ? : false
    [2,0,2,2] index has alias ? : false
    [2,1,0,0] index has alias ? : false
    [2,1,0,1] index has alias ? : false
    [2,1,0,2] index has alias ? : false
    [2,1,1,0] index has alias ? : false
    [2,1,1,1] index has alias ? : false
    [2,1,1,2] index has alias ? : true
    [2,1,2,0] index has alias ? : false
    [2,1,2,1] index has alias ? : true
    [2,1,2,2] index has alias ? : false
    [2,2,0,0] index has alias ? : true
    [2,2,0,1] index has alias ? : false
    [2,2,0,2] index has alias ? : false
    [2,2,1,0] index has alias ? : false
    [2,2,1,1] index has alias ? : true
    [2,2,1,2] index has alias ? : false
    [2,2,2,0] index has alias ? : false
    [2,2,2,1] index has alias ? : false
    [2,2,2,2] index has alias ? : false

    === tetragonal6 symmetry group type predicates
    [0,0,0,0] index has alias ? : true
    [0,0,0,1] index has alias ? : false
    [0,0,0,2] index has alias ? : false
    [0,0,1,0] index has alias ? : false
    [0,0,1,1] index has alias ? : true
    [0,0,1,2] index has alias ? : false
    [0,0,2,0] index has alias ? : false
    [0,0,2,1] index has alias ? : false
    [0,0,2,2] index has alias ? : true
    [0,1,0,0] index has alias ? : false
    [0,1,0,1] index has alias ? : true
    [0,1,0,2] index has alias ? : false
    [0,1,1,0] index has alias ? : true
    [0,1,1,1] index has alias ? : false
    [0,1,1,2] index has alias ? : false
    [0,1,2,0] index has alias ? : false
    [0,1,2,1] index has alias ? : false
    [0,1,2,2] index has alias ? : false
    [0,2,0,0] index has alias ? : false
    [0,2,0,1] index has alias ? : false
    [0,2,0,2] index has alias ? : true
    [0,2,1,0] index has alias ? : false
    [0,2,1,1] index has alias ? : false
    [0,2,1,2] index has alias ? : false
    [0,2,2,0] index has alias ? : true
    [0,2,2,1] index has alias ? : false
    [0,2,2,2] index has alias ? : false
    [1,0,0,0] index has alias ? : false
    [1,0,0,1] index has alias ? : true
    [1,0,0,2] index has alias ? : false
    [1,0,1,0] index has alias ? : true
    [1,0,1,1] index has alias ? : false
    [1,0,1,2] index has alias ? : false
    [1,0,2,0] index has alias ? : false
    [1,0,2,1] index has alias ? : false
    [1,0,2,2] index has alias ? : false
    [1,1,0,0] index has alias ? : true
    [1,1,0,1] index has alias ? : false
    [1,1,0,2] index has alias ? : false
    [1,1,1,0] index has alias ? : false
    [1,1,1,1] index has alias ? : true
    [1,1,1,2] index has alias ? : false
    [1,1,2,0] index has alias ? : false
    [1,1,2,1] index has alias ? : false
    [1,1,2,2] index has alias ? : true
    [1,2,0,0] index has alias ? : false
    [1,2,0,1] index has alias ? : false
    [1,2,0,2] index has alias ? : false
    [1,2,1,0] index has alias ? : false
    [1,2,1,1] index has alias ? : false
    [1,2,1,2] index has alias ? : true
    [1,2,2,0] index has alias ? : false
    [1,2,2,1] index has alias ? : true
    [1,2,2,2] index has alias ? : false
    [2,0,0,0] index has alias ? : false
    [2,0,0,1] index has alias ? : false
    [2,0,0,2] index has alias ? : true
    [2,0,1,0] index has alias ? : false
    [2,0,1,1] index has alias ? : false
    [2,0,1,2] index has alias ? : false
    [2,0,2,0] index has alias ? : true
    [2,0,2,1] index has alias ? : false
    [2,0,2,2] index has alias ? : false
    [2,1,0,0] index has alias ? : false
    [2,1,0,1] index has alias ? : false
    [2,1,0,2] index has alias ? : false
    [2,1,1,0] index has alias ? : false
    [2,1,1,1] index has alias ? : false
    [2,1,1,2] index has alias ? : true
    [2,1,2,0] index has alias ? : false
    [2,1,2,1] index has alias ? : true
    [2,1,2,2] index has alias ? : false
    [2,2,0,0] index has alias ? : true
    [2,2,0,1] index has alias ? : false
    [2,2,0,2] index has alias ? : false
    [2,2,1,0] index has alias ? : false
    [2,2,1,1] index has alias ? : true
    [2,2,1,2] index has alias ? : false
    [2,2,2,0] index has alias ? : false
    [2,2,2,1] index has alias ? : false
    [2,2,2,2] index has alias ? : false

    === trigonal7 symmetry group type predicates
    [0,0,0,0] index has alias ? : true
    [0,0,0,1] index has alias ? : false
    [0,0,0,2] index has alias ? : true
    [0,0,1,0] index has alias ? : false
    [0,0,1,1] index has alias ? : true
    [0,0,1,2] index has alias ? : true
    [0,0,2,0] index has alias ? : true
    [0,0,2,1] index has alias ? : true
    [0,0,2,2] index has alias ? : true
    [0,1,0,0] index has alias ? : false
    [0,1,0,1] index has alias ? : true
    [0,1,0,2] index has alias ? : true
    [0,1,1,0] index has alias ? : true
    [0,1,1,1] index has alias ? : false
    [0,1,1,2] index has alias ? : true
    [0,1,2,0] index has alias ? : true
    [0,1,2,1] index has alias ? : true
    [0,1,2,2] index has alias ? : false
    [0,2,0,0] index has alias ? : true
    [0,2,0,1] index has alias ? : true
    [0,2,0,2] index has alias ? : true
    [0,2,1,0] index has alias ? : true
    [0,2,1,1] index has alias ? : true
    [0,2,1,2] index has alias ? : false
    [0,2,2,0] index has alias ? : true
    [0,2,2,1] index has alias ? : false
    [0,2,2,2] index has alias ? : false
    [1,0,0,0] index has alias ? : false
    [1,0,0,1] index has alias ? : true
    [1,0,0,2] index has alias ? : true
    [1,0,1,0] index has alias ? : true
    [1,0,1,1] index has alias ? : false
    [1,0,1,2] index has alias ? : true
    [1,0,2,0] index has alias ? : true
    [1,0,2,1] index has alias ? : true
    [1,0,2,2] index has alias ? : false
    [1,1,0,0] index has alias ? : true
    [1,1,0,1] index has alias ? : false
    [1,1,0,2] index has alias ? : true
    [1,1,1,0] index has alias ? : false
    [1,1,1,1] index has alias ? : true
    [1,1,1,2] index has alias ? : true
    [1,1,2,0] index has alias ? : true
    [1,1,2,1] index has alias ? : true
    [1,1,2,2] index has alias ? : true
    [1,2,0,0] index has alias ? : true
    [1,2,0,1] index has alias ? : true
    [1,2,0,2] index has alias ? : false
    [1,2,1,0] index has alias ? : true
    [1,2,1,1] index has alias ? : true
    [1,2,1,2] index has alias ? : true
    [1,2,2,0] index has alias ? : false
    [1,2,2,1] index has alias ? : true
    [1,2,2,2] index has alias ? : false
    [2,0,0,0] index has alias ? : true
    [2,0,0,1] index has alias ? : true
    [2,0,0,2] index has alias ? : true
    [2,0,1,0] index has alias ? : true
    [2,0,1,1] index has alias ? : true
    [2,0,1,2] index has alias ? : false
    [2,0,2,0] index has alias ? : true
    [2,0,2,1] index has alias ? : false
    [2,0,2,2] index has alias ? : false
    [2,1,0,0] index has alias ? : true
    [2,1,0,1] index has alias ? : true
    [2,1,0,2] index has alias ? : false
    [2,1,1,0] index has alias ? : true
    [2,1,1,1] index has alias ? : true
    [2,1,1,2] index has alias ? : true
    [2,1,2,0] index has alias ? : false
    [2,1,2,1] index has alias ? : true
    [2,1,2,2] index has alias ? : false
    [2,2,0,0] index has alias ? : true
    [2,2,0,1] index has alias ? : false
    [2,2,0,2] index has alias ? : false
    [2,2,1,0] index has alias ? : false
    [2,2,1,1] index has alias ? : true
    [2,2,1,2] index has alias ? : false
    [2,2,2,0] index has alias ? : false
    [2,2,2,1] index has alias ? : false
    [2,2,2,2] index has alias ? : false

    === trigonal6 symmetry group type predicates
    [0,0,0,0] index has alias ? : true
    [0,0,0,1] index has alias ? : false
    [0,0,0,2] index has alias ? : false
    [0,0,1,0] index has alias ? : false
    [0,0,1,1] index has alias ? : true
    [0,0,1,2] index has alias ? : true
    [0,0,2,0] index has alias ? : false
    [0,0,2,1] index has alias ? : true
    [0,0,2,2] index has alias ? : true
    [0,1,0,0] index has alias ? : false
    [0,1,0,1] index has alias ? : true
    [0,1,0,2] index has alias ? : true
    [0,1,1,0] index has alias ? : true
    [0,1,1,1] index has alias ? : false
    [0,1,1,2] index has alias ? : false
    [0,1,2,0] index has alias ? : true
    [0,1,2,1] index has alias ? : false
    [0,1,2,2] index has alias ? : false
    [0,2,0,0] index has alias ? : false
    [0,2,0,1] index has alias ? : true
    [0,2,0,2] index has alias ? : true
    [0,2,1,0] index has alias ? : true
    [0,2,1,1] index has alias ? : false
    [0,2,1,2] index has alias ? : false
    [0,2,2,0] index has alias ? : true
    [0,2,2,1] index has alias ? : false
    [0,2,2,2] index has alias ? : false
    [1,0,0,0] index has alias ? : false
    [1,0,0,1] index has alias ? : true
    [1,0,0,2] index has alias ? : true
    [1,0,1,0] index has alias ? : true
    [1,0,1,1] index has alias ? : false
    [1,0,1,2] index has alias ? : false
    [1,0,2,0] index has alias ? : true
    [1,0,2,1] index has alias ? : false
    [1,0,2,2] index has alias ? : false
    [1,1,0,0] index has alias ? : true
    [1,1,0,1] index has alias ? : false
    [1,1,0,2] index has alias ? : false
    [1,1,1,0] index has alias ? : false
    [1,1,1,1] index has alias ? : true
    [1,1,1,2] index has alias ? : true
    [1,1,2,0] index has alias ? : false
    [1,1,2,1] index has alias ? : true
    [1,1,2,2] index has alias ? : true
    [1,2,0,0] index has alias ? : true
    [1,2,0,1] index has alias ? : false
    [1,2,0,2] index has alias ? : false
    [1,2,1,0] index has alias ? : false
    [1,2,1,1] index has alias ? : true
    [1,2,1,2] index has alias ? : true
    [1,2,2,0] index has alias ? : false
    [1,2,2,1] index has alias ? : true
    [1,2,2,2] index has alias ? : false
    [2,0,0,0] index has alias ? : false
    [2,0,0,1] index has alias ? : true
    [2,0,0,2] index has alias ? : true
    [2,0,1,0] index has alias ? : true
    [2,0,1,1] index has alias ? : false
    [2,0,1,2] index has alias ? : false
    [2,0,2,0] index has alias ? : true
    [2,0,2,1] index has alias ? : false
    [2,0,2,2] index has alias ? : false
    [2,1,0,0] index has alias ? : true
    [2,1,0,1] index has alias ? : false
    [2,1,0,2] index has alias ? : false
    [2,1,1,0] index has alias ? : false
    [2,1,1,1] index has alias ? : true
    [2,1,1,2] index has alias ? : true
    [2,1,2,0] index has alias ? : false
    [2,1,2,1] index has alias ? : true
    [2,1,2,2] index has alias ? : false
    [2,2,0,0] index has alias ? : true
    [2,2,0,1] index has alias ? : false
    [2,2,0,2] index has alias ? : false
    [2,2,1,0] index has alias ? : false
    [2,2,1,1] index has alias ? : true
    [2,2,1,2] index has alias ? : false
    [2,2,2,0] index has alias ? : false
    [2,2,2,1] index has alias ? : false
    [2,2,2,2] index has alias ? : false

    === cubic symmetry group type predicates
    [0,0,0,0] index has alias ? : true
    [0,0,0,1] index has alias ? : false
    [0,0,0,2] index has alias ? : false
    [0,0,1,0] index has alias ? : false
    [0,0,1,1] index has alias ? : true
    [0,0,1,2] index has alias ? : false
    [0,0,2,0] index has alias ? : false
    [0,0,2,1] index has alias ? : false
    [0,0,2,2] index has alias ? : true
    [0,1,0,0] index has alias ? : false
    [0,1,0,1] index has alias ? : true
    [0,1,0,2] index has alias ? : false
    [0,1,1,0] index has alias ? : true
    [0,1,1,1] index has alias ? : false
    [0,1,1,2] index has alias ? : false
    [0,1,2,0] index has alias ? : false
    [0,1,2,1] index has alias ? : false
    [0,1,2,2] index has alias ? : false
    [0,2,0,0] index has alias ? : false
    [0,2,0,1] index has alias ? : false
    [0,2,0,2] index has alias ? : true
    [0,2,1,0] index has alias ? : false
    [0,2,1,1] index has alias ? : false
    [0,2,1,2] index has alias ? : false
    [0,2,2,0] index has alias ? : true
    [0,2,2,1] index has alias ? : false
    [0,2,2,2] index has alias ? : false
    [1,0,0,0] index has alias ? : false
    [1,0,0,1] index has alias ? : true
    [1,0,0,2] index has alias ? : false
    [1,0,1,0] index has alias ? : true
    [1,0,1,1] index has alias ? : false
    [1,0,1,2] index has alias ? : false
    [1,0,2,0] index has alias ? : false
    [1,0,2,1] index has alias ? : false
    [1,0,2,2] index has alias ? : false
    [1,1,0,0] index has alias ? : true
    [1,1,0,1] index has alias ? : false
    [1,1,0,2] index has alias ? : false
    [1,1,1,0] index has alias ? : false
    [1,1,1,1] index has alias ? : true
    [1,1,1,2] index has alias ? : false
    [1,1,2,0] index has alias ? : false
    [1,1,2,1] index has alias ? : false
    [1,1,2,2] index has alias ? : true
    [1,2,0,0] index has alias ? : false
    [1,2,0,1] index has alias ? : false
    [1,2,0,2] index has alias ? : false
    [1,2,1,0] index has alias ? : false
    [1,2,1,1] index has alias ? : false
    [1,2,1,2] index has alias ? : true
    [1,2,2,0] index has alias ? : false
    [1,2,2,1] index has alias ? : true
    [1,2,2,2] index has alias ? : false
    [2,0,0,0] index has alias ? : false
    [2,0,0,1] index has alias ? : false
    [2,0,0,2] index has alias ? : true
    [2,0,1,0] index has alias ? : false
    [2,0,1,1] index has alias ? : false
    [2,0,1,2] index has alias ? : false
    [2,0,2,0] index has alias ? : true
    [2,0,2,1] index has alias ? : false
    [2,0,2,2] index has alias ? : false
    [2,1,0,0] index has alias ? : false
    [2,1,0,1] index has alias ? : false
    [2,1,0,2] index has alias ? : false
    [2,1,1,0] index has alias ? : false
    [2,1,1,1] index has alias ? : false
    [2,1,1,2] index has alias ? : true
    [2,1,2,0] index has alias ? : false
    [2,1,2,1] index has alias ? : true
    [2,1,2,2] index has alias ? : false
    [2,2,0,0] index has alias ? : true
    [2,2,0,1] index has alias ? : false
    [2,2,0,2] index has alias ? : false
    [2,2,1,0] index has alias ? : false
    [2,2,1,1] index has alias ? : true
    [2,2,1,2] index has alias ? : false
    [2,2,2,0] index has alias ? : false
    [2,2,2,1] index has alias ? : false
    [2,2,2,2] index has alias ? : true

    === isotropic symmetry group type predicates
    [0,0,0,0] index has alias ? : true
    [0,0,0,1] index has alias ? : false
    [0,0,0,2] index has alias ? : false
    [0,0,1,0] index has alias ? : false
    [0,0,1,1] index has alias ? : true
    [0,0,1,2] index has alias ? : false
    [0,0,2,0] index has alias ? : false
    [0,0,2,1] index has alias ? : false
    [0,0,2,2] index has alias ? : true
    [0,1,0,0] index has alias ? : false
    [0,1,0,1] index has alias ? : true
    [0,1,0,2] index has alias ? : false
    [0,1,1,0] index has alias ? : true
    [0,1,1,1] index has alias ? : false
    [0,1,1,2] index has alias ? : false
    [0,1,2,0] index has alias ? : false
    [0,1,2,1] index has alias ? : false
    [0,1,2,2] index has alias ? : false
    [0,2,0,0] index has alias ? : false
    [0,2,0,1] index has alias ? : false
    [0,2,0,2] index has alias ? : true
    [0,2,1,0] index has alias ? : false
    [0,2,1,1] index has alias ? : false
    [0,2,1,2] index has alias ? : false
    [0,2,2,0] index has alias ? : true
    [0,2,2,1] index has alias ? : false
    [0,2,2,2] index has alias ? : false
    [1,0,0,0] index has alias ? : false
    [1,0,0,1] index has alias ? : true
    [1,0,0,2] index has alias ? : false
    [1,0,1,0] index has alias ? : true
    [1,0,1,1] index has alias ? : false
    [1,0,1,2] index has alias ? : false
    [1,0,2,0] index has alias ? : false
    [1,0,2,1] index has alias ? : false
    [1,0,2,2] index has alias ? : false
    [1,1,0,0] index has alias ? : true
    [1,1,0,1] index has alias ? : false
    [1,1,0,2] index has alias ? : false
    [1,1,1,0] index has alias ? : false
    [1,1,1,1] index has alias ? : true
    [1,1,1,2] index has alias ? : false
    [1,1,2,0] index has alias ? : false
    [1,1,2,1] index has alias ? : false
    [1,1,2,2] index has alias ? : true
    [1,2,0,0] index has alias ? : false
    [1,2,0,1] index has alias ? : false
    [1,2,0,2] index has alias ? : false
    [1,2,1,0] index has alias ? : false
    [1,2,1,1] index has alias ? : false
    [1,2,1,2] index has alias ? : true
    [1,2,2,0] index has alias ? : false
    [1,2,2,1] index has alias ? : true
    [1,2,2,2] index has alias ? : false
    [2,0,0,0] index has alias ? : false
    [2,0,0,1] index has alias ? : false
    [2,0,0,2] index has alias ? : true
    [2,0,1,0] index has alias ? : false
    [2,0,1,1] index has alias ? : false
    [2,0,1,2] index has alias ? : false
    [2,0,2,0] index has alias ? : true
    [2,0,2,1] index has alias ? : false
    [2,0,2,2] index has alias ? : false
    [2,1,0,0] index has alias ? : false
    [2,1,0,1] index has alias ? : false
    [2,1,0,2] index has alias ? : false
    [2,1,1,0] index has alias ? : false
    [2,1,1,1] index has alias ? : false
    [2,1,1,2] index has alias ? : true
    [2,1,2,0] index has alias ? : false
    [2,1,2,1] index has alias ? : true
    [2,1,2,2] index has alias ? : false
    [2,2,0,0] index has alias ? : true
    [2,2,0,1] index has alias ? : false
    [2,2,0,2] index has alias ? : false
    [2,2,1,0] index has alias ? : false
    [2,2,1,1] index has alias ? : true
    [2,2,1,2] index has alias ? : false
    [2,2,2,0] index has alias ? : false
    [2,2,2,1] index has alias ? : false
    [2,2,2,2] index has alias ? : true

#### TensorComponent

The next step is to build the tensor compoents using the tensor component index and assigning a value. The class <code>TensorRank2Component<T></code> is a template class that takes an argument that must be a floating point type, that is float, double, or long double.

[mpcexamples::mpcTensorRank2Component()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_tensorrank2component.cpp)

```cpp
mpc::core::TensorRankNComponent<double,2> component00 = mpc::core::TensorRankNComponent<double,2>(11.0, mpc::core::TensorRank2ComponentIndex(0,0));
std::cout << "component00 : " << component00 << std::endl;
mpc::core::TensorRank2Component<double> component01 = mpc::core::TensorRank2Component<double>(12.0, mpc::core::TensorRank2ComponentIndex(0,1));
std::cout << "component01 : " << component01 << std::endl;
mpc::core::TensorRank2Component<double> component02 = mpc::core::TensorRank2Component<double>(13.0, mpc::core::TensorRank2ComponentIndex(0,2));
std::cout << "component01 : " << component02 << std::endl;
mpc::core::TensorRank2Component<double> component10 = mpc::core::TensorRank2Component<double>(21.0, mpc::core::TensorRank2ComponentIndex(1,0));
std::cout << "component01 : " << component10 << std::endl;
mpc::core::TensorRank2Component<double> component11 = mpc::core::TensorRank2Component<double>(22.0, mpc::core::TensorRank2ComponentIndex(1,1));
std::cout << "component01 : " << component11 << std::endl;
mpc::core::TensorRank2Component<double> component12 = mpc::core::TensorRank2Component<double>(23.0, mpc::core::TensorRank2ComponentIndex(1,2));
std::cout << "component01 : " << component12 << std::endl;
mpc::core::TensorRank2Component<double> component20 = mpc::core::TensorRank2Component<double>(31.0, mpc::core::TensorRank2ComponentIndex(2,0));
std::cout << "component01 : " << component20 << std::endl;
mpc::core::TensorRank2Component<double> component21 = mpc::core::TensorRank2Component<double>(32.0, mpc::core::TensorRank2ComponentIndex(2,1));
std::cout << "component01 : " << component21 << std::endl;
mpc::core::TensorRank2Component<double> component22 = mpc::core::TensorRank2Component<double>(33.0, mpc::core::TensorRank2ComponentIndex(2,2));
std::cout << "component01 : " << component22 << std::endl;
```
Output

    component00 : 11.000000,[0,0]
    component01 : 12.000000,[0,1]
    component01 : 13.000000,[0,2]
    component01 : 21.000000,[1,0]
    component01 : 22.000000,[1,1]
    component01 : 23.000000,[1,2]
    component01 : 31.000000,[2,0]
    component01 : 32.000000,[2,1]
    component01 : 33.000000,[2,2]

MPC uses two additional libraries: blitz and eigen.  Below are a few
     *     examples of creating arrays in blitz and matrices in eigen...
```cpp
blitz::Array<double,1> barray1d(3);
barray1d = component00.Value(), component01.Value(), component02.Value();
std::cout << "blitz array 1d : " << barray1d << std::endl;

// NOTE the order in assignment!!! Its the transpose of the actual matrix;
//     this is becuase we used ColumnMajorArray for storage ordering.
blitz::Array<double,2> barray2d = blitz::Array<double,2>(3,3,blitz::ColumnMajorArray<2>());
barray2d = component00.Value(), component10.Value(), component20.Value(),
        component01.Value(), component11.Value(), component21.Value(),
        component02.Value(), component12.Value(), component22.Value();
std::cout << "blitz array 2d : " << barray2d << std::endl;

Eigen::Matrix<double,3,3> earray2d;
earray2d(0,0) = component00.Value();
earray2d(0,1) = component01.Value();
earray2d(0,2) = component02.Value();
earray2d(1,0) = component10.Value();
earray2d(1,1) = component11.Value();
earray2d(1,2) = component12.Value();
earray2d(2,0) = component20.Value();
earray2d(2,1) = component21.Value();
earray2d(2,2) = component22.Value();
std::cout << "Eigen array 2d : \n" << earray2d << std::endl;
```
Output

    blitz array 1d : (0,2)
    [ 11 12 13 ]

    blitz array 2d : (0,2) x (0,2)
    [ 11 12 13
      21 22 23
      31 32 33 ]

    Eigen array 2d :
    11 12 13
    21 22 23
    31 32 33

Comparison operators for tensor components are defined as

* "==" : two components are equal if the index AND the value are equal
* "!=" : two components are not equal if the index OR the value are not equal
* "<"  : lhs component is less than rhs component if lhs component index is less than rhs component index
* ">"  : lhs component is greater than rhs component if lhs component index is greater than rhs component index
* "<=" : lhs component is less or equal to rhs component if lhs component index is less than or equal to rhs component index
* ">=" : lhs component is greater than or equal to rhs component if lhs component index is greater than or equal to rhs component index

```cpp
std::vector<mpc::core::TensorRank2Component<double> > vec_componentXX{
    component00,
    component01,
    component02,
    component10,
    component11,
    component12,
    component20,
    component21,
    component22
};

for (auto componentXX : vec_componentXX) {
    std::cout << componentXX << " == " << component11 << " : " << (componentXX == component11) << std::endl;
    std::cout << componentXX << " != " << component11 << " : " << (componentXX != component11) << std::endl;
    std::cout << componentXX << " <  " << component11 << " : " << (componentXX < component11) << std::endl;
    std::cout << componentXX << " >  " << component11 << " : " << (componentXX > component11) << std::endl;
    std::cout << componentXX << " <= " << component11 << " : " << (componentXX <= component11) << std::endl;
    std::cout << componentXX << " >= " << component11 << " : " << (componentXX >= component11) << std::endl;
}
```
Output

    11.000000,[0,0] == 22.000000,[1,1] : false
    11.000000,[0,0] != 22.000000,[1,1] : true
    11.000000,[0,0] <  22.000000,[1,1] : true
    11.000000,[0,0] >  22.000000,[1,1] : false
    11.000000,[0,0] <= 22.000000,[1,1] : true
    11.000000,[0,0] >= 22.000000,[1,1] : false
    12.000000,[0,1] == 22.000000,[1,1] : false
    12.000000,[0,1] != 22.000000,[1,1] : true
    12.000000,[0,1] <  22.000000,[1,1] : true
    12.000000,[0,1] >  22.000000,[1,1] : false
    12.000000,[0,1] <= 22.000000,[1,1] : true
    12.000000,[0,1] >= 22.000000,[1,1] : false
    13.000000,[0,2] == 22.000000,[1,1] : false
    13.000000,[0,2] != 22.000000,[1,1] : true
    13.000000,[0,2] <  22.000000,[1,1] : true
    13.000000,[0,2] >  22.000000,[1,1] : false
    13.000000,[0,2] <= 22.000000,[1,1] : true
    13.000000,[0,2] >= 22.000000,[1,1] : false
    21.000000,[1,0] == 22.000000,[1,1] : false
    21.000000,[1,0] != 22.000000,[1,1] : true
    21.000000,[1,0] <  22.000000,[1,1] : true
    21.000000,[1,0] >  22.000000,[1,1] : false
    21.000000,[1,0] <= 22.000000,[1,1] : true
    21.000000,[1,0] >= 22.000000,[1,1] : false
    22.000000,[1,1] == 22.000000,[1,1] : true
    22.000000,[1,1] != 22.000000,[1,1] : false
    22.000000,[1,1] <  22.000000,[1,1] : false
    22.000000,[1,1] >  22.000000,[1,1] : false
    22.000000,[1,1] <= 22.000000,[1,1] : true
    22.000000,[1,1] >= 22.000000,[1,1] : true
    23.000000,[1,2] == 22.000000,[1,1] : false
    23.000000,[1,2] != 22.000000,[1,1] : true
    23.000000,[1,2] <  22.000000,[1,1] : false
    23.000000,[1,2] >  22.000000,[1,1] : true
    23.000000,[1,2] <= 22.000000,[1,1] : false
    23.000000,[1,2] >= 22.000000,[1,1] : true
    31.000000,[2,0] == 22.000000,[1,1] : false
    31.000000,[2,0] != 22.000000,[1,1] : true
    31.000000,[2,0] <  22.000000,[1,1] : false
    31.000000,[2,0] >  22.000000,[1,1] : true
    31.000000,[2,0] <= 22.000000,[1,1] : false
    31.000000,[2,0] >= 22.000000,[1,1] : true
    32.000000,[2,1] == 22.000000,[1,1] : false
    32.000000,[2,1] != 22.000000,[1,1] : true
    32.000000,[2,1] <  22.000000,[1,1] : false
    32.000000,[2,1] >  22.000000,[1,1] : true
    32.000000,[2,1] <= 22.000000,[1,1] : false
    32.000000,[2,1] >= 22.000000,[1,1] : true
    33.000000,[2,2] == 22.000000,[1,1] : false
    33.000000,[2,2] != 22.000000,[1,1] : true
    33.000000,[2,2] <  22.000000,[1,1] : false
    33.000000,[2,2] >  22.000000,[1,1] : true
    33.000000,[2,2] <= 22.000000,[1,1] : false
    33.000000,[2,2] >= 22.000000,[1,1] : true

TensorComponent comparison operators < and> use the index member variable, not the value. Therefore, we can store <code>TensorRank2Component</code>s in a <code>std::set<T></code> and be guaranteed uniqueness.

```cpp
std::set<mpc::core::TensorRankNComponent<double,2> > rank2_component_set {};
rank2_component_set.insert(component00);
rank2_component_set.insert(component01);
rank2_component_set.insert(component02);
rank2_component_set.insert(component10);
rank2_component_set.insert(component11);
rank2_component_set.insert(component12);
rank2_component_set.insert(component20);
rank2_component_set.insert(component21);
rank2_component_set.insert(component22);
std::cout << "rank2_component_set.size() : " << rank2_component_set.size() << std::endl; // will not insert because index already exitsts
rank2_component_set.insert(mpc::core::TensorRank2Component<double>(99.0, mpc::core::TensorRank2ComponentIndex(0,0)));
std::cout << "rank2_component_set.size() after attempt to insert duplicate index : " << rank2_component_set.size() << std::endl;
```
Output

    rank2_component_set.size() : 9
    rank2_component_set.size() after attempt to insert duplicate index : 9

Tensors of rank 4:

[mpcexamples::mpcTensorRank4Component()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_tensorrank4component.cpp)

One example of creating a blitz multidimensional array as a fourth rank tensor in 3D Cartesian space:

```cpp
mpc::core::TensorRank4Component<double> component0000 = mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0));
mpc::core::TensorRank4Component<double> component0001 = mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1));
mpc::core::TensorRank4Component<double> component0002 = mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2));
mpc::core::TensorRank4Component<double> component0010 = mpc::core::TensorRank4Component<double>(1121.0, mpc::core::TensorRank4ComponentIndex(0,0,1,0));
mpc::core::TensorRank4Component<double> component0011 = mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1));
mpc::core::TensorRank4Component<double> component0012 = mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2));
mpc::core::TensorRank4Component<double> component0020 = mpc::core::TensorRank4Component<double>(1131.0, mpc::core::TensorRank4ComponentIndex(0,0,2,0));
mpc::core::TensorRank4Component<double> component0021 = mpc::core::TensorRank4Component<double>(1132.0, mpc::core::TensorRank4ComponentIndex(0,0,2,1));
mpc::core::TensorRank4Component<double> component0022 = mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2));
mpc::core::TensorRank4Component<double> component0100 = mpc::core::TensorRank4Component<double>(1211.0, mpc::core::TensorRank4ComponentIndex(0,1,0,0));
mpc::core::TensorRank4Component<double> component0101 = mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1));
mpc::core::TensorRank4Component<double> component0102 = mpc::core::TensorRank4Component<double>(1213.0, mpc::core::TensorRank4ComponentIndex(0,1,0,2));
mpc::core::TensorRank4Component<double> component0110 = mpc::core::TensorRank4Component<double>(1221.0, mpc::core::TensorRank4ComponentIndex(0,1,1,0));
mpc::core::TensorRank4Component<double> component0111 = mpc::core::TensorRank4Component<double>(1222.0, mpc::core::TensorRank4ComponentIndex(0,1,1,1));
mpc::core::TensorRank4Component<double> component0112 = mpc::core::TensorRank4Component<double>(1223.0, mpc::core::TensorRank4ComponentIndex(0,1,1,2));
mpc::core::TensorRank4Component<double> component0120 = mpc::core::TensorRank4Component<double>(1231.0, mpc::core::TensorRank4ComponentIndex(0,1,2,0));
mpc::core::TensorRank4Component<double> component0121 = mpc::core::TensorRank4Component<double>(1232.0, mpc::core::TensorRank4ComponentIndex(0,1,2,1));
mpc::core::TensorRank4Component<double> component0122 = mpc::core::TensorRank4Component<double>(1233.0, mpc::core::TensorRank4ComponentIndex(0,1,2,2));
mpc::core::TensorRank4Component<double> component0200 = mpc::core::TensorRank4Component<double>(1311.0, mpc::core::TensorRank4ComponentIndex(0,2,0,0));
mpc::core::TensorRank4Component<double> component0201 = mpc::core::TensorRank4Component<double>(1312.0, mpc::core::TensorRank4ComponentIndex(0,2,0,1));
mpc::core::TensorRank4Component<double> component0202 = mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2));
mpc::core::TensorRank4Component<double> component0210 = mpc::core::TensorRank4Component<double>(1321.0, mpc::core::TensorRank4ComponentIndex(0,2,1,0));
mpc::core::TensorRank4Component<double> component0211 = mpc::core::TensorRank4Component<double>(1322.0, mpc::core::TensorRank4ComponentIndex(0,2,1,1));
mpc::core::TensorRank4Component<double> component0212 = mpc::core::TensorRank4Component<double>(1323.0, mpc::core::TensorRank4ComponentIndex(0,2,1,2));
mpc::core::TensorRank4Component<double> component0220 = mpc::core::TensorRank4Component<double>(1331.0, mpc::core::TensorRank4ComponentIndex(0,2,2,0));
mpc::core::TensorRank4Component<double> component0221 = mpc::core::TensorRank4Component<double>(1332.0, mpc::core::TensorRank4ComponentIndex(0,2,2,1));
mpc::core::TensorRank4Component<double> component0222 = mpc::core::TensorRank4Component<double>(1333.0, mpc::core::TensorRank4ComponentIndex(0,2,2,2));
mpc::core::TensorRank4Component<double> component1000 = mpc::core::TensorRank4Component<double>(2111.0, mpc::core::TensorRank4ComponentIndex(1,0,0,0));
mpc::core::TensorRank4Component<double> component1001 = mpc::core::TensorRank4Component<double>(2112.0, mpc::core::TensorRank4ComponentIndex(1,0,0,1));
mpc::core::TensorRank4Component<double> component1002 = mpc::core::TensorRank4Component<double>(2113.0, mpc::core::TensorRank4ComponentIndex(1,0,0,2));
mpc::core::TensorRank4Component<double> component1010 = mpc::core::TensorRank4Component<double>(2121.0, mpc::core::TensorRank4ComponentIndex(1,0,1,0));
mpc::core::TensorRank4Component<double> component1011 = mpc::core::TensorRank4Component<double>(2122.0, mpc::core::TensorRank4ComponentIndex(1,0,1,1));
mpc::core::TensorRank4Component<double> component1012 = mpc::core::TensorRank4Component<double>(2123.0, mpc::core::TensorRank4ComponentIndex(1,0,1,2));
mpc::core::TensorRank4Component<double> component1020 = mpc::core::TensorRank4Component<double>(2131.0, mpc::core::TensorRank4ComponentIndex(1,0,2,0));
mpc::core::TensorRank4Component<double> component1021 = mpc::core::TensorRank4Component<double>(2132.0, mpc::core::TensorRank4ComponentIndex(1,0,2,1));
mpc::core::TensorRank4Component<double> component1022 = mpc::core::TensorRank4Component<double>(2133.0, mpc::core::TensorRank4ComponentIndex(1,0,2,2));
mpc::core::TensorRank4Component<double> component1100 = mpc::core::TensorRank4Component<double>(2211.0, mpc::core::TensorRank4ComponentIndex(1,1,0,0));
mpc::core::TensorRank4Component<double> component1101 = mpc::core::TensorRank4Component<double>(2212.0, mpc::core::TensorRank4ComponentIndex(1,1,0,1));
mpc::core::TensorRank4Component<double> component1102 = mpc::core::TensorRank4Component<double>(2213.0, mpc::core::TensorRank4ComponentIndex(1,1,0,2));
mpc::core::TensorRank4Component<double> component1110 = mpc::core::TensorRank4Component<double>(2221.0, mpc::core::TensorRank4ComponentIndex(1,1,1,0));
mpc::core::TensorRank4Component<double> component1111 = mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1));
mpc::core::TensorRank4Component<double> component1112 = mpc::core::TensorRank4Component<double>(2223.0, mpc::core::TensorRank4ComponentIndex(1,1,1,2));
mpc::core::TensorRank4Component<double> component1120 = mpc::core::TensorRank4Component<double>(2231.0, mpc::core::TensorRank4ComponentIndex(1,1,2,0));
mpc::core::TensorRank4Component<double> component1121 = mpc::core::TensorRank4Component<double>(2232.0, mpc::core::TensorRank4ComponentIndex(1,1,2,1));
mpc::core::TensorRank4Component<double> component1122 = mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2));
mpc::core::TensorRank4Component<double> component1200 = mpc::core::TensorRank4Component<double>(2311.0, mpc::core::TensorRank4ComponentIndex(1,2,0,0));
mpc::core::TensorRank4Component<double> component1201 = mpc::core::TensorRank4Component<double>(2312.0, mpc::core::TensorRank4ComponentIndex(1,2,0,1));
mpc::core::TensorRank4Component<double> component1202 = mpc::core::TensorRank4Component<double>(2313.0, mpc::core::TensorRank4ComponentIndex(1,2,0,2));
mpc::core::TensorRank4Component<double> component1210 = mpc::core::TensorRank4Component<double>(2321.0, mpc::core::TensorRank4ComponentIndex(1,2,1,0));
mpc::core::TensorRank4Component<double> component1211 = mpc::core::TensorRank4Component<double>(2322.0, mpc::core::TensorRank4ComponentIndex(1,2,1,1));
mpc::core::TensorRank4Component<double> component1212 = mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2));
mpc::core::TensorRank4Component<double> component1220 = mpc::core::TensorRank4Component<double>(2331.0, mpc::core::TensorRank4ComponentIndex(1,2,2,0));
mpc::core::TensorRank4Component<double> component1221 = mpc::core::TensorRank4Component<double>(2332.0, mpc::core::TensorRank4ComponentIndex(1,2,2,1));
mpc::core::TensorRank4Component<double> component1222 = mpc::core::TensorRank4Component<double>(2333.0, mpc::core::TensorRank4ComponentIndex(1,2,2,2));
mpc::core::TensorRank4Component<double> component2000 = mpc::core::TensorRank4Component<double>(3111.0, mpc::core::TensorRank4ComponentIndex(2,0,0,0));
mpc::core::TensorRank4Component<double> component2001 = mpc::core::TensorRank4Component<double>(3112.0, mpc::core::TensorRank4ComponentIndex(2,0,0,1));
mpc::core::TensorRank4Component<double> component2002 = mpc::core::TensorRank4Component<double>(3113.0, mpc::core::TensorRank4ComponentIndex(2,0,0,2));
mpc::core::TensorRank4Component<double> component2010 = mpc::core::TensorRank4Component<double>(3121.0, mpc::core::TensorRank4ComponentIndex(2,0,1,0));
mpc::core::TensorRank4Component<double> component2011 = mpc::core::TensorRank4Component<double>(3122.0, mpc::core::TensorRank4ComponentIndex(2,0,1,1));
mpc::core::TensorRank4Component<double> component2012 = mpc::core::TensorRank4Component<double>(3123.0, mpc::core::TensorRank4ComponentIndex(2,0,1,2));
mpc::core::TensorRank4Component<double> component2020 = mpc::core::TensorRank4Component<double>(3131.0, mpc::core::TensorRank4ComponentIndex(2,0,2,0));
mpc::core::TensorRank4Component<double> component2021 = mpc::core::TensorRank4Component<double>(3132.0, mpc::core::TensorRank4ComponentIndex(2,0,2,1));
mpc::core::TensorRank4Component<double> component2022 = mpc::core::TensorRank4Component<double>(3133.0, mpc::core::TensorRank4ComponentIndex(2,0,2,2));
mpc::core::TensorRank4Component<double> component2100 = mpc::core::TensorRank4Component<double>(3211.0, mpc::core::TensorRank4ComponentIndex(2,1,0,0));
mpc::core::TensorRank4Component<double> component2101 = mpc::core::TensorRank4Component<double>(3212.0, mpc::core::TensorRank4ComponentIndex(2,1,0,1));
mpc::core::TensorRank4Component<double> component2102 = mpc::core::TensorRank4Component<double>(3213.0, mpc::core::TensorRank4ComponentIndex(2,1,0,2));
mpc::core::TensorRank4Component<double> component2110 = mpc::core::TensorRank4Component<double>(3221.0, mpc::core::TensorRank4ComponentIndex(2,1,1,0));
mpc::core::TensorRank4Component<double> component2111 = mpc::core::TensorRank4Component<double>(3222.0, mpc::core::TensorRank4ComponentIndex(2,1,1,1));
mpc::core::TensorRank4Component<double> component2112 = mpc::core::TensorRank4Component<double>(3223.0, mpc::core::TensorRank4ComponentIndex(2,1,1,2));
mpc::core::TensorRank4Component<double> component2120 = mpc::core::TensorRank4Component<double>(3231.0, mpc::core::TensorRank4ComponentIndex(2,1,2,0));
mpc::core::TensorRank4Component<double> component2121 = mpc::core::TensorRank4Component<double>(3232.0, mpc::core::TensorRank4ComponentIndex(2,1,2,1));
mpc::core::TensorRank4Component<double> component2122 = mpc::core::TensorRank4Component<double>(3233.0, mpc::core::TensorRank4ComponentIndex(2,1,2,2));
mpc::core::TensorRank4Component<double> component2200 = mpc::core::TensorRank4Component<double>(3311.0, mpc::core::TensorRank4ComponentIndex(2,2,0,0));
mpc::core::TensorRank4Component<double> component2201 = mpc::core::TensorRank4Component<double>(3312.0, mpc::core::TensorRank4ComponentIndex(2,2,0,1));
mpc::core::TensorRank4Component<double> component2202 = mpc::core::TensorRank4Component<double>(3313.0, mpc::core::TensorRank4ComponentIndex(2,2,0,2));
mpc::core::TensorRank4Component<double> component2210 = mpc::core::TensorRank4Component<double>(3321.0, mpc::core::TensorRank4ComponentIndex(2,2,1,0));
mpc::core::TensorRank4Component<double> component2211 = mpc::core::TensorRank4Component<double>(3322.0, mpc::core::TensorRank4ComponentIndex(2,2,1,1));
mpc::core::TensorRank4Component<double> component2212 = mpc::core::TensorRank4Component<double>(3323.0, mpc::core::TensorRank4ComponentIndex(2,2,1,2));
mpc::core::TensorRank4Component<double> component2220 = mpc::core::TensorRank4Component<double>(3331.0, mpc::core::TensorRank4ComponentIndex(2,2,2,0));
mpc::core::TensorRank4Component<double> component2221 = mpc::core::TensorRank4Component<double>(3332.0, mpc::core::TensorRank4ComponentIndex(2,2,2,1));
mpc::core::TensorRank4Component<double> component2222 = mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2));

const int ND3 = 3;
// 3-dimensional space
const int RANK4 = 4;
blitz::Array<float,RANK4> tensor4_in_3d = blitz::Array<float,RANK4>(ND3, ND3, ND3, ND3, blitz::ColumnMajorArray<4>());
int counter = 0;
for (int i=0; i<ND3; ++i) {
        for (int j=0; j<ND3; ++j) {
                for (int k=0; k<ND3; ++k) {
                        for (int l=0; l<ND3; ++l) {
                                tensor4_in_3d(i,j,k,l) = mpc::core::TensorRank4Component<float>(counter, mpc::core::TensorRank4ComponentIndex(i,j,k,l)).Value();
                                ++counter;
                         }
                }
        }
}
```
Output

    component0000 : 1111.000000,[0,0,0,0]
    component0001 : 1112.000000,[0,0,0,1]
    component0002 : 1113.000000,[0,0,0,2]
    component0010 : 1121.000000,[0,0,1,0]
    component0011 : 1122.000000,[0,0,1,1]
    component0012 : 1123.000000,[0,0,1,2]
    component0020 : 1131.000000,[0,0,2,0]
    component0021 : 1132.000000,[0,0,2,1]
    component0022 : 1133.000000,[0,0,2,2]
    component0100 : 1211.000000,[0,1,0,0]
    component0101 : 1212.000000,[0,1,0,1]
    component0102 : 1213.000000,[0,1,0,2]
    component0110 : 1221.000000,[0,1,1,0]
    component0111 : 1222.000000,[0,1,1,1]
    component0112 : 1223.000000,[0,1,1,2]
    component0120 : 1231.000000,[0,1,2,0]
    component0121 : 1232.000000,[0,1,2,1]
    component0122 : 1233.000000,[0,1,2,2]
    component0200 : 1311.000000,[0,2,0,0]
    component0201 : 1312.000000,[0,2,0,1]
    component0202 : 1313.000000,[0,2,0,2]
    component0210 : 1321.000000,[0,2,1,0]
    component0211 : 1322.000000,[0,2,1,1]
    component0212 : 1323.000000,[0,2,1,2]
    component0220 : 1331.000000,[0,2,2,0]
    component0221 : 1332.000000,[0,2,2,1]
    component0222 : 1333.000000,[0,2,2,2]
    component1000 : 2111.000000,[1,0,0,0]
    component1001 : 2112.000000,[1,0,0,1]
    component1002 : 2113.000000,[1,0,0,2]
    component1010 : 2121.000000,[1,0,1,0]
    component1011 : 2122.000000,[1,0,1,1]
    component1012 : 2123.000000,[1,0,1,2]
    component1020 : 2131.000000,[1,0,2,0]
    component1021 : 2132.000000,[1,0,2,1]
    component1022 : 2133.000000,[1,0,2,2]
    component1100 : 2211.000000,[1,1,0,0]
    component1101 : 2212.000000,[1,1,0,1]
    component1102 : 2213.000000,[1,1,0,2]
    component1110 : 2221.000000,[1,1,1,0]
    component1111 : 2222.000000,[1,1,1,1]
    component1112 : 2223.000000,[1,1,1,2]
    component1120 : 2231.000000,[1,1,2,0]
    component1121 : 2232.000000,[1,1,2,1]
    component1122 : 2233.000000,[1,1,2,2]
    component1200 : 2311.000000,[1,2,0,0]
    component1201 : 2312.000000,[1,2,0,1]
    component1202 : 2313.000000,[1,2,0,2]
    component1210 : 2321.000000,[1,2,1,0]
    component1211 : 2322.000000,[1,2,1,1]
    component1212 : 2323.000000,[1,2,1,2]
    component1220 : 2331.000000,[1,2,2,0]
    component1221 : 2332.000000,[1,2,2,1]
    component1222 : 2333.000000,[1,2,2,2]
    component2000 : 3111.000000,[2,0,0,0]
    component2001 : 3112.000000,[2,0,0,1]
    component2002 : 3113.000000,[2,0,0,2]
    component2010 : 3121.000000,[2,0,1,0]
    component2011 : 3122.000000,[2,0,1,1]
    component2012 : 3123.000000,[2,0,1,2]
    component2020 : 3131.000000,[2,0,2,0]
    component2021 : 3132.000000,[2,0,2,1]
    component2022 : 3133.000000,[2,0,2,2]
    component2100 : 3211.000000,[2,1,0,0]
    component2101 : 3212.000000,[2,1,0,1]
    component2102 : 3213.000000,[2,1,0,2]
    component2110 : 3221.000000,[2,1,1,0]
    component2111 : 3222.000000,[2,1,1,1]
    component2112 : 3223.000000,[2,1,1,2]
    component2120 : 3231.000000,[2,1,2,0]
    component2121 : 3232.000000,[2,1,2,1]
    component2122 : 3233.000000,[2,1,2,2]
    component2200 : 3311.000000,[2,2,0,0]
    component2201 : 3312.000000,[2,2,0,1]
    component2202 : 3313.000000,[2,2,0,2]
    component2210 : 3321.000000,[2,2,1,0]
    component2211 : 3322.000000,[2,2,1,1]
    component2212 : 3323.000000,[2,2,1,2]
    component2220 : 3331.000000,[2,2,2,0]
    component2221 : 3332.000000,[2,2,2,1]
    component2222 : 3333.000000,[2,2,2,2]

#### Stress and Strain tensors
> to be completed ...

#### Symmetry

Now, for symmerty, specifically symmetry of 4th rank tensors corresponding to:
> c(i,j,k,l) = c(j,i,k,l) = c(i,j,l,k) = c(l,k,i,j)            

that is, triclinic symmetry. Additional symmetry groups are specializations of triclinic symmetry.

SymmetryGroupEnumeration and corresponding SymmetryGroupType class
* NONE             >> NoneSymmetryGroupType
* TRICLINIC        >> TriclinciSymmetryGroupType
* MONOCLINIC_X2    >> MonoclinicX2SymmetryGroupType
* MONOCLINIC_X3    >> MonoclinicX3SymmetryGroupType
* ORTHORHOMBIC     >> OrthorhombicSymemtryGroupType
* HEXAGONAL        >> HexagonalSymmetryType
* TETRAGONAL7      >> Tetragonal7SymmetryType
* TETRAGONAL6      >> Tetragonal6SymmetryType
* TRIGONAL7        >> Trigonal7SymmetryType
* TRIGONAL6        >> Trigonal6SymmetryType
* CUBIC            >> CubicSymmetryType
* ISOTROPIC        >> IsotropicSymmetryType

Each symmetry type is a subclass of <code>SymmetryGroupBase</code> and has (currently) two data members:
* SymmetryGroupEnumeration symmetry_group_enumeration
* int number_of_independent_components

[mpcexamples::mpcSymmetryTypes()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_symmetrytypes.cpp)
```cpp
mpc::core::NoneSymmetryGroupType none_symmetry_type = mpc::core::NoneSymmetryGroupType();
std::cout << "NoneSymmetryGroupType symmetry : " << none_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "NoneSymmetryGroupType number of independent components : " << none_symmetry_type.number_of_independent_components << std::endl;
mpc::core::TriclinicSymmetryGroupType triclinic_symmetry_type=mpc::core::TriclinicSymmetryGroupType();
std::cout << "TriclinicSymmetryGroupType symmetry : " << triclinic_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "TriclinicSymmetryGroupType number of independent components : " << triclinic_symmetry_type.number_of_independent_components << std::endl;
mpc::core::MonoclinicX2SymmetryGroupType monoclinicX2_symmetry_type=mpc::core::MonoclinicX2SymmetryGroupType();
std::cout << "MonoclinicX2SymmetryGroupType symmetry : " << monoclinicX2_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "MonoclinicX2SymmetryGroupType number of independent components : " << monoclinicX2_symmetry_type.number_of_independent_components << std::endl;
mpc::core::MonoclinicX3SymmetryGroupType monoclinicX3_symmetry_type=mpc::core::MonoclinicX3SymmetryGroupType();
std::cout << "MonoclinicX3SymmetryGroupType symmetry : " << monoclinicX3_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "MonoclinicX3SymmetryGroupType number of independent components : " << monoclinicX3_symmetry_type.number_of_independent_components << std::endl;
mpc::core::OrthorhombicSymmetryGroupType orthorhombic_symmetry_type=mpc::core::OrthorhombicSymmetryGroupType();
std::cout << "OrthorhombicSymmetryGroupType symmetry : " << orthorhombic_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "OrthorhombicSymmetryGroupType number of independent components : " << orthorhombic_symmetry_type.number_of_independent_components << std::endl;
mpc::core::HexagonalSymmetryGroupType hexagonal_symmetry_type=mpc::core::HexagonalSymmetryGroupType();
std::cout << "HexagonalSymmetryGroupType symmetry : " << hexagonal_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "HexagonalSymmetryGroupType number of independent components : " << hexagonal_symmetry_type.number_of_independent_components << std::endl;
mpc::core::Tetragonal7SymmetryGroupType tetragonal7_symmetry_type=mpc::core::Tetragonal7SymmetryGroupType();
std::cout << "Tetragonal7SymmetryGroupType symmetry : " << tetragonal7_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "Tetragonal7SymmetryGroupType number of independent components : " << tetragonal7_symmetry_type.number_of_independent_components << std::endl;
mpc::core::Tetragonal6SymmetryGroupType tetragonal6_symmetry_type=mpc::core::Tetragonal6SymmetryGroupType();
std::cout << "Tetragonal6SymmetryGroupType symmetry : " << tetragonal6_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "Tetragonal6SymmetryGroupType number of independent components : " << tetragonal6_symmetry_type.number_of_independent_components << std::endl;
mpc::core::Trigonal7SymmetryGroupType trigonal7_symmetry_type=mpc::core::Trigonal7SymmetryGroupType();
std::cout << "Trigonal7SymmetryGroupType symmetry : " << trigonal7_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "Trigonal7SymmetryGroupType number of independent components : " << trigonal7_symmetry_type.number_of_independent_components << std::endl;
mpc::core::Trigonal6SymmetryGroupType trigonal6_symmetry_type=mpc::core::Trigonal6SymmetryGroupType();
std::cout << "Trigonal6SymmetryGroupType symmetry : " << trigonal6_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "Trigonal6SymmetryGroupType number of independent components : " << trigonal6_symmetry_type.number_of_independent_components << std::endl;
mpc::core::CubicSymmetryGroupType cubic_symmetry_type=mpc::core::CubicSymmetryGroupType();
std::cout << "CubicSymmetryGroupType symmetry : " << cubic_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "CubicSymmetryGroupType number of independent components : " << cubic_symmetry_type.number_of_independent_components << std::endl;
mpc::core::IsotropicSymmetryGroupType isotropic_symmetry_type=mpc::core::IsotropicSymmetryGroupType();
std::cout << "IsotropicSymmetryGroupType symmetry : " << isotropic_symmetry_type.symmetry_group_enumeration << std::endl;
std::cout << "IsotropicSymmetryGroupType number of independent components : " << isotropic_symmetry_type.number_of_independent_components << std::endl;
```
Output

    NoneSymmetryGroupType symmetry : none
    NoneSymmetryGroupType number of independent components : 81
    TriclinicSymmetryGroupType symmetry : triclinic
    TriclinicSymmetryGroupType number of independent components : 21
    MonoclinicX2SymmetryGroupType symmetry : monoclinic_x2
    MonoclinicX2SymmetryGroupType number of independent components : 13
    MonoclinicX3SymmetryGroupType symmetry : monoclinic_x3
    MonoclinicX3SymmetryGroupType number of independent components : 13
    OrthorhombicSymmetryGroupType symmetry : orthorhombic
    OrthorhombicSymmetryGroupType number of independent components : 9
    HexagonalSymmetryGroupType symmetry : hexagonal
    HexagonalSymmetryGroupType number of independent components : 5
    Tetragonal7SymmetryGroupType symmetry : tetragonal_7
    Tetragonal7SymmetryGroupType number of independent components : 7
    Tetragonal6SymmetryGroupType symmetry : tetragonal_6
    Tetragonal6SymmetryGroupType number of independent components : 6
    Trigonal7SymmetryGroupType symmetry : trigonal_7
    Trigonal7SymmetryGroupType number of independent components : 7
    Trigonal6SymmetryGroupType symmetry : trigonal_6
    Trigonal6SymmetryGroupType number of independent components : 6
    CubicSymmetryGroupType symmetry : cubic
    CubicSymmetryGroupType number of independent components : 3
    IsotropicSymmetryGroupType symmetry : isotropic
    IsotropicSymmetryGroupType number of independent components : 2

Symmetry type predicates... Type predicates or type traits are boolean functions on types [ref]...

Note that these predicates are convenience functions derived from the more general:

```cpp
template <typename S, int N>
constexpr inline bool SymmetryGroupTypeHasNIndependentComponents();
```

For example

```cpp
// has 21 components
std::cout << "NoneSymmetryGroupType has 21 independent components ?         "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
std::cout << "TriclinicSymmetryGroupType has 21 independent components ?    "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX3SymmetryGroupType has 21 independent components ? "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX2SymmetryGroupType has 21 independent components ? "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
std::cout << "OrthorhombicSymmetryGroupType has 21 independent components ? "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
std::cout << "HexagonalSymmetryGroupType has 21 independent components ?    "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
std::cout << "Tetragonal7SymmetryGroupType has 21 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
std::cout << "Tetragonal6SymmetryGroupType has 21 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
std::cout << "Trigonal7SymmetryGroupType has 21 independent components ?    "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
std::cout << "Trigonal6SymmetryGroupType has 21 independent components ?    "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
std::cout << "CubicSymmetryGroupType has 21 independent components ?        "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
std::cout << "IsotropicSymmetryGroupType has 21 independent components ?    "
          << mpc::core::SymmetryGroupTypeHas21IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

// has 13 components
std::cout << "" << std::endl;
std::cout << "NoneSymmetryGroupType has 13 independent components ?         "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
std::cout << "TriclinicSymmetryGroupType has 13 independent components ?    "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX3SymmetryGroupType has 13 independent components ? "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX2SymmetryGroupType has 13 independent components ? "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
std::cout << "OrthorhombicSymmetryGroupType has 13 independent components ? "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
std::cout << "HexagonalSymmetryGroupType has 13 independent components ?    "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
std::cout << "Tetragonal7SymmetryGroupType has 13 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
std::cout << "Tetragonal6SymmetryGroupType has 13 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
std::cout << "Trigonal7SymmetryGroupType has 13 independent components ?    "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
std::cout << "Trigonal6SymmetryGroupType has 13 independent components ?    "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
std::cout << "CubicSymmetryGroupType has 13 independent components ?        "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
std::cout << "IsotropicSymmetryGroupType has 13 independent components ?    "
          << mpc::core::SymmetryGroupTypeHas13IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

// has 9 components
std::cout << "" << std::endl;
std::cout << "NoneSymmetryGroupType has 9 independent components ?          "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
std::cout << "TriclinicSymmetryGroupType has 9 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX3SymmetryGroupType has 9 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX2SymmetryGroupType has 9 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
std::cout << "OrthorhombicSymmetryGroupType has 9 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
std::cout << "HexagonalSymmetryGroupType has 9 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
std::cout << "Tetragonal7SymmetryGroupType has 9 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
std::cout << "Tetragonal6SymmetryGroupType has 9 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
std::cout << "Trigonal7SymmetryGroupType has 9 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
std::cout << "Trigonal6SymmetryGroupType has 9 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
std::cout << "CubicSymmetryGroupType has 9 independent components ?         "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
std::cout << "IsotropicSymmetryGroupType has 9 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas9IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

// has 7 components
std::cout << "" << std::endl;
std::cout << "NoneSymmetryGroupType has 7 independent components ?          "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
std::cout << "TriclinicSymmetryGroupType has 7 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX3SymmetryGroupType has 7 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX2SymmetryGroupType has 7 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
std::cout << "OrthorhombicSymmetryGroupType has 7 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
std::cout << "HexagonalSymmetryGroupType has 7 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
std::cout << "Tetragonal7SymmetryGroupType has 7 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
std::cout << "Tetragonal6SymmetryGroupType has 7 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
std::cout << "Trigonal7SymmetryGroupType has 7 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
std::cout << "Trigonal6SymmetryGroupType has 7 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
std::cout << "CubicSymmetryGroupType has 7 independent components ?         "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
std::cout << "IsotropicSymmetryGroupType has 7 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas7IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

// has 6 components
std::cout << "" << std::endl;
std::cout << "NoneSymmetryGroupType has 6 independent components ?          "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
std::cout << "TriclinicSymmetryGroupType has 6 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX3SymmetryGroupType has 6 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX2SymmetryGroupType has 6 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
std::cout << "OrthorhombicSymmetryGroupType has 6 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
std::cout << "HexagonalSymmetryGroupType has 6 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
std::cout << "Tetragonal7SymmetryGroupType has 6 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
std::cout << "Tetragonal6SymmetryGroupType has 6 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
std::cout << "Trigonal7SymmetryGroupType has 6 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
std::cout << "Trigonal6SymmetryGroupType has 6 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
std::cout << "CubicSymmetryGroupType has 6 independent components ?         "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
std::cout << "IsotropicSymmetryGroupType has 6 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas6IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

// has 5 components
std::cout << "" << std::endl;
std::cout << "NoneSymmetryGroupType has 5 independent components ?          "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
std::cout << "TriclinicSymmetryGroupType has 5 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX3SymmetryGroupType has 5 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX2SymmetryGroupType has 5 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>()<< std::endl;
std::cout << "OrthorhombicSymmetryGroupType has 5 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
std::cout << "HexagonalSymmetryGroupType has 5 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::HexagonalSymmetryGroupType>()<< std::endl;
std::cout << "Tetragonal7SymmetryGroupType has 5 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
std::cout << "Tetragonal6SymmetryGroupType has 5 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
std::cout << "Trigonal7SymmetryGroupType has 5 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
std::cout << "Trigonal6SymmetryGroupType has 5 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
std::cout << "CubicSymmetryGroupType has 5 independent components ?         "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
std::cout << "IsotropicSymmetryGroupType has 5 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas5IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

// has 3 components
std::cout << "" << std::endl;
std::cout << "NoneSymmetryGroupType has 3 independent components ?          "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
std::cout << "TriclinicSymmetryGroupType has 3 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX3SymmetryGroupType has 3 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX2SymmetryGroupType has 3 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
std::cout << "OrthorhombicSymmetryGroupType has 3 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
std::cout << "HexagonalSymmetryGroupType has 3 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
std::cout << "Tetragonal7SymmetryGroupType has 3 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
std::cout << "Tetragonal6SymmetryGroupType has 3 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
std::cout << "Trigonal7SymmetryGroupType has 3 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
std::cout << "Trigonal6SymmetryGroupType has 3 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
std::cout << "CubicSymmetryGroupType has 3 independent components ?         "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
std::cout << "IsotropicSymmetryGroupType has 3 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas3IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;

// has 2 components
std::cout << "" << std::endl;
std::cout << "NoneSymmetryGroupType has 2 independent components ?          "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::NoneSymmetryGroupType>() << std::endl;
std::cout << "TriclinicSymmetryGroupType has 2 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::TriclinicSymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX3SymmetryGroupType has 2 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::MonoclinicX3SymmetryGroupType>() << std::endl;
std::cout << "MonoclinicX2SymmetryGroupType has 2 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::MonoclinicX2SymmetryGroupType>() << std::endl;
std::cout << "OrthorhombicSymmetryGroupType has 2 independent components ?  "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::OrthorhombicSymmetryGroupType>() << std::endl;
std::cout << "HexagonalSymmetryGroupType has 2 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::HexagonalSymmetryGroupType>() << std::endl;
std::cout << "Tetragonal7SymmetryGroupType has 2 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::Tetragonal7SymmetryGroupType>() << std::endl;
std::cout << "Tetragonal6SymmetryGroupType has 2 independent components ?   "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::Tetragonal6SymmetryGroupType>() << std::endl;
std::cout << "Trigonal7SymmetryGroupType has 2 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::Trigonal7SymmetryGroupType>() << std::endl;
std::cout << "Trigonal6SymmetryGroupType has 2 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::Trigonal6SymmetryGroupType>() << std::endl;
std::cout << "CubicSymmetryGroupType has 2 independent components ?         "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::CubicSymmetryGroupType>() << std::endl;
std::cout << "IsotropicSymmetryGroupType has 2 independent components ?     "
          << mpc::core::SymmetryGroupTypeHas2IndependentComponents<mpc::core::IsotropicSymmetryGroupType>() << std::endl;
```
Output

    NoneSymmetryGroupType has 21 independent components ?         false
    TriclinicSymmetryGroupType has 21 independent components ?    true
    MonoclinicX3SymmetryGroupType has 21 independent components ? false
    MonoclinicX2SymmetryGroupType has 21 independent components ? false
    OrthorhombicSymmetryGroupType has 21 independent components ? false
    HexagonalSymmetryGroupType has 21 independent components ?    false
    Tetragonal7SymmetryGroupType has 21 independent components ?  false
    Tetragonal6SymmetryGroupType has 21 independent components ?  false
    Trigonal7SymmetryGroupType has 21 independent components ?    false
    Trigonal6SymmetryGroupType has 21 independent components ?    false
    CubicSymmetryGroupType has 21 independent components ?        false
    IsotropicSymmetryGroupType has 21 independent components ?    false

    NoneSymmetryGroupType has 13 independent components ?         false
    TriclinicSymmetryGroupType has 13 independent components ?    false
    MonoclinicX3SymmetryGroupType has 13 independent components ? true
    MonoclinicX2SymmetryGroupType has 13 independent components ? true
    OrthorhombicSymmetryGroupType has 13 independent components ? false
    HexagonalSymmetryGroupType has 13 independent components ?    false
    Tetragonal7SymmetryGroupType has 13 independent components ?  false
    Tetragonal6SymmetryGroupType has 13 independent components ?  false
    Trigonal7SymmetryGroupType has 13 independent components ?    false
    Trigonal6SymmetryGroupType has 13 independent components ?    false
    CubicSymmetryGroupType has 13 independent components ?        false
    IsotropicSymmetryGroupType has 13 independent components ?    false

    NoneSymmetryGroupType has 9 independent components ?          false
    TriclinicSymmetryGroupType has 9 independent components ?     false
    MonoclinicX3SymmetryGroupType has 9 independent components ?  false
    MonoclinicX2SymmetryGroupType has 9 independent components ?  false
    OrthorhombicSymmetryGroupType has 9 independent components ?  true
    HexagonalSymmetryGroupType has 9 independent components ?     false
    Tetragonal7SymmetryGroupType has 9 independent components ?   false
    Tetragonal6SymmetryGroupType has 9 independent components ?   false
    Trigonal7SymmetryGroupType has 9 independent components ?     false
    Trigonal6SymmetryGroupType has 9 independent components ?     false
    CubicSymmetryGroupType has 9 independent components ?         false
    IsotropicSymmetryGroupType has 9 independent components ?     false

    NoneSymmetryGroupType has 7 independent components ?          false
    TriclinicSymmetryGroupType has 7 independent components ?     false
    MonoclinicX3SymmetryGroupType has 7 independent components ?  false
    MonoclinicX2SymmetryGroupType has 7 independent components ?  false
    OrthorhombicSymmetryGroupType has 7 independent components ?  false
    HexagonalSymmetryGroupType has 7 independent components ?     false
    Tetragonal7SymmetryGroupType has 7 independent components ?   true
    Tetragonal6SymmetryGroupType has 7 independent components ?   false
    Trigonal7SymmetryGroupType has 7 independent components ?     true
    Trigonal6SymmetryGroupType has 7 independent components ?     false
    CubicSymmetryGroupType has 7 independent components ?         false
    IsotropicSymmetryGroupType has 7 independent components ?     false

    NoneSymmetryGroupType has 6 independent components ?          false
    TriclinicSymmetryGroupType has 6 independent components ?     false
    MonoclinicX3SymmetryGroupType has 6 independent components ?  false
    MonoclinicX2SymmetryGroupType has 6 independent components ?  false
    OrthorhombicSymmetryGroupType has 6 independent components ?  false
    HexagonalSymmetryGroupType has 6 independent components ?     false
    Tetragonal7SymmetryGroupType has 6 independent components ?   false
    Tetragonal6SymmetryGroupType has 6 independent components ?   true
    Trigonal7SymmetryGroupType has 6 independent components ?     false
    Trigonal6SymmetryGroupType has 6 independent components ?     true
    CubicSymmetryGroupType has 6 independent components ?         false
    IsotropicSymmetryGroupType has 6 independent components ?     false

    NoneSymmetryGroupType has 5 independent components ?          false
    TriclinicSymmetryGroupType has 5 independent components ?     false
    MonoclinicX3SymmetryGroupType has 5 independent components ?  false
    MonoclinicX2SymmetryGroupType has 5 independent components ?  false
    OrthorhombicSymmetryGroupType has 5 independent components ?  false
    HexagonalSymmetryGroupType has 5 independent components ?     true
    Tetragonal7SymmetryGroupType has 5 independent components ?   false
    Tetragonal6SymmetryGroupType has 5 independent components ?   false
    Trigonal7SymmetryGroupType has 5 independent components ?     false
    Trigonal6SymmetryGroupType has 5 independent components ?     false
    CubicSymmetryGroupType has 5 independent components ?         false
    IsotropicSymmetryGroupType has 5 independent components ?     false

    NoneSymmetryGroupType has 3 independent components ?          false
    TriclinicSymmetryGroupType has 3 independent components ?     false
    MonoclinicX3SymmetryGroupType has 3 independent components ?  false
    MonoclinicX2SymmetryGroupType has 3 independent components ?  false
    OrthorhombicSymmetryGroupType has 3 independent components ?  false
    HexagonalSymmetryGroupType has 3 independent components ?     false
    Tetragonal7SymmetryGroupType has 3 independent components ?   false
    Tetragonal6SymmetryGroupType has 3 independent components ?   false
    Trigonal7SymmetryGroupType has 3 independent components ?     false
    Trigonal6SymmetryGroupType has 3 independent components ?     false
    CubicSymmetryGroupType has 3 independent components ?         true
    IsotropicSymmetryGroupType has 3 independent components ?     false

    NoneSymmetryGroupType has 2 independent components ?          false
    TriclinicSymmetryGroupType has 2 independent components ?     false
    MonoclinicX3SymmetryGroupType has 2 independent components ?  false
    MonoclinicX2SymmetryGroupType has 2 independent components ?  false
    OrthorhombicSymmetryGroupType has 2 independent components ?  false
    HexagonalSymmetryGroupType has 2 independent components ?     false
    Tetragonal7SymmetryGroupType has 2 independent components ?   false
    Tetragonal6SymmetryGroupType has 2 independent components ?   false
    Trigonal7SymmetryGroupType has 2 independent components ?     false
    Trigonal6SymmetryGroupType has 2 independent components ?     false
    CubicSymmetryGroupType has 2 independent components ?         false
    IsotropicSymmetryGroupType has 2 independent components ?     true

It is also possible to call the above predicate function using the SymmetryGroupType using alias

    SymmetryGroupTypeHas21IndependentComponents<typename SymmetryGroupType<mpc::core::SymmetryGroupEnumeration::TRICLINIC>::type>()

MPC provides another predicate funciton for the SymmetryGroupEnumeration does exactly that:

    template<mpc::core::SymmetryGroupEnumeration Sym>
    constexpr inline bool SymmetryGroupEnumerationHas21IndependentComponents() {
        return SymmetryGroupTypeHas21IndependentComponents<typename SymmetryGroupType<Sym>::type>();
    }

For example,
```cpp
// 21 components
std::cout << "" << std::endl;
std::cout << "SymmetryGroupEnumeration::NONE has 21 independent components ?         "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRICLINIC has 21 independent components ?    "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 21 independent components ? "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 21 independent components ? "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 21 independent components ? "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 21 independent components ?    "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 21 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 21 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 21 independent components ?    "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 21 independent components ?    "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::CUBIC has 21 independent components ?        "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 21 independent components ?    "
          << mpc::core::SymmetryGroupEnumerationHas21IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

// 13 components
std::cout << "" << std::endl;
std::cout << "SymmetryGroupEnumeration::NONE has 13 independent components ?         "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRICLINIC has 13 independent components ?    "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 13 independent components ? "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 13 independent components ? "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 13 independent components ? "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 13 independent components ?    "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 13 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 13 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 13 independent components ?    "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 13 independent components ?    "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::CUBIC has 13 independent components ?        "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 13 independent components ?    "
          << mpc::core::SymmetryGroupEnumerationHas13IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

// 9 components
std::cout << "" << std::endl;
std::cout << "SymmetryGroupEnumeration::NONE has 9 independent components ?          "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRICLINIC has 9 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 9 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 9 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 9 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 9 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 9 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 9 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 9 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 9 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::CUBIC has 9 independent components ?         "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 9 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas9IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

// 7 components
std::cout << "" << std::endl;
std::cout << "SymmetryGroupEnumeration::NONE has 7 independent components ?          "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRICLINIC has 7 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 7 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 7 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 7 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 7 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 7 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 7 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 7 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 7 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::CUBIC has 7 independent components ?         "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 7 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas7IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

// 6 components
std::cout << "" << std::endl;
std::cout << "SymmetryGroupEnumeration::NONE has 6 independent components ?          "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRICLINIC has 6 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 6 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 6 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 6 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 6 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 6 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 6 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 6 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 6 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::CUBIC has 6 independent components ?         "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 6 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas6IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

// 5 components
std::cout << "" << std::endl;
std::cout << "SymmetryGroupEnumeration::NONE has 5 independent components ?          "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRICLINIC has 5 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 5 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 5 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 5 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 5 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 5 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 5 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 5 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 5 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::CUBIC has 5 independent components ?         "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 5 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas5IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

// 3 components
std::cout << "" << std::endl;
std::cout << "SymmetryGroupEnumeration::NONE has 3 independent components ?          "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRICLINIC has 3 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 3 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 3 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 3 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 3 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 3 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 3 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 3 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 3 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::CUBIC has 3 independent components ?         "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 3 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas3IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;

// 2 components
std::cout << "" << std::endl;
std::cout << "SymmetryGroupEnumeration::NONE has 2 independent components ?          "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::NONE>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRICLINIC has 2 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRICLINIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX3 has 2 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X3>() << std::endl;
std::cout << "SymmetryGroupEnumeration::MONOCLINICX2 has 2 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::MONOCLINIC_X2>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ORTHORHOMBIC has 2 independent components ?  "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::ORTHORHOMBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::HEXAGONAL has 2 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::HEXAGONAL>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL7 has 2 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TETRAGONAL6 has 2 independent components ?   "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::TETRAGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL7 has 2 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL7>() << std::endl;
std::cout << "SymmetryGroupEnumeration::TRIGONAL6 has 2 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::TRIGONAL6>() << std::endl;
std::cout << "SymmetryGroupEnumeration::CUBIC has 2 independent components ?         "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::CUBIC>() << std::endl;
std::cout << "SymmetryGroupEnumeration::ISOTROPIC has 2 independent components ?     "
          << mpc::core::SymmetryGroupEnumerationHas2IndependentComponents<mpc::core::SymmetryGroupEnumeration::ISOTROPIC>() << std::endl;
```
Output

    SymmetryGroupEnumeration::NONE has 21 independent components ?         false
    SymmetryGroupEnumeration::TRICLINIC has 21 independent components ?    true
    SymmetryGroupEnumeration::MONOCLINICX3 has 21 independent components ? false
    SymmetryGroupEnumeration::MONOCLINICX2 has 21 independent components ? false
    SymmetryGroupEnumeration::ORTHORHOMBIC has 21 independent components ? false
    SymmetryGroupEnumeration::HEXAGONAL has 21 independent components ?    false
    SymmetryGroupEnumeration::TETRAGONAL7 has 21 independent components ?  false
    SymmetryGroupEnumeration::TETRAGONAL6 has 21 independent components ?  false
    SymmetryGroupEnumeration::TRIGONAL7 has 21 independent components ?    false
    SymmetryGroupEnumeration::TRIGONAL6 has 21 independent components ?    false
    SymmetryGroupEnumeration::CUBIC has 21 independent components ?        false
    SymmetryGroupEnumeration::ISOTROPIC has 21 independent components ?    false

    SymmetryGroupEnumeration::NONE has 13 independent components ?         false
    SymmetryGroupEnumeration::TRICLINIC has 13 independent components ?    false
    SymmetryGroupEnumeration::MONOCLINICX3 has 13 independent components ? true
    SymmetryGroupEnumeration::MONOCLINICX2 has 13 independent components ? true
    SymmetryGroupEnumeration::ORTHORHOMBIC has 13 independent components ? false
    SymmetryGroupEnumeration::HEXAGONAL has 13 independent components ?    false
    SymmetryGroupEnumeration::TETRAGONAL7 has 13 independent components ?  false
    SymmetryGroupEnumeration::TETRAGONAL6 has 13 independent components ?  false
    SymmetryGroupEnumeration::TRIGONAL7 has 13 independent components ?    false
    SymmetryGroupEnumeration::TRIGONAL6 has 13 independent components ?    false
    SymmetryGroupEnumeration::CUBIC has 13 independent components ?        false
    SymmetryGroupEnumeration::ISOTROPIC has 13 independent components ?    false

    SymmetryGroupEnumeration::NONE has 9 independent components ?          false
    SymmetryGroupEnumeration::TRICLINIC has 9 independent components ?     false
    SymmetryGroupEnumeration::MONOCLINICX3 has 9 independent components ?  false
    SymmetryGroupEnumeration::MONOCLINICX2 has 9 independent components ?  false
    SymmetryGroupEnumeration::ORTHORHOMBIC has 9 independent components ?  true
    SymmetryGroupEnumeration::HEXAGONAL has 9 independent components ?     false
    SymmetryGroupEnumeration::TETRAGONAL7 has 9 independent components ?   false
    SymmetryGroupEnumeration::TETRAGONAL6 has 9 independent components ?   false
    SymmetryGroupEnumeration::TRIGONAL7 has 9 independent components ?     false
    SymmetryGroupEnumeration::TRIGONAL6 has 9 independent components ?     false
    SymmetryGroupEnumeration::CUBIC has 9 independent components ?         false
    SymmetryGroupEnumeration::ISOTROPIC has 9 independent components ?     false

    SymmetryGroupEnumeration::NONE has 7 independent components ?          false
    SymmetryGroupEnumeration::TRICLINIC has 7 independent components ?     false
    SymmetryGroupEnumeration::MONOCLINICX3 has 7 independent components ?  false
    SymmetryGroupEnumeration::MONOCLINICX2 has 7 independent components ?  false
    SymmetryGroupEnumeration::ORTHORHOMBIC has 7 independent components ?  false
    SymmetryGroupEnumeration::HEXAGONAL has 7 independent components ?     false
    SymmetryGroupEnumeration::TETRAGONAL7 has 7 independent components ?   true
    SymmetryGroupEnumeration::TETRAGONAL6 has 7 independent components ?   false
    SymmetryGroupEnumeration::TRIGONAL7 has 7 independent components ?     true
    SymmetryGroupEnumeration::TRIGONAL6 has 7 independent components ?     false
    SymmetryGroupEnumeration::CUBIC has 7 independent components ?         false
    SymmetryGroupEnumeration::ISOTROPIC has 7 independent components ?     false

    SymmetryGroupEnumeration::NONE has 6 independent components ?          false
    SymmetryGroupEnumeration::TRICLINIC has 6 independent components ?     false
    SymmetryGroupEnumeration::MONOCLINICX3 has 6 independent components ?  false
    SymmetryGroupEnumeration::MONOCLINICX2 has 6 independent components ?  false
    SymmetryGroupEnumeration::ORTHORHOMBIC has 6 independent components ?  false
    SymmetryGroupEnumeration::HEXAGONAL has 6 independent components ?     false
    SymmetryGroupEnumeration::TETRAGONAL7 has 6 independent components ?   false
    SymmetryGroupEnumeration::TETRAGONAL6 has 6 independent components ?   true
    SymmetryGroupEnumeration::TRIGONAL7 has 6 independent components ?     false
    SymmetryGroupEnumeration::TRIGONAL6 has 6 independent components ?     true
    SymmetryGroupEnumeration::CUBIC has 6 independent components ?         false
    SymmetryGroupEnumeration::ISOTROPIC has 6 independent components ?     false

    SymmetryGroupEnumeration::NONE has 5 independent components ?          false
    SymmetryGroupEnumeration::TRICLINIC has 5 independent components ?     false
    SymmetryGroupEnumeration::MONOCLINICX3 has 5 independent components ?  false
    SymmetryGroupEnumeration::MONOCLINICX2 has 5 independent components ?  false
    SymmetryGroupEnumeration::ORTHORHOMBIC has 5 independent components ?  false
    SymmetryGroupEnumeration::HEXAGONAL has 5 independent components ?     true
    SymmetryGroupEnumeration::TETRAGONAL7 has 5 independent components ?   false
    SymmetryGroupEnumeration::TETRAGONAL6 has 5 independent components ?   false
    SymmetryGroupEnumeration::TRIGONAL7 has 5 independent components ?     false
    SymmetryGroupEnumeration::TRIGONAL6 has 5 independent components ?     false
    SymmetryGroupEnumeration::CUBIC has 5 independent components ?         false
    SymmetryGroupEnumeration::ISOTROPIC has 5 independent components ?     false

    SymmetryGroupEnumeration::NONE has 3 independent components ?          false
    SymmetryGroupEnumeration::TRICLINIC has 3 independent components ?     false
    SymmetryGroupEnumeration::MONOCLINICX3 has 3 independent components ?  false
    SymmetryGroupEnumeration::MONOCLINICX2 has 3 independent components ?  false
    SymmetryGroupEnumeration::ORTHORHOMBIC has 3 independent components ?  false
    SymmetryGroupEnumeration::HEXAGONAL has 3 independent components ?     false
    SymmetryGroupEnumeration::TETRAGONAL7 has 3 independent components ?   false
    SymmetryGroupEnumeration::TETRAGONAL6 has 3 independent components ?   false
    SymmetryGroupEnumeration::TRIGONAL7 has 3 independent components ?     false
    SymmetryGroupEnumeration::TRIGONAL6 has 3 independent components ?     false
    SymmetryGroupEnumeration::CUBIC has 3 independent components ?         true
    SymmetryGroupEnumeration::ISOTROPIC has 3 independent components ?     false

    SymmetryGroupEnumeration::NONE has 2 independent components ?          false
    SymmetryGroupEnumeration::TRICLINIC has 2 independent components ?     false
    SymmetryGroupEnumeration::MONOCLINICX3 has 2 independent components ?  false
    SymmetryGroupEnumeration::MONOCLINICX2 has 2 independent components ?  false
    SymmetryGroupEnumeration::ORTHORHOMBIC has 2 independent components ?  false
    SymmetryGroupEnumeration::HEXAGONAL has 2 independent components ?     false
    SymmetryGroupEnumeration::TETRAGONAL7 has 2 independent components ?   false
    SymmetryGroupEnumeration::TETRAGONAL6 has 2 independent components ?   false
    SymmetryGroupEnumeration::TRIGONAL7 has 2 independent components ?     false
    SymmetryGroupEnumeration::TRIGONAL6 has 2 independent components ?     false
    SymmetryGroupEnumeration::CUBIC has 2 independent components ?         false
    SymmetryGroupEnumeration::ISOTROPIC has 2 independent components ?     true

Below are function predicates that take a <code>std::set< TensorRank4Component<T> ></code> as an argument...

    NOTE: component0011 and compoent1100 are aliases of each other if the
    symmetry of the stiffness or compliance tensor is not ::NONE.  That
    is to say, if the tensor has symmetry, triclinic or otherwise, these
    two components should be equivalent in value.  If they are not, the
    tensor symmetry will be of NoneSymmetryGroupType.

>since std::set<> uses operators < and >, and TensorRank4Component overloads those operators by comparing index only, attempting to insert two TensorRank4Components into the same set will not work.  The second one will fail because it has the same index regardless of the value.  This important fact gaurantees uniqueness among a set of components.

ISOTROPIC
```cpp
bool is_symmetry_aliased_set_symmetry_compliant = false;

// let's create some sets that we can use to test the predicates...
// ISOTROPIC
/*
 *  | 00  01  01  --  --  -- |
 *  | 01  00  01  --  --  -- |
 *  | 01  01  00  --  --  -- |
 *  | --  --  --  XX  --  -- |
 *  | --  --  --  --  XX  -- |
 *  | --  --  --  --  --  XX |
 *
 * For C, XX = 0.5 * [C(0,0) - C(0,1)]
 * For S, XX =   2 * [S(0,0) - S(0,1)]
 */

std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
};

std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_02{
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
};

std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_03{
    mpc::core::TensorRank4Component<double>(20.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(100.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(40.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
}; // NOTE: For C, XX = 0.5 * [C(0,0) - C(0,1)]; satisfies cubic as well

std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_04{
    mpc::core::TensorRank4Component<double>(20.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(100.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(160.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
}; // NOTE: For S, XX =   2 * [S(0,0) - S(0,1)]; satisfies cubic as well

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_00);
std::cout << "is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_01);
std::cout << "is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_02);
std::cout << "is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_03);
std::cout << "is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_04);
std::cout << "is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_04);
std::cout << "is isotropic symmetry aliased index set isotropic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;
```
Output

    is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? true

    is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? true

    is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? true

    is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? true

    is isotropic symmetry aliased index set isotropic symmetry [stiffness] compliant ? false

    is isotropic symmetry aliased index set isotropic symmetry [compliance] compliant ? true

    is isotropic symmetry aliased index set cubic symmetry [stiffness] compliant ? true

    is isotropic symmetry aliased index set cubic symmetry [compliance] compliant ? true

CUBIC    
```cpp
// CUBIC
/*
 *  | 00  01  01  --  --  -- |
 *  | 01  00  01  --  --  -- |
 *  | 01  01  00  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | --  --  --  --  --  33 |
 */

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::CubicSymmetryGroupType>(isotropic_symmetry_aliased_set_03);
std::cout << "is isotropic symmetry aliased index set cubic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::CubicSymmetryGroupType>(isotropic_symmetry_aliased_set_03);
std::cout << "is isotropic symmetry aliased index set cubic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)) // X33 >> (1212), (1221), (2112), (2121)
};

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00);
std::cout << "is cubic symmetry aliased index set cubic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00);
std::cout << "is cubic symmetry aliased index set cubic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_01);
std::cout << "is cubic symmetry aliased index set cubic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_01);
std::cout << "is cubic symmetry aliased index set cubic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::IsotropicSymmetryGroupType>(cubic_symmetry_aliased_set_01);
std::cout << "is cubic symmetry aliased index set isotropic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::IsotropicSymmetryGroupType>(cubic_symmetry_aliased_set_00);
std::cout << "is cubic symmetry aliased index set isotropic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;
```
Output

    is cubic symmetry aliased index set cubic symmetry [stiffness] compliant ? true

    is cubic symmetry aliased index set cubic symmetry [compliance] compliant ? true

    is cubic symmetry aliased index set cubic symmetry [stiffness] compliant ? true

    is cubic symmetry aliased index set cubic symmetry [compliance] compliant ? true

    is cubic symmetry aliased index set isotropic symmetry [stiffness] compliant ? false

    is cubic symmetry aliased index set isotropic symmetry [compliance] compliant ? false

TRIGONAL6    
```cpp
//  TRIGONAL6
/*
 *  | 00  01  02  03  --  -- |
 *  | 01  00  02 -03  --  -- |
 *  | 02  02  22  --  --  -- |
 *  | 03 -03  --  33  --  -- |
 *  | --  --  --  --  33 *03 |
 *  | --  --  --  -- *03  XX |
 *
 * For C, XX = 0.5 * [C(0,0) - C(0,1)]
 * For S, XX =   2 * [S(0,0) - S(0,1)]
 */

std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
};

std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_02{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_00);
std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_01);
std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_02);
std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_00);
std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_01);
std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_02);
std::cout << "is trigonal6 symmetry aliased index set trigonal6 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;
```
Output

    is trigonal6 symmetry aliased index set trigonal6 symmetry [stiffness] compliant ? true

    is trigonal6 symmetry aliased index set trigonal6 symmetry [stiffness] compliant ? true

    is trigonal6 symmetry aliased index set trigonal6 symmetry [stiffness] compliant ? false

    is trigonal6 symmetry aliased index set trigonal6 symmetry [compliance] compliant ? true

    is trigonal6 symmetry aliased index set trigonal6 symmetry [compliance] compliant ? false

    is trigonal6 symmetry aliased index set trigonal6 symmetry [compliance] compliant ? true

```cpp
// TRIGONAL7
/*
 *  | 00  01  02  03 -04  -- |
 *  | 01  00  02 -03  04  -- |
 *  | 02  02  22  --  --  -- |
 *  | 03 -03  --  33  -- *04 |
 *  | 04  14  --  --  33 *03 |
 *  | --  --  -- *04 *03  XX |
 *
 * where *NN is the numerical equal for C and twice the numerical equal for S; and
 * For C, XX = 0.5 * [C(0,0) - C(0,1)]
 * For S, XX =   2 * [S(0,0) - S(0,1)]
 *
 */

std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
};

std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_02{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_00);
std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_01);
std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_02);
std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_00);
std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_01);
std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_02);
std::cout << "is trigonal7 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

// NOTE: REMEMBER, trigonal6 is a specialization of trigonal7; the additional 04 component in trigonal7 could be zero valued and thus would be symmetry compliant, but
//     not the least symmetry.  You must test for trigonal6 before testing for trigonal7
is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_00);
std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_01);
std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_02);
std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_00);
std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_01);
std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Trigonal7SymmetryGroupType>(trigonal6_symmetry_aliased_set_02);
std::cout << "is trigonal6 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;
```
Output

    is trigonal7 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? true

    is trigonal7 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? true

    is trigonal7 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? false

    is trigonal7 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? true

    is trigonal7 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? false

    is trigonal7 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? true

    is trigonal6 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? true

    is trigonal6 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? true

    is trigonal6 symmetry aliased index set trigonal7 symmetry [stiffness] compliant ? true

    is trigonal6 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? true

    is trigonal6 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? true

    is trigonal6 symmetry aliased index set trigonal7 symmetry [compliance] compliant ? true

TETRAGONAL6
```cpp
// TETRAGONAL6
/*
 *  | 00  01  02  --  --  -- |
 *  | 01  00  02  --  --  -- |
 *  | 02  02  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | --  --  --  --  --  55 |
 */
std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_00);
std::cout << "is tetragonal6 symmetry aliased index set tetragonal6 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_01);
std::cout << "is tetragonal6 symmetry aliased index set tetragonal6 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_00);
std::cout << "is tetragonal6 symmetry aliased index set tetragonal6 symmetry [complaince] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_01);
std::cout << "is tetragonal6 symmetry aliased index set tetragonal6 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;
```
Output

    is tetragonal6 symmetry aliased index set tetragonal6 symmetry [stiffness] compliant ? true

    is tetragonal6 symmetry aliased index set tetragonal6 symmetry [stiffness] compliant ? true

    is tetragonal6 symmetry aliased index set tetragonal6 symmetry [complaince] compliant ? true

    is tetragonal6 symmetry aliased index set tetragonal6 symmetry [compliance] compliant ? true

TETRAGONAL7    
```cpp
// TETRAGONAL7
/*
 *  | 00  01  02  --  --  05 |
 *  | 01  00  02  --  -- -05 |
 *  | 02  02  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | 05 -05  --  --  --  55 |
 */
std::set<mpc::core::TensorRank4Component<double> > tetragonal7_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::Tetragonal7SymmetryGroupType>(tetragonal7_symmetry_aliased_set_00);
std::cout << "is tetragonal7 symmetry aliased index set tetragonal7 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::Tetragonal7SymmetryGroupType>(tetragonal7_symmetry_aliased_set_00);
std::cout << "is tetragonal7 symmetry aliased index set tetragonal7 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;
```
Output

    is tetragonal7 symmetry aliased index set tetragonal7 symmetry [stiffness] compliant ? true

    is tetragonal7 symmetry aliased index set tetragonal7 symmetry [compliance] compliant ? true

HEXAGONAL
```cpp
// HEXAGONAL
/*
 *  | 00  01  02  --  --  -- |
 *  | 01  00  02  --  --  -- |
 *  | 02  02  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | --  --  --  --  --  XX |
 *
 * For C, XX = 0.5 * [C(0,0) - C(0,1)]
 * For S, XX =   2 * [S(0,0) - S(0,1)]
 */
std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
};

std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_02{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_00);
std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_01);
std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_02);
std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_00);
std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_01);
std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_02);
std::cout << "is hexagonal symmetry aliased index set hexagonal symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;
```
Output

    is hexagonal symmetry aliased index set hexagonal symmetry [stiffness] compliant ? true

    is hexagonal symmetry aliased index set hexagonal symmetry [stiffness] compliant ? true

    is hexagonal symmetry aliased index set hexagonal symmetry [stiffness] compliant ? false

    is hexagonal symmetry aliased index set hexagonal symmetry [compliance] compliant ? true

    is hexagonal symmetry aliased index set hexagonal symmetry [compliance] compliant ? false

    is hexagonal symmetry aliased index set hexagonal symmetry [compliance] compliant ? true

ORTHORHOMBIC
```cpp
// ORTHORHOMBIC
/*
 *  | 00  01  02  --  --  -- |
 *  | 01  11  12  --  --  -- |
 *  | 02  12  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  44  -- |
 *  | --  --  --  --  --  55 |
 */
std::set<mpc::core::TensorRank4Component<double> > orthorhombic_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::OrthorhombicSymmetryGroupType>(orthorhombic_symmetry_aliased_set_00);
std::cout << "is orthorhombic symmetry aliased index set orthorhombic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::OrthorhombicSymmetryGroupType>(orthorhombic_symmetry_aliased_set_00);
std::cout << "is orthorhombic symmetry aliased index set orthorhombic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

// NOTE: tetragonal6 is a specialization of orthorhombic with additional constraints, so these are true
is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::OrthorhombicSymmetryGroupType>(tetragonal6_symmetry_aliased_set_00);
std::cout << "is tetragonal6 symmetry aliased index set orthorhombic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::OrthorhombicSymmetryGroupType>(tetragonal6_symmetry_aliased_set_00);
std::cout << "is tetragonal6 symmetry aliased index set orthorhombic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;
```
Output

    is orthorhombic symmetry aliased index set orthorhombic symmetry [stiffness] compliant ? true

    is orthorhombic symmetry aliased index set orthorhombic symmetry [compliance] compliant ? true

    is tetragonal6 symmetry aliased index set orthorhombic symmetry [stiffness] compliant ? true

    is tetragonal6 symmetry aliased index set orthorhombic symmetry [compliance] compliant ? true

MONOCLINIC_X3
```cpp
// MONOCLINIC_X3
/*
 *  | 00  01  02  --  --  05 |
 *  | 01  11  12  --  --  15 |
 *  | 02  12  22  --  --  25 |
 *  | --  --  --  33  34  -- |
 *  | --  --  --  34  44  -- |
 *  | 05  15  25  --  --  55 |
 */
std::set<mpc::core::TensorRank4Component<double> > monoclinicx3_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
    mpc::core::TensorRank4Component<double>(2212.0, mpc::core::TensorRank4ComponentIndex(1,1,0,1)), // X15 >> (1101), (1110), (0111), (1011)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(3312.0, mpc::core::TensorRank4ComponentIndex(2,2,0,1)), // X25 >> (2201), (2210), (0122), (1022)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(2313.0, mpc::core::TensorRank4ComponentIndex(1,2,0,2)), // X34 >> (1202), (1220), (2102), (2120), (0212), (2012), (0221), (2021)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::MonoclinicX3SymmetryGroupType>(monoclinicx3_symmetry_aliased_set_00);
std::cout << "is monoclinicx3 symmetry aliased index set monoclinicx3 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::MonoclinicX3SymmetryGroupType>(monoclinicx3_symmetry_aliased_set_00);
std::cout << "is monoclinicx3 symmetry aliased index set monoclinicx3 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;
```
Output

    is monoclinicx3 symmetry aliased index set monoclinicx3 symmetry [stiffness] compliant ? true

    is monoclinicx3 symmetry aliased index set monoclinicx3 symmetry [compliance] compliant ? true

MONOCLINIC_X2
```cpp
// MONOCLINIC_X2
/*
 *  | 00  01  02  --  04  -- |
 *  | 01  11  12  --  14  -- |
 *  | 02  12  22  --  24  -- |
 *  | --  --  --  33  --  35 |
 *  | 04  14  24  --  44  -- |
 *  | --  --  --  35  --  55 |
 */
std::set<mpc::core::TensorRank4Component<double> > monoclinicx2_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
    mpc::core::TensorRank4Component<double>(2213.0, mpc::core::TensorRank4ComponentIndex(1,1,0,2)), // X14 >> (1102), (1120), (0211), (2011)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(3313.0, mpc::core::TensorRank4ComponentIndex(2,2,0,2)), // X24 >> (2202), (2220), (0222), (2022)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(2312.0, mpc::core::TensorRank4ComponentIndex(1,2,0,1)), // X35 >> (1201), (1210), (2101), (2110), (0112), (1012), (0121), (1021)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::MonoclinicX2SymmetryGroupType>(monoclinicx2_symmetry_aliased_set_00);
std::cout << "is monoclinicx2 symmetry aliased index set monoclinicx2 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::MonoclinicX2SymmetryGroupType>(monoclinicx2_symmetry_aliased_set_00);
std::cout << "is monoclinicx2 symmetry aliased index set monoclinicx2 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::MonoclinicX2SymmetryGroupType>(monoclinicx3_symmetry_aliased_set_00);
std::cout << "is monoclinicx3 symmetry aliased index set monoclinicx2 symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::MonoclinicX2SymmetryGroupType>(monoclinicx3_symmetry_aliased_set_00);
std::cout << "is monoclinicx3 symmetry aliased index set monoclinicx2 symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;
```
Output

    is monoclinicx2 symmetry aliased index set monoclinicx2 symmetry [stiffness] compliant ? true

    is monoclinicx2 symmetry aliased index set monoclinicx2 symmetry [compliance] compliant ? true

    is monoclinicx3 symmetry aliased index set monoclinicx2 symmetry [stiffness] compliant ? false

    is monoclinicx3 symmetry aliased index set monoclinicx2 symmetry [compliance] compliant ? false

TRICLINIC
```cpp
// TRICLINIC
/*
 *  | 00  01  02  03  04  05 |
 *  | 01  11  12  13  14  15 |
 *  | 02  12  22  23  24  25 |
 *  | 03  13  23  33  34  35 |
 *  | 04  14  24  34  44  45 |
 *  | 05  15  25  35  45  55 |
 */

std::set<mpc::core::TensorRank4Component<double> > triclinic_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
    mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
    mpc::core::TensorRank4Component<double>(2223.0, mpc::core::TensorRank4ComponentIndex(1,1,1,2)), // X13 >> (1112), (1121), (1211), (2111)
    mpc::core::TensorRank4Component<double>(2213.0, mpc::core::TensorRank4ComponentIndex(1,1,0,2)), // X14 >> (1102), (1120), (0211), (2011)
    mpc::core::TensorRank4Component<double>(2212.0, mpc::core::TensorRank4ComponentIndex(1,1,0,1)), // X15 >> (1101), (1110), (0111), (1011)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(3323.0, mpc::core::TensorRank4ComponentIndex(2,2,1,2)), // X23 >> (2212), (2221), (1222), (2122)
    mpc::core::TensorRank4Component<double>(3313.0, mpc::core::TensorRank4ComponentIndex(2,2,0,2)), // X24 >> (2202), (2220), (0222), (2022)
    mpc::core::TensorRank4Component<double>(3312.0, mpc::core::TensorRank4ComponentIndex(2,2,0,1)), // X25 >> (2201), (2210), (0122), (1022)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(2313.0, mpc::core::TensorRank4ComponentIndex(1,2,0,2)), // X34 >> (1202), (1220), (2102), (2120), (0212), (2012), (0221), (2021)
    mpc::core::TensorRank4Component<double>(2312.0, mpc::core::TensorRank4ComponentIndex(1,2,0,1)), // X35 >> (1201), (1210), (2101), (2110), (0112), (1012), (0121), (1021)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(1312.0, mpc::core::TensorRank4ComponentIndex(0,2,0,1)), // X45 >> (0201), (0210), (2001), (2010), (0102), (1002), (0120), (1020)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::StiffnessType,mpc::core::TriclinicSymmetryGroupType>(triclinic_symmetry_aliased_set_00);
std::cout << "is triclinic symmetry aliased index set triclinic symmetry [stiffness] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;

is_symmetry_aliased_set_symmetry_compliant = mpc::core::IsComponentSetSymmetryCompliant<double,mpc::core::ComplianceType,mpc::core::TriclinicSymmetryGroupType>(triclinic_symmetry_aliased_set_00);
std::cout << "is triclinic symmetry aliased index set triclinic symmetry [compliance] compliant ? " << is_symmetry_aliased_set_symmetry_compliant << std::endl;
std::cout << "" << std::endl;
```
Output

    is triclinic symmetry aliased index set triclinic symmetry [stiffness] compliant ? true

    is triclinic symmetry aliased index set triclinic symmetry [compliance] compliant ? true

SYMMETRY COMPONENTS : the TensorRank4SymmetryComponents template function modifies the input set and adds the missing components given the symmetry and the stiffness or compliance type; this template function is specialized for each symmetry, stiffness/compliance pair in a function object which is created at compile time...

> NOTE: there are no "links" in the triclinic symmetry group;  only the typical aliases when going from matrix notation to tensor notation

```cpp
/*  symmetry components   */
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::TriclinicSymmetryGroupType>(triclinic_symmetry_aliased_set_00);
for (auto comp : triclinic_symmetry_aliased_set_00) {
    std::cout << "triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
}

std::cout << "" << std::endl;
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::TriclinicSymmetryGroupType>(triclinic_symmetry_aliased_set_00);
for (auto comp : triclinic_symmetry_aliased_set_00) {
    std::cout << "triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(hexagonal_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_00_copy);
for (auto comp : hexagonal_symmetry_aliased_set_00_copy) {
    std::cout << "hexagonal_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(hexagonal_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_00_copy2);
for (auto comp : hexagonal_symmetry_aliased_set_00_copy2) {
    std::cout << "hexagonal_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(tetragonal6_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_00_copy);
for (auto comp : tetragonal6_symmetry_aliased_set_00_copy) {
    std::cout << "tetragonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
}
// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(tetragonal6_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_00_copy2);
for (auto comp : tetragonal6_symmetry_aliased_set_00_copy2) {
    std::cout << "tetragonal6_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > tetragonal7_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(tetragonal7_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::Tetragonal7SymmetryGroupType>(tetragonal7_symmetry_aliased_set_00_copy);
for (auto comp : tetragonal7_symmetry_aliased_set_00_copy) {
    std::cout << "tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > tetragonal7_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(tetragonal7_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::Tetragonal7SymmetryGroupType>(tetragonal7_symmetry_aliased_set_00_copy2);
for (auto comp : tetragonal7_symmetry_aliased_set_00_copy2) {
    std::cout << "tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(trigonal6_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_00_copy);
for (auto comp : trigonal6_symmetry_aliased_set_00_copy) {
    std::cout << "trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(trigonal6_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_00_copy2);
for (auto comp : trigonal6_symmetry_aliased_set_00_copy2) {
    std::cout << "trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(trigonal7_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_00_copy);
for (auto comp : trigonal7_symmetry_aliased_set_00_copy) {
    std::cout << "trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(trigonal7_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_00_copy2);
for (auto comp : trigonal7_symmetry_aliased_set_00_copy2) {
    std::cout << "trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
}


// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(cubic_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00_copy);
for (auto comp : cubic_symmetry_aliased_set_00_copy) {
    std::cout << "cubic_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(cubic_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00_copy2);
for (auto comp : cubic_symmetry_aliased_set_00_copy2) {
    std::cout << "cubic_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_00_copy = std::set<mpc::core::TensorRank4Component<double> >(isotropic_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_00_copy);
for (auto comp : isotropic_symmetry_aliased_set_00_copy) {
    std::cout << "isotropic_symmetry_aliased_set_00 after symmetry components [stiffness] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_00_copy2 = std::set<mpc::core::TensorRank4Component<double> >(isotropic_symmetry_aliased_set_00);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_00_copy2);
for (auto comp : isotropic_symmetry_aliased_set_00_copy2) {
    std::cout << "isotropic_symmetry_aliased_set_00 after symmetry components [compliance] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_01_copy = std::set<mpc::core::TensorRank4Component<double> >(isotropic_symmetry_aliased_set_01);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::StiffnessType, mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_01_copy);
for (auto comp : isotropic_symmetry_aliased_set_01_copy) {
    std::cout << "isotropic_symmetry_aliased_set_01 after symmetry components [stiffness] : " << comp << std::endl;
}

// NOTE: this function WILL modify the set by adding missing components!  Create a copy...
std::cout << "" << std::endl;
std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_01_copy2 = std::set<mpc::core::TensorRank4Component<double> >(isotropic_symmetry_aliased_set_01);
mpc::core::TensorRank4SymmetryComponents<double, mpc::core::ComplianceType, mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_01_copy2);
for (auto comp : isotropic_symmetry_aliased_set_01_copy2) {
    std::cout << "isotropic_symmetry_aliased_set_01 after symmetry components [compliance] : " << comp << std::endl;
}
```
Output

    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[0,0,0,0]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1112.000000,[0,0,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1113.000000,[0,0,0,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1122.000000,[0,0,1,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1123.000000,[0,0,1,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1133.000000,[0,0,2,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1212.000000,[0,1,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1312.000000,[0,2,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1313.000000,[0,2,0,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 2212.000000,[1,1,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 2213.000000,[1,1,0,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 2222.000000,[1,1,1,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 2223.000000,[1,1,1,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 2233.000000,[1,1,2,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 2312.000000,[1,2,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 2313.000000,[1,2,0,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[1,2,1,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 3312.000000,[2,2,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 3313.000000,[2,2,0,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 3323.000000,[2,2,1,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [stiffness] : 3333.000000,[2,2,2,2]

    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[0,0,0,0]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 1112.000000,[0,0,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 1113.000000,[0,0,0,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 1122.000000,[0,0,1,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 1123.000000,[0,0,1,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 1133.000000,[0,0,2,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 1212.000000,[0,1,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 1312.000000,[0,2,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 1313.000000,[0,2,0,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 2212.000000,[1,1,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 2213.000000,[1,1,0,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 2222.000000,[1,1,1,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 2223.000000,[1,1,1,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 2233.000000,[1,1,2,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 2312.000000,[1,2,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 2313.000000,[1,2,0,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[1,2,1,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 3312.000000,[2,2,0,1]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 3313.000000,[2,2,0,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 3323.000000,[2,2,1,2]
    triclinic_symmetry_aliased_set_00 after symmetry components [compliance] : 3333.000000,[2,2,2,2]

    hexagonal_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[0,0,0,0]
    hexagonal_symmetry_aliased_set_00 after symmetry components [stiffness] : 1122.000000,[0,0,1,1]
    hexagonal_symmetry_aliased_set_00 after symmetry components [stiffness] : 1133.000000,[0,0,2,2]
    hexagonal_symmetry_aliased_set_00 after symmetry components [stiffness] : -5.500000,[0,1,0,1]
    hexagonal_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[0,2,0,2]
    hexagonal_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[1,1,1,1]
    hexagonal_symmetry_aliased_set_00 after symmetry components [stiffness] : 1133.000000,[1,1,2,2]
    hexagonal_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[1,2,1,2]
    hexagonal_symmetry_aliased_set_00 after symmetry components [stiffness] : 3333.000000,[2,2,2,2]

    hexagonal_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[0,0,0,0]
    hexagonal_symmetry_aliased_set_00 after symmetry components [compliance] : 1122.000000,[0,0,1,1]
    hexagonal_symmetry_aliased_set_00 after symmetry components [compliance] : 1133.000000,[0,0,2,2]
    hexagonal_symmetry_aliased_set_00 after symmetry components [compliance] : -22.000000,[0,1,0,1]
    hexagonal_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[0,2,0,2]
    hexagonal_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[1,1,1,1]
    hexagonal_symmetry_aliased_set_00 after symmetry components [compliance] : 1133.000000,[1,1,2,2]
    hexagonal_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[1,2,1,2]
    hexagonal_symmetry_aliased_set_00 after symmetry components [compliance] : 3333.000000,[2,2,2,2]

    tetragonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[0,0,0,0]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1122.000000,[0,0,1,1]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1133.000000,[0,0,2,2]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1212.000000,[0,1,0,1]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[0,2,0,2]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[1,1,1,1]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1133.000000,[1,1,2,2]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[1,2,1,2]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 3333.000000,[2,2,2,2]

    tetragonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[0,0,0,0]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1122.000000,[0,0,1,1]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1133.000000,[0,0,2,2]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1212.000000,[0,1,0,1]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[0,2,0,2]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[1,1,1,1]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1133.000000,[1,1,2,2]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[1,2,1,2]
    tetragonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 3333.000000,[2,2,2,2]

    tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[0,0,0,0]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1112.000000,[0,0,0,1]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1122.000000,[0,0,1,1]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1133.000000,[0,0,2,2]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1212.000000,[0,1,0,1]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : -1112.000000,[0,1,1,1]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[0,2,0,2]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[1,1,1,1]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1133.000000,[1,1,2,2]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[1,2,1,2]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 3333.000000,[2,2,2,2]

    tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[0,0,0,0]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1112.000000,[0,0,0,1]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1122.000000,[0,0,1,1]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1133.000000,[0,0,2,2]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1212.000000,[0,1,0,1]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : -1112.000000,[0,1,1,1]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[0,2,0,2]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[1,1,1,1]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1133.000000,[1,1,2,2]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[1,2,1,2]
    tetragonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 3333.000000,[2,2,2,2]

    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[0,0,0,0]
    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1122.000000,[0,0,1,1]
    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1123.000000,[0,0,1,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1133.000000,[0,0,2,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : -5.500000,[0,1,0,1]
    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1123.000000,[0,1,0,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[0,2,0,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[1,1,1,1]
    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : -1123.000000,[1,1,1,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 1133.000000,[1,1,2,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[1,2,1,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [stiffness] : 3333.000000,[2,2,2,2]

    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[0,0,0,0]
    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1122.000000,[0,0,1,1]
    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1123.000000,[0,0,1,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1133.000000,[0,0,2,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : -5.500000,[0,1,0,1]
    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 2246.000000,[0,1,0,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[0,2,0,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[1,1,1,1]
    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : -1123.000000,[1,1,1,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 1133.000000,[1,1,2,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[1,2,1,2]
    trigonal6_symmetry_aliased_set_00 after symmetry components [compliance] : 3333.000000,[2,2,2,2]

    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[0,0,0,0]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1113.000000,[0,0,0,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1122.000000,[0,0,1,1]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1123.000000,[0,0,1,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1133.000000,[0,0,2,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : -5.500000,[0,1,0,1]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1123.000000,[0,1,0,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : -1113.000000,[0,1,1,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[0,2,0,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : -1113.000000,[0,2,1,1]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[1,1,1,1]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : -1123.000000,[1,1,1,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 1133.000000,[1,1,2,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[1,2,1,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [stiffness] : 3333.000000,[2,2,2,2]

    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[0,0,0,0]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1113.000000,[0,0,0,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1122.000000,[0,0,1,1]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1123.000000,[0,0,1,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1133.000000,[0,0,2,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : -5.500000,[0,1,0,1]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 2246.000000,[0,1,0,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : -2226.000000,[0,1,1,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[0,2,0,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : -1113.000000,[0,2,1,1]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[1,1,1,1]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : -1123.000000,[1,1,1,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 1133.000000,[1,1,2,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[1,2,1,2]
    trigonal7_symmetry_aliased_set_00 after symmetry components [compliance] : 3333.000000,[2,2,2,2]

    cubic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[0,0,0,0]
    cubic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1122.000000,[0,0,1,1]
    cubic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1122.000000,[0,0,2,2]
    cubic_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[0,1,0,1]
    cubic_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[0,2,0,2]
    cubic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[1,1,1,1]
    cubic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1122.000000,[1,1,2,2]
    cubic_symmetry_aliased_set_00 after symmetry components [stiffness] : 2323.000000,[1,2,1,2]
    cubic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[2,2,2,2]

    cubic_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[0,0,0,0]
    cubic_symmetry_aliased_set_00 after symmetry components [compliance] : 1122.000000,[0,0,1,1]
    cubic_symmetry_aliased_set_00 after symmetry components [compliance] : 1122.000000,[0,0,2,2]
    cubic_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[0,1,0,1]
    cubic_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[0,2,0,2]
    cubic_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[1,1,1,1]
    cubic_symmetry_aliased_set_00 after symmetry components [compliance] : 1122.000000,[1,1,2,2]
    cubic_symmetry_aliased_set_00 after symmetry components [compliance] : 2323.000000,[1,2,1,2]
    cubic_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[2,2,2,2]

    isotropic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[0,0,0,0]
    isotropic_symmetry_aliased_set_00 after symmetry components [stiffness] : -1313.000000,[0,0,1,1]
    isotropic_symmetry_aliased_set_00 after symmetry components [stiffness] : -1313.000000,[0,0,2,2]
    isotropic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1212.000000,[0,1,0,1]
    isotropic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1212.000000,[0,2,0,2]
    isotropic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[1,1,1,1]
    isotropic_symmetry_aliased_set_00 after symmetry components [stiffness] : -1313.000000,[1,1,2,2]
    isotropic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1212.000000,[1,2,1,2]
    isotropic_symmetry_aliased_set_00 after symmetry components [stiffness] : 1111.000000,[2,2,2,2]

    isotropic_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[0,0,0,0]
    isotropic_symmetry_aliased_set_00 after symmetry components [compliance] : 505.000000,[0,0,1,1]
    isotropic_symmetry_aliased_set_00 after symmetry components [compliance] : 505.000000,[0,0,2,2]
    isotropic_symmetry_aliased_set_00 after symmetry components [compliance] : 1212.000000,[0,1,0,1]
    isotropic_symmetry_aliased_set_00 after symmetry components [compliance] : 1212.000000,[0,2,0,2]
    isotropic_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[1,1,1,1]
    isotropic_symmetry_aliased_set_00 after symmetry components [compliance] : 505.000000,[1,1,2,2]
    isotropic_symmetry_aliased_set_00 after symmetry components [compliance] : 1212.000000,[1,2,1,2]
    isotropic_symmetry_aliased_set_00 after symmetry components [compliance] : 1111.000000,[2,2,2,2]

    isotropic_symmetry_aliased_set_01 after symmetry components [stiffness] : 1111.000000,[0,0,0,0]
    isotropic_symmetry_aliased_set_01 after symmetry components [stiffness] : 1122.000000,[0,0,1,1]
    isotropic_symmetry_aliased_set_01 after symmetry components [stiffness] : 1122.000000,[0,0,2,2]
    isotropic_symmetry_aliased_set_01 after symmetry components [stiffness] : -5.500000,[0,1,0,1]
    isotropic_symmetry_aliased_set_01 after symmetry components [stiffness] : -5.500000,[0,2,0,2]
    isotropic_symmetry_aliased_set_01 after symmetry components [stiffness] : 1111.000000,[1,1,1,1]
    isotropic_symmetry_aliased_set_01 after symmetry components [stiffness] : 1122.000000,[1,1,2,2]
    isotropic_symmetry_aliased_set_01 after symmetry components [stiffness] : -5.500000,[1,2,1,2]
    isotropic_symmetry_aliased_set_01 after symmetry components [stiffness] : 1111.000000,[2,2,2,2]

    isotropic_symmetry_aliased_set_01 after symmetry components [compliance] : 1111.000000,[0,0,0,0]
    isotropic_symmetry_aliased_set_01 after symmetry components [compliance] : 1122.000000,[0,0,1,1]
    isotropic_symmetry_aliased_set_01 after symmetry components [compliance] : 1122.000000,[0,0,2,2]
    isotropic_symmetry_aliased_set_01 after symmetry components [compliance] : -22.000000,[0,1,0,1]
    isotropic_symmetry_aliased_set_01 after symmetry components [compliance] : -22.000000,[0,2,0,2]
    isotropic_symmetry_aliased_set_01 after symmetry components [compliance] : 1111.000000,[1,1,1,1]
    isotropic_symmetry_aliased_set_01 after symmetry components [compliance] : 1122.000000,[1,1,2,2]
    isotropic_symmetry_aliased_set_01 after symmetry components [compliance] : -22.000000,[1,2,1,2]
    isotropic_symmetry_aliased_set_01 after symmetry components [compliance] : 1111.000000,[2,2,2,2]

#### stiffness, compliance, and the stiffness compliance relationship
SymmetryGroupEnumeration and corresponding SymmetryGroupType class
* NONE             >> NoneSymmetryGroupType
* TRICLINIC        >> TriclinciSymmetryGroupType
* MONOCLINIC_X2    >> MonoclinicX2SymmetryGroupType
* MONOCLINIC_X3    >> MonoclinicX3SymmetryGroupType
* ORTHORHOMBIC     >> OrthorhombicSymemtryGroupType
* VTI              >> VTISymmetryGroupType
* HTI              >> HTISymmetryGroupType
* HEXAGONAL        >> HexagonalSymmetryType
* TETRAGONAL7      >> Tetragonal7SymmetryType
* TETRAGONAL6      >> Tetragonal6SymmetryType
* TRIGONAL7        >> Trigonal7SymmetryType
* TRIGONAL6        >> Trigonal6SymmetryType
* CUBIC            >> CubicSymmetryType
* ISOTROPIC        >> IsotropicSymmetryType

Each symmetry type is a subclass of SymmetryGroupBase and has (currently) two data members:

    SymmetryGroupEnumeration symmetry_group_enumeration
    int number_of_independent_components

[mpcexamples::mpcStiffnessComplianceCSRelationship()](https://github.com/threecubed/mpc/blob/master/examples/mpcx_stiffnesscompliance_csrelationship.cpp)
```cpp
mpc::core::StiffnessTensor<double> stiffness_tensor;

// TRICLINIC
/*
 *  | 00  01  02  03  04  05 |
 *  | 01  11  12  13  14  15 |
 *  | 02  12  22  23  24  25 |
 *  | 03  13  23  33  34  35 |
 *  | 04  14  24  34  44  45 |
 *  | 05  15  25  35  45  55 |
 */

std::set<mpc::core::TensorRank4Component<double> > triclinic_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
    mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
    mpc::core::TensorRank4Component<double>(2223.0, mpc::core::TensorRank4ComponentIndex(1,1,1,2)), // X13 >> (1112), (1121), (1211), (2111)
    mpc::core::TensorRank4Component<double>(2213.0, mpc::core::TensorRank4ComponentIndex(1,1,0,2)), // X14 >> (1102), (1120), (0211), (2011)
    mpc::core::TensorRank4Component<double>(2212.0, mpc::core::TensorRank4ComponentIndex(1,1,0,1)), // X15 >> (1101), (1110), (0111), (1011)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(3323.0, mpc::core::TensorRank4ComponentIndex(2,2,1,2)), // X23 >> (2212), (2221), (1222), (2122)
    mpc::core::TensorRank4Component<double>(3313.0, mpc::core::TensorRank4ComponentIndex(2,2,0,2)), // X24 >> (2202), (2220), (0222), (2022)
    mpc::core::TensorRank4Component<double>(3312.0, mpc::core::TensorRank4ComponentIndex(2,2,0,1)), // X25 >> (2201), (2210), (0122), (1022)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(2313.0, mpc::core::TensorRank4ComponentIndex(1,2,0,2)), // X34 >> (1202), (1220), (2102), (2120), (0212), (2012), (0221), (2021)
    mpc::core::TensorRank4Component<double>(2312.0, mpc::core::TensorRank4ComponentIndex(1,2,0,1)), // X35 >> (1201), (1210), (2101), (2110), (0112), (1012), (0121), (1021)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(1312.0, mpc::core::TensorRank4ComponentIndex(0,2,0,1)), // X45 >> (0201), (0210), (2001), (2010), (0102), (1002), (0120), (1020)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::TriclinicSymmetryGroupType>(triclinic_symmetry_aliased_set_00);
std::cout << "triclinic stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);
```
Output

    triclinic stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 1112
    component(0,0,0,2) : 1113
    component(0,0,1,0) : 1112
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 1123
    component(0,0,2,0) : 1113
    component(0,0,2,1) : 1123
    component(0,0,2,2) : 1133
    component(0,1,0,0) : 1112
    component(0,1,0,1) : 1212
    component(0,1,0,2) : 1312
    component(0,1,1,0) : 1212
    component(0,1,1,1) : 2212
    component(0,1,1,2) : 2312
    component(0,1,2,0) : 1312
    component(0,1,2,1) : 2312
    component(0,1,2,2) : 3312
    component(0,2,0,0) : 1113
    component(0,2,0,1) : 1312
    component(0,2,0,2) : 1313
    component(0,2,1,0) : 1312
    component(0,2,1,1) : 2213
    component(0,2,1,2) : 2313
    component(0,2,2,0) : 1313
    component(0,2,2,1) : 2313
    component(0,2,2,2) : 3313
    component(1,0,0,0) : 1112
    component(1,0,0,1) : 1212
    component(1,0,0,2) : 1312
    component(1,0,1,0) : 1212
    component(1,0,1,1) : 2212
    component(1,0,1,2) : 2312
    component(1,0,2,0) : 1312
    component(1,0,2,1) : 2312
    component(1,0,2,2) : 3312
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 2212
    component(1,1,0,2) : 2213
    component(1,1,1,0) : 2212
    component(1,1,1,1) : 2222
    component(1,1,1,2) : 2223
    component(1,1,2,0) : 2213
    component(1,1,2,1) : 2223
    component(1,1,2,2) : 2233
    component(1,2,0,0) : 1123
    component(1,2,0,1) : 2312
    component(1,2,0,2) : 2313
    component(1,2,1,0) : 2312
    component(1,2,1,1) : 2223
    component(1,2,1,2) : 2323
    component(1,2,2,0) : 2313
    component(1,2,2,1) : 2323
    component(1,2,2,2) : 3323
    component(2,0,0,0) : 1113
    component(2,0,0,1) : 1312
    component(2,0,0,2) : 1313
    component(2,0,1,0) : 1312
    component(2,0,1,1) : 2213
    component(2,0,1,2) : 2313
    component(2,0,2,0) : 1313
    component(2,0,2,1) : 2313
    component(2,0,2,2) : 3313
    component(2,1,0,0) : 1123
    component(2,1,0,1) : 2312
    component(2,1,0,2) : 2313
    component(2,1,1,0) : 2312
    component(2,1,1,1) : 2223
    component(2,1,1,2) : 2323
    component(2,1,2,0) : 2313
    component(2,1,2,1) : 2323
    component(2,1,2,2) : 3323
    component(2,2,0,0) : 1133
    component(2,2,0,1) : 3312
    component(2,2,0,2) : 3313
    component(2,2,1,0) : 3312
    component(2,2,1,1) : 2233
    component(2,2,1,2) : 3323
    component(2,2,2,0) : 3313
    component(2,2,2,1) : 3323
    component(2,2,2,2) : 3333

```cpp
// MONOCLINIC_X2
/*
 *  | 00  01  02  --  04  -- |
 *  | 01  11  12  --  14  -- |
 *  | 02  12  22  --  24  -- |
 *  | --  --  --  33  --  35 |
 *  | 04  14  24  --  44  -- |
 *  | --  --  --  35  --  55 |
 */
std::set<mpc::core::TensorRank4Component<double> > monoclinicx2_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
    mpc::core::TensorRank4Component<double>(2213.0, mpc::core::TensorRank4ComponentIndex(1,1,0,2)), // X14 >> (1102), (1120), (0211), (2011)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(3313.0, mpc::core::TensorRank4ComponentIndex(2,2,0,2)), // X24 >> (2202), (2220), (0222), (2022)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(2312.0, mpc::core::TensorRank4ComponentIndex(1,2,0,1)), // X35 >> (1201), (1210), (2101), (2110), (0112), (1012), (0121), (1021)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::MonoclinicX2SymmetryGroupType>(monoclinicx2_symmetry_aliased_set_00);
std::cout << "monoclinic(x2) stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);
```
Output

    monoclinic(x2) stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 0
    component(0,0,0,2) : 1113
    component(0,0,1,0) : 0
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 0
    component(0,0,2,0) : 1113
    component(0,0,2,1) : 0
    component(0,0,2,2) : 1133
    component(0,1,0,0) : 0
    component(0,1,0,1) : 1212
    component(0,1,0,2) : 0
    component(0,1,1,0) : 1212
    component(0,1,1,1) : 0
    component(0,1,1,2) : 2312
    component(0,1,2,0) : 0
    component(0,1,2,1) : 2312
    component(0,1,2,2) : 0
    component(0,2,0,0) : 1113
    component(0,2,0,1) : 0
    component(0,2,0,2) : 1313
    component(0,2,1,0) : 0
    component(0,2,1,1) : 2213
    component(0,2,1,2) : 0
    component(0,2,2,0) : 1313
    component(0,2,2,1) : 0
    component(0,2,2,2) : 3313
    component(1,0,0,0) : 0
    component(1,0,0,1) : 1212
    component(1,0,0,2) : 0
    component(1,0,1,0) : 1212
    component(1,0,1,1) : 0
    component(1,0,1,2) : 2312
    component(1,0,2,0) : 0
    component(1,0,2,1) : 2312
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 0
    component(1,1,0,2) : 2213
    component(1,1,1,0) : 0
    component(1,1,1,1) : 2222
    component(1,1,1,2) : 0
    component(1,1,2,0) : 2213
    component(1,1,2,1) : 0
    component(1,1,2,2) : 2233
    component(1,2,0,0) : 0
    component(1,2,0,1) : 2312
    component(1,2,0,2) : 0
    component(1,2,1,0) : 2312
    component(1,2,1,1) : 0
    component(1,2,1,2) : 2323
    component(1,2,2,0) : 0
    component(1,2,2,1) : 2323
    component(1,2,2,2) : 0
    component(2,0,0,0) : 1113
    component(2,0,0,1) : 0
    component(2,0,0,2) : 1313
    component(2,0,1,0) : 0
    component(2,0,1,1) : 2213
    component(2,0,1,2) : 0
    component(2,0,2,0) : 1313
    component(2,0,2,1) : 0
    component(2,0,2,2) : 3313
    component(2,1,0,0) : 0
    component(2,1,0,1) : 2312
    component(2,1,0,2) : 0
    component(2,1,1,0) : 2312
    component(2,1,1,1) : 0
    component(2,1,1,2) : 2323
    component(2,1,2,0) : 0
    component(2,1,2,1) : 2323
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1133
    component(2,2,0,1) : 0
    component(2,2,0,2) : 3313
    component(2,2,1,0) : 0
    component(2,2,1,1) : 2233
    component(2,2,1,2) : 0
    component(2,2,2,0) : 3313
    component(2,2,2,1) : 0
    component(2,2,2,2) : 3333

```cpp
// MONOCLINIC_X3
/*
 *  | 00  01  02  --  --  05 |
 *  | 01  11  12  --  --  15 |
 *  | 02  12  22  --  --  25 |
 *  | --  --  --  33  34  -- |
 *  | --  --  --  34  44  -- |
 *  | 05  15  25  --  --  55 |
 */
std::set<mpc::core::TensorRank4Component<double> > monoclinicx3_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
    mpc::core::TensorRank4Component<double>(2212.0, mpc::core::TensorRank4ComponentIndex(1,1,0,1)), // X15 >> (1101), (1110), (0111), (1011)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(3312.0, mpc::core::TensorRank4ComponentIndex(2,2,0,1)), // X25 >> (2201), (2210), (0122), (1022)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(2313.0, mpc::core::TensorRank4ComponentIndex(1,2,0,2)), // X34 >> (1202), (1220), (2102), (2120), (0212), (2012), (0221), (2021)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::MonoclinicX3SymmetryGroupType>(monoclinicx3_symmetry_aliased_set_00);
std::cout << "monoclinic(x3) stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);
```
Output

    monoclinic(x3) stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 1112
    component(0,0,0,2) : 0
    component(0,0,1,0) : 1112
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 1133
    component(0,1,0,0) : 1112
    component(0,1,0,1) : 1212
    component(0,1,0,2) : 0
    component(0,1,1,0) : 1212
    component(0,1,1,1) : 2212
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 3312
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 1313
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 2313
    component(0,2,2,0) : 1313
    component(0,2,2,1) : 2313
    component(0,2,2,2) : 0
    component(1,0,0,0) : 1112
    component(1,0,0,1) : 1212
    component(1,0,0,2) : 0
    component(1,0,1,0) : 1212
    component(1,0,1,1) : 2212
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 3312
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 2212
    component(1,1,0,2) : 0
    component(1,1,1,0) : 2212
    component(1,1,1,1) : 2222
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 2233
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 2313
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 2323
    component(1,2,2,0) : 2313
    component(1,2,2,1) : 2323
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 1313
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 2313
    component(2,0,2,0) : 1313
    component(2,0,2,1) : 2313
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 2313
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 2323
    component(2,1,2,0) : 2313
    component(2,1,2,1) : 2323
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1133
    component(2,2,0,1) : 3312
    component(2,2,0,2) : 0
    component(2,2,1,0) : 3312
    component(2,2,1,1) : 2233
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 3333

```cpp
// ORTHORHOMBIC
/*
 *  | 00  01  02  --  --  -- |
 *  | 01  11  12  --  --  -- |
 *  | 02  12  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  44  -- |
 *  | --  --  --  --  --  55 |
 */
std::set<mpc::core::TensorRank4Component<double> > orthorhombic_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::OrthorhombicSymmetryGroupType>(orthorhombic_symmetry_aliased_set_00);
std::cout << "orthorhombic stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);
```
Output

    orthorhombic stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 1133
    component(0,1,0,0) : 0
    component(0,1,0,1) : 1212
    component(0,1,0,2) : 0
    component(0,1,1,0) : 1212
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 1313
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 1313
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 1212
    component(1,0,0,2) : 0
    component(1,0,1,0) : 1212
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 2222
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 2233
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 2323
    component(1,2,2,0) : 0
    component(1,2,2,1) : 2323
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 1313
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 1313
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 2323
    component(2,1,2,0) : 0
    component(2,1,2,1) : 2323
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1133
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 2233
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 3333

```cpp
// HEXAGONAL
/*
 *  | 00  01  02  --  --  -- |
 *  | 01  00  02  --  --  -- |
 *  | 02  02  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | --  --  --  --  --  XX |
 *
 * For C, XX = 0.5 * [C(0,0) - C(0,1)]
 * For S, XX =   2 * [S(0,0) - S(0,1)]
 */
std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_00);
std::cout << "hexagonal stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);

std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_01);
std::cout << "hexagonal stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);

std::set<mpc::core::TensorRank4Component<double> > hexagonal_symmetry_aliased_set_02{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::HexagonalSymmetryGroupType>(hexagonal_symmetry_aliased_set_02);
std::cout << "hexagonal stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);
```
Output

    hexagonal stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 1133
    component(0,1,0,0) : 0
    component(0,1,0,1) : -5.5
    component(0,1,0,2) : 0
    component(0,1,1,0) : -5.5
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 2323
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 2323
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : -5.5
    component(1,0,0,2) : 0
    component(1,0,1,0) : -5.5
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 1111
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 1133
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 2323
    component(1,2,2,0) : 0
    component(1,2,2,1) : 2323
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 2323
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 2323
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 2323
    component(2,1,2,0) : 0
    component(2,1,2,1) : 2323
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1133
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 1133
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 3333

    hexagonal stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 1133
    component(0,1,0,0) : 0
    component(0,1,0,1) : -5.5
    component(0,1,0,2) : 0
    component(0,1,1,0) : -5.5
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 1313
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 1313
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : -5.5
    component(1,0,0,2) : 0
    component(1,0,1,0) : -5.5
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 1111
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 1133
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 1313
    component(1,2,2,0) : 0
    component(1,2,2,1) : 1313
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 1313
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 1313
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 1313
    component(2,1,2,0) : 0
    component(2,1,2,1) : 1313
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1133
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 1133
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 3333

    hexagonal stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 1133
    component(0,1,0,0) : 0
    component(0,1,0,1) : -22
    component(0,1,0,2) : 0
    component(0,1,1,0) : -22
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 1313
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 1313
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : -22
    component(1,0,0,2) : 0
    component(1,0,1,0) : -22
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 1111
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 1133
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 1313
    component(1,2,2,0) : 0
    component(1,2,2,1) : 1313
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 1313
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 1313
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 1313
    component(2,1,2,0) : 0
    component(2,1,2,1) : 1313
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1133
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 1133
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 3333

```cpp
// TETRAGONAL7
/*
 *  | 00  01  02  --  --  05 |
 *  | 01  00  02  --  -- -05 |
 *  | 02  02  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | 05 -05  --  --  --  55 |
 */
std::set<mpc::core::TensorRank4Component<double> > tetragonal7_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1112.0, mpc::core::TensorRank4ComponentIndex(0,0,0,1)), // X05 >> (0001), (0010), (0100), (1000)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::Tetragonal7SymmetryGroupType>(tetragonal7_symmetry_aliased_set_00);
std::cout << "tetragonal7 stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);
```
Output

    tetragonal7 stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 1112
    component(0,0,0,2) : 0
    component(0,0,1,0) : 1112
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 1133
    component(0,1,0,0) : 1112
    component(0,1,0,1) : 1212
    component(0,1,0,2) : 0
    component(0,1,1,0) : 1212
    component(0,1,1,1) : -1112
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 2323
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 2323
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 1112
    component(1,0,0,1) : 1212
    component(1,0,0,2) : 0
    component(1,0,1,0) : 1212
    component(1,0,1,1) : -1112
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : -1112
    component(1,1,0,2) : 0
    component(1,1,1,0) : -1112
    component(1,1,1,1) : 1111
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 1133
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 2323
    component(1,2,2,0) : 0
    component(1,2,2,1) : 2323
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 2323
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 2323
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 2323
    component(2,1,2,0) : 0
    component(2,1,2,1) : 2323
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1133
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 1133
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 3333

```cpp
// TETRAGONAL6
/*
 *  | 00  01  02  --  --  -- |
 *  | 01  00  02  --  --  -- |
 *  | 02  02  22  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | --  --  --  --  --  55 |
 */
std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_00);
std::cout << "tetragonal6 stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);

std::set<mpc::core::TensorRank4Component<double> > tetragonal6_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(2233.0, mpc::core::TensorRank4ComponentIndex(1,1,2,2)), // X12 >> (1122), (2211)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(1313.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::Tetragonal6SymmetryGroupType>(tetragonal6_symmetry_aliased_set_01);
std::cout << "tetragonal6 stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);
```
Output

    tetragonal6 stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 1133
    component(0,1,0,0) : 0
    component(0,1,0,1) : 1212
    component(0,1,0,2) : 0
    component(0,1,1,0) : 1212
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 2323
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 2323
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 1212
    component(1,0,0,2) : 0
    component(1,0,1,0) : 1212
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 1111
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 1133
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 2323
    component(1,2,2,0) : 0
    component(1,2,2,1) : 2323
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 2323
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 2323
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 2323
    component(2,1,2,0) : 0
    component(2,1,2,1) : 2323
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1133
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 1133
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 3333

    tetragonal6 stiffness tensor
    component(0,0,0,0) : 2222
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 2233
    component(0,1,0,0) : 0
    component(0,1,0,1) : 1212
    component(0,1,0,2) : 0
    component(0,1,1,0) : 1212
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 1313
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 1313
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 1212
    component(1,0,0,2) : 0
    component(1,0,1,0) : 1212
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 2222
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 2233
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 1313
    component(1,2,2,0) : 0
    component(1,2,2,1) : 1313
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 1313
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 1313
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 1313
    component(2,1,2,0) : 0
    component(2,1,2,1) : 1313
    component(2,1,2,2) : 0
    component(2,2,0,0) : 2233
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 2233
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 3333

```cpp
// TRIGONAL7
/*
 *  | 00  01  02  03 -04  -- |
 *  | 01  00  02 -03  04  -- |
 *  | 02  02  22  --  --  -- |
 *  | 03 -03  --  33  -- *04 |
 *  | 04  14  --  --  33 *03 |
 *  | --  --  -- *04 *03  XX |
 *
 * where *NN is the numerical equal for C and twice the numerical equal for S; and
 * For C, XX = 0.5 * [C(0,0) - C(0,1)]
 * For S, XX =   2 * [S(0,0) - S(0,1)]
 *
 */

std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::Trigonal7SymmetryGroupType>(trigonal7_symmetry_aliased_set_00);
std::cout << "trigonal7 stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);

std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

std::set<mpc::core::TensorRank4Component<double> > trigonal7_symmetry_aliased_set_02{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(1113.0, mpc::core::TensorRank4ComponentIndex(0,0,0,2)), // X04 >> (0002), (0020), (0200), (2000)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};
```
Output

    trigonal7 stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 0
    component(0,0,0,2) : 1113
    component(0,0,1,0) : 0
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 1123
    component(0,0,2,0) : 1113
    component(0,0,2,1) : 1123
    component(0,0,2,2) : 1133
    component(0,1,0,0) : 0
    component(0,1,0,1) : -5.5
    component(0,1,0,2) : 1123
    component(0,1,1,0) : -5.5
    component(0,1,1,1) : 0
    component(0,1,1,2) : -1113
    component(0,1,2,0) : 1123
    component(0,1,2,1) : -1113
    component(0,1,2,2) : 0
    component(0,2,0,0) : 1113
    component(0,2,0,1) : 1123
    component(0,2,0,2) : 2323
    component(0,2,1,0) : 1123
    component(0,2,1,1) : -1113
    component(0,2,1,2) : 0
    component(0,2,2,0) : 2323
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : -5.5
    component(1,0,0,2) : 1123
    component(1,0,1,0) : -5.5
    component(1,0,1,1) : 0
    component(1,0,1,2) : -1113
    component(1,0,2,0) : 1123
    component(1,0,2,1) : -1113
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 0
    component(1,1,0,2) : -1113
    component(1,1,1,0) : 0
    component(1,1,1,1) : 1111
    component(1,1,1,2) : -1123
    component(1,1,2,0) : -1113
    component(1,1,2,1) : -1123
    component(1,1,2,2) : 1133
    component(1,2,0,0) : 1123
    component(1,2,0,1) : -1113
    component(1,2,0,2) : 0
    component(1,2,1,0) : -1113
    component(1,2,1,1) : -1123
    component(1,2,1,2) : 2323
    component(1,2,2,0) : 0
    component(1,2,2,1) : 2323
    component(1,2,2,2) : 0
    component(2,0,0,0) : 1113
    component(2,0,0,1) : 1123
    component(2,0,0,2) : 2323
    component(2,0,1,0) : 1123
    component(2,0,1,1) : -1113
    component(2,0,1,2) : 0
    component(2,0,2,0) : 2323
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 1123
    component(2,1,0,1) : -1113
    component(2,1,0,2) : 0
    component(2,1,1,0) : -1113
    component(2,1,1,1) : -1123
    component(2,1,1,2) : 2323
    component(2,1,2,0) : 0
    component(2,1,2,1) : 2323
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1133
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 1133
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 3333

```cpp
//  TRIGONAL6
/*
 *  | 00  01  02  03  --  -- |
 *  | 01  00  02 -03  --  -- |
 *  | 02  02  22  --  --  -- |
 *  | 03 -03  --  33  --  -- |
 *  | --  --  --  --  33 *03 |
 *  | --  --  --  -- *03  XX |
 *
 * For C, XX = 0.5 * [C(0,0) - C(0,1)]
 * For S, XX =   2 * [S(0,0) - S(0,1)]
 */

std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::Trigonal6SymmetryGroupType>(trigonal6_symmetry_aliased_set_00);
std::cout << "trigonal6 stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);

std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(-5.5, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

std::set<mpc::core::TensorRank4Component<double> > trigonal6_symmetry_aliased_set_02{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(1123.0, mpc::core::TensorRank4ComponentIndex(0,0,1,2)), // X03 >> (0012), (0021), (1200), (2100)
    mpc::core::TensorRank4Component<double>(3333.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
    mpc::core::TensorRank4Component<double>(-22.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};
```
Output

    trigonal6 stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 1123
    component(0,0,2,0) : 0
    component(0,0,2,1) : 1123
    component(0,0,2,2) : 1133
    component(0,1,0,0) : 0
    component(0,1,0,1) : -5.5
    component(0,1,0,2) : 1123
    component(0,1,1,0) : -5.5
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 1123
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 1123
    component(0,2,0,2) : 2323
    component(0,2,1,0) : 1123
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 2323
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : -5.5
    component(1,0,0,2) : 1123
    component(1,0,1,0) : -5.5
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 1123
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 1111
    component(1,1,1,2) : -1123
    component(1,1,2,0) : 0
    component(1,1,2,1) : -1123
    component(1,1,2,2) : 1133
    component(1,2,0,0) : 1123
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : -1123
    component(1,2,1,2) : 2323
    component(1,2,2,0) : 0
    component(1,2,2,1) : 2323
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 1123
    component(2,0,0,2) : 2323
    component(2,0,1,0) : 1123
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 2323
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 1123
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : -1123
    component(2,1,1,2) : 2323
    component(2,1,2,0) : 0
    component(2,1,2,1) : 2323
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1133
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 1133
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 3333

```cpp
// CUBIC
/*
 *  | 00  01  01  --  --  -- |
 *  | 01  00  01  --  --  -- |
 *  | 01  01  00  --  --  -- |
 *  | --  --  --  33  --  -- |
 *  | --  --  --  --  33  -- |
 *  | --  --  --  --  --  33 |
 */
std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00);
std::cout << "cubic stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);

std::set<mpc::core::TensorRank4Component<double> > cubic_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(2222.0, mpc::core::TensorRank4ComponentIndex(1,1,1,1)), // X11 >> (1111)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

stiffness_tensor.SetComponentsWithSymmetry<mpc::core::CubicSymmetryGroupType>(cubic_symmetry_aliased_set_00);
std::cout << "cubic stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor.tensor);
```
Output

    cubic stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 1122
    component(0,1,0,0) : 0
    component(0,1,0,1) : 2323
    component(0,1,0,2) : 0
    component(0,1,1,0) : 2323
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 2323
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 2323
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 2323
    component(1,0,0,2) : 0
    component(1,0,1,0) : 2323
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 1111
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 1122
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 2323
    component(1,2,2,0) : 0
    component(1,2,2,1) : 2323
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 2323
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 2323
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 2323
    component(2,1,2,0) : 0
    component(2,1,2,1) : 2323
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1122
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 1122
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 1111

    cubic stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : 1122
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : 1122
    component(0,1,0,0) : 0
    component(0,1,0,1) : 2323
    component(0,1,0,2) : 0
    component(0,1,1,0) : 2323
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 2323
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 2323
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 2323
    component(1,0,0,2) : 0
    component(1,0,1,0) : 2323
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : 1122
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 1111
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : 1122
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 2323
    component(1,2,2,0) : 0
    component(1,2,2,1) : 2323
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 2323
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 2323
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 2323
    component(2,1,2,0) : 0
    component(2,1,2,1) : 2323
    component(2,1,2,2) : 0
    component(2,2,0,0) : 1122
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : 1122
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 1111

```cpp
// ISOTROPIC
/*
 *  | 00  01  01  --  --  -- |
 *  | 01  00  01  --  --  -- |
 *  | 01  01  00  --  --  -- |
 *  | --  --  --  XX  --  -- |
 *  | --  --  --  --  XX  -- |
 *  | --  --  --  --  --  XX |
 *
 * For C, XX = 0.5 * [C(0,0) - C(0,1)]
 * For S, XX =   2 * [S(0,0) - S(0,1)]
 */
std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_00{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1212.0, mpc::core::TensorRank4ComponentIndex(0,1,0,1)) // X55 >> (0101), (0110), (1001), (1010)
};

mpc::core::StiffnessTensor<double> stiffness_tensor_isotropic_00;
stiffness_tensor_isotropic_00.SetComponentsWithSymmetry<mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_00);
std::cout << "isotropic stiffness tensor" << std::endl;
print_tensor_components_double_4_fo(stiffness_tensor_isotropic_00.tensor);

//    mpc::core::ComplianceTensor<double> compliance_tensor_isotropic_00;
//    compliance_tensor_isotropic_00.SetComponentsWithSymmetry<mpc::core::IsotropicSymmetryGroupType>(isotropic_symmetry_aliased_set_00);
//    std::cout << "isotropic compliance tensor" << std::endl;
//    print_tensor_components_double_4_fo(compliance_tensor_isotropic_00.tensor);

std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_01{
    mpc::core::TensorRank4Component<double>(1111.0, mpc::core::TensorRank4ComponentIndex(0,0,0,0)), // X00 >> (0000)
    mpc::core::TensorRank4Component<double>(1122.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
};

std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_02{
    mpc::core::TensorRank4Component<double>(1133.0, mpc::core::TensorRank4ComponentIndex(0,0,2,2)), // X02 >> (0022), (2200)
    mpc::core::TensorRank4Component<double>(2323.0, mpc::core::TensorRank4ComponentIndex(1,2,1,2)), // X33 >> (1212), (1221), (2112), (2121)
};

std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_03{
    mpc::core::TensorRank4Component<double>(20.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(100.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(40.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
}; // NOTE: For C, XX = 0.5 * [C(0,0) - C(0,1)]; satisfies cubic as well

std::set<mpc::core::TensorRank4Component<double> > isotropic_symmetry_aliased_set_04{
    mpc::core::TensorRank4Component<double>(20.0, mpc::core::TensorRank4ComponentIndex(0,0,1,1)), // X01 >> (0011), (1100)
    mpc::core::TensorRank4Component<double>(100.0, mpc::core::TensorRank4ComponentIndex(2,2,2,2)), // X22 >> (2222)
    mpc::core::TensorRank4Component<double>(160.0, mpc::core::TensorRank4ComponentIndex(0,2,0,2)), // X44 >> (0202), (0220), (2002), (2020)
}; // NOTE: For S, XX =   2 * [S(0,0) - S(0,1)]; satisfies cubic as well
```
Output

    isotropic stiffness tensor
    component(0,0,0,0) : 1111
    component(0,0,0,1) : 0
    component(0,0,0,2) : 0
    component(0,0,1,0) : 0
    component(0,0,1,1) : -1313
    component(0,0,1,2) : 0
    component(0,0,2,0) : 0
    component(0,0,2,1) : 0
    component(0,0,2,2) : -1313
    component(0,1,0,0) : 0
    component(0,1,0,1) : 1212
    component(0,1,0,2) : 0
    component(0,1,1,0) : 1212
    component(0,1,1,1) : 0
    component(0,1,1,2) : 0
    component(0,1,2,0) : 0
    component(0,1,2,1) : 0
    component(0,1,2,2) : 0
    component(0,2,0,0) : 0
    component(0,2,0,1) : 0
    component(0,2,0,2) : 1212
    component(0,2,1,0) : 0
    component(0,2,1,1) : 0
    component(0,2,1,2) : 0
    component(0,2,2,0) : 1212
    component(0,2,2,1) : 0
    component(0,2,2,2) : 0
    component(1,0,0,0) : 0
    component(1,0,0,1) : 1212
    component(1,0,0,2) : 0
    component(1,0,1,0) : 1212
    component(1,0,1,1) : 0
    component(1,0,1,2) : 0
    component(1,0,2,0) : 0
    component(1,0,2,1) : 0
    component(1,0,2,2) : 0
    component(1,1,0,0) : -1313
    component(1,1,0,1) : 0
    component(1,1,0,2) : 0
    component(1,1,1,0) : 0
    component(1,1,1,1) : 1111
    component(1,1,1,2) : 0
    component(1,1,2,0) : 0
    component(1,1,2,1) : 0
    component(1,1,2,2) : -1313
    component(1,2,0,0) : 0
    component(1,2,0,1) : 0
    component(1,2,0,2) : 0
    component(1,2,1,0) : 0
    component(1,2,1,1) : 0
    component(1,2,1,2) : 1212
    component(1,2,2,0) : 0
    component(1,2,2,1) : 1212
    component(1,2,2,2) : 0
    component(2,0,0,0) : 0
    component(2,0,0,1) : 0
    component(2,0,0,2) : 1212
    component(2,0,1,0) : 0
    component(2,0,1,1) : 0
    component(2,0,1,2) : 0
    component(2,0,2,0) : 1212
    component(2,0,2,1) : 0
    component(2,0,2,2) : 0
    component(2,1,0,0) : 0
    component(2,1,0,1) : 0
    component(2,1,0,2) : 0
    component(2,1,1,0) : 0
    component(2,1,1,1) : 0
    component(2,1,1,2) : 1212
    component(2,1,2,0) : 0
    component(2,1,2,1) : 1212
    component(2,1,2,2) : 0
    component(2,2,0,0) : -1313
    component(2,2,0,1) : 0
    component(2,2,0,2) : 0
    component(2,2,1,0) : 0
    component(2,2,1,1) : -1313
    component(2,2,1,2) : 0
    component(2,2,2,0) : 0
    component(2,2,2,1) : 0
    component(2,2,2,2) : 1111


C-S Relationships
> much work to be done;  most text describe in terms of matrix notation, not tensor (no scalar applied to compliance)
```cpp
mpc::core::ComplianceTensor<double> compliance_tensor_from_stiffness_tensor = mpc::core::CSRelationship<mpc::core::TriclinicSymmetryGroupType>(stiffness_tensor);
mpc::core::StiffnessTensor<double> stiffness_tensor_from_compliance_tensor_from_stiffness_tensor = mpc::core::CSRelationship<mpc::core::NoneSymmetryGroupType>(compliance_tensor_from_stiffness_tensor);
```

---
### references
* Bass, J.D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63.
* Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
* Smith, Tad M., Sondergeld, Carl H., Rai, Chandra S., 2003, Gassmann fluid substitutions: A tutorial: GEOPHYSICS, 68, 2, 430-440
* Thomsen, Leon, 2014, Understanding seismic anisotropy in exploration and exploitation, second edition: Society of Exploration Geophysics.

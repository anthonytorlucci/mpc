# mpc::core
core namespace

### csrelationships.hpp
functions and function objects to calculate the stiffness tensor components from the compliance tensor components or vice versa

### cstypes.hpp
stiffness and compliance structs used as types for template specializations

### stiffnesscompliance.hpp
stiffness and compliance tensor classes; part of the core data structures

### stressstrain.hpp
stress and strain tensor classes; part of the core data structures

### symmetrycomponents.hpp
functions and function objects for extracting components of the stiffness or compliance tensor that are related in matrix notation form

### symmetrygrouptypes.hpp
classes that describe the different symmetry groups supported by mpc as types used for template specializations

### symmetrypredicates.hpp
boolean functions related to symmetry groups or sets of tensor components used for assertions or control flow

### tensorcomponent.hpp
structure that defines a tensor component

### tensorcomponentindex.hpp
structure that defines a tensor component index, i.e. the indices (i,j) or (i,j,k,l) of a tensor

### tensorcomponentindexaliases.hpp
tensor components aliased by symmetry; different symmetry group types will have different relationships among tensor components for which mpc defines them as "aliases"; this concept is still a work in progress...

### tensorcomponentindexpredicates.hpp
boolean functions that take a TensorRankNComponentIndex<N> that can be used in assertions or control program flow

### tensorinvariants.hpp
tensor invariants - reduction in tensor rank by contraction, usually to a rank zero tensor or scalar; for stiffness and compliance tensors, the bulk and shear modulii can be derived from the invariants

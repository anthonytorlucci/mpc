# mpcexamples
mechanical properties of crystals and polycrystalline aggregates

---
### introduction
mpc is c++ header-only template library designed for the explicit calculation of the mechanical properties of a crystal or polycrystalline aggregate in a three-dimensional Cartesian space.  The library's primary purpose is to compute the static effective stiffness and compliance tensors of heterogeneous or composite materials and the corresponding velocities using the Green-Christoffel equation.

The user should be familiar the basics of continuum mechanics, particularly solid mechanics including, at a minimum, tensor algebra.  These examples start by walking you through creating the core data structures that make mpc.  These core data structures are based on the concept of a tensor which is at the core of mechanics and thus form the core data structures for mpc.

We assume that the material obeys Hooke's law; that is, there exists a linear relationship between the stress applied to the material and the corresponding strain.  Hooke's law is written is concise suffix notation as
\[
\sigma_{ij} = c_{ijkl} \epsilon_{kl}
\]
or
\[
\epsilon_{kl} = s_{klij} \sigma_{ij}
\]
where \(\sigma_{ij}\) is the stress tensor, \(\epsilon_{kl}\) is the strain tensor, \(c_{ijkl}\) is the stiffness tensor, and \(s_{klij}\) is the compliance tensor.

mpc is broken up into a few main namespaces:
[utilities](./markdown/utilities.md)
[core](./markdown/core.md)
[data](./markdown/data.md)
[rockphysics](./markdown/rockphysics.md)
[transformation](./markdown/transformation.md)
[mechanics](./markdown/mechanics.md)


---
### references
* Bass, J.D., 1995, Elasticity of minerals, glasses, and melts in Ahrens, T. J., Mineral Physics and Crystallography: American Geophysical Union, 45-63.
* Dvorkin, J., Guitierrez, M., Grana, D., 2014, Seismic Reflections of Rock Properties : Cambridge University Press.
* Smith, Tad M., Sondergeld, Carl H., Rai, Chandra S., 2003, Gassmann fluid substitutions: A tutorial: GEOPHYSICS, 68, 2, 430-440
* Thomsen, Leon, 2014, Understanding seismic anisotropy in exploration and exploitation, second edition: Society of Exploration Geophysics.

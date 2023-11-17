# Cpp_CAM_Machin_project


## Task

A 3D Euclidean point cloud aligned in main axis directions (x, y, z) and with a constant distance grid (Figure 1) starting at a given reference point (the point with indices 0, 0, 0 is located at the reference point) is intersected by a move of a sphere (Figure 2), where the path of the sphere center is defined by a user-given formula `~x = f(t)` where `t` is in the interval between `t0` and `t1`. The function `f(t)` can be handled as a discrete function with a user-given `∆t`. Points that intersect with the sphere move are considered as deleted (Figure 3 middle).

- Only the first layer of points (which remains visible/undeleted) from the top view must be written to a file as ASCII data (the skin of the point cloud visible from the positive Z direction, see Figure 3 right). The file format is defined as follows:
  - Each line contains a single point.
  - The point definition contains x, y, and z coordinates delimited by space characters.
  - Each line ends with a new line character.
- Create a small documentation (1 page with 2 pictures) to present the mathematical approach of the sphere move point intersection. It should clearly communicate the mathematical approach and how the mathematical code is generated from that.
- Please discuss briefly in 4-5 sentences what problems can arise by using a discrete stepping `∆t`.

### Given

- Point class for the definition of a point in 3D and (some) methods for vector algebra.
- Visual Studio 2008 and 2013 solutions, Makefile, and qmake project file.
- High-level test function `CreateSkin(...)` (in `CreateSkin.cpp`) to test the resulting component. This defines also the interface of the component to be written.
- Program named `PointVisualizer` which allows you to view the results you obtain in 3D.

### Hints

- Use of vector algebra (dot product, cross product, etc.) is highly recommended. The use of sin and cos functions is not desired.
- Calculation speed and memory footprint are important but secondary in comparison to clearly readable code. E.g., a sphere, linear move of a sphere, point writer, etc. might be modeled as classes. Prefer compact classes and functions over large classes and functions.
- Comments in the source code are welcome. Please use good names for classes and functions.
- Move of a sphere between `f(t)` and `f(t + ∆t)` can be assumed as a linear move of the center of the sphere.

## Illustrations

### Figure 1: 3D Point Cloud
![3D Point Cloud](URL_to_Figure_1_Image)

### Figure 2: Linear Move of a Sphere
![Linear Move of a Sphere](URL_to_Figure_2_Image)

### Figure 3: Point Cloud and Top Skin
![Point Cloud and Top Skin](URL_to_Figure_3_Image)

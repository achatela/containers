# ft_containers: C++98 STL Containers Reimplementation

## Project Overview
The `ft_containers` project is part of the curriculum that challenges students to reimplement subsets of the C++ Standard Template Library (STL) adhering strictly to the C++98 standard. This project requires creating custom versions of several widely used containers in modern C++ programming.

## Containers Implemented
- **Vector**: A dynamic array capable of resizing itself to accommodate additional elements.
- **Map**: An associative container that stores elements formed by a combination of a key value and a mapped value, following a specific order.
- **Stack**: A container adaptor that gives the LIFO (Last In, First Out) type of data structure, utilizing `ft::vector` as the default underlying container.

## Additional Features
- Implementation of utility functions and classes such as `std::pair`, `std::make_pair`, and `std::allocator`.
- Introduction of iterator support with `std::iterator_traits` and `std::reverse_iterator`.
- Inclusion of SFINAE (Substitution Failure Is Not An Error) utilities like `std::enable_if` and type traits such as `std::is_integral`.
- Comparison functions like `std::equal` and `std::lexicographical_compare`.

## Compilation and Testing
- The code compiles using `c++` with the flags `-Wall -Wextra -Werror` and explicitly setting the standard to C++98 (`-std=c++98`).
- Includes a Makefile with targets for building, cleaning, and relinking prevention.
- Tests are provided to compare the behavior and performance of custom containers against the STL versions.

## Project Structure
- Each container is implemented in its dedicated header file within the `ft` namespace.
- Test cases are included in `main.cpp` to demonstrate the functionality and to ensure compatibility with the STL containers.

## Usage
To compile and run the tests with valgrind:
```bash
./script.sh
```

To compile and run the tests to compare performance with the STL containers:
```bash
./script_time.sh
```
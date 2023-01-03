## When to use std::vector and arrays

In C++, you can use either std::vector or arrays to store a collection of elements. The choice between std::vector and arrays depends on your requirements and the tradeoffs between them.

### std::vector

std::vector is a template class in the C++ Standard Template Library (STL) that represents a dynamically-sized array. It has the following advantages over arrays:

- It can grow or shrink dynamically to accommodate the number of elements that it contains.
- It provides constant time access to individual elements using an index.
- It supports common operations such as inserting and deleting elements, sorting, and searching.

However, std::vector has the following disadvantages compared to arrays:

- It has a larger overhead due to the additional information (such as the size and capacity of the vector) that it stores.
- It may have slower access times due to the extra level of indirection involved in accessing its elements.

### Arrays

Arrays are a built-in data type in C++ that represent a fixed-size collection of elements. They have the following advantages over std::vector:

- They have a smaller overhead compared to std::vector.
- They may have faster access times due to the direct access to their elements.

However, arrays have the following disadvantages compared to std::vector:

- They have a fixed size, and their size cannot be changed once they are created.
- They do not support common operations such as inserting and deleting elements, sorting, and searching.

In general, if you need a dynamic collection of elements that can grow or shrink and support common operations, you should use std::vector. If you need a fixed-size collection of elements with a small overhead and fast access times, you should use an array.

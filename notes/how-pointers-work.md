## How Pointers work

In C++, a pointer is a variable that stores the memory address of another object. Pointers are useful when you want to pass an object to a function by reference, or when you want to have a reference to an object that can be modified by the function.

To declare a pointer in C++, you use the \* operator between the type and the name of the pointer. For example:

```cpp
int x = 10;
int\* p = &x;
```

In this example, the variable p is a pointer to int, and it stores the memory address of the variable x.

To access the value stored in the object pointed by a pointer, you use the \* operator. This is called dereferencing the pointer. For example:

```cpp
int x = 10;
int* p = &x;
std::cout << *p << std::endl; // Outputs 10
```

In this example, the value of \*p is the value of the object pointed by p, which is x.

To get the memory address of an object, you use the & operator. This is called taking the address of the object. For example:

```cpp
int x = 10;
int\* p = &x;
std::cout << &x << std::endl; // Outputs the memory address of x
```

In this example, the value of &x is the memory address of the object x.

### Credits

ChatGPT

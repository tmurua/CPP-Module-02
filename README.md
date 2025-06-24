# CPP-Module-02

This repository contains my solutions for Module 02. In these exercises I implemented a fixed-point number class in C++98, progressively adding functionality from basic canonical form to full operator support. Below is an overview of each exercise, including my implementation plan and lessons learned.

---

## ex:00 - My First Class in Orthodox Canonical Form

**Files:** Makefile, main.cpp, Fixed.hpp, Fixed.cpp

**Plan**

1. **Private Data:**
   - `int rawBits;` to store the fixed-point representation.
   - `static const int fractionalBits = 8;` for the number of fractional bits.
2. **Orthodox Canonical Form:**
   - Default constructor initializing `rawBits` to 0 (using initializer list).
   - Copy constructor copying `rawBits`.
   - Copy-assignment operator with self-assignment check.
   - Destructor.
3. **Accessors:**
   - `int getRawBits() const;`
   - `void setRawBits(int const raw);`
4. **Logging:**
   - Output messages in each special member function to trace object lifetime.
5. **Testing:**
   - `main.cpp` instantiates three `Fixed` objects (`a`, `b(a)`, `c`) and assigns `c = b`.
   - Calls `getRawBits()` on each and prints the results.

**Lessons Learned**

- Implementation of **default/copy constructors**, **assignment operator**, and **destructor** in the Orthodox Canonical Form.
- Use of **initializer lists** for member initialization.
- Basic **getter/setter** patterns and encapsulation of raw data.
- Tracing object creation and destruction via console output.

---

## ex:01 - Towards a More Useful Fixed-Point Number Class

**Files:** Makefile, main.cpp, Fixed.hpp, Fixed.cpp

**Allowed Functions:** `roundf` (from `<cmath>`)

**Plan**

1. **Integer Constructor:**
   - Convert an `int` to fixed-point by left-shifting by `fractionalBits`.
2. **Float Constructor:**
   - Convert a `float` to fixed-point by multiplying by `2^fractionalBits` and rounding with `roundf()`.
3. **Conversion Methods:**
   - `float toFloat() const;` divides by `2^fractionalBits`.
   - `int toInt() const;` right-shifts by `fractionalBits`.
4. **Stream Insertion:**
   - Overload `operator<<` to output the floating-point representation via `toFloat()`.
5. **Logging:**
   - Output constructor and destructor messages to trace new code paths.
6. **Testing:**
   - `main.cpp` creates `Fixed` objects from int and float values, copies them, and prints both float and integer conversions.

**Lessons Learned**

- Implementing **custom constructors** for numeric conversions.
- Applying **bit-shifting** and **rounding** to manage fixed-point arithmetic.
- Overloading `` to integrate with C++ streams.
- Converting between fixed-point and built-in types.

---

## ex:02 - Now We’re Talking

**Files:** Makefile, main.cpp, Fixed.hpp, Fixed.cpp

**Allowed Functions:** `roundf` (from `<cmath>`)

**Plan**

1. **Comparison Operators:** `>`, `<`, `>=`, `<=`, `==`, `!=` comparing `rawBits`.
2. **Arithmetic Operators:** `+`, `-`, `*`, `/` with correct scaling:
   - Addition/Subtraction on `rawBits`.
   - Multiplication: multiply as `long` then shift down by `fractionalBits`.
   - Division: shift up then divide to maintain precision.
3. **Increment/Decrement:**
   - Pre- and post-increment/decrement adjusting `rawBits` by `1` (smallest ε).
4. **Min/Max Static Methods:**
   - `static Fixed &min(Fixed &a, Fixed &b);` (and const overload)
   - `static Fixed &max(Fixed &a, Fixed &b);` (and const overload)
5. **Stream Insertion:**
   - Continue using `operator<<` from ex:01.
6. **Testing:**
   - `main.cpp` exercises zero-initialization, increment operators, multiplication, and `Fixed::max()`.

**Lessons Learned**

- Overloading **comparison**, **arithmetic**, and **increment/decrement** operators.
- Handling **scale adjustments** for fixed-point multiplication and division.
- Implementing **static utility functions** (`min`/`max`) returning references.
- Deepening understanding of **operator overloading** in C++.

---

## Final Thoughts

Module 02 reinforced advanced class design in C++98, notably:

- **Orthodox Canonical Form** and proper resource handling.
- **Bitwise manipulation** for custom numeric types.
- **Operator overloading** for seamless integration with language syntax.
- Stepwise extension of functionality, from raw storage to full arithmetic support.

All code compiles under:

```
c++ -Wall -Wextra -Werror -std=c++98
```

and passes the provided tests for each exercise.


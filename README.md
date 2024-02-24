# Vec.h

Vec.h is a C/C++ library that provides a versatile vector implementation through the chyves::vec class template, allowing for dynamic arrays with various functionalities.

## Features
- Dynamic Array: ```chyves::vec``` provides a dynamic array implementation with features like element access, modification, resizing, and arithmetic operations.
- Initializer List Support: You can initalize vectors with the use of initializer lists leading to a cleaner codebase.
- Customizable Size: The template allows for fixed-size vectors with the options to specify the size at compile time.
- Arithmetic Operations: Overloaded operations enable vector addition, subtraction, along with multiplication and division by scalar.
- Ensure proper memory management by using functions like clear() and destructor.
- Handle exceptions like out-of-range access and division by zero.


## Usage
To use this, small library just download the vec.h file and import it into your codebase.
```cpp

#include "include/chyves/vec.h"

// Create Vectors
chyves::vec<int> myVector; // basic vector needs to have items manually added through set or push_back
chyves::vec<int> myVector2 = {10, 10, 10}; // vector already inited with items
chyves::vec<int, 5> myVector3 = {10, 10, 10, 10, 10}; // vector already inited with a fixed amount of items
chyves::vec3_int myVector4 = {10, 10, 10}; // preset vector that uses integers and a fixed amount of 3 items

// Custom Types
typedef chyves::vec<int, 10> my_custom_vec;
my_custom_vec vec = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

// Arithmetic Operations
chyves::vec<int> result = myVector2 + myVector3;

// Helper Functions
chyves::vec<int> exampleUnInitedVector;
exampleUnInitedVector.push_back(5); // added 5 to vector

std::cout << "Element at index 1: " << exampleUnInitedVector.get(0) << std::endl;

exampleUnInitedVector.set(1, 6); // change the 5 to 6

exampleUnInitedVector.push_back(12);
std::cout << "The size of the vector is " << exampleUnInitedVector.getSize() << std::endl;

```

### Available Custom Types
| Integers  |  Floats     | Booleans | Character Strings
| :------:  | :--------:  | :------: | :------------:
| vec_int   | vec_float   | vec_int  | vec_cchat
| vec2_int  | vec2_float  | vec2_int | vec_cchat
| vec3_int  | vec3_float  | vec3_int | vec_cchat
| vec4_int  | vec4_float  | vec4_int | vec_cchat

For more details on usage and customization options, refer to the source code. Thank you!

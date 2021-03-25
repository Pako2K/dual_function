# DualFunction
C++ class for a function with double behaviour

Use case: change dynamically the behavior of a function by pointing to another function with the same signature (return type and arguments types)

**Usage example:**

```
std::function<void(int&)> f1 { [](int& i){++i;} }; // Increment

std::function<void(int&)> f2 { [](int& i){} };  // Do nothing

DualFunction<void(int&)> dualFn(f1, f2);

int var{1}
dualFn(var); // var=2

dualFn.switchFn();
dualFn(var); // var=2 (function f2 does nothing)
```

By default the first function is the active one. To change the active function call one of these methods:

```
  enableFirst()
  enableSecond()
  switchFn()
```

To find out which function is active use this method:

```
  isFirstFn()
```

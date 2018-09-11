# Part 2 - Basics
This chapter corresponds to chapter 2 in "The C Programming Language" 2nd Edition by Kernighan, and sections of lectures 2 and 3 in the notes.

## Primitive Data Types
C has very few primitive data types:

|Name|Example|Description|
|-|-|-|
|int|`int i = 2;`|Integer|
|char|`char c = 'a';`|Character|
|float|`float f = 'a';`|Floating point number|
|double|`double d = 'a';`|Double-precise floating point number|

### Machine-Dependent Features of Primitives

## Variables, Values, and Addresses


```C
int main() {
  int x = 3, y;
  y = + + + + + x;
  y = - + - + - + x;
  y = - ++x;
  y = ++ -x;//ERROR address "-x" is not assignable
  y = ++ x ++;//ERROR address "x ++" is not assignable
  y = ++ ++ x;//ERROR address "++x" is not assignable
  return 0;
}
```

## Basic Operators



### More Operators

### Precedence

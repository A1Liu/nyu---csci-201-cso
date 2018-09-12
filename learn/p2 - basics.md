# Part 2 - Basics
This chapter corresponds to chapter 2 in "The C Programming Language" 2nd Edition by Kernighan, and sections of lectures 2 and 3 in the notes.

## Primitive Data Types
C has very few primitive data types:

|Name|Example|Description|
|-|-|-|
|int|`int i = 2;`|Integer|
|char|`char c = 'a';`|Character|
|float|`float f = 1.5;`|Floating point number|
|double|`double d = 1.1;`|Double-precise floating point number|

It also has a few qualifiers that affect the size of these types in memory:

|Name|Goes With|Description|
|-|-|
|short|int|smaller version of the int (can be written `short int` or just 'short')|
|long|int, double|larger version of the int and larger version of the double (int version can be written as `long int` or just `long`)|
|signed|int,char|Makes characters have values from -128 to 127|
|unsigned|int,char|Ints can't be negative, char goes from 0 to 255|


### Machine-Dependent Features of Primitives
Size of int, long, and short.

## Constants and Variables
Variables hold values.

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

#### Addresses vs Values

### Precedence

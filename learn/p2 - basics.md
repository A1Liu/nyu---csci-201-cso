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

|Precedence|Operator|Description|Associativity|
|-|-|-|-|
|1|++ --|Suffix/postfix increment and decrement|Left-to-right|
|()|Function call|
|[]|Array subscripting|
|.|Structure and union member access|
|->|Structure and union member access through pointer|
|(type){list}|Compound literal(C99)|
|2|++ --|Prefix increment and decrement|Right-to-left|
|+ -|Unary plus and minus|
|! ~|Logical NOT and bitwise NOT|
|(type)|Type cast|
|*|Indirection (dereference)|
|&|Address-of|
|sizeof|Size-of[note 1]|
|_Alignof|Alignment requirement(C11)|
|3|* / %|Multiplication, division, and remainder|Left-to-right|
|4|+ -|Addition and subtraction|
|5|<< >>|Bitwise left shift and right shift|
|6|< <=|For relational operators < and ≤ respectively|
|> >=|For relational operators > and ≥ respectively|
|7|== !=|For relational = and ≠ respectively|
|8|&|Bitwise AND|
|9|^|Bitwise XOR (exclusive or)|
|10|||Bitwise OR (inclusive or)|
|11|&&|Logical AND|
|12||||Logical OR|
|13[note 2]|?:|Ternary conditional[note 3]|Right-to-Left|
|14|=|Simple assignment|
|+= -=|Assignment by sum and difference|
|*= /= %=|Assignment by product, quotient, and remainder|
|<<= >>=|Assignment by bitwise left shift and right shift|
|&= ^= |=|Assignment by bitwise AND, XOR, and OR|
|15|,|Comma|Left-to-right|

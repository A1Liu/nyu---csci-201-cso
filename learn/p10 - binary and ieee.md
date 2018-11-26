## Data Representation

#### Binary, Decimal, and Hexadecimal
Binary is base 2, Decimal is base 10, and hexadecimal is base 16 (hexadecimal uses letters to represent 11-15). Memory addresses are represented using hexadecimal numbers, and use the prefix `0x`, i.e. `0x11f2a3`.

#### Bits and Bytes
Bits are singular 'switches'. Bytes are 8 bits. Addresses in memory refer to locations of bytes.

#### Big and Little Endian
* Big Endian - **Most significant byte** has the **lowest address**
* Little Endian - **Least significant byte** has the **lowest address**

So for example, if we stored the number `0x01234567` at address `0x100`,

![endians](/assets/big_little_endian.png)

Note: the bit order within each byte is unaffected, as is the order of everything outside of that specific piece of data. Endian notation is *byte* order within *singular integral datatypes* (i.e. int, long, char, short).

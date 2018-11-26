## The `mov` Instruction
The `mov` instruction moves information from a source to a destination.

#### Basic Syntax and Example
The basic format is this
```
movq <source>,<dest>
```
where `<source>` and `<dest>` are the source and destination of the information being moved. For example,
```
movq $23,%rax
```
where `$23` is the source and `%rax` is the destination. In this case, we're changing the value of `%rax` to `23`. You can also move information from one register to another:
```
movq %rax,%rdx
```
Here, we're moving the data stored in the register `%rax` into the register `%rdx`.

#### The Memory Accessor
If we want to treat the information stored in a register as a *location in memory*, we use `(parentheses)`:
```
movq %rax,(%rdx)
```
In this case, the data stored in `%rax` is being stored in *memory*, at the *address* specified by the register. We could also do the opposite:
```
movq (%rax),%rdx
```
And then the data stored at the *address in memory* represented by `%rax` would be stored in `%rdx`. A few more examples with C code, as well as another explanation, can be found [here][short-explanation].

**NOTE**: There is no memory to memory operation; that is, `movq (%rax),(%rdx)` is illegal. See [this post][mem-to-mem] for more details.

#### Suffixes
<!-- TODO This stuff  -->

C Declaration 	| Intel Data Type 	| Assembly code suffix 	| Size (bytes)
 --- 			| ---				| ---					| ---
Char 			| Byte 				| b 					| 1
Short 			| Word 				| w 					| 2
Int 			| Double Word 		| l 					| 4
Long 			| Quad Word 		| q 					| 8
Pointer 		| Quad Word 		| q 					| 8

#### `lea` for Address Operations


#### Special Cases




Document written using slides from Professor Zahran's CSCI 201 class.

[mem-to-mem]: https://stackoverflow.com/questions/11953352/why-ia32-does-not-allow-memory-to-memory-mov
[short-explanation]: https://stackoverflow.com/questions/4093572/mov-instructions-registers-confusion

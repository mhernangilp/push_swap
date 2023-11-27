<h1 align="center">
	🔄 push_swap
</h1>

<p align="center">
	<b><i>Because Swap_push isn’t as natural</i></b><br>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting._

	This project consists of coding a program that finds the lowest possible number of moves to
	sort a random list of integers using 2 stacks and a limited set of operations  

For more detailed information, look at the [**subject of this project**](https://github.com/mhernangilp/push_swap/blob/master/es.subject.pushSwap.pdf).


## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile, go to the program path and run:

```shell
$ make
```

**2. Executing the program**

To execute the program, run:

```C
$ ./push_swap $ARG
```

where `$ARG` is a space separated list of integers, e.g. `ARG="1 5 2 4 3"`


### Actions

**PUSH**

Take the first element at the top of one stack and put it at the top of the other; do nothing if the origin stack is empty.

* **`pa`** - top element of _stack b_ goes to top of _stack a_.
* **`pb`** - top element of _stack a_ goes to top of _stack b_.

**SWAP**

Swap the first 2 elements at the top of the stack; do nothing if there is only one or no elements.

* **`sa`** - swap  _stack a_.
* **`sb`** - swap  _stack b_.
* **`ss`** - `sa` and `sb` at the same time.

**ROTATE**

Shift up all elements of the stack by one; the first element becomes the last.

* **`ra`** - rotate stack a.
* **`rb`** - rotate stack b.
* **`rr`** - `ra` and `rb` at the same time.

**REVERSE ROTATE**

Shift down all elements of the stack by one; the last element becomes the first.

* **`rra`** - reverse rotate stack a.
* **`rrb`** - reverse rotate stack b.
* **`rrr`** - `rra` and `rrb` at the same time.


**USED ALGORITHM**

The algorithm I used is based on a modified version of radix sort. Instead of directly sorting the numbers,
this algorithm first determines the index indicating the position for each number.
It then converts these indices into binary form and employs a radix sort,
processing the binary representations from right to left.
This unique approach offers a novel perspective on sorting,
leveraging both positional index and binary manipulation for an efficient sorting mechanism.
   
 ## 📋 Testing

You can use this third party testers to fully test the project:

* [SimonCROS/push_swap_complexity_tester](https://github.com/SimonCROS/push_swap_tester)
* [laisarena/complete_push_swap_tester](https://github.com/laisarena/push_swap_tester)

And a useful to visualize the movements:

* [o-reo/push_swap_visualizaer](https://github.com/o-reo/push_swap_visualizer)

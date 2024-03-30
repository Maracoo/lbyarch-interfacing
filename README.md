# LBYARCH C-Assembly Interface

**Members:**
1. Teves, Hannah
2. Yu, Marco

## Project Specifications
This project requires the implementation of a kernel in both C programming language and x86-64 assembly language. The kernel's primary task is to compute the dot product of vector A and vector B and store the result in a variable named *sdot*.

**Input:** Scalar variable *n* (int) contains the length of the vector; Vectors A and B are both double-precision float. Scalar *sdot* is a double-precision float.

**Output:** Store the result in memory location *sdot*. Display the result for all versions of the kernel.

## Program Output
### 1. Debug Mode
**n = 2^20**
![Debug Mode 2^20](img\debug_20.png)

**n = 2^24**
![Debug Mode 2^24](img\debug_24.png)

**n = 2^28**
![Debug Mode 2^28](img\debug_28.png)

Comparing the performance of the C program and the x86-64 assembly kernels for vector sizes of 2^20, 2^24, and 2^28, we observed that both kernels achieved 100% correctness in calculating the dot product (sdot). However, significant differences were apparent in their average execution times. The x86-64 assembly kernel consistently outperformed the C program, demonstrating faster execution times across all vector sizes.

For the smallest vector size of 2^20, the average execution time difference was only 0.001067 seconds. However, as the vector size scaled up to 2^28, this difference increased to 0.355067 seconds. The performance gap between the two widened significantly as the vector size increased. This substantial time difference suggests that the x86-64 assembly kernel is more efficient in handling larger datasets.

### 2. Release Mode
**n = 2^20**
![Release Mode 2^20](img\release_20.png)

**n = 2^24**
![Release Mode 2^24](img\release_24.png)

**n = 2^28**
![Release Mode 2^28](img\release_28.png)

In contrast to the Debug mode, the C program outperforms the x86-64 assembly for the tested vector sizes: 2^20, 2^24, and 2^28. This can be observed by the increasing negative execution time difference from -0.000367 seconds to -0.281100 seconds as the vector size increased from 2^20 to 2^28. Despite this difference, the correctness of the dot product computation remained 100% accurate, producing the same result for both implementations.

## Analysis
The difference in performance between the C program and x86-64 assembly code can be attributed to the mode of execution used: Debug mode and Release mode.

In Debug mode, the assembly code demonstrates better performance due to its direct access to memory and CPU registers. This enables efficient optimizations to memory operations, resulting in a faster execution time. On the other hand, the C program depends on the compiler to access memory. As optimizations are disabled on debug mode, this leads to a less efficient program and slower execution.

In contrast, C outperforms assembly in Release mode. In this mode, the compiler applies various optimizations to the C code, significantly improving its performance. 

Therefore, the performance disparity between C and assembly code shows a trade-off between control and optimization. Assembly provides precise control over machine-level operations, but it's harder to use and needs a lot of expertise to make it efficient. However, C relies on compiler optimizations, which make it easier to write and understand while still being pretty fast.
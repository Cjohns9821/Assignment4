Running the recursive factorial and Fibonacci functions made the behavior of the call stack very visible. 
In the factorial implementation, each call printed a message when entering and exiting the function. 
This created a clear “stack growth and shrinkage” pattern: the function calls stacked deeper as n decreased, and then unwound in reverse order as each return completed. Because factorial only makes one recursive call per level, the stack grew linearly and predictably.

The Fibonacci function behaved very differently. 
Each call to fib(n) triggered two additional calls, causing the recursion depth to expand rapidly. 
Good grief all the way from x=1000 to x=1. 
It worked though!
Tracking current_depth and max_depth showed how quickly the stack reached deep levels even for moderate inputs like 20. 
The print statements revealed overlapping call paths and a much more chaotic call structure compared to factorial.

When running the intentional stack overflow demonstration, the program eventually crashed with a segmentation fault. 
This happened because the function repeatedly called itself without a base case, causing infinite stack growth. 
Each function call adds a stack frame containing parameters, local variables, and the return address. 
Without a stopping condition, these frames accumulate until the stack memory is exhausted.

Factorial and Fibonacci demonstrated very different recursion costs. 
Factorial grows the stack one frame per decrement of n, so factorial(10) produces exactly ten frames. 
Fibonacci, however, branches twice at every level, causing exponential growth. 
Even though the maximum depth is still tied to n, the total number of calls increases dramatically, and the stack becomes heavily utilized. 
This explains why Fibonacci recursion is expensive and why iterative versions are often preferred.

Python limits recursion depth to prevent exactly the kind of crash demonstrated in the overflow example. 
Without a recursion limit, a poorly written recursive function could consume all available stack memory and terminate the program. 
The limit acts as a safeguard, stopping runaway recursion before it reaches the operating system’s crash threshold.

Function pointers make callbacks possible by allowing functions to be passed as arguments. 
This lets code choose behavior dynamically instead of hard‑coding operations. 
In the array‑processing example, the same function could double, square, or negate values depending on which callback was provided. 
This pattern increases flexibility and reduces duplication because the core logic doesn’t need to change when the behavior changes.

Callback systems are widely used in real‑world programming. 
GUI frameworks rely on callbacks for event handling—button clicks, key presses, and window updates all trigger registered functions. 
Systems programmers use callbacks because they enable modular, extensible designs even though function pointers can be less readable. 
They allow low‑level code to remain generic while higher‑level logic defines specific behavior.
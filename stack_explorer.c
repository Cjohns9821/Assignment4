#include <stdio.h>

// ======================================================
// PART 1: BASIC RECURSION — FACTORIAL WITH STACK TRACING
// ======================================================

int factorial(int n) {
    printf("[factorial] called with n=%d\n", n);

    if (n <= 1) {
        printf("[factorial] returning 1 from n=%d\n", n);
        return 1;
    }

    int result = n * factorial(n - 1);

    printf("[factorial] returning %d from n=%d\n", result, n);
    return result;
}


// ======================================================
// PART 2: STACK DEPTH TRACKING — RECURSIVE FIBONACCI
// ======================================================

int current_depth = 0;
int max_depth = 0;

int fib(int n) {
    current_depth++;
    if (current_depth > max_depth)
        max_depth = current_depth;

    printf("[fib] n=%d depth=%d\n", n, current_depth);

    if (n <= 1) {
        current_depth--;
        return n;
    }

    int result = fib(n - 1) + fib(n - 2);

    current_depth--;
    return result;
}


// ======================================================
// PART 3: STACK OVERFLOW DEMONSTRATION
// ======================================================

// BAD VERSION — NO BASE CASE
void overflow() {
    int x = 1; // forces stack usage
    printf("overflow call, x=%d\n", x);
    overflow(); // infinite recursion → stack overflow
}

// FIXED VERSION
void overflow_fixed(int n) {
    if (n <= 0) return;

    int x = n;
    printf("overflow_fixed call, x=%d\n", x);
    overflow_fixed(n - 1);
}


// ======================================================
// PART 4: FUNCTION POINTERS & CALLBACKS
// ======================================================

int double_val(int x) { return x * 2; }
int square_val(int x) { return x * x; }
int negate_val(int x) { return -x; }

void process_array(int *arr, int size, int (*callback)(int)) {
    for (int i = 0; i < size; i++) {
        arr[i] = callback(arr[i]);
    }
}


// ======================================================
// PART 5: EVENT CALLBACK SYSTEM
// ======================================================

#define MAX_EVENTS 10
void (*event_callbacks[MAX_EVENTS])(void);
int event_count = 0;

void register_event(void (*cb)(void)) {
    if (event_count < MAX_EVENTS) {
        event_callbacks[event_count++] = cb;
    }
}

void fire_events() {
    for (int i = 0; i < event_count; i++) {
        event_callbacks[i]();
    }
}

void on_start() { printf("Event: start triggered!\n"); }
void on_finish() { printf("Event: finish triggered!\n"); }


// ======================================================
// MAIN — RUN ALL TESTS
// ======================================================

int main() {

    // PART 1 — FACTORIAL
    printf("=== FACTORIAL TEST ===\n");
    int f5 = factorial(5);
    printf("factorial(5) = %d\n", f5);

    int f10 = factorial(10);
    printf("factorial(10) = %d\n", f10);


    // PART 2 — FIBONACCI
    printf("\n=== FIBONACCI TEST ===\n");
    current_depth = 0;
    max_depth = 0;

    int f20 = fib(20);
    printf("fib(20) = %d\n", f20);
    printf("Max recursion depth reached: %d\n", max_depth);


    // PART 3 — STACK OVERFLOW
    // Uncomment to observe crash:
    // overflow();

    printf("\n=== FIXED OVERFLOW ===\n");
    overflow_fixed(1000);


    // PART 4 — CALLBACK ARRAY PROCESSOR
    printf("\n=== CALLBACK PROCESSOR ===\n");
    int nums[5] = {1, 2, 3, 4, 5};

    process_array(nums, 5, double_val);
    process_array(nums, 5, square_val);
    process_array(nums, 5, negate_val);

    printf("Processed array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");


    // PART 5 — EVENT SYSTEM
    printf("\n=== EVENT SYSTEM ===\n");
    register_event(on_start);
    register_event(on_finish);
    fire_events();

    return 0;
}

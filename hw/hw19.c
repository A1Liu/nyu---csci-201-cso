// Assume a program requires a billion memory references be executed.
//Assume every memory reference takes 0.1 microseconds to execute providing
//the reference page is memory resident. Assume each page fault takes an additional 10 milliseconds to service.
//
// If the program is completely resident, how long does it take to execute all billion memory references?

1e+9 * .1 * 1e-6 = 1e+3 * .1 = 1e+2 seconds
100 seconds

// If 0.1% of the memory references cause a page fault, how long
//does the program take to execute all the memory references and
//what percentage of that time is the program waiting for a page fault to complete?

100 * .999 = 99.9 seconds for non-page fault memory references
1e+9 * .001 (%page fault) * .01 (seconds/fault) = 1e+4 seconds due to page fault memory references
100 * .001 = .1 seconds for page fault memory references (before the page fault)

Combined:
99.9 + .1 + 10000 = 10100 secnds
% Time spent waiting for page fault to complete:
10000 / 10100 = .990099... = 99.0099... % of time spent waiting for page fault to complete

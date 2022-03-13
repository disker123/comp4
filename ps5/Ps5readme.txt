/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name:Greg Kaplowitz

Hours to complete assignment:5

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg�s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/

used the matrix method 



/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input:
atattat
tattata

Expected output:

What happened:
distance = 4
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2



/**********************************************************************
 * Look at your computer�s specs in the settings and find the total 
 * amount of RAM. Place it below. 
 **********************************************************************/
16GB


/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 4
b = 
largest N =
4*N^b=8,000,000,000

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you�re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************
==4324== HEAP SUMMARY:
==4324==     in use at exit: 0 bytes in 0 blocks
==4324==   total heap usage: 45 allocs, 45 frees, 76,630 bytes allocated
==4324== 
==4324== All heap blocks were freed -- no leaks are possible
==4324== 
==4324== For counts of detected and suppressed errors, rerun with: -v
==4324== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)



/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt		128		57.8		82,295,087 bytes	
ecoli5000.txt		144		145.4		134,617,748 bytes
ecoli7000.txt		144		147.8		134,617,748 bytes
ecoli10000.txt		144		174.9		134,617,748 bytes
ecoli20000.txt:my VB crashes at 20000
ecoli28284.txt:still crashes

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 
b = 
largest N = 
123,015,493,370.24
/
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/




**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/



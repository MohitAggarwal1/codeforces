<h2><a href="https://codeforces.com/contest/2207/problem/H2" target="_blank" rel="noopener noreferrer">2207H2 — Bowser's Castle (Medium Version)</a></h2>

| | |
|---|---|
| **Difficulty** | 3500 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2207H2](https://codeforces.com/contest/2207/problem/H2) |

## Topics
`constructive algorithms` `divide and conquer` `interactive` `trees` `two pointers`

---

## Problem Statement

<div class="header"><div class="title">H2. Bowser's Castle (Medium Version)</div><div class="time-limit"><div class="property-title">time limit per test</div>8 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>     </p><center><table class="tex-tabular bordertable"><tbody><tr><td class="tex-tabular-text-align-center tex-tabular-border-top tex-tabular-border-bottom"><span class="tex-font-size-small"><span class="tex-font-style-it"> <a href="https://www.youtube.com/watch?v=HCTQHn6Tk1o"> Bowser's Castle Corridor — Shiho Fujii, Ryo Nagamatsu, New Super Mario Bros. Wii </a></span></span></td></tr></tbody></table></center><center> <table class="tex-tabular bordertable"><tbody><tr><td class="tex-tabular-text-align-center"><img class="tex-graphics" src="https://espresso.codeforces.com/20b5e18257ef6199363595c78fee6e662c214d3e.png" style="max-width: 100.0%;max-height: 100.0%;"></td></tr></tbody></table> </center><p><span class="tex-font-style-bf">This is the medium version of the problem. The difference between the versions is that in this version, $$$n \leq 200$$$ and you may make $$$10^4$$$ queries. You can hack only if you solved all versions of this problem.</span> </p><p><span class="tex-font-style-it">This is an interactive problem.</span> </p><p>Let $$$n$$$ be a positive integer. A function on $$$n$$$ variables $$$x_1, \ldots, x_n$$$ is called <span class="tex-font-style-it">min-max</span> if it can be constructed as writing only $$$\min$$$ and $$$\max$$$ calls around $$$x_1, \ldots, x_n$$$ with each variable appearing exactly once in order from left to right in the expression. For example, $$$\min(x_1, x_2, x_3)$$$ is a min-max function on $$$3$$$ variables, but $$$\max(\min(x_1, x_3), x_2)$$$ and $$$\min(\max(x_1, x_2), \max(x_2, x_3))$$$ are not.</p><p>Bowser has chosen a min-max function on $$$n$$$ ($$$2 \leq n \leq 200$$$) variables and tells you $$$n$$$. Additionally, he lets you ask queries of the following form: you give Bowser $$$n$$$ integers $$$x_1, \ldots, x_n$$$ ($$$1 \leq x_i \leq 10^9$$$) as input, and he tells you $$$f(x_1, \ldots, x_n)$$$.</p><p>To escape his castle, you have to deduce his function using at most $$$10^4$$$ queries in total. After that, to prove to him that you have learned the function, Bowser will give you up to $$$5000$$$ of his own inputs $$$x_1, \ldots, x_n$$$, to which you must respond with the correct value of $$$f(x_1, \ldots, x_n)$$$.</p><p>Since Bowser's castle is very secure, he actually has multiple functions for you to figure out, with a total variable count of at most $$$200$$$. Additionally, he constrains that you use at most $$$10^4$$$ queries across all of the functions and that he will also not ask more than $$$5000$$$ queries in total.</p></div><div class="input-specification"><div class="section-title">Input</div><p>Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 100$$$). The description of the test cases follows. </p><p>The first line of each test case contains a single integer $$$n$$$ ($$$2 \leq n \leq 200$$$) — the number of variables in the min-max function.</p><p>It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$200$$$. </p><p>After you read this line of input, the interaction begins with your first query.</p></div><div><div class="section-title">Interaction</div><p>To make a query, output a line (without quotes) in the following format:</p><ul> <li> "<span class="tex-font-style-tt">? $$$x_1$$$ $$$x_2$$$ $$$\ldots$$$ $$$x_n$$$</span>" ($$$1 \leq x_i \leq 10^9$$$). </li></ul><p>Then, after each query, read a single integer — the answer to your query. You can make up to $$$10^4$$$ queries of this type <span class="tex-font-style-bf">in total across all $$$t$$$ test cases.</span></p><p>Once you are ready to begin answering Bowser's queries, output a line containing a single character "<span class="tex-font-style-tt">!</span>" (without quotes).</p><p>Each of Bowser's queries contains a single line of $$$n$$$ integers $$$x_1, x_2, \ldots, x_n$$$ ($$$1 \leq x_i \leq 10^9$$$) — Bowser's input. It is guaranteed that Bowser will not make more than $$$5000$$$ queries <span class="tex-font-style-bf">in total across all $$$t$$$ test cases.</span></p><p>After each query, output a single integer — the value of $$$f(x_1, x_2, \ldots, x_n)$$$. Note that these queries are <span class="tex-font-style-bf">online</span>, so Bowser will only provide you the next query after you respond to his previous query.</p><p>Once Bowser is done asking queries, you will receive a single line containing the integer $$$0$$$. After this, proceed to the next test case or exit if this is the last test case.</p><p>The interactor in this task is <span class="tex-font-style-bf">partially adaptive</span>. In particular, the functions Bowser chooses are fixed at the beginning of each interaction, but his queries to you may change.</p><p>After printing each query do not forget to output the end of line and flush$$$^{\text{∗}}$$$ the output. Otherwise, you will get <span class="tex-font-style-tt">Idleness limit exceeded</span> verdict. If, at any interaction step, you read $$$-1$$$ instead of valid data, your solution must exit immediately. This means that your solution will reveive <span class="tex-font-style-tt">Wrong answer</span> because of an invalid query or any other mistake. Failing to exit can result in an arbitrary verdict because your solution will continue to read from a closed stream. </p><p> <span class="tex-font-style-bf"><span><span class="tex-font-style-sf">Hacks</span></span></span>  </p><p>To hack, use the following format.</p><p>The first line should contain a single integer $$$t$$$ ($$$1 \leq t \leq 100$$$) — the number of test cases.</p><p>The first line of each test case should contain a single integer $$$n$$$ ($$$2 \leq n \leq 200$$$) — the number of variables in the min-max function.</p><p>The second line of each test case should contain a series of space-separated tokens (without quotes) from the following list, specifying the min-max function: </p><ul> <li> "<span class="tex-font-style-tt">min</span>" </li><li> "<span class="tex-font-style-tt">max</span>" </li><li> "<span class="tex-font-style-tt">(</span>" </li><li> "<span class="tex-font-style-tt">)</span>" </li><li> "," </li><li> positive integers in the range $$$1, 2, \ldots, n$$$. </li></ul><p>The sum of $$$n$$$ over all test cases should not exceed $$$200$$$.</p><p>For instance, the hack case corresponding to the example input is as follows:</p><pre class="lstlisting"><code class="prettyprint prettyprinted" style=""><span class="lit">2</span><br><span class="lit">3</span><br><span class="pln">max </span><span class="pun">(</span><span class="pln"> </span><span class="lit">1</span><span class="pln"> </span><span class="pun">,</span><span class="pln"> </span><span class="lit">2</span><span class="pln"> </span><span class="pun">,</span><span class="pln"> </span><span class="lit">3</span><span class="pln"> </span><span class="pun">)</span><br><span class="lit">4</span><br><span class="pln">min </span><span class="pun">(</span><span class="pln"> max </span><span class="pun">(</span><span class="pln"> </span><span class="lit">1</span><span class="pln"> </span><span class="pun">,</span><span class="pln"> </span><span class="lit">2</span><span class="pln"> </span><span class="pun">)</span><span class="pln"> </span><span class="pun">,</span><span class="pln"> max </span><span class="pun">(</span><span class="pln"> </span><span class="lit">3</span><span class="pln"> </span><span class="pun">,</span><span class="pln"> </span><span class="lit">4</span><span class="pln"> </span><span class="pun">)</span><span class="pln"> </span><span class="pun">)</span><br></code></pre><div class="statement-footnote"><p>$$$^{\text{∗}}$$$To flush, use: </p><ul> <li> <span class="tex-font-style-tt">fflush(stdout)</span> or <span class="tex-font-style-tt">cout.flush()</span> in C++; </li><li> <span class="tex-font-style-tt">sys.stdout.flush()</span> in Python; </li><li> see the documentation for other languages. </li></ul></div></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id008626563234796507" id="id008545741719506356" class="input-output-copier">Copy</div></div><pre id="id008626563234796507">2
3

5

2

3 6 2

3 5 7

0
4

8

3

8 7 6 5

0
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0021244189700547822" id="id0011074293890463949" class="input-output-copier">Copy</div></div><pre id="id0021244189700547822">

? 5 4 3

? 1 2 1

!

6

7


? 1 9 8 7

? 5 1000000000 2 3

!

6
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test case, Bowser's min-max function is $$$f := \max(x_1, x_2, x_3)$$$. After asking two queries to receive $$$f(5, 4, 3) = 5$$$ and $$$f(1, 2, 1) = 2$$$ from the jury, the solution is ready to answer the jury's queries. It correctly deduces that $$$f(3, 6, 2) = 6$$$ and $$$f(3, 5, 7) = 7$$$.</p><p>In the second test case, Bowser's min-max function is $$$f := \min(\max(x_1, x_2), \max(x_3, x_4))$$$. After asking two queries to receive $$$f(1, 9, 8, 7) = 8$$$ and $$$f(5, 10^9, 2, 3) = 3$$$ from the jury, the solution is ready to answer the jury's queries. It correctly deduces that $$$f(8, 7, 6, 5) = 6$$$.</p><p>Note that it is not guaranteed that the queries in the example uniquely determine the min-max function. The example is there only to demonstrate how the queries work. Empty lines in the example input and output are given only for better readability; you don't need to output them in your solution.</p></div>
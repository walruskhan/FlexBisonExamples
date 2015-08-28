<h1>01_simple_lexer</h1>
<p>A simple program that shows calling a lexer from a separate program. This program writes to and reads from
files on the disk, although these can easily be replaced by stdin/stdout for testing purposes.</p>
<p style="font-family: monospace; margin-top: 0px; color: green;">
$> ./SimpleLexer<br>
hello world<br>
&lt;response&gt;
</p>

<p>This chapter demonstrates the use of 'simple.l', a simple lex script<br></p>
The files in this project can be run on the command line via:</p>
<p style="font-family: monospace; margin-top: 0px; color: green;">
$> lex -d simple.l -o simple_scanner.c<br>
$> cc main.cpp simple_scanner.c -DUSE_FILES -o SimpleLexer<br>
$> ./SimpleLexer<br>
</p>
<p>The '-DUSE_FILES' flag simply defines the macro USE_FILES, which makes main.cpp read and write to files rather
than using stdin/stdout. If you omit this flag, you may use the program interactively.</p>
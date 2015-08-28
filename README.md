<h1>Flex / Bison Examples</h1>
<p>This repository contains a bunch of increasingly complex examples of programs written using lex/yacc
to do things such as implement a calculator or parse a file.</p>
<blink id="blinks_are_cool" style="color: red;">OBLIGATORY THIS IS A LEARNING EXERCISE FOR MYSELF WARNING</blink>
<p>More information can be found at the following websites:</p>
<ul>
    <li><a href='https://github.com/jengelsma/lex-tutorial'>jenglesma lex-tutorial Repository on Github - also contains a link to his Youtube video</a></li>
    <li><a href='http://luv.asn.au/overheads/lex_yacc/yacc.html'>A Yacc Tutorial, showcasing parsing of a typical configuration file</a></li>
</ul>

<br>
<p>This repository is divided up into various chapters, the chapters are described below</p>
<table>
    <tr>
        <td>Folder name</td>
        <td>Description</td>
    </tr>
    <tr>
        <td>01_simple_lexer</td>
        <td>A project with just a lex file. Used to show a very simple method of generating a token stream from an input.</td>
    </tr>
</table>

<h2>Building the examples</h2>
<p>This project uses CMake to create build files for a variety of platforms. CMake lets us generate projects
that can build 'out-of-source'. e.g. Rather than clutter up your nice, clean copy of the repository with various
junk as part of the compilation process. You can simply create an empty build directory, generate a build file
inside that directory and then build the project from there.<br>
Ensure you have cmake and flex/yacc installed on your system then run:</p>
<p style="font-family: monospace; margin-top: 0px; color: green;">
$> cd ~/home/greg/Desktop<br>
$> git clone <address_of_this_repository><br>
$> mkdir build<br>
$> cd build<br>
$> pwd<br>
~/home/greg/Desktop/build<br>
$> cmake -G "Unix Makefiles" ../FlexBisonExamples/CMakeLists.txt<br>
$> make Makefile<br>
$> ./01_simple_lexer/SimpleLexer<br>
</p>

<p>Options are also available to produce build files for popular IDE's such as Visual Studio, Eclipse, Xcode and code::blocks.
But outrageously funny and good looking people like us use the terminal :)</p>

<h2>Lex (Flex)</h2>
<ul>
    <li>Lex is a scanner generator</li>
    <ul>
        <li>Input is a lex file with extension *.l (the letter L)</li>
        <li>Output is a table-driven scanner (lex.yy.c)</li>
        <li>Flex is an open-source implementation of the original lex utility</li>
    </ul>
    
    <p>Generating, compiling and running a lex script</p>
    <p style="font-family: monospace; margin-top: 0px; color: green;">
    $> lex mylexfile.l && cc lex.yy.c -ll && ./a.out
    </p>
    
    <p>A lex file has the following layout:</p>
    <p style="font-family: monospace; margin-top: 0px; color: green;">
        /* preamble section */<br>
        %{<br>
            /* This section is copied to beginning of the generated file verbatim. c-code goes in here */<br>
            /* Often used to include headers, add function declarations etc */<br>
        %}<br>
        <br>
        %%<br>
        <br>
        /* Patterns section */<br>
        /* a list of patterns and associated actions */<br>
        REGEX_PATTERN&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;{ c-code }<br>
        <br>
        %%<br>
        <br>
        /* an optional post-amble section used for implementing function definitions */<br>
        /* This section is copied verbatim to the generated output files */<br>
    </p>
</ul>
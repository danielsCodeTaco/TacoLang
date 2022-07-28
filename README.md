# How to run a file from the interpreter
What you will need:
- Path to your code file (example: <code>C:\code\HelloWorld.taco</code>)
- The compiled interpreter (for the example command it will be named "interpreter.exe")
- Command Prompt/Terminal

1. Open your command prompt/terminal and type <code>interpreter.exe [path-to-file]</code> (<code>[path-to-file]</code> as the actual path to the code file of course)
2. That's all!

**OR**

1. Click and drag your file onto the interpreter

# Hello, World!
1. Make a new file named "HelloWorld.taco" anywhere
2. Open it in any text editor
3. Type <code>show:Hello, World!</code> and save the file
4. Run the interpreter with the command in the above section
<br>
The code outputs "Hello, World!"

# Variables, concatenating, and new lines
If you would like to make a variable you'd use the "var:" command.
<br>
To use the "var:" command you first type "var:", the variable's name (case sensitive and whitespace sensitive), a comma, and then the value of the variable.
<br>
Example code for creating variables and then cobcatenating their values together and changing one variable:
<br>
```
var:number,5       -- Creates the number variable and sets it to 5
var:greeting,hello -- Creates the greeting variable and sets it to hello
show:number        -- Shows the number variable's value
show:,             -- Puts ", " between
show:greeting      -- Shows the greeting variable's value
var:greeting,hi    -- Changes the greeting variable's value to "hi"
show:newLine       -- Shows a new line
show:greeting      -- Shows the new value of greeting
```

# Math
I will only show an example for addition as all math commands are used the same (add, subract, multiply, divide, sin, cos, tan, power, and sqrt (sqrt, sin, cos, and tan only take one argument though))
<br>
Example for adding one variable and one number together:
<br>
```
var:a,5   -- Creates the a variable and sets it to 5</code>
add:b,a.2 -- Creates the b variable and sets it to the a variable's value + 2</code>
show:b    -- Shows the b variable's value</code>
```

# Input
To use the "input:" command you type "input:", your variable's name, then a comma, and then a prompt
<br>
Example:
<br>
```
show:What's Your name? -- Says "What's your name? "
input:name,            -- Creates the variable "name" and sets it to what the user types
show:Hello,            -- Says "Hello, "
show:name              -- Says the value of the "name" variable
show:!                 -- Says "!"
```

Typescript basics

check what is typscript card

## getting started

typescript extends javascript by adding data types , classes and other oops features with type checking
\*\*\* for interview prep check application learn typescript
typescript has a definition file with .d.ts extension to provide a definition for external javascript libraries

typescript file extension .ts
command ts filename.ts

features :-
cross platform
object oriented language
static type-checking
optional static typing
dom mainpulation
ES6 features

Advantages
Typescript is also closer in syntax to backend languages like java and scala
typescript definition files , with .d.ts extension, provides support for existing Javascript libraries like Jquery,D3.js etc.
So, typescript code can add Javascript libraries using type definitions to avail the benefits of type-checking, code autocompletion and documentation in existing dynamically-typed Javascript libraries
Typescript has easy integration with task runner like Grunt and Gulp to automate workflow.

$ webstorm code editors

# setup

nodejs on which we run typescript compiler
typescript compiler :- a nodejs module that compiletypescript into javascript (ts-node).
It is a typescript execution and REPL for node.js

Live server allows us to launch development server local with hot reload feature

# what is hot reload?

npm install -g Typescript (install typescript compiler)
tsc -v

tsc filename.ts (convert typescript code to javascript)

#info :- 'tsc' is not recognized as internal :- it means we have not added npm path

npm install -g ts-node
ts-node filename.ts (completely compile typescript and then run file)

check quokka vs code extension to check output

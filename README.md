## Introduction 
                                  +-------+
                        Source -> |  Lex  |  -> yylex
                                  +-------+

                                  +-------+
                        Input ->  | yylex | -> Output
                                  +-------+
                              An overview of Lex
                            
* This repository contains components of a compiler in order to learn the basics of compilers
* Some codes are real implimentations of video tutorials and [stanford online course](https://www.coursera.org/course/compilers)
                              
                        lexical        grammar
                         rules          rules
                           |              |
                           v              v
                      +---------+    +---------+
                      |   Lex   |    |  Yacc   |
                      +---------+    +---------+
                           |              |
                           v              v
                      +---------+    +---------+
             Input -> |  yylex  | -> | yyparse | -> Parsed input
                      +---------+    +---------+


                            Lex with Yacc
                            
## Tools and Softwares
* I have used [lex](http://flex.sourceforge.net/)/[flex](http://dinosaur.compilertools.net/) for build scanner/lexical analizer and [YACC](http://dinosaur.compilertools.net/yacc/index.html)/BISON for syntax parsing

## Usage
* Clone the repository and go through the source before run
* Some may have precompiled bineries

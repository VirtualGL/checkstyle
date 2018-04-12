
/*
 * Training file for VirtualGL Style Checker
 *
 * Copyright (C)2018 D. R. Commander.  All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of The VirtualGL Project nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS",
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


/********** DETECTING WHITESPACE ERRORS **********/

/*--------- Stray tab characters ---------*/
	something;	something;  /* hit */
	something;  something;  /* miss */

/*--------- Spaces used for indentation ---------*/
  something;  ### hit ###
	something;  ### miss ###

/*--------- Alt-Space ---------*/
	   /* hit */
	   /* miss */

/*--------- Blank line(s) at top of file ---------*/
	/* See above */

/*--------- General whitespace errors ---------*/
	/* Should hit on "new blank line at EOF" */


/********** DETECTING INCORRECT COMMENT FORMATTING **********/
something;// hit
something; // hit
something;  // miss [hit on C++ comments]
something;/* hit */
something; /* hit */
something;  /* miss */


/********** DETECTING BAD LINE CONTINUATION SPACING **********/
#define something()  /* hit */  \
	something;
#define something()  /* hit */\
	something;
#define something()  /* miss */ \
	something;
  \  /* hit */
	\  /* miss */

/********** DETECTING ATTACHED else/catch **********/
} else(something_else)  /* hit */
else(something_else)  /* miss */

} catch(something)  /* hit */
catch(something)  /* miss */


/********** DETECTING INCORRECT BRACKET SPACING **********/

/*--------- Attached bracket ---------*/
if(something) {  /* hit */
if(something)  /* miss */

/*--------- Other issues ---------*/

{something;  /* hit */
{  something;  /* hit */
{ something;  /* hit */
	{something;  /* hit */
	{ something;  /* hit */
something;}  /* hit */
something;  }  /* hit */
{something;}  /* hit */
{  something;  }  /* hit */
}something  /* hit */
} something  /* miss */


/********** DETECTING INCORRECT STATEMENT SPACING **********/
if ()  /* hit */
if()  /* miss */
for ()  /* hit */
for()  /* miss */
catch ()  /* hit */
catch()  /* miss */
while ()  /* hit */
while()  /* miss */
do ()  /* hit */
do()  /* miss */
switch ()  /* hit */
switch()  /* miss */
do_stuff; do_other_stuff;  ### hit ###
do_stuff;  do_other_stuff;  ### miss ###
delete[]  /* hit */
delete []  /* miss */


/********** DETECTING INCORRECT FUNCTION/TYPE CAST SPACING **********/
	(type*)hello  /* hit */
	(type *)hello  /* miss */
	(type**)hello  /* hit */
	(type **)hello  /* miss */
	(type) var  ### hit ###
	(type)var  ### miss ###
(type) var  ### hit ###
(type)var  ### miss ###
something + (type) var  ### hit ###
something + (type)var  ### miss ###
	return (type) var  ### hit ###
	return (type)var  ### miss ###
	((type) var  ### hit ###
	((type)var  ### miss ###
((type) var  ### hit ###
((type)var  ### miss ###
return ((type) var  ### hit ###
return ((type)var  ### miss ###
(type) (var)  ### hit ###
(type)(var)  ### miss ###


/********** DETECTING INCORRECT MACRO SPACING **********/
#define macro \
something;  /* hit */

#define macro
	something;  /* miss */ \

#define macro \
	something;  /* miss */

#define macro(a, b) something  /* hit */
#define macro(a, b)   something  /* hit */
#define macro(a, b)  something  /* miss */
#define macro(a, b) \  /* miss */

#define  macro  something  /* hit */
#define macro something  /* hit */
#define macro   something  /* hit */
#define macro  something  /* miss */


/********** DETECTING INCORRECT COMMA SPACING **********/
comma,comma,down,doobie,doo,down,down,comma,comma  ### hit ###
comma ,comma ,down ,doobie ,doo ,down ,down ,comma ,comma  ### hit ###
comma, comma, down, doobie, doo, down, down, comma, comma  ### miss ###


/********** DETECTING INCORRECT OPERATOR SPACING **********/

/*--------- Incorrect pointer operator spacing ---------*/
char* something;  ### hit ###
char *something;  ### miss ###

/*--------- Incorrect address operator spacing ---------*/
char& something;  ### hit ###
char &something;  ### miss ###

/*--------- No space before other operators ---------*/
something=  ### hit ###
something =  ### miss ###
(something)=  ### hit ###
(something) =  ### miss ###
something[something]=  ### hit ###
something[something] =  ### miss ###

something+=  ### hit ###
something +=  ### miss ###

something-=  ### hit ###
something -=  ### miss ###

something*=  ### hit ###
something *=  ### miss ###

something/=  ### hit ###
something /=  ### miss ###

something%=  ### hit ###
something %=  ### miss ###

something&=  ### hit ###
something &=  ### miss ###

something|=  ### hit ###
something |=  ### miss ###

something^=  ### hit ###
something ^=  ### miss ###

something<<=  ### hit ###
something <<=  ### miss ###

something>>=  ### hit ###
something >>=  ### miss ###

something+  ### hit ###
something++  ### miss ###
something +  ### miss ###

something-  ### hit ###
something--  ### miss ###
something -  ### miss ###

something*  ### hit ###
something *  ### miss ###

something/  ### hit ###
something /  ### miss ###

something%  ### hit ###
something %  ### miss ###

something==  ### hit ###
something ==  ### miss ###

something!=  ### hit ###
something !=  ### miss ###

something>  ### hit ###
something >  ### miss ###

something<  ### hit ###
something <  ### miss ###

something>=  ### hit ###
something >=  ### miss ###

something<=  ### hit ###
something <=  ### miss ###

something&&  ### hit ###
something &&  ### miss ###

something||  ### hit ###
something ||  ### miss ###

something&  ### hit ###
something &  ### miss ###

something|  ### hit ###
something |  ### miss ###

something^  ### hit ###
something ^  ### miss ###

something<<  ### hit ###
something <<  ### miss ###

something>>  ### hit ###
something >>  ### miss ###

something? something: something  ### hit ###
something ? something : something  ### miss ###

/*--------- No space after other operators ---------*/
=something  ### hit ###
= something  ### miss [hit on operator continuance] ###
=(something)  ### hit ###
= (something)  ### miss [hit on operator continuance] ###

+=something  ### hit ###
+= something  ### miss [hit on operator continuance] ###

-=something  ### hit ###
-= something  ### miss [hit on operator continuance] ###

*=something  ### hit ###
*= something  ### miss [hit on operator continuance] ###

&=something  ### hit ###
&= something  ### miss [hit on operator continuance] ###

%=something  ### hit ###
%= something  ### miss [hit on operator continuance] ###

/=something  ### hit ###
/= something  ### miss [hit on operator continuance] ###

|=something  ### hit ###
|= something  ### miss [hit on operator continuance] ###

^=something  ### hit ###
^= something  ### miss [hit on operator continuance] ###

<<=something  ### hit ###
<<= something  ### miss [hit on operator continuance] ###

>>=something  ### hit ###
>>= something  ### miss [hit on operator continuance] ###

+something  ### hit ###
++something  ### miss ###
+ something  ### miss [hit on operator continuance] ###

-something  ### miss [can't check because indistinguishable from unary -][hit on operator continuance] ###
--something  ### miss ###
- something  ### miss [hit on operator continuance] ###

*something  ### miss [can't check because indistinguishable from pointer][hit on operator continuance] ###
* something  ### miss [hit on operator continuance] ###

/something  ### hit ###
/ something  ### miss [hit on operator continuance] ###

%something  ### hit ###
% something  ### miss [hit on operator continuance] ###

==something  ### hit ###
== something  ### miss ###

!=something  ### hit ###
!= something  ### miss ###

>something  ### hit ###
> something  ### miss ###

<something  ### hit ###
< something  ### miss ###

>=something  ### hit ###
>= something  ### miss ###

<=something  ### hit ###
<= something  ### miss ###

&&something  ### hit ###
&& something  ### miss ###

||something  ### hit ###
|| something  ### miss ###

|something  ### hit ###
| something  ### miss [hit on operator continuance] ###

^something  ### hit ###
^ something  ### miss [hit on operator continuance] ###

<<something  ### hit ###
<< something  ### miss [hit on operator continuance] ###

>>something  ### hit ###
>> something  ### miss [hit on operator continuance] ###

&something  ### miss [can't check because indistinguishable from address][hit on operator continuance] ###
& something  ### miss [hit on operator continuance] ###

something ?something :something  ### hit ###
something ? something : something  ### miss ###

/*--------- [!|~] something ---------*/
! something  /* hit */
!something  /* miss */

~ something  /* hit */
~something  /* miss */


/********** DETECTING INCORRECT OPERATOR CONTINUANCE **********/
### miss ###  something =
### miss ###  something +=
### miss ###  something -=
### miss ###  something *=
### miss ###  something /=
### miss ###  something %=
### miss ###  something &=
### miss ###  something |=
### miss ###  something ^=
### miss ###  something <<=
### miss ###  something >>=
### miss ###  something +
### miss ###  something -
### miss ###  something *
### miss ###  something /
### miss ###  something %
### miss ###  something &
### miss ###  something |
### miss ###  something ^
### miss ###  something <<
### miss ###  something >>

### hit ###  something ==
### hit ###  something !=
### hit ###  something >
### hit ###  something <
### hit ###  something >=
### hit ###  something <=
### hit ###  something &&
### hit ###  something ||

? something  ### hit ###
### miss ###  something ?
: something  ### hit ###
### miss ###  something :


/********** DETECTING INCORRECT FUNCTION SPACING **********/
	something (args)  ### hit ###
	something(args)  ### miss ###


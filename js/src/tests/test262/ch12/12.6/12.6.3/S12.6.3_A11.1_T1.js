// Copyright 2009 the Sputnik authors.  All rights reserved.
// This code is governed by the BSD license found in the LICENSE file.

/**
 * If (Evaluate Statement).type is "continue" and (Evaluate Statement).target is in the current label set, iteration of labeled "var-loop" breaks
 *
 * @path ch12/12.6/12.6.3/S12.6.3_A11.1_T1.js
 * @description Using "continue" in order to continue a loop
 */

__str=""

for(var index=0; index<10; index+=1) {
	if (index<5)continue;
	__str+=index;
}

if (__str!=="56789") {
	$ERROR('#1: __str === "56789". Actual:  __str ==='+ __str  );
}


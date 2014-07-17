/*
 *	CTTypesetter.h
 *	CoreText
 *
 *	Copyright (c) 2003-2007 Apple Inc. All rights reserved.
 *
 */

#ifndef __CTTYPESETTER__
#define __CTTYPESETTER__

#include <CoreText/CTLine.h>

#if defined(__cplusplus)
extern "C" {
#endif

/* --------------------------------------------------------------------------- */
/* Typesetter Types */
/* --------------------------------------------------------------------------- */

typedef const struct __CTTypesetter * CTTypesetterRef;


/*!
	@function	CTTypesetterGetTypeID
	@abstract	Returns the CFType of the typesetter object
*/

CFTypeID CTTypesetterGetTypeID( void ) AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;


/* --------------------------------------------------------------------------- */
/* Typesetter Values */
/* --------------------------------------------------------------------------- */

/*!
	@const		kCTTypesetterOptionDisableBidiProcessing
	@abstract	Disables bidi processing.
	@discussion	Value must be a CFBooleanRef. Default is false.
				Normally, typesetting applies the Unicode Bidirectional
				Algorithm as described in UAX #9. If a typesetter is created
				with this option set to true, no directional reordering is
				performed and any directional control characters are ignored.
*/

extern const CFStringRef kCTTypesetterOptionDisableBidiProcessing;


/* --------------------------------------------------------------------------- */
/* Typesetter Creation */
/* --------------------------------------------------------------------------- */

/*!
	@function	CTTypesetterCreateWithAttributedString
	@abstract	Creates an immutable typesetter object using an attributed
				string.

	@discussion The resultant typesetter can be used to create lines, perform
				line breaking, and do other contextual analysis based on the
				characters in the string.

	@param		string
				The CFAttributedStringRef that you want to typeset. This
				parameter must be filled in with a valid CFAttributedString.

	@result		This function will return a reference to a CTTypesetter if the
				call was successful. Otherwise, it will return NULL.
*/

CTTypesetterRef CTTypesetterCreateWithAttributedString(
	CFAttributedStringRef string ) AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;


/*!
	@function	CTTypesetterCreateWithAttributedStringAndOptions
	@abstract	Creates an immutable typesetter object using an attributed
				string and a dictionary of options.

	@discussion The resultant typesetter can be used to create lines, perform
				line breaking, and do other contextual analysis based on the
				characters in the string.

	@param		string
				The CFAttributedStringRef that you want to typeset. This
				parameter must be filled in with a valid CFAttributedString.

	@param		options
				A CFDictionary of typesetter options, or NULL if there are none.

	@result		This function will return a reference to a CTTypesetter if the
				call was successful. Otherwise, it will return NULL.
*/

CTTypesetterRef CTTypesetterCreateWithAttributedStringAndOptions(
	CFAttributedStringRef string,
	CFDictionaryRef options ) AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;


/* --------------------------------------------------------------------------- */
/* Typeset Line Creation */
/* --------------------------------------------------------------------------- */

/*!
	@function	CTTypesetterCreateLine
	@abstract	Creates an immutable line from the typesetter.

	@discussion The resultant line will consist of glyphs in the correct visual
				order, ready to draw.

	@param		typesetter
				The typesetter which the line will come from. This parameter is
				required and cannot be set to NULL.

	@param		stringRange
				The string range which the line will be based on. If the length
				portion of range is set to 0, then the typesetter will continue
				to add glyphs to the line until it runs out of characters in the
				string. The location and length of the range must be within the
				bounds of the string, othewise the call will fail.

	@result		This function will return a reference to a CTLine if the call was
				successful. Otherwise, it will return NULL.
*/

CTLineRef CTTypesetterCreateLine(
	CTTypesetterRef typesetter,
	CFRange stringRange ) AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;


/* --------------------------------------------------------------------------- */
/* Typeset Line Breaking */
/* --------------------------------------------------------------------------- */

/*!
	@function	CTTypesetterSuggestLineBreak
	@abstract	Suggests a contextual line break point based on the width
				provided.

	@discussion The line break can be triggered either by a hard break character
				in the stream or by filling the specified width with characters.

	@param		typesetter
				The typesetter which the line will come from. This parameter is
				required and cannot be set to NULL.

	@param		startIndex
				The starting point for the line break calculations. The break
				calculations will include the character starting at startIndex.

	@param		width
				The requested line break width.

	@result		The value returned is a count of the characters from startIndex
				that would cause the line break. This value returned can be used
				to construct a character range for CTTypesetterCreateLine.
*/

CFIndex CTTypesetterSuggestLineBreak(
	CTTypesetterRef typesetter,
	CFIndex startIndex,
	double width ) AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;


/*!
	@function	CTTypesetterSuggestClusterBreak
	@abstract	Suggests a cluster line break point based on the width provided.

	@discussion Suggests a typographic cluster line break point based on the width
				provided. This cluster break is similar to a character break,
				except that it will not break apart linguistic clusters. No other
				contextual analysis will be done. This can be used by the caller
				to implement a different line breaking scheme, such as
				hyphenation. Note that a typographic cluster break can also be
				triggered by a hard break character in the stream.

	@param		typesetter
				The typesetter which the line will come from. This parameter is
				required and cannot be set to NULL.

	@param		startIndex
				The starting point for the typographic cluster break
				calculations. The break calculations will include the character
				starting at startIndex.

	@param		width
				The requested typographic cluster break width.

	@result		The value returned is a count of the characters from startIndex
				that would cause the cluster break. This value returned can be
				used to construct a character range for CTTypesetterCreateLine.
*/

CFIndex CTTypesetterSuggestClusterBreak(
	CTTypesetterRef typesetter,
	CFIndex startIndex,
	double width ) AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;


#if defined(__cplusplus)
}
#endif

#endif

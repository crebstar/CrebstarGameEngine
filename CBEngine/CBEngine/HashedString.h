#pragma once
#ifndef included_HashedString
#define included_HashedString

#include "CBGeneralMacros.h"

namespace CBConstants
{
	constexpr unsigned int HASHED_STRING_HASH_CONSTANT = 5381;
}


class HashedString
{
private:
	// Note: Due to a VS2015 bug, order matters with constexpr functions.
	// See http://stackoverflow.com/questions/33907196/vs2015-constexpr-compile-error-with-constexpr-constructor-call-to-constexpr-memb#33907407
	// DJB2 Hash documentation http://www.cse.yorku.ca/~oz/hash.html
	constexpr unsigned int HashedString::HashString( const char* stringToHash ) const noexcept
	{
		return ( (!stringToHash) ? 0 : HashStringDJB2Recursive( CBConstants::HASHED_STRING_HASH_CONSTANT, stringToHash ) );
	}


	constexpr unsigned int HashedString::HashStringDJB2Recursive( const unsigned int hashConstant, const char* stringToHash ) const noexcept
	{
		return (!(*stringToHash) ? hashConstant : HashStringDJB2Recursive((( hashConstant << 5) + hashConstant) + (*stringToHash), stringToHash + 1));
	}

	unsigned int		mStringHash;
	const char*			mStringData;

public:
	~HashedString() = default; // Done to keep HashedString as a LiteralType to work with constexpr

	explicit constexpr HashedString( const char* stringToHash ) noexcept
		: mStringHash( HashString( stringToHash ) ),
			mStringData( stringToHash )
	{

	}

	
	// ===== Inline Functions ===== //
	// Overloaded Operators
	inline bool operator < ( const HashedString& stringToCompare ) const
	{
		return ( mStringHash < stringToCompare.mStringHash );
	}

	inline bool operator == ( const HashedString& stringToCompare ) const
	{
		return ( mStringHash == stringToCompare.mStringHash );
	}

	// Mutators
	const unsigned int GetStringHashValue() const;

	PREVENT_COPY_AND_ASSIGN( HashedString );
};


inline const unsigned int HashedString::GetStringHashValue() const
{
	return mStringHash;
}


#endif
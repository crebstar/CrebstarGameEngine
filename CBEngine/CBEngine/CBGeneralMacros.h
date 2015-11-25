#pragma once
#ifndef included_CBGeneralMacros
#define included_CBGeneralMacros

#define PREVENT_COPY_AND_ASSIGN(TypeName) \
	private: \
	TypeName( const TypeName & t ) = delete; \
	void operator = ( const TypeName & t ) = delete;

#define UNUSED(x) (void)(x);

#define STATIC 


#endif
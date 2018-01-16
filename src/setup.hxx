/* Read Skeleton/LICENSE.md file for copyright and licensing information. */

#ifndef SKELETON_SETUP_HXX_INCLUDED
#define SKELETON_SETUP_HXX_INCLUDED 1

#include <libintl.h>
#include <yaal/hcore/hstring.hxx>

#include "config.hxx"

namespace Skeleton {

struct OSetup {
	bool _quiet;			/* --quiet, --silent */
	bool _verbose;		/* --verbose */
	char* _programName;
	yaal::hcore::HString _logPath;
	/* self-sufficient */
	OSetup( void )
		: _quiet( false ), _verbose( false ),
		_programName( NULL ), _logPath() {}
	void test_setup( void );
private:
	OSetup( OSetup const& );
	OSetup& operator = ( OSetup const& );
};

extern OSetup setup;

}

#endif /* #ifndef SKELETON_SETUP_HXX_INCLUDED */


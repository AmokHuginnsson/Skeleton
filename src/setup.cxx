/* Read Skeleton/LICENSE.md file for copyright and licensing information. */

#include <cstdio>

#include <yaal/tools/util.hxx>
M_VCSID( "$Id: " __ID__ " $" )
#include <yaal/hcore/hfile.hxx>

#include "setup.hxx"

using namespace yaal::hcore;

namespace Skeleton {

void OSetup::test_setup( void ) {
	M_PROLOG
	if ( _quiet && _verbose ) {
		yaal::tools::util::failure( 1,
				_( "quiet and verbose options are exclusive\n" ) );
	}
	if ( _verbose ) {
		clog.reset_owned( make_pointer<HFile>( stdout, HFile::OWNERSHIP::EXTERNAL ) );
	}
	if ( _quiet ) {
		cout.reset();
	}
	return;
	M_EPILOG
}

}


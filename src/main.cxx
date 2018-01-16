/* Read Skeleton/LICENSE.md file for copyright and licensing information. */

#include <cstdlib>

#include <yaal/hcore/hlog.hxx>
#include <yaal/tools/signals.hxx>
#include <yaal/tools/util.hxx>
#include <yaal/tools/hthreadpool.hxx>
M_VCSID( "$Id: " __ID__ " $" )

#include "setup.hxx"
#include "options.hxx"

using namespace std;
using namespace yaal;
using namespace yaal::hcore;
using namespace yaal::tools;
using namespace yaal::tools::util;
using namespace Skeleton;

namespace Skeleton {

OSetup setup;

}

int main( int argc_, char* argv_[] ) {
	HScopeExitCall secTP( call( &HThreadPool::stop, &HThreadPool::get_instance() ) );
	HScopeExitCall secSS( call( &HSignalService::stop, &HSignalService::get_instance() ) );
	M_PROLOG
/* variables declarations for main loop: */
	/* HConsole& cons = HConsole::get_instance(); */
	int err( 0 );
/* end. */
	try {
/* TO-DO: enter main loop code here */
		HSignalService::get_instance();
		setup._programName = argv_[ 0 ];
		handle_program_options( argc_, argv_ );
		hcore::log.rehash( setup._logPath, setup._programName );
		setup.test_setup();
/*		if ( ! cons.is_enabled() )
			enter_curses(); */ /* enabling ncurses ablilities */
/* *BOOM* */
/*
		if ( cons.is_enabled() )
			cons.leave_curses(); / * ending ncurses sesion * /
*/
/* ... there is the place main loop ends. :OD-OT */
	} catch ( int e ) {
		err = e;
		/* escape from main loop */
	} catch ( ... ) {
/*
		if ( cons.is_enabled() )
			cons.leave_curses(); / * ending ncurses sesion * /
*/
		throw;
	}
	cerr << _( "Done" ) << endl;
	return ( err );
	M_FINAL
}


/*
---         `prj' 0.0.0 (c) 1978 by Marcin 'Amok' Konarski           ---

	rc_options.c - this file is integral part of `prj' project.

	i.  You may not make any changes in Copyright information.
	ii. You must attach Copyright information to any part of every copy
	    of this software.

Copyright:

 You are free to use this program as is, you can redistribute binary
 package freely but:
  1. You can not use any part of sources of this software.
  2. You can not redistribute any part of sources of this software.
  3. No reverse engineering is allowed.
  4. If you want redistribute binary package you can not demand any fees
     for this software.
     You can not even demand cost of the carrier (CD for example).
  5. You can not include it to any commercial enterprise (for example 
     as a free add-on to payed software or payed newspaper).
 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE. Use it at your own risk.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <stdhapi.h>

#include "variables.h"

int process_rc_file ( void )
	{
	FILE * l_psRc = 0;
	HString l_oOption, l_oValue;
	const char l_pcRcName [ ] = "prj";
	log << "process_rc_file ( ): ";
	l_psRc = rc_open ( l_pcRcName, false );
	if ( l_psRc )while ( read_rc_line ( l_oOption, l_oValue, l_psRc ) )
		{
		if ( ! strcasecmp ( l_oOption, "logfile" ) )
			g_pcLogFileName = xstrdup ( l_oValue );
		printf ( "option: [%s], value: [%s]\n", ( char * ) l_oOption, ( char * ) l_oValue );
		}
	l_psRc = rc_open ( l_pcRcName, true, l_psRc );
	if ( l_psRc )while ( read_rc_line ( l_oOption, l_oValue, l_psRc ) )
		{
		if ( ! strcasecmp ( l_oOption, "logfile" ) )
			g_pcLogFileName = xstrdup ( l_oValue );
		printf ( "option: [%s], value: [%s]\n", ( char * ) l_oOption, ( char * ) l_oValue );
		}
	if ( ! g_pcLogFileName )
		g_pcLogFileName = xstrdup ( "prj.log" );
	rc_close ( l_psRc );
	log << "done." << endl;
	return ( 0 );
	}

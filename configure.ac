pushdef([AC_VERSION],esyscmd(awk '/^VERSION[[[:space:]]]+=[[[:space:]]]+/{printf $3}' Makefile.mk.in))
pushdef([AC_SUBVERSION],esyscmd(awk '/^SUBVERSION[[[:space:]]]+=[[[:space:]]]+/{printf $3}' Makefile.mk.in))
pushdef([AC_EXTRAVERSION],esyscmd(awk '/^EXTRAVERSION[[[:space:]]]+=[[[:space:]]]+/{printf $3}' Makefile.mk.in))
pushdef([MY_PACKAGE_VERSION],[AC_VERSION.AC_SUBVERSION.AC_EXTRAVERSION-esyscmd(date +%Y%m%d|tr -d '\n')])
AC_INIT([[Skeleton]],[MY_PACKAGE_VERSION],[[amok@codestation.org]])
dnl It is expected that client applications have link to yaal's _aux.
dnl This macro has to be here due to primitivism of libtoolize.
AC_CONFIG_AUX_DIR([_aux])
m4_include([_aux/client-configure.m4])
YAAL_CONFIGURE_CLIENT_INIT(Skeleton,MY_PACKAGE_VERSION)
YAAL_CONFIGURE_CLIENT_FINALIZE

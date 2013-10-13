# Created by: vagner 
# $FreeBSD: head/security/libpssh/Makefile 328202 2013-10-13 14:47:10Z vagner $

PORTNAME=	libpssh
PORTVERSION=	1.0.1
CATEGORIES=	security

MAINTAINER= 	vagner@bsdway.ru	
COMMENT=	Badoo\'s open source asynchronous ssh lib for C/C++

LICENSE=        BSD

USE_GITHUB=     yes
NO_STAGE=       yes
GH_ACCOUNT=     svagner
GH_PROJECT=     ${PORTNAME}
GH_COMMIT=      4b4267a

LIB_DEPENDS=	ssh2:${PORTSDIR}/security/libssh2 \
		libevent-2.0.so:${PORTSDIR}/devel/libevent2

USE_GCC=        any
GNU_CONFIGURE=  yes
USE_AUTOTOOLS=  aclocal automake autoconf libtool

.include <bsd.port.pre.mk>

run-autotools:	
	@${ECHO_MSG} ""
	@${ECHO_MSG} "======================== ATTENTION ========================"
	@${ECHO_MSG} "To install this library you must reinstall libssh2 with "
	@${ECHO_MSG} "iohandle patch. This patches you can find in URI: "
	@${ECHO_MSG} "https://github.com/svagner/freebsd_ports/tree/master/patches/libssh2_iohandle_patch"
	@${ECHO_MSG} "Fetch it and copy to /usr/ports/security/libssh2/files. "
	@${ECHO_MSG} "After you must reinstall port libssh2 with commands: "
	@${ECHO_MSG} "# make clean && make install clean"
	@${ECHO_MSG} "If you don't want to do this press Ctrl+C"
	@${ECHO_MSG} "======================== ATTENTION ========================"
	@${ECHO_MSG} ""
	@sleep 10 
	@cd ${WRKSRC} && ${SH} ./autogen.sh

.include <bsd.port.post.mk>
